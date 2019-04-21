#ifndef FBREAKFAST_H
#define FBREAKFAST_H

#include "wfilterbase.h"

namespace Ui {
class FBreakfast;
}

class FBreakfast : public WFilterBase
{
    Q_OBJECT

public:
    explicit FBreakfast(QWidget *parent = nullptr);
    ~FBreakfast();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FBreakfast *ui;
private slots:
    void eliminate();
};

#endif // FBREAKFAST_H
