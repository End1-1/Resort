#ifndef DLGPAYMENTMODE_H
#define DLGPAYMENTMODE_H

#include "basedialog.h"

namespace Ui {
class DlgPaymentMode;
}

class DlgPaymentMode : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgPaymentMode(QWidget *parent = nullptr);
    ~DlgPaymentMode();
    virtual void callback(int sel, const QString &code);
    static bool getPayment(int &paymentMode, QString &comment, int &cl);
private slots:
    void paymentMode(const QString &code);
    void on_btnCancel_clicked();

    void on_btnOk_clicked();

private:
    Ui::DlgPaymentMode *ui;
};

#endif // DLGPAYMENTMODE_H
