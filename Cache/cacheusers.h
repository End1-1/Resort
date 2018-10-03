#ifndef CACHEUSERS_H
#define CACHEUSERS_H

#include "cachebasestruct.h"

#define cid_users 39

class CacheUsers : public CacheBaseStruct
{
public:
    CacheUsers();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_userName"); }
    inline QString fFull() { return getString("f_full"); }
    inline QString fGroup() { return getString("f_group"); }
};

#endif // CACHEUSERS_H
