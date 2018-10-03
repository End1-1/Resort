#include "dlgcl.h"
#include "ui_dlgcl.h"
#include "cachecityledger.h"

DlgCL::DlgCL(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgCL)
{
    ui->setupUi(this);
    ui->leCode->setSelector(this, cache(cid_city_ledger), ui->leName);
}

DlgCL::~DlgCL()
{
    delete ui;
}

bool DlgCL::getCL(QString &code, QString &name)
{
    DlgCL *d = new DlgCL(fPreferences.getDefaultParentForMessage());
    bool result = d->exec() == QDialog::Accepted;
    if (result) {
        code = d->ui->leCode->text();
        name = d->ui->leName->text();
    }
    delete d;
    return result;
}

void DlgCL::on_btnCancel_clicked()
{
    reject();
}

void DlgCL::on_btnOk_clicked()
{
    if (ui->leCode->text().isEmpty()) {
        return;
    }
    accept();
}
