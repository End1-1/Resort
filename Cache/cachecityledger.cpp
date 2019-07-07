#include "cachecityledger.h"

CacheCityLedger::CacheCityLedger() :
    CacheBaseStruct()
{
    fCacheId = cid_city_ledger;
    fLoadQuery = "select f_id, f_name, f_extra1, f_extra2 from f_city_ledger ";
    fUpdateQuery = "f_id=:f_id";
    getSelectorWidths(4, 80, 250, 100, 120);
    QStringList titles;
    titles << QObject::tr("Code")
           << QObject::tr("Name")
           << QObject::tr("Extra1")
           << QObject::tr("Extra2");
    getSelectorTitles(titles);
    
}
