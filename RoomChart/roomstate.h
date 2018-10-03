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
    explicit RoomState(QWidget *parent = 0);
    ~RoomState();
    virtual void callback(int sel, const QString &code);
    void setRoom(const QString &code);
private slots:
    void on_btnCancel_clicked();
    void on_btnOk_clicked();

    void on_deStart_textChanged(const QString &arg1);

    void on_deEnd_textChanged(const QString &arg1);

private:
    Ui::RoomState *ui;
    CacheRoom fRoom;
    void checkOO();
};

#endif // ROOMSTATE_H
