#ifndef CACHEDISHSTATE_H
#define CACHEDISHSTATE_H

#include "cachebasestruct.h"

#define cid_dish_state 62

class CacheDishState : public CacheBaseStruct
{
public:
    CacheDishState();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHEDISHSTATE_H
