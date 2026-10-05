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
#include "vauchers.h"

#include <QDate>
#include <QObject>
#include <QTime>

ExcelyResortSink::ExcelyResortSink(const QMap<QString, QString> &roomTypeMap)
    : m_roomTypeMap(roomTypeMap)
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

bool ExcelyResortSink::acceptDraft(const Excely::Resort::BookingDraft &draft,
                                   QString *pmsReservationId,
                                   QString *errorText)
{
    m_lastOutcome = Outcome::Failed;
    m_warnings.clear();
    m_touchedReserveIds.clear();
    m_touchedGuestIds.clear();

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

    QString primaryRsId;
    bool anyUpdate = false;
    bool anyCreate = false;

    for (int i = 0; i < work.rooms.size(); ++i) {
        const Excely::Resort::RoomDraft &room = work.rooms.at(i);
        QString chmKey = work.chmId;
        if (work.rooms.size() > 1) {
            const QString idx = room.indexNumber.isEmpty()
                    ? QString::number(i + 1)
                    : room.indexNumber;
            chmKey = work.chmId + QStringLiteral("#") + idx;
        }

        QString existsRes;
        QString existsIn;
        dr[":f_chm"] = chmKey;
        dr.exec("select f_id, f_invoice from f_reservation where f_chm=:f_chm");
        if (dr.nextRow()) {
            existsRes = dr.getString("f_id");
            existsIn = dr.getString("f_invoice");
        }
        // Fallback: single-room booking previously stored under bare chmId
        if (existsRes.isEmpty() && work.rooms.size() == 1) {
            dr[":f_chm"] = work.chmId;
            dr.exec("select f_id, f_invoice from f_reservation where f_chm=:f_chm");
            if (dr.nextRow()) {
                existsRes = dr.getString("f_id");
                existsIn = dr.getString("f_invoice");
                chmKey = work.chmId;
            }
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
        if (primaryRsId.isEmpty()) {
            primaryRsId = rsId;
        }
        m_touchedReserveIds.append(rsId);
        if (isUpdate) {
            anyUpdate = true;
        } else {
            anyCreate = true;
        }
    }

    if (anyCreate && !anyUpdate) {
        m_lastOutcome = Outcome::Created;
    } else if (anyUpdate && !anyCreate) {
        m_lastOutcome = Outcome::Updated;
    } else {
        m_lastOutcome = anyCreate ? Outcome::Created : Outcome::Updated;
    }

    if (pmsReservationId) {
        *pmsReservationId = primaryRsId;
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
    QStringList invoices;

    dr[":f_chm"] = draft.chmId;
    dr[":f_chm_like"] = draft.chmId + QStringLiteral("#%");
    dr.exec("select f_id, f_invoice from f_reservation where f_chm=:f_chm or f_chm like :f_chm_like");
    while (dr.nextRow()) {
        ids.append(dr.getString("f_id"));
        invoices.append(dr.getString("f_invoice"));
    }

    if (ids.isEmpty()) {
        m_lastOutcome = Outcome::Canceled;
        if (pmsReservationId) {
            *pmsReservationId = draft.chmId;
        }
        m_warnings.append(QObject::tr("%1: cancel — no local reservation found (confirm only)")
                              .arg(draft.chmId));
        return true;
    }

    for (int i = 0; i < ids.size(); ++i) {
        const QString rsId = ids.at(i);
        const QString inId = invoices.at(i);
        dr[":f_id"] = rsId;
        dr[":f_state"] = RESERVE_REMOVED;
        dr[":f_canceluser"] = Base::fPreferences.getLocal(def_working_user_id).toInt() > 0
                ? Base::fPreferences.getLocal(def_working_user_id).toInt()
                : 1;
        dr[":f_canceldate"] = QDate::currentDate();
        dr.update("f_reservation", where_id(ap(rsId)));

        dr[":f_id"] = rsId;
        dr[":f_reason"] = QObject::tr("Cancelled by Excely");
        dr.insert("f_reservation_cancel_reason");

        m_touchedReserveIds.append(rsId);
        BroadcastThread::cmdRefreshCache(cid_reservation, rsId);
        BroadcastThread::cmdRefreshCache(cid_room, QStringLiteral("0"));
        BroadcastThread::cmdRefreshCache(45, rsId);
        Q_UNUSED(inId);
    }

    m_lastOutcome = Outcome::Canceled;
    if (pmsReservationId) {
        *pmsReservationId = ids.first();
    }
    return true;
}

int ExcelyResortSink::ensureGuest(const Excely::Resort::GuestDraft &g)
{
    DoubleDatabase dr;
    if (!g.email.isEmpty()) {
        dr[":f_email"] = g.email;
        dr.exec("select f_id from f_guests where f_email=:f_email");
        if (dr.nextRow()) {
            const int id = dr.getInt("f_id");
            dr[":f_firstname"] = g.firstName.toUpper();
            dr[":f_lastname"] = g.lastName.toUpper();
            if (!g.phone.isEmpty()) {
                dr[":f_tel1"] = g.phone;
            }
            if (!g.nationShort.isEmpty()) {
                dr[":f_nation"] = g.nationShort;
            }
            dr.update("f_guests", where_id(id));
            return id;
        }
    }

    dr[":f_title"] = QString();
    dr[":f_firstname"] = g.firstName.toUpper();
    dr[":f_lastname"] = g.lastName.toUpper();
    dr[":f_sex"] = 1;
    dr[":f_nation"] = g.nationShort;
    dr[":f_passport"] = QString();
    dr[":f_email"] = g.email;
    dr[":f_tel1"] = g.phone;
    return dr.insert("f_guests");
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
                                   QString *warn)
{
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

    const QString classKey = m_roomTypeMap.value(roomTypeCode);
    DoubleDatabase dr;
    QList<int> checkRooms;
    bool okInt = false;
    const int classId = classKey.toInt(&okInt);
    if (okInt && classId > 0) {
        dr[":f_class"] = classId;
        dr.exec("select f_id from f_room where f_class=:f_class order by f_id");
    } else {
        dr[":f_short"] = classKey;
        dr.exec("select f_id from f_room where f_class in "
                "(select f_id from f_room_classes where f_short=:f_short) order by f_id");
    }
    while (dr.nextRow()) {
        checkRooms.append(dr.getInt("f_id"));
    }
    if (checkRooms.isEmpty()) {
        if (warn) {
            *warn = QObject::tr("no rooms for class %1 (CM %2)").arg(classKey, roomTypeCode);
        }
        return 0;
    }

    CacheReservation cr;
    cr.fInstance = cache(cid_reservation);
    if (cr.fInstance) {
        cr.fInstance->load();
    }
    QMap<QString, CacheReservation> reserveOut;
    for (int tempRoom : checkRooms) {
        bool startOk = true;
        bool endOk = true;
        cr.check(start, end, tempRoom, reserveOut, startOk, endOk, excludeReserveId);
        if (startOk && endOk) {
            return tempRoom;
        }
    }
    if (warn) {
        *warn = QObject::tr("no free room for class %1 / CM %2 on %3–%4")
                    .arg(classKey, roomTypeCode,
                         start.toString(Qt::ISODate),
                         end.toString(Qt::ISODate));
    }
    return 0;
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
    double totalAmount = room.total > 0.0 ? room.total : draft.grandTotal;
    double pricePerNight = room.roomFee;
    if (pricePerNight <= 0.0 && totalAmount > 0.0) {
        pricePerNight = totalAmount / nights;
    }

    QString roomWarn;
    const int roomId = findFreeRoom(room.roomTypeCode, startDate, endDate,
                                    isUpdate ? existsRes : QString(), &roomWarn);
    if (roomId == 0 && !roomWarn.isEmpty()) {
        m_warnings.append(QObject::tr("%1: %2 — left unassigned").arg(chmKey, roomWarn));
    }

    QString rsId;
    QString inId;
    if (isUpdate) {
        rsId = existsRes;
        inId = existsIn;
    } else {
        rsId = uuidx(VAUCHER_RESERVATION_N);
        inId = uuidx(QStringLiteral("IN"));
    }

    const double vatAmount = totalAmount - (totalAmount / ((20.0 / 100.0) + 1.0));
    const QString guestName = (draft.mainGuest.firstName + QLatin1Char(' ')
                               + draft.mainGuest.lastName)
                                  .trimmed();
    const QString bookingExt = draft.bookingExternalId.isEmpty()
            ? draft.chmId
            : draft.bookingExternalId;

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
    dr[":f_man"] = room.men > 0 ? room.men : 1;
    dr[":f_woman"] = 0;
    dr[":f_child"] = room.children;
    dr[":f_baby"] = 0;
    dr[":f_cardex"] = cardex;
    dr[":f_cityledger"] = cityLedger;
    dr[":f_booking"] = bookingExt;
    dr[":f_startdate"] = startDate;
    dr[":f_enddate"] = endDate;
    dr[":f_roomfee"] = pricePerNight;
    dr[":f_paymenttype"] = paymentType;
    dr[":f_mealqty"] = 1;
    dr[":f_mealprice"] = 0;
    dr[":f_extrabed"] = 0;
    dr[":f_extrabedfee"] = 0;
    dr[":f_pricepernight"] = pricePerNight;
    dr[":f_vat"] = 20;
    dr[":f_vatamount"] = vatAmount;
    dr[":f_vatmode"] = VAT_INCLUDED;
    dr[":f_total"] = totalAmount;
    dr[":f_grandTotal"] = totalAmount;
    dr[":f_totalusd"] = totalAmount / dollarRate;
    dr[":f_remarks"] = draft.remarks;

    if (isUpdate) {
        if (!dr.update("f_reservation", where_id(ap(existsRes)))) {
            if (errorText) {
                *errorText = QObject::tr("Update f_reservation failed: %1").arg(dr.fLastError);
            }
            return false;
        }
        dr[":f_reservation"] = existsRes;
        dr.exec("delete from f_reservation_guests where f_reservation=:f_reservation");
    } else {
        if (!dr.insert("f_reservation", false)) {
            if (errorText) {
                *errorText = QObject::tr("Insert f_reservation failed: %1").arg(dr.fLastError);
            }
            return false;
        }
    }

    dr[":f_reservation"] = rsId;
    dr[":f_guest"] = mainGuestId;
    dr[":f_first"] = 1;
    dr.insert("f_reservation_guests", false);

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
    dr[":f_amountusd"] = dollarRate;
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
