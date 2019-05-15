#ifndef WQUICKROOMASSIGNMENT_H
#define WQUICKROOMASSIGNMENT_H

#include "basewidget.h"

namespace Ui {
class WQuickRoomAssignment;
}

class WQuickRoomAssignment : public BaseWidget
{
    Q_OBJECT

public:
    explicit WQuickRoomAssignment(QWidget *parent = nullptr);
    ~WQuickRoomAssignment();
    virtual void setupTab();

private slots:
    void showRooms();
    void tblLineEditTextChanged(const QString &text);
    void on_btnRefresh_clicked();
    void on_btnSave_clicked();
    void on_tbl_doubleClicked(const QModelIndex &index);

private:
    Ui::WQuickRoomAssignment *ui;
};

#endif // WQUICKROOMASSIGNMENT_H
