#include "dbmregister.h"
#include <QPlainTextEdit>
#include "baseuid.h"
#include "basewidget.h"
#include "dlgadvanceentry.h"
#include "dlgpostcharge.h"
#include "dlgreceiptvaucher.h"
#include "dlgtracking.h"
#include "doubledatabase.h"
#include "edateedit.h"
#include "eqlineedit.h"
#include "mainwindow.h"
#include "preferences.h"
#include "trackcontrol.h"
#include "vauchers.h"

static const QString voucher_query =
    "select m.f_id, m.f_source, m.f_res, m.f_inv, m.f_wdate, m.f_rdate, m.f_time, m.f_user, u.f_username, "
    "m.f_room, m.f_guest, m.f_itemcode, i.f_en as f_itemname, m.f_finalname, m.f_amountamd, m.f_amountusd, m.f_usedprepaid, "
    "m.f_amountvat, m.f_fiscal, m.f_paymentmode, pm.f_en as f_paymentmodename, m.f_creditcard, cc.f_name as f_creditcardname, "
    "m.f_cityledger, cl.f_name as f_cityledgername, m.f_paymentcomment, m.f_dc, m.f_sign, m.f_doc, m.f_rec, m.f_finance, "
    "m.f_remarks, m.f_canceled, m.f_cancelreason, m.f_canceluser, m.f_canceldate, m.f_side, m.f_rb, m.f_vatmode, vm.f_en as f_vatmodename, "
    "m.f_session, m.f_fiscalmachine "
    "from m_register m "
    "left join users u on u.f_id=m.f_user "
    "left join f_invoice_item i on i.f_id=m.f_itemcode "
    "left join f_city_ledger cl on cl.f_id=m.f_cityledger "
    "left join f_payment_type pm on pm.f_id=m.f_paymentmode "
    "left join f_credit_card cc on cc.f_id=m.f_creditcard "
    "left join f_vat_mode vm on vm.f_id=m.f_vatmode ";

DBMRegister::DBMRegister()
{
    fWDate = __preferences.getLocalDate(def_working_day);
    fRDate = QDate::currentDate();
    fTime = QTime::currentTime();
    fUser = __preferences.getLocal(def_working_user_id).toUInt();
    fSession = 0;
    fRoom = 0;
    fItemCode = 0;
    fUsedPrepaid = 0;
    fAmountAMD = 0;
    fAmountUSD = def_usd;
    fAmountVAT = 0;
    fFiscal = 0;
    fPaymentMode = 0;
    fCreditCard = 0;
    fCityLedger = 0;
    fVATMode = 0;
    fSign = 0;
    fSide = 0;
    fFinance = 0;
    fCanceled = 0;
    fCancelUser = 0;
    fRb = 0;
    fFiscalMachine = 0;
    init();
}

DBMRegister::DBMRegister(const DBMRegister &r) :
    fId(r.fId),
    fSource(r.fSource),
    fReserve(r.fReserve),
    fInvoice(r.fInvoice),
    fWDate(r.fWDate),
    fRDate(r.fRDate),
    fTime(r.fTime),
    fUser(r.fUser),
    fUserName(r.fUserName),
    fRoom(r.fRoom),
    fGuest(r.fGuest),
    fItemCode(r.fItemCode),
    fItemName(r.fItemName),
    fFinalName(r.fFinalName),
    fUsedPrepaid(r.fUsedPrepaid),
    fAmountAMD(r.fAmountAMD),
    fAmountVAT(r.fAmountVAT),
    fAmountUSD(r.fAmountUSD),
    fVATMode(r.fVATMode),
    fVATModeName(r.fVATModeName),
    fFiscal(r.fFiscal),
    fPaymentMode(r.fPaymentMode),
    fPaymentModeName(r.fPaymentModeName),
    fCreditCard(r.fCreditCard),
    fCreditCardName(r.fCreditCardName),
    fCityLedger(r.fCityLedger),
    fCityLedgerName(r.fCityLedgerName),
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
    fCancelDate(r.fCancelDate),
    fRb(r.fRb),
    fSession(r.fSession),
    fFiscalMachine(r.fFiscalMachine)
{
    init();
    setle(r);
}

DBMRegister &DBMRegister::operator=(const DBMRegister &r)
{
    fId = r.fId;
    fSource = r.fSource;
    fReserve = r.fReserve;
    fInvoice = r.fInvoice;
    fWDate = r.fWDate;
    fRDate = r.fRDate;
    fTime = r.fTime;
    fUser = r.fUser;
    fUserName = r.fUserName;
    fRoom = r.fRoom;
    fGuest = r.fGuest;
    fItemCode = r.fItemCode;
    fItemName = r.fItemName;
    fFinalName = r.fFinalName;
    fUsedPrepaid = r.fUsedPrepaid;
    fAmountAMD = r.fAmountAMD;
    fAmountVAT = r.fAmountVAT;
    fAmountUSD = r.fAmountUSD;
    fVATMode = r.fVATMode;
    fVATModeName = r.fVATModeName;
    fFiscal = r.fFiscal;
    fPaymentMode = r.fPaymentMode;
    fPaymentModeName = r.fPaymentModeName;
    fCreditCard = r.fCreditCard;
    fCreditCardName = r.fCreditCardName;
    fCityLedger = r.fCityLedger;
    fCityLedgerName = r.fCityLedgerName;
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
    fRb = r.fRb;
    fSession = r.fSession;
    fFiscalMachine = r.fFiscalMachine;
    setle(r);
    return *this;
}

DBMRegister::~DBMRegister()
{
    delete fTc;
}

QString DBMRegister::voucherQuery()
{
    return voucher_query;
}

void DBMRegister::open(DoubleDatabase &d, const QString &id)
{
    d[":f_id"] = id;
    d.exec(voucher_query + " where m.f_id=:f_id");
    if (d.nextRow()) {
        fetchData(d);
        if (leID) {
            leID->setText(fId);
        }
        if (leUser) {
            leUser->setUInt(fUser);
        }
        if (leUserName) {
            leUserName->setText(fUserName);
        }
        if (leReserve) {
            leReserve->setText(fReserve);
        }
        if (leInvoice) {
            leInvoice->setText(fInvoice);
        }
        if (deWDate) {
            deWDate->setDate(fWDate);
        }
        if (leRoom) {
            leRoom->setUInt(fRoom);
        }
        if (leGuest) {
            leGuest->setText(fGuest);
        }
        if (leItemCode) {
            leItemCode->setUInt(fItemCode);
        }
        if (leItemName) {
            leItemName->setText(fItemName);
        }
        if (leFinalName) {
            leFinalName->setText(fFinalName);
        }
        if (leAmountAMD) {
            leAmountAMD->setDouble(fAmountAMD);
        }
        if (leAmountVAT) {
            leAmountVAT->setDouble(fAmountVAT);
        }
        if (leAmountUSD) {
            leAmountUSD->setDouble(fAmountAMD / fAmountUSD);
        }
        if (leVatMode) {
            leVatMode->setUInt(fVATMode);
        }
        if (leVatModeName) {
            leVatModeName->setText(fVATModeName);
        }
        if (lePaymentMode) {
            lePaymentMode->setUInt(fPaymentMode);
        }
        if (lePaymentModeName) {
            lePaymentModeName->setText(fPaymentModeName);
        }
        if (leCreditCard) {
            leCreditCard->setUInt(fCreditCard);
        }
        if (leCreditCardName) {
            leCreditCardName->setText(fCreditCardName);
        }
        if (leCityLedgerCode) {
            leCityLedgerCode->setUInt(fCityLedger);
        }
        if (leCityLedgerName) {
            leCityLedgerName->setText(fCityLedgerName);
        }
        if (leTaxCode) {
            leTaxCode->setUInt(fFiscal);
        }
        if (ptRemarks) {
            ptRemarks->setPlainText(fRemarks);
        }
        if (deWDate) {
            deWDate->setDate(fWDate);
        }
        fTc->resetChanges();
    }
}

void DBMRegister::fetchData(DoubleDatabase &d)
{
    fId = d.getString("f_id");
    fSource = d.getString("f_source");
    fReserve = d.getString("f_res");
    fInvoice = d.getString("f_inv");
    fWDate = d.getDate("f_wdate");
    fRDate = d.getDate("f_rdate");
    fTime = d.getTime("f_time");
    fUser = d.getUInt("f_user");
    fUserName = d.getString("f_username");
    fRoom = d.getUInt("f_room");
    fGuest = d.getString("f_guest");
    fItemCode = d.getUInt("f_itemcode");
    fItemName = d.getString("f_itemname");
    fFinalName = d.getString("f_finalname");
    fAmountAMD = d.getDouble("f_amountamd");
    fAmountUSD = d.getDouble("f_amountusd");
    fAmountVAT = d.getDouble("f_amountvat");
    fVATMode = d.getUInt("f_vatmode");
    fVATModeName = d.getString("f_vatmodename");
    fFiscal = d.getUInt("f_fiscal");
    fPaymentMode = d.getUInt("f_paymentmode");
    fPaymentModeName = d.getString("f_paymentmodename");
    fCreditCard = d.getUInt("f_creditcard");
    fCreditCardName = d.getString("f_creditcardname");
    fCityLedger = d.getUInt("f_cityledger");
    fCityLedgerName = d.getString("f_cityledgername");
    fPaymentComment = d.getString("f_paymentcomment");
    fDC = d.getString("f_dc");
    fSign = d.getInt("f_sign");
    fDoc = d.getString("f_doc");
    fRec = d.getString("f_rec");
    fFinance = d.getUInt("f_finance");
    fRemarks = d.getString("f_remarks");
    fSide = d.getUInt("f_side");
    fCanceled = d.getUInt("f_canceled");
    fCancelUser = d.getUInt("f_canceluser");
    fCancelDate = d.getDateTime("f_canceldate");
    fCancelReason = d.getString("f_cancelreason");
    fRb = d.getInt("f_rb");
    fSession = d.getInt("f_session");
    fFiscalMachine = d.getInt("f_fiscalmachie");
}

bool DBMRegister::openVoucher(const QString &id, QString &err)
{
    DoubleDatabase dd;
    dd[":f_id"] = id;
    dd.exec("select f_source from m_register where f_id=:f_id");
    if (dd.nextRow()) {
        QString voucherType = dd.getString(0);
        if (voucherType == VAUCHER_RECEIPT_N) {
            DlgReceiptVaucher *d = new DlgReceiptVaucher(0, 0, 0, fMainWindow);
            d->setVoucher(id);
            d->exec();
            delete d;
        } else if (voucherType == "RM" || voucherType == "CM" || voucherType == "CH" || voucherType == "PE") {
            DlgPostCharge *d = new DlgPostCharge(fMainWindow);
            d->setVoucher(id);
            d->exec();
            delete d;
        } else if (voucherType == "AV") {
            DlgAdvanceEntry *d = new DlgAdvanceEntry("", 0, fMainWindow);
            d->setVoucher(id);
            d->exec();
            delete d;
        }
    } else {
        err = tr("Could not load voucher");
        return false;
    }
    return true;
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
    dd[":f_vatmode"] = fVATMode;
    dd[":f_fiscal"] = fFiscal;
    dd[":f_paymentMode"] = fPaymentMode;
    dd[":f_creditCard"] = fCreditCard;
    dd[":f_cityLedger"] = fCityLedger;
    dd[":f_paymentComment"] = fPaymentComment;
    dd[":f_dc"] = fDC;
    dd[":f_sign"] = fSign;
    dd[":f_doc"] = fDoc;
    dd[":f_rec"] = fRec;
    dd[":f_remarks"] = fRemarks;
    dd[":f_finance"] = fFinance;
    dd[":f_canceled"] = fCanceled;
    dd[":f_cancelUser"] = fCancelUser;
    dd[":f_cancelReason"] = fCancelReason;
    dd[":f_cancelDate"] = fCancelDate;
    dd[":f_side"] = fSide;
    dd[":f_rb"] = fRb;
    dd[":f_session"] = fSession;
    dd[":f_fiscalmachine"] = fFiscalMachine;
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
    fTc->insert((isNew ? "NEW " : "EDIT ") + QString("VOUCHER"), QString("%1/%2/%3/%4")
                .arg(fSource)
                .arg(fFinalName)
                .arg(fAmountAMD)
                .arg(fCityLedgerName), "");
    fTc->resetChanges();
    return true;
}

void DBMRegister::showLog()
{
    DlgTracking::showTracking(fId);
}

void DBMRegister::setleID(EQLineEdit *l)
{
    leID = l;
}

void DBMRegister::setleUser(EQLineEdit *l1, EQLineEdit *l2)
{
    leUser = l1;
    leUserName = l2;
    connect(l1, SIGNAL(textChanged(QString)), this, SLOT(userChanged(QString)));
    connect(l2, SIGNAL(textChanged(QString)), this, SLOT(userNameChanged(QString)));
    fTc->addWidget(l2, "Operator");
}

void DBMRegister::setleFinalName(EQLineEdit *l)
{
    leFinalName = l;
    connect(l, SIGNAL(textChanged(QString)), this, SLOT(finalNameChanged(QString)));
    fTc->addWidget(l, "Final name");
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

void DBMRegister::setleItemName(EQLineEdit *l1, EQLineEdit *l2)
{
    leItemCode = l1;
    leItemName = l2;
    connect(l1, SIGNAL(textChanged(QString)), this, SLOT(itemCodeChanged(QString)));
    connect(l2, SIGNAL(textChanged(QString)), this, SLOT(itemNameChanged(QString)));
    fTc->addWidget(l2, "Item name");
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

void DBMRegister::setlePaymentMode(EQLineEdit *l1, EQLineEdit *l2)
{
    lePaymentMode = l1;
    lePaymentModeName = l2;
    connect(l1, SIGNAL(textChanged(QString)), this, SLOT(paymentChanged(QString)));
    connect(l2, SIGNAL(textChanged(QString)), this, SLOT(paymentNameChanged(QString)));
    fTc->addWidget(l2, "Payment mode");
}

void DBMRegister::setleCreditCard(EQLineEdit *l1, EQLineEdit *l2)
{
    leCreditCard = l1;
    leCreditCardName = l2;
    connect(l1, SIGNAL(textChanged(QString)), this, SLOT(creditCardChanged(QString)));
    connect(l2, SIGNAL(textChanged(QString)), this, SLOT(creditCardNameChanged(QString)));
    fTc->addWidget(l2, "Credit card");
}

void DBMRegister::setleVatMode(EQLineEdit *l1, EQLineEdit *l2)
{
    leVatMode = l1;
    leVatModeName = l2;
    connect(l1, SIGNAL(textChanged(QString)), this, SLOT(VATModeChanged(QString)));
    connect(l2, SIGNAL(textChanged(QString)), this, SLOT(VATModeNameChanged(QString)));
    fTc->addWidget(l2, "VAT mode");
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
}

void DBMRegister::setleAmountVAT(EQLineEdit *l)
{
    leAmountVAT = l;
    connect(l, SIGNAL(textChanged(QString)), this, SLOT(amountVATChanged(QString)));
    fTc->addWidget(l, "Amount VAT");
}

void DBMRegister::setleFiscal(EQLineEdit *l)
{
    leTaxCode = l;
    connect(l, SIGNAL(textChanged(QString)), this, SLOT(taxCodeChanged(QString)));
    fTc->addWidget(l, "Tax code");
}

void DBMRegister::setleFiscalMachine(EQLineEdit *l)
{
    leFiscalMachine = l;
    connect(l, SIGNAL(textChanged(QString)), this, SLOT(fiscalChanged(QString)));
    fTc->addWidget(l, "Fiscal machine");
}

void DBMRegister::setleRemarks(QPlainTextEdit *p)
{
    ptRemarks = p;
    connect(p, SIGNAL(textChanged()), this, SLOT(remarksChanged()));
    fTc->addWidget(p, "Remarks");
}

void DBMRegister::init()
{
    leID = nullptr;
    leUser = nullptr;
    leUserName = nullptr;
    deWDate = nullptr;
    leFinalName = nullptr;
    leInvoice = nullptr;
    leReserve = nullptr;
    leGuest = nullptr;
    leRoom = nullptr;
    leItemCode = nullptr;
    leItemName = nullptr;
    leCityLedgerCode = nullptr;
    leCityLedgerName = nullptr;
    lePaymentMode = nullptr;
    lePaymentModeName = nullptr;
    leCreditCard = nullptr;
    leCreditCardName = nullptr;
    leAmountAMD = nullptr;
    leAmountUSD = nullptr;
    leAmountVAT = nullptr;
    leVatMode = nullptr;
    leVatModeName = nullptr;
    leTaxCode = nullptr;
    ptRemarks = nullptr;
    fTc = new TrackControl(TRACK_VAUCHER);
}

void DBMRegister::setle(const DBMRegister &r)
{
    if (r.leID) {
        setleID(r.leID);
    }
    if (r.leUser) {
        setleUser(r.leUser, r.leUserName);
    }
    if (r.deWDate) {
        setleWDate(r.deWDate);
    }
    if (r.leFinalName) {
        setleFinalName(r.leFinalName);
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
    if (r.leRoom) {
        setleRoom(r.leRoom);
    }
    if (r.leCityLedgerCode) {
        setleCityLedger(r.leCityLedgerCode, r.leCityLedgerName);
    }
    if (r.lePaymentMode) {
        setlePaymentMode(r.lePaymentMode, r.lePaymentModeName);
    }
    if (r.leCreditCard) {
        setleCreditCard(r.leCreditCard, r.leCreditCardName);
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
    if (r.leVatMode) {
        setleVatMode(r.leVatMode, r.leVatModeName);
    }
    if (r.ptRemarks) {
        setleRemarks(r.ptRemarks);
    }
    if (r.leTaxCode) {
        setleFiscal(r.leTaxCode);
    }
    if (r.leItemCode) {
        setleItemName(r.leItemCode, r.leItemName);
    }
}

void DBMRegister::userChanged(const QString &s)
{
    fUser = s.toUInt();
}

void DBMRegister::userNameChanged(const QString &s)
{
    fUserName = s;
}

void DBMRegister::wdateChanged(const QString &s)
{
    Q_UNUSED(s);
    EDateEdit *d = static_cast<EDateEdit *>(sender());
    fWDate = d->date();
}

void DBMRegister::finalNameChanged(const QString &s)
{
    fFinalName = s;
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

void DBMRegister::itemCodeChanged(const QString &s)
{
    fItemCode = s.toUInt();
}

void DBMRegister::itemNameChanged(const QString &s)
{
    fItemName = s;
}

void DBMRegister::cityLedgerChanged(const QString &s)
{
    fCityLedger = s.toUInt();
}

void DBMRegister::cityLedgerNameChanged(const QString &s)
{
    fCityLedgerName = s;
}

void DBMRegister::paymentChanged(const QString &s)
{
    fPaymentMode = s.toUInt();
}

void DBMRegister::paymentNameChanged(const QString &s)
{
    fPaymentModeName = s;
}

void DBMRegister::creditCardChanged(const QString &s)
{
    fCreditCard = s.toUInt();
}

void DBMRegister::creditCardNameChanged(const QString &s)
{
    fCreditCardName = s;
}

void DBMRegister::amountAMDChagned(const QString &s)
{
    fAmountAMD = QLocale().toDouble(s);
    if (leAmountUSD) {
        leAmountUSD->setDouble(str_float(s) / fAmountUSD);
    }
}

void DBMRegister::amountUSDChanged(const QString &s)
{
    fAmountUSD = QLocale().toDouble(s);
}

void DBMRegister::amountVATChanged(const QString &s)
{
    fAmountVAT = QLocale().toDouble(s);
}

void DBMRegister::VATModeChanged(const QString &s)
{
    fVATMode = s.toUInt();
}

void DBMRegister::VATModeNameChanged(const QString &s)
{
    fVATModeName = s;
}

void DBMRegister::taxCodeChanged(const QString &s)
{
    fFiscal = s.toUInt();
}

void DBMRegister::fiscalChanged(const QString &s)
{
    fFiscalMachine = s.toInt();
}

void DBMRegister::remarksChanged()
{
    QPlainTextEdit *p = static_cast<QPlainTextEdit *>(sender());
    fRemarks = p->toPlainText();
}
