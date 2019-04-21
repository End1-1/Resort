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
    connect(fReportGrid, &WReportGrid::doubleClickOnRow, [this](const QList<QVariant> &val) {
        if (val.count() == 0) {
            return;
        }
        QString invoice = val.at(0).toString();
        DoubleDatabase dd(true, false);
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
    return QString("%1 %2 %3").arg(tr("Guest Tray Ledger")).arg(ui->deDate->text()).arg(ui->teTime->text());
}

QWidget *FCityTrayLedger::firstElement()
{
    return ui->deDate;
}

QWidget *FCityTrayLedger::lastElement()
{
    return ui->deDate;
}

void FCityTrayLedger::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(100, "", tr("Invoice"))
            .setColumn(40, "", tr("Room"))
            .setColumn(220, "", tr("Guest"))
            .setColumn(30, "", tr("Pax"))
            .setColumn(40, "", tr("Cat"))
            .setColumn(30, "", tr("Arr"))
            .setColumn(80, "", tr("Rate"))
            .setColumn(120, "", tr("Arrival"))
            .setColumn(120, "", tr("Departure"))
            .setColumn(70, "", tr("Time"))
            .setColumn(100, "", tr("AC balance, AMD"))
            .setColumn(100, "", tr("AC balance, USD"))
            .setColumn(100, "", tr("OA balance, AMD"))
            .setColumn(100, "", tr("OA balance, USD"))
            .setColumn(120, "", tr("Payment"))
            .setColumn(100, "", tr("Nationality"))
            .setColumn(200, "", tr("Source"));
    QString query = "select r.f_invoice, r.f_room, g.guest, r.f_man + r.f_woman + r.f_child as pax, rv.f_" + def_lang + ", "
            "ra.f_" + def_lang + ", r.f_pricePerNight, r.f_startDate, r.f_endDate, r.f_checkouttime, oa.amd, oa.usd, oc.amd, oc.usd, "
            "pm.f_" + def_lang + ", n.f_name, c.f_name "
            "from f_reservation r "
            "left join f_room rm on rm.f_id = r.f_room "
            "left join f_room_view rv on rv.f_id=rm.f_view "
            "left join f_room_arrangement ra on ra.f_id=r.f_arrangement "
            "left join f_payment_type pm on pm.f_id=r.f_paymentType "
            "left join guests g on g.f_id=r.f_guest "
            "left join f_guests gg on gg.f_id=r.f_guest "
            "left join f_nationality n on gg.f_nation=n.f_short "
            "left join f_cardex c on c.f_cardex=r.f_cardex "
            "left join (select f_inv, sum(f_amountAmd*f_sign) as amd, sum((f_amountAmd*f_sign)/f_amountUsd) as usd "
                "from m_register where f_finance=1 and f_canceled=0 and f_wdate<=':date' and f_side=1 group by 1) oa on oa.f_inv=r.f_invoice "
            "left join (select f_inv, sum(f_amountAmd*f_sign) as amd, sum((f_amountAmd*f_sign)/f_amountUsd) as usd "
                 "from m_register where f_finance=1 and f_canceled=0 and f_wdate<=':date' and f_side=0 group by 1) oc on oc.f_inv=r.f_invoice "
            "where r.f_state=1 "
            "order by rm.f_building, r.f_room, r.f_startDate ";
    query.replace(":date", ui->deDate->dateMySql(false));
    query.replace(":time", ui->teTime->time().toString(def_time_format));
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
    QList<int> col;
    col << 3 << 6 << 10 << 11 << 12 << 13;
    QList<double> val;
    rg->fModel->sumOfColumns(col, val);
    col.insert(0, 1);
    val.insert(0, rg->fModel->rowCount());
    rg->setTblTotalData(col, val);
}
