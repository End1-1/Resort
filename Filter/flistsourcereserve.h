#ifndef FLISTSOURCERESERVE_H
#define FLISTSOURCERESERVE_H

#include "wfilterbase.h"

namespace Ui {
class FListSourceReserve;
}

class FListSourceReserve : public WFilterBase
{
    Q_OBJECT

public:
    explicit FListSourceReserve(QWidget *parent = 0);
    ~FListSourceReserve();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual void apply(WReportGrid *rg);
    virtual void setup();
    static void openReport();
private:
    Ui::FListSourceReserve *ui;
};

#endif // FLISTSOURCERESERVE_H
