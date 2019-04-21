#ifndef CACHECREDITCARD_H
#define CACHECREDITCARD_H

#include "cachebasestruct.h"

static const int cid_credit_card = 44;

class CacheCreditCard : public CacheBaseStruct
{
public:
    CacheCreditCard();
    inline QString fCode() {return getString("f_id"); }
    inline QString fName() {return getString("f_name"); }
};

#endif // CACHECREDITCARD_H
