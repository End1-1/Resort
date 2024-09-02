#include "reresttable.h"
#include "ui_reresttable.h"
#include "cacheresthall.h"

#define HINT_HALL 1

RERestTable::RERestTable(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_REST_TABLE, parent),
    ui(new Ui::RERestTable)
{
    ui->setupUi(this);
    addWidget(ui->leCode, "Code");
    addWidget(ui->leName, "Name");
    addWidget(ui->leHallCode, "");
    addWidget(ui->leHallName, "Hall");
    addWidget(ui->leQueue, "Queue");
    fTable = "r_table";
    ui->leHallCode->setSelector(this, cache(cid_rest_hall), ui->leHallName, HINT_HALL);
}

RERestTable::~RERestTable()
{
    delete ui;
}

bool RERestTable::isDataCorrect()
{
    if (ui->leHallCode->asInt() == 0) {
        message_error(tr("Hall is not defined for this table"));
        return false;
    }
    return true;
}

void RERestTable::on_btnCancel_clicked()
{
    reject();
}

void RERestTable::on_btnOk_clicked()
{
    DoubleDatabase fDD;
    if (ui->leQueue->asInt() == 0) {
        fDD.exec("select max(f_queue) + 1 as q from r_table");
        fDD.nextRow();
        ui->leQueue->setInt(fDD.getInt(0));
    }
    save();
}
