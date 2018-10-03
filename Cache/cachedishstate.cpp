#include "cachedishstate.h"

CacheDishState::CacheDishState()
{
    fLoadQuery = "select f_id, f_" + def_lang + " from o_dish_state";
    fUpdateQuery = "f_id=:f_id";
    fCacheId = cid_dish_state;
    fSelectorTitle = QObject::tr("Dish state");
    getSelectorTwoField();

}
