#include "cachecurrencies.h"


CacheCurrencies::CacheCurrencies() :
    CacheBaseStruct()
{
    fCacheId = cid_currencies;
    fLoadQuery = "select f_id, f_short, f_name, f_rate from f_acc_currencies";
    fUpdateQuery = "f_id=:f_id";
    getSelectorTwoField();
    
}
