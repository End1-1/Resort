#include "cachevatmode.h"

CacheVatMode::CacheVatMode() :
    CacheBaseStruct()
{
    fCacheId = cid_vat_mode;
    fLoadQuery = "select f_id, f_" + def_lang + " from f_vat_mode";
    fSelectorTitle = QObject::tr("VAT mode");
    getSelectorTwoField();

}
