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
    explicit FInHouseGuest(QWidget *parent = nullptr);
    ~FInHouseGuest();
    virtual void apply(WReportGrid *rg);
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();

private slots:
    void on_chDate_clicked(bool checked);
    void on_chTime_clicked(bool checked);
    void on_chAll_clicked(bool checked);

private:
    Ui::FInHouseGuest *ui;
};

#endif // FINHOUSEGUEST_H
