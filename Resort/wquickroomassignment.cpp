#include "wquickroomassignment.h"
#include "ui_wquickroomassignment.h"
#include "wreservationroomtab.h"
#include "dbmregister.h"
#include "cacheroom.h"
#include "vauchers.h"
#include "cacheredreservation.h"
#include "cachereservationcardex.h"
#include "cachereservation.h"
#include "cacheactiveroom.h"
#include "dlgsimpleselectroom.h"
#include "wreservation.h"

WQuickRoomAssignment::WQuickRoomAssignment(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WQuickRoomAssignment)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tbl, ui->tbl->columnCount(), 80, 80, 100, 100, 300, 200, 0, 50);
}

WQuickRoomAssignment::~WQuickRoomAssignment()
{
    delete ui;
}

void WQuickRoomAssignment::setupTab()
{
    setupTabTextAndIcon(tr("Room assignment"), ":/images/storehouse.png");
}

void WQuickRoomAssignment::showRooms()
{
    int row, col;
    if (!ui->tbl->findWidgetCell(static_cast<QWidget*>(sender()), row, col)) {
        return;
    }
    DlgSimpleSelectRoom *d = new DlgSimpleSelectRoom(this);
    d->show();
    d->hide();
    d->fSingleSelection = true;
    if (d->getRoom("", QDate::fromString(ui->tbl->toString(row, 2), def_date_format), QDate::fromString(ui->tbl->toString(row, 3), def_date_format), QStringList(), "", true) == QDialog::Accepted) {
        QStringList rooms;
        d->getRoomsList(rooms);
        if (rooms.count() > 0) {
            ui->tbl->lineEdit(row, 1)->setText(rooms.at(0));
        }
    }
    delete d;
}

void WQuickRoomAssignment::tblLineEditTextChanged(const QString &text)
{
    EQLineEdit *l = static_cast<EQLineEdit*>(sender());
    int row = l->fRow;
    CacheRoom cr;
    if (!cr.get(text)) {
        ui->tbl->setItemWithValue(row, 5, "INVALID ROOM");
        return;
    }
    if (text.length() < 3) {
        return;
    }
    if (text == ui->tbl->toString(row, 1)) {
        ui->tbl->setItemWithValue(row, 5, "");
        return;
    }
    QString err;
    if (WReservationRoomTab::check(l->asInt(), QDate::fromString(ui->tbl->toString(row, 2), def_date_format), QDate::fromString(ui->tbl->toString(row, 3), def_date_format), ui->tbl->toString(row, 0), err)) {
        ui->tbl->setItemWithValue(row, 5, "OK");
    } else {
        ui->tbl->setItemWithValue(row, 5, err);
    }
}

void WQuickRoomAssignment::on_btnRefresh_clicked()
{
    ui->tbl->clearContents();
    ui->tbl->setRowCount(0);
    QString sql = "select r.f_id, r.f_room, r.f_startdate, r.f_enddate, g.guest, f_invoice "
            "from f_reservation r "
            "left join guests g on g.f_id=r.f_guest "
            "where r.f_state=2 and :date0 between :date1 and :date2 "
            "order by r.f_room, r.f_startdate ";
    if (ui->rbEntry->isChecked()) {
        sql.replace(":date0", "r.f_startdate");
    } else {
        sql.replace(":date0", "r.f_enddate");
    }
    sql.replace(":date1", ui->deStart->dateMySql());
    sql.replace(":date2", ui->deEnd->dateMySql());
    DoubleDatabase dd;
    dd.exec(sql);
    while (dd.nextRow()) {
        int row = ui->tbl->addRow();
        ui->tbl->setItemWithValue(row, 0, dd.getString("f_id"));
        ui->tbl->setItemWithValue(row, 1, dd.getInt("f_room"));
        ui->tbl->setItemWithValue(row, 2, dd.getDate("f_startdate"));
        ui->tbl->setItemWithValue(row, 3, dd.getDate("f_enddate"));
        ui->tbl->setItemWithValue(row, 4, dd.getString("guest"));
        ui->tbl->setItemWithValue(row, 5, "");
        ui->tbl->setItemWithValue(row, 6, dd.getString("f_invoice"));
        ui->tbl->addButton(row, 7, SLOT(showRooms()), this, QIcon(":/images/bedroom.png"));
        EQLineEdit *l = ui->tbl->addLineEdit(row, 1, false);
        l->setInt(dd.getInt("f_room"));
        connect(l, SIGNAL(textChanged(QString)), this, SLOT(tblLineEditTextChanged(QString)));
    }
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        if (ui->tbl->toString(i, 5) == "INVALID ROOM" && ui->tbl->lineEdit(i, 1)->asInt() == 0) {
            continue;
        }
        QString err;
        QString id = ui->tbl->toString(i, 0);
        EQLineEdit *l = ui->tbl->lineEdit(i, 1);
        if (WReservationRoomTab::check(l->asInt(), QDate::fromString(ui->tbl->toString(i, 2), def_date_format), QDate::fromString(ui->tbl->toString(i, 3), def_date_format), ui->tbl->toString(i, 0), err)) {
            ui->tbl->setItemWithValue(i, 5, "OK");
        } else {
            ui->tbl->setItemWithValue(i, 5, err);
            continue;
        }
    }
}

void WQuickRoomAssignment::on_btnSave_clicked()
{
    DoubleDatabase dd;
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        if (ui->tbl->toString(i, 5) == "INVALID ROOM" && ui->tbl->lineEdit(i, 1)->asInt() != 0) {
            continue;
        }
        QString err;
        QString id = ui->tbl->toString(i, 0);
        EQLineEdit *l = ui->tbl->lineEdit(i, 1);
        if (l->text() == ui->tbl->toString(i, 1)) {
            continue;
        }
        if (WReservationRoomTab::check(l->asInt(), QDate::fromString(ui->tbl->toString(i, 2), def_date_format), QDate::fromString(ui->tbl->toString(i, 3), def_date_format), ui->tbl->toString(i, 0), err)) {
            ui->tbl->setItemWithValue(i, 5, "OK");
        } else {
            ui->tbl->setItemWithValue(i, 5, err);
            continue;
        }
        dd[":f_room"] = l->asInt();
        dd.update("f_reservation", where_id(ap(id)));
        BroadcastThread::cmdRefreshCache(cid_reservation, id);
        BroadcastThread::cmdRefreshCache(cid_room, l->text());
        BroadcastThread::cmdRefreshCache(cid_red_reservation, id);
        BroadcastThread::cmdRefreshCache(cid_reservation_cardex, id);
        BroadcastThread::cmdRefreshCache(cid_room, ui->tbl->toString(i, 1));
        TrackControl tc(TRACK_RESERVATION);
        tc.fReservation = ui->tbl->toString(i, 0);
        tc.fInvoice = ui->tbl->toString(i, 6);
        tc.insert("Room moved", ui->tbl->toString(i, 1), l->text());
    }
    on_btnRefresh_clicked();
    message_info(tr("Saved"));
}

void WQuickRoomAssignment::on_tbl_doubleClicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    WReservation::openReserveWindows(ui->tbl->toString(index.row(), 0));
}
