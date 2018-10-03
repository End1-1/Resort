#ifndef LOGGING_H
#define LOGGING_H

#include <QElapsedTimer>

#define writelog(x) logging::writeLog(x)

#include <QString>

class logging
{
public:
    logging();
    static void writeLog(const QString &text);
    static void writeLog(const QString &text, QElapsedTimer &t);
};

extern bool logEnabled;

#endif // LOGGING_H
