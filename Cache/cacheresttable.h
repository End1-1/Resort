#ifndef CACHERESTTABLE_H
#define CACHERESTTABLE_H

#include "cachebasestruct.h"

#define cid_rest_table 27

class CacheRestTable : public CacheBaseStruct
{
public:
    CacheRestTable();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
    inline int fHall() { return getInt("f_hall"); }
};

#endif // CACHERESTTABLE_H
