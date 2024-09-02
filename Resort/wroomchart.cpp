#include "wroomchart.h"
#include "ui_wroomchart.h"
#include "wroomchartclasses.h"
#include "wroomchartdock.h"
#include "wreservation.h"
#include "wroomcharttemprectdlg.h"
#include "winvoice.h"
#include <QGraphicsItem>
#include <QScrollBar>
#include <QElapsedTimer>

WRoomChart::WRoomChart(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WRoomChart)
{
    ui->setupUi(this);
    fFirstDate = WORKING_DATE;
    fLastDate = fFirstDate.addYears(5);
    fVisibleDays = static_cast<int>(fFirstDate.daysTo(fLastDate));
    message::info(QString::number(fVisibleDays));
    message::info(WORKING_DATE.toString());
    message::info(fLastDate.toString());
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
    ui->roomView->verticalScrollBar()->blockSignals(true);
    ui->dateView->horizontalScrollBar()->blockSignals(true);
    ui->mainView->verticalScrollBar()->blockSignals(true);
    ui->mainView->horizontalScrollBar()->blockSignals(true);
    ui->mainView->setMinimumWidth(fVisibleDays * RECT_SIDE);
    connect(ui->scrollArea->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(mainViewVerticalScrollBarValueChanged(int)));
    connect(ui->scrollArea->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(mainViewHorizontalScrollBarValueChanged(int)));
    connect(ui->scrollRoom->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(roomViewVerticalScrollBarValueChanged(int)));
    connect(ui->scrollDate->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(dateViewHorizontalScrollBarValueChanged(int)));
    installEventFilter(this);
    fDock = new WRoomChartDock(this);
    fDock->hide();
    DoubleDatabase dd;
    dd.exec("select f_id, f_short from f_room_classes order by f_queue");
    while (dd.nextRow()) {
        QPushButton *b = new QPushButton();
        b->setMaximumSize(30, 30);
        b->setCheckable(true);
        b->setText(dd.getString(1));
        b->setProperty("cat", dd.getInt(0));
        connect(b, SIGNAL(clicked()), this, SLOT(catButtonClicked()));
        ui->hlCat->addWidget(b);
    }
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
    fMainScene = new ChartScene();
    connect(fMainScene, SIGNAL(createReserve(int, int, TempRectItem*)), this, SLOT(createReserve(int,int, TempRectItem*)));
    ui->mainView->setScene(fMainScene);
    fRoomScene = new QGraphicsScene();
    ui->roomView->setScene(fRoomScene);
    fDateScene = new QGraphicsScene();
    ui->dateView->setScene(fDateScene);

    int rows = 0;
    QString query = "select rm.f_id as f_room, rc.f_id, rc.f_invoice, rc.f_state, rc.f_statename, "
            "rc.f_reservestate, rc.f_reservestatename, rc.f_roomcategory, rm.f_short as f_roomshort, rm.f_state as f_roomstate, "
            "rc.f_roomfloor, rm.f_building as f_roombuilding, rc.f_startdate, rc.f_enddate, rc.f_days, rc.f_guest, "
            "rc.f_allguest, rc.f_cardex, rc.f_cardexname, rc.f_groupcode, rc.f_groupname "
            "from f_room rm left join f_reservation_chart rc on rc.f_room=rm.f_id ";
    QStringList where;
    QString f = categoriesFilter();
    if (!f.isEmpty()) {
        where << QString(" rc.f_roomcategory in (%1)").arg(f);
    }
    if (where.count() > 0) {
        query += "where ";
        bool first = true;
        foreach (QString s, where) {
            if (first) {
                first = false;
            } else {
                query += " and ";
            }
            query += s;
        }
    }
    query += " order by rm.f_building, rm.f_id, rc.f_startdate desc ";
    DoubleDatabase dd;
    dd.exec(query);
    qDebug() << "Reservation query" << t.elapsed();
    t.restart();

    int currRoom = 0;
    QDate currEntry;
    Reserve *prevReserve = nullptr;
    if (dd.nextRow()) {
        do {
            int room = dd.getInt("f_room");
            if (room == 0) {
                continue;
            }
            if (!fRoomRows.contains(room)) {
                fRoomRows[room] = rows++;
                fRoomShort[room] = dd.getString("f_roomshort");
                fRoomState[room] = dd.getInt("f_roomstate");
            }
            if (dd.getString("f_id").isEmpty()) {
                continue;
            }
            if (currRoom != room) {
                currRoom = room;
                currEntry = QDate::currentDate().addDays(-1);
            } else {
                if (currEntry == dd.getDate("f_enddate")) {
                    if (prevReserve) {
                        prevReserve->fOffcet = 12;
                    }
                }
            }
            currEntry = dd.getDate("f_startdate");
            QString id = dd.getString("f_id");
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
            prevReserve = r;
            r->setWidth(dd.getInt("f_days") + 1);
            int days = static_cast<int>(fFirstDate.daysTo(dd.getDate("f_startdate")));
            int left = (days * RECT_SIDE) + 2;
            int top = (fRoomRows[dd.getInt("f_room")] * RECT_SIDE) + 2;
            r->setPos(left, top);
            fMainScene->addItem(r);
        } while (dd.nextRow());
    }

    qDebug() << dd.rowCount() << t.elapsed();
    t.restart();

    ui->roomView->setMinimumHeight(rows * RECT_SIDE);
    ui->mainView->setMinimumHeight(rows * RECT_SIDE);
    ui->dateView->setMinimumWidth(fVisibleDays * RECT_SIDE);

    qreal lineHeight = fRoomRows.count() * RECT_SIDE;
    qreal lineWidth = fVisibleDays * RECT_SIDE;
    for (qint32 i = 0; i < fVisibleDays; i++) {
        QGraphicsItem *item = new QGraphicsLineItem(RECT_SIDE * i, 0, RECT_SIDE * i, lineHeight);
        item->setZValue(Z_VALUE_GRID_LINE);
        fMainScene->addItem(item);
    }

    qDebug() << "Col lines" << fFirstDate.daysTo(fLastDate) << t.elapsed();
    t.restart();

    for (int i = 0; i < rows + 1; i++) {
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
    QDate d;
    for (int i = 0; i < fVisibleDays; i++) {
        d = fFirstDate.addDays(i);
        if (!prev.isValid()) {
            prev = d;
            x = i;
        }
        QGraphicsItem *item = new DateRect(d);
        fDateScene->addItem(item);
        if (d.month() != prev.month() || d == fLastDate.addDays(-1)) {
            if (d == fLastDate.addDays(-1)) {
                d = d.addDays(1);
            }
            QGraphicsItem *month = new MonthRect(prev, static_cast<int>(prev.daysTo(d)));
            month->setPos(x * RECT_SIDE, 0);
            fDateScene->addItem(month);
            prev = d;
            x = i;
        }
    }

    qDebug() << "Room and date scene" << t.elapsed();
    t.restart();

    ui->scrollArea->verticalScrollBar()->setValue(0);
    ui->scrollArea->horizontalScrollBar()->setValue(0);

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
        WInvoice::openInvoiceFromReservation(id);
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

QString WRoomChart::categoriesFilter()
{
    QObjectList ol = ui->wCat->children();
    QString list;
    bool first = true;
    foreach (QObject *o, ol) {
        QPushButton *b = dynamic_cast<QPushButton*>(o);
        if (!b) {
            continue;
        }
        if (b->isChecked()) {
            if (first) {
                first = false;
            } else {
                list += ",";
            }
            list += b->property("cat").toString();
        }
    }
    return list;
}

void WRoomChart::createReserve(int row, int column, TempRectItem *t)
{
    qDebug() << row << column;
    QDate d1 = fFirstDate.addDays(column);
    QDate d2 = fFirstDate.addDays(t->rect().right() / RECT_SIDE);
    WRoomChartTempRectDlg *d = new WRoomChartTempRectDlg(this);
    d->setDates(d1, d2);
    d->exec();
    delete d;
    t->reset();
    fMainScene->update();
}

void WRoomChart::catButtonClicked()
{
    loadReservations();
}

void WRoomChart::mainViewVerticalScrollBarValueChanged(int value)
{
    ui->scrollRoom->verticalScrollBar()->setValue(value);
}

void WRoomChart::mainViewHorizontalScrollBarValueChanged(int value)
{
    ui->scrollDate->horizontalScrollBar()->setValue(value);
    qDebug() << ui->scrollDate->horizontalScrollBar()->value();
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

void WRoomChart::on_btnNewReservation_clicked()
{
    QList<CacheRoom*> rooms;
    rooms.append(nullptr);
    addTab<WReservation>()->setInitialParams(WORKING_DATE, WORKING_DATE, rooms);
}
