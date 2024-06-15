#include "fincompleteguestsnames.h"
#include "ui_fincompleteguestsnames.h"
#include "wdate2.h"
#include "wreportgrid.h"

FIncompleteGuestsNames::FIncompleteGuestsNames(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FIncompleteGuestsNames)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Incomplete guests"), ":/images/remarks.png");
}

FIncompleteGuestsNames::~FIncompleteGuestsNames()
{
    delete ui;
}

QWidget *FIncompleteGuestsNames::firstElement()
{
    return ui->wd->fw();
}

QWidget *FIncompleteGuestsNames::lastElement()
{
    return ui->wd->lw();
}

QString FIncompleteGuestsNames::reportTitle()
{
    return tr("Incomplete guests names");
}

void FIncompleteGuestsNames::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(120, "", tr("Checkin"))
        .setColumn(120, "", tr("Checkout"))
        .setColumn(120, "", tr("Invoice"))
        .setColumn(80, "", tr("Count"))
        .setColumn(80, "", tr("Names"));
    QString query = "SELECT r.f_startdate, r.f_enddate, r.f_invoice, r.f_man+r.f_woman+r.f_child, rc.cnt "
                     "FROM f_reservation r "
                      "   left JOIN (SELECT rc.f_reservation, COUNT(rc.f_id) AS cnt FROM f_reservation_guests rc GROUP BY 1) rc "
                      "       ON r.f_id=rc.f_reservation "
                      "WHERE r.f_startdate between %date1 and %date2 AND r.f_state IN (1,3) "
                    "AND r.f_man+r.f_woman+r.f_child - rc.cnt<>0 ";
    query.replace("%date1", ui->wd->ds1()).replace("%date2", ui->wd->ds2());
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
}
