#ifndef EXCELY_CHANNEL_IBOOKINGSINK_H
#define EXCELY_CHANNEL_IBOOKINGSINK_H

#include "excely/channel/bookingdto.h"
#include "excely/resort/resortbookingdraft.h"

#include <QString>
#include <QVector>

namespace Excely {
namespace Channel {

/**
 * Destination for imported bookings.
 * Resort will later implement this (DB writer). Poller uses a log/stub sink for now.
 */
class IBookingSink
{
public:
    virtual ~IBookingSink() = default;

    /**
     * Persist or stage a universal booking.
     * On success, set *pmsReservationId to the local reservation id used in confirmDelivered.
     */
    virtual bool accept(const Booking &booking,
                        QString *pmsReservationId,
                        QString *errorText = nullptr) = 0;
};

/**
 * Optional Resort-oriented sink that receives already-mapped drafts.
 * Kept separate so non-Resort consumers can ignore it.
 */
class IResortBookingSink
{
public:
    virtual ~IResortBookingSink() = default;

    virtual bool acceptDraft(const Resort::BookingDraft &draft,
                             QString *pmsReservationId,
                             QString *errorText = nullptr) = 0;
};

} // namespace Channel
} // namespace Excely

#endif
