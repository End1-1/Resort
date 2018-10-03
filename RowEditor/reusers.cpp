#include "reusers.h"
#include "ui_reusers.h"
#include "cacheusers.h"
#include "cacheusersgroups.h"

REUsers::REUsers(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_USER, parent),
    ui(new Ui::REUsers)
{
    ui->setupUi(this);
    fTable = "users";
    fCacheId = cid_users;
    ui->leGroupCode->setSelector(this, cache(cid_users_group), ui->leGroupName);
    addWidget(ui->leCode, tr("Code"))
            .addWidget(ui->cbState, tr("State"))
            .addWidget(ui->leGroupCode, "")
            .addWidget(ui->leGroupName, tr("Group"))
            .addWidget(ui->leUsername, tr("Username"))
            .addWidget(ui->leFName, tr("First name"))
            .addWidget(ui->leLName, tr("Last name"));
}

REUsers::~REUsers()
{
    delete ui;
}

void REUsers::on_btnCancel_clicked()
{
    reject();
}

void REUsers::on_btnOk_clicked()
{
    save();
}
