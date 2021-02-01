#include "dlgbreakfast.h"
#include "ui_dlgbreakfast.h"
#include "epushbutton.h"
#include "rmessage.h"
#include "pprintscene.h"
#include "pimage.h"
#include "paymentmode.h"
#include "ptextrect.h"
#include "vauchers.h"
#include "hall.h"
#include <QScrollBar>
#include <QPrinter>
#include <QPainter>

DlgBreakfast::DlgBreakfast(User *user, QWidget *parent) :
    BaseExtendedDialogR(parent),
    ui(new Ui::DlgBreakfast)
{
    ui->setupUi(this);
    fUser = user;
    if (!fBreakfast.get(fPreferences.getDb(def_auto_breakfast_id).toString())) {
        message_error(tr("Breakfast id not defined. Contact to administrator"));
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_date"] = WORKING_DATE;
    fDD.exec("select m.f_id, r.f_room, ar.f_" + def_lang + ", concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName), "
               "m.f_guests, m.f_show, r.f_mealPrice, ' ', ' ', ' ', ' ', r.f_invoice, m.f_doc "
               "from f_reservation_meal m "
               "inner join f_reservation r on r.f_id=m.f_reservation "
               "inner join f_guests g on g.f_id=r.f_guest "
               "inner join f_room_arrangement ar on ar.f_id=r.f_arrangement "
               "where f_date=:f_date and r.f_arrangement=1 "
               "order by r.f_room ");
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                0, 70, 70, 300, 60, 60, 60, 60, 50, 50, 50, 0, 0);
    Utils::fillTableWithData(ui->tblData, fDD.fDbRows);
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        ui->tblData->item(i, 6)->data(Qt::EditRole).toDouble();
        if (ui->tblData->toString(i, 2) == "B/O") {
            if (ui->tblData->item(i, 6)->data(Qt::EditRole).toDouble() < 0.1) {
                ui->tblData->setValue(i, 6, fBreakfast.fPrice());
            }
        }
        countRow(i);
        EPushButton *btnP = new EPushButton();
        EPushButton *btnM = new EPushButton();
        EPushButton *btnPrint = new EPushButton();
        btnP->setText("+");
        btnM->setText("-");
        btnP->setTag(i);
        btnM->setTag(i);
        btnPrint->setIcon(QIcon(":/images/printer.png"));
        btnPrint->setTag(i);
        QSize s(40, 40);
        btnM->setMinimumSize(s);
        btnM->setMaximumSize(s);
        btnP->setMinimumSize(s);
        btnP->setMaximumSize(s);
        btnPrint->setMinimumSize(s);
        btnPrint->setMaximumSize(s);
        ui->tblData->setCellWidget(i, 8, btnP);
        ui->tblData->setCellWidget(i, 9, btnM);
        if (ui->tblData->toString(i, 2) == "B/O") {
            ui->tblData->setCellWidget(i, 10, btnPrint);
        }
        connect(btnP, SIGNAL(clickedWithTag(int)), this, SLOT(btnPClick(int)));
        connect(btnM, SIGNAL(clickedWithTag(int)), this, SLOT(btnMClick(int)));
        connect(btnPrint, SIGNAL(clickedWithTag(int)), this, SLOT(btnPrint(int)));
    }
    showFullScreen();
}

DlgBreakfast::~DlgBreakfast()
{
    delete ui;
    delete fUser;
}

void DlgBreakfast::btnPClick(int tag)
{
    int c1 = ui->tblData->item(tag, 4)->data(Qt::EditRole).toInt();
    int c2 = ui->tblData->item(tag, 5)->data(Qt::EditRole).toInt();
    if (c2 > c1 - 1) {
        return;
    }
    ui->tblData->item(tag, 5)->setData(Qt::EditRole, c2 + 1);
    countRow(tag);
}

void DlgBreakfast::btnMClick(int tag)
{
    if (ui->tblData->toInt(tag, 12) > 0) {
        message_error(tr("Access denied"));
        return;
    }
    int c2 = ui->tblData->item(tag, 5)->data(Qt::EditRole).toInt();
    if (c2 == 0) {
        return;
    }
    ui->tblData->item(tag, 5)->setData(Qt::EditRole, c2 - 1);
    countRow(tag);
}

void DlgBreakfast::btnPrint(int tag)
{
    HallStruct *hall = Hall::fHallMap[fPreferences.getDb(def_default_hall).toInt()];
    if (!hall) {
        message_error(tr("Hall is not defined. Contact to administrator."));
        return;
    }
    if (ui->tblData->toInt(tag, 5) == 0) {
        message_error(tr("Incorrect guest count"));
        return;
    }
    if (ui->tblData->toInt(tag, 12) == 0) {
        switch (message_yesnocancel(tr("This row not saved. Save now?"))) {
        case RESULT_YES:
            saveRow(tag);
            break;
        case RESULT_NO:
            return;
        case RESULT_CANCEL:
            return;
        }
    } else {
        saveRow(tag);
    }
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
                                     .arg(ui->tblData->toInt(tag, 12)),
                                     &th, f))->textHeight();
    top += ps->addTextRect(10, top, 680, rowHeight, QString("%1: %2").arg(tr("Date")).arg(QDateTime::currentDateTime().toString(def_date_time_format)), &th)->textHeight();
    ps->addLine(10, top, 680, top, boldPen);
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("NAME OF SERVICE:"), &th)->textHeight() + 10;
    f.setPointSize(40);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight + 20, fBreakfast.fName(), &th)->textHeight() + 10;
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("PAX:"), &th)->textHeight() + 10;
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, ui->tblData->toString(tag, 5), &th)->textHeight() + 10;
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("PRICE PER PERSON:"), &th)->textHeight() + 10;
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, float_str(ui->tblData->toDouble(tag, 6), 2) + " AMD", &th)->textHeight() + 10;
    f.setPointSize(24);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("TOTAL AMOUNT:"), &th)->textHeight() + 10;
    f.setPointSize(40);
    f.setBold(true);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, float_str(ui->tblData->toDouble(tag, 7), 2) + " AMD", &th)->textHeight() + 10;
    f.setPointSize(24);
    f.setBold(false);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, tr("EQUIVALENT OF USD:"), &th)->textHeight() + 10;
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, float_str(ui->tblData->toDouble(tag, 7) / def_usd, 2) + " USD", &th)->textHeight() + 10;

    top += rowHeight;
    top += ps->addTextRect(10, top, 680, rowHeight, ui->tblData->toString(tag, 1) + ", " + ui->tblData->toString(tag, 3), &th)->textHeight();
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
}

void DlgBreakfast::countRow(int row)
{
    ui->tblData->setValue(row, 7, ui->tblData->toInt(row, 5) * ui->tblData->toDouble(row, 6));
}

void DlgBreakfast::saveRow(int row)
{
    if (ui->tblData->toDouble(row, 7) < 0.1) {
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.startTransaction();

    int vid = ui->tblData->toInt(row, 12);
    int rid = 0;
    if (vid == 0) {
        fDD[":f_id"] = 0;
        fDD[":f_ref"] = REF_RESERVATION_MEAL;
        vid = fDD.insert("m_v_postcharge", true);
        ui->tblData->setValue(row, 12, vid);
        fDD[":f_id"] = 0;
        rid = fDD.insert("m_register", true);
    } else {
        fDD[":f_source"] = VAUCHER_POSTCHARGE_N;
        fDD[":f_doc"] = vid;
        fDD.exec("select f_id from m_register where f_source=:f_source and f_doc=:f_doc");
        if (!fDD.nextRow()) {
            message_error("Application error. Contact to developer. Message: Breakfast, save row, fDbRows==0");
            return;
        }
        rid = fDD.getInt(0);
    }

    fDD[":f_source"] = VAUCHER_POSTCHARGE_N;
    fDD[":f_wdate"] = WORKING_DATE;
    fDD[":f_rdate"] = QDate::currentDate();
    fDD[":f_time"] = QTime::currentTime();
    fDD[":f_user"] = fUser->fId;
    fDD[":f_room"] = ui->tblData->toString(row, 1);
    fDD[":f_guest"] = ui->tblData->toString(row, 3);
    fDD[":f_itemCode"] = fBreakfast.fCode();
    fDD[":f_finalName"] = QString("%1 #%2").arg(fBreakfast.fName()).arg(vid);
    fDD[":f_amountAmd"] = ui->tblData->toDouble(row, 7);
    fDD[":f_amountVat"] = Utils::countVATAmount(ui->tblData->toDouble(row, 7), VAT_INCLUDED);
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = 0;
    fDD[":f_paymentMode"] = PAYMENT_CREDIT;
    fDD[":f_creditCard"] = 0;
    fDD[":f_cityLedger"] = 0;
    fDD[":f_paymentComment"] = "";
    fDD[":f_dc"] = "DEBIT";
    fDD[":f_sign"] = 1;
    fDD[":f_doc"] = vid;
    fDD[":f_rec"] = 0;
    fDD[":f_inv"] = ui->tblData->toInt(row, 11);
    fDD[":f_finance"] = 1;
    fDD[":f_remarks"] = "";
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    fDD[":f_side"] = 0;
    fDD.update("m_register", where_id(rid));

    fDD[":f_show"] = ui->tblData->toInt(row, 5);
    fDD[":f_doc"] = vid;
    fDD.update("f_reservation_meal", where_id(ui->tblData->toInt(row, 0)));
    fDD.commit();
}

void DlgBreakfast::on_btnExit_clicked()
{
    reject();
}

void DlgBreakfast::on_btnSave_clicked()
{
    for (int i = 0; i < ui->tblData->rowCount(); i ++) {
        if (ui->tblData->toInt(i, 12) == 0 && ui->tblData->toString(i, 2) == "B/O") {
            saveRow(i);
        }
    }
    message_info(tr("Saved"));
}

void DlgBreakfast::on_btnUp_clicked()
{
    ui->tblData->verticalScrollBar()->setValue(ui->tblData->verticalScrollBar()->value() - 10);
}

void DlgBreakfast::on_btnDown_clicked()
{
    ui->tblData->verticalScrollBar()->setValue(ui->tblData->verticalScrollBar()->value() + 10);
}
