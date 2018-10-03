#ifndef CACHEVATMODE_H
#define CACHEVATMODE_H

#include "cachebasestruct.h"

#define cid_vat_mode 22

class CacheVatMode : public CacheBaseStruct
{
public:
    CacheVatMode();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHEVATMODE_H
