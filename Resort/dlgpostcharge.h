#ifndef DLGPOSTCHARGE_H
#define DLGPOSTCHARGE_H

#include "basedialog.h"
#include "dbmregister.h"

namespace Ui {
class DlgPostCharge;
}

class DlgPostCharge : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgPostCharge(QWidget *parent = nullptr);
    ~DlgPostCharge();
    virtual void callback(int sel, const QString &code);
    void setVoucher(const QString &id);
    void setInvoice(const QString &invoice);
    void setRoom(int room);
    void setItem(int item);
    void setAmount(double amount);
    QString voucher() const;

private slots:
    void roomChanged();
    void on_tabWidget_currentChanged(int index);
    void on_btnCancel_clicked();
    void on_btnSave_clicked();
    void on_leAmount_textChanged(const QString &arg1);
    void on_btnNew_clicked();
    void on_btnPrintTax_clicked();
    void on_btnPrint_clicked();

private:
    Ui::DlgPostCharge *ui;
    DBMRegister fDoc;
    void setPaymentVisible(bool v);
    void setCardVisible(bool v);
    void setBalance();
    void clearSelectors();
    void fixTabWidget();
};

#endif // DLGPOSTCHARGE_H
