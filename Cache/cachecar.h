#ifndef CACHECAR_H
#define CACHECAR_H

#include "cachebasestruct.h"

#define cid_car 106

class CacheCar : public CacheBaseStruct
{
public:
    CacheCar();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHECAR_H
