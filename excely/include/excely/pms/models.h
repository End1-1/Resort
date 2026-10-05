#ifndef EXCELY_PMS_MODELS_H
#define EXCELY_PMS_MODELS_H

#include "excely/channel/bookingdto.h"

#include <QByteArray>
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
QString buildOtaNotifReportReservedXml(const QString &hotelCode,
                                       const QString &version,
                                       const QString &uniqueId,
                                       const QString &createDateTime,
                                       const QString &lastModifyDateTime,
                                       const QString &pmsReservationId,
                                       const QStringList &roomStayIndexNumbers = {});
QString buildOtaNotifReportDeniedXml(const QString &hotelCode,
                                     const QString &version,
                                     const QString &uniqueId,
                                     const QString &createDateTime,
                                     const QString &lastModifyDateTime,
                                     const QString &reason);

} // namespace Pms
} // namespace Excely

#endif
