#ifndef WQUICKCHECKOUTPROCESS_H
#define WQUICKCHECKOUTPROCESS_H

#include "basedialog.h"
#include <QTimer>

namespace Ui {
class WQuickCheckoutProcess;
}

class WQuickCheckoutProcess : public BaseDialog
{
    Q_OBJECT

public:
    explicit WQuickCheckoutProcess(QWidget *parent = nullptr);
    ~WQuickCheckoutProcess();
    void setListOfInvoices(const QStringList &invoices);
    virtual int exec();

private:
    Ui::WQuickCheckoutProcess *ui;
    QTimer fTimer;

private slots:
    void timeout();
};

#endif // WQUICKCHECKOUTPROCESS_H
