#include "dlgtaxprintsetup.h"
#include "ui_dlgtaxprintsetup.h"
#include "cacherestmenu.h"
#include "cacheresthall.h"

DlgTaxPrintSetup::DlgTaxPrintSetup(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgTaxPrintSetup)
{
    ui->setupUi(this);
    ui->lePort->setValidator(new QIntValidator());
    ui->leHallCode->setSelector(this, cache(cid_rest_hall), ui->leHallName);
    ui->leMenuCode->setSelector(this, cache(cid_rest_menu), ui->leMenuName);

    DoubleDatabase fDD;
    fDD[":f_comp"] = QHostInfo::localHostName();
    fDD.exec("select f_address, f_port, f_password, f_adg, f_hall, f_menu from s_tax_print where f_comp=:f_comp");
    if (fDD.nextRow()) {
        QList<QList<QVariant> > &fDbRows = fDD.fDbRows;
        ui->leAddress->setText(fDbRows.at(0).at(0).toString());
        ui->lePort->setText(fDbRows.at(0).at(1).toString());
        ui->lePassword->setText(fDbRows.at(0).at(2).toString());
        ui->leAdg->setText(fDbRows.at(0).at(3).toString());
        ui->leHallCode->setInitialValue(fDbRows.at(0).at(4).toString());
        ui->leMenuCode->setInitialValue(fDbRows.at(0).at(5).toString());
    }

}

DlgTaxPrintSetup::~DlgTaxPrintSetup()
{
    delete ui;
}

void DlgTaxPrintSetup::on_btnCancel_clicked()
{
    reject();
}

void DlgTaxPrintSetup::on_btnOk_clicked()
{
    DoubleDatabase fDD;
    fDD[":f_comp"] = QHostInfo::localHostName();
    fDD.exec("delete from s_tax_print where f_comp=:f_comp");
    fDD[":f_comp"] = QHostInfo::localHostName();
    fDD[":f_address"] = ui->leAddress->text();
    fDD[":f_port"] = ui->lePort->asInt();
    fDD[":f_password"] = ui->lePassword->text();
    fDD[":f_adg"] = ui->leAdg->text();
    fDD[":f_hall"] = ui->leHallCode->asInt();
    fDD[":f_menu"] = ui->leMenuCode->asInt();
    fDD.insert("s_tax_print");
    fPreferences.setDb(def_tax_address, ui->leAddress->text());
    fPreferences.setDb(def_tax_port, ui->lePort->text());
    fPreferences.setDb(def_tax_password, ui->lePassword->text());
    accept();
}
