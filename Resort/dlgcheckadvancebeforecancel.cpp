#include "dlgcheckadvancebeforecancel.h"
#include "ui_dlgcheckadvancebeforecancel.h"
#include "dlgnoshow.h"
#include "dlgtransferanyamount.h"
#include "message.h"
#include "dlgrefundvaucher.h"

DlgCheckAdvanceBeforeCancel::DlgCheckAdvanceBeforeCancel(const QString &inv, QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgCheckAdvanceBeforeCancel)
{
    ui->setupUi(this);
    fInvoice = inv;
    DoubleDatabase fDD;
    fDD[":f_invoice"] = inv;
    fDD.exec("select r.f_id, r.f_room, g.guest from f_reservation r "
              "left join guests g on g.f_id=r.f_guest "
              "where r.f_invoice=:f_invoice");
    if (fDD.nextRow()) {
        ui->leReservation->setText(fDD.getValue("f_id").toString());
        ui->leGuest->setText(fDD.getValue("guest").toString());
        ui->leRoom->setText(fDD.getValue("f_room").toString());
        ui->leInvoice->setText(inv);
    }
}

DlgCheckAdvanceBeforeCancel::~DlgCheckAdvanceBeforeCancel()
{
    delete ui;
}

int DlgCheckAdvanceBeforeCancel::checkAdvance(const QString &inv, QString &reason)
{
    DlgCheckAdvanceBeforeCancel *d = new DlgCheckAdvanceBeforeCancel(inv, fPreferences.getDefaultParentForMessage());
    d->getBalance();
    int result = d->exec();
    reason = d->ui->teReason->toPlainText();
    delete d;
    return result;
}

bool DlgCheckAdvanceBeforeCancel::getBalance()
{
    DoubleDatabase fDD;
    fDD[":f_inv"] = fInvoice;    
    fDD.exec("select sum(f_amountAmd*f_sign*-1) as amount from m_register where f_inv=:f_inv "
              "and f_finance=1 and f_canceled=0");
    if (!fDD.nextRow()) {
        ui->leBalance->setText("0");
        return false;
    }
    ui->leBalance->setDouble(fDD.getValue("amount").toDouble());
    ui->btnCancelreservation->setEnabled(ui->leBalance->asDouble() < 0.01);
    ui->btnRefund->setEnabled(ui->leBalance->asDouble() > 0.01);
    ui->btnTransferToCL->setEnabled(ui->leBalance->asDouble() > 0.01);
    ui->btnNoShow->setEnabled(r__(cr__reservation_cancelation_no_show));
    return true;
}

void DlgCheckAdvanceBeforeCancel::on_btnCancel_clicked()
{
    done(CR_NOCANCEL);
}

void DlgCheckAdvanceBeforeCancel::on_btnNoShow_clicked()
{
    DlgNoShow *d = new DlgNoShow(fPreferences.getDefaultParentForMessage());
    d->setReservation(ui->leReservation->text());
    d->exec();
    delete d;
    getBalance();
}

void DlgCheckAdvanceBeforeCancel::on_btnRefund_clicked()
{
    DlgRefundVaucher::refundVaucher("", ui->leReservation->text());
    getBalance();
}

void DlgCheckAdvanceBeforeCancel::on_btnCancelreservation_clicked()
{
    if (message_confirm(tr("Confirm to cancel reservation")) == RESULT_YES)  {
        ui->teReason->setPlainText(ui->teReason->toPlainText().trimmed());
        if (ui->teReason->toPlainText().isEmpty()) {
            message_error(tr("Please, specify the reason of cancelation"));
            return;
        }
        done(CR_CANCEL);
    }
}

void DlgCheckAdvanceBeforeCancel::on_btnTransferToCL_clicked()
{
    DlgTransferAnyAmount *d = new DlgTransferAnyAmount(this);
    d->setHint(hint_from_reserve);
    d->setReservation(ui->leReservation->text());
    d->exec();
    delete d;
    getBalance();
}
