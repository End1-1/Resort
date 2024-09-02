#include "finhousedetailbalance.h"
#include "ui_finhousedetailbalance.h"
#include "wreportgrid.h"
#include "winvoice.h"
#include "vauchers.h"

FInhouseDetailBalance::FInhouseDetailBalance(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FInhouseDetailBalance)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("In House Detailed Balance"), ":/images/invoice.png");
    connect(fReportGrid, &WReportGrid::doubleClickOnRow, [this](const QList<QVariant> &val){
        if (val.count() == 0) {
            return;
        }
        if (val.at(0).toString().isEmpty()) {
            return;
        }
        openInvoiceWithId(val.at(0).toString());
    });
    connect(ui->wd, SIGNAL(changed()), this, SLOT(refresh()));
}

FInhouseDetailBalance::~FInhouseDetailBalance()
{
    delete ui;
}

QString FInhouseDetailBalance::reportTitle()
{
    return QString("%1 %2 - %3")
            .arg(tr("In House Detailed Balance"))
            .arg(ui->wd->dss1())
            .arg(ui->wd->dss2());
}

QWidget *FInhouseDetailBalance::firstElement()
{
    return ui->wd->fw();
}

QWidget *FInhouseDetailBalance::lastElement()
{
    return ui->wd->lw();
}

void FInhouseDetailBalance::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(90, "", tr("Invoice"))
            .setColumn(40, "", tr("Room"))
            .setColumn(200, "", tr("Guest"))
            .setColumn(200, "", tr("Description"))
            .setColumn(80, "", tr("Debit"))
            .setColumn(80, "", tr("Credit"))
            .setColumn(140, "", tr("Payment"))
            .setColumn(150, "", tr("Comment"))
            .setColumn(100, "", tr("Tax"));
    QString query = "select r.f_invoice, r.f_room, g.guest, m.f_finalName, if (m.f_sign=1, m.f_amountAmd, 0), if (m.f_sign=-1, m.f_amountAmd, 0), pm.f_" + def_lang + ", "
            "m.f_paymentComment, m.f_fiscal "
            "from m_register m "
            "inner join f_reservation r on m.f_inv=r.f_invoice "
            "left join f_room rm on rm.f_id=r.f_room "
            "left join f_payment_type pm on pm.f_id=m.f_paymentMode "
            "left join guests g on r.f_guest=g.f_id "
            "where m.f_wdate between :date1 and :date2 and m.f_canceled=0 and ((f_finance=1 and f_source<>'AV') or (f_finance=0 and f_source='AT')) "
            "order by rm.f_building, r.f_room, m.f_inv, m.f_wdate ";
    query.replace(":date1", ui->wd->ds1());
    query.replace(":date2", ui->wd->ds2());
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
    query = "select m.f_inv, m.f_room, m.f_guest, m.f_finalName, 0, m.f_amountAmd, pm.f_" + def_lang + ", "
            "m.f_paymentComment, m.f_fiscal "
            "from m_register m "
            "left join f_payment_type pm on pm.f_id=m.f_paymentMode "
            "where f_source='AV' and m.f_wdate=:date and m.f_canceled=0 and m.f_finance=1 ";
    query.replace(":date", ui->wd->ds2());
    DoubleDatabase dd;
    dd.exec(query);
    while (dd.nextRow()) {
        QList<QVariant> row;
        for (int i = 0; i < dd.columnCount(); i++) {
            row << dd.getValue(i);
        }
        rg->fModel->appendRow(row);
    }
    QList<int> col;
    col << 4 << 5;
    QList<double> vals;
    rg->fModel->sumOfColumns(col, vals);
    rg->setTblTotalData(col, vals);
    rg->fModel->insertSubTotals(0, col);
    QString curr;
    for (int i = 0; i < rg->fModel->rowCount(); i++) {
        if (i == 0) {
            curr = rg->fModel->data(i, 0).toString();
            continue;
        }
        if (rg->fModel->data(i, 0).toString() == curr) {
            rg->fModel->setData(i, 0, "");
            rg->fModel->setData(i, 1, "");
            rg->fModel->setData(i, 2, "");
        } else {
            curr = rg->fModel->data(i, 0).toString();
        }
    }
    for (int i = 0; i < rg->fModel->rowCount(); i++) {
        if (rg->fModel->stringData(i, 6) == tr("CITY LEDGER")) {
            rg->fModel->setData(i, 3, tr("CHECKOUT"));
        }
    }
    if (fPreferences.getDb(def_append_tax_inhouse_detailed).toBool()) {
        QList<QVariant> emptyRow;
        for (int i = 0; i < rg->fModel->columnCount(); i++) {
            emptyRow.append(QVariant());
        }
        query = "select m.f_wdate, m.f_id, m.f_finalname, m.f_inv, t.f_tax, t.f_amountcash, t.f_amountcard, t.f_amountprepaid "
                "from m_tax_history t "
                "inner join m_register m on m.f_id=t.f_vaucher "
                "inner join f_reservation r on r.f_invoice=m.f_inv "
                "where t.f_wdate between :d1 and :d2 and m.f_wdate<:d1 and r.f_state=:f_state ";
        dd[":d1"] = ui->wd->d1();
        dd[":d2"] = ui->wd->d2();
        dd[":f_state"] = RESERVE_CHECKIN;
        dd.exec(query);
        while (dd.nextRow()) {
            //search invoice row
            bool ss = false; //Search subtotal
            for (int i = 0; i < rg->fModel->rowCount(); i++) {
                if (ss) {
                    if (rg->fModel->data(i, 0).toString().contains(tr("SUBTOTAL"), Qt::CaseInsensitive)) {
                        QList<QVariant> newRow = emptyRow;
                        newRow[0] = dd.getDate("f_wdate");
                        newRow[1] = tr("-TAX-");
                        newRow[2] = dd.getString("f_id");
                        newRow[3] = dd.getString("f_finalname");
                        newRow[4] = dd.getDouble("f_amountcash");
                        newRow[5] = dd.getDouble("f_amountcard");
                        newRow[6] = dd.getDouble("f_amountprepaid");
                        QString comment;
                        if (newRow[4].toDouble() > 0.01) {
                            comment += tr("Cash ");
                        }
                        if (newRow[5].toDouble() > 0.01) {
                            comment += tr("Card ");
                        }
                        if (newRow[6].toDouble() > 0.01) {
                            comment += tr("Prepaid ");
                        }
                        newRow[7] = comment;
                        newRow[8] = dd.getInt("f_tax");
                        rg->fModel->insertRow(i, newRow);
                        break;
                    }
                    continue;
                }
                if (rg->fModel->data(i, 0).toString() == dd.getString("f_inv")) {
                    ss = true;
                }
            }
            //search subtotal rowa
        }
    }
}

void FInhouseDetailBalance::refresh()
{
    apply(fReportGrid);
}
