#include "dlgexecfailedsqls.h"
#include "ui_dlgexecfailedsqls.h"
#include "message.h"

DlgExecFailedSqls::DlgExecFailedSqls(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgExecFailedSqls)
{
    ui->setupUi(this);
    DoubleDatabase dd;
    dd.setDatabase(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass);
    dd.open();
    dd[":f_src"] = __dd1Database;
    dd.exec("select count(f_id) from f_fail where f_src<>:f_src and f_norec=0 ");
    dd.nextRow();
    ui->lbView->setText(QString("Failed sql queries count: %1").arg(dd.getInt(0)));
}

DlgExecFailedSqls::~DlgExecFailedSqls()
{
    delete ui;
}

void DlgExecFailedSqls::openDialog()
{
    DlgExecFailedSqls *d = new DlgExecFailedSqls(fPreferences.getDefaultParentForMessage());
    d->exec();
    delete d;
}

void DlgExecFailedSqls::on_btnCancel_clicked()
{
    reject();
}

void DlgExecFailedSqls::on_btnStart_clicked()
{
    DoubleDatabase fDD;
    DoubleDatabase dempty; //local
    dempty.open();
    DoubleDatabase did;
    did.open();
    DoubleDatabase dsql; //remote
    dsql.setDatabase(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass); //resort
    dsql.open();
    dsql[":f_src"] = __dd1Database;
    dsql.exec("select * from airwick.f_fail where f_src<>:f_src and f_norec=0");
    DoubleDatabase ddel;
    ddel.open();
    DoubleDatabase dsrc;
    QString db = "hnaw";
#ifdef QT_DEBUG
    db = "resort";
#endif
    dsrc.setDatabase(BaseUIDX::fAirHost, db, BaseUIDX::fAirUser, BaseUIDX::fAirPass); //resort
    dsrc.open();
    while (dsql.nextRow()) {
        bool ok = true;
        if (dsql.getString("f_failId").isEmpty()) {
            ok = dempty.exec(dsql.getString("f_sql"));
        } else {
            QString id = dsql.getString("f_failId");
            id.replace("'", "");
            QString op = dsql.getString("f_failOp").toLower();
            QString table = dsql.getString("f_failTable");
            if (op == "insert" || op == "update") {
                dsrc[":f_id"] = id;
                if (!dsrc.exec("select * from " + table + " where f_id=:f_id")) {
                    fDD.logEvent(dsrc.fLastError);
                    continue;
                }
                if (dsrc.nextRow()) {
                    did[":f_id"] = id;
                    did.exec("delete from " + table + " where f_id=:f_id");
                    dsrc.getBindValues(did.fBindValues);
                    ok = did.insert(table, false);
                } else {
                    ok = false;
                    fDD.logEvent("No nextrow for " + table + " / " + id);
                    ddel[":f_id"] = dsql.getInt("f_id");
                    ddel.exec("update f_fail set f_norec=1 where f_id=:f_id");
                }
            } else if (op == "delete") {
                ok = dempty.exec(dsql.getString("f_sql"));
            }
        }
        if (ok) {
            ddel[":f_id"] = dsql.getInt("f_id");
            ddel.exec("delete from f_fail where f_id=:f_id");
        }
    }
    /*

    int i =0;
    dd.exec("select * from hnaw.m_register where f_wdate='2018-09-04'");
    while (dd.nextRow()) {
        ui->lbView->setText(QString("%1 / %2").arg(i++).arg(dd.rowCount()));
        qApp->processEvents();
        d2[":f_id"] = dd.getValue("f_id");
        d2.exec("delete from testb.m_register where f_id=:f_id");
        dd.getBindValues(d2.fBindValues);
        d2.insert("m_register", false);
        if (dd.getString("f_source") == "PS") {
            ddd[":f_id"] = dd.getValue("f_id");
            ddd.exec("select * from hnaw.o_header where f_id=:f_id");
            ddd.nextRow();
            d2[":f_id"] = dd.getValue("f_id");
            d2.exec("delete from testb.o_header where f_id=:f_id");
            ddd.getBindValues(d2.fBindValues);
            d2.insert("o_header", false);
            ddd[":f_header"] = dd.getValue("f_id");
            ddd.exec("select * from hnaw.o_dish where f_header=:f_header");
            while (ddd.nextRow()) {
                d2[":f_id"] = ddd.getValue("f_id");
                d2.exec("delete from testb.o_dish where f_id=:f_id");
                ddd.getBindValues(d2.fBindValues);
                d2.insert("o_dish", false);
            }
        }
    }
    */
    message_info(tr("Done"));
}
