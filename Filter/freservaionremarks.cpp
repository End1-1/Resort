#include "freservaionremarks.h"
#include "ui_freservaionremarks.h"
#include "wreportgrid.h"

FReservaionRemarks::FReservaionRemarks(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FReservaionRemarks)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Remarks"), ":/images/remarks.png");
    ui->label->setVisible(false);
    ui->wd->setVisible(false);
}

FReservaionRemarks::~FReservaionRemarks()
{
    delete ui;
}

void FReservaionRemarks::apply(WReportGrid *rg)
{
    if (ui->rbCheckout->isChecked()) {
        apply2(rg);
        return;
    }
    rg->fModel->clearColumns();
    rg->fTableView->verticalHeader()->setDefaultSectionSize(40);
    rg->fModel->setColumn(100, "f_room", tr("Room"))
            .setColumn(200, "f_guest", tr("Guest"))
            .setColumn(700, "f_remarks", tr("Remarks"));
    rg->fModel->setSqlQuery(QString("select r.f_room, concat(g.f_firstName, ' ' , g.f_lastName), r.f_remarks "
                        "from f_reservation r "
                        "left join f_guests g on g.f_id=r.f_guest "
                        "where r.f_state=%1 order by r.f_startDate")
                            .arg(ui->rbCheckin->isChecked() ? 1 : 2));
    rg->fModel->apply(rg);
    for (int i = 0; i < rg->fModel->rowCount(); i++) {
        rg->fModel->setBackgroundColor(i, (i % 2 == 0 ? Qt::white : COLOR_DARK_ROW));
    }
    rg->fTableView->resizeRowsToContents();
}

void FReservaionRemarks::apply2(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fTableView->verticalHeader()->setDefaultSectionSize(40);
    rg->fModel->setColumn(100, "f_room", tr("Room"))
            .setColumn(200, "f_invoice", tr("Invoice"))
            .setColumn(200, "f_startdate", tr("Arrival"))
            .setColumn(200, "f_enddate", tr("Departure"))
            .setColumn(200, "f_guest", tr("Guest"))
            .setColumn(700, "f_remarks", tr("Remarks"));
    rg->fModel->setSqlQuery(QString("select r.f_room, r.f_invoice, r.f_startdate, r.f_enddate, concat(g.f_firstName, ' ' , g.f_lastName), r.f_remarks "
                        "from f_reservation r "
                        "left join f_guests g on g.f_id=r.f_guest "
                        "where r.f_state=%1 and r.f_enddate between '%2' and '%3' order by r.f_startDate")
                            .arg(RESERVE_CHECKOUT)
                            .arg(ui->wd->d1().toString(def_mysql_date_format))
                            .arg(ui->wd->d2().toString(def_mysql_date_format)));
    rg->fModel->apply(rg);
    for (int i = 0; i < rg->fModel->rowCount(); i++) {
        rg->fModel->setBackgroundColor(i, (i % 2 == 0 ? Qt::white : COLOR_DARK_ROW));
    }
    rg->fTableView->resizeRowsToContents();
}

QWidget *FReservaionRemarks::firstElement()
{
    return ui->rbCheckin;
}

QWidget *FReservaionRemarks::lastElement()
{
    return ui->rbCheckin;
}

QString FReservaionRemarks::reportTitle()
{
    return QString("%1, %2")
            .arg(tr("Reservation remarks"))
            .arg(ui->rbCheckin->isChecked() ? tr("Checkin") : tr("Reserved"));
}

void FReservaionRemarks::openReport()
{
    WReportGrid *rg = addTab<WReportGrid>();
    FReservaionRemarks *y = new FReservaionRemarks(rg);
    rg->addFilterWidget(y);
    y->apply(rg);
}

void FReservaionRemarks::on_rbReserve_clicked()
{
    ui->label->setVisible(false);
    ui->wd->setVisible(false);
    apply(fReportGrid);
}

void FReservaionRemarks::on_rbCheckin_clicked()
{
    ui->label->setVisible(false);
    ui->wd->setVisible(false);
    apply(fReportGrid);
}

void FReservaionRemarks::on_rbCheckout_clicked()
{
    ui->label->setVisible(true);
    ui->wd->setVisible(true);
    apply(fReportGrid);
}
