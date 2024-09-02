#include "dlgchangeclofvaucher.h"
#include "ui_dlgchangeclofvaucher.h"
#include "cachecityledger.h"

DlgChangeCLOfVaucher::DlgChangeCLOfVaucher(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgChangeCLOfVaucher)
{
    ui->setupUi(this);
    ui->leNewCLCode->setSelector(this, cache(cid_city_ledger), ui->leNewCLName);
}

DlgChangeCLOfVaucher::~DlgChangeCLOfVaucher()
{
    delete ui;
}

bool DlgChangeCLOfVaucher::changeCL(const QString &vaucher, const QString &oldCL, const QString &name, const QString &amount)
{
    DlgChangeCLOfVaucher *d = new DlgChangeCLOfVaucher(fPreferences.getDefaultParentForMessage());
    d->ui->leVaucher->setText(vaucher);
    d->ui->leOldCLCode->setText(oldCL);
    CacheCityLedger ci;
    if (ci.get(oldCL)) {
        d->ui->leOldCLName->setText(ci.fName());
    }
    d->ui->leName->setText(name);
    d->ui->leAmount->setText(amount);
    DoubleDatabase fDD;
    fDD.exec("select * from m_register where f_id=" + ap(d->ui->leVaucher->text()));
    if (fDD.nextRow()) {
        d->ui->leRoom->setText(fDD.getValue("f_room").toString());
    }
    bool result = d->exec() == QDialog::Accepted;
    delete d;
    return result;
}

void DlgChangeCLOfVaucher::on_btnCancel_clicked()
{
    reject();
}

void DlgChangeCLOfVaucher::on_btnOk_clicked()
{
    if (ui->leNewCLCode->isEmpty()) {
        return;
    }
    DoubleDatabase fDD;
    if (ui->leRoom->text() == "-" || ui->leRoom->isEmpty()) {
        fDD[":f_guest"] = ui->leNewCLName->text();
        fDD[":f_paymentComment"] = ui->leNewCLName->text();
    }
    fDD[":f_cityLedger"] = ui->leNewCLCode->asInt();
    fDD.update("m_register", where_id(ap(ui->leVaucher->text())));
    accept();
}
