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
    explicit DlgHouseItem(QWidget *parent = nullptr);
    ~DlgHouseItem();
    void setRoom(int room);
    virtual void callback(int sel, const QString &code);
    static void openWindow(int room);

private slots:
    void onOffClicked();
    void comboStateCurrentIndexChanged(int index);
    void on_btnAddItem_clicked();
    void on_btnSave_clicked();
    void on_btnRemoveItem_clicked();
    void on_btnSaveStates_clicked();
    void on_btnCopy_clicked();
    void on_btnPaste_clicked();
    void on_btnDontDisturbe_clicked(bool checked);

private:
    Ui::DlgHouseItem *ui;
    EQLineEdit *fleInventory;
    void loadRoom();
    int addRow();
    void checkForReady();
};

#endif // DLGHOUSEITEM_H
