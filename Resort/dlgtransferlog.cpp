#include "dlgtransferlog.h"
#include "ui_dlgtransferlog.h"

DlgTransferLog::DlgTransferLog(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgTransferLog)
{
    ui->setupUi(this);
}

DlgTransferLog::~DlgTransferLog()
{
    delete ui;
}

void DlgTransferLog::status(const QString &msg)
{
    ui->lbMsg->setText(msg);
}

void DlgTransferLog::on_btnStart_clicked()
{
    CopyThread *ct = new CopyThread(ui->deStart->date(), ui->deEnd->date());
    connect(ct, SIGNAL(status(QString)), this, SLOT(status(QString)));
    ct->start();
}

CopyThread::CopyThread(const QDate &d1, const QDate &d2) {
    fDate1 = d1;
    fDate2 = d2;
    connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
}

void CopyThread::run() {
    DoubleDatabase d1(true, false);
    d1[":f_date1"] = fDate1;
    d1[":f_date2"] = fDate2;
    if (!d1.exec("select * from airlog.log where f_date between :f_date1 and :f_date2")) {
        emit status(d1.fLastError);
        return;
    }
    int rows = d1.rowCount();
    if (rows == 0) {
        emit status("Empty query");
        return;
    }
    int rowsInserted = 0;
    while (d1.nextRow()) {
        DoubleDatabase dd(true, false);
        DoubleDatabase d2;
        d2.setDatabase(__dd2Host, __dd2Database, __dd2Username, __dd2Password, 1);
        d2.open(true, false);
        d1.getBindValues(d2.fBindValues);
        QVariant id = d2.fBindValues[":f_id"];
        d2.fBindValues.remove(":f_id");
        if (!d2.insert("airlog.log", false)) {
            emit status(d2.fLastError);
            return;
        }
        dd[":f_id"] = id;
        dd.exec("delete from airlog.log where f_id=:f_id");
        rowsInserted++;
        if (rowsInserted % 100 == 0) {
            emit status(QString("%1 of %2").arg(rowsInserted).arg(rows));
        }
    }
    emit status(QString("%1 of %2").arg(rows).arg(rows));
}
