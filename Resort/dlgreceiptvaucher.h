#ifndef DLGRECEIPTVAUCHER_H
#define DLGRECEIPTVAUCHER_H

#include "baseextendeddialog.h"

namespace Ui {
class DlgReceiptVaucher;
}

class DlgReceiptVaucher : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DlgReceiptVaucher(QWidget *parent = nullptr);
    ~DlgReceiptVaucher();
    void setVaucher(const QString &id);
    virtual void callback(int sel, const QString &code);
private slots:
    void on_btnSave_clicked();
    void on_rbGuest_clicked(bool checked);
    void on_rbCityLedger_clicked(bool checked);
    void on_btnCancel_clicked();
    void on_btnPrint_clicked();
    void on_leAmountAMD_textEdited(const QString &arg1);
    void on_btnNew_clicked();
    void on_lePaymentCode_textChanged(const QString &arg1);
    void on_btnLog_clicked();

private:
    Ui::DlgReceiptVaucher *ui;
    void saveRoom();
    void saveCityLedger();
    void cardVisible(bool v);
};

#endif // DLGRECEIPTVAUCHER_H
