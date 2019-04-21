#ifndef WCARDEX_H
#define WCARDEX_H

#include "wreportgrid.h"

class WCardex : public WReportGrid
{
    Q_OBJECT
public:
    WCardex(QWidget *parent = nullptr);
    virtual void setupTab();
};

#endif // WCARDEX_H
