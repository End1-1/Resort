#include "wquickreservationscheckin.h"
#include "ui_wquickreservationscheckin.h"
#include "vauchers.h"
#include "dbmregister.h"
#include "paymentmode.h"
#include "trackcontrol.h"
#include "utils.h"
#include "cachereservation.h"
#include "cacheredreservation.h"
#include "broadcastthread.h"
#include "cacheinvoiceitem.h"
#include "cacheroom.h"
#include "cacheactiveroom.h"
#include "pprintcheckin.h"

#define col_room 1
#define col_pax 2
#define col_guest 3
#define col_entry 4
#define col_status 6
#define col_invoice2 7

WQuickReservationsCheckin::WQuickReservationsCheckin(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::WQuickReservationsCheckin)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tbl, ui->tbl->columnCount(),
                                     100, 100, 80, 300, 100, 100, 200, 0);
    ui->tbl->fitToColumns();
}

WQuickReservationsCheckin::~WQuickReservationsCheckin()
{
    delete ui;
}

void WQuickReservationsCheckin::setReservations(const QStringList &codes)
{
    QString ids;
    bool first = true;
    for (const QString &s: codes) {
        if (first) {
            first = false;
        } else {
            ids += ",";
        }
        ids += ap(s);
    }
    DoubleDatabase dd;
    dd.exec("select r.f_id, r.f_room, r.f_man+r.f_woman+r.f_child as f_pax, g.guest, r.f_startdate, r.f_enddate, '', "
            "r.f_invoice "
            "from f_reservation r "
            "left join guests g on g.f_id=r.f_guest "
            "where r.f_id in (" + ids + ")");
    Utils::fillTableWithData(ui->tbl, dd.fDbRows);
}

int WQuickReservationsCheckin::exec()
{
    connect(&fTimer, SIGNAL(timeout()), this, SLOT(timeout()));
    fTimer.start(1000);
    return BaseDialog::exec();
}

void WQuickReservationsCheckin::checkIn(int row, DoubleDatabase &dd)
{
    if (ui->tbl->toString(row, col_room).isEmpty()) {
        ui->tbl->setItemWithValue(row, col_status, tr("No room"));
        return;
    }
    if (ui->tbl->toInt(row, col_pax) < 1) {
        ui->tbl->setItemWithValue(row, col_status, tr("Guests count cannot be equal to zero"));
        return;
    }
    bool passportFound = false;
    dd[":f_reservation"] = ui->tbl->toString(row, 0);
    dd.exec("select g.f_passport "
            "from f_reservation_guests r "
            "left join f_guests g on g.f_id=r.f_guest "
            "where r.f_reservation=:f_reservation");
    while (dd.nextRow()) {
        if (dd.getString(0).isEmpty()) {
            continue;
        } else {
            passportFound = true;
            break;
        }
    }
    if (!passportFound && fPreferences.getDb(def_passport_required).toBool()) {
        ui->tbl->setItemWithValue(row, col_status, tr("No passport record found for registered guest"));
        return;
    }
    bool nationsOk = true;
    dd[":f_reservation"] = ui->tbl->toString(row, 0);
    dd.exec("select g.f_nation "
            "from f_reservation_guests r "
            "left join f_guests g on g.f_id=r.f_guest "
            "where r.f_reservation=:f_reservation");
    while (dd.nextRow()) {
        if (dd.getString(0).isEmpty() || dd.getString(0) == "-"){
            nationsOk = false;
            break;
        }
    }
    if (!nationsOk) {
        ui->tbl->setItemWithValue(row, col_status, tr("Check nations for all guests"));
        return;
    }
    if (ui->tbl->itemValue(row, col_entry, Qt::EditRole).toDate() != WORKING_DATE) {
        ui->tbl->setItemWithValue(row, col_status, tr("The entry date is not equal to working date"));
        return;
    }

    double arrivalFee = 0;
    double earlyCheckinFee = 0;
    int vatMode = VAT_INCLUDED;
    int paymentMode = PAYMENT_CASH;
    dd[":f_id"] = ui->tbl->toString(row, 0);
    dd.exec("select f_arrivalfee, f_earlycheckinfee, f_vatmode, f_paymentmode "
            "from f_reservation where f_id=:f_id");
    if (dd.nextRow()) {
        arrivalFee = dd.getDouble("f_arrivalfee");
        earlyCheckinFee = dd.getDouble("f_earlycheckinfee");
        vatMode = dd.getInt("f_vatmode");
        paymentMode = dd.getInt("f_paymentmode");
    }
    if (arrivalFee > 0.1) {
        if (fPreferences.getDb(def_airport_pickup_id).toInt() == 0) {
            ui->tbl->setItemWithValue(row, col_status, tr("Airport pickup id not defined in the config. Contact to administrator"));
            return;
        }
    }
    if (fPreferences.getDb(def_earyly_checkin_id).toInt() == 0) {
        ui->tbl->setItemWithValue(row, col_status, tr("Early checkin id is not defined. Contact to administrator"));
        return;
    }
    CacheRoom cri;
    if (cri.get(ui->tbl->toString(row, col_room))) {
        if (cri.fState() != ROOM_STATE_NONE) {
            ui->tbl->setItemWithValue(row, col_status, tr("Room is not vacant ready"));
            return;
        }
    } else {
        ui->tbl->setItemWithValue(row, col_status, tr("Unknown room"));
        return;
    }

    QString err;
    bool result = true;
    dd.startTransaction();
    TrackControl tc(TRACK_RESERVATION);
    tc.fReservation = ui->tbl->toString(row, 0);
    tc.fInvoice = ui->tbl->toString(row, col_invoice2);
    if (result) {
        dd[":f_state"] = RESERVE_CHECKIN;
        dd[":f_checkInDate"] = WORKING_DATE;
        dd[":f_checkInTime"] = QTime::currentTime();
        dd[":f_checkInUser"] = WORKING_USERID;
        result = result && dd.update("f_reservation", where_id(ap(ui->tbl->toString(row, 0))));
        if (!result) {
            err += dd.fLastError + "\r\n";
        }
    }
    if (result) {
        dd[":f_state"] = ROOM_STATE_CHECKIN;
        result = result && dd.update("f_room", where_id(ui->tbl->toInt(row, 1)));

        dd[":f_date"] = QDate::currentDate();
        dd[":f_wdate"] = WORKING_DATE;
        dd[":f_time"] = QTime::currentTime();
        dd[":f_oldState"] = ROOM_STATE_NONE;
        dd[":f_newState"] = ROOM_STATE_CHECKIN;
        dd[":f_user"] = WORKING_USERID;
        dd[":f_comment"] = "CHECKIN";
        dd[":f_reservation"] = ui->tbl->toString(row, 0);
        result = result && dd.insert("f_room_state_change", false);
        if (!result) {
            err += dd.fLastError + "\r\n";
        }
    }

    /*------------------------ BEGIN ADVANCE -------------------*/
    if (result) {
            dd[":f_source"] = VAUCHER_ADVANCE_N;
            dd[":f_inv"] = ui->tbl->toString(row, col_invoice2);
            dd.exec("select f_id, f_fiscal, f_amountAmd, f_wdate, f_paymentmode "
                       "from m_register where f_canceled=0 and f_source=:f_source "
                       "and f_inv=:f_inv ");
            while (dd.nextRow()) {
                int fiscal = dd.getInt(1);
                dd[":f_inv"] = ui->tbl->toString(row, col_invoice2);
                dd[":f_room"] = ui->tbl->toInt(row, col_room);
                result = result && dd.update("m_register", where_id(ap(dd.getString(0))));
                if (fiscal > 0) {
                    DoubleDatabase db;
                    db[":f_prepaid"] = dd.getDouble(2);
                    db[":f_id"] = ui->tbl->toString(row, col_invoice2);
                    db.exec("update m_v_invoice set f_prepaid=f_prepaid+:f_prepaid where f_id=:f_id");
                }
                DBMRegister dbmr;
                dbmr.fSource = VOUCHER_ADVANCE_TRANSFER_N;
                dbmr.fReserve = ui->tbl->toString(row, 0);
                dbmr.fInvoice = ui->tbl->toString(row, col_invoice2);
                dbmr.fRoom = ui->tbl->toInt(row, col_room);
                dbmr.fGuest = ui->tbl->toString(row, col_guest);
                dbmr.fItemCode = fPreferences.getDb(def_advance_transfer_voucher_id).toUInt();
                dbmr.fFinalName = tr("TRANSFER FROM ") + dd.getString("f_id") + ", " + dd.getDate("f_wdate").toString(def_date_format);
                dbmr.fDC = PAY_DEBIT;
                dbmr.fSign = -1;
                dbmr.fPaymentMode = dd.getInt("f_paymentMode");
                dbmr.fAmountAMD = dd.getDouble("f_amountamd");
                dbmr.fDoc = dd.getString("f_id");
                if (!dbmr.save(dd)) {
                    result = false;
                    err += dbmr.fError + "\r\n";
                }
            }
    }
    /*------------------------ END ADVANCE ----------------------*/
    /*------------------------ BEGIN EARLY CHECKIN FEE ----------------*/
    if (result) {
        if (isDoubleGreat(earlyCheckinFee, 0, 2)) {
            CacheInvoiceItem ii;
            if (ii.get(fPreferences.getDb(def_earyly_checkin_id).toString())) {
                dd[":f_id"] =  uuidx(ii.fVaucher());
                dd[":f_source"] = ii.fVaucher();
                dd[":f_res"] = ui->tbl->toString(row, 0);
                dd[":f_wdate"] = WORKING_DATE;
                dd[":f_rdate"] = QDate::currentDate();
                dd[":f_time"] = QTime::currentTime();
                dd[":f_user"] = WORKING_USERID;
                dd[":f_room"] = ui->tbl->toString(row, col_room);
                dd[":f_guest"] = ui->tbl->toString(row, col_guest);
                dd[":f_itemCode"] = fPreferences.getDb(def_earyly_checkin_id).toInt();
                dd[":f_finalName"] = ii.fName();
                dd[":f_amountAmd"] = earlyCheckinFee;
                dd[":f_amountVat"] = Utils::countVATAmount(earlyCheckinFee, vatMode);
                dd[":f_amountUsd"] = def_usd;
                dd[":f_fiscal"] = 0;
                dd[":f_paymentMode"] = PAYMENT_CREDIT;
                dd[":f_creditCard"] = 0;
                dd[":f_cityLedger"] = 0;
                dd[":f_paymentComment"] = "";
                dd[":f_dc"] = "CREDIT";
                dd[":f_sign"] = 1;
                dd[":f_doc"] = "";
                dd[":f_rec"] = 0;
                dd[":f_inv"] = ui->tbl->toString(row, col_invoice2);
                dd[":f_finance"] = 1;
                dd[":f_remarks"] = "";
                dd[":f_canceled"] = 0;
                dd[":f_cancelReason"] = "";
                dd[":f_side"] = fPreferences.getDb(def_rooming_eod_default_side).toInt();
                result = result && dd.insert("m_register");
                if (result) {
                    tc.insert("Auto early checkin fee", QString("%1 / %2 / %3")
                                 .arg(WORKING_DATE.toString(def_date_format))
                                 .arg(QTime::currentTime().toString(def_time_format))
                                 .arg(earlyCheckinFee), "");
                } else {
                    err += dd.fLastError + "\r\n";
                }
            }
        }
    }
    /*------------------------ END EARLY CHECKIN FEE ----------------*/
    /*------------------------ AIRPORT PICKUP -------------------------*/
    if (result) {
        if (arrivalFee > 0.1) {
            CacheInvoiceItem ia;
            if (ia.get(fPreferences.getDb(def_airport_pickup_id).toString())) {
                dd[":f_id"] = uuidx(ia.fVaucher());
                dd[":f_res"] = ui->tbl->toString(row, 0);
                dd[":f_source"] = ia.fVaucher();
                dd[":f_wdate"] = WORKING_DATE;
                dd[":f_rdate"] = QDate::currentDate();
                dd[":f_time"] = QTime::currentTime();
                dd[":f_user"] = WORKING_USERID;
                dd[":f_room"] = ui->tbl->toString(row, col_room);
                dd[":f_guest"] = ui->tbl->toString(row, col_guest);
                dd[":f_itemCode"] = ia.fCode();
                dd[":f_finalName"] = ia.fName();
                dd[":f_amountAmd"] = arrivalFee;
                dd[":f_amountVat"] = Utils::countVATAmount(arrivalFee, vatMode);
                dd[":f_amountUsd"] = def_usd;
                dd[":f_fiscal"] = 0;
                dd[":f_paymentMode"] = PAYMENT_CREDIT;
                dd[":f_creditCard"] = 0;
                dd[":f_cityLedger"] = 0;
                dd[":f_paymentComment"] = "";
                dd[":f_dc"] = "CREDIT";
                dd[":f_sign"] = 1;
                dd[":f_doc"] = "";
                dd[":f_rec"] = 0;
                dd[":f_inv"] = ui->tbl->toString(row, col_invoice2);
                dd[":f_finance"] = 1;
                dd[":f_remarks"] = "";
                dd[":f_canceled"] = 0;
                dd[":f_cancelReason"] = "";
                dd[":f_side"] = fPreferences.getDb(def_rooming_eod_default_side).toInt();
                result = result && dd.insert("m_register");
                if (result) {
                    tc.insert("Auto airport pickup fee", QString("%1 / %2 ")
                                 .arg(WORKING_DATE.toString(def_date_format))
                                 .arg(arrivalFee), "");
                } else {
                    err += dd.fLastError + "\r\n";
                }
            }
        }
    }
    /*------------------------ END AIRPORT PICKUP -------------------------*/
    /*----------------------- CHECKIN VOUCHER *----------------------------*/
    if (result) {
        QString checkinid = uuidx(VOUCHER_CHECKIN_N);
        dd[":f_id"] = checkinid;
        dd[":f_source"] = VOUCHER_CHECKIN_N;
        dd[":f_res"] = ui->tbl->toString(row, 0);
        dd[":f_wdate"] = WORKING_DATE;
        dd[":f_rdate"] = QDate::currentDate();
        dd[":f_time"] = QTime::currentTime();
        dd[":f_user"] = WORKING_USERID;
        dd[":f_room"] = ui->tbl->toString(row, col_room);
        dd[":f_guest"] = ui->tbl->toString(row, col_guest);
        dd[":f_itemCode"] = fPreferences.getDb(def_checkin_voucher_id).toInt();
        dd[":f_finalName"] = tr("CHECKIN #") + checkinid;
        dd[":f_amountAmd"] = 0;
        dd[":f_usedPrepaid"] = 0;
        dd[":f_amountVat"] = 0;
        dd[":f_amountUsd"] = 0;
        dd[":f_fiscal"] = 0;
        dd[":f_paymentMode"] = paymentMode;
        dd[":f_creditCard"] = 0;
        dd[":f_cityLedger"] = 0;
        dd[":f_paymentComment"] = "";
        dd[":f_dc"] = "CREDIT";
        dd[":f_sign"] = 0;
        dd[":f_doc"] = "";
        dd[":f_rec"] = "";
        dd[":f_inv"] = ui->tbl->toString(row, col_invoice2);
        dd[":f_finance"] = 0;
        dd[":f_remarks"] = "";
        dd[":f_canceled"] = 0;
        dd[":f_cancelReason"] = "";
        dd[":f_cancelDate"] = 0;
        dd[":f_cancelUser"] = 0;
        dd[":f_side"] = 0;
        result = result && dd.insert("m_register", false);
        if (!result) {
            err += dd.fLastError + "\r\n";
        }
    }
    /*----------------------- END OF CHECKIN VOUCHER ----------------------------*/

    if (result) {
        dd.commit();
        BroadcastThread::cmdRefreshCache(cid_red_reservation, ui->tbl->toString(row, 0));
        BroadcastThread::cmdRefreshCache(cid_reservation, ui->tbl->toString(row, 0));
        BroadcastThread::cmdRefreshCache(cid_room, ui->tbl->toString(row, col_room));
        BroadcastThread::cmdRefreshCache(cid_active_room, ui->tbl->toString(row, col_room));
        PPrintCheckin::print(ui->tbl->toString(row, 0), true);
        ui->tbl->setItemWithValue(row, col_status, tr("OK"));
    } else {
        ui->tbl->setItemWithValue(row, col_status, err);
        dd.rollback();
    }
}

void WQuickReservationsCheckin::timeout()
{
    fTimer.stop();
    DoubleDatabase dd;
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        ui->tbl->setCurrentCell(i, 0);
        checkIn(i, dd);
        qApp->processEvents();
    }
}
