#include "excelyresortsink.h"

#include "base.h"
#include "baseuid.h"
#include "broadcastthread.h"
#include "cacheguest.h"
#include "cacheone.h"
#include "cachereservation.h"
#include "cachereservationcardex.h"
#include "defines.h"
#include "doubledatabase.h"
#include "excely/resort/channeltoresort.h"
#include "paymentmode.h"
#include "stringutils.h"
#include "trackcontrol.h"
#include "vauchers.h"
#include "wreservationroomtab.h"

#include <QDate>
#include <QDateTime>
#include <QHash>
#include <QObject>
#include <QSet>
#include <QTime>

namespace {

/** PMS money fields are AMD. Convert channel amounts (USD → * dollarRate). */
double amountToAmd(double amount,
                   const QString &currencyCode,
                   double dollarRate,
                   QStringList *warnings,
                   const QString &ctx)
{
    const QString cur = currencyCode.trimmed().toUpper();
    if (amount <= 0.0 || cur.isEmpty() || cur == QLatin1String("AMD")) {
        return amount;
    }
    if (cur == QLatin1String("USD") || cur == QLatin1String("US$")) {
        return amount * (dollarRate > 0.0 ? dollarRate : 1.0);
    }
    if (warnings) {
        warnings->append(QObject::tr(
            "%1: currency %2 not converted — stored as AMD amount %3")
                             .arg(ctx, cur)
                             .arg(amount));
    }
    return amount;
}

bool isUsd(const QString &currencyCode)
{
    const QString cur = currencyCode.trimmed().toUpper();
    return cur == QLatin1String("USD") || cur == QLatin1String("US$");
}

} // namespace

ExcelyResortSink::ExcelyResortSink(const QMap<QString, QString> &roomTypeMap,
                                   const QSet<QString> &knownRatePlans)
    : m_roomTypeMap(roomTypeMap)
    , m_knownRatePlans(knownRatePlans)
{
}

QStringList ExcelyResortSink::takeWarnings()
{
    QStringList w = m_warnings;
    m_warnings.clear();
    return w;
}

bool ExcelyResortSink::accept(const Excely::Channel::Booking &booking,
                              QString *pmsReservationId,
                              QString *errorText)
{
    const Excely::Resort::BookingDraft draft = Excely::Resort::toResortDraft(booking);
    return acceptDraft(draft, pmsReservationId, errorText);
}

bool ExcelyResortSink::validateImportRooms(const Excely::Resort::BookingDraft &draft)
{
    m_rejectReason.clear();
    for (const Excely::Resort::RoomDraft &room : draft.rooms) {
        const QString roomType = room.roomTypeCode.trimmed();
        if (roomType.isEmpty() || !m_roomTypeMap.contains(roomType)) {
            m_rejectReason = QObject::tr("Unknown room type code '%1' (not in roomTypeMap)")
                                 .arg(roomType.isEmpty() ? QStringLiteral("(empty)") : roomType);
            return false;
        }

        const QString ratePlan = room.ratePlanCode.trimmed();
        const bool rateKnown = !ratePlan.isEmpty() && m_knownRatePlans.contains(ratePlan);
        const bool hasAmount = room.total > 0.0 || room.roomFee > 0.0 || draft.grandTotal > 0.0;
        if (!rateKnown && !hasAmount) {
            m_rejectReason = QObject::tr(
                "Unknown rate plan '%1' and no amounts on booking — cannot import")
                                 .arg(ratePlan.isEmpty() ? QStringLiteral("(empty)") : ratePlan);
            return false;
        }
        if (!rateKnown && hasAmount) {
            m_warnings.append(QObject::tr(
                "%1: unknown rate plan '%2' — importing using booking amounts")
                                  .arg(draft.chmId,
                                       ratePlan.isEmpty() ? QStringLiteral("(empty)") : ratePlan));
        }
    }
    return true;
}

bool ExcelyResortSink::acceptDraft(const Excely::Resort::BookingDraft &draft,
                                   QString *pmsReservationId,
                                   QString *errorText)
{
    m_lastOutcome = Outcome::Failed;
    m_rejectReason.clear();
    m_warnings.clear();
    m_touchedReserveIds.clear();
    m_touchedGuestIds.clear();
    m_roomConfirmations.clear();

    if (draft.chmId.isEmpty()) {
        if (errorText) {
            *errorText = QObject::tr("Empty channel reservation id");
        }
        return false;
    }

    if (draft.action == QStringLiteral("cancel") || draft.state == RESERVE_REMOVED) {
        return cancelByChm(draft, pmsReservationId, errorText);
    }

    Excely::Resort::BookingDraft work = draft;
    if (work.rooms.isEmpty()) {
        Excely::Resort::RoomDraft rd;
        rd.startDate = QDate::currentDate();
        rd.endDate = rd.startDate.addDays(1);
        rd.total = work.grandTotal;
        rd.roomFee = work.grandTotal;
        work.rooms.append(rd);
        m_warnings.append(QObject::tr("%1: no room stays — created placeholder dates")
                              .arg(work.chmId));
    }

    // Permanent rejects: unknown category, or unknown rate plan without amounts
    if (!validateImportRooms(work)) {
        m_lastOutcome = Outcome::Rejected;
        if (errorText) {
            *errorText = m_rejectReason;
        }
        // return true so host sends RequestDenied (not leave undelivered for retry)
        return true;
    }

    DoubleDatabase dr;
    dr.exec("select f_rate from f_acc_currencies where f_id=2");
    double dollarRate = 1.0;
    if (dr.nextRow()) {
        dollarRate = dr.getDouble("f_rate");
        if (dollarRate <= 0.0) {
            dollarRate = 1.0;
        }
    }

    int cityLedger = 0;
    const QString cardex = resolveCardex(work, &cityLedger);

    int paymentType = PAYMENT_CASH;
    const QString payHint = work.paymentTypeHint.toLower();
    if (payHint.contains(QStringLiteral("card")) || payHint.contains(QStringLiteral("bank"))) {
        paymentType = PAYMENT_CARD;
    }

    const int mainGuestId = ensureGuest(work.mainGuest);
    if (mainGuestId <= 0) {
        if (errorText) {
            *errorText = QObject::tr("Failed to create guest for %1").arg(work.chmId);
        }
        return false;
    }
    m_touchedGuestIds.append(mainGuestId);

    struct ExistingRow {
        QString id;
        QString invoice;
        QString chm;
        int state = 0;
        bool used = false;
    };
    QVector<ExistingRow> existing;
    dr[":f_chm"] = work.chmId;
    dr[":f_chm_like"] = work.chmId + QStringLiteral("#%");
    dr.exec("select f_id, f_invoice, f_chm, f_state from f_reservation "
            "where f_chm=:f_chm or f_chm like :f_chm_like order by f_id");
    while (dr.nextRow()) {
        ExistingRow row;
        row.id = dr.getString("f_id");
        row.invoice = dr.getString("f_invoice");
        row.chm = dr.getString("f_chm");
        row.state = dr.getInt("f_state");
        existing.append(row);
    }

    // Each RoomStay is its own PMS reservation: chmId#IndexNumber when the booking has several rooms
    QStringList chmKeys;
    QSet<QString> seenKeys;
    for (int i = 0; i < work.rooms.size(); ++i) {
        QString key = work.chmId;
        if (work.rooms.size() > 1) {
            QString idx = work.rooms.at(i).indexNumber.trimmed();
            if (idx.isEmpty() || seenKeys.contains(work.chmId + QStringLiteral("#") + idx)) {
                idx = QString::number(i + 1);
            }
            key = work.chmId + QStringLiteral("#") + idx;
        }
        seenKeys.insert(key);
        chmKeys.append(key);
    }

    // Pass 1: exact key match (prefer active row over canceled)
    QVector<int> matched(work.rooms.size(), -1);
    for (int i = 0; i < chmKeys.size(); ++i) {
        int best = -1;
        for (int j = 0; j < existing.size(); ++j) {
            const ExistingRow &row = existing.at(j);
            if (row.used || row.chm != chmKeys.at(i)) {
                continue;
            }
            if (best < 0 || (existing.at(best).state == RESERVE_REMOVED && row.state != RESERVE_REMOVED)) {
                best = j;
            }
        }
        if (best >= 0) {
            existing[best].used = true;
            matched[i] = best;
        }
    }
    // Pass 2: Modify usually brings new IndexNumbers — reuse remaining active rows in creation order
    for (int i = 0; i < chmKeys.size(); ++i) {
        if (matched.at(i) >= 0) {
            continue;
        }
        for (int j = 0; j < existing.size(); ++j) {
            if (!existing.at(j).used && existing.at(j).state != RESERVE_REMOVED) {
                existing[j].used = true;
                matched[i] = j;
                break;
            }
        }
    }

    QString primaryRsId;
    QString primaryInId;
    int primaryRoomId = 0;
    bool anyUpdate = false;
    bool anyCreate = false;
    bool anySkippedCanceled = false;
    bool anyWritten = false;

    for (int i = 0; i < work.rooms.size(); ++i) {
        const Excely::Resort::RoomDraft &room = work.rooms.at(i);
        const QString chmKey = chmKeys.at(i);

        QString existsRes;
        QString existsIn;
        int existsState = 0;
        if (matched.at(i) >= 0) {
            const ExistingRow &row = existing.at(matched.at(i));
            existsRes = row.id;
            existsIn = row.invoice;
            existsState = row.state;
        }

        // Do not resurrect a locally canceled channel booking on Create/Modify re-delivery
        if (!existsRes.isEmpty() && existsState == RESERVE_REMOVED) {
            m_warnings.append(QObject::tr(
                "%1: local %2 already canceled — skip revive")
                                  .arg(chmKey, existsRes));
            if (primaryRsId.isEmpty()) {
                primaryRsId = existsRes;
            }
            m_touchedReserveIds.append(existsRes);
            m_roomConfirmations.append({room.indexNumber, existsRes});
            anySkippedCanceled = true;
            continue;
        }

        const bool isUpdate = !existsRes.isEmpty();
        QString rsId;
        QString err;
        if (!upsertRoom(work, room, chmKey, isUpdate, existsRes, existsIn,
                        mainGuestId, cardex, cityLedger, paymentType, dollarRate,
                        &rsId, &err)) {
            if (errorText) {
                *errorText = err;
            }
            return false;
        }
        anyWritten = true;
        if (primaryRsId.isEmpty()) {
            primaryRsId = rsId;
            DoubleDatabase drInv;
            drInv[":f_id"] = rsId;
            if (drInv.exec("select f_invoice, f_room from f_reservation where f_id=:f_id")
                    && drInv.nextRow()) {
                primaryInId = drInv.getString("f_invoice");
                primaryRoomId = drInv.getInt("f_room");
            }
        }
        m_touchedReserveIds.append(rsId);
        m_roomConfirmations.append({room.indexNumber, rsId});
        if (isUpdate) {
            anyUpdate = true;
        } else {
            anyCreate = true;
        }
    }

    // Partial cancellation: RoomStays missing from this version are canceled in PMS
    if (anyWritten) {
        for (const ExistingRow &row : existing) {
            if (row.used || row.state == RESERVE_REMOVED) {
                continue;
            }
            cancelReservationRow(row.id, QObject::tr("Room removed by Excely modification"));
            m_touchedReserveIds.append(row.id);
            anyUpdate = true;
            m_warnings.append(QObject::tr("%1: room %2 no longer in booking — canceled")
                                  .arg(row.chm, row.id));
        }
    }

    if (primaryRsId.isEmpty()) {
        if (errorText) {
            *errorText = QObject::tr("No reservation processed for %1").arg(work.chmId);
        }
        return false;
    }

    if (!anyWritten && anySkippedCanceled) {
        // Tell host to RequestDenied so Exely drops undelivered (Reserved confirm does not clear this case)
        m_lastOutcome = Outcome::AlreadyCanceledLocally;
        if (pmsReservationId) {
            *pmsReservationId = primaryRsId;
        }
        m_warnings.append(QObject::tr(
            "%1: already canceled in PMS — will RequestDenied (not revive)")
                              .arg(work.chmId));
        return true;
    } else if (anyCreate && !anyUpdate) {
        m_lastOutcome = Outcome::Created;
    } else if (anyUpdate && !anyCreate) {
        m_lastOutcome = Outcome::Updated;
    } else {
        m_lastOutcome = anyCreate ? Outcome::Created : Outcome::Updated;
    }

    if (pmsReservationId) {
        *pmsReservationId = primaryRsId;
    }

    if (anyWritten && !work.deposits.isEmpty() && !primaryInId.isEmpty()) {
        const QString guestName = (work.mainGuest.firstName + QLatin1Char(' ')
                                   + work.mainGuest.lastName)
                                      .trimmed();
        syncAdvances(work, primaryRsId, primaryInId, primaryRoomId, guestName,
                     paymentType, dollarRate);
    }

    for (const QString &s : m_touchedReserveIds) {
        BroadcastThread::cmdRefreshCache(cid_reservation, s);
        BroadcastThread::cmdRefreshCache(cid_room, QStringLiteral("0"));
        BroadcastThread::cmdRefreshCache(45, s);
        BroadcastThread::cmdRefreshCache(cid_reservation_cardex, s);
        BroadcastThread::cmdRefreshCache(210, s);
    }
    for (int g : m_touchedGuestIds) {
        BroadcastThread::cmdRefreshCache(cid_guest, QString::number(g));
    }

    return true;
}

bool ExcelyResortSink::cancelByChm(const Excely::Resort::BookingDraft &draft,
                                   QString *pmsReservationId,
                                   QString *errorText)
{
    Q_UNUSED(errorText);
    DoubleDatabase dr;
    QStringList ids;

    dr[":f_chm"] = draft.chmId;
    dr[":f_chm_like"] = draft.chmId + QStringLiteral("#%");
    dr.exec("select f_id from f_reservation where f_chm=:f_chm or f_chm like :f_chm_like");
    while (dr.nextRow()) {
        ids.append(dr.getString("f_id"));
    }

    if (ids.isEmpty()) {
        m_lastOutcome = Outcome::Canceled;
        m_roomConfirmations.append({QString(), draft.chmId});
        if (pmsReservationId) {
            *pmsReservationId = draft.chmId;
        }
        m_warnings.append(QObject::tr("%1: cancel — no local reservation found (confirm only)")
                              .arg(draft.chmId));
        return true;
    }

    for (const QString &rsId : ids) {
        cancelReservationRow(rsId, QObject::tr("Cancelled by Excely"));
        m_touchedReserveIds.append(rsId);
    }

    m_lastOutcome = Outcome::Canceled;
    m_roomConfirmations.append({QString(), ids.first()});
    if (pmsReservationId) {
        *pmsReservationId = ids.first();
    }
    return true;
}

void ExcelyResortSink::trackExcely(const QString &invoice,
                                   const QString &rsId,
                                   const QString &action,
                                   const QString &oldValue,
                                   const QString &newValue)
{
    TrackControl::insert(TRACK_RESERVATION, action, oldValue, newValue, rsId, invoice, rsId);
}

void ExcelyResortSink::cancelReservationRow(const QString &rsId, const QString &reason)
{
    DoubleDatabase dr;
    QString invoice;
    dr[":f_id"] = rsId;
    if (dr.exec("select f_invoice from f_reservation where f_id=:f_id") && dr.nextRow()) {
        invoice = dr.getString("f_invoice");
    }

    dr[":f_id"] = rsId;
    dr[":f_state"] = RESERVE_REMOVED;
    dr[":f_canceluser"] = Base::fPreferences.getLocal(def_working_user_id).toInt() > 0
            ? Base::fPreferences.getLocal(def_working_user_id).toInt()
            : 1;
    dr[":f_canceldate"] = QDate::currentDate();
    dr.update("f_reservation", where_id(ap(rsId)));

    dr[":f_id"] = rsId;
    dr[":f_reason"] = reason;
    dr.insert("f_reservation_cancel_reason");

    trackExcely(invoice.isEmpty() ? QStringLiteral("-") : invoice,
                rsId,
                QObject::tr("Cancelled by Excely"),
                reason,
                QString());

    BroadcastThread::cmdRefreshCache(cid_reservation, rsId);
    BroadcastThread::cmdRefreshCache(cid_room, QStringLiteral("0"));
    BroadcastThread::cmdRefreshCache(45, rsId);
}

static QString iso3ToIso2(const QString &iso3)
{
    // Common Exely CitizenCountryName@Code (alpha-3) → alpha-2 used as f_nationality.f_short
    static const QHash<QString, QString> kMap = {
        {QStringLiteral("ARE"), QStringLiteral("AE")},
        {QStringLiteral("ARM"), QStringLiteral("AM")},
        {QStringLiteral("AUS"), QStringLiteral("AU")},
        {QStringLiteral("AUT"), QStringLiteral("AT")},
        {QStringLiteral("AZE"), QStringLiteral("AZ")},
        {QStringLiteral("BEL"), QStringLiteral("BE")},
        {QStringLiteral("BGR"), QStringLiteral("BG")},
        {QStringLiteral("BLR"), QStringLiteral("BY")},
        {QStringLiteral("BRA"), QStringLiteral("BR")},
        {QStringLiteral("CAN"), QStringLiteral("CA")},
        {QStringLiteral("CHE"), QStringLiteral("CH")},
        {QStringLiteral("CHN"), QStringLiteral("CN")},
        {QStringLiteral("CYP"), QStringLiteral("CY")},
        {QStringLiteral("CZE"), QStringLiteral("CZ")},
        {QStringLiteral("DEU"), QStringLiteral("DE")},
        {QStringLiteral("DNK"), QStringLiteral("DK")},
        {QStringLiteral("ESP"), QStringLiteral("ES")},
        {QStringLiteral("EST"), QStringLiteral("EE")},
        {QStringLiteral("FIN"), QStringLiteral("FI")},
        {QStringLiteral("FRA"), QStringLiteral("FR")},
        {QStringLiteral("GBR"), QStringLiteral("GB")},
        {QStringLiteral("GEO"), QStringLiteral("GE")},
        {QStringLiteral("GRC"), QStringLiteral("GR")},
        {QStringLiteral("HKG"), QStringLiteral("HK")},
        {QStringLiteral("HRV"), QStringLiteral("HR")},
        {QStringLiteral("HUN"), QStringLiteral("HU")},
        {QStringLiteral("IND"), QStringLiteral("IN")},
        {QStringLiteral("IRL"), QStringLiteral("IE")},
        {QStringLiteral("IRN"), QStringLiteral("IR")},
        {QStringLiteral("ISR"), QStringLiteral("IL")},
        {QStringLiteral("ITA"), QStringLiteral("IT")},
        {QStringLiteral("JPN"), QStringLiteral("JP")},
        {QStringLiteral("KAZ"), QStringLiteral("KZ")},
        {QStringLiteral("KGZ"), QStringLiteral("KG")},
        {QStringLiteral("KOR"), QStringLiteral("KR")},
        {QStringLiteral("LTU"), QStringLiteral("LT")},
        {QStringLiteral("LVA"), QStringLiteral("LV")},
        {QStringLiteral("MDA"), QStringLiteral("MD")},
        {QStringLiteral("MEX"), QStringLiteral("MX")},
        {QStringLiteral("NLD"), QStringLiteral("NL")},
        {QStringLiteral("NOR"), QStringLiteral("NO")},
        {QStringLiteral("POL"), QStringLiteral("PL")},
        {QStringLiteral("PRT"), QStringLiteral("PT")},
        {QStringLiteral("ROU"), QStringLiteral("RO")},
        {QStringLiteral("RUS"), QStringLiteral("RU")},
        {QStringLiteral("SWE"), QStringLiteral("SE")},
        {QStringLiteral("TUR"), QStringLiteral("TR")},
        {QStringLiteral("UKR"), QStringLiteral("UA")},
        {QStringLiteral("USA"), QStringLiteral("US")},
        {QStringLiteral("UZB"), QStringLiteral("UZ")},
    };
    return kMap.value(iso3);
}

int ExcelyResortSink::ensureGuest(const Excely::Resort::GuestDraft &g)
{
    DoubleDatabase dr;
    const QString nation = resolveNationShort(g.nationShort);
    const QString first = g.firstName.toUpper().trimmed();
    const QString last = g.lastName.toUpper().trimmed();

    auto applyUpdate = [&](int id) {
        dr[":f_title"] = QStringLiteral("");
        dr[":f_firstname"] = first;
        dr[":f_lastname"] = last;
        if (!g.phone.isEmpty()) {
            dr[":f_tel1"] = g.phone;
        }
        if (!nation.isEmpty()) {
            dr[":f_nation"] = nation;
        }
        if (!g.email.isEmpty()) {
            dr[":f_email"] = g.email;
        }
        dr.update("f_guests", where_id(id));
        return id;
    };

    if (!g.email.isEmpty()) {
        dr[":f_email"] = g.email;
        if (dr.exec("select f_id from f_guests where f_email=:f_email") && dr.nextRow()) {
            return applyUpdate(dr.getInt("f_id"));
        }
    }

    // Empty string, not null QString() — MySQL CONCAT(null, ...) yields NULL / "null" in UI
    dr[":f_title"] = QStringLiteral("");
    dr[":f_firstname"] = first;
    dr[":f_lastname"] = last;
    dr[":f_sex"] = 1;
    dr[":f_nation"] = nation;
    dr[":f_passport"] = QStringLiteral("");
    dr[":f_email"] = g.email;
    dr[":f_tel1"] = g.phone;
    const int id = dr.insert("f_guests");
    if (id <= 0) {
        m_warnings.append(QObject::tr("Insert f_guests failed: %1").arg(dr.fLastError));
    }
    return id;
}

QString ExcelyResortSink::resolveNationShort(const QString &countryCode)
{
    const QString code = countryCode.trimmed().toUpper();
    if (code.isEmpty()) {
        return QStringLiteral("");
    }

    auto lookupShort = [](const QString &shortCode) -> QString {
        if (shortCode.isEmpty()) {
            return QStringLiteral("");
        }
        DoubleDatabase dr;
        dr[":f_short"] = shortCode;
        if (dr.exec("select f_short from f_nationality where f_short=:f_short") && dr.nextRow()) {
            return dr.getString("f_short");
        }
        return QStringLiteral("");
    };

    // 1) Direct f_short (alpha-2 already, or hotel uses 3-letter shorts)
    if (QString found = lookupShort(code); !found.isEmpty()) {
        return found;
    }

    // 2) ISO-3166 alpha-3 → alpha-2, then f_short (no dependency on f_alpha3 column)
    if (code.size() == 3) {
        const QString iso2 = iso3ToIso2(code);
        if (QString found = lookupShort(iso2); !found.isEmpty()) {
            return found;
        }
        // UK sometimes stored instead of GB
        if (iso2 == QLatin1String("GB")) {
            if (QString found = lookupShort(QStringLiteral("UK")); !found.isEmpty()) {
                return found;
            }
        }
    }

    // 3) Optional f_alpha3 column (passport scanner / newer DBs). Probe once; never fail import.
    static int s_hasAlpha3 = -1; // -1 unknown, 0 no, 1 yes
    if (s_hasAlpha3 != 0 && code.size() == 3) {
        DoubleDatabase dr;
        dr.setNoSqlErrorLogMode(true);
        if (s_hasAlpha3 < 0) {
            s_hasAlpha3 = dr.exec(QStringLiteral("select f_alpha3 from f_nationality limit 1")) ? 1 : 0;
        }
        if (s_hasAlpha3 > 0) {
            dr.setNoSqlErrorLogMode(false);
            dr[":f_alpha3"] = code;
            if (dr.exec("select f_short from f_nationality where f_alpha3=:f_alpha3") && dr.nextRow()) {
                return dr.getString("f_short");
            }
        }
    }

    m_warnings.append(QObject::tr("Unknown nationality code '%1' (add matching f_short in f_nationality)")
                          .arg(code));
    return QStringLiteral("");
}

void ExcelyResortSink::linkReservationGuests(const QString &rsId,
                                             int mainGuestId,
                                             const Excely::Resort::BookingDraft &draft)
{
    DoubleDatabase dr;
    dr[":f_reservation"] = rsId;
    dr.exec("delete from f_reservation_guests where f_reservation=:f_reservation");

    QList<int> ids;
    QSet<int> seen;
    if (mainGuestId > 0) {
        ids.append(mainGuestId);
        seen.insert(mainGuestId);
    }

    const QString mainFirst = draft.mainGuest.firstName.toUpper().trimmed();
    const QString mainLast = draft.mainGuest.lastName.toUpper().trimmed();

    for (const Excely::Resort::GuestDraft &gd : draft.guests) {
        const QString gf = gd.firstName.toUpper().trimmed();
        const QString gl = gd.lastName.toUpper().trimmed();
        if (gf.isEmpty() && gl.isEmpty()) {
            continue;
        }
        // Skip duplicate of primary (toResortDraft copies ResGuests including main)
        if (gf == mainFirst && gl == mainLast) {
            continue;
        }
        const int gid = ensureGuest(gd);
        if (gid <= 0 || seen.contains(gid)) {
            continue;
        }
        ids.append(gid);
        seen.insert(gid);
        m_touchedGuestIds.append(gid);
    }

    for (int i = 0; i < ids.size(); ++i) {
        dr[":f_reservation"] = rsId;
        dr[":f_guest"] = ids.at(i);
        dr[":f_first"] = (i == 0) ? 1 : 0;
        dr.insert("f_reservation_guests", false);
    }
}

QString ExcelyResortSink::resolveCardex(const Excely::Resort::BookingDraft &draft, int *cityLedger)
{
    if (cityLedger) {
        *cityLedger = 0;
    }
    DoubleDatabase dr;
    QString cardex = draft.cardex.trimmed();

    if (!cardex.isEmpty()) {
        dr[":f_cardex"] = cardex;
        dr.exec("select f_cardex, f_cityledger from f_cardex where f_cardex=:f_cardex");
        if (dr.nextRow()) {
            if (cityLedger) {
                *cityLedger = dr.getInt("f_cityledger");
            }
            return dr.getString("f_cardex");
        }
        dr[":f_name"] = cardex;
        dr.exec("select f_cardex, f_cityledger from f_cardex where f_name=:f_name");
        if (dr.nextRow()) {
            if (cityLedger) {
                *cityLedger = dr.getInt("f_cityledger");
            }
            return dr.getString("f_cardex");
        }
    }

    if (!draft.companyName.isEmpty()) {
        dr[":f_name"] = draft.companyName;
        dr.exec("select f_cardex, f_cityledger from f_cardex where f_name=:f_name");
        if (dr.nextRow()) {
            if (cityLedger) {
                *cityLedger = dr.getInt("f_cityledger");
            }
            return dr.getString("f_cardex");
        }
    }

    return cardex;
}

int ExcelyResortSink::findFreeRoom(const QString &roomTypeCode,
                                   const QDate &start,
                                   const QDate &end,
                                   const QString &excludeReserveId,
                                   DoubleDatabase *lockDb,
                                   bool *roomLocked,
                                   QString *warn)
{
    if (roomLocked) {
        *roomLocked = false;
    }
    if (roomTypeCode.isEmpty()) {
        if (warn) {
            *warn = QObject::tr("empty room type code");
        }
        return 0;
    }
    if (!m_roomTypeMap.contains(roomTypeCode)) {
        if (warn) {
            *warn = QObject::tr("no roomTypeMap entry for CM code %1").arg(roomTypeCode);
        }
        return 0;
    }
    if (!lockDb) {
        if (warn) {
            *warn = QObject::tr("no database for room lock");
        }
        return 0;
    }

    const QString classKey = m_roomTypeMap.value(roomTypeCode);
    DoubleDatabase listDb;
    QList<int> checkRooms;
    bool okInt = false;
    const int classId = classKey.toInt(&okInt);
    if (okInt && classId > 0) {
        listDb[":f_class"] = classId;
        listDb.exec("select f_id from f_room where f_class=:f_class order by f_id");
    } else {
        listDb[":f_short"] = classKey;
        listDb.exec("select f_id from f_room where f_class in "
                    "(select f_id from f_room_classes where f_short=:f_short) order by f_id");
    }
    while (listDb.nextRow()) {
        checkRooms.append(listDb.getInt("f_id"));
    }
    if (checkRooms.isEmpty()) {
        if (warn) {
            *warn = QObject::tr("no rooms for class %1 (CM %2)").arg(classKey, roomTypeCode);
        }
        return 0;
    }

    QString lastErr;
    for (int tempRoom : checkRooms) {
        if (!lockDb->startTransaction()) {
            if (warn) {
                *warn = lockDb->fLastError.isEmpty()
                        ? QObject::tr("Cannot lock room")
                        : lockDb->fLastError;
            }
            return 0;
        }
        QString err;
        if (WReservationRoomTab::checkLocked(*lockDb, tempRoom, start, end, excludeReserveId, err)) {
            if (roomLocked) {
                *roomLocked = true;
            }
            return tempRoom;
        }
        lastErr = err;
        lockDb->rollback();
    }
    if (warn) {
        *warn = QObject::tr("no free room for class %1 / CM %2 on %3–%4")
                    .arg(classKey, roomTypeCode,
                         start.toString(Qt::ISODate),
                         end.toString(Qt::ISODate));
        if (!lastErr.isEmpty()) {
            *warn += QStringLiteral(" (") + lastErr + QLatin1Char(')');
        }
    }
    return 0;
}

int ExcelyResortSink::resolveBedQty(int roomId, const QString &roomTypeCode) const
{
    DoubleDatabase dr;
    if (roomId > 0) {
        dr[":f_id"] = roomId;
        if (dr.exec("select f_bedQty from f_room where f_id=:f_id") && dr.nextRow()) {
            const int qty = dr.getInt("f_bedQty");
            if (qty > 0) {
                return qty;
            }
        }
    }

    if (!roomTypeCode.isEmpty() && m_roomTypeMap.contains(roomTypeCode)) {
        const QString classKey = m_roomTypeMap.value(roomTypeCode);
        bool okInt = false;
        const int classId = classKey.toInt(&okInt);
        if (okInt && classId > 0) {
            dr[":f_class"] = classId;
            if (dr.exec("select max(f_bedQty) as q from f_room where f_class=:f_class")
                    && dr.nextRow()) {
                const int qty = dr.getInt("q");
                if (qty > 0) {
                    return qty;
                }
            }
        } else {
            dr[":f_short"] = classKey;
            if (dr.exec("select max(f_bedQty) as q from f_room where f_class in "
                        "(select f_id from f_room_classes where f_short=:f_short)")
                    && dr.nextRow()) {
                const int qty = dr.getInt("q");
                if (qty > 0) {
                    return qty;
                }
            }
        }
    }
    return 2; // majority of rooms are double
}

bool ExcelyResortSink::needsExtraBed(int men, int children, int bedQty, bool channelExtraBed)
{
    if (channelExtraBed) {
        return true;
    }
    const int bedsNeeded = qMax(0, men) + qMax(0, children); // babies excluded
    return bedQty > 0 && bedsNeeded > bedQty;
}

void ExcelyResortSink::syncAdvances(const Excely::Resort::BookingDraft &draft,
                                    const QString &rsId,
                                    const QString &invoiceId,
                                    int roomId,
                                    const QString &guestName,
                                    int paymentType,
                                    double dollarRate)
{
    if (invoiceId.isEmpty() || draft.deposits.isEmpty()) {
        return;
    }

    int itemCode = Preferences::getDb(def_advance_voucher_id).toInt();
    if (itemCode <= 0) {
        itemCode = 1;
        m_warnings.append(QObject::tr(
            "%1: advance voucher item id not configured — using %2")
                              .arg(draft.chmId)
                              .arg(itemCode));
    }

    const QString payLabel = paymentType == PAYMENT_CARD
            ? QStringLiteral("CARD")
            : (draft.paymentName.isEmpty() ? QStringLiteral("CASH") : draft.paymentName);
    const QString finalName = QObject::tr("ADVANCE") + QLatin1Char(' ') + payLabel;
    const int userId = Base::fPreferences.getLocal(def_working_user_id).toInt() > 0
            ? Base::fPreferences.getLocal(def_working_user_id).toInt()
            : 1;
    const QDate wdate = Base::fPreferences.getLocalDate(def_working_day);

    DoubleDatabase dr;
    for (const Excely::Resort::DepositDraft &dep : draft.deposits) {
        if (dep.amount <= 0.0) {
            continue;
        }

        const QString cur = dep.currencyCode.trimmed().toUpper();
        const double amountAmd = amountToAmd(dep.amount, cur, dollarRate,
                                             &m_warnings, draft.chmId);

        const QString marker = QStringLiteral("Excely:prepaid:%1:%2")
                                   .arg(draft.chmId)
                                   .arg(dep.paymentIndex >= 0 ? dep.paymentIndex : 0);

        QString existingId;
        dr[":f_inv"] = invoiceId;
        dr[":f_source"] = VAUCHER_ADVANCE_N;
        dr[":f_marker"] = QStringLiteral("%") + marker + QLatin1Char('%');
        dr.exec("select f_id, f_amountAmd from m_register "
                "where f_inv=:f_inv and f_source=:f_source and f_canceled=0 "
                "and f_remarks like :f_marker "
                "order by f_id desc limit 1");
        double prevAmount = 0.0;
        if (dr.nextRow()) {
            existingId = dr.getString("f_id");
            prevAmount = dr.getDouble("f_amountAmd");
        }

        const QString remarks = QStringLiteral("%1 %2 %3 %4")
                                    .arg(marker,
                                         dep.type.isEmpty() ? QStringLiteral("ReceivedPayment") : dep.type,
                                         QString::number(dep.amount, 'f', 2),
                                         cur.isEmpty() ? QStringLiteral("AMD") : cur);

        if (!existingId.isEmpty() && qAbs(prevAmount - amountAmd) < 0.01) {
            continue; // already in sync
        }

        dr[":f_source"] = VAUCHER_ADVANCE_N;
        dr[":f_res"] = rsId;
        dr[":f_inv"] = invoiceId;
        dr[":f_wdate"] = wdate;
        dr[":f_rdate"] = QDate::currentDate();
        dr[":f_time"] = QTime::currentTime();
        dr[":f_user"] = userId;
        dr[":f_room"] = roomId;
        dr[":f_guest"] = guestName;
        dr[":f_itemcode"] = itemCode;
        dr[":f_finalName"] = finalName;
        dr[":f_amountAmd"] = amountAmd;
        dr[":f_amountVat"] = 0;
        dr[":f_amountUsd"] = dollarRate > 0.0 ? dollarRate : 1.0;
        dr[":f_fiscal"] = 0;
        dr[":f_paymentMode"] = paymentType;
        dr[":f_creditCard"] = 0;
        dr[":f_cityLedger"] = 0;
        dr[":f_paymentComment"] = payLabel;
        dr[":f_dc"] = QStringLiteral("DEBET");
        dr[":f_sign"] = -1;
        dr[":f_doc"] = QString();
        dr[":f_rec"] = QString();
        dr[":f_finance"] = 1;
        dr[":f_remarks"] = remarks;
        dr[":f_canceled"] = 0;
        dr[":f_side"] = 0;
        dr[":f_rb"] = 0;
        dr[":f_vatmode"] = 0;
        dr[":f_usedPrepaid"] = 0;

        if (!existingId.isEmpty()) {
            if (!dr.update("m_register", where_id(ap(existingId)))) {
                m_warnings.append(QObject::tr("%1: update prepaid AV failed: %2")
                                      .arg(draft.chmId, dr.fLastError));
                continue;
            }
            m_warnings.append(QObject::tr("%1: prepaid updated %2 → %3 AMD (%4)")
                                  .arg(draft.chmId)
                                  .arg(prevAmount, 0, 'f', 2)
                                  .arg(amountAmd, 0, 'f', 2)
                                  .arg(existingId));
        } else {
            const QString avId = uuidx(VAUCHER_ADVANCE_N);
            dr[":f_id"] = avId;
            if (!dr.insert("m_register", false)) {
                m_warnings.append(QObject::tr("%1: insert prepaid AV failed: %2")
                                      .arg(draft.chmId, dr.fLastError));
                continue;
            }
            m_warnings.append(QObject::tr("%1: prepaid AV %2 = %3 AMD")
                                  .arg(draft.chmId, avId)
                                  .arg(amountAmd, 0, 'f', 2));
        }
    }
}

bool ExcelyResortSink::upsertRoom(const Excely::Resort::BookingDraft &draft,
                                  const Excely::Resort::RoomDraft &room,
                                  const QString &chmKey,
                                  bool isUpdate,
                                  const QString &existsRes,
                                  const QString &existsIn,
                                  int mainGuestId,
                                  const QString &cardex,
                                  int cityLedger,
                                  int paymentType,
                                  double dollarRate,
                                  QString *outRsId,
                                  QString *errorText)
{
    DoubleDatabase dr;

    QDate startDate = room.startDate;
    QDate endDate = room.endDate;
    if (!startDate.isValid()) {
        startDate = QDate::currentDate();
    }
    if (!endDate.isValid() || endDate <= startDate) {
        endDate = startDate.addDays(1);
    }

    const int nights = qMax(1, startDate.daysTo(endDate));
    const QString moneyCur = !room.currencyCode.trimmed().isEmpty()
            ? room.currencyCode
            : draft.currencyCode;
    const double rawTotal = room.total > 0.0 ? room.total : draft.grandTotal;
    double totalAmount = amountToAmd(rawTotal, moneyCur, dollarRate, &m_warnings, chmKey);
    double pricePerNight = room.roomFee > 0.0
            ? amountToAmd(room.roomFee, moneyCur, dollarRate, nullptr, chmKey)
            : 0.0;
    if (pricePerNight <= 0.0 && totalAmount > 0.0) {
        pricePerNight = totalAmount / nights;
    }
    // f_totalusd: original USD if channel sent USD, else AMD/rate
    const double totalUsd = isUsd(moneyCur)
            ? rawTotal
            : (dollarRate > 0.0 ? totalAmount / dollarRate : totalAmount);

    QString roomWarn;
    bool roomLocked = false;
    const int roomId = findFreeRoom(room.roomTypeCode, startDate, endDate,
                                    isUpdate ? existsRes : QString(),
                                    &dr, &roomLocked, &roomWarn);
    if (roomId == 0 && !roomWarn.isEmpty()) {
        m_warnings.append(QObject::tr("%1: %2 — left unassigned").arg(chmKey, roomWarn));
    }

    QString rsId;
    QString inId;
    // Previous values for TrackControl on modify
    int oldRoom = 0;
    QDate oldStart;
    QDate oldEnd;
    QTime oldArrival;
    QTime oldDeparture;
    int oldMan = 0;
    int oldChild = 0;
    int oldBaby = 0;
    int oldExtraBed = 0;
    double oldRoomFee = 0.0;
    double oldPricePerNight = 0.0;
    double oldTotal = 0.0;
    QString oldCardex;
    QString oldRemarks;

    if (isUpdate) {
        rsId = existsRes;
        inId = existsIn;
        dr[":f_id"] = existsRes;
        if (dr.exec("select f_room, f_startDate, f_endDate, f_arrivalTime, f_departureTime, "
                    "f_man, f_child, f_baby, f_extraBed, f_roomFee, f_pricePerNight, "
                    "f_grandTotal, f_cardex, f_remarks "
                    "from f_reservation where f_id=:f_id")
                && dr.nextRow()) {
            oldRoom = dr.getInt("f_room");
            oldStart = dr.getDate("f_startDate");
            oldEnd = dr.getDate("f_endDate");
            oldArrival = dr.getTime("f_arrivalTime");
            oldDeparture = dr.getTime("f_departureTime");
            oldMan = dr.getInt("f_man");
            oldChild = dr.getInt("f_child");
            oldBaby = dr.getInt("f_baby");
            oldExtraBed = dr.getInt("f_extraBed");
            oldRoomFee = dr.getDouble("f_roomFee");
            oldPricePerNight = dr.getDouble("f_pricePerNight");
            oldTotal = dr.getDouble("f_grandTotal");
            oldCardex = dr.getString("f_cardex");
            oldRemarks = dr.getString("f_remarks");
        }
    } else {
        rsId = uuidx(VAUCHER_RESERVATION_N);
        inId = uuidx(QStringLiteral("IN"));
    }

    const double vatAmount = totalAmount - (totalAmount / ((20.0 / 100.0) + 1.0));
    const QString guestName = (draft.mainGuest.firstName + QLatin1Char(' ')
                               + draft.mainGuest.lastName)
                                  .trimmed();
    // No separate channel number → leave f_booking empty. Do not copy f_chm.
    const QString bookingExt = draft.bookingExternalId.trimmed();
    const QTime arrivalTime = room.arrivalTime.isValid() ? room.arrivalTime : QTime(14, 0);
    const QTime departureTime = room.departureTime.isValid() ? room.departureTime : QTime(12, 0);

    dr[":f_id"] = rsId;
    dr[":f_invoice"] = inId;
    if (!isUpdate) {
        dr[":f_created"] = QDate::currentDate();
        dr[":f_author"] = Base::fPreferences.getLocal(def_working_user_id).toInt() > 0
                ? Base::fPreferences.getLocal(def_working_user_id).toInt()
                : 1;
        dr[":f_createtime"] = QTime::currentTime();
    }
    dr[":f_state"] = RESERVE_RESERVE;
    dr[":f_reservestate"] = CONFIRM_CONFIRM;
    dr[":f_arrangement"] = 1;
    dr[":f_mealincluded"] = 0;
    dr[":f_chm"] = chmKey;
    dr[":f_chmstatus"] = 1;
    dr[":f_room"] = roomId;
    dr[":f_group"] = 0;
    dr[":f_guest"] = mainGuestId;
    const int men = room.men > 0 ? room.men : 1;
    const int children = qMax(0, room.children);
    const int babies = qMax(0, room.babies);
    const int bedQty = resolveBedQty(roomId, room.roomTypeCode);
    const bool extraBed = needsExtraBed(men, children, bedQty, room.extraBed);

    dr[":f_man"] = men;
    dr[":f_woman"] = 0;
    dr[":f_child"] = children;
    dr[":f_baby"] = babies;
    dr[":f_cardex"] = cardex;
    dr[":f_cityledger"] = cityLedger;
    dr[":f_booking"] = bookingExt;
    dr[":f_startdate"] = startDate;
    dr[":f_enddate"] = endDate;
    dr[":f_arrivalTime"] = arrivalTime;
    dr[":f_departureTime"] = departureTime;
    dr[":f_roomfee"] = pricePerNight;
    dr[":f_paymenttype"] = paymentType;
    dr[":f_mealqty"] = 1;
    dr[":f_mealprice"] = 0;
    dr[":f_extrabed"] = extraBed ? 1 : 0;
    dr[":f_extrabedfee"] = 0; // fee usually included in AmountAfterTax
    dr[":f_pricepernight"] = pricePerNight;
    dr[":f_vat"] = 20;
    dr[":f_vatamount"] = vatAmount;
    dr[":f_vatmode"] = VAT_INCLUDED;
    dr[":f_total"] = totalAmount;
    dr[":f_grandTotal"] = totalAmount;
    dr[":f_totalusd"] = totalUsd;
    dr[":f_remarks"] = draft.remarks;

    if (isUpdate) {
        if (!dr.update("f_reservation", where_id(ap(existsRes)))) {
            if (roomLocked) {
                dr.rollback();
            }
            if (errorText) {
                *errorText = QObject::tr("Update f_reservation failed: %1").arg(dr.fLastError);
            }
            return false;
        }

        auto moneyStr = [](double v) {
            return QString::number(v, 'f', 2);
        };
        auto trackIf = [&](const QString &action, const QString &oldV, const QString &newV) {
            if (oldV != newV) {
                trackExcely(inId, rsId, action, oldV, newV);
            }
        };

        QString modifiedWhen = draft.lastModifyRaw.trimmed();
        if (modifiedWhen.isEmpty() && draft.lastModify.isValid()) {
            modifiedWhen = draft.lastModify.toString(Qt::ISODate);
        }
        if (modifiedWhen.isEmpty()) {
            modifiedWhen = QDateTime::currentDateTime().toString(Qt::ISODate);
        }
        trackExcely(inId, rsId, QObject::tr("Modified in Excely"), modifiedWhen, QString());

        trackIf(QObject::tr("Entry date"),
                oldStart.isValid() ? oldStart.toString(Qt::ISODate) : QString(),
                startDate.toString(Qt::ISODate));
        trackIf(QObject::tr("Departure date"),
                oldEnd.isValid() ? oldEnd.toString(Qt::ISODate) : QString(),
                endDate.toString(Qt::ISODate));
        trackIf(QObject::tr("Arrival time"),
                oldArrival.isValid() ? oldArrival.toString(QStringLiteral("HH:mm")) : QString(),
                arrivalTime.toString(QStringLiteral("HH:mm")));
        trackIf(QObject::tr("Departure time"),
                oldDeparture.isValid() ? oldDeparture.toString(QStringLiteral("HH:mm")) : QString(),
                departureTime.toString(QStringLiteral("HH:mm")));
        trackIf(QObject::tr("Room"),
                oldRoom > 0 ? QString::number(oldRoom) : QString(),
                roomId > 0 ? QString::number(roomId) : QString());
        trackIf(QObject::tr("Male"), QString::number(oldMan), QString::number(men));
        trackIf(QObject::tr("Childs"), QString::number(oldChild), QString::number(children));
        trackIf(QObject::tr("Babies"), QString::number(oldBaby), QString::number(babies));
        trackIf(QObject::tr("Extra bed"),
                oldExtraBed ? QStringLiteral("1") : QStringLiteral("0"),
                extraBed ? QStringLiteral("1") : QStringLiteral("0"));
        trackIf(QObject::tr("Rate"), moneyStr(oldRoomFee), moneyStr(pricePerNight));
        trackIf(QObject::tr("Price per night"), moneyStr(oldPricePerNight), moneyStr(pricePerNight));
        trackIf(QObject::tr("Grand total"), moneyStr(oldTotal), moneyStr(totalAmount));
        trackIf(QObject::tr("Cardex"), oldCardex, cardex);
        trackIf(QObject::tr("Remarks"), oldRemarks, draft.remarks);
    } else {
        if (!dr.insert("f_reservation", false)) {
            if (roomLocked) {
                dr.rollback();
            }
            if (errorText) {
                *errorText = QObject::tr("Insert f_reservation failed: %1").arg(dr.fLastError);
            }
            return false;
        }
        QString createdInExcely = draft.createDateTimeRaw.trimmed();
        if (createdInExcely.isEmpty() && draft.createDateTime.isValid()) {
            createdInExcely = draft.createDateTime.toString(Qt::ISODate);
        }
        if (createdInExcely.isEmpty()) {
            createdInExcely = QDateTime::currentDateTime().toString(Qt::ISODate);
        }
        trackExcely(inId, rsId, QObject::tr("Created in Excely"), createdInExcely, QString());
    }
    if (roomLocked && !dr.commit()) {
        const QString commitErr = dr.fLastError;
        dr.rollback();
        if (errorText) {
            *errorText = QObject::tr("Commit reservation failed: %1").arg(commitErr);
        }
        return false;
    }

    linkReservationGuests(rsId, mainGuestId, draft);

    const int itemCode = Preferences::getDb(def_reservation_voucher_id).toInt();
    dr[":f_id"] = rsId;
    dr[":f_source"] = VAUCHER_RESERVATION_N;
    dr[":f_res"] = rsId;
    dr[":f_wdate"] = Base::fPreferences.getLocalDate(def_working_day);
    dr[":f_rdate"] = QDate::currentDate();
    dr[":f_time"] = QTime::currentTime();
    dr[":f_user"] = Base::fPreferences.getLocal(def_working_user_id).toInt() > 0
            ? Base::fPreferences.getLocal(def_working_user_id).toInt()
            : 1;
    dr[":f_room"] = roomId;
    dr[":f_guest"] = guestName;
    dr[":f_itemcode"] = itemCode > 0 ? itemCode : 32;
    dr[":f_amountamd"] = totalAmount;
    dr[":f_amountvat"] = vatAmount;
    dr[":f_amountusd"] = dollarRate > 0.0 ? dollarRate : 1.0;
    dr[":f_paymentmode"] = paymentType;
    dr[":f_paymentcomment"] = draft.paymentName.isEmpty()
            ? (paymentType == PAYMENT_CARD ? QStringLiteral("CARD") : QStringLiteral("CASH"))
            : draft.paymentName;
    dr[":f_cityledger"] = cityLedger;
    dr[":f_sign"] = 1;
    dr[":f_inv"] = inId;
    dr[":f_finance"] = 0;
    dr[":f_remarks"] = draft.remarks;
    dr[":f_canceled"] = 0;
    dr[":f_side"] = 0;
    dr[":f_p"] = 0;
    dr[":f_rb"] = 0;
    dr[":f_cash"] = 0;
    if (isUpdate) {
        dr.update("m_register", where_id(ap(rsId)));
    } else {
        dr.insert("m_register", false);
    }

    if (outRsId) {
        *outRsId = rsId;
    }
    return true;
}
