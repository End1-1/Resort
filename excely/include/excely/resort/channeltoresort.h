#ifndef EXCELY_RESORT_CHANNELTORESORT_H
#define EXCELY_RESORT_CHANNELTORESORT_H

#include "excely/channel/bookingdto.h"
#include "excely/resort/resortbookingdraft.h"

namespace Excely {
namespace Resort {

/** Map universal Channel::Booking → Resort BookingDraft (no DB). */
BookingDraft toResortDraft(const Channel::Booking &in);

} // namespace Resort
} // namespace Excely

#endif
