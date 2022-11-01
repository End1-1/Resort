#ifndef WACCINVOICE_H
#define WACCINVOICE_H

#include "basewidget.h"

namespace Ui {
class WAccInvoice;
}

class WReportGrid;

class WAccInvoice : public BaseWidget
{
    Q_OBJECT

public:
    explicit WAccInvoice(QWidget *parent = nullptr);
    ~WAccInvoice();
    static void openInvoice(const QString &invoice);
    void load(const QString &id);
    QString invoice();
    virtual void setupTab();
    virtual void callback(int sel, const QString &code);

protected:
    virtual bool event(QEvent *event);

private:
    DoubleDatabase fDb;
    Ui::WAccInvoice *ui;
    WReportGrid *fReport;
    QString invoiceId();
    void viewEntries();
    void countAmounts();
    int fCurrentInvoicePosition;
    void correctCOCL();
    QString fOldCardex;
    QString fOldCardexCode;
    QString fOldVAT;
    QString fOldVATCode;

private slots:
    void handleValues(const QList<QVariant> &values);
    void on_btnTracking_clicked();
    void on_rbEntryName_clicked();
    void on_rbNoGroup_clicked();
    void on_chPaymentByGuest_clicked();
    void on_chPaymentByCompany_clicked();
    void on_btnPrint_clicked();
    void on_btnTaxPrint_clicked();
    void on_leInvoice_returnPressed();
    void on_btnTaxBack_clicked();
    void on_btnViewCorrections_clicked();
    void on_btnEliminate_clicked();
    void on_tblData_doubleClicked(const QModelIndex &index);
    void on_deDeparture_userDateChanged(const QDate &date);
    void on_deEntry_userDateChanged(const QDate &date);
    void on_btnPostingCharges_clicked();
    void on_btnMoveItem_clicked();
    void on_btnChangeCL_clicked();
    void on_btnNewVaucher_clicked();
    void on_deEntry_dateChanged(const QDate &date);
    void on_deCheckIn_dateChanged(const QDate &date);
    void on_btnEditReserv_clicked();
    void on_btnExcel_clicked();
    void on_btnEditRowVaucher_clicked();
    void on_chViewAllVauchers_clicked();
    void on_btnViewReserv_clicked();
    void on_btnGuestInfo_clicked();
    void on_btnNext_clicked();
    void on_btnExportAS_clicked();
    void on_btnExportASRetail_clicked();
    void on_btnMoveToCL_clicked();
};

#endif // WACCINVOICE_H
