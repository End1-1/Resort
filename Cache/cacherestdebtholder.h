#ifndef CACHERESTDEBTHOLDER_H
#define CACHERESTDEBTHOLDER_H

#include "cachebasestruct.h"

#define cid_rest_debt_holder 107

class CacheRestDebtHolder : public CacheBaseStruct
{
public:
    CacheRestDebtHolder();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
    inline QString fGovNumber() { return getString("f_gov"); }
    inline QString fInfo() { return getString("f_info"); }
};

#endif // CACHERESTDEBTHOLDER_H
