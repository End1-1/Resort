#ifndef CACHEYEAR_H
#define CACHEYEAR_H

#include "cachebasestruct.h"

static const int cid_serv_year = 130;

class CacheYear : public CacheBaseStruct
{
public:
    CacheYear();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHEYEAR_H
