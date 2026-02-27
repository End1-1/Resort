#include "dlgquickroomassignment.h"
#include "cacheactiveroom.h"
#include "cachereservation.h"
#include "cacheroom.h"
#include "ui_dlgquickroomassignment.h"
#include "wreservationroomtab.h"

#define HINT_ACTIVE_ROOM 1
#define HINT_ROOM 2

DlgQuickRoomAssignment::DlgQuickRoomAssignment(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgQuickRoomAssignment)
{
    ui->setupUi(this);
    ui->lefrRoom->setSelector(this, cache(cid_active_room), nullptr, HINT_ACTIVE_ROOM);
    ui->letoRoom->setSelector(this, cache(cid_room), nullptr, HINT_ROOM);
}

DlgQuickRoomAssignment::~DlgQuickRoomAssignment()
{
    delete ui;
}

void DlgQuickRoomAssignment::callback(int selectorNumber, const QString &value)
{
    switch (selectorNumber) {
    case HINT_ACTIVE_ROOM: {
        CacheActiveRoom ci;
        if (ci.get(value)) {
            ui->lefrGuest->setText(ci.fGuestName());
            ui->deEntry->setDate(ci.fEntry());
            ui->deDeparture->setDate(ci.fDeparture());
            ui->leReserve->setText(ci.fCode());
            ui->leInvoice->setText(ci.fInvoice());
            ui->lbfr->setPixmap(QPixmap(":/images/ok.png"));
        } else {
            ui->lbfr->setPixmap(QPixmap(":/images/remarks.png"));
        }
        break;
    }
    case HINT_ROOM: {
        fError.clear();
        if (WReservationRoomTab::check(ui->letoRoom->asInt(), ui->deEntry->date(), ui->deDeparture->date(), ui->leReserve->text(), fError)) {
            ui->lbto->setPixmap(QPixmap(":/images/ok.png"));
            fError.clear();
        } else {
            ui->lbto->setPixmap(QPixmap(":/images/remarks.png"));
        }
        break;
    }
    }
}

void DlgQuickRoomAssignment::on_btnCancel_clicked()
{
    reject();
}

void DlgQuickRoomAssignment::on_btnSave_clicked()
{
    QString err = fError;
    if (ui->lefrRoom->asInt() == 0) {
        err += tr("Room from is empty") + "<br>";
    }
    if (ui->letoRoom->asInt() == 0) {
        err += tr("Room to is empty") + "<br>";
    }
    fError.clear();
    if (!WReservationRoomTab::check(ui->letoRoom->asInt(), ui->deEntry->date(), ui->deDeparture->date(), ui->leReserve->text(), fError)) {
        ui->lbto->setPixmap(QPixmap(":/images/remarks.png"));
    }
    if (!err.isEmpty()) {
        message_error(err);
        return;
    }
    DoubleDatabase dd;
    dd[":f_state"] = ROOM_STATE_DIRTY;
    dd.update("f_room", where_id(ui->lefrRoom->asInt()));
    dd[":f_room"] = ui->letoRoom->asInt();
    dd.update("f_reservation", where_id(ap(ui->leReserve->text())));
    dd[":f_state"] = ROOM_STATE_CHECKIN;
    dd.update("f_room", where_id(ui->letoRoom->asInt()));
    dd[":f_room"] = ui->letoRoom->asInt();
    dd.update("m_register", where_id(ap(ui->leReserve->text())));
    BroadcastThread::cmdRefreshCache(cid_reservation, ui->leReserve->text());
    BroadcastThread::cmdRefreshCache(cid_room, ui->lefrRoom->text());
    BroadcastThread::cmdRefreshCache(cid_room, ui->letoRoom->text());
    BroadcastThread::cmdRefreshCache(cid_active_room, ui->lefrRoom->text());
    BroadcastThread::cmdRefreshCache(cid_active_room, ui->letoRoom->text());
    TrackControl tc(TRACK_RESERVATION);
    tc.fReservation = ui->leReserve->text();
    tc.fInvoice = ui->leInvoice->text();
    tc.insert("Quick room assignment", ui->lefrRoom->text(), ui->letoRoom->text());
    message_info(tr("Room moved"));
}
