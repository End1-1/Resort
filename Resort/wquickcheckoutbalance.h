#ifndef WQUICKCHECKOUTBALANCE_H
#define WQUICKCHECKOUTBALANCE_H

#include "basedialog.h"

namespace Ui {
class WQuickCheckoutBalance;
}

class WQuickCheckoutBalance : public BaseDialog
{
    Q_OBJECT

public:
    explicit WQuickCheckoutBalance(QWidget *parent = nullptr);
    ~WQuickCheckoutBalance();

private:
    Ui::WQuickCheckoutBalance *ui;
};

#endif // WQUICKCHECKOUTBALANCE_H
