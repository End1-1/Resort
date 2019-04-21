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
    explicit FHotelHierarchy(QWidget *parent = nullptr);
    ~FHotelHierarchy();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FHotelHierarchy *ui;
};

#endif // FHOTELHIERARCHY_H
