#ifndef DLGEXECFAILEDSQLS_H
#define DLGEXECFAILEDSQLS_H

#include "basedialog.h"

namespace Ui {
class DlgExecFailedSqls;
}

class DlgExecFailedSqls : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgExecFailedSqls(QWidget *parent = nullptr);
    ~DlgExecFailedSqls();
    static void openDialog();

private slots:
    void on_btnCancel_clicked();
    void on_btnStart_clicked();

private:
    Ui::DlgExecFailedSqls *ui;
};

#endif // DLGEXECFAILEDSQLS_H
