#ifndef EXCELYAVAILPUSHER_H
#define EXCELYAVAILPUSHER_H

#include "excely/pms/models.h"

#include <QDate>
#include <QString>
#include <QStringList>
#include <QVector>

/**
 * Computes room availability from PMS occupancy and uploads HotelAvailNotif.
 * - Delta mode: only dates whose BookingLimit changed since the last successful upload.
 * - Auto mode: call requestAutoPush() after occupancy changes; runs only if
 *   ExcelyAppConfig::autoUploadAvailability is enabled (off by default).
 */
class ExcelyAvailPusher
{
public:
    struct Result {
        bool ok = false;
        int messagesSent = 0;
        int datePointsChanged = 0;
        int datePointsTotal = 0;
        QStringList errors;
        QStringList warnings;
        QString summary() const;
    };

    /** Push computed PMS availability for [start, end]. forceFull ignores delta cache. */
    static Result pushFromPms(const QDate &start, const QDate &end, bool forceFull);

    /**
     * Schedule a debounced auto push (today .. today+horizon) when the option is on.
     * No-op if autoUploadAvailability is false or credentials/map missing.
     */
    static void requestAutoPush();

    /** Remember values after a successful manual AvailNotif (keeps delta cache consistent). */
    static void rememberUploaded(const QVector<Excely::Pms::AvailStatusMessage> &messages);

private:
    ExcelyAvailPusher() = delete;
};

#endif // EXCELYAVAILPUSHER_H
