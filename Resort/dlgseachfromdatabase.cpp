#include "dlgseachfromdatabase.h"
#include "ui_dlgseachfromdatabase.h"
#include "utils.h"
#include "dbmregister.h"

static QMap<DlgSeachFromDatabase::SearchTemplate, QString> stQuery;
static QMap<DlgSeachFromDatabase::SearchTemplate, QList<int> > stColumnsWidths;
static QMap<DlgSeachFromDatabase::SearchTemplate, QStringList> stColumnsTitles;

DlgSeachFromDatabase::DlgSeachFromDatabase(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgSeachFromDatabase)
{
    ui->setupUi(this);
    if (stQuery.isEmpty()) {
        stQuery[stVoucher] = DBMRegister::voucherQuery();
    }
}

void DlgSeachFromDatabase::setTemplate(DlgSeachFromDatabase::SearchTemplate st)
{
    fSearchTemplate = st;
}

DlgSeachFromDatabase::~DlgSeachFromDatabase()
{
    delete ui;
}

void DlgSeachFromDatabase::on_leSearch_returnPressed()
{
    ui->tbl->clearContents();
    if (fSearchTemplate > 0) {
        fQuery = stQuery[fSearchTemplate] + fField.arg(ui->leSearch->text());
    }
    DoubleDatabase dd;
    dd.exec(fQuery);
    ui->tbl->setColumnCount(dd.columnCount());
    int row = 0;
    ui->tbl->setRowCount(dd.rowCount());
    while (dd.nextRow()) {
        for (int i = 0; i < ui->tbl->columnCount(); i++) {
            ui->tbl->setItemWithValue(row, i, dd.getValue(i));
        }
        row++;
    }
    if (fSearchTemplate > 0) {

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
