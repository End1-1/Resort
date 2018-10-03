#include "cacherestdishmod.h"

CacheRestDishMod::CacheRestDishMod() :
    CacheBaseStruct()
{
    fLoadQuery = "select f_id, f_" + def_lang + " from r_dish_mod";
    fCacheId = cid_rest_dish_mod;
    fSelectorTitle = QObject::tr("Dish modifiers");
    getSelectorTwoField();
    
}
