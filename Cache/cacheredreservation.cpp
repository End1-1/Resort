#include "cacheredreservation.h"
#include "cacheone.h"

CacheRedReservation::CacheRedReservation() :
    CacheBaseStruct()
{
    fCacheId = cid_red_reservation;
    fLoadQuery = "select r.f_id, r.f_id as f_name, concat(g.f_title, ' ', g.f_firstName, ' ' ,g.f_lastName) as f_guest, \
            r.f_room, a.amount, r.f_startDate, r.f_endDate, r.f_invoice \
            from f_reservation r \
            left join (select f_res, sum(f_amountAmd*f_sign*-1) as amount from m_register where f_source='AV' and f_canceled=0 group by 1) a on a.f_res=r.f_id \
            inner join f_guests g on g.f_id=r.f_guest \
            where r.f_state=2 :cond \
            group by 1, 2, 3";
    fUpdateQuery = " and r.f_id=:f_id";
    fReplaceUpdateQuery = ":cond";
    fSelectorTitle = QObject::tr("Reservation");
    getSelectorWidths(5, 80, 0, 200, 100, 150);
    QStringList titles;
    titles << QObject::tr("Code")
           << QObject::tr("Name")
           << QObject::tr("Guest")
           << QObject::tr("Room")
           << QObject::tr("Balance");
    getSelectorTitles(titles);
    
}
