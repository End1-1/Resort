#include "dlgnotes.h"
#include "ui_dlgnotes.h"
#include "cacheguest.h"
#include "cacheusersgroups.h"
#include "cacheroom.h"

DlgNotes::DlgNotes(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_NOTE, parent),
    ui(new Ui::DlgNotes)
{
    ui->setupUi(this);
    ui->wdSchedule->setVisible(false);

    ui->leGuestCode->setSelector(this, cache(cid_guest), ui->leGuestName);
    ui->leGroupCode->setSelector(this, cache(cid_users_group), ui->leGroupName);
    ui->leRoomCode->setSelector(this, cache(cid_room), ui->leRoomName);
}

DlgNotes::~DlgNotes()
{
    delete ui;
}

void DlgNotes::setValues()
{
    ui->leCode->clear();
    ui->leRoomCode->clear();
    ui->leRoomName->clear();
    ui->deStart->setDateTime(QDateTime::currentDateTime());
    ui->deInterval->setTime(QTime::fromString("00:00:00", "HH:mm:ss"));
    ui->leGuestCode->clear();
    ui->leGuestName->clear();
    ui->leNationality->clear();
    ui->teText->clear();
    ui->leAuthor->setText(WORKING_USERNAME);
    if (fValues.count() > 0) {
        ui->leCode->setText(fValues.at(0).toString());
        ui->cbState->setIndexForData(fValues.at(1).toInt());
        ui->leRoomCode->setText(fValues.at(3).toString());
        ui->leRoomName->setText(fValues.at(4).toString());
        ui->leGroupCode->setText(fValues.at(5).toString());
        ui->leGroupName->setText(fValues.at(5).toString());
        ui->deStart->setDateTime(fValues.at(6).toDateTime());
        ui->deInterval->setTime(fValues.at(7).toTime());
        ui->teText->setPlainText(fValues.at(8).toString());
        ui->leGuestCode->setText(fValues.at(9).toString());
        ui->leGuestName->setText(fValues.at(10).toString());
        ui->leNationality->setText(fValues.at(11).toString());
        ui->leAuthor->setText(fValues.at(12).toString());
    }
}

void DlgNotes::setScheduleVisible(bool value)
{
    ui->wdSchedule->setVisible(value);
    ui->buttonBox->setVisible(!value);
}

void DlgNotes::on_buttonBox_accepted()
{
    DoubleDatabase fDD;
    if (ui->wdSchedule->isVisible()) {
        message_info(tr("You must schedule or dissmis the task"));
        return;
    }
    int code = ui->leCode->text().toInt();
    fDD[":f_state"] = ui->cbState->asInt();
    fDD[":f_room"] = ui->leRoomCode->text().toInt();
    fDD[":f_group"] = ui->leGroupCode->asInt();
    fDD[":f_dateStart"] = ui->deStart->dateTime();
    fDD[":f_interval"] = ui->deInterval->time();
    fDD[":f_text"] = ui->teText->toPlainText();
    fDD[":f_guest"] = ui->leGuestCode->text().toInt();
    if (code == 0) {
        fDD[":f_author"] = WORKING_USERID;
        code = fDD.insert("f_reminder");
        ui->leCode->setText(QString::number(code));
    } else {
        fDD.update("f_reminder", "where f_id=" + ui->leCode->text());
    }
    fValues.clear();
    fValues << ui->leCode->text()
            << ui->cbState->asInt()
            << ui->cbState->currentText()
            << ui->leRoomCode->text()
            << ui->leRoomName->text()
            << ui->leGroupCode->text()
            << ui->leGroupName->text()
            << ui->deStart->dateTime()
            << ui->deInterval->time()
            << ui->teText->toPlainText()
            << ui->leGuestCode->text()
            << ui->leGuestName->text()
            << ui->leNationality->text()
            << ui->leAuthor->text();

    accept();
}

void DlgNotes::on_btnSchedule_clicked()
{
    DoubleDatabase fDD;
    fDD[":f_state"] = 1;
    fDD[":f_dateLastComplete"] = QDateTime::currentDateTime();
    fDD.update("f_reminder", "where f_id=" + ui->leCode->text());
    reject();
}

void DlgNotes::on_btnDissmiss_clicked()
{
    DoubleDatabase fDD;
    fDD[":f_state"] = 2;
    fDD[":f_dateLastComplete"] = QDateTime::currentDateTime();
    fDD.update("f_reminder", "where f_id=" + ui->leCode->text());
    reject();
}

void DlgNotes::on_buttonBox_rejected()
{
    if (ui->wdSchedule->isVisible()) {
        message_info(tr("You must schedule or dissmis the task"));
        return;
    }
}
