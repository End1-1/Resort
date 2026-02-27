#include "wreportssetold.h"
#include "ui_wreportssetold.h"
#include "wreportgrid.h"
#include "edateedit.h"
#include "ecomboboxcompleter.h"
#include "paymentmode.h"
#include "wweb.h"
#include "doubleutils.h"
#include <QDir>
#include <QDesktopServices>
#include <QUrl>

WReportsSetOld::WReportsSetOld(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WReportsSetOld)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->tabButton(0, QTabBar::RightSide)->resize(0, 0);

    int month = QDate::currentDate().month();
    QList<QAbstractButton*> e = fBtnMonth.buttons();
    for (int i = 0; i < e.count(); i++) {
        ERadioButton *er = static_cast<ERadioButton*>(e.at(i));
        if (er->fData["month"].toInt() == month) {
            er->setChecked(true);
            break;
        }
    }

    fBtnGroup.addButton(ui->rbrCategory);
    fBtnGroup.addButton(ui->rbrCategoryYearly);
    fBtnGroup.addButton(ui->rbrOccupancyCategory);
    fBtnGroup.addButton(ui->rbrNationality);
    fBtnGroup.addButton(ui->rbrCardex);
    fBtnGroup.addButton(ui->rbCardexCategory);
    fBtnGroup.addButton(ui->rbrCardexYearly);
    fBtnGroup.addButton(ui->rbrNatYearly);
    fBtnGroup.addButton(ui->rbrSalesMan);
    fBtnGroup.addButton(ui->rbrSalesManYearly);
    fBtnGroup.addButton(ui->rbrArrangement);
    fBtnGroup.addButton(ui->rbrArrangementAge);
    fBtnGroup.addButton(ui->rbrPax);
    fBtnGroup.addButton(ui->rbrMarketSigmentYearly);
    fBtnGroup.addButton(ui->rbrMarketSigment);

    ui->rbrCategory->fData["rep"] = 5;
    ui->rbCardexCategory->fData["rep"] = 20;
    ui->rbrCategoryYearly->fData["rep"] = 6;
    ui->rbrOccupancyCategory->fData["rep"] = 7;
    ui->rbrNationality->fData["rep"] = 8;
    ui->rbrCardex->fData["rep"] = 9;
    ui->rbrCardexYearly->fData["rep"] = 10;
    ui->rbrNatYearly->fData["rep"] = 11;

    ui->rbrSalesMan->fData["rep"] = 12;
    ui->rbrSalesManYearly->fData["rep"] = 13;

    ui->rbrArrangement->fData["rep"] = 14;
    ui->rbrArrangementAge->fData["rep"] = 17;

    ui->rbrMarketSigmentYearly->fData["rep"] = 15;
    ui->rbrMarketSigment->fData["rep"] = 16;

    connect(ui->tabWidget, &QTabWidget::tabCloseRequested, [this] (int index) {
        QWidget *w = ui->tabWidget->widget(index);
        w->deleteLater();
        ui->tabWidget->removeTab(index);
    });
}

WReportsSetOld::~WReportsSetOld()
{
    delete ui;
}

void WReportsSetOld::setup()
{
    setupTabTextAndIcon(tr("Statistics"), ":/images/report.png");
}

QString WReportsSetOld::title()
{
    return "";
}

void WReportsSetOld::rbClicked()
{
    ERadioButton *rb = static_cast<ERadioButton*>(sender());
    DoubleDatabase fDD;
    fDD[":f_id"] = rb->fData["rep"];
    fDD.exec("select f_sql, f_widths, f_titles_en, f_filter, f_sum from serv_reports where f_id=:f_id");
    if (!fDD.nextRow()) {
        message_error(tr("Cannot load report data."));
        return;
    }
    foreach (QWidget* w, fFilterWidgets) {
        ui->hlFilter->removeWidget(w);
        delete w;
    }
    fFilterWidgets.clear();
    ui->hlFilter->removeItem(ui->hlFilter->takeAt(0));
    fFilterFields.clear();
    fFilterDefExpr.clear();
    QStringList filter = fDD.getValue("f_filter").toString().split(";", Qt::SkipEmptyParts);
    int i = 0;
    foreach (QString s, filter) {
        QStringList f = s.split("^", Qt::KeepEmptyParts);
        if (f.at(0) == ":year" || f.at(0) == ":month") {
            continue;
        }
        QLabel *l = new QLabel(f.at(1));
        fFilterWidgets.append(l);
        ui->hlFilter->addWidget(l);
        QWidget *wdt = nullptr;
        if (f.at(2).toLower() == "date") {
            wdt = new EDateEdit();
        } else if (f.at(2).toLower() == "integer") {

        } else if (f.at(2).toLower() == "combobox") {
            wdt = new EComboBoxCompleter();
            EComboBoxCompleter *cc = static_cast<EComboBoxCompleter*>(wdt);
            QStringList comboParams = f.at(4).split(":", Qt::SkipEmptyParts);
            if (comboParams.at(0).toLower() == "sql") {
                cc->setSQL(comboParams.at(1));
            } else if (comboParams.at(0).toLower() == "list") {
                QStringList list = comboParams.at(1).split(",", Qt::SkipEmptyParts);
                foreach (QString l, list) {
                    cc->addItem(l, l);
                }
            }
            if (comboParams.count() > 2) {
                cc->setCurrentIndex(comboParams.at(2).toInt());
            }
        } else if (f.at(2).toLower() == "combo month") {

        } else {
            message_error(tr("Unknown filter widget. Contact to administrator."));
        }
        if (wdt) {
            fFilterWidgets.append(wdt);
            fFilterFields[wdt] = f.at(0);
            fFilterBuilds[wdt] = f.at(3);
            fFilterDefExpr[wdt] = f.at(5);
            ui->hlFilter->addWidget(wdt);
            if (i == 1) {
                wdt->setFocus();
            }
        }
        i++;
    }
    ui->hlFilter->addStretch();
}

void WReportsSetOld::on_btnGo_clicked()
{
    ERadioButton *eb = static_cast<ERadioButton*>(fBtnGroup.checkedButton());
    if (!eb) {
        return;
    }
    QList<QCheckBox*> chl = ui->wCh->checked();
    if (chl.count() == 0 && !ui->chUseDateRange->isChecked()) {
        message_info(tr("No month selected"));
        return;
    }
    QString months;
    QSet<int> tm;
    if (ui->chUseDateRange->isChecked()) {
        if (ui->deDate1->date() > ui->deDate2->date()) {
            message_error(tr("Invalid date range"));
            return;
        }
        QDate d = ui->deDate1->date();
        do {
            tm << d.month();
            d = d.addDays(1);
        } while (d <= ui->deDate2->date());
        for (int i: tm) {
            if (months.length() > 0) {
                months += ",";
            }
            months += QString::number(i);
        }
    } else {
        for (QCheckBox *c: chl) {
            if (months.length() > 0) {
                months += ",";
            }
            months += c->property("M").toString();
        }
    }
    int month = 0;
    if (ui->chUseDateRange->isChecked()) {
        month = tm.values().at(0);
    } else {
        month = chl.at(0)->property("M").toInt();
    }
    QStringList mn = months.split(",", Qt::SkipEmptyParts);
    QMap<int, QString> ms;
    for (const QString &s: mn) {
        ms[s.toInt()] = s;
    }
    months = ms.values().join(",");
    QString reportTitle;
    if (month == 0) {
        reportTitle = ", " + ui->cbYear->currentText();
    } else {
        reportTitle = ", " + ui->cbYear->currentText() + "/" + months;
        reportTitle.replace("0,1,", "1,");
    }
    if (eb->fData["rep"].toInt() == 5 || eb->fData["rep"].toInt() == 7
            || eb->fData["rep"].toInt() == 8
            || eb->fData["rep"].toInt() == 11
            || eb->fData["rep"].toInt() == 14
            || eb->fData["rep"].toInt() == 9
            || eb->fData["rep"].toInt() == 16
            || eb->fData["rep"].toInt() == 17
            || eb->fData["rep"].toInt() == 20) {
        QList<QList<QVariant> > rows;
        QList<int> widths;
        QStringList titles;
        QList<int> sumCols;
        QList<double> sumVals;
        switch (eb->fData["rep"].toInt()) {
        case 5:
            reportTitle = "Category" + reportTitle;
            widths << 130 << 80 << 80 << 80 << 80 << 80 << 100 << 130 << 80;
            titles << "CATEGORY" << "GUESTS" << "NIGHTS" << "FREE PAX" << "FREE NIGHTS" << "ROOMING" << "PENALTY" << "LENGTH OF STAY" << "AVG.ROOM";
            sumCols << 1 << 2 << 3 << 4 << 5 << 6;
            category(rows, months);
            break;
        case 7:
            reportTitle = "Occupancy " + reportTitle;
            widths << 130
                   << 100 << 100 << 100 << 100
                   << 100 << 100 << 100 << 100
                   << 100 << 100 << 100 << 100
                   << 130;
            titles << "CATEGORY"
                   << "JAN" << "FEB" << "MAR" << "APR" << "MAY"
                   << "JUN" << "JUL" << "AUG" << "SEP" << "OCT"
                   << "NOV" << "DEC" << "TOTAL";
            occupancy(rows, months);
            break;
        case 8:
            reportTitle = "Nationality " + reportTitle;
            widths << 150
                   << 100 << 100 << 100 << 100
                   << 100 << 120 << 100;
            titles << "NATIONALITY"
                   << "PAX" << "NIGHTS" << "FREE PAX" << "FREE NIGHTS"
                   << "ROOMING" << "LENGTH OF STAY" << "AVG. ROOMING";
            sumCols << 1 << 2 << 3 << 4 << 5;
            nationality(rows, months);
            break;
        case 9:
            reportTitle = "Cardex" + reportTitle;
            widths << 200 << 80 << 80 << 80 << 80 << 80 << 100 << 130 << 80;
            titles << "Cardex" << "GUESTS" << "NIGHTS" << "FREE PAX" << "FREE NIGHTS" << "ROOMING" << "PENALTY" << "LENGTH OF STAY" << "AVG.ROOM";
            sumCols << 1 << 2 << 3 << 4 << 5 << 6;
            cardex(rows, months);
            break;
        case 11:
            reportTitle = "Nationality Yearly " + reportTitle;
            widths << 130
                   << 100 << 100 << 100 << 100
                   << 100 << 100 << 100 << 100
                   << 100 << 100 << 100 << 100
                   << 130;
            titles << "CATEGORY"
                   << "JAN" << "FEB" << "MAR" << "APR" << "MAY"
                   << "JUN" << "JUL" << "AUG" << "SEP" << "OCT"
                   << "NOV" << "DEC" << "TOTAL";
            nationalityYearly(rows, months);
            sumCols << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11 << 12 << 13;
            break;
        case 14:
            reportTitle = "Room arrangement" + reportTitle;
            widths << 130
                   << 100 << 100 << 100 << 100
                   << 100 << 100;
            titles << "CATEGORY"
                   << "NIGHTS B/O" << "NIGHTS B/B" << "PAX B/O" << "PAX B/B"
                   << "ROOMING B/O" << "ROOMIN B/B";
            sumCols << 1 << 2 << 3 << 4 << 5 << 6;
            roomArrangement(rows, months);
            break;
        case 16:
            reportTitle = "Market sigment" + reportTitle;
            widths << 200 << 80 << 80 << 80 << 80 << 80 << 100 << 130 << 80;
            titles << "Sigment" << "GUESTS" << "NIGHTS" << "FREE PAX" << "FREE NIGHTS" << "ROOMING" << "PENALTY" << "LENGTH OF STAY" << "AVG.ROOM";
            sumCols << 1 << 2 << 3 << 4 << 5 << 6;
            marketsigment(rows, months);
            break;
        case 17:
            reportTitle = "Room arrangement by age" + reportTitle;
            widths << 130
                   << 100 << 100
                   << 100 << 100
                    << 100 << 100
                    << 100 << 100
                    << 100 << 100
                    << 100 << 100
                    << 100 << 100
                    << 100 << 100
                   << 100 << 100;
            titles << "CATEGORY"
                   << "NIGHTS B/O" << "NIGHTS B/B"
                   << "NIGHTS B/0 0-6" << "NIGHTS B/B 0-6"
                   << "NIGHTS B/0 7-11" << "NIGHTS B/B < 12"
                   << "PAX B/O" << "PAX B/B"
                   << "PAX B/O 0-6" << "PAX B/B 0-6"
                   << "PAX B/O 7-11" << "PAX B/B 7-11"
                   << "ROOMING B/O" << "ROOMIN B/B"
                   << "ROOMING B/O 0-6" << "ROOMIN B/B 0-6"
                   << "ROOMING B/O 7-11" << "ROOMIN B/B 7-11"  ;
            sumCols << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11 << 12 << 13 << 14 << 15 << 16 << 17 << 18;
            roomArrangementByAge(rows, months, titles);
            break;
        case 20:
            reportTitle = tr("Cardex group / Category") + " " + ui->deDate1->text() + " - " + ui->deDate2->text();
            cardexCategory(rows, months, widths, titles, sumCols);
            break;
        }
        WReportGrid *rg = new WReportGrid(this);
        ui->tabWidget->addTab(rg, QIcon(":/images/report.png"), reportTitle);
        rg->setTab(ui->tabWidget, ui->tabWidget->count() - 1);
        rg->setupTabTextAndIcon(reportTitle, ":/images/report.png");
        for (int i = 0; i < widths.count(); i++) {
            rg->fModel->setColumn(widths.at(i), "", titles.at(i));
        }
        rg->fModel->fDD.fDbRows = rows;
        rg->fModel->apply(rg);
        rg->fModel->sumOfColumns(sumCols, sumVals);
        rg->setTblTotalData(sumCols, sumVals);
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
        switch (eb->fData["rep"].toInt()) {
        case 5:
            rg->fTableView->setSpan(rg->fModel->rowCount() - 1, 0, 1, 6);
            break;
        case 7:
            rg->fTableView->setSpan(rg->fModel->rowCount() - 1, 0, 1, 14);
            rg->fTableView->setSpan(rg->fModel->rowCount() - 2, 0, 1, 14);
            rg->fTableView->setSpan(rg->fModel->rowCount() - 3, 0, 1, 14);
            rg->setTblNoTotalData();
            break;
        case 20:
            if (sumVals[0] > 0) {
                rg->fTableTotal->setItem(0, widths.count() - 3, new C5TableWidgetItem(float_str(sumVals[widths.count() - 5] / sumVals[0] * 100)));
            }
            if (sumVals[widths.count() - 3] > 0) {
                rg->fTableTotal->setItem(0, widths.count() - 1, new C5TableWidgetItem(float_str(sumVals[widths.count() - 3] / sumVals[widths.count() - 5])));
            }
            break;
        }
    } else {
        DoubleDatabase fDD;
        fDD[":f_id"] = eb->fData["rep"];
        fDD.exec("select f_sql, f_widths, f_titles_en, f_filter, f_sum, f_name from serv_reports where f_id=:f_id");
        if (!fDD.nextRow()) {
            message_error(tr("Cannot load report data."));
            return;
        }

        QString fFilterSQL = fDD.getValue("f_sql").toString();
        WReportGrid *rg = new WReportGrid(this);
        ui->tabWidget->addTab(rg, QIcon(":/images/report.png"), reportTitle);
        rg->setTab(ui->tabWidget, ui->tabWidget->count() - 1);
        rg->setupTabTextAndIcon(reportTitle, ":/images/report.png");

        rg->fModel->clearColumns();
        QStringList widths = fDD.getValue("f_widths").toString().split(";", Qt::SkipEmptyParts);
        QStringList titles = fDD.getValue("f_titles_en").toString().split(";", Qt::SkipEmptyParts);
        for (int i = 0; i < widths.count(); i++) {
            rg->fModel->setColumn(widths.at(i).toInt(), "", titles.at(i));
        }

        QString query = fFilterSQL;
        reportTitle = QString("%1 %2/%3")
                    .arg(fDD.getString("f_name"))
                    .arg(ui->cbYear->currentText())
                    .arg(months);
        query.replace(":year", ui->cbYear->currentText())
                .replace(":month", months);

        for (QMap<QWidget*, QString>::const_iterator it = fFilterFields.begin(); it != fFilterFields.end(); it++) {
           if (isEDateEdit(it.key())) {
               EDateEdit *e = static_cast<EDateEdit*>(it.key());
               query.replace(it.value(), e->dateMySql());
           } else if (isComboCompleter(it.key()) || isComboMonth(it.key())) {
               EComboBoxCompleter *c = static_cast<EComboBoxCompleter*>(it.key());
               if (c->currentData().toString().isEmpty()) {
                   query.replace(it.value(),  fFilterDefExpr[c] );
               } else {
                   QString repStr = fFilterBuilds[c];
                   query.replace(it.value(), repStr.replace(it.value(), c->currentData().toString()) );
               }
           }
        }

        rg->fModel->apply(query.split(";", Qt::SkipEmptyParts));
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);

        rg->setTblNoTotalData();
        QStringList sums = fDD.getValue("f_sum").toString().split(";", Qt::SkipEmptyParts);
        QList<int> cols;
        QList<double> vals;
        if (sums.count() > 0) {
            foreach (QString s, sums) {
                cols << s.toInt();
            }
            rg->fModel->sumOfColumns(cols, vals);
            rg->setTblTotalData(cols, vals);
        }
    }
}

void WReportsSetOld::category(QList<QList<QVariant> > &rows, const QString &month)
{
    QList<QVariant> er;
    // category << pax << nights << free pax << free nights << rooming << noshow << length of stay << avg room
    er << QVariant() << QVariant() << QVariant() << QVariant()
       << QVariant() << QVariant() << QVariant() << QVariant()
       << QVariant();
    DoubleDatabase dd;
    dd.exec("select f_description from f_room_classes");
    QMap<QString, int> catMap;
    while (dd.nextRow()) {
        rows.append(er);
        catMap[dd.getString(0)] = rows.count() - 1;
        rows[catMap[dd.getString(0)]][0] = dd.getString(0);
    }
    QString rooming = fPreferences.getDb(def_rooming_list).toString();
    if (fPreferences.getDb(def_penalty_list).toString().length() > 0) {
        rooming += "," + fPreferences.getDb(def_penalty_list).toString();
    }
    QString query;
    if (ui->chUseDateRange->isChecked()) {
        query = "select rc.f_description, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_room rm on rm.f_id=r.f_room "
                "left join f_room_classes rc on rc.f_id=rm.f_class "
                "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
                "and m.f_wdate between :date1 and :date2 "
                "and m.f_paymentMode<> " + QString::number(PAYMENT_COMPLIMENTARY) + " "
                "and r.f_state in (1,2,3,6) and m.f_amountAmd>0.01 "
                "group by 1;";
        query.replace(":date1", ui->deDate1->dateMySql());
        query.replace(":date2", ui->deDate2->dateMySql());
    } else {
        query = "select rc.f_description, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv "
            "left join f_room rm on rm.f_id=r.f_room "
            "left join f_room_classes rc on rc.f_id=rm.f_class "
            "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
            "and extract(year from m.f_wdate)=:year and extract(month from m.f_wdate) in (:monthlist) "
            "and m.f_paymentMode<> " + QString::number(PAYMENT_COMPLIMENTARY) + " "
            "and r.f_state in (1,2,3,6) and m.f_amountAmd>0.01 "
            "group by 1;";
        query.replace(":monthlist", month);
        query.replace(":year", ui->cbYear->currentText());
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = catMap[dd.getString(0)];
        rows[row][1] = dd.getInt(1);
        rows[row][2] = dd.getDouble(2);
    }
    if (ui->chUseDateRange->isChecked()) {
        query = "select rc.f_description, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
                    "from m_register m "
                    "left join f_reservation r on r.f_invoice=m.f_inv "
                    "left join f_room rm on rm.f_id=r.f_room "
                    "left join f_room_classes rc on rc.f_id=rm.f_class "
                    "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
                    "and m.f_wdate between :date1 and :date2 "
                    "and m.f_paymentMode<> " + QString::number(PAYMENT_COMPLIMENTARY) + " "
                    "and r.f_state in (1,2,3,6) and m.f_amountAmd<0.01 "
                    "group by 1;";
        query.replace(":date1", ui->deDate1->dateMySql());
        query.replace(":date2", ui->deDate2->dateMySql());
    } else {
        query = "select rc.f_description, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
                    "from m_register m "
                    "left join f_reservation r on r.f_invoice=m.f_inv "
                    "left join f_room rm on rm.f_id=r.f_room "
                    "left join f_room_classes rc on rc.f_id=rm.f_class "
                    "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
                    "and extract(year from m.f_wdate)=:year and extract(month from m.f_wdate) in (:monthlist) "
                    "and m.f_paymentMode<> " + QString::number(PAYMENT_COMPLIMENTARY) + " "
                    "and r.f_state in (1,2,3,6) and m.f_amountAmd<0.01 "
                    "group by 1;";
        query.replace(":monthlist", month);
        query.replace(":year", ui->cbYear->currentText());
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = catMap[dd.getString(0)];
        rows[row][3] = dd.getInt(1);
        rows[row][4] = dd.getDouble(2);
    }

    if (ui->chUseDateRange->isChecked()) {
        query = "select rc.f_description, sum(m.f_amountAmd) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_room rm on rm.f_id=r.f_room "
                "left join f_room_classes rc on rc.f_id=rm.f_class "
                "where m.f_itemCode in (" + fPreferences.getDb(def_rooming_list).toString() + ") and m.f_canceled=0 and m.f_finance=1 "
                "and m.f_wdate between :date1 and :date2 "
                "and r.f_state in (1,2,3,6) "
                "group by 1";
        query.replace(":date1", ui->deDate1->dateMySql());
        query.replace(":date2", ui->deDate2->dateMySql());
    } else {
        query = "select rc.f_description, sum(m.f_amountAmd) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_room rm on rm.f_id=r.f_room "
                "left join f_room_classes rc on rc.f_id=rm.f_class "
                "where m.f_itemCode in (" + fPreferences.getDb(def_rooming_list).toString() + ") and m.f_canceled=0 and m.f_finance=1 "
                "and extract(year from m.f_wdate)=:year and extract(month from m.f_wdate) in (:monthlist) "
                "and r.f_state in (1,2,3,6) "
                "group by 1";
        query.replace(":monthlist", month);
        query.replace(":year", ui->cbYear->currentText());
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = catMap[dd.getString(0)];
        rows[row][5] = dd.getDouble(1);
    }

    if (ui->chUseDateRange->isChecked()) {
        query = "select rc.f_description, sum(m.f_amountAmd) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_room rm on rm.f_id=r.f_room "
                "left join f_room_classes rc on rc.f_id=rm.f_class "
                "where m.f_itemCode in (" + fPreferences.getDb(def_penalty_list).toString() + ") and m.f_canceled=0 and m.f_finance=1 "
                "and m.f_wdate between :date1 and :date2 "
                "and r.f_state in (1,2,3,6) "
                "group by 1";
        query.replace(":date1", ui->deDate1->dateMySql());
        query.replace(":date2", ui->deDate2->dateMySql());
    } else {
        query = "select rc.f_description, sum(m.f_amountAmd) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_room rm on rm.f_id=r.f_room "
                "left join f_room_classes rc on rc.f_id=rm.f_class "
                "where m.f_itemCode in (" + fPreferences.getDb(def_penalty_list).toString() + ") and m.f_canceled=0 and m.f_finance=1 "
                "and extract(year from m.f_wdate)=:year and extract(month from m.f_wdate) in (:monthlist) "
                "and r.f_state in (1,2,3,6) "
                "group by 1";
        query.replace(":monthlist", month);
        query.replace(":year", ui->cbYear->currentText());
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = catMap[dd.getString(0)];
        rows[row][6] = dd.getDouble(1);
    }

    for (int i = 0; i < rows.count(); i++) {
        if (rows[i][1].toDouble() + rows[i][3].toDouble() > 0.01) {
            rows[i][7] =  (rows[i][1].toDouble() + rows[i][3].toDouble()) / (rows[i][2].toDouble() + rows[i][4].toDouble());
        } else {
            rows[i][7] = 0;
        }
    }

    for (int i = 0; i < rows.count(); i++) {
        if (rows[i][2].toDouble() > 0) {
            rows[i][8] = rows[i][5].toDouble() / rows[i][2].toDouble();
        } else {
            rows[i][8] = 0;
        }
    }
    rows.append(er);
    rows[rows.count() - 1][0] = QString("ROOMING: %1").arg(rooming);
}

void WReportsSetOld::occupancy(QList<QList<QVariant> > &rows, const QString &month)
{
    Q_UNUSED(month);
    QList<QVariant> er;
    // category << jan << feb << mar << apr << may << jun << jul << aug << sep << oct << nov << dec << total
    er <<QVariant()
       << QVariant() << QVariant() << QVariant() << QVariant()
       << QVariant() << QVariant() << QVariant() << QVariant()
       << QVariant() << QVariant() << QVariant() << QVariant()
       << QVariant();
    DoubleDatabase dd;
    dd.exec("select f_description from f_room_classes");
    QMap<QString, int> catMap;
    while (dd.nextRow()) {
        rows.append(er);
        catMap[dd.getString(0)] = rows.count() - 1;
        rows[catMap[dd.getString(0)]][0] = dd.getString(0);
    }
    dd.exec("select rc.f_description, count(rm.f_id) "
            "from f_room rm "
            "left join f_room_classes rc on rc.f_id=rm.f_class "
            "group by 1");
    QMap<QString, int> countMap;
    while (dd.nextRow()) {
        countMap[dd.getString(0)] = dd.getInt(1);
    }
    QString rooming = fPreferences.getDb(def_rooming_list).toString();
    if (fPreferences.getDb(def_penalty_list).toString().length() > 0) {
        rooming += "," + fPreferences.getDb(def_penalty_list).toString();
    }
    QString query = "select rc.f_description, extract(month from m.f_wdate), count(m.f_id) "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv "
            "inner join f_room rm on rm.f_id=r.f_room "
            "inner join f_room_classes rc on rc.f_id=rm.f_class "
            "where m.f_canceled=0 and m.f_finance=1 and m.f_itemCode in (" + rooming + ") "
            "and extract(year from m.f_wdate)=:year "
            "group by 1, 2";
    query.replace(":year", ui->cbYear->currentText());
    dd.exec(query);
    QMap<int, QList<int> > totalDown;
    QMap<QString, QList<int> > totalLeft;
    while (dd.nextRow()) {
        int row = catMap[dd.getString(0)];
        int col = dd.getInt(1);
        QString dateStr = QString("01/%1/%2").arg(dd.getInt(1), 2, 10, QChar('0')).arg(ui->cbYear->currentText());
        int t = QDate::fromString(dateStr, "dd/MM/yyyy").daysInMonth();
        t *= countMap[dd.getString(0)];
        if (!totalDown.contains(dd.getInt(1))) {
            QList<int> ti;
            ti << 0 << 0 << 0;
            totalDown[dd.getInt(1)] = ti;
        }
        totalDown[dd.getInt(1)][0] = totalDown[dd.getInt(1)][0] + t;
        totalDown[dd.getInt(1)][1] = totalDown[dd.getInt(1)][1] + dd.getInt(2);
        if (totalDown[dd.getInt(1)][0] > 0) {
            totalDown[dd.getInt(1)][2] = totalDown[dd.getInt(1)][1] * 100 / totalDown[dd.getInt(1)][0];
        } else {
            totalDown[dd.getInt(1)][2] = 0;
        }
        if (!totalLeft.contains(dd.getString(0))) {
            QList<int> ti;
            ti << 0 << 0 << 0;
            totalLeft[dd.getString(0)] = ti;
        }
        totalLeft[dd.getString(0)][0] = totalLeft[dd.getString(0)][0] + t;
        totalLeft[dd.getString(0)][1] = totalLeft[dd.getString(0)][1] + dd.getInt(2);
        if (totalLeft[dd.getString(0)][0] > 0) {
            totalLeft[dd.getString(0)][2] = totalLeft[dd.getString(0)][1] * 100 / totalLeft[dd.getString(0)][0];
        } else {
            totalLeft[dd.getString(0)][2] = 0;
        }
        QString prc = (t == 0 ? "0" : QString::number(dd.getInt(2) * 100 / t, 'f', 0));
        rows[row][col] = QString("%1").arg(t).rightJustified(4 + (4 - QString("%1").arg(t).length()))
                + dd.getString(2).rightJustified(5 + (5 - dd.getString(2).length()))
                + prc.rightJustified(3 + (3 - prc.length()));
    }

    rows.append(er);
    rows[rows.count() - 1][0] = "TOTAL";
    for (QMap<int, QList<int> >::const_iterator it = totalDown.begin(); it != totalDown.end(); it++) {
        rows[rows.count() - 1][it.key()] = QString("%1%2%3")
                .arg(it.value()[0], 4, 10, QChar(' '))
                .arg(it.value()[1], 5, 10, QChar(' '))
                .arg(it.value()[2], 3, 10, QChar(' '));
    }
    int a = 0, c = 0, p = 0;
    for (QMap<QString, QList<int> >::const_iterator it = totalLeft.begin(); it != totalLeft.end(); it++) {
        a += it.value()[0];
        c += it.value()[1];
        int row = catMap[it.key()];
        rows[row][13] = QString("%1").arg(it.value()[0]).rightJustified(5 + (5 - QString::number(it.value()[0]).length()))
                + QString::number(it.value()[1]).rightJustified(6 + (6 - QString::number(it.value()[1]).length()))
                + QString::number(it.value()[2]).rightJustified(3 + (3 - QString::number(it.value()[2]).length()));
    }
    if (a == 0) {
        p = 0;
    } else {
        p = c * 100 / a;
    }
    rows[rows.count() - 1][13] = QString("%1").arg(a).rightJustified(5 + (5 - QString::number(a).length()))
            + QString::number(c).rightJustified(6 + (6 - QString::number(c).length()))
            + QString::number(p).rightJustified(3 + (3 - QString::number(p).length()));
    rows.append(er);
    rows.append(er);
    rows[rows.count() - 1][0] = "ROMMING :" + rooming;
    rows.append(er);
    rows[rows.count() - 1][0] = "EXPLANATION OF CONTENT: 1ST - AVAILABLE ROOMS FOR PERIOD, 2ND - COUNT OF CHARGES OF ROOMING, 3RD - COUNT OF CHARGES OF ROOMING * 100 / AVAILABLE ROOMS";
}

void WReportsSetOld::roomArrangement(QList<QList<QVariant> > &rows, const QString &month)
{
    // category << B/O << B/B << Pax B/O << Pax B/B << Rooming B/O << Romming B/B
    QList<QVariant> er;
    er <<QVariant()
       << QVariant() << QVariant() << QVariant() << QVariant()
       << QVariant() << QVariant();
    DoubleDatabase dd;
    dd.exec("select f_description from f_room_classes");
    QMap<QString, int> catMap;
    while (dd.nextRow()) {
        rows.append(er);
        catMap[dd.getString(0)] = rows.count() - 1;
        rows[catMap[dd.getString(0)]][0] = dd.getString(0);
    }
    QString rooming = fPreferences.getDb(def_rooming_list).toString();
    if (fPreferences.getDb(def_penalty_list).toString().length() > 0) {
        rooming += "," + fPreferences.getDb(def_penalty_list).toString();
    }
    QString query;
    if (ui->chUseDateRange->isChecked()) {
        query = "select rc.f_description, r.f_arrangement, "
            "count(m.f_id), sum(r.f_man+r.f_woman+r.f_child), sum(m.f_amountamd) "
            "from m_register m "
            "inner join f_reservation r on r.f_invoice=m.f_inv "
            "left join f_room rm on rm.f_id=r.f_room "
            "left join f_room_classes rc on rc.f_id=rm.f_class "
            "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
            "and m.f_wdate between :date1 and :date2 "
            "and r.f_state in (1,2,3,6) and m.f_amountAmd "
            "group by 1, 2 ";
        query.replace(":date1", ui->deDate1->dateMySql());
        query.replace(":date2", ui->deDate2->dateMySql());
    } else {
        query = "select rc.f_description, r.f_arrangement, count(m.f_id), "
            "sum(r.f_man+r.f_woman+r.f_child), sum(m.f_amountamd) "
            "from m_register m "
            "inner join f_reservation r on r.f_invoice=m.f_inv "
            "left join f_room rm on rm.f_id=r.f_room "
            "left join f_room_classes rc on rc.f_id=rm.f_class "
            "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
            "and extract(year from m.f_wdate)=:year "
            "and extract(month from m.f_wdate) in (:monthlist)"
            "and r.f_state in (1,2,3,6) and m.f_amountAmd "
            "group by 1, 2 ";
        query.replace(":year", ui->cbYear->currentText());
        query.replace(":monthlist", month);
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int col = 1;
        switch (dd.getInt(1)) {
        case 1:
            break;
        case 2:
            col = 2;
            break;
        }
        int row = catMap[dd.getString(0)];
        rows[row][col] = dd.getInt(2);
        rows[row][col + 2] = dd.getInt(3);
        rows[row][col + 4] = dd.getDouble(4);
    }
}

void WReportsSetOld::roomArrangementByAge(QList<QList<QVariant> > &rows, const QString &month, QStringList &titles)
{
    // category << B/O << B/B << Pax B/O << Pax B/B << Rooming B/O << Romming B/B
    QList<QVariant> er;
    er <<QVariant()
       << QVariant() << QVariant() << QVariant() << QVariant() << QVariant() << QVariant()
          << QVariant() << QVariant() << QVariant() << QVariant() << QVariant() << QVariant()
       << QVariant() << QVariant() << QVariant() << QVariant() << QVariant() << QVariant();
    DoubleDatabase dd;
    if (ui->chUseDateRange->isChecked()) {
        dd.exec("select f_sql from serv_sql where f_name='roomArrangementByAge11'");
    } else {
        dd.exec("select f_sql from serv_sql where f_name='roomArrangementByAge1'");
    }

    if (dd.nextRow() == false) {
        message_error(tr("Report body missing"));
        return;
    }
    QString query = dd.getString("f_sql");
    QString rooming = fPreferences.getDb(def_rooming_list).toString();
    if (fPreferences.getDb(def_penalty_list).toString().length() > 0) {
        rooming += "," + fPreferences.getDb(def_penalty_list).toString();
    }
    if (ui->chUseDateRange->isChecked()) {
        query.replace(":rooming", rooming);
        query.replace(":date1", ui->deDate1->dateMySql());
        query.replace(":date2", ui->deDate2->dateMySql());
    } else {
        query.replace(":rooming", rooming);
        query.replace(":year", ui->cbYear->currentText());
        query.replace(":month", month);
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = rows.count();
        if (row == 0) {
            for (int i = 0; i < dd.columnCount(); i++) {
               titles[i] = dd.fColumnNameMap[i];
            }
        }
        rows.append(er);
        for (int i = 0; i < dd.columnCount(); i++) {
            rows[row][i] = dd.getValue(i);
        }
    }
}

void WReportsSetOld::nationality(QList<QList<QVariant> > &rows, const QString &month)
{
    // Nationality << guest << nights << free guests << free nights << Rooming << lenght of stay << avg room
    QList<QVariant> er;
    er <<QVariant()
       << QVariant() << QVariant() << QVariant() << QVariant()
       << QVariant() << QVariant() << QVariant();
    DoubleDatabase dd;
    dd.exec("select f_name from f_nationality order by 1");
    QMap<QString, int> natMap;
    while (dd.nextRow()) {
        rows.append(er);
        natMap[dd.getString(0)] = rows.count() - 1;
        rows[natMap[dd.getString(0)]][0] = dd.getString(0);
    }
    QString rooming = fPreferences.getDb(def_rooming_list).toString();
    if (fPreferences.getDb(def_penalty_list).toString().length() > 0) {
        rooming += "," + fPreferences.getDb(def_penalty_list).toString();
    }
    QString query;
    if (ui->chUseDateRange->isChecked()) {
        query = "select n.f_name, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv "
            "left join f_guests g on g.f_id=r.f_guest "
            "left join f_nationality n on n.f_short=g.f_nation "
            "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
            "and m.f_wdate between :date1 and :date2 "
            "and r.f_state in (1,2,3,6) and m.f_amountAmd>0.01 "
            "group by 1 ";
        query.replace(":date1", ui->deDate1->dateMySql());
        query.replace(":date2", ui->deDate2->dateMySql());
    } else {
        query = "select n.f_name, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv "
            "left join f_guests g on g.f_id=r.f_guest "
            "left join f_nationality n on n.f_short=g.f_nation "
            "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
            "and extract(year from m.f_wdate)=:year "
            "and extract(month from m.f_wdate) in (:monthlist) "
            "and r.f_state in (1,2,3,6) and m.f_amountAmd>0.01 "
            "group by 1 ";
        query.replace(":year", ui->cbYear->currentText());
        query.replace(":monthlist", month);
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = natMap[dd.getString(0)];
        rows[row][1] = dd.getInt(1);
        rows[row][2] = dd.getInt(2);
    }
    if (ui->chUseDateRange->isChecked()) {
        query = "select n.f_name, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv "
            "left join f_guests g on g.f_id=r.f_guest "
            "left join f_nationality n on n.f_short=g.f_nation "
            "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
            "and m.f_wdate between :date1 and :date2 "
            "and r.f_state in (1,2,3,6) and m.f_amountAmd <0.01 "
            "group by 1 ";
        query.replace(":year", ui->cbYear->currentText());
        query.replace(":monthlist", month);
    } else {
        query = "select n.f_name, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv "
            "left join f_guests g on g.f_id=r.f_guest "
            "left join f_nationality n on n.f_short=g.f_nation "
            "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
            "and extract(year from m.f_wdate)=:year "
            "and extract(month from m.f_wdate) in (:monthlist) "
            "and r.f_state in (1,2,3,6) and m.f_amountAmd <0.01 "
            "group by 1 ";
        query.replace(":year", ui->cbYear->currentText());
        query.replace(":monthlist", month);
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = natMap[dd.getString(0)];
        rows[row][3] = dd.getInt(1);
        rows[row][4] = dd.getInt(2);
    }
    if (ui->chUseDateRange->isChecked()) {
        query = "select n.f_name, sum(m.f_amountAmd) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_guests g on g.f_id=r.f_guest "
                "left join f_nationality n on n.f_short=g.f_nation "
                "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
                "and m.f_wdate between :date1 and :date2 "
                "and r.f_state in (1,2,3,6) "
                "group by 1";
        query.replace(":year", ui->cbYear->currentText());
        query.replace(":monthlist", month);
    } else {
        query = "select n.f_name, sum(m.f_amountAmd) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_guests g on g.f_id=r.f_guest "
                "left join f_nationality n on n.f_short=g.f_nation "
                "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
                "and extract(year from m.f_wdate)=:year "
                "and extract(month from m.f_wdate) in (:monthlist) and r.f_state in (1,2,3,6) "
                "group by 1";
        query.replace(":year", ui->cbYear->currentText());
        query.replace(":monthlist", month);
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = natMap[dd.getString(0)];
        rows[row][5] = dd.getDouble(1);
    }
    for (int i = rows.count() - 1; i > -1; i--) {
        if (rows[i][1].toInt() == 0
                && rows[i][2].toInt() == 0
                && rows[i][3].toInt() == 0
                && rows[i][4].toInt() == 0
                && zerodouble(rows[i][5].toDouble())) {
            rows.removeAt(i);
        } else {
            if (rows[i][2].toInt() + rows[i][4].toInt() > 0) {
                rows[i][6] = (rows[i][1].toDouble() + rows[i][3].toDouble()) / (rows[i][2].toDouble() + rows[i][4].toDouble());
            } else {
                rows[i][6] = 0;
            }
            if (rows[i][2].toInt() + rows[i][4].toInt() > 0) {
                rows[i][7] = rows[i][5].toDouble() / (rows[i][2].toDouble() + rows[i][4].toDouble());
            } else {
                rows[i][6] = 0;
            }
        }
    }
}

void WReportsSetOld::nationalityYearly(QList<QList<QVariant> > &rows, const QString &month)
{
    // Nationality << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11 << 12 << total
    QList<QVariant> er;
    er <<QVariant()
       << QVariant() << QVariant() << QVariant() << QVariant()
       << QVariant() << QVariant() << QVariant() << QVariant()
       << QVariant() << QVariant() << QVariant() << QVariant()
       << QVariant();
    DoubleDatabase dd;
    dd.exec("select f_name from f_nationality order by 1");
    QMap<QString, int> natMap;
    while (dd.nextRow()) {
        rows.append(er);
        natMap[dd.getString(0)] = rows.count() - 1;
        rows[natMap[dd.getString(0)]][0] = dd.getString(0);
    }
    QString rooming = fPreferences.getDb(def_rooming_list).toString();
    if (fPreferences.getDb(def_penalty_list).toString().length() > 0) {
        rooming += "," + fPreferences.getDb(def_penalty_list).toString();
    }
    QString query = "select n.f_name, extract(month from m.f_wdate), sum(m.f_amountAmd) "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv "
            "left join f_guests g on g.f_id=r.f_guest "
            "left join f_nationality n on n.f_short=g.f_nation "
            "where m.f_canceled=0 and m.f_finance=1 and m.f_itemCode in (" + rooming + ") "
            "and extract(month from m.f_wdate) in (:monthlist) "
            "and extract(year from m.f_wdate)=:year and r.f_state in(1,2,3,6) "
            "group by 1, 2";
    query.replace(":year", ui->cbYear->currentText());
    query.replace(":monthlist", month);
    dd.exec(query);
    while (dd.nextRow()) {
        int row = natMap[dd.getString(0)];
        int col = dd.getInt(1);
        rows[row][col] = dd.getDouble(2);
    }
    for (int i = rows.count() - 1; i > -1; i--) {
            if (rows[i][1].toInt() == 0
                    && zerodouble(rows[i][1].toDouble())
                    && zerodouble(rows[i][2].toDouble())
                    && zerodouble(rows[i][3].toDouble())
                    && zerodouble(rows[i][4].toDouble())
                    && zerodouble(rows[i][5].toDouble())
                    && zerodouble(rows[i][6].toDouble())
                    && zerodouble(rows[i][7].toDouble())
                    && zerodouble(rows[i][8].toDouble())
                    && zerodouble(rows[i][9].toDouble())
                    && zerodouble(rows[i][10].toDouble())
                    && zerodouble(rows[i][11].toDouble())
                    && zerodouble(rows[i][12].toDouble())) {
                rows.removeAt(i);
            } else {
                rows[i][13] = rows[i][1].toDouble()
                        + rows[i][2].toDouble()
                        + rows[i][3].toDouble()
                        + rows[i][4].toDouble()
                        + rows[i][5].toDouble()
                        + rows[i][6].toDouble()
                        + rows[i][7].toDouble()
                        + rows[i][8].toDouble()
                        + rows[i][9].toDouble()
                        + rows[i][10].toDouble()
                        + rows[i][11].toDouble()
                        + rows[i][12].toDouble();
            }
    }
}

void WReportsSetOld::cardex(QList<QList<QVariant> > &rows, const QString &month)
{
    QList<QVariant> er;
    // cardex << pax << nights << free pax << free nights << rooming << noshow << length of stay << avg room
    er << QVariant() << QVariant() << QVariant() << QVariant()
       << QVariant() << QVariant() << QVariant() << QVariant()
       << QVariant();
    DoubleDatabase dd;
    dd.exec("select f_name from f_cardex");
    QMap<QString, int> catMap;
    while (dd.nextRow()) {
        rows.append(er);
        catMap[dd.getString(0)] = rows.count() - 1;
        rows[catMap[dd.getString(0)]][0] = dd.getString(0);
    }
    QString rooming = fPreferences.getDb(def_rooming_list).toString();
    if (fPreferences.getDb(def_penalty_list).toString().length() > 0) {
        rooming += "," + fPreferences.getDb(def_penalty_list).toString();
    }
    QString query;
    if (ui->chUseDateRange->isChecked()) {
        query = "select cx.f_name, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
                "and m.f_wdate between :date1 and :date2 "
                "and m.f_paymentMode<> " + QString::number(PAYMENT_COMPLIMENTARY) + " "
                "and r.f_state in (1,2,3,6) and m.f_amountAmd>0.01 "
                "group by 1;";
        query.replace(":date1", ui->deDate1->dateMySql());
        query.replace(":date2", ui->deDate2->dateMySql());
    } else {
        query = "select cx.f_name, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv "
            "left join f_cardex cx on cx.f_cardex=r.f_cardex "
            "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
            "and extract(year from m.f_wdate)=:year and extract(month from m.f_wdate) in (:monthlist) "
            "and m.f_paymentMode<> " + QString::number(PAYMENT_COMPLIMENTARY) + " "
            "and r.f_state in (1,2,3,6) and m.f_amountAmd>0.01 "
            "group by 1;";
        query.replace(":monthlist", month);
        query.replace(":year", ui->cbYear->currentText());
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = catMap[dd.getString(0)];
        rows[row][1] = dd.getInt(1);
        rows[row][2] = dd.getDouble(2);
    }
    if (ui->chUseDateRange->isChecked()) {
        query = "select cx.f_name, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
                    "from m_register m "
                    "left join f_reservation r on r.f_invoice=m.f_inv "
                    "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                    "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
                    "and m.f_wdate between :date1 and :date2 "
                    "and m.f_paymentMode<> " + QString::number(PAYMENT_COMPLIMENTARY) + " "
                    "and r.f_state in (1,2,3,6) and m.f_amountAmd<0.01 "
                    "group by 1;";
        query.replace(":date1", ui->deDate1->dateMySql());
        query.replace(":date2", ui->deDate2->dateMySql());
    } else {
        query = "select cx.f_name, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
                    "from m_register m "
                    "left join f_reservation r on r.f_invoice=m.f_inv "
                    "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                    "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
                    "and extract(year from m.f_wdate)=:year and extract(month from m.f_wdate) in (:monthlist) "
                    "and m.f_paymentMode<> " + QString::number(PAYMENT_COMPLIMENTARY) + " "
                    "and r.f_state in (1,2,3,6) and m.f_amountAmd<0.01 "
                    "group by 1;";
        query.replace(":monthlist", month);
        query.replace(":year", ui->cbYear->currentText());
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = catMap[dd.getString(0)];
        rows[row][3] = dd.getInt(1);
        rows[row][4] = dd.getDouble(2);
    }

    if (ui->chUseDateRange->isChecked()) {
        query = "select cx.f_name, sum(m.f_amountAmd) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                "where m.f_itemCode in (" + fPreferences.getDb(def_rooming_list).toString() + ") and m.f_canceled=0 and m.f_finance=1 "
                "and m.f_wdate between :date1 and :date2 "
                "and r.f_state in (1,2,3,6) "
                "group by 1";
        query.replace(":date1", ui->deDate1->dateMySql());
        query.replace(":date2", ui->deDate2->dateMySql());
    } else {
        query = "select cx.f_name, sum(m.f_amountAmd) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                "where m.f_itemCode in (" + fPreferences.getDb(def_rooming_list).toString() + ") and m.f_canceled=0 and m.f_finance=1 "
                "and extract(year from m.f_wdate)=:year and extract(month from m.f_wdate) in (:monthlist) "
                "and r.f_state in (1,2,3,6) "
                "group by 1";
        query.replace(":monthlist", month);
        query.replace(":year", ui->cbYear->currentText());
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = catMap[dd.getString(0)];
        rows[row][5] = dd.getDouble(1);
    }

    if (ui->chUseDateRange->isChecked()) {
        query = "select cx.f_name, sum(m.f_amountAmd) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                "where m.f_itemCode in (" + fPreferences.getDb(def_penalty_list).toString() + ") and m.f_canceled=0 and m.f_finance=1 "
                "and m.f_wdate between :date1 and :date2 "
                "and r.f_state in (1,2,3,6) "
                "group by 1";
        query.replace(":date1", ui->deDate1->dateMySql());
        query.replace(":date2", ui->deDate2->dateMySql());
    } else {
        query = "select cx.f_name, sum(m.f_amountAmd) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                "where m.f_itemCode in (" + fPreferences.getDb(def_penalty_list).toString() + ") and m.f_canceled=0 and m.f_finance=1 "
                "and extract(year from m.f_wdate)=:year and extract(month from m.f_wdate) in (:monthlist) "
                "and r.f_state in (1,2,3,6) "
                "group by 1";
        query.replace(":monthlist", month);
        query.replace(":year", ui->cbYear->currentText());
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = catMap[dd.getString(0)];
        rows[row][6] = dd.getDouble(1);
    }

    for (int i = 0; i < rows.count(); i++) {
        if (rows[i][1].toDouble() + rows[i][3].toDouble() > 0.01) {
            rows[i][7] =  (rows[i][1].toDouble() + rows[i][3].toDouble()) / (rows[i][2].toDouble() + rows[i][4].toDouble());
        } else {
            rows[i][7] = 0;
        }
    }

    for (int i = 0; i < rows.count(); i++) {
        if (rows[i][2].toDouble() > 0) {
            rows[i][8] = rows[i][5].toDouble() / rows[i][2].toDouble();
        } else {
            rows[i][8] = 0;
        }
    }
    for (int i = rows.count() - 1; i > -1; i--) {
            if (rows[i][1].toInt() == 0
                    && zerodouble(rows[i][1].toDouble())
                    && zerodouble(rows[i][2].toDouble())
                    && zerodouble(rows[i][3].toDouble())
                    && zerodouble(rows[i][4].toDouble())
                    && zerodouble(rows[i][5].toDouble())) {
                rows.removeAt(i);
            }
    }
    rows.append(er);
    rows[rows.count() - 1][0] = QString("ROOMING: %1").arg(rooming);
}

void WReportsSetOld::marketsigment(QList<QList<QVariant> > &rows, const QString &month)
{
    QList<QVariant> er;
    // cardex << pax << nights << free pax << free nights << rooming << noshow << length of stay << avg room
    er << QVariant() << QVariant() << QVariant() << QVariant()
       << QVariant() << QVariant() << QVariant() << QVariant()
       << QVariant();
    DoubleDatabase dd;
    dd.exec("select f_group from f_cardex");
    QMap<QString, int> catMap;
    while (dd.nextRow()) {
        rows.append(er);
        catMap[dd.getString(0)] = rows.count() - 1;
        rows[catMap[dd.getString(0)]][0] = dd.getString(0);
    }
    QString rooming = fPreferences.getDb(def_rooming_list).toString();
    if (fPreferences.getDb(def_penalty_list).toString().length() > 0) {
        rooming += "," + fPreferences.getDb(def_penalty_list).toString();
    }
    QString query;
    if (ui->chUseDateRange->isChecked()) {
        query = "select cx.f_group, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
                "and m.f_wdate between :date1 and :date2 "
                "and m.f_paymentMode<> " + QString::number(PAYMENT_COMPLIMENTARY) + " "
                "and r.f_state in (1,2,3,6) and m.f_amountAmd>0.01 "
                "group by 1;";
        query.replace(":date1", ui->deDate1->dateMySql());
        query.replace(":date2", ui->deDate2->dateMySql());
    } else {
        query = "select cx.f_group, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv "
            "left join f_cardex cx on cx.f_cardex=r.f_cardex "
            "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
            "and extract(year from m.f_wdate)=:year and extract(month from m.f_wdate) in (:monthlist) "
            "and m.f_paymentMode<> " + QString::number(PAYMENT_COMPLIMENTARY) + " "
            "and r.f_state in (1,2,3,6) and m.f_amountAmd>0.01 "
            "group by 1;";
        query.replace(":monthlist", month);
        query.replace(":year", ui->cbYear->currentText());
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = catMap[dd.getString(0)];
        rows[row][1] = dd.getInt(1);
        rows[row][2] = dd.getDouble(2);
    }
    if (ui->chUseDateRange->isChecked()) {
        query = "select cx.f_group, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
                    "from m_register m "
                    "left join f_reservation r on r.f_invoice=m.f_inv "
                    "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                    "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
                    "and m.f_wdate between :date1 and :date2 "
                    "and m.f_paymentMode<> " + QString::number(PAYMENT_COMPLIMENTARY) + " "
                    "and r.f_state in (1,2,3,6) and m.f_amountAmd<0.01 "
                    "group by 1;";
        query.replace(":date1", ui->deDate1->dateMySql());
        query.replace(":date2", ui->deDate2->dateMySql());
    } else {
        query = "select cx.f_group, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
                    "from m_register m "
                    "left join f_reservation r on r.f_invoice=m.f_inv "
                    "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                    "where m.f_itemCode in (" + rooming + ") and m.f_canceled=0 and m.f_finance=1 "
                    "and extract(year from m.f_wdate)=:year and extract(month from m.f_wdate) in (:monthlist) "
                    "and m.f_paymentMode<> " + QString::number(PAYMENT_COMPLIMENTARY) + " "
                    "and r.f_state in (1,2,3,6) and m.f_amountAmd<0.01 "
                    "group by 1;";
        query.replace(":monthlist", month);
        query.replace(":year", ui->cbYear->currentText());
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = catMap[dd.getString(0)];
        rows[row][3] = dd.getInt(1);
        rows[row][4] = dd.getDouble(2);
    }

    if (ui->chUseDateRange->isChecked()) {
        query = "select cx.f_group, sum(m.f_amountAmd) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                "where m.f_itemCode in (" + fPreferences.getDb(def_rooming_list).toString() + ") and m.f_canceled=0 and m.f_finance=1 "
                "and m.f_wdate between :date1 and :date2 "
                "and r.f_state in (1,2,3,6) "
                "group by 1";
        query.replace(":date1", ui->deDate1->dateMySql());
        query.replace(":date2", ui->deDate2->dateMySql());
    } else {
        query = "select cx.f_group, sum(m.f_amountAmd) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                "where m.f_itemCode in (" + fPreferences.getDb(def_rooming_list).toString() + ") and m.f_canceled=0 and m.f_finance=1 "
                "and extract(year from m.f_wdate)=:year and extract(month from m.f_wdate) in (:monthlist) "
                "and r.f_state in (1,2,3,6) "
                "group by 1";
        query.replace(":monthlist", month);
        query.replace(":year", ui->cbYear->currentText());
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = catMap[dd.getString(0)];
        rows[row][5] = dd.getDouble(1);
    }

    if (ui->chUseDateRange->isChecked()) {
        query = "select cx.f_group, sum(m.f_amountAmd) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                "where m.f_itemCode in (" + fPreferences.getDb(def_penalty_list).toString() + ") and m.f_canceled=0 and m.f_finance=1 "
                "and m.f_wdate between :date1 and :date2 "
                "and r.f_state in (1,2,3,6) "
                "group by 1";
        query.replace(":date1", ui->deDate1->dateMySql());
        query.replace(":date2", ui->deDate2->dateMySql());
    } else {
        query = "select cx.f_group, sum(m.f_amountAmd) "
                "from m_register m "
                "left join f_reservation r on r.f_invoice=m.f_inv "
                "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                "where m.f_itemCode in (" + fPreferences.getDb(def_penalty_list).toString() + ") and m.f_canceled=0 and m.f_finance=1 "
                "and extract(year from m.f_wdate)=:year and extract(month from m.f_wdate) in (:monthlist) "
                "and r.f_state in (1,2,3,6) "
                "group by 1";
        query.replace(":monthlist", month);
        query.replace(":year", ui->cbYear->currentText());
    }
    dd.exec(query);
    while (dd.nextRow()) {
        int row = catMap[dd.getString(0)];
        rows[row][6] = dd.getDouble(1);
    }

    for (int i = 0; i < rows.count(); i++) {
        if (rows[i][1].toDouble() + rows[i][3].toDouble() > 0.01) {
            rows[i][7] =  (rows[i][1].toDouble() + rows[i][3].toDouble()) / (rows[i][2].toDouble() + rows[i][4].toDouble());
        } else {
            rows[i][7] = 0;
        }
    }

    for (int i = 0; i < rows.count(); i++) {
        if (rows[i][2].toDouble() > 0) {
            rows[i][8] = rows[i][5].toDouble() / rows[i][2].toDouble();
        } else {
            rows[i][8] = 0;
        }
    }
    for (int i = rows.count() - 1; i > -1; i--) {
            if (rows[i][1].toInt() == 0
                    && zerodouble(rows[i][1].toDouble())
                    && zerodouble(rows[i][2].toDouble())
                    && zerodouble(rows[i][3].toDouble())
                    && zerodouble(rows[i][4].toDouble())
                    && zerodouble(rows[i][5].toDouble())) {
                rows.removeAt(i);
            }
    }
    rows.append(er);
    rows[rows.count() - 1][0] = QString("ROOMING: %1").arg(rooming);
}

void WReportsSetOld::cardexCategory(QList<QList<QVariant> > &rows, const QString &month, QList<int> &widths, QStringList &titles, QList<int> &sumCols)
{
    widths << 140 << 80;
    titles << "CATEGORY"  << "TOTAL";
    DoubleDatabase dd;
    dd.exec("select f_short from f_room_classes");
    QMap<QString, int> mCatRows;
    while (dd.nextRow()) {
        mCatRows[dd.getString(0)] = rows.count();
        QList<QVariant> v;
        v.append(dd.getString(0));
        rows.append(v);
    }
    dd[":date1"] = ui->deDate1->date();
    dd[":date2"] = ui->deDate2->date();
    dd.exec("select rc.f_short, count(r.f_id) * (datediff(:date2, :date1) + 1)"
            "from f_room r "
            "inner join f_room_classes rc on rc.f_id=r.f_class "
            "group by 1");
    while (dd.nextRow()) {
        int row = mCatRows[dd.getString(0)];
        QList<QVariant> &v = rows[row];
        v.append(dd.getInt(1));
    }
    //Rooms by category and cardex group
    dd[":date1"] = ui->deDate1->date();
    dd[":date2"] = ui->deDate2->date();
    dd.exec("select cx.f_group, rc.f_short, count(m.f_id) "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv  "
            "left join f_room rm on rm.f_id=r.f_room "
            "left join f_room_classes rc on rc.f_id=rm.f_class "
            "left join f_cardex cx on cx.f_cardex=r.f_cardex "
            "where r.f_state=3 and m.f_itemCode in (" + fPreferences.getDb(def_rooming_list).toString() + ") "
            "and m.f_wdate between :date1 and :date2 "
            "and m.f_canceled=0 and m.f_finance=1 "
            "group by 1, 2 ");
    QMap<QString, int> carCol;
    while (dd.nextRow()) {
        QString cx = dd.getString(0);
        QString cat = dd.getString(1);
        if (!carCol.contains(cx)) {
            for (int i = 0; i < rows.count(); i++) {
                rows[i].append(QVariant());
            }
            carCol[cx] = widths.count();
            widths.append(80);
            titles.append(cx);
        }
        int row = mCatRows[cat];
        int col = carCol[cx];
        rows[row][col] = dd.getInt(2);
    }

    //Guests
    dd[":date1"] = ui->deDate1->date();
    dd[":date2"] = ui->deDate2->date();
    dd.exec("select rc.f_short, sum(r.f_man+r.f_woman+r.f_child), count(m.f_id) "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv "
            "left join f_room rm on rm.f_id=r.f_room "
            "left join f_room_classes rc on rc.f_id=rm.f_class "
            "where m.f_itemCode in (" + fPreferences.getDb(def_rooming_list).toString() + ") and m.f_canceled=0 and m.f_finance=1 "
            "and m.f_wdate between :date1 and :date2 "
            "and r.f_state=3 "
            "group by 1");
    widths.append(80);
    titles.append(tr("Guests"));
    widths.append(80);
    titles.append(tr("Nights"));
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < rows.count(); i++) {
            rows[i].append(QVariant());
        }
    }
    int colnights = widths.count() - 1;
    while (dd.nextRow()) {
        int row = mCatRows[dd.getString(0)];
        int col = rows.at(0).count() - 2;
        rows[row][col] = dd.getInt(1);
        rows[row][colnights] = dd.getInt(2);
    }
    //Percentage
    widths.append(80);
    titles.append(tr("Occ. %"));
    for (int i = 0; i < rows.count(); i++) {
        int col = widths.count() - 1;
        rows[i].append(QVariant());
        rows[i][col] = float_str(rows[i][col - 1].toDouble() / rows[i][1].toDouble() * 100);
    }

    //Rooming
    dd[":date1"] = ui->deDate1->date();
    dd[":date2"] = ui->deDate2->date();
    dd.exec("select rc.f_short, sum(m.f_amountAmd) "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv "
            "left join f_room rm on rm.f_id=r.f_room "
            "left join f_room_classes rc on rc.f_id=rm.f_class "
            "where m.f_itemCode in (" + fPreferences.getDb(def_rooming_list).toString() + ") and m.f_canceled=0 and m.f_finance=1 "
            "and m.f_wdate between :date1 and :date2 "
            "and r.f_state=3 "
            "group by 1");
    widths.append(80);
    widths.append(80);
    titles.append(tr("Rooming"));
    titles.append(tr("Avg. rooming"));
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < rows.count(); i++) {
            rows[i].append(QVariant());
        }
    }
    while (dd.nextRow()) {
        int row = mCatRows[dd.getString(0)];
        int col = widths.count() - 2;
        rows[row][col] = float_str(dd.getDouble(1), 2);
        if (rows[row][colnights].toInt() > 0) {
            rows[row][col + 1] = dd.getDouble(1) / rows[row][colnights].toInt();
        }
    }

    for (int i = 1; i < widths.count() - 1; i++) {
        sumCols.append(i);
    }
}

void WReportsSetOld::on_chYear_clicked(bool checked)
{
    ui->wCh->checkAll(checked);
}

void WReportsSetOld::on_btnHelp_clicked()
{
    QDir d;
    QString fh = qApp->applicationDirPath() + "/help.html";
    QString fn = d.tempPath() + "/help.html";
    QFile::copy(fh, fn);
    QDesktopServices::openUrl(QUrl(fn));
}
