#ifndef MONTHNAMES_H
#define MONTHNAMES_H

#include <QString>
#include <QMap>

class DateUtils {
public:
    DateUtils();
    QString mn(int month) const;
private:
    static QMap<int, QString> __namesOfMonths;
};

extern DateUtils __dateUtils;

#endif // MONTHNAMES_H
