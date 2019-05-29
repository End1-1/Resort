#include "finhouseguest.h"
#include "ui_finhouseguest.h"
#include "wreportgrid.h"
#include "cachecardex.h"

FInHouseGuest::FInHouseGuest(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FInHouseGuest)
{
    ui->setupUi(this);
    ui->deDate->setVisible(r__(cr__inhouse_anytime));
    ui->chDate->setVisible(r__(cr__inhouse_anytime));
    ui->teTime->setVisible(r__(cr__inhouse_anytime));
    ui->chTime->setVisible(r__(cr__inhouse_anytime));
    ui->leCardex->setSelector(this, cache(cid_cardex), ui->leCardexName);
    ui->chDisplayName->click();
}

FInHouseGuest::~FInHouseGuest()
{
    delete ui;
}

void FInHouseGuest::apply(WReportGrid *rg)
{
    QString where;
    if (ui->chDate->isChecked() || ui->chTime->isChecked()) {
        where += " where (r.f_state=1 or r.f_state=3) ";
    } else {
        where += " where (r.f_state=1) ";
    }
    if (ui->chDate->isChecked()) {
        where += " and "+ ui->deDate->dateMySql() + " between r.f_startDate and r.f_endDate ";
    }
    if (ui->chTime->isChecked()) {
        where += QString(" and ADDTIME(CONVERT(%1, DATETIME), '%2') "
                         "between ADDTIME(CONVERT(r.f_startDate, DATETIME), r.f_checkintime) "
                         "and ADDTIME(CONVERT(r.f_endDate, DATETIME), if(r.f_checkouttime is null, '12:00:00', r.f_checkouttime))")
                .arg(ui->deDate->dateMySql())
                .arg(ui->teTime->time().toString("HH:mm:ss"));
    }
    if (!ui->leCardex->isEmpty()) {
        where += QString(" and r.f_cardex='%1' ").arg(ui->leCardex->text());
    }
    where += "order by r.f_room ";
    buildQuery(rg, where);

    QMap<QString, int> total;
    total["B/O-Adult"] = 0;
    total["B/O-Childs"] = 0;
    total["B/B-Adult"] = 0;
    total["B/B-Childs"] = 0;

    int occupied = rg->fModel->rowCount();
    int adults = 0;
    int childs = 0;
    int arCol = rg->fModel->columnIndex(tr("Acc."));
    int adCol = rg->fModel->columnIndex(tr("Adults"));
    int chCol = rg->fModel->columnIndex(tr("Childs"));
    for (int i = 0, count = rg->fModel->rowCount(); i < count; i++) {
        adults += rg->fModel->data(i, adCol).toInt();
        childs += rg->fModel->data(i, chCol).toInt();

        total[rg->fModel->data(i, arCol).toString() + "-Adult"] =
                total[rg->fModel->data(i, arCol).toString() + "-Adult"]
                + rg->fModel->data(i, adCol).toInt();

        total[rg->fModel->data(i, arCol).toString() + "-Childs"] =
                total[rg->fModel->data(i, arCol).toString() + "-Childs"]
                + rg->fModel->data(i, chCol).toInt();
    }

    int colCount = rg->fModel->columnCount();
    QList<QVariant> emptyRow;
    for (int i = 0; i < colCount; i++) {
        emptyRow << "";
    }
    QList<QVariant> tmpRow = emptyRow;
    rg->fModel->appendRow(emptyRow);
    tmpRow[1] = tr("Occupied");
    tmpRow[2] = tr("Adults");
    tmpRow[3] = tr("Childs");
    rg->fModel->appendRow(tmpRow);
    tmpRow = emptyRow;
    tmpRow[1] = QString::number(occupied);
    tmpRow[2] = QString::number(adults);
    tmpRow[3] = QString::number(childs);
    rg->fModel->appendRow(tmpRow);
    tmpRow = emptyRow;
    rg->fModel->appendRow(tmpRow);
    tmpRow[1] = "B/O - Adult";
    tmpRow[2] = "B/O - Child";
    tmpRow[3] = "B/B - Adult";
    tmpRow[4] = "B/B - Child";
    rg->fModel->appendRow(tmpRow);
    tmpRow = emptyRow;
    tmpRow[1] = total["B/O-Adult"];
    tmpRow[2] = total["B/O-Childs"];
    tmpRow[3] = total["B/B-Adult"];
    tmpRow[4] = total["B/B-Childs"];
    rg->fModel->appendRow(tmpRow);
    rg->fTableView->setSpan(occupied, 0, 1, colCount);
    rg->fTableView->setSpan(occupied + 3, 0, 1, colCount);

    if (ui->chDisplayRate->isChecked()) {
        QList<int> cols;
        cols << 9;
        QList<double> val;
        rg->fModel->sumOfColumns(cols, val);
        rg->fModel->setData(rg->fModel->rowCount() - 5, 8, tr("TOTAL RATE"));
        rg->fModel->setData(rg->fModel->rowCount() - 5, 9, val.at(0));
    }
}

QWidget *FInHouseGuest::firstElement()
{
    return ui->deDate;
}

QWidget *FInHouseGuest::lastElement()
{
    return ui->deDate;
}

QString FInHouseGuest::reportTitle()
{
    return QString("%1, %2")
            .arg(tr("In house guests"))
            .arg(ui->deDate->text());
}

void FInHouseGuest::on_chDate_clicked(bool checked)
{
    ui->deDate->setEnabled(checked);
}

void FInHouseGuest::on_chTime_clicked(bool checked)
{
    ui->teTime->setEnabled(checked);
    if (checked) {
        ui->deDate->setEnabled(true);
        ui->chDate->setChecked(true);
    }
}

void FInHouseGuest::on_chAll_clicked(bool checked)
{
    Q_UNUSED(checked);
    ui->chDisplayName->setChecked(false);
    ui->chDisplayRate->setChecked(false);
    ui->chDisplayCardex->setChecked(false);
    ui->chDisplayName->click();
    ui->chDisplayRate->click();
    ui->chDisplayCardex->click();
}
