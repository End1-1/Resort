#include "dlgpretax.h"
#include "ui_dlgpretax.h"
#include "cacheinvoiceitem.h"
#include "cachetaxmap.h"
#include "dlgprinttaxsm.h"

DlgPreTax::DlgPreTax(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgPreTax)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                0, 300, 100, 50, 0);
}

DlgPreTax::~DlgPreTax()
{
    delete ui;
}

void DlgPreTax::addRow(const QList<QVariant> &data)
{
    Utils::tableAppendRowData(ui->tblData, data, Qt::DisplayRole);
    C5TableWidgetItem *item = ui->tblData->item(ui->tblData->rowCount() - 1, 3);
    item->setCheckState(Qt::Checked);
    countTotal();
}

void DlgPreTax::setInvoice(const QString &invoice)
{
    fInvoice = invoice;
}

void DlgPreTax::countTotal()
{
    double total = 0;
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        C5TableWidgetItem *item = ui->tblData->item(i, 3);
        if (item->checkState() == Qt::Checked) {
            total += ui->tblData->toDouble(i, 2);
        }
    }
    ui->leTotal->setDouble(total);
}

void DlgPreTax::on_tblData_clicked(const QModelIndex &index)
{
    if (index.column() == 3) {
        countTotal();
    }
}

void DlgPreTax::on_btnOk_clicked()
{
    QString out;
    for (int  i = 0; i < ui->tblData->rowCount(); i++) {
        C5TableWidgetItem *item = ui->tblData->item(i, 3);
        if (item->checkState() == Qt::Checked) {
            int tc;
            CacheInvoiceItem c;
            if (!c.get(fPreferences.getDb(def_advance_voucher_id).toInt())) {
                message_error(tr("Error in tax print. c == 0, case 2."));
                continue;
            }
            CacheTaxMap ci;
            if (!ci.get(c.fCode())) {
                message_error(tr("No taxmap for ") + c.fName());
                return;
            }
            if (DlgPrintTaxSM::printAdvance(ci.fTax(), ui->tblData->toDouble(i, 2),  0, ui->tblData->toString(i, 0), ui->tblData->toString(i, 0), tc, out)) {
                DoubleDatabase fDD;
                fDD[":f_fiscal"] = tc;
                fDD.update("m_register", where_id(ap(ui->tblData->toInt(i, 0))));
                if (fInvoice.length() > 0) {
                    fDD[":f_amount"] = ui->tblData->toDouble(i, 2);
                    fDD[":f_id"] = fInvoice;
                    fDD.exec("update m_v_invoice set f_prepaid=f_prepaid+:f_amount where f_id=:f_id");
                }
            }
        }
    }
    accept();
}

void DlgPreTax::on_btnCancel_clicked()
{
    reject();
}
