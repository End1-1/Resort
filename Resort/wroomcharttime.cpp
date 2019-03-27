#include "wroomcharttime.h"
#include "wroomchartclasses.h"

WRoomChartTime::WRoomChartTime(Reserve *r) :
    QTimer()
{
    fReserve = r;
    setInterval(400);
    setSingleShot(true);
    connect(this, SIGNAL(timeout()), this, SLOT(timeout()));
}

void WRoomChartTime::start() {
    fDoubleClick = 0;
    QTimer::start();
}

void WRoomChartTime::incDoubleClick() {
    if (isActive()) {
        fDoubleClick ++;
    }
}

void WRoomChartTime::timeout() {
    if (fDoubleClick == 1) {
        fReserve->singleClick();
    } else if (fDoubleClick > 1) {
        fReserve->doubleClick();
    }
    fReserve->removeTimer();
}

