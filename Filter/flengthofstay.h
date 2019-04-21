#ifndef FLENGTHOFSTAY_H
#define FLENGTHOFSTAY_H

#include "wfilterbase.h"

namespace Ui {
class FLengthOfStay;
}

class FLengthOfStay : public WFilterBase
{
    Q_OBJECT

public:
    explicit FLengthOfStay(QWidget *parent = nullptr);
    ~FLengthOfStay();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FLengthOfStay *ui;

private slots:
    void openReservation();
    void openInvoice();
    void dblClick(const QList<QVariant> &r);
};

#endif // FLENGTHOFSTAY_H
