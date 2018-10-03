#include "dlghouseitem.h"
#include "ui_dlghouseitem.h"
#include "cacheroominventorystate.h"
#include "cacheroominventory.h"
#include "cacheroom.h"

#define SEL_ROOM_IN 1

DlgHouseItem::DlgHouseItem(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgHouseItem)
{
    ui->setupUi(this);
    ui->leRoomCode->setSelector(this, cache(cid_room), ui->leRoomName, SEL_ROOM_IN);
    Utils::tableSetColumnWidths(ui->tblMain, ui->tblMain->columnCount(),
                                0, 300, 150, 120, 300);

    fleInventory = 0;
}

DlgHouseItem::~DlgHouseItem()
{
    delete ui;
}

void DlgHouseItem::callback(int sel, const QString &code)
{
    Q_UNUSED(code);
    switch (sel) {
    case SEL_ROOM_IN: {
        loadRoom();
        break;
    }
    }
}


void DlgHouseItem::openWindow()
{
    DlgHouseItem *d = new DlgHouseItem(fPreferences.getDefaultParentForMessage());
    d->exec();
    delete d;
}

void DlgHouseItem::comboStateCurrentIndexChanged(int index)
{
    Q_UNUSED(index)
    bool ok = true;
    for (int i = 0; i < ui->tblMain->rowCount(); i++) {
        ok = ok && ui->tblMain->comboBox(i, 2)->currentData().toInt() == 1;
    }
    if (ok) {
        ui->lbStatus->setPixmap(QPixmap(":/images/ball-green.png"));
    } else {
        ui->lbStatus->setPixmap(QPixmap(":/images/ball-red.png"));
    }
}

void DlgHouseItem::loadRoom()
{
    ui->tblMain->clearContents();
    ui->tblMain->setRowCount(0);
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_room"] = ui->leRoomCode->asInt();
    fDD.exec("select * from f_room_inventory_journal where f_room=:f_room");
    for (int i = 0; i < fDD.rowCount(); i++) {
        int row = addRow();
        ui->tblMain->setItemWithValue(row, 0, fDD.getValue("f_id"));
        ui->tblMain->lineEdit(row, 1)->fHiddenText = fDD.getValue("f_inventory").toString();
        CacheRoomInventory ci;
        ci.get(fDD.getValue("f_inventory").toString());
        //ui->tblMain->comboBox(row, 2)->setIndexForData(fDD.getValue("f_state").toInt());
        //ui->tblMain->dateEdit(row, 3)->setDate(fDD.getValue("f_date").toDate());
        //ui->tblMain->lineEdit(row, 4)->setText(fDD.getValue("f_comment").toString());
    }
    comboStateCurrentIndexChanged(0);
}

int DlgHouseItem::addRow()
{
    int row = ui->tblMain->rowCount();
    ui->tblMain->setRowCount(row + 1);
    ui->tblMain->setItemWithValue(row, 0, 0);
    EQLineEdit *l = ui->tblMain->addLineEdit(row, 1, false);
    connect(l, SIGNAL(focusIn()), this, SLOT(leFocusIn()));
    connect(l, SIGNAL(focusOut()), this, SLOT(leFocusOut()));
    EQComboBox *c = ui->tblMain->addComboBox(row, 2);
    c->setCache(cid_room_inventory_state);
    connect(c, SIGNAL(currentIndexChanged(int)), this, SLOT(comboStateCurrentIndexChanged(int)));
    ui->tblMain->addDateEdit(row, 3, false);
    ui->tblMain->addLineEdit(row, 4, false);
    l->setFocus();
    return row;
}

void DlgHouseItem::on_btnAddItem_clicked()
{
    addRow();
}

void DlgHouseItem::on_btnSave_clicked()
{
    for (int i = 0; i < ui->tblMain->rowCount(); i++) {
        if (ui->tblMain->lineEdit(i, 1)->fHiddenText.toInt() == 0) {
            message_error(tr("Incomplete document"));
            return;
        }
    }
    DoubleDatabase fDD(true, doubleDatabase);
    for (int i = 0; i < ui->tblMain->rowCount(); i++) {
        if (ui->tblMain->item(i, 0)->data(Qt::EditRole).toInt() == 0) {
            fDD[":f_id"] = 0;
            ui->tblMain->setItemWithValue(i, 0, fDD.insert("f_room_inventory_journal"));
        }
        fDD[":f_room"] = ui->leRoomCode->asInt();
        fDD[":f_inventory"] = ui->tblMain->lineEdit(i, 1)->fHiddenText.toInt();
        fDD[":f_state"] = ui->tblMain->comboBox(i, 2)->currentData();
        fDD[":f_date"] = ui->tblMain->dateEdit(i, 3)->date();
        fDD[":f_comment"] = ui->tblMain->lineEdit(i, 4)->text();
        fDD.update("f_room_inventory_journal", where_id(ui->tblMain->item(i, 0)->data(Qt::EditRole).toInt()));
    }
}

void DlgHouseItem::on_btnRemoveItem_clicked()
{
    int row = ui->tblMain->currentRow();
    ui->tblMain->removeRow(row);
}
