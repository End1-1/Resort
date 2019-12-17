#ifndef DLGROOM_H
#define DLGROOM_H

#include "roweditordialog.h"

namespace Ui {
class DlgRoom;
}

class DlgRoom : public RowEditorDialog
{
    Q_OBJECT

public:
    explicit DlgRoom(QList<QVariant> &values, QWidget *parent = 0);
    ~DlgRoom();
    virtual void setValues();

private slots:
    void on_btnCancel_clicked();
    void on_btnOK_clicked();

private:
    Ui::DlgRoom *ui;

};

#endif // DLGROOM_H
