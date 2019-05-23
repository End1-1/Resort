#ifndef DLGQUICKADVANCEACTION_H
#define DLGQUICKADVANCEACTION_H

#include "basedialog.h"

namespace Ui {
class DlgQuickAdvanceAction;
}

class DlgQuickAdvanceAction : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgQuickAdvanceAction(QWidget *parent = nullptr);
    ~DlgQuickAdvanceAction();
    virtual void callback(int sel, const QString &code);
    void setJson(int taxCode, const QString &json, const QString &remarks);
    int taxNumber();
    double cash();
    double card();
    QString type();
    QString remarks();
    QString fJson;

private slots:
    void removeRow();
    void on_btnPlus_clicked();
    void on_leQty_textEdited(const QString &arg1);
    void on_lePrice_textEdited(const QString &arg1);
    void on_leTotal_textEdited(const QString &arg1);
    void on_btnPrint_clicked();
    void on_leGrandCash_textEdited(const QString &arg1);
    void on_leGrandCard_textEdited(const QString &arg1);

private:
    Ui::DlgQuickAdvanceAction *ui;
    void countTotal();
};

#endif // DLGQUICKADVANCEACTION_H
