#include "wquickreservationsguests.h"
#include "ui_wquickreservationsguests.h"
#include "message.h"
#include "cachenation.h"
#include "cacheguesttitle.h"
#include "wguest.h"

WQuickReservationsGuests::WQuickReservationsGuests(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::WQuickReservationsGuests)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tbl, ui->tbl->columnCount(), 70, 70, 200, 200, 50, 100);
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
    DoubleDatabase dd(true, doubleDatabase);
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        dd[":f_title"] = ui->tbl->lineEdit(i, 1)->text();
        dd[":f_firstname"] = ui->tbl->lineEdit(i, 2)->text();
        dd[":f_lastname"] = ui->tbl->lineEdit(i, 3)->text();
        dd[":f_nation"] = ui->tbl->lineEdit(i, 4)->text();
        if (ui->tbl->toInt(i, 0) == 0) {
            ui->tbl->setItemWithValue(i, 0, dd.insert("f_guests"));
            dd[":f_reservation"] = fReserve;
            dd[":f_guest"] = ui->tbl->toInt(i, 0);
            dd[":f_first"] = i == 0 ? 1 : 0;
            dd.insert("f_reservation_guests", false);
        } else {
            dd.update("f_guests", where_id(ui->tbl->toInt(i, 0)));
        }
    }
    BaseDialog::closeEvent(event);
}

void WQuickReservationsGuests::addRowTrack(int row)
{
    TrackControl *tc = new TrackControl(TRACK_RESERVATION);
    tc->fReservation = fReserve;
    tc->fInvoice = fInvoice;
    tc->addWidget(ui->tbl->lineEdit(row, 1), "Guest title");

}

void WQuickReservationsGuests::on_btnAddGuest_clicked()
{
    int row = ui->tbl->addRow();
    ui->tbl->setItemWithValue(row, 0, 0);
    auto *l = ui->tbl->addLineEdit(row, 1, false);
    l->setSelector(this, cache(cid_guest_title), nullptr);
    l->setInitialValue("");
    l = ui->tbl->addLineEdit(row, 2, false);
    l->setText("");
    l = ui->tbl->addLineEdit(row, 3, false);
    l->setText("");
    auto *l2 = ui->tbl->addLineEdit(row, 5, false);
    l= ui->tbl->addLineEdit(row, 4, false);
    l->setSelector(this, cache(cid_nation), l2, row);
    l->setInitialValue("-");
    addRowTrack(row);
}

void WQuickReservationsGuests::on_btnRemoveGuest_clicked()
{

}

void WQuickReservationsGuests::on_btnFullInfo_clicked()
{
    int row = ui->tbl->currentRow();
    if (row < 0) {
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_id"] = ui->tbl->toInt(row, 0);
    fDD.exec("select g.f_id, g.f_title, g.f_firstName, g.f_lastName, g.f_sex, s.f_" + def_lang + ", g.f_dateBirth, "
               "g.f_placeBirth, "
               "n.f_short, n.f_name as nationality, g.f_passport, g.f_address, g.f_tel1, g.f_tel2, "
               "g.f_email, g.f_postBox, g.f_remarks "
               "from f_guests g "
               "left join f_nationality n on g.f_nation=n.f_short "
               "left join f_guests_sex s on s.f_id=g.f_sex "
               "where g.f_id=:f_id ");
    if (fDD.rowCount() == 0) {
        message_error(tr("Cannot get guest info"));
        return;
    }
    QList<QVariant> v = fDD.fDbRows[0];
    WGuest *g = WGuest::guest(v);
    g->setValues();
    WGuest *w = WGuest::guest(v);
    w->exec();
    ui->tbl->lineEdit(row, 1)->setInitialValue(v.at(1).toString());
    ui->tbl->lineEdit(row, 2)->setText(v.at(2).toString());
    ui->tbl->lineEdit(row, 3)->setText(v.at(3).toString());
    ui->tbl->lineEdit(row, 4)->setInitialValue(v.at(8).toString());
}

void WQuickReservationsGuests::on_btnChangeGuest_clicked()
{
    int row = ui->tbl->currentRow();
    if (row < 0) {
        return;
    }
    ui->tbl->setItemWithValue(row, 0, 0);
    ui->tbl->lineEdit(row, 1)->setInitialValue("");
    ui->tbl->lineEdit(row, 2)->clear();
    ui->tbl->lineEdit(row, 2)->setPlaceholderText("First name");
    ui->tbl->lineEdit(row, 3)->clear();
    ui->tbl->lineEdit(row, 3)->setPlaceholderText("Last name");
    ui->tbl->lineEdit(row, 4)->setInitialValue("-");
    addRowTrack(row);
}
