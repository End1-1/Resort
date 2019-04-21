#ifndef DLGPOSTBREAKFAST_H
#define DLGPOSTBREAKFAST_H

#include "baseextendeddialog.h"

namespace Ui {
class DlgPostBreakfast;
}

class DlgPostBreakfast : public BaseExtendedDialog
{
    Q_OBJECT

public:
    enum POST_TYPE {ptNone = 0, ptBreakfast, ptMinibar};
    explicit DlgPostBreakfast(QWidget *parent = nullptr);
    ~DlgPostBreakfast();
    virtual void callback(int sel, const QString &code);
    static bool postBreakfast(const QString &invoice, POST_TYPE pt = ptNone);
private slots:
    void on_btnCancel_clicked();

    void on_btnSave_clicked();

    void on_btnPrintTax_clicked();

    void on_leQty_textChanged(const QString &arg1);

    void on_leAmount_textChanged(const QString &arg1);

private:
    Ui::DlgPostBreakfast *ui;
};

#endif // DLGPOSTBREAKFAST_H
