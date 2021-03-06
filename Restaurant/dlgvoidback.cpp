#include "dlgvoidback.h"
#include "ui_dlgvoidback.h"
#include "rmessage.h"
#include <QScrollBar>

DlgVoidBack::DlgVoidBack(QWidget *parent) :
    BaseExtendedDialogR(parent),
    ui(new Ui::DlgVoidBack)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                30, 0, 200, 100, 100, 200, 300, 100, 100);
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_state1"] = DISH_STATE_REMOVED_NOSTORE;
    fDD[":f_state2"] = DISH_STATE_REMOVED_STORE;
    fDD[":f_date"] = WORKING_DATE;
    fDD.exec("select '', od.f_id, oh.f_id, h.f_name, t.f_name, concat(u.f_firstName, ' ', u.f_lastName), d.f_" + def_lang + ", "
               "od.f_qty, od.f_total from o_dish od "
               "left join o_header oh on oh.f_id=od.f_header "
               "left join r_dish d on d.f_id=od.f_dish "
               "left join r_hall h on h.f_id=oh.f_hall "
               "left join r_table t on t.f_id=oh.f_table "
               "left join users u on u.f_id=oh.f_staff "
               "where oh.f_dateCash=:f_date and (od.f_state=:f_state1 or od.f_state=:f_state2)");
    Utils::fillTableWithData(ui->tblData, fDD.fDbRows);
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        ui->tblData->item(i, 0)->setCheckState(Qt::Unchecked);
    }
    showFullScreen();
}

DlgVoidBack::~DlgVoidBack()
{
    delete ui;
}

void DlgVoidBack::recover()
{
    DlgVoidBack *d = new DlgVoidBack();
    d->exec();
    delete d;
}

void DlgVoidBack::on_btnCancel_clicked()
{
    reject();
}

void DlgVoidBack::on_btnUp_clicked()
{
    ui->tblData->verticalScrollBar()->setValue(ui->tblData->verticalScrollBar()->value() - 6);
}

void DlgVoidBack::on_btnDown_clicked()
{
    ui->tblData->verticalScrollBar()->setValue(ui->tblData->verticalScrollBar()->value() + 6);
}

void DlgVoidBack::on_btnRecover_clicked()
{
    if (message_question("Confirm to recover selected entries") != QDialog::Accepted) {
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    for (int i = ui->tblData->rowCount() - 1; i > -1; i--) {
        if (ui->tblData->item(i, 0)->checkState() == Qt::Checked) {
            fDD[":f_state"] = DISH_STATE_READY;
            fDD.update("o_dish", where_id(ui->tblData->item(i, 1)->data(Qt::EditRole).toInt()));
            fDD[":f_header"] = ui->tblData->item(i, 2)->data(Qt::EditRole);
            fDD[":f_state"] = DISH_STATE_READY;
            fDD.exec("select sum(f_total) from o_dish where f_header=:f_header and f_state=:f_state");
            fDD[":f_total"] = fDD.fDbRows.at(0).at(0);
            fDD[":f_id"] = ui->tblData->item(i, 2)->data(Qt::EditRole);
            fDD.update("o_header", where_id(ui->tblData->item(i, 2)->data(Qt::EditRole).toInt()));
            ui->tblData->removeRow(i);
        }
    }
}

void DlgVoidBack::on_tblData_clicked(const QModelIndex &index)
{
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        ui->tblData->item(i, 0)->setCheckState(Qt::Unchecked);
    }
    if (!index.isValid()) {
        return;
    }
    ui->tblData->item(index.row(), 0)->setCheckState(Qt::Checked);
}
