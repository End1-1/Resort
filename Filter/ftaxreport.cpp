#include "ftaxreport.h"
#include "ui_ftaxreport.h"
#include "wreportgrid.h"

FTaxReport::FTaxReport(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FTaxReport)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Fiscal report"),":/images/arrival.png");
    connect(ui->wd, SIGNAL(changed()), this, SLOT(refresh()));
}

FTaxReport::~FTaxReport()
{
    delete ui;
}

void FTaxReport::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(80, "f_id", tr("Code"))
            .setColumn(110, "f_wdate", tr("Date"))
            .setColumn(80, "f_room", tr("Room"))
            .setColumn(100, "f_inv", tr("Invoice"))
            .setColumn(100, "f_fiscal", tr("Fiscal"))
            .setColumn(110, "f_fiscaldate", tr("Fiscal date"))
            .setColumn(80, "f_fiscaltime", tr("Time"))
            .setColumn(300, "f_finalname", tr("Purpose"))
            .setColumn(100, "f_amountamd", tr("Amount"));
    QString sql = QString("select m.f_id, m.f_wdate, m.f_room, m.f_inv, m.f_fiscal, m.f_fiscaldate, m.f_fiscaltime, "
                    "m.f_finalname, m.f_amountamd "
                    "from m_register m "
                    "where m.f_fiscal>0 and m.f_fiscaldate between %1 and %2 and m.f_canceled=%3")
            .arg(ui->wd->ds1(), ui->wd->ds2(), ui->chCanceled->isChecked() ? "1" : "0");
    rg->fModel->setSqlQuery(sql);
    rg->fModel->apply(rg);
    QList<int> cols;
    cols << 8;
    QList<double> vals;
    rg->fModel->sumOfColumns(cols, vals);
    rg->setTblTotalData(cols, vals);
    rg->countToTotal(0);
}

QWidget *FTaxReport::firstElement()
{
    return nullptr;
}

QWidget *FTaxReport::lastElement()
{
    return nullptr;
}

QString FTaxReport::reportTitle()
{
    return QString("%1, %2 - %3").arg(tr("Printed fiscals"), ui->wd->dss1(), ui->wd->dss2());
}

void FTaxReport::on_chCanceled_clicked()
{
    apply(fReportGrid);
}
