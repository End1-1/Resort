#include "wvauchereditor.h"
#include "ui_wvauchereditor.h"
#include "message.h"
#include "dlgtracking.h"
#include "pprintvaucher.h"
#include "dlgnewvaucheroption.h"
#include "cacheusers.h"
#include "cacheinvoiceitem.h"
#include "cachepaymentmode.h"
#include "cachevatmode.h"
#include "cachecityledger.h"
#include "cachecheckoutinvoice.h"
#include "paymentmode.h"
#include "cachevaucher.h"
#include "vauchers.h"

static const int HINT_INVOIC_ITEM = 1;
static const int HINT_PAYMENT_MODE = 2;
static const int HINT_VAT = 3;
static const int HINT_CARD = 4;
static const int HINT_CL = 5;
static const int HINT_INVOICE = 6;

WVaucherEditor::WVaucherEditor(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::WVaucherEditor)
{
    ui->setupUi(this);
    fTc = new TrackControl(TRACK_VAUCHER);
    fTc->addWidget(ui->leSourceCode, "Source")
            .addWidget(ui->deWorking, "Working date")
            .addWidget(ui->deReal, "Real date")
            .addWidget(ui->teTime, "Time")
            .addWidget(ui->leUserCode, "User")
            .addWidget(ui->leRoom, "Room")
            .addWidget(ui->leGuestName, "Guest")
            .addWidget(ui->leItemCode, "Item")
            .addWidget(ui->leFinalName, "Final name")
            .addWidget(ui->leAmount, "Amount")
            .addWidget(ui->lePrepaid, "Prepaid")
            .addWidget(ui->leVAT, "VAT")
            .addWidget(ui->leUSD, "USD rate")
            .addWidget(ui->lePayCode, "Payment mode")
            .addWidget(ui->leFiscal, "Fiscal")
            .addWidget(ui->leCardCode, "Card code")
            .addWidget(ui->leCLCode, "City ledger code")
            .addWidget(ui->lePayComment, "Payment comment")
            .addWidget(ui->leDC, "Debit/Credit")
            .addWidget(ui->leSign, "Sign")
            .addWidget(ui->leInvoice, "Invoice")
            .addWidget(ui->leFinFlag, "Finance flag")
            .addWidget(ui->leCancelFlag, "Cancel flag")
            .addWidget(ui->leCancelReason, "Cancel reason")
            .addWidget(ui->leCancelUserCode, "Cancel user")
            .addWidget(ui->deCancelDate, "Cancel date")
            .addWidget(ui->leGuestCompany, "Guest/Company side")
            .addWidget(ui->teRemarks, "Remarks")
            .addWidget(ui->leVATCode, "Vat mode")
            .addWidget(ui->leRb, "RB")
            .addWidget(ui->leDoc, "Doc")
            .addWidget(ui->leRec, "Rec")
            ;
    ui->leUserCode->setSelector(this, cache(cid_users), ui->leUserName);
    ui->leCancelUserCode->setSelector(this, cache(cid_users), ui->leCancelUserName);
    ui->leItemCode->setSelector(this, cache(cid_invoice_item), ui->leItemName, HINT_INVOIC_ITEM);
    ui->leSourceCode->setSelector(this, cache(cid_vaucher), ui->leSourceName);
    ui->lePayCode->setSelector(this, cache(cid_payment_mode), ui->lePayName, HINT_PAYMENT_MODE);
    ui->leVATCode->setSelector(this, cache(cid_vat_mode), ui->leVATName, HINT_VAT);
    ui->leVATCode->setInitialValue(VAT_INCLUDED);
    ui->leCardCode->setSelector(this, cache(cid_credit_card), ui->leCardName, HINT_CARD);
    ui->leCLCode->setSelector(this, cache(cid_city_ledger), ui->leCLName, HINT_CL);

    fFlagNew = false;
}

WVaucherEditor::~WVaucherEditor()
{
    delete ui;
}

void WVaucherEditor::callback(int sel, const QString &code)
{
    switch (sel) {
    case HINT_INVOIC_ITEM: {
        CacheInvoiceItem ci;
        if (fFlagNew && ci.get(code)) {
            ui->leSourceCode->setInitialValue(ci.fVaucher());
            if (ui->leSourceCode->text() == VAUCHER_ROOMING_N) {
                ui->leFinalName->setText(ui->leItemName->text() + " " + ui->deWorking->text());
            } else{
                ui->leFinalName->setText(ui->leItemName->text());
            }
        }
        break;
    }
    case HINT_PAYMENT_MODE: {
        CachePaymentMode ci;
        if (ci.get(code) && fFlagNew) {
            switch (ci.fCode().toInt()) {
            case PAYMENT_CASH:
                ui->lePayComment->setText(tr("CASH"));
                ui->leFinalName->setText(tr("PAYMENT CASH"));
                break;
            case PAYMENT_CARD:
                ui->lePayComment->setText("");
                ui->leFinalName->setText(tr("PAYMENT CARD"));
                break;
            case PAYMENT_CL:
                ui->lePayComment->setText("");
                ui->leFinalName->setText(tr("PAYMENT CL"));
                break;
            }
        }
        break;
    }
    case HINT_VAT: {
        CacheVatMode ci;
        if (ci.get(code)) {
            if (ui->leSourceCode->text() == VAUCHER_POSTCHARGE_N
                    || ui->leSourceCode->text() == VAUCHER_ROOMING_N
                    || ui->leSourceCode->text() == VAUCHER_RECEIPT_N) {
                ui->leVAT->setDouble(Utils::countVATAmount(ui->leAmount->asDouble(), ui->leVATCode->asInt()));
            }
        }
        break;
    }
    case HINT_CARD: {
        CacheCreditCard ci;
        if (ci.get(code) && fFlagNew) {
            if (ui->lePayCode->asInt() == PAYMENT_CARD) {
                ui->leFinalName->setText("PAYMENT " + ci.fName());
                ui->lePayComment->setText(ci.fName());
            }
        }
        break;
    }
    case HINT_CL: {
        CacheCityLedger ci;
        if (ci.get(code) && fFlagNew) {
            if (ui->lePayCode->asInt() == PAYMENT_CL) {
                ui->leFinalName->setText("PAYMENT " + ci.fName());
                ui->lePayComment->setText(ci.fName());
            }
        }
        break;
    }
    case HINT_INVOICE: {
        CacheCheckoutInvoice ci;
        if (ci.get(code)) {
            ui->leInvoice->setText(ci.fCode());
            loadInvoice();
        }
        break;
    }
    }
}

void WVaucherEditor::load(const QString &id)
{
    WVaucherEditor *ve = new WVaucherEditor(fPreferences.getDefaultParentForMessage());
    if (!id.isEmpty()) {
        ve->loadVaucher(id);
    }
    ve->exec();
    delete ve;
}

void WVaucherEditor::newVaucher(const QString &invoice)
{
    WVaucherEditor *ve = new WVaucherEditor(fPreferences.getDefaultParentForMessage());
    ve->ui->leInvoice->setText(invoice);
    ve->loadInvoice();
    ve->setNewFlag();
    ve->exec();
    delete ve;
}

void WVaucherEditor::loadVaucher(const QString &id)
{
    DoubleDatabase fDD;
    ui->leCode->setText(id);
    fDD[":f_id"] = id;    
    fDD.exec("select * from m_register where f_id=:f_id");
    if (!fDD.nextRow()) {
        message_error(tr("Incorrect vaucher id"));
        return;
    }

    ui->leSourceCode->setInitialValue(fDD.getValue("f_source").toString());
    ui->deWorking->setDate(fDD.getValue("f_wdate").toDate());
    ui->deReal->setDate(fDD.getValue("f_rdate").toDate());
    ui->teTime->setTime(fDD.getValue("f_time").toTime());
    ui->leUserCode->setInitialValue(fDD.getValue("f_user").toString());
    ui->leRoom->setText(fDD.getValue("f_room").toString());
    ui->leGuestName->setText(fDD.getValue("f_guest").toString());
    ui->leItemCode->setInitialValue(fDD.getValue("f_itemCode").toString());
    ui->leFinalName->setText(fDD.getValue("f_finalName").toString());
    ui->leAmount->setText(fDD.getValue("f_amountAmd").toString());
    ui->lePrepaid->setText(fDD.getValue("f_usedPrepaid").toString());
    ui->leVAT->setText(fDD.getValue("f_amountVat").toString());
    ui->leVATCode->setInitialValue(fDD.getString("f_vatmode"));
    ui->leUSD->setText(fDD.getValue("f_amountUsd").toString());
    ui->leFiscal->setText(fDD.getValue("f_fiscal").toString());
    ui->lePayCode->setInitialValue(fDD.getValue("f_paymentMode").toString());
    ui->leCardCode->setInitialValue(fDD.getValue("f_creditCard").toString());
    ui->leCLCode->setInitialValue(fDD.getValue("f_cityLedger").toString());
    ui->lePayComment->setText(fDD.getValue("f_paymentComment").toString());
    ui->leDC->setText(fDD.getValue("f_dc").toString());
    ui->leSign->setText(fDD.getValue("f_sign").toString());
    ui->leInvoice->setText(fDD.getValue("f_inv").toString());
    ui->leReservation->setText(fDD.getValue("f_res").toString());
    ui->leFinFlag->setText(fDD.getValue("f_finance").toString());
    ui->leCancelFlag->setText(fDD.getValue("f_canceled").toString());
    ui->leCancelReason->setText(fDD.getValue("f_cancelReason").toString());
    ui->deCancelDate->setDateTime(fDD.getValue("f_cancelDate").toDateTime());
    ui->leCancelUserCode->setInitialValue(fDD.getValue("f_cancelUser").toString());
    ui->leGuestCompany->setText(fDD.getValue("f_side").toString());
    ui->teRemarks->setPlainText(fDD.getValue("f_remarks").toString());
    ui->leRb->setText(fDD.getString("f_rb"));
    ui->leDoc->setText(fDD.getString("f_doc"));
    ui->leRec->setText(fDD.getString("f_rec"));
    fTc->resetChanges();
    fTc->fReservation = ui->leReservation->text();
    fTc->fInvoice = ui->leInvoice->text();
    fTc->fRecord = ui->leCode->text();
}

bool WVaucherEditor::errorCheck()
{
    QString errors;
    if (ui->leSourceName->isEmpty()) {
        errors += tr("Vaucher type is not selected") + "<br>";
    }
    if (!errors.isEmpty()) {
        message_error(errors);
    }
    return errors.isEmpty();
}

void WVaucherEditor::loadInvoice()
{
    CacheCheckoutInvoice ci;
    if (!ci.get(ui->leInvoice->text())) {
        return;
    }
    ui->leInvoice->setText(ci.fCode());
    ui->leReservation->setText(ci.fReservation());
    ui->leRoom->setText(ci.fRoom());
    ui->leGuestName->setText(ci.fGuest());
}

void WVaucherEditor::setNewFlag()
{
    int vo = DlgNewVaucherOption::vaucherOption();
    if (!vo) {
        return;
    }
    fFlagNew = true;
    switch (vo) {
    case VO_RV:
        ui->leSourceCode->setInitialValue(VAUCHER_RECEIPT_N);
        setRV();
        break;
    case VO_PS:
        ui->leSourceCode->setInitialValue(VAUCHER_POSTCHARGE_N);
        setPS();
        break;
    default:
        break;
    }
}

void WVaucherEditor::setRV()
{
    ui->leCancelFlag->setText("0");
    ui->leCancelReason->setText("");
    ui->leCancelUserCode->setText("0");
    ui->leCancelUserName->setText("");
    ui->leUSD->setDouble(def_usd);
    ui->deWorking->setDate(QDate::currentDate());
    ui->deReal->setDate(QDate::currentDate());
    ui->teTime->setTime(QTime::currentTime());
    ui->leItemCode->setInitialValue(fPreferences.getDb(def_receip_vaucher_id).toInt());
    ui->leVATCode->setInitialValue(VAT_NOVAT);
    ui->leUserCode->setInitialValue(WORKING_USERID);
    ui->lePayCode->setInitialValue(PAYMENT_CASH);
    ui->leSign->setText("-1");
    ui->leFinFlag->setText("1");
    ui->lePayComment->setText(tr("CASH"));
    ui->leFinalName->setText(tr("PAYMENT CASH"));
    ui->leDC->setText("CREDIT");
}

void WVaucherEditor::setPS()
{
    ui->leCancelFlag->setText("0");
    ui->leCancelReason->setText("");
    ui->leCancelUserCode->setText("0");
    ui->leCancelUserName->setText("");
    ui->leUSD->setDouble(def_usd);
    ui->deWorking->setDate(QDate::currentDate());
    ui->deReal->setDate(QDate::currentDate());
    ui->teTime->setTime(QTime::currentTime());
    ui->leItemCode->setInitialValue(0);
    ui->leUserCode->setInitialValue(WORKING_USERID);
    ui->lePayCode->setInitialValue(PAYMENT_CREDIT);
    ui->leSign->setText("1");
    ui->leFinFlag->setText("1");
    ui->lePayComment->setText(tr("CREDIT"));
    ui->leFinalName->setText(ui->leItemName->text());
    ui->leDC->setText("DEBIT");
}

void WVaucherEditor::on_btnSave_clicked()
{
    if (!errorCheck()) {
        return;
    }
    DoubleDatabase fDD;
    if (fFlagNew) {
        ui->leCode->setText(uuidx(ui->leSourceCode->text()));
        fDD[":f_id"] = ui->leCode->text();
        fDD.insert("m_register", false);
    }
    fDD[":f_source"] = ui->leSourceCode->text();
    fDD[":f_wdate"] = ui->deWorking->date();
    fDD[":f_rdate"] = ui->deWorking->date();
    fDD[":f_time"] = ui->teTime->time();
    fDD[":f_user"] = ui->leUserCode->asInt();
    fDD[":f_room"] = ui->leRoom->text();
    fDD[":f_guest"] = ui->leGuestName->text();
    fDD[":f_itemCode"] = ui->leItemCode->asInt();
    fDD[":f_finalName"] = ui->leFinalName->text();
    fDD[":f_amountAmd"] = ui->leAmount->asDouble();
    fDD[":f_usedPrepaid"] = ui->lePrepaid->asDouble();
    fDD[":f_amountVat"] = ui->leVAT->asDouble();
    fDD[":f_amountUSD"] = ui->leUSD->asDouble();
    fDD[":f_vatmode"] = ui->leVATCode->asInt();
    fDD[":f_fiscal"] = ui->leFiscal->asInt();
    fDD[":f_paymentMode"] = ui->lePayCode->asInt();
    fDD[":f_creditCard"] = ui->leCardCode->asInt();
    fDD[":f_cityLedger"] = ui->leCLCode->asInt();
    fDD[":f_paymentComment"] = ui->lePayComment->text();
    fDD[":f_dc"] = ui->leDC->text();
    fDD[":f_sign"] = ui->leSign->asInt();
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD[":f_res"] = ui->leReservation->text();
    fDD[":f_doc"] = ui->leDoc->text();
    fDD[":f_rec"] = ui->leRec->text();
    fDD[":f_finance"] = ui->leFinFlag->asInt();
    fDD[":f_canceled"] = ui->leCancelFlag->asInt();
    fDD[":f_cancelUser"] = ui->leCancelUserCode->asInt();
    fDD[":f_cancelDate"] = ui->deCancelDate->dateTime();
    fDD[":f_cancelReason"] = ui->leCancelReason->text();
    fDD[":f_side"] = ui->leGuestCompany->asInt();
    fDD[":f_remarks"] = ui->teRemarks->toPlainText();
    fDD[":f_rb"] = ui->leRb->asInt();
    fDD.update("m_register", where_id(ap(ui->leCode->text())));
    fTc->saveChanges();
    fFlagNew = false;
    message_info(tr("Saved"));
}

void WVaucherEditor::on_btnTrack_clicked()
{
    DlgTracking::showTracking(TRACK_VAUCHER, ui->leCode->text());
}

void WVaucherEditor::on_btnPrint_clicked()
{
    if (ui->leCode->isEmpty()) {
        message_error(tr("Vaucher is not saved"));
        return;
    }
    PPrintVaucher::printVaucher(ui->leCode->text());
}

void WVaucherEditor::on_btnNewVaucher_clicked()
{

}

void WVaucherEditor::on_deWorking_textChanged(const QString &arg1)
{
    if (fFlagNew) {
        if (ui->leSourceCode->text() == VAUCHER_ROOMING_N) {
            ui->leFinalName->setText(ui->leItemName->text() + " " + arg1);
        }
    }
}

void WVaucherEditor::on_leAmount_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    if (ui->leSourceCode->text() == VAUCHER_POSTCHARGE_N
            || ui->leSourceCode->text() == VAUCHER_ROOMING_N
            || ui->leSourceCode->text() == VAUCHER_RECEIPT_N) {
        ui->leVAT->setDouble(Utils::countVATAmount(ui->leAmount->asDouble(), ui->leVATCode->asInt()));
    }
}
