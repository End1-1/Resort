#ifndef FDAILYTRANSACTION_H
#define FDAILYTRANSACTION_H

#include "wfilterbase.h"

namespace Ui {
class FDailyTransaction;
}

class FDailyTransaction : public WFilterBase
{
    Q_OBJECT

public:
    explicit FDailyTransaction(QWidget *parent = nullptr);
    ~FDailyTransaction();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FDailyTransaction *ui;
};

#endif // FDAILYTRANSACTION_H
