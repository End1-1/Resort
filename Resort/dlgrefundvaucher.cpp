#include "dlgrefundvaucher.h"
#include "ui_dlgrefundvaucher.h"
#include "cacherefundinvoice.h"
#include "cachepaymentmode.h"
#include "message.h"
#include "pprintvaucher.h"
#include "paymentmode.h"
#include "vauchers.h"

#define HINT_REFUND_INVOICE 1

DlgRefundVaucher::DlgRefundVaucher(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgRefundVaucher)
{
    ui->setupUi(this);
    ui->leInvoice->setEnabled(true);
    ui->leInvoice->setSelector(this, cache(cid_refund_invoice), ui->leInvoice, HINT_REFUND_INVOICE);
    ui->leCLCode->setSelector(this, cache(cid_city_ledger), ui->leCLName);
    ui->lePaymentMode->setSelector(this, cache(cid_payment_mode), ui->lePaymentName);
    ui->lePaymentMode->fCodeFilter << QString::number(PAYMENT_CASH) << QString::number(PAYMENT_CARD) << QString::number(PAYMENT_BANK)
                                   << QString::number(PAYMENT_CPAY) << QString::number(PAYMENT_IDRAM);
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

void DlgRefundVaucher::refundByInvoice(const QString &invoice)
{
    DlgRefundVaucher *d = new DlgRefundVaucher(fPreferences.getDefaultParentForMessage());
    if (!invoice.isEmpty()) {
        d->setInvoice(invoice);
        d->ui->leInvoice->setEnabled(false);
    }
    d->exec();
    delete d;
}

void DlgRefundVaucher::callback(int sel, const QString &code)
{
    switch (sel) {
    case HINT_REFUND_INVOICE:
        setInvoice(code);
        break;
    default:
        break;
    }
}

void DlgRefundVaucher::on_btnSave_clicked()
{
    if (ui->lePaymentMode->asInt() == 0) {
        message_error(tr("Payment mode was not selected"));
        return;
    }
    if (ui->leInvoice->isEmpty()) {
        message_error(tr("Invoice is not selected"));
        return;
    }
    if (!setInvoice(ui->leInvoice->text())) {
        message_error(tr("Invoice is not defined"));
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
    fDD[":f_finalName"] = ui->rgGuest->isChecked() ? tr("Refund") + " " + ui->leInvoice->text() : tr("Refund") + " " + ui->leCLName->text();
    fDD[":f_amountAmd"] = ui->leAmount->asDouble();
    fDD[":f_amountVat"] = 0;
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = 0;
    fDD[":f_paymentMode"] = ui->lePaymentMode->asInt();
    fDD[":f_creditCard"] = 0;
    fDD[":f_cityLedger"] = ui->leCLCode->asInt();
    fDD[":f_paymentComment"] = ui->rgGuest->isChecked() ? tr("Refund") + " " + ui->leInvoice->text() : tr("Refund") + " " + ui->leCLName->text();
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
    DoubleDatabase fDD;
    fDD[":f_id"] = reserv;
    fDD.exec("select f_invoice from f_reservation where f_id=:f_id");
    if (fDD.nextRow()) {
        setInvoice(fDD.getString("f_invoice"));
    }
}

bool DlgRefundVaucher::setInvoice(const QString &invoice)
{
    ui->leReserve->clear();
    ui->leInvoice->setText(invoice);
    ui->leGuest->clear();
    ui->leRoom->clear();
    DoubleDatabase fDD;
    fDD[":f_invoice"] = invoice;
    fDD.exec("select r.f_id, r.f_invoice, r.f_room, "
             "concat(g.f_firstName, ' ', g.f_lastName) as f_guest_name "
             "from f_reservation r "
             "left join f_guests g on g.f_id=r.f_guest "
             "where r.f_invoice=:f_invoice "
             "order by r.f_endDate desc, r.f_id desc limit 1");
    if (!fDD.nextRow()) {
        getBalance();
        return false;
    }
    ui->leReserve->setText(fDD.getString("f_id"));
    ui->leInvoice->setText(fDD.getString("f_invoice"));
    ui->leGuest->setText(fDD.getString("f_guest_name"));
    ui->leRoom->setText(fDD.getString("f_room"));
    getBalance();
    return true;
}

void DlgRefundVaucher::getBalance()
{
    if (ui->leInvoice->isEmpty()) {
        ui->leBalance->setText("0");
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_invoice"] = ui->leInvoice->text();
    fDD.exec("select sum(f_amountAmd*f_sign*-1) from m_register "
               "where f_inv=:f_invoice and f_finance=1 and f_canceled=0");
    if (fDD.nextRow()) {
        ui->leBalance->setText(fDD.getString(0));
    } else {
        ui->leBalance->setText("0");
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

void DlgRefundVaucher::on_leInvoice_returnPressed()
{
    if (!setInvoice(ui->leInvoice->text())) {
        message_error(tr("Invoice is not defined"));
    }
}

#undef HINT_REFUND_INVOICE
