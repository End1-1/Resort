#ifndef DLGMOVETOCL_H
#define DLGMOVETOCL_H

#include "basedialog.h"

namespace Ui {
class DlgMoveToCL;
}

class DlgMoveToCL : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgMoveToCL(const QString &voucher, QWidget *parent = nullptr);
    ~DlgMoveToCL();

private slots:
    void on_btnCancel_clicked();

    void on_tblPay_cellClicked(int row, int column);

    void on_btnChange_clicked();

    void on_leDCL_textChanged(const QString &arg1);

private:
    Ui::DlgMoveToCL *ui;

    QString fSource;
};

#endif // DLGMOVETOCL_H
