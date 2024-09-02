#include "fcitytrayledger.h"
#include "ui_fcitytrayledger.h"
#include "wreportgrid.h"
#include "winvoice.h"
#include "waccinvoice.h"

FCityTrayLedger::FCityTrayLedger(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FCityTrayLedger)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Guest Tray Ledger"), ":/images/calculator.png");
    connect(fReportGrid, &WReportGrid::doubleClickOnRow, [](const QList<QVariant> &val) {
        if (val.count() == 0) {
            return;
        }
        QString invoice = val.at(2).toString();
        DoubleDatabase dd;
        dd[":f_invoice"] = invoice;
        dd.exec("select f_state from f_reservation where f_invoice=:f_invoice");
        if (dd.nextRow()) {
            switch (dd.getInt(0)) {
            case RESERVE_CHECKIN:
                WInvoice::openInvoiceWindow(invoice);
                break;
            case RESERVE_CHECKOUT:
                WAccInvoice::openInvoice(invoice);
                break;
            default:
                message_error(tr("This is not valid invoice"));
                break;
            }
        }

    });
}

FCityTrayLedger::~FCityTrayLedger()
{
    delete ui;
}

QString FCityTrayLedger::reportTitle()
{
    return QString("%1 %2").arg(tr("Guest Tray Ledger (inhouse)")).arg(WORKING_DATE.toString(def_date_format));
}

QWidget *FCityTrayLedger::firstElement()
{
    return this;
}

QWidget *FCityTrayLedger::lastElement()
{
    return this;
}

void FCityTrayLedger::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(50, "", tr("Room"))
            .setColumn(220, "", tr("Guest"))
            .setColumn(80, "", tr("Invoice"))
            .setColumn(30, "", tr("Pax"))
            .setColumn(40, "", tr("Cat"))
            .setColumn(30, "", tr("Arr"))
            .setColumn(80, "", tr("Rate"))
            .setColumn(110, "", tr("Arrival"))
            .setColumn(110, "", tr("Departure"))
            .setColumn(70, "", tr("Time"))
            .setColumn(100, "", tr("Balance, AMD"))
            .setColumn(100, "", tr("Balance, USD"))
            .setColumn(120, "", tr("Payment"))
            .setColumn(100, "", tr("Nationality"))
            .setColumn(200, "", tr("Source"));
    QString query = "select r.f_room, g.guest, r.f_invoice, r.f_man + r.f_woman + r.f_child as pax, left(rv.f_" + def_lang + ", 1), "
            "ra.f_" + def_lang + ", r.f_pricePerNight, r.f_startDate, r.f_endDate, r.f_checkouttime, "
            "sum(if(m.f_finance=1 and m.f_canceled=0, m.f_amountamd*m.f_sign, 0)), sum(if(m.f_finance=1 and m.f_canceled=0, m.f_amountamd/m.f_amountusd*m.f_sign, 0)), "
            "pm.f_" + def_lang + ", n.f_name, c.f_name "
            "from f_reservation r "
            "inner join m_register m on m.f_inv=r.f_invoice "
            "left join f_room rm on rm.f_id = r.f_room "
            "left join f_room_view rv on rv.f_id=rm.f_view "
            "left join f_room_arrangement ra on ra.f_id=r.f_arrangement "
            "left join f_payment_type pm on pm.f_id=r.f_paymentType "
            "left join guests g on g.f_id=r.f_guest "
            "left join f_guests gg on gg.f_id=r.f_guest "
            "left join f_nationality n on gg.f_nation=n.f_short "
            "left join f_cardex c on c.f_cardex=r.f_cardex "
            "where r.f_state=1 "
            "group by 1,2,3,4,5,6,7,8,9,10 "
            "order by rm.f_building, r.f_room, r.f_startDate ";
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
    QList<int> col;
    col << 3 << 6 << 10 << 11;
    QList<double> val;
    rg->fModel->sumOfColumns(col, val);
    col.insert(0, 1);
    val.insert(0, rg->fModel->rowCount());
    rg->setTblTotalData(col, val);
}
