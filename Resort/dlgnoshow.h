#ifndef DLGNOSHOW_H
#define DLGNOSHOW_H

#include "basedialog.h"

namespace Ui {
class DlgNoShow;
}

class DlgNoShow : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgNoShow(QWidget *parent = nullptr);
    ~DlgNoShow();
    virtual void callback(int sel, const QString &code);
    void setReservation(const QString &reserv);
    void load(const QString &id);

private slots:
    void on_btnClose_clicked();
    void on_btnPrint_clicked();
    void on_btnSave_clicked();
    void on_btnPrintTax_clicked();
    void on_btnLog_clicked();

private:
    Ui::DlgNoShow *ui;
    void getBalance();
};

#endif // DLGNOSHOW_H
