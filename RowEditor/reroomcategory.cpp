#include "reroomcategory.h"
#include "ui_reroomcategory.h"

RERoomCategory::RERoomCategory(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_ROOM_CATEGORY, parent),
    ui(new Ui::RERoomCategory)
{
    ui->setupUi(this);
    ui->leOrder->setValidator(new QIntValidator());
    addWidget(ui->leCode, "Code");
    addWidget(ui->leShort, "Short");
    addWidget(ui->leDescription, "Description");
    addWidget(ui->leOrder, "Order");
    fTable = "f_room_classes";
}

RERoomCategory::~RERoomCategory()
{
    delete ui;
}

void RERoomCategory::on_btnCancel_clicked()
{
    reject();
}

void RERoomCategory::on_btnOk_clicked()
{
    save();
}
