#ifndef CACHEDOCPAYMENT_H
#define CACHEDOCPAYMENT_H

#include "cachebasestruct.h"

#define cid_doc_payment 108

class CacheDocPayment : public CacheBaseStruct
{
public:
    CacheDocPayment();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHEDOCPAYMENT_H
