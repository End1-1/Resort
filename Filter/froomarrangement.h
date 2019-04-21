#ifndef FROOMARRANGEMENT_H
#define FROOMARRANGEMENT_H

#include "wfilterbase.h"

namespace Ui {
class FRoomArrangement;
}

class FRoomArrangement : public WFilterBase
{
    Q_OBJECT

public:
    explicit FRoomArrangement(QWidget *parent = nullptr);
    ~FRoomArrangement();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FRoomArrangement *ui;
};

#endif // FROOMARRANGEMENT_H
