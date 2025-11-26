#include "base.h"
#include "trackcontrol.h"

Preferences Base::fPreferences;
QString Base::fDbName;
int Base::WORKING_SESSION_ID;
Base::Base()
{
}

Base::~Base()
{
}

void Base::selector(int selectorNumber, const QVariant &value)
{
    Q_UNUSED(selectorNumber)
    Q_UNUSED(value)
}

void Base::callback(int sel, const QString &code)
{
    Q_UNUSED(sel)
    Q_UNUSED(code)
}
