#ifndef CACHEACTIVEROOM_H
#define CACHEACTIVEROOM_H

#include "cachebasestruct.h"

static const quint32 cid_active_room = 21;

class CacheActiveRoom : public CacheBaseStruct
{
public:
    CacheActiveRoom();
    inline QString fCode() { return getString("f_id"); }
    inline QString fName() { return getString("f_short"); }
    inline QString fRoomCode() {return getString("f_room"); }
    inline QString fRoomName() {return getString("f_short"); }
    inline QString fInvoice() {return getString("f_invoice"); }
    inline QString fGuestName() {return getString("f_guest"); }
    inline QDate fEntry() {return getDate("f_startdate");}
    inline QDate fDeparture() {return getDate("f_enddate");}
};

#endif // CACHEACTIVEROOM_H
