#ifndef FINHOUSEDETAILBALANCE_H
#define FINHOUSEDETAILBALANCE_H

#include "wfilterbase.h"

namespace Ui {
class FInhouseDetailBalance;
}

class FInhouseDetailBalance : public WFilterBase
{
    Q_OBJECT

public:
    explicit FInhouseDetailBalance(QWidget *parent = nullptr);
    ~FInhouseDetailBalance();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FInhouseDetailBalance *ui;

private slots:
    void refresh();
};

#endif // FINHOUSEDETAILBALANCE_H
