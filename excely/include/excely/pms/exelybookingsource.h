#ifndef EXCELY_PMS_EXELYBOOKINGSOURCE_H
#define EXCELY_PMS_EXELYBOOKINGSOURCE_H

#include "excely/channel/ibookingsource.h"
#include "excely/pms/pmsconnectclient.h"

namespace Excely {
namespace Pms {

/** IBookingSource adapter over PmsConnectClient. */
class ExelyBookingSource : public Channel::IBookingSource
{
public:
    explicit ExelyBookingSource(const Config &config);

    QString channelName() const override;
    bool ping(QString *errorText = nullptr) override;
    bool pullUndelivered(QVector<Channel::Booking> *out,
                         QVector<Channel::PmsError> *errors = nullptr) override;
    bool confirmDelivered(const Channel::Booking &booking,
                          const QString &pmsReservationId,
                          QString *errorText = nullptr) override;
    bool rejectDelivery(const Channel::Booking &booking,
                        const QString &reason,
                        QString *errorText = nullptr) override;

    PmsConnectClient &client() { return m_client; }

private:
    PmsConnectClient m_client;
};

} // namespace Pms
} // namespace Excely

#endif
