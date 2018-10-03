#ifndef CACHERESERVESTATUS_H
#define CACHERESERVESTATUS_H

#include "cachebasestruct.h"

#define cid_reserve_status 36

class CacheReserveStatus : public CacheBaseStruct
{
public:
    CacheReserveStatus();
    inline QString fCode() {return getString("f_id"); }
    inline QString fName() {return getString("f_" + def_lang); }
};

#endif // CACHERESERVESTATUS_H
