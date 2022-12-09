#include "dlgrecoverinvoice.h"
#include "ui_dlgrecoverinvoice.h"

DlgRecoverInvoice::DlgRecoverInvoice(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgRecoverInvoice)
{
    ui->setupUi(this);
}

DlgRecoverInvoice::~DlgRecoverInvoice()
{
    delete ui;
}

void DlgRecoverInvoice::on_btnClose_clicked()
{
    reject();
}

void DlgRecoverInvoice::on_btnRecover_clicked()
{
    ui->teLog->clear();
    if (ui->leInvoice->isEmpty()) {
        ui->teLog->appendPlainText(tr("Empty invoice number"));
    }
    DoubleDatabase ddr(__dd2Host, __dd2Database, __dd2Username, __dd2Password);
    if (!ddr.open(true, false)) {
        ui->teLog->appendPlainText(tr("Cannot open recover database"));
        ui->teLog->appendPlainText(ddr.fLastError);
    }
    DoubleDatabase ddl(true, false);
    if (!ddl.open(true, false)) {
        ui->teLog->appendPlainText(tr("Cannot open local database"));
        ui->teLog->appendPlainText(ddl.fLastError);
    }
    int rec = 0;
    ddr[":f_inv"] = ui->leInvoice->text();
    if (!ddr.exec("select * from m_register where f_inv=:f_inv")) {
        ui->teLog->appendPlainText(ddl.fLastError);
    }
    while (ddr.nextRow()) {
        rec++;
        ddr.getBindValues(ddl.fBindValues);
        if (!ddl.insert("m_register", false)) {
            ui->teLog->appendPlainText(ddl.fLastError);
        }
    }
    ddr[":f_invoice"] = ui->leInvoice->text();
    if (!ddr.exec("select * from f_reservation where f_invoice=:f_invoice")) {
        ui->teLog->appendPlainText(ddl.fLastError);
    }
    while (ddr.nextRow()) {
        rec++;
        ddr.getBindValues(ddl.fBindValues);
        if (!ddl.insert("f_reservation", false)) {
            ui->teLog->appendPlainText(ddl.fLastError);
        }
    }
    ddr[":f_invoice"] = ui->leInvoice->text();
    if (!ddr.exec("select * from f_reservation_guests where f_reservation in (select f_id from f_reservation where f_invoice=:f_invoice)")) {
        ui->teLog->appendPlainText(ddl.fLastError);
    }
    while (ddr.nextRow()) {
        rec++;
        ddr.getBindValues(ddl.fBindValues);
        ddl.fBindValues.remove(":f_id");
        if (!ddl.insert("f_reservation_guests", false)) {
            ui->teLog->appendPlainText(ddl.fLastError);
        }
    }
    ddr[":f_invoice"] = ui->leInvoice->text();
    if (!ddr.exec("select * from f_guests where f_id in (select f_guest from f_reservation_guests where f_reservation in (select f_id from f_reservation where f_invoice=:f_invoice))")) {
        ui->teLog->appendPlainText(ddl.fLastError);
    }
    while (ddr.nextRow()) {
        rec++;
        ddr.getBindValues(ddl.fBindValues);
        if (!ddl.insert("f_guests", false)) {
            ui->teLog->appendPlainText(ddl.fLastError);
        }
    }
    ui->teLog->appendPlainText(tr("Done") + "<br>" + QString("Number of records: %1").arg(rec));
}

void DlgRecoverInvoice::on_btnRecoverRestaurant_clicked()
{
    ui->teLog->clear();
    if (ui->leInvoice->isEmpty()) {
        ui->teLog->appendPlainText(tr("Empty invoice number"));
    }
    DoubleDatabase ddr(__dd2Host, __dd2Database, __dd2Username, __dd2Password);
    if (!ddr.open(true, false)) {
        ui->teLog->appendPlainText(tr("Cannot open recover database"));
        ui->teLog->appendPlainText(ddr.fLastError);
    }
    DoubleDatabase ddl(true, false);
    if (!ddl.open(true, false)) {
        ui->teLog->appendPlainText(tr("Cannot open local database"));
        ui->teLog->appendPlainText(ddl.fLastError);
    }
    int rec = 0;
    ddr[":f_id"] = ui->leInvoice->text();
    if (!ddr.exec("select * from m_register where f_id=:f_id")) {
        ui->teLog->appendPlainText(ddl.fLastError);
    }
    while (ddr.nextRow()) {
        rec++;
        ddr.getBindValues(ddl.fBindValues);
        if (!ddl.insert("m_register", false)) {
            ui->teLog->appendPlainText(ddl.fLastError);
        }
    }
    ddr[":f_id"] = ui->leInvoice->text();
    if (!ddr.exec("select * from o_header where f_id=:f_id")) {
        ui->teLog->appendPlainText(ddl.fLastError);
    }
    while (ddr.nextRow()) {
        rec++;
        ddr.getBindValues(ddl.fBindValues);
        if (!ddl.insert("o_header", false)) {
            ui->teLog->appendPlainText(ddl.fLastError);
        }
    }
    ddr[":f_header"] = ui->leInvoice->text();
    if (!ddr.exec("select * from o_dish where f_header=:f_header")) {
        ui->teLog->appendPlainText(ddl.fLastError);
    }
    while (ddr.nextRow()) {
        rec++;
        ddr.getBindValues(ddl.fBindValues);
        if (!ddl.insert("o_dish", false)) {
            ui->teLog->appendPlainText(ddl.fLastError);
        }
    }
    ui->teLog->appendPlainText(tr("Done") + "<br>" + QString("Number of records: %1").arg(rec));
}
