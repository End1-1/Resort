#ifndef CACHEBED_H
#define CACHEBED_H

#include "cachebasestruct.h"

#define cid_bed 47

class CacheBed : public CacheBaseStruct
{
public:
    CacheBed();
    inline QString fCode() {return getString("f_id"); }
    inline QString fName() {return getString("f_name"); }
};

#endif // CACHEBED_H
