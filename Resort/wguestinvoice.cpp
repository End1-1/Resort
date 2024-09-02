#include "wguestinvoice.h"
#include "ui_wguestinvoice.h"
#include "cacheactiveroom.h"
#include "dbmregister.h"
#include "vauchers.h"
#include "cacheredreservation.h"

static const int hint_room = 1;
static const int hint_reserve = 2;

WGuestInvoice::WGuestInvoice(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WGuestInvoice)
{
    ui->setupUi(this);
    ui->leRoom->setSelector(this, cache(cid_active_room), ui->leRoomName, hint_room);
    ui->leRoom->setStyleSheet("background:yellow;");
}

WGuestInvoice::~WGuestInvoice()
{
    delete ui;
}

void WGuestInvoice::callback(int sel, const QString &code)
{
    switch (sel) {
    case hint_room: {
        CacheActiveRoom c;
        if (c.get(code)) {
            initRoom(code.toInt());
            emit roomChanged();
        }
        break;
    }
    case hint_reserve: {
        ui->leRoom->clear();
        ui->leRoomName->clear();
        ui->leGuest->clear();
        ui->leBalance->clear();
        ui->leInvoice->clear();
        ui->leReserve->clear();
        ui->deEntry->clear();
        ui->deDeparture->clear();
        ui->leBalanceUSD->clear();
        DoubleDatabase dd;
        dd[":f_id"] = code;
        dd.exec("select r.f_id, r.f_invoice, r.f_room, r.f_startdate, r.f_enddate, g.guest as f_guest, rm.f_short "
                "from f_reservation r "
                "left join guests g on g.f_id=r.f_guest "
                "left join f_room rm on rm.f_id=r.f_room "
                "where r.f_id=:f_id");
        if (!dd.nextRow()) {
            return;
        }
        ui->leRoom->setReadOnly(true);
        ui->leReserve->clearSelector();
        ui->leRoom->setInt(dd.getInt("f_room"));
        ui->leRoomName->setText(dd.getString("f_short"));
        ui->leGuest->setText(dd.getString("f_guest"));
        ui->leInvoice->setText(dd.getString("f_invoice"));
        ui->leReserve->setText(dd.getString("f_id"));
        ui->deEntry->setDate(dd.getDate("f_startdate"));
        ui->deDeparture->setDate(dd.getDate("f_enddate"));
        ui->leReserve->setSelector(this, cache(cid_red_reservation), nullptr, hint_reserve);
        setBalance();
        break;
    }
    }
}

void WGuestInvoice::setReservationMode(const QString reserveId)
{
    ui->leRoom->clearSelector();
    ui->leRoom->setStyleSheet("");
    ui->leReserve->setSelector(this, cache(cid_red_reservation), nullptr, hint_reserve);
    ui->leReserve->setStyleSheet("background:yellow;");
    if (!reserveId.isEmpty()) {
        ui->leReserve->setInitialValue(reserveId);
    }
}

void WGuestInvoice::setInvoice(const QString &invoice)
{
    ui->leRoom->clearSelector();
    ui->leRoom->setReadOnly(true);
    DoubleDatabase dd;
    dd[":f_invoice"] = invoice;
    dd.exec("select r.f_id, r.f_invoice, r.f_startdate, r.f_enddate, g.guest as f_guest, rm.f_short, r.f_room "
            "from f_reservation r "
            "left join guests g on g.f_id=r.f_guest "
            "left join f_room rm on rm.f_id=r.f_room "
            "where r.f_invoice=:f_invoice");
    if (dd.nextRow()) {
        fillFields(dd);
    }
    setBalance();
}

void WGuestInvoice::initRoom(int room)
{
    ui->leRoom->clear();
    ui->leRoomName->clear();
    ui->leGuest->clear();
    ui->leBalance->clear();
    ui->leInvoice->clear();
    ui->leReserve->clear();
    ui->deEntry->clear();
    ui->deDeparture->clear();
    ui->leBalanceUSD->clear();
    DoubleDatabase dd;
    dd[":f_room"] = room;
    dd[":f_state"] = RESERVE_CHECKIN;
    dd.exec("select r.f_id, r.f_invoice, r.f_startdate, r.f_enddate, g.guest as f_guest, r.f_room, rm.f_short, "
            "r.f_vatMode "
            "from f_reservation r "
            "left join guests g on g.f_id=r.f_guest "
            "left join f_room rm on rm.f_id=r.f_room "
            "where r.f_state=:f_state and r.f_room=:f_room");
    if (!dd.nextRow()) {
        return;
    }
    ui->leRoom->setReadOnly(true);
    ui->leRoom->clearSelector();
    fillFields(dd);
    ui->leRoom->setSelector(this, cache(cid_active_room), ui->leRoomName, hint_room);
    setBalance();
}

void WGuestInvoice::setBalance()
{
    ui->leBalance->clear();
    ui->leBalanceUSD->clear();
    if (ui->leInvoice->isEmpty()) {
        return;
    }
    DoubleDatabase dd;
    dd[":f_inv"] = ui->leInvoice->text();
    dd.exec("select r.f_startdate, r.f_enddate, sum(m.f_amountamd*m.f_sign) as f_amountamd, sum(m.f_amountamd/m.f_amountusd*m.f_sign) as f_amountusd "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv "
            "where f_inv=:f_inv and f_canceled=0 and f_finance=1 "
            "group by 1, 2");
    if (dd.nextRow()) {
        ui->leBalance->setDouble(dd.getDouble("f_amountamd"));
        ui->leBalanceUSD->setDouble(dd.getDouble("f_amountusd"));
        ui->deEntry->setDate(dd.getDate("f_startdate"));
        ui->deDeparture->setDate(dd.getDate("f_enddate"));
    }
}

void WGuestInvoice::setRoom(int room)
{
    ui->leRoom->setInitialValue(room);
}

void WGuestInvoice::setRoomCategory(const QString &category)
{
    ui->leRoomName->setText(category);
}

void WGuestInvoice::setGuest(const QString &guest)
{
    ui->leGuest->setText(guest);
}

void WGuestInvoice::clear()
{
    initRoom(0);
}

void WGuestInvoice::clearSelector()
{
    ui->leRoom->clearSelector();
    ui->leReserve->clearSelector();
}

void WGuestInvoice::initSelector()
{
    ui->leRoom->setSelector(this, cache(cid_active_room), ui->leRoomName, hint_room);
}

int WGuestInvoice::room()
{
    return ui->leRoom->asInt();
}

int WGuestInvoice::vatMode()
{
    return fVATMode;
}

QString WGuestInvoice::guest() const
{
    return ui->leGuest->text();
}

QString WGuestInvoice::invoice() const
{
    return ui->leInvoice->text();
}

QString WGuestInvoice::reserve() const
{
    return ui->leReserve->text();
}

void WGuestInvoice::setDBMRegister(DBMRegister *r)
{
    r->setleRoom(ui->leRoom);
    r->setleGuest(ui->leGuest);
    r->setleInvoice(ui->leInvoice);
    r->setleReserve(ui->leReserve);
}

void WGuestInvoice::on_btnOpenInvoice_clicked()
{
    if (!ui->leInvoice->isEmpty()) {
        openInvoiceWithId(ui->leInvoice->text());
    }
}

void WGuestInvoice::fillFields(DoubleDatabase &dd)
{
    ui->leRoom->setInt(dd.getInt("f_room"));
    ui->leRoomName->setText(dd.getString("f_short"));
    ui->leGuest->setText(dd.getString("f_guest"));
    ui->leInvoice->setText(dd.getString("f_invoice"));
    ui->leReserve->setText(dd.getString("f_id"));
    ui->deEntry->setDate(dd.getDate("f_startdate"));
    ui->deDeparture->setDate(dd.getDate("f_enddate"));
    fVATMode = dd.getInt("f_vatmode");
}
