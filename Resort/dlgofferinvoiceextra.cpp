#include "dlgofferinvoiceextra.h"
#include "ui_dlgofferinvoiceextra.h"
#include "dlgpostcharge.h"

DlgOfferInvoiceExtra::DlgOfferInvoiceExtra(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgOfferInvoiceExtra)
{
    ui->setupUi(this);
    ui->btnDayUse->setVisible(false);
    ui->btnEarlyCheckin->setVisible(false);
    ui->btnExtraRooming->setVisible(false);
    ui->btnLateCheckout->setVisible(false);
    fExtra = false;
    fDayUseRate = 0.0;
}

DlgOfferInvoiceExtra::~DlgOfferInvoiceExtra()
{
    delete ui;
}

void DlgOfferInvoiceExtra::setRoom(int room)
{
    fRoom = room;
}

void DlgOfferInvoiceExtra::setExtra(Extra e)
{
    switch (e) {
    case exDayUse:
        if (fPreferences.getDb(def_day_use_id).toInt() == 0) {
            return;
        }
        ui->btnDayUse->setVisible(true);
        break;
    case exExtraRooming:
        if (fPreferences.getDb(def_extrarooming_id).toInt() == 0) {
            return;
        }
        ui->btnExtraRooming->setVisible(true);
        break;
    case exEarlyCheckin:
        if (fPreferences.getDb(def_earyly_checkin_id).toInt() == 0) {
            return;
        }
        ui->btnEarlyCheckin->setVisible(true);
        break;
    case exLateCheckout:
        if (fPreferences.getDb(def_late_checkout_id).toInt() == 0) {
            return;
        }
        ui->btnLateCheckout->setVisible(true);
        break;
    }
    fExtra = true;
}

int DlgOfferInvoiceExtra::exec()
{
    if (!fExtra) {
        return QDialog::Rejected;
    }
    adjustSize();
    return QDialog::exec();
}

void DlgOfferInvoiceExtra::on_btnCancel_clicked()
{
    reject();
}

void DlgOfferInvoiceExtra::on_btnExtraRooming_clicked()
{
    createChargeDlg(fPreferences.getDb(def_extrarooming_id).toInt());
}

void DlgOfferInvoiceExtra::on_btnEarlyCheckin_clicked()
{
    createChargeDlg(fPreferences.getDb(def_earyly_checkin_id).toInt());
}

void DlgOfferInvoiceExtra::on_btnDayUse_clicked()
{
    createChargeDlg(fPreferences.getDb(def_day_use_id).toInt());
}

void DlgOfferInvoiceExtra::on_btnLateCheckout_clicked()
{
    createChargeDlg(fPreferences.getDb(def_late_checkout_id).toInt());
}

void DlgOfferInvoiceExtra::createChargeDlg(int item)
{
    DlgPostCharge *d = new DlgPostCharge(this);
    d->setRoom(fRoom);
    d->setItem(item);
    d->setAmount(fDayUseRate);
    d->exec();
    d->deleteLater();
    accept();
}
