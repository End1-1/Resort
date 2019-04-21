#include "dbmregister.h"
#include "doubledatabase.h"
#include "baseuid.h"
#include "preferences.h"
#include "utils.h"
#include "eqlineedit.h"
#include "edateedit.h"
#include "trackcontrol.h"
#include <QPlainTextEdit>

DBMRegister::DBMRegister()
{
    init();
}

DBMRegister::DBMRegister(const DBMRegister &r) :
    fSource(r.fSource),
    fReserve(r.fReserve),
    fInvoice(r.fInvoice),
    fWDate(r.fWDate),
    fRDate(r.fRDate),
    fTime(r.fTime),
    fUser(r.fUser),
    fRoom(r.fRoom),
    fGuest(r.fGuest),
    fItemCode(r.fItemCode),
    fFinalName(r.fFinalName),
    fUsedPrepaid(r.fUsedPrepaid),
    fAmountAMD(r.fAmountAMD),
    fAmountVAT(r.fAmountVAT),
    fAmountUSD(r.fAmountUSD),
    fFiscal(r.fFiscal),
    fPaymentMode(r.fPaymentMode),
    fCreditCard(r.fCreditCard),
    fCityLedger(r.fCityLedger),
    fPaymentComment(r.fPaymentComment),
    fDC(r.fDC),
    fSign(r.fSign),
    fDoc(r.fDoc),
    fRec(r.fRec),
    fSide(r.fSide),
    fFinance(r.fFinance),
    fRemarks(r.fRemarks),
    fCanceled(r.fCanceled),
    fCancelUser(r.fCancelUser),
    fCancelReason(r.fCancelReason),
    fCancelDate(r.fCancelDate)
{
    init();
    setle(r);
}

DBMRegister &DBMRegister::operator=(const DBMRegister &r)
{
    fSource = r.fSource;
    fReserve = r.fReserve;
    fInvoice = r.fInvoice;
    fWDate = r.fWDate;
    fRDate = r.fRDate;
    fTime = r.fTime;
    fUser = r.fUser;
    fRoom = r.fRoom;
    fGuest = r.fGuest;
    fItemCode = r.fItemCode;
    fFinalName = r.fFinalName;
    fUsedPrepaid = r.fUsedPrepaid;
    fAmountAMD = r.fAmountAMD;
    fAmountVAT = r.fAmountVAT;
    fAmountUSD = r.fAmountUSD;
    fFiscal = r.fFiscal;
    fPaymentMode = r.fPaymentMode;
    fCreditCard = r.fCreditCard;
    fCityLedger = r.fCityLedger;
    fPaymentComment = r.fPaymentComment;
    fDC = r.fDC;
    fSign = r.fSign;
    fDoc = r.fDoc;
    fRec = r.fRec;
    fSide = r.fSide;
    fFinance = r.fFinance;
    fRemarks = r.fRemarks;
    fCanceled = r.fCanceled;
    fCancelUser = r.fCancelUser;
    fCancelReason = r.fCancelReason;
    fCancelDate = r.fCancelDate;
    setle(r);
    return *this;
}

DBMRegister::~DBMRegister()
{
    delete fTc;
}

bool DBMRegister::save(DoubleDatabase &dd)
{
    bool isNew = true;
    dd[":f_source"] = fSource;
    dd[":f_res"] = fReserve;
    dd[":f_inv"] = fInvoice;
    dd[":f_wdate"] = fWDate;
    dd[":f_rdate"] = fRDate;
    dd[":f_time"] = fTime;
    dd[":f_user"] = fUser;
    dd[":f_room"] = fRoom;
    dd[":f_guest"] = fGuest;
    dd[":f_itemCode"] = fItemCode;
    dd[":f_finalName"] = fFinalName;
    dd[":f_amountAMD"] = fAmountAMD;
    dd[":f_usedPrepaid"] = fUsedPrepaid;
    dd[":f_amountUSD"] = fAmountUSD;
    dd[":f_amountVAT"] = fAmountVAT;
    dd[":f_fiscal"] = fFiscal;
    dd[":f_paymentMode"] = fPaymentMode;
    dd[":f_creditCard"] = fCreditCard;
    dd[":f_cityLedger"] = fCityLedger;
    dd[":f_paymentComment"] = fPaymentComment;
    dd[":f_dc"] = fDC;
    dd[":f_sign"] = fSign;
    dd[":f_doc"] = fDoc;
    dd[":f_rec"] = fRec;
    dd[":f_finance"] = fFinance;
    dd[":f_canceled"] = fCanceled;
    dd[":f_cancelUser"] = fCancelUser;
    dd[":f_cancelReason"] = fCancelReason;
    dd[":f_cancelDate"] = fCancelDate;
    dd[":f_side"] = fSide;
    if (fId.isEmpty()) {
        fId = uuidx(fSource);
        if (fId.isEmpty()) {
            fError = tr("Could not get new id for ") + fSource;
            return false;
        }
        if (leID) {
            leID->setText(fId);
        }
        dd[":f_id"] = fId;
        if (!dd.insert("m_register", false)) {
            fError = dd.fLastError;
            return false;
        }
    } else {
        isNew = false;
        if (!dd.update("m_register", where_id(ap(fId)))) {
            fError = dd.fLastError;
            return false;
        }
    }
    fTc->fInvoice = fInvoice;
    fTc->fReservation = fReserve;
    fTc->fRecord = fId;
    fTc->insert((isNew ? "NEW " : "EDIT ") + QString("VOUCHER"), fFinalName, "");
    fTc->resetChanges();
    return true;
}

void DBMRegister::setleID(EQLineEdit *l)
{
    leID = l;
}

void DBMRegister::setleInvoice(EQLineEdit *l)
{
    leInvoice = l;
    connect(l, SIGNAL(textChanged(QString)), this, SLOT(invoiceChanged(QString)));
    fTc->addWidget(l, "Invoice");
}

void DBMRegister::setleReserve(EQLineEdit *l)
{
    leReserve = l;
    connect(l, SIGNAL(textChanged(QString)), this, SLOT(reserveChanged(QString)));
    fTc->addWidget(l, "Reserve");
}

void DBMRegister::setleWDate(EDateEdit *d)
{
    deWDate = d;
    connect(d, SIGNAL(textChanged(QString)), this, SLOT(wdateChanged(QString)));
    fTc->addWidget(d, "Working date");
}

void DBMRegister::setleGuest(EQLineEdit *l)
{
    leGuest = l;
    connect(l, SIGNAL(textChanged(QString)), this, SLOT(guestChanged(QString)));
    fTc->addWidget(l, "Guest");
}

void DBMRegister::setleRoom(EQLineEdit *l)
{
    leRoom = l;
    connect(l, SIGNAL(textChanged(QString)), this, SLOT(roomChanged(QString)));
    fTc->addWidget(l, "Room");
}

void DBMRegister::setleCityLedger(EQLineEdit *l1, EQLineEdit *l2)
{
    leCityLedgerCode = l1;
    leCityLedgerName = l2;
    connect(l1, SIGNAL(textChanged(QString)), this, SLOT(cityLedgerChanged(QString)));
    connect(l2, SIGNAL(textChanged(QString)), this, SLOT(cityLedgerNameChanged(QString)));
    fTc->addWidget(l1, "C/L Code");
    fTc->addWidget(l2, "C/L Name");
}

void DBMRegister::setleAmountAMD(EQLineEdit *l)
{
    leAmountAMD = l;
    connect(l, SIGNAL(textChanged(QString)), this, SLOT(amountAMDChagned(QString)));
    fTc->addWidget(l, "Amount AMD");
}

void DBMRegister::setleAmountUSD(EQLineEdit *l)
{
    leAmountUSD = l;
    connect(l, SIGNAL(textChanged(QString)), this, SLOT(amountUSDChagned(QString)));
    fTc->addWidget(l, "Amount USD");
}

void DBMRegister::setleAmountVAT(EQLineEdit *l)
{
    leAmountVAT = l;
    connect(l, SIGNAL(textChanged(QString)), this, SLOT(amountVATChagned(QString)));
    fTc->addWidget(l, "Amount VAT");
}

void DBMRegister::setleRemarks(QPlainTextEdit *p)
{
    ptRemarks = p;
    connect(p, SIGNAL(textChanged(QString)), this, SLOT(remarksChanged(QString)));
    fTc->addWidget(p, "Remarks");
}

void DBMRegister::init()
{
    fWDate = Preferences().getLocalDate(def_working_day);
    fRDate = QDate::currentDate();
    fTime = QTime::currentTime();
    fUser = Preferences().getLocal(def_working_user_id).toUInt();
    fRoom = 0;
    fItemCode = 0;
    fUsedPrepaid = 0;
    fAmountAMD = 0;
    fAmountUSD = 0;
    fAmountVAT = 0;
    fFiscal = 0;
    fPaymentMode = 0;
    fCreditCard = 0;
    fCityLedger = 0;
    fSign = 0;
    fSide = 0;
    fFinance = 0;
    fCanceled = 0;
    fCancelUser = 0;

    leID = nullptr;
    deWDate = nullptr;
    leInvoice = nullptr;
    leReserve = nullptr;
    leGuest = nullptr;
    leRoom = nullptr;
    leCityLedgerCode = nullptr;
    leCityLedgerName = nullptr;
    leAmountAMD = nullptr;
    leAmountUSD = nullptr;
    leAmountVAT = nullptr;
    ptRemarks = nullptr;

    fTc = new TrackControl(TRACK_VAUCHER);
}

void DBMRegister::setle(const DBMRegister &r)
{
    if (r.leID) {
        setleID(r.leID);
    }
    if (r.deWDate) {
        setleWDate(r.deWDate);
    }
    if (r.leInvoice) {
        setleInvoice(r.leInvoice);
    }
    if (r.leReserve) {
        setleReserve(r.leReserve);
    }
    if (r.leGuest) {
        setleGuest(r.leGuest);
    }
    if (r.leCityLedgerCode) {
        setleCityLedger(r.leCityLedgerCode, r.leCityLedgerName);
    }
    if (r.leAmountAMD) {
        setleAmountAMD(r.leAmountAMD);
    }
    if (r.leAmountUSD) {
        setleAmountUSD(r.leAmountUSD);
    }
    if (r.leAmountVAT) {
        setleAmountVAT(r.leAmountVAT);
    }
    if (r.ptRemarks) {
        setleRemarks(r.ptRemarks);
    }
}

void DBMRegister::wdateChanged(const QString &s)
{
    Q_UNUSED(s);
    EDateEdit *d = static_cast<EDateEdit*>(sender());
    fWDate = d->date();
}

void DBMRegister::invoiceChanged(const QString &s)
{
    fInvoice = s;
}

void DBMRegister::reserveChanged(const QString &s)
{
    fReserve = s;
}

void DBMRegister::guestChanged(const QString &s)
{
    fGuest = s;
}

void DBMRegister::roomChanged(const QString &s)
{
    fRoom = s.toUInt();
}

void DBMRegister::cityLedgerChanged(const QString &s)
{
    fCityLedger = s.toUInt();
}

void DBMRegister::cityLedgerNameChanged(const QString &s)
{
    fCityLedgerName = s;
}

void DBMRegister::amountAMDChagned(const QString &s)
{
    fAmountAMD = s.toDouble();
}

void DBMRegister::amountUSDChanged(const QString &s)
{
    fAmountUSD = s.toDouble();
}

void DBMRegister::amountVATChanged(const QString &s)
{
    fAmountVAT = s.toDouble();
}

void DBMRegister::remarksChanged(const QString &s)
{
    fRemarks = s;
}
