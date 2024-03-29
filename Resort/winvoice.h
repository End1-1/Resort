#ifndef WINVOICE_H
#define WINVOICE_H

#include "basewidget.h"

namespace Ui {
class WInvoice;
}

class WInvoice : public BaseWidget
{
    Q_OBJECT

public:
    explicit WInvoice(QWidget *parent = nullptr);
    ~WInvoice();
    virtual void callback(int sel, const QString &code);
    void loadInvoice(const QString &id);
    void loadReservation(const QString &id);
    void startTracking();
    bool activeDoc(const QString &invoice);
    static void openInvoiceWindow(const QString &invoice);
    static void openInvoiceFromReservation(const QString &reserve);

public slots:
    void on_btnTaxPrint_clicked();

protected:
    virtual void setupTab();
    virtual bool canClose();

private slots:
    void cacheUpdated(int cache, const QString &id);
    void viewGPOSOrder(const QString &id);
    void on_btnShowLeft_clicked();
    void on_btnShowRight_clicked();
    void on_leRoomCode_returnPressed();
    void on_btnLeft_clicked();
    void moveTableRow(EQTableWidget *from, EQTableWidget *to);
    void on_btnDoubleLeft_clicked();
    void on_btnRight_clicked();
    void on_btnDoubleRight_clicked();
    void on_btnRefresh_clicked();
    void on_tblInvRight_clicked(const QModelIndex &index);
    void on_tblInvLeft_clicked(const QModelIndex &index);
    void on_btnPostingCharges_clicked();
    void on_btnCheckout_clicked();
    void on_btnPaymentsDetails_clicked();
    void on_btnCancel_clicked();
    void on_btnTransfer_clicked();
    void on_btnTrack_clicked();
    void on_btnDiscount_clicked();
    void on_btnTransferAmount_clicked();
    void on_btnPrintInvoice_clicked();
    void on_btnModifyRoom_clicked();
    void on_tblInvLeft_doubleClicked(const QModelIndex &index);
    void on_tblInvRight_doubleClicked(const QModelIndex &index);
    void on_btnPrintAdvance_clicked();
    void on_btnPrevInvoice_clicked();
    void on_btnNextInvoice_clicked();
    void on_btnTaxBack_clicked();
    void on_btnAdvance_clicked();
    void on_btnManualTax_clicked();
    void on_btnRefTax_clicked();
    void on_btnTaxBack_2_clicked();
    void on_btnPostBreakfast_clicked();
    void on_btnPostMinibar_clicked();
    void on_btnWakeup_clicked();
    void on_btnDoNotDisturbe_clicked(bool checked);

    void on_btnResetAdvanceAmount_clicked();

    void on_btnPayment_clicked();

private:
    Ui::WInvoice *ui;
    void save();
    void clearInvoice();
    void countTotals();
    double countTotal(QTableWidget *t);
    void enableButtons(bool v);
};

#endif // WINVOICE_H
