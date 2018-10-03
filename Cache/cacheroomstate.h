#ifndef CACHEROOMSTATE_H
#define CACHEROOMSTATE_H

#include "cachebasestruct.h"

#define cid_room_state 46

class CacheRoomState : public CacheBaseStruct
{
public:
    CacheRoomState();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHEROOMSTATE_H
