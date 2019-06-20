#include "monthnames.h"

QMap<int, QString> DateUtils::__namesOfMonths;
DateUtils __dateUtils;

DateUtils::DateUtils()
{
    if (__namesOfMonths.isEmpty()) {
        __namesOfMonths[0] = "Undefined";
        __namesOfMonths[1] = "January";
        __namesOfMonths[2] = "February";
        __namesOfMonths[3] = "March";
        __namesOfMonths[4] = "April";
        __namesOfMonths[5] = "May";
        __namesOfMonths[6] = "June";
        __namesOfMonths[7] = "Jule";
        __namesOfMonths[8] = "August";
        __namesOfMonths[9] = "September";
        __namesOfMonths[10] = "October";
        __namesOfMonths[11] = "November";
        __namesOfMonths[12] = "December";
    }
}

QString DateUtils::mn(int month) const
{
    return __namesOfMonths[month];
}
