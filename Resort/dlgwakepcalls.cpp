#include "dlgwakepcalls.h"
#include "ui_dlgwakepcalls.h"
#include "cacheactiveroom.h"
#include "message.h"
#include <QMenu>

DlgWakepCalls::DlgWakepCalls(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgWakepCalls)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tbl, ui->tbl->columnCount(), 0, 120, 100, 80);
}

DlgWakepCalls::~DlgWakepCalls()
{
    delete ui;
}

void DlgWakepCalls::openWakeupCalls(const QString &room)
{
    DlgWakepCalls *dw = new DlgWakepCalls(__preferences.getDefaultParentForMessage());
    CacheActiveRoom ar;
    if (ar.get(room)) {
        dw->ui->leInvoice->setText(ar.fInvoice());
        dw->ui->leRoom->setText(ar.fRoomCode());
        dw->ui->leGuest->setText(ar.fGuestName());
        dw->load();
    }
    dw->exec();
    delete dw;
}

void DlgWakepCalls::openWakeupCallsByInvoice(const QString &invoice)
{
    DlgWakepCalls *dw = new DlgWakepCalls(__preferences.getDefaultParentForMessage());
    DoubleDatabase db;
    db[":f_invoice"] = invoice;
    db.exec("select g.guest, r.f_room from f_reservation r "
            "left join guests g on g.f_id=r.f_guest "
            "where r.f_invoice=:f_invoice ");
    if (!db.nextRow()) {
        return;
    }
    dw->ui->leInvoice->setText(invoice);
    dw->ui->leRoom->setText(db.getString(1));
    dw->ui->leGuest->setText(db.getString(0));
    dw->load();
    dw->exec();
    delete dw;
}

void DlgWakepCalls::on_btnAddWakeup_clicked()
{
    int row = ui->tbl->addRow();
    DoubleDatabase db;
    db[":f_invoice"] = ui->leInvoice->text();
    db[":f_date"] = ui->deDate->date();
    db[":f_time"] = ui->teTime->time();
    db[":f_repeat"] = ui->chEveryDay->isChecked();
    ui->tbl->setValue(row, 0, db.insert("f_wakeupcalls"));
    ui->tbl->setValue(row, 1, ui->deDate->text());
    ui->tbl->setValue(row, 2, ui->teTime->text());
    ui->tbl->setValue(row, 3, (int) ui->chEveryDay->isChecked());
}

void DlgWakepCalls::load()
{
    ui->tbl->clearContents();
    ui->tbl->setRowCount(0);
    DoubleDatabase db;
    db[":f_invoice"] = ui->leInvoice->text();
    db.exec("select f_id, f_date, f_time, f_repeat from f_wakeupcalls where f_invoice=:f_invoice");
    while (db.nextRow()) {
        int row = ui->tbl->addRow();
        ui->tbl->setValue(row, 0, db.getInt(0));
        ui->tbl->setValue(row, 1, db.getDate(1).toString(def_date_format));
        ui->tbl->setValue(row, 2, db.getTime(2));
        ui->tbl->setValue(row, 3, db.getInt(3));
    }
}

void DlgWakepCalls::on_tbl_customContextMenuRequested(const QPoint &pos)
{
    if (ui->tbl->currentRow() < 0) {
        return;
    }
    QMenu *menu = new QMenu(this);
    menu->addAction(QIcon(":/cancel.png"), tr("Remove"), this, SLOT(removeWakeup()));
    menu->popup(ui->tbl->mapToGlobal(pos));
}

void DlgWakepCalls::removeWakeup()
{
    if (ui->tbl->currentRow() < 0) {
        return;
    }
    if (message_confirm(tr("Are you sure?")) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase db;
    db[":f_id"] = ui->tbl->itemValue(ui->tbl->currentRow(), 0);
    db.exec("DELETE from f_wakeupcalls where f_id=:f_id");
    ui->tbl->removeRow(ui->tbl->currentRow());
}
