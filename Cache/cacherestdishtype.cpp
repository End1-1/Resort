#include "cacherestdishtype.h"

CacheRestDishType::CacheRestDishType() :
    CacheBaseStruct()
{
    fCacheId = cid_rest_dish_type;
    fLoadQuery = "select f_id, f_" + def_lang + " from r_dish_type";
    fSelectorTitle = QObject::tr("Dish type");
    getSelectorTwoField();

}
