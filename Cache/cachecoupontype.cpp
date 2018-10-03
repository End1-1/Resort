#include "cachecoupontype.h"

CacheCouponType::CacheCouponType() :
    CacheBaseStruct()
{
    fCacheId = cid_coupon_type;
    fLoadQuery = "select f_id, f_name from d_type";
    fUpdateQuery = "f_id=:f_id";
    getSelectorTwoField();
    
}
