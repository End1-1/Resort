#include "cachecashdoc.h"

CacheCashDoc::CacheCashDoc() :
    CacheBaseStruct()
{
    fLoadQuery = "select f_id, f_name from c_doc_type";
    fUpdateQuery = "f_id=:f_id";
    fCacheId = cid_cash_doc;
    fSelectorTitle = QObject::tr("Cash document type");
    getSelectorTwoField();
    
}
