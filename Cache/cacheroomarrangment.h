#ifndef CACHEROOMARRANGMENT_H
#define CACHEROOMARRANGMENT_H

#include "cachebasestruct.h"

#define cid_room_arrangment 37

class CacheRoomArrangment : public CacheBaseStruct
{
public:
    CacheRoomArrangment();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHEROOMARRANGMENT_H
