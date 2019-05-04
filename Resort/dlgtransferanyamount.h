#ifndef DLGTRANSFERANYAMOUNT_H
#define DLGTRANSFERANYAMOUNT_H

#include "basedialog.h"
#include "dbmregister.h"

static const int hint_from_room = 1;
static const int hint_from_reserve = 2;
static const int hint_from_cl = 3;
static const int hint_to_room = 4;
static const int hint_to_reserve = 5;
static const int hint_to_cl = 6;

namespace Ui {
class DlgTransferAnyAmount;
}

class DlgTransferAnyAmount : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgTransferAnyAmount(QWidget *parent = nullptr);
    ~DlgTransferAnyAmount();
    void setHint(int hint);
    void setRoom(int room);
    void setReservation(const QString &reserve);
    virtual void callback(int sel, const QString &code);

private slots:
    void on_btnCancel_clicked();
    void on_rbfromReserve_clicked();
    void on_rbfromRoom_clicked();
    void on_rbfromCL_clicked();
    void on_rbtoReserve_clicked();
    void on_rbtoRoom_clicked();
    void on_rbtoCL_clicked();
    void on_letoAmount_textChanged(const QString &arg1);
    void on_btnSave_clicked();
    void on_btnLog_clicked();

private:
    Ui::DlgTransferAnyAmount *ui;
    DBMRegister fDoc1;
    DBMRegister fDoc2;
    void disableControls();
};

#endif // DLGTRANSFERANYAMOUNT_H
