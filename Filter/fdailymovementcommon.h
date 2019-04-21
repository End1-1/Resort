#ifndef FDAILYMOVEMENTCOMMON_H
#define FDAILYMOVEMENTCOMMON_H

#include "wfilterbase.h"

namespace Ui {
class FDailyMovementCommon;
}

class FDailyMovementCommon : public WFilterBase
{
    Q_OBJECT

public:
    explicit FDailyMovementCommon(QWidget *parent = nullptr);
    ~FDailyMovementCommon();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();
    virtual void apply(WReportGrid *rg);
    static void open();

private:
    Ui::FDailyMovementCommon *ui;

};

#endif // FDAILYMOVEMENTCOMMON_H
