#include "fdailytransaction.h"
#include "ui_fdailytransaction.h"
#include "wreportgrid.h"

FDailyTransaction::FDailyTransaction(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FDailyTransaction)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Daily transactions"), ":/images/category.png");
}

FDailyTransaction::~FDailyTransaction()
{
    delete ui;
}

QString FDailyTransaction::reportTitle()
{
    return QString("%1 %2 - %3")
            .arg(tr("Daily transactions"))
            .arg(ui->wd->dss1())
            .arg(ui->wd->dss2());
}

QWidget *FDailyTransaction::firstElement()
{
    return ui->wd->fw();
}

QWidget *FDailyTransaction::lastElement()
{
    return ui->wd->lw();
}

void FDailyTransaction::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(80, "", tr("Type"))
            .setColumn(100, "", tr("Operator"))
            .setColumn(120, "", tr("Date"))
            .setColumn(80, "", tr("Time"))
            .setColumn(100,"", tr("Code"))
            .setColumn(80, "", tr("Room"))
            .setColumn(300, "", tr("Guest"))
            .setColumn(100, "", tr("Entry"))
            .setColumn(100, "", tr("Depature"))
            .setColumn(70, "", tr("Pax"))
            .setColumn(200, "", tr("Cardex"))
            .setColumn(80, "", tr("Rate"))
            .setColumn(100, "", tr("Total"));
    QString query = "select m.f_source, m.f_user, m.f_wdate, m.f_time, m.f_id, "
            "m.f_room, m.f_guest, r.f_startdate, r.f_enddate, r.f_man+r.f_woman+r.f_child as f_pax, "
            "c.f_name, r.f_pricePerNight, a.f_amountAmd "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv "
            "left join f_cardex c on c.f_cardex=r.f_cardex "
            "left join (select f_inv, sum(f_amountAmd*f_sign) as f_amountamd from m_register where f_canceled=0 and f_finance=1) a on a.f_inv=m.f_inv "
            "where m.f_wdate between :date1 and :date2 and m.f_canceled=0 and m.f_source in (:sources) and m.f_cityledger=0 "
            "order by field(f_source, 'CI', 'RS', 'CO'), m.f_wdate, m.f_time";
    query.replace(":date1", ui->wd->ds1()).replace(":date2", ui->wd->ds2());
    query.replace(":sources", "'CI', 'CO', 'RS'");
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
}
