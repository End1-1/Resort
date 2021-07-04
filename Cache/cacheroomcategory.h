#ifndef CACHEROOMCATEGORY_H
#define CACHEROOMCATEGORY_H

#include "cachebasestruct.h"

#define cid_room_category 54

class CacheRoomCategory : public CacheBaseStruct
{
public:
    CacheRoomCategory();
    inline QString fCode() {return getString("f_id"); }
    inline QString fName() {return getString("f_short"); }
    inline QString fFullName() {return getString("f_description"); }
    inline int fQueue(){return getInt("f_queue");}
};

#endif // CACHEROOMCATEGORY_H
