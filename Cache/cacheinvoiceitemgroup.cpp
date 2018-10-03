#include "cacheinvoiceitemgroup.h"


CacheInvoiceItemGroup::CacheInvoiceItemGroup() :
    CacheBaseStruct()
{
    fLoadQuery = "select f_id, f_" + def_lang + " from f_invoice_item_group";
    fCacheId = cid_invoice_group;
    fSelectorTitle = QObject::tr("Invoice item group");
    getSelectorTwoField();
    
}
