#ifndef CACHEROOMINVENTORY_H
#define CACHEROOMINVENTORY_H

#include "cachebasestruct.h"

#define cid_room_inventory 115

class CacheRoomInventory : public CacheBaseStruct
{
public:
    CacheRoomInventory();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHEROOMINVENTORY_H
