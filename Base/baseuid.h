#ifndef BASEUID_H
#define BASEUID_H

#include <QString>

extern int _IDGENMODE_;

#define uuid(x) BaseUID::genID(x)

class BaseUID
{
public:
    BaseUID();
    static QString genID(const QString &prefix);
    static QString ID(const QString &vaucher);
    static QString INTID(const QString &prefix);
    static int fUserId;
    static QString fAirHost;
    static QString fAirDbName;
    static QString fAirUser;
    static QString fAirPass;
};

#endif // BASEUID_H
