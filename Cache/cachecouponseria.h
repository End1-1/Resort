#ifndef CACHECOUPONSERIA_H
#define CACHECOUPONSERIA_H

#include "cachebasestruct.h"

#define cid_coupon_seria 109


class CacheCouponSeria : public CacheBaseStruct
{
public:
    CacheCouponSeria();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
    inline double fPrice() { return getDouble("f_price"); }
    inline QStringList fItems() { return getString("f_items").split(",", Qt::SkipEmptyParts); }
};

#endif // CACHECOUPONSERIA_H
