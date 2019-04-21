#ifndef DLGTAXPRINTSETUP_H
#define DLGTAXPRINTSETUP_H

#include "baseextendeddialog.h"

namespace Ui {
class DlgTaxPrintSetup;
}

class DlgTaxPrintSetup : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DlgTaxPrintSetup(QWidget *parent = nullptr);
    ~DlgTaxPrintSetup();

private slots:
    void on_btnCancel_clicked();
    void on_btnOk_clicked();

private:
    Ui::DlgTaxPrintSetup *ui;
};

#endif // DLGTAXPRINTSETUP_H
