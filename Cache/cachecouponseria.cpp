#include "cachecouponseria.h"

CacheCouponSeria::CacheCouponSeria() :
    CacheBaseStruct()
{
    fLoadQuery = "select f_id, f_name, f_price, f_items from d_coupon_seria ";
    fUpdateQuery = "f_id=:f_id";
    fCacheId = cid_coupon_seria;
    fSelectorTitle = QObject::tr("Coupon seria");
    getSelectorTwoField();
    
}
