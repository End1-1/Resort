#include "cachecashdesk.h"

CacheCashDesk::CacheCashDesk() :
    CacheBaseStruct()
{
    fLoadQuery = "select f_id, f_name from c_cash_names";
    fUpdateQuery = "f_id=:f_id";
    fCacheId = cid_cash_desk;
    fSelectorTitle = QObject::tr("Cashdesk");
    getSelectorTwoField();
    
}
