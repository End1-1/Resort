#include "cacherestfullmenu.h"

CacheRestFullMenu::CacheRestFullMenu()
{
    fLoadQuery = "select m.f_id, m.f_menu, mn.f_en as mfen, m.f_dish, d.f_en, d.f_am, d.f_ru, m.f_price, m.f_store "
            "from r_menu m "
            "left join r_dish d on d.f_id=m.f_dish "
            "left join r_menu_names mn on mn.f_id=m.f_menu "
            "where m.f_state=1 :cond"
            "order by 1, 4 ";
    fReplaceUpdateQuery = ":cond";
    fUpdateQuery = " and m.f_id=:f_id";
    fCacheId = cid_rest_full_menu;
    fSelectorTitle = QObject::tr("Dishes");
    getSelectorWidths(5, 0, 200, 0, 300, 80);
    QStringList titles;
    titles << QObject::tr("Code")
           << QObject::tr("Menu")
           << QObject::tr("Code")
           << QObject::tr("Dish")
           << QObject::tr("Price");
    getSelectorTitles(titles);

}
