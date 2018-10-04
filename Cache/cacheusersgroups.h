#ifndef CACHEUSERSGROUPS_H
#define CACHEUSERSGROUPS_H

#include "cachebasestruct.h"

#define cid_users_group 40

class CacheUsersGroups : public CacheBaseStruct
{
public:
    CacheUsersGroups();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
    inline QDate fMinDate() { return getDate("f_minDate"); }
};

#endif // CACHEUSERSGROUPS_H
