#include "dlgquickadvanceapply.h"
#include "ui_dlgquickadvanceapply.h"
#include "cachepaymentmode.h"
#include "cachecreditcard.h"
#include "cacheactiveroom.h"
#include "paymentmode.h"
#include "cachevaucher.h"
#include "message.h"
#include "vauchers.h"
#include "pprintvaucher.h"
#include "dbmregister.h"

static const int HINT_ROOM = 1;

DlgQuickAdvanceApply::DlgQuickAdvanceApply(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgQuickAdvanceApply)
{
    ui->setupUi(this);
    ui->leRoom->setSelector(this, cache(cid_active_room), ui->leRoomShort, HINT_ROOM);
    ui->leType->setSelector(this, cache(cid_payment_mode), ui->leTypeName);
    ui->leType->fCodeFilter << QString::number(PAYMENT_CASH)
            << QString::number(PAYMENT_CARD);
    ui->leVoucherType->setSelector(this, cache(cid_vaucher), ui->leVoucherTypeName);
    ui->leVoucherType->setInitialValue(VAUCHER_RECEIPT_N);
    ui->leVoucher->fCodeFilter << VAUCHER_RECEIPT_N
                               << VAUCHER_ADVANCE_N;
    ui->leCardType->setSelector(this, cache(cid_credit_card), ui->leCardTypeName);
}

DlgQuickAdvanceApply::~DlgQuickAdvanceApply()
{
    delete ui;
}

void DlgQuickAdvanceApply::callback(int sel, const QString &code)
{
    switch (sel) {
    case HINT_ROOM: {
        CacheActiveRoom c;
        if (c.get(code)) {
            ui->leGuest->setText(c.fGuestName());
            ui->leInvoice->setText(c.fInvoice());
            ui->leReserve->setText(c.fCode());
        } else {
            ui->leGuest->clear();
            ui->leInvoice->clear();
            ui->leReserve->clear();
        }
    }
    }
}

bool DlgQuickAdvanceApply::apply(int room, double amount, int paymode, int card, const QString &tax)
{
    DlgQuickAdvanceApply *d = new DlgQuickAdvanceApply(fPreferences.getDefaultParentForMessage());
    d->ui->leRoom->setInitialValue(room);
    d->ui->leAmount->setDouble(amount);
    d->ui->leType->setInitialValue(paymode);
    d->ui->leCardType->setInitialValue(card);
    d->ui->leTax->setText(tax);
    d->exec();
    bool result = !d->ui->leVoucher->isEmpty();
    delete d;
    return result;
}

void DlgQuickAdvanceApply::on_btnCancel_clicked()
{
    reject();
}

void DlgQuickAdvanceApply::on_btnApply_clicked()
{
    if (ui->leType->asInt() == 0) {
        message_error(tr("Mode of payment is not selected"));
        return;
    }
    if (ui->leType->asInt() == PAYMENT_CARD) {
        if (ui->leCardType->asInt() == 0) {
            message_error(tr("Card type is not selected"));
            return;
        }
    }
    DoubleDatabase dd;
    dd[":f_id"] = ui->leReserve->text();
    dd.exec("select f_state from f_reservation where f_id=:f_id");
    if (dd.nextRow()) {
        if (dd.getInt(0) != RESERVE_CHECKIN) {
            message_error(tr("The state of reservation is not checkin"));
            return;
        }
    } else {
        message_error(tr("Reservation is not exists"));
        return;
    }
    DBMRegister r;
    r.fSource = ui->leVoucherType->text();
    r.fReserve = ui->leReserve->text();
    r.fInvoice = ui->leInvoice->text();
    r.fRoom = ui->leRoom->asUInt();
    r.fGuest = ui->leGuest->text();
    if (ui->leVoucherType->text() == VAUCHER_RECEIPT_N) {
        r.fItemCode = fPreferences.getDb(def_receip_vaucher_id).toUInt();
        if (ui->leType->asInt() == 0) {
            r.fFinalName = tr("PAYMENT CASH");
        } else {
            r.fFinalName = tr("PAYMENT ") + ui->leCardTypeName->text();
        }
    } else {
        r.fItemCode = fPreferences.getDb(def_advance_voucher_id).toUInt();
        if (ui->leType->asInt() == 0) {
            r.fFinalName = tr("ADVANCE CASH");
        } else {
            r.fFinalName = tr("ADVANCE ") + ui->leCardTypeName->text();
        }
    }
    r.fFinance = 1;
    r.fAmountAMD = ui->leAmount->asDouble();
    r.fAmountUSD = ui->leAmount->asDouble() / def_usd;
    r.fFiscal = ui->leTax->text() == "YES" ? 1 : 0;
    r.fPaymentMode = ui->leType->asUInt();
    r.fCreditCard = ui->leCardType->asUInt();
    r.fDC = PAY_CREDIT;
    r.fSign = -1;
    if (!r.save(dd)) {
        message_error(r.fError);
        return;
    }
    ui->leVoucher->setText(r.fId);
    ui->btnApply->setEnabled(false);
    ui->btnPrint->setEnabled(true);
    ui->btnCancel->setText(tr("Close"));
}

void DlgQuickAdvanceApply::on_btnPrint_clicked()
{
    PPrintVaucher::printVaucher(ui->leVoucher->text());
}

void DlgQuickAdvanceApply::on_leType_textChanged(const QString &arg1)
{
    ui->leCardType->setEnabled(arg1.toInt() == PAYMENT_CARD);
    ui->leCardTypeName->setEnabled(arg1.toInt() == PAYMENT_CARD);
}
