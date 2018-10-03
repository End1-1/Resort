#ifndef CACHESTOREDOCSTATE_H
#define CACHESTOREDOCSTATE_H

#include "cachebasestruct.h"

#define cid_store_doc_state 103

class CacheStoreDocState : public CacheBaseStruct
{
public:
    CacheStoreDocState();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_name"); }
};

#endif // CACHESTOREDOCSTATE_H
