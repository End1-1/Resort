#include "pprintcheckin.h"
#include "pprintheader.h"
#include "pprintscene.h"
#include "ptextrect.h"
#include "pimage.h"
#include "basewidget.h"
#include "pprintpreview.h"
#include "cachepaymentmode.h"
#include "cacheroomarrangment.h"
#include "cacheguest.h"
#include "cachecardex.h"
#include "cachecardexgroup.h"
#include "defines.h"

PPrintCheckin::PPrintCheckin() :
    QObject(),
    Base()
{

}

void PPrintCheckin::print(const QString &id)
{
    PPrintCheckin p;
    PPrintPreview pv(fMainWindow->fPreferences.getDefaultParentForMessage());
    PPrintScene *ps = pv.addScene(0, Portrait);

    int top = 30;
    PImage *logo = new PImage("logo_print.png");
    ps->addItem(logo);
    logo->setRect(QRectF(20, 10, 500, 300));

    /* Header */
    PTextRect trHeader;
    trHeader.setBorders(false, false, false, false);
    trHeader.setFontSize(40);
    trHeader.setFontBold(true);
    trHeader.setTextAlignment(Qt::AlignCenter);
    top += ps->addTextRect(0, top, 2100, 80, tr("REGISTRATION CARD"), &trHeader)->textHeight();
    /* Data */
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_id"] = id;
    fDD.exec("select * from f_reservation where f_id=:f_id");
    if (!fDD.nextRow()) {
        message_error(QObject::tr("Could not open reservation"));
        return;
    }
    trHeader.setFontSize(30);
    ps->addTextRect(0, top, 2100, 80, fDD.getValue("f_id").toString(), &trHeader);

    top = 300;
    PTextRect trData;
    trData.setFontName("Times");
    trData.setFontSize(20);
    trData.setTextAlignment(Qt::AlignCenter);
    QList<int> col;
    QStringList val;
    col << 20 << 230 << 230 << 230 << 230 << 230 << 230 << 150 << 550;
    val << tr("ARRIVAL") << tr("DEPARTURE") << tr("ROOM ") << tr("ROOM RATE") << tr("EXTRA BED") << tr("PAX") << tr("ARR.") << tr("MODE OF PAYMENT");
    ps->addTableRow(top, 80, col, val, &trData);
    CacheRoomArrangment cra;
    CachePaymentMode cpm;
    cra.get(fDD.getValue("f_arrangement").toString());
    cpm.get(fDD.getValue("f_paymentType").toString());
    val << fDD.getValue("f_startDate").toDate().toString(def_date_format)
        << fDD.getValue("f_endDate").toDate().toString(def_date_format)
        << fDD.getValue("f_room").toString()
        << float_str(fDD.getValue("f_roomFee").toDouble(), 0)
        << float_str(fDD.getValue("f_extraBedFee").toDouble(), 0)
        << QString::number(fDD.getValue("f_man").toInt() + fDD.getValue("f_woman").toInt() + fDD.getValue("f_child").toInt())
        << cra.fName()
        << cpm.fName();
    ps->addTableRow(top, 80, col, val, &trData);
    top += 10;
    ps->addLine(20, top, 2100, top, QPen(Qt::SolidPattern, 5));
    top += 10;

    /* Guest info */
    PTextRect trGuest;
    trGuest.setBorders(false, false, false, false);
    trGuest.setFontName("Times");
    trGuest.setFontSize(24);
    CacheGuest g;
    g.get(fDD.getValue("f_guest").toString());
    ps->addTextRect(20, top, 230, 80, tr("LAST NAME"), &trGuest);
    trGuest.setFontItalic(true);
    ps->addTextRect(240, top, 700, 80, g.fLastName(), &trGuest);
    trGuest.setFontItalic(false);
    ps->addTextRect(710, top, 230, 80, tr("FIRST NAME"), &trGuest);
    trGuest.setFontItalic(true);
    top += ps->addTextRect(1000, top, 700, 80, g.fFirstName(), &trGuest)->textHeight();

    trData.setBorders(false, false, false, false);
    trData.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(20, top, 230, 80, tr("ADDRESS"), &trData);
    ps->addLine(235, top + 80, 2100, top + 80, QPen(Qt::SolidPattern, 3));
    top += 80;
    ps->addLine(235, top + 80, 2100, top + 80, QPen(Qt::SolidPattern, 3));
    top += 80;
    ps->addLine(235, top + 80, 2100, top + 80, QPen(Qt::SolidPattern, 3));
    top += 80;
    ps->addTextRect(20, top, 230, 80, tr("TEL."), &trData);
    ps->addLine(235, top + 80, 830, top + 80, QPen(Qt::SolidPattern, 3));
    ps->addTextRect(835, top, 230, 80, tr("FAX"), &trData);
    ps->addLine(1065, top + 80, 1600, top + 80, QPen(Qt::SolidPattern, 3));
    top += 80;
    ps->addTextRect(20, top, 230, 80, tr("P.O.B."), &trData);
    ps->addLine(235, top + 80, 830, top + 80, QPen(Qt::SolidPattern, 3));
    ps->addTextRect(835, top, 230, 80, tr("EMAIL"), &trData);
    ps->addLine(1065, top + 80, 1600, top + 80, QPen(Qt::SolidPattern, 3));
    top += 80;

    CacheCardex c;
    if (c.get(fDD.getValue("f_cardex").toString())) {
        ps->addTextRect(20, top, 230, 80, tr("CARDEX"), &trData);
        ps->addTextRect(235, top, 800, 80, c.fCode() + c.fName(), &trData);
        CacheCardexGroup cg;
        if (cg.get(c.fGroup())) {
            ps->addTextRect(805, top, 300, 80, tr("MARKET SIGMENT"), &trData);
            ps->addTextRect(1110, top, 600, 80, cg.fCode() + " " + cg.fName(), &trData);
        }
        top += 80;
    }
    top += 5;
    ps->addLine(20, top, 2100, top, QPen(Qt::SolidPattern, 5));
    top += 10;

    ps->addTextRect(20, top, 230, 80, tr("NATIONALITY"), &trData);
    top += ps->addTextRect(235, top, 800, 80, g.fNatShort() + " " + g.fNatFull(), &trData)->textHeight();
    ps->addTextRect(20, top, 230, 80, tr("PASSPORT"), &trData);
    ps->addTextRect(235, top, 500, 80, g.fPassport(), &trData);
    top += 80;
    ps->addLine(20, top, 2100, top, QPen(Qt::SolidPattern, 5));
    top += 80;

    trData.setFontBold(true);
    top += ps->addTextRect(20, top, 2100, 80, tr("1- ALL RATES ARE SUBJECT 20% V.A.T."), &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80, tr("2- THE MANAGEMENT IS NOT RESPONSIBLE FOR ANY VALUABLE LEFT IN THE ROOM"), &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80, tr("3- YOU WILL FIND A PRESONAL SAFETY DEPOSIT BOX IN YOUR ROOM FOR YOUR CONVEIENCE."), &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80, tr("SHOULD YOU WISH TO USE THE HOTEL'S SAFETY DEPOSIT BOXES AT THE FRON OFFICE, US $10 PER DAY WILL APPLY."), &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80, tr("4- FOR YOUR SAFETY, KINDLY NOTE THAT WATER PIPE AND ANY OTHER RELATE ITEMS TO IT ARE NOT ALLOWED IN THE ROOMS."), &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80, tr("5- OUR CHECK OUT TIME IS 12:00 (NOON)."), &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));

    top += 200;
    trData.setTextAlignment(Qt::AlignCenter);
    ps->addTextRect(20, top, 2100, 80, tr("WE WISH YOU A NICE AND PLEASANT STAY!"), &trData);
    top += 200;
    ps->addTextRect(20, top, 300, 80, tr("GUEST SIGNATURE"), &trData);
    ps->addLine(305, top + 70, 800, top + 70, QPen(Qt::SolidPattern, 3));


    pv.exec();
}