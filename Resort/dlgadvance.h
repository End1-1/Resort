#ifndef DLGADVANCE_H
#define DLGADVANCE_H

#include "baseextendeddialog.h"

namespace Ui {
class DlgAdvance;
}

class DlgAdvance : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DlgAdvance(const QString &reserve, QWidget *parent = 0);
    ~DlgAdvance();

    virtual void callback(int sel, const QString &code);

    void setVaucherId(const QString &id);
    static void openAdvance(const QString &vaucherId);
private slots:

    void on_btnClose_clicked();

    void on_btnPrint_clicked();

    void on_btnSave_clicked();

    void on_btnPrintTax_clicked();

private:
    Ui::DlgAdvance *ui;
};

#endif // DLGADVANCE_H
