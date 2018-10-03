#ifndef CACHENATION_H
#define CACHENATION_H

#include "cachebasestruct.h"

#define cid_nation 53

class CacheNation : public CacheBaseStruct
{
public:
    CacheNation();
    inline QString fId() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHENATION_H
