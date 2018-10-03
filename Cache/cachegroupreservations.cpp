#include "cachegroupreservations.h"

CacheGroupReservations::CacheGroupReservations()
{
    fCacheId = cid_group_reservation;
    fLoadQuery = "select f_id, f_name from f_reservation_group";
    fUpdateQuery = "f_id=:f_id";
    fSelectorTitle = QObject::tr("Group reservations");
    getSelectorTwoField();
    
}
