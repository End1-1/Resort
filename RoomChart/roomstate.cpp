#include "roomstate.h"
#include "ui_roomstate.h"
#include "vauchers.h"
#include "cachereservation.h"
#include "paymentmode.h"
#include "cacheroomstate.h"

#define HINT_ROOM_STATE 1

RoomState::RoomState(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::RoomState)
{
    ui->setupUi(this);
    ui->wdtOut->setVisible(false);
    ui->leNewState->setSelector(this, cache(cid_room_state), ui->leNewStateName, HINT_ROOM_STATE);
    fTrackControl = new TrackControl(TRACK_ROOM_STATE);
    adjustSize();
}

RoomState::~RoomState()
{
    delete ui;
}

void RoomState::callback(int sel, const QString &code)
{
    switch (sel) {
    case HINT_ROOM_STATE: {
        CacheRoomState c;
        if (c.get(code)) {
            switch (c.fCode().toInt()) {
            case ROOM_STATE_DIRTY:
            case ROOM_STATE_NONE:
                break;
            case ROOM_STATE_OUTOF:
                ui->wdtOut->setVisible(true);
                adjustSize();
                break;
            default:
                ui->leNewState->clear();
                ui->leNewStateName->clear();
                message_error(tr("This state is not available now"));
                break;
            }
        }
        break;
    }
    }
}

void RoomState::setRoom(const QString &code)
{
    if (!fRoom.get(code)) {
        return;
    }
    ui->leRoomCode->setText(fRoom.fCode());
    ui->leRoomName->setText(fRoom.fName());
    ui->leCurrentState->setInt(fRoom.fState());
    CacheRoomState crs;
    crs.get(fRoom.fState());
    ui->leCurrentStateName->setText(crs.fName());
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_room"] = fRoom.fCode();
    fDD.exec("select count(f_id) as c , sum(f_state) as s from f_room_inventory_journal where f_room=:f_room");
    if (fDD.nextRow()) {
        if (fDD.getInt("c") == fDD.getInt("s")) {
            ui->lbStatus->setPixmap(QPixmap(":/images/ball-green.png"));
        } else {
            ui->lbStatus->setPixmap(QPixmap(":/images/ball-red.png"));
        }
    }
}

void RoomState::on_btnCancel_clicked()
{
    reject();
}

void RoomState::on_btnOk_clicked()
{
    if (ui->leNewState->text().isEmpty()) {
        message_error(tr("Select the new state for room"));
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    QString add = ui->leRoomCode->text();
    if (ui->leNewState->asInt() == ROOM_STATE_OUTOF) {
        QString fId;
        QString invId = uuid(VAUCHER_INVOICE_N);
        add += QString(" %1 - %2")
                .arg(ui->deStart->text(), ui->deEnd->text());
        fDD[":f_state"] = RESERVE_OUTOFROOM;
        fDD[":f_reserveState"] = CONFIRM_BLOCK;
        fDD[":f_room"] = fRoom.fCode();
        fDD[":f_roomFee"] = fRoom.fPrice();
        fDD[":f_arrangement"] = 0;
        fDD[":f_paymentType"] = PAYMENT_CASH;
        fDD[":f_man"] = 1;
        fDD[":f_mealIncluded"] = 1;
        fDD[":f_cardex"] = fPreferences.getDb(def_default_cardex);
        fDD[":f_startDate"] = ui->deStart->date();
        fDD[":f_endDate"] = ui->deEnd->date();
        fDD[":f_author"] = WORKING_USERID;
        fDD[":f_invoice"] = invId;
        fDD[":f_remarks"] = ui->teRemarks->toPlainText();
        fId = uuid("RS");
        fDD.insertId("f_reservation", fId);
        fDD[":f_id"] = fId;
        fDD.update("f_reservation", where_id(ap(fId)));

        fTrackControl = new TrackControl(TRACK_RESERVATION);
        fTrackControl->insert("-=CREATED OUTOFORDER=-", QString("%1 - %2")
                                  .arg(ui->deStart->text())
                                  .arg(ui->deEnd->text()), "");
        BroadcastThread::cmdRefreshCache(cid_reservation, fId);
        if (ui->deStart->date() == WORKING_DATE) {
            fDD[":f_id"] = ui->leRoomCode->text();
            fDD[":f_state"] = ui->leNewState->text();
            fDD.exec("update f_room set f_state=:f_state where f_id=:f_id");
            //fRoom.fState() = ui->leNewState->asInt();
        }
    } else {
        if (ui->lbOO->text() != "OK") {
            message_error(tr("Invalid date range"));
            return;
        }
        if (ui->leCurrentState->asInt() == ROOM_STATE_OUTOF) {
            fDD[":f_room"] = ui->leRoomCode->asInt();
            fDD[":f_date"] = WORKING_DATE;
            fDD[":f_state"] = RESERVE_OUTOFROOM;
            fDD.exec("select f_id from f_reservation where f_room=:f_room "
                       "and :f_date>=f_startDate and :f_date<=f_endDate and f_state=:f_state");
            if (fDD.nextRow()) {
                fDD[":f_state"] = RESERVE_SERVICE_REMOVED;
                fDD.update("f_reservation", where_id(ap(fDD.getString(0))));
                BroadcastThread::cmdRefreshCache(cid_reservation, fDD.getString(0));
            }
        } else {

        }
        fDD[":f_id"] = ui->leRoomCode->text();
        fDD[":f_state"] = ui->leNewState->text();
        fDD.exec("update f_room set f_state=:f_state where f_id=:f_id");
       // fRoom.fState() = ui->leNewState->asInt();
    }
    fDD[":f_date"] = QDate::currentDate();
    fDD[":f_wdate"] = WORKING_DATE;
    fDD[":f_time"] = QTime::currentTime();
    fDD[":f_oldState"] = ui->leCurrentState->asInt();
    fDD[":f_newState"] = ui->leNewState->asInt();
    fDD[":f_user"] = WORKING_USERID;
    fDD[":f_comment"] = ui->teRemarks->toPlainText();
    fDD.insert("f_room_state_change");
    fTrackControl->insert("Room state changed", ui->leCurrentStateName->text(), ui->leNewStateName->text() + add);
    BroadcastThread::cmdRefreshCache(cid_room, ui->leRoomCode->text());
    accept();
}

void RoomState::on_deStart_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    checkOO();
}

void RoomState::on_deEnd_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    checkOO();
}

void RoomState::checkOO()
{
    CacheReservation c;
    QMap<QString, CacheReservation> out;
    bool startOk = true;
    bool endOk = true;
    c.check(ui->deStart->date(), ui->deEnd->date(), ui->leRoomCode->asInt(), out, startOk, endOk, "");
    if (!startOk || !endOk) {
        ui->lbOO->setText("NO");
    } else {
        ui->lbOO->setText("OK");
    }
}