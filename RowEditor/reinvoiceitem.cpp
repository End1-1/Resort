#include "reinvoiceitem.h"
#include "ui_reinvoiceitem.h"
#include "cacheinvoiceitem.h"
#include "cacheinvoiceitemgroup.h"
#include "cachetaxmap.h"

REInvoiceItem::REInvoiceItem(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_INVOICE_ITEM, parent),
    ui(new Ui::REInvoiceItem)
{
    ui->setupUi(this);
    ui->lePrice->setValidator(new QDoubleValidator(0, 99999999, 2));
    addWidget(ui->leCode, "Code");
    addWidget(ui->leVaucher, "Voucher");
    addWidget(ui->leGroupCode, "");
    addWidget(ui->leGroupName, "Group");
    addWidget(ui->leNameAm, "Name, am");
    addWidget(ui->leNameEn, "Name, en");
    addWidget(ui->leNameRu, "Name, ru");
    addWidget(ui->lePrice, "Price");
    addWidget(ui->leTaxName, "Tax name");
    addWidget(ui->leADGT, "ADGT");
    addWidget(ui->leVATDept, "Tax VAT Dept");
    addWidget(ui->leNoVATDept, "Tax no VAT Dept");
    addWidget(ui->chAuto, "Manual charge");
    addWidget(ui->chRest, "Available in restaurant");
    addWidget(ui->leReceptionTax, "Tax dept, reception");
    addWidget(ui->leASCode, "AS code");
    addWidget(ui->leASType, "AS type");
    addWidget(ui->leAccIncome, "AccIncome");
    addWidget(ui->leAccIncomeNoVat, "AccIncomeNoVAT");
    addWidget(ui->leAccVAT, "AccVAT");
    addWidget(ui->leAccNOVAT, "AccNOVAT");
    addWidget(ui->leByerAcc, "ByerAcc");
    addWidget(ui->leAccExpense, "AccExpense");
    fTable = "f_invoice_item";
    fCacheId = cid_invoice_item;
    ui->leGroupCode->setSelector(this, cache(cid_invoice_group), ui->leGroupName);
    ui->tblTaxPrint->setColumnWidth(0, 200);
}

REInvoiceItem::~REInvoiceItem()
{
    delete ui;
}

void REInvoiceItem::valuesToWidgets()
{
    RowEditorDialog::valuesToWidgets();
    ui->tblTaxPrint->clearContents();

    DoubleDatabase fDD;
    
    fDD.exec("select f_comp from serv_tax where f_active=1");
    ui->tblTaxPrint->setRowCount(fDD.rowCount());
    for (int i = 0; i < fDD.rowCount(); i++) {
        ui->tblTaxPrint->setItem(i, 0, new C5TableWidgetItem(fDD.getValue(i, "f_comp").toString()));
        fTaxMap[fDD.getValue(i, "f_comp").toString()] = i;
    }

    fDD[":f_item"] = ui->leCode->text();
    fDD.exec("select f_comp, f_tax from f_invoice_item_tax where f_item=:f_item");
    for (int i = 0; i < fDD.rowCount(); i++) {
        if (!fTaxMap.contains(fDD.getValue(i, "f_comp").toString())) {
            continue;
        }
        int row = fTaxMap[fDD.getValue(i, "f_comp").toString()];
        ui->tblTaxPrint->setItem(row, 1, new C5TableWidgetItem(fDD.getValue(i, "f_tax").toString()));
    }
}

void REInvoiceItem::on_tnCancel_clicked()
{
    reject();
}

void REInvoiceItem::on_btnOk_clicked()
{
    save();
    DoubleDatabase fDD;
    fDD[":f_item"] = ui->leCode->text();
    fDD.exec("delete from f_invoice_item_tax where f_item=:f_item");
    for (int i = 0; i < ui->tblTaxPrint->rowCount(); i++) {
        if (!ui->tblTaxPrint->item(i, 1)) {
            continue;
        }
        fDD[":f_comp"] = ui->tblTaxPrint->toString(i, 0);
        fDD[":f_tax"] = ui->tblTaxPrint->toInt(i, 1);
        fDD[":f_item"] = ui->leCode->text();
        fDD.insert("f_invoice_item_tax", false);
    }
    BroadcastThread::cmdRefreshCache(cid_tax_map, ui->leCode->text());
}
