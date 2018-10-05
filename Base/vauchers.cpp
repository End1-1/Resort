#include "vauchers.h"
#include "preferences.h"
#include "dlgpostingcharges.h"
#include "basewidget.h"
#include "dlggposorderinfo.h"
#include "dlgreceiptvaucher.h"
#include "wreservation.h"
#include "winvoice.h"
#include "waccinvoice.h"
#include "dlgadvance.h"
#include "dlgclinitialbalance.h"
#include "dlgdiscount.h"
#include "dlgcityadvance.h"
#include "paymentmode.h"

QString vaucherPaymentName(int code, const QString &cardcode, const QString &clcode) {
    QString payment = "";
    switch (code) {
    case PAYMENT_CASH:
        payment = "CASH";
        break;
    case PAYMENT_CARD:
        if (cardcode.toInt() > 0) {
            CacheCreditCard ccc;
            ccc.get(cardcode);
            payment = ccc.fName();
        }
        break;
    case PAYMENT_BANK:
        payment = "BANK";
        break;
    case PAYMENT_CL: {
        CacheCityLedger ccl;
        ccl.get(clcode);
        payment = ccl.fName();
        break;
    }
    case PAYMENT_CREDIT:
        payment = "CREDIT";
        break;
    default:
        payment = "UNKNOWN";
        break;
    }
    return payment;
}

QString vaucherCode(int code, const QString &prefix)
{
    Preferences p;
    return QString("%1%2").arg(prefix).arg(code, p.getDb(def_vouchers_digits).toInt(), 10, QChar('0'));
}

bool isTaxPay(const QString &code)
{
    return code == VAUCHER_ROOMING_N
            || code == VAUCHER_POSTCHARGE_N
            || code == VAUCHER_POINT_SALE_N
            || code == "CM"
            || code == "PE";
}

bool isTaxPrepay(const QString &code)
{
    return code == VAUCHER_RECEIPT_N
            || VAUCHER_ADVANCE_N;
}

bool openVaucherInvoice(const QString &vaucherId) {
    DoubleDatabase db(true, false);
    db[":f_id"] = vaucherId;
    db.exec("select f_inv from m_register where f_id=:f_id");
    if (!db.nextRow()) {
        message_error(QObject::tr("Cannot open invoice"));
        return false;
    }
    openInvoiceWithId(db.getString(0));
    return true;
}

void openVaucher(const QString &vaucher, const QString &id)
{
    if (vaucher == "RM" || vaucher == "CM" || vaucher == "CH" || vaucher == "PE") {
        DlgPostingCharges *d = new DlgPostingCharges(fMainWindow->fPreferences.getDefaultParentForMessage());
        d->loadVaucher(id);
        d->exec();
        delete d;
    } else if (vaucher == "PS") {
        DlgGPOSOrderInfo *d = new DlgGPOSOrderInfo(fMainWindow->fPreferences.getDefaultParentForMessage());
        d->setVaucher(id);
        d->exec();
        delete d;
    } else if (vaucher == "RV") {
        DlgReceiptVaucher *d = new DlgReceiptVaucher(fMainWindow->fPreferences.getDefaultParentForMessage());
        d->setVaucher(id);
        d->exec();
        delete d;
    } else if (vaucher == "RS") {
        WReservation::openVaucher(id);
    } else if (vaucher == "AV") {
        DlgAdvance::openAdvance(id);
    } else if (vaucher == "CR") {
        DlgCLInitialBalance::openVaucher(id);
    } else if (vaucher == "DS") {
        DlgDiscount::openVaucher(id);
    } else if (vaucher == "TC") {
        DlgCityAdvance::cityAdvance(id, "", 0);
    }
}

bool removeVaucher(const QString &id, const QString &reason)
{
    Preferences p;
    DoubleDatabase db(true, true);
    QString src, name;
    int doc, rec, item, fiscal;
    QString f_inv;
    int track = TRACK_VAUCHER;
    db[":f_id"] = id;
    db.exec("select f_source, f_doc, f_rec, f_itemCode, f_finalName, f_amountAmd, f_fiscal, f_inv, f_doc "
              "from m_register where f_id=:f_id");
    if (db.nextRow()) {
        src = db.getString(0);
        doc = db.getInt(1);
        rec = db.getInt(2);
        item = db.getInt(3);
        name = db.getString(4);
        //amount = r.at(0).at(5).toDouble();
        fiscal = db.getInt(6);
        f_inv = db.getString(7);
    } else {
        return false;
    }
    if (src == "PS") {
        db[":f_state"] = ORDER_STATE_REMOVED;
        db.update("o_header", where_id(ap(id)));
        db[":f_state"] = DISH_STATE_REMOVED_NOSTORE;
        db[":f_state1"] = DISH_STATE_READY;
        db[":f_header"] = id;
        db.exec("update o_dish set f_state=:f_state where f_header=:f_header and f_state=:f_state1 ");
    } else if (src == "PE") {
        db[":f_canceled"] = 1;
        db[":f_cancelUser"] = fMainWindow->fPreferences.getDb(def_working_user_id).toInt();
        db[":f_cancelDate"] = QDateTime::currentDateTime();
        db[":f_cancelReason"] = reason;
        db.update("m_register", where_id(doc));
    } else if (src == "CH") {
        if (item == 17) {
            db[":f_show"] = 0;
            db[":f_doc"] = 0;
            db.update("f_reservation_meal", where_field("f_doc", doc));
        }
    } else if (src == "RV" || src == "AV") {
        track = TRACK_RESERVATION;
        if (fiscal > 0) {
            if (!f_inv.isEmpty()) {
                // IN FUTURE: UPDATE PREPAID
            }
        }
    } else if (src == "TR") {
        DoubleDatabase dr(true, true);
        dr[":f_canceled"] = 1;
        dr[":f_cancelUser"] = p.getLocal(def_working_user_id).toInt();
        dr[":f_cancelDate"] = QDateTime::currentDateTime();
        dr[":f_cancelReason"] = reason;
        dr.update("m_register", where_id(ap(db.getValue("f_doc").toString())));
    }

    db[":f_canceled"] = 1;
    db[":f_cancelUser"] = p.getLocal(def_working_user_id).toInt();
    db[":f_cancelDate"] = QDateTime::currentDateTime();
    db[":f_cancelReason"] = reason;
    db.update("m_register", where_id(ap(id)));

    TrackControl::insert(track, "VAUCHER CANCELED", QString("%1%2 %3")
                  .arg(src)
                  .arg(doc)
                  .arg(name), "", id, f_inv);
    Q_UNUSED(rec)
    return true;
}

bool openInvoiceWithId(const QString &invoice)
{
    DoubleDatabase db(true, false);
    db[":f_invoice"] = invoice;
    db.exec("select f_state from f_reservation where f_invoice=:f_invoice");
    if (!db.nextRow()) {
        message_error(QObject::tr("Cannot open invoice"));
        return false;
    }
    int state = db.getInt(0);
    switch (state) {
    case RESERVE_CHECKIN:
        WInvoice::openInvoiceWindow(invoice);
        break;
    case RESERVE_CHECKOUT:
    case RESERVE_REMOVED: {
        WAccInvoice *ai = addTab<WAccInvoice>();
        ai->load(invoice);
        break;
    }
    }
    return true;
}