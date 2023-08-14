#ifndef LOGGING_H
#define LOGGING_H

#include <QElapsedTimer>

#define writelog(x) logging::writeLog(x)

#include <QString>

class logging
{
public:
    logging();
    static void justLog(const QString &text);
    static void writeLog(const QString &text);
    static void writeLog(const QString &text, QElapsedTimer &t);
    static void writeTravelLineLog(const QString &text, const QString &title);
};

extern bool logEnabled;

#endif // LOGGING_H
