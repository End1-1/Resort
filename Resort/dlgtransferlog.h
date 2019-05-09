#ifndef DLGTRANSFERLOG_H
#define DLGTRANSFERLOG_H

#include "basedialog.h"
#include <QThread>

class CopyThread : public QThread {
    Q_OBJECT
public:
    CopyThread(const QDate &d1, const QDate &d2);
protected:
    void run();
private:
    QDate fDate1;
    QDate fDate2;
signals:
    void status(const QString &);
};

namespace Ui {
class DlgTransferLog;
}

class DlgTransferLog : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgTransferLog(QWidget *parent = nullptr);
    ~DlgTransferLog();

private slots:
    void status(const QString &msg);
    void on_btnStart_clicked();

private:
    Ui::DlgTransferLog *ui;
};

#endif // DLGTRANSFERLOG_H
