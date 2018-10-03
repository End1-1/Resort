#include "cachedocpayment.h"

CacheDocPayment::CacheDocPayment() :
    CacheBaseStruct()
{
    fCacheId = cid_doc_payment;
    fLoadQuery = "select f_id, f_name from r_doc_payment order by f_id";
    fUpdateQuery = "f_id=:f_id";
    getSelectorTwoField();
    
}
