#ifndef CACHEROOM_H
#define CACHEROOM_H

#include "cachebasestruct.h"

static const int cid_room = 33;


class CacheRoom : public CacheBaseStruct
{
public:
    CacheRoom();
    inline QString fCode() {return getString("f_id"); }
    inline QString fName() {return getString("f_short"); }
    inline int fState() { return getInt("f_state"); }
    inline int fCategoryId() { return getInt("f_class"); }
    inline QString fCategoryShort() {return getString("f_cshort"); }
    inline QString fCategory() { return getString("f_description"); }
    inline QString fRoomDescription() { return getString("room_description"); }
    inline QString fBed() {return getString("f_bed"); }
    inline QString fView() {return getString("f_view"); }
    inline int fFloor() { return getInt("f_floor"); }
    inline int fSmoke() {return getInt("f_smoke"); }
    inline QString fPrice() {return getString("f_rate"); }
    inline int fBuilding() {return getInt("f_building"); }
    inline QString fStateName() {return getString("f_statename");}
    inline bool fDoNotDisturbe(){return getInt("f_donotdisturbe") > 0;}
};

bool CI_Romm_compare(QString &left, QString &right);

#endif // CACHEROOM_H
