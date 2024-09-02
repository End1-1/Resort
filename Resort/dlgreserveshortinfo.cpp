#include "dlgreserveshortinfo.h"
#include "ui_dlgreserveshortinfo.h"
#include "message.h"
#include "cacheusers.h"

DlgReserveShortInfo::DlgReserveShortInfo(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgReserveShortInfo)
{
    ui->setupUi(this);
    ui->leCheckoutUsercode->setSelector(this, cache(cid_users), ui->leCheckoutUserName);
    fTrackControl = new TrackControl(TRACK_RESERVATION);
    fTrackControl->addWidget(ui->deCheckin, "Checkin date");
    fTrackControl->addWidget(ui->teCheckin, "Checkin time");
    fTrackControl->addWidget(ui->deDeparture, "Departure date");
    fTrackControl->addWidget(ui->teCheckin, "Departure time");
    fTrackControl->addWidget(ui->leCheckoutUsercode, "Checkout user code");
}

DlgReserveShortInfo::~DlgReserveShortInfo()
{
    delete fTrackControl;
    delete ui;
}

void DlgReserveShortInfo::loadShortInfo(const QString &id)
{
    DlgReserveShortInfo *d = new DlgReserveShortInfo(fPreferences.getDefaultParentForMessage());
    d->ui->leCode->setText(id);
    if (!d->loadInfo()) {
        delete d;
        return;
    }
    d->exec();
    delete d;
}

void DlgReserveShortInfo::on_btnCancel_clicked()
{
    reject();
}

void DlgReserveShortInfo::on_btnOK_clicked()
{
    DoubleDatabase fDD;
    fDD[":f_startDate"] = ui->deCheckin->date();
    fDD[":f_checkinDate"] = ui->deCheckin->date();
    fDD[":f_endDate"] = ui->deDeparture->date();
    fDD[":f_checkInTime"] = ui->teCheckin->time();
    fDD[":f_checkOutTime"] = ui->teCheckout->time();
    fDD[":f_checkOutUser"] = ui->leCheckoutUsercode->asInt();
    fDD.update("f_reservation", where_id(ap(ui->leCode->text())));
    fDD[":f_wdate"] = ui->deDeparture->date();
    fDD[":f_rdate"] = ui->deDeparture->date();
    fDD[":f_time"] = ui->teCheckout->time();
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD.exec("update m_register set f_wdate=:f_wdate, f_rdate=:f_rdate, f_time=:f_time where f_source='CO' and f_inv=:f_inv");
    fTrackControl->saveChanges();
    message_info(tr("Saved"));
}

bool DlgReserveShortInfo::loadInfo()
{
    DoubleDatabase fDD;
    fDD[":f_id"] = ui->leCode->text();
    fDD.exec("select * from f_reservation where f_id=:f_id");
    if (!fDD.nextRow()) {
        return false;
    }
    ui->leInvoice->setText(fDD.getValue("f_invoice").toString());
    ui->leRoom->setText(fDD.getValue("f_room").toString());
    ui->deCheckin->setDate(fDD.getValue("f_startDate").toDate());
    ui->deDeparture->setDate(fDD.getValue("f_endDate").toDate());
    ui->teCheckin->setTime(fDD.getValue("f_checkInTime").toTime());
    ui->teCheckout->setTime(fDD.getValue("f_checkOutTime").toTime());
    ui->leCheckoutUsercode->setInitialValue(fDD.getValue("f_checkOutUser").toInt());
    fTrackControl->fReservation = ui->leCode->text();
    fTrackControl->fInvoice = ui->leInvoice->text();
    fTrackControl->resetChanges();
    return true;
}
