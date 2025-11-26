#ifndef FCITYLEDGERDETAILEDBALANCE_H
#define FCITYLEDGERDETAILEDBALANCE_H

#include "wfilterbase.h"

namespace Ui
{
class FCityLedgerDetailedBalance;
}

class FCityLedgerDetailedBalance : public WFilterBase
{
    Q_OBJECT

public:
    explicit FCityLedgerDetailedBalance(QWidget *parent = nullptr);
    ~FCityLedgerDetailedBalance();
    virtual void apply(WReportGrid *rg);
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual bool officialTitle();
    virtual bool handlePrint();
    void setData(const QDate &date1, const QDate &date2, const QString &cl);
    static void open();

private:
    Ui::FCityLedgerDetailedBalance *ui;
    void applyNorm(WReportGrid *rg);

private slots:
    void openInvoice();
    void on_btnNextDate_clicked();
    void on_btnPrevDate_clicked();
    void on_btnChangeCityLedger_clicked();
};

#endif // FCITYLEDGERDETAILEDBALANCE_H
