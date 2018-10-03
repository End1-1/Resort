#ifndef CACHECLADVANCE_H
#define CACHECLADVANCE_H

#include "cachebasestruct.h"

#define cid_cache_cl_advance 114

class CacheCLAdvance : public CacheBaseStruct
{
public:
    CacheCLAdvance();
    inline QString fCode() {return getString("f_cityLedger"); }
    inline QString fName() {return getString("f_name"); }
    inline double fAmount() {return getDouble("amount"); }
};

#endif // CACHECLADVANCE_H
