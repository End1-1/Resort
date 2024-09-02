#include "dlggrouprevive.h"
#include "ui_dlggrouprevive.h"
#include "wreservationroomtab.h"
#include "broadcastthread.h"
#include "cacheredreservation.h"
#include "cachereservation.h"
#include "trackcontrol.h"

DlgGroupRevive::DlgGroupRevive(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgGroupRevive)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tbl, ui->tbl->columnCount(), 30, 80, 80, 120, 120, 250, 300);
}

DlgGroupRevive::~DlgGroupRevive()
{
    delete ui;
}

void DlgGroupRevive::addRow(const QString &code, int room, const QDate &entry, const QDate &departure, const QString &guest)
{
    int row = ui->tbl->addRow();
    ui->tbl->addCheckBox(row, 0)->setChecked(true);
    ui->tbl->setItemWithValue(row, 1, code);
    ui->tbl->setItemWithValue(row, 2, room);
    ui->tbl->addDateEdit(row, 3, false)->setDate(entry);
    ui->tbl->addDateEdit(row, 4, false)->setDate(departure);
    ui->tbl->setItemWithValue(row, 5, guest);
    ui->tbl->dateEdit(row, 3)->setReadOnly(true);
    ui->tbl->dateEdit(row, 4)->setReadOnly(true);
    QString err;
    if (!WReservationRoomTab::check(room, entry, departure, code, err)) {
        ui->tbl->checkBox(row, 0)->setChecked(false);
        ui->tbl->checkBox(row, 0)->setEnabled(false);
        ui->tbl->setItemWithValue(row, 6, err);
    }
}
void DlgGroupRevive::on_btnCancel_clicked()
{
    reject();
}

void DlgGroupRevive::on_btnRevive_clicked()
{
    int cnt = 0;
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        if (!ui->tbl->checkBox(i, 0)->isChecked()) {
            continue;
        }
        QString err;
        if (!WReservationRoomTab::check(ui->tbl->itemValue(i, 2).toInt(),
                                        ui->tbl->dateEdit(i, 3)->date(),
                                        ui->tbl->dateEdit(i, 4)->date(),
                                        ui->tbl->itemValue(i, 1).toString(),
                                        err)) {
            ui->tbl->checkBox(i, 0)->setChecked(false);
            ui->tbl->checkBox(i, 0)->setEnabled(false);
            ui->tbl->setItemWithValue(i, 6, err);
        }
        cnt++;
        DoubleDatabase dd;
        dd[":f_state"] = RESERVE_RESERVE;
        dd.update("f_reservation", where_id(ap(ui->tbl->itemValue(i, 1).toString())));
        BroadcastThread::cmdRefreshCache(cid_reservation, ui->tbl->itemValue(i, 1).toString());
        BroadcastThread::cmdRefreshCache(cid_red_reservation, ui->tbl->itemValue(i, 1).toString());
        TrackControl tc(TRACK_RESERVATION);
        tc.fReservation = ui->tbl->itemValue(i, 1).toString();
        tc.insert("Revive in group", "", "");
    }
    if (cnt > 0) {
        message_info(tr("Done"));
        accept();
    } else {
        message_info(tr("Nothing to revive"));
    }
}

