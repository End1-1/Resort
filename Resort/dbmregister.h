#ifndef DBMREGISTER_H
#define DBMREGISTER_H

#include "doubledatabase.h"
#include <QObject>
#include <QString>
#include <QDate>

class EQLineEdit;
class EDateEdit;
class QPlainTextEdit;
class TrackControl;

class DBMRegister : QObject
{
    Q_OBJECT

public:
    DBMRegister();
    DBMRegister(const DBMRegister &r);
    DBMRegister &operator=(const DBMRegister &r);
    ~DBMRegister();
    static QString voucherQuery();
    void open(DoubleDatabase &d, const QString &id);
    void fetchData(DoubleDatabase &d);
    static bool openVoucher(const QString &id, QString &err);
    QString fId;
    QString fSource;
    QString fReserve;
    QString fInvoice;
    QDate fWDate;
    QDate fRDate;
    QTime fTime;
    quint32 fUser;
    QString fUserName;
    quint32 fRoom;
    QString fGuest;
    quint32 fItemCode;
    QString fItemName;
    QString fFinalName;
    double fUsedPrepaid;
    double fAmountAMD;
    double fAmountVAT;
    double fAmountUSD;
    quint32 fVATMode;
    QString fVATModeName;
    quint32 fFiscal;
    quint32 fPaymentMode;
    QString fPaymentModeName;
    quint32 fCreditCard;
    QString fCreditCardName;
    quint32 fCityLedger;
    QString fCityLedgerName;
    QString fPaymentComment;
    QString fDC;
    qint32 fSign;
    QString fDoc;
    QString fRec;
    quint32 fSide;
    quint32 fFinance;
    QString fRemarks;
    quint32 fCanceled;
    quint32 fCancelUser;
    QString fCancelReason;
    QDateTime fCancelDate;
    int fRb;
    int fSession;
    int fFiscalMachine;

    QString fError;
    TrackControl *fTc;
    bool save(DoubleDatabase &dd);
    void showLog();

    void setleID(EQLineEdit *l);
    void setleUser(EQLineEdit *l1, EQLineEdit *l2);
    void setleFinalName(EQLineEdit *l);
    void setleInvoice(EQLineEdit *l);
    void setleReserve(EQLineEdit *l);
    void setleWDate(EDateEdit *d);
    void setleGuest(EQLineEdit *l);
    void setleRoom(EQLineEdit *l);
    void setleItemName(EQLineEdit *l1, EQLineEdit *l2);
    void setleCityLedger(EQLineEdit *l1, EQLineEdit *l2);
    void setlePaymentMode(EQLineEdit *l1, EQLineEdit *l2);
    void setleCreditCard(EQLineEdit *l1, EQLineEdit *l2);
    void setleVatMode(EQLineEdit *l1, EQLineEdit *l2);
    void setleAmountAMD(EQLineEdit *l);
    void setleAmountUSD(EQLineEdit *l);
    void setleAmountVAT(EQLineEdit *l);
    void setleFiscal(EQLineEdit *l);
    void setleFiscalMachine(EQLineEdit *l);
    void setleRemarks(QPlainTextEdit *p);

private:
    EQLineEdit *leID;
    EQLineEdit *leUser;
    EQLineEdit *leUserName;
    EQLineEdit *leFinalName;
    EQLineEdit *leInvoice;
    EQLineEdit *leReserve;
    EQLineEdit *leGuest;
    EQLineEdit *leRoom;
    EQLineEdit *leItemCode;
    EQLineEdit *leItemName;
    EQLineEdit *leCityLedgerCode;
    EQLineEdit *leCityLedgerName;
    EQLineEdit *lePaymentMode;
    EQLineEdit *lePaymentModeName;
    EQLineEdit *leCreditCard;
    EQLineEdit *leCreditCardName;
    EQLineEdit *leAmountAMD;
    EQLineEdit *leAmountUSD;
    EQLineEdit *leAmountVAT;
    EQLineEdit *leVatMode;
    EQLineEdit *leVatModeName;
    EQLineEdit *leTaxCode;
    EQLineEdit *leFiscalMachine;
    EDateEdit *deWDate;
    QPlainTextEdit *ptRemarks;

    void init();
    void setle(const DBMRegister &r);

private slots:
    void userChanged(const QString &s);
    void userNameChanged(const QString &s);
    void wdateChanged(const QString &s);
    void finalNameChanged(const QString &s);
    void invoiceChanged(const QString &s);
    void reserveChanged(const QString &s);
    void guestChanged(const QString &s);
    void roomChanged(const QString &s);
    void itemCodeChanged(const QString &s);
    void itemNameChanged(const QString &s);
    void cityLedgerChanged(const QString &s);
    void cityLedgerNameChanged(const QString &s);
    void paymentChanged(const QString &s);
    void paymentNameChanged(const QString &s);
    void creditCardChanged(const QString &s);
    void creditCardNameChanged(const QString &s);
    void amountAMDChagned(const QString &s);
    void amountUSDChanged(const QString &s);
    void amountVATChanged(const QString &s);
    void VATModeChanged(const QString &s);
    void VATModeNameChanged(const QString &s);
    void taxCodeChanged(const QString &s);
    void fiscalChanged(const QString &s);
    void remarksChanged();
};

#endif // DBMREGISTER_H
