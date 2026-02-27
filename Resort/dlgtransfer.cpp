#include "dlgtransfer.h"
#include "ui_dlgtransfer.h"
#include "cachebed.h"
#include "cacheactiveroom.h"
#include "vauchers.h"

static const int HINT_ROOM_TO = 1;
static const int HINT_ROOM_FROM = 2;

DlgTransfer::DlgTransfer(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgTransfer)
{
    ui->setupUi(this);
    ui->leInvoiceFrom->setVisible(false);
    ui->leInvoiceTo->setVisible(false);
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                0, 120, 200, 80);
    ui->leRoomCodeFrom->setSelector(this, cache(cid_active_room), ui->leRoomNameFrom, HINT_ROOM_FROM);
    ui->leRoomCodeTo->setSelector(this, cache(cid_active_room), ui->leRoomNameTo, HINT_ROOM_TO);
    fTrackControl = new TrackControl(TRACK_RESERVATION);
}

DlgTransfer::~DlgTransfer()
{
    delete ui;
}

void DlgTransfer::callback(int sel, const QString &code)
{
    switch (sel) {
    case HINT_ROOM_TO: {
        CacheActiveRoom c;
        if (c.get(code)) {
            ui->leGuestTo->setText(c.fGuestName());
            ui->leInvoiceTo->setText(c.fInvoice());
            ui->leRoomCodeTo->setText(c.fRoomCode());
            ui->leReserveTo->setText(c.fCode());
        }
        break;
    }
    case HINT_ROOM_FROM: {
        CacheActiveRoom c;
        if (c.get(code)) {
            ui->leGuestFrom->setText(c.fGuestName());
            ui->leInvoiceFrom->setText(c.fInvoice());
            ui->leRoomCodeFrom->setText(c.fRoomCode());
        }
    }
    }
}

void DlgTransfer::setRoomByCode(const QString &code)
{
    CacheActiveRoom r;
    if (!r.get(code)) {
        return;
    }
    ui->leRoomCodeFrom->setInitialValue(code);
    ui->leGuestFrom->setText(r.fGuestName());
    ui->leInvoiceFrom->setText(r.fInvoice());
    ui->leRoomCodeFrom->setText(r.fRoomCode());
    fTrackControl->resetChanges();
}

void DlgTransfer::addRow(QList<QVariant> row)
{
    Utils::tableAppendRowData(ui->tblData, row, Qt::DisplayRole);
    ui->btnOk->setEnabled(true);
}

void DlgTransfer::on_chGuest_clicked(bool checked)
{
    ui->chCompany->setChecked(!checked);
}

void DlgTransfer::on_chCompany_clicked(bool checked)
{
    ui->chGuest->setChecked(!checked);
}

void DlgTransfer::on_btnCancel_clicked()
{
    reject();
}

void DlgTransfer::on_btnOk_clicked()
{
    QString errors;
    if (ui->leRoomCodeTo->asInt() == 0) {
        errors += tr("Destination room is not defined") + "<br>";
    }
    if (!errors.isEmpty()) {
        message_error(errors);
        return;
    }
    DoubleDatabase fDD;
    fDD.startTransaction();
    fTrackControl->fReservation = ui->leReserveFrom->text();
    fTrackControl->fInvoice = ui->leInvoiceFrom->text();
    for (int i = 0, count = ui->tblData->rowCount(); i < count; i++) {
        fDD[":f_inv"] = ui->leInvoiceTo->text();
        fDD[":f_res"] = ui->leReserveTo->text();
        fDD[":f_guest"] = ui->leGuestTo->text();
        fDD.update("m_register", where_id(ap(ui->tblData->item(i, 0)->text())));
        fDD[":f_id"] = ui->tblData->item(i, 0)->text();
        fDD.exec("select * from m_register where f_id=:f_id");
        if (fDD.nextRow()) {
            if (fDD.getString("f_source") == VAUCHER_POINT_SALE_N) {
                fDD[":f_paymentModeComment"] = fDD.getString("f_room") + ", " + fDD.getString("f_guest");
                fDD[":f_roomComment"] = fDD.getString("f_room") + ", " + fDD.getString("f_guest");
                fDD[":f_reservation"] = ui->leReserveTo->text();
                fDD.update("o_header", where_id(ap(ui->tblData->item(i, 0)->text())));
            }
        }
        fTrackControl->insert("Move out from invoice", QString("%1 / %2 / %3 / %4")
                                  .arg(ui->leInvoiceTo->text())
                                  .arg(ui->tblData->item(i, 1)->text())
                                  .arg(ui->tblData->item(i, 2)->text())
                                  .arg(ui->tblData->item(i, 3)->text()), "");
    }
    fTrackControl->saveChanges();
    fTrackControl->resetChanges();
    fTrackControl->fReservation = ui->leReserveTo->text();
    fTrackControl->fInvoice = ui->leInvoiceTo->text();
    for (int i = 0, count = ui->tblData->rowCount(); i < count; i++) {
        fTrackControl->insert("Move into invoice", QString("%1 / %2 / %3 / %4")
                                  .arg(ui->leInvoiceFrom->text())
                                  .arg(ui->tblData->item(i, 1)->text())
                                  .arg(ui->tblData->item(i, 2)->text())
                                  .arg(ui->tblData->item(i, 3)->text()), "");
    }
    fTrackControl->saveChanges();
    fDD.commit();
    accept();
}
