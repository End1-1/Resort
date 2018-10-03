#include "dlgreceiptvaucher.h"
#include "ui_dlgreceiptvaucher.h"
#include "pprintpreview.h"
#include "ptextrect.h"
#include "pprintheader.h"
#include "cachepaymentmode.h"
#include "vauchers.h"
#include "pimage.h"
#include "printtax.h"
#include "cacheactiveroom.h"
#include "paymentmode.h"
#include "pprintvaucher.h"
#include "cacheusers.h"

#define HINT_ACTIVE_ROOM 1
#define HINT_CITY_LEDGER 2
#define HINT_PAYMENT_MODE 3
#define HINT_CARD 4

DlgReceiptVaucher::DlgReceiptVaucher(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgReceiptVaucher)
{
    ui->setupUi(this);
    ui->leOpcode->setSelector(this, cache(cid_users), ui->leOpName);
    ui->leOpcode->setInitialValue(WORKING_USERID);
    ui->leRoom->setVisible(false);
    ui->leName->setReadOnly(!r__(cr__super_correction));
    ui->deDate->setDate(WORKING_DATE);

    ui->lePartnerCode->setSelector(this, cache(cid_active_room), ui->lePartnerName, HINT_ACTIVE_ROOM);
    ui->lePaymentCode->setSelector(this, cache(cid_payment_mode), ui->lePaymentName, HINT_PAYMENT_MODE);
    ui->lePaymentCode->fCodeFilter << QString::number(PAYMENT_CASH)
                                     << QString::number(PAYMENT_CARD)
                                     << QString::number(PAYMENT_BANK)
                                     << QString::number(PAYMENT_BARTER);
    ui->leCardCode->setSelector(this, cache(cid_credit_card), ui->leCardName, HINT_CARD);
    cardVisible(false);
    fTrackControl = new TrackControl(TRACK_RESERVATION);
}

DlgReceiptVaucher::~DlgReceiptVaucher()
{
    delete ui;
}

void DlgReceiptVaucher::setVaucher(const QString &id)
{
    ui->leVaucher->setText(id);
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_id"] = id;
    fDD.exec("select m.f_room, m.f_inv, m.f_guest, m.f_amountAmd, m.f_creditCard, m.f_cityLedger, \
        m.f_fiscal, m.f_wdate, m.f_finalName, m.f_doc, m.f_remarks, m.f_paymentMode, m.f_rb, m.f_user \
        from m_register m \
        where f_id=:f_id");
    if (fDD.rowCount() > 0) {
        QList<QList<QVariant> > &fDbRows = fDD.fDbRows;
        ui->leInvoice->setText(fDbRows.at(0).at(1).toString());
        ui->leAmountAMD->setDouble(fDbRows.at(0).at(3).toDouble());
        ui->leAmountUSD->setDouble(ui->leAmountAMD->asDouble() / def_usd);
        ui->leCardCode->setInitialValue(fDbRows.at(0).at(4).toString());
        ui->deDate->setDate(fDbRows.at(0).at(7).toDate());
        ui->leName->setText(fDbRows.at(0).at(8).toString());
        ui->teRemarks->setPlainText(fDbRows.at(0).at(10).toString());
        // = fDbRows.at(0).at(9).toInt();
        ui->lePaymentCode->setInitialValue(fDbRows.at(0).at(11).toString());
        ui->leRoom->setText(fDbRows.at(0).at(0).toString());
        ui->rbGuest->setChecked(fDbRows.at(0).at(12).toInt());
        ui->leOpcode->setInitialValue(fDbRows.at(0).at(13).toString());
        if (fDbRows.at(0).at(5).toInt() > 0) {
            ui->rbCityLedger->setChecked(true);
            ui->rbGuest->setChecked(false);
            ui->lePartnerCode->setInitialValue(fDbRows.at(0).at(5).toString());
        } else {
            ui->rbCityLedger->setChecked(false);
            ui->rbGuest->setChecked(true);
            ui->lePartnerCode->setText(fDbRows.at(0).at(0).toString());
            ui->lePartnerName->setText(fDbRows.at(0).at(2).toString());
        }
        if (ui->rbGuest->isChecked()) {
            fDD[":f_id"] = ui->lePartnerCode->asInt();
            fDD.exec("select concat(g.f_firstName, ' ' , g.f_lastName) from f_guests g where f_id=:f_id");
            if (fDD.rowCount() > 0) {
                ui->lePartnerName->setText(fDbRows.at(0).at(0).toString());
            }
        }
    }
    fTrackControl->resetChanges();
    switch (ui->lePaymentCode->asInt()) {
        case PAYMENT_BANK:
            ui->deDate->setReadOnly(!r__(cr__rv_change_date_bank));
            break;
        case PAYMENT_CASH:
            ui->deDate->setReadOnly(!r__(cr__rv_change_date_cash));
            break;
        case PAYMENT_CL:
            ui->deDate->setReadOnly(!r__(cr__rv_change_date_cl));
            break;
        case PAYMENT_CARD:
            ui->deDate->setReadOnly(!r__(cr__rv_change_date_card));
            break;
        default:
            ui->deDate->setReadOnly(true);
            break;
    }

    ui->btnSave->setVisible(r__(cr__super_correction));
    if (r__(cr__super_correction)) {
        ui->deDate->setReadOnly(false);
    }
    ui->btnPrint->setEnabled(true);
}


void DlgReceiptVaucher::callback(int sel, const QString &code)
{
    DoubleDatabase fDD(true, doubleDatabase);
    switch (sel) {
    case HINT_ACTIVE_ROOM: {
        CacheActiveRoom c;
        if (c.get(code)) {
        ui->leInvoice->setText(c.fInvoice());
        ui->lePartnerCode->setText(c.fRoomCode());
        ui->lePartnerName->setText(c.fGuestName());
        ui->leRoom->setText(c.fRoomCode());
        fDD[":f_side"] = 0;
        fDD[":f_invoice"] = c.fInvoice();
        fDD.exec("select sum(f_amountAmd*f_sign) from m_register where f_side=:f_side and f_inv=:f_invoice "
                   "and f_canceled=0 and f_finance=1 ");
        if (fDD.nextRow()) {
            ui->leBalance->setText(fDD.getString(0));
        }
        fTrackControl->resetChanges();
        }
        break;
    }
    case HINT_CITY_LEDGER: {
        ui->leRoom->clear();
        ui->leInvoice->clear();
        CacheCityLedger c;
        if (c.get(code)) {
            fDD[":f_cityLedger"] = ui->lePartnerCode->asInt();
            fDD.exec("select sum(f_amountAmd*f_sign*-1) from m_register "
                       "where f_cityLedger=:f_cityLedger and f_canceled=0 and f_finance=1 ");
            if (fDD.nextRow()) {
                ui->leBalance->setText(fDD.getString(0));
            }
            ui->leName->setText(tr("PAYMENT ") + " " + c.fName());
        }
        break;
    }
    case HINT_PAYMENT_MODE: {
        CachePaymentMode c;
        if (c.get(code)) {
            switch (c.fCode().toInt()) {
            case PAYMENT_CASH:
                cardVisible(false);
                ui->leName->setText(tr("PAYMENT CASH"));
                break;
            case PAYMENT_CARD:
                cardVisible(true);
                break;
            case PAYMENT_BANK:
                cardVisible(false);
                ui->leName->setText(tr("PAYMENT BANK"));
                break;
            default:
                cardVisible(false);
                ui->leName->setText("PAYMENT " + c.fName());
                break;
            }
        }
        break;
    }
    case HINT_CARD: {
        CacheCreditCard c;
        if (c.get(code)) {
            ui->leName->setText(tr("PAYMENT") + " " + c.fName());
        }
        break;
    }
    }
}

void DlgReceiptVaucher::on_btnSave_clicked()
{
    QString errors;
    if (ui->leAmountAMD->asDouble() < 0.1) {
        errors += tr("Amount cannot be equal to zero.") + "<br>";
    }
    if (ui->rbGuest->isChecked()) {
        CacheActiveRoom c;
        if (!c.get(ui->lePartnerCode->text()) && ui->leVaucher->isEmpty()) {
            errors += tr("Incorrect room number") + "<br>";
        }
    }
    if (ui->rbCityLedger->isChecked()) {
        CacheCityLedger c;
        if (!c.get(ui->lePartnerCode->text())) {
            errors += tr("Incorrect city ledger code") + "<br>";
        }
    }
    if (ui->lePaymentCode->asInt() == PAYMENT_CARD) {
        if (ui->leCardCode->asInt() == 0) {
            errors += tr("Card is not selected");
        }
    }
    if (!errors.isEmpty()) {
        message_error(errors);
        return;
    }
    saveRoom();
}

void DlgReceiptVaucher::on_rbGuest_clicked(bool checked)
{
    if (checked) {        
        ui->lePartnerCode->setSelector(this, cache(cid_active_room), ui->lePartnerName, HINT_ACTIVE_ROOM);
    }
}

void DlgReceiptVaucher::on_rbCityLedger_clicked(bool checked)
{
    if (checked) {
        ui->lePartnerCode->setSelector(this, cache(cid_city_ledger), ui->lePartnerName, HINT_CITY_LEDGER);
        ui->leBalance->clear();
    }
}

void DlgReceiptVaucher::on_btnCancel_clicked()
{
    reject();
}

void DlgReceiptVaucher::saveRoom()
{
    int rb = ui->rbCityLedger->isChecked();
    QString dc = "CREDIT";
    int sign = -1;
    if (ui->rbCityLedger->isChecked()) {
        dc = "DEBIT";
        sign = 1;
    }
    QString finalName;
    if (ui->rbGuest->isChecked()) {
        switch (ui->lePaymentCode->asInt()) {
        case PAYMENT_CASH:
            finalName = "CASH";
            break;
        case PAYMENT_BANK:
            finalName = "BANK";
            break;
        case PAYMENT_CARD:
            finalName = "CARD " + ui->leCardName->text();
            break;
        case PAYMENT_CL:
            finalName = "C/L " + ui->lePartnerName->text();
            break;
        case PAYMENT_BARTER:
            finalName = "BARTER " + ui->lePartnerName->text();
            break;
        default:
            message_error(tr("Selected payment mode is not allowed here"));
            return;
        }
    } else {
        switch (ui->lePaymentCode->asInt()) {
        case PAYMENT_CASH:
            finalName = "CASH";
            break;
        case PAYMENT_BANK:
            finalName = "BANK";
            break;
        case PAYMENT_CARD:
            finalName = "CARD " + ui->leCardName->text();
            break;
        case PAYMENT_BARTER:
            finalName = "BARTER " + ui->lePartnerName->text();
            break;
        default:
            message_error(tr("Selected payment mode is not allowed here"));
            return;
        }
    }
    bool isNew = false;
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.startTransaction();
    if (ui->leVaucher->isEmpty()) {
        isNew = true;
        ui->leVaucher->setText(uuid(VAUCHER_RECEIPT_N));
        fDD.insertId("m_register", ui->leVaucher->text());
    }
    fDD[":f_source"] = VAUCHER_RECEIPT_N;
    if (isNew) {
        fDD[":f_rdate"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_user"] = ui->leOpcode->asInt();
    }
    fDD[":f_wdate"] = ui->deDate->date();
    fDD[":f_room"] = (ui->rbCityLedger->isChecked() ? "-" : ui->leRoom->text());
    fDD[":f_guest"] = ui->lePartnerName->text();
    fDD[":f_itemCode"] = fPreferences.getDb(def_receip_vaucher_id);
    fDD[":f_finalName"] = ui->leName->text();
    fDD[":f_amountAmd"] = ui->leAmountAMD->asDouble();
    fDD[":f_amountVat"] = 0;
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = 0;
    fDD[":f_paymentMode"] = ui->lePaymentCode->asInt();
    fDD[":f_creditCard"] = ui->leCardCode->asInt();
    fDD[":f_cityLedger"] = (ui->rbCityLedger->isChecked() ? ui->lePartnerCode->asInt() : 0);
    fDD[":f_paymentComment"] = vaucherPaymentName(ui->lePaymentCode->asInt(),
                                                      ui->leCardCode->text(),
                                                      ui->lePartnerCode->text());
    fDD[":f_dc"] = dc;
    fDD[":f_sign"] = sign;
    fDD[":f_doc"] = "";
    fDD[":f_rec"] = "";
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD[":f_finance"] = 1;
    fDD[":f_remarks"] = ui->teRemarks->toPlainText();
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    fDD[":f_side"] = 0;
    fDD[":f_rb"] = rb;
    fDD[":f_cash"] = 1;
    fDD.update("m_register", where_id(ap(ui->leVaucher->text())));
    fDD.commit();

    QString msg = isNew ? "New receipt" : "Receipt modified";
    msg += " " + ui->leVaucher->text();
    QString value = ui->deDate->text() + "/" + ui->leRoom->text()
            + "/" + ui->lePartnerName->text() + "/" + ui->lePaymentName->text()
            + "/" + ui->leCardName->text() + "/" + ui->leName->text() + "/" + ui->leAmountAMD->text();
    fTrackControl->insert(msg, value, "");

    ui->btnPrint->setEnabled(true);
    ui->btnSave->setEnabled(false);
}

void DlgReceiptVaucher::cardVisible(bool v)
{
    ui->lbCardType->setVisible(v);
    ui->leCardCode->setVisible(v);
    ui->leCardName->setVisible(v);
    if (!v) {
        ui->leCardCode->clear();
        ui->leCardName->clear();
    }
}

void DlgReceiptVaucher::on_btnPrint_clicked()
{
    PPrintVaucher::printVaucher(ui->leVaucher->text());
}

void DlgReceiptVaucher::on_leAmountAMD_textEdited(const QString &arg1)
{
    ui->leAmountUSD->setDouble(arg1.toDouble() / def_usd);
}

void DlgReceiptVaucher::on_btnNew_clicked()
{
    accept();
    DlgReceiptVaucher *d = new DlgReceiptVaucher(this);
    d->exec();
    delete d;
}

void DlgReceiptVaucher::on_lePaymentCode_textChanged(const QString &arg1)
{
    bool ro = true;
    switch (arg1.toInt()) {
    case PAYMENT_BANK:
        ro = !r__(cr__rv_change_date_bank);
        break;
    case PAYMENT_CASH:
        ro = !r__(cr__rv_change_date_cash);
        break;
    case PAYMENT_CARD:
        ro = !r__(cr__rv_change_date_card);
        break;
    case PAYMENT_CL:
        ro = !r__(cr__rv_change_date_cl);
        break;
    }
    ui->deDate->setReadOnly(ro);
    if (ro) {
        ui->deDate->setDate(WORKING_DATE);
    }
}
