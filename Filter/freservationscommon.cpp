#include "freservationscommon.h"
#include "ui_freservationscommon.h"
#include "wreportgrid.h"
#include "vauchers.h"
#include "cachereservestate.h"
#include "cachecardex.h"
#include "cachereservestatus.h"
#include "cachereservegroup.h"
#include "cacheroom.h"
#include "cacheroomarrangment.h"

FReservationsCommon::FReservationsCommon(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FReservationsCommon)
{
    ui->setupUi(this);
    fReportGrid->addToolBarButton(":/images/invoice.png", tr("Open invoice"), SLOT(openInvoice()), this)->setFocusPolicy(Qt::NoFocus);
    ui->deStart->setDate(WORKING_DATE);
    ui->deEnd->setDate(WORKING_DATE.addDays(90));
    ui->leStatus->setSelector(this, cache(cid_reserve_status), ui->leStatus);
    ui->leState->setSelector(this, cache(cid_reserve_state), ui->leState);
    ui->leState->setInitialValue(RESERVE_RESERVE);
    ui->leRoom->setSelector(this, cache(cid_room), ui->leRoom);
    ui->leArrangement->setSelector(this, cache(cid_room_arrangment), ui->leArrangement);
    ui->leCardex->setSelector(this, cache(cid_cardex), ui->leCardex);
    ui->leGroupNum->setSelector(this, cache(cid_reserve_group), ui->leGroupNum);
}

FReservationsCommon::~FReservationsCommon()
{
    delete ui;
}

void FReservationsCommon::apply(WReportGrid *rg)
{
    QString where = "where ";
    if (ui->rbArrival->isChecked()) {
        where += "r.f_startdate between " + ui->deStart->dateMySql() + " and " + ui->deEnd->dateMySql() + " ";
    } else if (ui->rbCreated->isChecked()) {
        where += "r.f_created between " + ui->deStart->dateMySql() + " and " + ui->deEnd->dateMySql() + " ";
    } else {
        where += "r.f_endDate between " + ui->deStart->dateMySql() + " and " + ui->deEnd->dateMySql() + " ";
    }
    if (!ui->leState->text().isEmpty()) {
        where += " and r.f_state in (" + ui->leState->fHiddenText + ") ";
    }
    if (!ui->leStatus->text().isEmpty()) {
        where += " and r.f_reserveState in (" + ui->leStatus->fHiddenText + ") ";
    }
    if (!ui->leArrangement->text().isEmpty()) {
        where += " and r.f_arrangement in (" + ui->leArrangement->fHiddenText + ") ";
    }
    if (!ui->leRoom->text().isEmpty()) {
        where += " and r.f_room in (" + ui->leRoom->fHiddenText + ") ";
    }
    if (!ui->leCardex->text().isEmpty()) {
        where += " and r.f_cardex in (" + Utils::separateForQuote(ui->leCardex->fHiddenText) + ") ";
    }
    if (!ui->leGroupNum->fHiddenText.isEmpty()) {
        where += " and r.f_group in (" + ui->leGroupNum->fHiddenText + ") ";
    }
    if (ui->chOnlyWithCardex->isChecked()) {
        where += " and (r.f_cardex <> '' and r.f_cardex <>'" + fPreferences.getDb(def_default_cardex).toString() + "') ";
    }
    if (!ui->leBooking->isEmpty()) {
        where += " and r.f_booking like '%" + ui->leBooking->text() + "%' ";
    }
    if (ui->chOnlyGroup->isChecked()) {
        where += " and r.f_group>0 ";
    }
    if (ui->chExtraBed->isChecked()) {
        where += " and r.f_extrabed=1 ";
    }
    where += " order by r.f_startDate ";
    buildQuery(rg, where);
    QList<int> cols;
    cols << 12 << 13 << 18;
    QList<double> vals;
    fReportGrid->fModel->sumOfColumns(cols, vals);
    fReportGrid->setTblTotalData(cols, vals);
    if (fReportGrid->fTableTotal->toInt(0, 13) > 0) {
        fReportGrid->fTableTotal->setItemWithValue(0, 14,
            fReportGrid->fTableTotal->toDouble(0, 18) / fReportGrid->fTableTotal->toInt(0, 13));
    }
}

QWidget *FReservationsCommon::firstElement()
{
    return ui->deStart;
}

QWidget *FReservationsCommon::lastElement()
{
    return ui->deEnd;
}

QString FReservationsCommon::reportTitle()
{
    return QString("%1 %2 From: %3 To %4, State: %5")
            .arg(tr("Reservations"))
            .arg(ui->rbArrival->isChecked() ? ui->rbArrival->text() : ui->rbDeparture->text())
            .arg(ui->deStart->text())
            .arg(ui->deEnd->text())
            .arg(ui->leState->text().isEmpty() ? "-" : ui->leState->text());
}

void FReservationsCommon::openInvoice()
{
    QList<QVariant> out;
    if (fReportGrid->fillRowValuesOut(out) < 0) {
        message_info(tr("Nothing was selected"));
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_id"] = out.at(0);
    fDD.exec("select f_invoice from f_reservation where f_id=:f_id");
    if (!fDD.nextRow()) {
        message_error(tr("Cannot open invoice"));
        return;
    }
    QString inv = fDD.getString(0);
    if (inv.isEmpty()) {
        return;
    }

    openInvoiceWithId(inv);
}
