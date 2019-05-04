#ifndef DLGRECOVERINVOICE_H
#define DLGRECOVERINVOICE_H

#include "basedialog.h"

namespace Ui {
class DlgRecoverInvoice;
}

class DlgRecoverInvoice : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgRecoverInvoice(QWidget *parent = nullptr);
    ~DlgRecoverInvoice();

private slots:
    void on_btnClose_clicked();
    void on_btnRecover_clicked();

    void on_btnRecoverRestaurant_clicked();

private:
    Ui::DlgRecoverInvoice *ui;
};

#endif // DLGRECOVERINVOICE_H
