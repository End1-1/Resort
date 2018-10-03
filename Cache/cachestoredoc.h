#ifndef CACHESTOREDOC_H
#define CACHESTOREDOC_H

#include "cachebasestruct.h"

#define cid_store_doc_type 102

class CacheStoreDocType : public CacheBaseStruct
{
public:
    CacheStoreDocType();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHESTOREDOC_H
