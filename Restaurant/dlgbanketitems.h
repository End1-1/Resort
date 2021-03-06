#ifndef DLGBANKETITEMS_H
#define DLGBANKETITEMS_H

#include "baseextendeddialogr.h"

namespace Ui {
class DlgBanketItems;
}

class DlgBanketItems : public BaseExtendedDialogR
{
    Q_OBJECT

public:
    explicit DlgBanketItems(QWidget *parent = 0);
    ~DlgBanketItems();
    static bool getItem(int &code, QString &name);
private slots:
    void on_btnCancel_clicked();

    void on_btnOk_clicked();

private:
    Ui::DlgBanketItems *ui;
};

#endif // DLGBANKETITEMS_H
