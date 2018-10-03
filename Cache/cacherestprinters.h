#ifndef CACHERESTPRINTERS_H
#define CACHERESTPRINTERS_H

#include "cachebasestruct.h"

#define cid_rest_printers 30

class CacheRestPrinters : public CacheBaseStruct
{
public:
    CacheRestPrinters();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHERESTPRINTERS_H
