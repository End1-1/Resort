#include "excely/channel/bookingdto.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Excely {
namespace Channel {

bool PmsError::isAuthError() const
{
    // OTA Error Code 175 Password invalid (from protocol examples)
    return code == 175 || text.contains(QStringLiteral("Password"), Qt::CaseInsensitive)
            || text.contains(QStringLiteral("Unauthorized"), Qt::CaseInsensitive);
}

QString Booking::actionToString(BookingAction a)
{
    switch (a) {
    case BookingAction::Create: return QStringLiteral("create");
    case BookingAction::Modify: return QStringLiteral("modify");
    case BookingAction::Cancel: return QStringLiteral("cancel");
    default: return QStringLiteral("unknown");
    }
}

QString Booking::statusToString(BookingStatus s)
{
    switch (s) {
    case BookingStatus::Unconfirmed: return QStringLiteral("Unconfirmed");
    case BookingStatus::Confirmed: return QStringLiteral("Confirmed");
    case BookingStatus::Cancelled: return QStringLiteral("Cancelled");
    case BookingStatus::Released: return QStringLiteral("Released");
    case BookingStatus::Pending: return QStringLiteral("Pending");
    case BookingStatus::Reserved: return QStringLiteral("Reserved");
    case BookingStatus::RequestDenied: return QStringLiteral("RequestDenied");
    default: return QStringLiteral("Unknown");
    }
}

BookingAction Booking::actionFromStatus(BookingStatus s)
{
    switch (s) {
    case BookingStatus::Cancelled:
        return BookingAction::Cancel;
    case BookingStatus::Confirmed:
    case BookingStatus::Unconfirmed:
    case BookingStatus::Pending:
    case BookingStatus::Reserved:
        return BookingAction::Create; // modify vs create decided by sink via chm id lookup
    default:
        return BookingAction::Unknown;
    }
}

static QJsonObject guestToJson(const Guest &g)
{
    QJsonObject o;
    o.insert(QStringLiteral("first_name"), g.firstName);
    o.insert(QStringLiteral("middle_name"), g.middleName);
    o.insert(QStringLiteral("last_name"), g.lastName);
    o.insert(QStringLiteral("email"), g.email);
    o.insert(QStringLiteral("phone"), g.phone);
    o.insert(QStringLiteral("country"), g.countryCode);
    o.insert(QStringLiteral("external_id"), g.externalId);
    return o;
}

QJsonObject Booking::toJson() const
{
    QJsonObject o;
    o.insert(QStringLiteral("channel"), channelId);
    o.insert(QStringLiteral("action"), actionToString(action));
    o.insert(QStringLiteral("resstatus"), statusToString(status));
    o.insert(QStringLiteral("res_id"), channelReservationId);
    o.insert(QStringLiteral("res_external_id"), externalReservationId);
    o.insert(QStringLiteral("hotel_code"), hotelCode);
    o.insert(QStringLiteral("companyname"), companyCode.isEmpty() ? companyName : companyCode);
    o.insert(QStringLiteral("company_name"), companyName);
    o.insert(QStringLiteral("booking_channel"), bookingChannelCode);
    o.insert(QStringLiteral("guarantee"), guaranteeCode);
    o.insert(QStringLiteral("paymenttype"), paymentMethodName);
    o.insert(QStringLiteral("paymentname"), paymentSystemName);
    o.insert(QStringLiteral("comment"), comment);
    o.insert(QStringLiteral("full_comment"), fullComment);
    o.insert(QStringLiteral("total"), totalAfterTax);
    o.insert(QStringLiteral("currency"), currencyCode);
    if (createDateTime.isValid()) {
        o.insert(QStringLiteral("create_dt"), createDateTime.toString(Qt::ISODate));
    }
    if (lastModifyDateTime.isValid()) {
        o.insert(QStringLiteral("last_modify_dt"), lastModifyDateTime.toString(Qt::ISODate));
    }
    o.insert(QStringLiteral("main_guest"), guestToJson(mainGuest));

    QJsonArray guestsArr;
    for (const Guest &g : guests) {
        guestsArr.append(guestToJson(g));
    }
    o.insert(QStringLiteral("guests"), guestsArr);

    QJsonArray roomsArr;
    for (const RoomStay &rs : rooms) {
        QJsonObject r;
        r.insert(QStringLiteral("index"), rs.indexNumber);
        r.insert(QStringLiteral("room_type"), rs.roomTypeCode);
        r.insert(QStringLiteral("inv_block"), rs.invBlockCode);
        r.insert(QStringLiteral("rateplan"), rs.ratePlanCode);
        r.insert(QStringLiteral("arrival"), rs.arrival.toString(Qt::ISODate));
        r.insert(QStringLiteral("departure"), rs.departure.toString(Qt::ISODate));
        r.insert(QStringLiteral("days"), rs.nights);
        r.insert(QStringLiteral("guest_count_men"), rs.adults);
        r.insert(QStringLiteral("guest_count_oth"), rs.children);
        r.insert(QStringLiteral("total"), rs.amountAfterTax);
        r.insert(QStringLiteral("currency"), rs.currencyCode);
        roomsArr.append(r);
    }
    o.insert(QStringLiteral("rooms"), roomsArr);
    return o;
}

} // namespace Channel
} // namespace Excely
