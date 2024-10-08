#include "dlgeditservtax.h"
#include "ui_dlgeditservtax.h"

DlgEditServTax::DlgEditServTax(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgEditServTax)
{
    ui->setupUi(this);
}

DlgEditServTax::~DlgEditServTax()
{
    delete ui;
}

void DlgEditServTax::setParams(int id, const QString &comp, int active, const QString &host, const QString &port, const QString &pass)
{
    fId = id;
    ui->leComp->setText(comp);
    ui->leHost->setText(host);
    ui->lePort->setText(port);
    ui->lePass->setText(pass);
    ui->chEnabled->setChecked(active == 1);
}

void DlgEditServTax::on_btnOk_clicked()
{
    DoubleDatabase fDD;
    fDD[":f_host"] = ui->leHost->text();
    fDD[":f_port"] = ui->lePort->text();
    fDD[":f_password"] = ui->lePass->text();
    fDD[":f_active"] = ui->chEnabled->isChecked() ? 1 : 0;
    fDD.update("serv_tax", where_id(fId));
    accept();
}

void DlgEditServTax::on_btnCancel_clicked()
{
    reject();
}
