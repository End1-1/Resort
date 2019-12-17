#include "cacheroomextra.h"

CacheRoomExtra::CacheRoomExtra() :
    CacheBaseStruct()
{
    fCacheId = cid_room_extra;
    fLoadQuery = "select f_id, f_name from f_room_extra_list";
    fSelectorTitle = QObject::tr("Room extra");
    getSelectorTwoField();
}
