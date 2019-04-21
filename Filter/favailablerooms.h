#ifndef FAVAILABLEROOMS_H
#define FAVAILABLEROOMS_H

#include "wfilterbase.h"

namespace Ui {
class FAvailableRooms;
}

class FAvailableRooms : public WFilterBase
{
    Q_OBJECT

public:
    explicit FAvailableRooms(QWidget *parent = nullptr);
    ~FAvailableRooms();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FAvailableRooms *ui;
};

#endif // FAVAILABLEROOMS_H
