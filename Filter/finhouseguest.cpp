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
    ui->chAll->click();
    ui->chDisplayRate->click();
    fReportGrid->setupTabTextAndIcon(tr("In house guests"), ":/images/bed.png");
}

FInHouseGuest::~FInHouseGuest()
{
    delete ui;
}

void FInHouseGuest::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(0, "", tr("Date"))
            .setColumn(70, "", tr("Room"))
            .setColumn(70, "", tr("Cat"));
    if (ui->chDisplayName->isChecked()) {
        rg->fModel->setColumn(250, "", tr("Guests"));
    }
    rg->fModel->setColumn(60, "", tr("Adults"))
            .setColumn(60, "", tr("Childs"))
            .setColumn(50, "", tr("Acc."))
            .setColumn(100, "", tr("Arrival"))
            .setColumn(100, "", tr("Departure"))
            .setColumn(120, "", tr("Nation"));
    if (ui->chDisplayRate->isChecked()) {
        rg->fModel->setColumn(80, "", tr("Room rate"))
            .setColumn(60, "", tr("Extra bed"))
            .setColumn(60, "", tr("Meal plan"));
    }
    rg->fModel->setColumn(30, "", tr("VAT"));
    if (ui->chDisplayCardex->isChecked()) {
        rg->fModel->setColumn(300, "", tr("Cardex"));
    }
    rg->fModel->setColumn(200, "", tr("Operator"));
    QString query = "select current_date(), r.f_room, c.f_short, ";
    if (ui->chDisplayName->isChecked()) {
        query += "group_concat(g1.gname separator ', '), ";
    }
    query += "r.f_man+r.f_woman, r.f_child, "
            "ar.f_en, r.f_startdate, r.f_enddate, n.f_name, ";
    if (ui->chDisplayRate->isChecked()) {
        query += "r.f_pricepernight, r.f_extrabedfee, "
            "r.f_mealprice, ";
    }
    query += "v.f_vat,  ";
    if (ui->chDisplayCardex->isChecked()) {
        query += "cx.f_name, ";
    }
    query += "u.f_username "
            "from f_reservation r "
            "left join f_guests g on g.f_id=r.f_guest "
            "left join (select f_reservation, concat(g.f_firstName, ' ' , g.f_lastName) as gname "
                "from f_reservation_guests gr left join f_guests g on g.f_id=gr.f_guest) g1 on g1.f_reservation=r.f_id "
            "left join f_room rm on rm.f_id=r.f_room "
            "left join f_room_classes c on c.f_id=rm.f_class "
            "left join f_room_arrangement ar on ar.f_id=r.f_arrangement "
            "left join f_nationality n on n.f_short=g.f_nation "
            "left join f_vat_mode v on v.f_id=r.f_vatmode "
            "left join f_cardex cx on cx.f_cardex=r.f_cardex "
            "left join users u on u.f_id=r.f_checkinuser ";

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
    if (!ui->wCardex->cardex().isEmpty()) {
        where += QString(" and r.f_cardex='%1' ").arg(ui->wCardex->cardex());
    }
    where += "group by r.f_room order by rm.f_building, r.f_room ";
    query += where ;
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);

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
