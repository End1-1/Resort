#ifndef BASE_H
#define BASE_H

#include "defines.h"
#include "preferences.h"
#include "utils.h"
#include "eqlineedit.h"
#include "eqdateedit.h"
#include "baseuid.h"
#include "doubledatabase.h"
#include <QDate>
#include <QDebug>
#include <QDateTime>

class Base
{
public:
    Base();
    virtual ~Base();
    static QString fDbName;
    static Preferences fPreferences;
    static int WORKING_SESSION_ID;

    virtual void selector(int selectorNumber, const QVariant &value);
    virtual void callback(int sel, const QString &code);
protected:

};

#endif // BASE_H
