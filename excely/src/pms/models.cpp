#include "excely/pms/models.h"

#include "excely/pms/xmlhelpers.h"

#include <QDateTime>
#include <QHash>

namespace Excely {
namespace Pms {

using namespace Xml;

static Channel::BookingStatus parseStatus(const QString &s)
{
    if (s.compare(QLatin1String("Unconfirmed"), Qt::CaseInsensitive) == 0) return Channel::BookingStatus::Unconfirmed;
    if (s.compare(QLatin1String("Confirmed"), Qt::CaseInsensitive) == 0) return Channel::BookingStatus::Confirmed;
    if (s.compare(QLatin1String("Cancelled"), Qt::CaseInsensitive) == 0) return Channel::BookingStatus::Cancelled;
    if (s.compare(QLatin1String("Canceled"), Qt::CaseInsensitive) == 0) return Channel::BookingStatus::Cancelled;
    if (s.compare(QLatin1String("Released"), Qt::CaseInsensitive) == 0) return Channel::BookingStatus::Released;
    if (s.compare(QLatin1String("Pending"), Qt::CaseInsensitive) == 0) return Channel::BookingStatus::Pending;
    if (s.compare(QLatin1String("Reserved"), Qt::CaseInsensitive) == 0) return Channel::BookingStatus::Reserved;
    if (s.compare(QLatin1String("RequestDenied"), Qt::CaseInsensitive) == 0) return Channel::BookingStatus::RequestDenied;
    if (s.compare(QLatin1String("Requestdenied"), Qt::CaseInsensitive) == 0) return Channel::BookingStatus::RequestDenied;
    return Channel::BookingStatus::Unknown;
}

static QDateTime parseOtaDateTime(const QString &s)
{
    if (s.isEmpty()) return {};
    QDateTime dt = QDateTime::fromString(s, Qt::ISODate);
    if (!dt.isValid()) {
        dt = QDateTime::fromString(s, QStringLiteral("yyyy-MM-ddTHH:mm:ss"));
    }
    if (!dt.isValid()) {
        // Some samples: "30.01.2014 0:00:00"
        dt = QDateTime::fromString(s, QStringLiteral("dd.MM.yyyy H:mm:ss"));
    }
    return dt;
}

static void collectErrors(QXmlStreamReader &r, QVector<Channel::PmsError> *errors)
{
    if (!errors) {
        skipElement(r);
        return;
    }
    const QString endName = r.name().toString();
    while (!r.atEnd()) {
        r.readNext();
        if (r.isEndElement() && r.name() == endName) {
            break;
        }
        if (isStart(r, "Error") || isStart(r, "Warning")) {
            Channel::PmsError e;
            e.type = attr(r, "Type").toInt();
            e.code = attr(r, "Code").toInt();
            e.tag = attr(r, "Tag");
            e.text = r.readElementText(QXmlStreamReader::IncludeChildElements).trimmed();
            errors->append(e);
        }
    }
}

bool parseSuccessOrErrors(const QByteArray &xml,
                          const QString &rootLocalName,
                          QVector<Channel::PmsError> *errors,
                          bool *hasSuccess)
{
    if (hasSuccess) *hasSuccess = false;
    QXmlStreamReader r(xml);
    bool foundRoot = false;
    while (!r.atEnd()) {
        r.readNext();
        if (isStart(r, rootLocalName.toUtf8().constData())
                || (r.isStartElement() && r.name() == rootLocalName)) {
            foundRoot = true;
        }
        if (!foundRoot) continue;
        if (isStart(r, "Success")) {
            if (hasSuccess) *hasSuccess = true;
            skipElement(r);
        } else if (isStart(r, "Errors") || isStart(r, "Warnings")) {
            collectErrors(r, errors);
        }
    }
    return !r.hasError();
}

static void parseGuestPerson(QXmlStreamReader &r, Channel::Guest *g)
{
    while (!(r.isEndElement() && r.name() == QLatin1String("Customer"))) {
        r.readNext();
        if (r.atEnd()) break;
        if (isStart(r, "GivenName")) g->firstName = r.readElementText().trimmed();
        else if (isStart(r, "MiddleName")) g->middleName = r.readElementText().trimmed();
        else if (isStart(r, "Surname")) g->lastName = r.readElementText().trimmed();
        else if (isStart(r, "Email")) {
            const QString e = r.readElementText().trimmed();
            if (g->email.isEmpty()) g->email = e;
        } else if (isStart(r, "Telephone")) {
            const QString p = attr(r, "PhoneNumber");
            if (g->phone.isEmpty()) g->phone = p;
            skipElement(r);
        } else if (isStart(r, "CitizenCountryName")) {
            const QString code = attr(r, "Code").trimmed();
            if (!code.isEmpty()) {
                g->countryCode = code;
            }
            skipElement(r);
        } else if (isStart(r, "Address")) {
            // Descend — CountryName may be nested
            continue;
        } else if (isStart(r, "CountryName")) {
            QString code = attr(r, "Code").trimmed();
            if (code.isEmpty()) {
                code = r.readElementText().trimmed();
            } else {
                skipElement(r);
            }
            if (g->countryCode.isEmpty() && !code.isEmpty()) {
                g->countryCode = code;
            }
        } else if (isStart(r, "PersonName")) {
            // Descend into PersonName — GivenName/Surname are children
            continue;
        } else if (r.isStartElement()) {
            skipElement(r);
        }
    }
}

QString buildOtaReadRqXml(const QString &hotelCode, const QString &version)
{
    return QStringLiteral(
        "<OTA_ReadRQ xmlns=\"http://www.opentravel.org/OTA/2003/05\" Version=\"%1\">"
        "<ReadRequests>"
        "<HotelReadRequest HotelCode=\"%2\">"
        "<SelectionCriteria SelectionType=\"Undelivered\"/>"
        "</HotelReadRequest>"
        "</ReadRequests>"
        "</OTA_ReadRQ>")
        .arg(escape(version), escape(hotelCode));
}

QString buildOtaPingRqXml(const QString &hotelCode, const QString &version)
{
    return QStringLiteral(
        "<OTA_PingRQ xmlns=\"http://www.opentravel.org/OTA/2003/05\" Version=\"%1\">"
        "<EchoData HotelCode=\"%2\">SmartHotel</EchoData>"
        "</OTA_PingRQ>")
        .arg(escape(version), escape(hotelCode));
}

QString buildOtaHotelAvailRqXml(const QString &hotelCode, const QString &version)
{
    return QStringLiteral(
        "<OTA_HotelAvailRQ xmlns=\"http://www.opentravel.org/OTA/2003/05\" Version=\"%1\" "
        "TimeStamp=\"%2\">"
        "<AvailRequestSegments>"
        "<AvailRequestSegment>"
        "<HotelSearchCriteria>"
        "<Criterion>"
        "<HotelRef HotelCode=\"%3\"/>"
        "</Criterion>"
        "</HotelSearchCriteria>"
        "</AvailRequestSegment>"
        "</AvailRequestSegments>"
        "</OTA_HotelAvailRQ>")
        .arg(escape(version),
             QDateTime::currentDateTime().toString(Qt::ISODate),
             escape(hotelCode));
}

QString buildOtaHotelAvailNotifRqXml(const QString &hotelCode,
                                     const QString &version,
                                     const QVector<AvailStatusMessage> &messages)
{
    QString msgs;
    for (const AvailStatusMessage &m : messages) {
        QString limitAttr;
        if (m.sendBookingLimit) {
            limitAttr = QStringLiteral(" BookingLimit=\"%1\"").arg(m.bookingLimit);
        }
        QString sac = QStringLiteral(
            "<StatusApplicationControl Start=\"%1\" End=\"%2\" InvTypeCode=\"%3\"")
                          .arg(escape(m.start.toString(Qt::ISODate)),
                               escape(m.end.toString(Qt::ISODate)),
                               escape(m.invTypeCode));
        if (!m.ratePlanCode.isEmpty()) {
            sac += QStringLiteral(" RatePlanCode=\"%1\"").arg(escape(m.ratePlanCode));
        } else if (!m.invBlockCode.isEmpty()) {
            sac += QStringLiteral(" InvBlockCode=\"%1\"").arg(escape(m.invBlockCode));
        }
        sac += QStringLiteral("/>");

        QString restriction;
        if (!m.restrictionStatus.isEmpty()) {
            restriction = QStringLiteral("<RestrictionStatus Status=\"%1\"/>")
                              .arg(escape(m.restrictionStatus));
        }

        QString los;
        if (m.minLOS > 0) {
            los = QStringLiteral(
                "<LengthsOfStay>"
                "<LengthOfStay MinMaxMessageType=\"SetMinLOS\" Time=\"%1\" TimeUnit=\"Day\"/>"
                "</LengthsOfStay>")
                      .arg(m.minLOS);
        } else if (m.minLOS == 0) {
            // Clear previously set MinLOS (Exely certification: Open alone does not remove it)
            los = QStringLiteral(
                "<LengthsOfStay>"
                "<LengthOfStay MinMaxMessageType=\"RemoveMinLOS\"/>"
                "</LengthsOfStay>");
        }

        msgs += QStringLiteral("<AvailStatusMessage%1>%2%3%4</AvailStatusMessage>")
                    .arg(limitAttr, sac, restriction, los);
    }

    return QStringLiteral(
        "<OTA_HotelAvailNotifRQ xmlns=\"http://www.opentravel.org/OTA/2003/05\" "
        "Version=\"%1\" TimeStamp=\"%2\">"
        "<AvailStatusMessages HotelCode=\"%3\">"
        "%4"
        "</AvailStatusMessages>"
        "</OTA_HotelAvailNotifRQ>")
        .arg(escape(version),
             QDateTime::currentDateTime().toString(Qt::ISODate),
             escape(hotelCode),
             msgs);
}

QString buildOtaHotelRateAmountNotifRqXml(const QString &hotelCode,
                                          const QString &version,
                                          const QVector<RateAmountMessage> &messages)
{
    QString msgs;
    for (const RateAmountMessage &m : messages) {
        QVector<QPair<int, double>> bases = m.baseByGuestAmts;
        if (bases.isEmpty() && m.amountAfterTax > 0.0) {
            bases.append(qMakePair(qMax(1, m.numberOfGuests), m.amountAfterTax));
        }

        QString baseXml;
        if (!bases.isEmpty()) {
            baseXml = QStringLiteral("<BaseByGuestAmts>");
            for (const auto &b : bases) {
                baseXml += QStringLiteral(
                    "<BaseByGuestAmt AmountAfterTax=\"%1\" NumberOfGuests=\"%2\" CurrencyCode=\"%3\"/>")
                               .arg(QString::number(b.second, 'f', 2),
                                    QString::number(qMax(1, b.first)),
                                    escape(m.currencyCode));
            }
            baseXml += QStringLiteral("</BaseByGuestAmts>");
        }

        QString addXml;
        if (!m.additionalGuests.isEmpty()) {
            addXml = QStringLiteral("<AdditionalGuestAmounts>");
            for (const AdditionalGuestAmount &a : m.additionalGuests) {
                const QString cur = a.currencyCode.isEmpty() ? m.currencyCode : a.currencyCode;
                QString attrs = QStringLiteral("AmountAfterTax=\"%1\" CurrencyCode=\"%2\"")
                                    .arg(QString::number(a.amountAfterTax, 'f', 2), escape(cur));
                if (a.maxAdditionalGuests > 0) {
                    attrs += QStringLiteral(" MaxAdditionalGuests=\"%1\"")
                                 .arg(a.maxAdditionalGuests);
                }
                if (a.sendBedRequired) {
                    attrs += QStringLiteral(" BedRequired=\"%1\"")
                                 .arg(a.bedRequired ? QStringLiteral("true")
                                                    : QStringLiteral("false"));
                }
                if (a.ageQualifyingCode > 0) {
                    attrs += QStringLiteral(" AgeQualifyingCode=\"%1\"")
                                 .arg(a.ageQualifyingCode);
                }
                if (a.ageBucket >= 0) {
                    attrs += QStringLiteral(" AgeBucket=\"%1\"").arg(a.ageBucket);
                }
                if (a.minAge >= 0) {
                    attrs += QStringLiteral(" MinAge=\"%1\"").arg(a.minAge);
                }
                if (a.maxAge >= 0) {
                    attrs += QStringLiteral(" MaxAge=\"%1\"").arg(a.maxAge);
                }
                addXml += QStringLiteral("<AdditionalGuestAmount %1/>").arg(attrs);
            }
            addXml += QStringLiteral("</AdditionalGuestAmounts>");
        }

        msgs += QStringLiteral(
            "<RateAmountMessage>"
            "<StatusApplicationControl InvTypeCode=\"%1\" RatePlanCode=\"%2\"/>"
            "<Rates>"
            "<Rate Start=\"%3\" End=\"%4\">"
            "%5%6"
            "</Rate>"
            "</Rates>"
            "</RateAmountMessage>")
                    .arg(escape(m.invTypeCode),
                         escape(m.ratePlanCode),
                         escape(m.start.toString(Qt::ISODate)),
                         escape(m.end.toString(Qt::ISODate)),
                         baseXml,
                         addXml);
    }

    return QStringLiteral(
        "<OTA_HotelRateAmountNotifRQ xmlns=\"http://www.opentravel.org/OTA/2003/05\" "
        "Version=\"%1\" TimeStamp=\"%2\">"
        "<RateAmountMessages HotelCode=\"%3\">"
        "%4"
        "</RateAmountMessages>"
        "</OTA_HotelRateAmountNotifRQ>")
        .arg(escape(version),
             QDateTime::currentDateTime().toString(Qt::ISODate),
             escape(hotelCode),
             msgs);
}

QString buildOtaCancelRqXml(const QString &version,
                            const QString &channelReservationId,
                            const QString &reason)
{
    const QString reasonText = reason.trimmed().isEmpty()
            ? QStringLiteral("Cancelled by PMS")
            : reason.trimmed();
    return QStringLiteral(
        "<OTA_CancelRQ xmlns=\"http://www.opentravel.org/OTA/2003/05\" Version=\"%1\">"
        "<UniqueID ID=\"%2\" ID_Context=\"PMSConnect\" Reason=\"%3\"/>"
        "</OTA_CancelRQ>")
        .arg(escape(version),
             escape(channelReservationId),
             escape(reasonText));
}

QString buildOtaNotifReportReservedXml(const QString &hotelCode,
                                       const QString &version,
                                       const QString &uniqueId,
                                       const QString &createDateTime,
                                       const QString &lastModifyDateTime,
                                       const QString &pmsReservationId,
                                       const QStringList &roomStayIndexNumbers)
{
    QString roomStays;
    for (const QString &idx : roomStayIndexNumbers) {
        if (idx.trimmed().isEmpty()) continue;
        roomStays += QStringLiteral("<RoomStay IndexNumber=\"%1\"/>").arg(escape(idx));
    }
    QString roomStaysBlock;
    if (!roomStays.isEmpty()) {
        roomStaysBlock = QStringLiteral("<RoomStays>%1</RoomStays>").arg(roomStays);
    }
    return QStringLiteral(
        "<OTA_NotifReportRQ xmlns=\"http://www.opentravel.org/OTA/2003/05\" Version=\"%1\">"
        "<Success/>"
        "<NotifDetails HotelCode=\"%2\">"
        "<HotelNotifReport>"
        "<HotelReservations>"
        "<HotelReservation CreateDateTime=\"%3\" LastModifyDateTime=\"%4\" ResStatus=\"Reserved\">"
        "<UniqueID Type=\"14\" ID=\"%5\"/>"
        "%6"
        "<ResGlobalInfo>"
        "<HotelReservationIDs>"
        "<HotelReservationID ResID_Type=\"14\" ResID_Value=\"%7\"/>"
        "</HotelReservationIDs>"
        "</ResGlobalInfo>"
        "</HotelReservation>"
        "</HotelReservations>"
        "</HotelNotifReport>"
        "</NotifDetails>"
        "</OTA_NotifReportRQ>")
        .arg(escape(version),
             escape(hotelCode),
             escape(createDateTime),
             escape(lastModifyDateTime),
             escape(uniqueId),
             roomStaysBlock,
             escape(pmsReservationId));
}

QString buildOtaNotifReportReservedRoomsXml(const QString &hotelCode,
                                            const QString &version,
                                            const QString &uniqueId,
                                            const QString &createDateTime,
                                            const QString &lastModifyDateTime,
                                            const QVector<Channel::RoomConfirmation> &rooms)
{
    QStringList pmsIds;
    QHash<QString, QStringList> indexesByPms;
    for (const Channel::RoomConfirmation &rc : rooms) {
        if (!indexesByPms.contains(rc.pmsReservationId)) {
            pmsIds.append(rc.pmsReservationId);
        }
        QStringList &idx = indexesByPms[rc.pmsReservationId];
        if (!rc.indexNumber.trimmed().isEmpty()) {
            idx.append(rc.indexNumber);
        }
    }

    QString reservations;
    for (const QString &pmsId : pmsIds) {
        QString roomStays;
        for (const QString &idx : indexesByPms.value(pmsId)) {
            roomStays += QStringLiteral("<RoomStay IndexNumber=\"%1\"/>").arg(escape(idx));
        }
        if (!roomStays.isEmpty()) {
            roomStays = QStringLiteral("<RoomStays>%1</RoomStays>").arg(roomStays);
        }
        reservations += QStringLiteral(
            "<HotelReservation CreateDateTime=\"%1\" LastModifyDateTime=\"%2\" ResStatus=\"Reserved\">"
            "<UniqueID Type=\"14\" ID=\"%3\"/>"
            "%4"
            "<ResGlobalInfo>"
            "<HotelReservationIDs>"
            "<HotelReservationID ResID_Type=\"14\" ResID_Value=\"%5\"/>"
            "</HotelReservationIDs>"
            "</ResGlobalInfo>"
            "</HotelReservation>")
            .arg(escape(createDateTime),
                 escape(lastModifyDateTime),
                 escape(uniqueId),
                 roomStays,
                 escape(pmsId));
    }

    return QStringLiteral(
        "<OTA_NotifReportRQ xmlns=\"http://www.opentravel.org/OTA/2003/05\" Version=\"%1\">"
        "<Success/>"
        "<NotifDetails HotelCode=\"%2\">"
        "<HotelNotifReport>"
        "<HotelReservations>%3</HotelReservations>"
        "</HotelNotifReport>"
        "</NotifDetails>"
        "</OTA_NotifReportRQ>")
        .arg(escape(version), escape(hotelCode), reservations);
}

QString buildOtaNotifReportDeniedXml(const QString &hotelCode,
                                     const QString &version,
                                     const QString &uniqueId,
                                     const QString &createDateTime,
                                     const QString &lastModifyDateTime,
                                     const QString &reason)
{
    return QStringLiteral(
        "<OTA_NotifReportRQ xmlns=\"http://www.opentravel.org/OTA/2003/05\" Version=\"%1\">"
        "<Success/>"
        "<NotifDetails HotelCode=\"%2\">"
        "<HotelNotifReport>"
        "<HotelReservations>"
        "<HotelReservation CreateDateTime=\"%3\" LastModifyDateTime=\"%4\" ResStatus=\"RequestDenied\">"
        "<UniqueID Type=\"14\" ID=\"%5\"/>"
        "<ResGlobalInfo>"
        "<Comments><Comment><Text>%6</Text></Comment></Comments>"
        "</ResGlobalInfo>"
        "</HotelReservation>"
        "</HotelReservations>"
        "</HotelNotifReport>"
        "</NotifDetails>"
        "</OTA_NotifReportRQ>")
        .arg(escape(version),
             escape(hotelCode),
             escape(createDateTime),
             escape(lastModifyDateTime),
             escape(uniqueId),
             escape(reason));
}

bool parseResRetrieveRs(const QByteArray &xml,
                        QVector<Channel::Booking> *out,
                        QVector<Channel::PmsError> *errors)
{
    if (!out) return false;
    out->clear();

    QXmlStreamReader r(xml);
    Channel::Booking cur;
    Channel::RoomStay room;
    Channel::Guest guest;
    bool inResGuests = false;
    bool inResGlobalInfo = false;
    bool inRoomStay = false;
    bool haveBooking = false;

    auto flushRoom = [&]() {
        if (inRoomStay) {
            cur.rooms.append(room);
            inRoomStay = false;
        }
    };
    auto flushGuest = [&]() {
        if (inResGuests) {
            cur.guests.append(guest);
            guest = Channel::Guest{};
        }
    };
    auto flushBooking = [&]() {
        flushRoom();
        if (haveBooking) {
            if (cur.mainGuest.lastName.isEmpty() && !cur.guests.isEmpty()) {
                cur.mainGuest = cur.guests.first();
            }
            if (cur.totalAfterTax <= 0.0) {
                for (const Channel::RoomStay &rs : cur.rooms) {
                    cur.totalAfterTax += rs.amountAfterTax;
                }
            }
            cur.action = Channel::Booking::actionFromStatus(cur.status);
            if (cur.status == Channel::BookingStatus::Cancelled) {
                cur.action = Channel::BookingAction::Cancel;
            }
            cur.channelId = QStringLiteral("exely");
            out->append(cur);
            haveBooking = false;
        }
    };

    while (!r.atEnd()) {
        r.readNext();
        if (r.hasError()) {
            return false;
        }

        if (isStart(r, "Errors") || isStart(r, "Warnings")) {
            collectErrors(r, errors);
            continue;
        }
        if (isStart(r, "Success")) {
            skipElement(r);
            continue;
        }

        if (isStart(r, "HotelReservation")) {
            flushBooking();
            cur = Channel::Booking{};
            haveBooking = true;
            cur.status = parseStatus(attr(r, "ResStatus"));
            cur.createDateTimeRaw = attr(r, "CreateDateTime");
            cur.lastModifyDateTimeRaw = attr(r, "LastModifyDateTime");
            cur.createDateTime = parseOtaDateTime(cur.createDateTimeRaw);
            cur.lastModifyDateTime = parseOtaDateTime(cur.lastModifyDateTimeRaw);
            continue;
        }
        if (isEnd(r, "HotelReservation")) {
            flushBooking();
            continue;
        }

        if (!haveBooking) continue;

        if (isStart(r, "UniqueID")) {
            const QString id = attr(r, "ID");
            const QString ctx = attr(r, "ID_Context");
            if (ctx.compare(QLatin1String("External"), Qt::CaseInsensitive) == 0) {
                if (cur.externalReservationId.isEmpty()) cur.externalReservationId = id;
            } else if (cur.channelReservationId.isEmpty()) {
                cur.channelReservationId = id;
            }
            skipElement(r);
            continue;
        }
        if (isStart(r, "CompanyName")) {
            if (cur.companyCode.isEmpty()) cur.companyCode = attr(r, "Code");
            if (cur.companyName.isEmpty()) {
                cur.companyName = attr(r, "CompanyShortName");
                const QString text = r.readElementText().trimmed();
                if (cur.companyName.isEmpty()) cur.companyName = text;
                if (cur.bookingChannelCode.isEmpty()) cur.bookingChannelCode = cur.companyCode;
            } else {
                skipElement(r);
            }
            continue;
        }
        if (isStart(r, "BookingChannel")) {
            // Primary attribute optional
            skipElement(r);
            continue;
        }
        if (isStart(r, "Guarantee")) {
            cur.guaranteeCode = attr(r, "GuaranteeCode");
            // walk children for payment comments
            while (!(r.isEndElement() && r.name() == QLatin1String("Guarantee"))) {
                r.readNext();
                if (r.atEnd()) break;
                if (isStart(r, "Comment")) {
                    const QString name = attr(r, "Name");
                    // next Text
                    QString text;
                    while (!(r.isEndElement() && r.name() == QLatin1String("Comment"))) {
                        r.readNext();
                        if (isStart(r, "Text")) text = r.readElementText().trimmed();
                    }
                    if (name == QLatin1String("PaymentMethodName")) cur.paymentMethodName = text;
                    else if (name == QLatin1String("PaymentSystemName")) cur.paymentSystemName = text;
                    else if (name == QLatin1String("PaymentSystemTitle")) cur.paymentSystemTitle = text;
                }
            }
            continue;
        }
        if (isStart(r, "GuaranteePayment")) {
            Channel::Deposit d;
            d.type = attr(r, "Type");
            d.paymentIndex = attr(r, "PaymentIndex").isEmpty() ? -1 : attr(r, "PaymentIndex").toInt();
            while (!(r.isEndElement() && r.name() == QLatin1String("GuaranteePayment"))) {
                r.readNext();
                if (isStart(r, "AmountPercent")) {
                    d.amount = attr(r, "Amount").toDouble();
                    d.currencyCode = attr(r, "CurrencyCode");
                    skipElement(r);
                }
            }
            cur.deposits.append(d);
            continue;
        }
        if (isStart(r, "RoomStay")) {
            flushRoom();
            room = Channel::RoomStay{};
            room.indexNumber = attr(r, "IndexNumber");
            inRoomStay = true;
            continue;
        }
        if (isEnd(r, "RoomStay")) {
            flushRoom();
            continue;
        }
        if (inRoomStay && isStart(r, "RoomType")) {
            room.roomTypeCode = attr(r, "RoomTypeCode");
            room.invBlockCode = attr(r, "InvBlockCode");
            skipElement(r);
            continue;
        }
        if (inRoomStay && (isStart(r, "RatePlan") || isStart(r, "RoomRate"))) {
            if (room.ratePlanCode.isEmpty()) {
                QString rp = attr(r, "RatePlanCode");
                if (rp.isEmpty()) rp = attr(r, "RatePlanID");
                room.ratePlanCode = rp;
            }
            if (isStart(r, "RoomRate")) {
                // daily rate — keep last AmountAfterTax on nested Total if present later
            }
            // don't skip whole RoomRate — need Total
            continue;
        }
        if (inRoomStay && isStart(r, "TimeSpan")) {
            room.arrival = parseOtaDateTime(attr(r, "Start"));
            room.departure = parseOtaDateTime(attr(r, "End"));
            const QString dur = attr(r, "Duration");
            if (!dur.isEmpty()) room.nights = dur.toInt();
            skipElement(r);
            continue;
        }
        if (inRoomStay && isStart(r, "GuestCount")) {
            const QString aqc = attr(r, "AgeQualifyingCode");
            const int count = qMax(1, attr(r, "Count").toInt());
            const QString ageRaw = attr(r, "Age").trimmed();
            bool ageOk = false;
            const int ageYears = ageRaw.toInt(&ageOk);
            // AdultExtraBed / ChildBandExtraBed → channel flag (host also compares vs f_bedQty)
            if (aqc.contains(QLatin1String("ExtraBed"), Qt::CaseInsensitive)) {
                room.extraBed = true;
            }
            if (aqc.contains(QLatin1String("Adult"), Qt::CaseInsensitive)) {
                room.adults += count;
            } else if (ageOk && ageYears >= 0 && ageYears <= 2) {
                // Age 0–2 → f_baby (no bed, not counted toward occupancy beds)
                room.babies += count;
            } else {
                // Age > 2 or omitted → f_child (needs a bed, up to 18)
                room.children += count;
            }
            skipElement(r);
            continue;
        }
        if (isStart(r, "Total")) {
            const double amt = attr(r, "AmountAfterTax").toDouble();
            const QString curCode = attr(r, "CurrencyCode");
            if (inRoomStay) {
                // Prefer RoomStay-level total; RoomRate totals may overwrite with last day — accumulate if under RoomRates
                room.amountAfterTax = amt;
                if (!curCode.isEmpty()) room.currencyCode = curCode;
            } else if (inResGlobalInfo || !inRoomStay) {
                cur.totalAfterTax = amt;
                if (!curCode.isEmpty()) cur.currencyCode = curCode;
            }
            skipElement(r);
            continue;
        }
        if (isStart(r, "ResGuests")) {
            inResGuests = true;
            continue;
        }
        if (isEnd(r, "ResGuests")) {
            inResGuests = false;
            continue;
        }
        if (isStart(r, "ResGuest")) {
            guest = Channel::Guest{};
            continue;
        }
        if (isEnd(r, "ResGuest")) {
            flushGuest();
            continue;
        }
        if (isStart(r, "ResGlobalInfo")) {
            inResGlobalInfo = true;
            continue;
        }
        if (isEnd(r, "ResGlobalInfo")) {
            inResGlobalInfo = false;
            continue;
        }
        if (isStart(r, "Customer") && (inResGuests || inResGlobalInfo)) {
            Channel::Guest *target = inResGuests ? &guest : &cur.mainGuest;
            parseGuestPerson(r, target);
            continue;
        }
        if (isStart(r, "Text")) {
            const QString t = r.readElementText().trimmed();
            if (!t.isEmpty()) {
                if (cur.comment.isEmpty()) cur.comment = t;
                cur.fullComment = t;
            }
            continue;
        }
        if (isStart(r, "BasicPropertyInfo")) {
            cur.hotelCode = attr(r, "HotelCode");
            skipElement(r);
            continue;
        }
    }

    flushBooking();
    return true;
}

bool parseHotelAvailRs(const QByteArray &xml,
                       HotelCatalog *out,
                       QVector<Channel::PmsError> *errors)
{
    if (!out) return false;
    out->roomTypes.clear();
    out->ratePlans.clear();
    out->companies.clear();

    QXmlStreamReader r(xml);
    while (!r.atEnd()) {
        r.readNext();
        if (r.hasError()) return false;
        if (isStart(r, "Errors") || isStart(r, "Warnings")) {
            collectErrors(r, errors);
            continue;
        }
        if (isStart(r, "RoomType")) {
            RoomTypeInfo rt;
            rt.roomTypeCode = attr(r, "RoomTypeCode");
            while (!(r.isEndElement() && r.name() == QLatin1String("RoomType"))) {
                r.readNext();
                if (isStart(r, "RoomDescription")) {
                    rt.name = attr(r, "Name");
                } else if (isStart(r, "Text") && rt.description.isEmpty()) {
                    rt.description = r.readElementText().trimmed();
                } else if (isStart(r, "Occupancy")) {
                    if (!attr(r, "MinOccupancy").isEmpty()) {
                        rt.minOccupancy = attr(r, "MinOccupancy").toInt();
                        rt.maxOccupancy = attr(r, "MaxOccupancy").toInt();
                    }
                    skipElement(r);
                }
            }
            if (!rt.roomTypeCode.isEmpty()) out->roomTypes.append(rt);
            continue;
        }
        if (isStart(r, "RatePlan")) {
            RatePlanInfo rp;
            rp.ratePlanCode = attr(r, "RatePlanCode");
            rp.invBlockCode = attr(r, "InvBlockCode");
            const QString allowed = attr(r, "PriceUploadIsAllowed");
            if (!allowed.isEmpty()) rp.priceUploadAllowed = (allowed.compare(QLatin1String("true"), Qt::CaseInsensitive) == 0);
            while (!(r.isEndElement() && r.name() == QLatin1String("RatePlan"))) {
                r.readNext();
                if (isStart(r, "RatePlanDescription")) {
                    rp.name = attr(r, "Name");
                } else if (isStart(r, "Text") && rp.description.isEmpty()) {
                    rp.description = r.readElementText().trimmed();
                }
            }
            if (!rp.ratePlanCode.isEmpty()) out->ratePlans.append(rp);
            continue;
        }
        if (isStart(r, "CompanyName")) {
            ChannelCompanyInfo c;
            c.code = attr(r, "Code");
            c.shortName = attr(r, "CompanyShortName");
            c.name = r.readElementText().trimmed();
            if (!c.code.isEmpty()) out->companies.append(c);
            continue;
        }
        if (isStart(r, "Profile")) {
            // ProfileType on Profile
            // handled via CompanyName inside
            continue;
        }
    }
    return true;
}

} // namespace Pms
} // namespace Excely
