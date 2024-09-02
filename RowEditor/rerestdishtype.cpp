#include "rerestdishtype.h"
#include "ui_rerestdishtype.h"
#include "cacherestdishtype.h"
#include "cacherestdishpart.h"
#include <QColorDialog>

RERestDishType::RERestDishType(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_DISH_TYPE, parent),
    ui(new Ui::RERestDishType)
{
    ui->setupUi(this);
    ui->leTextColor->setText("-16777216");
    addWidget(ui->leCode, "Code");
    addWidget(ui->lePartCode, "");
    addWidget(ui->lePartName, "Part");
    addWidget(ui->leNameAm, "Name, am");
    addWidget(ui->leNameEn, "Name, en");
    addWidget(ui->leNameRu, "Name, ru");
    addWidget(ui->leBgColor, "Background color");
    addWidget(ui->leTextColor, "Text color");
    addWidget(ui->leQueue, "Queue");
    addWidget(ui->chActive, "Enabled");
    fTable = "r_dish_type";
    fCacheId = cid_rest_dish_type;
    ui->lePartCode->setSelector(this, cache(cid_rest_dish_part), ui->lePartName);
}

RERestDishType::~RERestDishType()
{
    delete ui;
}

bool RERestDishType::isDataCorrect()
{
    if (ui->lePartCode->asInt() == 0) {
        message_error(tr("Part code must be defined"));
        return false;
    }
    if (ui->leQueue->asInt() == 0) {
        DoubleDatabase fDD;
        fDD.exec("select max(f_queue) as f_queue from r_dish_type");
        fDD.nextRow();
        ui->leQueue->setInt(fDD.getInt(0));
    }
    return true;
}

void RERestDishType::on_btnCancel_clicked()
{
    reject();
}

void RERestDishType::on_btnOk_clicked()
{
    if (!isDataCorrect()) {
        return;
    }
    save();
}

void RERestDishType::on_btnBgColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->leBgColor->color(), this, tr("Background color"));
    ui->leBgColor->setText(QString::number((int)color.rgb()));
}

void RERestDishType::on_btnTextColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->leTextColor->color(), this, tr("Text color"));
    ui->leTextColor->setText(QString::number((int)color.rgb()));
}
