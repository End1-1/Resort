#ifndef DLGCLEARLOG_H
#define DLGCLEARLOG_H

#include "basedialog.h"

namespace Ui {
class DlgClearLog;
}

class DlgClearLog : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgClearLog(QWidget *parent = nullptr);
    ~DlgClearLog();

private slots:
    void on_btnClear_clicked();

private:
    Ui::DlgClearLog *ui;
};

#endif // DLGCLEARLOG_H
