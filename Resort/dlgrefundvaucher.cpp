#include "dlgrefundvaucher.h"
#include "ui_dlgrefundvaucher.h"
#include "cacheredreservation.h"
#include "cachepaymentmode.h"
#include "cachereservation.h"
#include "message.h"
#include "pprintvaucher.h"
#include "paymentmode.h"
#include "vauchers.h"

DlgRefundVaucher::DlgRefundVaucher(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgRefundVaucher)
{
    ui->setupUi(this);
    ui->leCLCode->setSelector(this, cache(cid_city_ledger), ui->leCLName);
    ui->lePaymentMode->setSelector(this, cache(cid_payment_mode), ui->lePaymentName);
    ui->lePaymentMode->fCodeFilter
            << QString::number(PAYMENT_CASH)
            << QString::number(PAYMENT_BANK);
}

DlgRefundVaucher::~DlgRefundVaucher()
{
    delete ui;
}

void DlgRefundVaucher::refundVaucher(const QString &vaucher, const QString &reserv)
{
    Q_UNUSED(vaucher);
    DlgRefundVaucher *d = new DlgRefundVaucher(fPreferences.getDefaultParentForMessage());
    if (!reserv.isEmpty()) {
        d->setReservation(reserv);
    }
    d->exec();
    delete d;
}

void DlgRefundVaucher::on_btnSave_clicked()
{
    if (ui->lePaymentMode->asInt() == 0) {
        message_error(tr("Payment mode was not selected"));
        return;
    }
    if (ui->leReserve->isEmpty() && ui->rgGuest->isChecked()) {
        message_error(tr("Reservation is not selected"));
        return;
    }
    DoubleDatabase fDD;
    if (ui->leVaucher->isEmpty()) {
        ui->leVaucher->setText(uuidx("RF"));
        fDD[":f_id"] = ui->leVaucher->text();
        fDD[":f_source"] = VAUCHER_REFUND_N;
        fDD.insert("m_register");
        fDD[":f_rdate"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_user"] = WORKING_USERID;
    }

    fDD[":f_wdate"] = ui->deDate->date();
    fDD[":f_res"] = ui->leReserve->text();
    fDD[":f_room"] = ui->leRoom->text();
    fDD[":f_guest"] = ui->leGuest->text();
    fDD[":f_itemCode"] = fPreferences.getDb(def_invoice_default_refund_id);
    fDD[":f_finalName"] = ui->rgGuest->isChecked() ? tr("Refund") + " " + ui->leReserve->text() : tr("Refund") + " " + ui->leCLName->text();
    fDD[":f_amountAmd"] = ui->leAmount->asDouble();
    fDD[":f_amountVat"] = 0;
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = 0;
    fDD[":f_paymentMode"] = ui->lePaymentMode->asInt();
    fDD[":f_creditCard"] = 0;
    fDD[":f_cityLedger"] = ui->leCLCode->asInt();
    fDD[":f_paymentComment"] = ui->rgGuest->isChecked() ? tr("Refund") + " " + ui->leReserve->text() : tr("Refund") + " " + ui->leCLName->text();;
    fDD[":f_dc"] = ui->rgGuest->isChecked() ? "CREDIT" : "CREDIT";
    fDD[":f_sign"] = ui->rgGuest->isChecked() ? 1 : -1;
    fDD[":f_doc"] = "";
    fDD[":f_rec"] = "";
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD[":f_finance"] = 1;
    fDD[":f_remarks"] = "";
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    fDD[":f_side"] = 0;
    fDD[":f_rb"] = 0;
    fDD.update("m_register", where_id(ap(ui->leVaucher->text())));
    if (ui->chDecreaseAdvance->isChecked()) {
        fDD[":f_invoice"] = ui->leInvoice->text();
        fDD[":f_amount"] = ui->leAmount->asDouble();
        fDD.insert("f_used_advance", false);
    }
    getBalance();
    message_info(tr("Saved"));
}

void DlgRefundVaucher::setReservation(const QString &reserv)
{
    CacheRedReservation ci;
    if (ci.get(reserv)) {
        ui->leReserve->setText(reserv);
        ui->leInvoice->setText(ci.fInvoice());
        ui->leGuest->setText(ci.fGuest());
        ui->leRoom->setText(ci.fRoom());
    } else {
        CacheReservation cr;
        if (cr.get(reserv)) {
            ui->leReserve->setText(reserv);
            ui->leInvoice->setText(cr.fInvoice());
            ui->leGuest->setText(cr.fGuest());
            ui->leRoom->setText(cr.fRoom());
        }
    }
    getBalance();
}

void DlgRefundVaucher::getBalance()
{
    DoubleDatabase fDD;
    fDD[":f_invoice"] = ui->leInvoice->text();
    fDD.exec("select sum(f_amountAmd*f_sign*-1) from m_register "
               "where f_inv=:f_invoice and f_finance=1 and f_canceled=0");
    if (fDD.nextRow()) {
        ui->leBalance->setText(fDD.getString(0));
    }
}

void DlgRefundVaucher::on_btnPrint_clicked()
{
    if (ui->leVaucher->isEmpty()) {
        message_error(tr("Voucher is not saved"));
        return;
    }
    PPrintVaucher::printVaucher(ui->leVaucher->text());
}

void DlgRefundVaucher::on_btnCancel_clicked()
{
    reject();
}

void DlgRefundVaucher::on_rgGuest_clicked(bool checked)
{
    ui->leCLCode->setEnabled(!checked);
    ui->leCLName->setEnabled(!checked);
}

void DlgRefundVaucher::on_rgCL_clicked(bool checked)
{
    ui->leCLCode->setEnabled(checked);
    ui->leCLName->setEnabled(checked);
}
