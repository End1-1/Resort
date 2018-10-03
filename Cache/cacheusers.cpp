#include "cacheusers.h"

CacheUsers::CacheUsers() :
    CacheBaseStruct()
{
    fCacheId = cid_users;
    fLoadQuery = "select f_id, f_userName, concat(f_firstName, ' ', f_lastName) as f_full, f_group from users";
    fSelectorTitle = QObject::tr("Users");
    getSelectorTwoField();

}
