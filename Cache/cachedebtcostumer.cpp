#include "cachedebtcostumer.h"

CacheDebtCostumer::CacheDebtCostumer() :
    CacheBaseStruct()
{
    fLoadQuery = "select f_id, f_name from o_debt_holder ";
    fUpdateQuery = "f_id=:f_id";
    fCacheId = cid_debt_costumer;
    fSelectorTitle = QObject::tr("Debt costumer");
    
}
