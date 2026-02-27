#include "dlgnoshow.h"
#include "ui_dlgnoshow.h"
#include "pprintvaucher.h"
#include "message.h"
#include "cachevatmode.h"
#include "cachecityledger.h"
#include "cachecreditcard.h"
#include "cachepaymentmode.h"
#include "cacheredreservation.h"
#include "vauchers.h"
#include "cacheinvoiceitem.h"
#include "paymentmode.h"
#include "dlgtracking.h"
#include "cachetaxmap.h"
#include "dlgprinttaxsm.h"
#include <QProcess>
#include <QDir>

static const int HINT_PAYMENT_MODE = 1;
static const int HINT_RED_RESERVE = 2;

DlgNoShow::DlgNoShow(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgNoShow)
{
    ui->setupUi(this);
    ui->leReserve->setSelector(this, cache(cid_red_reservation), nullptr, HINT_RED_RESERVE);
    ui->leVATCode->setSelector(this, cache(cid_vat_mode), ui->leVATName);
    ui->leVATCode->setInitialValue(VAT_NOVAT);
    ui->leCLCode->setSelector(this, cache(cid_city_ledger), ui->leCLName);
    ui->leCardCode->setSelector(this, cache(cid_credit_card), ui->leCardName);
    ui->lePaymentMode->setSelector(this, cache(cid_payment_mode), ui->lePaymentName, HINT_PAYMENT_MODE);
    ui->lePaymentMode->fCodeFilter
            << QString::number(PAYMENT_CASH)
            << QString::number(PAYMENT_CARD)
            << QString::number(PAYMENT_ADVANCE)
            << QString::number(PAYMENT_ROOM)
            << QString::number(PAYMENT_CL)
            << QString::number(PAYMENT_PAYX);
    ui->deDate->setDate(WORKING_DATE);
    ui->wGuest->setVisible(false);
}

DlgNoShow::~DlgNoShow()
{
    delete ui;
}

void DlgNoShow::callback(int sel, const QString &code)
{
    switch (sel) {
        case HINT_PAYMENT_MODE: {
            ui->wGuest->setVisible(false);
            CachePaymentMode ci;
            if (ci.get(code)) {
                switch( ci.fCode().toInt()) {
                    case PAYMENT_CL:
                        ui->leCLCode->setEnabled(true);
                        ui->btnPrintTax->setEnabled(true);
                        break;
                    case PAYMENT_CARD:
                        ui->leCardCode->setEnabled(true);
                        ui->btnPrintTax->setEnabled(true);
                        break;
                    case PAYMENT_ROOM:
                        ui->wGuest->setVisible(true);
                        adjustSize();
                        break;
                }
                ui->btnPrintTax->setEnabled(ci.fCode().toInt() != PAYMENT_CL);
            }
            ui->leCardCode->setEnabled(ui->lePaymentMode->asInt() == PAYMENT_CARD);
            break;
        }
        case HINT_RED_RESERVE: {
            CacheRedReservation ci;
            if (ci.get(code)) {
                ui->leReserve->setText(ci.fCode());
                ui->leInvoice->setText(ci.fInvoice());
                ui->leGuest->setText(ci.fGuest());
                ui->leRoom->setText(ci.fRoom());
            }
            break;
        }
    }
}

void DlgNoShow::setReservation(const QString &reserv)
{
    CacheRedReservation ci;
    if (ci.get(reserv)) {
        ui->leReserve->setText(ci.fCode());
        ui->leInvoice->setText(ci.fInvoice());
        ui->leGuest->setText(ci.fGuest());
        ui->leRoom->setText(ci.fRoom());
    }
    getBalance();
}

void DlgNoShow::load(const QString &id)
{
    DoubleDatabase fDD;
    fDD[":f_id"] = id;
    ui->leCode->setText(id);
    fDD.exec("select * from m_register where f_id=:f_id");
    if (!fDD.nextRow()) {
        message_error(tr("Invalid voucher id"));
        return;
    }
    ui->deDate->setDate(fDD.getValue("f_wdate").toDate());
    ui->leReserve->setText(fDD.getValue("f_res").toString());
    ui->leInvoice->setText(fDD.getValue("f_inv").toString());
    ui->leGuest->setText(fDD.getValue("f_guest").toString());
    ui->leRoom->setText(fDD.getValue("f_room").toString());
    ui->lePaymentMode->setInitialValue(fDD.getValue("f_paymentMode").toString());
    ui->leCLCode->setInitialValue(fDD.getValue("f_cityLedger").toString());
    ui->leCardCode->setInitialValue(fDD.getValue("f_creditCard").toString());
    ui->leAmount->setText(fDD.getValue("f_amountAmd").toString());
    ui->leVATCode->setInitialValue(VAT_NOVAT);
    ui->btnPrintTax->setEnabled(fDD.getValue("f_fiscal").toInt() == 0);
    fDD[":f_id"] = ui->leReserve->text();
    fDD.exec("select * from f_reservation where f_id=:f_id");
    ui->rbCancelation->setChecked(fPreferences.getDb(def_cancelfee_code).toInt());
    if (!fDD.nextRow()) {
        message_error(tr("Invalid reservation number"));
        return;
    }
    ui->deEntry->setDate(fDD.getValue("f_startDate").toDate());
    ui->deDeparture->setDate(fDD.getValue("f_endDate").toDate());
    ui->leTaxCode->setInt(fDD.getValue("f_fiscal").toInt());
    getBalance();
}

void DlgNoShow::on_btnClose_clicked()
{
    reject();
}

void DlgNoShow::on_btnPrint_clicked()
{
    if (ui->leCode->isEmpty()) {
        message_error(tr("The voucher was not saved"));
    } else {
        PPrintVaucher::printVaucher(ui->leCode->text());
    }
}

void DlgNoShow::on_btnSave_clicked()
{
    if (ui->leReserve->isEmpty()) {
        message_error(tr("Reservation must be selected"));
        return;
    }
    if (ui->leBalance->asDouble() > 0.01) {
        if (ui->leAmount->asDouble() > ui->leBalance->asDouble()) {
            message_error(tr("Amount cannot be greater than balance"));
            return;
        }
    }
    if (ui->lePaymentMode->asInt() == PAYMENT_ADVANCE) {
        if (ui->leAmount->asDouble() > ui->leBalance->asDouble()) {
            message_error(tr("Amount cannot be greater than advance"));
            return;
        }
    }
    if (ui->lePaymentMode->asInt() == 0) {
        message_error(tr("Payment mode was note selected"));
        return;
    }
    if (ui->lePaymentMode->asInt() == PAYMENT_CARD) {
        if (ui->leCardCode->asInt() == 0) {
            message_error(tr("Type of card missing"));
            return;
        }
    }
    if (ui->lePaymentMode->asInt() == PAYMENT_ROOM) {
        if (ui->wGuest->invoice().isEmpty()) {
            message_error(tr("Destination room was not selected"));
            return;
        }
    }
    if (ui->leAmount->asDouble() < 0.01) {
        message_error(tr("Amount cannot be 0"));
        return;
    }
    QString inv = ui->leInvoice->text();
    QString res = ui->leReserve->text();
    QString guest = ui->leGuest->text();
    if (ui->lePaymentMode->asInt() == PAYMENT_ROOM) {
        inv = ui->wGuest->invoice();
        res = ui->wGuest->reserve();
        guest = ui->wGuest->guest();
    }
    DoubleDatabase fDD;
    if (ui->leCode->isEmpty()) {
        ui->leCode->setText(uuidx("CH"));
        DoubleDatabase did;
        did.open();
        did.insertId("m_register", ui->leCode->text());
        fDD[":f_source"] = VAUCHER_POSTCHARGE_N;
        fDD[":f_rdate"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_user"] = WORKING_USERID;
    }
    fDD[":f_wdate"] = ui->deDate->date();
    fDD[":f_res"] = res;
    fDD[":f_room"] = ui->leRoom->text();
    fDD[":f_guest"] = guest;
    fDD[":f_itemCode"] = (ui->rbCancelation->isChecked() ? fPreferences.getDb(def_cancelfee_code).toInt() :
                          fPreferences.getDb(def_noshowfee_code).toInt());
    fDD[":f_finalName"] = (ui->rbCancelation->isChecked() ? tr("Cancelation fee") + " " + res
                           : tr("No show fee") + " " + res);
    fDD[":f_amountAmd"] = ui->leAmount->asDouble();
    fDD[":f_amountVat"] = Utils::countVATAmount(ui->leAmount->asDouble(), ui->leVATCode->asInt());
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = 0;
    fDD[":f_paymentMode"] = ui->lePaymentMode->asInt();
    fDD[":f_creditCard"] = ui->leCardCode->asInt();
    fDD[":f_cityLedger"] = ui->leCLCode->asInt();
    fDD[":f_paymentComment"] = ui->lePaymentMode->asInt() == PAYMENT_CL ? ui->leCLName->text() : "";
    fDD[":f_dc"] = "DEBIT";
    fDD[":f_sign"] = 1;
    fDD[":f_doc"] = "";
    fDD[":f_rec"] = "";
    fDD[":f_inv"] = inv;
    fDD[":f_finance"] = 1;
    fDD[":f_remarks"] = "";
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    fDD[":f_side"] = 0;
    fDD[":f_rb"] = 0;
    fDD[":f_cash"] = ui->lePaymentMode->asInt() == PAYMENT_CL ? 0 : 1;
    fDD.update("m_register", where_id(ap(ui->leCode->text())));
    TrackControl tc(TRACK_INVOICE_ITEM);
    tc.fInvoice = ui->leInvoice->text();
    tc.fReservation = ui->leReserve->text();
    tc.fRecord = ui->leCode->text();
    tc.insert(ui->rbCancelation->isChecked() ? "CANCELATION FEE" : "NO SHOW FEE",
              ui->lePaymentName->text() + "/" + ui->leAmount->text(), "");
    message_info(tr("Saved"));
    getBalance();
}

void DlgNoShow::on_btnPrintTax_clicked()
{
    if (ui->leCode->isEmpty()) {
        message_error(tr("Save first"));
        return;
    }
    QString itemCode = ui->rbCancelation->isChecked() ? fPreferences.getDb(def_cancelfee_code).toString() :
                       fPreferences.getDb(def_noshowfee_code).toString();
    CacheInvoiceItem ii;
    if (!ii.get(itemCode)) {
        return;
    }
    CacheTaxMap tm;
    if (!tm.get(itemCode)) {
        message_error(tr("No tax department defined for ") + ii.fName());
        return;
    }
    int pm = ui->lePaymentMode->asInt();
    double card = pm != PAYMENT_CASH ? ui->leAmount->asDouble() : 0;
    double prepaid = pm == PAYMENT_ADVANCE ? ui->leAmount->asDouble() : 0;
    DlgPrintTaxSM dpt(tm.fTax(), this);
    QString dep = ii.fVatDept();
    if (ui->leVATCode->asInt() == VAT_NOVAT) {
        dep = ii.fNoVatDept();
    }
    dpt.addGoods(ii.fVatDept(),
                 ii.fAdgt(),
                 ii.fCode(),
                 ii.fTaxName(),
                 ui->leAmount->asDouble(),
                 1);
    dpt.fOrder = ui->leCode->text();
    dpt.fCardAmount = card;
    dpt.fPrepaid = prepaid;
    int result = dpt.exec();
    DoubleDatabase fDD;
    if (result == TAX_OK) {
        fDD[":f_fiscal"] = dpt.fTaxCode;
        fDD.update("m_register", where_id(ap(ui->leCode->text())));
        ui->leTaxCode->setInt(dpt.fTaxCode);
        fDD[":f_vaucher"] = ui->leCode->text();
        fDD[":f_invoice"] = ui->leInvoice->text();
        fDD[":f_date"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_name"] = (ui->rbCancelation->isChecked() ? tr("Cancelation fee") + " " + ui->leReserve->text()
                          : tr("No show fee") + " " + ui->leReserve->text() );
        fDD[":f_amountCash"] = pm == PAYMENT_CASH ? ui->leAmount->asDouble() : 0;
        fDD[":f_amountCard"] = pm == PAYMENT_CARD ? ui->leAmount->asDouble() : 0;
        fDD[":f_amountPrepaid"] = pm == PAYMENT_ADVANCE ? ui->leAmount->asDouble() : 0;
        fDD[":f_user"] = WORKING_USERID;
        fDD[":f_comp"] = HOSTNAME;
        fDD.insert("m_tax_history");
        TrackControl::insert(TRACK_RESERVATION,
                             ui->rbCancelation->isChecked() ? tr("Cancelation fee tax") : tr("No show fee tax"),
                             ui->leTaxCode->text(), ui->leCode->text(), ui->leCode->text(), ui->leInvoice->text(), ui->leReserve->text());
        message_info(tr("Tax printed"));
    }
}

void DlgNoShow::getBalance()
{
    DoubleDatabase fDD;
    fDD[":f_invoice"] = ui->leInvoice->text();
    fDD.exec("select sum(f_amountAmd*f_sign*-1) from m_register "
             "where f_inv=:f_invoice and f_finance=1 and f_canceled=0");
    if (fDD.nextRow()) {
        ui->leBalance->setText(fDD.getString(0));
    }
    QStringList fa, fp;
    fa << QString::number(PAYMENT_ADVANCE);
    fp << QString::number(PAYMENT_BANK)
       << QString::number(PAYMENT_CARD)
       << QString::number(PAYMENT_CASH)
       << QString::number(PAYMENT_CL)
       << QString::number(PAYMENT_PAYX);
}

void DlgNoShow::on_btnLog_clicked()
{
    DlgTracking::showTracking(ui->leCode->text());
}
