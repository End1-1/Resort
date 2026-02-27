#include "rerestdish.h"
#include "ui_rerestdish.h"
#include "dlgtracking.h"
#include "eqcheckbox.h"
#include "cacherestprinters.h"
#include "cachereststore.h"
#include "cacherestdishmod.h"
#include "cacherestdishtype.h"
#include "cachedish.h"
#include <QColorDialog>
#include <QFileDialog>
#include <QBuffer>

#define HINT_DISH 1

RERestDish::RERestDish(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_DISH, parent),
    ui(new Ui::RERestDish)
{
    ui->setupUi(this);
    ui->leTextColor->setText("-16777216");
    addWidget(ui->leCode, "Code");
    addWidget(ui->lePart, "Part");
    addWidget(ui->leTypeCode, "");
    addWidget(ui->leTypeName, "Type");
    addWidget(ui->leNameAm, "Name, am");
    addWidget(ui->leNameEn, "Name, en");
    addWidget(ui->leNameRu, "Name, ru");
    addWidget(ui->teAm, "Text, am");
    addWidget(ui->teEn, "Text, en");
    addWidget(ui->teRu, "Text, ru");
    addWidget(ui->leBgColor, "Backgroun color");
    addWidget(ui->leTextColor, "Text color");
    addWidget(ui->leQueue, "Queue");
    addWidget(ui->leADGT, "ADGT");
    addWidget(ui->leArmSoft, "ArmSoft code");
    addWidget(ui->leLastPrice, "Last input price");
    fTable = "r_dish";
    ui->leQueue->setValidator(new QIntValidator());
    Utils::tableSetColumnWidths(ui->tblMenu, ui->tblMenu->columnCount(),
                                30, 0, 0, 100, 100, 100, 100, 100, 0, 50);
    DoubleDatabase fDD;
    fDD.exec("select f_id, f_en from r_menu_names");
    ui->tblMenu->setRowCount(fDD.rowCount());
    int row = 0;
    while (fDD.nextRow()) {
        QCheckBox *check = new QCheckBox(this);
        check->setChecked(false);
        ui->tblMenu->setCellWidget(row, 0, check);
        fTrackControl->addWidget(check, "Checkbox of " + fDD.getString(1));
        for (int i = 1, count = ui->tblMenu->columnCount() - 1; i < count; i++) {
            EQLineEdit *l = createLineEdit(row, i);
            switch (i) {
            case 2:
                l->setText(fDD.getString(0));
                break;
            case 3:
                l->setText(fDD.getString(1));
                l->setReadOnly(true);
                break;
            case 4:
                fTrackControl->addWidget(l, "Price for " + fDD.getString(1));
                break;
            case 5:
                l->setShowButtonOnFocus(true);
                l->setSelector(this, cache(cid_rest_printers), l);
                fTrackControl->addWidget(l, "Printer1 for " + fDD.getString(1));
                break;
            case 6:
                l->setShowButtonOnFocus(true);
                l->setSelector(this, cache(cid_rest_printers), l);
                fTrackControl->addWidget(l, "Printer2 for " + fDD.getString(1));
                break;
            case 7:
                l->setShowButtonOnFocus(true);
                l->setSelector(this, cache(cid_rest_store), l);
                fTrackControl->addWidget(l, "Store for " + fDD.getString(1));
                break;
            }
        }
        EQCheckBox *checkComplex = new EQCheckBox(this);
        checkComplex->setChecked(false);
        checkComplex->fRow = row;
        checkComplex->fColumn = 9;
        connect(checkComplex, SIGNAL(clicked(bool)), this, SLOT(checkComplex(bool)));
        ui->tblMenu->setCellWidget(row, 9, checkComplex);
        row++;
    }

    Utils::tableSetColumnWidths(ui->tblModifier, ui->tblModifier->columnCount(), 0, 0, 300, 30);
    ui->leTypeCode->setSelector(this, cache(cid_rest_dish_type), ui->leTypeName);
    connect(ui->tabPage, SIGNAL(currentChanged(int)), this, SLOT(tabPageIndexChanged(int)));
    fImageChanged = false;
    fImageLoaded = false;
}

RERestDish::~RERestDish()
{
    delete ui;
}

void RERestDish::selector(int number, const QVariant &value)
{
    Q_UNUSED(value);
    Q_UNUSED(number);
//    switch (number) {
//    case SEL_DISH: {
//        CI_Dish *c = value.value<CI_Dish*>();
//        if (!c) {
//            return;
//        }
//        addDishRow(c.fCode(), c.fName(), 0);
//        break;
//    }
//    }
}

bool RERestDish::isDataCorrect()
{
    if (ui->leTypeCode->asInt() == 0) {
        fDataErrors.append(tr("Type code must be defined"));
    }
    if (ui->leQueue->asInt() == 0) {
        DoubleDatabase fDD;
        fDD.exec("select max(f_queue) as f_queue from r_dish");
        fDD.nextRow();
        ui->leQueue->setInt(fDD.getInt(0));
    }
    return fDataErrors.count() == 0;
}

void RERestDish::valuesToWidgets()
{
    DoubleDatabase fDD;
    RowEditorDialog::valuesToWidgets();
    ui->tblRecipe->clearContents();
    ui->tblRecipe->setRowCount(0);
    if (!isNew) {
        fDD[":f_dish"] = ui->leCode->asInt();
        fDD.exec("select m.f_id, m.f_state, m.f_menu, m.f_price, m.f_print1, m.f_print2, "
                   "m.f_store, s.f_name, m.f_complex "
                   "from r_menu m "
                   "left join r_store s on s.f_id=m.f_store "
                   "where m.f_dish=:f_dish");
        while (fDD.nextRow()) {
            int row = 0;
            bool found = false;
            for (int i = 0, count = ui->tblMenu->rowCount(); i < count; i++) {
                if (cellValue(i, 2) == fDD.getString(2)) {
                    row = i;
                    found = true;
                    break;
                }
            }
            if (!found) {
                continue;
            }
            setCellValue(row, 1, fDD.getString(0)); //table rec id
            setCellValue(row, 4, fDD.getString(3)); //price
            CacheInstance *ci = cache(cid_rest_printers);
            QMap<QString, QList<QVariant> >::iterator it = ci->fRows.begin();
            QString code;
            while (code.isEmpty() && it != ci->fRows.end()) {
                QList<QVariant>::iterator it2 = it.value().begin();
                while (it2 != it.value().end()) {
                    if ((*it2).toString() ==  fDD.getString(4)) {
                        code = it.key();
                        break;
                    }
                    it2++;
                }
                it++;
            }
            static_cast<EQLineEdit*>(ui->tblMenu->cellWidget(row, 5))->setInitialValue(code);
            code.clear();
            it = ci->fRows.begin();
            while (code.isEmpty() && it != ci->fRows.end()) {
                QList<QVariant>::iterator it2 = it.value().begin();
                while (it2 != it.value().end()) {
                    if ((*it2).toString() ==  fDD.getString(5)) {
                        code = it.key();
                        break;
                    }
                    it2++;
                }
                it++;
            }
            static_cast<EQLineEdit*>(ui->tblMenu->cellWidget(row, 6))->setInitialValue(code);
            static_cast<EQLineEdit*>(ui->tblMenu->cellWidget(row, 7))->setInitialValue(fDD.getString(6));
            //setCellValue(row, 7, fDD.getString(6)); //store id
           // setCellValue(row, 8, fDD.getString(7)); //store name
            QCheckBox *check = static_cast<QCheckBox*>(ui->tblMenu->cellWidget(row, 0));
            check->setChecked(fDD.getInt(1) == 1);

            check = static_cast<QCheckBox*>(ui->tblMenu->cellWidget(row, 9));
            check->setChecked(fDD.getInt(8) == 1);
        }

        fDD[":f_dish"] = ui->leCode->asInt();
        fDD.exec("select r.f_part, d.f_en, r.f_qty "
                  "from r_recipe r "
                  "left join r_dish d on d.f_id=r.f_part "
                  "where r.f_dish=:f_dish");
        while (fDD.nextRow()) {
            addDishRow(fDD.getString("f_part"), fDD.getString("f_en"), fDD.getDouble("f_qty"));
        }
        fDD[":f_dish"] = ui->leCode->text();
        fDD.exec("select f_code from r_dish_scancode where f_dish=:f_dish");
        for (int  i = 0; i < fDD.rowCount(); i++) {
            QListWidgetItem *item = new QListWidgetItem(ui->lstScancodes);
            item->setText(fDD.getString(i, "f_scancode"));
            ui->lstScancodes->addItem(item);
        }
    }
    fDD[":f_dish"] = ui->leCode->asInt();
    fDD.exec("select m.f_id, m.f_mod, mn.f_" + def_lang + " "
               "from r_dish_mod_required m "
               "inner join r_dish_mod mn on mn.f_id=m.f_mod "
               "where m.f_dish=:f_dish");
//    CacheRestDishMod mod;
//    while (fDD.nextRow()) {
//        mod.fCode = it->at(1).toString();
//        mod.fName = it->at(2).toString();
//        dishMod(&mod);
//        ui->tblModifier->item(ui->tblModifier->rowCount() - 1, 0)->setText(it->at(0).toString());
//    }

    fDD[":f_id"] = ui->leCode->asInt();
    fDD.exec("select f_tax from r_dish where f_id=:f_id");
    fDD.nextRow();
    ui->chAutoPrintTax->setChecked((bool)fDD.getString("f_tax").toInt());
    fTrackControl->resetChanges();
}

void RERestDish::clearWidgets()
{
    RowEditorDialog::clearWidgets();
    for (int i = 0, count = ui->tblMenu->rowCount(); i < count; i++) {
        QCheckBox *check = static_cast<QCheckBox*>(ui->tblMenu->cellWidget(i, 0));
        check->setChecked(false);
        check = static_cast<QCheckBox*>(ui->tblMenu->cellWidget(i, 9));
                check->setChecked(false);
        for (int j = 1, colCount = ui->tblMenu->columnCount() - 1; j < colCount; j++) {
            switch (j) {
            case 2:
            case 3:
                continue;
            default:
                setCellValue(i, j, "");
                break;
            }
        }
    }
    ui->tblModifier->clearContents();
    ui->tblModifier->setRowCount(0);
    ui->lstScancodes->clear();
    fImageChanged = false;
    fImageLoaded = false;
    ui->lbImage->setPixmap(QPixmap(":/images/cancel.png"));
}

void RERestDish::save()
{
    RowEditorDialog::save();
    DoubleDatabase fDD;
    fDD[":f_dish"] = ui->leCode->text();
    fDD.exec("delete from r_menu where f_dish=:f_dish");
    for (int i = 0, rowCount = ui->tblMenu->rowCount(); i < rowCount; i++) {
        int id = cellValue(i, 1).toInt();
        QCheckBox *check = static_cast<QCheckBox*>(ui->tblMenu->cellWidget(i, 0));
        fDD[":f_state"] = check->isChecked() ? "1" : "0";
        fDD[":f_menu"] = cellValue(i, 2);
        fDD[":f_dish"] = ui->leCode->text();
        fDD[":f_price"] = cellDouble(i, 4);
        fDD[":f_print1"] = cellValue(i, 5);
        fDD[":f_print2"] = cellValue(i, 6);
        fDD[":f_store"] = static_cast<EQLineEdit*>(ui->tblMenu->cellWidget(i, 7))->fHiddenText.toInt();
        check = static_cast<QCheckBox*>(ui->tblMenu->cellWidget(i, 9));
        fDD[":f_complex"] = (int) check->isChecked();
        id = fDD.insert("r_menu", true);
        fDD.update("r_menu", where_id(id));
    }
    for (QStringList::const_iterator it = fRemovedModifiers.begin(); it != fRemovedModifiers.end(); it++) {
        fDD[":f_id"] = *it;
        fDD.exec("delete from r_dish_mod_required where f_id=:f_id");
    }
    for (int i = 0, rowCount = ui->tblModifier->rowCount(); i < rowCount; i++) {
        if (ui->tblModifier->item(i, 0)->text().isEmpty()) {
            fDD[":f_dish"] = ui->leCode->asInt();
            fDD[":f_mod"] = ui->tblModifier->item(i, 1)->text();
            fDD.insert("r_dish_mod_required");
        }
    }
    if (fImageChanged) {
        QPixmap p = ui->lbImage->pixmap();
        QByteArray bytes;
        QBuffer buff(&bytes);
        buff.open(QIODevice::WriteOnly);
        p.save(&buff, "PNG");
        fDD[":f_image"] = bytes;
        fDD.update("r_dish", where_id(ui->leCode->asInt()));
    }
    /* correct queue */
    fDD[":f_queue"] = ui->leQueue->asInt();
    fDD.exec("update r_dish set f_queue=f_queue+1 where f_queue>=:f_queue");
    fDD[":f_queue"] = ui->leQueue->asInt();
    fDD.update("r_dish", where_id(ui->leCode->asInt()));
    /* recipe */
    fDD[":f_dish"] = ui->leCode->asInt();
    fDD.exec("delete from r_recipe where f_dish=:f_dish");
    for (int i = 0; i < ui->tblRecipe->rowCount(); i++) {
        fDD[":f_dish"] = ui->leCode->asInt();
        fDD[":f_part"] = ui->tblRecipe->toInt(i, 0);
        fDD[":f_qty"] = ui->tblRecipe->lineEdit(i, 2)->asDouble();
        fDD.insert("r_recipe");
    }
    fDD[":f_lastPrice"] = ui->leLastPrice->asDouble();
    fDD.update("r_dish", where_id(ui->leCode->asInt()));
    /* scancodes */
    fDD[":f_dish"] = ui->leCode->text();
    fDD.exec("delete from r_dish_scancode where f_dish=:f_dish");
    for (int i = 0; i < ui->lstScancodes->count(); i++) {
        fDD[":f_code"] = ui->lstScancodes->item(i)->text();
        fDD.exec("delete from r_dish_scancode where f_code=:f_code");
        fDD[":f_dish"] = ui->leCode->text();
        fDD[":f_code"] = ui->lstScancodes->item(i)->text();
        fDD.insert("r_dish_scancode");
    }
    fDD[":f_tax"] = (int) ui->chAutoPrintTax->isChecked();
    fDD.update("r_dish", where_id(ui->leCode->asInt()));
}

void RERestDish::hide()
{
    if (ui->tabPage->currentIndex() == 2) {
        ui->tabPage->setCurrentIndex(0);
    }
}

void RERestDish::checkComplex(bool v)
{
    EQCheckBox *check = static_cast<EQCheckBox*>(sender());
    fTrackControl->insert("Complex for menu",
                              QString("%1 %2")
                              .arg(cellValue(check->fRow, 3))
                              .arg(int(!v)),
                              QString("%1 %2")
                              .arg(cellValue(check->fRow, 3))
                              .arg((int) v));
}

void RERestDish::tabPageIndexChanged(int index)
{
    if (index == 3) {
        if (!fImageLoaded) {
            if (ui->leCode->asInt() > 0) {
                DoubleDatabase fDD;
                fDD[":f_id"] = ui->leCode->asInt();
                fDD.exec("select f_image from r_dish where f_id=:f_id");
                QPixmap p;
                p.loadFromData(fDD.fDbRows.at(0).at(0).toByteArray());
                int w = ui->lbImage->width();
                int h = ui->lbImage->height();
                ui->lbImage->setPixmap(p.scaled(w, h));
            }
        }
    }
}

void RERestDish::dishMod(const QString &code)
{
    CacheRestDishMod m;
    if (m.get(code)) {
        int row = ui->tblModifier->rowCount();
        ui->tblModifier->setRowCount(row + 1);
        for (int i = 0, colCount = ui->tblModifier->columnCount(); i < colCount; i++) {
            ui->tblModifier->setItem(row, i, new C5TableWidgetItem());
        }
        ui->tblModifier->item(row, 1)->setText(m.fCode());
        ui->tblModifier->item(row, 2)->setText(m.fName());
        EPushButton *b = new EPushButton(this);
        b->setMinimumSize(25, 25);
        b->setMaximumSize(25, 25);
        b->setIcon(QIcon(":/images/garbage.png"));
        b->setTag(row);
        connect(b, SIGNAL(clickedWithTag(int)), this, SLOT(btnRemoveModifier(int)));
        ui->tblModifier->setCellWidget(row, 3, b);
    }
}

void RERestDish::btnRemoveModifier(int row)
{
    fRemovedModifiers.append(ui->tblModifier->item(row, 0)->text());
    ui->tblModifier->removeRow(row);
}

void RERestDish::on_btnTextColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->leTextColor->color(), this, tr("Background color"));
    ui->leTextColor->setText(QString::number((int)color.rgb()));
}

void RERestDish::on_btnBgColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->leBgColor->color(), this, tr("Background color"));
    ui->leBgColor->setText(QString::number((int)color.rgb()));
}

void RERestDish::on_btnCancel_clicked()
{
    reject();
}

void RERestDish::on_btnOk_clicked()
{
    fDataErrors.clear();
    if (!isDataCorrect()) {
        message_error(fDataErrors.join("<br>"));
        return;
    }
    save();
}

EQLineEdit *RERestDish::createLineEdit(int row, int column)
{
    EQLineEdit *le = new EQLineEdit(this);
    le->setReadOnly(false);
    le->fRow = row;
    le->fColumn = column;
    le->setFrame(false);
    if (column == 4) {
        le->setValidator(new QDoubleValidator());
    }
    if (column == 7) {
        le->setValidator(new QIntValidator());
    }
    ui->tblMenu->setCellWidget(row, column, le);
    return le;
}

QString RERestDish::cellValue(int row, int column)
{
    EQLineEdit *l = static_cast<EQLineEdit*>(ui->tblMenu->cellWidget(row, column));
    return l->text();
}

double RERestDish::cellDouble(int row, int column)
{
    EQLineEdit *l = static_cast<EQLineEdit*>(ui->tblMenu->cellWidget(row, column));
    return l->asDouble();
}

void RERestDish::setCellValue(int row, int column, const QString &value)
{
    EQLineEdit *l = static_cast<EQLineEdit*>(ui->tblMenu->cellWidget(row, column));
    l->setText(value);
}

void RERestDish::addDishRow(const QString &code, const QString &name, double qty)
{
    int row = ui->tblRecipe->rowCount();
    ui->tblRecipe->setRowCount(row + 1);
    ui->tblRecipe->setItemWithValue(row, 0, code);
    ui->tblRecipe->setItemWithValue(row, 1, name);
    EQLineEdit *l = ui->tblRecipe->addLineEdit(row, 2, false);
    l->setValidator(new QDoubleValidator(0, 10000, 3));
    l->setDouble(qty);
}

void RERestDish::on_btnLoadImage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select image"), "", "*.jpg;*.png;*.jpeg");
    if (!fileName.isEmpty()) {
        fImageChanged = true;
        int w = ui->lbImage->width();
        int h = ui->lbImage->height();
        QPixmap p(fileName);
        ui->lbImage->setPixmap(p.scaled(w, h));
    }
}

void RERestDish::on_btnRemoveRecipeRow_clicked()
{
    int row = ui->tblRecipe->currentRow();
    if (row < 0) {
        return;
    }
    if (message_confirm(tr("Confirm to delete selected row")) != QDialog::Accepted) {
        return;
    }
    ui->tblRecipe->removeRow(row);
}

void RERestDish::on_btnClearRecipe_clicked()
{
    if (message_confirm(tr("Confirm to clear recipe")) != QDialog::Accepted) {
        return;
    }
    ui->tblRecipe->clearContents();
    ui->tblRecipe->setRowCount(0);
}

void RERestDish::on_chContainItself_clicked(bool checked)
{
    for (int i = 0; i < ui->tblRecipe->rowCount(); i++) {
        if (ui->tblRecipe->toString(i, 0) == ui->leCode->text()) {
            if (checked) {
                return;
            } else {
                ui->tblRecipe->removeRow(i);
                return;
            }
        }
    }
    CacheDish c;
    if (c.get(ui->leCode->text())) {
        addDishRow(c.fCode(), c.fName(), 1);
    }
}

void RERestDish::on_btnTrack_clicked()
{
    DlgTracking::showTracking(TRACK_DISH, ui->leCode->text());
}

void RERestDish::on_leReadScancode_returnPressed()
{
    if (ui->leReadScancode->isEmpty()) {
        return;
    }
    QListWidgetItem *item = new QListWidgetItem(ui->lstScancodes);
    item->setText(ui->leReadScancode->text());
    ui->lstScancodes->addItem(item);
    ui->leReadScancode->clear();
}
