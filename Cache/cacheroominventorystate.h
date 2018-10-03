#ifndef CACHEROOMINVENTORYSTATE_H
#define CACHEROOMINVENTORYSTATE_H

#include "cachebasestruct.h"

#define cid_room_inventory_state 116


class CacheRoomInventoryState : public CacheBaseStruct
{
public:
    CacheRoomInventoryState();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHEROOMINVENTORYSTATE_H
