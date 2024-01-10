#include "dlgbanket.h"
#include "ui_dlgbanket.h"
#include "rnumbers.h"
#include "rpaymenttype.h"
#include "dlgreservation.h"
#include "cachecityledger.h"
#include "cacheinvoiceitem.h"
#include "printtax.h"
#include "dlgbanketitems.h"
#include "rmessage.h"
#include "cacheusers.h"
#include "vauchers.h"
#include "cacheactiveroom.h"
#include "rchangehall.h"
#include "hall.h"
#include "user.h"
#include "pprintscene.h"
#include "dlggettext.h"
#include "ptextrect.h"
#include "cachepaymentmode.h"
#include "printtaxn.h"
#include "pimage.h"
#include "paymentmode.h"
#include "cachetaxmap.h"
#include "dlglist.h"
#include <QPrinter>
#include <QPainter>

DlgBanket::DlgBanket(User *user, QWidget *parent) :
    BaseExtendedDialogR(parent),
    ui(new Ui::DlgBanket)
{
    ui->setupUi(this);
    fFiscal = 0;
    fUser = user;
    fTrackControl = new TrackControl(TRACK_REST_ORDER);
    ui->deDate->setDate(WORKING_DATE);
    showFullScreen();
}

DlgBanket::~DlgBanket()
{
    delete ui;
    delete fUser;
}

void DlgBanket::printReceipt(const QString &num)
{
    if (num.isEmpty()) {
        if (message_yesnocancel(tr("Document not saved"))) {
            return;
        }
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_id"] = num;    
    fDD.exec("select e.f_state, e.f_comment, e.f_pax, e.f_price, e.f_prepayment, e.f_total, e.f_paymentDetails, "
              "h.f_name as hallname, pm.f_en as paymentname, e.f_wdate "
              "from o_event e "
              "left join r_hall h on h.f_id=e.f_hall "
              "left join f_payment_type pm on pm.f_id=e.f_paymentMode "
              "where e.f_id=:f_id");
    if (!fDD.nextRow()) {
        message_error(tr("Invalid number"));
        return;
    }

    QString state = fDD.getValue("f_state").toInt() != 1 ? tr("DRAFT") : tr("CLOSED");

    QList<PPrintScene*> lps;
    PPrintScene *ps = new PPrintScene(Portrait);
    lps.append(ps);
    QPen boldPen(Qt::SolidLine);
    boldPen.setWidth(4);
    PTextRect th;
    QFont f("Arial", 30);
    th.setFont(f);
    th.setBorders(false, false, false, false);
    int top = 10;
    th.setTextAlignment(Qt::AlignHCenter);
    int rowHeight = 60;
    PImage *logo = new PImage("logo_print.png");
    ps->addItem(logo);
    logo->setRect(QRectF(150, top, 400, 250));
    top += 250;
    f.setPointSize(40);
    th.setFont(f);
    top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight + 10, fDD.getValue("hallname").toString(), &th, f))->textHeight();
    top += 20;
    f.setPointSize(28);
    th.setFont(f);
    top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, QString("%1 %2")
                                     .arg(tr("RECEIPT S/N "))
                                     .arg(num),
                                     &th, f))->textHeight();
    if (state.contains(tr("DRAFT"))) {
        top += ps->addTextRect(10, top, 680, rowHeight, tr("(DRAFT)"), &th)->textHeight();
    }
    top += ps->addTextRect(10, top, 680, rowHeight, QString("%1: %2").arg(tr("Date")).arg(fDD.getValue("f_wdate").toDate().toString(def_date_time_format)), &th)->textHeight();
    ps->addLine(10, top, 680, top, boldPen);
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("NAME OF SERVICE:"), &th)->textHeight() + 10;
    f.setPointSize(40);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight + 20, fDD.getValue("f_comment").toString(), &th)->textHeight() + 10;
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("PAX:"), &th)->textHeight() + 10;
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, fDD.getValue("f_pax").toString(), &th)->textHeight() + 10;
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("PRICE PER PERSON:"), &th)->textHeight() + 10;
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, float_str(fDD.getValue("f_price").toDouble(), 2) + " AMD", &th)->textHeight() + 10;
    f.setPointSize(24);
    th.setFont(f);
    if (fDD.getValue("f_prepayment").toDouble() > 0.1) {
        top += ps->addTextRect(10, top, 680, rowHeight, tr("PREPAYMENT: ") + fDD.getValue("f_prepayment").toString(), &th)->textHeight();
    }
    top += ps->addTextRect(10, top, 680, rowHeight, tr("TOTAL AMOUNT:"), &th)->textHeight() + 10;
    f.setPointSize(40);
    f.setBold(true);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, float_str(fDD.getValue("f_total").toDouble(), 2) + " AMD", &th)->textHeight() + 10;
    f.setPointSize(24);
    f.setBold(false);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("EQUIVALENT OF USD:"), &th)->textHeight() + 10;
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, float_str(fDD.getValue("f_price").toDouble() / def_usd, 2) + " USD", &th)->textHeight() + 10;
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("MODE OF PAYMENT:"), &th)->textHeight() + 10;
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, fDD.getValue("paymentname").toString() + "/" + fDD.getValue("f_paymentDetails").toString(), &th)->textHeight() + 10;
    top += rowHeight;
    top += ps->addTextRect(10, top, 680, rowHeight, tr("Guest signature"), &th)->textHeight();
    top += (rowHeight * 2);
    ps->addLine(10, top, 680, top, boldPen);
    top += rowHeight;
    top += ps->addTextRect(10, top, 680, rowHeight, tr("Manager signature"), &th)->textHeight();
    top += (rowHeight * 2);
    ps->addLine(10, top, 680, top, boldPen);
    top += rowHeight;


    //Finish
    top += rowHeight;
    ps->addTextRect(new PTextRect(10, top, 680, rowHeight, "_", &th, f));

    QPrinter printer;
    //printer.setPrinterName(fHall->fReceiptPrinter);
    QMatrix m;
    m.scale(3, 3);
    QPainter painter(&printer);
    painter.setMatrix(m);
    for (int i = 0; i < lps.count(); i++) {
        if (i > 0) {
            printer.newPage();
        }
        lps[i]->render(&painter);
    }

    fTrackControl->insert("Print event receipt", "", "");
    fTrackControl->saveChanges();
}

void DlgBanket::on_btnExit_clicked()
{
    if (fDoc > 0) {
        if (message_question(tr("Confirm to exit")) != QDialog::Accepted) {
            return;
        }
    }
    accept();
}

void DlgBanket::on_btnGuestQty_clicked()
{
    float num = 0;
    if (RNumbers::getNumber(num, 0, this)) {
        ui->leGuests->setInt(num);
        ui->leTotal->setDouble(ui->lePrice->asDouble() * ui->leGuests->asInt());
        ui->leNeedToPay->setDouble(ui->leTotal->asDouble() - ui->lePrepayment->asDouble());
    }
}

void DlgBanket::on_btnPrice_clicked()
{
    float num = 0;
    if (RNumbers::getNumber(num, 0, this)) {
        ui->lePrice->setInt(num);
        ui->leTotal->setDouble(ui->lePrice->asDouble() * ui->leGuests->asInt());
        ui->leNeedToPay->setDouble(ui->leTotal->asDouble() - ui->lePrepayment->asDouble());
    }
}

void DlgBanket::on_btnPayment_clicked()
{
    int cardCode = 0;
    QString cardName;
    int cityLedger = 0;
    QString cityLedgerName;
    int paymentMode = 0;
    switch (RPaymentType::getPaymentMode(this, cardCode)) {
    case -1:
        return;
    case 0:
        paymentMode = PAYMENT_CASH;
        cardName = "CASH";
        break;
    case 1:
        paymentMode = PAYMENT_CARD;
        cardName = "VISA";
        break;
    case 2:
        paymentMode = PAYMENT_CARD;
        cardName = "MAESTRO";
        break;
    case 3:
        paymentMode = PAYMENT_CARD;
        cardName = "MASTERCARD";
        break;
    case 4:
        paymentMode = PAYMENT_CARD;
        cardName = "ARCA";
        break;
    case 5:
        paymentMode = PAYMENT_CARD;
        cardName = "AMEX";
        break;

    case 6: {
        DlgReservation *d = new DlgReservation(this);
        d->loadRoom();
        QString invoice, guest, room;
        if (d->exec() == QDialog::Accepted) {
            DoubleDatabase fDD(true, true);
            fDD[":f_id"] = d->fReservationId;
            fDD.exec("select f_invoice, f_room, concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName) "
                       "from f_reservation r "
                       "inner join f_guests g on g.f_id=r.f_guest "
                       "where r.f_id=:f_id");
            fDD.nextRow();
            invoice = fDD.getString(0);
            room = fDD.getString(1);
            guest = fDD.getString(2);
            cardName = QString("%1, %2").arg(room).arg(guest);
        } else {
            delete d;
            return;
        }
        cardCode = room.toInt();
        paymentMode = PAYMENT_ROOM;
        cardName = invoice;
        break;
    }
    case 7: {
        DlgReservation *d = new DlgReservation(this);
        d->loadCL();
        if (d->exec() == QDialog::Accepted) {
            cityLedger = d->fReservationId.toInt();
            CacheCityLedger ccl;
            ccl.get(d->fReservationId);
            cityLedgerName = ccl.fName();
            paymentMode = PAYMENT_CL;
            cardName = cityLedgerName;
            cardCode = cityLedger;
        } else {
            delete d;
            return;
        }
        break;
    }
    default:
        message_error(tr("Payment mode not supported"));
        paymentMode = 0;
        cardName = "";
        break;
    }
    CachePaymentMode i;
    if (i.get(paymentMode)) {
        ui->leModeOfPayment->fHiddenText = QString::number(paymentMode);
        ui->leModeOfPayment->setText(i.fName());
        ui->lePaymentComment->setText(cardName);
        ui->lePaymentComment->fHiddenText = QString::number(cardCode);
    } else {
        ui->leModeOfPayment->clear();
        ui->leModeOfPayment->fHiddenText = "";
        ui->lePaymentComment->clear();
    }
}

void DlgBanket::printTax()
{
    //Print tax
    if (fPreferences.getDb(def_tax_port).toInt() == 0) {
        message_error(tr("Setup tax printer first"));
        return;
    }

    HallStruct *h = nullptr;
    for (int i = 0; i < Hall::fBanketHall.count(); i++) {
        if (Hall::fBanketHall.at(i)->fId == ui->leHall->fHiddenText.toInt()) {
            h = Hall::fBanketHall.at(i);
            break;
        }
    }

    if (!h) {
        message_error(tr("No hall selected"));
        return;
    }

    CacheInvoiceItem i;
    if (!i.get(ui->leService->fHiddenText)) {
        message_error(tr("No invoice item defined for event"));
        return;
    }
    CacheTaxMap tm;
    if (!tm.get(i.fCode())) {
        message_error(tr("No tax department defined for ") + i.fName());
        return;
    }

   //b double total = ui->lePrice->asDouble();
//    pt->fRecList.append(i->fCode);
//    pt->fDept.append(h->fVatDept);
//    pt->fAdgCode.append(i->fAdgt);
//    pt->fCodeList.append(i->fCode);
//    pt->fNameList.append(i->fName);
//    pt->fQtyList.append("1");
//    pt->fPriceList.append(ui->lePrice->text());
//    pt->fTaxNameList.append(i->fTaxName);

    PrintTaxN ptn(fPreferences.getDb(def_tax_address).toString(),
                  fPreferences.getDb(def_tax_port).toInt(),
                  fPreferences.getDb(def_tax_password).toString(), "true", "3", "3");
    ptn.addGoods(h->fVatDept, i.fAdgt(), i.fCode(), i.fTaxName(), ui->leTotal->asDouble() + ui->lePrepayment->asDouble(), 1, 0);

    switch (ui->leModeOfPayment->fHiddenText.toInt()) {
    case PAYMENT_CASH:
//        pt->fAmountCash = float_str(total, 2);
//        pt->fAmountCard = "0";
        break;
    case PAYMENT_CARD:/*
        pt->fAmountCard = float_str(total, 2);
        pt->fAmountCash = "0";*/
        break;
    default:
        message_error(tr("Printing fiscal receipt is not available for selected payment mode"));
        return;
    }
    DoubleDatabase air;
    air.setDatabase(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass, 1);
    air.open(true, false);

    QString in, out, err;
    int result = ptn.makeJsonAndPrint(ui->leModeOfPayment->fHiddenText.toInt() == PAYMENT_CARD ? ui->lePrice->asDouble() : 0, 0, in, out, err);
    if (result != pt_err_ok) {        
        air[":f_date"] = QDate::currentDate();
        air[":f_time"] = QTime::currentTime();
        air[":f_db"] = 1;
        air[":f_order"] = fDoc;
        //air[":f_queryCode"] = opcode_PrintTaxN;
        air[":f_queryJson"] = in;
        air[":f_replyJson"] = out;
        air[":f_replyResult"] = result;
        air[":f_replyJson"] = out;
        air[":f_replyText"] = err;
        air[":f_replyTaxCode"] = "-";
        air.insert("tax_print", false);

        message_error(out + QString("<br>") + err);
        return;
    }
    air[":f_date"] = QDate::currentDate();
    air[":f_time"] = QTime::currentTime();
    air[":f_db"] = 1;
    air[":f_order"] = fDoc;
    //air[":f_queryCode"] = opcode_PrintTaxN;
    air[":f_queryJson"] = in;
    air[":f_replyJson"] = out;
    air[":f_replyResult"] = result;
    air[":f_replyJson"] = out;
    air[":f_replyText"] = err;
    air[":f_replyTaxCode"] = 1;
    air.insert("tax_print", false);
    air.close();
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_tax"] = 1;
    fDD.update("o_event", where_id(ap(fDoc)));
    fDD[":f_fiscal"] = 1;
    fDD.update("m_register", where_id(ap(fDoc)));
}

bool DlgBanket::isCorrect(bool draft)
{
    if (ui->leService->fHiddenText.toInt() == 0) {
        message_error(tr("Service was not selected"));
        return false;
    }
    if (ui->leGuests->asInt() < 1) {
        message_error(tr("Incorrect guest count"));
        return false;
    }
    if (ui->lePrice->asDouble() < 1) {
        message_error(tr("Incorrect price"));
        return false;
    }
    if (!draft) {
        if (ui->leModeOfPayment->fHiddenText.toInt() == 0) {
            message_error(tr("Mode of payment was not selected"));
            return false;
        }
    }
    if (ui->leHall->fHiddenText.toInt() == 0) {
        message_error(tr("Hall was not selected"));
        return false;
    }

    if (message_question(tr("Really save?")) != QDialog::Accepted) {
        return false;
    }
    return true;
}

void DlgBanket::on_btnSelectService_clicked()
{
    int code;
    QString name;
    if (DlgBanketItems::getItem(code, name)) {
        ui->leService->setText(name);
        ui->leService->fHiddenText = QString::number(code);
    }
}

void DlgBanket::on_btnPrintReceipt_clicked()
{
    printReceipt(fDoc);
}

void DlgBanket::on_btnSave_clicked()
{
    if (!isCorrect(false)) {
        return;
    }

    int creditCard = 0;
    int cityLedger = 0;
    QString room = "-";
    QString guest = "-";
    QString invoice = "";
    QString res = "";
    QString pm = ui->leModeOfPayment->fHiddenText;
    switch (pm.toInt()) {
    case PAYMENT_CARD:
        creditCard = ui->lePaymentComment->fHiddenText.toInt();
        break;
    case PAYMENT_CL:
        cityLedger = ui->lePaymentComment->fHiddenText.toInt();
        room = ui->lePaymentComment->fHiddenText;
        break;
    case PAYMENT_ROOM: {
        CacheActiveRoom ci;
        if (ci.get(ui->lePaymentComment->fHiddenText)) {
            room = ci.fRoomCode();
            guest = ci.fGuestName();
            invoice = ui->lePaymentComment->text();
            res = ci.fCode();
        }
        break;
    }
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.startTransaction();

    fDD[":f_wdate"] = WORKING_DATE;
    fDD[":f_state"] = 1;
    fDD[":f_rdate"] = QDate::currentDate();
    fDD[":f_time"] = QTime::currentTime();
    fDD[":f_user"] = fUser->fId;
    fDD[":f_itemCode"] = ui->leService->fHiddenText.toInt();
    fDD[":f_comment"] = ui->leComment->text();
    fDD[":f_hall"] = ui->leHall->fHiddenText.toInt();
    fDD[":f_pax"] = ui->leGuests->asInt();
    fDD[":f_price"] = ui->lePrice->asDouble();
    fDD[":f_total"] = ui->leTotal->asDouble();
    fDD[":f_tax"] = 0;
    fDD[":f_paymentMode"] = ui->leModeOfPayment->fHiddenText;
    fDD[":f_creditCard"] = creditCard;
    fDD[":f_cityLedger"] = cityLedger;
    fDD[":f_paymentDetails"] = ui->lePaymentComment->text();
    if (fDoc.isEmpty()) {
        fDoc = uuidx(VAUCHER_EVENT_N);
        fDD.insertId("o_event", fDoc);
    } else {
        fDD.update("o_event", where_id(ap(fDoc)));
    }

    fDD.insertId("m_register", fDoc);
    fDD[":f_source"] = VAUCHER_EVENT_N;
    fDD[":f_res"] = res;
    fDD[":f_wdate"] = WORKING_DATE;
    fDD[":f_rdate"] = QDate::currentDate();
    fDD[":f_time"] = QTime::currentTime();
    fDD[":f_user"] = fUser->fId;
    fDD[":f_room"] = room;
    fDD[":f_guest"] = guest;
    fDD[":f_itemCode"] = ui->leService->fHiddenText.toInt();
    fDD[":f_finalName"] = QString("%1 %2 #%3").arg(ui->leHall->text()).arg(ui->leService->text()).arg(fDoc);
    fDD[":f_amountAmd"] = ui->leTotal->asDouble();
    fDD[":f_amountVat"] = Utils::countVATAmount(ui->lePrice->asDouble(), 1);
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = fFiscal;
    fDD[":f_paymentMode"] = ui->leModeOfPayment->fHiddenText.toInt();
    fDD[":f_creditCard"] = creditCard;
    fDD[":f_cityLedger"] = cityLedger;
    fDD[":f_paymentComment"] = ui->lePaymentComment->text();
    fDD[":f_dc"] = (cityLedger == 0 ? "DEBIT" : "CREDIT");
    fDD[":f_sign"] = (cityLedger == 0 ? 1 : -1);
    fDD[":f_doc"] = fDoc;
    fDD[":f_rec"] = 0;
    fDD[":f_inv"] = invoice;
    fDD[":f_finance"] = 1;
    fDD[":f_remarks"] = "";
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    fDD[":f_side"] = 0;
    fDD.update("m_register", where_id(ap(fDoc)));

    fDD[":f_id"] = ui->lePaymentComment->text();
    fDD.exec("select f_invoice, f_room, concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName) "
               "from f_reservation r "
               "inner join f_guests g on g.f_id=r.f_guest "
               "where r.f_id=:f_id");
    if (fDD.nextRow()) {
        fDD[":f_room"] = fDD.getString(1);
        fDD[":f_guest"] = fDD.getString(2);
        fDD.update("m_register", where_id(ap(ui->lePaymentComment->text())));
    }

    fTrackControl->insert(TRACK_REST_ORDER,"Save event", QString("%1,%2,%3,%4,%5,%6")
                          .arg(ui->deDate->text())
                          .arg(ui->leGuests->text())
                          .arg(ui->lePrice->text())
                          .arg(ui->leTotal->text())
                          .arg(ui->leComment->text())
                          .arg(ui->lePaymentComment->text()), "", fDoc);
    fTrackControl->saveChanges();

    fDD.commit();

    ui->btnSelectService->setEnabled(false);
    ui->btnGuestQty->setEnabled(false);
    ui->btnPrice->setEnabled(false);
    ui->btnPayment->setEnabled(false);
    ui->btnHall->setEnabled(false);
    ui->btnSave->setEnabled(false);
    ui->btnDraft->setEnabled(false);

    ui->lbState->setText(QString("%1 %2").arg("EVENT S/N ").arg(fDoc));
}

void DlgBanket::on_btnHall_clicked()
{
    RChangeHall *h = new RChangeHall(this);
    h->setup(Hall::fBanketHall);
    if (h->exec() == QDialog::Accepted)  {
        HallStruct *hs = nullptr;
        for (int i = 0; i < Hall::fBanketHall.count(); i++) {
            if (h->hall() == Hall::fBanketHall.at(i)->fId) {
                hs = Hall::fBanketHall.at(i);
                break;
            }
        }
        if (hs) {
            ui->leHall->setText(hs->fName);
            ui->leHall->fHiddenText = QString::number(hs->fId);
            if (!hs->fId) {
                message_error(QString::number(hs->fId));
            }
        } else {
            message_error(tr("Cannot find hall") + "<br>" + QString::number(h->hall()));
        }
    }
    delete h;
}

void DlgBanket::on_btnTaxPrint_clicked()
{
    if (fDoc.isEmpty()) {
        message_error(tr("Document not saved"));
        return;
    }
    printTax();

    fTrackControl->insert("Print event fiscal", "", "");
    fTrackControl->saveChanges();
}

void DlgBanket::on_btnComment_clicked()
{
    QString comment;
    QString sql = "select f_id, f_name from r_banquet_comment";
    QVariant result;
    if (DlgList::getValue(tr("COMMENT"), comment, result, sql)) {
        ui->leComment->setText(comment);
    }
}

void DlgBanket::on_btnDraft_clicked()
{
    if (!isCorrect(false)) {
        return;
    }

    int creditCard = 0;
    int cityLedger = 0;
    switch (ui->leModeOfPayment->fHiddenText.toInt()) {
    case PAYMENT_CARD:
        creditCard = ui->lePaymentComment->fHiddenText.toInt();
        break;
    case PAYMENT_CL:
        cityLedger = ui->lePaymentComment->fHiddenText.toInt();
        break;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_wdate"] = ui->deDate->date();
    fDD[":f_state"] = 0;
    fDD[":f_rdate"] = QDate::currentDate();
    fDD[":f_time"] = QTime::currentTime();
    fDD[":f_user"] = fUser->fId;
    fDD[":f_itemCode"] = ui->leService->fHiddenText.toInt();
    fDD[":f_comment"] = ui->leComment->text();
    fDD[":f_hall"] = ui->leHall->fHiddenText.toInt();
    fDD[":f_pax"] = ui->leGuests->asInt();
    fDD[":f_price"] = ui->lePrice->asDouble();
    fDD[":f_total"] = ui->leTotal->asDouble();
    fDD[":f_tax"] = 0;
    fDD[":f_paymentMode"] = ui->leModeOfPayment->fHiddenText;
    fDD[":f_creditCard"] = creditCard;
    fDD[":f_cityLedger"] = cityLedger;
    fDD[":f_prepayment"] = ui->lePrepayment->asDouble();
    fDD[":f_prepaymentMode"] = ui->leModePrepayment->fHiddenText.toInt();
    fDD[":f_prepaymentModeComment"] = ui->leModePrepaymentComment->text();
    fDD[":f_prepaymentTax"] = ui->lePrepaymentTax->text();
    fDD[":f_paymentDetails"] = ui->lePaymentComment->text();
    if (fDoc.isEmpty()) {
        fDoc = uuidx(VAUCHER_EVENT_N);
        fDD.insertId("o_event", fDoc);
    }
    fDD.update("o_event", where_id(ap(fDoc)));

    fTrackControl->insert("Save draft", "", "");
    fTrackControl->saveChanges();

    ui->lbState->setText(QString("%1 #%2").arg(tr("DRAFT")).arg(fDoc));

}

void DlgBanket::on_btnOpen_clicked()
{
    QString name;
    QString sql = "select f_id, concat(date_format(f_wdate, '%d/%m/%Y'), ' ', f_comment, ' ', f_total) "
            "from o_event where f_state=0 and f_canceled=0";
    QVariant result;
    if (!DlgList::getValue(tr("DRAFTS"), name, result, sql)) {
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_id"] = result;
    fDD.exec("select f_itemCode, f_comment, f_hall, f_pax, f_total, f_paymentMode, f_creditCard, f_cityLedger, "
               "f_prepayment, f_prepaymentModeComment,  f_prepaymentTax, f_paymentDetails "
               "from o_event where f_id=:f_id");
    if (!fDD.nextRow()) {
        message_error(tr("Cannot load event case, #1"));
        return;
    }

    CacheInvoiceItem ci;
    if (ci.get(fDD.getString(0))) {
        ui->leService->setText(ci.fName());
        ui->leService->fHiddenText = ci.fCode();
    }
    ui->leComment->setText(fDD.getString(1));
    HallStruct *hall = Hall::fHallMap[fDD.getInt(2)];
    if (hall) {
        ui->leHall->setText(hall->fName);
        ui->leHall->fHiddenText = QString::number(hall->fId);
    }
    ui->leGuests->setText(fDD.getString(3));
    ui->leTotal->setDouble(fDD.getDouble(4));
    if (ui->leGuests->asInt()) {
        ui->lePrice->setDouble(ui->leTotal->asDouble() / ui->leGuests->asInt());
    }

    CacheCreditCard cc;
    if (cc.get(fDD.getString(6))) {
        ui->lePaymentComment->setText(cc.fName());
        ui->lePaymentComment->fHiddenText = cc.fCode();
    }

    CacheCityLedger cl;
    if (cl.get(fDD.getString(7))) {
        ui->lePaymentComment->setText(cl.fName());
        ui->lePaymentComment->fHiddenText = cl.fCode();
    }

    CachePaymentMode pc;
    if (pc.get(fDD.getString(5))) {
        if (fDD.getInt(5) == PAYMENT_ROOM) {
            DoubleDatabase dd(true, false);
            dd[":f_invoice"] = fDD.getString("f_paymentdetails");
            dd.exec("select r.f_room from f_reservation r where r.f_invoice=:f_invoice");
            if (dd.nextRow()) {
                ui->lePaymentComment->setText(fDD.getString("f_paymentdetails"));
                ui->lePaymentComment->fHiddenText = dd.getString("f_room");
            }
        }
        ui->leModeOfPayment->setText(pc.fName());
        ui->leModeOfPayment->fHiddenText = pc.fCode();
    }

    ui->lePrepayment->setText(float_str(fDD.getDouble(8), 0));
    ui->lbState->setText(QString("%1 #%2").arg(tr("DRAFT")).arg(result.toString()));
    fDoc = result.toString();

    CachePaymentMode pprep;
    if (pprep.get(fDD.getString("f_prepaymentMode"))) {
        ui->leModePrepayment->setText(pprep.fName());
        ui->leModePrepayment->fHiddenText = pprep.fCode();
    }
    ui->leModePrepaymentComment->setText(fDD.getString("f_prepaymentModeComment"));
    ui->lePrepaymentTax->setText(fDD.getString("f_prepaymentTax"));
    ui->leTotal->setDouble(ui->lePrice->asDouble() * ui->leGuests->asInt());
    ui->leNeedToPay->setDouble(ui->leTotal->asDouble() - ui->lePrepayment->asDouble());
    ui->deDate->setDate(fDD.getDate("f_wdate"));

    ui->btnDraft->setEnabled(true);
    ui->btnSave->setEnabled(true);
    ui->pushButton_2->setEnabled(ui->lePrepaymentTax->asInt() == 0);
    ui->deDate->setEnabled(false);

    fTrackControl->insert("Open draft", "", "");
    fTrackControl->saveChanges();
}

void DlgBanket::on_btnNew_clicked()
{
    ui->leService->fHiddenText.clear();
    ui->leService->clear();
    ui->leComment->clear();
    ui->leGuests->clear();
    ui->lePrepayment->clear();
    ui->lePrice->clear();
    ui->leModeOfPayment->clear();
    ui->leModeOfPayment->fHiddenText.clear();
    ui->lePaymentComment->clear();
    ui->lePaymentComment->fHiddenText.clear();
    ui->leHall->clear();
    ui->leHall->fHiddenText.clear();
    fDoc = "";
    ui->btnDraft->setEnabled(true);
}

void DlgBanket::on_btnPrepayment_clicked()
{
    float num = 0;
    if (RNumbers::getNumber(num, 0, this)) {
        ui->lePrepayment->setInt(num);
        ui->leNeedToPay->setDouble(ui->leTotal->asDouble() - ui->lePrepayment->asDouble());
    }
}

void DlgBanket::on_btnPrintDuplicate_clicked()
{
    QString ordNum;
    if (!DlgGetText::getText(ordNum, "PE-")) {
        return;
    }
    if (ordNum.trimmed().isEmpty()) {
        return;
    }
    printReceipt(ordNum);
}

void DlgBanket::on_pushButton_clicked()
{
    int cardCode = 0;
    QString cardName;
    int cityLedger = 0;
    QString cityLedgerName;
    int paymentMode = 0;
    switch (RPaymentType::getPaymentMode(this, cardCode)) {
    case -1:
        return;
    case 0:
        paymentMode = PAYMENT_CASH;
        cardName = "CASH";
        break;
    case 1:
        paymentMode = PAYMENT_CARD;
        cardName = "VISA";
        break;
    case 2:
        paymentMode = PAYMENT_CARD;
        cardName = "MAESTRO";
        break;
    case 3:
        paymentMode = PAYMENT_CARD;
        cardName = "MASTERCARD";
        break;
    case 4:
        paymentMode = PAYMENT_CARD;
        cardName = "ARCA";
        break;
    case 5:
        paymentMode = PAYMENT_CARD;
        cardName = "AMEX";
        break;
/*
    case 6: {
        DlgReservation *d = new DlgReservation(this);
        d->loadRoom();
        if (d->exec() == QDialog::Accepted) {
            fDD[":f_reservation"] = d->fReservationId;
            fDD.update("o_header", where_id(fTable->fOrder));
            fDD[":f_id"] = d->fReservationId;
            fDD.exec("select f_invoice, f_room, concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName) "
                       "from f_reservation r "
                       "inner join f_guests g on g.f_id=r.f_guest "
                       "where r.f_id=:f_id");
            invoice = fDbRows.at(0).at(0).toInt();
            room = fDbRows.at(0).at(1).toString();
            guest = fDbRows.at(0).at(2).toString();
            cardName = QString("%1, %2").arg(room).arg(guest);
        } else {
            delete d;
            return;
        }
        cardCode = 0;
        paymentMode = PAYMENT_ROOM;
        cardName = paymentModeComment;
        break;
    } */
    case 7: {
        DlgReservation *d = new DlgReservation(this);
        d->loadCL();
        if (d->exec() == QDialog::Accepted) {
            cityLedger = d->fReservationId.toInt();
            CacheCityLedger ccl;
            ccl.get(d->fReservationId);
            cityLedgerName = ccl.fName();
            paymentMode = PAYMENT_CL;
            cardName = cityLedgerName;
            cardCode = cityLedger;
        } else {
            delete d;
            return;
        }
        break;
    }
    default:
        message_error(tr("Payment mode not supported"));
        paymentMode = 0;
        cardName = "";
        break;
    }
    CachePaymentMode i;
    if (i.get(paymentMode)) {
        ui->leModePrepayment->fHiddenText = QString::number(paymentMode);
        ui->leModePrepayment->setText(i.fName());
        ui->leModePrepaymentComment->setText(cardName);
        ui->leModePrepaymentComment->fHiddenText = QString::number(cardCode);
    } else {
        ui->leModePrepayment->clear();
        ui->leModePrepayment->fHiddenText = "";
        ui->leModePrepaymentComment->clear();
    }
}

void DlgBanket::on_pushButton_2_clicked()
{
    if (fDoc.length() == 0) {
        message_error(tr("Save first!"));
        return;
    }
    if (ui->lePrepayment->asDouble() < 0.01) {
        message_error(tr("Amount of prepayment cannot be empty"));
        return;
    }
    PrintTaxN ptn(fPreferences.getDb(def_tax_address).toString(),
                  fPreferences.getDb(def_tax_port).toInt(),
                  fPreferences.getDb(def_tax_password).toString(), "true", "3", "3");
    QString in, out, err;
    int res = ptn.printAdvanceJson(ui->leModePrepayment->fHiddenText.toInt() == PAYMENT_CASH ? ui->lePrepayment->asDouble() : 0,
                         ui->leModePrepayment->fHiddenText.toInt() == PAYMENT_CASH ? 0 : ui->lePrepayment->asDouble(), in, out, err);
    if (res == pt_err_ok) {
        ui->pushButton_2->setEnabled(false);
        DoubleDatabase fDD(true, doubleDatabase);
        fDD[":f_prepaymentTax"] = 1;
        fDD.update("o_event", where_id(ap(fDoc)));

        DoubleDatabase air;
        air.setDatabase(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass, 1);
        air.open(true, false);
        air[":f_order"] = fDoc;
        air[":f_queryJson"] = in;
        air[":f_replyJson"] = out;
        air[":f_replyText"] = err;
        air[":f_date"] = QDate::currentDate();
        air[":f_time"] = QTime::currentTime();
        air.insert("tax_print", false);
        air.close();
    }
}

void DlgBanket::on_btnDuplicateFiscal_clicked()
{
    QString ordNum;
    if (!DlgGetText::getText(ordNum, "PE-")) {
        return;
    }
    if (ordNum.trimmed().isEmpty()) {
        return;
    }
    if (fPreferences.getDb(def_tax_port).toInt() == 0) {
        message_error(tr("Setup tax printer first"));
        return;
    }
    DoubleDatabase fDD;
    fDD.open(true, doubleDatabase);
    fDD[":f_id"] = ordNum;
    fDD.exec("select * from o_event where f_id=:f_id and f_state=1 ");
    if (!fDD.nextRow()) {
        message_error(tr("Invalid event number"));
    }
    HallStruct *h = 0;
    for (int i = 0; i < Hall::fBanketHall.count(); i++) {
        if (Hall::fBanketHall.at(i)->fId == fDD.getInt("f_hall")) {
            h = Hall::fBanketHall.at(i);
            break;
        }
    }
    if (!h) {
        message_error(tr("No hall selected"));
        return;
    }

    CacheInvoiceItem i;
    if (!i.get(fDD.getInt("f_itemCode"))) {
        message_error(tr("No invoice item defined for event"));
        return;
    }
    CacheTaxMap tm;
    if (!tm.get(i.fCode())) {
        message_error(tr("No tax department defined for ") + i.fName());
        return;
    }

    PrintTaxN ptn(fPreferences.getDb(def_tax_address).toString(),
                  fPreferences.getDb(def_tax_port).toInt(),
                  fPreferences.getDb(def_tax_password).toString(), "true", "3", "3");
    ptn.addGoods(h->fVatDept, i.fAdgt(), i.fCode(), i.fTaxName(), fDD.getDouble("f_total"), 1, 0);

    switch (fDD.getInt("f_paymentMode")) {
    case PAYMENT_CASH:
//        pt->fAmountCash = float_str(total, 2);
//        pt->fAmountCard = "0";
        break;
    case PAYMENT_CARD:/*
        pt->fAmountCard = float_str(total, 2);
        pt->fAmountCash = "0";*/
        break;
    default:
        message_error(tr("Printing fiscal receipt is not available for selected payment mode"));
        return;
    }
    DoubleDatabase air;
    air.setDatabase(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass, 1);
    air.open(true, false);

    QString in, out, err;
    int result = ptn.makeJsonAndPrint(fDD.getInt("f_paymentMode") == PAYMENT_CARD ? fDD.getDouble("f_total") : 0, 0, in, out, err);
    if (result != pt_err_ok) {
        air[":f_date"] = QDate::currentDate();
        air[":f_time"] = QTime::currentTime();
        air[":f_db"] = 1;
        air[":f_order"] = fDoc;
        //air[":f_queryCode"] = opcode_print_receipt;
        air[":f_queryJson"] = in;
        air[":f_replyJson"] = out;
        air[":f_replyResult"] = result;
        air[":f_replyJson"] = out;
        air[":f_replyText"] = err;
        air[":f_replyTaxCode"] = "-";
        air.insert("tax_print", false);

        message_error(out + QString("<br>") + err);
        return;
    }
    air[":f_date"] = QDate::currentDate();
    air[":f_time"] = QTime::currentTime();
    air[":f_db"] = 1;
    air[":f_order"] = fDoc;
    //air[":f_queryCode"] = opcode_PrintTaxN;
    air[":f_queryJson"] = in;
    air[":f_replyJson"] = out;
    air[":f_replyResult"] = result;
    air[":f_replyJson"] = out;
    air[":f_replyText"] = err;
    air[":f_replyTaxCode"] = 1;
    air.insert("tax_print", false);
    air.close();

    fDD[":f_tax"] = 1;
    fDD.update("o_event", where_id(ap(fDoc)));
    fDD[":f_fiscal"] = 1;
    fDD.update("m_register", where_id(ap(fDoc)));
}
