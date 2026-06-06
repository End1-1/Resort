#ifndef STRINGUTILS_H
#define STRINGUTILS_H
#include <QLocale>
#include <QString>

#define where_id(id) QString("where f_id=%1").arg(id)
#define where_field(field, value) QString("where %1=%2").arg(field).arg(value)
#define ap(x) QString("'%1'").arg(x)
const QLocale &appNumberLocale();
QString float_str(double value, int f = 2);
double str_float(const QString &text);

#endif // STRINGUTILS_H
