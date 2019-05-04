#ifndef CACHECITYLEDGER_H
#define CACHECITYLEDGER_H

#include "cachebasestruct.h"

static const int cid_city_ledger = 24;

class CacheCityLedger : public CacheBaseStruct
{
public:
    CacheCityLedger();
    inline QString fCode() {return getString("f_id"); }
    inline QString fName() {return getString("f_name");}
    inline QString fVatMode() {return "";}
    inline QString fVatName() {return ""; }
    inline QString fCommission() {return ""; }
    inline QString fDateTo() {return "";}
    inline QString fExtra1() {return getString("f_extra1"); }
    inline QString fExtra2() {return getString("f_extra2"); }

};

#endif // CACHECITYLEDGER_H
