#include "dlgtaxback2.h"
#include "ui_dlgtaxback2.h"
#include "dlgprinttaxsm.h"

DlgTaxBack2::DlgTaxBack2(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgTaxBack2)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                0, 300, 100, 100, 0, 30);
}

DlgTaxBack2::~DlgTaxBack2()
{
    delete ui;
}

void DlgTaxBack2::taxBack(const QString &invoice, const QList<QVariant> &numbers)
{
    DlgTaxBack2 *d = new DlgTaxBack2(fPreferences.getDefaultParentForMessage());
    d->fInvoice = invoice;
    QString ids;
    bool first = true;
    foreach (QVariant n, numbers) {
        if (first) {
            first = false;
        } else {
            ids += ",";
        }
        ids += n.toString();
    }
    d->load(ids);
    d->exec();
    delete d;
}

void DlgTaxBack2::on_btnCancel_clicked()
{
    reject();
}

void DlgTaxBack2::on_btnOK_clicked()
{
    QSet<int> ch;
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        if (ui->tblData->item(i, 5)->checkState() == Qt::Checked) {
            ch << ui->tblData->toInt(i, 3);
        }
    }
    DoubleDatabase fDD;
    foreach (int n, ch) {
        int taxCode = 0;
        if (DlgPrintTaxSM::printTaxback(fPreferences.getDb(def_default_fiscal_machine).toInt(), n, fInvoice, taxCode) == TAX_OK) {
            for (int i = 0; i < ui->tblData->rowCount(); i++) {
                if (ui->tblData->toInt(i, 3) == n) {
                    fDD[":f_id"] = ui->tblData->toString(i, 0);
                    fDD.exec("update m_register set f_fiscal=0 where f_id=" + ap(ui->tblData->toString(i, 0)));
                }
            }
        }
    }
    accept();
}

void DlgTaxBack2::load(const QString &ids)
{
    if (ids.isEmpty()) {
        return;
    }
    DoubleDatabase fDD;
    fDD.exec("select f_id, f_finalName, f_amountAmd, f_fiscal, f_source from m_register where f_fiscal in (" + ids + ") ");
    ui->tblData->setRowCount(fDD.rowCount());
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        ui->tblData->setItemWithValue(i, 0, fDD.getValue(i, "f_id"));
        ui->tblData->setItemWithValue(i, 1, fDD.getValue(i, "f_finalName"));
        ui->tblData->setItemWithValue(i, 2, fDD.getValue(i, "f_amountAmd"));
        ui->tblData->setItemWithValue(i, 3, fDD.getValue(i, "f_fiscal"));
        ui->tblData->setItemWithValue(i, 4, fDD.getValue(i, "f_source"));
        ui->tblData->setItemWithValue(i, 5, 0);
        ui->tblData->item(i, 5)->setCheckState(Qt::Unchecked);
    }
}
