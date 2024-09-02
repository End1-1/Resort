#include "wquickcheckout.h"
#include "ui_wquickcheckout.h"
#include "dlgreceiptvaucher.h"
#include "paymentmode.h"
#include "printtaxd.h"
#include "winvoice.h"
#include "cacheguest.h"
#include "vauchers.h"
#include "dlgpostcharge.h"
#include "cacheinvoiceitem.h"
#include "cachetaxmap.h"
#include "wquickcheckoutprocess.h"
#include <QPainter>

WQuickCheckout::WQuickCheckout(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WQuickCheckout)
{
    ui->setupUi(this);
    ui->tbl->installEventFilter(this);
    installEventFilter(this);
    ui->tbl->setItemDelegate(new WQuickCheckoutItemDelegate(this));
    ui->chAllInvoices->setChecked(__s.value("quickcheckout_allinvoices").toBool());
    Utils::tableSetColumnWidths(ui->tbl, ui->tbl->columnCount(), 60, 100, 200, 300, 100, 100, 100, 80, 80, 200);
    Utils::tableSetColumnWidths(ui->tblTotal, ui->tbl->columnCount(), 60, 100, 200, 300, 100, 100, 100, 80, 80, 200);
    refresh();
}

WQuickCheckout::~WQuickCheckout()
{
    delete ui;
}

bool WQuickCheckout::selected(int row)
{
    return ui->tbl->item(row, 0)->data(Qt::UserRole).toInt() == 1;
}

void WQuickCheckout::setup()
{
    setupTabTextAndIcon(tr("Checkout"), ":/images/departure.png");
}

bool WQuickCheckout::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        auto *ke = static_cast<QKeyEvent*>(event);
        switch (ke->key()) {
        case Qt::Key_Plus:
            ke->accept();
            if (ke->modifiers() & Qt::ControlModifier) {
                setRowSelected(-1);
            } else {
                setRowSelected(1);
            }
            return true;
        case Qt::Key_Minus:
            ke->accept();
            if (ke->modifiers() & Qt::ControlModifier) {
                setRowSelected(-2);
            } else {
                setRowSelected(0);
            }
            return true;
        }
    }
    return BaseWidget::eventFilter(watched, event);
}

void WQuickCheckout::refresh()
{
    QMap<QString, int> invMap;
    QString query = "select r.f_room, r.f_invoice, c.f_name, g.guest as f_guest, 0, 0, 0, r.f_man+r.f_woman, "
                    "rc.f_short, concat(rg.f_name, ' - ', r.f_group) as f_groupname "
                    "from f_reservation r "
                    "left join f_room rm on rm.f_id=r.f_room "
                    "left join f_room_classes rc on rc.f_id=rm.f_class "
                    "left join guests g on g.f_id=r.f_guest "
                    "left join f_cardex c on c.f_cardex=r.f_cardex "
                    "left join f_reservation_group rg on rg.f_id=r.f_group "
                    "where r.f_state=:f_state :date :cardex :group "
                    "order by r.f_room ";
    if (ui->chAllInvoices->isChecked()) {
        query.replace(":date", "");
    } else {
        query.replace(":date", QString(" and r.f_enddate='%1'").arg(WORKING_DATE.toString(def_mysql_date_format)));
    }
    if (ui->wCardex->empty()) {
        query.replace(":cardex", "");
    } else {
        query.replace(":cardex", QString(" and r.f_cardex='%1'").arg(ui->wCardex->cardex()));
    }
    if (ui->wGroup->group() == 0) {
        query.replace(":group", "");
    } else {
        query.replace(":group", QString(" and r.f_group=%1").arg(ui->wGroup->group()));
    }
    DoubleDatabase dd;
    dd[":f_state"] = RESERVE_CHECKIN;
    dd.exec(query);
    Utils::fillTableWithData(ui->tbl, dd.fDbRows);
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        invMap[ui->tbl->toString(i, 1)] = i;
    }
    dd[":f_state"] = RESERVE_CHECKIN;
    dd.exec("select m.f_inv, m.f_amountamd, m.f_sign, m.f_side "
            "from m_register m "
            "inner join f_reservation r on r.f_invoice=m.f_inv "
            "where r.f_state=:f_state and m.f_finance=1 and m.f_canceled=0 ");
    double t1 = 0.0, t2 = 0.0, t3 = 0.0;
    while (dd.nextRow()) {
        if (!invMap.contains(dd.getString("f_inv"))) {
            continue;
        }
        int col = 4;
        int row = invMap[dd.getString("f_inv")];
        if (dd.getInt("f_side") == 1) {
            t2 += dd.getDouble("f_amountamd") * dd.getDouble("f_sign");
            col = 5;
        } else {
            t1 += dd.getDouble("f_amountamd") * dd.getDouble("f_sign");
        }
        ui->tbl->setValue(row, col, ui->tbl->toDouble(row, col) + (dd.getDouble("f_amountamd") * dd.getDouble("f_sign")));
        ui->tbl->setValue(row, 6, ui->tbl->toDouble(row, 4) + ui->tbl->toDouble(row, 5));
    }
    QStringList vh;
    vh << QString::number(ui->tbl->rowCount());
    ui->tblTotal->setVerticalHeaderLabels(vh);
    t3 = t1 + t2;
    ui->tblTotal->setValue(0, 4, t1);
    ui->tblTotal->setValue(0, 5, t2);
    ui->tblTotal->setValue(0, 6, t3);
}

void WQuickCheckout::setRowSelected(int flag)
{
    if (flag < 0) {
        flag = flag == -1 ? 1 : 0;
        for (int i = 0; i < ui->tbl->rowCount(); i++) {
            ui->tbl->setValue(i, 0, flag, Qt::UserRole);
        }
        ui->tbl->viewport()->update();
        return;
    }
    int row = ui->tbl->currentRow();
    if (row < 0) {
        return;
    }
    ui->tbl->setValue(row, 0, flag, Qt::UserRole);
    ui->tbl->viewport()->update();
}

void WQuickCheckout::updateRow(int row)
{
    DoubleDatabase dd;
    dd[":f_inv"] = ui->tbl->toString(row, 1);
    dd.exec("select m.f_amountamd, m.f_sign, m.f_side "
            "from m_register m "
            "where m.f_inv=:f_inv and m.f_finance=1 and m.f_canceled=0");
    ui->tbl->setValue(row, 4, 0);
    ui->tbl->setValue(row, 5, 0);
    ui->tbl->setValue(row, 6, 0);
    while (dd.nextRow()) {
        int col = 4;
        if (dd.getInt("f_side") == 1) {
            col = 5;
        }
        ui->tbl->setValue(row, col, ui->tbl->toDouble(row, col) + (dd.getDouble("f_amountamd") * dd.getDouble("f_sign")));
        ui->tbl->setValue(row, 6, ui->tbl->toDouble(row, 4) + ui->tbl->toDouble(row, 5));
    }
    double t1 = 0.0, t2 = 0.0;
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        t1 += ui->tbl->toDouble(i, 4);
        t2 += ui->tbl->toDouble(i, 5);
    }
    ui->tblTotal->setValue(0, 4, t1);
    ui->tblTotal->setValue(0, 5, t2);
    ui->tblTotal->setValue(0, 6, t1 + t2);
}

void WQuickCheckout::on_chAllInvoices_clicked(bool checked)
{
    __s.setValue("quickcheckout_allinvoices", checked);
}

void WQuickCheckout::on_btnRefresh_clicked()
{
    refresh();
}


WQuickCheckoutItemDelegate::WQuickCheckoutItemDelegate(WQuickCheckout *w) :
    QItemDelegate(w)
{
    fParent = w;
}

void WQuickCheckoutItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!index.isValid()) {
        return;
    }
    painter->save();
    QColor bgColor = Qt::white;
    if (fParent->selected(index.row())) {
        bgColor = Qt::cyan;
    }
    painter->fillRect(option.rect, bgColor);
    QRectF rText = option.rect;
    rText.adjust(2, 2, -2, -2);
    QFont f(painter->font());
    if (option.state & QStyle::State_Selected) {
        f.setBold(true);
        f.setPointSize(f.pointSize() + 1);
    }
    painter->setFont(f);
    painter->drawText(rText, index.data(Qt::DisplayRole).toString());
    painter->restore();
}

void WQuickCheckout::on_tbl_doubleClicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    DoubleDatabase dd;
    auto *rv = new DlgReceiptVaucher(0, 0, 0, this);
    auto *pt =  new PrintTaxD(fPreferences.getDb(def_default_fiscal_machine).toInt(), this);
    rv->setRoom(ui->tbl->toInt(index.row(), 0));
    rv->setRoom(ui->tbl->toInt(index.row(), 0));
    switch (index.column()) {
    case 1: {
        WInvoice::openInvoiceWindow(ui->tbl->toString(index.row(), 1));
        break;
    }
    case 4:
        if (ui->tbl->toDouble(index.row(), 4) != 0.0) {
            rv->setSide(0);
            rv->setPaymentMode(PAYMENT_CASH, 0);
            rv->setAmount(ui->tbl->toDouble(index.row(), 4));
            rv->exec();
        }
        break;
    case 5:
        if (ui->tbl->toDouble(index.row(), 5) != 0.0) {
            rv->setSide(1);
            dd[":f_invoice"] = ui->tbl->toString(index.row(), 1);
            dd.exec("select f_cityledger from f_reservation where f_invoice=:f_invoice");
            if (dd.nextRow()) {
                rv->setPaymentMode(PAYMENT_CL, dd.getInt("f_cityledger"));
            } else {
                rv->setPaymentMode(PAYMENT_CL, 0);
            }
            rv->setAmount(ui->tbl->toDouble(index.row(), 5));
            rv->exec();
        }
        break;
    case 6: {
        pt->fInvoice = ui->tbl->toString(index.row(), 1);
        dd[":f_inv"] = pt->fInvoice;
        dd.exec("select m.f_id, m.f_source, m.f_itemcode, m.f_amountamd, m.f_vatmode "
                "from m_register m "
                "where m.f_inv=:f_inv and m.f_finance=1 and m.f_canceled=0 "
                "and m.f_source<>'RV' and m.f_fiscal=0 ");
        while (dd.nextRow()) {
            if (dd.getString("f_source") == VAUCHER_POINT_SALE_N) {
                QString orderId = dd.getString("f_id");
                CacheInvoiceItem c;
                if (!c.get(dd.getString("f_itemcode"))) {
                    message_error(tr("Error in tax print. c == 0, case 2."));
                    continue;
                }
                CacheTaxMap ci;
                if (!ci.get(c.fCode())) {
                    message_error(tr("Tax department undefined for ") + c.fName());
                    return;
                }
                DoubleDatabase fDD;
                fDD[":f_header"] = orderId;
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
                    pt->fDept.append(dd.getInt("f_vatmode") == VAT_INCLUDED ? ci.fName() : c.fNoVatDept());
                    pt->fRecList.append(dd.getString("f_id"));
                    pt->fCodeList.append(fDD.getString(0));
                    pt->fNameList.append(fDD.getString(1));
                    pt->fPriceList.append(fDD.getString(4));
                    pt->fQtyList.append(fDD.getString(3));
                    pt->fAdgCode.append(fDD.getString(2));
                    pt->fTaxNameList.append(fDD.getString(1));
                }
            } else  {
                CacheInvoiceItem c;
                if (!c.get(dd.getString("f_itemcode"))) {
                    message_error(tr("Error in tax print. c == 0, case 1."));
                    continue;
                }
                CacheTaxMap ci;
                if (!ci.get(c.fCode())) {
                    message_error(tr("Tax department undefined for ") + c.fName());
                    return;
                }
                pt->fDept.append(dd.getInt("f_vatmode") == VAT_INCLUDED ? ci.fName() : c.fNoVatDept());
                pt->fRecList.append(dd.getString("f_id"));
                pt->fCodeList.append(c.fCode());
                pt->fNameList.append(c.fTaxName());
                pt->fPriceList.append(dd.getString("f_amountamd"));
                pt->fQtyList.append("1");
                pt->fAdgCode.append(c.fAdgt());
                pt->fTaxNameList.append(c.fTaxName());
            }
        }
        pt->build();
        if (pt->fRecList.count() > 0) {
            pt->exec();
        } else {
            message_info(tr("Nothing to print"));
        }
        break;
    }
    }
    delete rv;
    delete pt;
    updateRow(index.row());
}

void WQuickCheckout::on_btnCheckout_clicked()
{
    QStringList invoices;
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        if (ui->tbl->item(i, 0)->data(Qt::UserRole).toInt() == 1) {
            invoices << ui->tbl->toString(i, 1);
        }
    }
    if (invoices.count() == 0) {
        message_info(tr("Nothing was selected"));
        return;
    } else {
        if (message_confirm(tr("Confirm to checkout")) != QDialog::Accepted) {
            return;
        }
        WQuickCheckoutProcess *wp = new WQuickCheckoutProcess(this);
        wp->setListOfInvoices(invoices);
        wp->exec();
        delete wp;
        refresh();
    }
}

void WQuickCheckout::on_btnCommonPostCharge_clicked()
{
    QStringList invoices;
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        if (ui->tbl->item(i, 0)->data(Qt::UserRole).toInt() == 1) {
            invoices << ui->tbl->toString(i, 1);
        }
    }
    if (invoices.count() == 0) {
        message_info(tr("Nothing was selected"));
        return;
    } else {
        auto *pc = new DlgPostCharge(this);
        pc->setInvoice(invoices.at(0));
        pc->exec();
        QString doc = pc->voucher();
        delete pc;
        if (doc.isEmpty()) {
            message_info(tr("Nothing was charged"));
            return;
        }
        invoices.removeAt(0);
        DoubleDatabase dd;
        for (const QString &s: invoices) {
            dd[":f_invoice"] = s;
            dd.exec("select * from f_reservation where f_invoice=:f_invoice");
            if (!dd.nextRow()) {
                message_error(tr("Invoice no exists: ") + s);
                return;
            }
            int room = dd.getInt("f_room");
            QString res = dd.getString("f_id");
            CacheGuest cg;
            QString guest = "UNKNOWN";
            if (cg.get(dd.getInt("f_guest"))) {
                guest = cg.fFullName();
            }
            DBMRegister d;
            d.open(dd, doc);
            d.fId.clear();
            d.fRoom = room;
            d.fInvoice = s;
            d.fReserve = res;
            d.fGuest = guest;
            if (!d.save(dd)) {
                message_error(d.fError);
                return;
            }
        }
    }
    refresh();
    message_info(tr("Done"));
}
