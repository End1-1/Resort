#include "cacheinvoiceitem.h"

CacheInvoiceItem::CacheInvoiceItem() :
    CacheBaseStruct()
{
    fCacheId = cid_invoice_item;
    fLoadQuery = "select f_id, f_" + def_lang + ", f_group, f_en, f_am, f_ru, f_adgt, "
            "f_vatDept, f_noVatDept, f_taxName, f_vaucher, f_auto, f_price, f_vatReception  from f_invoice_item";
    fUpdateQuery = "f_id=:f_id";
    fSelectorTitle = QObject::tr("Type of sale");
    QStringList titles;
    titles << QObject::tr("Code")
           << QObject::tr("Name")
           << QObject::tr("Group");
    getSelectorTitles(titles);
    getSelectorWidths(3, 80, 300, 0);
    
}
