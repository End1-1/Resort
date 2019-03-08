#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QString>

#define SERVER_DEFAULT_PORT 1250

class AppConfig
{
public:
    AppConfig();
    static QString fServerAddress;
    static int fServerPort;
    static QString fAppSession;
};

#endif // APPCONFIG_H
