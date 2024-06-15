#ifndef FINCOMPLETEGUESTSNAMES_H
#define FINCOMPLETEGUESTSNAMES_H

#include "wfilterbase.h"

namespace Ui {
class FIncompleteGuestsNames;
}

class FIncompleteGuestsNames : public WFilterBase
{
    Q_OBJECT

public:
    explicit FIncompleteGuestsNames(QWidget *parent = nullptr);
    ~FIncompleteGuestsNames();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();
    virtual void apply(WReportGrid *rg);

private:
    Ui::FIncompleteGuestsNames *ui;
};

#endif // FINCOMPLETEGUESTSNAMES_H
