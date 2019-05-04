#include "dlgseachfromdatabase.h"
#include "ui_dlgseachfromdatabase.h"
#include "utils.h"

DlgSeachFromDatabase::DlgSeachFromDatabase(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgSeachFromDatabase)
{
    ui->setupUi(this);
}

DlgSeachFromDatabase::~DlgSeachFromDatabase()
{
    delete ui;
}

void DlgSeachFromDatabase::on_leSearch_returnPressed()
{
    ui->tbl->clearContents();
    DoubleDatabase dd(true, false);
    dd.exec(fQuery + fField.arg(ui->leSearch->text()));
    ui->tbl->setColumnCount(dd.columnCount());
    int row = 0;
    ui->tbl->setRowCount(dd.rowCount());
    while (dd.nextRow()) {
        for (int i = 0; i < ui->tbl->columnCount(); i++) {
            ui->tbl->setItemWithValue(row, i, dd.getValue(i));
        }
        row++;
    }
}

void DlgSeachFromDatabase::on_tbl_doubleClicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    for (int i = 0; i < ui->tbl->columnCount(); i++) {
        fResult << ui->tbl->itemValue(index.row(), i, Qt::EditRole);
    }
    accept();
}
