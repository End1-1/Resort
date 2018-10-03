#ifndef CACHERESERVEGROUP_H
#define CACHERESERVEGROUP_H

#include "cachebasestruct.h"

#define cid_reserve_group 100

class CacheReserveGroup : public CacheBaseStruct
{
public:
    CacheReserveGroup();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHERESERVEGROUP_H
