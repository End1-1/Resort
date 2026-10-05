#include "excely/pms/exelybookingsource.h"

namespace Excely {
namespace Pms {

ExelyBookingSource::ExelyBookingSource(const Config &config)
    : m_client(config)
{
}

QString ExelyBookingSource::channelName() const
{
    return QStringLiteral("exely");
}

bool ExelyBookingSource::ping(QString *errorText)
{
    return m_client.ping(errorText);
}

bool ExelyBookingSource::pullUndelivered(QVector<Channel::Booking> *out,
                                         QVector<Channel::PmsError> *errors)
{
    return m_client.readUndelivered(out, errors);
}

bool ExelyBookingSource::confirmDelivered(const Channel::Booking &booking,
                                          const QString &pmsReservationId,
                                          QString *errorText)
{
    return m_client.confirmReserved(booking, pmsReservationId, errorText);
}

bool ExelyBookingSource::rejectDelivery(const Channel::Booking &booking,
                                        const QString &reason,
                                        QString *errorText)
{
    return m_client.requestDenied(booking, reason, errorText);
}

} // namespace Pms
} // namespace Excely
