#ifndef WPAYMENTDETAILS_H
#define WPAYMENTDETAILS_H

#include "basewidget.h"

namespace Ui {
class WPaymentDetails;
}

class DBMRegister;
class EQLineEdit;

class WPaymentDetails : public BaseWidget
{
    Q_OBJECT

public:
    explicit WPaymentDetails(QWidget *parent = nullptr);
    ~WPaymentDetails();
    virtual void callback(int sel, const QString &code);
    void clearSelectors();
    void setFiscal(int id);
    void setTaxReceipt(int id);
    int getTaxReceipt();
    int getFiscal();
    void setDBMRegister(DBMRegister *r);
    void setPaymentFilter(QList<int> modes);
    int paymentCode();
    double amount();
    void setSuggestAmount(double d);
    void hideVAT(bool v);
    QString paymentComment() const;
    QString cardName() const;
    EQLineEdit *leFiscal();
    EQLineEdit *leTaxReceipt();

private slots:
    void on_btnSuggestAmount_clicked();

private:
    Ui::WPaymentDetails *ui;
    void hideCard(bool v);
    void hideCL(bool v);
};

#endif // WPAYMENTDETAILS_H
