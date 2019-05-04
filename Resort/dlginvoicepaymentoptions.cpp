#include "dlginvoicepaymentoptions.h"
#include "ui_dlginvoicepaymentoptions.h"

DlgInvoicePaymentOptions::DlgInvoicePaymentOptions(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgInvoicePaymentOptions)
{
    ui->setupUi(this);
    ui->chCloseAfterSaveCheckout->setChecked(closeAfterSaveCheckout());
    ui->chDoNotPrintVoucher->setChecked(doNotPrintVoucher());
}

DlgInvoicePaymentOptions::~DlgInvoicePaymentOptions()
{
    delete ui;
}

bool DlgInvoicePaymentOptions::doNotPrintVoucher()
{
    return __s.value("donotprintvoucher").toBool();
}

bool DlgInvoicePaymentOptions::closeAfterSaveCheckout()
{
    return __s.value("closeaftercheckout").toBool();
}

void DlgInvoicePaymentOptions::on_btnCancel_clicked()
{
    reject();
}

void DlgInvoicePaymentOptions::on_bntSave_clicked()
{
    __s.setValue("closeaftercheckout", ui->chCloseAfterSaveCheckout->isChecked());
    __s.setValue("donotprintvoucher", ui->chDoNotPrintVoucher->isChecked());
    accept();
}
