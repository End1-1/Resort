#ifndef FMONTHLYOCCPERC_H
#define FMONTHLYOCCPERC_H

#include "wfilterbase.h"

namespace Ui {
class FMonthlyOccPerc;
}

class FMonthlyOccPerc : public WFilterBase
{
    Q_OBJECT

public:
    explicit FMonthlyOccPerc(QWidget *parent = nullptr);
    ~FMonthlyOccPerc();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FMonthlyOccPerc *ui;
};

#endif // FMONTHLYOCCPERC_H
