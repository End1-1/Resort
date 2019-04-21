#ifndef DLGQUICKADVANCEAPPLY_H
#define DLGQUICKADVANCEAPPLY_H

#include "basedialog.h"

namespace Ui {
class DlgQuickAdvanceApply;
}

class DlgQuickAdvanceApply : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgQuickAdvanceApply(QWidget *parent = nullptr);
    ~DlgQuickAdvanceApply();
    virtual void callback(int sel, const QString &code);
    static bool apply(int room, double amount, int paymode, int card, const QString &tax);

private slots:
    void on_btnCancel_clicked();
    void on_btnApply_clicked();
    void on_btnPrint_clicked();
    void on_leType_textChanged(const QString &arg1);

private:
    Ui::DlgQuickAdvanceApply *ui;
};

#endif // DLGQUICKADVANCEAPPLY_H
