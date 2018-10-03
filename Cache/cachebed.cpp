#include "cachebed.h"

CacheBed::CacheBed()
{
    fCacheId = cid_bed;
    fLoadQuery = "select f_id, f_name  from f_room_bed";
    fUpdateQuery = "f_id=:f_id";
    fSelectorTitle = QObject::tr("Bed");
    getSelectorTwoField();
    
}
