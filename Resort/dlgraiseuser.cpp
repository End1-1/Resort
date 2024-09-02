#include "dlgraiseuser.h"
#include "ui_dlgraiseuser.h"

DlgRaiseUser::DlgRaiseUser(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgRaiseUser)
{
    ui->setupUi(this);
    fUser = 0;
}

DlgRaiseUser::~DlgRaiseUser()
{
    delete ui;
}

int DlgRaiseUser::raiseUser(int role)
{
    int result = 0;
    DlgRaiseUser *d = new DlgRaiseUser(fPreferences.getDefaultParentForMessage());
    d->fRole = role;
    if (d->exec() == QDialog::Accepted) {
        result = d->fUser;
    }
    delete d;
    return result;
}

void DlgRaiseUser::returnPressed()
{
    on_btnOk_clicked();
}

void DlgRaiseUser::escapePressed()
{
    reject();
}

void DlgRaiseUser::on_btnCancel_clicked()
{
    reject();
}

void DlgRaiseUser::on_btnOk_clicked()
{
    DoubleDatabase fDD;
    QString query = "select u.f_id, r.f_flag "
            "from users u "
            "inner join users_groups g on g.f_id=u.f_group "
            "inner join users_rights r on r.f_group=g.f_id "
            "where u.f_username=:f_username and u.f_password=md5(:f_password) "
            "and r.f_right=:f_right ";
    fDD[":f_username"] = ui->leUsername->text();
    fDD[":f_password"] = ui->lePassword->text();
    fDD[":f_right"] = fRole;
    fDD.exec(query);
    if (!fDD.nextRow()) {
        message_error(tr("Access denied"));
        return;
    }
    if (fDD.getInt(0) == 0) {
        message_error(tr("Access denied"));
        return;
    }
    fUser = fDD.getInt(0);
    accept();
}
