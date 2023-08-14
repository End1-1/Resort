#ifndef CACHERESERVATION_H
#define CACHERESERVATION_H

#include "cachebasestruct.h"
#include "utils.h"
#include <QDate>

static const int cid_reservation = 34;

#define pos_id 0
#define pos_room 3
#define pos_datestart 6
#define pos_dateend 7
#define pos_state 1
#define pos_status 2
#define pos_cardex 5

class CacheReservation : public CacheBaseStruct
{
public:
    CacheReservation() ;
    bool hasNext(CacheReservation &c, bool fill = true);
    bool hasNext();
    bool hasPrev(CacheReservation &c, bool fill = true);
    bool hasPrev();
    void check(const QDate &start, const QDate &end, int room, QMap<QString, CacheReservation> &out, bool &startOk, bool &endOk, const QString &reserveId);
    void exludeList(const QDate &start, const QDate &end, QSet<int> &excludeRooms);

    inline QString fId() { return getString(pos_id); }
    inline int fState() {return getInt("f_state"); }
    inline int fArrangement() { return getInt("f_arrangement"); }
    inline int fGroup() { return getInt("f_group"); }
    inline QString fName() {return getString("f_id"); }
    inline QString fRoom() {return getString(pos_room); }
    inline QString fRoomShort() { return getString("f_short"); }
    inline QString fCardex() {return getString("f_cardex"); }
    inline QString fDateCreate() {return getString("f_created"); }
    inline QDate fDateStart() {return getDate(pos_datestart); }
    inline QDate fDateEnd() {return getDate(pos_dateend); }
    inline QString fGuest() {return getString("f_guest_name"); }
    inline QString fCardexName() {return getString("f_cardex_name"); }
    inline QString fRemarks() {return getString("f_remarks"); }
    inline int fAuthor() {return getInt("f_author"); }
    inline QString fInvoice() {return getString("f_invoice"); }
    inline int fStatus() {return getInt("f_reserveState"); }
    inline QString fStatusName() {return getString("f_reserveStateName"); }
    inline QString fAdvance() {return getString("amount"); }
    inline QString fCredit() {return getString("credit"); }
    inline QString fDebet() {return getString("debet"); }
    inline QString fBalance() {return float_str(getDouble("credit") - getDouble("debet"), 2); }
    inline bool fDoNotDisturbe() {return getInt("f_donotdisturbe") > 0;}
    inline int fChmStatus() {return getInt("f_chmstatus");}

    virtual void postProcess(CacheInstance *ci);
    virtual void postUpdate(CacheInstance *ci, const QString &id);
private:
    QMap<int, QStringList> fRooms;
    QMap<QString, int> fOldRoomList;
};

#endif // CACHERESERVATION_H
