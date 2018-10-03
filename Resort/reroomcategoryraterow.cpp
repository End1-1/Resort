#include "reroomcategoryraterow.h"
#include "ui_reroomcategoryraterow.h"
#include "cachebed.h"

RERoomCategoryRateRow::RERoomCategoryRateRow(int category, QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_ROOM_CATEGORY_RATE, parent),
    ui(new Ui::RERoomCategoryRateRow)
{
    ui->setupUi(this);
    ui->leCategory->setValidator(new QIntValidator());
    ui->leRate->setValidator(new QDoubleValidator(0, 9999999, 0));
    ui->leMonth1->setValidator(new QIntValidator());
    ui->leMonth2->setValidator(new QIntValidator());
    ui->leDay1->setValidator(new QIntValidator());
    ui->leDay2->setValidator(new QIntValidator());
    ui->leCode->setVisible(false);
    ui->leCategory->setVisible(false);
    ui->lbCategory->setVisible(false);
    ui->lbCode->setVisible(false);
    ui->leBedCode->setSelector(this, cache(cid_bed), ui->leBedName);
    fCategory = category;
    adjustSize();
    addWidget(ui->leCode, "Code");
    addWidget(ui->leCategory, "Category");
    addWidget(ui->leMonth1, "Month1");
    addWidget(ui->leDay1, "Day1");
    addWidget(ui->leMonth2, "Month2");
    addWidget(ui->leDay2, "Day2");
    addWidget(ui->leBedCode, "");
    addWidget(ui->leBedName, "Bed");
    addWidget(ui->leRate, "Rate");
    fTable = "f_room_rate";
}

RERoomCategoryRateRow::~RERoomCategoryRateRow()
{
    delete ui;
}

void RERoomCategoryRateRow::valuesToWidgets()
{
    if (fValues.count() == 0) {
        ui->leCategory->setInt(fCategory);
    } else {
        RowEditorDialog::valuesToWidgets();
    }
}

void RERoomCategoryRateRow::on_btnCancel_clicked()
{
    reject();
}

void RERoomCategoryRateRow::on_btnOk_clicked()
{
    save();
}
