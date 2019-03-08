#ifndef FHOTELHIERARCHY_H
#define FHOTELHIERARCHY_H

#include "wfilterbase.h"

namespace Ui {
class FHotelHierarchy;
}

class FHotelHierarchy : public WFilterBase
{
    Q_OBJECT

public:
    explicit FHotelHierarchy(QWidget *parent = 0);
    ~FHotelHierarchy();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FHotelHierarchy *ui;
};

#endif // FHOTELHIERARCHY_H
