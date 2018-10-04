#include "cacheusersgroups.h"

CacheUsersGroups::CacheUsersGroups() :
    CacheBaseStruct()
{
    fCacheId = cid_users_group;
    fLoadQuery = "select f_id, f_" + def_lang + ", f_minDate from users_groups";
    fSelectorTitle = QObject::tr("Users groups");
    getSelectorTwoField();

}
