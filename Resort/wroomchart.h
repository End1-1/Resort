#ifndef WROOMCHART_H
#define WROOMCHART_H

#include "basewidget.h"
#include <QGraphicsScene>

namespace Ui {
class WRoomChart;
}

class WRoomChartDock;
class ChartScene;
class TempRectItem;

class WRoomChart : public BaseWidget
{
    Q_OBJECT

public:
    explicit WRoomChart(QWidget *parent = nullptr);
    ~WRoomChart();
    void loadReservations();
    virtual void setup();
    virtual void setupTab();
    void singleClick(const QString &id);
    void doubleClick(const QString &id);
    ChartScene *fMainScene;
    QGraphicsScene *fRoomScene;
    QGraphicsScene *fDateScene;

private:
    Ui::WRoomChart *ui;
    WRoomChartDock *fDock;
    int fVisibleDays;
    virtual bool event(QEvent *event);
    QString categoriesFilter();

private slots:
    void createReserve(int row, int column, TempRectItem *t);
    void catButtonClicked();
    void mainViewVerticalScrollBarValueChanged(int value);
    void mainViewHorizontalScrollBarValueChanged(int value);
    void roomViewVerticalScrollBarValueChanged(int value);
    void dateViewHorizontalScrollBarValueChanged(int value);
    void on_btnReset_clicked();
    void on_btnNewReservation_clicked();
};

#endif // WROOMCHART_H
