#include "wroomchart.h"
#include "ui_wroomchart.h"
#include "wroomchartclasses.h"
#include "wroomchartdock.h"
#include "wreservation.h"
#include "winvoice.h"
#include <QGraphicsItem>
#include <QScrollBar>
#include <QElapsedTimer>
#include <QThread>

WRoomChart::WRoomChart(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WRoomChart)
{
    ui->setupUi(this);
    fVisibleDays = static_cast<int>(fFirstDate.daysTo(fLastDate));
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
    ui->mainView->verticalScrollBar()->blockSignals(true);
    ui->mainView->horizontalScrollBar()->blockSignals(true);
    ui->mainView->setMinimumWidth(fVisibleDays * RECT_SIDE);
    connect(ui->scrollArea->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(mainViewVerticalScrollBarValueChanged(int)));
    connect(ui->scrollArea->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(mainViewHorizontalScrollBarValueChanged(int)));
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
    dd.exec("select * from f_reservation_chart order by f_roombuilding, f_room ");
    qDebug() << "Reservation query" << t.elapsed();
    t.restart();

    if (dd.nextRow()) {        
        do {
            int room = dd.getInt("f_room");
            QString id = dd.getString("f_id");
            if (!fRoomRows.contains(room)) {
                fRoomRows[room] = rows++;
                fRoomShort[room] = dd.getString("f_roomshort");
                fRoomState[room] = dd.getInt("f_roomstate");
            }
            fReserveDateStart[id] = dd.getDate("f_startdate");
            fReserveDateEnd[id] = dd.getDate("f_enddate");
            fReserveCardex[id] = dd.getString("f_cardex");
            fReserveGuest[id] = dd.getString("f_guest");
            fReserveState[id] = dd.getInt("f_state");
            fReserveRoomName[id] = dd.getString("f_roomshort");
            fReserveStatus[id] = dd.getInt("f_reservestate");
            fReserveStateName[id] = dd.getString("f_statename");
            fReserveStatusName[id] = dd.getString("f_reservestatname");
            fReserveInvoice[id] = dd.getString("f_invoice");
            fReserveGroup[id] = dd.getInt("f_group");
            fReserveGroupName[id] = dd.getString("f_groupname");
            Reserve *r = new Reserve(id, this);
            r->setWidth(dd.getInt("f_days"));
            int left = ((static_cast<int>(fFirstDate.daysTo(dd.getDate("f_startdate"))) + 1) * RECT_SIDE) + 2;
            int top = (fRoomRows[dd.getInt("f_room")] * RECT_SIDE) + 2;
            r->setPos(left + 2, top);
            fMainScene->addItem(r);
        } while (dd.nextRow());
    }

    qDebug() << dd.rowCount() << t.elapsed();
    t.restart();

    qreal lineHeight = fRoomRows.count() * RECT_SIDE;
    qreal lineWidth = fVisibleDays * RECT_SIDE;
    for (qint32 i = 0; i < fVisibleDays; i++) {
        QGraphicsItem *item = new QGraphicsLineItem(RECT_SIDE * i, 0, RECT_SIDE * i, lineHeight);
        item->setZValue(Z_VALUE_GRID_LINE);
        fMainScene->addItem(item);
    }

    qDebug() << "Col lines" << fFirstDate.daysTo(fLastDate) << t.elapsed();
    t.restart();

    ui->roomView->setMinimumHeight(rows * RECT_SIDE);
    ui->mainView->setMinimumHeight(rows * RECT_SIDE);
    for (int i = 0; i < rows; i++) {
        QGraphicsItem *item = new QGraphicsLineItem(0, RECT_SIDE * i,  lineWidth, RECT_SIDE * i);
        item->setZValue(Z_VALUE_GRID_LINE);
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
    for (int i = 0; i < fVisibleDays; i++) {
        QDate d = fFirstDate.addDays(i);
        if (!prev.isValid()) {
            prev = d;
            x = i;
        }
        if (d.month() != prev.month()) {
            QGraphicsItem *month = new MonthRect(prev, static_cast<int>(prev.daysTo(d)));
            month->setPos(x * RECT_SIDE, 0);
            fDateScene->addItem(month);
            prev = d;
            x = i;
        }
        QGraphicsItem *item = new DateRect(d);
        fDateScene->addItem(item);
    }

    qDebug() << "Room and date scene" << t.elapsed();
    t.restart();

    ui->scrollArea->verticalScrollBar()->setValue(0);
    int mainScrollPos = static_cast<int>(fFirstDate.daysTo(WORKING_DATE) * RECT_SIDE);
    ui->scrollArea->horizontalScrollBar()->setValue(mainScrollPos);
    ui->dateView->horizontalScrollBar()->setMaximum(static_cast<int>(fDateScene->width()));
    ui->dateView->horizontalScrollBar()->setValue(static_cast<int>(fFirstDate.daysTo(WORKING_DATE)) * RECT_SIDE);
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
    switch (fReserveState[id]) {
    case RESERVE_CHECKIN:
        WInvoice::openInvoiceWindow(id);
        break;
    case RESERVE_RESERVE:
        WReservation::openReserveWindows(id);
        break;
    }
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
    ui->scrollArea->verticalScrollBar()->setValue(value);
}

void WRoomChart::dateViewHorizontalScrollBarValueChanged(int value)
{
    ui->scrollArea->horizontalScrollBar()->setValue(value);
}

void WRoomChart::on_btnReset_clicked()
{
    loadReservations();
}
