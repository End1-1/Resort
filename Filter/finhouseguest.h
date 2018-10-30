#ifndef FINHOUSEGUEST_H
#define FINHOUSEGUEST_H

#include "wfilterbase.h"

namespace Ui {
class FInHouseGuest;
}

class FInHouseGuest : public WFilterBase
{
    Q_OBJECT

public:
    explicit FInHouseGuest(QWidget *parent = 0);
    ~FInHouseGuest();
    virtual void apply(WReportGrid *rg);
    virtual QWidget *firstElement();
    virtual QString reportTitle();
private slots:
    void on_chDate_clicked(bool checked);

    void on_chTime_clicked(bool checked);

private:
    Ui::FInHouseGuest *ui;
};

#endif // FINHOUSEGUEST_H
