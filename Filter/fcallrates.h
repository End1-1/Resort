#ifndef FCALLRATES_H
#define FCALLRATES_H

#include "wfilterbase.h"

namespace Ui {
class FCallRates;
}

class FCallRates : public WFilterBase
{
    Q_OBJECT

public:
    explicit FCallRates(QWidget *parent = 0);
    ~FCallRates();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FCallRates *ui;
};

#endif // FCALLRATES_H
