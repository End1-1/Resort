#ifndef DBMINVOICE_H
#define DBMINVOICE_H

#include "doubledatabase.h"
#include "dbmregister.h"
#include <QString>
#include <QDate>
#include <QObject>

class EQLineEdit;
class EDateEdit;
class TrackControl;

class DBMInvoice : QObject
{
    Q_OBJECT

public:
    DBMInvoice();
    ~DBMInvoice();
    bool open(DoubleDatabase &d, const QString &id);
    bool save(DoubleDatabase &d);
    bool addVoucher(const DBMRegister &r);
    int vouchersCount();
    DBMRegister &voucher(int index);

    void setleInvoice(EQLineEdit *l);
    void setleDate(EDateEdit *d);
    void setleCityLedger(EQLineEdit *l1, EQLineEdit *l2);
    void setleDebit(EQLineEdit *l);
    void setleCredit(EQLineEdit *l);
    void setleBalance(EQLineEdit *l);

    QString fInvoice;
    QString fReserve;
    QDate fDate;
    int fCityLedger;
    QString fCityLedgerName;
    double fDebit;
    double fCredit;
    QString fError;

private:
    void init();
    void setBalance();
    void countAmounts();
    QList<DBMRegister> fVouchers;
    TrackControl *fTc;

    EQLineEdit *leInvoice;
    EQLineEdit *leCityLedger;
    EQLineEdit *leCityLedgerName;
    EDateEdit *deDate;
    EQLineEdit *leDebit;
    EQLineEdit *leCredit;
    EQLineEdit *leBalance;

private slots:
    void cityLedgerChanged(const QString &s);
    void cityLedgerNameChanged(const QString &s);
    void idateChanged(const QString &s);
};

#endif // DBMINVOICE_H
