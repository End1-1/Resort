#ifndef EXCELY_RESORT_BOOKINGDRAFT_H
#define EXCELY_RESORT_BOOKINGDRAFT_H

#include <QDate>
#include <QDateTime>
#include <QJsonObject>
#include <QString>
#include <QTime>
#include <QVector>

namespace Excely {
namespace Resort {

/**
 * Intermediate shape aligned with SmartHotel / Resort `f_reservation` import.
 *
 * Not written to DB here — only prepared for a future Resort sink.
 */
struct GuestDraft {
    QString firstName;
    QString middleName;
    QString lastName;
    QString email;
    QString phone;
    QString nationShort;   // f_guests.f_nation
    bool isPrimary = false;
};

struct RoomDraft {
    QString roomTypeCode;  // CM code → map to f_room_classes.f_short
    QString ratePlanCode;  // CM rate plan code
    QDate startDate;       // f_startDate
    QDate endDate;         // f_endDate
    QTime arrivalTime;
    QTime departureTime;
    int men = 0;           // f_man
    int children = 0;      // f_child (+ baby if split later)
    double roomFee = 0.0;  // f_roomFee / night approx
    double total = 0.0;    // f_total / f_grandTotal for this stay
    QString currencyCode;
    QString indexNumber;   // RoomStay IndexNumber for NotifReport
};

struct BookingDraft {
    QString channel;               // "exely"
    QString action;                // create | modify | cancel
    QString chmId;                 // → f_chm (channel UniqueID)
    QString bookingExternalId;     // → f_booking (sales channel number if any)
    int state = 2;                 // RESERVE_RESERVE=2, RESERVE_CHECKOUT_CANCELED=6
    int reserveState = 1;          // CONFIRM_CONFIRM=1
    int chmStatus = 1;             // 1 = new import pending UI ack
    int roomId = 0;                // f_room (0 = unassigned until mapped)
    QString cardex;                // f_cardex (agency / POS)
    QString companyName;
    QString remarks;
    QString paymentTypeHint;       // CASH | BankCard | ...
    QString paymentName;
    QString guaranteeCode;
    double grandTotal = 0.0;
    QString currencyCode;
    QDateTime lastModify;

    GuestDraft mainGuest;
    QVector<GuestDraft> guests;
    QVector<RoomDraft> rooms;

    /** JSON import payload for a future Resort sink (channel-agnostic). */
    QJsonObject toImportJson() const;
};

} // namespace Resort
} // namespace Excely

#endif
