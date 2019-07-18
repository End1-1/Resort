#ifndef FFORECASTOCCUPANCYCATEGORYREAL_H
#define FFORECASTOCCUPANCYCATEGORYREAL_H

#include "wfilterbase.h"

namespace Ui {
class FForecastOccupancyCategoryReal;
}

class FForecastOccupancyCategoryReal : public WFilterBase
{
    Q_OBJECT

public:
    explicit FForecastOccupancyCategoryReal(QWidget *parent = nullptr);
    ~FForecastOccupancyCategoryReal();
    virtual void apply(WReportGrid *rg);
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual QString reportTitle();

private slots:
    void on_deStart_dateChanged(const QDate &date);
    void on_deEnd_dateChanged(const QDate &date);

private:
    Ui::FForecastOccupancyCategoryReal *ui;
    void setupTab();
};

#endif // FFORECASTOCCUPANCYCATEGORYREAL_H
