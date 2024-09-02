#include "rerestdishcomplex.h"
#include "cacherestmenu.h"
#include "cachemenudishes.h"
#include "ui_rerestdishcomplex.h"

#define HINT_MENU 1

RERestDishComplex::RERestDishComplex(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_DISH_COMPLEX, parent),
    ui(new Ui::RERestDishComplex)
{
    ui->setupUi(this);
    ui->leMenuCode->setVisible(false);
    ui->leDishCode->setVisible(false);
    addWidget(ui->leCode, "Code");
    addWidget(ui->leNameAm, "Name, am");
    addWidget(ui->leNameEn, "Name, en");
    addWidget(ui->leNameRu, "Name, ru");
    addWidget(ui->teStart, "Start time");
    addWidget(ui->teEnd, "End time");
    addWidget(ui->lePrice, "Price");
    addWidget(ui->lePriceDeviation, "Price deviation");
    addWidget(ui->leAdgt, "ADGT");
    addWidget(ui->chEnabled, "Enabled");
    ui->lePrice->setValidator(new QDoubleValidator(0, 0, 2));
    ui->lePriceDeviation->setValidator(new QIntValidator());
    fTable = "r_dish_complex";
    Utils::tableSetColumnWidths(ui->tblDishes, ui->tblDishes->columnCount(),
                                0, 0, 150, 200, 80, 30);
    ui->leMenuCode->setSelector(this, cache(cid_rest_menu), ui->leMenu, HINT_MENU);
    ui->leDishCode->setSelector(this, cache(cid_menu_dishes), ui->leDishName);
}

RERestDishComplex::~RERestDishComplex()
{
    delete ui;
}

void RERestDishComplex::callback(int sel, const QString &code)
{
    switch (sel) {
    case HINT_MENU: {
        CacheRestMenu c;
        ui->leDishCode->fFieldFilter.clear();
        if (c.get(code)) {
            ui->leDishCode->fFieldFilter["f_menu"] << c.fCode();
        }
        break;
    }
    }
}

void RERestDishComplex::valuesToWidgets()
{
    RowEditorDialog::valuesToWidgets();
    DoubleDatabase fDD;
    if (!isNew) {
        fDD[":f_complex"] = ui->leCode->asInt();
        fDD.exec("select rc.f_id, rc.f_dish, mn.f_" + def_lang + ", d.f_" + def_lang + ", m.f_price "
                   "from r_dish_complex_list rc "
                   "inner join r_menu m on m.f_id=rc.f_dish "
                   "inner join r_menu_names mn on mn.f_id=m.f_menu "
                   "inner join r_dish d on d.f_id=m.f_dish "
                   "where rc.f_complex=:f_complex");
        int row = 0;
        while (fDD.nextRow()) {
            ui->tblDishes->setRowCount(row + 1);
            ui->tblDishes->setRowCount(row + 1);
            ui->tblDishes->setItem(row, 0, Utils::tableItem(fDD.getValue(0)));
            ui->tblDishes->setItem(row, 1, Utils::tableItem(fDD.getValue(1)));
            ui->tblDishes->setItem(row, 2, Utils::tableItem(fDD.getValue(2)));
            ui->tblDishes->setItem(row, 3, Utils::tableItem(fDD.getValue(3)));
            ui->tblDishes->setItem(row, 4, Utils::tableItem(fDD.getValue(4)));
            ui->tblDishes->addButton(row, 5, SLOT(removeRow(int)), this, QIcon(":/images/garbage.png"));
            row++;
        }
    }
}

void RERestDishComplex::clearWidgets()
{
    RowEditorDialog::clearWidgets();
    ui->tblDishes->clearContents();
    ui->tblDishes->setRowCount(0);
    ui->leMenu->clear();
    ui->leMenuCode->clear();
    ui->leDishCode->clear();
    ui->leDishName->clear();
    ui->leDishesTotal->setText("0");
}

void RERestDishComplex::removeRow(int row)
{
    EPushButton *btn = static_cast<EPushButton*>(sender());
    row = -1;
    for (int i = 0; i < ui->tblDishes->rowCount(); i++) {
        if (btn == ui->tblDishes->cellWidget(i, 5)) {
            row = i;
            break;
        }
    }
    if (row < 0) {
        return;
    }
    if (message_confirm(tr("Confirm to delete selected row")) != QDialog::Accepted) {
        return;
    }
    if (ui->tblDishes->toInt(row, 0) > 0) {
        DoubleDatabase fDD;
        fDD[":f_dish"] = ui->tblDishes->toInt(row, 1);
        fDD[":f_complex"] = ui->leCode->asInt();
        fDD.exec("delete from r_dish_complex_list where f_complex=:f_complex and f_dish=:f_dish");
        fTrackControl->insert("Remove dish", QString("%1 / %2")
                                  .arg(ui->tblDishes->toString(row, 3))
                                  .arg(ui->tblDishes->toString(row, 4)), "");
    }
    ui->tblDishes->removeRow(row);
}

void RERestDishComplex::on_btnCancel_clicked()
{
    reject();
}

void RERestDishComplex::on_btnOK_clicked()
{
    save();
    for (int i = 0; i < ui->tblDishes->rowCount(); i++) {
        if (ui->tblDishes->toInt(i, 0) == 0) {
            DoubleDatabase fDD;
            fDD[":f_complex"] = ui->leCode->asInt();
            fDD[":f_dish"] = ui->tblDishes->toInt(i, 1);
            fDD.insert("r_dish_complex_list");
            fTrackControl->insert("Append dish", QString("%1 / %2")
                                      .arg(ui->tblDishes->toString(i, 3))
                                      .arg(ui->tblDishes->toString(i, 4)), "");
        }
    }
    fTrackControl->saveChanges();
}

void RERestDishComplex::on_btnAdd_clicked()
{
    CacheMenuDishes c;
    if (!c.get(ui->leDishCode->text())) {
        return;
    }
    int row = ui->tblDishes->rowCount();
    ui->tblDishes->setRowCount(row + 1);
    ui->tblDishes->setItem(row, 0, new C5TableWidgetItem("0"));
    ui->tblDishes->setItem(row, 1, Utils::tableItem(c.fCode()));
    ui->tblDishes->setItem(row, 2, Utils::tableItem(c.fMenu()));
    ui->tblDishes->setItem(row, 3, Utils::tableItem(c.fName()));
    ui->tblDishes->setItem(row, 4, Utils::tableItem(c.fPrice()));
    ui->tblDishes->addButton(row, 5, SLOT(removeRow(int)), this, QIcon(":/images/garbage.png"));
    countTotal();
}

void RERestDishComplex::countTotal()
{
    double total = 0;
    for (int i = 0; i < ui->tblDishes->rowCount(); i++) {
        total += ui->tblDishes->toDouble(i, 4);
    }
    ui->leDishesTotal->setDouble(total);
}
