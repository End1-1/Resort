#include "cacherestmenu.h"

CacheRestMenu::CacheRestMenu() :
    CacheBaseStruct()
{
    fCacheId = cid_rest_menu;
    fLoadQuery = "select f_id, f_" + def_lang + " from r_menu_names";
    fSelectorTitle = QObject::tr("Menu");
    getSelectorTwoField();

}
