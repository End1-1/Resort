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
    fWidgets << ui->leCode
             << ui->leClassCode
             << ui->leClassName
             << ui->leViewCode
             << ui->leViewName
             << ui->leFloor
             << ui->leBuild
             << ui->leShortName
             << ui->leDescription
             << ui->leRate
             << ui->leBedCode
             << ui->leBedName
             << ui->leQty
             << ui->leQueue
             << ui->chSmoking
             << ui->lePhone;
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
        ui->leCode->setReadOnly(true);
        valuesToWidgets();
        ui->btnOK->setText(tr("Edit"));
        isNew = false;
    }
}

void DlgRoom::on_btnCancel_clicked()
{
    reject();
}

void DlgRoom::on_btnOK_clicked()
{
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_id"] = ui->leCode->text();
    fDD[":f_class"] = ui->leClassCode->text();
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
        fDD.exec("select f_id from f_room where f_id=" + ui->leCode->text());
        if (fDD.rowCount() > 0) {
            message_error(tr("The room with selected code exists"));
            return;
        }
        fDD.insert("f_room", false);
    } else {
        fDD.update("f_room", "where f_id=" + ui->leCode->text());
    }
    widgetsToValues();
    BroadcastThread::cmdRefreshCache(cid_room, ui->leCode->text());
    accept();
}
