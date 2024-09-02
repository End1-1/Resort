#include "wquickcheckoutprocess.h"
#include "ui_wquickcheckoutprocess.h"
#include "trackcontrol.h"
#include "vauchers.h"
#include "dbmregister.h"
#include "pprintinvoice.h"
#include "dlginvoicepaymentoptions.h"
#include "paymentmode.h"
#include "cachereservation.h"
#include "cacheroom.h"
#include "cacheactiveroom.h"
#include "cacheredreservation.h"

WQuickCheckoutProcess::WQuickCheckoutProcess(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::WQuickCheckoutProcess)
{
    ui->setupUi(this);
    connect(&fTimer, SIGNAL(timeout()), this, SLOT(timeout()));
    Utils::tableSetColumnWidths(ui->tbl, ui->tbl->columnCount(), 50, 100, 100, 300, 100, 200, 120);
}

WQuickCheckoutProcess::~WQuickCheckoutProcess()
{
    delete ui;
}

void WQuickCheckoutProcess::setListOfInvoices(const QStringList &invoices)
{
    QString inv;
    for (const QString &s: invoices) {
        if (inv.length() > 0) {
            inv += ",";
        }
        inv += QString("'%1'").arg(s);
    }
    QString query = QString("select r.f_room, r.f_invoice, r.f_id, g.guest, sum(m.f_amountamd*m.f_sign), '', r.f_enddate "
                            "from m_register m "
                            "left join f_reservation r on r.f_invoice=m.f_inv "
                            "left join guests g on g.f_id=r.f_guest "
                            "where m.f_finance=1 and m.f_canceled=0 and r.f_invoice in (%1) "
                            "group by 1, 2, 3 "
                            "order by 1").arg(inv);
    DoubleDatabase dd;
    dd.exec(query);
    Utils::fillTableWithData(ui->tbl, dd.fDbRows);
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        if (ui->tbl->toDouble(i, 4) > -0.01 && ui->tbl->toDouble(i, 4) < 0.01) {
            ui->tbl->setValue(i, 5, "READY");
        } else {
            ui->tbl->setValue(i, 5, "CHECK BALANCE");
        }
    }
}

int WQuickCheckoutProcess::exec()
{
    fTimer.start(1500);
    return BaseDialog::exec();
}

void WQuickCheckoutProcess::timeout()
{
    DoubleDatabase dd;
    TrackControl tc(TRACK_RESERVATION);
    fTimer.stop();
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        ui->tbl->setCurrentCell(i, 0);
        if (ui->tbl->toString(i, 5) != "READY") {
            continue;
        }
        dd.startTransaction();
        tc.fInvoice = ui->tbl->toString(i, 1);
        tc.fReservation = ui->tbl->toString(i, 2);
        bool result = true;
        dd[":f_state"] = RESERVE_CHECKOUT;
        dd[":f_checkOutTime"] = QTime::currentTime();
        dd[":f_checkOutUser"] = WORKING_USERID;
        dd[":f_enddate"] = WORKING_DATE;
        if (ui->tbl->toDate(i, 6) > WORKING_DATE) {
            tc.insert("Departure date changed", ui->tbl->toDate(i, 6).toString(def_date_format), WORKING_DATE.toString(def_date_format));
        }
        result = result && dd.update("f_reservation", where_id(ap(ui->tbl->toString(i, 2))));
        if (!result) {
            tc.insert("Checkout error", dd.fLastError, "");
        } else {
            tc.insert("Checkout", "", "");
        }
        if (result) {
            //ROOM
            dd[":f_state"] = ROOM_STATE_DIRTY;
            result = result && dd.update("f_room", where_id(ui->tbl->toInt(i, 0)));
            dd[":f_date"] = QDate::currentDate();
            dd[":f_wdate"] = WORKING_DATE;
            dd[":f_time"] = QTime::currentTime();
            dd[":f_oldState"] = ROOM_STATE_CHECKIN;
            dd[":f_newState"] = ROOM_STATE_DIRTY;
            dd[":f_user"] = WORKING_USERID;
            dd[":f_comment"] = "CHECKOUT";
            dd[":f_reservation"] = ui->tbl->toString(i, 2);
            result = result && dd.insert("f_room_state_change", false);
            if (!result) {
                tc.insert("Checkout error", dd.fLastError, "");
            }
        }
        if (result) {
            DBMRegister mr;
            mr.fSource = VAUCHER_CHECKOUT_N;
            mr.fInvoice = ui->tbl->toString(i, 1);
            mr.fReserve = ui->tbl->toString(i, 2);
            mr.fRoom = ui->tbl->toInt(i, 0);
            mr.fGuest = ui->tbl->toString(i, 3);
            mr.fItemCode = fPreferences.getDb(def_checkout_voucher_id).toInt();
            mr.fFinalName = QString("CHECKOUT %1, %2").arg(ui->tbl->toInt(i, 0)).arg(ui->tbl->toString(i, 3));
            mr.fAmountUSD = def_usd;
            mr.fSign = 1;
            mr.fDC = PAY_CREDIT;
            result = result && mr.save(dd);
            if (!result) {
                tc.insert("Checkout error", mr.fError, "");
            }
        }
        if (result) {
            dd[":f_inv"] = ui->tbl->toString(i, 1);
            dd[":f_source"] = VAUCHER_RECEIPT_N;
            dd.exec("select f_id, sum(f_amountAmd) "
                    "from m_register "
                    "where f_paymentmode=4 and f_inv=:f_inv and f_source=:f_source and f_canceled=0 "
                    "group by 1");
            QMap<QString, double> clOut;
            while (dd.nextRow()) {
                clOut[dd.getString(0)] = dd.getDouble(1);
            }
            for (QMap<QString, double>::const_iterator it = clOut.begin(); it != clOut.end(); it++) {
                dd[":f_id"] = it.key();
                dd.exec("select * from m_register where f_id=:f_id");
                if (dd.nextRow()) {
                    DBMRegister mr;
                    mr.fSource = VAUCHER_CHECKOUT_N;
                    mr.fInvoice = ui->tbl->toString(i, 1);
                    mr.fReserve = ui->tbl->toString(i, 2);
                    mr.fRoom = ui->tbl->toInt(i, 0);
                    mr.fGuest = ui->tbl->toString(i, 3);
                    mr.fItemCode = fPreferences.getDb(def_checkout_voucher_id).toInt();
                    mr.fFinalName = QString("CHECKOUT %1, %2").arg(ui->tbl->toInt(i, 0)).arg(ui->tbl->toString(i, 3));
                    mr.fAmountAMD = it.value() * -1;
                    mr.fAmountUSD = def_usd;
                    mr.fDC = PAY_CREDIT;
                    mr.fSign = 1;
                    mr.fCityLedger = dd.getUInt("f_cityledger");
                    CacheCityLedger cc;
                    if (cc.get(mr.fCityLedger)) {
                        mr.fPaymentComment = cc.fName();
                        mr.fFinalName = QString("CHECKOUT %1").arg(cc.fName());
                    } else {
                        mr.fPaymentComment = QString("UNKNOWN C/L %1").arg(mr.fCityLedger);
                    }
                    result = result && mr.save(dd);
                    if (!result) {
                        tc.insert("Checkout error", mr.fError, "");
                    }
                }
            }
        }
        if (result) {
            dd[":f_inv"] = ui->tbl->toString(i, 1);
            dd.exec("select sum(f_amountAmd) from m_register where f_inv=:f_inv and f_finance=1 and f_canceled=0 and f_sign=1");
            dd.nextRow();
            QVariant finalAmount = dd.getDouble(0);
            dd[":f_grandTotal"] = finalAmount;
            result = result && dd.update("f_reservation", where_id(ap(ui->tbl->toString(i, 2))));
            if (!result) {
                tc.insert("Checkout error", dd.fLastError, "");
            }
            dd[":f_amountAmd"] = finalAmount;
            result = result && dd.update("m_register", where_id(ap(ui->tbl->toString(i, 2))));
            if (!result) {
                tc.insert("Checkout error", dd.fLastError, "");
            }
        }
        if (result) {
            dd[":f_id"] = ui->tbl->toString(i, 2);
            dd.exec("delete from f_reservation_chart where f_id=:f_id");
            dd[":f_reservation"] = ui->tbl->toString(i, 2);
            dd.exec("delete from f_reservation_map where f_reservation=:f_reservation");            
            CacheReservation r;
            if (r.get(ui->tbl->toString(i, 2))) {
                CacheReservation n;
                if (r.hasNext(n)) {
                    BroadcastThread::cmdRefreshCache(cid_reservation, n.fId());
                    BroadcastThread::cmdRefreshCache(cid_red_reservation, n.fId());
                }
            }
            BroadcastThread::cmdRefreshCache(cid_reservation, ui->tbl->toString(i, 2));
            BroadcastThread::cmdRefreshCache(cid_room, ui->tbl->toString(i, 0));
            BroadcastThread::cmdRefreshCache(cid_active_room, ui->tbl->toString(i, 0));
        }
        if (!result) {
            dd.rollback();
            ui->tbl->setValue(i, 5, "FAILED");
        } else {
            dd.commit();
            dd[":f_inv"] = ui->tbl->toString(i, 1);
            dd.exec("select * from m_register where f_finance=1 and f_canceled=0 and f_inv=:f_inv");
            if (dd.nextRow()) {
                PPrintInvoice(ui->tbl->toString(i, 1), -1, QStringList(), DlgInvoicePaymentOptions::printInvoiceImmediately(), "USD", def_usd,  true,  this);
            }
            ui->tbl->setValue(i, 5, "OK");
        }
        qApp->processEvents();
    }
}
