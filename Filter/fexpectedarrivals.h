#ifndef FEXPECTEDARRIVALS_H
#define FEXPECTEDARRIVALS_H

#include "wfilterbase.h"
#include "goexpextedarrivals.h"

namespace Ui {
class FExpectedArrivals;
}

class FExpectedArrivals : public WFilterBase
{
    Q_OBJECT

public:
    explicit FExpectedArrivals(QWidget *parent = nullptr);
    ~FExpectedArrivals();
    virtual void apply(WReportGrid *rg);
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();
    virtual GOWidget *gridOptionWidget();

private:
    Ui::FExpectedArrivals *ui;
    void printArrival(WReportGrid *rg);
    void printDeparture(WReportGrid *rg);
    void printBoth(WReportGrid *rg);
    QString type();
    QString type2();
};

#endif // FEXPECTEDARRIVALS_H
