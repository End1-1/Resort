#ifndef GUESTCHECKIN_H
#define GUESTCHECKIN_H

#include "wfilterbase.h"

namespace Ui {
class GuestCheckin;
}

class GuestCheckin : public WFilterBase
{
    Q_OBJECT

public:
    explicit GuestCheckin(QWidget *parent = nullptr);
    ~GuestCheckin();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private:
    Ui::GuestCheckin *ui;
};

#endif // GUESTCHECKIN_H
