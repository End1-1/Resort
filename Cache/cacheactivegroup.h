#ifndef CACHEACTIVEGROUP_H
#define CACHEACTIVEGROUP_H

#include "cachebasestruct.h"

static const int cid_active_group = 120;

class CacheActiveGroup : public CacheBaseStruct
{
public:
    CacheActiveGroup();
    inline QString fId() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHEACTIVEGROUP_H
