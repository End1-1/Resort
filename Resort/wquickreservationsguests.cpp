#include "wquickreservationsguests.h"
#include "ui_wquickreservationsguests.h"
#include "message.h"
#include "cachenation.h"
#include "cacheguesttitle.h"

WQuickReservationsGuests::WQuickReservationsGuests(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::WQuickReservationsGuests)
{
    ui->setupUi(this);
}

WQuickReservationsGuests::~WQuickReservationsGuests()
{
    delete ui;
}

void WQuickReservationsGuests::setRoom(const QString &reserve)
{
    fReserve = reserve;
    DoubleDatabase dd(true, false);
    dd[":f_id"] = fReserve;
    dd.exec("select f_room, f_invoice from f_reservation where f_id=:f_id");
    if (dd.nextRow()) {
        ui->lbRoom->setText(QString("ROOM #%1").arg(dd.getInt(0)));
        fInvoice = dd.getString(1);
    } else {
        message_error(tr("Invalid reservation code"));
        return;
    }
    dd[":f_reservation"] = fReserve;
    dd.exec("select r.f_guest, g.f_title, g.f_firstname, g.f_lastname, g.f_nation, n.f_name "
            "from f_reservation_guests r "
            "left join f_guests g on g.f_id=r.f_guest "
            "left join f_nationality n on n.f_short=g.f_nation "
            "where r.f_reservation=:f_reservation "
            "order by r.f_first desc ");
    ui->tbl->setRowCount(dd.rowCount());
    int row = 0;
    while (dd.nextRow()) {
        ui->tbl->setItemWithValue(row, 0, dd.getInt(0));
        auto *l = ui->tbl->addLineEdit(row, 1, false);
        l->setSelector(this, cache(cid_guest_title), nullptr);
        l->setInitialValue(dd.getString("f_title"));
        l = ui->tbl->addLineEdit(row, 2, false);
        l->setText(dd.getString("f_firstname"));
        l = ui->tbl->addLineEdit(row, 3, false);
        l->setText(dd.getString("f_lastname"));
        auto *l2 = ui->tbl->addLineEdit(row, 5, false);
        l= ui->tbl->addLineEdit(row, 4, false);
        l->setSelector(this, cache(cid_nation), l2, row);
        l->setInitialValue(dd.getString("f_nation"));
        addRowTrack(row);
        row++;
    }
}

void WQuickReservationsGuests::closeEvent(QCloseEvent *event)
{
    //event->ignore();
    return;
}

void WQuickReservationsGuests::addRowTrack(int row)
{
    TrackControl *tc = new TrackControl(TRACK_RESERVATION);
    tc->fReservation = fReserve;
    tc->fInvoice = fInvoice;
    tc->addWidget(ui->tbl->lineEdit(row, 1), "Guest title");

}
