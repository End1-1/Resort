#include "fdailymovement.h"
#include "ui_fdailymovement.h"
#include "cacheinvoiceitem.h"
#include "wreportgrid.h"
#include "vauchers.h"

FDailyMovement::FDailyMovement(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FDailyMovement)
{
    ui->setupUi(this);
    fReportGrid->addToolBarButton(":/images/invoice.png", tr("Open invoice"), SLOT(openInvoice()), this)
            ->setFocusPolicy(Qt::ClickFocus);

    QString query = "select u.f_username, m.f_rdate, m.f_time, m.f_room, m.f_itemCode, "
            "m.f_id, left(m.f_dc, 1), m.f_finalName, p.f_en, m.f_paymentComment, "
            "m.f_amountAmd, m.f_amountVat, m.f_amountAmd / m.f_amountUsd, m.f_guest, m.f_source, "
            "uc.f_username, m.f_id, sdm.f_queue "
            "from m_register m "
            "left join users u on u.f_id=m.f_user "
            "left join f_invoice_item p on p.f_id=m.f_paymentMode "
            "left join serv_daily_movement sdm on sdm.f_itemCode=m.f_itemCode "
            "left join users uc on uc.f_id=m.f_cancelUser "
            "where m.f_wdate=:f_wdate and m.f_canceled=:f_canceled :where "
            "order by sdm.f_queue, m.f_time, m.f_source "
           ;

    fReportGrid->fTableView->verticalHeader()->setDefaultSectionSize(20);
    fReportGrid->fStaticQuery = query;
    fReportGrid->addFilterWidget(this);
    fReportGrid->setupTabTextAndIcon(tr("Daily movement"), ":/images/graph.png");
    fDockItem = new DWSelectorInvoiceItem(this);
    fDockItem->fGroup = 0;
    fDockItem->configure();
    fDockItem->setSelector(ui->leSale);
    connect(fDockItem, SIGNAL(invoiceItem(CI_InvoiceItem*)), this, SLOT(invoiceItem(CI_InvoiceItem*)));
}

FDailyMovement::~FDailyMovement()
{
    delete ui;
}

void FDailyMovement::apply(WReportGrid *rg)
{
    QString where;
    if (ui->leSale->fHiddenText.length() > 0) {
        where += " and m.f_itemCode in (" + ui->leSale->fHiddenText + ") ";
    }
    rg->fModel->clearColumns();
    rg->fModel->
            setColumn(30,"", tr("Op")) //1
            .setColumn(80, "", tr("Date")) //2
            .setColumn(60, "", tr("Time")) //3
            .setColumn(80, "", tr("Room")) //4
            .setColumn(0, "", tr("Sal")) //5
            .setColumn(100, "", tr("Code")) //6
            .setColumn(40, "", tr("*")) //7
            .setColumn(300, "", tr("Remark")) //8
            .setColumn(100, "", tr("Payment")) //9
            .setColumn(100, "", tr("Type")) //10
            .setColumn(100, "", tr("Amount")) //11
            .setColumn(80, "", tr("VAT")) //12
            .setColumn(80, "", tr("USD")) //13
            .setColumn(300, "", tr("Guest")) //14
            .setColumn(0, "", tr("Voucher")) //15
            .setColumn((ui->chCanceled->isChecked() ? 100 : 0), "", tr("Cancel by")) //16
            .setColumn(0, "", tr("RecId")) //17
            .setColumn(0, "", tr("Queue")) //18
            ;
    QString query = fReportGrid->fStaticQuery;
    query = query.replace(":f_wdate", ui->deStart->dateMySql())
            .replace(":f_canceled", (ui->chCanceled->isChecked() ? "1" : "0"))
            .replace(":where", where);

    fReportGrid->fModel->setSqlQuery(query);
    fReportGrid->fModel->apply();
    int i = 0;
    while (i < fReportGrid->fModel->rowCount() - 1) {
        if (fReportGrid->fModel->data(i, 4).toInt() == 30) {
            if (fReportGrid->fModel->data(i, 8).toString() == "CITY LEDGER"
                    && (fReportGrid->fModel->data(i, 14).toString() == "RV"
                        || fReportGrid->fModel->data(i, 14).toString() == "AV")) {
                fReportGrid->fModel->removeRow(i);
                continue;
            }
        }
        i++;
    }

    QList<int> cols;
    cols << 10 << 11 << 12;
    rg->fModel->insertSubTotals(17, cols);
    double cash = 0, card = 0, bank = 0;
    for (int i = 0; i < rg->fModel->rowCount(); i++) {
        switch (rg->fModel->data(i, 4).toInt()) {
        case IT_ADVANCE:
        case IT_PAYMENT:
            if (rg->fModel->data(i, 8).toString() == "CASH") {
                cash += rg->fModel->data(i, 10, Qt::EditRole).toDouble();
            } else if (rg->fModel->data(i, 8).toString().contains("CARD", Qt::CaseInsensitive)) {
                card += rg->fModel->data(i, 10, Qt::EditRole).toDouble();
            } else if (rg->fModel->data(i, 8).toString().contains("BANK", Qt::CaseInsensitive)) {
                bank += rg->fModel->data(i, 10, Qt::EditRole).toDouble();
            }
        }

        if (rg->fModel->data(i, 0).toString().contains("Subtotal", Qt::CaseInsensitive)) {
            int itemCode = rg->fModel->data(i - 1, 4).toInt();
            if (itemCode == IT_ADVANCE) {
                itemCode = IT_PAYMENT;
            }
            CI_InvoiceItem *ii = CacheInvoiceItem::instance()->get(itemCode);
            rg->fModel->setData(i, 0, QString("%1 %2").arg(tr("Subtotal")).arg(ii->fName));
            if (itemCode == IT_PAYMENT) {
                QList<QVariant> emptyRow;
                         //  1      2     3     4     5    6    7     8      9    10    11    12    13    14    15    16    17    18
                emptyRow << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "";
                emptyRow[0] = QString("%1").arg(tr("TOTAL CASH"));
                emptyRow[10] = cash;
                rg->fModel->insertRow(i, emptyRow);
                rg->fTableView->setSpan(i, 0, 1, 10);
                i++;
                emptyRow[0] = QString("%1").arg(tr("TOTAL CARD"));
                emptyRow[10] = card;
                rg->fModel->insertRow(i, emptyRow);
                rg->fTableView->setSpan(i, 0, 1, 10);
                i++;
                emptyRow[0] = QString("%1").arg(tr("TOTAL BANK"));
                emptyRow[10] = bank;
                rg->fModel->insertRow(i, emptyRow);
                rg->fTableView->setSpan(i, 0, 1, 10);
                i++;
            }
        }
    }
//    i = 0;
//    int count = 0;
//    double totalAMD = 0 ;
//    double totalVAT = 0;
//    double totalUSD = 0;
//    QString totalTitle = "";
//    QString totalVaucher = "";

//    while (i < fReportGrid->fModel->rowCount()) {
//        if (i == 0) {
//            count ++;
//            totalAMD += fReportGrid->fModel->data(i, 10, Qt::EditRole).toDouble();
//            totalVAT += fReportGrid->fModel->data(i, 11, Qt::EditRole).toDouble();
//            totalUSD += fReportGrid->fModel->data(i, 12, Qt::EditRole).toDouble();
//            totalTitle = fReportGrid->fModel->data(i, 4, Qt::EditRole).toString();
//            totalVaucher = fReportGrid->fModel->data(i, 14, Qt::EditRole).toString();
//            i++;
//            continue;
//        }
//        if (totalTitle != fReportGrid->fModel->data(i, 4).toString()
//                || totalVaucher != fReportGrid->fModel->data(i, 14).toString()) {
//            QString temp = fReportGrid->fModel->data(i, 4).toString();
//            QString temp2 = fReportGrid->fModel->data(i, 14).toString();
//            QList<QVariant> row = emptyRow;
//            CI_InvoiceItem *ci = CacheInvoiceItem::instance()->get(totalTitle);
//            if (ci) {
//                totalTitle = ci->fName;
//            }
//            row[0] = QString("%1 %2").arg(tr("Subtotal")).arg(totalTitle);
//            row[10] = totalAMD;
//            row[11] = totalVAT;
//            row[12] = totalUSD;
//            fReportGrid->fModel->insertRow(i, row);
//            fReportGrid->fTableView->setSpan(i, 0, 1, 10);
//            i++;
//            row = emptyRow;
//            fReportGrid->fModel->insertRow(i, row);
//            fReportGrid->fTableView->setSpan(i, 0, 1, 14);
//            i++;
//            totalTitle = temp;
//            totalVaucher = temp2;
//            count = 0;
//            totalAMD = 0;
//            totalVAT = 0;
//            totalUSD = 0;
//            /* new row with new title */
//            row = emptyRow;
//            ci = CacheInvoiceItem::instance()->get(totalTitle);
//            if (ci) {
//                row[0] = QString("%2").arg(ci->fName);
//            } else {
//                row[0] = QString("%2").arg(totalTitle);
//            }
//            fReportGrid->fModel->insertRow(i, row);
//            fReportGrid->fTableView->setSpan(i, 0, 1, 14);
//            i++;
//        }
//        count++;
//        totalAMD += fReportGrid->fModel->data(i, 10, Qt::EditRole).toDouble();
//        totalVAT += fReportGrid->fModel->data(i, 11, Qt::EditRole).toDouble();
//        totalUSD += fReportGrid->fModel->data(i, 12, Qt::EditRole).toDouble();
//        i++;
//    }
//    if (count++) {
//        QList<QVariant> row = emptyRow;
//        CI_InvoiceItem *ci = CacheInvoiceItem::instance()->get(totalTitle);
//        if (ci) {
//            totalTitle = ci->fName;
//        }
//        row[0] = QString("%1 %2").arg(tr("Subtotal")).arg(totalTitle);
//        row[10] = totalAMD;
//        row[12] = totalUSD;
//        fReportGrid->fModel->insertRow(fReportGrid->fModel->rowCount(), row);
//        fReportGrid->fTableView->setSpan(fReportGrid->fModel->rowCount() - 1, 0, 1, 10);
//    }
//    processPayments(emptyRow);
}

QWidget *FDailyMovement::firstElement()
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
                row[10] = totalAMD;
                row[11] = totalVAT;
                row[12] = totalUSD;
                fReportGrid->fModel->insertRow(i, row);
                fReportGrid->fTableView->setSpan(i, 0, 1, 10);
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
        totalAMD += fReportGrid->fModel->data(i, 10, Qt::EditRole).toDouble();
        totalVAT += fReportGrid->fModel->data(i, 11, Qt::EditRole).toDouble();
        totalUSD += fReportGrid->fModel->data(i, 12, Qt::EditRole).toDouble();
    }
    if (cnt > 0) {
        QList<QVariant> row = emptyRow;
        row[10] = totalAMD;
        row[11] = totalVAT;
        row[12] = totalUSD;
        cnt++;
        fReportGrid->fModel->insertRow(cnt, row);
        fReportGrid->fTableView->setSpan(cnt, 0, 1, 10);
        cnt++;
        row = emptyRow;
        fReportGrid->fModel->insertRow(cnt, row);
        fReportGrid->fTableView->setSpan(cnt, 0, 1, 14);
    }
}

void FDailyMovement::invoiceItem(CI_InvoiceItem *c)
{
    dockResponse<CI_InvoiceItem, CacheInvoiceItem>(ui->leSale, c);
}

void FDailyMovement::openInvoice()
{
    QList<QVariant> out;
    if (fReportGrid->fillRowValuesOut(out) < 0) {
        message_info_tr("Nothing was selected");
        return;
    }
    QString inv = out.at(16).toString();
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
