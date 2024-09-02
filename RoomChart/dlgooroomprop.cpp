#include "dlgooroomprop.h"
#include "ui_dlgooroomprop.h"
#include "cacheroom.h"

DlgOORoomProp::DlgOORoomProp(const QString &code, QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgOORoomProp)
{
    ui->setupUi(this);
    fReservation.get(code);
    ui->leReserve->setText(fReservation.fId());
    ui->leRoom->setText(fReservation.fRoom());
    ui->teRemarks->setPlainText(fReservation.fRemarks());
    ui->deStart->setDate(fReservation.fDateStart());
    ui->deEnd->setDate(fReservation.fDateEnd());
    fTrackControl = new TrackControl(TRACK_ROOM_STATE);
}

DlgOORoomProp::~DlgOORoomProp()
{
    delete ui;
}

void DlgOORoomProp::on_btnCancel_clicked()
{
    reject();
}

void DlgOORoomProp::on_btnOk_clicked()
{
    if (ui->lbOO->text() != "OK") {
        message_error(tr("Invalid date range"));
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_startDate"] = ui->deStart->date();
    fDD[":f_endDate"] = ui->deEnd->date();
    fDD[":f_remarks"] = ui->teRemarks->toPlainText();
    fDD.update("f_reservation", where_id(ap(ui->leReserve->text())));
    accept();
    QString range = QString(" %1 - %2, %3")
            .arg(ui->deStart->text())
            .arg(ui->deEnd->text())
            .arg(ui->teRemarks->toPlainText());
    if (ui->deStart->date() <= WORKING_DATE) {
        fDD[":f_id"] = ui->leRoom->text();
        fDD[":f_state"] = ROOM_STATE_OUTOF;
        fDD.exec("update f_room set f_state=:f_state where f_id=:f_id");
        fTrackControl->insert("O/O modification", "?" , "OO");
        BroadcastThread::cmdRefreshCache(cid_room, ui->leRoom->text());
    }
    if (fReservation.fDateStart() <= WORKING_DATE && ui->deStart->date() > WORKING_DATE) {
        fDD[":f_id"] = ui->leRoom->text();
        fDD[":f_state"] = ROOM_STATE_NONE;
        fDD.exec("update f_room set f_state=:f_state where f_id=:f_id");
        fTrackControl->insert("O/O modification", "OO" , "VR");
        BroadcastThread::cmdRefreshCache(cid_room, ui->leRoom->text());
    }
    fTrackControl->insert("O/O modification", ui->leRoom->text() , range);
    BroadcastThread::cmdRefreshCache(cid_reservation, ui->leReserve->text());
}

void DlgOORoomProp::on_deEnd_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    checkOO();
}

void DlgOORoomProp::on_deStart_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    checkOO();
}

void DlgOORoomProp::checkOO()
{
    QMap<QString, CacheReservation> out;
    bool startOk = true;
    bool endOk = true;
    CacheReservation cr;
    cr.check(ui->deStart->date(), ui->deEnd->date(), ui->leRoom->asInt(), out, startOk, endOk, fReservation.fId());
    if (!startOk || !endOk) {
        ui->lbOO->setText("NO");
    } else {
        ui->lbOO->setText("OK");
    }
}

void DlgOORoomProp::on_btmRemove_clicked()
{
    if (message_confirm(tr("Confirm to remove")) != QDialog::Accepted) {
        return;
    }
    accept();
    QString range = QString(" %1 - %2, %3")
            .arg(ui->deStart->text())
            .arg(ui->deEnd->text())
            .arg(ui->teRemarks->toPlainText());
    fTrackControl->insert("O/O removed", ui->leRoom->text() , range);
    DoubleDatabase fDD;
    fDD[":f_state"] = RESERVE_REMOVED;
    fDD.update("f_reservation", where_id(ap(ui->leReserve->text())));
    if (fReservation.fDateStart() <= WORKING_DATE) {
        fDD[":f_state"] = ROOM_STATE_DIRTY;
        fDD.update("f_room", where_id(ui->leRoom->asInt()));
        BroadcastThread::cmdRefreshCache(cid_room, ui->leRoom->text());
    }
    BroadcastThread::cmdRefreshCache(cid_reservation, ui->leReserve->text());
}
