#include "cacheactiveroom.h"

CacheActiveRoom::CacheActiveRoom() :
    CacheBaseStruct()
{
    fCacheId = cid_active_room;
    fLoadQuery = "select r.f_room, rm.f_short, r.f_invoice, concat(g.f_title, ' ' , g.f_firstName, ' ' , g.f_lastName) as f_guest, "
                     "r.f_id, r.f_startdate, r.f_enddate "
                    "from f_reservation r "
                    "inner join f_room rm on rm.f_id=r.f_room "
                    "inner join f_guests g on g.f_id=r.f_guest "
                    "where r.f_state=" + QString::number(RESERVE_CHECKIN) + " :cond";
    fReplaceUpdateQuery = ":cond";
    fUpdateQuery = " and r.f_room=:f_id";
    getSelectorWidths(4, 80, 120, 100, 250);
    QStringList titles;
    titles << QObject::tr("Room")
           << QObject::tr("Room name")
           << QObject::tr("Invoice")
           << QObject::tr("Guest");
    getSelectorTitles(titles);
    
}
