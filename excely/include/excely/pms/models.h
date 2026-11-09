#ifndef EXCELY_PMS_MODELS_H
#define EXCELY_PMS_MODELS_H

#include "excely/channel/bookingdto.h"

#include <QByteArray>
#include <QDate>
#include <QPair>
#include <QString>
#include <QStringList>
#include <QVector>

namespace Excely {
namespace Pms {

struct RoomTypeInfo {
    QString roomTypeCode;
    QString name;
    QString description;
    int minOccupancy = 0;
    int maxOccupancy = 0;
};

struct RatePlanInfo {
    QString ratePlanCode;
    QString name;
    QString description;
    bool priceUploadAllowed = true;
    QString invBlockCode;
};

struct ChannelCompanyInfo {
    QString code;
    QString shortName;
    QString name;
    int profileType = 0; // 4 agent, 10 OTA, 12 BE
};

struct HotelCatalog {
    QVector<RoomTypeInfo> roomTypes;
    QVector<RatePlanInfo> ratePlans;
    QVector<ChannelCompanyInfo> companies;
};

/** One AvailStatusMessage for OTA_HotelAvailNotifRQ. */
struct AvailStatusMessage {
    QString invTypeCode;       // required
    QString ratePlanCode;      // xor with invBlockCode
    QString invBlockCode;
    QDate start;
    QDate end;
    int bookingLimit = 0;
    bool sendBookingLimit = true;
    QString restrictionStatus; // "Open" | "Close" | empty = omit
    int minLOS = -1;           // <0 = omit LengthsOfStay; 0 = RemoveMinLOS; >0 = SetMinLOS days
};

/**
 * Extra occupancy price → AdditionalGuestAmount in OTA_HotelRateAmountNotifRQ.
 * Extra adult bed: defaults (no age attrs).
 * Extra child bed: AgeQualifyingCode=8 + AgeBucket and/or MinAge/MaxAge.
 * Child without bed: BedRequired=false + MinAge/MaxAge (e.g. 2–18).
 */
struct AdditionalGuestAmount {
    double amountAfterTax = 0.0;
    QString currencyCode;
    int maxAdditionalGuests = -1; // <0 omit; 1 = first extra bed, …
    bool bedRequired = true;
    bool sendBedRequired = false; // emit BedRequired only when set (false = without bed)
    int ageQualifyingCode = -1;   // 8 = child band (Exely)
    int ageBucket = -1;           // 0-based hotel child age range index
    int minAge = -1;
    int maxAge = -1;
};

/** One RateAmountMessage for OTA_HotelRateAmountNotifRQ. */
struct RateAmountMessage {
    QString invTypeCode;       // required
    QString ratePlanCode;      // required for room rates
    QDate start;               // on Rate@Start
    QDate end;                 // on Rate@End
    /** Legacy single BaseByGuestAmt (used if baseByGuestAmts is empty). */
    double amountAfterTax = 0.0;
    int numberOfGuests = 1;
    QString currencyCode;      // ISO 4217
    /** Preferred: several BaseByGuestAmt (NumberOfGuests → amount). */
    QVector<QPair<int, double>> baseByGuestAmts;
    QVector<AdditionalGuestAmount> additionalGuests;
};

/** Parse OTA_ResRetrieveRS body (SOAP body inner XML or full envelope). */
bool parseResRetrieveRs(const QByteArray &xml,
                        QVector<Channel::Booking> *out,
                        QVector<Channel::PmsError> *errors);

bool parseHotelAvailRs(const QByteArray &xml,
                       HotelCatalog *out,
                       QVector<Channel::PmsError> *errors);

bool parseSuccessOrErrors(const QByteArray &xml,
                          const QString &rootLocalName,
                          QVector<Channel::PmsError> *errors,
                          bool *hasSuccess);

QString buildOtaReadRqXml(const QString &hotelCode, const QString &version);
QString buildOtaPingRqXml(const QString &hotelCode, const QString &version);
QString buildOtaHotelAvailRqXml(const QString &hotelCode, const QString &version);
QString buildOtaHotelAvailNotifRqXml(const QString &hotelCode,
                                     const QString &version,
                                     const QVector<AvailStatusMessage> &messages);
QString buildOtaHotelRateAmountNotifRqXml(const QString &hotelCode,
                                          const QString &version,
                                          const QVector<RateAmountMessage> &messages);
QString buildOtaCancelRqXml(const QString &version,
                            const QString &channelReservationId,
                            const QString &reason);
QString buildOtaNotifReportReservedXml(const QString &hotelCode,
                                       const QString &version,
                                       const QString &uniqueId,
                                       const QString &createDateTime,
                                       const QString &lastModifyDateTime,
                                       const QString &pmsReservationId,
                                       const QStringList &roomStayIndexNumbers = {});
/** One HotelReservation per distinct PMS id, each listing its RoomStay IndexNumbers. */
QString buildOtaNotifReportReservedRoomsXml(const QString &hotelCode,
                                            const QString &version,
                                            const QString &uniqueId,
                                            const QString &createDateTime,
                                            const QString &lastModifyDateTime,
                                            const QVector<Channel::RoomConfirmation> &rooms);
QString buildOtaNotifReportDeniedXml(const QString &hotelCode,
                                     const QString &version,
                                     const QString &uniqueId,
                                     const QString &createDateTime,
                                     const QString &lastModifyDateTime,
                                     const QString &reason);

} // namespace Pms
} // namespace Excely

#endif
