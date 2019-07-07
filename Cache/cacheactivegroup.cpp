#include "cacheactivegroup.h"

CacheActiveGroup::CacheActiveGroup() :
    CacheBaseStruct ()
{
    fCacheId = cid_active_group;
    fLoadQuery = "select g.f_id, g.f_name, count(r.f_id) "
            "from f_reservation_group g "
            "inner join f_reservation r on r.f_group=g.f_id  "
            "where r.f_state in (1, 2) "
            "group by 1, 2";
    fSelectorTitle = QObject::tr("Reservation groups");
    getSelectorTwoField();
}
