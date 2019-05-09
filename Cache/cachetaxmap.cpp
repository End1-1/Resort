#include "cachetaxmap.h"
#include <QHostInfo>

CacheTaxMap::CacheTaxMap() :
    CacheBaseStruct()
{
    fCacheId = cid_tax_map;
    fLoadQuery = "select f_item, f_dept from f_invoice_item_tax where upper(f_comp)=upper('" + def_station + QHostInfo::localHostName() + "') :where";
    fReplaceUpdateQuery = ":where";
    fUpdateQuery = "  and f_item=:f_id ";
}
