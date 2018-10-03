#ifndef CACHECURRENCIES_H
#define CACHECURRENCIES_H

#include "cachebasestruct.h"

#define cid_currencies 51


class CacheCurrencies : public CacheBaseStruct
{
public:
    CacheCurrencies();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_short"); }
    inline QString fDescription() {return getString("f_name"); }
    inline double fRate() {return getDouble("f_rate"); }
};

#endif // CACHECURRENCIES_H
