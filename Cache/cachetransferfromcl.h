#ifndef CACHETRANSFERFROMCL_H
#define CACHETRANSFERFROMCL_H

#include "cachebasestruct.h"

static const quint32 cid_transfer_fromcl = 119;

class CacheTransferFromCL : public CacheBaseStruct
{
public:
    CacheTransferFromCL();
    inline QString fCode() {return getString("f_cityLedger"); }
    inline QString fName() {return getString("f_name"); }
    inline double fAmount() {return getDouble("amount"); }
};

#endif // CACHETRANSFERFROMCL_H
