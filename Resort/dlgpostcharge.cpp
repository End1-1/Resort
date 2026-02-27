#include "dlgpostcharge.h"
#include "cachecityledger.h"
#include "cachecreditcard.h"
#include "cacheinvoiceitem.h"
#include "cachepaymentmode.h"
#include "cacherights.h"
#include "cacheroom.h"
#include "cacheroomarrangment.h"
#include "cachevatmode.h"
#include "dlgsingleprinttax.h"
#include "paymentmode.h"
#include "pprintvaucher.h"
#include "ui_dlgpostcharge.h"
#include "utils.h"
#include "vauchers.h"

#define hint_item 1
#define hint_payment 2

DlgPostCharge::DlgPostCharge(QWidget *parent)
    : BaseDialog(parent)
    , ui(new Ui::DlgPostCharge)
{
    ui->setupUi(this);
    fDoc.setleID(ui->leVoucher);
    fDoc.setleWDate(ui->deDate);
    fDoc.setleItemName(ui->leItem, ui->leItemName);
    fDoc.setleFinalName(ui->leFinalName);
    fDoc.setlePaymentMode(ui->lePayment, ui->lePaymentName);
    fDoc.setleCreditCard(ui->leCard, ui->leCardName);
    fDoc.setleAmountAMD(ui->leAmount);
    fDoc.setleAmountUSD(ui->leAmountUSD);
    fDoc.setleVatMode(ui->leVAT, ui->leVATName);
    fDoc.setleRemarks(ui->teRemarks);
    fDoc.setleFiscal(ui->leFiscal);
    ui->wRoom->setDBMRegister(&fDoc);
    ui->wCL->setDBMRegister(&fDoc);
    ui->btnNew->setEnabled(false);
    qApp->processEvents();
    ui->deDate->setReadOnly(!r__(cr__change_postcharge_wdate));
    ui->leItem->setSelector(this, cache(cid_invoice_item), ui->leItemName, hint_item);
    ui->lePayment->setSelector(this, cache(cid_payment_mode), ui->lePaymentName, hint_payment);
    ui->leVAT->setSelector(this, cache(cid_vat_mode), ui->leVATName, 0);
    ui->leVAT->setInitialValue(VAT_INCLUDED);
    ui->leCard->setSelector(this, cache(cid_credit_card), ui->leCardName, 0);
    ui->leItem->fFieldFilter["f_group"] << "1";
    DoubleDatabase dd;
    if (WORKING_USERGROUP != 1) {
        dd[":f_auto"] = 1;
    } else {
        dd[":f_auto"] = 100;
    }
    dd[":f_group"] = 1;
    dd.exec("select f_id from f_invoice_item where f_auto=:f_auto or f_group>:f_group");
    while (dd.nextRow()) {
        ui->leItem->fCodeExcludeFilter << dd.getString(0);
    }
    on_tabWidget_currentChanged(0);
    connect(ui->wRoom, SIGNAL(roomChanged()), this, SLOT(roomChanged()));
}

DlgPostCharge::~DlgPostCharge()
{
    delete ui;
}

void DlgPostCharge::callback(int sel, const QString &code)
{
    switch (sel) {
    case hint_item: {
        CacheInvoiceItem c;
        if (c.get(code)) {
            if (!r__(cr__super_correction)) {
                if (c.fNoManual()) {
                    message_error(tr("This item cannot be charged"));
                    ui->leItem->setInitialValue("");
                    return;
                }
            }
            ui->leFinalName->setText(c.fName());
        }
        break;
    }
    case hint_payment: {
        CachePaymentMode c;
        setCardVisible(false);
        if (c.get(code)) {
            if (c.fCode().toInt() == PAYMENT_CARD) {
                setCardVisible(true);
            }
        }
        break;
    }
    }
}

void DlgPostCharge::setVoucher(const QString &id)
{
    clearSelectors();
    DoubleDatabase dd;
    fDoc.open(dd, id);
    fixTabWidget();
    setBalance();
    ui->btnPrintTax->setEnabled(fDoc.fFiscal == 0);
    ui->btnNew->setEnabled(true);
    ui->btnSave->setVisible(r__(cr__super_correction));
    ui->leAmount->setReadOnly(!r__(cr__super_correction));
}

void DlgPostCharge::setInvoice(const QString &invoice)
{
    ui->wRoom->setInvoice(invoice);
}

void DlgPostCharge::setRoom(int room)
{
    ui->tabWidget->setTabEnabled(2, false);
    ui->tabWidget->setTabEnabled(1, false);
    on_tabWidget_currentChanged(0);
    ui->wRoom->initRoom(room);
}

void DlgPostCharge::setItem(int item)
{
    ui->leItem->setInitialValue(item);
    ui->leAmount->setFocus();
}

void DlgPostCharge::setAmount(double amount)
{
    ui->leAmount->setDouble(amount);
}

QString DlgPostCharge::voucher() const
{
    return ui->leVoucher->text();
}

void DlgPostCharge::roomChanged()
{
    ui->leVAT->setInitialValue(ui->wRoom->vatMode());
}

void DlgPostCharge::on_tabWidget_currentChanged(int index)
{
    ui->wRoom->clear();
    ui->wCL->clear();
    setPaymentVisible(index == 1);
    setCardVisible(false);
    switch (index) {
    case 0:
        ui->lePayment->setInitialValue(PAYMENT_CREDIT);
        break;
    }
    ui->grSale->adjustSize();
    ui->tabWidget->adjustSize();
    adjustSize();
}

void DlgPostCharge::on_btnCancel_clicked()
{
    reject();
}

void DlgPostCharge::on_btnSave_clicked()
{
    if (!ui->deDate->date().isValid()) {
        message_error(tr("The date of voucher is not valid"));
        return;
    }
    switch (ui->tabWidget->currentIndex()) {
    case 0:
        if (ui->wRoom->room() == 0) {
            message_error(tr("Guest invoice is empty"));
            return;
        }
        break;
    case 2:
        if (ui->wCL->cityLedger() == 0) {
            message_error((tr("Cityledger code is empty")));
            return;
        }
        break;
    }
    CacheInvoiceItem ii;
    if (!ii.get(ui->leItem->text())) {
        message_error(tr("Type of sale incorrect"));
        return;
    }
    if (ii.fVaucher().isEmpty()) {
        message_error(tr("This type of sale cannot be charged"));
        return;
    }
    if (isDoubleLess(ui->leAmount->asDouble(), 0.1, 10)) {
        message_error(tr("Amount is zero"));
        return;
    }
    if (ui->leVAT->asInt() == 0) {
        message_error(tr("Mode of VAT is not selected"));
        return;
    }
    QString paymentComment;
    switch (ui->lePayment->asInt()) {
    case PAYMENT_CASH:
        paymentComment = "CASH";
        break;
    case PAYMENT_CARD:
        if (ui->leCard->asInt() == 0) {
            message_error(tr("Card is not selected"));
            return;
        }
        paymentComment = ui->leCardName->text();
        break;
    case PAYMENT_BANK:
        paymentComment = "BANK";
        break;
    case PAYMENT_CL:
        break;
    }

    DoubleDatabase dd;
    if (ii.fVaucher() == VAUCHER_ROOMING_N) {
        QString appendix;
        switch (message_yesnocancel(tr("The date will append to the name.<br>Click YES to use current working date<br>Click NO - to use previouse working date"))) {
        case RESULT_YES:
            appendix = " " + fPreferences.getDb(def_working_day).toString();
            break;
        case RESULT_NO:
            appendix = " " + WORKING_DATE.addDays(-1).toString(def_date_format);
            break;
        }
        dd[":f_invoice"] = ui->wRoom->invoice();
        dd.exec("select f_arrangement from f_reservation where f_invoice=:f_invoice");
        if (dd.nextRow()) {
            CacheRoomArrangment ra;
            if (ra.get(dd.getString(0))) {
                appendix += " - " + ra.fName();
            }
        }
        ui->leFinalName->setText(ui->leItemName->text() + " " + appendix);
    }
    QString dc = "CREDIT";
    int sign = 1;
    switch (ui->tabWidget->currentIndex()) {
    case 0:
        break;
    case 2:
        dc = "DEBET";
        sign = -1;
        ui->wRoom->setGuest(ui->wCL->cityLedgerName());
        ui->wRoom->setRoom(ui->wCL->cityLedger());
        break;
    }
    fDoc.fSource = ii.fVaucher();
    fDoc.fDC = dc;
    fDoc.fSign = sign;
    fDoc.fFinance = 1;
    fDoc.fItemCode = ui->leItem->asUInt();
    fDoc.fAmountVAT = Utils::countVATAmount(ui->leAmount->asDouble(), ui->leVAT->asInt());
    fDoc.fRb = ui->tabWidget->currentIndex();
    fDoc.fPaymentComment = paymentComment;
    if (ui->rbCompany->isChecked()) {
        fDoc.fSide = 1;
    }
    if (!fDoc.save(dd)) {
        message_error(fDoc.fError);
        return;
    }
    ui->btnNew->setEnabled(true);
    ui->btnPrint->setEnabled(true);
    ui->btnPrintTax->setEnabled(true);
    clearSelectors();
    setBalance();
    if (fPreferences.getDb(def_print_voucher_after_save).toInt() == 1) {
        PPrintVaucher::printVaucher(ui->leVoucher->text());
    }
}

void DlgPostCharge::on_leAmount_textChanged(const QString &arg1)
{
    ui->leAmountUSD->setDouble(arg1.toDouble() / def_usd);
}

void DlgPostCharge::on_btnNew_clicked()
{
    reject();
    DlgPostCharge *p = new DlgPostCharge(fMainWindow);
    p->exec();
    delete p;
}

void DlgPostCharge::setPaymentVisible(bool v)
{
    QStringList paymentFilter;
    if (v) {
        paymentFilter << QString::number(PAYMENT_CASH)
                      << QString::number(PAYMENT_CARD)
                      << QString::number(PAYMENT_BANK);
    } else {
        paymentFilter << QString::number(PAYMENT_CREDIT);
    }
    ui->lePayment->fCodeFilter = paymentFilter;
    if (v) {
        ui->lePayment->setInitialValue("");
    } else {
        ui->lePayment->setInitialValue(PAYMENT_CREDIT);
    }
    ui->lePayment->setVisible(v);
    ui->lePaymentName->setVisible(v);
    ui->lbPayment->setVisible(v);
}

void DlgPostCharge::setCardVisible(bool v)
{
    ui->lbCard->setVisible(v);
    ui->leCard->setVisible(v);
    ui->leCardName->setVisible(v);
}

void DlgPostCharge::setBalance()
{
    switch (ui->tabWidget->currentIndex()) {
    case 0:
        ui->wRoom->setBalance();
        break;
    case 1:
        break;
    case 2:
        ui->wCL->setBalance();
        break;
    }
}

void DlgPostCharge::clearSelectors()
{
    ui->leItem->clearSelector();
    ui->lePayment->clearSelector();
    ui->wRoom->clearSelector();
    ui->wCL->clearSelector();
    ui->leVAT->clearSelector();
}

void DlgPostCharge::fixTabWidget()
{
    ui->tabWidget->disconnect(this, SLOT(on_tabWidget_currentChanged(int)));
    switch (fDoc.fRb) {
    case 0: {
        ui->tabWidget->setTabEnabled(0, true);
        ui->tabWidget->setTabEnabled(1, false);
        ui->tabWidget->setTabEnabled(2, false);
        CacheRoom c;
        if (c.get(ui->wRoom->room())) {
            ui->wRoom->setRoomCategory(c.fName());
        }
        break;
    }
    case 1:
        ui->lePayment->setVisible(true);
        ui->lePaymentName->setVisible(true);
        ui->lbPayment->setVisible(true);
        setCardVisible(ui->lePayment->asInt() == PAYMENT_CARD);
        ui->tabWidget->setTabEnabled(1, true);
        ui->tabWidget->setTabEnabled(0, false);
        ui->tabWidget->setTabEnabled(2, false);
        break;
    case 2:
        ui->lePayment->setVisible(true);
        ui->lePaymentName->setVisible(true);
        ui->lbPayment->setVisible(true);
        setCardVisible(ui->lePayment->asInt() == PAYMENT_CARD);
        ui->tabWidget->setTabEnabled(2, true);
        ui->tabWidget->setTabEnabled(0, false);
        ui->tabWidget->setTabEnabled(1, false);
        break;
    }
    adjustSize();
}

void DlgPostCharge::on_btnPrintTax_clicked()
{
    int mp = PAYMENT_CASH;
    if (ui->tabWidget->currentIndex() == 2) {
        mp = ui->lePayment->asInt();
    }
    DlgSinglePrintTax *d = new DlgSinglePrintTax(ui->wRoom->invoice(), this);
    d->addItem(ui->leItem->text(), ui->leAmount->asDouble(), mp, ui->leVoucher->text());
    if (d->exec() == QDialog::Accepted) {
        TrackControl::insert(2, "Print fiscal", QString::number(d->fTaxCode), "", "", ui->wRoom->invoice());
        ui->btnPrintTax->setEnabled(false);
        ui->leFiscal->setInt(d->fTaxCode);
        DoubleDatabase dd;
        fDoc.save(dd);
    }
    d->deleteLater();
}

void DlgPostCharge::on_btnPrint_clicked()
{
    if (ui->leVoucher->notEmpty()) {
        PPrintVaucher::printVaucher(ui->leVoucher->text());
    }
}
