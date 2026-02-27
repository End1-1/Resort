#include "dlgmovetocl.h"
#include "cachecityledger.h"
#include "cachepaymentmode.h"
#include "message.h"
#include "stringutils.h"
#include "trackcontrol.h"
#include "ui_dlgmovetocl.h"

DlgMoveToCL::DlgMoveToCL(const QString &voucher, QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgMoveToCL)
{
    ui->setupUi(this);
    ui->tblPay->setColumnWidth(0, 100);
    ui->tblPay->setColumnWidth(1, 300);
    ui->tblPay->setColumnWidth(2, 100);
    ui->tblPay->setColumnWidth(3, 100);
    ui->tblPay->addRow();
    ui->tblPay->setValue(0, 0, tr("None"));
    ui->leDCL->setSelector(this, cache(cid_city_ledger), ui->leDCLName);
    ui->leCurrCL->setSelector(this, cache(cid_city_ledger), ui->leCurrCLName);
    ui->leCurrPayment->setSelector(this, cache(cid_payment_mode), ui->leCurrPaymentName);
    ui->leDCL->setInitialValue(__s.value("dst_move_to_cl").toInt());

    DoubleDatabase db;
    db[":f_id"] = voucher;
    db.exec("select * from m_register where f_id=:f_id");
    if (db.nextRow() == false) {
        message_error(tr("Invalid voucher id"));
        reject();
        return;
    }
    ui->leVoucher->setText(voucher);
    ui->leFinaleName->setText(db.getString("f_finalname"));
    ui->leAmount->setDouble(db.getDouble("f_amountamd"));
    ui->leCurrPayment->setInitialValue(db.getInt("f_paymentmode"));
    ui->leInvoice->setText(db.getString("f_inv"));
    fSource = db.getString("f_source");

    db[":f_inv"] = db.getString("f_inv");
    db.exec("select f_id, f_finalname, f_amountamd, f_cityledger from m_register "
            "where f_inv=:f_inv and f_source='RV' and f_canceled=0 and f_cityledger>0");
    while (db.nextRow()) {
        int r = ui->tblPay->rowCount();
        ui->tblPay->setRowCount(r + 1);
        for (int c = 0; c < db.columnCount(); c++) {
            ui->tblPay->setValue(r, c, db.getValue(c));
        }
    }
}

DlgMoveToCL::~DlgMoveToCL()
{
    delete ui;
}
void DlgMoveToCL::on_btnCancel_clicked()
{
    reject();
}

void DlgMoveToCL::on_tblPay_cellClicked(int row, int column)
{
    if (row == 0) {
        ui->leCurrCL->setInitialValue(0);
    } else {
        ui->leCurrCL->setInitialValue(ui->tblPay->toInt(row, 3));
    }
}

void DlgMoveToCL::on_btnChange_clicked()
{
    if (ui->leDCL->asInt() == 0) {
        message_error(tr("No destination CL selected"));
        return;
    }
    if (message_confirm(tr("Confirm operation")) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase db;
    db[":f_sign"] = fSource == "RV" ? 1 : -1;
    db[":f_dc"] = fSource == "RV" ? "CREDIT" : "DEBIT";
    db[":f_guest"] = ui->leDCLName->text();
    db[":f_cityledger"] = ui->leDCL->asInt();
    db[":f_finalname"] = ui->leFinaleName->text() + " " + ui->leCurrCLName->text();
    db[":f_id"] = ui->leVoucher->text();
    db.exec("update m_register set f_inv='', f_res='', f_room=0, f_paymentmode=9, f_guest=:f_guest, "
            "f_sign=:f_sign, f_dc=:f_dc, "
            "f_cityledger=:f_cityledger, f_finalname=:f_finalname where f_id=:f_id");
    TrackControl::insert(TRACK_INVOICE_ITEM, "CHANGE CL", ui->leCurrCLName->text(), ui->leDCLName->text(), ui->leVoucher->text(), ui->leInvoice->text() );

    int r = ui->tblPay->currentRow();
    if (r > 0) {
        db[":f_id"] = ui->tblPay->toString(r, 0);
        db[":f_amount"] = ui->tblPay->toDouble(r, 2) - ui->leAmount->asDouble();
        db.exec("update m_register set f_amountamd=:f_amount, f_amountusd=:f_amountamd/f_amountusd where f_id=:f_id");
        TrackControl::insert(TRACK_INVOICE_ITEM,
                             "CHANGE AMOUNT",
                             ui->tblPay->toString(r, 2),
                             QString::number(ui->tblPay->toDouble(r, 2) - ui->leAmount->asDouble()),
                             ui->tblPay->toString(r, 0),
                             ui->leInvoice->text());
        if (ui->tblPay->toDouble(r, 2) - ui->leAmount->asDouble() < 1) {
            db[":f_id"] = ui->tblPay->toString(r, 0);
            db[":f_canceluser"] = WORKING_USERID;
            db.exec("update m_register set f_canceled=1, f_canceldate=current_timestamp, f_canceluser=:f_canceluser, f_cancelreason='AMOUNT = 0' where f_id=:f_id");    TrackControl::insert(TRACK_INVOICE_ITEM, "CANCELED", "AMOUNT = 0", "", ui->tblPay->toString(r, 0), ui->leInvoice->text() );
        }
    }
    accept();
}

void DlgMoveToCL::on_leDCL_textChanged(const QString &arg1)
{
    __s.setValue("dst_move_to_cl", arg1);
}
