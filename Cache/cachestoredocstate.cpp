#include "cachestoredocstate.h"

CacheStoreDocState::CacheStoreDocState() :
    CacheBaseStruct()
{
    fCacheId = cid_store_doc_state;
    fLoadQuery = "select f_id, f_name from r_doc_state";
    fSelectorTitle = QObject::tr("State");
    getSelectorTwoField();

}
