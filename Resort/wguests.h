#ifndef WGUESTS_H
#define WGUESTS_H

#include "wreportgrid.h"

class WGuests : public WReportGrid
{
    Q_OBJECT
public:
    WGuests(QWidget *parent = nullptr);
protected:
    virtual void setupTab();
};

#endif // WGUESTS_H
