#ifndef CACHECHECKOUTINVOICE_H
#define CACHECHECKOUTINVOICE_H

#include "cachebasestruct.h"

#define cid_checkout_invoice 63

extern QDate CheckoutMinDate;

class CacheCheckoutInvoice : public CacheBaseStruct
{
public:
    CacheCheckoutInvoice();
    int fCurrPos;
    void next();
    void prev();
    inline QString fCode() {return getString("f_invoice"); }
    inline QString fName() {return getString("f_invoice"); }
    inline QString fReservation() {return getString("f_reservation"); }
    inline QString fRoom() {return getString("f_room"); }
    inline QString fGuest() {return getString("f_guest"); }
    inline QString fEntry() {return getDate("f_startDate").toString(def_date_format); }
    inline QDate fDeparture() {return getDate("f_endDate"); }
    inline QString fAmount() {return getString("amount"); }
    inline QString fOperator() {return getString("f_username"); }
};

#endif // CACHECHECKOUTINVOICE_H
