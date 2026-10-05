#include "excelyappconfig.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QObject>
#include <QSettings>

ExcelyAppConfig ExcelyAppConfig::load()
{
    ExcelyAppConfig cfg;
    QSettings s(QStringLiteral("SmartHotel"), QStringLiteral("SmartHotel"));
    s.beginGroup(QStringLiteral("excely"));

    cfg.pms.endpoint = s.value(QStringLiteral("endpoint"),
                               QStringLiteral("https://pmsconnect.test.hopenapi.com/Api/PMSConnect.svc"))
                           .toString()
                           .trimmed();
    cfg.pms.username = s.value(QStringLiteral("username")).toString().trimmed();
    cfg.pms.password = s.value(QStringLiteral("password")).toString();
    cfg.pms.hotelCode = s.value(QStringLiteral("hotelCode")).toString().trimmed();
    cfg.pms.protocolVersion = s.value(QStringLiteral("protocolVersion"),
                                      QStringLiteral("1.18"))
                                  .toString()
                                  .trimmed();
    if (cfg.pms.protocolVersion.isEmpty()) {
        cfg.pms.protocolVersion = QStringLiteral("1.18");
    }

    cfg.setRoomTypeMapJson(QString::fromUtf8(s.value(QStringLiteral("roomTypeMap")).toByteArray()));

    s.endGroup();
    return cfg;
}

bool ExcelyAppConfig::save(QString *errorText) const
{
    const QString mapJson = roomTypeMapJson();
    if (!mapJson.isEmpty()) {
        QJsonParseError pe;
        const QJsonDocument doc = QJsonDocument::fromJson(mapJson.toUtf8(), &pe);
        if (pe.error != QJsonParseError::NoError || !doc.isObject()) {
            if (errorText) {
                *errorText = QObject::tr("Excely roomTypeMap must be a JSON object: %1")
                                 .arg(pe.errorString());
            }
            return false;
        }
    }

    QSettings s(QStringLiteral("SmartHotel"), QStringLiteral("SmartHotel"));
    s.beginGroup(QStringLiteral("excely"));
    s.setValue(QStringLiteral("endpoint"), pms.endpoint.trimmed());
    s.setValue(QStringLiteral("username"), pms.username.trimmed());
    s.setValue(QStringLiteral("password"), pms.password);
    s.setValue(QStringLiteral("hotelCode"), pms.hotelCode.trimmed());
    s.setValue(QStringLiteral("protocolVersion"),
               pms.protocolVersion.trimmed().isEmpty()
                   ? QStringLiteral("1.18")
                   : pms.protocolVersion.trimmed());
    s.setValue(QStringLiteral("roomTypeMap"), mapJson.toUtf8());
    s.endGroup();
    s.sync();
    return true;
}

QString ExcelyAppConfig::roomTypeMapJson() const
{
    if (roomTypeMap.isEmpty()) {
        return QString();
    }
    QJsonObject jo;
    for (auto it = roomTypeMap.constBegin(); it != roomTypeMap.constEnd(); ++it) {
        jo.insert(it.key(), it.value());
    }
    return QString::fromUtf8(QJsonDocument(jo).toJson(QJsonDocument::Compact));
}

void ExcelyAppConfig::setRoomTypeMapJson(const QString &json)
{
    roomTypeMap.clear();
    const QByteArray raw = json.trimmed().toUtf8();
    if (raw.isEmpty()) {
        return;
    }
    const QJsonDocument doc = QJsonDocument::fromJson(raw);
    if (!doc.isObject()) {
        return;
    }
    const QJsonObject jo = doc.object();
    for (auto it = jo.begin(); it != jo.end(); ++it) {
        const QString v = it.value().toVariant().toString().trimmed();
        if (!it.key().isEmpty() && !v.isEmpty()) {
            roomTypeMap.insert(it.key().trimmed(), v);
        }
    }
}

bool ExcelyAppConfig::hasCredentials(QString *hint) const
{
    if (pms.hotelCode.isEmpty() || pms.username.isEmpty() || pms.password.isEmpty()) {
        if (hint) {
            *hint = QObject::tr(
                "Excely credentials are not configured.\n"
                "Open Global config → Application → Excely and set:\n"
                "  hotel code, username, password\n"
                "Optional: endpoint, protocol version, room type map.");
        }
        return false;
    }
    if (pms.endpoint.isEmpty()) {
        if (hint) {
            *hint = QObject::tr("Excely endpoint is empty.");
        }
        return false;
    }
    return true;
}
