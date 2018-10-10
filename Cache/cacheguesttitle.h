#ifndef CACHEGUESTTITLE_H
#define CACHEGUESTTITLE_H

#include "cachebasestruct.h"

#define cid_guest_title 23


class CacheGuestTitle : public CacheBaseStruct
{
public:
    CacheGuestTitle();
    inline QString fId() {return getString("f_" + def_lang); }
    inline QString fName() {return getString("f_" + def_lang); }
};

#endif // CACHEGUESTTITLE_H
