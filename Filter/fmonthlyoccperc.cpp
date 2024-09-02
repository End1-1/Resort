#include "fmonthlyoccperc.h"
#include "ui_fmonthlyoccperc.h"
#include "wreportgrid.h"
#include "monthnames.h"
#include "cacheyear.h"

FMonthlyOccPerc::FMonthlyOccPerc(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FMonthlyOccPerc)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Yearly summary occupancy report"), ":/images/reports.png");
    ui->deDate1->setDate(QDate::fromString(QString("%1-01-01").arg(ui->cbYear->currentText()), "yyyy-MM-dd"));
    ui->deDate2->setDate(QDate::fromString(QString("%1-12-31").arg(ui->cbYear->currentText()), "yyyy-MM-dd"));
}

FMonthlyOccPerc::~FMonthlyOccPerc()
{
    delete ui;
}

QWidget *FMonthlyOccPerc::firstElement()
{
    return ui->cbYear;
}

QWidget *FMonthlyOccPerc::lastElement()
{
    return ui->cbYear;
}

QString FMonthlyOccPerc::reportTitle()
{
    return QString("%1: %2 - %3").arg(tr("Yearly summary occupancy report"), ui->deDate1->text(), ui->deDate2->text());
}

void FMonthlyOccPerc::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(100, "", tr("Year"))
            .setColumn(150, "", tr("Month"))
            .setColumn(100, "", tr("Av. rooms"))
            .setColumn(100, "", tr("Occ. rooms"))
            .setColumn(100, "", tr("Occ. percent"));
    QString rooming = fPreferences.getDb(def_rooming_list).toString();
    if (fPreferences.getDb(def_penalty_list).toString().length() > 0) {
        rooming += "," + fPreferences.getDb(def_penalty_list).toString();
    }
    QString query = "select extract(year from f_wdate) as f_year, extract(month from f_wdate) as f_month, ";
    if (ui->chGroupByDays->isChecked()) {
        query += "extract(day from f_wdate), ";
    }
    query += "count(f_id) as f_count "
            "from m_register m "
            "where m.f_wdate between :date1 and :date2 and f_canceled=0 and f_finance=1 "
            "and f_itemCode in (:rooming) "
            "group by 1, 2 ";
    if (ui->chGroupByDays->isChecked()) {
        query += ",3";
    }
    query.replace(":date1", ui->deDate1->dateMySql());
    query.replace(":date2", ui->deDate2->dateMySql());
    query.replace(":rooming", rooming);
    QList<QList<QVariant> > &rows = rg->fModel->fDD.fDbRows;
    rows.clear();
    QList<QVariant> er;
    er << QVariant() << QVariant() << QVariant() << QVariant() << QVariant();
    DoubleDatabase dd;
    dd.exec("select count(f_id) from f_room");
    dd.nextRow();
    int rooms = dd.getInt(0);
    dd.exec(query);
    while (dd.nextRow()) {
        QList<QVariant> nr = er;
        nr[0] = dd.getInt("f_year");
        nr[1] = __dateUtils.mn(dd.getInt("f_month"));
        if (ui->chGroupByDays->isChecked()) {
            nr[2] = rooms;
        } else {
            int days = QDate::fromString(QString("%1-%2-01").arg(dd.getInt("f_year")).arg(dd.getInt("f_month"), 2, 10, QChar('0')), "yyyy-MM-dd").daysInMonth();
            nr[2] = rooms * days;
        }
        nr[3] = dd.getInt("f_count");
        nr[4] = nr[3].toDouble() / nr[2].toDouble() * 100.00;
        rows.append(nr);
    }
    int total = 0, occ = 0;
    for (int i = 0; i < rows.count(); i++) {
        total += rows[i][2].toInt();
        occ += rows[i][3].toInt();
    }
    QList<QVariant> trr = er;
    trr[0] = tr("Total");
    trr[2] = total;
    trr[3] = occ;
    trr[4] = trr[3].toDouble() / trr[2].toDouble() * 100.00;
    rows.append(trr);
    //sql << "select year, f_name, f_total, f_occ, f_perc from rep";
    rg->fModel->apply(rg);
    rg->fTableView->setSpan(rows.count() - 1, 0, 1, 2);
}
