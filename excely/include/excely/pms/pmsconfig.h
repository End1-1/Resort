#ifndef EXCELY_PMS_PMSCONFIG_H
#define EXCELY_PMS_PMSCONFIG_H

#include <QString>

namespace Excely {
namespace Pms {

struct Config {
    QString endpoint = QStringLiteral("https://pmsconnect.test.hopenapi.com/Api/PMSConnect.svc");
    QString hotelCode;
    QString username;
    QString password;
    QString protocolVersion = QStringLiteral("1.18");
    int pollIntervalSec = 300;
    int requestTimeoutMs = 60000;

    bool isValid(QString *errorText = nullptr) const;
    static Config fromIniFile(const QString &path, QString *errorText = nullptr);
};

} // namespace Pms
} // namespace Excely

#endif
