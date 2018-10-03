#ifndef CACHERESTDISHPART_H
#define CACHERESTDISHPART_H

#include "cachebasestruct.h"

#define cid_rest_dish_part 28

class CacheRestDishPart : public CacheBaseStruct
{
public:
    CacheRestDishPart();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHERESTDISHPART_H
