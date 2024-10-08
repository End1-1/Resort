#include "pprintreceipt.h"
#include "pprintscene.h"
#include "trackcontrol.h"
#include "ptextrect.h"
#include "pimage.h"
#include "paymentmode.h"
#include "cacheusers.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QPrinterInfo>
#include <QPrintDialog>

PPrintReceipt::PPrintReceipt(const QString &printerName, const QString &number, int user) :
    Base()
{
    DoubleDatabase drh;
    drh.open();
    drh[":f_id"] = number;
    drh.exec("select h.f_name as hname, t.f_name as tname, concat(u.f_firstName, ' ', u.f_lastName)  as staff,\
               oh.f_dateOpen, oh.f_dateClose, oh.f_dateCash, oh.f_total, oh.f_roomComment, oh.f_paymentMode, \
               oh.f_cityLedger, oh.f_paymentModeComment \
               from o_header oh \
               left join r_hall h on h.f_id=oh.f_hall \
               left join r_table t on t.f_id=oh.f_table \
               left join users u on u.f_id=oh.f_staff \
               where oh.f_id=:f_id");

    if (!drh.nextRow()) {
        QMessageBox::warning(0, QObject::tr("Print receipt"), QObject::tr("Incorrect order number"));
        return;
    }

    DoubleDatabase drd;
    drd[":f_header"] = number;
    drd.exec("select od.f_state, d.f_" + def_lang + ", od.f_qty, od.f_price, od.f_total, od.f_complex \
               from o_dish od \
               left join r_dish d on d.f_id=od.f_dish \
               where od.f_header=:f_header and od.f_state in (1, 2, 3) \
               and (od.f_complex=0 or (od.f_complexId=od.f_complex and od.f_complex>0))");


    QList<PPrintScene*> lps;
    PPrintScene *ps = new PPrintScene(Portrait);
    lps.append(ps);
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
    top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight + 10, drh.getValue("hname").toString(), &th, f))->textHeight();
    top += 20;
    f.setPointSize(30);
    th.setFont(f);
    top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, QString("%1 %2")
                                     .arg(QObject::tr("Receipt S/N "))
                                     .arg(number),
                                     &th, f))->textHeight();
    f.setPointSize(24);
    th.setFont(f);
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(new PTextRect(10, top, 150, rowHeight, QObject::tr("Table"), &th, f));
    ps->addTextRect(new PTextRect(160, top, 200, rowHeight, drh.getValue("tname").toString(), &th, f));
    ps->addTextRect(new PTextRect(340, top, 230, rowHeight, QObject::tr("Date"), &th, f));
    top += ps->addTextRect(new PTextRect(450, top, 250, rowHeight, drh.getValue("f_dateCash").toDate().toString(def_date_format), &th, f))->textHeight();
    /*
    ps->addTextRect(new PTextRect(10, top, 150, rowHeight, QObject::tr("Time"), &th, f));
    top += ps->addTextRect(new PTextRect(160, top, 200, rowHeight, QTime::currentTime().toString(def_time_format), &th, f))->textHeight();
    */
    ps->addTextRect(new PTextRect(10, top, 150, rowHeight, QObject::tr("Waiter"), &th, f));
    top += ps->addTextRect(new PTextRect(160, top, 500, rowHeight, drh.getValue("staff").toString(), &th, f))->textHeight();

    ps->addTextRect(new PTextRect(10, top, 150, rowHeight, QObject::tr("Opened"), &th, f));
    top += ps->addTextRect(new PTextRect(160, top, 350, rowHeight, drh.getValue("f_dateOpen").toDateTime().toString(def_date_time_format), &th, f))->textHeight();
    ps->addTextRect(new PTextRect(10, top, 150, rowHeight, QObject::tr("Closed"), &th, f));
    top += ps->addTextRect(new PTextRect(160, top, 350, rowHeight, drh.getValue("f_dateClose").toDateTime().toString(def_date_time_format), &th, f))->textHeight();

    top += 2;
    ps->addLine(10, top, 680, top);
    top ++;
    ps->addTextRect(new PTextRect(10, top, 100, rowHeight, QObject::tr("Qty"), &th, f));
    ps->addTextRect(new PTextRect(110, top, 390, rowHeight, QObject::tr("Description"), &th, f));
    top += ps->addTextRect(new PTextRect(500, top, 200, rowHeight, QObject::tr("Amount"), &th, f))->textHeight();
    ps->addLine(10, top, 680, top);
    top ++;
    f.setPointSize(18);
    f.setBold(true);
    th.setFont(f);

    for (int i = 0; i < drd.rowCount(); i++) {
        if (drd.getValue(i, "f_state").toInt() != DISH_STATE_READY) {
            continue;
        }
        ps->addTextRect(new PTextRect(10, top, 100, rowHeight, float_str(drd.getValue(i, "f_qty").toDouble(), 1), &th, f));
        ps->addTextRect(new PTextRect(110, top, 390, rowHeight, drd.getValue(i, "f_" + def_lang).toString(), &th, f));
        top += ps->addTextRect(new PTextRect(500, top, 200, rowHeight, float_str(drd.getValue(i, "f_total").toDouble(), 2), &th, f))->textHeight();
        if (top > sizePortrait.height()  - 200) {
            top = 10;
            ps = new PPrintScene(Portrait);
            lps.append(ps);
        }
    }
    ps->addLine(10, top, 680, top);
    top += 2;
    f.setPointSize(24);
    th.setFont(f);
    ps->addTextRect(new PTextRect(10, top, 400, rowHeight, QObject::tr("Total, AMD"), &th, f));
    top += ps->addTextRect(new PTextRect(500, top, 200, rowHeight, float_str(drh.getValue("f_total").toDouble(), 2), &th, f))->textHeight();
    ps->addTextRect(new PTextRect(10, top, 400, rowHeight, QObject::tr("Total, USD"), &th, f));
    top += ps->addTextRect(new PTextRect(500, top, 200, rowHeight, float_str(drh.getValue("f_total").toDouble() / def_usd, 2), &th, f))->textHeight();

    top += rowHeight;
    f.setPointSize(28);
    th.setFont(f);
    th.setTextAlignment(Qt::AlignHCenter);

    if (top > sizePortrait.height()  - 200) {
        top = 10;
        ps = new PPrintScene(Portrait);
        lps.append(ps);
    }
    if (!drh.getValue("f_roomComment").toString().isEmpty()) {
       top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, drh.getValue("f_roomComment").toString(), &th, f))->textHeight();
       top += rowHeight;
       top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, QObject::tr("Signature"), &th, f))->textHeight();
       top += rowHeight + 2;
       ps->addLine(150, top, 680, top);
    }

    if (top > sizePortrait.height()  - 200) {
        top = 10;
        ps = new PPrintScene(Portrait);
        lps.append(ps);
    }
    if (drh.getValue("f_paymentMode").toInt() == PAYMENT_COMPLIMENTARY) {
        top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, QObject::tr("COMPLIMENTARY"), &th, f))->textHeight();
    } else {
        top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, QObject::tr("SALES"), &th, f))->textHeight();
    }

    top += rowHeight;
    top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, QObject::tr("Mode Of Payment"), &th, f))->textHeight();
    switch (drh.getValue("f_paymentMode").toInt()) {
    case PAYMENT_CASH:
        top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, QObject::tr("CASH") + "/" + drh.getValue("f_paymentComment").toString(), &th, f))->textHeight();
        break;
    case PAYMENT_CARD:
        top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, QObject::tr("CARD") + "/" + drh.getValue("f_paymentModeComment").toString(), &th, f))->textHeight();
        break;
    case PAYMENT_ROOM:
        top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, drh.getValue("f_paymentModeComment").toString(), &th, f))->textHeight();
        break;
    case PAYMENT_CL:
        top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, "CL/" +
                                             drh.getValue("f_paymentModeComment").toString() +
                                             "(" + drh.getValue("f_cityLedger").toString() + ")", &th, f))->textHeight();
        break;
    case PAYMENT_COMPLIMENTARY:
        top += ps->addTextRect(new PTextRect(10, top, 680, rowHeight, drh.getValue("f_paymentModeComment").toString(), &th, f))->textHeight();
        break;
    }

    top += 10;
    f.setPointSize(28);
    f.setBold(true);
    th.setFont(f);

    bool voida = false;
    for (int i = 0; i < drd.rowCount(); i++) {
        if (drd.getValue(i, "f_state").toInt() != DISH_STATE_REMOVED_STORE) {
            continue;
        }
        voida = true;
    }
    if (voida) {
        top += (rowHeight * 3);
        top += ps->addTextRect(10, top, 600, rowHeight, QObject::tr("****VOID****"), &th)->textHeight();
        for (int i = 0; i < drd.rowCount(); i++) {
            if (drd.getValue(i, "f_state").toInt() != DISH_STATE_REMOVED_STORE) {
                continue;
            }
            ps->addTextRect(new PTextRect(10, top, 100, rowHeight, float_str(drd.getValue(i, "f_qty").toDouble(), 1), &th, f));
            ps->addTextRect(new PTextRect(110, top, 390, rowHeight, drd.getValue(i, "f_" + def_lang).toString(), &th, f));
            top += ps->addTextRect(new PTextRect(400, top, 200, rowHeight, float_str(drd.getValue(i, "f_total").toDouble(), 2), &th, f))->textHeight();
            if (top > sizePortrait.height()  - 200) {
                top = 10;
                ps = new PPrintScene(Portrait);
                lps.append(ps);
            }
        }
    }

    bool mistakea = false;
    for (int i = 0; i < drd.rowCount(); i++) {
        if (drd.getValue(i, "f_state").toInt() != DISH_STATE_REMOVED_STORE) {
            continue;
        }
        mistakea = true;
    }
    if (mistakea) {
        top += rowHeight;
        top += ps->addTextRect(10, top, 600, rowHeight, QObject::tr("****MISTAKE****"), &th)->textHeight();
        for (int i = 0; i < drd.rowCount(); i++) {
            if (drd.getValue(i, "f_state").toInt() != DISH_STATE_REMOVED_NOSTORE) {
                continue;
            }
            ps->addTextRect(new PTextRect(10, top, 100, rowHeight, float_str(drd.getValue(i, "f_qty").toDouble(), 1), &th, f));
            ps->addTextRect(new PTextRect(110, top, 390, rowHeight, drd.getValue(i, "f_" + def_lang).toString(), &th, f));
            top += ps->addTextRect(new PTextRect(400, top, 200, rowHeight, float_str(drd.getValue(i, "f_total").toDouble(), 2), &th, f))->textHeight();
            if (top > sizePortrait.height()  - 200) {
                top = 10;
                ps = new PPrintScene(Portrait);
                lps.append(ps);
            }
        }
    }

    //Finish
    top += rowHeight;
    ps->addTextRect(new PTextRect(10, top, 680, rowHeight, "_", &th, f));

    top += 10;
    f.setPointSize(18);
    f.setBold(false);
    th.setFont(f);
    top += ps->addTextRect(10, top, 680, rowHeight, QString("Printed %1").arg(QDateTime::currentDateTime().toString(def_date_time_format)), &th)->textHeight();
    CacheUsers u;
    if (u.get(user)) {
        top += ps->addTextRect(10, top, 680, rowHeight, QString("By ") + u.fFull(), &th)->textHeight();
    }

    QPrinter printer;
    printer.setPrinterName(printerName.toUpper());
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
    DoubleDatabase fDD;
    fDD[":f_print"] = drh.getValue("f_print").toInt() + 1;
    fDD.update("o_header", where_id(ap(number)));
    TrackControl::insert(TRACK_REST_ORDER, "Print receipt", "", "", "", number);
}

void PPrintReceipt::printOrder(const QString &printerName, const QString &number, int user)
{
    PPrintReceipt(printerName, number, user);
}
