#include "dlgtaxback.h"
#include "ui_dlgtaxback.h"
#include "basewidget.h"
#include "vauchers.h"

DlgTaxBack::DlgTaxBack(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgTaxBack)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                0, 300, 100, 0, 30, 80);
}

DlgTaxBack::~DlgTaxBack()
{
    delete ui;
}

void DlgTaxBack::taxBack(const QString &invoice, QList<QList<QVariant> >& rows)
{
    DlgTaxBack *d = new DlgTaxBack(fMainWindow);
    d->fInvoice = invoice;
    Utils::fillTableWithData(d->ui->tblData, rows);

    for(int i = 0; i < d->ui->tblData->rowCount(); i++) {
        d->ui->tblData->item(i, 4)->setCheckState(Qt::Unchecked);
    }

    d->exec();
    delete d;
}

void DlgTaxBack::on_btnCancel_clicked()
{
    reject();
}

void DlgTaxBack::on_btnOK_clicked()
{
    DoubleDatabase fDD;

    for(int i = 0; i < ui->tblData->rowCount(); i++) {
        if(ui->tblData->item(i, 4)->checkState() == Qt::Checked) {
            fDD[":f_fiscal"] = 0;
            fDD.update("m_register", where_id(ap(ui->tblData->toString(i, 0))));

            if(ui->tblData->toString(i, 3) == VAUCHER_ADVANCE_N) {
                fDD[":f_id"] = fInvoice;
                fDD[":f_prepaid"] = ui->tblData->toDouble(i, 2);
                fDD.exec("update m_v_invoice set f_prepaid=f_prepaid-:f_prepaid where f_id=:f_id");
            }

            TrackControl tc(TRACK_INVOICE_ITEM);
            tc.fInvoice = fInvoice;
            tc.fRecord = ui->tblData->toString(i, 0);
            tc.insert("Tax back",  ui->tblData->toString(i, 1), ui->tblData->toString(i, 5));
        }
    }

    accept();
}
