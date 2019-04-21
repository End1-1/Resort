#include "fwakeupcall.h"
#include "ui_fwakeupcall.h"
#include "wreportgrid.h"
#include "dlgwakepcalls.h"

FWakeupCall::FWakeupCall(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FWakeupCall)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Wakeup calls"), ":/images/alarm.png");
    connect(ui->wd, SIGNAL(changed()), fReportGrid, SLOT(on_btnRefresh_clicked()));
    connect(fReportGrid, SIGNAL(doubleClickOnRow(QList<QVariant>)), this, SLOT(openDialog(QList<QVariant>)));
}

FWakeupCall::~FWakeupCall()
{
    delete ui;
}

QString FWakeupCall::reportTitle()
{
    return QString("%1 %2 - %3")
            .arg(tr("Wakeup calls"))
            .arg(ui->wd->dss1())
            .arg(ui->wd->dss2());
}

QWidget *FWakeupCall::firstElement()
{
    return ui->wd->fw();
}

QWidget *FWakeupCall::lastElement()
{
    return ui->wd->lw();
}

void FWakeupCall::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(100, "", tr("Invoice"))
            .setColumn(100, "", tr("Room"))
            .setColumn(300, "", tr("Guest"))
            .setColumn(120, "", tr("Date"))
            .setColumn(120, "", tr("Time"))
            .setColumn(100, "", tr("Repeat"));
    QString query = "select w.f_invoice, r.f_room, g.guest, w.f_date, w.f_time, w.f_repeat "
                    "from f_wakeupcalls w "
                    "left join f_reservation r on w.f_invoice=r.f_invoice "
                    "left join guests g on g.f_id=r.f_guest "
                    "where (w.f_date between :date1 and :date2 and w.f_repeat=0) "
                    "or (w.f_repeat=1 and :date1 between r.f_startdate and r.f_enddate) "
                    "or (w.f_repeat=1 and :date2 between r.f_startdate and r.f_enddate) ";
    query.replace(":date1", ui->wd->ds1()).replace(":date2", ui->wd->ds2());
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
}

void FWakeupCall::openDialog(const QList<QVariant> &values)
{
    if (values.count() == 0) {
        return;
    }
    DlgWakepCalls::openWakeupCallsByInvoice(values.at(0).toString());
}
