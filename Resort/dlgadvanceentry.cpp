#include "dlgadvanceentry.h"
#include "ui_dlgadvanceentry.h"
#include "cachereservation.h"
#include "pprintpreview.h"
#include "ptextrect.h"
#include "pimage.h"
#include "cacheredreservation.h"
#include "vauchers.h"
#include "pprintscene.h"
#include "paymentmode.h"
#include "dlgprinttaxsm.h"
#include "pprintvaucher.h"
#include "cachecladvance.h"
#include "cachepaymentmode.h"
#include "voucher_tc.h"

#define HINT_PAYMENT_MODE 1
#define HINT_RED_RESERVATION 2
#define HINT_CITY_LEDGER 3

DlgAdvanceEntry::DlgAdvanceEntry(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_RESERVATION, parent),
    ui(new Ui::DlgAdvanceEntry)
{
    ui->setupUi(this);
    ui->leUser->setInt(WORKING_USERID);
    ui->leUser->setVisible(false);
    ui->lbOperator->setVisible(false);
    ui->lineEdit->setVisible(false ); // canceled
    ui->btnPrint->setEnabled(false);
    ui->lePaymentCode->setValidator(new QIntValidator());
    ui->leCityLedgerCode->setValidator(new QIntValidator());
    ui->leAmount->setValidator(new QDoubleValidator(0, 999999999, 2));
    ui->grCard->setVisible(false);
    ui->grCityLedger->setVisible(false);
    ui->leTCVoucher->setVisible(false);

    ui->lePaymentCode->setSelector(this, cache(cid_payment_mode), ui->lePaymentName, HINT_PAYMENT_MODE);
    ui->lePaymentCode->fCodeFilter << QString::number(PAYMENT_CASH)
                                     << QString::number(PAYMENT_CARD)
                                     << QString::number(PAYMENT_CL)
                                     << QString::number(PAYMENT_BANK);

    ui->leReserveId->setSelector(this, cache(cid_red_reservation), ui->leReserveId, HINT_RED_RESERVATION);
    ui->leCardCode->setSelector(this, cache(cid_credit_card), ui->leCardName);
    ui->leCityLedgerCode->setSelector(this, cache(cid_city_ledger), ui->leCityLedgerName, HINT_CITY_LEDGER);

    addWidget(ui->leState, "");
    addWidget(ui->leUser, "User");
    addWidget(ui->leReserveId, "");
    addWidget(ui->deDate, "Advance date");
    addWidget(ui->lePaymentCode, "");
    addWidget(ui->lePaymentName, "Payment mode");
    addWidget(ui->leCityLedgerCode, "");
    addWidget(ui->leCityLedgerName, "City ledger");
    addWidget(ui->leCardCode, "");
    addWidget(ui->lineEdit, "");
    addWidget(ui->leCardName, "Card");
    addWidget(ui->leAmount, "Amount of advance");
    addWidget(ui->leAmountUSD, "Amount of advance, USD");
    addWidget(ui->teRemarks, "Remarks");
    fCacheId = cid_red_reservation;
    ui->lbState->setVisible(false);
    ui->leState->setVisible(false);
    adjustSize();
}

DlgAdvanceEntry::~DlgAdvanceEntry()
{
    delete ui;
}

void DlgAdvanceEntry::callback(int sel, const QString &code)
{
    switch (sel) {
    case HINT_PAYMENT_MODE: {
        CachePaymentMode c;
        ui->leCLbalance->setText(0);
        ui->leCityLedgerCode->clear();
        if (c.get(code)) {
            ui->grCard->setVisible(false);
            ui->grCityLedger->setVisible(false);
            switch (c.fCode().toInt()) {
            case PAYMENT_CARD:
                ui->grCard->setVisible(true);
                //ui->leCardCode->customButtonClicked(true);
                break;
            case PAYMENT_CL:
                ui->grCityLedger->setVisible(true);
                //ui->leCityLedgerCode->customButtonClicked(true);
                break;
            }
            adjustSize();
        }
        break;
    }
    case HINT_RED_RESERVATION: {
        fTrackControl->fInvoice = "";
        fTrackControl->fReservation = "";
        CacheRedReservation c;
        if (c.get(code)) {
            ui->leBalance->setText(c.fBalance());
            ui->leRoom->setText(c.fRoom());
            ui->leInvoice->setText(c.fInvoice());
            ui->leGuest->setText(c.fGuest());
            fTrackControl->fInvoice = c.fInvoice();
            fTrackControl->fReservation = c.fCode();
        }
        break;
    }
    case HINT_CITY_LEDGER: {
        CacheCityLedger c;
        ui->chUserFromBalance->setEnabled(false);
        if (c.get(code)) {
            CacheCLAdvance ca;
            if (ca.get(c.fCode())) {
                ui->leCLbalance->setText(ca.fAmount());
                ui->chUserFromBalance->setEnabled(ca.fAmount() > 0.01);
            }
        } else {
            ui->leCLbalance->setText(0);
        }
        break;
    }
    }
}

bool DlgAdvanceEntry::isDataCorrect()
{
    if (ui->leReserveId->asInt() == 0) {
        fDataErrors.append(tr("Incorrect reservation number"));
    }
    if (ui->leAmount->asDouble() < 0.01) {
        fDataErrors.append(tr("Incorrect amount"));
    }
    switch (ui->lePaymentCode->asInt()) {
    case 0:
        fDataErrors.append(tr("Payment mode is not correct"));
        break;
    case PAYMENT_CL:
        if (ui->leCityLedgerCode->asInt() == 0) {
            fDataErrors.append(tr("Selected city ledger is not correct"));
        }
        break;
    case PAYMENT_CARD:
        if (ui->leCardCode->asInt() == 0) {
            fDataErrors.append(tr("Select card type"));
        }
    }
    return fDataErrors.count() == 0;
}

void DlgAdvanceEntry::advance(const QString &code)
{
    QList<QVariant> values;
    DlgAdvanceEntry *d = new DlgAdvanceEntry(values, fPreferences.getDefaultParentForMessage());
    d->ui->leReserveId->setInitialValue(code);
    d->exec();
    delete d;
}

void DlgAdvanceEntry::on_btnCancel_clicked()
{
    reject();
}

void DlgAdvanceEntry::on_btnSave_clicked()
{
    QString finalName;
    switch (ui->lePaymentCode->asInt()) {
    case PAYMENT_CARD:
        finalName = "CC/" + ui->leCardName->text();
        break;
    case PAYMENT_CASH:
        finalName = "CASH";
        break;
    case PAYMENT_CL:
        finalName = "CL/" + ui->leCityLedgerName->text();
        if (ui->chUserFromBalance->isChecked()) {
            if (ui->leAmount->asDouble() > ui->leCLbalance->asDouble()) {
                message_error(tr("Not enough money on the C/L balance"));
                return;
            }
        }
        break;
    case PAYMENT_BANK:
        finalName = "BANK";
        break;
    default:
        message_error(tr("Selected mode of payment is not allowed here"));
        return;
    }
    //finalName += " " + WORKING_DATE.toString(def_date_format);

    bool isNew = false;
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.startTransaction();
    if (ui->leVaucher->isEmpty()) {
        isNew = true;
        ui->leVaucher->setText(uuid(VAUCHER_ADVANCE_N));
        fDD.insertId("m_register", ui->leVaucher->text());
    }
    fDD[":f_source"] = VAUCHER_ADVANCE_N;
    if (isNew) {
        fDD[":f_wdate"] = WORKING_DATE;
        fDD[":f_rdate"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_user"] = WORKING_USERID;
    } else {
        if (r__(cr__super_correction)) {
            fDD[":f_wdate"] = ui->deDate->date();
        }
    }
    fDD[":f_room"] = ui->leRoom->text();
    fDD[":f_guest"] = ui->leGuest->text();
    fDD[":f_itemCode"] = fPreferences.getDb(def_receip_vaucher_id);
    fDD[":f_finalName"] = tr("ADVANCE") + " " + finalName;
    fDD[":f_amountAmd"] = ui->leAmount->asDouble();
    fDD[":f_amountVat"] = 0;
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = 0;
    fDD[":f_paymentMode"] = ui->lePaymentCode->asInt();
    fDD[":f_creditCard"] = ui->leCardCode->asInt();
    fDD[":f_cityLedger"] = ui->leCityLedgerCode->asInt();
    fDD[":f_paymentComment"] = vaucherPaymentName(ui->lePaymentCode->asInt(), ui->leCardCode->text(), ui->leCityLedgerCode->text());
    fDD[":f_dc"] = "CREDIT";
    fDD[":f_sign"] = -1;
    fDD[":f_doc"] = "";
    fDD[":f_rec"] = "";
    fDD[":f_res"] = ui->leReserveId->text();
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD[":f_finance"] = 1;
    fDD[":f_remarks"] = ui->teRemarks->toPlainText();
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    fDD[":f_side"] = 0;
    fDD[":f_cash"] = ui->chUserFromBalance->isChecked() ? 0 : 1;
    fDD.update("m_register", where_id(ap(ui->leVaucher->text())));
    fDD.commit();
    ui->btnSave->setEnabled(false);
    ui->btnPrint->setEnabled(true);
    ui->leReserveId->setEnabled(false);
    BroadcastThread::cmdRefreshCache(cid_red_reservation, ui->leReserveId->text());

    if (isNew) {
        if (ui->chUserFromBalance->isChecked()) {
            voucher_tc tc;
            QString tcId = tc.genId("TC");
            tc.set("f_id", tcId);
            tc.set("f_res", ui->leReserveId->text())
                .set("f_wdate", WORKING_DATE)
                .set("f_rdate", QDate::currentDate())
                .set("f_time", QTime::currentTime())
                .set("f_user", WORKING_USERID)
                .set("f_room", ui->leRoom->text())
                .set("f_guest", ui->leGuest->text())
                .set("f_itemCode", VAUCHER_TRANSFER_CL)
                .set("f_finalName", finalName)
                .set("f_amountAmd", ui->leAmount->asDouble())
                .set("f_usedPrepaid", 0)
                .set("f_amountVat", 0)
                .set("f_amountUsd", def_usd)
                .set("f_fiscal", 0)
                .set("f_paymentMode", 0)
                .set("f_creditCard", 0)
                .set("f_cityLedger", ui->leCityLedgerCode->asInt())
                .set("f_paymentComment", "")
                .set("f_dc", "CREDIT")
                .set("f_sign", -1)
                .set("f_doc", ui->leVaucher->text())
                .set("f_inv", ui->leVaucher->text())
                .set("f_finance", 1)
                .set("f_remarks", "")
                .set("f_side", 1)
                .set("f_canceled", 0)
                .set("f_cancelReason", "")
                .set("f_cancelDate", QDate::currentDate())
                .set("f_cancelUser", 0)
                .set("p", 0)
                .set("f_usedTaxId", 0)
                .set("f_rb", 0)
                .set("f_cash", 0);
            tc.saveVoucher();

            fDD[":f_doc"] = tcId;
            fDD.update("m_register", where_id(ap(ui->leVaucher->text())));
        }
    }


    QString msg = isNew ? "New advance" : "Advance modified";
    msg += " " + ui->leVaucher->text();
    QString v2;
    if (ui->chUserFromBalance->isChecked()) {
        v2 += " [Transfer from C/L " + ui->leCityLedgerCode->text() + "]";
    }
    QString value = ui->deDate->text() + "/" + ui->leRoom->text()
            + "/" + ui->leGuest->text() + "/" + ui->lePaymentName->text()
            + "/" + ui->leCardName->text() + "/" + finalName
            + "/" + float_printout(ui->leAmount->asDouble());
    fTrackControl->insert(msg, value, v2);
}

void DlgAdvanceEntry::on_leAmount_textChanged(const QString &arg1)
{
    ui->leAmountUSD->setDouble(arg1.toDouble() / def_usd);
}

void DlgAdvanceEntry::on_btnPrint_clicked()
{
   PPrintVaucher::printVaucher(ui->leVaucher->text());
}

void DlgAdvanceEntry::on_btnNew_clicked()
{
    accept();
    QList<QVariant> v;
    DlgAdvanceEntry *d = new DlgAdvanceEntry(v, fPreferences.getDefaultParentForMessage());
    d->exec();
    delete d;
}

void DlgAdvanceEntry::on_btnPrintTax_clicked()
{
    if (ui->leVaucher->text().isEmpty()) {
        message_error(tr("Save first"));
        return;
    }
    if (ui->leTax->asInt() > 0) {
        message_error(tr("Already printed"));
        return;
    }

    double cash = ui->lePaymentCode->asInt() == PAYMENT_CASH ? ui->leAmount->asDouble() : 0;
    double card = ui->lePaymentCode->asInt() == PAYMENT_CARD ? ui->leAmount->asDouble() : 0;
    int taxCode;
    if (!DlgPrintTaxSM::printAdvance(cash, card, ui->leVaucher->text(), taxCode)) {
        return;
    }
    //PrintTax::printAdvance(ui->leAmount->asDouble(), ui->lePaymentCode->asInt(), QString("AV%1").arg(ui->leVaucher->text()));
    ui->leTax->setInt(taxCode);
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_vaucher"] = ui->leVaucher->text();
    fDD[":f_invoice"] = "";
    fDD[":f_date"] = QDate::currentDate();
    fDD[":f_time"] = QTime::currentTime();
    fDD[":f_name"] = tr("ADVANCE") + " " + ui->lePaymentName->text() + " " + ui->leCardName->text() + ui->leCityLedgerName->text();
    fDD[":f_amountCash"] = ui->lePaymentCode->asInt() == PAYMENT_CASH ? ui->leAmount->asDouble() : 0;
    fDD[":f_amountCard"] = ui->lePaymentCode->asInt() == PAYMENT_CASH ? 0 : ui->leAmount->asDouble();
    fDD[":f_amountPrepaid"] = 0;
    fDD[":f_user"] = WORKING_USERID;
    fDD[":f_comp"] = HOSTNAME;
    fDD.insert("m_tax_history");

    fTrackControl->insert("Tax printed", ui->leVaucher->text(), ui->leAmount->text());
}
