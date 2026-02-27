#include "wtaxattack.h"
#include "ui_wtaxattack.h"
#include "waccinvoice.h"
#include "cachecardex.h"
#include "vauchers.h"
#include "cacheinvoiceitem.h"
#include "cachetaxmap.h"
#include "printtaxd.h"
#include <QMenu>

static const int col_invoice3 = 0;
static const int col_voucher = 4;
static const int col_amount = 6;
static const int col_checkbox = 7;
static const int col_item = 8;
static const int col_vat = 9;

WTaxAttack::WTaxAttack(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WTaxAttack)
{
    ui->setupUi(this);
    ui->leCardex->setSelector(this, cache(cid_cardex), ui->leCardexName);
    Utils::tableSetColumnWidths(ui->tbl, ui->tbl->columnCount(), 80, 120, 300, 200, 80, 200, 100, 100, 0, 0);
    for (int i = 0; i < ui->tbl->columnCount(); i++) {
        ui->tblt->setColumnWidth(i, ui->tbl->columnWidth(i));
    }
    on_btnRefresh_clicked();
}

WTaxAttack::~WTaxAttack()
{
    delete ui;
}

void WTaxAttack::setup()
{
    setupTabTextAndIcon(tr("Print tax of invoices"), ":/images/canon.png");
}

void WTaxAttack::checkboxClicked(bool v)
{
    Q_UNUSED(v);
    countAmounts();
}

void WTaxAttack::checkAll()
{
    setCheckboxChecked(true);
}

void WTaxAttack::uncheckAll()
{
    setCheckboxChecked(false);
}

void WTaxAttack::on_btnRefresh_clicked()
{
    DoubleDatabase dd;
    dd[":f_state"] = RESERVE_CHECKOUT;
    dd[":date1"] = ui->deStart->date();
    dd[":date2"] = ui->deEnd->date();
    QString where;
    if (!ui->leCardex->isEmpty()) {
        where += " and r.f_cardex=" + ap(ui->leCardex->text());
    }
    dd.exec("select m.f_inv, r.f_enddate, m.f_guest, c.f_name, m.f_id, m.f_finalName, m.f_amountamd, '', "
            "m.f_itemcode, m.f_vatmode "
            "from m_register m "
            "left join f_reservation r on r.f_invoice=m.f_inv "
            "left join f_cardex c on c.f_cardex=r.f_cardex "
            "where r.f_state=:f_state and m.f_fiscal=0 and m.f_canceled=0 "
            "and r.f_enddate between :date1 and :date2 and m.f_finance=1 "
            "and m.f_amountamd > 0.001 and m.f_source <>'RV' " + where);
    Utils::fillTableWithData(ui->tbl, dd.fDbRows);
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        ui->tbl->setRowHidden(i, false);
        connect(ui->tbl->addCheckBox(i, col_checkbox), SIGNAL(clicked(bool)), this, SLOT(checkboxClicked(bool)));
    }
    QStringList rowsCount;
    rowsCount.append(QString::number(ui->tbl->rowCount()));
    ui->tblt->setVerticalHeaderLabels(rowsCount);
    countAmounts();
}

void WTaxAttack::countAmounts()
{
    double total = 0, sel = 0;
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        if (ui->tbl->isRowHidden(i)) {
            continue;
        }
        total += ui->tbl->toDouble(i, col_amount);
        if (ui->tbl->checkBox(i, col_checkbox)->isChecked()) {
            sel += ui->tbl->toDouble(i, col_amount);
        }
    }
    ui->tblt->setItemWithValue(0, col_amount, total);
    ui->tblt->setItemWithValue(0, col_checkbox, sel);
}

void WTaxAttack::setCheckboxChecked(bool v)
{
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        ui->tbl->checkBox(i, col_checkbox)->setChecked(v);
    }
    countAmounts();
}

void WTaxAttack::on_tbl_doubleClicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    WAccInvoice::openInvoice(ui->tbl->toString(index.row(), col_invoice3));
}

void WTaxAttack::on_leSearch_textChanged(const QString &arg1)
{
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        for (int j = 0; j < ui->tbl->columnCount(); j++) {
            if (ui->tbl->toString(i, j).contains(arg1, Qt::CaseInsensitive)) {
                ui->tbl->setRowHidden(i, false);
                goto CONT;
            } else {
                ui->tbl->setRowHidden(i, true);
            }
        }
    CONT:
        continue;
    }
    countAmounts();
}

void WTaxAttack::on_leInvoice_returnPressed()
{
    ui->leSearch->clear();
    QStringList invoices = ui->leInvoice->text().split(",", Qt::SkipEmptyParts);
    if (invoices.isEmpty()) {
        invoices.append("");
    }
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        for (const QString &s : invoices) {
            if (ui->tbl->toString(i, 0).contains(s, Qt::CaseInsensitive)) {
                goto CONT;
            }
        }
        ui->tbl->setRowHidden(i, true);
    CONT:
        continue;
    }
    countAmounts();
}

void WTaxAttack::on_tbl_customContextMenuRequested(const QPoint &pos)
{
    auto *m = new QMenu(this);
    m->addAction(tr("Check all"), this, SLOT(checkAll()));
    m->addAction(tr("Uncheck all"), this, SLOT(uncheckAll()));
    m->exec(ui->tbl->mapToGlobal(pos));
}

void WTaxAttack::on_btnPrintTax_clicked()
{
    QString inv;
    PrintTaxD *pt = nullptr;
    int totalrows = 0;
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        if (!ui->tbl->checkBox(i, col_checkbox)->isChecked()) {
            continue;
        }
        totalrows ++;
        if (inv.isEmpty()) {
            inv = ui->tbl->toString(i, 0);
            pt = new PrintTaxD(fPreferences.getDb(def_default_fiscal_machine).toInt(), this);
        }
        if (ui->tbl->toString(i, 0) != inv) {
            pt->build();
            pt->exec2();
            delete pt;
            pt = new PrintTaxD(fPreferences.getDb(def_default_fiscal_machine).toInt(), this);
        }
        CacheInvoiceItem c;
        if (!c.get(ui->tbl->toString(i, col_item))) {
            message_error(tr("Error in tax print. c == 0, case 2."));
            continue;
        }
        if (c.fVaucher() == VAUCHER_POINT_SALE_N) {
            CacheTaxMap ci;
            if (!ci.get(c.fCode())) {
                message_error(tr("Tax department undefined for ") + c.fName());
                return;
            }
            DoubleDatabase fDD;
            fDD[":f_header"] = ui->tbl->toString(i, col_voucher);
            fDD[":f_state"] = DISH_STATE_READY;
            fDD.exec("select d.f_id, d.f_am, d.f_adgt, od.f_qty, od.f_price "
                     "from o_dish od "
                     "inner join r_dish d on d.f_id=od.f_dish "
                     "where od.f_header=:f_header and od.f_state=:f_state "
                     "and (od.f_complex=0 or (od.f_complex>0 and od.f_complexId>0)) ");
            while (fDD.nextRow()) {
                QString vatReception = c.fVatDept();
                if (!c.fVatReception().isEmpty()) {
                    vatReception = c.fVatReception();
                }
                pt->fDept.append(ui->tbl->toInt(i, col_vat) == VAT_INCLUDED ? ci.fName() : c.fNoVatDept());
                pt->fRecList.append(ui->tbl->toString(i, col_voucher));
                pt->fCodeList.append(fDD.getString(0));
                pt->fNameList.append(fDD.getString(1));
                pt->fPriceList.append(fDD.getString(4));
                pt->fQtyList.append(fDD.getString(3));
                pt->fAdgCode.append(fDD.getString(2));
                pt->fTaxNameList.append(fDD.getString(1));
            }
        } else {
            CacheTaxMap ci;
            if (!ci.get(c.fCode())) {
                message_error(tr("Tax department undefined for ") + c.fName());
                return;
            }
            pt->fDept.append(ui->tbl->toInt(i, col_vat) == VAT_INCLUDED ? ci.fName() : c.fNoVatDept());
            pt->fRecList.append(ui->tbl->toString(i, col_vat));
            pt->fCodeList.append(c.fCode());
            pt->fNameList.append(c.fTaxName());
            pt->fPriceList.append(QString::number(ui->tbl->toDouble(i, col_amount), 'f', 2));
            pt->fQtyList.append("1");
            pt->fAdgCode.append(c.fAdgt());
            pt->fTaxNameList.append(c.fTaxName());
        }
    }
    if (pt) {
        pt->build();
        pt->exec2();
        delete pt;
    }
    if (totalrows == 0) {
        message_info(tr("Nothing were printed"));
    }
    on_btnRefresh_clicked();
}
