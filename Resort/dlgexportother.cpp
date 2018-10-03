#include "dlgexportother.h"
#include "ui_dlgexportother.h"
#include "fvauchers.h"
#include <QTextBlock>

DlgExportOther::DlgExportOther(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgExportOther)
{
    ui->setupUi(this);
}

DlgExportOther::~DlgExportOther()
{
    delete ui;
}

void DlgExportOther::on_btnStart_clicked()
{
    DoubleDatabase db;
    QStringList dbParams = fPreferences.getDb("AHC").toString().split(";", QString::SkipEmptyParts);
    if (dbParams.count() < 4) {
        message_error(tr("Setup second database parameters"));
        return;
    }
    db.setDatabase(dbParams[0], dbParams[1], dbParams[2], dbParams[3], 1);
    if (!db.open(true, false)) {
        message_error(tr("Cannot connect to second database"));
        return;
    }
    if (ui->chCardex->isChecked()) {
        processTable("f_cardex", db);
    }
    if (ui->chCityLedger->isChecked()) {
        processTable("f_city_ledger", db);
    }

    if (ui->chUsers->isChecked()) {
        processTable("users", db);
    }
    if (ui->chMenu->isChecked()) {
        processTable("r_dish", db);
        processTable("r_dish_complex", db);
        processTable("r_dish_mod", db);
        processTable("r_dish_mod_required", db);
        processTable("r_dish_part", db);
        processTable("r_dish_type", db);
        processTable("r_complimentary_comment", db);
        processTable("r_banquet_comment", db);
        processTable("r_menu", db);
        processTable("r_menu_names", db);
    }
    if (ui->chReports->isChecked()) {
        processTable("serv_reports", db);
    }
    if (ui->chUserRights->isChecked()) {
        processTable2("users_rights", db);
    }
    message_info(tr("Synchronization complete"));
}

void DlgExportOther::processTable(const QString &table, DoubleDatabase &db)
{
    DoubleDatabase dd(db);
    dd.open(true, false);
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.exec("select * from " + table);
    ui->teLog->appendPlainText(QString("Process %1. %2 rows.")
                               .arg(table)
                               .arg(fDD.rowCount()));
    ui->teLog->appendPlainText(tr("Go!"));
    for (int i = 0, count = fDD.rowCount(); i < count; i++) {
        fDD.getBindValues(i, db.fBindValues);
        if (table == "f_city_ledger") {
            if (db.fBindValues[":f_extra1"].toString().length() > 0) {
                db.fBindValues[":f_name"] = db.fBindValues[":f_extra1"];
                db.fBindValues[":f_address"] = db.fBindValues[":f_extra2"];
                db.fBindValues[":f_phone"] = "";
                db.fBindValues[":f_email"] = "";
            }
        }
        if (table == "f_cardex") {
            if (db.fBindValues[":f_extra1"].toString().length() > 0) {
                db.fBindValues[":f_name"] = db.fBindValues[":f_extra1"];
                db.fBindValues[":f_addr1"] = db.fBindValues[":f_extra2"];
                db.fBindValues[":f_addr2"] = "";
                db.fBindValues[":f_contact"] = "";
                db.fBindValues[":f_contactPos"] = "";
                db.fBindValues[":f_email"] = "";
                db.fBindValues[":f_fax"] = "";
                db.fBindValues[":f_tel"] = "";
            }
        }

        dd.deleteTableEntry(table, db.fBindValues[":f_id"]);
        db.insert(table);
        if (i % 50 == 0) {
            logCount(fDD.rowCount(), i);
        }
    }
    logCount(fDD.rowCount(), fDD.rowCount());
}

void DlgExportOther::processTable2(const QString &table, DoubleDatabase &db)
{
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.exec("select * from " + table);
    ui->teLog->appendPlainText(QString("Process %1. %2 rows.")
                               .arg(table)
                               .arg(fDD.rowCount()));
    ui->teLog->appendPlainText(tr("Go!"));
    db.exec("delete from " + table);
    for (int i = 0, count = fDD.rowCount(); i < count; i++) {
        fDD.getBindValues(i, db.fBindValues);
        if (table == "f_city_ledger") {
            if (db.fBindValues[":f_extra1"].toString().length() > 0) {
                db.fBindValues[":f_name"] = db.fBindValues[":f_extra1"];
                db.fBindValues[":f_address"] = db.fBindValues[":f_extra2"];
                db.fBindValues[":f_phone"] = "";
                db.fBindValues[":f_email"] = "";
            }
        }
        if (table == "f_cardex") {
            if (db.fBindValues[":f_extra1"].toString().length() > 0) {
                db.fBindValues[":f_name"] = db.fBindValues[":f_extra1"];
                db.fBindValues[":f_addr1"] = db.fBindValues[":f_extra2"];
                db.fBindValues[":f_addr2"] = "";
                db.fBindValues[":f_contact"] = "";
                db.fBindValues[":f_contactPos"] = "";
                db.fBindValues[":f_email"] = "";
                db.fBindValues[":f_fax"] = "";
                db.fBindValues[":f_tel"] = "";
            }
        }
        db.fBindValues.remove(":f_id");
        db.insert(table, false);
        if (i % 50 == 0) {
            logCount(fDD.rowCount(), i);
        }
    }
    logCount(fDD.rowCount(), fDD.rowCount());
}

void DlgExportOther::logCount(int total, int current)
{
    QString text = QString("%1 of %2").arg(current).arg(total);
    QTextBlock tb = ui->teLog->document()->findBlockByLineNumber(ui->teLog->document()->lineCount() - 1);
    if (tb.isValid()) {
        QTextCursor cursor(tb);
        cursor.select(QTextCursor::BlockUnderCursor);
        cursor.removeSelectedText();
    }
    ui->teLog->appendPlainText(text);
    qApp->processEvents();
}

void DlgExportOther::on_btnCancel_clicked()
{
    reject();
}
