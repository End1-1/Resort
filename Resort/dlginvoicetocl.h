#ifndef DLGINVOICETOCL_H
#define DLGINVOICETOCL_H

#include "baseextendeddialog.h"

namespace Ui {
class DlgInvoiceToCL;
}

class DlgInvoiceToCL : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DlgInvoiceToCL(QWidget *parent = nullptr);
    ~DlgInvoiceToCL();
    static bool transferDebt(const QString &invoice, QWidget *parent = nullptr);

private slots:
    void on_btnCancel_clicked();
    void on_btnSave_clicked();

private:
    Ui::DlgInvoiceToCL *ui;
    void setInvoice(const QString &invoice);
};

#endif // DLGINVOICETOCL_H
