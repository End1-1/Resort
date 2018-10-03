#ifndef CACHEORDERSTATE_H
#define CACHEORDERSTATE_H

#include "cachebasestruct.h"

#define cid_order_state  60

class CacheOrderState : public CacheBaseStruct
{
public:
    CacheOrderState();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHEORDERSTATE_H
