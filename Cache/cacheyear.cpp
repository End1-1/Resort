#include "cacheyear.h"

CacheYear::CacheYear() :
    CacheBaseStruct()
{
    fCacheId = cid_serv_year;
    fLoadQuery = "select f_id, f_name  from serv_years";
    fUpdateQuery = "f_id=:f_id";
    fSelectorTitle = QObject::tr("Year");
    getSelectorTwoField();
}
