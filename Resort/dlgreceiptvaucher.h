#ifndef DLGRECEIPTVAUCHER_H
#define DLGRECEIPTVAUCHER_H

#include "baseextendeddialog.h"
#include "dbmregister.h"

namespace Ui {
class DlgReceiptVaucher;
}

class DlgReceiptVaucher : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DlgReceiptVaucher(int fiscalmachine, double suggestAmount, int side, QWidget *parent = nullptr);
    ~DlgReceiptVaucher();
    void setVoucher(const QString &id);
    virtual void callback(int sel, const QString &code);
    void setSide(quint32 side);
    void setCL(int cl);
    void setInvoice(const QString &invoice);
    void setRoom(int room);
    void setPaymentMode(int mode, int cl);
    void setAmount(double amount);

private slots:
    void on_btnSave_clicked();
    void on_btnCancel_clicked();
    void on_btnPrint_clicked();
    void on_leAmountAMD_textEdited(const QString &arg1);
    void on_btnNew_clicked();
    void on_lePaymentCode_textChanged(const QString &arg1);
    void on_btnLog_clicked();
    void on_tabWidget_currentChanged(int index);

    void on_btnSuggestAmount_clicked();

private:
    Ui::DlgReceiptVaucher *ui;
    void cardVisible(bool v);
    void clVisible(bool v);
    void clearSelectors();
    void fixTabWidget();
    void setBalance();
    DBMRegister fDoc;
    double fSuggestAmount;
};

#endif // DLGRECEIPTVAUCHER_H
