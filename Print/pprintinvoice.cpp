#include "pprintinvoice.h"
#include "pprintpreview.h"
#include "ptextrect.h"
#include "cacheinvoiceitem.h"
#include "paymentmode.h"
#include "pimage.h"
#include "cacheusers.h"
#include <QApplication>

PPrintInvoice::PPrintInvoice(const QString &id, int side, QWidget *parent) :
    BaseWidget(parent)
{
    fId = id;
    fSide = side;
    previewInvoice();
}

void PPrintInvoice::previewInvoice()
{
    DoubleDatabase fDD(true, doubleDatabase);
    int numNights = 0;
    fDD[":f_invoice"] = fId;
    QString query;
    if (fSide > -1) {
        fDD[":f_side"] = fSide;
        query = "select ic.f_sign, ic.f_wdate, ic.f_paymentMode, ic.f_finalName, "
                "ic.f_amountAmd, ic.f_amountVat, ic.f_dc, ic.f_remarks "
                "from m_register ic "
                "where ic.f_inv=:f_invoice and ic.f_side=:f_side "
                "and ic.f_canceled=0 and ic.f_finance=1 "
                "order by ic.f_wdate, ic.f_id ";
    } else {
        query = "select ic.f_sign, ic.f_wdate, ic.f_paymentMode, ic.f_finalName, "
                "ic.f_amountAmd, ic.f_amountVat, ic.f_dc, ic.f_remarks "
                "from m_register ic "
                "where ic.f_inv=:f_invoice and ic.f_canceled=0 and ic.f_finance=1 "
                "order by ic.f_wdate, ic.f_id ";
    }
    fDD.exec(query);

    DoubleDatabase dh(true);
    dh[":f_invoice"] = fId;
    dh.exec("select concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName) as f_guest, nat.f_name as f_nation, "
               "cat.f_short, cat.f_description, r.f_room, r.f_startDate, "
               "r.f_checkInDate, r.f_checkinTime, r.f_endDate, r.f_man+r.f_woman+r.f_child as f_pax, "
               "r.f_checkOutTime, r.f_author, ar.f_" + def_lang + " as f_arrName, r.f_cardex, ca.f_name as f_cardexName, "
               "r.f_vatMode, vm.f_" + def_lang + " as f_vatModeName, r.f_upgradeFrom, g.f_address, r.f_checkinUser,"
               "nights.ntotal, r.f_checkOutUser "
               "from f_reservation r "
               "inner join f_guests g on g.f_id=r.f_guest "
               "inner join f_room rm on rm.f_id=r.f_room "
               "inner join f_room_classes cat on cat.f_id=rm.f_class "
               "left join f_cardex ca on ca.f_cardex=r.f_cardex "
               "left join f_room_arrangement ar on ar.f_id=r.f_arrangement "
               "left join f_nationality nat on nat.f_short=g.f_nation "
               "inner join f_vat_mode vm on vm.f_id=r.f_vatMode "
               "left join (select f_inv, count(f_id) as ntotal from m_register where f_canceled=0 and f_source='RM' and f_inv=:f_invoice) nights on nights.f_inv=r.f_invoice "
               "where r.f_invoice=:f_invoice ");
    if (!dh.nextRow()) {
        message_error(tr("Cannot print empty invoice. Contact with program developer."));
        return;
    }
    int vatMode = dh.getInt("f_vatMode");
    DoubleDatabase drh(true);
    drh[":f_invoice"] = fId;
    drh.exec("select f_state from f_reservation where f_invoice=:f_invoice");
    drh.nextRow();
    numNights = dh.getInt("ntotal");
    PPrintPreview *pp = new PPrintPreview(this);
    PPrintScene *ps = pp->addScene(0, Portrait);
    QString invHeader = drh.getValue("f_state").toInt() == RESERVE_CHECKOUT ? tr("SETTLEMENT / TAX INVOICE") : tr ("PROFORMA INVOICE");
    PTextRect *trHeader = new PTextRect(20, 20, 2100, 200, invHeader, 0, QFont(qApp->font().family(), 50));
    trHeader->setBorders(false, false, false, false);
    trHeader->setTextAlignment(Qt::AlignHCenter);
//    f.setPointSize(30);
//    trHeader->setFont(f);
    QString inv;
    if (fPreferences.getDb(def_invoice_header_mode).toInt() == 0) {
        inv = QString("%1 #%2, %3")
            .arg(tr("ROOM"))
            .arg(QString("%1").arg(dh.getString("f_room")))
            .arg(fId);
    } else {
        inv = QString("%1 #%2")
                .arg(tr("S/N"))
                .arg(fId);
    }
    PTextRect *trInvoice = new PTextRect(20, trHeader->textHeight(), 2100, 80, inv, 0, QFont(qApp->font().family(), 30, 75));
    trInvoice->setTextAlignment(Qt::AlignHCenter);
    trInvoice->setBorders(false, false, false, false);
    PTextRect *trInfo = new PTextRect(1500, 20, 600, 400, fPreferences.getDb(def_vouchers_right_header).toString(),
                                      0, QFont(qApp->font().family(), 25));
    trInfo->setTextAlignment(Qt::AlignTop | Qt::AlignRight);
    trInfo->setWrapMode(QTextOption::WordWrap);
    trInfo->setBorders(false, false, false, false);
    ps->addItem(trInfo);
    ps->addItem(trInvoice);
    ps->addItem(trHeader);
    PImage *logo = new PImage("logo_print.png");
    ps->addItem(logo);
    logo->setRect(QRectF(20, 10, 500, 300));
    PTextRect th;
    th.setBorders(false, false, false, false);
    PTextRect *r = nullptr;
    QPen pline(Qt::SolidLine);
    pline.setWidth(3);
    QFont f(qApp->font().family(), 25);
    f.setBold(true);
    th.setFont(f);
    th.setRectPen(pline);
    int top = 310;
    int rowHeight = 60;
    r = ps->addTextRect(new PTextRect(20, top, 2100, rowHeight, dh.getString("f_guest"), &th, f));
    top += r->textHeight();
    DoubleDatabase dguest(true);
    dguest[":f_invoice"] = fId;
    dguest.exec("select g.guest from f_reservation_guests rg \
                 left join guests g on g.f_id=rg.f_guest \
                where rg.f_first=0 and rg.f_reservation in (select f_id from f_reservation where f_invoice=:f_invoice) ");
    while (dguest.nextRow()) {
        top += ps->addTextRect(new PTextRect(20, top, 2100, rowHeight, dguest.getString(0), &th, f))->textHeight();
    }
    if (!dh.getString("f_address").isEmpty()) {
        top += ps->addTextRect(20, top, 2100, rowHeight, tr("Address: ") + dh.getString("f_address"), &th)->textHeight();
    }
    top += r->textHeight();
    QPen boldPen;
    boldPen.setWidth(4);
    top += 10;
    ps->addLine(20, top, 2100, top, boldPen);
    //row 1
    ps->addTextRect(new PTextRect(20, top, 300, rowHeight, tr("Nationality"), &th, f));
    ps->addTextRect(new PTextRect(400, top, 400, rowHeight, dh.getString("f_nation"), &th, f));
    ps->addTextRect(new PTextRect(1100, top, 400, rowHeight, tr("Arrival date"), &th, f));
    r = ps->addTextRect(new PTextRect(1500, top, 500, rowHeight, dh.getDate("f_startDate").toString(def_date_format), &th, f));
    top += r->textHeight();
    //row 2
    ps->addTextRect(new PTextRect(20, top, 300, rowHeight, tr("Room category"), &th, f));
    ps->addTextRect(new PTextRect(400, top, 700, rowHeight, dh.getString("f_description"), &th, f));
    ps->addTextRect(new PTextRect(1100, top, 400, rowHeight, tr("Departure date"), &th, f));
    r = ps->addTextRect(new PTextRect(1500, top, 500, rowHeight, dh.getDate("f_endDate").toString(def_date_format), &th, f));
    top += r->textHeight();
    //row 3
    QString room = dh.getString("f_room");
    if (dh.getInt("f_upgradeFrom") > 0) {
        room += "           " + dh.getString("f_upgradeFrom");
    }
    if (fPreferences.getDb(def_invoice_header_mode).toInt()) {
        ps->addTextRect(new PTextRect(20, top, 300, rowHeight, tr("Room "), &th, f));
        ps->addTextRect(new PTextRect(400, top, 400, rowHeight, dh.getString("f_room"), &th, f));
    } else {
        ps->addTextRect(new PTextRect(20, top, 300, rowHeight, tr("S/N "), &th, f));
        ps->addTextRect(new PTextRect(400, top, 500, rowHeight, fId, &th, f));
    }
    ps->addTextRect(new PTextRect(1100, top, 400, rowHeight, tr("Number of nights"), &th, f));
    r = ps->addTextRect(new PTextRect(1500, top, 500, rowHeight, QString::number(numNights), &th, f));
    top += r->textHeight();
    //row 4
    ps->addTextRect(new PTextRect(20, top, 300, rowHeight, tr("CheckIn"), &th, f));
    ps->addTextRect(new PTextRect(400, top, 400, rowHeight, dh.getDate("f_checkInDate").toString(def_date_format), &th, f));
    ps->addTextRect(new PTextRect(1100, top, 400, rowHeight, tr("Number of guests"), &th, f));
    r = ps->addTextRect(new PTextRect(1500, top, 500, rowHeight, dh.getString("f_pax"), &th, f));
    top += r->textHeight();
    //row 5
    ps->addTextRect(new PTextRect(20, top, 300, rowHeight, tr("CheckIn time"), &th, f));
    ps->addTextRect(new PTextRect(400, top, 400, rowHeight, dh.getTime("f_checkInTime").toString(def_time_format), &th, f));
    ps->addTextRect(new PTextRect(1100, top, 400, rowHeight, tr("CheckOut date"), &th, f));
    r = ps->addTextRect(new PTextRect(1500, top, 500, rowHeight, dh.getDate("f_endDate").toString(def_date_format), &th, f));
    top += r->textHeight();
    //row 6
    ps->addTextRect(new PTextRect(20, top, 300, rowHeight, tr("Operator in"), &th, f));
    CacheUsers cu;
    cu.get(dh.getString("f_checkInUser"));
    ps->addTextRect(new PTextRect(400, top, 700, rowHeight, cu.fFull(), &th, f));
    ps->addTextRect(new PTextRect(1100, top, 400, rowHeight, tr("CheckOut time"), &th, f));
    r = ps->addTextRect(new PTextRect(1500, top, 500, rowHeight, dh.getTime("f_checkOutTime").toString(def_time_format), &th,f));
    top += r->textHeight();
    //row 7
    ps->addTextRect(new PTextRect(20, top, 300, rowHeight, tr("Arrangement"), &th, f));
    r = ps->addTextRect(new PTextRect(400, top, 400, rowHeight, dh.getString("f_arrName"), &th, f));
    ps->addTextRect(new PTextRect(1100, top, 400, rowHeight, tr("CheckOut Op."), &th, f));

    if (cu.get(dh.getString("f_checkOutUser"))) {
        r = ps->addTextRect(new PTextRect(1500, top, 500, rowHeight, cu.fFull(), &th,f));
    } else {
        r = ps->addTextRect(new PTextRect(1500, top, 500, rowHeight, "-", &th,f));
    }
    top += r->textHeight();
    //row 8
    ps->addTextRect(new PTextRect(20, top, 300, rowHeight, tr("Cardex"), &th, f));
    r = ps->addTextRect(new PTextRect(400, top, 2000, rowHeight, dh.getString("f_cardex") + " / " + dh.getString("f_cardexName"), &th, f));
    top += r->textHeight();
    top += r->textHeight();
    //table header
    th.setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    th.setBorders(true, true, true, true);
    th.setBrush(QBrush(QColor::fromRgb(215, 215, 215), Qt::SolidPattern));
    ps->addTextRect(new PTextRect(20, top, 60, rowHeight * 2, tr("*"), &th, f));
    ps->addTextRect(new PTextRect(80, top, 200, rowHeight * 2, tr("Date"), &th, f));
    ps->addTextRect(new PTextRect(250, top, 850, rowHeight * 2, tr("Description"), &th, f));
    ps->addTextRect(new PTextRect(1100, top, 100, rowHeight * 2, tr("Cur"), &th, f));
    ps->addTextRect(new PTextRect(1200, top, 300, rowHeight * 2, tr("Debit\n") + " " + dh.getString("f_vatModeName"), &th, f));
    ps->addTextRect(new PTextRect(1500, top, 300, rowHeight * 2, tr("Credit"), &th, f));
    ps->addTextRect(new PTextRect(1800, top, 300, rowHeight * 2, tr("Balance"), &th, f));
    //table data
    f.setBold(false);
    f.setPointSize(f.pointSize() - 2);
    th.setFont(f);
    top += (rowHeight * 2);
    th.setTextAlignment(Qt::AlignLeft);
    th.setWrapMode(QTextOption::NoWrap);
    th.setBrush(QBrush(Qt::white, Qt::SolidPattern));
    int rowNum = 1;
    double lastBalance = 0;
    double totalVat = 0;
    double totalCredit = 0;
    double totalDebet = 0;
    double totalCash = 0;
    double totalCard = 0;
    double totalOther = 0;
    while (fDD.nextRow()) {
        double debet, credit;
        if (fDD.getInt(0) == 1) {
            f.setBold(false);
            th.setFont(f);
            debet =  fDD.getDouble(4);
            credit = 0;
        } else {
            f.setBold(true);
            th.setFont(f);
            debet = 0;
            credit = fDD.getDouble(4);
        }

        ps->addTextRect(new PTextRect(20, top, 60, rowHeight, QString::number(rowNum++), &th, f));
        ps->addTextRect(new PTextRect(80, top, 200, rowHeight, fDD.getDate(1).toString(def_date_format), &th, f));
        ps->addTextRect(new PTextRect(250, top, 850, rowHeight, fDD.getString(3) + " " + fDD.getString(7), &th, f));
        ps->addTextRect(new PTextRect(1100, top, 100, rowHeight, "AMD", &th, f));

        int pMode = fDD.getInt(2);
        if (fDD.getInt(0) <0 ) {
            switch (pMode) {
            case PAYMENT_CARD:
                totalCard += credit;
                break;
            case PAYMENT_CASH:
                totalCash += credit;
                break;
            default:
                totalOther += credit;
                break;
            }
        }
        totalVat += fDD.getDouble(5);
        totalCredit += credit;
        totalDebet += debet;
        lastBalance -= -1 * ((debet) - credit);
        ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, float_printout(debet), &th, f));
        ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, float_printout(credit), &th, f));
        ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, float_printout(lastBalance), &th, f));
        top += rowHeight;
        if (top > 2800) {
            top = 30;
            ps = pp->addScene(0, Portrait);
        }
    }
    top += (rowHeight / 2);
    //ps->addTextRect(new PTextRect(20, top, 60, rowHeight, tr("*"), &th, f));
    //ps->addTextRect(new PTextRect(80, top, 200, rowHeight, tr("Date"), &th, f));
    f.setBold(true);
    th.setFont(f);
    th.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(new PTextRect(250, top,  950, rowHeight, tr("Total amount"), &th, f));
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, float_printout(totalDebet), &th, f));
    ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, float_printout(totalCredit), &th, f));
    ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, float_printout(lastBalance), &th, f));
    top += rowHeight;
    if (top > 2800) {
        top = 30;

        ps = pp->addScene(0, Portrait);
    }
    f.setBold(false);
    th.setFont(f);
    th.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(new PTextRect(250, top,  950, rowHeight, tr("Total cash"), &th, f));
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, float_printout(totalCash), &th, f));
    ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, "", &th, f));
    ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, "", &th, f));
    top += rowHeight;
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0, Portrait);
    }

    th.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(new PTextRect(250, top,  950, rowHeight, tr("Total cashless"), &th, f));
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, float_printout(totalCard + totalOther), &th, f));
    ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, "", &th, f));
    ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, "", &th, f));
    top += rowHeight;
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0, Portrait);
    }

    th.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(new PTextRect(250, top,  950, rowHeight, tr("Being the equivalent of USD"), &th, f));
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, float_printout(totalDebet / def_usd), &th, f));
    ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, float_printout(totalCredit / def_usd), &th, f));
    ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, float_printout(lastBalance / def_usd), &th, f));
    top += rowHeight;
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0, Portrait);
    }
    th.setTextAlignment(Qt::AlignRight);
    if (vatMode == VAT_INCLUDED) {
        ps->addTextRect(new PTextRect(250, top,  950, rowHeight, tr("VAT 20%"), &th, f));
        th.setTextAlignment(Qt::AlignLeft);
        ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, "", &th, f));
        ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, float_printout(totalVat), &th, f));
        ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, "", &th, f));
    }
    top += rowHeight;
    top += rowHeight;
    top += rowHeight;
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0, Portrait);
    }
    th.setBorders(false, false, false, false);
    f.setBold(true);
    th.setFont(f);
    r = ps->addTextRect(new PTextRect(20, top, 400, rowHeight, tr("Guest signature"), &th, f));
    ps->addLine(400, top + r->textHeight(), 1000, top + r->textHeight(), boldPen);
    top += r->textHeight();
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0, Portrait);
    }
    f.setBold(false);
    th.setFont(f);
    r = ps->addTextRect(new PTextRect(20, top, 2000, rowHeight, tr("The sum of only ") + Utils::numberToWords(totalCredit), &th, f));
    top += r->textHeight();
    top += r->textHeight();
    top += r->textHeight();
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0, Portrait);
    }
    f.setPointSize(f.pointSize() - 6);
    th.setFont(f);
    th.setWrapMode(QTextOption::WordWrap);
    ps->addTextRect(new PTextRect(20, top, 2000, rowHeight * 3, fPreferences.getDb(def_vouchers_invoice_footer).toString(), &th, f));
    TrackControl tc(0);
    tc.insert("Print invoice request", fId, "");
    pp->exec();
    delete pp;
}
