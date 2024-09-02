#include "faccmonthlyreport.h"
#include "ui_faccmonthlyreport.h"
#include "wreportgrid.h"
#include "paymentmode.h"
#include "fvauchers.h"
#include <QHeaderView>

FAccMonthlyReport::FAccMonthlyReport(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FAccMonthlyReport)
{
    ui->setupUi(this);
    setTabText();
    fReportGrid->fTableView->verticalHeader()->setDefaultSectionSize(18);
    connect(fReportGrid->fTableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(dblClick(QModelIndex)));
    ui->cbMonth->setCurrentIndex(QDate::currentDate().month() - 1);
    ui->deStart->setDate(QDate::currentDate().addDays((QDate::currentDate().day() - 1) * -1));
    ui->deEnd->setDate(QDate::currentDate());
    fDec = 4;
}

FAccMonthlyReport::~FAccMonthlyReport()
{
    delete ui;
}

void FAccMonthlyReport::getInvoiceContent(QList<QList<QVariant> > &rows, QMap<QString, int> &dateMap, int col, const QString & item) {
    DoubleDatabase dd;
    dd.open();
    dd[":f_date1"] = ui->deStart->date();
    dd[":f_date2"] = ui->deEnd->date();
    QString date = "date_format(ic.f_wdate, '%d/%m/%Y')";
    if (ui->rbWeek->isChecked()) {
        date = "date_format(ic.f_wdate, '%v, %m/%Y')";
    }
    if (ui->rbMonth->isChecked()) {
        date = "date_format(ic.f_wdate, '%m/%Y')";
    }
    if (ui->rbYear->isChecked()) {
        date = "date_format(ic.f_wdate, '%Y')";
    }
    dd[":f_canceled"] = (ui->chCanceled->isChecked() ? 1 : 0);
    dd.exec("select " + date + ", sum(abs(ic.f_amountAmd*f_sign)) "
               "from m_register ic "
               "where f_canceled=:f_canceled and f_wdate between :f_date1 and :f_date2 "
               "and ic.f_itemCode in (" + item + ") and ic.f_paymentMode<> " + QString::number(PAYMENT_COMPLIMENTARY) + " "
               "group by 1");
    while (dd.nextRow()) {
        int destRow = dateMap[dd.getString(0)];
        rows[destRow][col] = trunc(dd.getValue(1).toDouble());
    }
}

void FAccMonthlyReport::getAvailableRoom(QList<QList<QVariant> > &rows, QMap<QString, int> &dateMap)
{
    QString date = "date_format(d.f_date, '%d/%m/%Y')";
    if (ui->rbWeek->isChecked()) {
        date = "date_format(d.f_date, '%v, %m/%Y')";
    }
    if (ui->rbMonth->isChecked()) {
        date = "date_format(d.f_date, '%m/%Y')";
    }
    if (ui->rbYear->isChecked()) {
        date = "date_format(d.f_date, '%Y')";
    }
    DoubleDatabase dd;
    dd[":f_date1"] = ui->deStart->date();
    dd[":f_date2"] = ui->deEnd->date();
    dd.exec("select " + date + ", count(rm.f_id) from f_room rm, s_days d where d.f_date between :f_date1 and :f_date2 group by 1");
    while (dd.nextRow()) {
        int destRow = dateMap[dd.getString(0)];
        rows[destRow][15] = dd.getValue(1);
    }
}

void FAccMonthlyReport::getNights(QList<QList<QVariant> > &rows, QMap<QString, int> &dateMap)
{
    QString date = "date_format(m.f_wdate, '%d/%m/%Y')";
    if (ui->rbWeek->isChecked()) {
        date = "date_format(m.f_wdate, '%v, %m/%Y')";
    }
    if (ui->rbMonth->isChecked()) {
        date = "date_format(m.f_wdate, '%m/%Y')";
    }
    if (ui->rbYear->isChecked()) {
        date = "date_format(m.f_wdate, '%Y')";
    }
    QString rooming = fPreferences.getDb(def_rooming_list).toString();
    if (fPreferences.getDb(def_penalty_list).toString().length() > 0) {
        rooming += "," + fPreferences.getDb(def_penalty_list).toString();
    }
    DoubleDatabase dd;
    dd[":f_date1"] = ui->deStart->date();
    dd[":f_date2"] = ui->deEnd->date();
    dd[":f_canceled"] = (ui->chCanceled->isChecked() ? 1 : 0);
    dd.exec("select " + date + ", count(m.f_id) "
               "from m_register m "
               "where m.f_canceled=:f_canceled and m.f_wdate between :f_date1 and :f_date2 and m.f_amountamd>0.1 and m.f_finance=1 "
               "and m.f_itemCode in (" + rooming + ") and m.f_paymentMode<> " + QString::number(PAYMENT_COMPLIMENTARY) + " "
               "group by 1");
    while (dd.nextRow()) {
        int destRow = dateMap[dd.getString(0)];
        rows[destRow][16] = dd.getValue(1);
    }
}

void FAccMonthlyReport::getFreeNights(QList<QList<QVariant> > &rows, QMap<QString, int> &dateMap)
{
    QString date = "date_format(m.f_wdate, '%d/%m/%Y')";
    if (ui->rbWeek->isChecked()) {
        date = "date_format(m.f_wdate, '%v, %m/%Y')";
    }
    if (ui->rbMonth->isChecked()) {
        date = "date_format(m.f_wdate, '%m/%Y')";
    }
    if (ui->rbYear->isChecked()) {
        date = "date_format(m.f_wdate, '%Y')";
    }
    DoubleDatabase dd;
    dd[":f_date1"] = ui->deStart->date();
    dd[":f_date2"] = ui->deEnd->date();
    dd[":f_canceled"] = (ui->chCanceled->isChecked() ? 1 : 0);
    dd.exec("select " + date + ", count(m.f_id) "
               "from m_register m "
               "where m.f_canceled=:f_canceled and m.f_wdate between :f_date1 and :f_date2 and m.f_amountamd<0.01 and m.f_finance=1 "
               "and m.f_itemCode in (" + fPreferences.getDb(def_rooming_list).toString() + ") and m.f_paymentMode<> " + QString::number(PAYMENT_COMPLIMENTARY) + " "
               "group by 1");
    while (dd.nextRow()) {
        int destRow = dateMap[dd.getString(0)];
        rows[destRow][17] = dd.getValue(1);
    }
}

void FAccMonthlyReport::getGuest(QList<QList<QVariant> > &rows, QMap<QString, int> &dateMap)
{
    QString date = "date_format(m.f_wdate, '%d/%m/%Y')";
    if (ui->rbWeek->isChecked()) {
        date = "date_format(m.f_wdate, '%v, %m/%Y')";
    }
    if (ui->rbMonth->isChecked()) {
        date = "date_format(m.f_wdate, '%m/%Y')";
    }
    if (ui->rbYear->isChecked()) {
        date = "date_format(m.f_wdate, '%Y')";
    }
    DoubleDatabase dd;
    dd[":f_date1"] = ui->deStart->date();
    dd[":f_date2"] = ui->deEnd->date();
    dd[":f_canceled"] = (ui->chCanceled->isChecked() ? 1 : 0);
    dd.exec("select " + date + ", sum(r.f_man+r.f_woman+r.f_child) "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv "
            "where m.f_wdate between :f_date1 and :f_date2 and m.f_canceled=:f_canceled and f_finance=1 "
            "and r.f_state in(1, 3) "
            "and m.f_itemCode in (" + fPreferences.getDb(def_rooming_list).toString() + ") "
            "group by 1");
    while (dd.nextRow()) {
        int destRow = dateMap[dd.getString(0)];
        rows[destRow][19] = dd.getValue(1);
    }

}

void FAccMonthlyReport::getGPOSContent(QList<QList<QVariant> > &rows, QMap<QString, int> &dateMap, int col, const QString &store)
{
    DoubleDatabase fDD;
    fDD[":f_date1"] = ui->deStart->date();
    fDD[":f_date2"] = ui->deEnd->date();
    QString date = "date_format(ic.f_date, '%d/%m/%Y')";
    if (ui->rbWeek->isChecked()) {
        date = "date_format(o.f_dateCash, '%v, %m/%Y')";
    }
    if (ui->rbMonth->isChecked()) {
        date = "date_format(o.f_dateCash, '%m/%Y')";
    }
    if (ui->rbYear->isChecked()) {
        date = "date_format(o.f_dateCash, '%Y')";
    }
    fDD.exec("select " + date + ", sum(d.f_total) "
               "from o_dish d "
               "inner join o_header o on o.f_id=d.f_header "
               "where o.f_state=2 and d.f_state=1 and o.f_dateCash between :f_date1 and :f_date2 "
               "and d.f_store in (" + store + ") "
               "group by 1");
    while (fDD.nextRow()) {
        int destRow = dateMap[fDD.getString(0)];
        rows[destRow][col] = fDD.getValue(1);
    }
}

void FAccMonthlyReport::apply(WReportGrid *rg)
{
    DoubleDatabase fDD;
    fDD.exec("select * from serv_monthly order by f_id");
    QMap<QString, QVariant> row;
    row["#"] = 0;
    row["date"] = 1;
    row["rooming"] = 2;
    row["extrabed"] = 3;
    row["minibar"] = 4;
    row["laundry"] = 5;
    row["phone"] =  6;
    row["conference"] = 7;
    row["other"] = 8;
    row["roscafe"] = 9;
    row["restaurant"] = 10;
    row["airport"] = 11;
    row["banq"] = 12;
    row["swiming"] = 13;
    row["total"] = 14;
    row["avroom"]  = 15;
    row["occroom"] = 16;
    row["free"] = 18;
    row["avgrate"] = 19;
    row["pax"] = 20;
    row["rev"] = 21;
    QList<int> totalColumns;
    totalColumns << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11 << 12 << 13 << 14 << 15 << 16 << 17 << 18 << 19 << 20;
    rg->fModel->clearColumns();
    rg->fModel->setColumn(30, "", tr("#")) //0
            .setColumn(80, "", tr("Date")); //1
    for (int i = 0; i < fDD.rowCount(); i++) {
        rg->fModel->setColumn(fDD.getValue(i, "f_width").toInt(), "", fDD.getValue(i, "f_title").toString().replace("/", "\r\n"));
    }
    rg->fModel->setColumn(90, "", tr("Total")) //13
            .setColumn(50, "", tr("Av.\nroom")) //14
            .setColumn(50, "", tr("Occ.\nroom")) //15
            .setColumn(30, "", tr("Fr\nee")) //16
            .setColumn(70, "", tr("Avg.rate")) //17
            .setColumn(50, "", tr("Pax")) //18
            .setColumn(100, "", tr("REV")); //19;
    QList<QVariant> rowTemplate;
    for (int i = 0; i < row.count(); i++) {
        rowTemplate << QVariant("");
    }
    QMap<QString, int> dateMap;
    QList<QList<QVariant> > rows;
    QString dateToStr = "dd/MM/yyyy";
    if (ui->rbWeek->isChecked()) {
        dateToStr = "MM/yyyy";
    }
    if (ui->rbMonth->isChecked()) {
        dateToStr = "MM/yyyy";
    }
    if (ui->rbYear->isChecked()) {
        dateToStr = "yyyy";
    }
    if (!ui->deStart->date().isValid() || !ui->deEnd->date().isValid()) {
        message_error(tr("Invalid date range"));
        return;
    }
    for (QDate d = ui->deStart->date(); d < ui->deEnd->date().addDays(1); d = d.addDays(1)) {
        QString dateStr = d.toString(dateToStr);
        if (ui->rbWeek->isChecked()) {
            dateStr = QString::number(d.weekNumber()) + ", " + d.toString(dateToStr);
        }
        if (!dateMap.contains(dateStr)) {
            rows.append(rowTemplate);
            rows[rows.count() - 1][0] = rows.count();
            rows[rows.count() - 1][1] = dateStr;
            dateMap[dateStr] = rows.count() - 1;
        }
    }
    for (int i = 0; i < fDD.rowCount(); i++) {
        getInvoiceContent(rows, dateMap, i + 2, fDD.getValue(i, "f_items").toString());
    }

//    Total
    for (int i = 0; i < rows.count(); i++) {
        rows[i][14] = 0.0;
        for (int j = 2; j < 14; j++) {
            rows[i][14] = trunc(rows[i][14].toDouble() + rows[i][j].toDouble());
        }
        if (i > 0) {
            rows[i][20] = trunc(rows[i - 1][20].toDouble() + rows[i][14].toDouble());
        } else {
            rows[i][20] = rows[i][14];
        }

        if (rows[i][16].toDouble() > 0) {
            rows[i][18] = trunc(rows[i][2].toDouble() / rows[i][16].toDouble());
        }
    }

    QString date = "date_format(f_date, '%d/%m/%x')";
    if (ui->rbWeek->isChecked()) {
        date = "date_format(f_date, '%v, %m/%x')";
    }
    if (ui->rbMonth->isChecked()) {
        date = "date_format(f_date, '%m/%x')";
    }
    if (ui->rbYear->isChecked()) {
        date = "date_format(f_date, '%x')";
    }
    getAvailableRoom(rows, dateMap);
    getNights(rows, dateMap);
    getFreeNights(rows, dateMap);
    getGuest(rows, dateMap);
//    //Occupied date, av room rooms, rate, free room, pax
//    fDD[":date1"] = ui->deStart->date();
//    fDD[":date2"] = ui->deEnd->date();
//    fDD.exec("call occupied_room_in_range(:date1, :date2)");
//    fDD.exec("select " + date + ", sum(f_avroom), sum(f_room), sum(f_rate), sum(f_free), sum(f_pax) from map group by 1");
//    while (fDD.nextRow()) {
//        int destRow = dateMap[fDD.getString(0)];
//        rows[destRow][16] = fDD.getValue(2);
//        rows[destRow][17] = fDD.getValue(4);
//        rows[destRow][18] = fDD.getValue(3);
//        rows[destRow][19] = fDD.getValue(5);
//    }
//    fDD.exec("drop temporary table map");

    for (int i = 0; i < rows.count(); i++) {

        if (rows[i][16].toDouble() > 0) {
            rows[i][18] = trunc(rows[i][2].toDouble() / rows[i][16].toDouble());
        }

    }

    rg->fModel->setDataFromSource(rows);
    if (rows.count() < 0) {
        return;
    }
    QList<double> totalValues;
    rg->fModel->sumOfColumns(totalColumns, totalValues);
    totalValues[totalValues.count() - 1] = rows.at(rows.count() - 1).at(20).toDouble();
    rg->setTblTotalData(totalColumns, totalValues);

    if (fReportGrid->fTableTotal->toDouble(0, 16) > 0) {
        fReportGrid->fTableTotal->setItemWithValue(0, 18, fReportGrid->fTableTotal->toDouble(0, 2) / fReportGrid->fTableTotal->toDouble(0, 16));
    }

}

QWidget *FAccMonthlyReport::firstElement()
{
    return ui->deStart;
}

QWidget *FAccMonthlyReport::lastElement()
{
    return ui->deEnd;
}

QString FAccMonthlyReport::reportTitle()
{
    QString text;
    if (ui->rbDay->isChecked()) {
        text = tr("By day");
    } else if (ui->rbWeek->isChecked()) {
        text = tr("By week");
    } else if (ui->rbMonth->isChecked()) {
        text = tr("By month");
    } else if (ui->rbYear->isChecked()) {
        text = tr("By year");
    }
    return QString("%1 From %2 To %3, %4 %5")
            .arg(tr("Monthly report"))
            .arg(ui->deStart->text())
            .arg(ui->deEnd->text())
            .arg(text)
            .arg(ui->chCanceled->isChecked() ? tr("Canceled") : "");
}

void FAccMonthlyReport::dblClick(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    if (index.column() < 2 || index.column() > 13) {
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_id"] = index.column() - 1;
    fDD.exec("select * from serv_monthly where f_id=:f_id");
    if (!fDD.nextRow()) {
        return;
    }
    QString items = fDD.getString("f_items");
    QString dateStr = fReportGrid->fModel->data(index.row(), 1).toString();
    QDate date = QDate::fromString(dateStr, def_date_format);
    FVauchers::openWithFilter(date, date, items);
}

void FAccMonthlyReport::setTabText()
{
    fReportGrid->setupTabTextAndIcon(QString("%1 %2-%3")
                                     .arg(tr("Monthly report"))
                                     .arg(ui->deStart->date().toString(def_date_format))
                                     .arg(ui->deEnd->date().toString(def_date_format)),
                                     ":/images/graph.png");
}

void FAccMonthlyReport::setDateRange()
{
    QString d1 = QString("01/%1/%2")
            .arg(ui->cbMonth->currentIndex() + 1, 2, 10, QChar('0'))
            .arg(ui->cbYear->currentText());
    QDate date1 = QDate::fromString(d1, def_date_format);

    QString d2 = QString("%1/%2/%3")
            .arg(date1.daysInMonth())
            .arg(ui->cbMonth->currentIndex() + 1, 2, 10, QChar('0'))
            .arg(ui->cbYear->currentText());
    QDate date2 = QDate::fromString(d2, def_date_format);
    ui->deStart->setDate(date1);
    ui->deEnd->setDate(date2);
}

void FAccMonthlyReport::on_deStart_dateChanged(const QDate &date)
{
    Q_UNUSED(date)
    setTabText();
}

void FAccMonthlyReport::on_deEnd_dateChanged(const QDate &date)
{
    Q_UNUSED(date)
    setTabText();
}

void FAccMonthlyReport::on_cbYear_currentIndexChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    setDateRange();
}

void FAccMonthlyReport::on_cbMonth_currentIndexChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    setDateRange();
}
