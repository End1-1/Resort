#ifndef FINHOUSEGUESTFUTURE_H
#define FINHOUSEGUESTFUTURE_H

#include "wfilterbase.h"

namespace Ui {
class FInhouseGuestFuture;
}

class FInhouseGuestFuture : public WFilterBase
{
    Q_OBJECT

public:
    explicit FInhouseGuestFuture(QWidget *parent = nullptr);
    ~FInhouseGuestFuture() override;
    virtual void apply(WReportGrid *rg) override;
    virtual QWidget *firstElement() override;
    virtual QWidget *lastElement() override;
    virtual QString reportTitle() override;

private:
    Ui::FInhouseGuestFuture *ui;

private slots:
    void refresh();
};

#endif // FINHOUSEGUESTFUTURE_H
