#ifndef FEXPECTEDDEPARTURESIMPLE_H
#define FEXPECTEDDEPARTURESIMPLE_H

#include "wfilterbase.h"

namespace Ui {
class FExpectedDepartureSimple;
}

class FExpectedDepartureSimple : public WFilterBase
{
    Q_OBJECT

public:
    explicit FExpectedDepartureSimple(QWidget *parent = nullptr);
    ~FExpectedDepartureSimple();
    virtual void apply(WReportGrid *rg);
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();

private:
    Ui::FExpectedDepartureSimple *ui;

private slots:
    void refresh();
};

#endif // FEXPECTEDDEPARTURESIMPLE_H
