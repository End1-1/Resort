#include "cachestorepartners.h"

CacheStorePartners::CacheStorePartners() :
    CacheBaseStruct()
{
    fCacheId = cid_store_partners;
    fLoadQuery = "select f_id, f_name, f_taxcode, f_phone, f_comment from r_partners";
    fSelectorTitle = QObject::tr("Partners");
    getSelectorWidths(4, 80, 100, 200, 100);
    QStringList titles;
    titles << QObject::tr("Code")
           << QObject::tr("Tax code")
           << QObject::tr("Name")
           << QObject::tr("Phone");
    getSelectorTitles(titles);

}
