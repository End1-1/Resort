#include "reroominventory.h"
#include "ui_reroominventory.h"
#include "wreportgrid.h"
#include "cacheroominventory.h"

RERoomInventory::RERoomInventory(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_ROOM_INVENTORY, parent),
    ui(new Ui::RERoomInventory)
{
    ui->setupUi(this);
    addWidget(ui->leCode, "Code");
    addWidget(ui->leName, "Name");
    fTable = "f_room_inventory";
    fCacheId = cid_room_inventory;
}

RERoomInventory::~RERoomInventory()
{
    delete ui;
}

void RERoomInventory::openRoomInventoryReport()
{
    QList<int> widths;
    widths << 100
           << 400;
    QStringList fields;
    fields << "f_id"
           << "f_name";
    QStringList titles;
    titles << tr("Code")
           << tr("Name");
    QString title = tr("Room inventory");
    QString icon = ":/images/configure.png";
    QString query = "select f_id, f_name from f_room_inventory";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RERoomInventory>(widths, fields, titles, title, icon, query);
}

void RERoomInventory::setValues()
{
    RowEditorDialog::setValues();
    ui->lst->clear();
    DoubleDatabase db;
    db[":f_inventory"] = ui->leCode->asInt();
    db.exec("select g.f_en, g.f_id, i.f_permit from users_groups g left join f_room_inventory_permission i on g.f_id=i.f_group and i.f_inventory=:f_inventory");
    while (db.nextRow()) {
        QListWidgetItem *i = new QListWidgetItem(ui->lst);
        i->setText(db.getString(0));
        i->setData(Qt::UserRole, db.getInt(1));
        i->setFlags(i->flags() | Qt::ItemIsUserCheckable);
        i->setCheckState(db.getInt(2) == 0 ? Qt::Unchecked : Qt::Checked);
        ui->lst->addItem(i);
    }
}

void RERoomInventory::save()
{
    if (RowEditorDialog::saveOnly()) {
        DoubleDatabase db;
        db[":f_inventory"] = ui->leCode->asInt();
        db.exec("delete from f_room_inventory_permission where f_inventory=:f_inventory");
        for (int i = 0; i < ui->lst->count(); i++) {
            db[":f_inventory"] = ui->leCode->asInt();
            db[":f_group"] = ui->lst->item(i)->data(Qt::UserRole).toInt();
            db[":f_permit"] = ui->lst->item(i)->checkState() == Qt::Checked ? 1 : 0;
            db.insert("f_room_inventory_permission", false);
        }
    }
    accept();
}

void RERoomInventory::on_btnCancel_clicked()
{
    reject();
}

void RERoomInventory::on_btnSave_clicked()
{
    save();
}
