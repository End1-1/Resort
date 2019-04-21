#ifndef DLGEXPORTOTHER_H
#define DLGEXPORTOTHER_H

#include "baseextendeddialog.h"

namespace Ui {
class DlgExportOther;
}

class DlgExportOther : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DlgExportOther(QWidget *parent = nullptr);
    ~DlgExportOther();

private slots:
    void on_btnStart_clicked();

    void on_btnCancel_clicked();

private:
    Ui::DlgExportOther *ui;
    void processTable(const QString &table, DoubleDatabase &db);
    void processTable2(const QString &table, DoubleDatabase &db);
    void logCount(int total, int current);
};

#endif // DLGEXPORTOTHER_H
