#ifndef FCITYTRAYLEDGER2_H
#define FCITYTRAYLEDGER2_H

#include "wfilterbase.h"

namespace Ui {
class FCityTrayLedger2;
}

class FCityTrayLedger2 : public WFilterBase
{
    Q_OBJECT

public:
    explicit FCityTrayLedger2(QWidget *parent = nullptr);
    ~FCityTrayLedger2();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FCityTrayLedger2 *ui;
};

#endif // FCITYTRAYLEDGER2_H
