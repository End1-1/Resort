#include "excely/pms/pmsconfig.h"

#include <QSettings>

namespace Excely {
namespace Pms {

bool Config::isValid(QString *errorText) const
{
    if (endpoint.trimmed().isEmpty()) {
        if (errorText) *errorText = QStringLiteral("endpoint is empty");
        return false;
    }
    if (hotelCode.trimmed().isEmpty()) {
        if (errorText) *errorText = QStringLiteral("hotelCode is empty");
        return false;
    }
    if (username.trimmed().isEmpty() || password.isEmpty()) {
        if (errorText) *errorText = QStringLiteral("username/password required");
        return false;
    }
    return true;
}

Config Config::fromIniFile(const QString &path, QString *errorText)
{
    QSettings s(path, QSettings::IniFormat);
    Config c;
    c.endpoint = s.value(QStringLiteral("endpoint"), c.endpoint).toString().trimmed();
    c.hotelCode = s.value(QStringLiteral("hotelCode")).toString().trimmed();
    c.username = s.value(QStringLiteral("username")).toString().trimmed();
    c.password = s.value(QStringLiteral("password")).toString();
    c.protocolVersion = s.value(QStringLiteral("protocolVersion"), c.protocolVersion).toString().trimmed();
    c.pollIntervalSec = s.value(QStringLiteral("pollIntervalSec"), c.pollIntervalSec).toInt();
    c.requestTimeoutMs = s.value(QStringLiteral("requestTimeoutMs"), c.requestTimeoutMs).toInt();
    if (c.pollIntervalSec < 60) {
        // Protocol: max 30 ReadRQ/hour → min ~120s; keep soft floor at 60
        c.pollIntervalSec = 60;
    }
    if (!c.isValid(errorText)) {
        return Config{};
    }
    return c;
}

} // namespace Pms
} // namespace Excely
