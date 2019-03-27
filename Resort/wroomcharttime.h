#ifndef WROOMCHARTTIME_H
#define WROOMCHARTTIME_H

#include <QTimer>

class Reserve;

class WRoomChartTime : public QTimer
{
    Q_OBJECT

public:
    explicit WRoomChartTime(Reserve *r);

    void start();

    void incDoubleClick();

private:
    int fDoubleClick;

    Reserve *fReserve;

public slots:
    void timeout();
};


#endif // WROOMCHARTTIME_H
