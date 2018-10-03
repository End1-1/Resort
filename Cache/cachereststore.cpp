#include "cachereststore.h"

CacheRestStore::CacheRestStore() :
    CacheBaseStruct()
{
    fLoadQuery = "select f_id, f_name from r_store";
    fCacheId = cid_rest_store;
    fSelectorTitle = QObject::tr("Store");
    getSelectorTwoField();

}
