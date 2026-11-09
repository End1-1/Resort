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
    int children = 0;      // f_child (Age > 2 .. 18; needs a bed)
    int babies = 0;        // f_baby (Age 0..2; no bed / not in bed count)
    bool extraBed = false; // channel ExtraBed flag; sink also sets if (men+children) > f_bedQty
    double roomFee = 0.0;  // f_roomFee / night approx
    double total = 0.0;    // f_total / f_grandTotal for this stay
    QString currencyCode;
    QString indexNumber;   // RoomStay IndexNumber for NotifReport
};

/** GuaranteePayment / prepaid from channel → m_register AV on import. */
struct DepositDraft {
    QString type;          // e.g. ReceivedPayment
    double amount = 0.0;
    QString currencyCode;
    int paymentIndex = -1;
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
    QDateTime createDateTime;      // Exely HotelReservation@CreateDateTime
    QString createDateTimeRaw;     // verbatim for logs / NotifReport
    QDateTime lastModify;
    QString lastModifyRaw;

    GuestDraft mainGuest;
    QVector<GuestDraft> guests;
    QVector<RoomDraft> rooms;
    QVector<DepositDraft> deposits;

    /** JSON import payload for a future Resort sink (channel-agnostic). */
    QJsonObject toImportJson() const;
};

} // namespace Resort
} // namespace Excely

#endif
