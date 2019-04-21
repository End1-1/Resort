#ifndef FRESERVATIONSCOMMON_H
#define FRESERVATIONSCOMMON_H

#include "wfilterbase.h"

namespace Ui {
class FReservationsCommon;
}

class WReportGrid;

class FReservationsCommon : public WFilterBase
{
    Q_OBJECT

public:
    explicit FReservationsCommon(QWidget *parent = nullptr);
    ~FReservationsCommon();
    virtual void apply(WReportGrid *rg);
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();

private:
    Ui::FReservationsCommon *ui;

private slots:
    void openInvoice();
};

#endif // FRESERVATIONSCOMMON_H
