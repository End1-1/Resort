#include "dlgdiscount.h"
#include "paymentmode.h"
#include "ui_dlgdiscount.h"
#include "cacheactiveroom.h"
#include "cacheinvoiceitem.h"
#include "vauchers.h"
#include "pprintvaucher.h"
#include "dlgtracking.h"

static const int HINT_ROOM = 1;
static const int HINT_CL = 2;

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
    ui->leCLCode->setSelector(this, cache(cid_city_ledger), ui->leCLName, HINT_CL);
    sideChanged(true);
    fTrackControl = new TrackControl(TRACK_RESERVATION);
    fTrackControl->addWidget(ui->deDate, "Date")
    .addWidget(ui->leCLCode, "City ledger")
    .addWidget(ui->leValue, "Discount amount")
    .addWidget(ui->leFinalAmount, "Final amount")
    .addWidget(ui->leGuest, "Guest")
    .addWidget(ui->leRoomCode, "Room")
    .addWidget(ui->rbGuest, "Guest/Company")
    .addWidget(ui->peRemarks, "Remarks");
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
                DoubleDatabase fDD;
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
        case HINT_CL: {
            DoubleDatabase dd;
            dd[":f_cityledger"] = ui->leCLCode->asInt();
            dd.exec("select sum(m.f_amountamd*f_sign) from m_register m \
                where f_cityLedger=:f_cityledger and f_canceled=0 and f_finance=1 ");
            if (dd.nextRow()) {
                ui->leAmount->setDouble(dd.getDouble(0));
            } else {
                ui->leAmount->setDouble(0);
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
    if (ui->leVaucher->isEmpty()) {
        ui->leAmount->setText(float_str(guestAmount, 2));
    } else {
        ui->leAmount->setText(float_str(guestAmount + ui->leValue->asDouble(), 2));
    }
    ui->leFinalAmount->setText(float_str(guestAmount, 2));
    fTrackControl->resetChanges();
}

void DlgDiscount::openVaucher(const QString &id)
{
    DlgDiscount *d = new DlgDiscount(fPreferences.getDefaultParentForMessage());
    DoubleDatabase fDD;
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
    d->ui->leGuest->setText(fDD.getValue("f_guest").toString());
    d->ui->leCLCode->setText(fDD.getValue("f_cityledger").toString());
    d->ui->leValue->setText(fDD.getValue("f_amountAmd").toString());
    d->ui->leRoomCode->setInitialValue(fDD.getValue("f_room").toString());
    d->ui->rbGuest->setChecked(fDD.getValue("f_rb").toInt() == 0);
    d->ui->peRemarks->setPlainText(fDD.getValue("f_remarks").toString());
    d->fTrackControl->resetChanges();
    d->on_leValue_textChanged(d->ui->leValue->text());
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

void DlgDiscount::countDiscount()
{
    ui->leFinalAmount->setDouble(ui->leAmount->asDouble() - ui->leValue->asDouble());
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
    ui->gbGuest->setEnabled(guest);
    ui->rbCompany->setEnabled(guest);
    adjustSize();
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
    // may be this is remove
    //    if (ui->leFinalAmount->asDouble() < -0.001 && ui->rbGuest->isChecked()) {
    //        message_error(tr("You cannot to do this :)"));
    //        return;
    //    }
    bool isNew = true;
    DoubleDatabase fDD;
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
    fDD[":f_itemCode"] = fPreferences.getDb(def_invoice_default_discount_id);
    fDD[":f_finalName"] = tr("DISCOUNT S/N ") + ui->leVaucher->text() + " " + QString("%1AMD").arg(ui->leValue->asDouble());
    fDD[":f_amountAmd"] = ui->leValue->asDouble();
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
    fDD[":f_remarks"] = ui->peRemarks->toPlainText();
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
    fTrackControl->insert("Discount", float_str(ui->leAmount->asDouble(), 2),
                          QString("%1AMD, Final amount: %2AMD").arg(ui->leValue->asDouble()).arg(ui->leFinalAmount->text()));
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

void DlgDiscount::on_btnLog_clicked()
{
    DlgTracking::showTracking(ui->leVaucher->text());
}
