#ifndef DLGBANKET_H
#define DLGBANKET_H

#include "baseextendeddialogr.h"
#include "user.h"
#include "trackcontrol.h"

namespace Ui {
class DlgBanket;
}

class DlgBanket : public BaseExtendedDialogR
{
    Q_OBJECT

public:
    explicit DlgBanket(User *user, QWidget *parent = nullptr);
    ~DlgBanket();
    void printReceipt(const QString &num);

private slots:
    void on_btnExit_clicked();
    void on_btnGuestQty_clicked();
    void on_btnPrice_clicked();
    void on_btnPayment_clicked();
    void on_btnSelectService_clicked();
    void on_btnPrintReceipt_clicked();
    void on_btnSave_clicked();
    void on_btnHall_clicked();
    void on_btnTaxPrint_clicked();
    void on_btnComment_clicked();
    void on_btnDraft_clicked();
    void on_btnOpen_clicked();
    void on_btnNew_clicked();
    void on_btnPrepayment_clicked();
    void on_btnPrintDuplicate_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_btnDuplicateFiscal_clicked();

private:
    TrackControl *fTrackControl;
    Ui::DlgBanket *ui;
    void printTax();
    int fFiscal;
    QString fDoc;
    User *fUser;
    bool isCorrect(bool draft);
};

#endif // DLGBANKET_H
