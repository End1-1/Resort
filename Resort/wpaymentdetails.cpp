#include "wpaymentdetails.h"
#include "ui_wpaymentdetails.h"
#include "dbmregister.h"
#include "cachepaymentmode.h"
#include "cachecreditcard.h"
#include "cachevatmode.h"
#include "cachecityledger.h"
#include "paymentmode.h"

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

void WPaymentDetails::hideVAT(bool v)
{
    ui->lbVatMode->setVisible(!v);
    ui->lbAmountVAT->setVisible(!v);
    ui->leVAT->setVisible(!v);
    ui->leVATName->setVisible(!v);
    ui->leVATAmount->setVisible(!v);
    adjustSize();
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

void WPaymentDetails::hideCard(bool v)
{
    ui->leCard->setVisible(!v);
    ui->leCardName->setVisible(!v);
    ui->lbCard->setVisible(!v);
}

void WPaymentDetails::hideCL(bool v)
{
    ui->lbCL->setVisible(!v);
    ui->leCL->setVisible(!v);
    ui->leCLName->setVisible(!v);
}
