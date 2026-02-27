#include "dlgpostbreakfast.h"
#include "ui_dlgpostbreakfast.h"
#include "vauchers.h"
#include "cachepaymentmode.h"
#include "dlgprinttaxsm.h"
#include "cacheinvoiceitem.h"
#include "cacheresthall.h"
#include "cacheresttable.h"
#include "cachereststore.h"
#include "cacherestfullmenu.h"
#include "cachecreditcard.h"
#include "paymentmode.h"
#include "cachetaxmap.h"

#define SEL_TABLE 1
#define SEL_DISH 2
#define HINT_PAYMENT 3
#define HINT_DISH 4
#define HINT_HALL 5


DlgPostBreakfast::DlgPostBreakfast(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgPostBreakfast)
{
    ui->setupUi(this);
    ui->lbCard->setVisible(false);
    ui->leCardCode->setVisible(false);
    ui->leCardName->setVisible(false);
    ui->lePMCode->setSelector(this, cache(cid_payment_mode), ui->lePMComment, HINT_PAYMENT);
//    ui->lePMCode->fCodeFilter << QString::number(PAYMENT_CASH)
//        << QString::number(PAYMENT_CARD)
//        << QString::number(PAYMENT_CREDIT);
    ui->lePMCode->fCodeFilter << QString::number(PAYMENT_CREDIT);
    ui->lePMCode->setInitialValue(PAYMENT_CREDIT);

    ui->leHall->setSelector(this, cache(cid_rest_hall), ui->leHallName, HINT_HALL);
    ui->leHall->fCodeFilter = fPreferences.getDb(def_rest_hall_for_reception).toString().split(",", Qt::SkipEmptyParts);

    ui->leCardCode->setSelector(this, cache(cid_credit_card), ui->leCardName);
    ui->leTable->setSelector(this, cache(cid_rest_table), ui->leTableName);

    ui->leDish->setSelector(this, cache(cid_rest_full_menu), ui->leDishName);
    ui->leDish->fFieldFilter["f_menu"] << "-1";
}

DlgPostBreakfast::~DlgPostBreakfast()
{
    delete ui;
}

void DlgPostBreakfast::callback(int sel, const QString &code)
{
    switch (sel) {
    case HINT_PAYMENT: {
        CachePaymentMode ci;
        ui->lbCard->setVisible(false);
        ui->leCardCode->setVisible(false);
        ui->leCardName->setVisible(false);
        if (ci.get(code)) {
            if (ci.fCode().toInt() == PAYMENT_CARD) {
                ui->lbCard->setVisible(true);
                ui->leCardCode->setVisible(true);
                ui->leCardName->setVisible(true);
            }
        }
        break;
    }
    case HINT_DISH: {
        CacheRestFullMenu ci;
        if (ci.get(code)) {
            ui->leDish->setText(ci.fCode());
            ui->leDishName->setText(ci.fName());
            ui->lePrice->setDouble(ci.fPrice());
            ui->leStore->fHiddenText = QString::number(ci.fStore());
            CacheRestStore cs;
            if (cs.get(ci.fStore())) {
                ui->leStore->setText(cs.fName());
            }
        }
        break;
    }
    case HINT_HALL: {
        CacheRestHall ci;
        ci.get(code);
        if (ui->leHall->asInt() > 0) {
            ui->leTable->fFieldFilter["f_hall"] << ui->leHall->text();
            ui->leDish->fFieldFilter["f_menu"] << ci.fDefaultMenu();
        } else {
            ui->leTable->fFieldFilter.clear();
            ui->leDish->fFieldFilter.clear();
        }
        break;
    }
    }
}

bool DlgPostBreakfast::postBreakfast(const QString &invoice, POST_TYPE pt)
{
    DlgPostBreakfast *d = new DlgPostBreakfast(fPreferences.getDefaultParentForMessage());
    d->ui->leInvoice->setText(invoice);
    DoubleDatabase fDD;
    fDD[":f_invoice"] = invoice;
    fDD.exec("select r.f_id, r.f_room, g.guest from f_reservation r left join guests g on r.f_guest=g.f_id where f_invoice=:f_invoice");
    if (fDD.nextRow()) {
        d->ui->leRes->setText(fDD.getValue("f_id").toString());
        d->ui->leRoom->setText(fDD.getValue("f_room").toString());
        d->ui->leGuest->setText(fDD.getValue("guest").toString());
    }
    switch (pt) {
    case ptBreakfast: {
        d->ui->leHall->setInitialValue(fPreferences.getDb(def_breakfast_default_hall).toInt());
        d->ui->leTable->setInitialValue(fPreferences.getDb(def_breakfast_default_table).toInt());
        d->ui->leDish->setInitialValue(fPreferences.getDb(def_breakfast_default_dish).toInt());

        CacheRestHall ch;
        if (ch.get(d->ui->leHall->text())) {
            d->ui->leDish->fFieldFilter["f_menu"] << ch.fDefaultMenu();
        }
        CacheRestFullMenu ci;
        if (ci.get(d->ui->leDish->text())) {
            d->ui->leStore->fHiddenText = QString::number(ci.fStore());
            d->ui->leDishName->setText(ci.fName());
            d->ui->lePrice->setDouble(ci.fPrice());
            CacheRestStore cs;
            if (cs.get(ci.fStore())) {
                d->ui->leStore->setText(cs.fName());
            }
        }
        d->ui->leQty->setFocus();
        break;
    }
    case ptMinibar: {
        d->ui->leHall->setInitialValue(fPreferences.getDb(def_minibar_default_hall).toInt());
        d->ui->leTable->setInitialValue(fPreferences.getDb(def_minibar_default_table).toInt());
        d->ui->leDish->setInitialValue(fPreferences.getDb(def_minibar_default_dish).toInt());

        CacheRestFullMenu ci;
        if (ci.get(d->ui->leDish->text())) {
            d->ui->leStore->fHiddenText = QString::number(ci.fStore());
            d->ui->leDishName->setText(ci.fName());
            d->ui->lePrice->setDouble(ci.fPrice());
            CacheRestStore cs;
            if (cs.get(ci.fStore())) {
                d->ui->leStore->setText(cs.fName());
            }
        }
        d->ui->leQty->setFocus();
        break;
    }
    default:
        break;
    }
    bool result = d->exec() == QDialog::Accepted;
    delete d;
    return result;
}

void DlgPostBreakfast::on_btnCancel_clicked()
{
    reject();
}

void DlgPostBreakfast::on_btnSave_clicked()
{
    if (ui->leHall->asInt() == 0) {
        message_error(tr("Hall must be selected"));
        return;
    }
    if (ui->leTable->asInt() == 0) {
        message_error(tr("Table must be selected"));
        return;
    }
    if (ui->leDish->asInt() == 0) {
        message_error(tr("Dish must be selected"));
        return;
    }
    if (ui->leQty->asDouble() < 0.01) {
        message_error(tr("Invalid quantity of the guests"));
        return;
    }
    if (ui->leAmount->asDouble() < 0.01) {
        message_error(tr("Invalid amount"));
        return;
    }
    if (ui->lePMCode->asInt() == 0) {
        message_error(tr("Payment mode is not selected"));
        return;
    }
    if (ui->lePMCode->asInt() == PAYMENT_CARD && ui->leCardCode->asInt() == 0) {
        message_error(tr("Card is not selected"));
        return;
    }
    bool isNew = false;
    DoubleDatabase fDD;
    fDD.startTransaction();
    if (ui->leVoucher->isEmpty()) {
        isNew = true;
        QString rid = uuidx(VAUCHER_POINT_SALE_N);
        fDD.insertId("m_register", rid);
        ui->leVoucher->setText(rid);
    }
    fDD[":f_source"] = VAUCHER_POINT_SALE_N;
    if (isNew) {
        fDD[":f_wdate"] = ui->deDate->date();
        fDD[":f_rdate"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_user"] = WORKING_USERID;
    }
    fDD[":f_room"] = ui->leRoom->text();
    fDD[":f_guest"] = ui->leGuest->text();
    fDD[":f_itemCode"] = fPreferences.getDb(def_auto_breakfast_id).toInt();
    fDD[":f_finalName"] = ui->leHallName->text() + " S/N " + ui->leVoucher->text();
    fDD[":f_amountAmd"] = ui->leAmount->asDouble();
    fDD[":f_amountVat"] = Utils::countVATAmount(ui->leAmount->asDouble(), VAT_INCLUDED);
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = 0;
    fDD[":f_paymentMode"] = PAYMENT_ROOM;
    fDD[":f_creditCard"] = 0;
    fDD[":f_cityLedger"] = 0;
    fDD[":f_paymentComment"] = ui->leRoom->text() + "," + ui->leGuest->text();
    fDD[":f_dc"] = "DEBIT";
    fDD[":f_sign"] = 1;
    fDD[":f_doc"] = "";
    fDD[":f_rec"] = "";
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD[":f_finance"] = 1;
    fDD[":f_remarks"] = "";
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    fDD[":f_side"] = 0;
    fDD[":f_rb"] = 0;
    fDD[":f_cash"] = ui->lePMCode->asInt() == PAYMENT_CREDIT ? 0 : 1;
    fDD.update("m_register", where_id(ap(ui->leVoucher->text())));

    QString headerId = ui->leVoucher->text();
    fDD[":f_id"] = headerId;
    fDD.insert("o_header");
    fDD[":f_state"] = ORDER_STATE_CLOSED;
    fDD[":f_hall"] = ui->leHall->asInt();
    fDD[":f_table"] = ui->leTable->asInt();
    fDD[":f_staff"] = WORKING_USERID;
    fDD[":f_dateOpen"] = QDateTime::currentDateTime();
    fDD[":f_dateClose"] = QDateTime::currentDateTime();
    fDD[":f_dateCash"] = ui->deDate->date();
    fDD[":f_paymentMode"] = PAYMENT_ROOM;
    fDD[":f_paymentModeComment"] = ui->leRoom->text() + "," + ui->leGuest->text();
    fDD[":f_comment"] = "";
    fDD[":f_cityLedger"] = 0;
    fDD[":f_reservation"] = "";
    fDD[":f_complex"] = 0;
    fDD[":f_print"] = 0;
    fDD[":f_tax"] = 0;
    fDD[":f_roomComment"] = ui->leRoom->text() + ", " + ui->leGuest->text();
    fDD[":f"] = 0;
    fDD[":f_total"] = ui->leAmount->asDouble();
    fDD.update("o_header", where_id(ap(headerId)));

    CacheRestFullMenu rf;
    rf.get(ui->leDish->text());
    QString dishId = uuidx("DR");
    fDD[":f_id"] = dishId;
    fDD.insert("o_dish");
    fDD[":f_header"] = headerId;
    fDD[":f_state"] = DISH_STATE_READY;
    fDD[":f_dish"] = rf.fDishCode();
    fDD[":f_qty"] = ui->leQty->asDouble();
    fDD[":f_qtyPrint"] = ui->leQty->asDouble();
    fDD[":f_price"] = ui->lePrice->asDouble();
    fDD[":f_svcValue"] = 0;
    fDD[":f_svcAmount"] = 0;
    fDD[":f_dctValue"] = 0;
    fDD[":f_dctAmount"] = 0;
    fDD[":f_total"] = ui->leAmount->asDouble();
    fDD[":f_totalUSD"] = def_usd;
    fDD[":f_print1"] = "";
    fDD[":f_print2"] = "";
    fDD[":f_store"] = ui->leStore->fHiddenText.toInt();
    fDD[":f_comment"] = "";
    fDD[":f_staff"] = WORKING_USERID;
    fDD[":f_complex"] = 0;
    fDD[":f_complexId"] = 0;
    fDD[":f_adgt"] = ui->leDish->fHiddenText;
    fDD[":f_complexRec"] = "";
    fDD[":f_cancelUser"] = 0;
    fDD.update("o_dish", where_id(ap(dishId)));

    if (ui->lePMCode->asInt() == PAYMENT_CASH || ui->lePMCode->asInt() == PAYMENT_CARD) {
        QString voucherPay = uuidx(VAUCHER_RECEIPT_N);
        fDD.insertId("m_register", voucherPay);
        if (isNew) {
            fDD[":f_wdate"] = ui->deDate->date();
            fDD[":f_rdate"] = QDate::currentDate();
            fDD[":f_time"] = QTime::currentTime();
            fDD[":f_user"] = WORKING_USERID;
        }
        fDD[":f_source"] = VAUCHER_RECEIPT_N;
        fDD[":f_room"] = ui->leRoom->text();
        fDD[":f_guest"] = ui->leGuest->text();
        fDD[":f_itemCode"] = fPreferences.getDb(def_auto_breakfast_id).toInt();
        fDD[":f_finalName"] = vaucherPaymentName(ui->lePMCode->asInt(),
                                                     ui->leCardCode->text(),
                                                     "");
        fDD[":f_amountAmd"] = ui->leAmount->asDouble();
        fDD[":f_amountVat"] = Utils::countVATAmount(ui->leAmount->asDouble(), VAT_INCLUDED);
        fDD[":f_amountUsd"] = def_usd;
        fDD[":f_fiscal"] = 0;
        fDD[":f_paymentMode"] = ui->lePMCode->asInt();
        fDD[":f_creditCard"] = 0;
        fDD[":f_cityLedger"] = 0;
        fDD[":f_paymentComment"] = vaucherPaymentName(ui->lePMCode->asInt(),
                                                          ui->leCardCode->text(),
                                                          "");
        fDD[":f_dc"] = "CREDIT";
        fDD[":f_sign"] = -1;
        fDD[":f_doc"] = "";
        fDD[":f_rec"] = "";
        fDD[":f_inv"] = ui->leInvoice->text();
        fDD[":f_finance"] = 1;
        fDD[":f_remarks"] = "";
        fDD[":f_canceled"] = 0;
        fDD[":f_cancelReason"] = "";
        fDD[":f_side"] = 0;
        fDD[":f_rb"] = 0;
        fDD[":f_cash"] = ui->lePMCode->asInt() == PAYMENT_CREDIT ? 0 : 1;
        fDD.update("m_register", where_id(ap(voucherPay)));
    }

    fDD.commit();
    ui->btnSave->setEnabled(false);
    message_info(tr("Saved"));
}

void DlgPostBreakfast::on_btnPrintTax_clicked()
{
    if (ui->leTax->asInt() > 0) {
        message_error(tr("Tax already printed"));
        return;
    }
    CacheInvoiceItem ii;
    if (!ii.get(fPreferences.getDb(def_auto_breakfast_id).toInt())) {
        message_error(tr("Application error. Contact to developer. Message DlgPostBreakfast invoice item = 0"));
        return;
    }
    CacheTaxMap cm;
    if (!cm.get(ii.fCode())) {
            return;
    }

    DlgPrintTaxSM dpt(cm.fTax(), this);
    dpt.addGoods(ii.fVatDept(),
                 ii.fAdgt(),
                 ii.fCode(),
                 ii.fTaxName(),
                 ui->lePrice->asDouble(),
                 ui->leQty->asDouble());
    dpt.fOrder = ui->leVoucher->text();
    dpt.fCardAmount = 0;
    dpt.fPrepaid = 0;

    int result = dpt.exec();
    if (result == TAX_OK) {
        DoubleDatabase fDD;
        fDD[":f_fiscal"] = dpt.fTaxCode;
        fDD.update("m_register", where_id(ap(ui->leVoucher->text())));
        ui->leTax->setInt(dpt.fTaxCode);

        fDD[":f_vaucher"] = ui->leVoucher->text();
        fDD[":f_invoice"] = ui->leInvoice->text();
        fDD[":f_date"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_name"] = ii.fName();
        fDD[":f_amountCash"] = ui->leAmount->asDouble();
        fDD[":f_amountCard"] = 0;
        fDD[":f_amountPrepaid"] = 0;
        fDD[":f_user"] = WORKING_USERID;
        fDD[":f_comp"] = HOSTNAME;
        fDD.insert("m_tax_history");
        return;
    }
}

void DlgPostBreakfast::on_leQty_textChanged(const QString &arg1)
{
    ui->leAmount->setDouble(arg1.toDouble() * ui->lePrice->asDouble());
}

void DlgPostBreakfast::on_leAmount_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
}
