#include "dlgtransferanyamount.h"
#include "ui_dlgtransferanyamount.h"
#include "cacheredreservation.h"
#include "cachecityledger.h"
#include "cacheroom.h"
#include "cacheactiveroom.h"
#include "vauchers.h"
#include "paymentmode.h"
#include "message.h"

static const int dc_debit = 1;
static const int dc_credit = 2;

DlgTransferAnyAmount::DlgTransferAnyAmount(QWidget *parent) :
    BaseDialog (parent),
    ui(new Ui::DlgTransferAnyAmount)
{
    ui->setupUi(this);
    QDoubleValidator *dv = new QDoubleValidator(0,999999999, 2);
    dv->setNotation(QDoubleValidator::StandardNotation);
    ui->letoAmount->setValidator(dv);
    ui->rbfromRoom->click();
    ui->rbtoCL->click();
    // FROM SIDE
    fDoc1.setleID(ui->leDebitVoucher);
    fDoc1.setleWDate(ui->dewDate);
    fDoc1.setleReserve(ui->lefromReserve);
    fDoc1.setleInvoice(ui->lefromInvoice);
    fDoc1.setleRoom(ui->lefromRoomCode);
    fDoc1.setleGuest(ui->lefromGuest);
    fDoc1.setleAmountAMD(ui->letoAmount);
    fDoc1.setleAmountUSD(ui->leAmountUSD);
    fDoc1.setleRemarks(ui->teRemarks);
    fDoc1.setleCityLedger(ui->lefromCL, ui->lefromCLName);
    //TO SIDE
    fDoc2.setleID(ui->leCreditVoucher);
    fDoc2.setleWDate(ui->dewDate);
    fDoc2.setleReserve(ui->letoReserve);
    fDoc2.setleInvoice(ui->letoInvoice);
    fDoc2.setleRoom(ui->letoRoomCode);
    fDoc2.setleGuest(ui->letoGuest);
    fDoc2.setleAmountAMD(ui->letoAmount);
    fDoc2.setleAmountUSD(ui->leAmountUSD);
    fDoc2.setleRemarks(ui->teRemarks);
    fDoc2.setleCityLedger(ui->letoCL, ui->letoCLName);
}

DlgTransferAnyAmount::~DlgTransferAnyAmount()
{
    delete ui;
}

void DlgTransferAnyAmount::setHint(int hint)
{
    switch (hint) {
    case hint_from_room:
        ui->rbfromRoom->click();
        break;
    case hint_from_reserve:
        ui->rbfromReserve->click();
        break;
    case hint_from_cl:
        ui->rbfromCL->click();
        break;
    }
}

void DlgTransferAnyAmount::setRoom(int room)
{
    ui->lefromRoomCode->setInitialValue(room);
}

void DlgTransferAnyAmount::setReservation(const QString &reserve)
{
    ui->lefromReserve->setInitialValue(reserve);
}

void DlgTransferAnyAmount::callback(int sel, const QString &code)
{
    switch (sel) {
    case hint_from_room: {
        CacheActiveRoom c;
        if (c.get(code)) {
            ui->lefromRoomName->setText(c.fName());
            ui->lefromReserve->setText(c.fCode());
            ui->lefromInvoice->setText(c.fInvoice());
            ui->lefromGuest->setText(c.fGuestName());
            ui->defromEntry->setDate(c.fEntry());
            ui->defromDeparture->setDate(c.fDeparture());
            DoubleDatabase dd;
            dd[":f_inv"] = c.fInvoice();
            dd.exec("select sum(f_amountAmd*f_sign) from m_register where f_inv=:f_inv and f_finance=1 and f_canceled=0");
            dd.nextRow();
            ui->lefromBalance->setDouble(dd.getDouble(0));
            if (ui->lefromBalance->asDouble() < 0) {
                ui->rbfromDebit->setChecked(true);
            } else {
                ui->rbfromCredit->setChecked(true);
            }
        } else {
            ui->lefromRoomName->clear();
            ui->lefromReserve->clear();
            ui->lefromInvoice->clear();
            ui->lefromGuest->clear();
            ui->defromEntry->clear();
            ui->defromDeparture->clear();
            ui->lefromBalance->clear();
        }
        break;
    }
    case hint_from_reserve: {
        CacheRedReservation c;
        if (c.get(code)) {
            CacheRoom r;
            if (r.get(c.fRoom())) {
                ui->lefromRoomName->setText(r.fName());
            } else {
                ui->lefromRoomName->clear();
            }
            ui->lefromRoomCode->setText(c.fRoom());
            ui->lefromReserve->setText(c.fCode());
            ui->lefromInvoice->setText(c.fInvoice());
            ui->lefromGuest->setText(c.fGuest());
            ui->defromEntry->setText(c.fEntry());
            ui->defromDeparture->setText(c.fDeparture());
            DoubleDatabase dd;
            dd[":f_inv"] = c.fInvoice();
            dd.exec("select sum(f_amountAmd*f_sign) from m_register where f_inv=:f_inv and f_finance=1 and f_canceled=0");
            dd.nextRow();
            ui->lefromBalance->setDouble(dd.getDouble(0));
            if (ui->lefromBalance->asDouble() < 0) {
                ui->rbfromDebit->setChecked(true);
            } else {
                ui->rbfromCredit->setChecked(true);
            }
        } else {
            ui->lefromRoomName->clear();
            ui->lefromReserve->clear();
            ui->lefromInvoice->clear();
            ui->lefromGuest->clear();
            ui->defromEntry->clear();
            ui->defromDeparture->clear();
            ui->lefromBalance->clear();
        }
        break;
    }
    case hint_from_cl: {
        CacheCityLedger c;
        if (c.get(code)) {
            DoubleDatabase dd;
            dd[":f_cityledger"] = code;
            dd.exec("select sum(f_amountamd*f_sign) from m_register where f_cityledger=:f_cityledger and f_finance=1 and f_canceled=0");
            dd.nextRow();
            ui->lefromBalance->setDouble(dd.getDouble(0));
        } else {
            ui->lefromBalance->clear();
        }
        if (ui->lefromBalance->asDouble() < 0) {
            ui->rbfromDebit->setChecked(true);
        } else {
            ui->rbfromCredit->setChecked(true);
        }
        break;
    }
    case hint_to_room: {
        CacheActiveRoom c;
        if (c.get(code)) {
            ui->letoRoomName->setText(c.fName());
            ui->letoReserve->setText(c.fCode());
            ui->letoInvoice->setText(c.fInvoice());
            ui->letoGuest->setText(c.fGuestName());
            ui->detoEntry->setDate(c.fEntry());
            ui->detoDeparture->setDate(c.fDeparture());
            DoubleDatabase dd;
            dd[":f_inv"] = c.fInvoice();
            dd.exec("select sum(f_amountAmd*f_sign) from m_register where f_inv=:f_inv and f_finance=1 and f_canceled=0");
            dd.nextRow();
            ui->letoBalance->setDouble(dd.getDouble(0));
        } else {
            ui->letoRoomName->clear();
            ui->letoReserve->clear();
            ui->letoInvoice->clear();
            ui->letoGuest->clear();
            ui->detoEntry->clear();
            ui->detoDeparture->clear();
            ui->letoBalance->clear();
        }
        break;
    }
    case hint_to_reserve: {
        CacheRedReservation c;
        if (c.get(code)) {
            CacheRoom r;
            if (r.get(c.fRoom())) {
                ui->letoRoomName->setText(r.fName());
            } else {
                ui->letoRoomName->clear();
            }
            ui->letoRoomCode->setText(c.fRoom());
            ui->letoReserve->setText(c.fCode());
            ui->letoInvoice->setText(c.fInvoice());
            ui->letoGuest->setText(c.fGuest());
            ui->detoEntry->setText(c.fEntry());
            ui->detoDeparture->setText(c.fDeparture());
            DoubleDatabase dd;
            dd[":f_inv"] = c.fInvoice();
            dd.exec("select sum(f_amountAmd*f_sign) from m_register where f_inv=:f_inv and f_finance=1 and f_canceled=0");
            dd.nextRow();
            ui->letoBalance->setDouble(dd.getDouble(0));
        } else {
            ui->letoRoomName->clear();
            ui->letoReserve->clear();
            ui->letoInvoice->clear();
            ui->letoGuest->clear();
            ui->detoEntry->clear();
            ui->detoDeparture->clear();
            ui->letoBalance->clear();
        }
        break;
    }
    case hint_to_cl: {
        CacheCityLedger c;
        if (c.get(code)) {
            DoubleDatabase dd;
            dd[":f_cityledger"] = code;
            dd.exec("select sum(f_amountamd*f_sign) from m_register where f_cityledger=:f_cityledger and f_finance=1 and f_canceled=0");
            dd.nextRow();
            ui->letoBalance->setDouble(dd.getDouble(0));
        } else {
            ui->letoBalance->clear();
        }
        break;
    }
    }
}

void DlgTransferAnyAmount::on_btnCancel_clicked()
{
    reject();
}

void DlgTransferAnyAmount::on_rbfromReserve_clicked()
{
    ui->wDC->setEnabled(false);
    ui->wfromCL->setVisible(false);
    ui->lefromCL->clear();
    ui->lefromCLName->clear();
    ui->wfromRoom->setVisible(true);
    ui->lefromRoomCode->setSelector(nullptr, nullptr, nullptr);
    ui->lefromCL->setSelector(nullptr, nullptr, nullptr);
    ui->lefromReserve->setSelector(this, cache(cid_red_reservation), ui->letoRoomName, hint_from_reserve);
    ui->lefromRoomCode->setStyleSheet("");
    ui->lefromCL->setStyleSheet("");
    ui->lefromReserve->setStyleSheet("background:yellow;");
    ui->defromEntry->clear();
    ui->defromDeparture->clear();
    ui->lefromRoomCode->clear();
    ui->lefromReserve->setInitialValue(ui->lefromReserve->text());
}

void DlgTransferAnyAmount::on_rbfromRoom_clicked()
{
    ui->wDC->setEnabled(false);
    ui->wfromCL->setVisible(false);
    ui->lefromCL->clear();
    ui->lefromCLName->clear();
    ui->wfromRoom->setVisible(true);
    ui->lefromRoomCode->setSelector(this, cache(cid_active_room), ui->lefromRoomName, hint_from_room);
    ui->lefromCL->setSelector(nullptr, nullptr, nullptr);
    ui->lefromReserve->setSelector(nullptr, nullptr, nullptr);
    ui->lefromRoomCode->setStyleSheet("background:yellow;");
    ui->lefromCL->setStyleSheet("");
    ui->lefromReserve->setStyleSheet("");
    ui->defromEntry->clear();
    ui->defromDeparture->clear();
    ui->lefromRoomCode->clear();
    ui->lefromRoomCode->setInitialValue(ui->lefromRoomCode->text());
}

void DlgTransferAnyAmount::on_rbfromCL_clicked()
{
    ui->wDC->setEnabled(true);
    ui->wfromCL->setVisible(true);
    ui->wfromRoom->setVisible(false);
    ui->lefromRoomCode->clear();
    ui->lefromRoomName->clear();
    ui->lefromReserve->clear();
    ui->lefromInvoice->clear();
    ui->lefromGuest->clear();
    ui->lefromRoomCode->setSelector(nullptr, nullptr, nullptr);
    ui->lefromCL->setSelector(this, cache(cid_city_ledger), ui->lefromCLName, hint_from_cl);
    ui->lefromReserve->setSelector(nullptr, nullptr, nullptr);
    ui->lefromRoomCode->setStyleSheet("");
    ui->lefromCL->setStyleSheet("background:yellow;");
    ui->lefromReserve->setStyleSheet("");
    ui->defromEntry->clear();
    ui->defromDeparture->clear();
    ui->letoCL->setInitialValue(ui->letoCL->text());
}

void DlgTransferAnyAmount::on_rbtoReserve_clicked()
{
    ui->wtoCL->setVisible(false);
    ui->letoCL->clear();
    ui->letoCLName->clear();
    ui->wtoRoom->setVisible(true);
    ui->letoRoomCode->setSelector(nullptr, nullptr, nullptr);
    ui->letoCL->setSelector(nullptr, nullptr, nullptr);
    ui->letoReserve->setSelector(this, cache(cid_red_reservation), ui->letoRoomName, hint_to_reserve);
    ui->letoRoomCode->setStyleSheet("");
    ui->letoCL->setStyleSheet("");
    ui->letoReserve->setStyleSheet("background:yellow;");
    ui->detoEntry->clear();
    ui->detoDeparture->clear();
    ui->letoRoomCode->clear();
    ui->letoReserve->setInitialValue(ui->letoReserve->text());
}

void DlgTransferAnyAmount::on_rbtoRoom_clicked()
{
    ui->wtoCL->setVisible(false);
    ui->letoCL->clear();
    ui->letoCLName->clear();
    ui->wtoRoom->setVisible(true);
    ui->letoRoomCode->setSelector(this, cache(cid_active_room), ui->letoRoomName, hint_to_room);
    ui->letoCL->setSelector(nullptr, nullptr, nullptr);
    ui->letoReserve->setSelector(nullptr, nullptr, nullptr);
    ui->letoRoomCode->setStyleSheet("background:yellow;");
    ui->letoCL->setStyleSheet("");
    ui->letoReserve->setStyleSheet("");
    ui->detoEntry->clear();
    ui->detoDeparture->clear();
    ui->letoRoomCode->clear();
    ui->letoRoomCode->setInitialValue(ui->letoRoomCode->text());
}

void DlgTransferAnyAmount::on_rbtoCL_clicked()
{
    ui->wtoCL->setVisible(true);
    ui->wtoRoom->setVisible(false);
    ui->letoRoomCode->clear();
    ui->letoRoomName->clear();
    ui->letoReserve->clear();
    ui->letoInvoice->clear();
    ui->letoGuest->clear();
    ui->letoRoomCode->setSelector(nullptr, nullptr, nullptr);
    ui->letoCL->setSelector(this, cache(cid_city_ledger), ui->letoCLName, hint_to_cl);
    ui->letoReserve->setSelector(nullptr, nullptr, nullptr);
    ui->letoRoomCode->setStyleSheet("");
    ui->letoCL->setStyleSheet("background:yellow;");
    ui->letoReserve->setStyleSheet("");
    ui->detoEntry->clear();
    ui->detoDeparture->clear();
    ui->letoCL->setInitialValue(ui->letoCL->text());
}

void DlgTransferAnyAmount::on_letoAmount_textChanged(const QString &arg1)
{
    ui->leAmountUSD->setDouble(arg1.toDouble() / def_usd);
}

void DlgTransferAnyAmount::on_btnSave_clicked()
{
    QString err;
    QString finalName("Transfer from :from to :to");
    QString replaceFrom, replaceTo;
    QString guestFrom, guestTo;
    if (ui->letoAmount->asDouble() < 0.001) {
        err += tr("Invalid amount for transfer") + "<br>";
    }
    if (ui->letoAmount->asDouble() > abs(ui->lefromBalance->asDouble()) && !ui->rbfromCL->isChecked()) {
        err += tr("Transfer amount cannot be greater then balance") + "<br>";
    }

    switch (ui->wfromAction->radioTag()) {
    case hint_from_reserve:
        replaceFrom = ui->lefromReserve->text();
        guestFrom = ui->lefromGuest->text();
        if (ui->lefromReserve->isEmpty()) {
            err += tr("Source reservation is empty") + "<br>";
        }
        if (ui->lefromInvoice->text() == ui->letoInvoice->text()) {
            err += tr("Useless transfer") + "<br>";
        }
        break;
    case hint_from_room:
        replaceFrom = ui->lefromRoomCode->text() + "," + ui->lefromInvoice->text();
        guestFrom = ui->lefromGuest->text();
        if (ui->lefromInvoice->isEmpty()) {
            err += tr("Source invoice is empty") + "<br>";
        }
        if (ui->lefromInvoice->text() == ui->letoInvoice->text()) {
            err += tr("Useless transfer") + "<br>";
        }
        break;
    case hint_from_cl:
        replaceFrom = "CL/" + ui->lefromCLName->text();
        guestFrom = ui->lefromCLName->text();
        if (ui->lefromCL->text() == ui->letoCL->text()) {
            err += tr("Useless transfer") + "<br>";
        }
        if (ui->lefromCL->asInt() == 0) {
            err += tr("Source cityledger is empty") + "<br>";
        }
        break;
    }

    switch (ui->wtoAction->radioTag()) {
    case hint_to_reserve:
        replaceTo = ui->letoReserve->text();
        guestTo = ui->letoGuest->text();
        if (ui->letoReserve->isEmpty()) {
            err += tr("Destination reservation is empty") + "<br>";
        }
        break;
    case hint_to_room:
        replaceTo = ui->letoRoomCode->text() + ", " + ui->letoInvoice->text();
        guestTo = ui->letoGuest->text();
        if (ui->letoInvoice->isEmpty()) {
            err += tr("Destination invoice is empty") + "<br>";
        }
        break;
    case hint_to_cl:
        replaceTo = "CL/" + ui->letoCLName->text();
        guestTo = ui->letoCLName->text();
        if (ui->letoCL->asInt() == 0) {
            err += tr("Destination cityledger is empty") + "<br>";
        }
        break;
    }

    QString dcn1, dcn2;
    int dcc1 = 0, dcc2 = 0;
    switch (ui->wDC->radioTag()) {
    case dc_debit:
        switch (ui->wfromAction->radioTag()) {
        case hint_from_reserve:
        case hint_from_room:
            dcn1 = PAY_CREDIT;
            dcc1 = 1;
            switch (ui->wtoAction->radioTag()) {
            case hint_to_reserve:
            case hint_to_room:
                dcn2 = PAY_DEBIT;
                dcc2 = -1;
                break;
            case hint_to_cl:
                dcn2 = PAY_CREDIT;
                dcc2 = 1;
                break;
            }
            break;
        case hint_from_cl:
            dcn1 = PAY_CREDIT;
            dcc1 = 1;
            switch (ui->wtoAction->radioTag()) {
            case hint_to_reserve:
            case hint_to_room:
                dcn2 = PAY_CREDIT;
                dcc2 = 1;
                break;
            case hint_to_cl:
                dcn2 = PAY_DEBIT;
                dcc2 = -1;
                break;
            }
            break;
        }
        break;
    case dc_credit:
        switch (ui->wfromAction->radioTag()) {
        case hint_from_reserve:
        case hint_from_room:
            dcn1 = PAY_DEBIT;
            dcc1 = -1;
            switch (ui->wtoAction->radioTag()) {
            case hint_to_reserve:
            case hint_to_room:
                dcn2 = PAY_CREDIT;
                dcc2 = 1;
                break;
            case hint_to_cl:
                dcn2 = PAY_DEBIT;
                dcc2 = -1;
                break;
            }
            break;
        case hint_from_cl:
            dcn1 = PAY_DEBIT;
            dcc1 = -1;
            switch (ui->wtoAction->radioTag()) {
            case hint_to_reserve:
            case hint_to_room:
                dcn2 = PAY_DEBIT;
                dcc2 = -1;
                break;
            case hint_to_cl:
                dcn2 = PAY_CREDIT;
                dcc2 = 1;
                break;
            }
            break;
        }
        break;
    }

    finalName.replace(":from", replaceFrom);
    finalName.replace(":to", replaceTo);
    if (!err.isEmpty()) {
        message_error(err);
        return;
    }
    DoubleDatabase dd;
    dd.startTransaction();
    fDoc1.fSource = VAUCHER_TRANSFER_AMOUNT_N;
    fDoc1.fItemCode = fPreferences.getDb(def_transfer_amount_id).toUInt();
    fDoc1.fGuest = guestFrom;
    fDoc1.fFinalName = finalName;
    fDoc1.fFinance = 1;
    fDoc1.fPaymentMode = PAYMENT_CREDIT;
    fDoc1.fDC = dcn1;
    fDoc1.fSign = dcc1;
    if (!fDoc1.save(dd)) {
        dd.rollback();
        message_error(fDoc1.fError);
        return;
    }

    fDoc2.fDoc = fDoc1.fId;
    fDoc2.fSource = VAUCHER_TRANSFER_AMOUNT_N;
    fDoc2.fItemCode = fPreferences.getDb(def_transfer_amount_id).toUInt();;
    fDoc2.fGuest = guestTo;
    fDoc2.fFinalName = finalName;
    fDoc2.fFinance = 1;
    fDoc2.fPaymentMode = PAYMENT_CREDIT;
    fDoc2.fDC = dcn2;
    fDoc2.fSign= dcc2;
    if (!fDoc2.save(dd)) {
        dd.rollback();
        message_error(fDoc2.fError);
        return;
    }
    fDoc1.fDoc = fDoc2.fId;
    if (!fDoc1.save(dd)) {
        dd.rollback();
        message_error(fDoc1.fError);
        return;
    }
    dd.commit();
    ui->lefromCL->clearSelector();
    ui->lefromRoomCode->clearSelector();
    ui->lefromReserve->clearSelector();
    ui->letoCL->clearSelector();
    ui->letoRoomCode->clearSelector();
    ui->letoReserve->clearSelector();
    message_info(tr("Saved"));
}

void DlgTransferAnyAmount::on_btnLog_clicked()
{
    fDoc1.showLog();
}

void DlgTransferAnyAmount::disableControls()
{
    ui->wfromAction->setEnabled(false);
    ui->wtoAction->setEnabled(false);
}
