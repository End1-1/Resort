#include "wpaymentdetails.h"
#include "ui_wpaymentdetails.h"
#include "dbmregister.h"
#include "cachepaymentmode.h"
#include "cachecreditcard.h"
#include "cachevatmode.h"
#include "cachecityledger.h"
#include "paymentmode.h"
#include "cachetaxmap.h"
#include "cachefiscalmachine.h"

static const int hint_payment = 1;

WPaymentDetails::WPaymentDetails(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WPaymentDetails)
{
    ui->setupUi(this);
    QDoubleValidator *v = new QDoubleValidator(0, 999999999, 2);
    v->setNotation(QDoubleValidator::StandardNotation);
    ui->lePayment->setValidator(v);
    ui->lePayment->setSelector(this, cache(cid_payment_mode), ui->lePaymentName, hint_payment);
    ui->leCard->setSelector(this, cache(cid_credit_card), ui->leCardName);
    ui->leVAT->setSelector(this, cache(cid_vat_mode), ui->leVATName);
    ui->leCL->setSelector(this, cache(cid_city_ledger), ui->leCLName);
    ui->leFiscal->setSelector(this, cache(cid_fiscalmachine), ui->leFiscalName);

//    ui->leFiscal->setVisible(false);
//    ui->leFiscalName->setVisible(false);
//    ui->lbFiscalMachine->setVisible(false);
}

WPaymentDetails::~WPaymentDetails()
{
    delete ui;
}

void WPaymentDetails::callback(int sel, const QString &code)
{
    switch (sel) {
    case hint_payment: {
        hideCL(true);
        hideCard(true);
        CachePaymentMode c;
        if (c.get(code)) {
            switch (code.toInt()) {
            case PAYMENT_CL:
                hideCL(false);
                break;
            case PAYMENT_CARD:
                hideCard(false);
                break;
            }
        }
        break;
    }
    }
}

void WPaymentDetails::clearSelectors()
{
    ui->lePayment->clearSelector();
    ui->leCard->clearSelector();
    ui->leVAT->clearSelector();
    ui->leCL->clearSelector();
    ui->leFiscal->clearSelector();
}

void WPaymentDetails::setFiscal(int id)
{
    ui->leFiscal->setInitialValue(id);
}

void WPaymentDetails::setTaxReceipt(int id)
{
    ui->leTaxReceipt->setInt(id);
}

int WPaymentDetails::getTaxReceipt()
{
    return ui->leTaxReceipt->asInt();
}

int WPaymentDetails::getFiscal()
{
    return ui->leFiscal->asInt();
}

void WPaymentDetails::setDBMRegister(DBMRegister *r)
{
    r->setlePaymentMode(ui->lePayment, ui->lePaymentName);
    r->setleCreditCard(ui->leCard, ui->leCardName);
    r->setleVatMode(ui->leVAT, ui->leVATName);
    r->setleAmountVAT(ui->leVATAmount);
    r->setleAmountAMD(ui->leAmount);
    r->setleAmountUSD(ui->leAmountUSD);
    r->setleCityLedger(ui->leCL, ui->leCLName);
    r->setleFiscalMachine(ui->leFiscal);
}

void WPaymentDetails::setPaymentFilter(QList<int> modes)
{
    ui->lePayment->fCodeFilter.clear();
    foreach (int i, modes) {
        ui->lePayment->fCodeFilter << QString::number(i);
    }
    callback(hint_payment, "0");
}

int WPaymentDetails::paymentCode()
{
    return ui->lePayment->asInt();
}

double WPaymentDetails::amount()
{
    return ui->leAmount->asDouble();
}

void WPaymentDetails::setSuggestAmount(double d)
{
    ui->btnSuggestAmount->setText(QString("%1 %2").arg(tr("Suggested amount"), float_str(d, 2)));
    ui->btnSuggestAmount->setProperty("amount", d);
}

void WPaymentDetails::hideVAT(bool v)
{
    ui->lbVatMode->setVisible(!v);
    ui->lbAmountVAT->setVisible(!v);
    ui->leVAT->setVisible(!v);
    ui->leVATName->setVisible(!v);
    ui->leVATAmount->setVisible(!v);
    adjustSize();
    static_cast<QWidget*>(parent())->adjustSize();
    if (parent()->parent()) {
        static_cast<QWidget*>(parent()->parent())->adjustSize();
    }
}

QString WPaymentDetails::paymentComment() const
{
    QString payment = "";
    switch (ui->lePayment->asInt()) {
    case PAYMENT_CASH:
        payment = "CASH";
        break;
    case PAYMENT_CARD:
        payment = ui->leCard->asInt() == 0 ? "UNKNOWN CARD" : ui->leCardName->text();
        break;
    case PAYMENT_BANK:
        payment = "BANK";
        break;
    case PAYMENT_CL: {
        payment = ui->leCL->asInt() == 0 ? "UNKNOWN CL" : ui->leCLName->text();
        break;
    }
    case PAYMENT_CREDIT:
        payment = "CREDIT";
        break;
    default:
        payment = "UNKNOWN";
        break;
    }
    return payment;
}

QString WPaymentDetails::cardName() const
{
    return ui->leCardName->text();
}

EQLineEdit *WPaymentDetails::leFiscal()
{
    return ui->leFiscal;
}

EQLineEdit *WPaymentDetails::leTaxReceipt()
{
    return ui->leTaxReceipt;
}

void WPaymentDetails::hideCard(bool v)
{
    ui->leCard->setVisible(!v);
    ui->leCardName->setVisible(!v);
    ui->lbCard->setVisible(!v);
    adjustSize();
    static_cast<QWidget*>(parent())->adjustSize();
    if (parent()->parent()) {
        static_cast<QWidget*>(parent()->parent())->adjustSize();
    }
}

void WPaymentDetails::hideCL(bool v)
{
    ui->lbCL->setVisible(!v);
    ui->leCL->setVisible(!v);
    ui->leCLName->setVisible(!v);
    adjustSize();
    static_cast<QWidget*>(parent())->adjustSize();
    if (parent()->parent()) {
        static_cast<QWidget*>(parent()->parent())->adjustSize();
    }
}

void WPaymentDetails::on_btnSuggestAmount_clicked()
{
    ui->leAmount->setDouble(ui->btnSuggestAmount->property("amount").toDouble());
}
