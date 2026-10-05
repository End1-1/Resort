#ifndef EXCELY_CHANNEL_BOOKINGDTO_H
#define EXCELY_CHANNEL_BOOKINGDTO_H

#include <QDateTime>
#include <QJsonObject>
#include <QString>
#include <QStringList>
#include <QVector>

namespace Excely {
namespace Channel {

/** What the sink should do with this booking. */
enum class BookingAction {
    Create,
    Modify,
    Cancel,
    Unknown
};

enum class BookingStatus {
    Unconfirmed,
    Confirmed,
    Cancelled,
    Released,
    Pending,
    Reserved,       // Exely / OTA "Reserved" sometimes used as confirm target
    RequestDenied,
    Unknown
};

struct Guest {
    QString firstName;
    QString middleName;
    QString lastName;
    QString email;
    QString phone;
    QString countryCode;   // ISO
    QString externalId;    // CM profile id if any
};

struct RoomStay {
    QString indexNumber;       // RoomStay@IndexNumber
    QString roomTypeCode;      // CM room type code
    QString invBlockCode;
    QString ratePlanCode;
    QDateTime arrival;
    QDateTime departure;
    int nights = 0;
    int adults = 0;
    int children = 0;
    double amountAfterTax = 0.0;
    QString currencyCode;
};

struct Deposit {
    QString type;              // e.g. ReceivedPayment
    double amount = 0.0;
    QString currencyCode;
    int paymentIndex = -1;
};

/**
 * Universal channel booking — filled by any CM adapter (Exely, future OTAs).
 * Intentionally independent of Resort DB column names.
 */
struct Booking {
    QString channelId;             // "exely", "bookingcom", ...
    BookingAction action = BookingAction::Unknown;
    BookingStatus status = BookingStatus::Unknown;

    QString channelReservationId;  // UniqueID (PMSConnect / primary)
    QString externalReservationId; // UniqueID ID_Context=External
    QDateTime createDateTime;
    QDateTime lastModifyDateTime;

    QString hotelCode;
    QString companyCode;           // BookingChannel CompanyName@Code
    QString companyName;
    bool primaryChannel = true;
    QString bookingChannelCode;

    QString guaranteeCode;         // None | PrePay | CcDcVoucher
    QString paymentMethodName;
    QString paymentSystemName;
    QString paymentSystemTitle;

    QString comment;
    QString fullComment;

    Guest mainGuest;
    QVector<Guest> guests;
    QVector<RoomStay> rooms;
    QVector<Deposit> deposits;

    double totalAfterTax = 0.0;
    QString currencyCode;

    QJsonObject toJson() const;
    static QString actionToString(BookingAction a);
    static QString statusToString(BookingStatus s);
    static BookingAction actionFromStatus(BookingStatus s);
};

struct PmsError {
    int type = 0;
    int code = 0;
    QString tag;
    QString text;
    bool isLimitError() const { return code == -100 || code == -101; }
    bool isAuthError() const;
};

} // namespace Channel
} // namespace Excely

#endif
