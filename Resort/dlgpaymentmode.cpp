#include "dlgpaymentmode.h"
#include "ui_dlgpaymentmode.h"
#include "paymentmode.h"
#include "message.h"
#include "cachepaymentmode.h"
#include "cachecityledger.h"
#include "cachecreditcard.h"

static const int HINT_PAYMENT_MODE1 = 1;

DlgPaymentMode::DlgPaymentMode(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgPaymentMode)
{
    ui->setupUi(this);
    ui->lePaymentMode->setSelector(this,
                                   cache(cid_payment_mode),
                                   ui->lePaymentMode,
                                   HINT_PAYMENT_MODE1);
    ui->leCL->setSelector(this, cache(cid_city_ledger), ui->leCL);
    ui->leCardType->setSelector(this, cache(cid_credit_card), ui->leCardType);
}

DlgPaymentMode::~DlgPaymentMode()
{
    delete ui;
}

void DlgPaymentMode::callback(int sel, const QString &code)
{
    switch (sel) {
    case HINT_PAYMENT_MODE1: {
        paymentMode(code);
        break;
    }
    }
}

bool DlgPaymentMode::getPayment(int &paymentMode, QString &comment, int &cl)
{
    DlgPaymentMode *d = new DlgPaymentMode(fPreferences.getDefaultParentForMessage());
    bool result = d->exec() == QDialog::Accepted;
    if (result) {
        cl = 0;
        paymentMode = d->ui->lePaymentMode->fHiddenText.toInt();
        switch (paymentMode) {
        case PAYMENT_CARD:
            comment = d->ui->leCardType->text();
            break;
        case PAYMENT_CL:
            cl = d->ui->leCL->fHiddenText.toInt();
            comment = d->ui->leCL->text();
            break;
        }
    }
    delete d;
    return result;
}

void DlgPaymentMode::paymentMode(const QString &code)
{
    CachePaymentMode ci;
    if (!ci.get(ui->lePaymentMode->fHiddenText)) {
        return;
    }
    ui->leCardType->setEnabled(false);
    ui->leCL->setEnabled(false);
    ui->leRoom->setEnabled(false);
    if (ci.get(code)) {
        switch (ci.fCode().toInt()) {
        case PAYMENT_CASH:
            break;
        case PAYMENT_CARD:
            ui->leCardType->setEnabled(true);
            break;
        case PAYMENT_CL:
            ui->leCL->setEnabled(true);
            break;
        case PAYMENT_BANK:
            break;
        case PAYMENT_ROOM:
            break;
        default:
            message_error(tr("This payment mode is not available in this case."));
            break;
        }
    }
}

void DlgPaymentMode::on_btnCancel_clicked()
{
    reject();
}

void DlgPaymentMode::on_btnOk_clicked()
{
    CachePaymentMode pm;
    if (!pm.get(ui->lePaymentMode->fHiddenText)) {
        message_error(tr("Payment mode is not selected"));
        return;
    }
    accept();
}
