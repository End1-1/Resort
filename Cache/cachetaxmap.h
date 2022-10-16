#ifndef CACHETAXMAP_H
#define CACHETAXMAP_H

#include "cachebasestruct.h"

#define cid_tax_map 105

class CacheTaxMap : public CacheBaseStruct
{
public:
    CacheTaxMap();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_dept"); }
    inline int fTax() {return getInt("f_tax");}
};

#endif // CACHETAXMAP_H
