#ifndef CACHEACTIVEROOM_H
#define CACHEACTIVEROOM_H

#include "cachebasestruct.h"

#define cid_active_room 21

class CacheActiveRoom : public CacheBaseStruct
{
public:
    CacheActiveRoom();
    QString fCode() { return getString("f_id"); }
    QString fName() { return getString("f_short"); }
    QString fRoomCode() {return getString("f_room"); }
    QString fRoomName() {return getString("f_short"); }
    QString fInvoice() {return getString("f_invoice"); }
    QString fGuestName() {return getString("f_guest"); }
};

#endif // CACHEACTIVEROOM_H
