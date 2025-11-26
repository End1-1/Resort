#include "fexpectedarrivals2.h"
#include "ui_fexpectedarrivals2.h"
#include "wreportgrid.h"
#include "wreservation.h"
#include "cachecardex.h"

FExpectedArrivals2::FExpectedArrivals2(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FExpectedArrivals2)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Expected arrivals/depatures"), ":/images/arrival.png");
    ui->leCardexCode->setSelector(this, cache(cid_cardex), ui->leCardexName);
    connect(ui->wd, &WDate2::changed, [this]() {
        apply(fReportGrid);
    });
    connect(fReportGrid, SIGNAL(doubleClickOnRow(QList<QVariant>)), this, SLOT(doubleClickOnRow(QList<QVariant>)));
    GOExpextedArrivals g("Expected arrivals/depatures");
    Q_UNUSED(g);
}

FExpectedArrivals2::~FExpectedArrivals2()
{
    delete ui;
}

void FExpectedArrivals2::apply(WReportGrid *rg)
{
    if (ui->rbEntry->isChecked()) {
        printArrival(rg);
    } else if (ui->rbDeparture->isChecked()) {
        printDeparture(rg);
    } else {
        printBoth(rg);
    }
}

QWidget *FExpectedArrivals2::firstElement()
{
    return ui->wd->fw();
}

QWidget *FExpectedArrivals2::lastElement()
{
    return ui->wd->lw();
}

QString FExpectedArrivals2::reportTitle()
{
    return QString("%1 %2 From %3 To %4")
           .arg("Expected")
           .arg(type())
           .arg(ui->wd->ds1())
           .arg(ui->wd->ds2());
}

GOWidget *FExpectedArrivals2::gridOptionWidget()
{
    return new GOExpextedArrivals("Expected arrivals/depatures");
}

void FExpectedArrivals2::printArrival(WReportGrid *rg)
{
    rg->fModel->clearData();
    QList<int> cols;
    cols << 100 //id
         << 100 // room
         << 300 // guest
         << 30 // man
         << 30 // female
         << 30 // child
         << 50 // nigths
         << 150 // cardex
         << 80 // advance
         << 0 // cardex rate
         << 80 // rate
         << 30 // status
         << 100 //departure
         << 200 //remarks
         ;
    QStringList titles ;
    titles << tr("Voucher")
           << tr("Room")
           << tr("Guest")
           << tr("M")
           << tr("F")
           << tr("C")
           << tr("Nights")
           << tr("Cardex")
           << tr("Advance")
           << tr("CardexRate")
           << tr("Room rate")
           << tr("RS")
           << tr("Departure")
           << tr("Remarks");
    rg->fModel->clearColumns();
    QList<QVariant> emptyRow;
    for (int i = 0; i < cols.count(); i++) {
        rg->fModel->setColumn(cols.at(i), "", titles.at(i));
        emptyRow << QVariant();
    }
    QString where;
    if (ui->rbEntry->isChecked()) {
        where = QString ("where %1 between %2 and %3 %4")
                .arg("r.f_startDate")
                .arg(ui->wd->ds1())
                .arg(ui->wd->ds2())
                .arg(" and r.f_state = 2 ");
    }
    // - cdx.cardex_rate
    if (ui->leCardexCode->text().length() > 0) {
        where += " and r.f_cardex='" + ui->leCardexCode->text() + "' ";
    }
    QString query = "select r.f_startDate, r.f_id, rm.f_short, concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName), "
                    "r.f_man, r.f_woman, r.f_child, datediff(r.f_endDate, r.f_startDate), cx.f_name, adv.total, '-', ";
    if (ui->chWithoutRates->isChecked()) {
        query += "'0',";
    } else {
        query += "r.f_pricePerNight, ";
    }
    query += "left(s.f_en, 1), r.f_endDate, replace(r.f_remarks, '\n', ' ') as f_remarks "
             "from f_reservation r "
             "left join f_room rm on rm.f_id=r.f_room "
             "left join f_guests g on g.f_id=r.f_guest "
             "left join f_cardex cx on cx.f_cardex=r.f_cardex "
             "left join f_reservation_status s on s.f_id=r.f_reserveState "
             "left join (select a.f_res, abs(sum(f_amountAmd*f_sign)) as total "
             "from m_register a where f_canceled=0 and f_finance=1 group by 1) adv on adv.f_res=r.f_id "
             + where +
             "order by " + GOExpextedArrivals::value("sort order", "Expected arrivals/depatures").toString();
    ;
    QList<int> entryRows;
    QList<int> mainRows;
    QList<int> addRows;
    QList<int> totalRows;
    QList<int> rowsHeights;
    int count = 0;
    int guestCount = 0;
    double totalAdv = 0;
    double totalPosted = 0;
    int r = 0;
    QDate entryDate;
    DoubleDatabase fDD;
    fDD.exec(query);
    QList<QVariant> row;
    while (fDD.nextRow()) {
        if (entryDate != fDD.getDate(0)) {
            if (count > 0) {
                row = emptyRow;
                row[0] = tr("Total");
                row[1] = count;
                row[8] = totalAdv;
                row[10] = totalPosted;
                rg->fModel->appendRow(row);
                totalRows << r;
                r++;
                count = 0;
                totalAdv = 0;
                totalPosted = 0;
                rg->fModel->appendRow(emptyRow);
                entryRows << r;
                r++;
            }
            row = emptyRow;
            entryDate = fDD.getDate(0);
            row[0] = (tr("Entry date: ") + entryDate.toString(def_date_format));
            rg->fModel->appendRow(row);
            entryRows << r;
            r++;
        }
        totalAdv += fDD.getDouble(9);
        totalPosted += fDD.getDouble(11);
        guestCount += (fDD.getInt(4) + fDD.getInt(5) + fDD.getInt(6));
        row = emptyRow;
        for (int i = 1; i < 15; i++) {
            row[i - 1] = fDD.getValue(i);
        }
        rg->fModel->appendRow(row);
        mainRows << r;
        r++;
        rg->fModel->appendRow(emptyRow);
        entryRows << r;
        rowsHeights << r;
        r++;
        count ++;
    }
    if (count > 0) {
        row = emptyRow;
        row[0] = tr("Total");
        row[1] = count;
        row[2] = tr("Total guests count") + ": " + QString::number(guestCount);
        row[8] = totalAdv;
        row[10] = totalPosted;
        rg->fModel->appendRow(row);
        totalRows << r;
        r++;
        count = 0;
        totalAdv = 0;
        totalPosted = 0;
        rg->fModel->appendRow(emptyRow);
        r++;
    }
    // rg->fModel->setSqlQuery("");
    rg->fModel->applyFinal(rg, true);
    foreach (int i, entryRows) {
        rg->fTableView->setSpan(i, 0, 1, 14);
    }
    foreach (int i, addRows) {
        rg->fTableView->setSpan(i, 0, 1, 14);
    }
    foreach (int i, totalRows) {
        rg->fTableView->setSpan(i, 2, 1, 6);
    }
    for (int i = 0, rowCount = rg->fModel->rowCount(); i < rowCount; i++) {
        rg->fTableView->setRowHeight(i, rg->fTableView->verticalHeader()->defaultSectionSize());
    }
    foreach (int i, rowsHeights) {
        rg->fTableView->setRowHeight(i, 5);
    }
    for (int i = 0, count = rg->fModel->rowCount(); i < count; i++) {
        if (rg->fModel->data(i, 0).toString().isEmpty()) {
            //            rg->fModel->setBackgroundColor(i, COLOR_DARK_ROW);
        }
    }
    if (rg->fModel->rowCount() == 0) {
        if (ui->rbEntry->isChecked() && ui->rbDeparture->isChecked()) {
            message_info(tr("There are no arrivals and departures"));
            return;
        }
        if (ui->rbEntry->isChecked()) {
            message_info(tr("There are no arrivals"));
        }
        if (ui->rbDeparture->isChecked()) {
            message_info(tr("There are no departures"));
        }
    }
}

void FExpectedArrivals2::printDeparture(WReportGrid *rg)
{
    rg->fModel->clearData();
    QList<int> cols;
    cols << 100 //id
         << 100 // room
         << 300 // guest
         << 30 // man
         << 30 // female
         << 30 // child
         << 50 // nigths
         << 150 // cardex
         << 80 // advance
         << 0 // cardex rate
         << 80 // rate
         << 30 // status
         << 100 //departure
         << 250 //remarks
         ;
    QStringList titles ;
    titles << tr("Voucher")
           << tr("Room")
           << tr("Guest")
           << tr("M")
           << tr("F")
           << tr("C")
           << tr("Nights")
           << tr("Cardex")
           << tr("Advance")
           << tr("CardexRate")
           << tr("Balance")
           << tr("RS")
           << tr("Departure")
           << tr("Remarks");
    rg->fModel->clearColumns();
    QList<QVariant> emptyRow;
    for (int i = 0; i < cols.count(); i++) {
        rg->fModel->setColumn(cols.at(i), "", titles.at(i));
        emptyRow << QVariant();
    }
    QString where = QString ("where %1 between %2 and %3 and r.f_state=%4 ")
                    .arg("r.f_endDate")
                    .arg(ui->wd->ds1())
                    .arg(ui->wd->ds2())
                    .arg(RESERVE_CHECKIN);
    if (ui->leCardexCode->text().length() > 0) {
        where += " and r.f_cardex='" + ui->leCardexCode->text() + "' ";
    }
    // - cdx.cardex_rate
    QString query = "select r.f_startDate, r.f_id, rm.f_short, "
                    "concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName), "
                    "r.f_man, r.f_woman, r.f_child, datediff(r.f_endDate, r.f_startDate), cx.f_name, adv.total, '-', "
                    "bl.total, "
                    "left(s.f_en, 1), r.f_endDate, replace(r.f_remarks, '\n', ' ') as f_remarks "
                    "from f_reservation r "
                    "inner join f_room rm on rm.f_id=r.f_room "
                    "inner join f_guests g on g.f_id=r.f_guest "
                    "left join f_cardex cx on cx.f_cardex=r.f_cardex "
                    "inner join f_reservation_status s on s.f_id=r.f_reserveState "
                    "left join (select a.f_res, sum(f_amountAmd) as total from m_register a where f_source='AV' and f_finance=1 and f_canceled=0 group by 1) adv on adv.f_res=r.f_id "
                    "left join (select f_inv, sum(f_amountAmd*f_sign) as total from m_register where f_canceled=0 and f_finance=1 group by 1) bl on bl.f_inv=r.f_invoice "
                    + where +
                    "order by r.f_endDate, r.f_room "
                    ;
    QList<int> entryRows;
    QList<int> mainRows;
    QList<int> addRows;
    QList<int> totalRows;
    QList<int> rowsHeights;
    int count = 0;
    int guestCount = 0;
    double totalAdv = 0;
    double totalPosted = 0;
    int r = 0;
    QDate entryDate;
    DoubleDatabase fDD;
    fDD.exec(query);
    QList<QVariant> row;
    while (fDD.nextRow()) {
        if (entryDate != fDD.getDate(13)) {
            if (count > 0) {
                row = emptyRow;
                row[0] = tr("Total");
                row[1] = count;
                row[8] = totalAdv;
                row[10] = totalPosted;
                rg->fModel->appendRow(row);
                totalRows << r;
                r++;
                count = 0;
                totalAdv = 0;
                totalPosted = 0;
                rg->fModel->appendRow(emptyRow);
                entryRows << r;
                r++;
            }
            row = emptyRow;
            entryDate = fDD.getDate(13);
            row[0] = tr("Departure date: ") + entryDate.toString(def_date_format);
            rg->fModel->appendRow(row);
            entryRows << r;
            r++;
        }
        totalAdv += fDD.getDouble(9);
        totalPosted += fDD.getDouble(11);
        guestCount += (fDD.getInt(4) + fDD.getInt(5) + fDD.getInt(6));
        row = emptyRow;
        for (int i = 1; i < 15; i++) {
            row[i - 1] = fDD.getValue(i);
        }
        rg->fModel->appendRow(row);
        mainRows << r;
        r++;
        rg->fModel->appendRow(emptyRow);
        entryRows << r;
        rowsHeights << r;
        r++;
        count ++;
    }
    if (count > 0) {
        row = emptyRow;
        row[0] = tr("Total");
        row[1] = count;
        row[2] = tr("Total guests count") + ": " + QString::number(guestCount);
        row[8] = totalAdv;
        row[10] = totalPosted;
        rg->fModel->appendRow(row);
        totalRows << r;
        r++;
        count = 0;
        totalAdv = 0;
        totalPosted = 0;
        rg->fModel->appendRow(emptyRow);
        r++;
    } else {
        message_info(tr("There are no departures"));
    }
    rg->fModel->applyFinal(rg, true);
    foreach (int i, entryRows) {
        rg->fTableView->setSpan(i, 0, 1, 14);
    }
    foreach (int i, addRows) {
        rg->fTableView->setSpan(i, 0, 1, 14);
    }
    foreach (int i, totalRows) {
        rg->fTableView->setSpan(i, 2, 1, 6);
    }
    for (int i = 0, rowCount = rg->fModel->rowCount(); i < rowCount; i++) {
        rg->fTableView->setRowHeight(i, rg->fTableView->verticalHeader()->defaultSectionSize());
    }
    foreach (int i, rowsHeights) {
        rg->fTableView->setRowHeight(i, 5);
    }
}

void FExpectedArrivals2::printBoth(WReportGrid *rg)
{
    rg->fModel->clearData();
    QList<int> cols;
    cols << 100 //id
         << 100 // room
         << 300 // guest
         << 30 // man
         << 30 // female
         << 30 // child
         << 50 // nigths
         << 150 // cardex
         << 80 // advance
         << 0 // cardex rate
         << 80 // rate
         << 30 // status
         << 100 //departure
         << 250 //remarks
         ;
    QStringList titles ;
    titles << tr("Voucher")
           << tr("Room")
           << tr("Guest")
           << tr("M")
           << tr("F")
           << tr("C")
           << tr("Nights")
           << tr("Cardex")
           << tr("Advance")
           << tr("CardexRate")
           << tr("Balance")
           << tr("RS")
           << tr("Departure")
           << tr("Remarks");
    rg->fModel->clearColumns();
    QList<QVariant> emptyRow;
    for (int i = 0; i < cols.count(); i++) {
        rg->fModel->setColumn(cols.at(i), "", titles.at(i));
        emptyRow << QVariant();
    }
    QString where = QString ("where %1 between %2 and %3 %4")
                    .arg("r.f_startDate")
                    .arg(ui->wd->ds1())
                    .arg(ui->wd->ds2())
                    .arg(" and r.f_state = 2 ");
    // - cdx.cardex_rate
    if (ui->leCardexCode->text().length() > 0) {
        where += " and r.f_cardex='" + ui->leCardexCode->text() + "' ";
    }
    QString query = "select r.f_startDate, r.f_id, rm.f_short, concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName), "
                    "r.f_man, r.f_woman, r.f_child, datediff(r.f_endDate, r.f_startDate), cx.f_name, adv.total, '-', ";
    if (ui->chWithoutRates->isChecked()) {
        query += "'0',";
    } else {
        query += "r.f_pricePerNight, ";
    }
    query += "left(s.f_en, 1), r.f_endDate, replace(r.f_remarks, '\n', ' ') as f_remarks "
             "from f_reservation r "
             "left join f_room rm on rm.f_id=r.f_room "
             "left join f_guests g on g.f_id=r.f_guest "
             "left join f_cardex cx on cx.f_cardex=r.f_cardex "
             "left join f_reservation_status s on s.f_id=r.f_reserveState "
             "left join (select a.f_res, abs(sum(f_amountAmd*f_sign)) as total "
             "from m_register a where f_canceled=0 and f_finance=1 group by 1) adv on adv.f_res=r.f_id "
             + where +
             "order by " + GOExpextedArrivals::value("sort order", "Expected arrivals/depatures").toString();
    ;
    QList<int> entryRows;
    QList<int> mainRows;
    QList<int> addRows;
    QList<int> totalRows;
    QList<int> rowsHeights;
    int count = 0;
    int guestCount = 0;
    double totalAdv = 0;
    double totalPosted = 0;
    int r = 0;
    QDate entryDate;
    DoubleDatabase fDD;
    fDD.exec(query);
    QList<QVariant> row;
    while (fDD.nextRow()) {
        if (entryDate != fDD.getDate(0)) {
            if (count > 0) {
                row = emptyRow;
                row[0] = tr("Total");
                row[1] = count;
                row[8] = totalAdv;
                row[10] = totalPosted;
                rg->fModel->appendRow(row);
                totalRows << r;
                r++;
                count = 0;
                totalAdv = 0;
                totalPosted = 0;
                rg->fModel->appendRow(emptyRow);
                entryRows << r;
                r++;
            }
            row = emptyRow;
            entryDate = fDD.getDate(0);
            row[0] = (tr("Entry date: ") + entryDate.toString(def_date_format));
            rg->fModel->appendRow(row);
            entryRows << r;
            r++;
        }
        totalAdv += fDD.getDouble(9);
        totalPosted += fDD.getDouble(11);
        guestCount += (fDD.getInt(4) + fDD.getInt(5) + fDD.getInt(6));
        row = emptyRow;
        for (int i = 1; i < 15; i++) {
            row[i - 1] = fDD.getValue(i);
        }
        rg->fModel->appendRow(row);
        mainRows << r;
        r++;
        rg->fModel->appendRow(emptyRow);
        entryRows << r;
        rowsHeights << r;
        r++;
        count ++;
    }
    // DEPARTURES
    where = QString ("where %1 between %2 and %3 and r.f_state=%4 ")
            .arg("r.f_endDate")
            .arg(ui->wd->ds1())
            .arg(ui->wd->ds2())
            .arg(RESERVE_CHECKIN);
    if (ui->leCardexCode->text().length() > 0) {
        where += " and r.f_cardex='" + ui->leCardexCode->text() + "' ";
    }
    // - cdx.cardex_rate
    query = "select r.f_startDate, r.f_id, rm.f_short, "
            "concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName), "
            "r.f_man, r.f_woman, r.f_child, datediff(r.f_endDate, r.f_startDate), cx.f_name, adv.total, '-', "
            "bl.total, "
            "left(s.f_en, 1), r.f_endDate, replace(r.f_remarks, '\n', ' ') as f_remarks "
            "from f_reservation r "
            "inner join f_room rm on rm.f_id=r.f_room "
            "inner join f_guests g on g.f_id=r.f_guest "
            "left join f_cardex cx on cx.f_cardex=r.f_cardex "
            "inner join f_reservation_status s on s.f_id=r.f_reserveState "
            "left join (select a.f_res, sum(f_amountAmd) as total from m_register a where f_source='AV' and f_finance=1 and f_canceled=0 group by 1) adv on adv.f_res=r.f_id "
            "left join (select f_inv, sum(f_amountAmd*f_sign) as total from m_register where f_canceled=0 and f_finance=1 group by 1) bl on bl.f_inv=r.f_invoice "
            + where +
            "order by r.f_endDate, r.f_room "
            ;
    entryDate = QDate::fromString("01/01/2000", "dd/MM/yyyy");
    fDD.exec(query);
    while (fDD.nextRow()) {
        if (entryDate != fDD.getDate(13)) {
            if (count > 0) {
                row = emptyRow;
                row[0] = tr("Total");
                row[1] = count;
                row[8] = totalAdv;
                row[10] = totalPosted;
                rg->fModel->appendRow(row);
                totalRows << r;
                r++;
                count = 0;
                totalAdv = 0;
                totalPosted = 0;
                rg->fModel->appendRow(emptyRow);
                entryRows << r;
                r++;
            }
            row = emptyRow;
            entryDate = fDD.getDate(13);
            row[0] = tr("Departure date: ") + entryDate.toString(def_date_format);
            rg->fModel->appendRow(row);
            entryRows << r;
            r++;
        }
        totalAdv += fDD.getDouble(9);
        totalPosted += fDD.getDouble(11);
        guestCount += (fDD.getInt(4) + fDD.getInt(5) + fDD.getInt(6));
        row = emptyRow;
        for (int i = 1; i < 15; i++) {
            row[i - 1] = fDD.getValue(i);
        }
        rg->fModel->appendRow(row);
        mainRows << r;
        r++;
        rg->fModel->appendRow(emptyRow);
        entryRows << r;
        rowsHeights << r;
        r++;
        count ++;
    }
    if (count > 0) {
        row = emptyRow;
        row[0] = tr("Total");
        row[1] = count;
        row[2] = tr("Total guests count") + ": " + QString::number(guestCount);
        row[8] = totalAdv;
        row[10] = totalPosted;
        rg->fModel->appendRow(row);
        totalRows << r;
        r++;
        count = 0;
        totalAdv = 0;
        totalPosted = 0;
        rg->fModel->appendRow(emptyRow);
        r++;
    } else {
        message_info(tr("There are no arrivals or departures"));
    }
    // rg->fModel->setSqlQuery("");
    rg->fModel->applyFinal(rg, true);
    foreach (int i, entryRows) {
        rg->fTableView->setSpan(i, 0, 1, 14);
    }
    foreach (int i, addRows) {
        rg->fTableView->setSpan(i, 0, 1, 14);
    }
    foreach (int i, totalRows) {
        rg->fTableView->setSpan(i, 2, 1, 6);
    }
    for (int i = 0, rowCount = rg->fModel->rowCount(); i < rowCount; i++) {
        rg->fTableView->setRowHeight(i, rg->fTableView->verticalHeader()->defaultSectionSize());
    }
    foreach (int i, rowsHeights) {
        rg->fTableView->setRowHeight(i, 5);
    }
    for (int i = 0, count = rg->fModel->rowCount(); i < count; i++) {
        if (rg->fModel->data(i, 0).toString().isEmpty()) {
            //  rg->fModel->setBackgroundColor(i, COLOR_DARK_ROW);
        }
    }
}

QString FExpectedArrivals2::type()
{
    QString type;
    if (ui->rbEntry->isChecked()) {
        type = tr("Arrivals");
    } else if (ui->rbDeparture->isChecked()) {
        type = tr("Departures");
    } else {
        type = tr("Arrivals and departures");
    }
    return type;
}

QString FExpectedArrivals2::type2()
{
    QString type;
    if (ui->rbEntry->isChecked()) {
        type = tr("Entry");
    } else if (ui->rbDeparture->isChecked()) {
        type = tr("Departure");
    } else {
        type = tr("Arrivals and departures");
    }
    return type;
}

void FExpectedArrivals2::doubleClickOnRow(const QList<QVariant> &v)
{
    if (v.count() == 0) {
        return;
    }
    if (v.at(0).toString().isEmpty()) {
        return;
    }
    WReservation::openReserveWindows(v.at(0).toString());
}
