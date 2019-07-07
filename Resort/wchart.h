#ifndef WCHART_H
#define WCHART_H

#include "basewidget.h"
#include <QtCharts/QChartGlobal>

namespace Ui {
class WChart;
}

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class WChart : public BaseWidget
{
    Q_OBJECT

public:
    explicit WChart(QWidget *parent = nullptr);
    ~WChart();
    void setTitle(const QString &title, const QString &image);
    void lineChart(int vMax, const QDate &hMin, const QDate &hMax, const QList<QPair<QDateTime, int> > &values) const;

private:
    Ui::WChart *ui;
};

#endif // WCHART_H
