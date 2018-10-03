#ifndef CACHERESTSTORE_H
#define CACHERESTSTORE_H

#include "cachebasestruct.h"

#define cid_rest_store 31


class CacheRestStore : public CacheBaseStruct
{
public:
    CacheRestStore();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHERESTSTORE_H
