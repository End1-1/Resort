#ifndef CACHESTOREPARTNERS_H
#define CACHESTOREPARTNERS_H

#include "cachebasestruct.h"

#define cid_store_partners 101

class CacheStorePartners : public CacheBaseStruct
{
public:
    CacheStorePartners();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
    inline QString fTaxCode() {return getString("f_taxcode"); }
    inline QString fPhone() {return getString("f_phone"); }
    inline QString fComments() {return getString("f_comment"); }
};

#endif // CACHESTOREPARTNERS_H
