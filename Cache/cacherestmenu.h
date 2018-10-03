#ifndef CACHERESTMENU_H
#define CACHERESTMENU_H

#include "cachebasestruct.h"

#define cid_rest_menu 26

class CacheRestMenu : public CacheBaseStruct
{
public:
    CacheRestMenu();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHERESTMENU_H
