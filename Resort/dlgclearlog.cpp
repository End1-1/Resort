#include "dlgclearlog.h"
#include "ui_dlgclearlog.h"
#include "message.h"

DlgClearLog::DlgClearLog(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgClearLog)
{
    ui->setupUi(this);
    DoubleDatabase db;
    db.open(true, false);
    db.exec("select distinct(f_user) from airlog.log order by 1");
    while (db.nextRow()) {
        ui->cbUser->addItem(db.getString(0));
    }
}

DlgClearLog::~DlgClearLog()
{
    delete ui;
}

void DlgClearLog::on_btnClear_clicked()
{
    if (message_confirm(tr("Confirm to delete history for") + ui->cbUser->currentText()) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase db(true, false);
    if (ui->cbUser->currentText() == "") {
        db.exec("delete from airlog.log where f_user is null or f_user=''");
    } else {
        db.exec("delete from airlog.log where f_user='" + ui->cbUser->currentText() + "'");
    }
    message_info(tr("Done"));
}
