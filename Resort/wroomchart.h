#ifndef WROOMCHART_H
#define WROOMCHART_H

#include "basewidget.h"
#include <QGraphicsScene>

namespace Ui {
class WRoomChart;
}

class WRoomChartDock;

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

private:
    Ui::WRoomChart *ui;

    QGraphicsScene *fMainScene;

    QGraphicsScene *fRoomScene;

    QGraphicsScene *fDateScene;

    WRoomChartDock *fDock;

    virtual bool event(QEvent *event);

private slots:
    void mainViewVerticalScrollBarValueChanged(int value);

    void mainViewHorizontalScrollBarValueChanged(int value);

    void roomViewVerticalScrollBarValueChanged(int value);

    void dateViewHorizontalScrollBarValueChanged(int value);

    void on_btnReset_clicked();
};

#endif // WROOMCHART_H
