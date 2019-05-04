#ifndef CACHEINVOICEITEM_H
#define CACHEINVOICEITEM_H

#include "cachebasestruct.h"

static const int cid_invoice_item = 20;

class CacheInvoiceItem : public CacheBaseStruct
{
public:
    CacheInvoiceItem();
    inline QString fCode() {return getString("f_id"); }
    inline QString fName(){ return getString("f_" + def_lang);}
    inline int fGroup() { return getInt("f_group"); }
    inline QString fVaucher() {return getString("f_vaucher"); }
    inline QString fName2(const QString &country) {return getString("f_" + country); }
    inline QString fAdgt() {return getString("f_adgt"); }
    inline QString fVatDept() {return getString("f_vatDept"); }
    inline QString fVatReception() {return getString("f_vatReception"); }
    inline QString fNoVatDept() {return getString("f_noVatDept"); }
    inline QString fTaxName() {return getString("f_taxName"); }
    inline double fPrice() {return getDouble("f_price"); }
    inline bool fNoManual() {return getInt("f_auto") == 1 ? true : false; }
};

#endif // CACHEINVOICEITEM_H
