#include "fdailymovement.h"
#include "ui_fdailymovement.h"
#include "cacheinvoiceitem.h"
#include "wreportgrid.h"
#include "cachepaymentmode.h"
#include "paymentmode.h"
#include "vauchers.h"
#include <QHeaderView>

FDailyMovement::FDailyMovement(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FDailyMovement)
{
    ui->setupUi(this);
    QFont f(qApp->font());
    f.setPointSize(f.pointSize() - 1);
    setFont(f);
    fReportGrid->setFont(f);
    fReportGrid->addToolBarButton(":/images/invoice.png", tr("Open invoice"), SLOT(openInvoice()), this)
            ->setFocusPolicy(Qt::ClickFocus);

    QString query = "select u.f_username, m.f_rdate, m.f_time, m.f_room, m.f_itemCode, "
            "m.f_id, m.f_inv, left(m.f_dc, 1), concat(m.f_finalName, ' ', coalesce(m.f_remarks, '')), p.f_en, m.f_paymentComment, "
            "m.f_amountAmd, m.f_amountVat, m.f_amountAmd / m.f_amountUsd as f_amountUsd, m.f_guest, m.f_source, "
            "uc.f_username as f_username2, m.f_id as f_id2, m.f_paymentMode, m.f_canceled "
            "from m_register m "
            "left join users u on u.f_id=m.f_user "
            "left join f_payment_type p on p.f_id=m.f_paymentMode "
            "left join users uc on uc.f_id=m.f_cancelUser "
            "where m.f_wdate=:f_wdate and m.f_canceled=:f_canceled :where "
            "order by :order "
           ;

    fReportGrid->fTableView->verticalHeader()->setDefaultSectionSize(20);
    fReportGrid->fStaticQuery = query;
    fReportGrid->addFilterWidget(this);
    fReportGrid->setupTabTextAndIcon(tr("Daily movement"), ":/images/graph.png");
    ui->leSale->setSelector(this, cache(cid_invoice_item), ui->leSale);

    GODaily g("Daily movement");
    Q_UNUSED(g)
}

FDailyMovement::~FDailyMovement()
{
    delete ui;
}

void FDailyMovement::apply(WReportGrid *rg)
{
    rg->fModel->fDD.fDbRows.clear();
    rg->fModel->clearColumns();
    rg->fModel->
            setColumn(30,"", tr("Op")) //1
            .setColumn(80, "", tr("Date")) //2
            .setColumn(60, "", tr("Time")) //3
            .setColumn(70, "", tr("Room")) //4
            .setColumn(0, "", tr("Sal")) //5
            .setColumn(80, "", tr("Code")) //6
            .setColumn(80, "", tr("Invoice")) //7
            .setColumn(20, "", tr("*")) //8
            .setColumn(250, "", tr("Remark")) //9
            .setColumn(120, "", tr("Payment")) //10
            .setColumn(110, "", tr("Type")) //11
            .setColumn(100, "", tr("Amount")) //12
            .setColumn(80, "", tr("VAT")) //13
            .setColumn(80, "", tr("USD")) //14
            .setColumn(250, "", tr("Guest")) //15
            .setColumn(0, "", tr("Voucher")) //16
            .setColumn((ui->chCanceled->isChecked() ? 100 : 0), "", tr("Cancel by")) //17
            .setColumn(0, "", tr("RecId")) //18
            .setColumn(0, "", tr("Payment mode")) // 19
            .setColumn(0, "", tr("Canceled")) //20
            ;
    QStringList items = fPreferences.getDb(def_daily_movement_items).toString().split(";", Qt::SkipEmptyParts);
    if (ui->leSale->fHiddenText.length() > 0) {
        processItems(ui->leSale->fHiddenText, ui->chCanceled->isChecked());
    } else {
        foreach (QString s, items) {
            processItems(s, ui->chCanceled->isChecked());
        }
    }
    if (fPreferences.getDb(def_daily_report_print_canceled).toInt() == 1 && !ui->chCanceled->isChecked()) {
        if (ui->leSale->fHiddenText.length() > 0) {
            processItems(ui->leSale->fHiddenText, true);
        } else {
            foreach (QString s, items) {
                processItems(s, true);
            }
        }
    }
    rg->fModel->apply(rg);
    Report r;
    if (fReportGrid->fReportOptions.contains(fReportGrid->fGridClassName)) {
        r = fReportGrid->fReportOptions[fReportGrid->fGridClassName];
    } else {
        r.fFontName = font().family();
        r.fFontSize = font().pointSize();
    }
    r.fFontBold = true;
    for (int i = 0; i < rg->fModel->rowCount(); i++) {
        if (rg->fModel->data(i, 0).toString().contains(tr("SUBTOTAL FOR")) ||
                rg->fModel->data(i, 1).toString().isEmpty()) {
            rg->fTableView->setSpan(i, 0, 1, 11);
        } else if (rg->fModel->data(i, 0).toString().isEmpty()) {
            rg->fTableView->setSpan(i, 0, 1, 19);
        }
    }
    rg->fModel->removeRow(rg->fModel->rowCount() - 1);
    for (int i = 0; i < rg->fModel->rowCount(); i++) {
        if (rg->fTableView->columnSpan(i, 0) > 1 && !rg->fModel->data(i, 0).toString().isEmpty()) {
            QFont f(r.fFontName, r.fFontSize);
            f.setBold(r.fFontBold);
            rg->fModel->setFont(i, 0, f);
            rg->fModel->setFont(i, 11, f);
            rg->fModel->setFont(i, 12, f);
            rg->fModel->setFont(i, 13, f);
        }
    }
    for (int i = 0; i < rg->fModel->rowCount(); i++) {
        if (rg->fModel->data(i, 19).toInt() == 1) {
            rg->fModel->setBackgroundColor(i, Qt::gray);
        }
    }
}

QWidget *FDailyMovement::firstElement()
{
    return ui->deStart;
}

QWidget *FDailyMovement::lastElement()
{
    return ui->deStart;
}

QString FDailyMovement::reportTitle()
{
    QString result = QString("%1 %2")
            .arg(tr("Daily movement"))
            .arg(ui->deStart->text());
    if (ui->chCanceled->isChecked()) {
        result += " [" + tr("Canceled") + "]";
    }
    return result;
}

GOWidget *FDailyMovement::gridOptionWidget()
{
    return new GODaily("Daily movement");
}

void FDailyMovement::open()
{
    WReportGrid *rg = addTab<WReportGrid>();
    FDailyMovement *dm = new FDailyMovement(rg);
    dm->apply(rg);
}

void FDailyMovement::setupTab()
{
    setupTabTextAndIcon(QString("%1 %2")
                        .arg(tr("Daily movement"))
                        .arg(ui->deStart->date().toString(def_date_format)),
                        ":/images/graph.png");
}

void FDailyMovement::processPayments(QList<QVariant> &emptyRow)
{
    QString mode;
    double totalAMD = 0;
    double totalVAT = 0;
    double totalUSD = 0;
    int cnt = 0;
    for (int i = 0, count = fReportGrid->fModel->rowCount(); i < count; i++) {
        if (fReportGrid->fModel->data(i, 4).toInt() != 30) {
            continue;
        }
        if (mode.isEmpty()) {
            mode = fReportGrid->fModel->data(i, 9).toString();
        } else {
            if (mode != fReportGrid->fModel->data(i, 9).toString()) {
                QList<QVariant> row = emptyRow;
                row[11] = totalAMD;
                row[12] = totalVAT;
                row[13] = totalUSD;
                fReportGrid->fModel->insertRow(i, row);
                fReportGrid->fTableView->setSpan(i, 0, 1, 11);
                i++;
                row = emptyRow;
                fReportGrid->fModel->insertRow(i, row);
                fReportGrid->fTableView->setSpan(i, 0, 1, 14);
                i++;
                mode = fReportGrid->fModel->data(i, 9).toString();
                totalAMD = 0;
                totalUSD = 0;
                totalVAT = 0;
            }
        }
        cnt = i;
        totalAMD += fReportGrid->fModel->data(i, 11, Qt::EditRole).toDouble();
        totalVAT += fReportGrid->fModel->data(i, 12, Qt::EditRole).toDouble();
        totalUSD += fReportGrid->fModel->data(i, 13, Qt::EditRole).toDouble();
    }
    if (cnt > 0) {
        QList<QVariant> row = emptyRow;
        row[11] = totalAMD;
        row[12] = totalVAT;
        row[13] = totalUSD;
        cnt++;
        fReportGrid->fModel->insertRow(cnt, row);
        fReportGrid->fTableView->setSpan(cnt, 0, 1, 11);
        cnt++;
        row = emptyRow;
        fReportGrid->fModel->insertRow(cnt, row);
        fReportGrid->fTableView->setSpan(cnt, 0, 1, 14);
    }
}

void FDailyMovement::processItems(QString items, bool canceled)
{
    DoubleDatabase fDD;
    bool totalRowSeparate = items.contains("+");
    if (totalRowSeparate) {
        items.remove("+");
    }
    
    QString query = fReportGrid->fStaticQuery;
    query.replace(":f_wdate", ui->deStart->dateMySql());
    query.replace(":f_canceled", canceled ? "1" : "0");
    query.replace(":where", QString(" and f_itemCode in (%1)").arg(items));
    query.replace(":order", GODaily::value("sort order", "Daily movement").toString());
    fDD.exec(query);
    if (fDD.rowCount() == 0) {
        return;
    }
    QList<QVariant> emptyRow;
           //.  1      2     3     4     5    6    7     8      9    10    11    12    13    14    15    16    17    18    19     20
    emptyRow << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "";
    QList<QList<QVariant> > rows;
    QMap<int, double> payment;
    for (int i = 0; i < fDD.rowCount(); i++) {
        if (fDD.getValue(i, "f_source").toString() == VAUCHER_RECEIPT_N) {
            if (fDD.getValue(i, "f_paymentMode").toInt() == PAYMENT_CL) {
                continue;
            }
        }
        QList<QVariant> oneRow;
        for (int j = 0, count = fDD.columnCount(); j < count; j++) {
            oneRow << fDD.getValue(i, j);
        }
        payment[fDD.getValue(i, "f_paymentMode").toInt()] = payment[fDD.getValue(i, "f_paymentMode").toInt()] + fDD.getValue(i, "f_amountAmd").toDouble();
        payment[-1] = payment[-1] + fDD.getValue(i, "f_amountAmd").toDouble();
        payment[-2] = payment[-2] + fDD.getValue(i, "f_amountVat").toDouble();
        payment[-3] = payment[-3] + fDD.getValue(i, "f_amountUsd").toDouble();
        rows << oneRow;
    }
    QList<QVariant> trr = emptyRow;
    trr[11] = payment[-1];
    trr[12] = payment[-2];
    trr[13] = payment[-3];
    QStringList itemCode = items.split(",", Qt::SkipEmptyParts);
    QString names = tr("SUBTOTAL FOR ");
    foreach (QString s, itemCode) {
        CacheInvoiceItem ci;
        if (ci.get(s)) {
            names += ci.fName() + ",";
        }
    }
    names.remove(names.length() - 1, 1);
    if (totalRowSeparate) {
        names += " " + float_str(payment[-1]) ;
        trr[0] = names;
        if (fPreferences.getDb(def_daily_movement_total_side).toInt() == 0) {
            rows << trr;
        } else {
            rows.insert(0, trr);
        }
        trr[11] = "";
        trr[12] = "";
        trr[13] = "";
        for (QMap<int, double>::const_iterator it = payment.begin(); it != payment.end(); it++) {
            if (it.key() < 0) {
                continue;
            }
            CachePaymentMode ci;
            if (ci.get(it.key())) {
                names = QString("%1: %2").arg(ci.fName()).arg(float_str(it.value()));
            } else {
                names = QString("%1: %2").arg("UNKNOWN").arg(float_str(it.value()));
            }
            trr[0] = names;
            if (fPreferences.getDb(def_daily_movement_total_side).toInt() == 0) {
                rows << trr;
            } else {
                rows.insert(0, trr);
            }
        }
    } else {
        names += " " + float_str(payment[-1]) + " [";
        for (QMap<int, double>::const_iterator it = payment.begin(); it != payment.end(); it++) {
            if (it.key() < 0) {
                continue;
            }
            CachePaymentMode ci;
            if (ci.get(it.key())) {
                names += QString("%1: %2,").arg(ci.fName()).arg(float_str(it.value()));
            } else {
                names += QString("%1: %2,").arg("UNKNOWN").arg(float_str(it.value()));
            }
        }
        names.remove(names.length() - 1, 1);
        names += "]";
        trr[0] = names;
        if (fPreferences.getDb(def_daily_movement_total_side).toInt() == 0) {
            rows << trr;
        } else {
            rows.insert(0, trr);
        }
    }
    rows << emptyRow;
    fReportGrid->fModel->fDD.fDbRows << rows;
}

void FDailyMovement::openInvoice()
{
    QList<QVariant> out;
    if (fReportGrid->fillRowValuesOut(out) < 0) {
        message_info(tr("Nothing was selected"));
        return;
    }
    QString inv = out.at(17).toString();
    if (inv.isEmpty()) {
        return;
    }
    openVaucherInvoice(inv);
}

void FDailyMovement::on_btnPrevDate_clicked()
{
    ui->deStart->setDate(ui->deStart->date().addDays(-1));
    apply(fReportGrid);
}

void FDailyMovement::on_btnNextDate_clicked()
{
    ui->deStart->setDate(ui->deStart->date().addDays(1));
    apply(fReportGrid);
}
