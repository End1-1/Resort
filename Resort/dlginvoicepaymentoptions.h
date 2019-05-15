#ifndef DLGINVOICEPAYMENTOPTIONS_H
#define DLGINVOICEPAYMENTOPTIONS_H

#include "basedialog.h"

namespace Ui {
class DlgInvoicePaymentOptions;
}

class DlgInvoicePaymentOptions : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgInvoicePaymentOptions(QWidget *parent = nullptr);
    ~DlgInvoicePaymentOptions();
    static bool doNotPrintVoucher();
    static bool closeAfterSaveCheckout();
    static bool printInvoiceImmediately();

private slots:
    void on_btnCancel_clicked();
    void on_bntSave_clicked();

private:
    Ui::DlgInvoicePaymentOptions *ui;
};

#endif // DLGINVOICEPAYMENTOPTIONS_H
