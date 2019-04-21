#ifndef DLGWAKEPCALLS_H
#define DLGWAKEPCALLS_H

#include "basedialog.h"

namespace Ui {
class DlgWakepCalls;
}

class DlgWakepCalls : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgWakepCalls(QWidget *parent = nullptr);
    ~DlgWakepCalls();
    static void openWakeupCalls(const QString &room);
    static void openWakeupCallsByInvoice(const QString &invoice);

private slots:
    void on_btnAddWakeup_clicked();

    void on_tbl_customContextMenuRequested(const QPoint &pos);

    void removeWakeup();

private:
    Ui::DlgWakepCalls *ui;

    void load();
};

#endif // DLGWAKEPCALLS_H
