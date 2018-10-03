#include "cacheorderstate.h"

CacheOrderState::CacheOrderState()
{
    fLoadQuery = "select f_id, f_" + def_lang + " from o_state";
    fCacheId = cid_order_state;
    fSelectorTitle = QObject::tr("Order state");
    getSelectorTwoField();
    
}
