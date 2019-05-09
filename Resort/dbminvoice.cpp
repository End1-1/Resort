#include "dbminvoice.h"
#include "eqlineedit.h"
#include "edateedit.h"
#include "trackcontrol.h"
#include "vauchers.h"
#include "baseuid.h"

DBMInvoice::DBMInvoice()
{
    init();
}

DBMInvoice::~DBMInvoice()
{
    delete fTc;
    fVouchers.clear();
}

bool DBMInvoice::open(DoubleDatabase &d, const QString &id)
{
    d[":f_id"] = id;
    d.exec("select i.f_reserve, i.f_date, i.f_debit, i.f_credit, i.f_cityledger, cl.f_name as f_cityledgername "
           "from m_invoice i "
           "left join f_city_ledger cl on cl.f_id=i.f_cityledger "
           "where i.f_id=:f_id");
    if (d.nextRow()) {
        fInvoice = id;
        fReserve = d.getString("f_reserve");
        fDate = d.getDate("f_date");
        fDebit = d.getDouble("f_debit");
        fCredit = d.getDouble("f_credit");
        fCityLedger = d.getInt("f_cityledger");
        fCityLedgerName = d.getString("f_cityledgername");

        if (leInvoice) {
            leInvoice->setText(fInvoice);
        }
        if (deDate) {
            deDate->setDate(fDate);
        }
        if (leDebit) {
            leDebit->setDouble(fDebit);
        }
        if (leCredit) {
            leCredit->setDouble(fCredit);
        }
        if (leCityLedger) {
            leCityLedger->setInt(fCityLedger);
        }
        if (leCityLedgerName) {
            leCityLedgerName->setText(fCityLedgerName);
        }
        d[":f_inv"] = id;
        d.exec(DBMRegister::voucherQuery() + " where m.f_inv=:f_inv");
        while (d.nextRow()) {
            DBMRegister r;
            r.fetchData(d);
            fVouchers.append(r);
        }
        return true;
    }
    fError = tr("Invalid invoice number");
    return false;
}

bool DBMInvoice::save(DoubleDatabase &d)
{
    fError = "";
    d[":f_reserve"] = fReserve;
    d[":f_date"] = fDate;
    d[":f_cityledger"] = fCityLedger;
    d[":f_debit"] = fDebit;
    d[":f_credit"] = fCredit;
    if (fInvoice.isEmpty()) {
        fInvoice = uuidx(VAUCHER_INVOICE_N);
        d[":f_id"] = fInvoice;
        if (!d.insert("m_invoice", false)) {
            fError += d.fLastError + "<br>";
            return false;
        }
    } else {
        if (!d.update("m_invoice", where_id(ap(fInvoice)))) {
            fError += d.fLastError + "<br>";
            return false;
        }
    }
    for (int i = 0; i < fVouchers.count(); i++) {
        DBMRegister &r = fVouchers[i];
        r.fInvoice = fInvoice;
        if (!r.save(d)) {
            fError += r.fError + "<br>";
        }
    }
    if(fError.isEmpty()) {
        fTc->resetChanges();
        return true;
    }
    return false;
}

bool DBMInvoice::addVoucher(const DBMRegister &r)
{
    foreach (DBMRegister v, fVouchers) {
        if (v.fId == r.fId) {
            return false;
        }
    }
    fVouchers.append(r);
    return true;
}

int DBMInvoice::vouchersCount()
{
    return fVouchers.count();
}

DBMRegister &DBMInvoice::voucher(int index)
{
    return fVouchers[index];
}

void DBMInvoice::setleInvoice(EQLineEdit *l)
{
    leInvoice = l;
}

void DBMInvoice::setleDate(EDateEdit *d)
{
    deDate = d;
    fDate = d->date();
    connect(d, SIGNAL(textChanged(QString)), this, SLOT(idateChanged(QString)));
    fTc->addWidget(d, "Date");
}

void DBMInvoice::setleCityLedger(EQLineEdit *l1, EQLineEdit *l2)
{
    leCityLedger = l1;
    leCityLedgerName = l2;
    connect(l1, SIGNAL(textChanged(QString)), this, SLOT(cityLedgerChanged(QString)));
    connect(l2, SIGNAL(textChanged(QString)), this, SLOT(cityLedgerNameChanged(QString)));
    fTc->addWidget(l2, "CityLedger");
}

void DBMInvoice::setleDebit(EQLineEdit *l)
{
    leDebit = l;
    fTc->addWidget(l, "Debit");
}

void DBMInvoice::setleCredit(EQLineEdit *l)
{
    leCredit = l;
    fTc->addWidget(l, "Credit");
}

void DBMInvoice::setleBalance(EQLineEdit *l)
{
    leBalance = l;
    fTc->addWidget(l, "Balance");
}

void DBMInvoice::init()
{
    fCityLedger = 0;
    fDebit = 0;
    fCredit = 0;

    leInvoice = nullptr;
    deDate = nullptr;
    leCityLedger = nullptr;
    leCityLedgerName = nullptr;
    leDebit = nullptr;
    leCredit = nullptr;
    leBalance = nullptr;

    fTc = new TrackControl(TRACK_INVOICE_ITEM);
}

void DBMInvoice::setBalance()
{
    if (leDebit) {
        leDebit->setDouble(fDebit);
    }
    if (leCredit) {
        leCredit->setDouble(fCredit);
    }
    if (leBalance) {
        leBalance->setDouble((fDebit*-1) + fCredit);
    }
}

void DBMInvoice::countAmounts()
{
    fDebit = 0;
    fCredit = 0;
    foreach (DBMRegister r, fVouchers) {
        if (r.fFinance == 0 || r.fCanceled == 1) {
            continue;
        }
        switch(r.fSign) {
        case -1:
            fDebit += r.fAmountAMD;
            break;
        case 1:
            fCredit += r.fAmountAMD;
            break;
        }
    }
    setBalance();
}

void DBMInvoice::cityLedgerChanged(const QString &s)
{
    fCityLedger = s.toInt();
}

void DBMInvoice::cityLedgerNameChanged(const QString &s)
{
    fCityLedgerName = s;
}

void DBMInvoice::idateChanged(const QString &s)
{
    Q_UNUSED(s);
    EDateEdit *d = static_cast<EDateEdit*>(sender());
    fDate = d->date();
}
