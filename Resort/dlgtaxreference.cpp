#include "dlgtaxreference.h"
#include "ui_dlgtaxreference.h"

DlgTaxReference::DlgTaxReference(int itemId, QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgTaxReference)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                0, 100, 100, 300, 100, 140);
    fItemId = itemId;
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_item"] = itemId;
    fDD.exec("select t.f_id, r.f_room, t.f_invoice, i.f_" + def_lang + ", t.f_amount, f_date "
               "from m_free_tax t "
               "left join f_invoice_item i on i.f_id=t.f_item "
               "left join f_reservation r on r.f_invoice=t.f_invoice "
               "where t.f_item<>:f_item and f_used=0");
    Utils::fillTableWithData(ui->tblData, fDD.fDbRows);
    ui->tblData->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tblData, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(tblContextMenu(QPoint)));
    fTaxMenu.addAction(tr("Remove entry"), this, SLOT(deleteRow()));
    on_rbThisInvoice_clicked();
}

DlgTaxReference::~DlgTaxReference()
{
    delete ui;
}

void DlgTaxReference::setHeader(const QString &room, const QString &guest, const QString &invoice)
{
    ui->leRoom->setText(room);
    ui->leGuest->setText(guest);
    ui->leInvoice->setText(invoice);
    filterRows();
}

void DlgTaxReference::setItem(const QString &name, const QString &amount, int recId)
{
    ui->leEntryName->setText(name);
    ui->leAmount->setText(amount);
    fRecId = recId;
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        if (ui->tblData->toString(i, 4) != amount) {
            ui->tblData->setRowHidden(i, true);
        }
    }
}

void DlgTaxReference::tblContextMenu(const QPoint &p)
{
    fTaxMenu.popup(ui->tblData->mapToGlobal(p));
}

void DlgTaxReference::deleteRow()
{
    QModelIndexList sel = ui->tblData->selectionModel()->selectedRows();
    if (sel.count() == 0) {
        message_info(tr("Nothing is selected"));
        return;
    }
    if (message_confirm(tr("Confirm to delete selected row")) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_id"] = ui->tblData->toInt(sel.at(0).row(), 0);
    fDD.exec("delete from m_free_tax where f_id=:f_id");
    ui->tblData->removeRow(sel.at(0).row());
}

void DlgTaxReference::on_leSearch_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
}

void DlgTaxReference::on_tblData_doubleClicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_fiscal"] = 1;
    fDD.update("m_register", where_id(fRecId));
    fDD[":f_used"] = 1;
    fDD.update("m_free_tax", where_id(ui->tblData->toInt(index.row(), 0)));
    accept();
}

void DlgTaxReference::filterRows()
{
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        if (ui->rbThisInvoice->isChecked()) {
            ui->tblData->setRowHidden(i, false);
            if (ui->tblData->toString(i, 2) != ui->leInvoice->text()) {
                ui->tblData->setRowHidden(i, true);
            }
        } else {
            ui->tblData->setRowHidden(i, false);
        }
    }
}

void DlgTaxReference::on_rbAllInvoice_clicked()
{
    filterRows();
}

void DlgTaxReference::on_rbThisInvoice_clicked()
{
    filterRows();
}
