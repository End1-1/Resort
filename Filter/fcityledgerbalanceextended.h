#ifndef FCITYLEDGERBALANCEEXTENDED_H
#define FCITYLEDGERBALANCEEXTENDED_H

#include "wfilterbase.h"

namespace Ui {
class FCityLedgerBalanceExtended;
}

class FCityLedgerBalanceExtended : public WFilterBase
{
    Q_OBJECT

public:
    explicit FCityLedgerBalanceExtended(QWidget *parent = nullptr);
    ~FCityLedgerBalanceExtended();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);
    virtual QString reportTitle();
    virtual bool officialTitle();
    static void open();

private slots:
    void doubleClickOnRowSlot(const QList<QVariant> &values);
    void on_btnPrevDate_clicked();
    void on_btnNextDate_clicked();

private:
    Ui::FCityLedgerBalanceExtended *ui;
    QString fQuery;
};

#endif // FCITYLEDGERBALANCEEXTENDED_H
