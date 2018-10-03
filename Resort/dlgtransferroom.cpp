#include "dlgtransferroom.h"
#include "ui_dlgtransferroom.h"
#include "cacheroom.h"

DlgTransferRoom::DlgTransferRoom(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgTransferRoom)
{
    ui->setupUi(this);
    ui->leAmount->setValidator(new QIntValidator());
}

DlgTransferRoom::~DlgTransferRoom()
{
    delete ui;
}

void DlgTransferRoom::on_leRoomCode1_returnPressed()
{
    ui->leRoomName1->clear();
    CacheRoom r;
    if (!r.get(ui->leRoomCode1->text())) {
        message_error(tr("Invalid room code"));
        return;
    }
    ui->leRoomName1->setText(r.fName());
}

void DlgTransferRoom::on_leRoomCode2_returnPressed()
{
    ui->leRoomName2->clear();
    CacheRoom r;
    if (!r.get(ui->leRoomCode2->text())) {
        message_error(tr("Invalid room code"));
        return;
    }
    ui->leRoomName2->setText(r.fName());
}

void DlgTransferRoom::on_btnCancel_clicked()
{
    reject();
}

void DlgTransferRoom::on_btnOk_clicked()
{
    message_error(tr("Not implemented, bye!"));
}
