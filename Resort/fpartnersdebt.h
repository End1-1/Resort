#ifndef FPARTNERSDEBT_H
#define FPARTNERSDEBT_H

#include "wfilterbase.h"

namespace Ui {
class FPartnersDebt;
}

class FPartnersDebt : public WFilterBase
{
    Q_OBJECT

public:
    explicit FPartnersDebt(QWidget *parent = nullptr);
    ~FPartnersDebt();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FPartnersDebt *ui;

private slots:
    void btnNew();
};

#endif // FPARTNERSDEBT_H
