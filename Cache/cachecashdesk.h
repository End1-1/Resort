#ifndef CACHECASHDESK_H
#define CACHECASHDESK_H

#include "cachebasestruct.h"

#define cid_cash_desk 110

class CacheCashDesk : public CacheBaseStruct
{
public:
    CacheCashDesk();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHECASHDESK_H
