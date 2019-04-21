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
    explicit FDishes(QWidget *parent = nullptr);
    ~FDishes();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private:
    QList<QVariant> fRowValues;
    int currCols;
    Ui::FDishes *ui;

private slots:
    void doubleClickOnRow(const QList<QVariant> row);
    void newBtn();
    void on_btnGetFromCafe_clicked();
};

#endif // FDISHES_H
