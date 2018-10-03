#ifndef FDISHES_H
#define FDISHES_H

#include "wfilterbase.h"

namespace Ui {
class FDishes;
}

class FDishes : public WFilterBase
{
    Q_OBJECT

public:
    explicit FDishes(QWidget *parent = 0);
    ~FDishes();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual void apply(WReportGrid *rg);
private:
    QList<QVariant> fRowValues;
    int currCols;
    Ui::FDishes *ui;
private slots:
    void doubleClickOnRow(const QList<QVariant> row);
    void newBtn();
};

#endif // FDISHES_H
