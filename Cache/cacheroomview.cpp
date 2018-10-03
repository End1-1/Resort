#include "cacheroomview.h"

CacheRoomView::CacheRoomView() :
    CacheBaseStruct()
{
    fCacheId = cid_room_view;
    fLoadQuery = "select f_id, f_short from f_room_view";
    fSelectorTitle = QObject::tr("Room view");
    getSelectorTwoField();

}
