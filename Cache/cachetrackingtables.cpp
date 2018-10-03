#include "cachetrackingtables.h"

CacheTrackingTables::CacheTrackingTables() :
    CacheBaseStruct()
{
    fCacheId = cid_tracking_tables;
    fLoadQuery = "select f_id, f_name from f_changes_windows";
    fSelectorTitle = QObject::tr("Table");
    getSelectorTwoField();

}
