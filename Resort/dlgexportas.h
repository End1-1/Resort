#ifndef DLGEXPORTAS_H
#define DLGEXPORTAS_H

#include "basedialog.h"
#include <QSqlQuery>

namespace Ui {
class DlgExportAS;
}

class DlgExportAS : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgExportAS(QWidget *parent = nullptr);
    ~DlgExportAS();
    static void getAsDataMap(QMap<int, QMap<QString, QVariant> > &partnersMap, QMap<QString, QMap<QString, QVariant> > &servicesMap, QMap<QString, QMap<QString, QVariant> > &goodsMap, QMap<QString, QMap<QString, QVariant> > &unitsMap);
    static void exportInvoiceToAs(const QString &invoice, const QMap<int, QMap<QString, QVariant> > &partnersMap, const QMap<QString, QMap<QString, QVariant> > &servicesMap, const QMap<QString, QMap<QString, QVariant> > &unitsMap, bool forceMove);
    static void exportInvoiceToAsAsRetailSale(const QString &invoice, int side);
    static void exportInvoiceToAsAsRetailSaleOnlyTax(const QString &invoice);

private slots:
    void on_btnUploadPostCharges_clicked();
    void on_btnSaveAsSettings_clicked();
    void on_btnUploadInvoices_clicked();
    void on_btnUploadPayments_clicked();
    void on_btnUploadInvoicesRetail_clicked();

    void on__5lePartnerDebet_editingFinished();

    void on__5lePartnerCredit_editingFinished();

    void on__5btnStart_clicked();

    void on_btnUploadInvoicesRetail_2_clicked();

private:
    Ui::DlgExportAS *ui;
    static void recordToMap(QMap<QString, QVariant> &m, QSqlQuery &q, QStringList &fields);
};

#endif // DLGEXPORTAS_H
