#include "excely/pms/models.h"

#include "excely/pms/xmlhelpers.h"

#include <QDateTime>

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
            g->countryCode = attr(r, "Code");
            skipElement(r);
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
            cur.createDateTime = parseOtaDateTime(attr(r, "CreateDateTime"));
            cur.lastModifyDateTime = parseOtaDateTime(attr(r, "LastModifyDateTime"));
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
            const int count = attr(r, "Count").toInt();
            if (aqc.contains(QLatin1String("Adult"), Qt::CaseInsensitive)) {
                room.adults += count > 0 ? count : 1;
            } else {
                room.children += count > 0 ? count : 1;
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
