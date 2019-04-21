#ifndef FNOUSEDADVANCE_H
#define FNOUSEDADVANCE_H

#include "wfilterbase.h"

namespace Ui {
class FNoUsedAdvance;
}

class FNoUsedAdvance : public WFilterBase
{
    Q_OBJECT

public:
    explicit FNoUsedAdvance(QWidget *parent = nullptr);
    ~FNoUsedAdvance();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);
    static void openReport();

private:
    Ui::FNoUsedAdvance *ui;
};

#endif // FNOUSEDADVANCE_H
