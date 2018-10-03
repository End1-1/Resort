#ifndef CACHECARDEXGROUP_H
#define CACHECARDEXGROUP_H

#include "cachebasestruct.h"

#define cid_cardex_group 58

class CacheCardexGroup : public CacheBaseStruct
{
public:
    CacheCardexGroup();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_code"); }
};

#endif // CACHECARDEXGROUP_H
