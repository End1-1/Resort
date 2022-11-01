#ifndef CACHEFISCALMACHINE_H
#define CACHEFISCALMACHINE_H

#include "cachebasestruct.h"

static const int cid_fiscalmachine = 200;

class CacheFiscalMachine : public CacheBaseStruct
{
public:
    CacheFiscalMachine();
    inline QString fId() {return getString("f_id"); }
    inline QString fIP() {return getString("f_ip"); }
    inline QString fName() {return getString("f_name"); }
    inline QString fPort() {return getString("f_port");}
    inline QString fPassword() {return getString("f_password");}
};

#endif // CACHEFISCALMACHINE_H
