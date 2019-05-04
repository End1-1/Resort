#ifndef CACHECARDEX_H
#define CACHECARDEX_H

#include "cachebasestruct.h"

static const int cid_cardex = 5;

class CacheCardex : public CacheBaseStruct
{
public:
    CacheCardex();
    inline QString fCode() { return getString("f_cardex"); }
    inline QString fName() {return getString("f_name"); }
    QString fVatMode() {return getString("f_vatMode"); }
    QString fGroup() {return getString("f_group"); }
    QString fVatName() {return getString("f_" + def_lang); }
    QString fCommission() {return getString("f_commission"); }
    QString fDateTo() {return getString("f_dateTo"); }
    bool fBookingRequired() { return getString("f_bookingRequired") == "1"; }
};

#endif // CACHECARDEX_H
