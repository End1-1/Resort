#ifndef DLGTRANSFER_H
#define DLGTRANSFER_H

#include "baseextendeddialog.h"

namespace Ui {
class DlgTransfer;
}

class DlgTransfer : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DlgTransfer(QWidget *parent = nullptr);
    ~DlgTransfer();
    virtual void callback(int sel, const QString &code);
    void setRoomByCode(const QString &code);
    void addRow(QList<QVariant> row);

private slots:
    void on_chGuest_clicked(bool checked);
    void on_chCompany_clicked(bool checked);
    void on_btnCancel_clicked();
    void on_btnOk_clicked();

private:
    Ui::DlgTransfer *ui;
};

#endif // DLGTRANSFER_H
