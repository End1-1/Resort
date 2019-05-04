#ifndef WPAYMENTDETAILS_H
#define WPAYMENTDETAILS_H

#include "basewidget.h"

namespace Ui {
class WPaymentDetails;
}

class DBMRegister;

class WPaymentDetails : public BaseWidget
{
    Q_OBJECT

public:
    explicit WPaymentDetails(QWidget *parent = nullptr);
    ~WPaymentDetails();
    virtual void callback(int sel, const QString &code);
    void clearSelectors();
    void setDBMRegister(DBMRegister *r);
    void setPaymentFilter(QList<int> modes);
    int paymentCode();
    double amount();
    void hideVAT(bool v);
    QString paymentComment() const;
    QString cardName() const;

private:
    Ui::WPaymentDetails *ui;
    void hideCard(bool v);
    void hideCL(bool v);
};

#endif // WPAYMENTDETAILS_H
