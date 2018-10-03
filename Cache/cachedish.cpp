#include "cachedish.h"

CacheDish::CacheDish() :
    CacheBaseStruct()
{
    fLoadQuery = "select f_id, f_" + def_lang + " from r_dish";
    fUpdateQuery = "f_id=:f_id";
    fCacheId = cid_dish;
    fSelectorTitle = QObject::tr("Dish");
    getSelectorTwoField();
    
}
