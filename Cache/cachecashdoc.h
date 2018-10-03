#ifndef CACHECASHDOC_H
#define CACHECASHDOC_H

#include "cachebasestruct.h"

#define cid_cash_doc 111

#define CASHDOC_STORE 1
#define CASHDOC_SALE 2
#define CASHDOC_SALARY 3
#define CASHDOC_MOVE 4
#define CASHDOC_DEBT 5

class CacheCashDoc : public CacheBaseStruct
{
public:
    CacheCashDoc();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHECASHDOC_H
