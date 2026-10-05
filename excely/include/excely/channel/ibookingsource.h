#ifndef EXCELY_CHANNEL_IBOOKINGSOURCE_H
#define EXCELY_CHANNEL_IBOOKINGSOURCE_H

#include "excely/channel/bookingdto.h"

#include <QString>
#include <QVector>

namespace Excely {
namespace Channel {

/**
 * Universal pull API for any channel manager / booking source.
 * Implementations: Exely PMSConnect, future adapters.
 */
class IBookingSource
{
public:
    virtual ~IBookingSource() = default;

    virtual QString channelName() const = 0;

    /** Connectivity / protocol health check. */
    virtual bool ping(QString *errorText = nullptr) = 0;

    /**
     * Fetch bookings not yet acknowledged by PMS (or equivalent).
     * Empty list is success with nothing pending.
     */
    virtual bool pullUndelivered(QVector<Booking> *out, QVector<PmsError> *errors = nullptr) = 0;

    /**
     * Acknowledge successful import. pmsReservationId is PMS-side number
     * (maps to HotelReservationID ResID_Value in Exely NotifReport).
     */
    virtual bool confirmDelivered(const Booking &booking,
                                  const QString &pmsReservationId,
                                  QString *errorText = nullptr) = 0;

    /** Tell the channel the booking could not be created in PMS. */
    virtual bool rejectDelivery(const Booking &booking,
                                const QString &reason,
                                QString *errorText = nullptr) = 0;
};

} // namespace Channel
} // namespace Excely

#endif
