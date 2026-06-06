#include "stringutils.h"
#include <QRegularExpression>

static const QLocale locale = QLocale(QLocale::English, QLocale::UnitedStates);
static const QString DecimalPoint = locale.decimalPoint();
static const QRegularExpression reZero = QRegularExpression("(?!\\d[\\" + DecimalPoint +"][1-9]+)0+$");
static const QRegularExpression rDP("[\\" + DecimalPoint + "]$");

const QLocale &appNumberLocale()
{
    return locale;
}

QString float_str(double value, int f)
{
    f = 2;
    return locale.toString(value, 'f', f).remove(reZero).remove(rDP);
}

double str_float(const QString &text) {
    return locale.toDouble(text);
}
