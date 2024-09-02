#include "dlgroom.h"
#include "ui_dlgroom.h"
#include "cachebed.h"
#include "cacheroomcategory.h"
#include "cacheroom.h"
#include "cacheroomview.h"

DlgRoom::DlgRoom(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_ROOM, parent),
    ui(new Ui::DlgRoom)
{
    ui->setupUi(this);
    ui->leBedCode->setSelector(this, cache(cid_bed), ui->leBedName);
    ui->leClassCode->setSelector(this, cache(cid_room_category), ui->leClassName);
    ui->leViewCode->setSelector(this, cache(cid_room_view), ui->leViewName);
    ui->btnOK->setText(tr("New"));
    addWidget(ui->leCode, "Code")
    .addWidget(ui->leClassCode, "Class code")
    .addWidget(ui->leClassName, "Class name")
    .addWidget(ui->leViewCode, "View code")
    .addWidget(ui->leViewName, "View name")
    .addWidget(ui->leFloor, "Floor")
    .addWidget(ui->leBuild, "Build")
    .addWidget(ui->leShortName, "Shortname")
    .addWidget(ui->leDescription, "Description")
    .addWidget(ui->leRate, "Room rate")
    .addWidget(ui->leBedCode, "Bed code")
    .addWidget(ui->leBedName, "Bed name")
    .addWidget(ui->leQty, "Qty")
    .addWidget(ui->leQueue, "Queue")
    .addWidget(ui->chSmoking, "Smoking")
    .addWidget(ui->lePhone, "Phone");
}

DlgRoom::~DlgRoom()
{
    delete ui;
}

void DlgRoom::setValues()
{
    ui->leCode->clear();
    ui->leClassCode->clear();
    ui->leClassName->clear();
    ui->leViewCode->clear();
    ui->leViewName->clear();
    ui->leFloor->clear();
    ui->leShortName->clear();
    ui->leDescription->clear();
    ui->leRate->clear();
    ui->leBedCode->clear();
    ui->leBedName->clear();
    ui->leBuild->clear();
    ui->leQty->clear();
    ui->leQueue->clear();
    ui->chSmoking->setChecked(false);
    ui->lePhone->clear();
    if (fValues.count() > 0) {
        valuesToWidgets();
        ui->btnOK->setText(tr("Edit"));
        isNew = false;
    } else {
        fTrackControl->resetChanges();
    }
}

void DlgRoom::on_btnCancel_clicked()
{
    reject();
}

void DlgRoom::on_btnOK_clicked()
{
    QString err;
    if (ui->leCode->isEmpty()) {
        err += tr("Room code is missing");
    }
    if (!err.isEmpty()) {
        message_error(err);
        return;
    }
    DoubleDatabase fDD;
    if (fTrackControl->oldValue(ui->leCode) != ui->leCode->text()) {
        fDD[":f_id"] = ui->leCode->text();
        fDD.exec("select * from f_room where f_id=:f_id");
        if (fDD.nextRow()) {
            message_error(tr("Duplicate room code."));
            return;
        }
    }
    fDD[":f_id"] = ui->leCode->text();
    fDD[":f_class"] = ui->leClassCode->text();
    fDD[":f_view"] = ui->leViewCode->text();
    fDD[":f_floor"] = ui->leFloor->text();
    fDD[":f_building"] = ui->leBuild->text();
    fDD[":f_short"] = ui->leShortName->text();
    fDD[":f_description"] = ui->leDescription->text();
    fDD[":f_rate"] = ui->leRate->text();
    fDD[":f_bed"] = ui->leBedCode->text();
    fDD[":f_bedQty"] = ui->leQty->text();
    fDD[":f_queue"] = ui->leQueue->text();
    fDD[":f_smoke"] = ui->chSmoking->isChecked() ? 1 : 0;
    fDD[":f_phone"] = ui->lePhone->text();
    if (isNew) {
        QMap<QString, QVariant> e;
        DoubleDatabase dd2;
        dd2[":f_id"] = ui->leCode->text();
        dd2.exec("select f_id from f_room where f_id=" + ui->leCode->text());
        if (dd2.rowCount() > 0) {
            message_error(tr("The room with selected code exists"));
            return;
        }
        fDD[":f_state"] = 0;
        fDD.insert("f_room", false);
    } else {
        fDD.update("f_room", "where f_id=" + fTrackControl->oldValue(ui->leCode));
        fDD[":f_room"] = ui->leCode->text();
        fDD[":f_oldroom"] = fTrackControl->oldValue(ui->leCode);
        fDD[":f_state"] = RESERVE_RESERVE;
        fDD.exec("update f_reservation set f_room=:f_room where f_room=:f_oldroom and f_state=:f_state");
    }
    widgetsToValues();
    fTrackControl->saveChanges();
    BroadcastThread::cmdRefreshCache(cid_room, ui->leCode->text());
    accept();
}
