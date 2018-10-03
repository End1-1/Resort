#ifndef REUSERS_H
#define REUSERS_H

#include "roweditordialog.h"

namespace Ui {
class REUsers;
}

class REUsers : public RowEditorDialog
{
    Q_OBJECT
public:
    explicit REUsers(QList<QVariant> &values, QWidget *parent = 0);
    ~REUsers();

private slots:
    void on_btnCancel_clicked();
    void on_btnOk_clicked();

private:
    Ui::REUsers *ui;

};

#endif // REUSERS_H
