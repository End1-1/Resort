#ifndef WCITYLEDGER_H
#define WCITYLEDGER_H

#include "basewidget.h"

namespace Ui {
class WCityLedger;
}

class DBMRegister;

class WCityLedger : public BaseWidget
{
    Q_OBJECT

public:
    explicit WCityLedger(QWidget *parent = nullptr);
    ~WCityLedger();
    void callback(int sel, const QString &code);
    void clear();
    void setDBMRegister(DBMRegister *r);
    int cityLedger();
    QString cityLedgerName() const;
    void setCL(int code);
    void clearSelector();
    void initSelector();
    void setBalance();

private:
    Ui::WCityLedger *ui;

};

#endif // WCITYLEDGER_H
