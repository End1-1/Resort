#include "refiscalmachine.h"
#include "ui_refiscalmachine.h"
#include "cachefiscalmachine.h"
#include "message.h"
#include "taxhelper.h"

REFiscalMachine::REFiscalMachine(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_COMMON, parent),
    ui(new Ui::REFiscalMachine)
{
    ui->setupUi(this);
    fTable = "s_tax_map";
    fCacheId = cid_fiscalmachine;
    addWidget(ui->leCode, "Code")
            .addWidget(ui->leName, "Name")
            .addWidget(ui->leIp, "IP")
            .addWidget(ui->lePort, "Port")
            .addWidget(ui->lePassword, "Password")
            .addWidget(ui->leOpCode, "Operator code")
            .addWidget(ui->leOpPin, "Operator pin")
            .addWidget(ui->leExtPos, "Ext pos");
}

REFiscalMachine::~REFiscalMachine()
{
    delete ui;
}

void REFiscalMachine::on_btnCancel_clicked()
{
    reject();
}

void REFiscalMachine::on_btnOk_clicked()
{
    if (saveOnly()) {
        TaxHelper::init();
        accept();
    }
}

void REFiscalMachine::on_btnRemove_clicked()
{
    if (ui->leCode->asInt() == 0) {
        reject();
        return;
    }
    if (message_yesnocancel(tr("Are you sure to delete this fiscal machine?")) != RESULT_YES) {
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_fiscalmachine"] = ui->leCode->asInt();
    fDD.exec("select f_id from m_register where f_fiscalmachine=:f_fiscalmachine limit 1");
    if (fDD.rowCount() > 0) {
        message_error(tr("Cannot remove fiscal machine. Records found in vouchers history."));
        return;
    }
    fDD[":f_tax"] = ui->leCode->asInt();
    fDD.exec("select f_item from f_invoice_item_tax where f_tax=:f_tax limit 1");
    if (fDD.rowCount() > 0) {
        message_error(tr("Cannot remove fiscal machine. It is used in invoice item tax map."));
        return;
    }

    QString oldValue = QString("%1/%2/%3:%4")
                       .arg(ui->leCode->text(), ui->leName->text(), ui->leIp->text(), ui->lePort->text());
    fDD[":f_id"] = ui->leCode->asInt();
    fDD.exec("delete from s_tax_map where f_id=:f_id");
    fTrackControl->fRecord = ui->leCode->text();
    fTrackControl->insert("Remove fiscal machine", oldValue, "");
    fTrackControl->saveChanges();
    BroadcastThread::cmdRefreshCache(cid_fiscalmachine, ui->leCode->text());
    TaxHelper::init();
    clearWidgets();
    accept();
    message_info(tr("The fiscal machine removed from database, refresh current report"));
}
