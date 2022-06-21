#ifndef FTAXREPORT_H
#define FTAXREPORT_H

#include "wfilterbase.h"

namespace Ui {
class FTaxReport;
}

class FTaxReport : public WFilterBase
{
    Q_OBJECT

public:
    explicit FTaxReport(QWidget *parent = nullptr);
    ~FTaxReport();
    virtual void apply(WReportGrid *rg);
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();

private slots:
    void on_chCanceled_clicked();

private:
    Ui::FTaxReport *ui;
};

#endif // FTAXREPORT_H
