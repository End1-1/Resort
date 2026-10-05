#include "excely/resort/channeltoresort.h"

#include <QJsonArray>

namespace Excely {
namespace Resort {

BookingDraft toResortDraft(const Channel::Booking &in)
{
    BookingDraft d;
    d.channel = in.channelId.isEmpty() ? QStringLiteral("exely") : in.channelId;
    d.chmId = in.channelReservationId;
    d.bookingExternalId = in.externalReservationId;
    d.lastModify = in.lastModifyDateTime;
    d.cardex = in.companyCode;
    d.companyName = in.companyName.isEmpty() ? in.companyCode : in.companyName;
    d.remarks = in.fullComment.isEmpty() ? in.comment : in.fullComment;
    d.paymentTypeHint = in.paymentMethodName;
    d.paymentName = in.paymentSystemName;
    d.guaranteeCode = in.guaranteeCode;
    d.grandTotal = in.totalAfterTax;
    d.currencyCode = in.currencyCode;
    d.chmStatus = 1;

    switch (in.status) {
    case Channel::BookingStatus::Cancelled:
        d.action = QStringLiteral("cancel");
        d.state = 6; // canceled
        break;
    default:
        d.action = (in.action == Channel::BookingAction::Modify)
                ? QStringLiteral("modify")
                : QStringLiteral("create");
        d.state = 2; // reserve
        d.reserveState = 1;
        break;
    }

    d.mainGuest.firstName = in.mainGuest.firstName;
    d.mainGuest.middleName = in.mainGuest.middleName;
    d.mainGuest.lastName = in.mainGuest.lastName;
    d.mainGuest.email = in.mainGuest.email;
    d.mainGuest.phone = in.mainGuest.phone;
    d.mainGuest.nationShort = in.mainGuest.countryCode;
    d.mainGuest.isPrimary = true;

    if (d.mainGuest.lastName.isEmpty() && !in.guests.isEmpty()) {
        const Channel::Guest &g0 = in.guests.first();
        d.mainGuest.firstName = g0.firstName;
        d.mainGuest.middleName = g0.middleName;
        d.mainGuest.lastName = g0.lastName;
        d.mainGuest.email = g0.email;
        d.mainGuest.phone = g0.phone;
        d.mainGuest.nationShort = g0.countryCode;
    }

    for (const Channel::Guest &g : in.guests) {
        GuestDraft gd;
        gd.firstName = g.firstName;
        gd.middleName = g.middleName;
        gd.lastName = g.lastName;
        gd.email = g.email;
        gd.phone = g.phone;
        gd.nationShort = g.countryCode;
        d.guests.append(gd);
    }

    for (const Channel::RoomStay &rs : in.rooms) {
        RoomDraft rd;
        rd.roomTypeCode = rs.roomTypeCode;
        rd.ratePlanCode = rs.ratePlanCode;
        rd.indexNumber = rs.indexNumber;
        if (rs.arrival.isValid()) {
            rd.startDate = rs.arrival.date();
            rd.arrivalTime = rs.arrival.time();
        }
        if (rs.departure.isValid()) {
            rd.endDate = rs.departure.date();
            rd.departureTime = rs.departure.time();
        }
        rd.men = rs.adults;
        rd.children = rs.children;
        rd.total = rs.amountAfterTax;
        rd.currencyCode = rs.currencyCode;
        if (rd.startDate.isValid() && rd.endDate.isValid()) {
            const int nights = rd.startDate.daysTo(rd.endDate);
            if (nights > 0 && rd.total > 0.0) {
                rd.roomFee = rd.total / nights;
            }
        } else if (rs.nights > 0 && rs.amountAfterTax > 0.0) {
            rd.roomFee = rs.amountAfterTax / rs.nights;
        }
        d.rooms.append(rd);
    }

    if (d.grandTotal <= 0.0) {
        for (const RoomDraft &rd : d.rooms) {
            d.grandTotal += rd.total;
        }
    }
    if (d.currencyCode.isEmpty() && !d.rooms.isEmpty()) {
        d.currencyCode = d.rooms.first().currencyCode;
    }

    return d;
}

QJsonObject BookingDraft::toImportJson() const
{
    QJsonObject o;
    o.insert(QStringLiteral("channel"), channel);
    o.insert(QStringLiteral("action"), action);
    o.insert(QStringLiteral("res_id"), chmId);
    o.insert(QStringLiteral("res_external_id"), bookingExternalId);
    o.insert(QStringLiteral("resstatus"), action == QStringLiteral("cancel")
             ? QStringLiteral("Cancelled")
             : QStringLiteral("Confirmed"));
    o.insert(QStringLiteral("resstatuscode"), state);
    o.insert(QStringLiteral("cardex"), cardex);
    o.insert(QStringLiteral("companyname"), companyName);
    o.insert(QStringLiteral("comment"), remarks);
    o.insert(QStringLiteral("full_comment"), remarks);
    o.insert(QStringLiteral("paymenttype"), paymentTypeHint);
    o.insert(QStringLiteral("paymentname"), paymentName);
    o.insert(QStringLiteral("guarantee"), guaranteeCode);
    o.insert(QStringLiteral("total"), grandTotal);
    o.insert(QStringLiteral("currency"), currencyCode);

    QJsonObject mg;
    mg.insert(QStringLiteral("first_name"), mainGuest.firstName);
    mg.insert(QStringLiteral("middle_name"), mainGuest.middleName);
    mg.insert(QStringLiteral("last_name"), mainGuest.lastName);
    mg.insert(QStringLiteral("email"), mainGuest.email);
    mg.insert(QStringLiteral("phone"), mainGuest.phone);
    mg.insert(QStringLiteral("country"), mainGuest.nationShort);
    o.insert(QStringLiteral("main_guest"), mg);

    QJsonArray guestsArr;
    for (const GuestDraft &g : guests) {
        QJsonObject jo;
        jo.insert(QStringLiteral("first_name"), g.firstName);
        jo.insert(QStringLiteral("middle_name"), g.middleName);
        jo.insert(QStringLiteral("last_name"), g.lastName);
        jo.insert(QStringLiteral("email"), g.email);
        jo.insert(QStringLiteral("phone"), g.phone);
        jo.insert(QStringLiteral("country"), g.nationShort);
        guestsArr.append(jo);
    }
    o.insert(QStringLiteral("guests"), guestsArr);

    QJsonArray roomsArr;
    for (const RoomDraft &r : rooms) {
        QJsonObject jo;
        jo.insert(QStringLiteral("room_type"), r.roomTypeCode);
        jo.insert(QStringLiteral("rateplan"), r.ratePlanCode);
        QDateTime arr(r.startDate, r.arrivalTime.isValid() ? r.arrivalTime : QTime(14, 0));
        QDateTime dep(r.endDate, r.departureTime.isValid() ? r.departureTime : QTime(12, 0));
        jo.insert(QStringLiteral("arrival"), arr.toString(QStringLiteral("yyyy-MM-ddTHH:mm:ss")));
        jo.insert(QStringLiteral("departure"), dep.toString(QStringLiteral("yyyy-MM-ddTHH:mm:ss")));
        jo.insert(QStringLiteral("days"), r.startDate.isValid() && r.endDate.isValid()
                  ? r.startDate.daysTo(r.endDate) : 0);
        jo.insert(QStringLiteral("total"), r.total);
        jo.insert(QStringLiteral("guest_count_men"), r.men);
        jo.insert(QStringLiteral("guest_count_oth"), r.children);
        jo.insert(QStringLiteral("index"), r.indexNumber);
        roomsArr.append(jo);
    }
    o.insert(QStringLiteral("rooms"), roomsArr);
    return o;
}

} // namespace Resort
} // namespace Excely
