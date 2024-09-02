#include "dlggroupreserveoption.h"
#include "ui_dlggroupreserveoption.h"
#include "cachegroupreservations.h"
#include "cacheguest.h"
#include "trackcontrol.h"
#include "message.h"

DlgGroupReserveOption::DlgGroupReserveOption(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgGroupReserveOption)
{
    ui->setupUi(this);
    ui->leGroupCode->setSelector(this, cache(cid_group_reservation), ui->leGroupName);
}

DlgGroupReserveOption::~DlgGroupReserveOption()
{
    delete ui;
}

void DlgGroupReserveOption::addRemove(const QString &id)
{
    DlgGroupReserveOption *d = new DlgGroupReserveOption(fPreferences.getDefaultParentForMessage());
    DoubleDatabase fDD;
    fDD[":f_id"] = id;
    fDD.exec("select * from f_reservation where f_id=:f_id");
    fDD.nextRow();
    d->ui->leReservation->setText(id);
    d->ui->leRoom->setText(fDD.getValue("f_room").toString());
    CacheGuest g;
    g.get(fDD.getValue("f_guest").toString());
    d->ui->leGuest->setText(g.fName());
    d->ui->leGroupCode->setInitialValue(fDD.getValue("f_group").toString());
    d->exec();
    delete d;
}


void DlgGroupReserveOption::on_btnAddToGroup_clicked()
{
    DoubleDatabase fDD;
    fDD[":f_group"] = ui->leGroupCode->asInt();
    fDD.update("f_reservation", where_id(ap(ui->leReservation->text())));
    TrackControl::insert(TRACK_RESERVATION_GROUP, "Merging with group", ui->leGroupCode->text() + "/" + ui->leGroupName->text(), "", "-", "-", ui->leReservation->text());
    TrackControl::insert(TRACK_RESERVATION, "Merging with group", ui->leGroupCode->text() + "/" + ui->leGroupName->text(), "", "-", "-", ui->leReservation->text());
    accept();
}

void DlgGroupReserveOption::on_bgtnRemoveFromGroup_clicked()
{
    if (message_confirm(tr("Confirm removing from group")) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_group"] = 0;
    fDD.update("f_reservation", where_id(ap(ui->leReservation->text())));
    TrackControl::insert(TRACK_RESERVATION_GROUP, "Removed from group", ui->leGroupCode->text() + "/" + ui->leGroupName->text(), "", "-", "-", ui->leReservation->text());
    TrackControl::insert(TRACK_RESERVATION, "Removed from group", ui->leGroupCode->text() + "/" + ui->leGroupName->text(), "", "-", "-", ui->leReservation->text());
    accept();
}
