#ifndef CACHEINVOICEITEMGROUP_H
#define CACHEINVOICEITEMGROUP_H

#include "cachebasestruct.h"

#define cid_invoice_group 57

class CacheInvoiceItemGroup : public CacheBaseStruct
{
public:
    CacheInvoiceItemGroup();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_" + def_lang); }
};

#endif // CACHEINVOICEITEMGROUP_H
