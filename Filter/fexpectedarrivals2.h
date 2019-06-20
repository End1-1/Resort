#ifndef FEXPECTEDARRIVALS2_H
#define FEXPECTEDARRIVALS2_H

#include "wfilterbase.h"
#include "goexpextedarrivals.h"

namespace Ui {
class FExpectedArrivals2;
}

class FExpectedArrivals2 : public WFilterBase
{
    Q_OBJECT

public:
    explicit FExpectedArrivals2(QWidget *parent = nullptr);
    ~FExpectedArrivals2();
    virtual void apply(WReportGrid *rg);
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();
    virtual GOWidget *gridOptionWidget();

private:
    Ui::FExpectedArrivals2 *ui;
    void printArrival(WReportGrid *rg);
    void printDeparture(WReportGrid *rg);
    void printBoth(WReportGrid *rg);
    QString type();
    QString type2();

private slots:
    void doubleClickOnRow(const QList<QVariant> &v);
};

#endif // FEXPECTEDARRIVALS2_H
