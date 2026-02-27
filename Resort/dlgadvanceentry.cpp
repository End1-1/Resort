#include "dlgadvanceentry.h"
#include "ui_dlgadvanceentry.h"
#include "cachereservation.h"
#include "pprintpreview.h"
#include "ptextrect.h"
#include "pimage.h"
#include "cacheredreservation.h"
#include "vauchers.h"
#include "pprintscene.h"
#include "cacheinvoiceitem.h"
#include "paymentmode.h"
#include "dlgtracking.h"
#include "dlgprinttaxsm.h"
#include "cachetaxmap.h"
#include "pprintvaucher.h"
#include "cacheusers.h"
#include "paymentmode.h"

static const int HINT_PAYMENT_MODE = 1;
static const int HINT_RED_RESERVATION = 2;
static const int HINT_CITY_LEDGER = 3;

DlgAdvanceEntry::DlgAdvanceEntry(const QString &reserveId, double suggestAmount, QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgAdvanceEntry)
{
    ui->setupUi(this);
    ui->leUser->setSelector(this, cache(cid_users), ui->leUsername);
    ui->leUser->setInitialValue(WORKING_USERID);
    ui->btnPrint->setEnabled(false);
    QList<int> paymentFilter;
    paymentFilter << PAYMENT_CASH
                  << PAYMENT_CARD
                  << PAYMENT_BANK
                  << PAYMENT_PAYX
                  << PAYMENT_TERMINAL
                  << PAYMENT_CPAY;
    ui->wPayment->setPaymentFilter(paymentFilter);
    ui->wPayment->hideVAT(true);
    ui->wInvoice->setDBMRegister(&fDoc);
    ui->wInvoice->setReservationMode(reserveId);
    ui->wPayment->setDBMRegister(&fDoc);
    fDoc.setleID(ui->leVoucher);
    fDoc.setleWDate(ui->deDate);
    fDoc.setleUser(ui->leUser, ui->leUsername);
    fDoc.fSource = VAUCHER_ADVANCE_N;
    fDoc.fItemCode = fPreferences.getDb(def_advance_voucher_id).toUInt();
    fDoc.setleFinalName(ui->leFinalName);
    fDoc.setleFiscal(ui->wPayment->leTaxReceipt());
    fDoc.setleFiscalMachine(ui->wPayment->leFiscal());
    fDoc.fDC = "DEBET";
    fDoc.fSign = -1;
    fDoc.fFinance = 1;
    fDoc.setleRemarks(ui->teRemarks);
    ui->btnLog->setVisible(fPreferences.getDb(def_show_logs).toBool());
    ui->wPayment->setSuggestAmount(suggestAmount);
    adjustSize();
}

void DlgAdvanceEntry::clearSelector()
{
    ui->wPayment->clearSelectors();
    ui->leUser->clearSelector();
    ui->wInvoice->clearSelector();
}

DlgAdvanceEntry::~DlgAdvanceEntry()
{
    delete ui;
}

void DlgAdvanceEntry::setFiscal(int id)
{
    ui->wPayment->setFiscal(id);
}

void DlgAdvanceEntry::setVoucher(const QString &id)
{
    clearSelector();
    DoubleDatabase dd;
    fDoc.open(dd, id);
    ui->wInvoice->setBalance();
}

void DlgAdvanceEntry::setRoom(int room)
{
    ui->wInvoice->setRoom(room);
}

void DlgAdvanceEntry::setInvoice(const QString &invoice)
{
    ui->wInvoice->setInvoice(invoice);
}

int DlgAdvanceEntry::exec()
{
    adjustSize();
    return BaseDialog::exec();
}

void DlgAdvanceEntry::on_btnCancel_clicked()
{
    reject();
}

void DlgAdvanceEntry::on_btnSave_clicked()
{
    if (ui->wInvoice->invoice().isEmpty()) {
        message_error(tr("Reservation must be defined"));
        return;
    }
    QString finalName;
    switch (fDoc.fPaymentMode) {
    case PAYMENT_CARD:
        if (ui->wPayment->cardName().isEmpty()) {
            message_error(tr("Card is not selected"));
            return;
        }
        finalName = "CC/" + ui->wPayment->cardName();
        break;
    case PAYMENT_CASH:
        finalName = "CASH";
        break;    
    case PAYMENT_BANK:
        finalName = "BANK";
        break;
    case PAYMENT_PAYX:
        finalName = "PAYX";
        break;
    case PAYMENT_TERMINAL:
        finalName = "TERMINAL";
        break;
    case PAYMENT_CPAY:
        finalName = "CPAY";
        break;
    default:
        message_error(tr("Selected mode of payment is not allowed here"));
        return;
    }
    finalName = tr("ADVANCE") + " " + finalName;
    ui->leFinalName->setText(finalName);

    DoubleDatabase fDD;
    fDoc.fPaymentComment = ui->wPayment->paymentComment();
    if (!fDoc.save(fDD)) {
        message_error(fDoc.fError);
        return;
    }
    ui->btnSave->setEnabled(false);
    ui->btnPrint->setEnabled(true);
    ui->wInvoice->setBalance();
    clearSelector();
    BroadcastThread::cmdRefreshCache(cid_red_reservation, ui->wInvoice->reserve());
}

void DlgAdvanceEntry::on_btnPrint_clicked()
{
   PPrintVaucher::printVaucher(ui->leVoucher->text());
}

void DlgAdvanceEntry::on_btnNew_clicked()
{
    accept();
    DlgAdvanceEntry *d = new DlgAdvanceEntry("", 0, fPreferences.getDefaultParentForMessage());
    d->exec();
    delete d;
}

void DlgAdvanceEntry::on_btnPrintTax_clicked()
{
    if (ui->wPayment->getTaxReceipt() > 0) {
        message_error(tr("Already printed"));
        return;
    }
    if (ui->leVoucher->text().isEmpty()) {
        message_error(tr("Save first"));
        return;
    }

//    if (ui->wPayment->paymentCode() == PAYMENT_CASH
//            || ui->wPayment->paymentCode() == PAYMENT_ADVANCE
//            || ui->wPayment->paymentCode() == PAYMENT_TERMINAL) {
//        if (ui->wPayment->amount() > 299000) {
//            message_error(tr("Stop! Think twice!"));
//            return;
//        }
//    }

//    if (ui->wPayment->getFiscal() == 0) {
//        message_error(tr("Fiscal machine is not defined"));
//        return;
//    }

    CacheInvoiceItem c;
    if (!c.get(fPreferences.getDb(def_advance_voucher_id).toInt())) {
        message_error(tr("Error in tax print. c == 0, case 1."));
        return;
    }
    CacheTaxMap ci;
    if (!ci.get(c.fCode())) {
        message_error(tr("Tax department undefined for ") + c.fName());
        return;
    }


    double cash = ui->wPayment->paymentCode() == PAYMENT_CASH ? ui->wPayment->amount() : 0;
    double card = ui->wPayment->paymentCode() == PAYMENT_CASH ? 0 : ui->wPayment->amount();
    int taxCode = 0;
    QString outJson;
    if (!DlgPrintTaxSM::printAdvance(ci.fTax(), cash, card,
                                     ui->wInvoice->invoice(),
                                     ui->leVoucher->text(), taxCode, outJson)) {
        return;
    }
    ui->wPayment->setTaxReceipt(taxCode);
    DoubleDatabase dd;
    if (!fDoc.save(dd)) {
        message_error(fDoc.fError);
        return;
    }
}

void DlgAdvanceEntry::on_btnLog_clicked()
{
    DlgTracking::showTracking(ui->leVoucher->text());
}
