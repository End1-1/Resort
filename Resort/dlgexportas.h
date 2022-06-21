#ifndef DLGEXPORTAS_H
#define DLGEXPORTAS_H

#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class DlgExportAS;
}

class DlgExportAS : public QDialog
{
    Q_OBJECT

public:
    explicit DlgExportAS(QWidget *parent = nullptr);
    ~DlgExportAS();
    static void getAsDataMap(QMap<int, QMap<QString, QVariant> > &partnersMap, QMap<QString, QMap<QString, QVariant> > &servicesMap, QMap<QString, QMap<QString, QVariant> > &goodsMap, QMap<QString, QMap<QString, QVariant> > &unitsMap);
    static void exportInvoiceToAs(const QString &invoice, const QMap<int, QMap<QString, QVariant> > &partnersMap, const QMap<QString, QMap<QString, QVariant> > &servicesMap, const QMap<QString, QMap<QString, QVariant> > &unitsMap, bool forceMove);

private slots:
    void on_btnUploadPostCharges_clicked();

    void on_btnSaveAsSettings_clicked();

    void on_btnUploadInvoices_clicked();

private:
    Ui::DlgExportAS *ui;

    static void recordToMap(QMap<QString, QVariant> &m, QSqlQuery &q, QStringList &fields);
};

#endif // DLGEXPORTAS_H
