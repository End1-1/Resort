#include "dlgchangeexportvaucher.h"
#include "ui_dlgchangeexportvaucher.h"
#include "cacheinvoiceitem.h"

static const int HINT_INVOICE_ITEM = 1;

DlgChangeExportVaucher::DlgChangeExportVaucher(DoubleDatabase &db, QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgChangeExportVaucher),
    fVauchers(db)
{
    ui->setupUi(this);
    ui->leItemCode->setSelector(this, cache(cid_invoice_item), ui->leItemName, HINT_INVOICE_ITEM);
}

DlgChangeExportVaucher::~DlgChangeExportVaucher()
{
    delete ui;
}

void DlgChangeExportVaucher::callback(int sel, const QString &code)
{
    switch (sel) {
    case HINT_INVOICE_ITEM: {
        CacheInvoiceItem c;
        if (c.get(code)) {
            ui->leSource->setText(c.fVaucher());
        }
        break;
    }
    }
}

void DlgChangeExportVaucher::setDatabaseResult(int i)
{
    ui->deDate->setDate(fVauchers.getValue(i, "f_wdate").toDate());
    ui->leAmount->setText(fVauchers.getValue(i, "f_amountAmd").toString());
    ui->leItemCode->setText(fVauchers.getValue(i, "f_itemCode").toString());
    ui->leItemName->setText(fVauchers.getValue(i, "f_finalName").toString());
    ui->leSource->setText(fVauchers.getValue(i, "f_source").toString());
    ui->teTime->setTime(fVauchers.getValue(i, "f_time").toTime());
    fIndex = i;
}

void DlgChangeExportVaucher::on_btnCancel_clicked()
{
    reject();
}

void DlgChangeExportVaucher::on_btnOK_clicked()
{
    QString newId = uuidx(ui->leSource->text());
    fVauchers.setValue(fIndex, "f_id", newId);
    fVauchers.setValue(fIndex, "f_wdate", ui->deDate->date());
    fVauchers.setValue(fIndex, "f_rdate", ui->deDate->date());
    fVauchers.setValue(fIndex, "f_amountAmd", ui->leAmount->text());
    fVauchers.setValue(fIndex, "f_itemCode", ui->leItemCode->text());
    fVauchers.setValue(fIndex, "f_finalName", ui->leItemName->text());
    fVauchers.setValue(fIndex, "f_time", ui->teTime->time());
    fVauchers.setValue(fIndex, "f_source", ui->leSource->text());
    accept();
}
