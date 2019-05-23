#include "dlgreceiptvaucher.h"
#include "ui_dlgreceiptvaucher.h"
#include "pprintpreview.h"
#include "ptextrect.h"
#include "pprintheader.h"
#include "cachepaymentmode.h"
#include "vauchers.h"
#include "pimage.h"
#include "printtax.h"
#include "dlgtracking.h"
#include "cacheactiveroom.h"
#include "cacheroom.h"
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
    ui->leFinalName->setReadOnly(!r__(cr__super_correction));
    ui->deDate->setDate(WORKING_DATE);
    ui->lePaymentCode->setSelector(this, cache(cid_payment_mode), ui->lePaymentName, HINT_PAYMENT_MODE);
    ui->lePaymentCode->fCodeFilter << QString::number(PAYMENT_CASH)
                                     << QString::number(PAYMENT_CARD)
                                     << QString::number(PAYMENT_BANK)
                                     << QString::number(PAYMENT_BARTER);
    ui->leCardCode->setSelector(this, cache(cid_credit_card), ui->leCardName, HINT_CARD);
    cardVisible(false);
    fTrackControl = new TrackControl(TRACK_RESERVATION);
    fDoc.setleID(ui->leVaucher);
    fDoc.fSource = VAUCHER_RECEIPT_N;
    ui->wRoom->setDBMRegister(&fDoc);
    ui->wCL->setDBMRegister(&fDoc);
    fDoc.setleWDate(ui->deDate);
    fDoc.fItemCode = fPreferences.getDb(def_receip_vaucher_id).toUInt();
    fDoc.fFinance = 1;
    fDoc.setleFinalName(ui->leFinalName);
    fDoc.setlePaymentMode(ui->lePaymentCode, ui->lePaymentName);
    fDoc.setleAmountAMD(ui->leAmountAMD);
    fDoc.setleAmountUSD(ui->leAmountUSD);
    fDoc.setleCreditCard(ui->leCardCode, ui->leCardName);
    fDoc.setleRemarks(ui->teRemarks);
    on_tabWidget_currentChanged(0);
}

DlgReceiptVaucher::~DlgReceiptVaucher()
{
    delete ui;
}

void DlgReceiptVaucher::setVoucher(const QString &id)
{
    clearSelectors();
    DoubleDatabase dd(true, false);
    fDoc.open(dd, id);
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
            cardVisible(true);
            break;
        default:
            ui->deDate->setReadOnly(true);
            break;
    }
    fixTabWidget();
    setBalance();
    ui->btnSave->setVisible(r__(cr__super_correction));
    ui->leAmountAMD->setReadOnly(!r__(cr__super_correction));
    if (r__(cr__super_correction)) {
        ui->deDate->setReadOnly(false);
    }
    ui->btnPrint->setEnabled(true);
    adjustSize();
}


void DlgReceiptVaucher::callback(int sel, const QString &code)
{
    switch (sel) {
    case HINT_PAYMENT_MODE: {
        CachePaymentMode c;
        if (c.get(code)) {
            switch (c.fCode().toInt()) {
            case PAYMENT_CASH:
                cardVisible(false);
                ui->leFinalName->setText(tr("PAYMENT CASH"));
                break;
            case PAYMENT_CARD:
                cardVisible(true);
                break;
            case PAYMENT_BANK:
                cardVisible(false);
                ui->leFinalName->setText(tr("PAYMENT BANK"));
                break;
            default:
                cardVisible(false);
                ui->leFinalName->setText("PAYMENT " + c.fName());
                break;
            }
        }
        break;
    }
    case HINT_CARD: {
        CacheCreditCard c;
        if (c.get(code)) {
            ui->leFinalName->setText(tr("PAYMENT") + " " + c.fName());
        }
        break;
    }
    }
}

void DlgReceiptVaucher::setSide(quint32 side)
{
    fDoc.fSide = side;
}

void DlgReceiptVaucher::on_btnSave_clicked()
{
    QString errors;
    if (ui->leAmountAMD->asDouble() < 0.1) {
        errors += tr("Amount cannot be equal to zero.") + "<br>";
    }
    QString dc = "DEBIT";
    int sign = -1;
    QString finalName = tr("PAYMENT") + " ";
    QString room;
    switch (ui->tabWidget->currentIndex()) {
    case 0:
        if (ui->wRoom->room() == 0) {
            errors += tr("Room is not selected") + "<br>";
        } else {
            room = QString::number(ui->wRoom->room());
        }
        switch (ui->lePaymentCode->asInt()) {
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
            finalName += "C/L " + ui->wRoom->guest();
            break;
        case PAYMENT_BARTER:
            finalName += "BARTER " + ui->wRoom->guest();
            break;
        default:
            errors += tr("Selected payment mode is not allowed here") + "<br>";
            break;
        }
        break;
    case 1:
        dc = "CREDIT";
        sign = 1;
        ui->wRoom->setGuest(ui->wCL->cityLedgerName());
        ui->wRoom->setRoom(ui->wCL->cityLedger());
        if (ui->wCL->cityLedger() == 0) {
            errors += tr("Cityledger is not selected") + "<br>";
        } else {
            room = QString::number(ui->wCL->cityLedger());
        }
        switch (ui->lePaymentCode->asInt()) {
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
        default:
            errors += tr("Selected payment mode is not allowed here") + "<br>";
            break;
        }
    }
    if (ui->lePaymentCode->asInt() == PAYMENT_CARD) {
        if (ui->leCardCode->asInt() == 0) {
            errors += tr("Card is not selected") + "<br>";
        }
    }
    ui->leFinalName->setText(finalName);
    if (!errors.isEmpty()) {
        message_error(errors);
        return;
    }

    DoubleDatabase fDD(true, doubleDatabase);
    fDoc.fDC = dc;
    fDoc.fSign = sign;
    fDoc.fPaymentComment = vaucherPaymentName(ui->lePaymentCode->asInt(), ui->leCardCode->text(), QString::number(ui->wCL->cityLedger()));
    fDoc.fRb = ui->tabWidget->currentIndex();
    if(!fDoc.save(fDD)) {
        message_error(fDoc.fError);
        return;
    }
    clearSelectors();
    setBalance();
    fixTabWidget();
    ui->btnPrint->setEnabled(true);
    ui->btnSave->setEnabled(false);
}

void DlgReceiptVaucher::on_btnCancel_clicked()
{
    reject();
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

void DlgReceiptVaucher::clearSelectors()
{
    ui->wRoom->clearSelector();
    ui->wCL->clearSelector();
    ui->lePaymentCode->clearSelector();
    ui->leCardCode->clearSelector();
    if (!r__(cr__super_correction)) {
        ui->leOpcode->clearSelector();
    }
    ui->tabWidget->disconnect(this, SLOT(on_tabWidget_currentChanged(int)));
}

void DlgReceiptVaucher::fixTabWidget()
{
    switch (fDoc.fRb) {
    case 0: {
        ui->tabWidget->setTabEnabled(1, false);
        CacheRoom c;
        if (c.get(ui->wRoom->room())) {
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
    switch (ui->tabWidget->currentIndex()) {
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

void DlgReceiptVaucher::on_btnLog_clicked()
{
    DlgTracking::showTracking(ui->leVaucher->text());
}

void DlgReceiptVaucher::on_tabWidget_currentChanged(int index)
{
    switch (index) {
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
