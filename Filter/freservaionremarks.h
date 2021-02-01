#ifndef FRESERVAIONREMARKS_H
#define FRESERVAIONREMARKS_H

#include "wfilterbase.h"

namespace Ui {
class FReservaionRemarks;
}

class FReservaionRemarks : public WFilterBase
{
    Q_OBJECT

public:
    explicit FReservaionRemarks(QWidget *parent = nullptr);
    ~FReservaionRemarks();
    virtual void apply(WReportGrid *rg);
    void apply2(WReportGrid *rg);
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();
    static void openReport();

private slots:
    void on_rbReserve_clicked();
    void on_rbCheckin_clicked();

    void on_rbCheckout_clicked();

private:
    Ui::FReservaionRemarks *ui;
};

#endif // FRESERVAIONREMARKS_H
