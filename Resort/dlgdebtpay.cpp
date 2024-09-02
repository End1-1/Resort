#include "dlgdebtpay.h"
#include "ui_dlgdebtpay.h"
#include "cachedebtcostumer.h"

#define SEL_DEBT_COST 1

DlgDebtPay::DlgDebtPay(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgDebtPay)
{
    ui->setupUi(this);
    ui->leCostCode->setSelector(this, cache(cid_debt_costumer), ui->leCostName);
}

DlgDebtPay::~DlgDebtPay()
{
    delete ui;
}

void DlgDebtPay::debtPay(int id)
{
    DlgDebtPay *d = new DlgDebtPay(fPreferences.getDefaultParentForMessage());
    if (id > 0) {
        DoubleDatabase fDD;
        fDD[":f_id"] = id;
        fDD.exec("select * from o_debt_pay where f_id=:f_id");
        if (fDD.rowCount() > 0) {
            d->ui->leCode->setInt(id);
            d->ui->leDate->setDate(fDD.getValue("f_date").toDate());
            d->ui->leCostCode->setInitialValue(fDD.getValue("f_holder").toInt());
            d->ui->leAmount->setDouble(fDD.getValue("f_amount").toDouble());
        }
    }
    d->exec();
    delete d;
}

void DlgDebtPay::on_btnCancel_clicked()
{
    reject();
}

void DlgDebtPay::on_btnOk_clicked()
{
    DoubleDatabase fDD;
    if (ui->leCode->asInt() == 0) {
        ui->leCode->setInt(fDD.insert("o_debt_pay"));
    }
    fDD[":f_date"] = ui->leDate->date();
    fDD[":f_holder"] = ui->leCostCode->asInt();
    fDD[":f_amount"] = ui->leAmount->asDouble();
    fDD.update("o_debt_pay", where_id(ui->leCode->asInt()));
    message_info(tr("Saved"));
    accept();
}
