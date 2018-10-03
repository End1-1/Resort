#include "cachepaymentmode.h"
#include "cacheone.h"

CachePaymentMode::CachePaymentMode() :
    CacheBaseStruct()
{
    fCacheId = cid_payment_mode;
    fLoadQuery = "select f_id, f_" + def_lang + " from f_payment_type order by 2 ";
    fSelectorTitle = QObject::tr("Payment mode");
    getSelectorTwoField();
    
}
