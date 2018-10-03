#ifndef CACHSEX_H
#define CACHSEX_H

#include "cachebasestruct.h"

#define cid_sex 52

class CacheSex : public CacheBaseStruct
{
public:
    CacheSex();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHSEX_H
