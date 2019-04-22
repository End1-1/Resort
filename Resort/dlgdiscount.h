#ifndef DLGDISCOUNT_H
#define DLGDISCOUNT_H

#include "baseextendeddialog.h"

namespace Ui {
class DlgDiscount;
}

class DlgDiscount : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DlgDiscount(QWidget *parent = nullptr);
    ~DlgDiscount();
    virtual void callback(int sel, const QString &code);
    void setParams(const QString &room, double guestAmount, double companyAmount);
    static void openVaucher(const QString &id);

private slots:
    void on_btnCancel_clicked();
    void on_leValue_textChanged(const QString &arg1);
    void on_gbGuest_clicked();
    void on_rbCompany_clicked();
    void on_btnOk_clicked();
    void on_rbCityLedger_clicked();
    void on_rbGuest_clicked();
    void on_btnPrint_clicked();
    void on_btnLog_clicked();

private:
    Ui::DlgDiscount *ui;
    QString fInvoice;
    double fGuestAmount;
    double fCompanyAmount;
    void countDiscount();
    void sideChanged(bool guest);
};

#endif // DLGDISCOUNT_H
