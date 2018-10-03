#include "dlgadvance.h"
#include "ui_dlgadvance.h"
#include "vauchers.h"
#include "dlgprinttaxsm.h"
#include "pprintvaucher.h"
#include "paymentmode.h"
#include "cachepaymentmode.h"

#define HINT_PAYMENT_MODE 1

DlgAdvance::DlgAdvance(const QString &reserve, QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgAdvance)
{
    ui->setupUi(this);
    ui->leCardCode->setEnabled(false);
    ui->leCardName->setEnabled(false);
    ui->leReserve->setText(reserve);
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_id"] = reserve;
    ui->deDate->setDate(WORKING_DATE);
    fDD.exec("select f_room, f_invoice, concat(g.f_firstName, ' ', g.f_lastName) "
               "from f_reservation r "
               "left join f_guests g on g.f_id=r.f_guest "
               "where r.f_id=:f_id");
    if (fDD.nextRow()) {
        ui->leRoom->setText(fDD.getString(0));
        ui->leGuest->setText(fDD.getString(2));
        ui->leInvoice->setText(fDD.getString(1));
    }

    ui->lePaymentCode->setSelector(this, cache(cid_payment_mode), ui->lePaymentName, HINT_PAYMENT_MODE);
    ui->leCardCode->setSelector(this, cache(cid_credit_card), ui->leCardName);
    fTrackControl = new TrackControl(TRACK_RESERVATION);
}

DlgAdvance::~DlgAdvance()
{
    delete ui;
}

void DlgAdvance::callback(int sel, const QString &code)
{
    switch (sel) {
    case HINT_PAYMENT_MODE: {
        CachePaymentMode c;
        if (c.get(code)) {
            switch (c.fCode().toInt()) {
            case PAYMENT_CASH:
            case PAYMENT_CARD:
                break;
            default:
                message_error(tr("This mode of payment is not allowed here"));
                return;
            }
            ui->leCardCode->setEnabled(c.fCode().toInt() == PAYMENT_CARD);
            ui->leCardName->setEnabled(ui->leCardCode->isEnabled());
            ui->lbCard->setEnabled(ui->leCardCode->isEnabled());
            if (!ui->leCardCode->isEnabled()) {
                ui->leCardCode->clear();
                ui->leCardName->clear();
            }
        }
        break;
    }
    }
}

void DlgAdvance::setVaucherId(const QString &id)
{
    ui->leVaucher->setText(id);
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_id"] = id;
    fDD.exec("select r.f_room, r.f_invoice, concat(g.f_firstName, ' ', g.f_lastName), "
               "m.f_amountAmd, m.f_creditCard, m.f_paymentMode, m.f_doc, m.f_remarks, "
               "r.f_id, m.f_wdate, f_fiscal "
               "from m_register m "
               "left join f_reservation r on r.f_invoice=m.f_inv "
               "left join f_guests g on g.f_id=r.f_guest "
               "where m.f_id=:f_id");
    if (fDD.rowCount() > 0) {
        QList<QList<QVariant> > &fDbRows = fDD.fDbRows;
        ui->leRoom->setText(fDbRows.at(0).at(0).toString());
        ui->leGuest->setText(fDbRows.at(0).at(2).toString());
        ui->leInvoice->setText(fDbRows.at(0).at(1).toString());
        ui->lePaymentCode->setInitialValue(fDbRows.at(0).at(5).toString());
        ui->leCardCode->setInitialValue(fDbRows.at(0).at(4).toString());
        ui->leAmount->setText(float_str(fDbRows.at(0).at(3).toDouble(), 0));
        //fVaucherDoc = fDbRows.at(0).at(6).toInt();
        ui->teRemarks->setPlainText(fDbRows.at(0).at(7).toString());
        ui->leReserve->setText(fDbRows.at(0).at(8).toString());
        ui->deDate->setDate(fDbRows.at(0).at(9).toDate());
        ui->leTax->setInt(fDbRows.at(0).at(10).toInt());
    }
    ui->btnSave->setVisible(r__(cr__super_correction));
    ui->teRemarks->setEnabled(r__(cr__super_correction));
    ui->leAmount->setEnabled(r__(cr__super_correction));
    ui->lePaymentCode->setEnabled(r__(cr__super_correction));
    ui->leCardCode->setEnabled(r__(cr__super_correction));
}

void DlgAdvance::openAdvance(const QString &vaucherId)
{
    DlgAdvance *d = new DlgAdvance(0, fPreferences.getDefaultParentForMessage());
    d->setVaucherId(vaucherId);
    d->exec();
    delete d;
}

void DlgAdvance::on_btnClose_clicked()
{
    reject();
}

void DlgAdvance::on_btnPrint_clicked()
{
    if (ui->leVaucher->isEmpty()) {
        message_error(tr("Document not saved"));
        return;
    }
    PPrintVaucher::printVaucher(ui->leVaucher->text());
}

void DlgAdvance::on_btnSave_clicked()
{
    if (ui->lePaymentCode->asInt() == 0) {
        message_error(tr("Mode of payment not selected"));
        return;
    }
    if (ui->lePaymentCode->asInt() == PAYMENT_CARD) {
        if (ui->leCardCode->asInt() == 0) {
            message_error(tr("Card type not selected"));
            return;
        }
    }
    if (ui->leAmount->asDouble() < 0.1) {
        message_error(tr("Amount must be greater then zero"));
        return;
    }
    QString finalName = "CASH";
    switch (ui->lePaymentCode->asInt()) {
    case PAYMENT_CARD:
        finalName = ui->leCardName->text();
        break;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    bool isNew = false;
    if (ui->leVaucher->isEmpty()) {
        isNew = true;
        ui->leVaucher->setText(uuid(VAUCHER_ADVANCE_N));
        fDD.insertId("m_register", ui->leVaucher->text());
    }
    fDD[":f_source"] = VAUCHER_ADVANCE_N;
    if (isNew) {
        fDD[":f_wdate"] = ui->deDate->date();
        fDD[":f_rdate"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_user"] = WORKING_USERID;
    } else {
        if (r__(cr__super_correction)) {
            fDD[":f_wdate"] = ui->deDate->date();
        }
    }
    fDD[":f_room"] = ui->leRoom->text();
    fDD[":f_guest"] = ui->leGuest->text();
    fDD[":f_itemCode"] = fPreferences.getDb(def_receip_vaucher_id);
    fDD[":f_finalName"] = tr("ADVANCE") + " " + finalName;
    fDD[":f_amountAmd"] = ui->leAmount->asDouble();
    fDD[":f_amountVat"] = 0;
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = 0;
    fDD[":f_paymentMode"] = ui->lePaymentCode->asInt();
    fDD[":f_creditCard"] = ui->leCardCode->asInt();
    fDD[":f_cityLedger"] = 0;
    fDD[":f_paymentComment"] = finalName;
    fDD[":f_dc"] = "CREDIT";
    fDD[":f_sign"] = -1;
    fDD[":f_res"] = ui->leReserve->text();
    fDD[":f_doc"] = "";
    fDD[":f_rec"] = "";
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD[":f_finance"] = 1;
    fDD[":f_remarks"] = ui->teRemarks->toPlainText();
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    fDD[":f_side"] = 0;
    fDD[":f_cash"] = 1;
    fDD.update("m_register", where_id(ap(ui->leVaucher->text())));
    fDD.commit();
    ui->btnSave->setEnabled(false);

    QString msg = isNew ? "New advance" : "Advance modified";
    msg += " " + ui->leVaucher->text();
    QString value = ui->deDate->text() + "/" + ui->leRoom->text()
            + "/" + ui->leGuest->text() + "/" + ui->lePaymentName->text()
            + "/" + ui->leCardName->text() + "/" + finalName + "/" + ui->leAmount->text();
    fTrackControl->insert(msg, value, "");
}

void DlgAdvance::on_btnPrintTax_clicked()
{
    if (ui->leVaucher->text().isEmpty()) {
        message_error(tr("Save first"));
        return;
    }
    if (ui->leTax->asInt() > 0) {
        message_error(tr("Already printed"));
        return;
    }

    if (!(ui->lePaymentCode->asInt() == PAYMENT_CASH || ui->lePaymentCode->asInt() == PAYMENT_CARD)) {
        message_error(tr("Tax print is not available for this payment mode"));
    }

    ///
    double cash = ui->lePaymentCode->asInt() == PAYMENT_CASH ? ui->leAmount->asDouble() : 0;
    double card = ui->lePaymentCode->asInt() == PAYMENT_CARD ? ui->leAmount->asDouble() : 0;
    int taxCode;
    if (!DlgPrintTaxSM::printAdvance(cash, card, ui->leVaucher->text(), taxCode)) {
        return;
    }
    //PrintTax::printAdvance(ui->leAmount->asDouble(), ui->lePaymentCode->asInt(), QString("AV%1").arg(ui->leVaucher->text()));
    ui->leTax->setInt(taxCode);


    ///
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_fiscal"] = taxCode;
    fDD.update("m_register", where_id(ap(ui->leVaucher->text())));

    fDD[":f_vaucher"] = ui->leVaucher->text();
    fDD[":f_invoice"] = ui->leInvoice->text();
    fDD[":f_date"] = QDate::currentDate();
    fDD[":f_time"] = QTime::currentTime();
    fDD[":f_name"] = tr("ADVANCE") + " " + ui->lePaymentName->text() + " " + ui->leCardName->text();
    fDD[":f_amountCash"] = ui->lePaymentCode->asInt() ==  PAYMENT_CASH ? ui->leAmount->asDouble() : 0;
    fDD[":f_amountCard"] = ui->lePaymentCode->asInt() ==  PAYMENT_CASH ? 0 : ui->leAmount->asDouble();
    fDD[":f_amountPrepaid"] = 0;
    fDD[":f_user"] = WORKING_USERID;
    fDD[":f_comp"] = HOSTNAME;
    fDD.insert("m_tax_history");
    fTrackControl->insert("Tax printed", ui->leVaucher->text(), ui->leAmount->text());

    message_info(tr("Document was sent to tax printer."));
}
