#include "frestauranttotal.h"
#include "ui_frestauranttotal.h"
#include "wreportgrid.h"
#include "cachedish.h"
#include "cachedishstate.h"
#include "dlgperemovereason.h"
#include "dlggposorderinfo.h"
#include "paymentmode.h"
#include "cacheorderstate.h"
#include "cacherestdishtype.h"
#include "cachereststore.h"
#include "cacheresthall.h"
#include "cacheusers.h"
#include "cacheresttable.h"
#include "cachepaymentmode.h"
#include <QPrinter>

#define sn_order_state 1
#define sn_table 2
#define sn_dish 3
#define sn_dish_state 4

FRestaurantTotal::FRestaurantTotal(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FRestaurantTotal)
{
    ui->setupUi(this);
    if (r__(cr__o_cancelation)) {
        fReportGrid->addToolBarButton(":/images/garbage.png", tr("Remove"), SLOT(removeOrder()), this)->setFocusPolicy(Qt::ClickFocus);
    }
    if (r__(cr__remove_restaurant)) {
        fReportGrid->addToolBarButton(":/images/biohazard.png", tr("Eliminate!"), SLOT(removePermanently()), this)->setFocusPolicy(Qt::ClickFocus);
    }
    fReportGrid->addToolBarButton(":/images/printer.png", tr("Print receipts"), SLOT(printReceipt()), this)->setFocusPolicy(Qt::ClickFocus);
    connect(fReportGrid, SIGNAL(doubleClickOnRow(QList<QVariant>)), this, SLOT(doubleClick(QList<QVariant>)));
    ui->leHall->setSelector(this, cache(cid_rest_hall), ui->leHall);
    ui->leHall->fSelectorMultiCheck = true;
    ui->leState->setSelector(this, cache(cid_order_state), ui->leState);
    ui->leState->fSelectorMultiCheck = true;
    ui->leTable->setSelector(this, cache(cid_rest_table), ui->leTable);
    ui->leTable->fSelectorMultiCheck = true;
    ui->leStaff->setSelector(this, cache(cid_users), ui->leStaff);
    ui->leStaff->fSelectorMultiCheck = true;
    ui->leStore->setSelector(this, cache(cid_rest_store), ui->leStore);
    ui->leStore->fSelectorMultiCheck = true;
    ui->leDishType->setSelector(this, cache(cid_rest_dish_type), ui->leDishType);
    ui->leDishType->fSelectorMultiCheck = true;
    ui->leDish->setSelector(this, cache(cid_dish), ui->leDish);
    ui->leDish->fSelectorMultiCheck = true;
    ui->lePaymentMode->setSelector(this, cache(cid_payment_mode), ui->lePaymentMode);
    ui->lePaymentMode->fSelectorMultiCheck = true;
    ui->lePaymentMode->fCodeFilter << QString::number(PAYMENT_CARD)
                                   << QString::number(PAYMENT_CASH)
                                   << QString::number(PAYMENT_CL)
                                   << QString::number(PAYMENT_BANK)
                                   << QString::number(PAYMENT_ROOM)
                                   << QString::number(PAYMENT_COMPLIMENTARY);
    ui->leDishState->setSelector(this, cache(cid_dish_state), ui->leDishState);
    ui->leDishState->fSelectorMultiCheck = true;

    ui->leState->setInitialValue(ORDER_STATE_CLOSED);
    ui->leDishState->setInitialValue(DISH_STATE_READY);

    fReportGrid->fIncludes.clear();
    fReportGrid->fIncludes["oh.f_comment"] = false;
    fReportGrid->fIncludes["oh.f_id"] = false;
    fReportGrid->fIncludes["oh.f_state"] = false;
    fReportGrid->fIncludes["os.f_" + def_lang] = false;
    fReportGrid->fIncludes["oh.f_dateCash"] = false;
    fReportGrid->fIncludes["oh.f_dateOpen"] = false;
    fReportGrid->fIncludes["oh.f_dateClose"] = false;
    fReportGrid->fIncludes["timediff(oh.f_dateclose, oh.f_dateopen)"] = false;
    fReportGrid->fIncludes["oh.f_hall"] = false;
    fReportGrid->fIncludes["h.f_name"] = false;
    fReportGrid->fIncludes["oh.f_table"] = false;
    fReportGrid->fIncludes["t.f_name"] = false;
    fReportGrid->fIncludes["oh.f_staff"] = false;
    fReportGrid->fIncludes["concat(u.f_firstName,' ',u.f_lastName)"] = false;
    fReportGrid->fIncludes["oh.f_cityLedger"] = false;
    fReportGrid->fIncludes["cl.f_name"] = false;
    fReportGrid->fIncludes["od.f_store"] = false;
    fReportGrid->fIncludes["s.f_name"] = false;
    fReportGrid->fIncludes["od.f_state"] = false;
    fReportGrid->fIncludes["ds.f_en"] = false;
    fReportGrid->fIncludes["d.f_type"] = false;
    fReportGrid->fIncludes["dt.f_" + def_lang] = false;
    fReportGrid->fIncludes["d.f_as"] = false;
    fReportGrid->fIncludes["od.f_dish"] = false;
    fReportGrid->fIncludes["d.f_" + def_lang] = false;
    fReportGrid->fIncludes["oh.f_tax"] = false;
    fReportGrid->fIncludes["oh.f_paymentMode"] = false;
    fReportGrid->fIncludes["pm.f_" + def_lang] = false;
    fReportGrid->fIncludes["oh.f_paymentModeComment"] = false;
    fReportGrid->fIncludes["sum(od.f_qty)"] = true;
    fReportGrid->fIncludes["sum(od.f_total)"] = true;
    fReportGrid->fIncludes["count(distinct(oh.f_id))"] = false;
    fReportGrid->fIncludes["sum(oh.f_total)"] = false;
}

FRestaurantTotal::~FRestaurantTotal()
{
    delete ui;
}

void FRestaurantTotal::apply(WReportGrid *rg)
{
    QString order;
    bool countAmount = !ui->chDish->isChecked()
            && !ui->chStore->isChecked()
            && !ui->chDishType->isChecked()
            && !ui->chDishState->isChecked()
            && ui->leDish->fHiddenText.isEmpty()
            && ui->leStore->text().isEmpty()
            && ui->leDishType->text().isEmpty()
            && ui->leArmSoft->text().isEmpty()
            && !ui->chArmSoft->isChecked();
    fReportGrid->fIncludes["sum(od.f_qty)"] = !countAmount;
    fReportGrid->fIncludes["count(distinct(oh.f_id))"] = countAmount;
    rg->fFieldsWidths.clear();
    rg->fFieldsWidths << 100 //f_id
           << 0 // oh_fstate
           << 80 //state name
           << 100 //date_cash
           << 110 // date open
           << 110 // date close
           << 100 // total duration
           << 0 //hall code
           << 80 //hall name
           << 0 // table code
           << 50 // table name
           << 0 //oh.f_staff
           << 150 //staff name
           << 0 // cl code
           << 150 // cl
           << 0 // store code
           << 100 // store name
           << 0 // dish state code
           << 80 //dish_ state
           << 0 // dish type code
           << 200 // dish type name
           << 0 //dish code
           << 200 //dish name
           << 50 // armsoft
           << 100 // tax
           << 0 // payment mode
           << 150 //payment mode name
           << 80 // payment mode comment
           << 200 //Comment
           << 80 // count of orders
           << 80 // sum qty
           << 80 // sum total
              ;
    rg->fFields.clear();
    rg->fFields << "oh.f_id"
           << "oh.f_state"
           << "os.f_" + def_lang
           << "oh.f_dateCash"
           << "oh.f_dateOpen"
           << "oh.f_dateClose"
           << "timediff(oh.f_dateclose, oh.f_dateopen)"
           << "oh.f_hall"
           << "h.f_name"
           << "oh.f_table"
           << "t.f_name"
           << "oh.f_staff"
           << "concat(u.f_firstName,' ',u.f_lastName)"
           << "oh.f_cityLedger"
           << "cl.f_name"
           << "od.f_store"
           << "od.f_state"
           << "s.f_name"
           << "ds.f_en"
           << "d.f_type"
           << "dt.f_" + def_lang
           << "od.f_dish"
           << "d.f_" + def_lang
           << "d.f_as"
           << "oh.f_tax"
           << "oh.f_paymentMode"
           << "pm.f_" + def_lang
           << "oh.f_paymentModeComment"
           << "oh.f_comment"
              ;
    if (countAmount) {
        rg->fFields
                << "count(distinct(oh.f_id))"
                << "sum(od.f_total)";
    } else {
        rg->fFields.append("sum(od.f_qty)");
        rg->fFields.append("sum(od.f_total)");
    }
    rg->fFieldTitles.clear();
    rg->fFieldTitles << tr("Order #")
           << tr("State code")
           << tr("State")
           << tr("Date")
           << tr("Opened")
           << tr("Closed")
           << tr("Duration")
           << tr("Hall code")
           << tr("Hall")
           << tr("Table code")
           << tr("Table")
           << tr("Staff code")
           << tr("Staff")
           << tr("City ledger code")
           << tr("City ledger")
           << tr("Store code")
           << tr("Store")
           << tr("Dish state code")
           << tr("Dish state")
           << tr("Dish type code")
           << tr("Dish type")
           << tr("Dish code")
           << tr("Dish")
           << tr("ArmSoft")
           << tr("Tax")
           << tr("Payment mode code")
           << tr("P/M")
           << tr("P/M comment")
           << tr("Order comment")
           << tr("Qty")
           << tr("Total")
           ;

    rg->fTables.clear();
    rg->fTables << "o_header oh"
           << "o_dish od"
           << "o_state os"
           << "r_hall h"
           << "r_table t"
           << "r_store s"
           << "r_dish_type dt"
           << "r_dish d"
           << "users u"
           << "f_city_ledger cl"
           << "f_payment_type pm"
           << "o_dish_state ds";
    rg->fJoins.clear();
    rg->fJoins << "from" //od
          << "inner" //oh
          << "inner" //os
          << "inner" //h
          << "inner" //t
          << "inner" //s
          << "inner" //dt
          << "inner" // d
          << "inner" //u
          << "left" //cl
          << "inner" //pm
          << "left" //ds
             ;
    rg->fJoinConds.clear();
    rg->fJoinConds << ""
              << "od.f_header=oh.f_id"
              << "os.f_id=oh.f_state"
              << "h.f_id=oh.f_hall"
              << "t.f_id=oh.f_table"
              << "s.f_id=od.f_store"
              << "dt.f_id=d.f_type"
              << "d.f_id=od.f_dish"
              << "u.f_id=oh.f_staff"
              << "cl.f_id=oh.f_cityLedger"
              << "pm.f_id=oh.f_paymentMode"
              << "ds.f_id=od.f_state"
                 ;

    QString where = "where (oh.f_dateCash between '" + ui->deStart->date().toString(def_mysql_date_format) + "' "
            + " and '" + ui->deEnd->date().toString(def_mysql_date_format) + "') ";
    if (!ui->leOrder->text().isEmpty()) {
        QStringList ids = ui->leOrder->text().split(",");
        QString idtot;
        bool f = true;
        foreach (QString s, ids) {
            if (f) {
                f = false;
            } else {
                idtot += ",";
            }
            idtot += ap(s);
        }
        where += " and oh.f_id in (" + idtot + ") ";
    }
    if (!ui->leState->text().isEmpty()) {
        where += " and oh.f_state in (" + ui->leState->fHiddenText + ") ";
    }
    if (!ui->leHall->text().isEmpty()) {
        where += " and oh.f_hall in (" + ui->leHall->fHiddenText + ") ";
    }
    if (!ui->leTable->text().isEmpty()) {
        where += " and oh.f_table in (" + ui->leTable->fHiddenText + ") ";
    }
    if (!ui->leStaff->text().isEmpty()) {
        where += " and oh.f_staff in (" + ui->leStaff->fHiddenText + ") ";
    }
    if (!ui->leDishState->text().isEmpty()) {
        where += " and od.f_state in (" + ui->leDishState->fHiddenText + ") ";
    }
    if (!ui->leStore->text().isEmpty()) {
        where += " and od.f_store in (" + ui->leStore->fHiddenText + ") ";
    }
    if (!ui->leDishType->text().isEmpty()) {
        where += " and d.f_type in (" + ui->leDishType->fHiddenText + ") ";
    }
    if (!ui->leDish->text().isEmpty()) {
        where += " and od.f_dish in (" + ui->leDish->fHiddenText + ") ";
    }
    if (!ui->leArmSoft->text().isEmpty()) {
        where += " and d.f_as in(" + ui->leArmSoft->text() + ") ";
    }
    if (!ui->lePaymentMode->text().isEmpty()) {
        where += " and oh.f_paymentMode in (" + ui->lePaymentMode->fHiddenText + ") ";
    }
    if (!ui->lePMComment->text().isEmpty()) {
        where += " and upper(oh.f_paymentModeComment) like '" + ui->lePMComment->text() + "%' ";
    }
    if (!ui->leTax->text().isEmpty()) {
        where += " and oh.f_tax in (" + ui->leTax->text() + ") ";
    }
    if (ui->rbNoShowComplex->isChecked()) {
        where += " and (od.f_complex=0 or (od.f_complex>0 and od.f_complexId>0)) ";
    }
    if (ui->rbShowComplex->isChecked()) {

    }
    if (ui->rbOnlycomplex->isChecked()) {
        where += " and (od.f_complex>0 and od.f_complexId=0) ";
    }

    if (ui->chOrderNum->isChecked()) {
        order += "oh.f_id,";
    }
    QString group;
    QObjectList ol(children());
    bool first = true;
    foreach (QObject *o, ol) {
        if (isCheckBox(static_cast<QWidget*>(o))) {
            EQCheckBox *check = static_cast<EQCheckBox*>(o);
            if (check->isChecked()) {
                if (first) {
                    first = false;
                } else {
                    group += ",";
                }
                group += check->getField().replace(";", ",");
                if (check->getRequireLang()) {
                    group += def_lang;
                }
            }
        }
    }
    if (!group.isEmpty()) {
        group = " group by " + group;
    }
    if (!order.isEmpty()) {
        order = " order by " + order;
    }
    where += group;
    order.remove(order.length() - 1, 1);
    where += order;
    buildQuery(rg, where);
    QList<int> colsTotal;
    colsTotal << rg->fModel->columnIndex(tr("Qty")) << rg->fModel->columnIndex(tr("Total"));
    QList<double> valsTotal;
    rg->fModel->sumOfColumns(colsTotal, valsTotal);
    rg->setTblTotalData(colsTotal, valsTotal);
    if (ui->chOrderNum->isChecked()) {
        QColor dark = COLOR_DARK_ROW;
        QColor currColor = Qt::white;
        QString currId ;
        for (int i = 0, count = rg->fModel->rowCount(); i < count; i++) {
            if (rg->fModel->data(i, 0).toString() != currId) {
                currId = rg->fModel->data(i, 0).toString();
                currColor = (currColor == Qt::white ? dark : Qt::white);
            }
            rg->fModel->setBackgroundColor(i, currColor);
        }
    }
}

QWidget *FRestaurantTotal::firstElement()
{
    return ui->deStart;
}

QWidget *FRestaurantTotal::lastElement()
{
    return ui->deEnd;
}

QString FRestaurantTotal::reportTitle()
{
    return QString("%1 %2-%3")
            .arg(tr("Restaurant sales"))
            .arg(ui->deStart->text())
            .arg(ui->deEnd->text());
}

void FRestaurantTotal::open()
{
    WReportGrid *rg = addTab<WReportGrid>();
    rg->setupTabTextAndIcon(tr("Restaurant total"), ":/images/cutlery.png");
    FRestaurantTotal *fr = new FRestaurantTotal(rg);
    rg->addFilterWidget(fr);
    fr->apply(rg);
}

void FRestaurantTotal::removeVoucher(const QString &id)
{
    QStringList dishes;
    DoubleDatabase fDD;
    fDD.startTransaction();
    fDD.exec("select f_id from o_dish where f_header=:f_header");
    while (fDD.nextRow()) {
        dishes.append(fDD.getString(0));
    }
    fDD[":f_header"] = id;
    fDD.exec("delete from o_dish where f_header=:f_header");
    fDD[":f_id"] = id;
    fDD.exec("delete from o_header where f_id=:f_id");
    fDD[":f_id"] = id;
    fDD.exec("delete from m_register where f_id=:f_id");
    for (const QString &d: dishes) {
        fDD[":f_rec"] = d;
        fDD.exec("delete from o_dish_qty where f_rec=:f_rec");
    }
    fDD.commit();
}

void FRestaurantTotal::printNewPage(int &top, int &left, int &page, PPrintPreview *pp, PPrintScene *&ps, int nextHeight)
{
    int footerTop = sizePortrait.height() - 200;
    QBrush b(Qt::white, Qt::SolidPattern);
    PTextRect trFooter;
    trFooter.setBrush(b);
    QFont ffooter(qApp->font().family(), 20);
    trFooter.setFont(ffooter);
    trFooter.setBorders(false, false, false, false);
    trFooter.setTextAlignment(Qt::AlignLeft);

    if (top + nextHeight > sizePortrait.height() - 300) {
        if (left == 20) {
            left = 1100;
        } else {
            left = 20;
            ps->addTextRect(20, footerTop, 1800, 60, QString("%1: %2 %3")
                            .arg(tr("Printed"))
                            .arg(QDateTime::currentDateTime().toString(def_date_time_format))
                            .arg(WORKING_USERNAME), &trFooter);
            trFooter.setTextAlignment(Qt::AlignRight);
            ps->addTextRect(1800, footerTop, 200, 60, QString("%1 %2")
                            .arg(tr("Page"))
                            .arg(page), &trFooter);
            trFooter.setTextAlignment(Qt::AlignLeft);
            ps = pp->addScene(0,QPageLayout::Portrait);
            page++;
        }
        top = 20;
    }
}

void FRestaurantTotal::printReceipt()
{
    if (!fReportGrid->fIncludes["oh.f_id"]) {
        message_error(tr("Order id must be included in the query"));
        return;
    }
    QModelIndexList sel = fReportGrid->fTableView->selectionModel()->selectedIndexes();
    if (sel.count() == 0) {
        message_error(tr("Nothing was selected"));
        return;
    }
    QSet<QString> orders;
    foreach (QModelIndex m, sel) {
        orders.insert(fReportGrid->fModel->data(m.row(), 0, Qt::EditRole).toString());
    }
    if (orders.count() == 0) {
        return;
    }

    int left = 20;
    int top = 20;
    int page = 1;

    PTextRect prTempl;
    prTempl.setWrapMode(QTextOption::NoWrap);
    prTempl.setFont(QFont(qApp->font().family(), 17));
    prTempl.setBorders(true, true, true, true);
    QPen pen;
    pen.setWidth(2);
    prTempl.setRectPen(pen);
    PTextRect prHead(prTempl, "");
    prHead.setFont(QFont(qApp->font().family(), 20));
    prHead.setBrush(QBrush(QColor::fromRgb(215, 215, 215), Qt::SolidPattern));
    prHead.setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    PPrintPreview pp(this);
    PPrintScene *ps = pp.addScene(0,QPageLayout::Portrait);
    PTextRect th;
    QFont f("Arial", 30);
    th.setFont(f);
    th.setBorders(false, false, false, false);
    th.setTextAlignment(Qt::AlignLeft);
    int rowHeight = 60;

    CacheRestHall hall;
    CacheRestTable table;
    CacheUsers users;
    foreach (QString s, orders) {
        printNewPage(top, left, page, &pp, ps, 250);
        PImage *logo = new PImage("logo_print.png");
        ps->addItem(logo);
        logo->setRect(QRectF(left + 150, top, 400, 250));
        top += 260;
        printNewPage(top, left, page, &pp, ps);

        DoubleDatabase dh;
        dh[":f_id"] = s;
        dh.exec("select * from o_header where f_id=:f_id");
        dh.nextRow();
        hall.get(dh.getString("f_hall"));
        top += ps->addTextRect(left + 10, top, 680, rowHeight, hall.fName(), &prHead)
                ->textHeight();
        QString receiptNum = QString("%1 %2").arg(tr("Receipt S/N")).arg(s);
        printNewPage(top, left, page, &pp, ps, rowHeight);
        top += ps->addTextRect(left + 10, top, 680, rowHeight, receiptNum, &prHead)->textHeight();
        ps->addTextRect(new PTextRect(left + 10, top, 150, rowHeight, tr("Table"), &th, f));
        table.get(dh.getValue("f_table").toString());
        ps->addTextRect(new PTextRect(left + 160, top, 200, rowHeight, table.fName(), &th, f));
        ps->addTextRect(new PTextRect(left + 340, top, 230, rowHeight, tr("Date"), &th, f));
        printNewPage(top, left, page, &pp, ps, rowHeight);
        top += ps->addTextRect(new PTextRect(450, top, 250, rowHeight, dh.getValue("f_datecash").toDate().toString(def_date_format), &th, f))
                ->textHeight();
        ps->addTextRect(new PTextRect(left + 10, top, 150, rowHeight, tr("Time"), &th, f));
        printNewPage(top, left, page, &pp, ps, rowHeight);
        top += ps->addTextRect(new PTextRect(left + 160, top, 200, rowHeight, QTime::currentTime().toString(def_time_format), &th, f))->textHeight();
        ps->addTextRect(new PTextRect(left + 10, top, 150, rowHeight, tr("Waiter"), &th, f));
        printNewPage(top, left, page, &pp, ps, rowHeight);
        users.get(dh.getValue("f_staff").toString());
        top += ps->addTextRect(new PTextRect(left + 160, top, 500, rowHeight, users.fFull(), &th, f))->textHeight();
        ps->addTextRect(new PTextRect(left + 10, top, 150, rowHeight, tr("Opened"), &th, f));
        printNewPage(top, left, page, &pp, ps, rowHeight);
        top += ps->addTextRect(new PTextRect(left + 160, top, 350, rowHeight, dh.getValue("f_dateOpen").toDateTime().toString(def_date_time_format), &th, f))->textHeight();
        ps->addTextRect(new PTextRect(left + 10, top, 150, rowHeight, tr("Closed"), &th, f));
        printNewPage(top, left, page, &pp, ps, rowHeight);
        top += ps->addTextRect(new PTextRect(left + 160, top, 350, rowHeight, dh.getValue("f_dateClose").toDateTime().toString(def_date_time_format), &th, f))->textHeight();

        printNewPage(top, left, page, &pp, ps, rowHeight);
        top += 2;
        ps->addLine(left + 10, top, left + 680, top);
        top ++;
        ps->addTextRect(new PTextRect(left + 10, top, 100, rowHeight, tr("Qty"), &th, f));
        ps->addTextRect(new PTextRect(left + 110, top, 390, rowHeight, tr("Description"), &th, f));
        top += ps->addTextRect(new PTextRect(left + 500, top, 200, rowHeight, tr("Amount"), &th, f))->textHeight();
        ps->addLine(left + 10, top, left + 680, top);
        top ++;


        DoubleDatabase dcomplex;
        dcomplex[":f_header"] = s;
        dcomplex.exec("select od.f_id, od.f_dish, dc.f_en, dc.f_ru, dc.f_am, od.f_qty, od.f_qtyPrint, od.f_price, "
                             "od.f_svcValue, od.f_svcAmount, od.f_dctValue, od.f_dctAmount, od.f_total, "
                             "od.f_print1, od.f_print2, od.f_comment, od.f_staff, od.f_state, od.f_complex, od.f_complexId, "
                             "dc.f_adgt "
                             "from o_dish od "
                             "left join r_dish_complex dc on dc.f_id=od.f_complexId "
                             "where od.f_header=:f_header and f_complex>0 and f_complexId>0 and f_state=1 "
                             "order by od.f_id ");
        f.setPointSize(18);
        f.setBold(true);
        th.setFont(f);
        for (int i = 0; i < dcomplex.rowCount(); i++) {
            ps->addTextRect(new PTextRect(left + 10, top, 100, rowHeight, float_str(dcomplex.getValue(i, "f_qty").toDouble(), 1), &th, f));
            ps->addTextRect(new PTextRect(left + 110, top, 390, rowHeight, dcomplex.getValue(i, "f_en").toString(), &th, f));
            top += ps->addTextRect(new PTextRect(left + 500, top, 200, rowHeight, float_str(dcomplex.getValue(i, "f_price").toDouble() * dcomplex.getValue(i, "f_qty").toDouble(), 2), &th, f))->textHeight();
            printNewPage(top, left, page, &pp, ps);
        }
        DoubleDatabase ddish;
        ddish[":f_header"] = s;
        ddish.exec("select od.f_id, od.f_dish, d.f_en, d.f_ru, d.f_am, od.f_qty, od.f_qtyPrint, od.f_price, "
                          "od.f_svcValue, od.f_svcAmount, od.f_dctValue, od.f_dctAmount, od.f_total, "
                          "od.f_print1, od.f_print2, od.f_comment, od.f_staff, od.f_state, od.f_complex, od.f_complexId, "
                          "od.f_adgt, od.f_complexRec "
                          "from o_dish od "
                          "left join r_dish d on d.f_id=od.f_dish "
                          "where od.f_header=:f_header and (f_complex=0 or (f_complex>0 and f_complexId=0)) and f_state=1 "
                          "order by od.f_id ");

        for (int i = 0; i < ddish.rowCount(); i++) {
            ps->addTextRect(new PTextRect(left + 10, top, 100, rowHeight, float_str(ddish.getValue(i, "f_qty").toDouble(), 1), &th, f));
            ps->addTextRect(new PTextRect(left + 110, top, 390, rowHeight, ddish.getValue(i, "f_en").toString(), &th, f));
            top += ps->addTextRect(new PTextRect(left + 500, top, 200, rowHeight, float_str(ddish.getValue(i, "f_total").toDouble(), 2), &th, f))->textHeight();
            printNewPage(top, left, page, &pp, ps);
        }
        ps->addLine(left + 10, top, left + 680, top);
        top += 2;
        f.setPointSize(24);
        th.setFont(f);
        ps->addTextRect(new PTextRect(left + 10, top, 400, rowHeight, tr("Total, AMD"), &th, f));
        top += ps->addTextRect(new PTextRect(left + 500, top, 200, rowHeight, float_str(dh.getValue("f_total").toDouble(), 1), &th, f))->textHeight();
        ps->addTextRect(new PTextRect(left + 10, top, 400, rowHeight, tr("Total, USD"), &th, f));
        top += ps->addTextRect(new PTextRect(left + 500, top, 200, rowHeight, float_str(dh.getValue("f_total").toDouble() / def_usd, 2), &th, f))->textHeight();

        top += rowHeight;
        f.setPointSize(28);
        th.setFont(f);
        th.setTextAlignment(Qt::AlignHCenter);
        printNewPage(top, left, page, &pp, ps);
        if (!dh.getValue("f_roomComment").toString().isEmpty()) {
           top += ps->addTextRect(new PTextRect(left + 10, top, 680, rowHeight, dh.getValue("f_roomComment").toString(), &th, f))->textHeight();
           top += rowHeight;
           top += ps->addTextRect(new PTextRect(left + 10, top, 680, rowHeight, tr("Signature"), &th, f))->textHeight();
           top += rowHeight + 2;
           ps->addLine(left + 150, top, left + 680, top);
        }

        printNewPage(top, left, page, &pp, ps);
        if (dh.getValue("f_paymentMode").toInt() == PAYMENT_COMPLIMENTARY) {
            top += ps->addTextRect(new PTextRect(left + 10, top, 680, rowHeight, tr("COMPLIMENTARY"), &th, f))->textHeight();
        } else {
            top += ps->addTextRect(new PTextRect(left + 10, top, 680, rowHeight, tr("SALES"), &th, f))->textHeight();
        }
        if (dh.getValue("f_paymentMode").toInt()) {
            top += rowHeight;
            top += ps->addTextRect(new PTextRect(left + 10, top, 680, rowHeight, tr("Mode Of Payment"), &th, f))->textHeight();
            switch (dh.getValue("f_paymentMode").toInt()) {
            case PAYMENT_CASH:
                top += ps->addTextRect(new PTextRect(left + 10, top, 680, rowHeight, tr("CASH"), &th, f))->textHeight();
                break;
            case PAYMENT_CARD:
                top += ps->addTextRect(new PTextRect(left + 10, top, 680, rowHeight, tr("CARD") + "/" + dh.getValue("f_paymentModeComment").toString(), &th, f))->textHeight();
                break;
            case PAYMENT_ROOM:
                top += ps->addTextRect(new PTextRect(left + 10, top, 680, rowHeight, dh.getValue("f_paymentModeComment").toString(), &th, f))->textHeight();
                break;
            case PAYMENT_CL:
                top += ps->addTextRect(new PTextRect(left + 10, top, 680, rowHeight, "CL/" + dh.getValue("f_paymentModeComment").toString(), &th, f))->textHeight();
                break;
            case PAYMENT_COMPLIMENTARY:
                top += ps->addTextRect(new PTextRect(left + 10, top, 680, rowHeight, dh.getValue("f_paymentModeComment").toString(), &th, f))->textHeight();
                break;
            }
        } else {
            th.setTextAlignment(Qt::AlignLeft);
            top += rowHeight;
            ps->addTextRect(left + 10, top, 400, rowHeight, tr("Room number:"), &th);
            top += 2;
            ps->addLine(left + 300, top + rowHeight, left + 600, top + rowHeight);
            top += rowHeight + 2;
            ps->addTextRect(left + 10, top, 200, rowHeight, tr("Signature"), &th);
            top += 2;
            ps->addLine(left + 300, top + rowHeight, left + 600, top + rowHeight);
        }
        top++;
        ps->addLine(left + 10, top, left + 680, top, QPen(QBrush(Qt::SolidPattern), 5));
        top += 20;

        printNewPage(top, left, page, &pp, ps);
    }

    int footerTop = sizePortrait.height() - 200;
    QBrush b(Qt::white, Qt::SolidPattern);
    PTextRect trFooter;
    trFooter.setBrush(b);
    QFont ffooter(qApp->font().family(), 20);
    trFooter.setFont(ffooter);
    trFooter.setBorders(false, false, false, false);
    trFooter.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(20, footerTop, 1800, 60, QString("%1: %2 %3")
                    .arg(tr("Printed"))
                    .arg(QDateTime::currentDateTime().toString(def_date_time_format))
                    .arg(WORKING_USERNAME), &trFooter);
    trFooter.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(1800, footerTop, 200, 60, QString("%1 %2")
                    .arg(tr("Page"))
                    .arg(page), &trFooter);
    trFooter.setTextAlignment(Qt::AlignLeft);

    pp.exec();

}

void FRestaurantTotal::removeOrder()
{
    if (!fReportGrid->fIncludes["oh.f_id"]) {
        message_error(tr("Order id must be included in the query"));
        return;
    }
    QList<QVariant> val;
    if (fReportGrid->fillRowValuesOut(val) < 0) {
        message_error(tr("Nothing was selected"));
        return;
    }
    if (message_yesnocancel(tr("Confirm to remove the order")) != RESULT_YES) {
        return;
    }
    DlgPERemoveReason *d = new DlgPERemoveReason(this);
    int state = d->exec();
    if (state == QDialog::Rejected) {
        return;
    }
    DoubleDatabase fDD;
    fDD.startTransaction();
    fDD[":f_state"] = ORDER_STATE_REMOVED;
    fDD[":f_comment"] = "Canceled by " + WORKING_USERNAME;
    fDD.update("o_header", where_id(ap(val.at(0).toString())));
    fDD[":f_state"] = state;
    fDD[":f_state_cond"] = DISH_STATE_READY;
    fDD[":f_header"] = val.at(0);
    fDD[":f_comment"] = "Canceled by " + WORKING_USERNAME;
    fDD.exec("update o_dish set f_state=:f_state, f_comment=:f_comment "
                   "where f_header=:f_header and f_state=:f_state_cond");
    fDD[":f_id"] = val.at(0);
    fDD[":f_cancelReason"] = "Canceled by " + WORKING_USERNAME;
    fDD.exec("update m_register set f_canceled=1, f_cancelReason=:f_cancelReason where f_id=:f_id");
    fDD.commit();
    message_info(tr("Please, refresh report to view the changes"));
}

void FRestaurantTotal::removePermanently()
{
    if (!fReportGrid->fIncludes["oh.f_id"]) {
        message_error(tr("Order id must be included in the query"));
        return;
    }
    QList<QVariant> val;
    if (fReportGrid->fillRowValuesOut(val) < 0) {
        message_error(tr("Nothing was selected"));
        return;
    }
    if (message_yesnocancel(tr("<h1><b>Confirm to remove the order<br>PERMANENTLY</b></h1>")) != RESULT_YES) {
        return;
    }
    removeVoucher(val.at(0).toString());
    message_info(tr("Please, refresh report to view the changes"));
}

void FRestaurantTotal::on_btnOrdersSubtotal_clicked()
{
    if (!ui->chOrderNum->isChecked()) {
        message_error(tr("Order number must be checked"));
        return;
    }
    QList<int> cols;
    cols << fReportGrid->fModel->columnIndex(tr("Qty"))
         << fReportGrid->fModel->columnIndex(tr("Total"));
    fReportGrid->fModel->insertSubTotals(0, cols);
}

void FRestaurantTotal::doubleClick(const QList<QVariant> &row)
{
    if (!ui->chOrderNum->isChecked()) {
        message_error(tr("Order number checkbox must be checked"));
        return;
    }
    if (row.count() == 0) {
        message_error(tr("Nothing is selected"));
        return;
    }
    DlgGPOSOrderInfo *d = new DlgGPOSOrderInfo(this);
    d->setOrder(row.at(0).toString());
    d->exec();
    delete d;
}

void FRestaurantTotal::on_btnPrevDate_clicked()
{
    ui->deStart->setDate(ui->deStart->date().addDays(-1));
    ui->deEnd->setDate(ui->deEnd->date().addDays(-1));
    apply(fReportGrid);
}

void FRestaurantTotal::on_btnNextDate_clicked()
{
    ui->deStart->setDate(ui->deStart->date().addDays(1));
    ui->deEnd->setDate(ui->deEnd->date().addDays(1));
    apply(fReportGrid);
}
