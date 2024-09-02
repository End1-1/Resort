#include "fforecastoccupancycategory.h"
#include "ui_fforecastoccupancycategory.h"
#include "wreportgrid.h"

FForecastOccupancyCategory::FForecastOccupancyCategory(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FForecastOccupancyCategory)
{
    ui->setupUi(this);
    setupTab();
}

FForecastOccupancyCategory::~FForecastOccupancyCategory()
{
    delete ui;
}

void FForecastOccupancyCategory::apply(WReportGrid *rg)
{
    if (ui->deStart->date() < WORKING_DATE || ui->deEnd->date() < WORKING_DATE || ui->deStart->date() > ui->deEnd->date()) {
        message_error(tr("Invalid date range"));
        return;
    }
    rg->fModel->clearData();
    rg->fModel->clearColumns();
    QMap<QString, int> cats;
    QMap<QString, int> catsQty;
    DoubleDatabase fDD;
    fDD.exec("select rc.f_short, count(rm.f_id) from f_room_classes rc "
               "left join f_room rm on rm.f_class=rc.f_id group by 1");
    int ind = 0;
    int totRooms = 0;
    int catCount = 0;
    while (fDD.nextRow()) {
        catCount++;
        cats[fDD.getString(0)] = ind++;
        catsQty[fDD.getString(0)] = fDD.getInt(1);
        totRooms += fDD.getInt(1);
    }

    rg->fModel->setColumn(100, "", tr("Date"));
    rg->fModel->setColumn(40, "", tr("Tot"));
    for (QMap<QString, int>::const_iterator it = cats.constBegin(); it != cats.constEnd(); it++) {
        rg->fModel->setColumn(40, "", it.key());
    }
    rg->fModel->setColumn(80, "", tr("Tot/occ"));
    int vacIndex = rg->fModel->columnCount();
    for (QMap<QString, int>::const_iterator it = cats.constBegin(); it != cats.constEnd(); it++) {
        rg->fModel->setColumn(40, "", it.key());
    }
    rg->fModel->setColumn(80, "", tr("Tot/vac"));
    int totIndex = rg->fModel->columnCount();
    rg->fModel->setColumn(40, "", tr("O/O"))
            .setColumn(80, "", tr("Amount"))
            .setColumn(80, "", tr("Avg. rate"))
            .setColumn(50, "", tr("Per %"));

    QList<QVariant> er;
    int row;
    QList<QList<QVariant> > rows;
    rows.clear();
    for (int i = 0; i < rg->fModel->columnCount(); i++) {
        er.append(QVariant());

    }
    for (QDate d = ui->deStart->date(); d != ui->deEnd->date().addDays(1); d = d.addDays(1)) {
        QString query = QString("select rc.f_short, r.f_state, count(r.f_room) as rooms, "
                                "sum(coalesce(r.f_pricepernight, 0)) as f_amount "
                                "from f_room rm "
                                "left join f_reservation r on r.f_room=rm.f_id "
                                "left join f_room_classes rc on rc.f_id=rm.f_class "
                                "where '%1' >= r.f_startDate and '%1' < r.f_endDate "
                                "and r.f_state in (1,2,4,7,9) "
                                "group by 1, 2")
                .arg(d.toString(def_mysql_date_format));
        QList<QVariant> nr;
        fDD.exec(query);
        if (fDD.rowCount() > 0) {
            nr = er;
            nr[0] = d.toString(def_date_format);
            nr[1] = totRooms;
            rows.append(nr);
            row = rows.count() - 1;
            while (fDD.nextRow()) {
                int catIndex = cats[fDD.getString("f_short")] + 2;
                if (fDD.getInt(1) == RESERVE_OUTOFROOM || fDD.getInt(1) == RESERVE_OUTOFINVENTORY || fDD.getInt(1) == RESERVE_SERVICE) {
                    rows[row][totIndex] = rows[row][totIndex].toInt() + fDD.getInt("rooms");
                    rows[row][catIndex + vacIndex - 2] = rows[row][catIndex + vacIndex - 2].toInt() - fDD.getInt("rooms");
                } else {
                    rows[row][catIndex] = rows[row][catIndex].toInt() + fDD.getInt("rooms");
                    rows[row][totIndex + 1] = rows[row][totIndex + 1].toDouble() + fDD.getDouble("f_amount");
                }
            }
        }
    }

    for (int i = 0; i < rows.count(); i++) {
        int totalOcc = 0;
        int totalVac = 0;
        for (QMap<QString, int>::const_iterator it = cats.constBegin(); it != cats.constEnd(); it++) {
            int catIndex = it.value() + 2;
            if (rows[i][catIndex].toInt() == 0) {
                rows[i][catIndex] = 0;
            }
            rows[i][catIndex + vacIndex - 2] = catsQty[it.key()] - rows[i][catIndex].toInt() + rows[i][catIndex + vacIndex - 2].toInt();
            totalOcc += rows[i][catIndex].toInt();
            totalVac += rows[i][catIndex + vacIndex - 2].toInt();
        }
        rows[i][vacIndex - 1] = totalOcc;
        rows[i][totIndex - 1] = totalVac;
        rows[i][totIndex + 2] = rows[i][totIndex + 1].toDouble() / rows[i][vacIndex - 1].toInt();
        rows[i][totIndex + 3] = (rows[i][vacIndex - 1].toDouble()) / totRooms * 100.0;
    }


    rg->fModel->fDD.fDbRows = rows;
    rg->fModel->apply(rg);

    QList<int> cols;
    QList<double> vals;
    for (int i = 1; i < rg->fModel->columnCount(); i++) {
        cols.append(i);
    }
    rg->fModel->sumOfColumns(cols, vals);
    vals[totIndex + 2 - 1] = vals[totIndex + 1 - 1] / vals[vacIndex - 1 - 1];
    vals[totIndex + 3 - 1] = vals[vacIndex - 1 - 1] / vals[0] * 100.0;
    rg->setTblTotalData(cols, vals);
}

QWidget *FForecastOccupancyCategory::firstElement()
{
    return ui->deStart;
}

QWidget *FForecastOccupancyCategory::lastElement()
{
    return ui->deEnd;
}

QString FForecastOccupancyCategory::reportTitle()
{
    return QString("%1 %2 - %3")
            .arg(tr("Forecast / Occupancy"))
            .arg(ui->deStart->text())
            .arg(ui->deEnd->text());
}

void FForecastOccupancyCategory::setupTab()
{
    fReportGrid->setupTabTextAndIcon(QString("%1 %2-%3")
                                     .arg(tr("Forecast occupancy / category"))
                                     .arg(ui->deStart->date().toString(def_date_format))
                                     .arg(ui->deEnd->date().toString(def_date_format)),
                                     ":/images/checkin.png");
}

void FForecastOccupancyCategory::on_deStart_dateChanged(const QDate &date)
{
    Q_UNUSED(date)
    setupTab();
}

void FForecastOccupancyCategory::on_deEnd_dateChanged(const QDate &date)
{
    Q_UNUSED(date)
    setupTab();
}
