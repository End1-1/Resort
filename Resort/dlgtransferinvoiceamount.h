#ifndef DLGTRANSFERINVOICEAMOUNT_H
#define DLGTRANSFERINVOICEAMOUNT_H

#include "baseextendeddialog.h"
#include "cacheactiveroom.h"

namespace Ui {
class DlgTransferInvoiceAmount;
}

class DlgTransferInvoiceAmount : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DlgTransferInvoiceAmount(QWidget *parent = 0);
    ~DlgTransferInvoiceAmount();
    virtual void callback(int sel, const QString &code);
    void setRoomFrom(const QString &code);
private slots:

    void on_btnSave_clicked();

    void on_btnCancel_clicked();

    void on_leAmountTo_textChanged(const QString &arg1);

    void on_btnPrint_clicked();

private:
    Ui::DlgTransferInvoiceAmount *ui;
    void getAmount(const QString &invoice);
};

#endif // DLGTRANSFERINVOICEAMOUNT_H
