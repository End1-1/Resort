#ifndef DLGOFFERINVOICEEXTRA_H
#define DLGOFFERINVOICEEXTRA_H

#include "basedialog.h"

namespace Ui {
class DlgOfferInvoiceExtra;
}

class DlgPostCharge;

class DlgOfferInvoiceExtra : public BaseDialog
{
    Q_OBJECT

public:
    enum Extra {exDayUse = 1, exExtraRooming, exEarlyCheckin, exLateCheckout};
    explicit DlgOfferInvoiceExtra(QWidget *parent = nullptr);
    ~DlgOfferInvoiceExtra();
    void setRoom(int room);
    void setExtra(Extra e);
    virtual int exec() override;
    double fDayUseRate;

private slots:
    void on_btnCancel_clicked();
    void on_btnExtraRooming_clicked();
    void on_btnEarlyCheckin_clicked();
    void on_btnDayUse_clicked();
    void on_btnLateCheckout_clicked();

private:
    Ui::DlgOfferInvoiceExtra *ui;
    bool fExtra;
    int fRoom;
    void createChargeDlg(int item);
};

#endif // DLGOFFERINVOICEEXTRA_H
