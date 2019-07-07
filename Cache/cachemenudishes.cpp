#include "cachemenudishes.h"

CacheMenuDishes::CacheMenuDishes() :
    CacheBaseStruct()
{
    fCacheId = cid_menu_dishes;
    fLoadQuery = "select m.f_id, m.f_menu, mn.f_" + def_lang + " as f_menuName, t.f_en as f_typename, "
            "m.f_dish, d.f_" + def_lang + " as f_dishName, m.f_price "
            "from r_menu m "
            "inner join r_dish d on d.f_id=m.f_dish "
            "inner join r_dish_type t on t.f_id=d.f_type "
            "inner join r_menu_names mn on mn.f_id=m.f_menu "
            "where m.f_state=1 :cond";
    fSelectorTitle = QObject::tr("Menu dishes");
    fReplaceUpdateQuery = ":cond";
    fUpdateQuery = " and m.f_id=:f_id";
    getSelectorWidths(4, 120, 250, 350, 80);
    QStringList titles;
    titles << QObject::tr("Menu")
           << QObject::tr("Type")
           << QObject::tr("Dish")
           << QObject::tr("Price");
    getSelectorTitles(titles);
    
}
