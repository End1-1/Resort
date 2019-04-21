#ifndef CACHEPAYMENTMODE_H
#define CACHEPAYMENTMODE_H

#include "cachebasestruct.h"

static const int cid_payment_mode = 11;

class CachePaymentMode : public CacheBaseStruct
{
public:
    CachePaymentMode();
    inline QString fCode() {return getString("f_id"); }
    inline QString fName() {return getString("f_" + def_lang); }
};

#endif // CACHEPAYMENTMODE_H
