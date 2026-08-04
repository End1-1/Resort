#ifndef CACHEREFUNDINVOICE_H
#define CACHEREFUNDINVOICE_H

#include "cachebasestruct.h"

#define cid_refund_invoice 121

class CacheRefundInvoice : public CacheBaseStruct
{
public:
    CacheRefundInvoice();
    inline QString fCode() { return getString("f_invoice"); }
    inline QString fName() { return getString("f_invoice"); }
    inline QString fReservation() { return getString("f_reservation"); }
    inline QString fRoom() { return getString("f_room"); }
    inline QString fGuest() { return getString("f_guest"); }
    inline QString fEntry() { return getDate("f_startDate").toString(def_date_format); }
    inline QString fDeparture() { return getDate("f_endDate").toString(def_date_format); }
};

#endif // CACHEREFUNDINVOICE_H
