#include "cacheresttable.h"


CacheRestTable::CacheRestTable() :
    CacheBaseStruct()
{
    fLoadQuery = "select f_id, f_hall, f_name from r_table";
    fCacheId = cid_rest_table;
    fSelectorTitle = QObject::tr("Tables");
    getSelectorTwoField();

}
