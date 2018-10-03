#include "cachenation.h"

CacheNation::CacheNation() :
    CacheBaseStruct()
{
    fCacheId = cid_nation;
    fLoadQuery = "select f_short, f_name from f_nationality";
    fUpdateQuery = "f_short";
    fSelectorTitle = QObject::tr("Nation");
    getSelectorTwoField();
    
}
