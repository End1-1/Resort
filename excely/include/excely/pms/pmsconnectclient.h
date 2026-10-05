#ifndef EXCELY_PMS_PMSCONNECTCLIENT_H
#define EXCELY_PMS_PMSCONNECTCLIENT_H

#include "excely/channel/bookingdto.h"
#include "excely/pms/models.h"
#include "excely/pms/pmsconfig.h"

#include <QObject>
#include <QNetworkAccessManager>

namespace Excely {
namespace Pms {

/**
 * Low-level SOAP client for Exely PMSConnect 1.18.
 * Synchronous helpers block the calling thread via QEventLoop (CLI-friendly).
 */
class PmsConnectClient : public QObject
{
    Q_OBJECT
public:
    explicit PmsConnectClient(const Config &config, QObject *parent = nullptr);

    void setConfig(const Config &config);
    const Config &config() const { return m_config; }

    bool ping(QString *errorText = nullptr);
    bool hotelAvail(HotelCatalog *out, QVector<Channel::PmsError> *errors = nullptr);
    bool readUndelivered(QVector<Channel::Booking> *out, QVector<Channel::PmsError> *errors = nullptr);
    bool confirmReserved(const Channel::Booking &booking,
                         const QString &pmsReservationId,
                         QString *errorText = nullptr);
    bool requestDenied(const Channel::Booking &booking,
                       const QString &reason,
                       QString *errorText = nullptr);

    static QString soapActionRead();
    static QString soapActionNotifReport();
    static QString soapActionPing();
    static QString soapActionHotelAvail();

private:
    bool postSoap(const QString &soapAction,
                  const QString &otaBodyXml,
                  QByteArray *responseBody,
                  QString *errorText);

    Config m_config;
    QNetworkAccessManager m_nam;
};

} // namespace Pms
} // namespace Excely

#endif
