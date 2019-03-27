#include "dlgdiscount.h"
#include "paymentmode.h"
#include "ui_dlgdiscount.h"
#include "cacheactiveroom.h"
#include "cacheinvoiceitem.h"
#include "vauchers.h"
#include "pprintvaucher.h"

#define HINT_ROOM 1

DlgDiscount::DlgDiscount(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgDiscount)
{
    ui->setupUi(this);
    ui->leInvoice->setVisible(false);
    ui->leReservation->setVisible(false);
    ui->leValue->setValidator(new QDoubleValidator(0, 999999999, 2));

    ui->leTypeCode->setSelector(this, cache(cid_invoice_item), ui->leType);
    ui->leTypeCode->setInitialValue(fPreferences.getDb(def_invoice_default_discount_id).toString());
    ui->leTypeCode->fFieldFilter["f_group"] << "4";

    ui->leRoomCode->setSelector(this, cache(cid_active_room), ui->leRoomCode, HINT_ROOM);
    ui->leCLCode->setSelector(this, cache(cid_city_ledger), ui->leCLName);

    sideChanged(true);
    fTrackControl = new TrackControl(TRACK_RESERVATION);
    fTrackControl->addWidget(ui->deDate, "Date")
            .addWidget(ui->leCLCode, "City ledger")
            .addWidget(ui->leDiscountAmount, "Discount amount")
            .addWidget(ui->leFinalAmount, "Final amount")
            .addWidget(ui->leGuest, "Guest")
            .addWidget(ui->leRoomCode, "Room")
            .addWidget(ui->rbGuest, "Guest/Company");
}

DlgDiscount::~DlgDiscount()
{
    delete ui;
}

void DlgDiscount::callback(int sel, const QString &code)
{
    switch (sel) {
    case HINT_ROOM: {
        CacheActiveRoom c;
        if (c.get(code)) {
            DoubleDatabase fDD(true, doubleDatabase);
            fDD[":invoice"] = c.fInvoice();
            ui->leInvoice->setText(c.fInvoice());
            ui->leReservation->setText(c.fCode());
            fDD.exec("select l.f_amount, r.f_amount "
                       "from m_register i "
                       "left join (select f_inv, sum(f_amountAmd*f_sign)as f_amount from m_register where f_inv=:invoice and f_side=0 and f_finance=1 and f_canceled=0 group by 1) l on l.f_inv=i.f_inv "
                       "left join (select f_inv, sum(f_amountAmd*f_sign)as f_amount from m_register where f_inv=:invoice and f_side=1 and f_finance=1 and f_canceled=0 group by 1) r on r.f_inv=i.f_inv "
                       "where i.f_inv=:invoice ");
            if (fDD.nextRow()) {
                setParams(c.fRoomCode(), fDD.getDouble(0), fDD.getDouble(1));
            } else {
                message_error(tr("No active invoice for this room"));
            }
        }
        break;
    }
    }
}

void DlgDiscount::setParams(const QString &room, double guestAmount, double companyAmount)
{
    ui->leRoomCode->setText(room);
    fGuestAmount = guestAmount;
    fCompanyAmount = companyAmount;
    CacheActiveRoom ar;
    if (!ar.get(room)) {
        message_error("Application error, contact to developer. Message: Discount dialog, set params, active room==0");
        return;
    }
    fInvoice = ar.fInvoice();
    ui->leInvoice->setText(fInvoice);
    ui->leRoomName->setText(ar.fRoomName());
    ui->leGuest->setText(ar.fGuestName());
    ui->leAmount->setText(float_str(guestAmount, 2));
    ui->leFinalAmount->setText(float_str(guestAmount, 2));
    fTrackControl->resetChanges();
}

void DlgDiscount::openVaucher(const QString &id)
{
    DlgDiscount *d = new DlgDiscount(fPreferences.getDefaultParentForMessage());
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_id"] = id;
    fDD.exec("select * from m_register where f_id=:f_id");
    if (!fDD.nextRow()) {
        message_error(tr("Cannot load voucher"));
        delete d;
        return;
    }
    d->ui->deDate->setDate(fDD.getValue("f_wdate").toDate());
    d->ui->leVaucher->setText(id);
    d->ui->leInvoice->setText(fDD.getValue("f_inv").toString());
    d->ui->leRoomCode->setText(fDD.getValue("f_room").toString());
    d->ui->leGuest->setText(fDD.getValue("f_guest").toString());
    d->ui->leCLCode->setText(fDD.getValue("f_cityledger").toString());
    d->ui->leAmount->setText(fDD.getValue("f_amountAmd").toString());
    d->ui->rbGuest->setChecked(fDD.getValue("f_rb").toInt() == 0);
    d->fTrackControl->resetChanges();
    d->exec();
    delete d;
}

void DlgDiscount::on_btnCancel_clicked()
{
    reject();
}

void DlgDiscount::on_leValue_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    countDiscount();
}

void DlgDiscount::on_rbAmount_clicked()
{
    ui->lbType->setText("AMD");
    ui->leValue->setValidator(new QDoubleValidator(0, 999999999, 2));
    countDiscount();
}

void DlgDiscount::countDiscount()
{
    if (ui->rbAmount->isChecked()) {
        ui->leFinalAmount->setDouble(ui->leAmount->asDouble() - ui->leValue->asDouble());
        ui->leDiscountAmount->setText(ui->leValue->text());
    } else {
        ui->leDiscountAmount->setDouble(ui->leAmount->asDouble() * (ui->leValue->asDouble() / 100));
        ui->leFinalAmount->setDouble(ui->leAmount->asDouble() - ui->leDiscountAmount->asDouble());
    }
}

void DlgDiscount::sideChanged(bool guest)
{
    ui->lbCityLedger->setVisible(!guest);
    ui->leCLCode->setVisible(!guest);
    ui->leCLName->setVisible(!guest);
    ui->lbGuest->setVisible(guest);
    ui->lbRoom->setVisible(guest);
    ui->leGuest->setVisible(guest);
    ui->leRoomCode->setVisible(guest);
    ui->leRoomName->setVisible(guest);
    ui->rbPercent->setEnabled(guest);
    ui->gbGuest->setEnabled(guest);
    ui->rbCompany->setEnabled(guest);
    adjustSize();
}

void DlgDiscount::on_rbPercent_clicked()
{
    ui->lbType->setText("%");
    ui->leValue->setValidator(new QDoubleValidator(0, 100, 2));
    if (ui->leValue->asDouble() > 100.0001) {
        ui->leValue->setDouble(100);
    }
    countDiscount();
}

void DlgDiscount::on_gbGuest_clicked()
{
    ui->leAmount->setDouble(fGuestAmount);
    countDiscount();
}

void DlgDiscount::on_rbCompany_clicked()
{
    ui->leAmount->setDouble(fCompanyAmount);
    countDiscount();
}

void DlgDiscount::on_btnOk_clicked()
{
    if (ui->leValue->asDouble() < 0.01) {
        message_error(tr("Empty discount value"));
        return;
    }
    if (ui->leTypeCode->asInt() == 0) {
        message_error(tr("Discount type not defined"));
        return;
    }
    if (ui->leFinalAmount->asDouble() < -0.001 && ui->rbGuest->isChecked()) {
        message_error(tr("You cannot to do this :)"));
        return;
    }
    bool isNew = true;
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.startTransaction();
    QString rid = uuidx(VAUCHER_DISCOUNT_N);
    fDD.insertId("m_register", rid);
    ui->leVaucher->setText(rid);
    fDD[":f_source"] = VAUCHER_DISCOUNT_N;
    if (isNew) {
        fDD[":f_wdate"] = WORKING_DATE;
        fDD[":f_rdate"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_user"] = WORKING_USERID;
    }
    fDD[":f_room"] = ui->rbGuest->isChecked() ?  ui->leRoomCode->text() : ui->leCLCode->text();
    fDD[":f_guest"] = ui->rbGuest->isChecked() ? ui->leGuest->text() : ui->leCLName->text();
    fDD[":f_itemCode"] = fPreferences.getDb(def_receip_vaucher_id);
    fDD[":f_finalName"] = tr("DISCOUNT S/N ") + ui->leVaucher->text();
    fDD[":f_amountAmd"] = ui->leDiscountAmount->asDouble();
    fDD[":f_amountVat"] = 0;
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = 0;
    fDD[":f_paymentMode"] = PAYMENT_DISCOUNT;
    fDD[":f_creditCard"] = 0;
    fDD[":f_cityLedger"] = ui->leCLCode->asInt();
    fDD[":f_paymentComment"] = "";
    fDD[":f_dc"] = ui->rbGuest->isChecked() ? "CREDIT" : "DEBIT";
    fDD[":f_sign"] = ui->rbGuest->isChecked() ? -1 : 1;
    fDD[":f_doc"] = "";
    fDD[":f_rec"] = "";
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD[":f_finance"] = 1;
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    if (ui->rbAmount->isChecked()) {
        fDD[":f_remarks"] = QString("Discount, %1AMD").arg(ui->leDiscountAmount->asDouble());
    } else {
        fDD[":f_remarks"] = QString("Discount, %1% (%2AMD)")
                .arg(ui->leValue->asDouble())
                .arg(ui->leDiscountAmount->asDouble());
    }
    fDD[":f_side"] = 0;
    fDD.update("m_register", where_id(ap(ui->leVaucher->text())));
    fDD.commit();

    QString msg = isNew ? "New Discount" : "Discount modified";
    msg += " " + ui->leVaucher->text();
    QString value = ui->deDate->text() + "/" + ui->leRoomCode->text()
            + "/" + ui->leGuest->text() + "/" + ui->leAmount->text()
            + "/" + ui->leCLName->text() + "/" + ui->leType->text();
    fTrackControl->fInvoice = ui->leInvoice->text();
    fTrackControl->fReservation = ui->leReservation->text();
    fTrackControl->fRecord = ui->leVaucher->text();
    fTrackControl->insert(msg, value, "");

    if (ui->rbAmount->isChecked()) {
        fTrackControl->insert("Discount", float_str(ui->leAmount->asDouble(), 2),
                              QString("%1AMD, Final amount: %2AMD").arg(ui->leValue->asDouble()).arg(ui->leFinalAmount->text()));
    } else {
        fTrackControl->insert("Discount", float_str(ui->leAmount->asDouble(), 2),
                              QString("%1%, Final amount: %2AMD").arg(ui->leValue->asDouble()).arg(ui->leFinalAmount->text()));
    }
    ui->btnOk->setEnabled(false);
    ui->btnPrint->setEnabled(true);
}

void DlgDiscount::on_rbCityLedger_clicked()
{
    sideChanged(false);
}

void DlgDiscount::on_rbGuest_clicked()
{
    sideChanged(true);
}

void DlgDiscount::on_btnPrint_clicked()
{
    if (ui->leVaucher->isEmpty()) {
        message_error(tr("Save first"));
        return;
    }
    PPrintVaucher::printVaucher(ui->leVaucher->text());
}
