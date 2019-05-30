#ifndef WCARDEXLIST_H
#define WCARDEXLIST_H

#include "wreportgrid.h"

class WCardexList : public WReportGrid
{
    Q_OBJECT
public:
    WCardexList(QWidget *parent = 0);
    virtual void setupTab();
};

#endif // WCARDEX_H
