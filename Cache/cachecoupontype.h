#ifndef CACHECOUPONTYPE_H
#define CACHECOUPONTYPE_H

#include "cachebasestruct.h"

#define cid_coupon_type 104

#define COUPON_STATE_NEW 1
#define COUPON_STATE_DELIVERED 2
#define COUPON_STATE_USED 3
#define COUPON_STATE_EXPARED 4

class CacheCouponType : public CacheBaseStruct
{
public:
    CacheCouponType();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHECOUPONTYPE_H
