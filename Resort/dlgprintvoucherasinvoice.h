#ifndef DLGPRINTVOUCHERASINVOICE_H
#define DLGPRINTVOUCHERASINVOICE_H

#include "basewidget.h"
#include "dbminvoice.h"
#include "dbminvoice.h"

namespace Ui {
class DlgPrintVoucherAsInvoice;
}

class DlgPrintVoucherAsInvoice : public BaseWidget
{
    Q_OBJECT

public:
    explicit DlgPrintVoucherAsInvoice(QWidget *parent = nullptr);
    ~DlgPrintVoucherAsInvoice();
    static DlgPrintVoucherAsInvoice *openInvoiceWindow(const QString &id);
    QString invoice() const;
    void setup();
    void openInvoice(const QString &id);
    void addVoucher(const QString &id);

private slots:
    void on_btnPrint_clicked();
    void on_btnAddVoucher_clicked();
    void on_btnSave_clicked();

private:
    Ui::DlgPrintVoucherAsInvoice *ui;
    void addRow(const DBMRegister &r, bool appendToInvoice);
    bool save();
    DBMInvoice fInvoice;
};

#endif // DLGPRINTVOUCHERASINVOICE_H
