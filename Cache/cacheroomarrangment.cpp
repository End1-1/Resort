#include "cacheroomarrangment.h"


CacheRoomArrangment::CacheRoomArrangment() :
    CacheBaseStruct()
{
    fCacheId = cid_room_arrangment;
    fLoadQuery = "select f_id, f_" + def_lang + " from f_room_arrangement";
    fSelectorTitle = QObject::tr("Room arrangment");
    getSelectorTwoField();

}
