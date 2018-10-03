#include "cachereservestate.h"

CacheReserveState::CacheReserveState() :
    CacheBaseStruct()
{
    fCacheId = cid_reserve_state;
    fLoadQuery = "select f_id, f_" + def_lang + " from f_reservation_state";
    fSelectorTitle = QObject::tr("State");
    getSelectorTwoField();
    
}
