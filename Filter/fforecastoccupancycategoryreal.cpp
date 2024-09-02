#include "fforecastoccupancycategoryreal.h"
#include "ui_fforecastoccupancycategoryreal.h"
#include "wreportgrid.h"

struct ROOM {
    bool v1;
    bool v2;
    ROOM() {
        v1 = false;
        v2 = false;
    }
};

FForecastOccupancyCategoryReal::FForecastOccupancyCategoryReal(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FForecastOccupancyCategoryReal)
{
    ui->setupUi(this);
    setupTab();
}

FForecastOccupancyCategoryReal::~FForecastOccupancyCategoryReal()
{
    delete ui;
}

void FForecastOccupancyCategoryReal::apply(WReportGrid *rg)
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

    QMap<QString, QMap<QString, ROOM> > mapTmpl;
    fDD.exec("select rc.f_short, rm.f_id from f_room rm "
               "left join f_room_classes rc on rm.f_class=rc.f_id ");
    while (fDD.nextRow()) {
        mapTmpl[fDD.getString("f_short")][fDD.getString("f_id")].v1 = false;
        mapTmpl[fDD.getString("f_short")][fDD.getString("f_id")].v2 = false;
    }

    rg->fModel->setColumn(100, "", tr("Date"));
    rg->fModel->setColumn(40, "", tr("Tot"));
    for (QMap<QString, int>::const_iterator it = cats.begin(); it != cats.end(); it++) {
        rg->fModel->setColumn(40, "", it.key());
    }
    rg->fModel->setColumn(80, "", tr("Tot/occ"));
    int vacIndex = rg->fModel->columnCount();
    for (QMap<QString, int>::const_iterator it = cats.begin(); it != cats.end(); it++) {
        rg->fModel->setColumn(40, "", it.key());
    }
    rg->fModel->setColumn(80, "", tr("Tot/vac"));
    int totIndex = rg->fModel->columnCount();
    rg->fModel->setColumn(40, "", tr("O/O"))
            .setColumn(80, "", tr("Amount"))
            .setColumn(80, "", tr("Avg. rate"))
            .setColumn(50, "", tr("Per %"));

    QList<QVariant> er;
    int row = 0;
    QList<QList<QVariant> > rows;
    rows.clear();
    for (int i = 0; i < rg->fModel->columnCount(); i++) {
        er.append(QVariant());

    }
    for (QDate d = ui->deStart->date(); d != ui->deEnd->date().addDays(1); d = d.addDays(1)) {
        QMap<QString, QMap<QString, ROOM> > map = mapTmpl;
        QString query = QString("select rc.f_short, r.f_room, r.f_state, r.f_startdate, r.f_enddate, r.f_id, "
                                "sum(coalesce(r.f_pricepernight, 0)) as f_amount "
                                "from f_room rm "
                                "left join f_reservation r on r.f_room=rm.f_id "
                                "left join f_room_classes rc on rc.f_id=rm.f_class "
                                "where '%1' between r.f_startDate and r.f_endDate "
                                "and r.f_state in (1,2,4,7,9) "
                                "group by r.f_id ")
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
                int state = fDD.getInt("f_state");
                QString cs = fDD.getString("f_short");
                QDate d1 = fDD.getDate("f_startdate");
                QDate d2 = fDD.getDate("f_enddate");
                if (state == RESERVE_OUTOFROOM || state == RESERVE_OUTOFINVENTORY || state == RESERVE_SERVICE) {
                    rows[row][totIndex] = rows[row][totIndex].toInt() + 1;
                    map[cs][fDD.getString("f_room")].v1 = true;
                    map[cs][fDD.getString("f_room")].v2 = true;
                } else {
                    rows[row][catIndex] = rows[row][catIndex].toInt() + 1;
                    rows[row][totIndex + 1] = rows[row][totIndex + 1].toDouble() + fDD.getDouble("f_amount");
                    if (d1 < d && d2 > d) {
                        map[cs][fDD.getString("f_room")].v1 = true;
                        map[cs][fDD.getString("f_room")].v2 = true;
                    } else if (d1 == d) {
                        map[cs][fDD.getString("f_room")].v2 = true;
                        if (d == WORKING_DATE) {
                            map[cs][fDD.getString("f_room")].v1 = true;
                        }
                    } else if (d2 == d) {
                        map[cs][fDD.getString("f_room")].v1 = true;
                    }
                }
            }
        } else {
            nr = er;
            nr[0] = d.toString(def_date_format);
            nr[1] = totRooms;
            rows.append(nr);
            row = rows.count() - 1;

//                int catIndex = cats[fDD.getString("f_short")] + 2;
//                int state = fDD.getInt("f_state");
//                QString cs = fDD.getString("f_short");
//                QDate d1 = fDD.getDate("f_startdate");
//                QDate d2 = fDD.getDate("f_enddate");
//                if (state == RESERVE_OUTOFROOM || state == RESERVE_OUTOFINVENTORY || state == RESERVE_SERVICE) {
//                    rows[row][totIndex] = rows[row][totIndex].toInt() + 1;
//                    map[cs][fDD.getString("f_room")].v1 = true;
//                    map[cs][fDD.getString("f_room")].v2 = true;
//                } else {
//                    rows[row][catIndex] = rows[row][catIndex].toInt() + 1;
//                    rows[row][totIndex + 1] = rows[row][totIndex + 1].toDouble() + fDD.getDouble("f_amount");
//                    if (d1 < d && d2 > d) {
//                        map[cs][fDD.getString("f_room")].v1 = true;
//                        map[cs][fDD.getString("f_room")].v2 = true;
//                    } else if (d1 == d) {
//                        map[cs][fDD.getString("f_room")].v2 = true;
//                        if (d == WORKING_DATE) {
//                            map[cs][fDD.getString("f_room")].v1 = true;
//                        }
//                    } else if (d2 == d) {
//                        map[cs][fDD.getString("f_room")].v1 = true;
//                    }
//                }

        }

        QMap<QString, int> mapQty;
        for (QMap<QString, QMap<QString, ROOM> >::const_iterator it = map.begin(); it != map.end(); it++) {
            for (QMap<QString, ROOM>::const_iterator ir = it.value().begin(); ir != it.value().end(); ir++) {
                if (ir.value().v1 == false || ir.value().v2 == false) {
                    mapQty[it.key()] = mapQty[it.key()] + 1;
                }
            }
            if (rows.count() == 0) {
                continue;
            }
            rows[row][cats[it.key()] + vacIndex] = mapQty[it.key()];
        }
    }

    for (int i = 0; i < rows.count(); i++) {
        int totalOcc = 0;
        int totalVac = 0;
        for (QMap<QString, int>::const_iterator it = cats.begin(); it != cats.end(); it++) {
            int catIndex = it.value() + 2;
            if (rows[i][catIndex].toInt() == 0) {
                rows[i][catIndex] = 0;
            }
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

QWidget *FForecastOccupancyCategoryReal::firstElement()
{
    return ui->deStart;
}

QWidget *FForecastOccupancyCategoryReal::lastElement()
{
    return ui->deEnd;
}

QString FForecastOccupancyCategoryReal::reportTitle()
{
    return QString("%1 %2 - %3")
            .arg(tr("Forecast / Occupancy"))
            .arg(ui->deStart->text())
            .arg(ui->deEnd->text());
}

void FForecastOccupancyCategoryReal::setupTab()
{
    fReportGrid->setupTabTextAndIcon(QString("%1 %2-%3")
                                     .arg(tr("Forecast occupancy / category"))
                                     .arg(ui->deStart->date().toString(def_date_format))
                                     .arg(ui->deEnd->date().toString(def_date_format)),
                                     ":/images/checkin.png");
}

void FForecastOccupancyCategoryReal::on_deStart_dateChanged(const QDate &date)
{
    Q_UNUSED(date)
    setupTab();
}

void FForecastOccupancyCategoryReal::on_deEnd_dateChanged(const QDate &date)
{
    Q_UNUSED(date)
    setupTab();
}
