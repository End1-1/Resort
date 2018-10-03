#include "cachereservestatus.h"

CacheReserveStatus::CacheReserveStatus() :
    CacheBaseStruct()
{
    fCacheId = cid_reserve_status;
    fLoadQuery = "select f_id, f_" + def_lang + " from f_reservation_status";
    fSelectorTitle = QObject::tr("Reservation status");
    getSelectorTwoField();
    
}
