#ifndef DLGSINGLEPRINTTAX_H
#define DLGSINGLEPRINTTAX_H

#include "basedialog.h"

namespace Ui {
class DlgSinglePrintTax;
}

class DlgSinglePrintTax : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgSinglePrintTax(const QString &invoice, QWidget *parent = nullptr);
    ~DlgSinglePrintTax();
    int fTaxCode;
    virtual void callback(int sel, const QString &code);
    int addItem(const QString &itemCode, double amount, int modeOfPayment, const QString &voucher);

private slots:
    void on_btnClose_clicked();
    void on_btnPrint_clicked();

private:
    Ui::DlgSinglePrintTax *ui;
    QString fInvoice;
};

#endif // DLGSINGLEPRINTTAX_H
