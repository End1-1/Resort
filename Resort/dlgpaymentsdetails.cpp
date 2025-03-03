#include "dlgpaymentsdetails.h"
#include "ui_dlgpaymentsdetails.h"
#include "cachepaymentmode.h"
#include "pimage.h"
#include "ptextrect.h"
#include "pprintpreview.h"
#include "cacheinvoiceitem.h"
#include "cacheactiveroom.h"
#include "pprintheader.h"
#include "dlgrefundvaucher.h"
#include "pprintvaucher.h"
#include "printtaxn.h"
#include "cachetaxmap.h"
#include "paymentmode.h"
#include "dlginvoicepaymentoptions.h"
#include "dlgprinttaxsm.h"
#include "vauchers.h"
#include <QInputDialog>

#define HINT_CITY_LEDGER 1
#define HINT_CREDIT_CARD 2
#define HINT_REFUND 3
#define HINT_ROOM 4
#define HINT_ACTIVE_ROOM 5

DlgPaymentsDetails::DlgPaymentsDetails(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgPaymentsDetails)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tblGuest, ui->tblGuest->columnCount(),
                                0, 120, 0, 200, 90, 90, 90, 200, 25, 30, 0);
    Utils::tableSetColumnWidths(ui->tblCompany, ui->tblCompany->columnCount(),
                                0, 120, 0, 200, 90, 90, 90, 200, 25, 30, 0);
    Utils::tableSetColumnWidths(ui->tblRefund, ui->tblRefund->columnCount(),
                                0, 120, 100, 100, 80, 200, 100, 30, 0);
    ui->leRoomCode->setSelector(this, cache(cid_active_room), nullptr, HINT_ACTIVE_ROOM);
    fTrackControl = new TrackControl(TRACK_RESERVATION);
    fTrackControl->fInvoice = ui->leInvoice->text();
    fTrackControl->fReservation = ui->leReservation->text();
    fCheckoutFlag = 0;
}

DlgPaymentsDetails::~DlgPaymentsDetails()
{
    delete ui;
}

void DlgPaymentsDetails::callback(int sel, const QString &code)
{
    switch (sel) {
        case HINT_CITY_LEDGER: {
            CacheCityLedger c;
            if (c.get(code)) {
                EQTableWidget *t  = ui->tabWidget->currentIndex() == 0 ? ui->tblGuest : ui->tblCompany;
                int row = t->currentRow();
                if (row < 0) {
                    return;
                }
                if (lineEdit(t, row, 10)->text() == "RV") {
                    lineEdit(t, row, 3)->setText("PAYMENT " + c.fName());
                } else {
                    lineEdit(t, row, 3)->setText("ADVANCE " + c.fName());
                }
            }
            break;
        }
        case HINT_REFUND: {
            break;
        }
        case HINT_CREDIT_CARD: {
            CacheCreditCard c;
            if (c.get(code)) {
                QTableWidget *t  = ui->tabWidget->currentIndex() == 0 ? ui->tblGuest : ui->tblCompany;
                int row = t->currentRow();
                if (row < 0) {
                    return;
                }
                if (lineEdit(t, row, 10)->text() == "RV") {
                    lineEdit(t, row, 3)->setText("PAYMENT " + c.fName());
                } else {
                    lineEdit(t, row, 3)->setText("ADVANCE " + c.fName());
                }
            }
            break;
        }
        case HINT_ROOM: {
            break;
        }
        case HINT_ACTIVE_ROOM: {
            CacheActiveRoom c;
            if (c.get(code)) {
                ui->leInvoice->setText(c.fInvoice());
                setInvoice(c.fInvoice());
                ui->leRoomCode->setText(c.fRoomCode());
            }
            break;
        }
    }
}

void DlgPaymentsDetails::setInvoice(const QString &id)
{
    ui->leInvoice->setText(id);
    DoubleDatabase fDD;
    fDD[":invoice"] = id;
    fDD.exec("select r.f_room, rm.f_short, concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName), "
             "r.f_cityLedger, cl.f_name, r.f_startDate, r.f_endDate, r.f_id, rm.f_donotdisturbe "
             "from f_reservation r "
             "inner join f_guests g on g.f_id=r.f_guest "
             "inner join f_room rm on rm.f_id=r.f_room "
             "left join f_city_ledger cl on cl.f_id=r.f_cityLedger "
             "where r.f_invoice=:invoice");
    if (fDD.nextRow()) {
        QList<QList<QVariant> > &fDbRows = fDD.fDbRows;
        ui->leRoomCode->setText(fDbRows.at(0).at(0).toString());
        ui->leRoomName->setText(fDbRows.at(0).at(1).toString());
        ui->leGuest->setText(fDbRows.at(0).at(2).toString());
        ui->leCityLedgerCode->setText(fDbRows.at(0).at(3).toString());
        ui->leCityLedgerName->setText(fDbRows.at(0).at(4).toString());
        fArrival = fDbRows.at(0).at(5).toDate();
        fDeparture = fDbRows.at(0).at(6).toDate();
        ui->leReservation->setText(fDbRows.at(0).at(7).toString());
    }
    /*-------------------- BEGIN INVOICE------------------
    fDD[":f_group1"] = IG_POSTING_CHARGES;
    fDD[":f_group2"] = IG_DISCOUNT;
    fDD[":f_group3"] = IG_NEGATIVE_BALANCE;
    fDD[":f_group4"] = IG_POSITIVE_BALANCE;*/
    fDD.exec("select sum(f_amountAmd * f_sign),sum(f_amountAmd / (f_amountUSD * f_sign)), 1 "
             "from m_register m "
             "where f_side=0 and f_finance=1 and f_canceled=0 and f_inv=" + ap(ui->leInvoice->text()) + " "
             "and f_sign=1  "
             " union "
             "select sum(f_amountAmd * f_sign),sum(f_amountUSD * f_sign), 2 "
             "from m_register "
             "where f_side=1 and f_finance=1 and f_canceled=0 and f_inv=" + ap(ui->leInvoice->text()) + " "
             "and f_sign=1  ");
    while (fDD.nextRow()) {
        if (fDD.getInt(2) == 1) {
            ui->leTotalAmdGuest->setDouble(fDD.getDouble(0));
            ui->leTotalUSDGuest->setDouble(fDD.getDouble(1));
        } else {
            ui->leTotalCompAMD->setDouble(fDD.getDouble(0));
            ui->leTotalCompUSD->setDouble(fDD.getDouble(1));
        }
    }
    /*-------------------- END INVOICE ------------------*/
    /*------------------- BEGIN PAID --------------------*/
    fDD[":f_invoice"] = ui->leInvoice->text();
    fDD.exec("select m.f_id, m.f_wdate, m.f_itemCode, m.f_finalName, "
             "m.f_paymentComment, m.f_amountAmd, "
             "m.f_amountAmd / m.f_amountUSD as amountUSD, m.f_remarks, m.f_side "
             "from m_register m "
             "where m.f_inv=:f_invoice and m.f_canceled=0 and f_finance=1 "
             "and m.f_sign=-1");
    QTableWidget *tg = ui->tblGuest;
    QTableWidget *tc = ui->tblCompany;
    tg->setRowCount(0);
    tc->setRowCount(0);
    while (fDD.nextRow()) {
        QTableWidget *t = fDD.getInt(8) == 0 ? tg : tc;
        int row = t->rowCount();
        t->setRowCount(row + 1);
        for (int i = 0, colCount = t->columnCount() - 1; i < colCount; i++) {
            createLineEdit(t, row, i);
        }
        QList<QVariant> values;
        values << fDD.getInt("f_id") // rec
               << fDD.getDate("f_wdate").toString(def_date_format) // date
               << fDD.getInt("f_itemCode") // itemid
               << fDD.getString("f_finalName") // item name
               << fDD.getString("f_paymentComment") //payment detail
               << fDD.getDouble("f_amountAmd") //amount
               << fDD.getDouble("f_amountUSD") //amount ids
               << fDD.getString("f_remarks") // remarks
               << ""
               << ""
               << ""
               ;
        setRowValues(t, row, values);
    }
    /*------------------- END PAID --------------------*/
    /*-------------- BEGIN REFUND ---------------------*/
    fDD[":f_invoice"] = ui->leInvoice->text();
    fDD.exec("select m.f_id, m.f_wdate, m.f_amountAmd, "
             "m.f_amountAmd/m.f_amountUsd, m.f_cityLedger, cl.f_name,"
             "m.f_remarks, '',  m.f_side "
             "from m_register m "
             "left join f_city_ledger cl on cl.f_id=m.f_cityLedger "
             "where m.f_inv=:f_invoice and m.f_canceled=0 "
             "and m.f_source='RF'");
    for (int i = 0, count = fDD.rowCount(); i < count; i++) {
        Utils::tableAppendRowData(ui->tblRefund, fDD.fDbRows.at(i), Qt::DisplayRole);
    }
    /*-------------- END REFUND ---------------------*/
    countRefund();
    countTotal();
    fTrackControl->resetChanges();
}

bool DlgPaymentsDetails::isZeroBalance()
{
    return float_equal(ui->leBalanceAMD->asDouble(), 0.0);
}

void DlgPaymentsDetails::setCheckoutFlag()
{
    fCheckoutFlag = 1;
}

void DlgPaymentsDetails::refundRemove(int tag)
{
    tag = -1;
    EPushButton *b = static_cast<EPushButton *>(sender());
    for (int i = 0; i < ui->tblRefund->rowCount(); i++) {
        if (ui->tblRefund->cellWidget(i, 7) == b) {
            tag = i;
            break;
        }
    }
    if (tag < 0) {
        message_error("Application error. Contact to developer. Message: refundRemove, tag=-1");
        return;
    }
    ui->tblRefund->removeRow(tag);
    double totalAmd = ui->tblRefund->sumOfColumn(2);
    double totalUsd = ui->tblRefund->sumOfColumn(3);
    ui->leRefund->setDouble(totalAmd);
    ui->leRefundUSD->setDouble(totalUsd);
    countTotal();
}

void DlgPaymentsDetails::refundTextChanged(const QString &text)
{
    EQLineEdit *l = static_cast<EQLineEdit *>(sender());
    ui->tblRefund->setValue(l->fRow, l->fColumn + 1, text.toDouble() / def_usd);
    double totalAmd = ui->tblRefund->sumOfColumn(l->fColumn);
    double totalUsd = ui->tblRefund->sumOfColumn(l->fColumn + 1);
    ui->leRefund->setDouble(totalAmd);
    ui->leRefundUSD->setDouble(totalUsd);
    countTotal();
}

void DlgPaymentsDetails::removeRowClicked(int tag)
{
    Q_UNUSED(tag)
    EPushButton *btn = static_cast<EPushButton *>(sender());
    QTableWidget *t = ui->tabWidget->currentIndex() == 0 ? ui->tblGuest : ui->tblCompany;
    for (int i = 0; i < t->rowCount(); i++) {
        if (t->cellWidget(i, btn->fColumn) == btn) {
            for (int j = 0; j < t->columnCount(); j++) {
                //                EQLineEdit *l = lineEdit(t, i, j);
                //                if (fDockCard->selector() == l) {
                //                    fDockCard->setSelector(0);
                //                }
                //                if (fDockCityLedger->selector() == l) {
                //                    fDockCityLedger->setSelector(0);
                //                }
                //                if (l) {
                //                    delete l;
                //                }
            }
            t->removeRow(i);
        }
    }
    countTotal();
}

void DlgPaymentsDetails::amountLineEditEdited(const QString &text)
{
    EQLineEdit *leAmd = static_cast<EQLineEdit *>(sender());
    QTableWidget *t = leAmd->fTag == 0 ? ui->tblGuest : ui->tblCompany;
    EQLineEdit *leUsd = lineEdit(t, leAmd->fRow, leAmd->fColumn + 1);
    leUsd->setDouble(text.toDouble() / def_usd);
    countTotal();
}

void DlgPaymentsDetails::countTotal()
{
    ui->lePaidAMDGuest->setDouble(countTotal(ui->tblGuest, 0));
    ui->lePaidUSDGuest->setDouble(countTotal(ui->tblGuest, 1));
    ui->leBalanceAMDGuest->setDouble(ui->leTotalAmdGuest->asDouble() + ui->leRefund->asDouble() -
                                     ui->lePaidAMDGuest->asDouble());
    ui->leBalanceUSDGuest->setDouble(ui->leTotalUSDGuest->asDouble() + ui->leRefundUSD->asDouble() -
                                     ui->lePaidUSDGuest->asDouble());
    ui->lePaidCompAMD->setDouble(countTotal(ui->tblCompany, 0));
    ui->lePaidCompUSD->setDouble(countTotal(ui->tblCompany, 1));
    ui->leBalanceCompAMD->setDouble(ui->leTotalCompAMD->asDouble() - ui->lePaidCompAMD->asDouble());
    ui->leBalanceCompUSD->setDouble(ui->leTotalCompUSD->asDouble() - ui->lePaidCompUSD->asDouble());
    ui->leTotalAMD->setDouble(ui->leTotalAmdGuest->asDouble() + ui->leTotalCompAMD->asDouble());
    ui->leTotalUSD->setDouble(ui->leTotalUSDGuest->asDouble() + ui->leTotalCompUSD->asDouble());
    ui->lePaidAMD->setDouble(ui->lePaidAMDGuest->asDouble() + ui->lePaidCompAMD->asDouble());
    ui->lePaidUSD->setDouble(ui->lePaidUSDGuest->asDouble() + ui->lePaidCompUSD->asDouble());
    ui->leBalanceAMD->setDouble(ui->leBalanceAMDGuest->asDouble() + ui->leBalanceCompAMD->asDouble());
    ui->leBalanceUSD->setDouble(ui->leBalanceUSDGuest->asDouble() + ui->leBalanceCompUSD->asDouble());
}

void DlgPaymentsDetails::printPayment(EQTableWidget *t, QList<int> &rows)
{
    foreach (int r, rows) {
        PPrintVaucher::printVaucher(t->toString(r, 0));
    }
}

double DlgPaymentsDetails::countTotal(QTableWidget *t, int curr)
{
    int col = 5 + curr;
    double result = 0;
    for (int i = 0, rowCount = t->rowCount(); i < rowCount; i++) {
        EQLineEdit *l = lineEdit(t, i, col);
        result += l->asDouble();
    }
    return result;
}

void DlgPaymentsDetails::countRefund()
{
    ui->leRefund->setDouble(ui->tblRefund->sumOfColumn(2));
    ui->leRefundUSD->setDouble(ui->tblRefund->sumOfColumn(3));
}

void DlgPaymentsDetails::newPaidRow(int mode)
{
    if (mode == PAYMENT_CL) {
        if (!fCheckoutFlag) {
            message_error(tr("This payment mode available after checkout"));
            return;
        }
    }
    int side = ui->tabWidget->currentIndex();
    if (side == 2) {
        newRefundRow(mode);
        return;
    }
    QString rv = "RV";
    QString finalName = "PAYMENT";
    double amount = side == 0 ? ui->leBalanceAMDGuest->asDouble() : ui->leBalanceCompAMD->asDouble();
    if (amount < 0.01) {
        amount = 0;
    }
    CachePaymentMode ci;
    ci.get(mode);
    QTableWidget *t = side == 0 ? ui->tblGuest : ui->tblCompany;
    int row = t->rowCount();
    t->setRowCount(row + 1);
    t->setCurrentCell(row, 0);
    EQLineEdit *cardCLSelect = nullptr;
    for (int i = 0, colCount = t->columnCount(); i < colCount; i++) {
        EQLineEdit *l = createLineEdit(t, row, i);
        l->fTag = side;
    }
    EQLineEdit *le = lineEdit(t, row, 4);
    if (mode == PAYMENT_CL) {
        le->setSelector(this, cache(cid_city_ledger), lineEdit(t, row, 7), HINT_CITY_LEDGER);
        cardCLSelect = le;
    } else if (mode == PAYMENT_CARD) {
        le->setSelector(this, cache(cid_credit_card), lineEdit(t, row, 7), HINT_CREDIT_CARD);
        cardCLSelect = le;
    }
    EPushButton *b = new EPushButton(this);
    b->setMaximumSize(25, 25);
    b->setMinimumSize(25, 25);
    b->setIcon(QIcon(":/images/garbage.png"));
    b->setTag(row);
    b->fColumn = 8;
    connect(b, SIGNAL(clickedWithTag(int)), this, SLOT(removeRowClicked(int)));
    t->setCellWidget(row, 8, b);
    QList<QVariant> values;
    if (mode == PAYMENT_CL) {
        finalName = "CHECKOUT C/L";
    } else {
        finalName += " " + ci.fName();
    }
    values << ""
           << WORKING_DATE.toString(def_date_format)
           << ci.fCode()
           << finalName
           << ""
           << amount
           << float_str(amount / def_usd, 2)
           << ""
           << ""
           << ""
           << rv;
    setRowValues(t, row, values);
    EQLineEdit *l = lineEdit(t, row, 5);
    l->setValidator(new QDoubleValidator(0, 999999999, 2));
    l->setReadOnly(false);
    connect(l, SIGNAL(textEdited(QString)), this, SLOT(amountLineEditEdited(QString)));
    countTotal();
    if (mode == PAYMENT_CL) {
        lineEdit(t, row, 4)->setText(ui->leCityLedgerCode->text());
        lineEdit(t, row, 7)->setText(ui->leCityLedgerName->text());
    }
    if (mode == PAYMENT_CL || mode == PAYMENT_CARD) {
        if (cardCLSelect) {
            cardCLSelect->setFocus();
            if (mode == PAYMENT_CARD) {
                cardCLSelect->doubleClickEvent();
            }
        }
    }
}

void DlgPaymentsDetails::newRefundRow(int mode)
{
    DlgRefundVaucher::refundVaucher("", ui->leReservation->text());
    setInvoice(ui->leInvoice->text());
    return;
    int side = 0;
    switch (mode) {
        case PAYMENT_CASH:
            break;
        case PAYMENT_CARD:
            message_error(tr("This mode is not available for refund."));
            break;
        case PAYMENT_BANK:
            break;
        case PAYMENT_CL:
            side = 1;
            break;
    }
    int row = ui->tblRefund->rowCount();
    ui->tblRefund->setRowCount(row + 1);
    ui->tblRefund->setItemWithValue(row, 0, "");
    ui->tblRefund->setItemWithValue(row, 1, WORKING_DATE);
    ui->tblRefund->setItemWithValue(row, 2, 0);
    ui->tblRefund->setItemWithValue(row, 3, 0);
    ui->tblRefund->setItemWithValue(row, 4, 0);
    ui->tblRefund->setItemWithValue(row, 5, "");
    ui->tblRefund->setItemWithValue(row, 6, "");
    ui->tblRefund->setItemWithValue(row, 7, "");
    ui->tblRefund->setItemWithValue(row, 8, side);
    EQLineEdit *line = ui->tblRefund->addLineEdit(row, 2, true);
    line->setFont(ui->tblRefund->font());
    connect(line, SIGNAL(textChanged(QString)), this, SLOT(refundTextChanged(QString)));
    if (ui->leBalanceAMD->asDouble() < 0) {
        line->setDouble(ui->leBalanceAMD->asDouble() * -1);
    }
    if (mode == PAYMENT_CL) {
        EQLineEdit *lineCity = ui->tblRefund->addLineEdit(row, 4, true);
        connect(lineCity, SIGNAL(focusIn()), this, SLOT(refundLineFocusIn()));
        if (ui->leCityLedgerCode->asInt() == 0) {
            ui->tblRefund->lineEdit(row, 4)->setFocus();
        } else {
            ui->tblRefund->lineEdit(row, 4)->setText(ui->leCityLedgerCode->text());
            ui->tblRefund->setItemWithValue(row, 5, ui->leCityLedgerName->text());
        }
    }
    ui->tblRefund->addButton(row, 7, SLOT(refundRemove(int)), this, QIcon(":/images/garbage.png"));
    countRefund();
    countTotal();
}

void DlgPaymentsDetails::setRowValues(QTableWidget *t, int row, const QList<QVariant> &values)
{
    for (int i = 0, count = values.count(); i < count; i++) {
        t->setItem(row, i, new C5TableWidgetItem(values.at(i).toString()));
        EQLineEdit *l = lineEdit(t, row, i);
        if (!l) {
            continue;
        }
        l->fRow = row;
        l->fColumn = i;
        l->fTable = t;
        connect(l, &EQLineEdit::textChanged, [this](const QString &text) {
            EQLineEdit *e = dynamic_cast<EQLineEdit *>(sender());
            if (!e) {
                return;
            }
            e->fTable->item(e->fRow, e->fColumn)->setText(text);
        });
        l->setText(values.at(i).toString());
    }
}

EQLineEdit *DlgPaymentsDetails::createLineEdit(QTableWidget *t, int row, int column)
{
    EQLineEdit *le = new EQLineEdit(this);
    le->setFont(t->font());
    le->setReadOnly(true);
    le->fRow = row;
    le->fColumn = column;
    le->setFrame(false);
    t->setCellWidget(row, column, le);
    return le;
}

EQLineEdit *DlgPaymentsDetails::lineEdit(QTableWidget *t, int row, int column)
{
    EQLineEdit *l = dynamic_cast<EQLineEdit *>(t->cellWidget(row, column));
    return l;
}

bool DlgPaymentsDetails::savePayment(QTableWidget *t, int side, QList<int> &printRows)
{
    if (fCheckoutFlag) {
    }
    //QString sideRemarks = (side == 0 ? "Payment, guest" : "Payment, company");
    for (int i = 0, rowCount = t->rowCount(); i < rowCount; i++) {
        if (lineEdit(t, i, 5)->asDouble() < 0.1) {
            message_error(tr("Amount cannot be zero"));
            return false;
        }
        int pmMode = lineEdit(t, i, 2)->text().toInt();
        EQLineEdit *l = lineEdit(t, i, 0);
        if (l->isEmpty()) {
            printRows << i;
            int creditCard = 0;
            int clCode = 0;
            QString modeName = "";
            switch (pmMode) {
                case PAYMENT_CASH:
                    modeName = "CASH";
                    break;
                case PAYMENT_CARD:
                    creditCard = lineEdit(t, i, 4)->text().toInt();
                    modeName = lineEdit(t, i, 7)->text();
                    break;
                case PAYMENT_BANK:
                    modeName = "BANK";
                    break;
                case PAYMENT_CL:
                    lineEdit(t, i, 3)->setText(QString("CHECKOUT %1, %2").arg(ui->leRoomCode->text()).arg(ui->leGuest->text()));
                    clCode = lineEdit(t, i, 4)->text().toInt();
                    modeName = "CHECKOUT " + lineEdit(t, i, 7)->text();
                    break;
            }
            QString finalName = QString("%1 #%2 %3")
                                .arg("PAYMENT")
                                .arg(ui->leInvoice->text())
                                .arg(modeName);
            if (fCheckoutFlag) {
                finalName = "STL. #" + ui->leInvoice->text() + " " + modeName;
            }
            QString rid = uuidx(t->item(i, 10)->text());
            DoubleDatabase fDD;
            fDD.insertId("m_register", rid);
            fDD[":f_source"] = t->item(i, 10)->text();
            fDD[":f_res"] = ui->leReservation->text();
            fDD[":f_wdate"] = WORKING_DATE;
            fDD[":f_rdate"] = QDate::currentDate();
            fDD[":f_time"] = QTime::currentTime();
            fDD[":f_user"] = WORKING_USERID;
            fDD[":f_room"] = ui->leRoomCode->text();
            fDD[":f_guest"] = ui->leGuest->text();
            fDD[":f_itemCode"] = fPreferences.getDb(def_receip_vaucher_id);
            fDD[":f_finalName"] = lineEdit(t, i, 3)->text();
            fDD[":f_amountAmd"] = lineEdit(t, i, 5)->asDouble();
            fDD[":f_amountVat"] = 0;
            fDD[":f_amountUsd"] = def_usd;
            fDD[":f_fiscal"] = 0;
            fDD[":f_paymentMode"] = lineEdit(t, i, 2)->text();
            fDD[":f_creditCard"] = creditCard;
            fDD[":f_cityLedger"] = clCode;
            fDD[":f_paymentComment"] = modeName;
            fDD[":f_dc"] = "CREDIT";
            fDD[":f_sign"] = -1;
            fDD[":f_doc"] = "";
            fDD[":f_rec"] = "";
            fDD[":f_inv"] = ui->leInvoice->text();
            fDD[":f_finance"] = 1;
            fDD[":f_remarks"] = "";
            fDD[":f_canceled"] = 0;
            fDD[":f_cancelReason"] = "";
            fDD[":f_side"] = side;
            fDD[":f_cash"] = pmMode == PAYMENT_CL ? 0 : 1;
            fDD[":f_session"] = 0;
            fDD.update("m_register", where_id(ap(rid)));
            t->item(i, 0)->setText(rid);
            lineEdit(t, i, 0)->setText(rid);
            fTrackControl->fRecord = rid;
            fTrackControl->insert("Payment" + QString(fCheckoutFlag ? " before checkout" : " from invoice"), t->item(i, 0)->text(),
                                  lineEdit(t, i, 3)->text() + " " + lineEdit(t, i, 5)->text());
            if (t->item(i, 10)->text() == "AV") {
                if (message_confirm(QString::fromUtf8("Տպել կանխավճարի ՀԴՄ՞ ") + lineEdit(t, i,
                                    5)->text() + " AMD") == QDialog::Accepted) {
                    int tc;
                    QString outJson;
                    CacheInvoiceItem c;
                    if (!c.get(fPreferences.getDb(def_advance_voucher_id).toInt())) {
                        message_error(tr("Error in tax print. c == 0, case 2."));
                        continue;
                    }
                    CacheTaxMap ci;
                    if (!ci.get(c.fCode())) {
                        message_error(tr("No taxmap for ") + c.fName());
                        return false;
                    }
                    if (DlgPrintTaxSM::printAdvance(ci.fTax(), lineEdit(t, i, 5)->text().toDouble(),  lineEdit(t, i, 2)->asInt(),
                                                    ui->leInvoice->text(),
                                                    rid, tc, outJson)) {
                        fDD[":f_prepaid"] = lineEdit(t, i, 5)->text().toDouble();
                        fDD[":f_id"] = ui->leInvoice->text();
                        fDD.exec("update m_v_invoice set f_prepaid=f_prepaid+:f_prepaid where f_id=:f_id");
                        fDD[":f_fiscal"] = tc;
                        fDD.update("m_register", where_id(ap(rid)));
                    }
                }
            }
            t->removeCellWidget(i, 8);
        }
    }
    return true;
}

void DlgPaymentsDetails::on_btnCash_clicked()
{
    newPaidRow(PAYMENT_CASH);
}

void DlgPaymentsDetails::on_btnCard_clicked()
{
    newPaidRow(PAYMENT_CARD);
}

void DlgPaymentsDetails::on_btnCityLedger_clicked()
{
    newPaidRow(PAYMENT_CL);
}

void DlgPaymentsDetails::on_btnBank_clicked()
{
    newPaidRow(PAYMENT_BANK);
}

void DlgPaymentsDetails::on_btnSave_clicked()
{
    fTrackControl->fInvoice = ui->leInvoice->text();
    fTrackControl->fReservation = ui->leReservation->text();
    if (fPreferences.getDb(def_invoice_default_refund_id).toInt() == 0) {
        message_error(tr("Refund id is not defined. Contact to administrator."));
        return;
    }
    QTableWidget *t = ui->tblGuest;
    for (int i = 0, rowCount = ui->tblGuest->rowCount(); i < rowCount; i++) {
        if (lineEdit(t, i, 2)->asInt() == PAYMENT_CARD ||
                lineEdit(t, i, 2)->asInt() == PAYMENT_CL) {
            if (lineEdit(t, i, 4)->asInt() == 0) {
                message_error(tr("Payment mode is credit card or city ledger, but account field is empty"));
                return;
            }
        }
    }
    t = ui->tblCompany;
    for (int i = 0, rowCount = ui->tblCompany->rowCount(); i < rowCount; i++) {
        if (lineEdit(t, i, 2)->asInt() == PAYMENT_CARD ||
                lineEdit(t, i, 2)->asInt() == PAYMENT_CL) {
            if (lineEdit(t, i, 4)->asInt() == 0) {
                message_error(tr("Payment mode is credit card or city ledger, but account field is empty"));
                return;
            }
        }
    }
    QList<int> printRefundRow;
    DoubleDatabase fDD;
    fDD.startTransaction();
    QList<int> printRows1;
    QList<int> printRows2;
    if (!savePayment(ui->tblGuest, 0, printRows1)) {
        if (printRows1.count() > 0 && !DlgInvoicePaymentOptions::doNotPrintVoucher()) {
            printPayment(ui->tblGuest, printRows1);
        }
        return;
    }
    if (!savePayment(ui->tblCompany, 1, printRows2)) {
        if (printRows2.count() > 0 && !DlgInvoicePaymentOptions::doNotPrintVoucher()) {
            printPayment(ui->tblCompany, printRows2);
        }
        return;
    }
    for (int i = 0, rowCount = ui->tblRefund->rowCount(); i < rowCount; i++) {
        if (ui->tblRefund->toString(i, 0).isEmpty()) {
            printRefundRow << i;
            fDD.startTransaction();
            QString rid = uuidx(VAUCHER_REFUND_N);
            fDD.insertId("m_register", rid);
            fDD[":f_source"] = VAUCHER_REFUND_N;
            fDD[":f_wdate"] = WORKING_DATE;
            fDD[":f_rdate"] = QDate::currentDate();
            fDD[":f_time"] = QTime::currentTime();
            fDD[":f_user"] = WORKING_USERID;
            fDD[":f_room"] = ui->leRoomName->text();
            fDD[":f_guest"] = ui->leGuest->text();
            fDD[":f_itemCode"] = fPreferences.getDb(def_invoice_default_refund_id);
            fDD[":f_finalName"] = tr("REFUND ") + rid;
            fDD[":f_amountAmd"] = ui->tblRefund->lineEdit(i, 2)->asDouble();
            fDD[":f_amountVat"] = 0;
            fDD[":f_amountUsd"] = def_usd;
            fDD[":f_fiscal"] = 0;
            fDD[":f_paymentMode"] = PAYMENT_CREDIT;
            fDD[":f_creditCard"] = 0;
            fDD[":f_cityLedger"] = ui->tblRefund->toInt(i, 4);
            fDD[":f_paymentComment"] = (ui->tblRefund->toInt(i, 4) ? ui->tblRefund->toString(i, 5) : "");
            fDD[":f_dc"] = "DEBIT";
            fDD[":f_sign"] = 1;
            fDD[":f_doc"] = "";
            fDD[":f_rec"] = "";
            fDD[":f_inv"] = ui->leInvoice->text();
            fDD[":f_finance"] = 1;
            fDD[":f_remarks"] = ui->tblRefund->toString(i, 6);
            fDD[":f_canceled"] = 0;
            fDD[":f_cancelReason"] = "";
            fDD[":f_side"] = ui->tblRefund->toInt(i, 8);
            fDD[":f_cash"] = 0;
            fDD[":f_session"] = 0;
            fDD.update("m_register", where_id(ap(rid)));
            ui->tblRefund->setValue(i, 0, rid);
            fTrackControl->insert("Refund", ui->tblRefund->toString(i, 2), "");
        }
    }
    fTrackControl->saveChanges();
    fDD.commit();
    if (printRows1.count() > 0 && !DlgInvoicePaymentOptions::doNotPrintVoucher()) {
        printPayment(ui->tblGuest, printRows1);
    }
    if (printRows2.count() > 0 && !DlgInvoicePaymentOptions::doNotPrintVoucher()) {
        printPayment(ui->tblCompany, printRows2);
    }
    if (printRefundRow.count() > 0 && !DlgInvoicePaymentOptions::doNotPrintVoucher()) {
        foreach (int i, printRefundRow) {
            PPrintVaucher::printVaucher(ui->tblRefund->toString(i, 0));
        }
    }
    if (fCheckoutFlag && DlgInvoicePaymentOptions::closeAfterSaveCheckout()) {
        accept();
    }
}

void DlgPaymentsDetails::on_btnOptions_clicked()
{
    DlgInvoicePaymentOptions *d = new DlgInvoicePaymentOptions(this);
    d->exec();
    delete d;
}

void DlgPaymentsDetails::on_btnBankPayX_clicked()
{
    newPaidRow(PAYMENT_PAYX);
}

void DlgPaymentsDetails::on_btnBankPayX_2_clicked()
{
    newPaidRow(PAYMENT_TERMINAL);
}

void DlgPaymentsDetails::on_btnCPay_clicked()
{
    newPaidRow(PAYMENT_CPAY);
}
