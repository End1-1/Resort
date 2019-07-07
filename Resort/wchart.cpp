#include "wchart.h"
#include "ui_wchart.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>

WChart::WChart(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WChart)
{
    ui->setupUi(this);
}

WChart::~WChart()
{
    delete ui;
}

void WChart::setTitle(const QString &title, const QString &image)
{
    setupTabTextAndIcon(title, image);
}

void WChart::lineChart(int vMax, const QDate &hMin, const QDate &hMax, const QList<QPair<QDateTime, int> > &values) const
{
    QValueAxis *va = new QValueAxis();
    va->setRange(0, vMax);
    QDateTimeAxis *dt = new QDateTimeAxis();
    dt->setRange(QDateTime(hMin), QDateTime(hMax));
    dt->setFormat("dd/MM/yyyy");
    auto *chart = new QChart();
    auto *ls = new QLineSeries(chart);
    for (const QPair<QDateTime, int> &d: values) {
        ls->append(d.first.toMSecsSinceEpoch(), d.second);
    }
    chart->addAxis(va, Qt::AlignLeft);
    chart->addAxis(dt, Qt::AlignBottom);
    chart->addSeries(ls);
    auto *chartView = new QChartView(chart);
    ui->vl->addWidget(chartView);
}
