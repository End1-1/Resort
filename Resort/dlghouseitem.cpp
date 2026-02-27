#include "dlghouseitem.h"
#include "ui_dlghouseitem.h"
#include "cacheroominventorystate.h"
#include "cacheroominventory.h"
#include "cacheroomstate.h"
#include "cacheroom.h"
#include "cachereservation.h"
#include "dlghouseitemonoffwidget.h"
#include <QMutex>
#include <QClipboard>

#define SEL_ROOM_IN 1

static QMutex fMutex;

DlgHouseItem::DlgHouseItem(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgHouseItem)
{
    ui->setupUi(this);
    ui->leRoomCode->setSelector(this, cache(cid_room), ui->leRoomName, SEL_ROOM_IN);
    Utils::tableSetColumnWidths(ui->tblMain, ui->tblMain->columnCount(),
                                0, 300, 150, 120, 300);

    fleInventory = 0;
    ui->btnAddItem->setVisible(r__(cr__edit_room_inventory_list));
    ui->btnRemoveItem->setVisible(r__(cr__edit_room_inventory_list));
    ui->btnCopy->setVisible(r__(cr__edit_room_inventory_list));
    ui->btnPaste->setVisible(r__(cr__edit_room_inventory_list));
    ui->btnSave->setVisible(r__(cr__edit_room_inventory_list));

    if (WORKING_USERGROUP != 1) {
        ui->btnAddItem->setVisible(r__(cr__edit_room_inventory_list) && !r__(cr__view_room_inventory_state));
        ui->btnRemoveItem->setVisible(r__(cr__edit_room_inventory_list) && !r__(cr__view_room_inventory_state));
        ui->btnCopy->setVisible(r__(cr__edit_room_inventory_list) && !r__(cr__view_room_inventory_state));
        ui->btnPaste->setVisible(r__(cr__edit_room_inventory_list) && !r__(cr__view_room_inventory_state));
        ui->btnSave->setVisible(r__(cr__edit_room_inventory_list) && !r__(cr__view_room_inventory_state));
        ui->btnSaveStates->setVisible(!r__(cr__view_room_inventory_state));
    }

    if (fPreferences.getDb(def_touchscreen).toBool()) {
        ui->tblMain->verticalHeader()->setDefaultSectionSize(40);
        QFont f(qApp->font());
        f.setPointSize(f.pointSize() + 4);
        setFont(f);
        QSize s(60, 60);
        ui->btnAddItem->setMinimumSize(s);
        ui->btnCopy->setMinimumSize(s);
        ui->btnDontDisturbe->setMinimumSize(s);
        ui->btnPaste->setMinimumSize(s);
        ui->btnRemoveItem->setMinimumSize(s);
        ui->btnSave->setMinimumSize(s);
        ui->btnSaveStates->setMinimumSize(s);
        ui->tblMain->verticalHeader()->setDefaultSectionSize(50);
        ui->tblMain->horizontalHeader()->setFixedHeight(40);
    }
}

DlgHouseItem::~DlgHouseItem()
{
    delete ui;
}

void DlgHouseItem::setRoom(int room)
{
    ui->leRoomCode->setInitialValue(room);
}

void DlgHouseItem::callback(int sel, const QString &code)
{
    Q_UNUSED(code);
    switch (sel) {
    case SEL_ROOM_IN: {
        QMutexLocker ml(&fMutex);
        loadRoom();
        break;
    }
    }
}


void DlgHouseItem::openWindow(int room)
{
    DlgHouseItem *d = new DlgHouseItem(fPreferences.getDefaultParentForMessage());
    if (room > 0) {
        d->setRoom(room);
    }
    d->exec();
    delete d;
}

void DlgHouseItem::onOffClicked()
{
    bool ok = true;
    for (int i = 0; i < ui->tblMain->rowCount(); i++) {
        ok = ok && static_cast<DlgHouseItemOnOffWidget*>(ui->tblMain->cellWidget(i, 2))->isChecked();
        if (!ok) {
            break;
        }
    }
    if (ok) {
        ui->lbStatus->setPixmap(QPixmap(":/images/ball-green.png"));
    } else {
        ui->lbStatus->setPixmap(QPixmap(":/images/ball-red.png"));
    }
}

void DlgHouseItem::comboStateCurrentIndexChanged(int index)
{
    Q_UNUSED(index)
    bool ok = true;
    for (int i = 0; i < ui->tblMain->rowCount(); i++) {
        ok = ok && ui->tblMain->comboBox(i, 2)->currentData().toInt() == 1;
        if (!ok) {
            break;
        }
    }
    if (ok) {
        ui->lbStatus->setPixmap(QPixmap(":/images/ball-green.png"));
    } else {
        ui->lbStatus->setPixmap(QPixmap(":/images/ball-red.png"));
    }
}

void DlgHouseItem::loadRoom()
{
    if (ui->leRoomCode->asInt() == 0) {
        return;
    }
    ui->tblMain->clearContents();
    ui->tblMain->setRowCount(0);
    QList<int> inventories;
    DoubleDatabase db;
    db[":f_group"] = WORKING_USERGROUP;
    db.exec("select f_inventory from f_room_inventory_permission where f_group=:f_group and f_permit=1");
    while (db.nextRow()) {
        inventories.append(db.getInt(0));
    }
    db[":f_room"] = ui->leRoomCode->asInt();
    db.exec("select * from f_room_inventory_journal where f_room=:f_room");
    while (db.nextRow()) {
        if (WORKING_USERGROUP != 1) {
            if (r__(cr__view_room_inventory_state)) {
                continue;
            }
            if (!r__(cr__edit_room_inventory_list)) {
                if (!inventories.contains(db.getInt("f_inventory"))) {
                    continue;
                }
            }
        }
        int row = addRow();
        ui->tblMain->setItemWithValue(row, 0, db.getValue("f_id"));
        //ui->tblMain->lineEdit(row, 1)->fHiddenText = fDD.getValue("f_inventory").toString();
        ui->tblMain->lineEdit(row, 1)->setInitialValue(db.getValue("f_inventory").toString());
        if (!r__(cr__edit_room_inventory_list)) {
            ui->tblMain->lineEdit(row, 1)->clearSelector();
            ui->tblMain->lineEdit(row, 1)->setHiddenTextEnabled(false);
        }
        if (fPreferences.getDb(def_touchscreen).toBool()) {
            static_cast<DlgHouseItemOnOffWidget*>(ui->tblMain->cellWidget(row, 2))->setChecked(db.getValue("f_state").toInt() == 1);
        } else {
            ui->tblMain->comboBox(row, 2)->setIndexForData(db.getValue("f_state").toInt());
        }
        ui->tblMain->dateEdit(row, 3)->setDate(db.getValue("f_date").toDate());
        ui->tblMain->lineEdit(row, 4)->setText(db.getValue("f_comment").toString());
    }
    if (fPreferences.getDb(def_touchscreen).toBool()) {
        onOffClicked();
    } else {
        comboStateCurrentIndexChanged(0);
    }
    CacheRoom cr;
    if (!cr.get(ui->leRoomCode->asInt())) {
        return;
    }
    ui->btnDontDisturbe->setChecked(cr.fDoNotDisturbe());
}

int DlgHouseItem::addRow()
{
    int row = ui->tblMain->rowCount();
    ui->tblMain->setRowCount(row + 1);
    ui->tblMain->setItemWithValue(row, 0, 0);
    EQLineEdit *l = ui->tblMain->addLineEdit(row, 1, false);
    l->setSelector(this, cache(cid_room_inventory), l);
    if (fPreferences.getDb(def_touchscreen).toBool()) {
        auto *w = new DlgHouseItemOnOffWidget();
        connect(w, &DlgHouseItemOnOffWidget::clicked, this, &DlgHouseItem::onOffClicked);
        ui->tblMain->setCellWidget(row, 2, w);
    } else {
        EQComboBox *c = ui->tblMain->addComboBox(row, 2);
        c->setCache(cid_room_inventory_state);
        connect(c, SIGNAL(currentIndexChanged(int)), this, SLOT(comboStateCurrentIndexChanged(int)));
    }
    ui->tblMain->addDateEdit(row, 3, false);
    ui->tblMain->addLineEdit(row, 4, false);
    return row;
}

void DlgHouseItem::checkForReady()
{
    CacheRoomState rs;
    DoubleDatabase db;
    db[":f_room"] = ui->leRoomCode->asInt();
    db.exec("select * from f_room_inventory_journal where f_room=:f_room and f_state <> 1");
    if (db.nextRow()) {
        db[":f_id"] = ui->leRoomCode->asInt();
        db.exec("select f_state from f_room where f_id=:f_id");
        int oldstate = -1;
        if (db.nextRow()) {
            oldstate = db.getInt(0);
        }
        if (oldstate == ROOM_STATE_NONE) {
            db[":f_date"] = QDate::currentDate();
            db[":f_wdate"] = WORKING_DATE;
            db[":f_time"] = QTime::currentTime();
            db[":f_oldState"] = oldstate;
            db[":f_newState"] = ROOM_STATE_DIRTY;
            db[":f_user"] = WORKING_USERID;
            db[":f_comment"] = "";
            db.insert("f_room_state_change");
            db[":f_id"] = ui->leRoomCode->asInt();
            db[":f_state"] = ROOM_STATE_DIRTY;
            db.exec("update f_room set f_state=:f_state where f_id=:f_id");
            QString statename = QString::number(oldstate);
            if (rs.get(oldstate)) {
                statename = rs.fName();
            }
            TrackControl::insert(TRACK_ROOM_STATE, "Room state changed", statename, "VACANT NOT READY, Reason: not clear");
            BroadcastThread::cmdRefreshCache(cid_room, ui->leRoomCode->text());
        }
    } else {
        db[":f_id"] = ui->leRoomCode->asInt();
        db.exec("select f_state from f_room where f_id=:f_id");
        int oldstate = -1;
        if (db.nextRow()) {
            oldstate = db.getInt(0);
        }
        db[":f_date"] = QDate::currentDate();
        db[":f_wdate"] = WORKING_DATE;
        db[":f_time"] = QTime::currentTime();
        db[":f_oldState"] = oldstate;
        db[":f_newState"] = ROOM_STATE_NONE;
        db[":f_user"] = WORKING_USERID;
        db[":f_comment"] = "";
        db.insert("f_room_state_change");
        db[":f_id"] = ui->leRoomCode->asInt();
        db[":f_state"] = 0;
        db.exec("update f_room set f_state=:f_state where f_id=:f_id");
        QString statename = QString::number(oldstate);
        if (rs.get(oldstate)) {
            statename = rs.fName();
        }
        TrackControl::insert(TRACK_ROOM_STATE, "Room state changed", statename, "VACANT READY, Reason: all clear");
        BroadcastThread::cmdRefreshCache(cid_room, ui->leRoomCode->text());
    }
}

void DlgHouseItem::on_btnAddItem_clicked()
{
    addRow();
}

void DlgHouseItem::on_btnSave_clicked()
{
    if (r__(cr__edit_room_inventory_list)) {
        for (int i = 0; i < ui->tblMain->rowCount(); i++) {
            if (ui->tblMain->lineEdit(i, 1)->fHiddenText.toInt() == 0) {
                message_error(tr("Incomplete document"));
                return;
            }
        }
    }
    DoubleDatabase fDD;
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
    checkForReady();
    message_info(tr("Saved"));
}

void DlgHouseItem::on_btnRemoveItem_clicked()
{
    int row = ui->tblMain->currentRow();
    QTableWidgetItem *item = ui->tblMain->item(row, 0);
    if (item && item->data(Qt::EditRole).toInt() > 0) {
        DoubleDatabase fDD;
        fDD[":f_id"] = ui->tblMain->item(row, 0)->data(Qt::EditRole);
        fDD.exec("delete from f_room_inventory_journal where f_id=:f_id");
    }
    ui->tblMain->removeRow(row);
}

void DlgHouseItem::on_btnSaveStates_clicked()
{
    DoubleDatabase fDD;
    for (int i = 0; i < ui->tblMain->rowCount(); i++) {
        if (fPreferences.getDb(def_touchscreen).toBool()) {
            fDD[":f_state"] = static_cast<DlgHouseItemOnOffWidget*>(ui->tblMain->cellWidget(i, 2))->isChecked() ? 1 : 0;
        } else {
            fDD[":f_state"] = ui->tblMain->comboBox(i, 2)->currentData();
        }
        fDD[":f_date"] = ui->tblMain->dateEdit(i, 3)->date();
        fDD[":f_comment"] = ui->tblMain->lineEdit(i, 4)->text();
        fDD.update("f_room_inventory_journal", where_id(ui->tblMain->item(i, 0)->data(Qt::EditRole).toInt()));
    }
    checkForReady();
    message_info(tr("Saved"));
}

void DlgHouseItem::on_btnCopy_clicked()
{
    QString c("DLGHOUSE:;");
    for (int i = 0; i < ui->tblMain->rowCount(); i++) {
        c += QString("%1,%2;").arg(ui->tblMain->lineEdit(i, 1)->fHiddenText).arg(ui->tblMain->comboBox(i, 2)->currentData().toInt());
    }
    qApp->clipboard()->setText(c);
}

void DlgHouseItem::on_btnPaste_clicked()
{
    QString c = qApp->clipboard()->text();
    QStringList s = c.split(";", Qt::SkipEmptyParts);
    if (s.count() == 0) {
        return;
    }
    if (s.at(0) != "DLGHOUSE:") {
        return;
    }
    for (int i = 1; i < s.count(); i++) {
        QStringList p = s.at(i).split(",", Qt::SkipEmptyParts);
        if (p.count() != 2) {
            continue;
        }
        int row = addRow();
        ui->tblMain->lineEdit(row, 1)->setInitialValue(p.at(0));
        ui->tblMain->comboBox(row, 2)->setIndexForData(p.at(1).toInt());
    }
}

void DlgHouseItem::on_btnDontDisturbe_clicked(bool checked)
{
    if (message_confirm(tr("Change the room state?")) != RESULT_YES) {
        ui->btnDontDisturbe->setChecked(!checked);
        return;
    }
    DoubleDatabase dd;
    dd[":f_donotdisturbe"] = (int) checked;
    dd[":f_id"] = ui->leRoomCode->asInt();
    dd.exec("update f_room set f_donotdisturbe=:f_donotdisturbe where f_id=:f_id");
    BroadcastThread::cmdRefreshCache(cid_room, ui->leRoomCode->text());
    dd[":f_room"] = ui->leRoomCode->asInt();
    dd[":f_state"] = RESERVE_CHECKIN;
    dd.exec("select f_id from f_reservation where f_state=:f_state and f_room=:f_room");
    if (dd.nextRow()) {
        BroadcastThread::cmdRefreshCache(cid_reservation, dd.getString(0));
    }
}
