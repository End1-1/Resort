#include "finhouseguestfuture.h"
#include "ui_finhouseguestfuture.h"
#include "wreportgrid.h"

FInhouseGuestFuture::FInhouseGuestFuture(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FInhouseGuestFuture)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Inhouse guest, future"), ":/images/bed.png");
    connect(ui->wDate, SIGNAL(changed()), this, SLOT(refresh()));
    fReportGrid->addToolBarButton(":/images/chart.png", tr("Chart"), SLOT(chart()), this);
}

FInhouseGuestFuture::~FInhouseGuestFuture()
{
    delete ui;
}

void FInhouseGuestFuture::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(120, "", tr("Date"))
            .setColumn(120, "", tr("Checkout"))
            .setColumn(120, "", tr("Day use"))
            .setColumn(120, "", tr("In house"))
            .setColumn(120, "", tr("Checkin"))
            .setColumn(120, "", tr("Total"))
            .setColumn(120, "", tr("Delta"));
    if (ui->wDate->d1() > ui->wDate->d2()) {
        message_error(tr("Invalid date range"));
        return;
    }
    if (ui->wDate->d1() < WORKING_DATE) {
        message_error(tr("Invalid date range"));
        return;
    }
    QDate d = ui->wDate->d1();
    QList<QList<QVariant> > rows;
    QList<QVariant> er;
    for (int i = 0; i < 7; i++) {
        er.append(QVariant());
    }
    DoubleDatabase dd;
    do {
        dd[":f_date"] = d;
        dd.exec("select f_startdate, f_enddate, count(f_man+f_woman+f_child) "
                "from f_reservation "
                "where (:f_date between f_startdate and f_enddate and f_state=2) or (f_state=1 and :f_date <= f_enddate) "
                "group by 1, 2");
        QMap<QDate, int> dateMap;
        while (dd.nextRow()) {
            if (!dateMap.contains(d)) {
                rows.append(er);
                dateMap[d] = rows.count() - 1;
            }
            QList<QVariant> &nr = rows[dateMap[d]];
            nr[0] = d;
            if (dd.getDate(0) == d && dd.getDate(1) == d) {
                nr[2] = nr[2].toInt() + dd.getInt(2);
            } else if (dd.getDate(0) == d) {
                nr[4] = nr[4].toInt() + dd.getInt(2);
            } else if (dd.getDate(1) == d) {
                nr[1] = nr[1].toInt() + dd.getInt(2);
            } else {
                nr[3] = nr[3].toInt() + dd.getInt(2);
            }
            nr[5] = 0;
            for (int i = 1; i < 6; i++) {
                nr[5] = nr[5].toInt() + nr[i].toInt();
            }
        }
        d = d.addDays(1);
    } while (d < ui->wDate->d2().addDays(1));
    for (int i = 1; i < rows.count(); i++) {
        rows[i][6] = rows[i][5].toInt() - rows[i - 1][5].toInt();
        if (rows[i][6].toInt() > 0) {
            rows[i][6] = QString("+%1").arg(rows[i][6].toInt());
        }
    }
    rg->fModel->fDD.fDbRows = rows;
    rg->fModel->apply(nullptr);
    QList<int> cols;
    QList<double> vals;
    cols << 1 << 2 << 3 << 4 << 5;
    rg->fModel->sumOfColumns(cols, vals);
    rg->setTblTotalData(cols, vals);
}

QWidget *FInhouseGuestFuture::firstElement()
{
    return ui->wDate->fw();
}

QWidget *FInhouseGuestFuture::lastElement()
{
    return ui->wDate->lw();
}

QString FInhouseGuestFuture::reportTitle()
{
    return tr("Inhouse guest, future %1 - %2").arg(ui->wDate->dss1()).arg(ui->wDate->dss2());
}

void FInhouseGuestFuture::refresh()
{
    apply(fReportGrid);
}
