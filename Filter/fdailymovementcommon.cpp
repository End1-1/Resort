#include "fdailymovementcommon.h"
#include "ui_fdailymovementcommon.h"
#include "wreportgrid.h"
#include "cacheinvoiceitem.h"

FDailyMovementCommon::FDailyMovementCommon(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FDailyMovementCommon)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Financial report"), ":/images/graph.png");
    ui->leTypeOfSale->setSelector(this, cache(cid_invoice_item), ui->leTypeOfSale);
}

FDailyMovementCommon::~FDailyMovementCommon()
{
    delete ui;
}

QWidget *FDailyMovementCommon::firstElement()
{
    return ui->deDate;
}

QWidget *FDailyMovementCommon::lastElement()
{
    return ui->leEnd;
}

QString FDailyMovementCommon::reportTitle()
{
    return QString("%1 %2 - %3").
            arg(tr("Daily financial report"), ui->deDate->text(), ui->leEnd->text());
}

void FDailyMovementCommon::apply(WReportGrid *rg)
{
    fReportGrid->fStaticQuery =
            "select :date m.f_source, m.f_itemCode, p.f_en, "
            "sum(m.f_amountAmd), sum(m.f_amountAmd / m.f_amountUsd), "
            "m1.f_amountamd, m1.f_amountusd "
            "from m_register m "
            "left join users u on u.f_id=m.f_user "
            "left join f_invoice_item p on p.f_id=m.f_itemCode "
            "left join serv_daily_movement sdm  on sdm.f_itemCode=m.f_itemCode "
            "left join (select m1.f_itemcode, sum(m1.f_amountamd) as f_amountamd, sum(m1.f_amountamd/m1.f_amountusd) as f_amountusd "
                " from m_register m1 "
                " where m1.f_wdate between :f_wdate1 and :f_wdate2 and m1.f_canceled=0 and m1.f_finance=1 and m1.f_fiscal>0 "
                " group by 1) m1 on m1.f_itemcode=m.f_itemcode "
            "where m.f_wdate between :f_wdate1 and :f_wdate2 and m.f_canceled=0 and f_finance=1 "
            "and p.f_group=1 :itemCode  "
            "group by 1, 2, 3 :groupDate "
            "order by m.f_itemCode, m.f_wdate";
    QString query = rg->fStaticQuery;
    fReportGrid->fModel->clearColumns();
    if (ui->chExpandDate->isChecked()) {
        query.replace(":date","m.f_wdate,")
                .replace(":groupDate", ",4");
        fReportGrid->fModel->setColumn(100, "", tr("Date"));
    } else {
        query.replace(":date","")
                .replace(":groupDate", "");
    }
    if (ui->leTypeOfSale->fHiddenText.isEmpty()) {
        query.replace(":itemCode", "");
    } else {
        query.replace(":itemCode", QString(" and m.f_itemCode in(%1)").arg(ui->leTypeOfSale->fHiddenText));
    }
    fReportGrid->fModel->setColumn(50, "", tr("Source"))
            .setColumn(50, "", tr("Code"))
            .setColumn(300, "", tr("Name"))
            .setColumn(100, "", tr("Amount 1, AMD"))
            .setColumn(100, "", tr("Amount 1, USD"))
            .setColumn(100, "", tr("Amount 2, AMD"))
            .setColumn(100, "", tr("Amount 2, USD"));

    query.replace(":f_wdate1", ui->deDate->dateMySql())
            .replace(":f_wdate2", ui->leEnd->dateMySql());
    fReportGrid->fModel->setSqlQuery(query);
    fReportGrid->fModel->apply(rg);
    QList<int> cols;
    cols << 3 << 4;
    QList<double> vals;
    fReportGrid->fModel->sumOfColumns(cols, vals);
    fReportGrid->setTblTotalData(cols, vals);
}

void FDailyMovementCommon::open()
{
    WReportGrid *rg = addTab<WReportGrid>();
    FDailyMovementCommon *dmc = new FDailyMovementCommon(rg);
    rg->addFilterWidget(dmc);
    dmc->apply(rg);
}
