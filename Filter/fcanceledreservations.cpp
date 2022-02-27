#include "fcanceledreservations.h"
#include "ui_fcanceledreservations.h"
#include "wreportgrid.h"
#include "wreservation.h"

FCanceledReservations::FCanceledReservations(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FCanceledReservations)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Canceled reservations"), ":/images/garbage.png");
    connect(fReportGrid, &WReportGrid::doubleClickOnRow, [this](const QList<QVariant> &values) {
        if (values.count() == 0) {
            return;
        }
        WReservation::openReserveWindows(values.at(0).toString());
    });
}

FCanceledReservations::~FCanceledReservations()
{
    delete ui;
}

QWidget *FCanceledReservations::firstElement()
{
    return ui->deStart;
}

QWidget *FCanceledReservations::lastElement()
{
    return ui->deEnd;
}

QString FCanceledReservations::reportTitle()
{
    return QString("%1 %2-%3")
            .arg(tr("Canceled reservations"))
            .arg(ui->deStart->text())
            .arg(ui->deEnd->text());
}

void FCanceledReservations::apply(WReportGrid *rg)
{
    QString date;
    if (ui->rbCancel->isChecked()) {
        date = "r.f_canceldate";
    } else if (ui->rbEntry->isChecked()) {
        date = "r.f_startdate";
    } else if (ui->rbDeparture->isChecked()) {
        date = "r.f_enddate";
    }
    rg->fModel->clearColumns();
    rg->fModel->setColumn(100, "", tr("Code"))
            .setColumn(120, "", tr("Arrival"))
            .setColumn(120, "", tr("Departure"))
            .setColumn(120, "", tr("Canceled"))
            .setColumn(140, "", tr("Nationality"))
            .setColumn(200, "", tr("Guest"))
            .setColumn(80, "", tr("Room"))
            .setColumn(100, "", tr("Rate"))
            .setColumn(100, "", tr("Total"))
            .setColumn(250, "", tr("OP"))
            .setColumn(250, "", tr("Cancel by"))
            .setColumn(300, "", tr("Reason"))
            ;
    QString query = QString("select r.f_id, r.f_startDate, r.f_endDate, r.f_cancelDate, n.f_name, "
            "concat(g.f_firstname, ' ', g.f_lastname) as guest, "
            "r.f_room, r.f_pricepernight, r.f_grandtotal, concat(u1.f_firstName, ' ', u1.f_lastName), concat(u2.f_firstName, ' ', u2.f_lastName), "
            "cr.f_reason "
            "from f_reservation r   "
            "left join f_guests g on g.f_id=r.f_guest "
            "left join users u1 on u1.f_id=r.f_author "
            "left join users u2 on u2.f_id=r.f_cancelUser "
            "left join f_nationality n on n.f_short=g.f_nation "
            "left join f_reservation_cancel_reason cr on cr.f_id=r.f_id "
            "where cast(%1 as date) between :date1 and :date2 and r.f_state=:f_state")
            .arg(date);
    query.replace(":date1", ui->deStart->dateMySql());
    query.replace(":date2", ui->deEnd->dateMySql());
    query.replace(":f_state", QString::number(RESERVE_REMOVED));
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
    QList<int> col;
    col << 8;
    QList<double> val;
    rg->fModel->sumOfColumns(col, val);
    rg->setTblTotalData(col, val);
}

void FCanceledReservations::openReport()
{
    WReportGrid *rg = addTab<WReportGrid>();
    FCanceledReservations *clb = new FCanceledReservations(rg);
    rg->addFilterWidget(clb);
    clb->apply(rg);
}
