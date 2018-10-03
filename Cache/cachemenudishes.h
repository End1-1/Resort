#ifndef CACHEMENUDISHES_H
#define CACHEMENUDISHES_H

#include "cachebasestruct.h"

#define cid_menu_dishes 49

class CacheMenuDishes : public CacheBaseStruct
{
public:
    CacheMenuDishes();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_dishName"); }
    inline QString fMenuId() {return getString("f_menu"); }
    inline QString fTypeName() {return getString("f_typename"); }
    inline QString fMenu() { return getString("f_menuname"); }
    inline QString fPrice() {return getString("f_price"); }
};

#endif // CACHEMENUDISHES_H
