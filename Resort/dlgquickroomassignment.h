#ifndef DLGQUICKROOMASSIGNMENT_H
#define DLGQUICKROOMASSIGNMENT_H

#include "basedialog.h"

namespace Ui {
class DlgQuickRoomAssignment;
}

class DlgQuickRoomAssignment : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgQuickRoomAssignment(QWidget *parent = nullptr);
    ~DlgQuickRoomAssignment();
    virtual void callback(int selectorNumber, const QString &value);

private slots:
    void on_btnCancel_clicked();
    void on_btnSave_clicked();

private:
    Ui::DlgQuickRoomAssignment *ui;
    QString fError;
};

#endif // DLGQUICKROOMASSIGNMENT_H
