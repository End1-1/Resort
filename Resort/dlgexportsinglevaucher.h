#ifndef DLGEXPORTSINGLEVAUCHER_H
#define DLGEXPORTSINGLEVAUCHER_H

#include "baseextendeddialog.h"

namespace Ui {
class DlgExportSingleVaucher;
}

class DlgExportSingleVaucher : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DlgExportSingleVaucher(QWidget *parent = nullptr);
    ~DlgExportSingleVaucher();
    void setupVaucher(const QString &id);
    static int exportSingleVaucher(const QString &id);
private slots:
    void showInvoices(bool v);
    void on_btnCancel_clicked();

    void on_btnOk_clicked();

    void on_leInvoice_returnPressed();

private:
    DoubleDatabase fSDb;
    DoubleDatabase fVoucher;
    QString fVaucherId;
    Ui::DlgExportSingleVaucher *ui;
};

#endif // DLGEXPORTSINGLEVAUCHER_H
