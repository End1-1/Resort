#include "fcashreportbyitem.h"
#include "ui_fcashreportbyitem.h"
#include "wreportgrid.h"
#include "cacheusers.h"

FCashReportByItem::FCashReportByItem(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FCashReportByItem)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Cash report common"), ":/images/credit-card.png");
    ui->leOperator->setSelector(this, cache(cid_users), ui->leOperatorName, 0);
    connect(ui->wd, SIGNAL(changed()), this, SLOT(refresh()));
}

FCashReportByItem::~FCashReportByItem()
{
    delete ui;
}

void FCashReportByItem::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(100, "", tr("Source"))
    .setColumn(250, "", tr("Name"))
    .setColumn(150, "", tr("Mode of payment"))
    .setColumn(100, "", tr("Qty"))
    .setColumn(100, "", tr("Amount AMD"))
    .setColumn(100, "", tr("Amount, USD"));
    QString query = "select m.f_source, p.f_en, pm.f_en, count(m.f_id), "
                    "if(m.f_source='RF', -sum(m.f_amountAmd),sum(m.f_amountAmd)),"
                    "if(m.f_source='RF', -sum(m.f_amountAmd / m.f_amountUsd),  sum(m.f_amountAmd / m.f_amountUsd)) "
                    "from m_register m "
                    "left join users u on u.f_id=m.f_user "
                    "left join f_invoice_item p on p.f_id=m.f_itemCode "
                    "left join f_payment_type pm on pm.f_id=m.f_paymentmode "
                    "where m.f_wdate between :f_wdate1 and :f_wdate2 and m.f_canceled=0 and f_finance=1 :operator "
                    "and m.f_SOURCE in ('AV', 'RV', 'RF') and m.f_paymentMode in (1, 2, 3, 4, 15, 16, 17) "
                    "group by 1, 2, 3 "
                    "order by m.f_source ";
    query.replace(":f_wdate1", ui->wd->ds1());
    query.replace(":f_wdate2", ui->wd->ds2());
    if (ui->leOperator->asInt() > 0) {
        query.replace(":operator", QString(" and m.f_user=%1").arg(ui->leOperator->text()));
    } else {
        query.replace(":operator", "");
    }
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
    QList<int> cols;
    cols << 3 << 4 << 5;
    QList<double> vals;
    rg->fModel->sumOfColumns(cols, vals);
    rg->setTblTotalData(cols, vals);
    rg->fModel->insertSubTotals(0, cols);
}

QWidget *FCashReportByItem::firstElement()
{
    return ui->wd->fw();
}

QWidget *FCashReportByItem::lastElement()
{
    return ui->wd->lw();
}

QString FCashReportByItem::reportTitle()
{
    return QString("Cash report by items %1-%2").arg(ui->wd->dss1()).arg(ui->wd->dss2());
}

void FCashReportByItem::refresh()
{
    apply(fReportGrid);
}
