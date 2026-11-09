#ifndef EXCELYAPPCONFIG_H
#define EXCELYAPPCONFIG_H

#include "excely/pms/pmsconfig.h"

#include <QMap>
#include <QString>

/**
 * Resort-side Excely settings from QSettings("SmartHotel","SmartHotel") group excely/.
 *
 * Keys:
 *   endpoint, username, password, hotelCode, protocolVersion
 *   roomTypeMap  — JSON object { "<CM room type code>": "<f_room_classes.f_short or f_id>" }
 *   chartEnabled — bool, default false (room-chart button and auto-pull)
 *   autoUploadAvailability — bool, default false (manual is primary)
 *   autoAvailHorizonDays — int, default 365
 *   availSyncInvBlock — optional InvBlockCode for computed PMS→Exely availability push
 *   availLastUpload — JSON cache of last successfully uploaded BookingLimit (managed by pusher)
 *
 * Seed test values only via QSettings / README — never hardcode secrets here.
 */
struct ExcelyAppConfig {
    Excely::Pms::Config pms;
    QMap<QString, QString> roomTypeMap;
    bool chartEnabled = false;
    bool autoUploadAvailability = false;
    int autoAvailHorizonDays = 365;
    QString availSyncInvBlock;

    static ExcelyAppConfig load();
    bool save(QString *errorText = nullptr) const;
    bool hasCredentials(QString *hint = nullptr) const;

    /** Serialize roomTypeMap as compact JSON object string. */
    QString roomTypeMapJson() const;
    void setRoomTypeMapJson(const QString &json);
};

#endif // EXCELYAPPCONFIG_H
