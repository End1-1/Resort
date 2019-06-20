#include "fcityledgerbalanceextended.h"
#include "ui_fcityledgerbalanceextended.h"
#include "wreportgrid.h"
#include "ptextrect.h"
#include "fcityledgerdetailedbalance.h"
#include "pimage.h"

FCityLedgerBalanceExtended::FCityLedgerBalanceExtended(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FCityLedgerBalanceExtended)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon( tr("C/L Balance by period"), ":/images/balance.png");
#ifdef _METROPOL_
    fQuery = "select cl.f_id, cl.f_name, coalesce(o.amount, 0), coalesce(d.amount, 0), coalesce(c.amount, 0), \
            coalesce(o.amount, 0) + coalesce(d.amount, 0) - coalesce(c.amount, 0) \
            from f_city_ledger cl \
            left join (select f_cityLedger, sum(m.f_amountAmd*m.f_sign*-1) as amount from m_register m where f_finance=1 and f_canceled=0 and f_wdate<:f_wdate1 group by 1) o on o.f_cityLedger=cl.f_id \
            left join (select f_cityLedger, sum(f_amountAmd) as amount from m_register where f_finance=1 and f_canceled=0 and f_sign=-1 and f_wdate between :f_wdate1 and :f_wdate2 group by 1) d on d.f_cityLedger=cl.f_id \
            left join (select f_cityLedger, sum(f_amountAmd) as amount from m_register where f_finance=1 and f_canceled=0 and f_sign=1  and f_wdate between :f_wdate1 and :f_wdate2 group by 1) c on c.f_cityLedger=cl.f_id \
            where coalesce(o.amount, 0) <> 0 or coalesce(d.amount, 0) <> 0 or coalesce(c.amount, 0) <> 0 \
            order by 2 ";
#else
    fQuery = "select cl.f_id, cl.f_name, coalesce(o.amount, 0), coalesce(d.amount, 0), coalesce(c.amount, 0), \
    coalesce(o.amount, 0) + coalesce(d.amount, 0) - coalesce(c.amount, 0) \
    from f_city_ledger cl \
    left join (select f_cityLedger, \
        sum(if(m.f_source in ('CH', 'PS', 'PE', 'RF', 'RM'), m.f_amountamd, \
        if(m.f_source in ('RV','CR', 'AV', 'DS', 'TR'),m.f_amountAmd*m.f_sign*-1, m.f_amountAmd*m.f_sign*1))) as amount from m_register m where f_finance=1 and f_canceled=0 and f_wdate<:f_wdate1 group by 1) o on o.f_cityLedger=cl.f_id \
    left join (select f_cityLedger, sum(f_amountAmd) as amount from m_register where f_finance=1 and f_canceled=0 and (f_sign=-1 or (f_sign=1 and f_source<>'RV' and f_source<>'DS' and f_source<>'AV' and f_source<>'RF' and f_source<>'TR')) and f_wdate between :f_wdate1 and :f_wdate2 group by 1) d on d.f_cityLedger=cl.f_id \
    left join (select f_cityLedger, sum(f_amountAmd) as amount from m_register where f_finance=1 and f_canceled=0 and f_sign=1 and (f_source in ('RV', 'DS', 'AV', 'RF', 'TR'))  and f_wdate between :f_wdate1 and :f_wdate2 group by 1) c on c.f_cityLedger=cl.f_id \
    where coalesce(o.amount, 0) <> 0 or coalesce(d.amount, 0) <> 0 or coalesce(c.amount, 0) <> 0 \
    order by 1 ";
#endif
    connect(fReportGrid, SIGNAL(doubleClickOnRow(QList<QVariant>)), this, SLOT(doubleClickOnRowSlot(QList<QVariant>)));
}

FCityLedgerBalanceExtended::~FCityLedgerBalanceExtended()
{
    delete ui;
}

QWidget *FCityLedgerBalanceExtended::firstElement()
{
    return ui->deStart;
}

QWidget *FCityLedgerBalanceExtended::lastElement()
{
    return ui->deEnd;
}

void FCityLedgerBalanceExtended::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(100, "", tr("CODE"))
            .setColumn(300, "", tr("DESCRIPTION"))
            .setColumn(150, "", tr("BROUHGT FORWARD"))
            .setColumn(150, "", tr("DEBIT"))
            .setColumn(150, "", tr("CREDIT"))
            .setColumn(150, "", tr("BALANCE"));
    QString query = fQuery;
    query.replace(":f_wdate1", ui->deStart->dateMySql()).replace(":f_wdate2", ui->deEnd->dateMySql());
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
    QList<int> cols;
    cols << 2 << 3 << 4 << 5;
    QList<double> vals;
    rg->fModel->sumOfColumns(cols, vals);
    rg->setTblTotalData(cols, vals);
}

QString FCityLedgerBalanceExtended::reportTitle()
{
    QString title = QString("%1\r\n%2: %3\r\n %4: %5")
            .arg(tr("CITY LEDGER BALANCE"))
            .arg(tr("FROM DATE"))
            .arg(ui->deStart->text())
            .arg(tr("TO DATE"))
            .arg(ui->deEnd->text());
    return title;
}

bool FCityLedgerBalanceExtended::officialTitle()
{
    return true;
}

void FCityLedgerBalanceExtended::open()
{
    WReportGrid *rg = addTab<WReportGrid>();
    FCityLedgerBalanceExtended *be = new FCityLedgerBalanceExtended(rg);
    rg->addFilterWidget(be);
    be->apply(rg);
}

void FCityLedgerBalanceExtended::doubleClickOnRowSlot(const QList<QVariant> &values)
{
    if (values.count() == 0) {
        return;
    }
    WReportGrid *rg = addTab<WReportGrid>();
    FCityLedgerDetailedBalance *clb = new FCityLedgerDetailedBalance(rg);
    clb->setData(ui->deStart->date(), ui->deEnd->date(), values.at(0).toString());
    clb->apply(rg);
}

void FCityLedgerBalanceExtended::on_btnPrevDate_clicked()
{
    ui->deStart->setDate(ui->deStart->date().addDays(-1));
    ui->deEnd->setDate(ui->deEnd->date().addDays(-1));
    apply(fReportGrid);
}

void FCityLedgerBalanceExtended::on_btnNextDate_clicked()
{
    ui->deStart->setDate(ui->deStart->date().addDays(1));
    ui->deEnd->setDate(ui->deEnd->date().addDays(1));
    apply(fReportGrid);
}
