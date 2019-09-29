#ifndef DLGADVANCEENTRY_H
#define DLGADVANCEENTRY_H

#include "basedialog.h"
#include "dbmregister.h"

namespace Ui {
class DlgAdvanceEntry;
}

class DlgAdvanceEntry : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgAdvanceEntry(const QString &reserveId, QWidget *parent = nullptr);
    ~DlgAdvanceEntry();
    void setVoucher(const QString &id);
    void setRoom(int room);
    void setInvoice(const QString &invoice);

private slots:
    void on_btnCancel_clicked();
    void on_btnSave_clicked();
    void on_btnPrint_clicked();
    void on_btnNew_clicked();
    void on_btnPrintTax_clicked();
    void on_rbAdvance_clicked(bool checked);
    void on_btnService_clicked(bool checked);
    void on_btnLog_clicked();

private:
    Ui::DlgAdvanceEntry *ui;
    DBMRegister fDoc;
    void changeTaxMode(bool mode);
    void clearSelector();
};

#endif // DLGADVANCEENTRY_H
