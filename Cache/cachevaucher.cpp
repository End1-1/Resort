#include "cachevaucher.h"

CacheVaucher::CacheVaucher()
{
    fLoadQuery = "select f_code, f_description from m_vaucher";
    fCacheId = cid_vaucher;
    fSelectorTitle = QObject::tr("Voucher type");
    getSelectorTwoField();

}
