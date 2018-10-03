#ifndef CACHEROOMVIEW_H
#define CACHEROOMVIEW_H

#include "cachebasestruct.h"

#define cid_room_view 55

class CacheRoomView : public CacheBaseStruct
{
public:
    CacheRoomView();
    inline QString fCode(){return getString("f_id"); }
    inline QString fName(){return getString("f_short");}
};

#endif // CACHEROOMVIEW_H
