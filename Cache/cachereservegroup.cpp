#include "cachereservegroup.h"

CacheReserveGroup::CacheReserveGroup() :
    CacheBaseStruct()
{
    fCacheId = cid_reserve_group;
    fLoadQuery = "select f_id, f_name from f_reservation_group";
    fSelectorTitle = QObject::tr("Reservation group");
    getSelectorTwoField();
    
}
