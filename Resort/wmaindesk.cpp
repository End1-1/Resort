#include "wmaindesk.h"
#include <QElapsedTimer>
#include <QInputDialog>
#include <QScrollBar>
#include "cacheone.h"
#include "cachereservationcardex.h"
#include "dayitemdelegate.h"
#include "dlgchartcolor.h"
#include "dlgchartdaterange.h"
#include "dlgendofday.h"
#include "dlggroupreservationfuck.h"
#include "dlgpostcharge.h"
#include "dlgreserveconfirmstatus.h"
#include "dlgtransferanyamount.h"
#include "eqtablewidget.h"
#include "monthitemdelegate.h"
#include "reservewidget.h"
#include "roomitemdelegate.h"
#include "roomstate.h"
#include "ui_wmaindesk.h"
#include "utils.h"
#include "winvoice.h"
#include "wmaindeskfilterlist.h"
#include "wreservation.h"

#define SEL_CARDEX 1

WMainDesk::WMainDesk(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WMainDesk)
{
    DoubleDatabase fDD;
    ui->setupUi(this);
    ui->wRoom->setMaximumWidth(__s.value("showroomdescription").toBool() ? 250 : 100);
    ui->wRoom->setMinimumWidth(__s.value("showroomdescription").toBool() ? 250 : 100);
    ui->tblRoom->setColumnWidth(0, ui->wRoom->maximumWidth() - 2);
    ui->g->verticalScrollBar()->blockSignals(true);
    ui->g->horizontalScrollBar()->blockSignals(true);
    fDD.exec("select f_short from f_room_classes order by f_queue");
    while (fDD.nextRow()) {
        QPushButton *btn = new QPushButton(fDD.getString("f_short"));
        btn->setCheckable(true);
        btn->setMaximumWidth(25);
        btn->setStyleSheet("QPushButton:checked{background-color:rgb(178, 250, 184);}");
        connect(btn, SIGNAL(clicked()), this, SLOT(catButtonClick()));
        ui->hlCatButtons->addWidget(btn);
        fCatList.append(fDD.getString(0));
    }
    fDD.exec("select f_id, f_name from f_room_bed order by 1");
    while (fDD.nextRow()) {
        fBedList.append(fDD.getString(0));
        fBedListNames.append(fDD.getString(1));
    }
    fDD.exec("select f_id, f_name from f_room_building ");
    while (fDD.nextRow()) {
        fBuildingList.append(fDD.getString(0));
        fBuildingListNames.append(fDD.getString(1));
    }
    fSmokeList.append(tr("Yes"));
    fSmokeList.append(tr("No"));
    fSmokeListNames.append(tr("Yes"));
    fSmokeListNames.append(tr("No"));
    fStateList.append(tr("Vacant ready"));
    fStateList.append(tr("Checkin"));
    fStateList.append(tr("Dirty"));
    fStateList.append(tr("O/O"));
    fStateListNames.append(tr("Vacant ready"));
    fStateListNames.append(tr("Checkin"));
    fStateListNames.append(tr("Dirty"));
    fStateListNames.append(tr("O/O"));
    fDockHint = new DWMainDeskHint(this);
    fDockHint->hide();
    connect(fDockHint, SIGNAL(visibilityChanged(bool)), this, SLOT(dockHintVisibilityChanged(bool)));
    fDD.exec("select min(f_startdate) from f_reservation where f_state in (1,2,4,7,9)");
    if (fDD.nextRow()) {
        fDateStart = fDD.getDate(0);
        fDateStart.setDate(fDateStart.year(), fDateStart.month(), 1);
    } else {
        fDateStart = QDate::currentDate();
    }
    fDateEnd = fDateStart.addYears(5);
    ChartStartDate = fDateStart;
    int dayCount = fDateStart.daysTo(fDateEnd) + 1;
    ui->tblDay->setColumnCount(dayCount);
    ui->tblDay->horizontalHeader()->setDefaultSectionSize(COLUMN_WIDTH);
    ui->tblDay->setMinimumWidth(dayCount *COLUMN_WIDTH + 2);
    ui->g->setMinimumWidth(ui->tblDay->minimumWidth());
    ui->tblDay->setRowCount(1);
    ui->tblDay->setItemDelegate(new DayItemDelegate());
    for (int i = 0; i < dayCount; i++) {
        C5TableWidgetItem *item = new C5TableWidgetItem();
        item->setData(Qt::UserRole, fDateStart.addDays(i));
        ui->tblDay->setItem(0, i, item);
    }
    ui->tblMonth->setItemDelegate(new MonthItemDelegate());
    ui->tblMonth->setRowCount(1);
    ui->tblMonth->setColumnCount(ui->tblDay->columnCount());
    ui->tblMonth->horizontalHeader()->setDefaultSectionSize(COLUMN_WIDTH);
    int col = 0;
    for (QDate d = fDateStart, end = fDateEnd.addDays(1); d < end; d = d.addDays(d.daysInMonth())) {
        ui->tblMonth->setSpan(0, col, 1, d.daysInMonth());
        C5TableWidgetItem *item = new C5TableWidgetItem();
        item->setData(Qt::UserRole, d);
        ui->tblMonth->setItem(0, col, item);
        col += d.daysInMonth();
    }
    ui->tblRoom->setItemDelegate(new RoomItemDelegate());
    ui->tblRoom->verticalHeader()->setDefaultSectionSize(ROW_HEIGHT);
    fReserveStatus = 0;
    connect(ui->saMain->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(scMainHScroll(int)));
    connect(ui->g->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(scMainHScroll(int)));
    connect(ui->saDate->horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(scDateHScroll(int)));
    connect(ui->saMain->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(scMainVScroll(int)));
    connect(ui->g->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(scMainVScroll(int)));
    connect(ui->saRoom->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(scRoomVScroll(int)));
    connect(ui->tblRoom->selectionModel(), SIGNAL(currentChanged(QModelIndex, QModelIndex)), this,
            SLOT(roomSelectionChanged(QModelIndex, QModelIndex)));
    connect(ui->tblDay->selectionModel(), SIGNAL(currentChanged(QModelIndex, QModelIndex)), this,
            SLOT(daySelectionChanged(QModelIndex, QModelIndex)));
    connect(cache(cid_reservation), SIGNAL(updated(int, QString)), this, SLOT(reservationCacheUpdated(int, QString)));
    connect(cache(cid_room), SIGNAL(updated(int, QString)), this, SLOT(roomCacheUpdated(int, QString)));
    connect( &fTimer, SIGNAL(timeout()), this, SLOT(timeout()));
    timeout();
    fTimer.start(30000);
    ui->btnEndOfDay->setVisible(r__(cr__eod));
    ui->btnGroupReservation->setVisible(r__(cr__reservation_group_reservation));
    ui->tblDay->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tblDay->horizontalHeader()->setDefaultSectionSize(COLUMN_WIDTH);
}

WMainDesk::~WMainDesk()
{
    delete ui;
}

void WMainDesk::setup()
{
    fScene = new RoomScene(this);
    connect(fScene, SIGNAL(editReserve(QString)), this, SLOT(editReserveRoom(QString)));
    ui->g->setScene(fScene);
    filterRoom();
    int x = xFromDate(WORKING_DATE);
    ui->saMain->horizontalScrollBar()->setValue(x);
}

void WMainDesk::setupTab()
{
    setupTabTextAndIcon(tr("Room chart"), ":/images/analytics.png");
}

void WMainDesk::handleBroadcast(const QMap<QString, QVariant> &data)
{
    int cmd = data["command"].toInt();
    switch (cmd) {
        case cmd_end_of_day:
            int x = xFromDate(WORKING_DATE);
            ui->saMain->horizontalScrollBar()->setValue(x);
    }
}

bool WMainDesk::event(QEvent *e)
{
    switch (e->type()) {
        case QEvent::WindowActivate:
            break;
        case QEvent::WindowDeactivate:
            //fDockHint->hide();
            break;
        default:
            break;
    }
    return BaseWidget::event(e);
}

void WMainDesk::timeout()
{
    if (WORKING_DATE.daysTo(QDate::currentDate()) > 0) {
        ui->btnEndOfDay->setEnabled(true);
    }
}

void WMainDesk::scDateHScroll(int value)
{
    ui->saMain->horizontalScrollBar()->setValue(value);
}

void WMainDesk::scMainHScroll(int value)
{
    ui->saDate->horizontalScrollBar()->setValue(value);
}

void WMainDesk::scRoomVScroll(int value)
{
    ui->saMain->verticalScrollBar()->setValue(value);
}

void WMainDesk::scMainVScroll(int value)
{
    ui->saRoom->verticalScrollBar()->setValue(value);
}

void WMainDesk::catButtonClick()
{
    auto *btn = static_cast<QPushButton *>(sender());
    uncheckCatButtons();
    btn->setChecked(true);
    fCatFilter = btn->text();
    filterRoom();
}

void WMainDesk::roomSelectionChanged(const QModelIndex &m1, const QModelIndex &m2)
{
    Q_UNUSED(m1)
    Q_UNUSED(m2)
    roomsRowSelectionChanged();
}

void WMainDesk::editReserveRoom(const QString &code)
{
    WReservation::openReserveWindows(code);
}

void WMainDesk::daySelectionChanged(const QModelIndex &m1, const QModelIndex &m2)
{
    Q_UNUSED(m1)
    Q_UNUSED(m2)
    daysColumnSelectionChanged();
}

void WMainDesk::reservationCacheUpdated(int cacheId, const QString &id)
{
    if (cacheId != cid_reservation) {
        return;
    }
    fDockHint->reset();
    DoubleDatabase fDD;
    fDD[":state1"] = RESERVE_CHECKIN;
    fDD[":state2"] = RESERVE_RESERVE;
    fDD[":state3"] = RESERVE_SERVICE;
    fDD[":state4"] = RESERVE_OUTOFINVENTORY;
    fDD[":state5"] = RESERVE_OUTOFROOM;
    fDD.exec("select r.f_state, r.f_id, r.f_room, concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName), "
             "r.f_startDate, r.f_endDate, r.f_cardex, n.f_name, '', "
             "r.f_invoice, concat(u.f_firstName, ' ', u.f_lastName), r.f_booking "
             "from f_reservation r  "
             "left join f_guests g on g.f_id=r.f_guest "
             "left join f_nationality n on n.f_short=g.f_nation "
             "left join users u on u.f_id=r.f_author "
             "where (r.f_state=:state1 or r.f_state=:state2 or r.f_state=:state3 or r.f_state=:state4 or r.f_state=:state5) "
             "and r.f_id=" + ap(id) + " "
             "order by 1, 2 ");
    QList<QVariant> v;
    fScene->removeInvalidReserveWidget(id);
    CacheReservation r;
    if (!r.get(id))  {
        return;
    }
    if (fReserveStatus > 0) {
        if (r.fStatus() != fReserveStatus) {
            return;
        }
    }
    if (!fRoomList.contains(r.fRoom())) {
        return;
    }
    switch (r.fState()) {
        case RESERVE_CHECKIN:
        case RESERVE_RESERVE: {
            fScene->addReserveInfo(id);
            break;
        }
        case RESERVE_SERVICE:
        case RESERVE_OUTOFINVENTORY:
        case RESERVE_OUTOFROOM: {
            fScene->addReserveWidget(id);
            break;
        }
    }
}

void WMainDesk::roomCacheUpdated(int cacheId, const QString &id)
{
    Q_UNUSED(cacheId)
    Q_UNUSED(id)
    ui->tblRoom->viewport()->update();
}

void WMainDesk::dockHintVisibilityChanged(bool v)
{
    if (!v) {
        ui->leFilterGuest->clear();
    }
}

void WMainDesk::changeDate()
{
    DlgChartDateRange *d = new DlgChartDateRange(this);
    if (d->exec() == QDialog::Accepted) {
        QDate date;
        d->getResult(date);
    }
    delete d;
}

void WMainDesk::filterRoom()
{
    QElapsedTimer et, tit;
    tit.start();
    et.start();
    qDebug() << "Start filter room";
    int roomStateFilter = -1;
    if (fStateFilter == tr("Vacant ready")) {
        roomStateFilter = ROOM_STATE_NONE;
    } else if (fStateFilter == tr("Checkin")) {
        roomStateFilter = ROOM_STATE_CHECKIN;
    } else if (fStateFilter == tr("Dirty")) {
        roomStateFilter = ROOM_STATE_DIRTY;
    } else if (fStateFilter == tr("O/O")) {
        roomStateFilter = ROOM_STATE_OUTOF;
    }
    fRoomList.clear();
    CacheInstance *c = cache(cid_room);
    QMap<QString, QList<QVariant> > &roomRows = c->fRows;
    CacheInstance *ci = cache(cid_reservation);
    QMap<QString, QList<QVariant> > &reserveRows = ci->fRows;
    CacheRoom room;
    room.fInstance = c;
    QMap<QString, QList<QVariant> >::iterator it = roomRows.begin();
    qDebug() << et.elapsed() << "Cache loaded. Start filter";
    et.restart();
    while (it != roomRows.end()) {
        room.fData = it.value();
        if (!ui->leJumpToRoom->text().isEmpty()) {
            QStringList jumpList = ui->leJumpToRoom->text().split(",", Qt::SkipEmptyParts);
            if (jumpList.contains(room.fCode())) {
                fRoomList.append(room.fCode());
                it++;
                continue;
            } else {
                it++;
                continue;
            }
        }
        if (roomStateFilter > -1) {
            if (room.fState() != roomStateFilter) {
                it++;
                continue;
            }
        }
        if (fCatFilter.length() > 0) {
            if (room.fCategoryShort() != fCatFilter) {
                it++;
                continue;
            }
        }
        if (fBedFilter.length() > 0) {
            if (room.fBed() != fBedFilter) {
                it++;
                continue;
            }
        }
        if (fSmokeFilter.length() > 0) {
            if (fSmokeFilter == tr("Yes")) {
                if (room.fSmoke() == 0) {
                    it++;
                    continue;
                }
            } else {
                if (room.fSmoke() == 1) {
                    it++;
                    continue;
                }
            }
        }
        if (fBuildingFilter.length() > 0) {
            if (room.fBuilding() != fBuildingFilter.toInt()) {
                it++;
                continue;
            }
        }
        fRoomList.append(room.fCode());
        it++;
    }
    qDebug() << et.elapsed() << "End filter. Init background";
    et.restart();
    DoubleDatabase ddr;
    ddr.exec("select f_id from f_room order by f_building, f_id");
    QStringList tmpRoom = fRoomList;
    fRoomList.clear();
    while (ddr.nextRow()) {
        if (tmpRoom.contains(ddr.getString(0))) {
            fRoomList << ddr.getString(0);
        }
    }
    ui->lbRoomsCount->setText(QString("Rooms: %1").arg(fRoomList.count()));
    fScene->initBackgroung(fDateStart.daysTo(fDateEnd) + 1, fRoomList);
    qDebug() << et.elapsed() << "End init background. Init rooms";
    et.restart();
    ui->tblRoom->clear();
    ui->tblRoom->setRowCount(fRoomList.count());
    ui->tblRoom->setColumnCount(1);
    for (int i = 0, count = fRoomList.count(); i < count; i++) {
        C5TableWidgetItem *item = new C5TableWidgetItem();
        item->setData(Qt::UserRole, fRoomList.at(i));
        ui->tblRoom->setItem(i, 0, item);
    }
    int minimumHeight = ui->saRoom->height();
    int height = fRoomList.count() * ROW_HEIGHT;
    minimumHeight = minimumHeight < height ? height : minimumHeight;
    ui->tblRoom->setMinimumHeight(minimumHeight);
    ui->tblRoom->setMaximumHeight(minimumHeight);
    //ui->saMain->verticalScrollBar()->setValue(0);
    ui->g->setMinimumHeight(minimumHeight);
    ui->g->setMaximumHeight(minimumHeight);
    qDebug() << et.elapsed() << "End init rooms. Add reservations to chart";
    et.restart();
    int totalr = 0;
    it = reserveRows.begin();
    while (it != reserveRows.end()) {
        if (fReserveStatus > 0) {
            if (it->at(pos_status).toInt() != fReserveStatus) {
                it++;
                continue;
            }
        }
        if (!fFilterCardex.isEmpty()) {
            if (!it->at(pos_cardex).toString().contains(fFilterCardex, Qt::CaseInsensitive)) {
                it++;
                continue;
            }
        }
        if (!fRoomList.contains(it->at(pos_room).toString())) {
            it++;
            continue;
        }
        totalr ++;
        switch (it->at(pos_state).toInt()) {
            case RESERVE_CHECKIN:
            case RESERVE_RESERVE: {
                fScene->addReserveInfo(it->at(pos_id).toString());
                break;
            }
            case RESERVE_SERVICE:
            case RESERVE_OUTOFINVENTORY:
            case RESERVE_OUTOFROOM: {
                fScene->addReserveWidget(it->at(pos_id).toString());
                break;
            }
        }
        it++;
    }
    qDebug() << totalr << et.elapsed() << tit.elapsed() << "All done. Start working";
    et.restart();
}

void WMainDesk::dockHint(const QString &filter)
{
    fDockHint->setWindowTitle(tr("Search for:") + " \"" + filter + "\"");
    fDockHint->commonFilter(filter);
    fDockHint->show();
    fDockHint->raise();
}

int WMainDesk::xFromDate(const QDate &date)
{
    int dayCount = fDateStart.daysTo(date);
    return dayCount *COLUMN_WIDTH;
}

void WMainDesk::roomsRowSelectionChanged()
{
    QModelIndexList indexes = ui->tblRoom->selectionModel()->selectedIndexes();
    QSet<int> selectedRows;
    for (QModelIndexList::const_iterator it = indexes.begin(); it != indexes.end(); it++) {
        selectedRows.insert(it->row());
    }
    fScene->rowsSelect(selectedRows);
}

void WMainDesk::daysColumnSelectionChanged()
{
    QModelIndexList indexes = ui->tblDay->selectionModel()->selectedIndexes();
    QSet<int> selectedColumns;
    for (QModelIndexList::const_iterator it = indexes.begin(); it != indexes.end(); it++) {
        selectedColumns.insert(it->column());
    }
    fScene->columnsSelect(selectedColumns);
}

void WMainDesk::on_btnClearFilter_clicked()
{
    ui->leJumpToRoom->clear();
    fCatFilter.clear();
    fBedFilter.clear();
    fSmokeFilter.clear();
    fStateFilter.clear();
    ui->btnFilterCategory->setText(QString("%1: %2").arg(tr("Category filter")).arg(tr("All")));
    ui->btnBedFilter->setText(QString("%1: %2").arg(tr("Bed filter")).arg(tr("All")));
    ui->btnSmokeFilter->setText(QString("%1: %2").arg(tr("Smoke filter")).arg(tr("All")));
    ui->btnRoomStateFilter->setText(QString("%1: %2").arg(tr("Room state filter")).arg(tr("All")));
    ui->leFilterGuest->clear();
    ui->tblRoom->selectionModel()->clear();
    ui->tblDay->selectionModel()->clear();
    fDockHint->hide();
    fReserveStatus = 0;
    fFilterCardex = "";
    ui->btnStatus->setText(tr("Status"));
    filterRoom();
}

void WMainDesk::on_btnScrollRight_clicked()
{
    ui->saMain->horizontalScrollBar()->setValue(ui->saMain->horizontalScrollBar()->value() + 200);
}

void WMainDesk::on_btnScrollLeft_clicked()
{
    ui->saMain->horizontalScrollBar()->setValue(ui->saMain->horizontalScrollBar()->value() - 200);
}

void WMainDesk::on_btnCheckIn_clicked()
{
    QList<CacheRoom *> rooms;
    rooms.append(nullptr);
    addTab<WReservation>()->setInitialParams(WORKING_DATE, WORKING_DATE, rooms);
}

void WMainDesk::on_btnClearSelection_clicked()
{
    if (message_confirm(tr("Are sure to delete draft reservations")) == QDialog::Accepted) {
        fScene->clearReserveWidgets();
    }
}

void WMainDesk::on_btnGroupReservation_clicked()
{
    addTab<DlgGroupReservationFuck>();
}

void WMainDesk::on_btnScrollDown_clicked()
{
    ui->saMain->verticalScrollBar()->setValue(ui->saMain->verticalScrollBar()->value() + 200);
}

void WMainDesk::on_btnScrollUp_clicked()
{
    ui->saMain->verticalScrollBar()->setValue(ui->saMain->verticalScrollBar()->value() - 200);
}

void WMainDesk::on_btnEndOfDay_clicked()
{
    DlgEndOfDay *d = new DlgEndOfDay(this);
    if (d->exec() == QDialog::Accepted)  {
    }
    delete d;
}

void WMainDesk::on_btnCheckin_clicked()
{
    fDockHint->checkInFilter();
    fDockHint->show();
    fDockHint->raise();
}

void WMainDesk::on_btnShowDockHint_clicked()
{
    if (!fDockHint->isVisible() || !fDockHint->hasFocus()) {
        dockHint("");
    }
}

void WMainDesk::on_btnJumpToDate_clicked()
{
    DlgChartDateRange *d = new DlgChartDateRange(this);
    if (d->exec() == QDialog::Accepted) {
        QDate date;
        d->getResult(date);
        int x = xFromDate(date);
        ui->saMain->horizontalScrollBar()->setValue(x);
    }
    delete d;
}

void WMainDesk::on_tblRoom_clicked(const QModelIndex &index)
{
    Q_UNUSED(index)
    roomsRowSelectionChanged();
}

void WMainDesk::on_tblDay_clicked(const QModelIndex &index)
{
    Q_UNUSED(index)
    daysColumnSelectionChanged();
}

void WMainDesk::on_btnCheckoutFilter_clicked()
{
    fDockHint->checkOutFilter();
    fDockHint->show();
    fDockHint->raise();
}

void WMainDesk::on_leJumpToRoom_editingFinished()
{
    filterRoom();
}

void WMainDesk::on_tblRoom_doubleClicked(const QModelIndex &index)
{
    if (!r__(cr__room_status_change)) {
        message_error(tr("Access denied"));
        return;
    }
    if (!index.isValid()) {
        return;
    }
    if (index.data(Qt::UserRole + 1).toInt() == ROOM_STATE_CHECKIN) {
        message_info(tr("Changing the state of the room is not available in this case"));
        return;
    }
    RoomState *rs = new RoomState(this);
    rs->setRoom(index.data(Qt::UserRole).toString());
    if (rs->exec() == QDialog::Accepted) {
        //Get changes from r
        ui->tblRoom->viewport()->update();
    }
    delete rs;
}

void WMainDesk::on_btnInvoice_clicked()
{
    addTab<WInvoice>();
}

void WMainDesk::on_btnPostCharge_clicked()
{
    auto *d = new DlgPostCharge(this);
    d->exec();
    delete d;
}

void WMainDesk::on_btnTransferRoom_clicked()
{
    DlgTransferAnyAmount *d = new DlgTransferAnyAmount(this);
    d->exec();
    delete d;
}

void WMainDesk::on_btnAirReserve_clicked()
{
    fDockHint->airFilter();
    fDockHint->show();
    fDockHint->raise();
}

void WMainDesk::on_leFilterGuest_textEdited(const QString &arg1)
{
    if (arg1.length() == 0) {
        fDockHint->hide();
    } else {
        dockHint(arg1);
    }
}

void WMainDesk::on_btnStatus_clicked()
{
    DlgReserveConfirmStatus *d = new DlgReserveConfirmStatus(this);
    int result = d->exec();
    delete d;
    if (result > 0) {
        fReserveStatus = result;
        switch (fReserveStatus) {
            case CONFIRM_BLOCK:
                ui->btnStatus->setText(tr("Block"));
                break;
            case CONFIRM_CONFIRM:
                ui->btnStatus->setText(tr("Confirm"));
                break;
            case CONFIRM_GUARANTEED:
                ui->btnStatus->setText(tr("Guaranted"));
                break;
            case CONFIRM_TENTATIVE:
                ui->btnStatus->setText(tr("Tentative"));
                break;
            case CONFIRM_WAITING:
                ui->btnStatus->setText(tr("Waiting"));
                break;
            default:
                ui->btnStatus->setText(tr("Status"));
                break;
        }
        filterRoom();
    }
}

void WMainDesk::on_btnFilterCardex_clicked()
{
    fFilterCardex = cache(cid_reservation_cardex)->get("");
    filterRoom();
}

void WMainDesk::on_btnColors_clicked()
{
    DlgChartColor *d = new DlgChartColor(this);
    d->exec();
    delete d;
}

void WMainDesk::on_btnRefreshChart_clicked()
{
    CacheOne::clearAll();
    connect(cache(cid_reservation), SIGNAL(updated(int, QString)), this, SLOT(reservationCacheUpdated(int, QString)));
    connect(cache(cid_room), SIGNAL(updated(int, QString)), this, SLOT(roomCacheUpdated(int, QString)));
    on_btnClearFilter_clicked();
}

void WMainDesk::on_btnFilterCategory_clicked()
{
    fCatFilter.clear();
    uncheckCatButtons();
    filterRoom();
}

void WMainDesk::on_btnBedFilter_clicked()
{
    if  (WMainDeskFilterList::filter(fBedList, fBedListNames, tr("Bed"), fBedFilter)) {
        ui->btnBedFilter->setText(QString("%1: %2").arg(tr("Bed filter")).arg(fBedFilter.isEmpty() ? tr("All") : fBedFilter));
        qApp->processEvents();
        filterRoom();
    }
}

void WMainDesk::on_btnSmokeFilter_clicked()
{
    if  (WMainDeskFilterList::filter(fSmokeList, fSmokeListNames, tr("Smoke"), fSmokeFilter)) {
        ui->btnSmokeFilter->setText(QString("%1: %2").arg(tr("Smoke filter")).arg(fSmokeFilter.isEmpty() ? tr("All") :
                                    fSmokeFilter));
        qApp->processEvents();
        filterRoom();
    }
}

void WMainDesk::on_btnRoomStateFilter_clicked()
{
    if  (WMainDeskFilterList::filter(fStateList, fStateListNames, tr("Room state"), fStateFilter)) {
        ui->btnRoomStateFilter->setText(QString("%1: %2").arg(tr("Room state filter")).arg(fStateFilter.isEmpty() ? tr("All") :
                                        fStateFilter));
        qApp->processEvents();
        filterRoom();
    }
}

void WMainDesk::uncheckCatButtons()
{
    QObjectList ol = ui->wCatButtons->children();
    for (QObject *o : ol) {
        QPushButton *b = dynamic_cast<QPushButton *>(o);
        if (b) {
            b->setChecked(false);
        }
    }
}

void WMainDesk::on_btnBuilding_clicked()
{
    if  (WMainDeskFilterList::filter(fBuildingList, fBuildingListNames, tr("Building"), fBuildingFilter)) {
        ui->btnBuilding->setText(QString("%1: %2").arg(tr("Building filter")).arg(fBuildingFilter.isEmpty() ? tr("All") :
                                 fBuildingFilter));
        qApp->processEvents();
        filterRoom();
    }
}
