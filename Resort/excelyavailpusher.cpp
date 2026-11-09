#include "excelyavailpusher.h"

#include "defines.h"
#include "doubledatabase.h"
#include "excely/pms/pmsconnectclient.h"
#include "excelyappconfig.h"

#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>
#include <QMutex>
#include <QMutexLocker>
#include <QObject>
#include <QPair>
#include <QSet>
#include <QSettings>
#include <QTimer>
#include <QtGlobal>

namespace {

QMutex g_mutex;

struct ClassInfo {
    int classId = 0;
    QString shortCode;
    int totalRooms = 0;
};

QString cacheGroupKey(const QString &invTypeCode,
                      const QString &ratePlanCode,
                      const QString &invBlockCode)
{
    return invTypeCode + QLatin1Char('|') + ratePlanCode + QLatin1Char('|') + invBlockCode;
}

QJsonObject loadCacheObject()
{
    QSettings s(QStringLiteral("SmartHotel"), QStringLiteral("SmartHotel"));
    s.beginGroup(QStringLiteral("excely"));
    const QByteArray raw = s.value(QStringLiteral("availLastUpload")).toByteArray();
    s.endGroup();
    if (raw.isEmpty()) {
        return {};
    }
    const QJsonDocument doc = QJsonDocument::fromJson(raw);
    return doc.isObject() ? doc.object() : QJsonObject{};
}

void saveCacheObject(const QJsonObject &jo)
{
    QSettings s(QStringLiteral("SmartHotel"), QStringLiteral("SmartHotel"));
    s.beginGroup(QStringLiteral("excely"));
    s.setValue(QStringLiteral("availLastUpload"),
               QJsonDocument(jo).toJson(QJsonDocument::Compact));
    s.endGroup();
    s.sync();
}

int cachedLimit(const QJsonObject &cache, const QString &groupKey, const QDate &day, bool *found)
{
    if (found) {
        *found = false;
    }
    if (!cache.contains(groupKey) || !cache.value(groupKey).isObject()) {
        return -1;
    }
    const QJsonObject days = cache.value(groupKey).toObject();
    const QString ds = day.toString(Qt::ISODate);
    if (!days.contains(ds)) {
        return -1;
    }
    if (found) {
        *found = true;
    }
    return days.value(ds).toInt(-1);
}

void setCachedLimit(QJsonObject *cache, const QString &groupKey, const QDate &day, int limit)
{
    QJsonObject days = cache->value(groupKey).toObject();
    days.insert(day.toString(Qt::ISODate), limit);
    cache->insert(groupKey, days);
}

/** Resolve roomTypeMap values to class id + room count. */
QMap<QString, ClassInfo> resolveMappedClasses(const QMap<QString, QString> &roomTypeMap,
                                              QStringList *warnings)
{
    QMap<QString, ClassInfo> out;
    DoubleDatabase dr;
    dr.exec(QStringLiteral(
        "select rc.f_id, rc.f_short, count(rm.f_id) "
        "from f_room_classes rc "
        "left join f_room rm on rm.f_class=rc.f_id "
        "group by rc.f_id, rc.f_short"));
    QMap<QString, ClassInfo> byShort;
    QMap<int, ClassInfo> byId;
    while (dr.nextRow()) {
        ClassInfo ci;
        ci.classId = dr.getInt(0);
        ci.shortCode = dr.getString(1);
        ci.totalRooms = dr.getInt(2);
        byShort.insert(ci.shortCode.toUpper(), ci);
        byId.insert(ci.classId, ci);
    }

    for (auto it = roomTypeMap.constBegin(); it != roomTypeMap.constEnd(); ++it) {
        const QString inv = it.key().trimmed();
        const QString local = it.value().trimmed();
        if (inv.isEmpty() || local.isEmpty()) {
            continue;
        }
        ClassInfo ci;
        bool okInt = false;
        const int id = local.toInt(&okInt);
        if (okInt && byId.contains(id)) {
            ci = byId.value(id);
        } else if (byShort.contains(local.toUpper())) {
            ci = byShort.value(local.toUpper());
        } else {
            if (warnings) {
                warnings->append(QObject::tr("roomTypeMap: no local category for %1 → %2")
                                     .arg(inv, local));
            }
            continue;
        }
        out.insert(inv, ci);
    }
    return out;
}

/**
 * Occupied rooms per class id per night for [start, end).
 * Counts assigned rooms with active reserve/check-in/OO/service/OI.
 */
QMap<int, QMap<QDate, int>> occupiedByClassNight(const QList<int> &classIds,
                                                 const QDate &start,
                                                 const QDate &end)
{
    QMap<int, QMap<QDate, int>> out;
    if (classIds.isEmpty() || !start.isValid() || !end.isValid() || end < start) {
        return out;
    }

    DoubleDatabase dr;
    QString inList;
    for (int i = 0; i < classIds.size(); ++i) {
        if (i) {
            inList += QLatin1Char(',');
        }
        inList += QString::number(classIds.at(i));
    }

    // Embed dates (no prepared binds) — Qt6 MySQL prepared SELECT can break QDate
    const QString sql = QStringLiteral(
        "select rm.f_class, r.f_startdate, r.f_enddate, r.f_room "
        "from f_reservation r "
        "inner join f_room rm on rm.f_id=r.f_room "
        "where r.f_state in (1,2,4,7,9) "
        "and r.f_room>0 "
        "and rm.f_class in (%1) "
        "and r.f_startdate < '%2' "
        "and r.f_enddate > '%3'")
                            .arg(inList,
                                 end.addDays(1).toString(Qt::ISODate),
                                 start.toString(Qt::ISODate));
    if (!dr.exec(sql)) {
        return out;
    }

    // Per class/night: unique rooms
    QMap<int, QMap<QDate, QSet<int>>> uniq;
    while (dr.nextRow()) {
        const int classId = dr.getInt(0);
        QDate rs = dr.getDate(1);
        QDate re = dr.getDate(2);
        if (!rs.isValid()) {
            rs = QDate::fromString(dr.getString(1).left(10), Qt::ISODate);
        }
        if (!re.isValid()) {
            re = QDate::fromString(dr.getString(2).left(10), Qt::ISODate);
        }
        const int roomId = dr.getInt(3);
        if (!rs.isValid() || !re.isValid() || roomId <= 0) {
            continue;
        }
        QDate d = qMax(rs, start);
        const QDate last = qMin(re.addDays(-1), end);
        for (; d <= last; d = d.addDays(1)) {
            uniq[classId][d].insert(roomId);
        }
    }
    for (auto cit = uniq.constBegin(); cit != uniq.constEnd(); ++cit) {
        for (auto dit = cit.value().constBegin(); dit != cit.value().constEnd(); ++dit) {
            out[cit.key()][dit.key()] = dit.value().size();
        }
    }
    return out;
}

QVector<Excely::Pms::AvailStatusMessage> consolidate(
    const QString &invTypeCode,
    const QString &ratePlanCode,
    const QString &invBlockCode,
    const QList<QPair<QDate, int>> &dayLimits)
{
    QVector<Excely::Pms::AvailStatusMessage> msgs;
    if (dayLimits.isEmpty()) {
        return msgs;
    }
    QDate segStart = dayLimits.first().first;
    QDate segEnd = segStart;
    int segLimit = dayLimits.first().second;

    auto flush = [&]() {
        Excely::Pms::AvailStatusMessage m;
        m.invTypeCode = invTypeCode;
        m.ratePlanCode = ratePlanCode;
        m.invBlockCode = invBlockCode;
        m.start = segStart;
        m.end = segEnd;
        m.sendBookingLimit = true;
        m.bookingLimit = segLimit;
        // Do not send Open/Close/MinLOS on computed sync — only BookingLimit
        msgs.append(m);
    };

    for (int i = 1; i < dayLimits.size(); ++i) {
        const QDate d = dayLimits.at(i).first;
        const int lim = dayLimits.at(i).second;
        if (lim == segLimit && d == segEnd.addDays(1)) {
            segEnd = d;
        } else {
            flush();
            segStart = d;
            segEnd = d;
            segLimit = lim;
        }
    }
    flush();
    return msgs;
}

class AutoPushScheduler : public QObject
{
public:
    static AutoPushScheduler *instance()
    {
        static AutoPushScheduler *s = new AutoPushScheduler(qApp);
        return s;
    }

    void schedule()
    {
        if (!m_timer) {
            m_timer = new QTimer(this);
            m_timer->setSingleShot(true);
            QObject::connect(m_timer, &QTimer::timeout, this, [this]() {
                const ExcelyAppConfig cfg = ExcelyAppConfig::load();
                if (!cfg.autoUploadAvailability) {
                    return;
                }
                const QDate start = QDate::currentDate();
                const QDate end = start.addDays(qMax(1, cfg.autoAvailHorizonDays) - 1);
                ExcelyAvailPusher::pushFromPms(start, end, false);
            });
        }
        m_timer->start(4000);
    }

private:
    explicit AutoPushScheduler(QObject *parent)
        : QObject(parent)
    {
    }
    QTimer *m_timer = nullptr;
};

} // namespace

QString ExcelyAvailPusher::Result::summary() const
{
    QStringList lines;
    lines << QObject::tr("PMS availability push: %1")
                 .arg(ok ? QObject::tr("OK") : QObject::tr("FAILED"));
    lines << QObject::tr("Changed date-points: %1 / %2").arg(datePointsChanged).arg(datePointsTotal);
    lines << QObject::tr("Messages sent: %1").arg(messagesSent);
    for (const QString &w : warnings) {
        lines << QObject::tr("Warning: %1").arg(w);
    }
    for (const QString &e : errors) {
        lines << QObject::tr("Error: %1").arg(e);
    }
    return lines.join(QLatin1Char('\n'));
}

ExcelyAvailPusher::Result ExcelyAvailPusher::pushFromPms(const QDate &start,
                                                          const QDate &end,
                                                          bool forceFull)
{
    Result result;
    QMutexLocker lock(&g_mutex);

    if (!start.isValid() || !end.isValid() || end < start) {
        result.errors.append(QObject::tr("Invalid date range"));
        return result;
    }

    ExcelyAppConfig cfg = ExcelyAppConfig::load();
    QString credHint;
    if (!cfg.hasCredentials(&credHint)) {
        result.errors.append(credHint);
        return result;
    }
    if (cfg.roomTypeMap.isEmpty()) {
        result.errors.append(QObject::tr(
            "Room type map is empty. Set Excely room type map in Global config."));
        return result;
    }

    const QMap<QString, ClassInfo> mapped = resolveMappedClasses(cfg.roomTypeMap, &result.warnings);
    if (mapped.isEmpty()) {
        result.errors.append(QObject::tr("No valid room type mappings resolved."));
        return result;
    }

    QList<int> classIds;
    for (const ClassInfo &ci : mapped) {
        if (!classIds.contains(ci.classId)) {
            classIds.append(ci.classId);
        }
    }
    const QMap<int, QMap<QDate, int>> occupied = occupiedByClassNight(classIds, start, end);

    QJsonObject cache = loadCacheObject();
    const QString ratePlan; // computed sync: room-type level (optional inv block)
    const QString invBlock = cfg.availSyncInvBlock.trimmed();

    QVector<Excely::Pms::AvailStatusMessage> toSend;
    QJsonObject cacheUpdates = cache;

    for (auto it = mapped.constBegin(); it != mapped.constEnd(); ++it) {
        const QString invType = it.key();
        const ClassInfo &ci = it.value();
        const QString groupKey = cacheGroupKey(invType, ratePlan, invBlock);
        QList<QPair<QDate, int>> changedDays;

        for (QDate d = start; d <= end; d = d.addDays(1)) {
            const int occ = occupied.value(ci.classId).value(d, 0);
            const int limit = qMax(0, ci.totalRooms - occ);
            ++result.datePointsTotal;

            bool found = false;
            const int prev = cachedLimit(cache, groupKey, d, &found);
            if (forceFull || !found || prev != limit) {
                changedDays.append(qMakePair(d, limit));
                ++result.datePointsChanged;
                setCachedLimit(&cacheUpdates, groupKey, d, limit);
            }
        }

        toSend += consolidate(invType, ratePlan, invBlock, changedDays);
    }

    if (toSend.isEmpty()) {
        result.ok = true;
        result.warnings.append(QObject::tr("No availability changes to upload."));
        return result;
    }

    Excely::Pms::PmsConnectClient client(cfg.pms);
    // Chunk to stay within practical request size
    const int chunkSize = 80;
    for (int i = 0; i < toSend.size(); i += chunkSize) {
        const QVector<Excely::Pms::AvailStatusMessage> chunk = toSend.mid(i, chunkSize);
        QVector<Excely::Channel::PmsError> errors;
        if (!client.hotelAvailNotif(chunk, &errors)) {
            for (const Excely::Channel::PmsError &e : errors) {
                result.errors.append(QStringLiteral("%1: %2").arg(e.code).arg(e.text));
            }
            if (result.errors.isEmpty()) {
                result.errors.append(QObject::tr("HotelAvailNotif failed"));
            }
            return result;
        }
        // Soft warnings (e.g. WARN 150)
        for (const Excely::Channel::PmsError &e : errors) {
            result.warnings.append(QStringLiteral("%1: %2").arg(e.code).arg(e.text));
        }
        result.messagesSent += chunk.size();
    }

    saveCacheObject(cacheUpdates);
    result.ok = true;
    return result;
}

void ExcelyAvailPusher::requestAutoPush()
{
    const ExcelyAppConfig cfg = ExcelyAppConfig::load();
    if (!cfg.autoUploadAvailability) {
        return;
    }
    QString hint;
    if (!cfg.hasCredentials(&hint) || cfg.roomTypeMap.isEmpty()) {
        return;
    }
    AutoPushScheduler::instance()->schedule();
}

void ExcelyAvailPusher::rememberUploaded(const QVector<Excely::Pms::AvailStatusMessage> &messages)
{
    QMutexLocker lock(&g_mutex);
    QJsonObject cache = loadCacheObject();
    for (const Excely::Pms::AvailStatusMessage &m : messages) {
        if (!m.sendBookingLimit || !m.start.isValid() || !m.end.isValid() || m.end < m.start) {
            continue;
        }
        const QString groupKey = cacheGroupKey(m.invTypeCode, m.ratePlanCode, m.invBlockCode);
        for (QDate d = m.start; d <= m.end; d = d.addDays(1)) {
            setCachedLimit(&cache, groupKey, d, m.bookingLimit);
        }
    }
    saveCacheObject(cache);
}
