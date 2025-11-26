#include "fexpecteddeparturesimple.h"
#include "ui_fexpecteddeparturesimple.h"
#include "wreportgrid.h"

FExpectedDepartureSimple::FExpectedDepartureSimple(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FExpectedDepartureSimple)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Expected departures / simple"),
                                     ":/images/departure.png");
    connect(ui->wd, SIGNAL(changed()), this, SLOT(refresh()));
}

FExpectedDepartureSimple::~FExpectedDepartureSimple()
{
    delete ui;
}

void FExpectedDepartureSimple::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(100, "", tr("Room"))
    .setColumn(120, "", tr("Nation"))
    .setColumn(100, "", tr("Guests"))
    .setColumn(120, "", tr("Entry"))
    .setColumn(120, "", tr("Departure"))
    .setColumn(300, "", tr("Remarks"));
    rg->fModel->setSqlQuery("select rm.f_short, n.f_name, r.f_man+r.f_woman + r.f_child, r.f_startdate, r.f_enddate, r.f_remarks "
                            "from f_reservation r "
                            "inner join f_room rm on rm.f_id=r.f_room "
                            "inner join f_guests g on g.f_id=r.f_guest "
                            "left join f_nationality n on n.f_short=g.f_nation "
                            "where r.f_endDate between " + ui->wd->ds1() + " and " + ui->wd->ds2() + " "
                            "and r.f_state=1 "
                            "order by r.f_room ");
    rg->fModel->apply(rg);
    QList<int> cols;
    cols << 1;
    QList<double> vals;
    rg->fModel->sumOfColumns(cols, vals);
    rg->setTblTotalData(cols, vals);
    rg->countToTotal(0);
}

QWidget *FExpectedDepartureSimple::firstElement()
{
    return this;
}

QWidget *FExpectedDepartureSimple::lastElement()
{
    return this;
}

QString FExpectedDepartureSimple::reportTitle()
{
    return QString("%1, %2").arg(tr("Expected departures")).arg(WORKING_DATE.toString(def_date_format));
}

void FExpectedDepartureSimple::refresh()
{
    apply(fReportGrid);
}
