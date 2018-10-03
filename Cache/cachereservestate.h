#ifndef CACHERESERVESTATE_H
#define CACHERESERVESTATE_H

#include "cachebasestruct.h"

#define cid_reserve_state 35

class CacheReserveState : public CacheBaseStruct
{
public:
    CacheReserveState();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHERESERVESTATE_H
