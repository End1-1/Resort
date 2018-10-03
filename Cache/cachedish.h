#ifndef CACHEDISH_H
#define CACHEDISH_H

#include "cachebasestruct.h"

#define cid_dish 61

class CacheDish : public CacheBaseStruct
{
public:
    CacheDish();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHEDISH_H
