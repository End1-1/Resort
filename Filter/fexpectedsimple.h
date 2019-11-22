#ifndef FEXPECTEDSIMPL_H
#define FEXPECTEDSIMPL_H

#include "wfilterbase.h"

namespace Ui {
class FExpectedSimple;
}

class FExpectedSimple : public WFilterBase
{
    Q_OBJECT

public:
    explicit FExpectedSimple(QWidget *parent = nullptr);
    ~FExpectedSimple();
    virtual void apply(WReportGrid *rg);
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();

private:
    Ui::FExpectedSimple *ui;

private slots:
    void refresh();
};

#endif // FEXPECTEDSIMPL_H
