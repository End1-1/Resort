#ifndef CACHERESTDISHTYPE_H
#define CACHERESTDISHTYPE_H

#include "cachebasestruct.h"

#define cid_rest_dish_type 29

class CacheRestDishType : public CacheBaseStruct
{
public:
    CacheRestDishType();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHERESTDISHTYPE_H
