#ifndef CACHEREDRESERVATION_H
#define CACHEREDRESERVATION_H

#include "cachebasestruct.h"

static const int cid_red_reservation = 45;

class CacheRedReservation : public CacheBaseStruct
{
public:
    CacheRedReservation();
    inline QString fCode()  {return getString("f_id"); }
    inline QString fGuest() {return getString("f_guest"); }
    inline QString fRoom() { return getString("f_room"); }
    inline QString fName() { return getString("f_guest"); }
    inline QString fInvoice() {return getString("f_invoice"); }
    inline QString fBalance() {return getString("amount"); }
    inline QString fEntry() {return getDate("f_startDate").toString(def_date_format); }
    inline QString fDeparture() {return getDate("f_endDate").toString(def_date_format); }
};

#endif // CACHEREDRESERVATION_H
