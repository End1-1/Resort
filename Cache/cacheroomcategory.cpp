#include "cacheroomcategory.h"

CacheRoomCategory::CacheRoomCategory() :
    CacheBaseStruct()
{
    fCacheId = cid_room_category;
    fLoadQuery = "select f_id, f_short, f_description, f_queue from f_room_classes";
    fSelectorTitle = QObject::tr("Room category");
    getSelectorWidths(4, 80, 120, 250, 100);
    QStringList titles;
    titles << QObject::tr("Code")
           << QObject::tr("Short")
           << QObject::tr("Description")
           << QObject::tr("Queue");
    getSelectorTitles(titles);

}
