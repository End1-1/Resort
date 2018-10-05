#include "cachereservation.h"
#include "utils.h"
#include "cacheone.h"
#include <QElapsedTimer>

CacheReservation::CacheReservation() :
    CacheBaseStruct()
{
    fCacheId = cid_reservation;
    fLoadQuery = "select r.f_id, r.f_state, r.f_reserveState, r.f_room, rm.f_short, r.f_cardex, r.f_startDate, r.f_endDate, "
                  "concat(g.f_firstName, ' ', g.f_lastName) as f_guest_name, c.f_name as f_cardex_name, r.f_invoice,  "
                  "rs.f_" + def_lang + " as f_reserveStateName, a.amount, coalesce(cc.credit, 0), coalesce(cd.debet, 0), "
                  "r.f_remarks, r.f_arrangement, r.f_author, r.f_group, "
                  "r.f_created, r.f_createTime "
                  "from f_reservation r "
                  "left join f_room rm on rm.f_id=r.f_room "
                  "left join f_guests g on r.f_guest=g.f_id "
                  "inner join f_reservation_status rs on rs.f_id=r.f_reserveState "
                  "left join f_cardex c on c.f_cardex=r.f_cardex "
                  "left join (select f_inv, sum(f_amountAmd) as amount from m_register where f_source='AV' and f_canceled=0 and f_finance=1) a on  a.f_inv=r.f_invoice "
                  "left join (select f_inv, sum(f_amountAmd) as credit from m_register where f_sign=1 and f_canceled=0 and f_finance=1 group by 1) cc on cc.f_inv=r.f_invoice "
                  "left join (select f_inv, sum(f_amountAmd) as debet from m_register where f_sign=-1 and f_canceled=0 and f_finance=1 group by 1) cd on cd.f_inv=r.f_invoice "
                  "where (r.f_state in (1,2,7) or (r.f_state in (4, 9) and r.f_endDate>='"
                   + __preferences.getLocalDate(def_working_day).toString(def_mysql_date_format) + "')) :cond  ";
    fReplaceUpdateQuery = ":cond";
    fUpdateQuery = " and r.f_id=:f_id";
    
}

bool CacheReservation::hasNext(CacheReservation &c, bool fill)
{
    CacheReservation *ci = (CacheReservation*)fInstance->fStruct;
    QString id = fData.at(pos_id).toString();
    int room = fData.at(pos_room).toInt();
    QDate endDate = fData.at(pos_dateend).toDate();
    if (fill) {
        c.fValid = false;
        if (c.fData.isEmpty()) {
            c.fData = fData;
        }
    }
    if (!ci->fRooms.contains(room)) {
        return false;
    }
    QStringList &ids = ci->fRooms[room];
    foreach (QString s, ids) {
        if (id == s) {
            continue;
        }
        if (endDate == fInstance->fRows[s].at(pos_datestart).toDate()) {
            if (fill) {
                c.fData = fInstance->fRows[s];
                c.fValid = true;
            }
            return true;
        }
    }
    return false;
}

bool CacheReservation::hasNext()
{
    CacheReservation c;
    return hasNext(c, false);
}

bool CacheReservation::hasPrev(CacheReservation &c, bool fill)
{
    CacheReservation *ci = (CacheReservation*)fInstance->fStruct;
    QString id = fData.at(pos_id).toString();
    int room = fData.at(pos_room).toInt();
    QDate startDate = fData.at(pos_datestart).toDate();
    if (fill) {
        c.fValid = false;
        if (c.fData.isEmpty()) {
            c.fData = fData;
        }
    }
    if (!ci->fRooms.contains(room)) {
        return false;
    }
    QStringList &ids = ci->fRooms[room];
    foreach (QString s, ids) {
        if (id == s) {
            continue;
        }
        if (startDate == fInstance->fRows[s].at(pos_dateend).toDate()) {
            if (fill) {
                c.fData = fInstance->fRows[s];
                c.fValid = true;
            }
            return true;
        }
    }
    return false;
}

bool CacheReservation::hasPrev()
{
    CacheReservation c;
    return hasPrev(c, false);
}

void CacheReservation::check(const QDate &start, const QDate &end, int room,
                             QMap<QString, CacheReservation> &out,
                             bool &startOk, bool &endOk, const QString &reserveId)
{
    CacheInstance *ci = cache(cid_reservation);
    CacheReservation cr;
    cr.fInstance = ci;
    QMap<QString, QList<QVariant> >::iterator it = ci->fRows.begin();
    while (it != ci->fRows.end()) {
        cr.fData = it.value();
        if (!cr.fValid) {
            it++;
            continue;
        }
        if (cr.fRoom().toInt() != room) {
            it++;
            continue;
        }
        if (cr.fId() == reserveId) {
            it++;
            continue;
        }
        if (cr.fState() == RESERVE_OUTOFINVENTORY || cr.fState() == RESERVE_OUTOFROOM) {
            if (start == cr.fDateEnd() || end == cr.fDateStart()) {
                out.insert(cr.fId(), cr);
                startOk = false;
                endOk = false;
                it++;
                continue;
            }
        }
        if (start == end) {
            if (cr.fDateStart() == cr.fDateEnd()) {
                if (cr.fDateStart() == start) {
                    startOk = false;
                    endOk = false;
                    it++;
                    continue;
                }
            }
            if (start == cr.fDateEnd()) {

            }
        }
        if (start <= cr.fDateStart() && end >= cr.fDateEnd() && cr.fDateStart() != cr.fDateEnd()) {
            out.insert(cr.fId(), cr);
            startOk = false;
            endOk = false;
            it++;
            continue;
        }
        if (start > cr.fDateStart() && end < cr.fDateEnd()) {
            out.insert(cr.fId(), cr);
            startOk = false;
            endOk = false;
            it++;
            continue;
        }
        if (start <= cr.fDateStart()) {
            if (end > cr.fDateStart()) {
                if (cr.fDateStart() != cr.fDateEnd()) {
                    out.insert(cr.fId(), cr);
                    endOk = false;
                    it++;
                    continue;
                }
            }
        }
        if (end > cr.fDateEnd()) {
            if (start < cr.fDateEnd()) {
                out.insert(cr.fId(), cr);
                startOk = false;
                it++;
                continue;
            }
        }
        it++;
    }
}

void CacheReservation::exludeList(const QDate &start, const QDate &end, QSet<int> &excludeRooms)
{
    excludeRooms.clear();
    CacheInstance *ci = cache(cid_reservation);
    CacheReservation cr;
    cr.fInstance = ci;
    QMap<QString, QList<QVariant> >::iterator it = ci->fRows.begin();
    while (it != ci->fRows.end()) {
        cr.fData = it.value();
//        if (!cr.fValid) {
//            continue;
//        }
        if (start <= cr.fDateStart() && end >= cr.fDateEnd()) {
            excludeRooms.insert(cr.fRoom().toInt());
            it++;
            continue;
        }
        if (start >= cr.fDateStart() && end <= cr.fDateEnd()) {
            excludeRooms.insert(cr.fRoom().toInt());
            it++;
            continue;
        }
        if (start <= cr.fDateStart()) {
            if (end > cr.fDateStart()) {
                excludeRooms.insert(cr.fRoom().toInt());
                it++;
                continue;
            }
        }
        if (end > cr.fDateEnd()) {
            if (start < cr.fDateEnd()) {
                excludeRooms.insert(cr.fRoom().toInt());
                it++;
                continue;
            }
        }
        it++;
    }
}

void CacheReservation::postProcess(CacheInstance *ci)
{
    fRooms.clear();
    fOldRoomList.clear();
    QMap<QString, QList<QVariant> >::const_iterator it = ci->fRows.begin();
    while (it != ci->fRows.end()) {
        fRooms[it.value().at(pos_room).toInt()].append(it.key());
        fOldRoomList[it.key()] = it.value().at(pos_room).toInt();
        it++;
    }
}

void CacheReservation::postUpdate(CacheInstance *ci, const QString &id)
{
    CacheBaseStruct::postUpdate(ci, id);
    Q_UNUSED(ci);
    Q_UNUSED(id);
    postProcess(ci);
}
