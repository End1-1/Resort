#include "cacheroominventory.h"

CacheRoomInventory::CacheRoomInventory()
{
    fCacheId = cid_room_inventory;
    fLoadQuery = "select f_id, f_name from f_room_inventory";
    fSelectorTitle = QObject::tr("Room inventory");
    getSelectorTwoField();

}

