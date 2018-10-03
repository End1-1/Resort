#include "cacheroomstate.h"

CacheRoomState::CacheRoomState() :
    CacheBaseStruct()
{
    fCacheId = cid_room_state;
    fLoadQuery = "select f_id, f_" + def_lang + " from f_room_state";
    fSelectorTitle = QObject::tr("Room state");
    getSelectorTwoField();

}
