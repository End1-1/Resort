#include "cachereservationcardex.h"

CacheReservationCardex::CacheReservationCardex()
{
    fLoadQuery = "select distinct(r.f_cardex), c.f_name from f_reservation r "
            "left join f_cardex c on c.f_cardex=r.f_cardex where length(r.f_cardex)>0 "
            "and r.f_state in (1,2) :cond ";
    fReplaceUpdateQuery = ":cond";
    fUpdateQuery = " and r.f_id=:f_id";
    fSelectorTitle = QObject::tr("Cardex");
    getSelectorTwoField();
    
}
