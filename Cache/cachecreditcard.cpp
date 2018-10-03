#include "cachecreditcard.h"

CacheCreditCard::CacheCreditCard() :
    CacheBaseStruct()
{
    fCacheId = cid_credit_card;
    fLoadQuery = "select f_id, f_name from f_credit_card";
    fUpdateQuery = "f_id=:f_id";
    fSelectorTitle = QObject::tr("Credit card");
    getSelectorTwoField();
    
}
