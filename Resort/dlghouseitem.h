#ifndef DLGHOUSEITEM_H
#define DLGHOUSEITEM_H

#include "baseextendeddialog.h"

namespace Ui {
class DlgHouseItem;
}


class DlgHouseItem : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DlgHouseItem(QWidget *parent = 0);
    ~DlgHouseItem();
    virtual void callback(int sel, const QString &code);
    static void openWindow();
private slots:
    void comboStateCurrentIndexChanged(int index);
    void on_btnAddItem_clicked();

    void on_btnSave_clicked();

    void on_btnRemoveItem_clicked();

private:
    Ui::DlgHouseItem *ui;
    EQLineEdit *fleInventory;
    void loadRoom();
    int addRow();
};

#endif // DLGHOUSEITEM_H
