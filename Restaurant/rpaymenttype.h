#ifndef RPAYMENTTYPE_H
#define RPAYMENTTYPE_H

#include "baseextendeddialogr.h"

namespace Ui {
class RPaymentType;
}

class RPaymentType : public BaseExtendedDialogR
{
    Q_OBJECT

public:
    explicit RPaymentType(QWidget *parent = 0);
    ~RPaymentType();
    static int getPaymentMode(QWidget *parent, int &addResult);
private slots:
    void on_btnOk_clicked();

    void on_btnCancel_clicked();

private:
    Ui::RPaymentType *ui;
};

#endif // RPAYMENTTYPE_H
