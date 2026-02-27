#include "rdesk.h"
#include "ui_rdesk.h"
#include "rchangelanguage.h"
#include "rchangemenu.h"
#include "rmessage.h"
#include "cachetaxmap.h"
#include "rpaymenttype.h"
#include "rselecttable.h"
#include "rdishcomment.h"
#include "paymentmode.h"
#include "dlgsmile.h"
#include "rtools.h"
#include "baseuid.h"
#include "rlogin.h"
#include "rnumbers.h"
#include "cacherights.h"
#include "rmodifiers.h"
#include "dlgreservation.h"
#include "pprintreceipt.h"
#include "ptextrect.h"
#include "dlgprinttax.h"
#include "pimage.h"
#include "pprintscene.h"
#include "dlgcomplexdish.h"
#include "cacheinvoiceitem.h"
#include "logging.h"
#include "cacherights.h"
#include "defrest.h"
#include "cacheusers.h"
#include "dlggettext.h"
#include "reportprint.h"
#include "printtax.h"
#include "dlgselecttaxcashmode.h"
#include "cachecityledger.h"
#include "dlgvoidback.h"
#include "dlglist.h"
#include "rlogin.h"
#include "cachedish.h"
#include "dlgdate.h"
#include "vauchers.h"
#include "dlgorders.h"
#include <QItemDelegate>
#include <QPrintDialog>
#include <QPrinter>
#include <QInputDialog>
#include <QPrinterInfo>
#include <QScrollBar>

QMap<int, DishStruct*> RDesk::fQuickDish;

class PartItemDelegate : public QItemDelegate {
protected:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
        painter->fillRect(option.rect, QBrush());
        if (!index.isValid()) {
            return;
        }
        DishPartStruct *p = index.data(Qt::UserRole).value<DishPartStruct*>();
        if (!p) {
            return;
        }
        if (option.state & QStyle::State_Selected) {
            painter->fillRect(option.rect, QColor::fromRgb(190, 240, 254, 255));
        }
        QFont f(qApp->font());
        f.setBold(true);
        painter->setFont(f);
        QTextOption o;
        o.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QRect textRect = option.rect;
        textRect.adjust(3, 3, -3, -3);
        painter->drawText(textRect, p->fName[def_lang], o);
    }
};

class TypeItemDelegate : public QItemDelegate {
protected:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
        painter->fillRect(option.rect, Qt::white);
        TypeStruct *t = index.data(Qt::UserRole).value<TypeStruct*>();
        if (!t) {
            return;
        }
        QTextOption o;
        o.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        o.setWrapMode(QTextOption::WordWrap);
        QBrush brush(Qt::SolidPattern);
        if (option.state & QStyle::State_Selected) {
            brush.setStyle(Qt::DiagCrossPattern);
        }
        painter->setBrush(brush);
        painter->fillRect(option.rect, QColor::fromRgb(t->fBgColor));
        if (option.state & QStyle::State_Selected) {
            painter->fillRect(option.rect, QColor::fromRgb(42,42, 42));
            painter->setPen(Qt::white);
        } else {
            painter->setPen(QColor::fromRgb(t->fTextColor));
        }
        QRect textRect = option.rect;
        textRect.adjust(3, 3, -3, -3);
        QFont f(qApp->font());
        f.setPointSize(14);
        painter->setFont(f);
        painter->drawText(textRect, t->fName[def_lang], o);
    }
};

class DishItemDelegate : public QItemDelegate {
public:
    DishItemDelegate(RDesk *desk) {
        fDesk = desk;
    }
protected:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
        painter->fillRect(option.rect, Qt::white);
        if (!index.isValid()) {
            return;
        }
        DishStruct *d = index.data(Qt::UserRole).value<DishStruct*>();
        if (!d) {
            return;
        }

        QTextOption o;
        o.setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        o.setWrapMode(QTextOption::WordWrap);
        painter->fillRect(option.rect, QColor::fromRgb(d->fBgColor));
        QRect textRect = option.rect;
        textRect.adjust(3, 3, -3, -3);
        painter->setPen(QColor::fromRgb(d->fTextColor));
        QFont f(qApp->font());
        f.setPointSize(12);
        f.setBold(true);
        painter->setFont(f);
        QString text = QString("%1 [%2]")
                .arg(d->fName[def_lang])
                .arg(QString::number(d->fPrice, 'f', 0));
        painter->drawText(textRect, text, o);
    }
private:
    RDesk *fDesk;
};

class OrderDishDelegate : public QItemDelegate {
protected:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
        painter->save();
        painter->fillRect(option.rect, Qt::white);
        if (!index.isValid()) {
            return;
        }
        OrderDishStruct *od = index.data(Qt::UserRole).value<OrderDishStruct*>();
        if (!od) {
            return;
        }
        QFont f(qApp->font());
        if (option.state & QStyle::State_Selected) {
            painter->fillRect(option.rect, QColor::fromRgb(42, 42, 42));
            painter->setPen(Qt::white);
            f.setBold(true);
            painter->setFont(f);
        } else {
            painter->setPen(QColor::fromRgb(42, 42, 42));
        }
        if (od->fState != DISH_STATE_READY) {
            f.setStrikeOut(true);
            painter->setFont(f);
        }
        QTextOption o;
        o.setWrapMode(QTextOption::WordWrap);
        switch (index.column()) {
        case 0: {
            QRect textRect = option.rect;
            textRect.adjust(2, 2, -2, -2);
            painter->drawText(textRect, od->fName[def_lang], o);
            f.setPointSize(8);
            painter->setFont(f);
            int h = QFontMetrics(f).height();
            QRect commentRect = textRect;
            commentRect.adjust(0, commentRect.height() - h - 1, 0, 0);
            painter->drawText(commentRect, od->fComment, o);
            if (od->fComplex > 0) {
                QRect imageRect = option.rect;
                imageRect.adjust(imageRect.width() - 20, imageRect.height() - 20, -5, -5);
                QImage img(":/images/dinner.png");
                painter->drawImage(imageRect, img);
            }
            break;
        }
        case 1: {
            o.setAlignment(Qt::AlignHCenter);
            QRect qtyRect = option.rect;
            qtyRect.adjust(2, 2, -2, (qtyRect.height() / 2) * -1);
            f.setBold(true);
            painter->setFont(f);
            painter->drawText(qtyRect, float_str(od->fQty, 1), o);

            QRect printRect = option.rect;
            printRect.adjust(2, (printRect.height() / 2), -2, -2);
            f.setBold(false);
            painter->setFont(f);
            painter->drawText(printRect, float_str(od->fQtyPrint, 1), o);

            painter->drawLine(qtyRect.left(), qtyRect.bottom(), qtyRect.right(), qtyRect.bottom());
            break;
        }
        case 2: {
            o.setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
            QRect totalRect = option.rect;
            totalRect.adjust(2, 2, -2, -2);
            painter->drawText(totalRect, float_str(od->fTotal, 0), o);
            break;
        }
        }
        painter->restore();
    }
};

class TotalItemDelegate : public QItemDelegate {
protected:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
        painter->setPen(Qt::white);
        QItemDelegate::paint(painter, option, index);
    }
};

RDesk::RDesk(QWidget *parent) :
    BaseExtendedDialogR(parent),
    ui(new Ui::RDesk)
{
    ui->setupUi(this);
    ui->lbRoom->setText("");
    ui->tblComplex->setVisible(false);
    fCanClose = false;
    fShowRemoved = false;
    fTable  = nullptr;
    fCloseTimeout = 0;
    ui->tblPart->setItemDelegate(new PartItemDelegate());
    ui->tblType->setItemDelegate(new TypeItemDelegate());
    ui->tblDish->setItemDelegate(new DishItemDelegate(this));
    ui->tblOrder->setItemDelegate(new OrderDishDelegate());
    ui->tblTotal->setItemDelegate(new TotalItemDelegate());
    if (fQuickDish.count() == 0) {
//        fDD[":f_hall"] = def_default_hall
    }
    fHall = Hall::getHallById(fPreferences.getDb(def_default_hall).toInt());
    /*
    fMenu = fHall->fDefaultMenu;
    setBtnMenuText();
    setupType(0);
    */
    DefRest d(HOSTNAME);
    Q_UNUSED(d)
}

RDesk::~RDesk()
{
    delete ui;
    delete fStaff;
}

void RDesk::prepareToShow()
{
    showFullScreen();
    qApp->processEvents();
}

bool RDesk::setup(TableStruct *t)
{
    int maxPartHeight = ui->tblPart->verticalHeader()->defaultSectionSize() * ui->tblPart->rowCount();
    ui->tblPart->setMaximumHeight(maxPartHeight + 2);
    ui->tblPart->horizontalHeader()->setDefaultSectionSize((ui->tblPart->width() / 2) - 2);
    int col = 0, row = 0;
    ui->tblPart->clearContents();
    for (QList<DishPartStruct*>::const_iterator it = fDishTable.fDishPart.begin(); it != fDishTable.fDishPart.end(); it++) {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setData(Qt::UserRole, QVariant::fromValue(*it));
        ui->tblPart->setItem(row, col, item);
        col++;
        if (col == 2) {
            row++;
            col = 0;
        }
        if (row == 3) {
            break;
        }
    }

    fMenu = Hall::fHallMap[t->fHall]->fDefaultMenu;
    setBtnMenuText();
    setupType(0);

    int colWidth = ui->tblDish->horizontalHeader()->defaultSectionSize();
    int colCount = ui->tblDish->width() / colWidth;
    int delta = ui->tblDish->width() - (colCount * colWidth);
    colWidth += (delta / colCount);
    ui->tblDish->horizontalHeader()->setDefaultSectionSize(colWidth);
    ui->tblDish->setColumnCount(colCount);

    ui->tblOrder->setColumnWidth(1, 40);
    ui->tblOrder->setColumnWidth(2, 60);
    ui->tblOrder->setColumnWidth(0, ui->tblOrder->width() - 104 - ui->tblOrder->verticalHeader()->width());

    ui->tblTotal->setColumnWidth(1, 70);
    ui->tblTotal->setColumnWidth(0, ui->tblTotal->width() - 72);

    bool result = false;
    if (t) {
        result = setTable(t);
    }
    connect(&fTimer, SIGNAL(timeout()), this, SLOT(timeout()));
    fTimer.start(1000 * 60 * 2);
    changeBtnState();
    return result;
}

void RDesk::setStaff(User *user)
{
    fStaff = user;
    ui->lbStaff->setText(user->fName);
    Base::fPreferences.setLocal(def_working_username, user->fName);
}

void RDesk::showHideRemovedItems()
{
    fShowRemoved = !fShowRemoved;
    for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
        OrderDishStruct *od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
        if (!od) {
            continue;
        }
        setOrderRowHidden(i, od);
    }
}

void RDesk::setOrderComment()
{
    QString comment;
    if (RDishComment::getComment(comment, this)) {
        fTable->fComment = comment;
        DoubleDatabase fDD(true, doubleDatabase);
        fDD[":f_comment"] = comment;
        fDD.update("o_header", QString("where f_id='%1'").arg(fTable->fOrder));
        TrackControl::insert(TRACK_REST_ORDER,"Set order comment", comment, "", "", fTable->fOrder, "");
    }
}

void RDesk::moveTable()
{
    int trackUser;
    if (!right(cr__o_movement, trackUser)) {
        return;
    }
    RSelectTable *t = new RSelectTable(this);
    t->setup(fTable->fHall);
    if (t->exec() == QDialog::Accepted) {
        TableStruct *table = t->table();
        if (table == fTable) {
            DlgSmile *ds = new DlgSmile(this);
            ds->exec();
            delete ds;
            return;
        }
        DoubleDatabase fDD(true, doubleDatabase);
        fDD.startTransaction();
        fDD.exec(QString("select f_id from r_table where f_id in (%1, %2) for update")
                .arg(fTable->fId)
                .arg(table->fId));
        if (!table->fOrder.isEmpty()) {
            if (!message_question(tr("Destination table is not empty, continue with merge?"))) {
                return;
            }
            fDD.exec(QString("update o_dish set f_header='%1' where f_header='%2'")
                            .arg(table->fOrder)
                            .arg(fTable->fOrder));
            fDD.exec(QString("update o_header set f_state=%1 where f_id='%2'")
                            .arg(ORDER_STATE_MOVED)
                            .arg(fTable->fOrder));
            TrackControl::insert(TRACK_REST_ORDER, "Table moved from",
                                      QString("%1/%2").arg(table->fName).arg(table->fOrder),
                                      QString("%1/%2").arg(fTable->fName).arg(fTable->fOrder), "", fTable->fOrder, "");
        } else {
            fDD[":f_table"] = table->fId;
            fDD.update("o_header", where_id(ap(fTable->fOrder)));
        }

        fDD.exec(QString("update r_table set f_lockTime=0, f_lockHost='', f_order='' where f_id=%1")
                        .arg(fTable->fId));
        fDD.exec(QString("update r_table set f_order='%1' where f_id=%2")
                        .arg(table->fOrder.isEmpty() ? fTable->fOrder : table->fOrder)
                        .arg(table->fId));
        TrackControl::insert(TRACK_REST_ORDER, "Table moved to",
                                  QString("%1/%2").arg(fTable->fName).arg(fTable->fOrder),
                                  QString("%1/%2").arg(table->fName).arg(table->fOrder.isEmpty() ? fTable->fOrder : table->fOrder),
                             "", fTable->fOrder, "");
        fDD.commit();
        fTable->fOrder.clear();
        if (setTable(table)) {
            fHall = Hall::getHallById(fTable->fHall);
            if (fMenu != fHall->fDefaultMenu) {
                fMenu = fHall->fDefaultMenu;
                setBtnMenuText();
                setupType(0);
            }
        }
    }
    delete t;
    changeBtnState();
}

void RDesk::removeOrder()
{
    int trackUser = fStaff->fId;
    if (!g__(cr__o_cancelation, trackUser)) {
        return;
    }
    if (message_question(tr("Confirm remove whole order")) != QDialog::Accepted) {
        return;
    }
    QString name, sql = "select f_id, f_en from o_dish_state where f_id in (2, 3)";
    QVariant result;
    if (!DlgList::getValue(tr("STORE OPTION"), name, result, sql)) {
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
        OrderDishStruct *od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
        if (od->fState == DISH_STATE_READY && od->fQtyPrint > 0.1) {
            fDD[":f_state"] = result.toInt();
            fDD[":f_cancelUser"] = trackUser;
            fDD[":f_cancelDate"] = QDateTime::currentDateTime();
            fDD.update("o_dish", where_id(ap(od->fRecId)));
            printRemovedDish(od, od->fQty - od->fQtyPrint, trackUser);
        } else if (od->fState == DISH_STATE_READY) {
            fDD[":f_state"] = DISH_STATE_EMPTY;
            fDD[":f_cancelUser"] = trackUser;
            fDD[":f_cancelDate"] = QDateTime::currentDateTime();
            fDD.update("o_dish", where_id(ap(od->fRecId)));
        }
        if (od->fState == DISH_STATE_READY) {
            QString dish = QString("%1, %2/%3")
                    .arg(od->fName["en"])
                    .arg(od->fQty)
                    .arg(od->fQtyPrint);
            TrackControl::insert(TRACK_REST_ORDER, "Dish removed with order", dish, "", od->fRecId, fTable->fOrder, "");
        }
    }
    TrackControl::insert(TRACK_REST_ORDER, "Order canceled", "", "", "", fTable->fOrder, "");
    closeOrder(ORDER_STATE_REMOVED);
}

void RDesk::showTableOrders()
{

}

void RDesk::showMyTotal()
{
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_dateCash"] = fPreferences.getLocalDate(def_working_day);
    fDD[":f_staff"] = fStaff->fId;
    fDD[":f_state"] = ORDER_STATE_CLOSED;
    fDD.exec("select i.f_" + def_lang + ", sum(d.f_total) "
               "from o_dish d "
               "inner join o_header h on h.f_id=d.f_header "
               "inner join f_invoice_item i on i.f_id=h.f_paymentMode "
               "where h.f_dateCash=:f_dateCash and h.f_staff=:f_staff and h.f_state=:f_state "
               "group by 1");
    QString msg;
    while (fDD.nextRow()) {
        msg += fDD.getString(0) + " - " + fDD.getString(1) + "<br> ";
    }
    message_info(msg);

}

void RDesk::recover()
{
    int trackUser;
    if (!right(cr__o_recover_order, trackUser)){
        message_error(tr("Access denied"));
        return;
    }
    QString ordNum;
    if (!DlgGetText::getText(ordNum, "PS-")) {
        return;
    }
    if (ordNum.trimmed().isEmpty()) {
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_id"] = ordNum;
    fDD.exec("select f_staff, f_dateCash, f_total, f_table from o_header where f_id=:f_id");
    if (!fDD.nextRow()) {
        message_error(tr("Invalid order id"));
        return;
    }
    if (WORKING_DATE > fDD.getDate(1)) {
        message_error(tr("Order is not in current working date"));
        return;
    }
    int table = fDD.getInt(3);
    int staff = fDD.getInt(0);
    double amount = fDD.getDouble(2);
    fDD[":f_id"] = fDD.getInt(3);
    fDD.exec("select f_order from r_table where f_id=:f_id");
    if (!fDD.nextRow()) {
        message_error(tr("Invalid order id"));
        return;
    }
    int orderId = fDD.getInt(0);
    if (orderId > 0) {
        message_error(tr("Table is busy, try again later"));
        return;
    }
    CacheUsers u;
    u.get(staff);
    QString q = QString("Table %1<br>Staff %2<br>Amount %3")
            .arg(Hall::fTablesMap[table]->fName)
            .arg(u.fFull())
            .arg(amount);
    if (message_question(q) != QDialog::Accepted) {
        return;
    }
    fDD[":f_order"] = ordNum;
    fDD.update("r_table", where_id(table));
    fDD[":f_state"] = ORDER_STATE_OPENED;
    fDD.update("o_header", where_id(ap(ordNum)));
    QString rrId = uuidx(VAUCHER_RECOVER_N);
    fDD[":f_id1"] = rrId;
    fDD[":f_source1"] = VAUCHER_RECOVER_N;
    fDD[":f_itemCode"] = 41;
    fDD[":f_finalName"] = tr("RECOVER FOR ") + ordNum;
    fDD[":f_finance"] = 0;
    fDD[":f_id"] = ordNum;
    fDD.exec("update m_register set f_id=:f_id1, f_source=:f_source1, f_finance=:f_finance, f_itemCode=:f_itemCode "
               "where f_id=:f_id");
    if (fTable) {
        if (table == fTable->fId) {
            fTable = 0;
            TableStruct *t = Hall::fTablesMap[table];
            setTable(t);
        }
    }
    message_info(tr("Table was successful recovered"));

}

void RDesk::initialCash()
{
    float num;
    DoubleDatabase fDD(true, doubleDatabase);
    if (RNumbers::getNumber(num, 100000, this)) {
        fDD.startTransaction();
        fDD[":f_date"] = fPreferences.getLocalDate(def_working_day);
        fDD[":f_staff"] = fStaff->fId;
        fDD.exec("delete from o_initial_cash where f_date=:f_date and f_staff=:f_staff");
        fDD[":f_date"] = fPreferences.getLocalDate(def_working_day);
        fDD[":f_staff"] = fStaff->fId;
        fDD[":f_amount"] = num;
        fDD.insert("o_initial_cash", false);
        fDD.commit();
    }
}

void RDesk::setComplexMode()
{
    DishComplexStruct *dc = DlgComplexDish::complex(this);
    if (dc) {
        checkOrderHeader(fTable, 0, false);
        DoubleDatabase fDD(true, doubleDatabase);
        fDD[":f_header"] = fTable->fOrder;
        fDD[":f_state"] = DISH_STATE_READY;
        fDD[":f_dish"] = dc->fId;
        fDD[":f_qty"] = dc->fQty;
        fDD[":f_qtyPrint"] = dc->fQty;
        fDD[":f_price"] = dc->fPrice;
        fDD[":f_svcValue"] = 0;
        fDD[":f_svcAmount"] = 0;
        fDD[":f_dctValue"] = 0;
        fDD[":f_dctAmount"] = 0;
        fDD[":f_total"] = dc->fPrice;
        fDD[":f_print1"] = "";
        fDD[":f_print2"] = "";
        fDD[":f_store"] = 0;
        fDD[":f_comment"] = "";
        fDD[":f_staff"] = fStaff->fId;
        fDD[":f_complex"] = dc->fId;
        fDD[":f_complexId"] = dc->fId;
        fDD[":f_adgt"] = dc->fAdgt;
        if (dc->fRecId.isEmpty()) {
            dc->fRecId = uuidx("DR");
            fDD[":f_id"] = dc->fRecId;
            fDD.insert("o_dish", false);
            if (dc->fRecId.isEmpty()) {
                message_error("Application will quit due an program error.");
                qApp->quit();
                return;
            }
        } else {
            fDD.update("o_dish", where_id(ap(dc->fRecId)));
        }
        TrackControl::insert(TRACK_REST_ORDER, "New complex begin", dc->fName["en"], "----", "", fTable->fOrder, "");
        for (int i = 0; i < dc->fDishes.count(); i++) {
            dc->fDishes[i]->fComplexRec = dc->fRecId;
            dc->fDishes[i]->fComplex = dc->fId;
            dc->fDishes[i]->fPrice = 0;
            addDishToOrder(dc->fDishes[i]);
        }
        ui->tblComplex->setRowCount(ui->tblComplex->rowCount() + 1);
        ui->tblComplex->setItem(ui->tblComplex->rowCount() - 1, 0, new QTableWidgetItem());
        ui->tblComplex->item(ui->tblComplex->rowCount() - 1, 0)->setData(Qt::UserRole, QVariant::fromValue(dc));
        countTotal();
        TrackControl::insert(TRACK_REST_ORDER, "New complex end", dc->fName["en"], "----", "", fTable->fOrder, "");
    }
}

void RDesk::closeOrder(int state)
{
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_staff"] = fStaff->fId;
    fDD[":f_state"] = state;
    fDD[":f_dateCash"] = WORKING_DATE;
    fDD[":f_dateClose"] = QDateTime::currentDateTime();
    fDD.update("o_header", where_id(ap(fTable->fOrder)));
    fDD[":f_order"] = "";
    fDD.update("r_table", where_id(ap(fTable->fId)));
    fDD[":f_id"] = fTable->fOrder;

    fDD.exec("select f_tax from o_Header where f_id=:f_id");
    if (fDD.nextRow()) {
        fDD[":f_fiscal"] = fDD.getValue("f_tax").toInt();
        fDD.update("m_register", where_id(ap(fTable->fOrder)));
    }
    clearOrder();
}

void RDesk::printTotalToday()
{
    int trackUser;
    QString userName = fStaff->fName;
    if (!right(cr__o_print_reports, trackUser)) {
        return;
    }
    CacheUsers u;
    if (u.get(trackUser)) {
        userName = u.fFull();
    }
    ReportPrint::printTotal(WORKING_DATE, userName, fHall->fReceiptPrinter);
}

void RDesk::printTotalYesterday()
{
    int trackUser;
    QString userName = fStaff->fName;
    if (!right(cr__o_print_reports, trackUser)) {
        return;
    }
    CacheUsers u;
    if (u.get(trackUser)) {
        userName = u.fFull();
    }
    ReportPrint::printTotal(WORKING_DATE.addDays(-1), userName, fHall->fReceiptPrinter);
}

void RDesk::printTotalAnyDay()
{
    int trackUser;
    QString userName = fStaff->fName;
    if (!right(cr__print_reports_any_day, trackUser)) {
        return;
    }
    QDate date;
    if (!DlgDate::getDate(date)) {
        return;
    }
    CacheUsers u;
    if (u.get(trackUser)) {
        userName = u.fFull();
    }
    ReportPrint::printTotal(date, userName, fHall->fReceiptPrinter);
}

int RDesk::printTax(int cashMode)
{
    CacheInvoiceItem ii;
    if (!ii.get(fHall->fItemIdForInvoice)) {
        message_error(tr("No invoice item defined for this station"));
        return 0;
    }
    CacheTaxMap tm;
    if (!tm.get(ii.fCode())) {
        message_error(tr("No tax code define for ") + ii.fCode());
        return 0;
    }
    //Print tax
    if (fPreferences.getDb(def_tax_port).toInt() == 0) {
        message_error(tr("Setup tax printer first"));
        return 0;
    }

    QString taxpayer;
    taxpayer = QInputDialog::getText(this, tr("Enter taxpayer pin"), tr("Taxpayer pin"));

    int taxCode = 0;
    int result = DlgPrintTax::printTax(fHall->fVatDept, fTable->fOrder, (cashMode == tax_mode_cash ? 0 : fTable->fAmount.toDouble()), taxCode, taxpayer);
    if (result != TAX_OK) {
        return 0;
    }

    fTable->fTaxPrint = 1;
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_tax"] = taxCode;
    fDD.update("o_header", where_id(ap(fTable->fOrder)));

    for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
        OrderDishStruct *od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
        if (!od) {
            continue;
        }
        if (od->fState != DISH_STATE_READY) {
            continue;
        }
        if (od->fComplex > 0) {
            continue;
        }
        fDD[":f_vaucher"] = fTable->fOrder;
        fDD[":f_invoice"] = "";
        fDD[":f_date"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_name"] = od->fName["en"];
        fDD[":f_amountCash"] = cashMode == tax_mode_cash ? fTable->fAmount : "0";
        fDD[":f_amountCard"] = cashMode == tax_mode_cash ? "0" : fTable->fAmount;
        fDD[":f_amountPrepaid"] = 0;
        fDD[":f_user"] = fStaff->fId;
        DoubleDatabase did;
        did.open(true, true);
        did[":f_id"] = 0;
        int id = did.insert("m_tax_history", true);
        fDD.update("m_tax_history", where_id(id));
    }
    for (int i = 0; i < ui->tblComplex->rowCount(); i++) {
        DishComplexStruct *dc = ui->tblComplex->item(i, 0)->data(Qt::UserRole).value<DishComplexStruct*>();
        if (!dc) {
            message_error("Application error. Contact to developer. Message: dc ==0, print tax");
            return false;
        }
        fDD[":f_vaucher"] = fTable->fOrder;
        fDD[":f_invoice"] = 0;
        fDD[":f_date"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_name"] = dc->fName["en"];
        fDD[":f_amountCash"] = cashMode == tax_mode_cash ? fTable->fAmount : "0";
        fDD[":f_amountCard"] = cashMode == tax_mode_cash ? "0" : fTable->fAmount;
        fDD[":f_amountPrepaid"] = 0;
        fDD[":f_user"] = fStaff->fId;
        DoubleDatabase did;
        did.open(true, true);
        did[":f_id"] = 0;
        int id = did.insert("m_tax_history", true);
        fDD.update("m_tax_history", where_id(id));
    }
    return taxCode;
}

void RDesk::printTaxDialog()
{
    int trackUser = fStaff->fId;
    if (!g__(cr__print_any_tax, trackUser)) {
        return;
    }
    DlgOrders *d = new DlgOrders(fStaff->fId, this);
    d->exec();
    delete d;
}

void RDesk::printReceiptByNumber()
{
    int trackUser = fStaff->fId;
    if (!g__(cr__print_receipt_by_umber, trackUser)) {
        return;
    }
    QString userName = fStaff->fName;
    CacheUsers u;
    if (u.get(trackUser)) {
        userName = u.fFull();
    } else {
        userName = "#Username Error";
    }
    QString ordNum;
    if (!DlgGetText::getText(ordNum, "PS-")) {
        return;
    }
    if (ordNum.trimmed().isEmpty()) {
        return;
    }
    PPrintReceipt::printOrder(fHall->fReceiptPrinter, ordNum, trackUser);

}

void RDesk::voidBack()
{
    int trackUser = fStaff->fId;
    if (!g__(cr__o_cancelation, trackUser)) {
        return;
    }
    DlgVoidBack::recover();
    if (fTable) {
        loadOrder();
    }
}

void RDesk::printVoidReport()
{
    int trackUser = fStaff->fId;
    if (!g__(cr__o_print_reports, trackUser)) {
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_dateCash"] = WORKING_DATE;
    fDD.exec("select oh.f_id, h.f_name as hname, t.f_name as tname, concat(u1.f_firstName, ' ' , u1.f_lastName) as staff, \
              ds.f_en as state, d.f_en as dish, od.f_qty, od.f_total, \
              concat(u2.f_firstName, ' ', u2.f_lastName) as staffcancel \
              from o_dish od \
              left join o_header oh on oh.f_id=od.f_header \
              left join r_hall h on h.f_id=oh.f_hall \
              left join o_dish_state ds on ds.f_id=od.f_state \
              left join r_table t on t.f_id=oh.f_table \
              left join users u1 on u1.f_id=oh.f_staff \
              left join r_dish d on d.f_id=od.f_dish \
              left join users u2 on u2.f_id=od.f_cancelUser \
              where od.f_state in (2, 3) and oh.f_dateCash=:f_dateCash \
              order by 1");

    QList<PPrintScene*> lps;
    PPrintScene *ps = new PPrintScene(Portrait);
    lps.append(ps);
    PTextRect th;
    QFont f("Arial", 30);
    th.setTextAlignment(Qt::AlignHCenter);
    th.setFont(f);
    th.setBorders(false, false, false, false);
    int top = 10;
    th.setTextAlignment(Qt::AlignHCenter);
    int rowHeight = 60;
    PImage *logo = new PImage("logo_print.png");
    ps->addItem(logo);
    logo->setRect(QRectF(200, top, 400, 250));
    top += 250;
    top += ps->addTextRect(new PTextRect(10, top, 750, rowHeight, QString("%1").arg(tr("VOID REPORT")), &th, f))->textHeight();
    top += ps->addTextRect(10, top, 680, rowHeight, WORKING_DATE.toString(def_date_format), &th)->textHeight();
    f.setPointSize(24);
    th.setFont(f);
    CacheUsers u;
    u.get(trackUser);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("Printed by ") + u.fFull(), &th)->textHeight();
    top += ps->addTextRect(0, top, 680, rowHeight, tr("Date") + ": " + WORKING_DATE.toString(def_date_format), &th)->textHeight();
    ps->addLine(10, top, 750, top);

    th.setTextAlignment(Qt::AlignLeft);

    QPen dotPen(Qt::DotLine);
    for (int i = 0; i < fDD.rowCount(); i++) {
        QString row = QString("%1 / %2 / #%3")
                .arg(fDD.getValue(i, "hname").toString())
                .arg(fDD.getValue(i, "tname").toString())
                .arg(fDD.getValue(i, "f_id").toString());
        top += ps->addTextRect(10, top, 680, rowHeight, row, &th)->textHeight();
        ps->addLine(10, top, 680, top, dotPen);
        row = QString ("%1 / %2 / %3")
                .arg(fDD.getValue(i, "dish").toString())
                .arg(fDD.getValue(i, "f_qty").toString())
                .arg(fDD.getValue(i, "f_total").toString());
        top += ps->addTextRect(10, top, 680, rowHeight, row, &th)->textHeight();
        row = QString("%1").arg(fDD.getValue(i, "staff").toString());
        top += ps->addTextRect(10, top, 680, rowHeight, row, &th)->textHeight();
        top += ps->addTextRect(10, top, 680, rowHeight, tr("Type: ") + fDD.getValue(i, "state").toString(), &th)->textHeight();
        top += ps->addTextRect(10, top, 680, rowHeight, tr("Manager"), &th)->textHeight();
        top += ps->addTextRect(10, top, 680, rowHeight, fDD.getValue(i, "staffcancel").toString(), &th)->textHeight();
        top ++;
        ps->addLine(10, top, 680, top, dotPen);
        top += 2;
        ps->addLine(10, top, 680, top, dotPen);
        top += rowHeight;
        if (top > sizePortrait.height() - 200) {
            top = 10;
            ps = new PPrintScene(Portrait);
            lps.append(ps);
        }
    }

    ps->addTextRect(10, top, 300, rowHeight, "_", &th);


    QPrinter printer;
    printer.setPrinterName(fHall->fReceiptPrinter);
    QMatrix m;
    m.scale(3, 3);
    QPainter painter(&printer);
    painter.setMatrix(m);
    for (int i = 0; i < lps.count(); i++) {
        if (i > 0) {
            printer.newPage();
        }
        lps[i]->render(&painter);
    }
    qDeleteAll(lps);
}

void RDesk::complimentary()
{
    int trackUser = fStaff->fId;
    if (!g__(cr__o_complimentary, trackUser)) {
        return;
    }
    QString comment, sql = "select f_id, f_name from r_complimentary_comment";
    QVariant result;
    if (!DlgList::getValue(tr("Complimentary comment"), comment, result, sql)) {
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_paymentMode"] = PAYMENT_COMPLIMENTARY;
    fDD[":f_paymentModeComment"] = tr("Complimentary");
    fDD.update("o_header", where_id(ap(fTable->fOrder)));
    fTable->fPaymentComment = comment;
    fTable->fPaymentMode = PAYMENT_COMPLIMENTARY;

    fDD[":f_id"] = fTable->fOrder;
    fDD[":f_source"] = VAUCHER_POINT_SALE_N;
    fDD[":f_wdate"] = WORKING_DATE;
    fDD[":f_rdate"] = QDate::currentDate();
    fDD[":f_time"] = QTime::currentTime();
    fDD[":f_user"] = fStaff->fId;
    fDD[":f_room"] = "";
    fDD[":f_guest"] = "";
    fDD[":f_itemCode"] = fHall->fItemIdForInvoice;
    fDD[":f_finalName"] = Hall::fHallMap[fTable->fHall]->fName + " " + fTable->fOrder;
    fDD[":f_amountAmd"] = QLocale().toDouble(ui->tblTotal->item(1, 1)->data(Qt::EditRole).toString());
    fDD[":f_amountVat"] = Utils::countVATAmount(QLocale().toDouble(ui->tblTotal->item(1, 1)->data(Qt::EditRole).toString()), VAT_INCLUDED);
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = 0;
    fDD[":f_paymentMode"] = fTable->fPaymentMode;
    fDD[":f_creditCard"] = 0;
    fDD[":f_cityLedger"] = 0;
    fDD[":f_paymentComment"] = "";
    fDD[":f_dc"] = PAY_DEBIT ;
    fDD[":f_sign"] = 1;
    fDD[":f_doc"] = fTable->fOrder;
    fDD[":f_rec"] = "";
    fDD[":f_inv"] = "";
    fDD[":f_finance"] = 1;
    fDD[":f_remarks"] = "";
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    fDD[":f_side"] = 0;
    fDD[":f_cash"] = 0;
    fDD.insert("m_register", false);
    printReceipt(true);
    closeOrder();
}

void RDesk::changePassword()
{
    QString login;
    if (RLogin::getLogin(login, tr("Login"), this)) {
        QString query = QString("update users set f_altPassword='' where f_altPassword=md5('%1')")
                .arg(login);
        DoubleDatabase fDD(true, doubleDatabase);
        fDD.exec(query);
        query = QString("update users set f_altPassword=md5('%1') where f_id=%2")
                .arg(login)
                .arg(fStaff->fId);
        fDD.exec(query);
        message_info(tr("Your password was changed"));
    }
}

void RDesk::openTools()
{
    RTools *t = new RTools(this);
    t->setNoTable();
    if (t->exec() == QDialog::Accepted) {

    }
    delete t;
}

void RDesk::closeEvent(QCloseEvent *e)
{
    if (!fCanClose) {
        e->ignore();
        return;
    }
    checkEmpty();
    BaseExtendedDialogR::closeEvent(e);
}

void RDesk::onBtnQtyClicked()
{
    fCloseTimeout = 0;
    QModelIndexList sel = ui->tblOrder->selectionModel()->selectedRows();
    if (sel.count() == 0) {
        return;
    }
    QPushButton *b = static_cast<QPushButton*>(sender());
    float qty;
    if (b->text() == "-0.5") {
        qty = -0.5;
    } else if (b->text() == "+0.5") {
        qty = 0.5;
    } else {
        qty = b->text().toFloat();
    }
    OrderDishStruct *od = sel.at(0).data(Qt::UserRole).value<OrderDishStruct*>();
    if (!od) {
        return;
    }
    if (od->fState != DISH_STATE_READY) {
        message_error(tr("You cannot edit the quantity of selected item"));
        return;
    }
    if (od->fDishId == Hall::getHallById(fTable->fHall)->fServiceItem) {
        return;
    }
    if (od->fQty + qty < 0.1) {
        return;
    }
    if (od->fComplex == 0) {
        QString oldQty = QString("%1, %2 / %3").arg(od->fName[def_lang])
                .arg(od->fQty)
                .arg(od->fQtyPrint);
        if (od->fQtyPrint < 0.01) {
            if (qty > 0.9) {
                if (qty < 10.0) {
                    od->fQty = qty;
                } else {
                    od->fQty += qty;
                }
            } else {
                od->fQty += qty;
            }
        } else {
            od->fQty += qty;
        }
        QString newQty = QString("%1, %2 / %3").arg(od->fName[def_lang])
                .arg(od->fQty)
                .arg(od->fQtyPrint);
        countDish(od);
        TrackControl::insert(TRACK_REST_ORDER, "Dish qty", oldQty, newQty, od->fRecId, fTable->fOrder, "");
        updateDish(od);
    } else {
        double complexQty = 0;
        DishComplexStruct *dc = nullptr;
        for (int i = 0; i < ui->tblComplex->rowCount(); i++) {
            DishComplexStruct *dt = ui->tblComplex->item(i, 0)->data(Qt::UserRole).value<DishComplexStruct*>();
            if (dt->fRecId == od->fComplexRecId) {
                dc = dt;
                break;
            }
        }
        if (!dc) {
            message_error("Application error. Contact to developer, message: dc ==0, dish qty");
            return;
        }
        QString oldQty = QString("%1, %2").arg(dc->fName[def_lang])
                .arg(dc->fQty);
        for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
            od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
            if (od->fComplexRecId != dc->fRecId) {
                continue;
            }
            QString odOldQty = QString("%1, %2 / %3").arg(od->fName[def_lang])
                    .arg(od->fQty)
                    .arg(od->fQtyPrint);
            if (od->fQtyPrint < 0.01) {
                if (qty > 0.9){
                    od->fQty = qty;
                } else {
                    od->fQty += qty;
                }
            } else {
                od->fQty += qty;
            }
            complexQty = od->fQty;
            QString odNewQty = QString("%1, %2 / %3").arg(od->fName[def_lang])
                    .arg(od->fQty)
                    .arg(od->fQtyPrint);
            TrackControl::insert(TRACK_REST_ORDER, "Dish qty", odOldQty, odNewQty, od->fRecId, fTable->fOrder, "");
            countDish(od);
            updateDish(od);
        }
        dc->fQty = complexQty;
        DoubleDatabase fDD(true, doubleDatabase);
        fDD[":f_qty"] = dc->fQty;
        fDD[":f_total"] = dc->fPrice * dc->fQty;
        fDD.update("o_dish", where_id(ap(dc->fRecId)));
        QString newQty = QString("%1, %2").arg(dc->fName[def_lang])
                .arg(dc->fQty);
        TrackControl::insert(TRACK_REST_ORDER, "Complex qty", oldQty, newQty, "", fTable->fOrder, "");
    }
    resetPrintQty();
    ui->tblOrder->viewport()->update();
    countTotal();
    changeBtnState();
}

void RDesk::timeout()
{
    if (fTable) {
        QString query = QString("update r_table set f_lockTime=%1, f_lockHost='%2' where f_id=%3")
                .arg(QDateTime::currentDateTime().toTime_t())
                .arg(Utils::hostName())
                .arg(fTable->fId);
        DoubleDatabase fDD(true, doubleDatabase);
        fDD.exec(query);
    }
    fCloseTimeout++;
    if (fCloseTimeout > 5) {
        on_btnExit_clicked();
    }
}

void RDesk::on_btnExit_clicked()
{
    if (fTable) {
        DoubleDatabase fDD(true, doubleDatabase);
        fDD[":f_id"] = fTable->fId;
        if (!fDD.exec("select f_id from r_table where f_id=:f_id for update")) {
            message_error(tr("Cannot close current table, try later"));
            return;
        }
        fDD[":f_lockTime"] = 0;
        fDD[":f_lockHost"] = "";
        fDD.update("r_table", QString("where f_id=%1").arg(fTable->fId));
        checkUnprinted();
    }
    fCanClose = true;
    close();
}

void RDesk::on_btnLanguage_clicked()
{
    if (RChangeLanguage::changeLanguage(this)) {
        ui->tblPart->viewport()->update();
        ui->tblType->viewport()->update();
        ui->tblDish->viewport()->update();
        ui->tblOrder->viewport()->update();
    }
}

void RDesk::on_btnMenu_clicked()
{
    int newMenu;
    if (RChangeMenu::changeMenu(fMenu, newMenu, this)) {
        fMenu = newMenu;
        setBtnMenuText();
        setupType(0);
    }
}

void RDesk::setBtnMenuText()
{
    if (fMenu == 0) {
        message_error(tr("Default menu is not set"));
        return;
    }
    ui->btnMenu->setText(QString("%1\r\n%2")
                         .arg(tr("Menu"))
                         .arg(fDishTable.fMenu[fMenu]->fName[def_lang]));
}

void RDesk::setupType(int partId)
{
    writelog("RDesk::setupType start.");
    QMap<int, TypeStruct*> type;
    fDishTable.filterType(fMenu, partId, type);
    ui->tblDish->clear();
    ui->tblDish->setRowCount(0);
    ui->tblType->clear();
    ui->tblType->setColumnCount(2);
    ui->tblType->horizontalHeader()->setDefaultSectionSize((ui->tblType->width() - 10)  /2);
    int row = -1, col = 3;
    for (QMap<int, TypeStruct*>::const_iterator it = type.begin(); it != type.end(); it++) {
        if (col > ui->tblType->columnCount() - 1) {
            col = 0;
            row ++;
            ui->tblType->setRowCount(row + 1);
        }
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setData(Qt::UserRole, QVariant::fromValue(it.value()));
        ui->tblType->setItem(row, col++, item);
    }
    writelog("RDesk::setupType end.");
}

void RDesk::setupDish(int typeId)
{
    ui->tblDish->clear();
    QMap<int, DishStruct*> dish;
    fDishTable.filterDish(fMenu, typeId, dish);
    int rowCount = (dish.count() / ui->tblDish->columnCount());
    if (dish.count() % ui->tblDish->columnCount() > 0) {
        rowCount++;
    }
    ui->tblDish->setRowCount(rowCount);
    int col = 0, row = 0;
    for (QMap<int, DishStruct*>::const_iterator it = dish.begin(); it != dish.end(); it++) {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setData(Qt::UserRole, QVariant::fromValue(*it));
        ui->tblDish->setItem(row, col++, item);
        if (col == ui->tblDish->columnCount()) {
            row++;
            col = 0;
        }
    }
}

void RDesk::addDishToOrder(DishStruct *d, bool dontCheckTable)
{
    checkOrderHeader(fTable, d, dontCheckTable);
    OrderDishStruct *od = new OrderDishStruct();
    if (d->fMod.count() > 0) {
        QStringList mods;
        for (QList<QMap<QString, QString> >::const_iterator it = d->fMod.begin(); it != d->fMod.end(); it++) {
            mods.append(it->value(def_lang));
        }
        RModifiers *m = new RModifiers(this);
        m->setModifiers(mods);
        if (m->exec() == QDialog::Accepted) {
            od->fComment = m->mod();
        }
        delete m;
    }
    od->fDishId = d->fId;
    od->fState = DISH_STATE_READY;
    od->fPrint1 = d->fPrint1;
    od->fPrint2 = d->fPrint2;
    od->fStore = d->fStore;
    od->fName = d->fName;
    od->fPrice = d->fPrice;
    od->fSvcValue = fHall->fDefaultSvcValue;
    od->fSvcAmount = od->fSvcValue * od->fTotal;
    od->fDctValue = 0;
    od->fDctAmount = 0;
    od->fQty = 1;
    od->fQtyPrint = 0;
    od->fComplex = d->fComplex;
    od->fComplexRecId = d->fComplexRec;
    od->fAdgt = d->fAdgt;
    od->fSvcValue = d->fSvcValue;

    countDish(od);
    od->fRecId = uuidx("DR");
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_header"] = fTable->fOrder;
    fDD[":f_state"] = DISH_STATE_READY;
    fDD[":f_dish"] = od->fDishId;
    fDD[":f_qty"] = od->fQty;
    fDD[":f_qtyPrint"] = od->fQtyPrint;
    fDD[":f_price"] = od->fPrice;
    fDD[":f_svcValue"] = od->fSvcValue;
    fDD[":f_svcAmount"] = od->fSvcAmount;
    fDD[":f_dctValue"] = od->fDctValue;
    fDD[":f_dctAmount"] = od->fDctAmount;
    fDD[":f_total"] = od->fTotal;
    fDD[":f_totalUSD"] = od->fTotal / def_usd;
    fDD[":f_print1"] = od->fPrint1;
    fDD[":f_print2"] = od->fPrint2;
    fDD[":f_store"] = od->fStore;
    fDD[":f_comment"] = od->fComment;
    fDD[":f_staff"] = fStaff->fId;
    fDD[":f_complex"] = od->fComplex;
    fDD[":f_complexId"] = 0;
    fDD[":f_adgt"] = od->fAdgt;
    fDD[":f_complexRec"] = od->fComplexRecId;
    fDD[":f_id"] = od->fRecId;
    fDD.insert("o_dish", false);
    updateDishQtyHistory(od);
    addDishToTable(od);
    countTotal();
    resetPrintQty();
    TrackControl::insert(TRACK_REST_ORDER, "New dish", od->fName["en"], "", od->fRecId, fTable->fOrder, "");
}

void RDesk::addDishToTable(OrderDishStruct *od)
{
    int row = ui->tblOrder->rowCount();
    ui->tblOrder->setRowCount(row + 1);
    for (int i = 0; i < 3; i++) {
        ui->tblOrder->setItem(row, i, new QTableWidgetItem());
    }
    ui->tblOrder->item(row, 0)->setData(Qt::UserRole, QVariant::fromValue(od));
    ui->tblOrder->item(row, 1)->setData(Qt::UserRole, QVariant::fromValue(od));
    ui->tblOrder->item(row, 2)->setData(Qt::UserRole, QVariant::fromValue(od));
    ui->tblOrder->setCurrentCell(row, 0);
    setOrderRowHidden(row, od);
    changeBtnState();
}

void RDesk::updateDish(OrderDishStruct *od)
{
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_state"] = od->fState;
    fDD[":f_qty"] = od->fQty;
    fDD[":f_qtyPrint"] = od->fQtyPrint;
    fDD[":f_price"] = od->fPrice;
    fDD[":f_svcValue"] = od->fSvcValue;
    fDD[":f_svcAmount"] = od->fSvcAmount;
    fDD[":f_dctValue"] = od->fDctValue;
    fDD[":f_dctAmount"] = od->fDctAmount;
    fDD[":f_total"] = od->fTotal;
    fDD[":f_totalUSD"] = od->fTotal / def_usd;
    fDD[":f_comment"] = od->fComment;
    fDD[":f_cancelUser"] = od->fCancelUser;
    fDD[":f_cancelDate"] = od->fCancelDate;
    fDD.update("o_dish", QString("where f_id='%1'").arg(od->fRecId));
    updateDishQtyHistory(od);
}

double RDesk::countTotal()
{
    double total = 0;
    OrderDishStruct *serv = nullptr;
    for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
        OrderDishStruct *od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
        if (!od) {
            continue;
        }
        if (od->fState != DISH_STATE_READY) {
            continue;
        }
        if (od->fDishId == Hall::getHallById(fTable->fHall)->fServiceItem) {
            serv = od;
            continue;
        }
//        if (od->fComplex > 0 ) {
//            continue;
//        }
        total += od->fPrice * od->fQtyPrint;
    }
    for (int i = 0; i < ui->tblComplex->rowCount(); i++) {
        DishComplexStruct *dc = ui->tblComplex->item(i, 0)->data(Qt::UserRole).value<DishComplexStruct*>();
        if (!dc) {
            message_error("Application error. Contact to developer. Message: dc == 0, countTotal");
            return -1;
        }
        total += dc->fPrice * dc->fQty;
    }
    double grandTotal = total ;
    if (serv) {
        serv->fPrice = grandTotal * Hall::getHallById(fTable->fHall)->fDefaultSvcValue;
        serv->fTotal = serv->fPrice;
        updateDish(serv);
        grandTotal += serv->fTotal;
    }
    ui->tblTotal->item(1, 1)->setData(Qt::EditRole, float_str(grandTotal, 0));
    fTable->fAmount = QString::number(grandTotal, 'f', 2);

    if (!fTable->fOrder.isEmpty()) {
        DoubleDatabase dd;
        dd.open(true, true);
        dd[":f_total"] = grandTotal;
        dd.update("o_header", where_id(ap(fTable->fOrder)));
        dd.close();
    }

    return grandTotal;
}

bool RDesk::checkQtyBeforeReceipt()
{
    OrderDishStruct *serv = nullptr;
    for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
        OrderDishStruct *od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
        if (!od) {
            continue;
        }
        if (od->fState != DISH_STATE_READY) {
            continue;
        }
        if (od->fDishId == Hall::getHallById(fTable->fHall)->fServiceItem) {
            serv = od;
            continue;
        }
        if (od->fQty - od->fQtyPrint > 0.01) {
            return false;
        }
    }
    return true;
}

void RDesk::countDish(OrderDishStruct *d)
{
    d->fTotal = d->fQty * d->fPrice;
    d->fSvcAmount += (d->fTotal * d->fSvcValue);
    d->fTotal += d->fSvcAmount;
    d->fDctAmount = d->fTotal * d->fDctValue;
    d->fTotal -= d->fDctAmount;
}

bool RDesk::setTable(TableStruct *t)
{
    if (fTable) {
        if (t == fTable) {
            DlgSmile *ds = new DlgSmile(this);
            ds->exec();
            delete ds;
            return true;
        }
    }
    Splash s(this);
    s.show();
    DoubleDatabase fDD(true, doubleDatabase);
    if (fTable) {
        //unlock previous table
        checkEmpty();
        QString query = QString("update r_table set f_lockTime=0, f_lockHost='' where f_id=%1")
                .arg(fTable->fId);
        fDD.exec(query);
    }
    fTable = t;
    s.setText(tr("Opening table ") + t->fName);
    ui->tblTotal->item(0, 1)->setText(t->fName);
    ui->tblTotal->item(1, 1)->setText("0");
    fDD.startTransaction();
    fDD[":f_id"] = t->fId;
    if (!fDD.exec("select f_lockTime, f_lockHost, f_order from r_table where f_id=:f_id for update")) {
        if (fDD.fLastError.contains("Lock wait timeout exceeded")) {
            fDD.commit();
            s.close();
            message_error(tr("Table in editing mode"));
            fCanClose = true;
            close();
            return false;
        }
    }
    fDD.nextRow();
    QString lockHost = fDD.getString(1);
    int lockTime = fDD.getInt(0);
    int currTime = QDateTime::currentDateTime().toTime_t();
    if (lockTime > 0) {
        if (currTime - lockTime < 1 * 60 * 3) {
            if (lockHost != Utils::hostName()) {
                s.close();
                message_error(tr("Table in editing mode"));
                fCanClose = true;
                close();
                return false;
            }
        }
    }
    clearOrder();
    fTable->fOrder = fDD.getString(2);
    QString query = QString("update r_table set f_lockTime=%1, f_lockHost='%2' where f_id=%3")
            .arg(QDateTime::currentDateTime().toTime_t())
            .arg(Utils::hostName())
            .arg(fTable->fId);
    fDD.exec(query);
    fDD.commit();
    if (!fTable->fOrder.isEmpty()) {
        loadOrder();
    }
    fHall = Hall::getHallById(fTable->fHall);
    s.close();
    return true;
}

void RDesk::checkOrderHeader(TableStruct *t, DishStruct *od, bool skipService)
{
    HallStruct *h = Hall::getHallById(fTable->fHall);
    if (!h) {
        message_error(tr("Invalid hall id. Contact to application developer"));
        clearOrder();
        accept();
        return;
    }
    if (!skipService) {
        if (od) {
            if (h->fDefaultSvcValue > 0.001) {
                for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
                    OrderDishStruct *odc = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
                    if (odc->fDishId == h->fServiceItem) {
                        goto AAA;
                    }
                }
                CacheDish cd;
                if (!cd.get(h->fServiceItem)) {
                    message_error(tr("Hall have service value, but item of service value is not assigned"));
                    clearOrder();
                    accept();
                    return;
                }

                DishStruct *o = new DishStruct();
                *o = *od;
                o->fSvcValue = h->fDefaultSvcValue;
                o->fId = cd.fCode().toInt();
                o->fName["en"] = cd.fName();
                o->fName["ru"] = cd.fName();
                o->fName["am"] = cd.fName();
                o->fPrice = 0;
                addDishToOrder(o, true);
            }
        }
    }
    AAA:
    DoubleDatabase fDD(true, doubleDatabase);
    if (t->fOrder.isEmpty()) {
        fDD.startTransaction();
        QString query = QString("select f_id from r_table where f_id='%1' for update")
                .arg(t->fId);
        fDD.exec(query);
        t->fOrder = uuidx(VAUCHER_POINT_SALE_N + Hall::getHallById(fTable->fHall)->fPrefix);
        fDD.insertId("o_header", t->fOrder);
        fDD[":f_state"] = ORDER_STATE_OPENED;
        fDD[":f_table"] = t->fId;
        fDD[":f_staff"] = fStaff->fId;
        fDD[":f_dateOpen"] = QDateTime::currentDateTime();
        fDD[":f_dateCash"] = WORKING_DATE;
        fDD[":f_tax"] = 0;
        fDD[":f_paymentMode"] = PAYMENT_CASH;
        fDD[":f_hall"] = t->fHall;
        t->fOpened = fDD[":f_dateOpen"].toDateTime();
        fDD.update("o_header", where_id(ap(t->fOrder)));
        fDD[":f_order"] = t->fOrder;
        fDD.update("r_table", QString("where f_id=%1").arg(t->fId));
        fDD.commit();
        TrackControl::insert(TRACK_REST_ORDER, "Order started", "", "", "", t->fOrder, "");
    }
}

void RDesk::clearOrder()
{
    for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
        delete ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
    }
    fTable->fPrint = 0;
    ui->tblOrder->clear();
    ui->tblOrder->setRowCount(0);
    fTable->fOrder = "";
    fTable->fPaymentComment = "";
    fTable->fRoomComment = "";
    ui->lbRoom->clear();
    for (int i = 0; i < ui->tblComplex->rowCount(); i++) {
        DishComplexStruct *dc = ui->tblComplex->item(i, 0)->data(Qt::UserRole).value<DishComplexStruct*>();
        for (int j = 0; j < dc->fDishes.count(); j++) {
            delete dc->fDishes[j];
        }
        delete dc;
    }
    ui->tblComplex->setRowCount(0);
    countTotal();
}

void RDesk::loadOrder()
{
    ui->tblComplex->clear();
    ui->tblComplex->setRowCount(0);
    //ui->tblOrder->clear();
    ui->tblOrder->setRowCount(0);
    User u;
    QString query = QString("select h.f_staff, h.f_comment, concat(u.f_firstName, ' ', u.f_lastName), h.f_print, "
                            "h.f_paymentMode, h.f_paymentModeComment, h.f_cityLedger, h.f_roomComment, h.f_dateOpen, "
                            "h.f_tax "
                             "from o_header h "
                             "left join users u on u.f_id=h.f_staff "
                             "where h.f_id='%1'")
            .arg(fTable->fOrder);
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.exec(query);
    QList<QList<QVariant> > &fDbRows = fDD.fDbRows;
    if (fDbRows.count() == 0) {
        return;
    }
    u.fId = fDbRows.at(0).at(0).toInt();
    u.fName = fDbRows.at(0).at(2).toString();
    fTable->fComment = fDbRows.at(0).at(1).toString();
    fTable->fPrint = fDbRows.at(0).at(3).toInt();
    fTable->fPaymentMode = fDbRows.at(0).at(4).toInt();
    fTable->fPaymentComment = fDbRows.at(0).at(5).toString();
    fTable->fCitiLedger = fDbRows.at(0).at(6).toInt();
    fTable->fRoomComment = fDbRows.at(0).at(7).toString();
    fTable->fOpened = fDbRows.at(0).at(8).toDateTime();
    fTable->fTaxPrint = fDbRows.at(0).at(9).toInt();
    if (u.fId != fStaff->fId) {
        message_info(QString("%1<br>%2")
                     .arg(tr("Table opened by"))
                     .arg(u.fName));
    }
    //Complex
    query = "select od.f_id, od.f_dish, dc.f_en, dc.f_ru, dc.f_am, od.f_qty, od.f_qtyPrint, od.f_price, "
            "od.f_svcValue, od.f_svcAmount, od.f_dctValue, od.f_dctAmount, od.f_total, "
            "od.f_print1, od.f_print2, od.f_comment, od.f_staff, od.f_state, od.f_complex, od.f_complexId, "
            "dc.f_adgt "
            "from o_dish od "
            "left join r_dish_complex dc on dc.f_id=od.f_complexId "
            "where od.f_header=:f_header and f_complex>0 and f_complexId>0 and f_state=1 "
            "order by od.f_id ";
    fDD[":f_header"] = fTable->fOrder;
    fDD.exec(query);
    for (QList<QList<QVariant> >::const_iterator it = fDbRows.begin(); it != fDbRows.end(); it++) {
        DishComplexStruct *dc = new DishComplexStruct();
        dc->fRecId = it->at(0).toString();
        dc->fName["en"] = it->at(2).toString();
        dc->fName["ru"] = it->at(3).toString();
        dc->fName["am"] = it->at(4).toString();
        dc->fAdgt = it->at(20).toString();
        dc->fId = it->at(19).toInt();
        dc->fQty = it->at(5).toDouble();
        dc->fPrice = it->at(7).toDouble();
        int row = ui->tblComplex->rowCount();
        ui->tblComplex->setRowCount(row + 1);
        ui->tblComplex->setItem(row, 0, new QTableWidgetItem());
        ui->tblComplex->item(row, 0)->setData(Qt::UserRole, QVariant::fromValue(dc));
    }


    query = "select od.f_id, od.f_dish, d.f_en, d.f_ru, d.f_am, od.f_qty, od.f_qtyPrint, od.f_price, "
            "od.f_svcValue, od.f_svcAmount, od.f_dctValue, od.f_dctAmount, od.f_total, "
            "od.f_print1, od.f_print2, od.f_comment, od.f_staff, od.f_state, od.f_complex, od.f_complexId, "
            "od.f_adgt, od.f_complexRec "
            "from o_dish od "
            "left join r_dish d on d.f_id=od.f_dish "
            "where od.f_header=:f_header and (f_complex=0 or (f_complex>0 and f_complexId=0)) and f_state=1 "
            "order by od.f_id ";
    fDD[":f_header"] = fTable->fOrder;
    fDD.exec(query);
    for (QList<QList<QVariant> >::const_iterator it = fDbRows.begin(); it != fDbRows.end(); it++) {
        OrderDishStruct *d = new OrderDishStruct();
        int c = 0;
        d->fRecId = it->at(c++).toString();
        d->fDishId = it->at(c++).toInt();
        d->fName["en"] = it->at(c++).toString();
        d->fName["ru"] = it->at(c++).toString();
        d->fName["am"] = it->at(c++).toString();
        d->fQty = it->at(c++).toFloat();
        d->fQtyPrint = it->at(c++).toFloat();
        d->fPrice = it->at(c++).toFloat();
        d->fSvcValue = it->at(c++).toFloat();
        d->fSvcAmount = it->at(c++).toFloat();
        d->fDctValue = it->at(c++).toFloat();
        d->fDctAmount = it->at(c++).toFloat();
        d->fTotal = it->at(c++).toFloat();
        d->fPrint1 = it->at(c++).toString();
        d->fPrint2 = it->at(c++).toString();
        d->fComment = it ->at(c++).toString();
        d->fStaff = it->at(c++).toInt();
        d->fState = it->at(c++).toInt();
        d->fComplex = it->at(c++).toInt();
        c++; //complexId
        d->fAdgt = it->at(c++).toString();
        d->fComplexRecId = it->at(c++).toString();
        if (!d->fComplexRecId.isEmpty()) {
            for (int i = 0; i < ui->tblComplex->rowCount(); i++) {
                DishComplexStruct *ds = ui->tblComplex->item(i, 0)->data(Qt::UserRole).value<DishComplexStruct*>();
                if (ds) {
                    if (ds->fRecId == d->fComplexRecId) {
                        DishStruct *dss = new DishStruct();
                        dss->fId = d->fDishId;
                        dss->fName = d->fName;
                        dss->fPrice = d->fPrice;
                        ds->fDishes.append(dss);
                    }
                }
            }
        }
        countDish(d);
        addDishToTable(d);
        setOrderRowHidden(ui->tblOrder->rowCount() - 1, d);
    }
    changeBtnState();
    ui->lbRoom->setText(fTable->fRoomComment);
    countTotal();
}

void RDesk::setOrderRowHidden(int row, OrderDishStruct *od)
{
    switch(od->fState) {
    case DISH_STATE_READY:
        ui->tblOrder->setRowHidden(row, false);
        break;
    case DISH_STATE_REMOVED_NOSTORE:
    case DISH_STATE_REMOVED_STORE:
    case DISH_STATE_MOVED:
        ui->tblOrder->setRowHidden(row, !fShowRemoved);
        break;
    case DISH_STATE_EMPTY:
        ui->tblOrder->setRowHidden(row, true);
        break;
    }
}

void RDesk::printServiceCheck(const QString &prn, int side)
{
    QStringList printers = QPrinterInfo::availablePrinterNames();
    foreach (QString s, printers) {
        writelog("printer - " + s);
    }

    if (!printers.contains(prn, Qt::CaseInsensitive)) {
        message_error(tr("The printer with name not exists on the system") + "\r\n" + prn);
        return;
    }
    QList<PPrintScene*> lps;
    PPrintScene *ps = new PPrintScene(Portrait);
    lps.append(ps);
    PTextRect th;
    QFont f("Arial", 24);
    th.setFont(f);
    th.setBorders(false, false, false, false);
    PTextRect *r = nullptr;
    int top = 10;
    th.setTextAlignment(Qt::AlignHCenter);
    int rowHeight = 60;
    f.setPointSize(34);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, fHall->fName, &th)->textHeight();
    f.setPointSize(24);
    th.setFont(f);
    r = ps->addTextRect(new PTextRect(10, top, 680, rowHeight, QString("%1 %2")
                                     .arg(tr("Service check, order #"))
                                     .arg(fTable->fOrder),
                                     &th, f));
    top += r->textHeight();
    top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, QString("%1: %2").arg(tr("Table")).arg(fTable->fName), &th, f))->textHeight();
    top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, QString("%1: %2").arg(tr("Time"))
                                        .arg(QDateTime::currentDateTime().toString(def_date_time_format)), &th, f))->textHeight();
    top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, QString("%1: %2").arg(tr("Waiter"))
                                        .arg(fStaff->fName), &th, f))->textHeight();
    ps->addLine(10, top, 680, top);
    top += 2;
    ps->addTextRect(new PTextRect(10, top, 80, rowHeight, tr("Qty"), &th, f));
    top += ps->addTextRect(new PTextRect(90, top, 680, rowHeight, tr("Description"), &th, f))->textHeight();
    ps->addLine(10, top, 680, top);
    top += 2;
    th.setTextAlignment(Qt::AlignLeft);
    for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
        OrderDishStruct *od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
        if (!od) {
            continue;
        }
        if (od->fState != DISH_STATE_READY) {
            continue;
        }
        if (side == 1) {
            if (od->fPrint1.toUpper() != prn) {
                continue;
            }
        }
        if (side == 2) {
            if (od->fPrint2.toUpper() != prn) {
                continue;
            }
        }
        float qty = od->fQty - od->fQtyPrint;
        if (qty < 0.1) {
            continue;
        }
        ps->addTextRect(new PTextRect(10, top, 80, rowHeight, float_str(qty, 1), &th, f));
        top += ps->addTextRect(new PTextRect(90, top, 680, rowHeight, od->fName[def_lang], &th, f))->textHeight();
        TrackControl::insert(TRACK_REST_ORDER, "Printed service check", od->fName[def_lang], float_str(qty, 1), od->fRecId, fTable->fOrder, "");
        if (!od->fComment.isEmpty()) {
            f.setPointSize(18);
            f.setBold(true);
            th.setFont(f);
            top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, od->fComment, &th, f))->textHeight();
            f.setPointSize(24);
            f.setBold(false);
            th.setFont(f);
        }
        ps->addLine(10, top, 680, top);
        if (top > sizePortrait.height() - 200) {
            top = 10;
            ps = new PPrintScene(Portrait);
            lps.append(ps);
        }
    }
    top += 25;
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(10, top, 680, rowHeight, tr("Printer: ") + prn, &th);
    top += 5;
    ps->addTextRect(10, top, 680, rowHeight, "_", &th);
    QPrinter printer;
    //writelog("before set " + prn.toUpper());
    printer.setPrinterName(prn.toUpper());
    //writelog("after set " + printer.printerName());
    int scale = 3; //600 / printer.resolution();
    //printer.setPrinterName("\\\\10.2.1.37\\HP LaserJet Professional P1102");
    QPainter painter(&printer);
    QPrintDialog pd(&printer, this);
    QMatrix m;
    m.scale(scale, scale);
    painter.setMatrix(m);
    for (int i = 0; i < lps.count(); i++) {
        if (i > 0) {
            printer.newPage();
        }
        lps[i]->render(&painter);
    }
}

void RDesk::printRemovedDish(OrderDishStruct *od, double removed, int user)
{
    TrackControl::insert(TRACK_REST_ORDER, "Print removed dish", od->fName[def_lang], float_str(removed, 1), od->fRecId, fTable->fOrder, "");
    CacheUsers u;
    QString userName = fStaff->fName;
    if (u.get(user)) {
        userName =  u.fName();
    }
    PPrintScene ps(Portrait);
    PTextRect th;
    QFont f("Arial", 34);
    f.setBold(true);
    th.setFont(f);
    th.setBorders(false, false, false, false);
    PTextRect *r = nullptr;
    int top = 10;
    th.setTextAlignment(Qt::AlignHCenter);
    int rowHeight = 60;
    r = ps.addTextRect(10, top, 680, rowHeight, QString("%1").arg(tr("Cancelation check")), &th);
    top += r->textHeight();
    top += ps.addTextRect(10, top, 680, rowHeight, QString("Order #%1")
                                     .arg(fTable->fOrder),
                                     &th)->textHeight();
    f.setPointSize(25);
    th.setFont(f);
    top += r->textHeight();
    top += ps.addTextRect(new PTextRect(10, top, 680, rowHeight, QString("%1: %2").arg(tr("Table")).arg(fTable->fName), &th, f))->textHeight();
    top += ps.addTextRect(new PTextRect(10, top, 680, rowHeight, QString("%1: %2").arg(tr("Time"))
                                        .arg(QDateTime::currentDateTime().toString(def_date_time_format)), &th, f))->textHeight();
    top += ps.addTextRect(new PTextRect(10, top, 680, rowHeight, QString("%1: %2").arg(tr("User"))
                                        .arg(userName), &th, f))->textHeight();
    ps.addLine(10, top, 680, top);
    th.setTextAlignment(Qt::AlignLeft);
    ps.addTextRect(new PTextRect(10, top, 80, rowHeight, float_str(removed, 1), &th, f));
    top += ps.addTextRect(new PTextRect(90, top, 680, rowHeight, od->fName[def_lang], &th, f))->textHeight();

    QPrinterInfo pi;
    if (!od->fPrint1.isEmpty()) {
        if (!pi.availablePrinterNames().contains(od->fPrint1, Qt::CaseInsensitive)) {
            message_error(QString("Printer %1 is not exists").arg(od->fPrint1));
        } else {
            QPrinter printer;
            //QPrintDialog pd(&printer, this);
            printer.setPrinterName(od->fPrint1.toUpper());
            int scale = 3; //600 / printer.resolution();
            QMatrix m;
            m.scale(scale, scale);
            QPainter painter(&printer);
            painter.setMatrix(m);
            ps.render(&painter);
            //message_info("print on " + od->fPrint1);
        }
    }
    if (!od->fPrint2.isEmpty()) {
        if (!pi.availablePrinterNames().contains(od->fPrint2, Qt::CaseInsensitive)) {
            message_error(QString("Printer %1 is not exists").arg(od->fPrint2));
        } else {
            QPrinter printer;
            //QPrintDialog pd(&printer, this);
            printer.setPrinterName(od->fPrint2.toUpper());
            int scale = 3;//600 / printer.resolution();
            QMatrix m;
            m.scale(scale, scale);
            QPainter painter(&printer);
            painter.setMatrix(m);
            ps.render(&painter);
            //message_info("print on " + od->fPrint2);
        }
    }
}

void RDesk::printReceipt(bool printModePayment)
{
    if (!checkQtyBeforeReceipt()) {
        message_error(tr("Order is not ready. Send first."));
        return;
    }
    //TODO: long open order handler. if (fTable->fOpened - QDateTime::currentDateTime() < '10 hour')...
    int trackUser = fStaff->fId;
    if (!printModePayment) {
        if (fTable->fPrint > 0) {
            if (!g__(cr__o_print_unlimited_receipt, trackUser)) {
                return;
            }
        }
    }
    QString userName = fStaff->fName;
    CacheUsers u;
    if (u.get(trackUser)) {
        userName = u.fFull();
    } else {
        userName = "#Username Error";
    }

    for (int i = 0, count = ui->tblOrder->rowCount(); i < count; i++) {
        OrderDishStruct *od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
        if (od->fComplex) {
            od->fPrice = 0;
            od->fTotal = 0;
            updateDish(od);
        }
    }
    ui->tblOrder->viewport()->update();

    DoubleDatabase drTax;
    drTax.setDatabase(BaseUIDX::fAirHost, "airwick", BaseUIDX::fAirUser, BaseUIDX::fAirPass, 1);
    drTax.open(true, false);
    drTax[":f_order"] = fTable->fOrder;
    drTax.exec("select f_replyTaxCode from tax_print where f_order=:f_order and f_replyResult=0");
    drTax.nextRow();

    QList<PPrintScene*> lps;
    PPrintScene *ps = new PPrintScene(Portrait);
    lps.append(ps);
    PTextRect th;
    QFont f("Arial", 30);
    th.setFont(f);
    th.setBorders(false, false, false, false);
    int top = 10;
    th.setTextAlignment(Qt::AlignHCenter);
    int rowHeight = 60;
    PImage *logo = new PImage("logo_print.png");
    ps->addItem(logo);
    logo->setRect(QRectF(150, top, 400, 250));
    top += 250;
    f.setPointSize(40);
    th.setFont(f);
    top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight + 10, fHall->fName, &th, f))->textHeight();
    top += 20;
    f.setPointSize(20);
    th.setFont(f);
    top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, QString("%1 %2")
                                     .arg(tr("Receipt S/N "))
                                     .arg(fTable->fOrder),
                                     &th, f))->textHeight();
    f.setPointSize(24);
    th.setFont(f);
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(new PTextRect(10, top, 150, rowHeight, tr("Table"), &th, f));
    ps->addTextRect(new PTextRect(160, top, 200, rowHeight, fTable->fName, &th, f));
    ps->addTextRect(new PTextRect(340, top, 230, rowHeight, tr("Date"), &th, f));
    top += ps->addTextRect(new PTextRect(450, top, 250, rowHeight, WORKING_DATE.toString(def_date_format), &th, f))
            ->textHeight();
    if (!printModePayment) {
        ps->addTextRect(new PTextRect(10, top, 150, rowHeight, tr("Time"), &th, f));
        top += ps->addTextRect(new PTextRect(160, top, 200, rowHeight, QTime::currentTime().toString(def_time_format), &th, f))->textHeight();
    }
    if (drTax.rowCount() > 0) {
        ps->addTextRect(new PTextRect(10, top, 150, rowHeight, tr("Tax #"), &th, f));
        top += ps->addTextRect(new PTextRect(160, top, 200, rowHeight, drTax.getValue("f_replyTaxCode").toString(), &th, f))->textHeight();
    }
    ps->addTextRect(new PTextRect(10, top, 150, rowHeight, tr("Waiter"), &th, f));
    top += ps->addTextRect(new PTextRect(160, top, 500, rowHeight, userName, &th, f))->textHeight();
    if (printModePayment) {
        ps->addTextRect(new PTextRect(10, top, 150, rowHeight, tr("Opened"), &th, f));
        top += ps->addTextRect(new PTextRect(160, top, 350, rowHeight, fTable->fOpened.toString(def_date_time_format), &th, f))->textHeight();
        ps->addTextRect(new PTextRect(10, top, 150, rowHeight, tr("Closed"), &th, f));
        top += ps->addTextRect(new PTextRect(160, top, 350, rowHeight, QDateTime::currentDateTime().toString(def_date_time_format), &th, f))->textHeight();
    }
    top += 2;
    ps->addLine(10, top, 680, top);
    top ++;
    ps->addTextRect(new PTextRect(10, top, 100, rowHeight, tr("Qty"), &th, f));
    ps->addTextRect(new PTextRect(110, top, 390, rowHeight, tr("Description"), &th, f));
    top += ps->addTextRect(new PTextRect(500, top, 200, rowHeight, tr("Amount"), &th, f))->textHeight();
    ps->addLine(10, top, 680, top);
    top ++;
    f.setPointSize(18);
    f.setBold(true);
    th.setFont(f);
    for (int i = 0; i < ui->tblComplex->rowCount(); i++) {
        DishComplexStruct *dc = ui->tblComplex->item(i,0)->data(Qt::UserRole).value<DishComplexStruct*>();
        if (!dc) {
            message_error("Application error. Contact to developer. Message: dc==0, print receipt");
            return;
        }
        ps->addTextRect(new PTextRect(10, top, 100, rowHeight, float_str(dc->fQty, 1), &th, f));
        ps->addTextRect(new PTextRect(110, top, 390, rowHeight, dc->fName[def_lang], &th, f));
        top += ps->addTextRect(new PTextRect(500, top, 200, rowHeight, float_str(dc->fPrice * dc->fQty, 2), &th, f))->textHeight();
        if (top > sizePortrait.height()  - 200) {
            top = 10;
            ps = new PPrintScene(Portrait);
            lps.append(ps);
        }
    }
    OrderDishStruct *serv = nullptr;
    for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
        OrderDishStruct *od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
        if (!od) {
            continue;
        }
        if (od->fState != DISH_STATE_READY) {
            continue;
        }
        if (od->fComplex > 0) {
            continue; //handle complex
        }
        if (od->fSvcValue  > 0.01) {
            serv = od;
            continue;
        }
        ps->addTextRect(new PTextRect(10, top, 100, rowHeight, float_str(od->fQty, 1), &th, f));
        ps->addTextRect(new PTextRect(110, top, 390, rowHeight, od->fName[def_lang], &th, f));
        top += ps->addTextRect(new PTextRect(500, top, 200, rowHeight, float_str(od->fTotal, 2), &th, f))->textHeight();
        if (top > sizePortrait.height()  - 200) {
            top = 10;
            ps = new PPrintScene(Portrait);
            lps.append(ps);
        }
    }
    if (serv) {
        ps->addTextRect(new PTextRect(10, top, 390, rowHeight, serv->fName[def_lang], &th, f));
        top += ps->addTextRect(new PTextRect(500, top, 200, rowHeight, float_str(serv->fTotal, 2), &th, f))->textHeight();
        if (top > sizePortrait.height()  - 200) {
            top = 10;
            ps = new PPrintScene(Portrait);
            lps.append(ps);
        }
    }
    ps->addLine(10, top, 680, top);
    top += 2;
    f.setPointSize(24);
    th.setFont(f);
    ps->addTextRect(new PTextRect(10, top, 400, rowHeight, tr("Total, AMD"), &th, f));
    top += ps->addTextRect(new PTextRect(500, top, 200, rowHeight, ui->tblTotal->item(1, 1)->data(Qt::EditRole).toString(), &th, f))->textHeight();
    ps->addTextRect(new PTextRect(10, top, 400, rowHeight, tr("Total, USD"), &th, f));
    top += ps->addTextRect(new PTextRect(500, top, 200, rowHeight, float_str(QLocale().toDouble(ui->tblTotal->item(1, 1)->data(Qt::EditRole).toString()) / def_usd, 2), &th, f))->textHeight();

    top += rowHeight;
    f.setPointSize(28);
    th.setFont(f);
    th.setTextAlignment(Qt::AlignHCenter);

    if (top > sizePortrait.height()  - 200) {
        top = 10;
        ps = new PPrintScene(Portrait);
        lps.append(ps);
    }
    if (!fTable->fRoomComment.isEmpty()) {
       top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, fTable->fRoomComment, &th, f))->textHeight();
       top += rowHeight;
       top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, tr("Signature"), &th, f))->textHeight();
       top += rowHeight + 2;
       ps->addLine(150, top, 680, top);
    }

    if (top > sizePortrait.height()  - 200) {
        top = 10;
        ps = new PPrintScene(Portrait);
        lps.append(ps);
    }
    if (fTable->fPaymentMode == PAYMENT_COMPLIMENTARY) {
        top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, tr("COMPLIMENTARY"), &th, f))->textHeight();
    } else {
        top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, tr("SALES"), &th, f))->textHeight();
    }
    if (printModePayment) {
        top += rowHeight;
        top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, tr("Mode Of Payment"), &th, f))->textHeight();
        switch (fTable->fPaymentMode) {
        case PAYMENT_CASH:
            top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, tr("CASH") + "/" + fTable->fPaymentComment, &th, f))->textHeight();
            break;
        case PAYMENT_CARD:
            top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, tr("CARD") + "/" + fTable->fPaymentComment, &th, f))->textHeight();
            break;
        case PAYMENT_ROOM:
            top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, fTable->fPaymentComment, &th, f))->textHeight();
            break;
        case PAYMENT_CL:
            top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, "CL/" + fTable->fPaymentComment, &th, f))->textHeight();
            break;
        case PAYMENT_COMPLIMENTARY:
            top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, fTable->fPaymentComment, &th, f))->textHeight();
            break;
        }
    } else {
        th.setTextAlignment(Qt::AlignLeft);
        top += rowHeight;
        ps->addTextRect(10, top, 400, rowHeight, tr("Room number:"), &th);
        top += 2;
        ps->addLine(300, top + rowHeight, 600, top + rowHeight);
        top += rowHeight + 2;
        ps->addTextRect(10, top, 200, rowHeight, tr("Signature"), &th);
        top += 2;
        ps->addLine(300, top + rowHeight, 600, top + rowHeight);
    }

    if (fShowRemoved) {
        top += (rowHeight * 3);
        top += ps->addTextRect(10, top, 600, rowHeight, tr("****VOID****"), &th)->textHeight();
        for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
            OrderDishStruct *od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
            if (!od) {
                continue;
            }
            if (od->fState != DISH_STATE_REMOVED_STORE) {
                continue;
            }
            if (od->fComplex > 0) {
                continue; //handle complex
            }
            ps->addTextRect(new PTextRect(10, top, 100, rowHeight, float_str(od->fQty, 1), &th, f));
            ps->addTextRect(new PTextRect(110, top, 390, rowHeight, od->fName[def_lang], &th, f));
            top += ps->addTextRect(new PTextRect(500, top, 200, rowHeight, float_str(od->fTotal, 2), &th, f))->textHeight();
            if (top > sizePortrait.height()  - 200) {
                top = 10;
                ps = new PPrintScene(Portrait);
                lps.append(ps);
            }
        }
        top += rowHeight;
        top += ps->addTextRect(10, top, 600, rowHeight, tr("****MISTAKE****"), &th)->textHeight();
        for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
            OrderDishStruct *od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
            if (!od) {
                continue;
            }
            if (od->fState != DISH_STATE_REMOVED_NOSTORE) {
                continue;
            }
            if (od->fComplex > 0) {
                continue; //handle complex
            }
            ps->addTextRect(new PTextRect(10, top, 100, rowHeight, float_str(od->fQty, 1), &th, f));
            ps->addTextRect(new PTextRect(110, top, 390, rowHeight, od->fName[def_lang], &th, f));
            top += ps->addTextRect(new PTextRect(500, top, 200, rowHeight, float_str(od->fTotal, 2), &th, f))->textHeight();
            if (top > sizePortrait.height()  - 200) {
                top = 10;
                ps = new PPrintScene(Portrait);
                lps.append(ps);
            }
        }
    }

    //Finish
    top += rowHeight;
    ps->addTextRect(new PTextRect(10, top, 680, rowHeight, "_", &th, f));

    QPrinter printer;
    printer.setPrinterName(fHall->fReceiptPrinter);
    QMatrix m;
    int scale = 3;
#ifdef QT_DEBUG
    scale = 1;
#endif
    m.scale(scale, scale);
    QPainter painter(&printer);
    painter.setMatrix(m);
    for (int i = 0; i < lps.count(); i++) {
        if (i > 0) {
            printer.newPage();
        }
        lps[i]->render(&painter);
    }

    fTable->fPrint = abs(fTable->fPrint) + 1;
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_print"] = fTable->fPrint;
    fDD.update("o_header", where_id(ap(fTable->fOrder)));
    changeBtnState();
    QString v = printModePayment ? "v2" : "v1";
    TrackControl::insert(TRACK_REST_ORDER, "Print receipt " + v, fTable->fPaymentComment + " " + fTable->fRoomComment, "", "", fTable->fOrder, "");
}

void RDesk::changeBtnState()
{
    bool emptyReceipt = true;
    bool btnPrintService = false;
    bool btnPrintReceipt = false;
    bool btnPayment = false;
    bool btnSetRoom = false;
    for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
        OrderDishStruct *od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
        if (!od) {
            continue;
        }
        if (od->fState != DISH_STATE_READY) {
            continue;
        }
        float qty = od->fQty - od->fQtyPrint;
        emptyReceipt = false;
        if (qty > 0.1) {
            btnPrintService = true;
            break;
        }
    }
    btnPrintReceipt = !btnPrintService;
    btnPayment = fTable->fPrint > 0 && !btnPrintService;
    btnSetRoom = !fTable->fOrder.isEmpty();
    ui->btnPrint->setEnabled(btnPrintService);
    ui->btnSetRoom->setEnabled(btnSetRoom);
    ui->btnCheckout->setEnabled(btnPrintReceipt && !emptyReceipt);
    ui->btnPayment->setEnabled(btnPayment);
}

void RDesk::checkEmpty()
{
    if (!fTable) {
        return;
    }
    if (fTable->fOrder.isEmpty()) {
        return;
    }

    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_lockTime"] = 0;
    fDD[":f_lockHost"] = "";
    fDD.update("r_table", where_id(fTable->fId));

    bool orderEmpty = true;
    for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
        OrderDishStruct *od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
        if (!od) {
            continue;
        }
        if (od->fState == DISH_STATE_READY) {
            orderEmpty = false;
        }
    }
    if (orderEmpty) {
        fDD[":f_state"] = ORDER_STATE_EMPTY;
        fDD[":f_dateClose"] = QDateTime::currentDateTime();
        fDD.update("o_header", where_id(ap(fTable->fOrder)));
        fDD[":f_order"] = "";
        fDD.update("r_table", where_id(fTable->fId));

        fDD[":f_header"] = fTable->fOrder;
        fDD[":f_s1"] = DISH_STATE_REMOVED_NOSTORE;
        fDD[":f_s2"] = DISH_STATE_REMOVED_STORE;
        fDD.exec("select * from o_dish where f_header=:f_header and (f_state=:f_s1 or f_state=:f_s2)");
        if (fDD.nextRow()) {
            fShowRemoved = true;
            printReceipt(true);
        }
    }
}

void RDesk::resetPrintQty()
{
    if (fTable->fPrint > 0) {
        fTable->fPrint = (fTable->fPrint) * -1;
        DoubleDatabase fDD(true, doubleDatabase);
        fDD[":f_print"] = fTable->fPrint;
        fDD.update("o_header", where_id(ap(fTable->fOrder)));
    }
}

void RDesk::checkUnprinted()
{
    switch (defrest(dr_new_dish_state_after_close).toInt()) {
    case 0:
        break;
    case 1:
        for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
            OrderDishStruct *od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
            if (!od) {
                continue;
            }
            if (od->fState != DISH_STATE_READY) {
                continue;
            }
            if (od->fQty - od->fQtyPrint > 0.1) {
                od->fQty = od->fQtyPrint;
                if (od->fQty < 0.001) {
                    od->fState = DISH_STATE_EMPTY;
                }
                updateDish(od);
            }
        }
        break;
    case 2:
        ui->btnPrint->click();
        break;
    }
}

void RDesk::updateDishQtyHistory(OrderDishStruct *od)
{
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_rec"] = od->fRecId;
    fDD[":f_user"] = fStaff->fName;
    fDD[":f_date"] = QDateTime::currentDateTime();
    fDD[":f_info"] = QString("%1/%2").arg(od->fQty).arg(od->fQtyPrint);
    fDD.insert("o_dish_qty", false);
}

void RDesk::on_tblPart_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    DishPartStruct *p = index.data(Qt::UserRole).value<DishPartStruct*>();
    if (!p) {
        return;
    }
    setupType(p->fId);
}

void RDesk::on_tblType_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    TypeStruct *t = index.data(Qt::UserRole).value<TypeStruct*>();
    if (!t) {
        return;
    }
    setupDish(t->fId);
}

void RDesk::on_tblDish_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    DishStruct *d = index.data(Qt::UserRole).value<DishStruct*>();
    if (!d) {
        return;
    }
    fCloseTimeout = 0;
    addDishToOrder(d);
}

void RDesk::on_btnTrash_clicked()
{
    QModelIndexList sel = ui->tblOrder->selectionModel()->selectedRows();
    if (sel.count() == 0) {
        return;
    }
    ui->tblOrder->clearSelection();
    OrderDishStruct *od = sel.at(0).data(Qt::UserRole).value<OrderDishStruct*>();
    if (!od) {
        return;
    }
    if (!message_question(tr("Confirm to delete the selected item"))) {
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    QString oldQty = QString("%1, %2/%3").arg(od->fName[def_lang]).arg(od->fQty).arg(od->fQtyPrint);
    int trackUser = fStaff->fId;
    if (od->fComplex == 0) {
        if (od->fQtyPrint < 0.01) {
            od->fState = DISH_STATE_EMPTY;
            ui->tblOrder->setRowHidden(sel.at(0).row(), true);
        } else {
            float num = 0;
            float qtyToPrint = 0;
            QVariant reason;
            if (RNumbers::getNumber(num, od->fQty, this)) {
                qtyToPrint = od->fQtyPrint - (od->fQty - num);
                if (qtyToPrint > 0.01) {
                    if (!g__(cr__o_cancelation, trackUser)) {
                        message_error(tr("Access denied"));
                        return;
                    }
                    QString name, sql = "select f_id, f_en from o_dish_state where f_id in (2, 3)";
                    if (!DlgList::getValue(tr("REMOVE OPTION"), name, reason, sql)) {
                        return;
                    }
                } else {
                    reason = DISH_STATE_REMOVED_NOSTORE;
                }
                if (float_equal(od->fQty, num)) {
                    od->fState = reason.toInt();
                    od->fCancelUser = trackUser;
                    od->fQty -= num;
                    od->fQtyPrint = od->fQty;
                    od->fCancelDate = QDateTime::currentDateTime();
                    setOrderRowHidden(sel.at(0).row(), od);
                } else {
                    float qtyEmpty = od->fQty - od->fQtyPrint;
                    if (float_greaterOrEqual(qtyEmpty, num)) {
                        od->fQty -= num;
                    } else {
                        od->fQty -= qtyEmpty;
                        num -= qtyEmpty;
                        //Log empty
                        if (float_equal(od->fQty, num)) {
                            od->fQty -= num;
                            od->fQtyPrint = od->fQty;
                            od->fState = reason.toInt();
                            od->fCancelUser = trackUser;
                            od->fCancelDate = QDateTime::currentDateTime();
                        } else {
                            od->fQty -= num;
                            od->fQtyPrint = od->fQty;
                            OrderDishStruct *r = new OrderDishStruct();
                            *r = *od;
                            r->fState = reason.toInt();
                            r->fQty = num;
                            r->fQtyPrint = num;
                            r->fRecId = uuidx("DR");
                            fDD.insertId("o_dish", r->fRecId);
                            fDD[":f_header"] = fTable->fOrder;
                            fDD[":f_state"] = r->fState;
                            fDD[":f_dish"] = r->fDishId;
                            fDD[":f_qty"] = r->fQty;
                            fDD[":f_qtyPrint"] = r->fQtyPrint;
                            fDD[":f_price"] = r->fPrice;
                            fDD[":f_svcValue"] = r->fSvcValue;
                            fDD[":f_svcAmount"] = r->fSvcAmount;
                            fDD[":f_dctValue"] = r->fDctValue;
                            fDD[":f_dctAmount"] = r->fDctAmount;
                            fDD[":f_total"] = r->fTotal;
                            fDD[":f_print1"] = r->fPrint1;
                            fDD[":f_print2"] = r->fPrint2;
                            fDD[":f_store"] = r->fStore;
                            fDD[":f_comment"] = r->fComment;
                            fDD[":f_staff"] = fStaff->fId;
                            fDD[":f_cancelUser"] = trackUser;
                            fDD[":f_cancelDate"] = QDateTime::currentDateTime();
                            fDD.update("o_dish", where_id(ap(r->fRecId)));
                            addDishToTable(r);
                        }
                    }
                }
                if (qtyToPrint > 0.01) {
                    printRemovedDish(od, qtyToPrint, trackUser);
                }
            }
        }
        QString newQty = QString("%1, %2/%3").arg(od->fName[def_lang]).arg(od->fQty).arg(od->fQtyPrint);
        TrackControl::insert(TRACK_REST_ORDER, "Dish qty", oldQty, newQty, od->fRecId, fTable->fOrder, "");
        countDish(od);
        updateDish(od);
        resetPrintQty();
    } else {
        //if od.f_complex > 0
        if (od->fQtyPrint > 0.1) {
            if (!g__(cr__o_cancelation, trackUser)) {
                message_error(tr("Access denied"));
                return;
            }
        }
        if (message_yesnocancel(tr("Are you sure remove whole complex?")) != RESULT_YES) {
            return;
        }
        QVariant reason;
        QString name, sql = "select f_id, f_en from o_dish_state where f_id in (2, 3)";
        if (!DlgList::getValue(tr("REMOVE OPTION"), name, reason, sql)) {
            return;
        }
        for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
            OrderDishStruct *o = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
            if (o->fComplexRecId == od->fComplexRecId) {
                o->fState = reason.toInt();
                ui->tblOrder->setRowHidden(i, !fShowRemoved);
                updateDish(o);
                TrackControl::insert(TRACK_REST_ORDER, "Remove complex component", o->fName["en"], "", o->fRecId, fTable->fOrder, "");
            }
        }
        for (int i = 0; i < ui->tblComplex->rowCount(); i++) {
            DishComplexStruct *dc = ui->tblComplex->item(i, 0)->data(Qt::UserRole).value<DishComplexStruct*>();
            if (dc->fRecId == od->fComplexRecId) {
                fDD[":f_state"] = reason.toInt();
                fDD.update("o_dish", where_id(ap(dc->fRecId)));
                ui->tblComplex->removeRow(i);
                TrackControl::insert(TRACK_REST_ORDER, "Remove complex", dc->fName["en"], "", dc->fRecId, fTable->fOrder, "");
                delete dc;
                break;
            }
        }
        fDD[":f_state"] = reason;
        fDD.update("o_dish", where_id(od->fComplexRecId));
    }
    countTotal();
    changeBtnState();
}

void RDesk::on_btnPayment_clicked()
{
    DoubleDatabase fDD(true, doubleDatabase);
    fCloseTimeout = 0;
    int cardCode = 0;
    QString cardName;
    int cityLedger = 0;
    QString cityLedgerName;
    QString invoice;
    int prnTax = 0;
    int side = 0;
    QString room = "";
    QString guest = "-";
    QString dc = "DEBIT";
    int sign = 1;
    switch (RPaymentType::getPaymentMode(this, cardCode)) {
    case -1:
        return;
    case 0:
        fTable->fPaymentMode = PAYMENT_CASH;
        fTable->fPaymentComment = "";
        switch (message_yesnocancel(tr("Print tax?"))) {
        case RESULT_YES:
            if ((prnTax = printTax(tax_mode_cash)) == TAX_FAIL) {
                return;
            } else {
                cardCode = 0;
            }
            break;
        case RESULT_CANCEL:
            return;
        }
        break;
    case 1:
        fTable->fPaymentMode = PAYMENT_CARD;
        fTable->fPaymentComment = "VISA";
        switch (message_yesnocancel(tr("Print tax?"))) {
        case RESULT_YES:
            if ((prnTax = printTax(tax_mode_card)) == TAX_FAIL) {
                return;
            }
            break;
        case RESULT_CANCEL:
            return;
        }
        break;
    case 2:
        fTable->fPaymentMode = PAYMENT_CARD;
        fTable->fPaymentComment = "MAESTRO";
        switch (message_yesnocancel(tr("Print tax?"))) {
        case RESULT_YES:
            if ((prnTax = printTax(tax_mode_card)) == TAX_FAIL) {
                return;
            }
            break;
        case RESULT_CANCEL:
            return;
        }
        break;
    case 3:
        fTable->fPaymentMode = PAYMENT_CARD;
        fTable->fPaymentComment = "MASTERCARD";
        switch (message_yesnocancel(tr("Print tax?"))) {
        case RESULT_YES:
            if ((prnTax = printTax(tax_mode_card)) == TAX_FAIL) {
                return;
            }
            break;
        case RESULT_CANCEL:
            return;
        }
        break;
    case 4:
        fTable->fPaymentMode = PAYMENT_CARD;
        fTable->fPaymentComment = "ARCA";
        switch (message_yesnocancel(tr("Print tax?"))) {
        case RESULT_YES:
            if ((prnTax = printTax(tax_mode_card)) == TAX_FAIL) {
                return;
            }
            break;
        case RESULT_CANCEL:
            return;
        }
        break;
    case 5:
        fTable->fPaymentMode = PAYMENT_CARD;
        fTable->fPaymentComment = "AMEX";
        switch (message_yesnocancel(tr("Print tax?"))) {
        case RESULT_YES:
            if ((prnTax = printTax(tax_mode_card)) == TAX_FAIL) {
                return;
            }
            break;
        case RESULT_CANCEL:
            return;
        }
        break;
    case 6: {
        DlgReservation *d = new DlgReservation(this);
        d->loadRoom();
        QString paymentModeComment;
        if (d->exec() == QDialog::Accepted) {
            fDD[":f_reservation"] = d->fReservationId;
            fDD.update("o_header", where_id(ap(fTable->fOrder)));
            fDD[":f_id"] = d->fReservationId;
            fDD.exec("select f_invoice, f_room, concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName) "
                       "from f_reservation r "
                       "inner join f_guests g on g.f_id=r.f_guest "
                       "where r.f_id=:f_id");
            fDD.nextRow();
            invoice = fDD.getString(0);
            room = fDD.getString(1);
            guest = fDD.getString(2);
            paymentModeComment = QString("%1, %2").arg(room).arg(guest);
            fDD[":f_reservation"] = d->fReservationId;
            fDD.exec("select f_itemId from f_reservation_item_side where f_reservation=:f_reservation");
            while (fDD.nextRow()) {
                if (Hall::fHallMap[fTable->fHall]->fItemIdForInvoice == fDD.getInt(0)) {
                    side = 1;
                    break;
                }
            }
        } else {
            delete d;
            return;
        }
        cardCode = 0;
        fTable->fPaymentMode = PAYMENT_ROOM;
        fTable->fPaymentComment = paymentModeComment;
        break;
    }
    case 7: {
        DlgReservation *d = new DlgReservation(this);
        d->loadCL();
        if (d->exec() == QDialog::Accepted) {
            cityLedger = d->fReservationId.toInt();
            CacheCityLedger ccl;
            ccl.get(d->fReservationId);
            cityLedgerName = ccl.fName();
            fDD[":f_cityLedger"] = d->fReservationId;
            fDD.update("o_header", where_id(ap(fTable->fOrder)));
            fTable->fPaymentMode = PAYMENT_CL;
            fTable->fPaymentComment = cityLedgerName;
            dc = "CREDIT";
            sign = -1;
        } else {
            delete d;
            return;
        }
        cardCode = 0;
        break;
    }
    default:
        message_error(tr("Payment mode not supported"));
        return;
    }
    fDD[":f_paymentMode"] = fTable->fPaymentMode;
    fDD[":f_paymentModeComment"] = fTable->fPaymentComment;
    fDD.update("o_header", where_id(ap(fTable->fOrder)));

    if (cardCode > 0) {
        CacheCreditCard cc;
        if (cc.get(cardCode)) {
            cardName = cc.fName();
        }
    }
    fDD[":f_id"] = fTable->fOrder;
    fDD[":f_source"] = VAUCHER_POINT_SALE_N;
    fDD[":f_wdate"] = WORKING_DATE;
    fDD[":f_rdate"] = QDate::currentDate();
    fDD[":f_time"] = QTime::currentTime();
    fDD[":f_user"] = fStaff->fId;
    fDD[":f_room"] = room;
    fDD[":f_guest"] = guest;
    fDD[":f_itemCode"] = fHall->fItemIdForInvoice;
    fDD[":f_finalName"] = Hall::fHallMap[fTable->fHall]->fName + " " + fTable->fOrder;
    fDD[":f_amountAmd"] = QLocale().toDouble(ui->tblTotal->item(1, 1)->data(Qt::EditRole).toString());
    fDD[":f_amountVat"] = Utils::countVATAmount(QLocale().toDouble(ui->tblTotal->item(1, 1)->data(Qt::EditRole).toString()), VAT_INCLUDED);
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = prnTax;
    fDD[":f_paymentMode"] = fTable->fPaymentMode;
    fDD[":f_creditCard"] = cardCode;
    fDD[":f_cityLedger"] = cityLedger;
    fDD[":f_paymentComment"] = cardName + cityLedgerName;
    fDD[":f_dc"] = dc;
    fDD[":f_sign"] = sign;
    fDD[":f_doc"] = fTable->fOrder;
    fDD[":f_rec"] = "";
    fDD[":f_inv"] = invoice;
    fDD[":f_finance"] = 1;
    fDD[":f_remarks"] = "";
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    fDD[":f_side"] = side;
    fDD[":f_cash"] = fTable->fPaymentMode == PAYMENT_CARD || fTable->fPaymentMode == PAYMENT_CARD || fTable->fPaymentMode == PAYMENT_BANK;
    fDD.insert("m_register", false);

    printReceipt(true);
    closeOrder();
    changeBtnState();
}

void RDesk::on_btnPrint_clicked()
{
    QSet<QString> prn1, prn2;
    for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
        OrderDishStruct *od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
        if (!od) {
            continue;
        }
        if (od->fState != DISH_STATE_READY) {
            continue;
        }
        if (od->fQty - od->fQtyPrint > 0.1) {
            if (!od->fPrint1.isEmpty()) {
                prn1 << od->fPrint1.toUpper();
            }
            if (!od->fPrint2.isEmpty()) {
                prn2 << od->fPrint2.toUpper();
            }
        }
    }
    bool printed = false;
    if (prn1.count() > 0) {
        for (QSet<QString>::const_iterator prn = prn1.begin(); prn != prn1.end(); prn++) {
            printServiceCheck(*prn, 1);
        }
        printed = true;
    }
    if (prn2.count() > 0) {
        for (QSet<QString>::const_iterator prn = prn2.begin(); prn != prn2.end(); prn++) {
            printServiceCheck(*prn, 2);
        }
        printed = true;
    }
    for (int i = 0; i < ui->tblOrder->rowCount(); i++) {
        OrderDishStruct *od = ui->tblOrder->item(i, 0)->data(Qt::UserRole).value<OrderDishStruct*>();
        if (!od) {
            continue;
        }
        od->fQtyPrint = od->fQty;
        updateDish(od);
    }
    countTotal();
    ui->tblOrder->viewport()->update();
    changeBtnState();
}

void RDesk::on_btnTable_clicked()
{
    checkUnprinted();
    RSelectTable *t = new RSelectTable(this);
    t->setup(fTable->fHall);
    if (t->exec() == QDialog::Accepted) {
        if (setTable(t->table())) {
            fHall = Hall::getHallById(fTable->fHall);
            if (fMenu != fHall->fDefaultMenu) {
                fMenu = fHall->fDefaultMenu;
                setBtnMenuText();
                setupType(0);
            }
        }
    }
    delete t;
    fCloseTimeout = 0;
    changeBtnState();
}

void RDesk::on_btnComment_clicked()
{
    QModelIndexList sel = ui->tblOrder->selectionModel()->selectedRows();
    if (sel.count() == 0) {
        return;
    }
    OrderDishStruct *od = sel.at(0).data(Qt::UserRole).value<OrderDishStruct*>();
    if (!od) {
        return;
    }
    if (!od->fComment.isEmpty()) {
        if (od->fQtyPrint > 0.01) {
            message_error(tr("You cannot edit comment for this item"));
            return;
        }
    }
    if (od->fQtyPrint > 0.01) {
        message_error(tr("You cannot edit comment for this item"));
        return;
    }
    QString comment;
    if (RDishComment::getComment(comment, this)) {
        od->fComment = comment;
        updateDish(od);
        ui->tblOrder->viewport()->update();
    }
}

void RDesk::on_btnTools_clicked()
{
    RTools *t = new RTools(this);
    if (t->exec() == QDialog::Accepted) {

    }
    delete t;
}

void RDesk::on_btnCheckout_clicked()
{
    printReceipt(false);
    fCloseTimeout = 0;
}

void RDesk::on_btnTransfer_clicked()
{
    int trackUser;
    if (!right(cr__o_movement, trackUser)) {
        return;
    }
    QModelIndexList sel = ui->tblOrder->selectionModel()->selectedRows();
    if (sel.count() == 0) {
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    /*------------------------------BEGIN SELECT TABLE-------------------*/
    RSelectTable *t = new RSelectTable(this);
    TableStruct *table = nullptr;
    t->setup(fTable->fHall);
    if (t->exec() == QDialog::Accepted) {
        table = t->table();
        if (table == fTable) {
            DlgSmile *ds = new DlgSmile(this);
            ds->exec();
            delete ds;
            return;
        }
        fDD.startTransaction();
        fDD.exec(QString("select f_id from r_table where f_id in (%1, %2) for update")
                .arg(fTable->fId)
                .arg(table->fId));
        if (!table->fOrder.isEmpty()) {
            if (!message_question(tr("Destination table is not empty, continue with merge?"))) {
                delete t;
                fDD.commit();
                return;
            }
        } else {
            checkOrderHeader(table, nullptr, false);
        }
        /*----------------------------- END SELECT TABLE -------------------------*/
        /*-----------------------------BEGIN MOVE DISH-----------------------------*/
        OrderDishStruct *om = sel.at(0).data(Qt::UserRole).value<OrderDishStruct*>();
        OrderDishStruct od = *om;
        om->fState = DISH_STATE_MOVED;
        setOrderRowHidden(sel.at(0).row(), om);
        updateDish(om);
        fDD[":f_header"] = table->fOrder;
        fDD[":f_state"] = od.fState;
        fDD[":f_dish"] = od.fDishId;
        fDD[":f_qty"] = od.fQty;
        fDD[":f_qtyPrint"] = od.fQtyPrint;
        fDD[":f_price"] = od.fPrice;
        fDD[":f_svcValue"] = od.fSvcValue;
        fDD[":f_svcAmount"] = od.fSvcAmount;
        fDD[":f_dctValue"] = od.fDctValue;
        fDD[":f_dctAmount"] = od.fDctAmount;
        fDD[":f_total"] = od.fTotal;
        fDD[":f_print1"] = od.fPrint1;
        fDD[":f_print2"] = od.fPrint2;
        fDD[":f_store"] = od.fStore;
        fDD[":f_comment"] = od.fComment;
        fDD[":f_staff"] = fStaff->fId;
        fDD[":f_complex"] = od.fComplex;
        fDD[":f_complexId"] = 0;
        fDD[":f_adgt"] = od.fAdgt;
        fDD[":f_complexRec"] = od.fComplexRecId;
        od.fRecId = uuidx("DR");
        fDD[":f_id"] = od.fRecId;
        fDD.insert("o_dish", false);
        if (od.fRecId.isEmpty()) {
            message_error(tr("Cannot insert new dish. Please reopen application"));
            return;
        }
        TrackControl::insert(TRACK_REST_ORDER, "Dish movement",
                                  QString("%1: %2, %3/%4")
                                  .arg(fTable->fName)
                                  .arg(od.fName[def_lang])
                                  .arg(od.fQty)
                                  .arg(od.fQtyPrint),
                                  QString("%1: %2/%3")
                                  .arg(tr("New table"))
                                  .arg(table->fName)
                                  .arg(table->fOrder), "", fTable->fOrder, "");
    }    
    fDD.commit();
    resetPrintQty();
    changeBtnState();
    /*-----------------------------END MOVE DISH-----------------------------*/
}

int RDesk::right(int right, int &trackUser)
{
    bool access = g__(right, fStaff->fId);
    trackUser = fStaff->fId;
    if (!access) {
        trackUser = 0;
        QString login;
        if (RLogin::getLogin(login, tr("Raise privileges"), this)) {
            User u(login);
            if (u.isValid()) {
                access = g__(right, u.fId);
                if (access) {
                    trackUser = u.fId;
                }
            }
        }
    }
    if (!access) {
        message_error(tr("Access denied"));
    }
    return access;
}

void RDesk::on_btnTypeUp_clicked()
{
    ui->tblType->verticalScrollBar()->setValue(ui->tblType->verticalScrollBar()->value() - 6);
}

void RDesk::on_btnTypeDown_clicked()
{
    ui->tblType->verticalScrollBar()->setValue(ui->tblType->verticalScrollBar()->value() + 6);
}

void RDesk::on_btnDishUp_clicked()
{
    ui->tblDish->verticalScrollBar()->setValue(ui->tblDish->verticalScrollBar()->value() - 6);
}

void RDesk::on_btnDishDown_clicked()
{
    ui->tblDish->verticalScrollBar()->setValue(ui->tblDish->verticalScrollBar()->value() + 6);
}

void RDesk::on_btnOrdDown_clicked()
{
    ui->tblOrder->verticalScrollBar()->setValue(ui->tblOrder->verticalScrollBar()->value() + 6);
}

void RDesk::on_btnOrdUp_clicked()
{
    ui->tblOrder->verticalScrollBar()->setValue(ui->tblOrder->verticalScrollBar()->value() - 6);
}

void RDesk::on_btnSetRoom_clicked()
{
    DoubleDatabase fDD(true, doubleDatabase);
    DlgReservation *d = new DlgReservation(this);
    d->loadRoom();
    if (d->exec() == QDialog::Accepted) {
        fDD[":f_id"] = d->fReservationId;
        fDD.exec("select r.f_room, concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName) "
                   "from f_reservation r "
                   "inner join f_guests g on g.f_id=r.f_guest "
                   "where r.f_id=:f_id");
        if (fDD.nextRow()) {
            fDD[":f_roomComment"] = fDD.getString(0) + ", " + fDD.getString(1);
            fTable->fRoomComment = fDD[":f_roomComment"].toString();
            ui->lbRoom->setText(fTable->fRoomComment);
            fDD.update("o_header", where_id(ap(fTable->fOrder)));
        }
    }
    delete d;
}

void RDesk::on_btnComplex_clicked()
{
    setComplexMode();
    fCloseTimeout = 0;
}

void RDesk::on_pushButton_clicked()
{
    printTax(0);
}

void RDesk::on_btnGuests_clicked()
{
    DlgReservation *d = new DlgReservation(this);
    d->loadRoom();
    d->exec();
    delete d;
}
