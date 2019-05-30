#ifndef FCASHREPORTBYITEM_H
#define FCASHREPORTBYITEM_H

#include "wfilterbase.h"

namespace Ui {
class FCashReportByItem;
}

class FCashReportByItem : public WFilterBase
{
    Q_OBJECT

public:
    explicit FCashReportByItem(QWidget *parent = nullptr);
    ~FCashReportByItem();
    virtual void apply(WReportGrid *rg);
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();

private:
    Ui::FCashReportByItem *ui;

private slots:
    void refresh();
};

#endif // FCASHREPORTBYITEM_H
