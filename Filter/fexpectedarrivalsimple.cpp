#include "fexpectedarrivalsimple.h"
#include "ui_fexpectedarrivalsimple.h"
#include "wreportgrid.h"

FExpectedArrivalSimple::FExpectedArrivalSimple(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FExpectedArrivalSimple)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Expected arrivals / simple"),
                                     ":/images/arrival.png");
    connect(ui->wd, SIGNAL(changed()), this, SLOT(refresh()));
}

FExpectedArrivalSimple::~FExpectedArrivalSimple()
{
    delete ui;
}

void FExpectedArrivalSimple::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(100, "", tr("Room"))
    .setColumn(100, "", tr("Guests"))
    .setColumn(120, "", tr("Entry"))
    .setColumn(120, "", tr("Departure"))
    .setColumn(300, "", tr("Remarks"));
    rg->fModel->setSqlQuery("select f_short, f_man+f_woman + f_child,r.f_startdate, r.f_enddate, r.f_remarks "
                            "from f_reservation r "
                            "inner join f_room rm on rm.f_id=r.f_room "
                            "where f_startDate between " + ui->wd->ds1() + " and " + ui->wd->ds2() + " "
                            "and r.f_state=2 "
                            "order by r.f_room ");
    rg->fModel->apply(rg);
    QList<int> cols;
    cols << 1;
    QList<double> vals;
    rg->fModel->sumOfColumns(cols, vals);
    rg->setTblTotalData(cols, vals);
    rg->countToTotal(0);
}

QWidget *FExpectedArrivalSimple::firstElement()
{
    return nullptr;
}

QWidget *FExpectedArrivalSimple::lastElement()
{
    return nullptr;
}

QString FExpectedArrivalSimple::reportTitle()
{
    return QString("%1").arg(tr("Expected arrivals"));
}

void FExpectedArrivalSimple::refresh()
{
    apply(fReportGrid);
}
