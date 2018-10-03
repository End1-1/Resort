#include "cacherestdebtholder.h"
#include "cacheone.h"

CacheRestDebtHolder::CacheRestDebtHolder() :
    CacheBaseStruct()
{
    fCacheId = cid_rest_debt_holder;
    fLoadQuery = "select d.f_id, d.f_name, g.f_gov, f_info from o_debt_holder d "
             "left join (select f_holder, group_concat(f_govNumber) as f_gov from o_debt_holder_car group by 1) g on g.f_holder=d.f_id ";
    
    getSelectorTwoField();
}
