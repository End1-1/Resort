#ifndef CACHEROOMEXTRA_H
#define CACHEROOMEXTRA_H

#include "cachebasestruct.h"

static const int cid_room_extra = 121;

class CacheRoomExtra : public CacheBaseStruct
{
public:
    CacheRoomExtra();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHEROOMEXTRA_H
