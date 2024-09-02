#include "dlgdishhistory.h"
#include "ui_dlgdishhistory.h"

DlgDishHistory::DlgDishHistory(const QString &dishId, QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgDishHistory)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(), 100, 300, 200);
    DoubleDatabase fDD;
    fDD[":f_rec"] = dishId;
    fDD.exec("select f_date, f_user, f_info from o_dish_qty where f_rec=:f_rec order by f_date");
    Utils::fillTableWithData(ui->tblData, fDD.fDbRows);
}

DlgDishHistory::~DlgDishHistory()
{
    delete ui;
}
