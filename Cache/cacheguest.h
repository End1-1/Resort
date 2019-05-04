#ifndef CACHEGUEST_H
#define CACHEGUEST_H

#include "cachebasestruct.h"

static const int cid_guest = 43;

class CacheGuest : public CacheBaseStruct
{
public:
    CacheGuest();
    inline QString fId() {return getString("f_id"); }
    inline QString fCode() {return getString("f_code"); }
    inline QString fName() {return getString("f_fullName"); }
    inline QString fFullName() {return getString("f_fullName"); }
    inline QString fTitle() { return getString("f_title"); }
    inline QString fNatShort() {return getString("f_nation"); }
    inline QString fNatFull() { return getString("f_natFull"); }
    inline QString fPassport() {return getString("f_passport"); }
    inline QString fFirstName() {return getString("f_firstName");}
    inline QString fLastName() {return getString("f_lastName"); }
};

#endif // CACHEGUEST_H
