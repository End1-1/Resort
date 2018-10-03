#ifndef CACHERESTFULLMENU_H
#define CACHERESTFULLMENU_H

#include "cachebasestruct.h"

#define cid_rest_full_menu 113

class CacheRestFullMenu : public CacheBaseStruct
{
public:
    CacheRestFullMenu();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("mfen"); }
    inline int fMenuCode() { return getInt("f_menu"); }
    inline int fDishCode() { return getInt("f_dish"); }
    inline int fStore() { return getInt("f_store"); }
    inline QString fNameInt(const QString &country) { return getString("f_" + country); }
    inline double fPrice() {return getDouble("f_price"); }
};

#endif // CACHERESTFULLMENU_H
