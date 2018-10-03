#include "cacheroominventorystate.h"

CacheRoomInventoryState::CacheRoomInventoryState()
{
    fCacheId = cid_room_inventory_state;
    fLoadQuery = "select f_id, f_name from f_room_inventory_state ";

}
