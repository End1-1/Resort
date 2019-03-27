#include "recallrate.h"
#include "ui_recallrate.h"

RECallRate::RECallRate(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_CALL_RATE, parent),
    ui(new Ui::RECallRate)
{
    ui->setupUi(this);
    addWidget(ui->leID, "ID")
            .addWidget(ui->leDirection, "Direction")
            .addWidget(ui->leLocal, "Local")
            .addWidget(ui->leArea, "Area")
            .addWidget(ui->leCode, "Code")
            .addWidget(ui->leRate, "Rate");
    fTable = "f_call_rate";
    fCacheId = 0;
}

RECallRate::~RECallRate()
{
    delete ui;
}

void RECallRate::on_btnCancel_clicked()
{
    reject();
}

void RECallRate::on_btnOK_clicked()
{
    save();
}
