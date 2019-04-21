#ifndef DLGDEBTPAY_H
#define DLGDEBTPAY_H

#include "baseextendeddialog.h"

namespace Ui {
class DlgDebtPay;
}

class DlgDebtPay : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DlgDebtPay(QWidget *parent = nullptr);
    ~DlgDebtPay();
    static void debtPay(int id);
private slots:
    void on_btnCancel_clicked();

    void on_btnOk_clicked();

private:
    Ui::DlgDebtPay *ui;
};

#endif // DLGDEBTPAY_H
