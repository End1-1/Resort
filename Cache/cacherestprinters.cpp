#include "cacherestprinters.h"

CacheRestPrinters::CacheRestPrinters() :
    CacheBaseStruct()
{
    fCacheId = cid_rest_printers;
    fLoadQuery = "select f_id, f_name from r_printers";
    fSelectorTitle = QObject::tr("Printers");
    getSelectorTwoField();

}
