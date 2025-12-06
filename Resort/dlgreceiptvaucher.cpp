#include "dlgreceiptvaucher.h"
#include "ui_dlgreceiptvaucher.h"
#include "pprintpreview.h"
#include "ptextrect.h"
#include "pprintheader.h"
#include "cachepaymentmode.h"
#include "vauchers.h"
#include "pimage.h"
#include "printtaxn.h"
#include "dlgtracking.h"
#include "cacheactiveroom.h"
#include "cacheroom.h"
#include "paymentmode.h"
#include "pprintvaucher.h"
#include "cacheusers.h"
#include "databaserow.h"
#include "winvoice.h"

#define HINT_ACTIVE_ROOM 1
#define HINT_CITY_LEDGER 2
#define HINT_PAYMENT_MODE 3
#define HINT_CARD 4

DlgReceiptVaucher::DlgReceiptVaucher(int fiscalmachine, double suggestAmount, int side, QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgReceiptVaucher)
{
    ui->setupUi(this);
    ui->leOpcode->setSelector(this, cache(cid_users), ui->leOpName);
    ui->leOpcode->setInitialValue(WORKING_USERID);
    ui->leFinalName->setReadOnly(!r__(cr__super_correction));
    ui->deDate->setDate(WORKING_DATE);
    ui->leCL->setSelector(this, cache(cid_city_ledger), ui->leCLName);
    ui->lePaymentCode->setSelector(this, cache(cid_payment_mode), ui->lePaymentName, HINT_PAYMENT_MODE);

    if(side == 0) {
        ui->lePaymentCode->fCodeFilter << QString::number(PAYMENT_CASH)
                                       << QString::number(PAYMENT_CARD)
                                       << QString::number(PAYMENT_BANK)
                                       << QString::number(PAYMENT_BARTER)
                                       << QString::number(PAYMENT_CL)
                                       << QString::number(PAYMENT_PAYX)
                                       << QString::number(PAYMENT_TERMINAL)
                                       << QString::number(PAYMENT_CPAY);
    } else {
        ui->lePaymentCode->fCodeFilter << QString::number(PAYMENT_CL);
    }

    ui->leCardCode->setSelector(this, cache(cid_credit_card), ui->leCardName, HINT_CARD);
    cardVisible(false);
    clVisible(false);
    fTrackControl = new TrackControl(TRACK_RESERVATION);
    fDoc.setleID(ui->leVaucher);
    fDoc.fSource = VAUCHER_RECEIPT_N;
    ui->wRoom->setDBMRegister(&fDoc);
    ui->wCL->setDBMRegister(&fDoc);
    fDoc.setleWDate(ui->deDate);
    fDoc.fItemCode = fPreferences.getDb(def_receip_vaucher_id).toUInt();
    fDoc.fFinance = 1;
    fDoc.fSide = side;
    fDoc.setleFinalName(ui->leFinalName);
    fDoc.setlePaymentMode(ui->lePaymentCode, ui->lePaymentName);
    fDoc.setleAmountAMD(ui->leAmountAMD);
    fDoc.setleAmountUSD(ui->leAmountUSD);
    fDoc.setleCreditCard(ui->leCardCode, ui->leCardName);
    fDoc.setleRemarks(ui->teRemarks);
    ui->btnLog->setVisible(fPreferences.getDb(def_show_logs).toBool());
    on_tabWidget_currentChanged(0);
    fDoc.fFiscalMachine = fiscalmachine;
    DoubleDatabase dd;

    if(fDoc.fFiscalMachine > 0) {
        if(row_of_id(dd, "s_tax_map", fDoc.fFiscalMachine)) {
            ui->leFiscalMachine->setText(dd.getString("f_name"));
        }
    }

    fSuggestAmount = suggestAmount;
    ui->btnSuggestAmount->setText(float_str(suggestAmount));
    ui->lbSuggestAmount->setVisible(suggestAmount > 0.01);
    ui->btnSuggestAmount->setVisible(suggestAmount > 0.01);
    adjustSize();
}

DlgReceiptVaucher::~DlgReceiptVaucher()
{
    delete ui;
}

void DlgReceiptVaucher::setVoucher(const QString &id)
{
    clearSelectors();
    DoubleDatabase dd;
    fDoc.open(dd, id);

    switch(ui->lePaymentCode->asInt()) {
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
        cardVisible(true);
        break;

    default:
        ui->deDate->setReadOnly(!r__(cr__change_rv_other_types));
        break;
    }

    if(fDoc.fFiscalMachine > 0) {
        if(row_of_id(dd, "s_tax_map", fDoc.fFiscalMachine)) {
            ui->leFiscalMachine->setText(dd.getString("f_name"));
        }
    }

    fixTabWidget();
    setBalance();
    ui->btnSave->setVisible(r__(cr__super_correction));
    ui->leAmountAMD->setReadOnly(!r__(cr__super_correction));
//    if (r__(cr__super_correction)) {
//        ui->deDate->setReadOnly(false);
//    }
    ui->btnPrint->setEnabled(true);
    adjustSize();
}

void DlgReceiptVaucher::callback(int sel, const QString &code)
{
    switch(sel) {
    case HINT_PAYMENT_MODE: {
        CachePaymentMode c;

        if(c.get(code)) {
            switch(c.fCode().toInt()) {
            case PAYMENT_CASH:
                cardVisible(false);
                clVisible(false);
                ui->leFinalName->setText(tr("PAYMENT CASH"));
                break;

            case PAYMENT_CARD:
                clVisible(false);
                cardVisible(true);
                break;

            case PAYMENT_BANK:
                clVisible(false);
                cardVisible(false);
                ui->leFinalName->setText(tr("PAYMENT BANK"));
                break;

            case PAYMENT_PAYX:
                cardVisible(false);
                clVisible(false);
                ui->leFinalName->setText(tr("PAYMENT PAYX"));
                break;

            case PAYMENT_TERMINAL:
                cardVisible(false);
                clVisible(false);
                ui->leFinalName->setText(tr("PAYMENT TERMINAL"));
                break;

            case PAYMENT_CPAY:
                cardVisible(false);
                clVisible(false);
                ui->leFinalName->setText(tr("PAYMENT CPAY"));
                break;

            case PAYMENT_CL:
                clVisible(true);
                ui->leFinalName->setText(QString("CHECKOUT %1, %2").arg(ui->wRoom->room()).arg(ui->wRoom->guest()));
                break;

            default:
                cardVisible(false);
                clVisible(false);
                ui->leFinalName->setText("PAYMENT " + c.fName());
                break;
            }
        }

        break;
    }

    case HINT_CARD: {
        CacheCreditCard c;

        if(c.get(code)) {
            ui->leFinalName->setText(tr("PAYMENT") + " " + c.fName());
        }

        break;
    }
    }
}

void DlgReceiptVaucher::setSide(quint32 side)
{
    fDoc.fSide = side;

    if(side == 1) {
        ui->lePaymentCode->fCodeFilter << QString::number(PAYMENT_CASH)
                                       << QString::number(PAYMENT_CARD)
                                       << QString::number(PAYMENT_BANK)
                                       << QString::number(PAYMENT_BARTER)
                                       << QString::number(PAYMENT_CL);
    }
}

void DlgReceiptVaucher::setCL(int cl)
{
    ui->lePaymentCode->setInitialValue(PAYMENT_CL);
    ui->leCL->setInitialValue(cl);
}

void DlgReceiptVaucher::setInvoice(const QString &invoice)
{
    DoubleDatabase dd;
    dd[":f_invoice"] = invoice;
    dd.exec("select f_room from f_reservation where f_invoice=:f_invoice");

    if(dd.nextRow()) {
        setRoom(dd.getInt("f_room"));
    }
}

void DlgReceiptVaucher::setRoom(int room)
{
    ui->wRoom->setRoom(room);
}

void DlgReceiptVaucher::setPaymentMode(int mode, int cl)
{
    ui->lePaymentCode->setInitialValue(mode);

    if(cl > 0) {
        ui->leCL->setInitialValue(cl);
    }
}

void DlgReceiptVaucher::setAmount(double amount)
{
    ui->leAmountAMD->setDouble(amount);
}

void DlgReceiptVaucher::on_btnSave_clicked()
{
    QString errors;

    if(ui->leAmountAMD->asDouble() < 0.1) {
        errors += tr("Amount cannot be equal to zero.") + "<br>";
    }

    QString dc = "DEBIT";
    int sign = -1;
    QString finalName = tr("PAYMENT") + " ";
    QString room;

    switch(ui->tabWidget->currentIndex()) {
    case 0:
        if(ui->wRoom->room() == 0) {
            errors += tr("Room is not selected") + "<br>";
        } else {
            room = QString::number(ui->wRoom->room());
        }

        switch(ui->lePaymentCode->asInt()) {
        case PAYMENT_CASH:
            finalName += "CASH";
            break;

        case PAYMENT_BANK:
            finalName += "BANK";
            break;

        case PAYMENT_CARD:
            finalName += ui->leCardName->text();
            break;

        case PAYMENT_CL:
            if(ui->leCL->asInt() == 0) {
                errors += tr("City ledger is not defined");
            }

            finalName = QString("CHECKOUT %1, %2").arg(ui->wRoom->room()).arg(ui->wRoom->guest());
            break;

        case PAYMENT_BARTER:
            finalName += "BARTER " + ui->wRoom->guest();
            break;

        case PAYMENT_PAYX:
            finalName += "PAYX";
            break;

        case PAYMENT_CPAY:
            finalName += "CPAY";
            break;

        case PAYMENT_TERMINAL:
            finalName += "TERMINAL";
            break;

        default:
            errors += tr("Selected mode of payment is not allowed here") + "<br>";
            break;
        }

        break;

    case 1:
        dc = "CREDIT";
        sign = 1;
        ui->wRoom->setGuest(ui->wCL->cityLedgerName());
        ui->wRoom->setRoom(ui->wCL->cityLedger());

        if(ui->wCL->cityLedger() == 0) {
            errors += tr("Cityledger is not selected") + "<br>";
        } else {
            room = QString::number(ui->wCL->cityLedger());
        }

        switch(ui->lePaymentCode->asInt()) {
        case PAYMENT_CASH:
            finalName += "CASH";
            break;

        case PAYMENT_BANK:
            finalName += "BANK";
            break;

        case PAYMENT_CARD:
            finalName += ui->leCardName->text();
            break;

        case PAYMENT_BARTER:
            finalName += "BARTER " + ui->wCL->cityLedgerName();
            break;

        case PAYMENT_PAYX:
            finalName += "PAYX";
            break;

        case PAYMENT_TERMINAL:
            finalName += "TERMINAL";
            break;

        case PAYMENT_CPAY:
            finalName += "CPAY";
            break;

        default:
            errors += tr("Selected payment mode is not allowed here") + "<br>";
            break;
        }
    }

    if(ui->lePaymentCode->asInt() == PAYMENT_CARD) {
        if(ui->leCardCode->asInt() == 0) {
            errors += tr("Card is not selected") + "<br>";
        }
    }

    ui->leFinalName->setText(finalName);

    if(!errors.isEmpty()) {
        message_error(errors);
        return;
    }

    DoubleDatabase fDD;
    fDoc.fDC = dc;
    fDoc.fSign = sign;

    if(ui->tabWidget->currentIndex() == 0) {
        if(ui->lePaymentCode->asInt() == PAYMENT_CL) {
            fDoc.fCityLedger = ui->leCL->asUInt();
            fDoc.fPaymentComment = "CHECKOUT " + ui->leCLName->text();
        } else {
            fDoc.fPaymentComment = "PAYMENT " + vaucherPaymentName(ui->lePaymentCode->asInt(), ui->leCardCode->text(), ui->leCL->text());
        }
    } else {
        fDoc.fPaymentComment = "PAYMENT " + vaucherPaymentName(ui->lePaymentCode->asInt(), ui->leCardCode->text(), QString::number(ui->wCL->cityLedger()));
    }

    fDoc.fRb = ui->tabWidget->currentIndex();

    if(!fDoc.save(fDD)) {
        message_error(fDoc.fError);
        return;
    } /*

    if (ui->tabWidget->currentIndex() == 0) {
        if (ui->lePaymentCode->asInt() == PAYMENT_CL) {
            DBMRegister fDoc2;
            fDoc2 = fDoc;
            fDoc2.fId.clear();
            fDoc2.fDoc = fDoc.fId;
            fDoc2.fCityLedger = ui->leCL->asUInt();
            fDoc2.fFinalName = QString("CHECKOUT %1, %2").arg(ui->wRoom->room()).arg(ui->wRoom->guest());
            fDoc2.fReserve = "";
            fDoc2.fInvoice = "";
            if (!fDoc2.save(fDD)) {
                message_error(fDoc2.fError);
                return;
            }
            fDoc.fDoc = fDoc2.fId;
            fDoc.save(fDD);
        }
    } */
    clearSelectors();
    setBalance();
    fixTabWidget();
    ui->btnPrint->setEnabled(true);
    ui->btnSave->setEnabled(false);
}

void DlgReceiptVaucher::on_btnCancel_clicked()
{
    if(ui->lePaymentCode->asInt() != PAYMENT_CL) {
        if(!ui->leVaucher->text().isEmpty()) {
            WInvoice w(this);
            w.loadInvoice(ui->wRoom->invoice());
            w.on_btnTaxPrint_clicked();
        }
    }

    reject();
}

void DlgReceiptVaucher::cardVisible(bool v)
{
    ui->lbCardType->setVisible(v);
    ui->leCardCode->setVisible(v);
    ui->leCardName->setVisible(v);

    if(!v) {
        ui->leCardCode->clear();
        ui->leCardName->clear();
    }
}

void DlgReceiptVaucher::clVisible(bool v)
{
    ui->lbCL->setVisible(v);
    ui->leCL->setVisible(v);
    ui->leCLName->setVisible(v);

    if(!v) {
        ui->leCL->clear();
        ui->leCLName->clear();
    }
}

void DlgReceiptVaucher::clearSelectors()
{
    ui->wRoom->clearSelector();
    ui->wCL->clearSelector();
    ui->lePaymentCode->clearSelector();
    ui->leCardCode->clearSelector();

    if(!r__(cr__super_correction)) {
        ui->leOpcode->clearSelector();
    }

    ui->tabWidget->disconnect(this, SLOT(on_tabWidget_currentChanged(int)));
}

void DlgReceiptVaucher::fixTabWidget()
{
    switch(fDoc.fRb) {
    case 0: {
        ui->tabWidget->setTabEnabled(1, false);
        CacheRoom c;

        if(c.get(ui->wRoom->room())) {
            ui->wRoom->setRoomCategory(c.fName());
        }

        break;
    }

    case 1:
        ui->tabWidget->setTabEnabled(0, false);
        break;
    }
}

void DlgReceiptVaucher::setBalance()
{
    switch(ui->tabWidget->currentIndex()) {
    case 0:
        ui->wRoom->setBalance();
        break;

    case 1:
        ui->wCL->setBalance();
        break;
    }
}

void DlgReceiptVaucher::on_btnPrint_clicked()
{
    PPrintVaucher::printVaucher(ui->leVaucher->text());
}

void DlgReceiptVaucher::on_leAmountAMD_textEdited(const QString &arg1)
{
    ui->leAmountUSD->setDouble(str_float(arg1) / def_usd);
}

void DlgReceiptVaucher::on_btnNew_clicked()
{
    accept();
    DlgReceiptVaucher(fDoc.fFiscalMachine, 0, 0, this).exec();
}

void DlgReceiptVaucher::on_lePaymentCode_textChanged(const QString &arg1)
{
    bool ro = true;

    switch(arg1.toInt()) {
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

    default:
        ro = !r__(cr__change_rv_other_types);
        break;
    }

    ui->deDate->setReadOnly(ro);

    if(ro) {
        ui->deDate->setDate(WORKING_DATE);
    }
}

void DlgReceiptVaucher::on_btnLog_clicked()
{
    DlgTracking::showTracking(ui->leVaucher->text());
}

void DlgReceiptVaucher::on_tabWidget_currentChanged(int index)
{
    switch(index) {
    case 0: {
        ui->wCL->clear();
        ui->wRoom->initSelector();
        break;
    }

    case 1:
        ui->wRoom->clear();
        ui->wCL->initSelector();
        break;
    }

    adjustSize();
}

void DlgReceiptVaucher::on_btnSuggestAmount_clicked()
{
    ui->leAmountAMD->setDouble(fSuggestAmount);
    on_leAmountAMD_textEdited(ui->leAmountAMD->text());
}
