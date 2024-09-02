#include "vauchers.h"
#include "preferences.h"
#include "basewidget.h"
#include "dlggposorderinfo.h"
#include "dlgreceiptvaucher.h"
#include "wreservation.h"
#include "winvoice.h"
#include "waccinvoice.h"
#include "dlgclinitialbalance.h"
#include "dbmregister.h"
#include "dlgdiscount.h"
#include "paymentmode.h"
#include "dbmregister.h"
#include "dlgprintvoucherasinvoice.h"
#include "dlgpostcharge.h"

QString vaucherPaymentName(int code, const QString &cardcode, const QString &clcode)
{
    QString payment = "";
    switch (code) {
        case PAYMENT_CASH:
            payment = "CASH";
            break;
        case PAYMENT_CARD:
            if (cardcode.toInt() > 0) {
                CacheCreditCard ccc;
                if (ccc.get(cardcode)) {
                    payment = ccc.fName();
                } else {
                    payment = "UNKNOWN CARD";
                }
            }
            break;
        case PAYMENT_BANK:
            payment = "BANK";
            break;
        case PAYMENT_CL: {
            CacheCityLedger ccl;
            if (ccl.get(clcode)) {
                payment = ccl.fName();
            } else {
                payment = "UNKNOWN CL";
            }
            break;
        }
        case PAYMENT_CREDIT:
            payment = "CREDIT";
            break;
        case PAYMENT_PAYX:
            payment = "PAY X";
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
           || code == VAUCHER_ADVANCE_N;
}

bool openVaucherInvoice(const QString &vaucherId)
{
    DoubleDatabase db;
    QString inv;
    QString doc;
    db[":f_id"] = vaucherId;
    db.exec("select f_inv, f_doc from m_register where f_id=:f_id");
    if (!db.nextRow()) {
        message_error(QObject::tr("Cannot open invoice"));
        return false;
    } else {
        inv = db.getString(0);
        doc = db.getString(1);
    }
    if (inv.isEmpty() && !doc.isEmpty()) {
        db[":f_id"] = doc;
        db.exec("select f_inv, f_doc from m_register where f_id=:f_id");
        if (!db.nextRow()) {
            message_error(QObject::tr("Cannot open invoice"));
            return false;
        } else {
            inv = db.getString(0);
        }
    }
    openInvoiceWithId(inv);
    return true;
}

void openVaucher(const QString &vaucher, const QString &id)
{
    QString err;
    if (vaucher == "RM" || vaucher == "CM" || vaucher == "CH" || vaucher == "PE") {
        if (!DBMRegister::openVoucher(id, err)) {
            message_error(err);
        }
    } else if (vaucher == "PS") {
        DlgGPOSOrderInfo *d = new DlgGPOSOrderInfo(fMainWindow->fPreferences.getDefaultParentForMessage());
        d->setVaucher(id);
        d->exec();
        delete d;
    } else if (vaucher == "RV") {
        if (!DBMRegister::openVoucher(id, err)) {
            message_error(err);
        }
    } else if (vaucher == "RS") {
        WReservation::openVaucher(id);
    } else if (vaucher == "AV") {
        if (!DBMRegister::openVoucher(id, err)) {
            message_error(err);
        }
    } else if (vaucher == "CR") {
        DlgCLInitialBalance::openVaucher(id);
    } else if (vaucher == "DS") {
        DlgDiscount::openVaucher(id);
    } else if (vaucher == "TR") {
        DoubleDatabase dd;
        dd[":f_id"] = id;
        dd.exec("select f_doc from m_register where f_id=:f_id");
        if (dd.nextRow()) {
            openVaucherInvoice(dd.getString(0));
        }
    }
}

bool removeVaucher(const QString &id, const QString &reason)
{
    Preferences p;
    DoubleDatabase db;
    QString src, name, doc, wdate;
    int rec, item, fiscal;
    double amount;
    QString f_inv;
    int track = TRACK_VAUCHER;
    db[":f_id"] = id;
    db.exec("select f_source, f_doc, f_rec, f_itemCode, f_finalName, f_amountAmd, f_fiscal, f_inv, f_doc, f_wdate "
            "from m_register where f_id=:f_id");
    if (db.nextRow()) {
        src = db.getString(0);
        doc = db.getString(1);
        rec = db.getInt(2);
        item = db.getInt(3);
        name = db.getString(4);
        amount = db.getDouble(5);
        fiscal = db.getInt(6);
        f_inv = db.getString(7);
        wdate = db.getDate(9).toString(def_date_format);
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
        db.update("m_register", where_id(id));
    } else if (src == "CH") {
        if (item == 17) {
            db[":f_show"] = 0;
            db[":f_doc"] = "";
            db.update("f_reservation_meal", where_field("f_doc", id));
        }
    } else if (src == "RV" || src == "AV") {
        track = TRACK_RESERVATION;
        if (fiscal > 0) {
            if (!f_inv.isEmpty()) {
                // IN FUTURE: UPDATE PREPAID
            }
        }
    }
    db[":f_canceled"] = 1;
    db[":f_cancelUser"] = p.getLocal(def_working_user_id).toInt();
    db[":f_cancelDate"] = QDateTime::currentDateTime();
    db[":f_cancelReason"] = reason;
    db.update("m_register", where_id(ap(id)));
    if (!doc.isEmpty()) {
        db[":f_canceled"] = 1;
        db[":f_cancelUser"] = p.getLocal(def_working_user_id).toInt();
        db[":f_cancelDate"] = QDateTime::currentDateTime();
        db[":f_cancelReason"] = reason;
        db.update("m_register", where_id(ap(doc)));
    }
    TrackControl::insert(track, "VAUCHER CANCELED", QString("%1%2 %3")
                         .arg(src)
                         .arg(id)
                         .arg(name), "", id, f_inv);
    if (!doc.isEmpty()) {
        TrackControl::insert(track, "VAUCHER CANCELED", QString("%1%2 %3")
                             .arg(src)
                             .arg(doc)
                             .arg(name), "", doc, f_inv);
    }
    Q_UNUSED(rec)
    DBMRegister vr;
    vr.fSource = VOUCHER_REMOVAL_N;
    vr.fItemCode = __preferences.getDb(def_removal_vaucher_id).toInt();
    vr.fFinalName = QObject::tr("REMOVAL OF") + " " + name;
    vr.fAmountAMD = amount;
    vr.fDoc = id;
    vr.fRemarks = id + " / " + wdate + " / " + reason;
    vr.save(db);
    return true;
}

bool openInvoiceWithId(const QString &invoice)
{
    DoubleDatabase db;
    db[":f_invoice"] = invoice;
    db.exec("select f_state from f_reservation where f_invoice=:f_invoice");
    if (!db.nextRow()) {
        db[":f_id"] = invoice;
        db.exec("select f_id from m_register where f_id=:f_id");
        if (db.nextRow()) {
            DlgPrintVoucherAsInvoice::openInvoiceWindow(invoice);
            return true;
        }
        message_error(QObject::tr("Cannot open invoice"));
        return false;
    }
    int state = db.getInt(0);
    switch (state) {
        case RESERVE_CHECKIN:
            WInvoice::openInvoiceWindow(invoice);
            break;
        case RESERVE_RESERVE:
        case RESERVE_CHECKOUT:
        case RESERVE_REMOVED:
            WAccInvoice::openInvoice(invoice);
            break;
        default:
            WAccInvoice::openInvoice(invoice);
            break;
    }
    return true;
}

bool voucherKind(const QString &id, const QString &compare)
{
    DoubleDatabase db;
    db[":f_id"] = id;
    db.exec("select f_source from m_register where f_id=:f_id");
    if (db.nextRow()) {
        return db.getString(0) == compare;
    }
    return false;
}
