#include "dlgendofday.h"
#include "ui_dlgendofday.h"
#include "cacheinvoiceitem.h"
#include "wreservation.h"
#include "winvoice.h"
#include "paymentmode.h"
#include "utils.h"
#include "vauchers.h"

DlgEndOfDay::DlgEndOfDay(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgEndOfDay)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tblCharges, ui->tblCharges->columnCount(), 0, 0, 0, 80, 250, 80, 80, 120, 120, 100, 100, 0, 0);
    fCanCharge = true;
    ui->lbLastDate->setText(QString("%1 - %2")
                            .arg(tr("Last charge date"))
                            .arg(WORKING_DATE.addDays(-1).toString(def_date_format)));
    ui->lbCurrentDate->setText(QString("%1 - %2")
                            .arg(tr("Current charge date"))
                            .arg(WORKING_DATE.toString(def_date_format)));
    loadData();
    fTrackControl = new TrackControl(TRACK_RESERVATION);
}

DlgEndOfDay::~DlgEndOfDay()
{
    delete ui;
}

void DlgEndOfDay::openReservation(const QString &id)
{
    WReservation::openReserveWindows(id);
}

void DlgEndOfDay::openInvoice(const QString &id)
{
    WInvoice::openInvoiceWindow(id);
}

void DlgEndOfDay::on_btnCancel_clicked()
{
    reject();
}

void DlgEndOfDay::on_btnOk_clicked()
{
    if (!fCanCharge) {
        message_error(tr("Unable to complete automatic charging, check the booking"));
        return;
    }

    QString query;
    bool first = true;
    bool result = true;
    DoubleDatabase fDD;
    fDD.startTransaction();
    for (int i = 0, count = ui->tblCharges->rowCount(); i < count; i++) {

        double amount = ui->tblCharges->item(i, 8)->data(Qt::EditRole).toDouble();
        double vatAmount = 0;
        int vat = ui->tblCharges->item(i, 1)->data(Qt::EditRole).toInt();
        switch (vat) {
        case VAT_NOVAT:
            break;
        case VAT_INCLUDED:
            vatAmount = amount - (amount / ((20.0 / 100.0) + 1));
            break;
        case VAT_WITHOUT:
            vatAmount = amount * (20.0 / 100.0);
            break;
        }

        QString invoice = ui->tblCharges->item(i, 0)->data(Qt::EditRole).toString();
        QString rid = uuidx(VAUCHER_ROOMING_N);
        result = fDD.insertId("m_register", rid);
        if (!result) {
            break;
        }
        fDD[":f_source"] = VAUCHER_ROOMING_N;
        fDD[":f_res"] = ui->tblCharges->toString(i, 2);
        fDD[":f_wdate"] = WORKING_DATE;
        fDD[":f_rdate"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_user"] = WORKING_USERID;
        fDD[":f_room"] = ui->tblCharges->item(i, 3)->data(Qt::EditRole).toInt();
        fDD[":f_guest"] = ui->tblCharges->item(i, 4)->data(Qt::EditRole).toString();
        fDD[":f_itemCode"] = fPreferences.getDb(def_room_charge_id);
        CacheInvoiceItem cii;
        cii.get(fPreferences.getDb(def_room_charge_id).toString());
        fDD[":f_finalName"] = QString("%1 %2 - %3")
                .arg(cii.fName())
                .arg(WORKING_DATE.toString(def_date_format))
                .arg(ui->tblCharges->item(i, 11)->data(Qt::EditRole).toString());
        fDD[":f_amountAmd"] = amount;
        fDD[":f_amountVat"] = vatAmount;
        fDD[":f_amountUsd"] = def_usd;
        fDD[":f_fiscal"] = 0;
        fDD[":f_vatmode"] = vat;
        fDD[":f_paymentMode"] = PAYMENT_CREDIT;
        fDD[":f_creditCard"] = 0;
        fDD[":f_cityLedger"] = 0;
        fDD[":f_paymentComment"] = "";
        fDD[":f_dc"] = "CREDIT";
        fDD[":f_sign"] = 1;
        fDD[":f_doc"] = "";
        fDD[":f_rec"] = "";
        fDD[":f_inv"] = invoice;
        fDD[":f_finance"] = 1;
        fDD[":f_remarks"] = "";
        fDD[":f_canceled"] = 0;
        fDD[":f_cancelReason"] = "";
        if (fPreferences.getDb(def_rooming_eod_default_side).toInt() == 1) {
            if (ui->tblCharges->item(i, 12)->data(Qt::EditRole).toInt() > 0) {
                fDD[":f_side"] =  1;
            } else {
                fDD[":f_side"] = 0;
            }
        } else {
            fDD[":f_side"] = 0;
        }
        fDD[":f_cash"] = 0;
        result = result && fDD.update("m_register", where_id(ap(rid)));
        fTrackControl->resetChanges();
        fTrackControl->fRecord = rid;
        fTrackControl->fInvoice = invoice;
        fTrackControl->fReservation = ui->tblCharges->toString(i, 2);
        fTrackControl->insert("EOD ROOMING", "", QString("%1 %2AMD")
                .arg(ui->tblCharges->item(i, 3)->data(Qt::EditRole).toInt())
                .arg(amount));
        if (!result) {
            break;
        }
    }

    query = QString("update f_global_settings set f_value='%1' where f_settings=1 and f_key='%2'")
                .arg(WORKING_DATE.addDays(1).toString(def_date_format), def_working_day);
    if (result) {
        result = fDD.exec(query);
    }

    /* --------------- BEGIN ROOM VACANCY HISTORY ---------------- */
    QList<QList<QVariant> > dbrows;
    fDD.exec("select f_id, f_state from f_room", dbrows);
    first = true;
    query = "insert into f_room_vacancy (f_room, f_date, f_state) values ";
    QListIterator<QList<QVariant> > it(dbrows);
    while (it.hasNext()) {
        QList<QVariant> row = it.next();
        if (first) {
            first = false;
        } else {
            query += ",";
        }
        query += QString("(%1, '%2', %3)")
                .arg(row.at(0).toInt())
                .arg(WORKING_DATE.toString(def_mysql_date_format))
                .arg(row.at(1).toInt());
    }
    if (!first && result) {
        result = result && fDD.exec(query);
    }
    /* --------------- END ROOM VACANCY HISTORY ---------------- */

    /* --------------- BEGIN GUESTS COUNT HISTORY ----------------*/
    fDD.exec("select f_reservation, f_guest from f_reservation_guests "
               "where f_reservation in (select f_id from f_reservation where f_state=1)", dbrows);
    query = "";
    first = true;

    for (int i = 0; i < dbrows.count(); i++) {
        if (i == 0) {
            query = "insert into f_reservation_guests_history (f_date, f_reservation,f_guest) values ";
        }
        if (first) {
            first = false;
        } else {
            query += ",";
        }
        query += QString("('%1', '%2', %3)")
                .arg(WORKING_DATE.toString(def_mysql_date_format))
                .arg(dbrows.at(i).at(0).toString())
                .arg(dbrows.at(i).at(1).toInt());

    }
    if (result && !query.isEmpty()) {
        result = result && fDD.exec(query);
    }
    /* --------------- END GUESTS COUNT HISTORY ----------------*/

    /*------- CORRECT DATE CASH FOR OPENED ORDERS AT RESTAURANT-------*/
    if (result) {
        fDD[":f_dateCash"] = WORKING_DATE.addDays(1);
        result = result && fDD.update("o_header", where_field("f_state", 1));
    }
    /*------- END CORRECT DATE CASH FOR OPENED ORDERS AT RESTAURANT-------*/

    /*-------------------- MEAL ---------------------------------------*/
    fDD[":f_state"] = RESERVE_CHECKIN;
    fDD.exec("select r.f_id, f_man + f_woman + f_child "
               "from f_reservation r "
               "where r.f_state=:f_state ", dbrows);
    query = "";
    first = true;
    for (int i = 0; i < dbrows.count(); i++) {
        if (first) {
            first = false;
        } else {
            query += ",";
        }
        query += QString("('%1', '%2', %3, %4, %5)")
                .arg(dbrows.at(i).at(0).toInt())
                .arg(WORKING_DATE.addDays(1).toString(def_mysql_date_format))
                .arg(dbrows.at(i).at(1).toString())
                .arg(0)
                .arg(0)
                ;
    }
    if (!query.isEmpty()) {
        query = "insert into f_reservation_meal (f_reservation, f_date, f_guests, f_show, f_doc) values "
                + query;
        result = result && fDD.exec(query);
    }
    /*-------------------- END MEAL ---------------------------------------*/


    /*-------------------- CURRENCIES RATES ----------------------*/
    if (result) {
        fDD.exec("select f_id, f_rate from f_acc_currencies");
        QStringList l;
        while (fDD.nextRow()) {
            l << QString("insert into f_acc_currency_rate (f_date, f_currency, f_rate) values ('%1', %2, %3)")
                 .arg(WORKING_DATE.toString(def_mysql_date_format))
                 .arg(fDD.getInt(0))
                 .arg(fDD.getDouble(1));
        }
        foreach (QString s, l) {
            fDD.exec(s);
        }
    }

    /* SET AUTOMATICALLY TAX FISCAL FLAG */
    fDD[":f_itemCode"] = fPreferences.getDb(def_room_charge_id).toInt();
    fDD[":f_wdate"] = WORKING_DATE;
    fDD.exec("select f_id, f_inv, f_amountAmd from m_register where f_itemCode=:f_itemCode "
               "and f_wdate=:f_wdate and f_fiscal=0 and f_canceled=0", dbrows);
    /* OLD VERSION */
    QList<QList<QVariant> > dbrowTax;
    fDD.exec("select f_id, f_invoice, f_amount, f_source, f_taxcode from m_free_tax where f_used=0 and f_source='RM' and f_taxCode <= 1", dbrowTax);
    for (int j = 0; j < dbrows.count(); j++) {
        QString inv = dbrows.at(j).at(1).toString();
        for (int i = dbrowTax.count() - 1; i > -1; i--) {
            if ((inv == dbrowTax.at(i).at(1).toString()) && isDoubleEqual(dbrows.at(j).at(2).toDouble(), dbrowTax.at(i).at(2).toDouble(), 2)) {
                fDD[":f_fiscal"] = dbrowTax.at(i).at(4);
                fDD.update("m_register", where_id(ap(dbrows.at(j).at(0).toString())));
                fDD[":f_used"] = 1;
                fDD.update("m_free_tax", where_id(dbrowTax.at(i).at(0).toInt()));
                dbrowTax.removeAt(i);
                break;
            }
        }
    }
    /* NEW VERSION */
    fDD.exec("select f_id, f_invoice, f_amount, f_source, f_taxcode from m_free_tax where f_used=0 and f_source='RM' and f_taxCode>1", dbrowTax);
    for (int j = 0; j < dbrows.count(); j++) {
        QString inv = dbrows.at(j).at(1).toString();
        for (int i = dbrowTax.count() - 1; i > -1; i--) {
            if ((inv == dbrowTax.at(i).at(1).toString()) && isDoubleEqual(dbrows.at(j).at(2).toDouble(), dbrowTax.at(i).at(2).toDouble(), 2)) {
                fDD[":f_fiscal"] = dbrowTax.at(i).at(4);
                fDD.update("m_register", where_id(ap(dbrows.at(j).at(0).toString())));
                fDD[":f_used"] = 1;
                fDD.update("m_free_tax", where_id(dbrowTax.at(i).at(0).toInt()));
                dbrowTax.removeAt(i);
                break;
            }
        }
    }

    /* ROOM STATE. OUT OF ORDER AND OUT OF INVENTORY */

    fDD[":f_state1"] = RESERVE_OUTOFINVENTORY;
    fDD[":f_state2"] = RESERVE_OUTOFROOM;
    fDD[":f_startDate"] = WORKING_DATE;
    fDD.exec("select f_room, f_state from f_reservation where f_state=:f_state1 or f_state=:f_state2 "
                " and f_startDate=:f_startDate", dbrows);
    for (int i = 0; i < dbrows.count(); i++) {
        int state = 0;
        switch (dbrows.at(i).at(1).toInt()) {
        case RESERVE_OUTOFINVENTORY:
            state = ROOM_STATE_OUTINVENTORY;
            break;
        case RESERVE_OUTOFROOM:
            state = ROOM_STATE_OUTOF;
            break;
        }
        fDD[":f_room"] = dbrows.at(i).at(0);
        QList<QList<QVariant> > dbroom;
        fDD.exec("select f_state from f_room where f_id=:f_room", dbroom);
        fDD[":f_state"] = state;
        fDD.update("f_room", where_id(dbrows.at(i).at(0).toInt()));
        fDD[":f_date"] = QDate::currentDate();
        fDD[":f_wdate"] = WORKING_DATE;
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_oldState"] = dbroom.at(0).at(0);
        fDD[":f_newState"] = state;
        fDD[":f_user"] = WORKING_USERID;
        fDD[":f_comment"] = "EOD";
        fDD.insert("f_room_state_change", false);
    }

    /* remove expired out of order and out of inventory */
    fDD[":f_state1"] = RESERVE_OUTOFINVENTORY;
    fDD[":f_state2"] = RESERVE_OUTOFROOM;
    fDD[":f_endDate"] = WORKING_DATE;
    fDD.exec("select f_room, f_state from f_reservation where f_state=:f_state1 or f_state=:f_state2 "
                " and f_endDate=:f_endDate", dbrows);
    for (int i = 0; i <dbrows.count(); i++) {
        QList<QList<QVariant> > droom;
        fDD[":f_room"] = dbrows.at(i).at(0);
        fDD.exec("select f_state from f_room where f_id=:f_room", droom);
        fDD[":f_state"] = ROOM_STATE_DIRTY;
        fDD.update("f_room", where_id(dbrows.at(i).at(0).toInt()));
        fDD[":f_date"] = QDate::currentDate();
        fDD[":f_wdate"] = WORKING_DATE;
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_oldState"] = droom.at(0).at(0);
        fDD[":f_newState"] = ROOM_STATE_NONE;
        fDD[":f_user"] = WORKING_USERID;
        fDD[":f_comment"] = "EOD";
        fDD.insert("f_room_state_change", false);
    }

    /* ADD DAY TO S_DAYS SYSTEM TABLE */
    fDD[":f_date"] = WORKING_DATE.addDays(1);
    fDD.exec("select f_id from s_days where f_date=:f_date");
    if (!fDD.nextRow()) {
        fDD[":f_date"] = WORKING_DATE.addDays(1);
        fDD.insert("s_days");
    }
    /* END OF ADD DAY TO S_DAYS SYSTEM TABLE */

    if (fPreferences.getDb(def_user_auto_session).toBool()) {
        fDD.exec("update s_user_session set f_end=current_timestamp");
    }

    if (result) {
        fDD.exec("insert into f_eod (f_date) values (current_timestamp())");
        fDD.commit();
        fPreferences.setLocalDate(def_working_day, WORKING_DATE.addDays(1));
        if (!fPreferences.getDb(def_external_rest_db).toString().isEmpty()) {
            DoubleDatabase de(__dd1Host, fPreferences.getDb(def_external_rest_db).toString(), __dd1Username, __dd1Password);
            if (de.open()) {
                de[":f_datecash"] = WORKING_DATE;
                de.exec("update s_station_conf set f_datecash=:f_datecash");
            }
        }
        BroadcastThread::cmdCommand(cmd_end_of_day, QMap<QString, QString>());
        accept();
    } else {
        fDD.rollback();
        message_error(tr("Error in query, automatic charging not complete"));
    }

}

void DlgEndOfDay::on_btnRefresh_clicked()
{
    loadData();
}

void DlgEndOfDay::loadData()
{
    ui->tblCharges->clearContents();
    ui->tblCharges->setRowCount(0);
    ui->lbSemaphore->setPixmap(QPixmap(":/images/ball-green.png"));
    DoubleDatabase fDD;
    fDD[":f_state"] = RESERVE_CHECKIN;
    fDD.exec("select r.f_invoice, r.f_vatMode, r.f_id, r.f_room, "
               "concat(g.f_title, ' ', g.f_firstName, ' ' , g.f_lastName), r.f_man + r.f_woman + r.f_child, "
               "r.f_startDate, r.f_endDate,"
               "r.f_pricePerNight, "
               " '', '', ra.f_en, r.f_cityledger "
               "from f_reservation r  "
               "inner join f_guests g on g.f_id=r.f_guest "
               "inner join f_room_arrangement ra on ra.f_id=r.f_arrangement "
               "where r.f_state=:f_state");
    ui->tblCharges->setRowCount(fDD.rowCount());
    Utils::fillTableWithData(ui->tblCharges, fDD.fDbRows);
    for (int i = 0, count = ui->tblCharges->rowCount(); i < count; i++) {
        ui->tblCharges->item(i, 9)->setData(Qt::EditRole, tr("Ready"));
    }
    int start = ui->tblCharges->rowCount();
    fDD[":f_date"] = WORKING_DATE;
    fDD[":f_state"] = RESERVE_RESERVE;
    fDD.exec("select r.f_invoice, r.f_vatMode, r.f_id,  r.f_room, concat(g.f_title, ' ', g.f_firstName, ' ' , g.f_lastName), r.f_man + r.f_woman + r.f_child, "
               "r.f_startDate, r.f_endDate,"
               "r.f_pricePerNight, "
               " '', '', '', r.f_cityledger "
               "from f_reservation r "
               "inner join f_guests g on g.f_id=r.f_guest "
               "where r.f_startDate=:f_date and r.f_state=:f_state");
    if (fDD.rowCount() > 0) {
        fCanCharge = false;
        ui->lbSemaphore->setPixmap(QPixmap(":/images/ball-red.png"));
        ui->btnOk->setEnabled(false);
    }
    Utils::fillTableWithData(ui->tblCharges, fDD.fDbRows, true);
    for (int i = start, count = ui->tblCharges->rowCount(); i < count; i++) {
        ui->tblCharges->item(i, 9)->setData(Qt::EditRole, tr("Checkin"));
        EPushButton *b = new EPushButton();
        b->setIcon(QIcon(":/images/double-right.png"));
        b->fId = ui->tblCharges->item(i, 2)->data(Qt::EditRole).toString();
        connect(b, SIGNAL(clickedWithId(QString)), this, SLOT(openReservation(QString)));
        ui->tblCharges->setCellWidget(i, 10, b);
    }
    start = ui->tblCharges->rowCount();
    fDD[":f_date"] = WORKING_DATE;
    fDD[":f_state"] = RESERVE_CHECKIN;
    fDD.exec("select r.f_invoice, r.f_vatMode, r.f_id, r.f_room, concat(g.f_title, ' ', g.f_firstName, ' ' , g.f_lastName), r.f_man + r.f_woman + r.f_child, "
               "r.f_startDate, r.f_endDate,"
               "r.f_pricePerNight, "
               " '', '', '', r.f_cityledger "
               "from f_reservation r "
               "inner join f_guests g on g.f_id=r.f_guest "
               "where r.f_endDate=:f_date and r.f_state=:f_state");
    if (fDD.rowCount() > 0) {
        fCanCharge = false;
        ui->lbSemaphore->setPixmap(QPixmap(":/images/ball-red.png"));
        ui->btnOk->setEnabled(false);
    }
    Utils::fillTableWithData(ui->tblCharges, fDD.fDbRows, true);
    for (int i = start, count = ui->tblCharges->rowCount(); i < count; i++) {
        ui->tblCharges->item(i, 9)->setData(Qt::EditRole, tr("Checkout"));
        EPushButton *b = new EPushButton();
        b->setIcon(QIcon(":/images/double-right.png"));
        b->fId = ui->tblCharges->item(i, 0)->data(Qt::EditRole).toString();
        connect(b, SIGNAL(clickedWithId(QString)), this, SLOT(openInvoice(QString)));
        ui->tblCharges->setCellWidget(i, 10, b);
    }
#ifndef QT_DEBUG
    if (WORKING_DATE.daysTo(QDate::currentDate()) <= 0) {
        ui->btnOk->setEnabled(false);
    }
#endif
}
