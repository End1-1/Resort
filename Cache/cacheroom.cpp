#include "cacheroom.h"

CacheRoom::CacheRoom() :
    CacheBaseStruct()
{
    fLoadQuery = "select r.f_id, r.f_short, r.f_state, c.f_short as f_cshort, c.f_description, r.f_bed, r.f_smoke, "
            "r.f_rate, r.f_floor, v.f_" + def_lang + " as f_view "
            "from f_room r "
            "inner join f_room_classes c on c.f_id=r.f_class "
            "inner join f_room_view v on v.f_id=r.f_view ";
    fUpdateQuery = "r.f_id=:f_id";
    fCacheId = cid_room;
    fSelectorTitle = QObject::tr("Room");
    getSelectorTwoField();

}


bool CI_Romm_compare(QString &left, QString &right)
{
    return left.toInt() < right.toInt();
}
