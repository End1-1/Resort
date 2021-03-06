#ifndef FCLADVANCE_H
#define FCLADVANCE_H

#include "wfilterbase.h"

namespace Ui {
class FCLAdvance;
}

class FCLAdvance : public WFilterBase
{
    Q_OBJECT

public:
    explicit FCLAdvance(QWidget *parent = nullptr);
    ~FCLAdvance();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FCLAdvance *ui;
};

#endif // FCLADVANCE_H
