#ifndef CACHERESTHALL_H
#define CACHERESTHALL_H

#include "cachebasestruct.h"

#define cid_rest_hall 25

class CacheRestHall : public CacheBaseStruct
{
public:
    CacheRestHall();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
    inline QString fDefaultMenu() { return getString("f_defaultMenu"); }
};

#endif // CACHERESTHALL_H
