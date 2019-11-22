#ifndef FEXPECTEDARRIVALSIMPLE_H
#define FEXPECTEDARRIVALSIMPLE_H

#include "wfilterbase.h"

namespace Ui {
class FExpectedArrivalSimple;
}

class FExpectedArrivalSimple : public WFilterBase
{
    Q_OBJECT

public:
    explicit FExpectedArrivalSimple(QWidget *parent = nullptr);
    ~FExpectedArrivalSimple();
    virtual void apply(WReportGrid *rg);
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();

private:
    Ui::FExpectedArrivalSimple *ui;

private slots:
    void refresh();
};

#endif // FEXPECTEDARRIVALSIMPLE_H
