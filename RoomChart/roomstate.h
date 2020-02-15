#ifndef ROOMSTATE_H
#define ROOMSTATE_H

#include "baseextendeddialog.h"
#include "cacheroom.h"

namespace Ui {
class RoomState;
}

class RoomState : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit RoomState(QWidget *parent = nullptr);
    ~RoomState();
    virtual void callback(int sel, const QString &code);
    void setRoom(const QString &code);
    void uncheckStiky();

private slots:
    void on_btnCancel_clicked();
    void on_btnOk_clicked();
    void on_deStart_textChanged(const QString &arg1);
    void on_deEnd_textChanged(const QString &arg1);
    void on_btnSticky_clicked(bool checked);

    void on_lbStatus_linkActivated(const QString &link);

    void on_btnWhy_clicked();

private:
    Ui::RoomState *ui;
    CacheRoom fRoom;
    bool fUncheckedStiky;
    void checkOO();
};

#endif // ROOMSTATE_H
