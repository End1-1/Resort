#include "cacherefundinvoice.h"

CacheRefundInvoice::CacheRefundInvoice() :
    CacheBaseStruct()
{
    fLoadQuery = "select r.f_invoice, r.f_invoice as f_name, r.f_startDate, r.f_endDate, "
                 "r.f_room, r.f_id as f_reservation, "
                 "concat(g.f_firstName, ' ', g.f_lastName) as f_guest "
                 "from f_reservation r "
                 "left join f_guests g on g.f_id=r.f_guest "
                 "where 1=1 :cond "
                 "order by r.f_endDate desc, r.f_id desc ";
    fReplaceUpdateQuery = ":cond";
    fUpdateQuery = " and r.f_invoice=:f_id";
    fCacheId = cid_refund_invoice;
    fSelectorTitle = QObject::tr("Invoices for refund");
    getSelectorWidths(7, 0, 120, 100, 100, 80, 120, 220);
    QStringList titles;
    titles << QObject::tr("Code")
           << QObject::tr("Invoice")
           << QObject::tr("Entry")
           << QObject::tr("Departure")
           << QObject::tr("Room")
           << QObject::tr("Reservation")
           << QObject::tr("Guest");
    getSelectorTitles(titles);
}
