#include "cacherestdishpart.h"

CacheRestDishPart::CacheRestDishPart() :
    CacheBaseStruct()
{
    fCacheId = cid_rest_dish_part;
    fLoadQuery = "select f_id, f_" + def_lang + " from r_dish_part";
    fSelectorTitle = QObject::tr("Menu main partitions");
    getSelectorTwoField();

}
