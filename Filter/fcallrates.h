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
    explicit FCallRates(QWidget *parent = nullptr);
    ~FCallRates();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FCallRates *ui;
};

#endif // FCALLRATES_H
