#ifndef WNOTES_H
#define WNOTES_H

#include "wreportgrid.h"

class WNotes : public WReportGrid
{
    Q_OBJECT
public:
    explicit WNotes(QWidget *parent = nullptr);
    virtual void setupTab();

};

#endif // WNOTES_H
