#include "wquickreservationspax.h"
#include "ui_wquickreservationspax.h"

WQuickReservationsPax::WQuickReservationsPax(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::WQuickReservationsPax)
{
    ui->setupUi(this);
    fTrack = new TrackControl(TRACK_RESERVATION);
    fTrack->addWidget(ui->sbMan, "Man")
            .addWidget(ui->sbWoman, "Woman")
            .addWidget(ui->sbChild, "Child")
            .addWidget(ui->sbBaby, "Baby");
}

WQuickReservationsPax::~WQuickReservationsPax()
{
    if (!fCode.isEmpty()) {
        DoubleDatabase dd;
        dd[":f_man"] = ui->sbMan->value();
        dd[":f_woman"] = ui->sbWoman->value();
        dd[":f_child"] = ui->sbChild->value();
        dd[":f_baby"] = ui->sbBaby->value();
        dd.update("f_reservation", where_id(ap(fCode)));
        fTrack->saveChanges();
    }
    delete fTrack;
    delete ui;
}

void WQuickReservationsPax::setReservationCode(const QString &code)
{
    if (code.isEmpty()) {
        return;
    }
    fCode = code;
    DoubleDatabase dd;
    dd[":f_id"] = code;
    dd.exec("select f_room, f_invoice, f_man, f_woman, f_child, f_baby from f_reservation where f_id=:f_id");
    if (dd.nextRow()) {
        ui->lbRoom->setText(QString("ROOM #%1").arg(dd.getInt("f_room")));
        fTrack->fReservation = code;
        fTrack->fInvoice = dd.getString("f_invoice");
        ui->sbMan->setValue(dd.getInt("f_man"));
        ui->sbWoman->setValue(dd.getInt("f_woman"));
        ui->sbChild->setValue(dd.getInt("f_child"));
        ui->sbBaby->setValue(dd.getInt("f_baby"));
        fTrack->resetChanges();
    }
}

void WQuickReservationsPax::getValues(int &man, int &woman, int &child, int &baby)
{
    man = ui->sbMan->value();
    woman = ui->sbWoman->value();
    child = ui->sbChild->value();
    baby = ui->sbBaby->value();
}

int WQuickReservationsPax::pax()
{
    return ui->sbMan->value() + ui->sbWoman->value() + ui->sbChild->value();
}
