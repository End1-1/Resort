#include "fexpectedsimple.h"
#include "ui_fexpectedsimple.h"
#include "wreportgrid.h"

FExpectedSimple::FExpectedSimple(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FExpectedSimple)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Expected arrivals / simple"),
                                     ":/images/arrival.png");
    connect(ui->wd, SIGNAL(changed()), this, SLOT(refresh()));
    ui->wd->setVisible(false);
}

FExpectedSimple::~FExpectedSimple()
{
    delete ui;
}

void FExpectedSimple::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(100, "", tr("Room"))
    .setColumn(120, "", tr("Nation"))
    .setColumn(70, "", tr("Guests"))
    .setColumn(70, "", tr("Adults"))
    .setColumn(70, "", tr("Childs"))
    .setColumn(110, "", tr("Entry"))
    .setColumn(110, "", tr("Departure"))
    .setColumn(200, "", tr("Cardex"))
    .setColumn(300, "", tr("Remarks"));
    rg->fModel->setSqlQuery("select rm.f_short, n.f_name, r.f_man+r.f_woman + r.f_child, "
                            "r.f_man+r.f_woman, r.f_child, "
                            "r.f_startdate, r.f_enddate, ca.f_name, r.f_remarks "
                            "from f_reservation r "
                            "inner join f_room rm on rm.f_id=r.f_room "
                            "inner join f_guests g on g.f_id=r.f_guest "
                            "left join f_nationality n on n.f_short=g.f_nation "
                            "left join f_cardex ca on ca.f_cardex=r.f_cardex "
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

QWidget *FExpectedSimple::firstElement()
{
    return nullptr;
}

QWidget *FExpectedSimple::lastElement()
{
    return nullptr;
}

QString FExpectedSimple::reportTitle()
{
    return QString("%1, %2").arg(tr("Expected arrivals"), WORKING_DATE.toString(def_date_format));
}

void FExpectedSimple::refresh()
{
    apply(fReportGrid);
}
