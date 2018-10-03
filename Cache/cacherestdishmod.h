#ifndef CACHERESTDISHMOD_H
#define CACHERESTDISHMOD_H

#include "cachebasestruct.h"

#define cid_rest_dish_mod 32

class CacheRestDishMod : public CacheBaseStruct
{
public:
    CacheRestDishMod();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHERESTDISHMOD_H
