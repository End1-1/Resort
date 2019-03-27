#include "dlgpostingcharges.h"
#include "ui_dlgpostingcharges.h"
#include "printtax.h"
#include "pprintscene.h"
#include "pprintpreview.h"
#include "cacheroom.h"
#include "ptextrect.h"
#include "cacheinvoiceitem.h"
#include "pimage.h"
#include "vauchers.h"
#include "dlgprinttaxsm.h"
#include "pprintvaucher.h"
#include "cacheroomarrangment.h"
#include "cachepaymentmode.h"
#include "cachecityledger.h"
#include "cachecreditcard.h"
#include "cacheactiveroom.h"
#include "paymentmode.h"
#include <QDir>
#include <QProcess>

#define HINT_INVOICE_ITEM 1
#define HINT_PAYMENT_MODE 2
#define HINT_ROOM 3

DlgPostingCharges::DlgPostingCharges(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgPostingCharges)
{
    ui->setupUi(this);
    DoubleDatabase fDD(true, doubleDatabase);
    ui->deDate->setDate(WORKING_DATE);
    ui->leAmount->setValidator(new QDoubleValidator(0, 999999, 2));
    ui->leTaxCash->setValidator(new QDoubleValidator(0, 999999999, 2));
    ui->leTaxCard->setValidator(new QDoubleValidator(0, 99999999, 2));
    ui->leTaxPre->setValidator(new QDoubleValidator(0, 99999999, 2));
    ui->leItemCode->setSelector(this, cache(cid_invoice_item), ui->leItemName, HINT_INVOICE_ITEM);
    ui->leItemCode->fFieldFilter["f_group"] << "1";
    if (WORKING_USERGROUP != 1) {
        fDD[":f_auto"] = 1;
        fDD[":f_group"] = 1;
        fDD.exec("select f_id from f_invoice_item where f_auto=:f_auto and f_group=:f_group");
        while (fDD.nextRow()) {
            ui->leItemCode->fCodeExcludeFilter << fDD.getString(0);
        }
    }
    ui->leRoomCode->setSelector(this, cache(cid_active_room), ui->leRoomName, HINT_ROOM);
    ui->leCityCode->setSelector(this, cache(cid_city_ledger), ui->leCityName);
    ui->lePayCode->setSelector(this, cache(cid_payment_mode), ui->lePayName, HINT_PAYMENT_MODE);
    ui->lePayCode->fCodeFilter << QString::number(PAYMENT_CASH)
                               << QString::number(PAYMENT_CARD)
                               << QString::number(PAYMENT_BANK)
                               << QString::number(PAYMENT_CREDIT);
    ui->leCardCode->setSelector(this, cache(cid_credit_card), ui->leCardName);
    ui->cbVAT->setIndexForData(VAT_INCLUDED);
    fTrackControl = new TrackControl(TRACK_RESERVATION);
    on_rbRoom_clicked(true);
    ui->wPayment->setVisible(false);
    ui->lePayCode->setInitialValue(PAYMENT_CREDIT);
}

DlgPostingCharges::~DlgPostingCharges()
{
    delete ui;
}

void DlgPostingCharges::callback(int sel, const QString &code)
{
    switch (sel) {
    case HINT_INVOICE_ITEM: {
        CacheInvoiceItem c;
        if (c.get(code)) {
            if (c.fNoManual()) {
                if (!r__(cr__super_correction)) {
                    message_error(tr("You cannot use this name for manual charge"));
                    ui->leItemCode->clear();
                    ui->leItemName->clear();
                    return;
                }
            }
            ui->leVaucher->setText(c.fVaucher());
        }
        break;
    }
    case HINT_PAYMENT_MODE: {
        CachePaymentMode c;
        if (c.get(code)) {
            ui->leCardCode->setEnabled(c.fCode().toInt() == PAYMENT_CARD);
        }
        break;
    }
    case HINT_ROOM: {
        CacheActiveRoom c;
        if (c.get(code)) {
            ui->leRoomCode->setText(c.fRoomCode());
            ui->leRoomName->setText(c.fRoomName());
            ui->leGuest->setText(c.fGuestName());
            ui->leInvoice->setText(c.fInvoice());
            fTrackControl->fInvoice = c.fInvoice();
            fTrackControl->fReservation = c.fCode();
        } else {
            ui->leRoomCode->clear();
            ui->leRoomName->clear();
            ui->leGuest->clear();
            ui->leInvoice->clear();
        }
        break;
    }
    }
}

void DlgPostingCharges::loadVaucher(const QString &id)
{
    ui->leVaucherId->setText(id);
    ui->grType->setVisible(false);
    adjustSize();
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_id"] = id;
    fDD.exec("select f_source, f_room, f_guest, f_cityLedger, f_amountAmd, f_amountVat, f_inv, f_itemCode, "
               "f_finalName, f_remarks, f_doc, f_side, f_wdate, f_rb, f_time, f_fiscal "
               "from m_register m "
               "where f_id=:f_id");
    if (fDD.rowCount() == 0) {
        message_error(tr("Invalid vaucher id. Please, contact to application developer."));
        accept();
        return;
    } else {
        int c = 0;
        QList<QList<QVariant> > &fDbRows = fDD.fDbRows;
        ui->leVaucher->setText(fDbRows.at(0).at(c++).toString());
        ui->leRoomCode->setText(fDbRows.at(0).at(c++).toString());
        ui->leGuest->setText(fDbRows.at(0).at(c++).toString());
        ui->leCityCode->setText(fDbRows.at(0).at(c++).toString());
        ui->leAmount->setText(fDbRows.at(0).at(c++).toString());
        ui->leAmountVat->setText(fDbRows.at(0).at(c++).toString());
        ui->leInvoice->setText(fDbRows.at(0).at(c++).toString());
        ui->leItemCode->setText(fDbRows.at(0).at(c++).toString());
        ui->leItemName->setText(fDbRows.at(0).at(c++).toString());
        ui->teRemark->setPlainText(fDbRows.at(0).at(c++).toString());
        //fDoc = fDbRows.at(0).at(c++).toInt();
        c++;
        ui->chPayByComp->setChecked(fDbRows.at(0).at(c).toBool());
        ui->chPayGuest->setChecked(!fDbRows.at(0).at(c++).toBool());
        ui->deDate->setDate(fDbRows.at(0).at(c++).toDate());
        switch (fDbRows.at(0).at(c++).toInt()) {
        case 0:
            ui->rbRoom->setChecked(true);
            break;
        case 1:
            ui->rbDirect->setChecked(true);
            break;
        case 2:
            ui->rbCity->setChecked(true);
            break;
        }
        ui->teTime->setTime(fDbRows.at(0).at(c++).toTime());
        ui->leTaxCode->setText(fDbRows.at(0).at(c++).toString());

        fDD[":f_invoice"] = ui->leInvoice->text();
        fDD.exec("select rm.f_short, concat(g.f_firstName, ' ', g.f_lastName) "
                   "from f_reservation r "
                   "left join f_room rm on rm.f_id=r.f_room "
                   "left join f_guests g on g.f_id=r.f_guest "
                   "where r.f_invoice=:f_invoice");
        if (fDD.rowCount() > 0) {
            ui->leRoomName->setText(fDbRows.at(0).at(0).toString());
        }
    }

    if (ui->leAmountVat->asDouble() < 0.01) {
        ui->cbVAT->setIndexForData(VAT_NOVAT);
    }

    ui->leItemCode->setReadOnly(!r__(cr__super_correction));
    ui->leRoomCode->setReadOnly(true);
    ui->leItemName->setReadOnly(false);
    CacheCityLedger cl;
    if (cl.get(ui->leCityCode->text())) {
        ui->leCityName->setText(cl.fName());
    }
    ui->btnOk->setVisible(r__(cr__super_correction));
    if (r__(cr__super_correction)) {
        ui->deDate->setReadOnly(false);
    }
    ui->btnPrint->setEnabled(true);
}

void DlgPostingCharges::setRoom(const QString &room)
{
    CacheActiveRoom ci;
    if (ci.get(room)) {
        ui->leRoomCode->setText(room);
        ui->leRoomName->setText(ci.fRoomName());
        ui->leInvoice->setText(ci.fInvoice());
        ui->leGuest->setText(ci.fGuestName());
        ui->leItemCode->setFocus();
        fTrackControl->resetChanges();
        fTrackControl->fInvoice = ci.fInvoice();
        fTrackControl->fReservation = ci.fCode();
        DoubleDatabase fDD(true, doubleDatabase);
        fDD[":f_reservation"] = ci.fCode();
        fDD.exec("select f_itemId from f_reservation_item_side where f_reservation=:f_reservation");
        while (fDD.nextRow()) {
            fCompanySide.append(fDD.getString(0));
        }
        ui->rbCity->setEnabled(false);
        ui->rbDirect->setEnabled(false);
        fDD[":f_id"] = ci.fCode();
        fDD.exec("select * from f_reservation where f_id=:f_id");
        fDD.nextRow();
        ui->cbVAT->setIndexForData(fDD.getInt("f_vatMode"));
    }
}

void DlgPostingCharges::setInvoice(const QString &id)
{
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_invoice"] = id;
    fDD.exec("select r.f_room, g.guest, f_vatMode from "
              "f_reservation r "
              "left join guests g on g.f_id=r.f_guest "
              "where f_invoice=:f_invoice ");
    if (!fDD.nextRow()) {
        message_error(tr("Cannot set invoice"));
        return;
    }
    ui->leRoomCode->setText(fDD.getString(0));
    ui->leRoomName->setText(fDD.getString(0));
    ui->leGuest->setText(fDD.getString(1));
    ui->leInvoice->setText(id);
    ui->cbVAT->setIndexForData(fDD.getInt(2));
    fTrackControl->fInvoice = ui->leInvoice->text();
}

void DlgPostingCharges::setSaleItem(const QString &code, bool disableChanges)
{
    CacheInvoiceItem c;
    if (c.get(code)) {
        if (c.fNoManual()) {
            message_error(tr("You cannot use this name for manual charge"));
            ui->leItemCode->clear();
            ui->leItemName->clear();
            return;
        }
        ui->leItemCode->setText(c.fCode());
        ui->leItemName->setText(c.fName());
        ui->leItemCode->setEnabled(!disableChanges);
    } else {
        message_error(tr("Item with code %1 not exist").arg(code));
    }
}

void DlgPostingCharges::on_btnCancel_clicked()
{
    reject();
}

void DlgPostingCharges::on_btnOk_clicked()
{
    if (ui->rbDirect->isChecked()) {
        if (ui->lePayCode->asInt() == 0) {
            message_error(tr("The mode of payment not selected"));
            return;
        }
    } else {
        ui->lePayCode->setInitialValue(PAYMENT_CREDIT);
    }
    if (ui->lePayCode->asInt() == 0) {
        message_error(tr("The mode of payment not selected. Contact to Administrator"));
        return;
    }
    if (ui->lePayCode->asInt() == PAYMENT_CARD) {
        if (ui->leCardCode->asInt() == 0) {
            message_error(tr("The name of credit card not selected"));
            return;
        }
    }
    QString dc = "DEBIT";
    int rb = 0;
    int sign = 1;
    if (ui->rbDirect->isChecked()) {
        rb = 1;
    }
    if (ui->rbCity->isChecked()) {
        dc = "CREDIT";
        sign = -1;
        rb = 2;
    }
    if (ui->leVaucher->text().isEmpty()) {
        message_error(tr("Voucher code is missing. Contact with administrator."));
        return;
    }
    bool isNew = false;
    QString appendix;
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.startTransaction();
    if (ui->leVaucherId->isEmpty()) {
        isNew = true;
        QString rid = uuidx(ui->leVaucher->text());
        fDD.insertId("m_register", rid);
        if (ui->leVaucher->text() == VAUCHER_ROOMING_N) {
            switch (message_yesnocancel(tr("The date will append to the name.<br>Click YES to use current working date<br>Click NO - to use previouse working date"))) {
            case RESULT_YES:
                appendix = " " + fPreferences.getDb(def_working_day).toString();
                break;
            case RESULT_NO:
                appendix = " " + WORKING_DATE.addDays(-1).toString(def_date_format);
                break;
            }
            fDD[":f_invoice"] = ui->leInvoice->text();
            fDD.exec("select f_arrangement from f_reservation where f_invoice=:f_invoice");
            if (fDD.nextRow()) {
                CacheRoomArrangment ra;
                if (ra.get(fDD.getString(0))) {
                    appendix += " - " + ra.fName();
                }
            }
        }
        ui->leVaucherId->setText(rid);
    }
    fDD[":f_source"] = ui->leVaucher->text();
    if (isNew) {
        fDD[":f_wdate"] = ui->deDate->date();
        fDD[":f_rdate"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_user"] = WORKING_USERID;
    }
    fDD[":f_room"] = (ui->rbRoom->isChecked() ? ui->leRoomCode->text() : "-");
    fDD[":f_guest"] = (ui->rbRoom->isChecked() ? ui->leGuest->text() : (ui->rbDirect->isChecked() ? "-" : ui->leCityName->text()));
    fDD[":f_itemCode"] = ui->leItemCode->text();
    fDD[":f_finalName"] = ui->leItemName->text() + appendix;
    fDD[":f_amountAmd"] = ui->leAmount->asDouble();
    fDD[":f_amountVat"] = ui->leAmountVat->asDouble();
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = 0;
    fDD[":f_paymentMode"] = ui->lePayCode->asInt();
    fDD[":f_creditCard"] = ui->leCardCode->asInt();
    fDD[":f_cityLedger"] = ui->leCityCode->asInt();
    fDD[":f_paymentComment"] = vaucherPaymentName(ui->lePayCode->asInt(), ui->leCardCode->text(), ui->leCityName->text());
    fDD[":f_dc"] = dc;
    fDD[":f_sign"] = sign;
    fDD[":f_doc"] = "";
    fDD[":f_rec"] = "";
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD[":f_finance"] = 1;
    fDD[":f_remarks"] = ui->teRemark->toPlainText();
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    fDD[":f_side"] = (int) ui->chPayByComp->isChecked();
    fDD[":f_rb"] = rb;
    fDD[":f_cash"] = ui->rbDirect->isChecked() ? 1 : 0;
    fDD.update("m_register", where_id(ap(ui->leVaucherId->text())));
    fDD.commit();

    QString msg = isNew ? "New postcharge" : "Postcharge modified";
    msg += " " + ui->leVaucher->text();
    QString value = ui->deDate->text() + "/" + ui->leRoomCode->text()
            + "/" + ui->leGuest->text() + "/" + ui->leAmount->text()
            + "/" + ui->leCityName->text() + "/" + ui->leItemName->text() + appendix
            + "/" + ui->leAmount->text();
    fTrackControl->fRecord = ui->leVaucherId->text();
    fTrackControl->insert(msg, value, "");

    if (ui->rbRoom->isChecked()) {
        fDD[":f_invoice"] = ui->leInvoice->text();
        fDD[":f_used"] = 0;
        fDD[":f_amount"] = ui->leAmount->asDouble();
        fDD.exec("select f_id, f_amount, f_item, f_source from m_free_tax "
                   "where f_invoice=:f_invoice and f_amount=:f_amount and f_used=:f_used ");
        bool done = false;
        while (fDD.nextRow()) {
            if (fDD.getInt(2) == ui->leItemCode->asInt()) {
                fDD[":f_fiscal"] = 1;
                fDD[":f_usedTaxId"] = fDD.getInt(0);
                fDD.update("m_register", where_id(ap(ui->leVaucherId->text())));
                fDD[":f_used"] = 1;
                fDD.update("m_free_tax", where_id(fDD.getInt(0)));
                done = true;
                break;
            }
        }
        if (!done) {
            while (fDD.nextRow()) {
                if (ui->leVaucher->text() != "RM") {
                    break;
                }
                if (fDD.getString(3) == ui->leVaucher->text()) {
                    fDD[":f_fiscal"] = 1;
                    fDD[":f_usedTaxId"] = fDD.getInt(0);
                    fDD.update("m_register", where_id(ap(ui->leVaucherId->text())));
                    fDD[":f_used"] = 1;
                    fDD.update("m_free_tax", where_id(fDD.getInt(0)));
                    done = true;
                    break;
                }
            }
        }
    }

    ui->btnOk->setEnabled(false);
    ui->btnPrint->setEnabled(true);
    ui->leItemCode->setReadOnly(true);
    ui->leAmount->setReadOnly(true);
    ui->cbVAT->setEnabled(false);
    ui->teRemark->setReadOnly(true);
}

void DlgPostingCharges::on_leRoomCode_returnPressed()
{
    CacheActiveRoom ci;
    if (ci.get(ui->leRoomCode->text())) {
        ui->leRoomName->setText(ci.fRoomName());
        ui->leInvoice->setText(ci.fInvoice());
        ui->leGuest->setText(ci.fGuestName());
    }
}

void DlgPostingCharges::on_leItemCode_returnPressed()
{
    CacheInvoiceItem ci;
    if (ci.get(ui->leItemCode->text())) {
        ui->leItemName->setText(ci.fName());
        if (fCompanySide.contains(ci.fCode())) {
            ui->chPayByComp->setChecked(true);
            ui->chPayGuest->setChecked(false);
        } else {
            ui->chPayByComp->setChecked(false);
            ui->chPayGuest->setChecked(true);
        }
    }
}

void DlgPostingCharges::on_leAmount_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1);
    switch (ui->cbVAT->asInt()) {
    case VAT_NOVAT:
        ui->leAmountVat->clear();
        break;
    case VAT_INCLUDED:
        ui->leAmountVat->setDouble(ui->leAmount->asDouble() - (ui->leAmount->asDouble() / ((20.0 / 100.0) + 1)));
        break;
    case VAT_WITHOUT:
        ui->leAmountVat->setDouble(ui->leAmount->asDouble() * (20.0 / 100.0));
        break;
    }
}

void DlgPostingCharges::on_cbVAT_currentIndexChanged(int index)
{
    Q_UNUSED(index)
    on_leAmount_textEdited("");
}

void DlgPostingCharges::on_chPayGuest_clicked(bool checked)
{
    ui->chPayByComp->setChecked(!checked);
}

void DlgPostingCharges::on_chPayByComp_clicked(bool checked)
{
    ui->chPayGuest->setChecked(!checked);
}

void DlgPostingCharges::on_rbRoom_clicked(bool checked)
{
    ui->grRoom->setVisible(checked);
    ui->grCity->setVisible(!checked);
    ui->chPayGuest->setEnabled(checked);
    ui->chPayByComp->setEnabled(checked);
    disablePayment();
    adjustSize();
}

void DlgPostingCharges::on_rbDirect_clicked(bool checked)
{
    ui->grRoom->setVisible(!checked);
    ui->grCity->setVisible(!checked);
    ui->chPayGuest->setEnabled(checked);
    ui->chPayGuest->setChecked(true);
    ui->chPayByComp->setEnabled(!checked);
    enablePayment();
    adjustSize();
}

void DlgPostingCharges::on_rbCity_clicked(bool checked)
{
    ui->grRoom->setVisible(!checked);
    ui->grCity->setVisible(checked);
    ui->chPayGuest->setEnabled(!checked);
    ui->chPayByComp->setEnabled(checked);
    ui->chPayByComp->setChecked(true);
    disablePayment();
    adjustSize();
}

void DlgPostingCharges::on_btnPrint_clicked()
{
    PPrintVaucher::printVaucher(ui->leVaucherId->text());
}

void DlgPostingCharges::on_btnPrintTax_clicked()
{
    DoubleDatabase fDD(true, doubleDatabase);
    if (ui->leVaucherId->text().isEmpty()) {
        message_error(tr("Save first"));
        return;
    }
    if (ui->leTaxCode->asInt() > 0) {
        message_error(tr("Already printed"));
        return;
    }
    CacheInvoiceItem ii;
    if (!ii.get(ui->leItemCode->text())) {
        message_error(tr("Application error. Contact to developer. Message DlgPostCharge invoice item = 0"));
        return;
    }
    DlgPrintTaxSM dpt;
    dpt.addGoods(ii.fVatDept(),
                 ii.fAdgt(),
                 ii.fCode(),
                 ii.fTaxName(),
                 ui->leAmount->asDouble(),
                 1);
    dpt.fOrder = ui->leVaucherId->text();
    dpt.fCardAmount = ui->leTaxCard->asDouble();
    dpt.fPrepaid = ui->leTaxPre->asDouble();

    int result = dpt.exec();
    if (result == TAX_OK) {
        fDD[":f_fiscal"] = dpt.fTaxCode;
        fDD.update("m_register", where_id(ap(ui->leVaucherId->text())));
        ui->leTaxCode->setInt(dpt.fTaxCode);

        fDD[":f_vaucher"] = ui->leVaucherId->text();
        fDD[":f_invoice"] = ui->leInvoice->text();
        fDD[":f_date"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_name"] = ui->leItemName->text();
        fDD[":f_amountCash"] = ui->leTaxCash->asDouble();
        fDD[":f_amountCard"] = ui->leTaxCard->asDouble();
        fDD[":f_amountPrepaid"] = ui->leTaxPre->asDouble();
        fDD[":f_user"] = WORKING_USERID;
        fDD[":f_comp"] = HOSTNAME;
        fDD.insert("m_tax_history", false);

        fTrackControl->insert(TRACK_RESERVATION, "Tax printed", ui->leVaucher->text(), ui->leAmount->text());
        return;
    }
}

void DlgPostingCharges::on_leTaxCash_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    correctAmounts(ui->leTaxCash, ui->leTaxCard, ui->leTaxPre);
}

void DlgPostingCharges::on_leTaxCard_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    correctAmounts(ui->leTaxCard, ui->leTaxCash, ui->leTaxPre);
}

void DlgPostingCharges::on_leTaxPre_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    correctAmounts(ui->leTaxPre, ui->leTaxCash, ui->leTaxCard);
}

void DlgPostingCharges::correctAmounts(EQLineEdit *l1, EQLineEdit *l2, EQLineEdit *l3)
{
    double total = ui->leAmount->asDouble();
    if (l1->asDouble() > total) {
        l1->setDouble(total);
        l2->setDouble(0);
        l3->setDouble(0);
    }
    l2->setDouble(total - l3->asDouble() - l1->asDouble());
    if (l2->asDouble() < 0) {
        l3->setDouble(l3->asDouble() + l2->asDouble());
        l2->setDouble(0);
    }
}

void DlgPostingCharges::disablePayment()
{
    ui->wPayment->setVisible(false);
    ui->lePayCode->setInitialValue(PAYMENT_CREDIT);
    ui->leCardCode->clear();
    ui->leCardName->clear();
    ui->leCardCode->setEnabled(false);
}

void DlgPostingCharges::enablePayment()
{
    ui->wPayment->setVisible(true);
    ui->lePayCode->setInitialValue(PAYMENT_CASH);
    ui->leCardCode->clear();
    ui->leCardName->clear();
    ui->leCardCode->setEnabled(false);
}

void DlgPostingCharges::on_btnNew_clicked()
{
    accept();
    DlgPostingCharges *p = new DlgPostingCharges(this);
    p->exec();
    delete p;
}
