#ifndef FYEARLYFINANCIALREPORT_H
#define FYEARLYFINANCIALREPORT_H

#include "wfilterbase.h"

namespace Ui {
class FYearlyFinancialReport;
}

class FYearlyFinancialReport : public WFilterBase
{
    Q_OBJECT

public:
    explicit FYearlyFinancialReport(QWidget *parent = nullptr);
    ~FYearlyFinancialReport();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();
    virtual void apply(WReportGrid *rg);
    static void openReport();

private:
    Ui::FYearlyFinancialReport *ui;
};

#endif // FYEARLYFINANCIALREPORT_H
