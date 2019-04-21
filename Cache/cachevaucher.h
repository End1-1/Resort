#ifndef CACHEVAUCHER_H
#define CACHEVAUCHER_H

#include "cachebasestruct.h"

static const int cid_vaucher = 59;

class CacheVaucher : public CacheBaseStruct
{
public:
    CacheVaucher();
    inline QString fCode() { return getString("f_code"); }
    inline QString fName() { return getString("f_description"); }
};

#endif // CACHEVAUCHER_H
