#ifndef DLGENDOFDAY_H
#define DLGENDOFDAY_H

#include "baseextendeddialog.h"

namespace Ui {
class DlgEndOfDay;
}

class DlgEndOfDay : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DlgEndOfDay(QWidget *parent = nullptr);
    ~DlgEndOfDay();

private slots:
    void openReservation(const QString &id);
    void openInvoice(const QString &id);
    void on_btnCancel_clicked();
    void on_btnOk_clicked();
    void on_btnRefresh_clicked();

private:
    Ui::DlgEndOfDay *ui;
    bool fCanCharge;
    void loadData();
};

#endif // DLGENDOFDAY_H
