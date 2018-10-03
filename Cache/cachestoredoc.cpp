#include "cachestoredoc.h"

CacheStoreDocType::CacheStoreDocType() :
    CacheBaseStruct()
{
    fCacheId = cid_store_doc_type;
    fLoadQuery = "select f_id, f_name from r_doc_type";
    fSelectorTitle = QObject::tr("Type");
    getSelectorTwoField();

}
