#include "wroomchart.h"
#include "ui_wroomchart.h"
#include "wroomchartclasses.h"
#include "wroomchartdock.h"
#include <QGraphicsItem>
#include <QScrollBar>
#include <QElapsedTimer>
#include <QThread>

WRoomChart::WRoomChart(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WRoomChart)
{
    ui->setupUi(this);
    FONT = qApp->font();
    if (DAYS_OF_WEEK.count() == 0) {
        DAYS_OF_WEEK[1] = "Mo";
        DAYS_OF_WEEK[2] = "Tu";
        DAYS_OF_WEEK[3] = "We";
        DAYS_OF_WEEK[4] = "Th";
        DAYS_OF_WEEK[5] = "Fr";
        DAYS_OF_WEEK[6] = "Sa";
        DAYS_OF_WEEK[7] = "Su";
    }
    fMainScene = nullptr;
    fRoomScene = nullptr;
    fDateScene = nullptr;
    connect(ui->mainView->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(mainViewVerticalScrollBarValueChanged(int)));
    connect(ui->mainView->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(mainViewHorizontalScrollBarValueChanged(int)));
    connect(ui->roomView->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(roomViewVerticalScrollBarValueChanged(int)));
    connect(ui->dateView->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(dateViewHorizontalScrollBarValueChanged(int)));
    installEventFilter(this);
    fDock = new WRoomChartDock(this);
    fDock->hide();
}

WRoomChart::~WRoomChart()
{
    delete ui;
}

void WRoomChart::loadReservations()
{
    QElapsedTimer t, t2;
    t.start();
    t2.start();

    fRoomRows.clear();
    fRoomShort.clear();
    fRoomState.clear();
    fReserveDateEnd.clear();
    fReserveDateStart.clear();
    fReserveRoomName.clear();
    fReserveCardex.clear();
    fReserveGuest.clear();
    if (fRoomScene) {
        ClearScene *cs = new ClearScene();
        cs->addObject(fRoomScene);
        cs->addObject(fDateScene);
        cs->addObject(fMainScene);
        cs->start();
    }
    fMainScene = new QGraphicsScene();
    ui->mainView->setScene(fMainScene);
    fRoomScene = new QGraphicsScene();
    ui->roomView->setScene(fRoomScene);
    fDateScene = new QGraphicsScene();
    ui->dateView->setScene(fDateScene);

    DoubleDatabase dd(true, false);    
    int rows = 0;
    dd.exec("select r.f_id, r.f_state, r.f_reservestate, r.f_room, r.f_startdate, r.f_enddate, "
            "g.guest, c.f_name, rm.f_short, rm.f_state as f_roomstate, sn.f_en as f_statename, rsn.f_en as f_statusname,  "
            "r.f_invoice, r.f_group, rg.f_name as f_groupname "
            "from f_reservation r "
            "left join guests g on g.f_id=r.f_guest "
            "left join f_cardex c on c.f_cardex=r.f_cardex "
            "left join f_room rm on rm.f_id=r.f_room "
            "left join f_reservation_state sn on sn.f_id=r.f_state "
            "left join f_reservation_status rsn on rsn.f_id=r.f_reservestate "
            "left join f_reservation_group rg on rg.f_id=r.f_group "
            "where r.f_state in (1,2,4,7,9) and r.f_room>0 "
            "order by rm.f_building, rm.f_floor, rm.f_id ");

    qDebug() << "Reservation query" << t.elapsed();
    t.restart();

    if (dd.nextRow()) {        
        do {
            QDate dateStart = dd.getDate(4);
            int room = dd.getInt(3);
            if (!fRoomRows.contains(room)) {
                fRoomRows[room] = rows++;
                fRoomShort[room] = dd.getString(8);
                fRoomState[room] = dd.getInt("f_roomstate");
            }
            QString id = dd.getString(0);
            fReserveDateStart[id] = dateStart;
            fReserveDateEnd[id] = dd.getDate(5);
            fReserveCardex[id] = dd.getString(7);
            fReserveGuest[id] = dd.getString(6);
            fReserveState[id] = dd.getInt(1);
            fReserveRoomName[id] = dd.getString(8);
            fReserveStatus[id] = dd.getInt(2);
            fReserveStateName[id] = dd.getString("f_statename");
            fReserveStatusName[id] = dd.getString("f_statusname");
            fReserveInvoice[id] = dd.getString("f_invoice");
            fReserveGroup[id] = dd.getInt("f_group");
            fReserveGroupName[id] = dd.getString("f_groupname");
            Reserve *r = new Reserve(id, this);
            r->setWidth(dateStart.daysTo(dd.getDate(5)));
            int left = fFirstDate.daysTo(dateStart) + 1;
            r->setPos((left * RECT_SIDE) + 2, (fRoomRows[dd.getInt(3)] * RECT_SIDE) + 2);
            fMainScene->addItem(r);
        } while (dd.nextRow());
    }

    qDebug() << dd.rowCount() << t.elapsed();
    t.restart();

    qreal lineHeight = fMainScene->height();
    for (qint64 i = 0, count = fFirstDate.daysTo(fLastDate); i < count; i++) {
        QGraphicsItem *item = new QGraphicsLineItem(RECT_SIDE * i, 0, RECT_SIDE * i, lineHeight);
        item->setZValue(Z_VALUE_GRID_LINE);
        fMainScene->addItem(item);
    }

    qDebug() << "Col lines" << fFirstDate.daysTo(fLastDate) << t.elapsed();
    t.restart();

    qreal lineWidth = fMainScene->width();
    for (int i = 0; i < rows; i++) {
        QGraphicsItem *item = new QGraphicsLineItem(0, RECT_SIDE * i,  lineWidth, RECT_SIDE * i);
        item->setZValue(Z_VALUE_GRID_LINE + 1);
        fMainScene->addItem(item);
    }

    qDebug() << "Row lines" << rows << t.elapsed();
    t.restart();

    for (int i = 0; i < rows; i++) {
        RoomRect *r = new RoomRect(fRoomRows.key(i));
        r->setPos(0, i * RECT_SIDE);
        fRoomScene->addItem(r);
    }

    int x = 0;
    QDate prev;
    for (int i = 0, count = fFirstDate.daysTo(fLastDate); i < count; i++) {
        QDate d = fFirstDate.addDays(i);
        if (!prev.isValid()) {
            prev = d;
            x = i;
        }
        if (d.month() != prev.month()) {
            QGraphicsItem *month = new MonthRect(prev, prev.daysTo(d));
            month->setPos(x * RECT_SIDE, 0);
            fDateScene->addItem(month);
            prev = d;
            x = i;
        }
        QGraphicsItem *item = new DateRect(d);
        fDateScene->addItem(item);
    }

    qDebug() << "Room scene" << t.elapsed();
    t.restart();

    ui->mainView->verticalScrollBar()->setValue(0);
    ui->mainView->horizontalScrollBar()->setValue(fFirstDate.daysTo(WORKING_DATE) * RECT_SIDE);
    ui->dateView->horizontalScrollBar()->setMaximum(fDateScene->width());
    ui->dateView->horizontalScrollBar()->setValue(fFirstDate.daysTo(WORKING_DATE) * RECT_SIDE);
    ui->roomView->verticalScrollBar()->setValue(0);

    qDebug() << "Total" << t2.elapsed();
}

void WRoomChart::setup()
{
    BaseWidget::setup();
    show();
    qApp->processEvents();
    loadReservations();
}

void WRoomChart::setupTab()
{
    setupTabTextAndIcon(tr("Room chart"), ":/images/traffic.png");
}

void WRoomChart::singleClick(const QString &id)
{
    QMap<QString, QString> d;
    d["statuscode"] = QString::number(fReserveState[id]);
    d["status"] = fReserveStateName[id];
    d["type"] = fReserveStatusName[id];
    d["guest"] = fReserveGuest[id];
    d["entrydate"] = fReserveDateStart[id].toString(def_date_format);
    d["departuredate"] = fReserveDateEnd[id].toString(def_date_format);
    d["code"] = id;
    d["invoice"] = fReserveInvoice[id];
    d["groupid"] = QString::number(fReserveGroup[id]);
    d["groupname"] = fReserveGroupName[id];
    fDock->setData(d);
    fDock->show();
    fDock->raise();
}

void WRoomChart::doubleClick(const QString &id)
{

}

bool WRoomChart::event(QEvent *event)
{
    if (event->type() == QEvent::KeyRelease) {
        QKeyEvent *k = static_cast<QKeyEvent*>(event);
        if (k->key() == Qt::Key_Enter || k->key() == Qt::Key_Return) {
            qDebug() << "DAVAVAVA!";
        }
    }
    return BaseWidget::event(event);
}

void WRoomChart::mainViewVerticalScrollBarValueChanged(int value)
{
    ui->roomView->verticalScrollBar()->setValue(value);
}

void WRoomChart::mainViewHorizontalScrollBarValueChanged(int value)
{
    ui->dateView->horizontalScrollBar()->setValue(value);
}

void WRoomChart::roomViewVerticalScrollBarValueChanged(int value)
{
    ui->mainView->verticalScrollBar()->setValue(value);
}

void WRoomChart::dateViewHorizontalScrollBarValueChanged(int value)
{
    ui->mainView->horizontalScrollBar()->setValue(value);
}

void WRoomChart::on_btnReset_clicked()
{
    loadReservations();
}
