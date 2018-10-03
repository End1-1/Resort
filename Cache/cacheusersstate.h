#ifndef CACHEUSERSSTATE_H
#define CACHEUSERSSTATE_H

#include "cachebasestruct.h"

#define cid_users_state 41

class CacheUsersState : public CacheBaseStruct
{
public:
    CacheUsersState();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHEUSERSSTATE_H
