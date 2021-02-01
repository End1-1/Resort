#include "dlgonebreakfasat.h"
#include "ui_dlgonebreakfasat.h"
#include "pprintscene.h"
#include "ptextrect.h"
#include "pimage.h"
#include "rnumbers.h"
#include "rmessage.h"
#include "dlgreservation.h"
#include "cacheinvoiceitem.h"
#include "rpaymenttype.h"
#include "dlglist.h"
#include "vauchers.h"
#include "cacheinvoiceitem.h"
#include "cachecreditcard.h"
#include "cachecityledger.h"
#include "cachepaymentmode.h"
#include "paymentmode.h"
#include "cachetaxmap.h"
#include <QPrinter>
#include <QPainter>

DlgOneBreakfasat::DlgOneBreakfasat(User *u, QWidget *parent) :
    BaseExtendedDialogR(parent),
    ui(new Ui::DlgOneBreakfasat)
{
    ui->setupUi(this);
    fUser = u;;
    hideAllMode();
    fTrackControl = new TrackControl(TRACK_REST_ORDER);
}

DlgOneBreakfasat::~DlgOneBreakfasat()
{
    delete ui;
}

void DlgOneBreakfasat::on_btnPrint_clicked()
{
    if (ui->lePax->asDouble() < 1) {
        message_error(tr("Incorrect guest count"));
        return;
    }

    if (ui->lePayment->fHiddenText.toInt() == 0) {
        message_error(tr("Payment mode is not selected"));
        return;
    }

    switch (message_yesnocancel(tr("Save now?"))) {
    case RESULT_YES:
        break;
    case RESULT_NO:
        return;
    case RESULT_CANCEL:
        return;
    }

    CacheInvoiceItem cb;
    if (!cb.get(fPreferences.getDb(def_auto_breakfast_id).toString())) {
        message_error(tr("Breakfast code is not defined. Contact to administrator"));
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.startTransaction();
    QString paymentComment = "CASH";
    switch (ui->lePayment->fHiddenText.toInt()) {
    case PAYMENT_BANK:
        paymentComment = tr("BANK");
        break;
    case PAYMENT_CARD:
        paymentComment = ui->leCardType->text();
        break;
    case PAYMENT_CL:
        paymentComment = ui->leCityLedger->text();
        break;
    }

    fDD.insertId("m_register", fBreakfastId);

    fDD[":f_source"] = cb.fVaucher();
    fDD[":f_wdate"] = WORKING_DATE;
    fDD[":f_rdate"] = QDate::currentDate();
    fDD[":f_time"] = QTime::currentTime();
    fDD[":f_user"] = fUser->fId;
    fDD[":f_room"] = ui->leRoom->text();
    fDD[":f_guest"] = ui->leGuest->text();
    fDD[":f_itemCode"] = cb.fCode();
    fDD[":f_finalName"] = QString("%1 S/N %2").arg(tr("BREAKFAST")).arg(fBreakfastId);
    fDD[":f_amountAmd"] = ui->leTotal->asDouble();
    fDD[":f_amountVat"] = Utils::countVATAmount(ui->leTotal->asDouble(), VAT_INCLUDED);
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = 0;
    fDD[":f_paymentMode"] = ui->lePayment->fHiddenText;
    fDD[":f_creditCard"] = ui->leCardType->fHiddenText;
    fDD[":f_cityLedger"] = ui->leCityLedger->fHiddenText;
    fDD[":f_paymentComment"] = paymentComment;
    fDD[":f_dc"] = ui->lePayment->fHiddenText.toInt() == PAYMENT_CL ? "CREDIT" : "DEBIT";
    fDD[":f_sign"] = ui->lePayment->fHiddenText.toInt() == PAYMENT_CL ? -1 : 1;
    fDD[":f_doc"] = "";
    fDD[":f_rec"] = "";
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD[":f_finance"] = 1;
    fDD[":f_remarks"] = "";
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    fDD[":f_side"] = 0;
    fDD.update("m_register", where_id(ap(fBreakfastId)));

    fDD[":f_state"] = 2;
    fDD[":f_close"] = QDateTime::currentDateTime();
    fDD.update("o_breakfast", where_id(ap(fBreakfastId)));

    /*
    fDD[":f_show"] = ui->tblData->toInt(row, 5);
    fDD[":f_doc"] = vid;
    fDD.update("f_reservation_meal", where_id(ui->tblData->toInt(row, 0)));
    */

    fTrackControl->insert("Save breakfast", "", "");
    fTrackControl->saveChanges();


    fDD.commit();

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
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, QString("%1 %2")
                                     .arg(tr("RECEIPT #"))
                                     .arg(fBreakfastId),
                                     &th, f))->textHeight();
    top += ps->addTextRect(10, top, 680, rowHeight, QString("%1: %2").arg(tr("Date")).arg(QDateTime::currentDateTime().toString(def_date_time_format)), &th)->textHeight();
    ps->addLine(10, top, 680, top, boldPen);
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("NAME OF SERVICE:"), &th)->textHeight() + 10;
    f.setPointSize(40);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight + 20, tr("BREAKFAST"), &th)->textHeight() + 10;
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("PAX:"), &th)->textHeight() + 10;
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, ui->lePax->text(), &th)->textHeight() + 10;
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("PRICE PER PERSON:"), &th)->textHeight() + 10;
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, float_str(ui->lePrice->asDouble(), 2) + " AMD", &th)->textHeight() + 10;
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("TOTAL AMOUNT:"), &th)->textHeight() + 10;
    f.setPointSize(40);
    f.setBold(true);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, float_str(ui->leTotal->asDouble(), 2) + " AMD", &th)->textHeight() + 10;
    f.setPointSize(24);
    f.setBold(false);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("EQUIVALENT OF USD:"), &th)->textHeight() + 10;
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, float_str(ui->leTotal->asDouble() / def_usd, 2) + " USD", &th)->textHeight() + 10;

    top += rowHeight;
    top += ps->addTextRect(10, top, 680, rowHeight, ui->leRoom->text() + ", " + ui->leGuest->text(), &th)->textHeight();
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

    ui->btnPrice->setEnabled(false);
    ui->btnPax->setEnabled(false);
    ui->btnPayment->setEnabled(false);
    ui->btnPrint->setEnabled(false);
    ui->btnPrintTax->setEnabled(true);
    ui->btnOpenDraft->setEnabled(false);
    ui->btnPrePrint->setEnabled(false);
}

void DlgOneBreakfasat::on_lePax_textChanged(const QString &arg1)
{
    ui->leTotal->setDouble(arg1.toDouble() * ui->lePrice->asDouble());
}

void DlgOneBreakfasat::on_lePrice_textChanged(const QString &arg1)
{
    ui->leTotal->setDouble(arg1.toDouble() * ui->lePax->asDouble());
}

void DlgOneBreakfasat::on_btnExit_clicked()
{
    accept();
}

void DlgOneBreakfasat::on_btnPax_clicked()
{
    float num = 0;
    if (RNumbers::getNumber(num, 0, this)) {
        ui->lePax->setInt(num);
    }
}

void DlgOneBreakfasat::on_btnPrice_clicked()
{
    float num = 0;
    if (RNumbers::getNumber(num, 0, this)) {
        ui->lePrice->setInt(num);
    }
}

void DlgOneBreakfasat::on_btnPayment_clicked()
{
    DoubleDatabase fDD(true, doubleDatabase);
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
        hideAllMode();
        cardName = "CASH";
        break;
    case 1:
        paymentMode = PAYMENT_CARD;
        setModeCard();
        cardName = "VISA";
        break;
    case 2:
        paymentMode = PAYMENT_CARD;
        setModeCard();
        cardName = "MAESTRO";
        break;
    case 3:
        paymentMode = PAYMENT_CARD;
        setModeCard();
        cardName = "MASTERCARD";
        break;
    case 4:
        fDD[":f_paymentMode"] = PAYMENT_CARD;
        setModeCard();
        cardName = "ARCA";
        break;
    case 5:
        paymentMode = PAYMENT_CARD;
        setModeCard();
        cardName = "AMEX";
        break;

    case 6: {
        DlgReservation *d = new DlgReservation(this);
        d->loadRoom();
        if (d->exec() == QDialog::Accepted) {
            fDD[":f_id"] = d->fReservationId;
            fDD.exec("select f_invoice, f_room, g.guest "
                       "from f_reservation r "
                       "inner join guests g on g.f_id=r.f_guest "
                       "where r.f_id=:f_id");
            ui->leInvoice->setText(fDD.fDbRows.at(0).at(0).toString());
            ui->leRoom->setText(fDD.fDbRows.at(0).at(1).toString());
            ui->leGuest->setText(fDD.fDbRows.at(0).at(2).toString());
            cardName = QString("%1, %2").arg(ui->leRoom->text()).arg(ui->leGuest->text());
        } else {
            delete d;
            return;
        }
        setModeRoom();
        ui->leRoom->setText(fDD.fDbRows.at(0).at(1).toString());
        ui->leInvoice->setText(fDD.fDbRows.at(0).at(0).toString());
        ui->leGuest->setText(fDD.fDbRows.at(0).at(2).toString());
        paymentMode = PAYMENT_ROOM;
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
        } else {
            delete d;
            return;
        }
        setModeCityLedger();
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
        ui->lePayment->fHiddenText = QString::number(paymentMode);
        ui->lePayment->setText(i.fName());
        ui->leCardType->setText(cardName);
        ui->leCardType->fHiddenText = QString::number(cardCode);
        ui->leCityLedger->setText(cityLedgerName);
        ui->leCityLedger->fHiddenText = QString::number(cityLedger);
    } else {
        ui->lePayment->clear();
        ui->lePayment->fHiddenText = "";
        ui->leCardType->clear();
        ui->leCardType->fHiddenText = "";
    }
}

void DlgOneBreakfasat::on_btnPrintTax_clicked()
{
    //Print tax
    if (fPreferences.getDb(def_tax_port).toInt() == 0) {
        message_error(tr("Setup tax printer first"));
        return;
    }

    Preferences p;
    CacheInvoiceItem i;
    if (!i.get(p.getDb(def_auto_breakfast_id).toString())) {
        message_error(tr("No invoice item defined for breakfast"));
        return;
    }
    CacheTaxMap tm;
    if (!tm.get(i.fCode())) {
        message_error(tr("No tax department defined for ") + i.fName());
        return;
    }
//    PrintTax *pt = new PrintTax(this);
//    double total = ui->leTotal->asDouble();
//    pt->fRecList.append(i.fCode());
//    pt->fDept.append(tm.fName());
//    pt->fAdgCode.append(i.fAdgt());
//    pt->fCodeList.append(i.fCode());
//    pt->fNameList.append(i.fName());
//    pt->fQtyList.append(ui->lePax->text());
//    pt->fPriceList.append(ui->lePrice->text());
//    pt->fTaxNameList.append(i.fTaxName());


//    switch (ui->lePayment->fHiddenText.toInt()) {
//    case PAYMENT_CASH:
//        pt->fAmountCash = float_str(total, 2);
//        pt->fAmountCard = "0";
//        break;
//    case PAYMENT_CARD:
//        pt->fAmountCard = float_str(total, 2);
//        pt->fAmountCash = "0";
//        break;
//    default:
//        delete pt;
//        message_error(tr("Printing fiscal receipt is not available for selected payment mode"));
//        return;
//    }
//    fDD[":f_tax"] = 1;
//    fDD.update("m_register", where_id(fBreakfastId));
//    pt->fInvoice = fBreakfastId;

//    fTrackControl->insert("Print tax", "", "");
//    fTrackControl->saveChanges();

//    pt->build();
//    pt->print();
//    delete pt;

}

void DlgOneBreakfasat::hideAllMode()
{
    ui->lbCardType->setVisible(false);
    ui->leCardType->setVisible(false);
    ui->lbCityLedger->setVisible(false);
    ui->leCityLedger->setVisible(false);
    ui->leRoom->setVisible(false);
    ui->leInvoice->setVisible(false);
    ui->lbRoom->setVisible(false);
    ui->lbInvoice->setVisible(false);
    ui->btnRoom->setVisible(false);
    ui->leGuest->setVisible(false);
    ui->lbGuest->setVisible(false);
    ui->leCardType->clear();
    ui->leCardType->fHiddenText.clear();
    ui->leCityLedger->clear();
    ui->leCityLedger->fHiddenText.clear();
    ui->leRoom->clear();
    ui->leGuest->clear();
    ui->leInvoice->clear();
}

void DlgOneBreakfasat::setModeCard()
{
    hideAllMode();
    ui->lbCardType->setVisible(true);
    ui->leCardType->setVisible(true);
}

void DlgOneBreakfasat::setModeCityLedger()
{
    hideAllMode();
    ui->lbCityLedger->setVisible(true);
    ui->leCityLedger->setVisible(true);
}

void DlgOneBreakfasat::setModeRoom()
{
    hideAllMode();
    ui->lbGuest->setVisible(true);
    ui->lbInvoice->setVisible(true);
    ui->lbRoom->setVisible(true);
    ui->leGuest->setVisible(true);
    ui->leInvoice->setVisible(true);
    ui->leRoom->setVisible(true);
}

void DlgOneBreakfasat::on_btnPrePrint_clicked()
{
    CacheInvoiceItem cb;
    if (!cb.get(fPreferences.getDb(def_auto_breakfast_id).toString())) {
        message_error("Breakfast code is not defined. Contact to administrator");
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_user"] = fUser->fId;
    fDD[":f_pax"] = ui->lePax->asInt();
    fDD[":f_price"] = ui->lePrice->asDouble();
    fDD[":f_paymentMode"] = ui->lePayment->fHiddenText.toInt();
    fDD[":f_card"] = ui->leCardType->fHiddenText.toInt();
    fDD[":f_cityLedger"] = ui->leCityLedger->fHiddenText.toInt();
    fDD[":f_room"] = ui->leRoom->text().toInt();
    fDD[":f_open"] = QDateTime::currentDateTime();

    fBreakfastId = uuidx(cb.fVaucher());
    fDD.insertId("o_breakfast", fBreakfastId);
    fDD.update("o_breakfast", where_id(ap(fBreakfastId)));

    fTrackControl->insert("Draft breakfast", "", "");
    fTrackControl->saveChanges();

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
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, QString("%1 %2")
                                     .arg(tr("RECEIPT #"))
                                     .arg(fBreakfastId),
                                     &th, f))->textHeight();
    top += ps->addTextRect(10, top, 680, rowHeight, QString("%1: %2").arg(tr("Date")).arg(QDateTime::currentDateTime().toString(def_date_time_format)), &th)->textHeight();
    ps->addLine(10, top, 680, top, boldPen);
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("NAME OF SERVICE:"), &th)->textHeight() + 10;
    f.setPointSize(40);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight + 20, tr("BREAKFAST"), &th)->textHeight() + 10;
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("PAX:"), &th)->textHeight() + 10;
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, ui->lePax->text(), &th)->textHeight() + 10;
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("PRICE PER PERSON:"), &th)->textHeight() + 10;
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, float_str(ui->lePrice->asDouble(), 2) + " AMD", &th)->textHeight() + 10;
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("TOTAL AMOUNT:"), &th)->textHeight() + 10;
    f.setPointSize(40);
    f.setBold(true);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, float_str(ui->leTotal->asDouble(), 2) + " AMD", &th)->textHeight() + 10;
    f.setPointSize(24);
    f.setBold(false);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("EQUIVALENT OF USD:"), &th)->textHeight() + 10;
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, float_str(ui->leTotal->asDouble() / def_usd, 2) + " USD", &th)->textHeight() + 10;

    top += rowHeight;
    top += ps->addTextRect(10, top, 680, rowHeight, ui->leRoom->text() + ", " + ui->leGuest->text(), &th)->textHeight();
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

    ui->btnPrint->setEnabled(true);
    ui->btnPrePrint->setEnabled(false);
}

void DlgOneBreakfasat::on_btnOpenDraft_clicked()
{
    QString name;
    QString sql = "select o.f_id, concat('Date: ', date_format(f_open, '%d.%m.%Y'), ' Staff: ', u.f_username, "
            "'\r\n', 'Pax: ', f_pax, ' Price: ', f_price, ' Room: ', f_room) "
            "from o_breakfast o "
            "left join users u on u.f_id=o.f_user "
            " where o.f_state=1";
    QVariant draftId;
    if (!DlgList::getValue(tr("Breakfast"), name, draftId, sql)) {
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_id"] = draftId;
    fDD.exec("select f_pax, f_price, f_paymentMode, f_card, f_cityLedger, f_room "
               "from o_breakfast where f_id=:f_id");
    if (fDD.fDbRows.count() == 0) {
        return;
    }
    fBreakfastId = draftId.toString();
    ui->lePax->setText(fDD.fDbRows.at(0).at(0).toString());
    ui->lePrice->setText(fDD.fDbRows.at(0).at(1).toString());
    ui->lePayment->fHiddenText = fDD.fDbRows.at(0).at(2).toString();
    ui->leCardType->fHiddenText = fDD.fDbRows.at(0).at(3).toString();
    ui->leCityLedger->fHiddenText = fDD.fDbRows.at(0).at(4).toString();
    ui->leRoom->setText(fDD.fDbRows.at(0).at(5).toString());
    CachePaymentMode pm;
    if (pm.get(ui->lePayment->fHiddenText)) {
        ui->lePayment->setText(pm.fName());
    }
    CacheCreditCard cc;
    if (cc.get(ui->leCardType->fHiddenText)) {
        setModeCard();
        ui->leCardType->setText(cc.fName());
    }
    CacheCityLedger cl;
    if (cl.get(ui->leCityLedger->fHiddenText)) {
        setModeCityLedger();
        ui->leCityLedger->setText(cl.fName());
    }
    if (ui->leRoom->text().toInt() > 0) {
        fDD[":f_room"] = ui->leRoom->text().toInt();
        fDD[":f_state"] = RESERVE_CHECKIN;
        fDD.exec("select r.f_invoice, g.guest, f_room from f_reservation r "
                   "left join guests g on g.f_id=r.f_guest "
                   "where r.f_room=:f_room and r.f_state=:f_state");
        if (fDD.nextRow()) {
            setModeRoom();
            ui->leRoom->setText(fDD.getString(2));
            ui->leInvoice->setText(fDD.getString(0));
            ui->leGuest->setText(fDD.getString(1));
        }
    }
    ui->btnPrePrint->setEnabled(false);
    ui->btnPrint->setEnabled(true);

    fTrackControl->insert("Open draft", "", "");
    fTrackControl->saveChanges();
}
