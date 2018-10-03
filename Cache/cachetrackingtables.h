#ifndef CACHETRACKINGTABLES_H
#define CACHETRACKINGTABLES_H

#include "cachebasestruct.h"

#define cid_tracking_tables 38

class CacheTrackingTables : public CacheBaseStruct
{
public:
    CacheTrackingTables();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHETRACKINGTABLES_H
