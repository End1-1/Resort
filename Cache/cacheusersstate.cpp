#include "cacheusersstate.h"

CacheUsersState::CacheUsersState() :
    CacheBaseStruct()
{
    fCacheId = cid_users_state;
    fLoadQuery = "select f_id, f_" + def_lang + " from users_states";
    fSelectorTitle = QObject::tr("User state");
    getSelectorTwoField();

}

