#ifndef DLGPRINTVOUCHERASINVOICE_H
#define DLGPRINTVOUCHERASINVOICE_H

#include "basewidget.h"

namespace Ui {
class DlgPrintVoucherAsInvoice;
}

class DlgPrintVoucherAsInvoice : public BaseWidget
{
    Q_OBJECT

public:
    explicit DlgPrintVoucherAsInvoice(QWidget *parent = nullptr);
    ~DlgPrintVoucherAsInvoice();
    void setup();
    void addVoucher(const QString &id);

private slots:
    void on_btnPrint_clicked();
    void on_btnAddVoucher_clicked();
    void on_btnSave_clicked();

private:
    Ui::DlgPrintVoucherAsInvoice *ui;
    void countTotal();
    void addRow(const QList<QVariant> &v);
};

#endif // DLGPRINTVOUCHERASINVOICE_H
