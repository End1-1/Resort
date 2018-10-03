#ifndef DLGCHANGEEXPORTVAUCHER_H
#define DLGCHANGEEXPORTVAUCHER_H

#include "baseextendeddialog.h"

namespace Ui {
class DlgChangeExportVaucher;
}

class DlgChangeExportVaucher : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DlgChangeExportVaucher(DoubleDatabase &db, QWidget *parent = 0);
    ~DlgChangeExportVaucher();
    virtual void callback(int sel, const QString &code);
    void setDatabaseResult(int i = 0);
private slots:
    void on_btnCancel_clicked();

    void on_btnOK_clicked();

private:
    int fIndex;
    Ui::DlgChangeExportVaucher *ui;
    DoubleDatabase &fVauchers;
};

#endif // DLGCHANGEEXPORTVAUCHER_H
