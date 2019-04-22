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
    QString fId;
    QString fSource;
    QString fReserve;
    QString fInvoice;
    QDate fWDate;
    QDate fRDate;
    QTime fTime;
    quint32 fUser;
    quint32 fRoom;
    QString fGuest;
    quint32 fItemCode;
    QString fFinalName;
    double fUsedPrepaid;
    double fAmountAMD;
    double fAmountVAT;
    double fAmountUSD;
    quint32 fFiscal;
    quint32 fPaymentMode;
    quint32 fCreditCard;
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

    QString fError;
    TrackControl *fTc;
    bool save(DoubleDatabase &dd);
    void showLog();

    void setleID(EQLineEdit *l);
    void setleInvoice(EQLineEdit *l);
    void setleReserve(EQLineEdit *l);
    void setleWDate(EDateEdit *d);
    void setleGuest(EQLineEdit *l);
    void setleRoom(EQLineEdit *l);
    void setleCityLedger(EQLineEdit *l1, EQLineEdit *l2);
    void setleAmountAMD(EQLineEdit *l);
    void setleAmountUSD(EQLineEdit *l);
    void setleAmountVAT(EQLineEdit *l);
    void setleRemarks(QPlainTextEdit *p);

private:
    EQLineEdit *leID;
    EQLineEdit *leInvoice;
    EQLineEdit *leReserve;
    EQLineEdit *leGuest;
    EQLineEdit *leRoom;
    EQLineEdit *leCityLedgerCode;
    EQLineEdit *leCityLedgerName;
    EQLineEdit *leAmountAMD;
    EQLineEdit *leAmountUSD;
    EQLineEdit *leAmountVAT;
    EDateEdit *deWDate;
    QPlainTextEdit *ptRemarks;

    void init();
    void setle(const DBMRegister &r);

private slots:
    void wdateChanged(const QString &s);
    void invoiceChanged(const QString &s);
    void reserveChanged(const QString &s);
    void guestChanged(const QString &s);
    void roomChanged(const QString &s);
    void cityLedgerChanged(const QString &s);
    void cityLedgerNameChanged(const QString &s);
    void amountAMDChagned(const QString &s);
    void amountUSDChanged(const QString &s);
    void amountVATChanged(const QString &s);
    void remarksChanged(const QString &s);
};

#endif // DBMREGISTER_H
