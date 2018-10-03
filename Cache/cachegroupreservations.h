#ifndef CACHEGROUPRESERVATIONS_H
#define CACHEGROUPRESERVATIONS_H

#include "cachebasestruct.h"

#define cid_group_reservation 117

class CacheGroupReservations : public CacheBaseStruct
{
public:
    CacheGroupReservations();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHEGROUPRESERVATIONS_H
