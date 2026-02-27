#include "pprintvaucher.h"
#include "pprintpreview.h"
#include "ptextrect.h"
#include "pimage.h"
#include "cacheusers.h"
#include "message.h"
#include "cachevaucher.h"
#include "basewidget.h"
#include "cachepaymentmode.h"
#include "cachecityledger.h"
#include "cachecreditcard.h"
#include "cacheinvoiceitem.h"
#include "paymentmode.h"
#include "defines.h"

PPrintVaucher::PPrintVaucher() :
    Base()
{
}

void PPrintVaucher::printVaucher(const QString &id)
{
    PPrintVaucher p;
    PPrintPreview *pv = new PPrintPreview(fMainWindow->fPreferences.getDefaultParentForMessage());
    PPrintScene *ps = pv->addScene(0,QPageLayout::Portrait);
    DoubleDatabase fDD;
    fDD.startTransaction();
    fDD[":f_id"] = id;
    fDD.exec("select f_source, f_user, f_room, f_guest, m.f_id, f_wdate, "
             "f_paymentMode, f_amountAmd, f_amountVat, f_amountAmd / f_amountUsd, "
             "f_creditCard, f_cityLedger, "
             "f_canceled, f_cancelDate, u.f_username, m.f_finalName, "
             "m.f_finance, concat(uo.f_firstName, ' ', uo.f_lastName), "
             "m.f_paymentMode, m.f_remarks "
             "from m_register m "
             "left join users u on u.f_id=m.f_cancelUser "
             "left join users uo on uo.f_id=m.f_user "
             "where m.f_id=:f_id");

    if(!fDD.nextRow()) {
        message_error("Application error. Contact to developer. Message: PrintVoucher row count=0");
        fDD.commit();
        return;
    }

    QList<QList<QVariant> >& fDbRows = fDD.fDbRows;
    int room = fDbRows.at(0).at(2).toInt();
    DoubleDatabase reserv;
    reserv.open();

    if(room > 0) {
        DoubleDatabase dq;
        dq.open();
        dq[":f_id"] = id;
        dq.exec("select f_inv from m_register where f_id=:f_id");
        dq.nextRow();
        reserv[":f_invoice"] = dq.getValue(0);
        reserv.exec("select r.f_startDate, r.f_checkInUser, r.f_endDate, r.f_checkOutUser, "
                    "r.f_checkInTime, r.f_checkOutTime "
                    "from f_reservation r "
                    "where r.f_invoice=:f_invoice");
    }

    CacheVaucher cv;

    if(!cv.get(fDbRows.at(0).at(0).toString())) {
        message_error("Application error. Contact to developer. Message: PrintVoucher cv=0");
        fDD.commit();
        return;
    }

    int top = 10;
    PTextRect *trHeader = new PTextRect(20, top, 2000, 80, cv.fName(), 0, QFont("Arial", 50));
    top += trHeader->textHeight();
    trHeader->setBorders(false, false, false, false);
    trHeader->setTextAlignment(Qt::AlignHCenter);
    QString inv = QString("S/N %1").arg(fDbRows.at(0).at(4).toString());
    PTextRect *trInvoice = new PTextRect(20, trHeader->textHeight(), 2000, 80, inv, 0, QFont("Arial", 30));
    top += trInvoice->textHeight();
    trInvoice->setTextAlignment(Qt::AlignHCenter);
    trInvoice->setBorders(false, false, false, false);
    PTextRect *trInfo = new PTextRect(1500, 20, 500, 400, fPreferences.getDb(def_vouchers_right_header).toString(),
                                      0, QFont("Arial", 25));
    int rowHeight = 80;
    QPen boldPen(Qt::black);
    boldPen.setWidth(6);
    QFont f("Arial", 30);
    f.setItalic(true);
    f.setBold(true);
    PTextRect th;
    th.setRectPen(boldPen);
    th.setBorders(false, false, false, false);
    th.setFont(f);
    th.setTextAlignment(Qt::AlignHCenter);

    if(fDbRows.at(0).at(12).toInt() == 1) {
        top += ps->addTextRect(20, top, 2000, 80, QObject::tr("CORRECTION"), &th)->textHeight();
        f.setPointSize(20);
        f.setItalic(false);
        f.setBold(false);
        th.setFont(f);
        ps->addTextRect(20, top, 2000, 80, QString("[%1: %2  %3: %4]")
                        .arg(QObject::tr("DATE"))
                        .arg(fDbRows.at(0).at(13).toDate().toString(def_date_format))
                        .arg(QObject::tr("OPERATOR"))
                        .arg(fDbRows.at(0).at(14).toString()),
                        &th);
    }

    top += trInfo->textHeight();
    trInfo->setTextAlignment(Qt::AlignTop | Qt::AlignRight);
    trInfo->setBorders(false, false, false, false);
    ps->addItem(trInfo);
    ps->addItem(trInvoice);
    ps->addItem(trHeader);
    PImage *logo = new PImage("logo_print.png");
    ps->addItem(logo);
    logo->setRect(QRectF(20, 10, 500, 300));
    top = 320;
    ps->addLine(10, top, 2100, top, boldPen);
    top += 10;
    f.setPointSize(30);
    f.setItalic(false);
    f.setBold(false);
    th.setFont(f);
    th.setBorders(true, true, true, true);
    th.setTextAlignment(Qt::AlignHCenter);
    QList<int> cols;
    QStringList vals;
    int vatWidth = (fDbRows.at(0).at(2).toDouble() > 0.1 ? 200 : 0);
    vatWidth = 0 ;
    cols << 20 << 350 << 200 << 500 << vatWidth << 1050 - vatWidth;
    vals << QObject::tr("Date")
         << QObject::tr("Room")
         << QObject::tr("Amount")
         << "" //QObject::tr("VAT")
         << QObject::tr("Purpose")
         ;
    ps->addTableRow(top, rowHeight, cols, vals, &th);
    vals << fDbRows.at(0).at(5).toDate().toString(def_date_format)
         << fDbRows.at(0).at(2).toString()
         << QString("%1 AMD").arg(float_str(fDbRows.at(0).at(7).toDouble(), 2))
         << ""//(vatWidth == 0 ? "" : fDbRows.at(0).at(8).toString())
         << fDbRows.at(0).at(15).toString();
    ps->addTableRow(top, rowHeight, cols, vals, &th);

    if(fDbRows.at(0).at(16).toInt() == 1) {
        top += 10;
        cols.clear();
        cols << 20 << 1080 << 1000;
        vals << QObject::tr("Mode of Payment")
             << QObject::tr("Additional info");
        ps->addTableRow(top, rowHeight, cols, vals, &th);
        CachePaymentMode pm ;

        if(!pm.get(fDbRows.at(0).at(18).toString())) {
            message_error(QObject::tr("Application error. Contact to developer. Message PrintVoucher pm=0"));
            return;
        }

        vals << pm.fName();
        QString pmInfo;

        switch(pm.fCode().toInt()) {
        case PAYMENT_CASH:
            break;

        case PAYMENT_CARD: {
            CacheCreditCard ccc;
            ccc.get(fDbRows.at(0).at(10).toString());
            pmInfo = ccc.fName();
            break;
        }

        case PAYMENT_CL: {
            CacheCityLedger ccl;

            if(ccl.get(fDbRows.at(0).at(11).toString())) {
                pmInfo = ccl.fName();
            } else {
                pmInfo = "-";
            }

            break;
        }
        }

        vals << pmInfo;
        ps->addTableRow(top, rowHeight, cols, vals, &th);
    }

    top += 10;
    cols.clear();
    cols << 20 << 380 << 700 << 400 << 600;
    vals << QObject::tr("Guest name")
         << fDbRows.at(0).at(3).toString()
         << QObject::tr("Operator")
         << fDbRows.at(0).at(17).toString();
    th.setWrapMode(QTextOption::WordWrap);
    ps->addTableRow(top, rowHeight * 1.5, cols, vals, &th);
    th.setWrapMode(QTextOption::NoWrap);

    if(room > 0 && room < 1000 && reserv.rowCount() > 0) {
        QString checkInUser = "-";
        QString checkOutUser = "-";
        CacheUsers uin;

        if(uin.get(reserv.getValue(0, "f_checkInUser").toString())) {
            checkInUser = uin.fFull();
        }

        CacheUsers uout;

        if(uout.get(reserv.getValue(0, "f_checkOutUser").toString())) {
            checkOutUser = uout.fFull();
        }

        cols.clear();
        cols << 20 << 380 << 700 << 400 << 600;
        vals << QObject::tr("Arrival date")
             << reserv.getValue(0, "f_startDate").toDate().toString(def_date_format)
             << QObject::tr("Operator")
             << checkInUser;
        ps->addTableRow(top, rowHeight, cols, vals, &th);
        vals << QObject::tr("Departure date")
             << reserv.getValue(0, "f_endDate").toDate().toString(def_date_format)
             << QObject::tr("Operator")
             << checkOutUser;
        ps->addTableRow(top, rowHeight, cols, vals, &th);
    }

    top += rowHeight;
    QString remarks = fDbRows.at(0).at(19).toString();

    if(!remarks.isEmpty()) {
        top += (rowHeight / 2);
        th.setTextAlignment(Qt::AlignLeft);
        th.setBorders(false, false, false, false);
        th.setWrapMode(QTextOption::WrapAnywhere);
        top += ps->addTextRect(20, top, 2100, rowHeight * 3, QObject::tr("Remarks: ") + remarks,
                               &th)->textHeight() + (rowHeight / 2);
        th.setBorders(true, true, true, true);
    }

    th.setBorders(false, false, false, false);
    vals << QObject::tr("Guest signature")
         << ""
         << QObject::tr("Manager signature")
         << "";
    ps->addTableRow(top, rowHeight, cols, vals, &th);
    top += (rowHeight * 2);
    ps->addLine(20, top, 600, top, boldPen);
    ps->addLine(1100, top, 2100, top, boldPen);
    top += rowHeight;
    QString footer = QString("%1: %2, %3: %4")
                     .arg(QObject::tr("Printed"))
                     .arg(QDateTime::currentDateTime().toString(def_date_time_format))
                     .arg(QObject::tr("Operator"))
                     .arg(WORKING_USERNAME);
    f.setBold(true);
    f.setPointSize(18);
    th.setFont(f);
    th.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(20, top, 2100, rowHeight, footer, &th);
    fDD.commit();
    pv->exec();
    delete pv;
}
