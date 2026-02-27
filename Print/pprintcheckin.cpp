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

void PPrintCheckin::print(const QString &id, bool noPreview)
{
    PPrintCheckin p;
    PPrintPreview pv(fMainWindow->fPreferences.getDefaultParentForMessage());
    PPrintScene *ps = pv.addScene(0,QPageLayout::Portrait);
    /* Data */
    DoubleDatabase fDD;
    fDD[":f_id"] = id;
    fDD.exec("select * from f_reservation where f_id=:f_id");
    if (!fDD.nextRow()) {
        message_error(QObject::tr("Could not open reservation"));
        return;
    }
    PPrintHeader(ps, tr("REGISTRATION CARD"), QString("%1 / %2").arg(fDD.getValue("f_id").toString(),
                 fDD.getValue("f_invoice").toString()));
    int top = 310;
    /* Header */
    PTextRect trHeader;
    trHeader.setBorders(false, false, false, false);
    trHeader.setFontSize(40);
    trHeader.setFontBold(true);
    trHeader.setTextAlignment(Qt::AlignCenter);
    top = 320;
    PTextRect trData;
    trData.setFontName("Times");
    trData.setFontSize(20);
    trData.setTextAlignment(Qt::AlignCenter);
    QList<int> col;
    QStringList val;
    col << 20 << 230 << 230 << 230 << 230 << 230 << 230 << 150 << 550;
    val << tr("ARRIVAL") << tr("DEPARTURE") << tr("ROOM ") << tr("ROOM RATE") << tr("EXTRA BED") << tr("PAX") << tr("ARR.")
        << tr("MODE OF PAYMENT");
    ps->addTableRow(top, 80, col, val, &trData);
    CacheRoomArrangment cra;
    CachePaymentMode cpm;
    if (!cra.get(fDD.getValue("f_arrangement").toString())) {
        message_error(tr("Invalid arrangement code") + "<br>" + fDD.getValue("f_arrangement").toString());
        return;
    }
    if (!cpm.get(fDD.getValue("f_paymentType").toString())) {
        message_error(tr("Invalid payment code") + "<br>" + fDD.getValue("f_paymentType").toString());
        return;
    }
    val << fDD.getValue("f_startDate").toDate().toString(def_date_format)
        << fDD.getValue("f_endDate").toDate().toString(def_date_format)
        << fDD.getValue("f_room").toString()
        << float_str(fDD.getValue("f_roomFee").toDouble(), 2)
        << float_str(fDD.getValue("f_extraBedFee").toDouble(), 2)
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
    DoubleDatabase dguest;
    dguest[":f_id"] = id;
    dguest.exec("select concat(g.f_title, '  ', g.f_lastname, ' ', g.f_firstname, ', ', n.f_name), if(length(coalesce(g.f_passport, 'N/A'))=0,'N/A',coalesce(g.f_passport, 'N/A')) as f_passport "
                "from f_reservation_guests rg "
                "left join f_guests g on g.f_id=rg.f_guest "
                "left join f_nationality n on n.f_short=g.f_nation "
                "where rg.f_reservation in "
                "(select f_id from f_reservation where f_id=:f_id) "
                "order by rg.f_first desc ");
    top += ps->addTextRect(20, top, 2000, 70, tr("Guests:"), &trGuest)->textHeight();
    while (dguest.nextRow()) {
        // top += ps->addTextRect(20, top, 2000, 70, QString("%1, Passport: %2").arg(dguest.getString(0), dguest.getString(1)),
        //                        &trGuest)->textHeight();
        top += ps->addTextRect(20, top, 2000, 70, QString("%1").arg(dguest.getString(0)),
                               &trGuest)->textHeight();
    }
    //    ps->addTextRect(20, top, 230, 80, tr("LAST NAME"), &trGuest);
    //    trGuest.setFontItalic(true);
    //    ps->addTextRect(240, top, 700, 80, g.fLastName(), &trGuest);
    //    trGuest.setFontItalic(false);
    //    ps->addTextRect(710, top, 230, 80, tr("FIRST NAME"), &trGuest);
    //    trGuest.setFontItalic(true);
    //    top += ps->addTextRect(1000, top, 700, 80, g.fFirstName(), &trGuest)->textHeight();
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
    ps->addLine(20, top, 2100, top, QPen(Qt::SolidPattern, 5));
    top += 80;
    trData.setFontBold(true);
    top += ps->addTextRect(20, top, 2100, 80, tr("1- THE MANAGEMENT IS NOT RESPONSIBLE FOR ANY VALUABLES LEFT IN THE ROOM"),
                           &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80,
                           tr("2- SMOKING IN A NON-SMOKING GUEST ROOM, CORRIDORS, OR ANY IN DOORS AREAS "),
                           &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(40, top, 2100, 80,
                           tr("WILL RESULT IN A PENALTY OF 50,000 AMD"),
                           &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80, tr("3- DAMAGE TO PROPERTY IS SUBJECT TO A PENALTY"),
                           &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += 100;
    ps->addTextRect(20, top, 300, 80, tr("GUEST SIGNATURE"), &trData);
    ps->addLine(305, top + 70, 800, top + 70, QPen(Qt::SolidPattern, 3));
    top += 200;
    trData.setTextAlignment(Qt::AlignCenter);
    ps->addTextRect(20, top, 2100, 80, tr("WE WISH YOU A NICE AND PLEASANT STAY!"), &trData);
    top += 200;
    trData.setFontSize(24);
    top += ps->addTextRect(20, top, 2100, 80, tr("BY SIGNING BELOW, I CONFIRM THAT I HAVE READ AND AGREE TO ABIDE"),
                           &trData)->textHeight();
    top += ps->addTextRect(20, top, 2100, 80, tr("BY THE HOTEL RULES, INCLUDING PENALTIES FOR SMOKING AND PROPERTY DAMAGE"),
                           &trData)->textHeight();
    pv.exec(noPreview);
}

/*     top += ps->addTextRect(20, top, 2100, 80, tr("1- ALL RATES ARE SUBJECT 20% V.A.T."), &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80, tr("2- THE MANAGEMENT IS NOT RESPONSIBLE FOR ANY VALUABLE LEFT IN THE ROOM"),
                           &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80,
                           tr("3- YOU WILL FIND A PRESONAL SAFETY DEPOSIT BOX IN YOUR ROOM FOR YOUR CONVEIENCE."), &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80,
                           tr("SHOULD YOU WISH TO USE THE HOTEL'S SAFETY DEPOSIT BOXES AT THE FRONT OFFICE."), &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80,
                           tr("4- FOR YOUR SAFETY, KINDLY NOTE THAT WATER PIPE AND ANY OTHER RELATE ITEMS TO IT ARE NOT ALLOWED IN THE ROOMS."),
                           &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80, tr("5- OUR CHECK OUT TIME IS 12:00 (NOON)."), &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80, tr("6- SMOKING IS NOT PERMITTED, EXCEPT IN THE DESIGNATED SMOKING AREAS."),
                           &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80,
                           tr("SMOKING IS ALLOWED: ON BALCONY (IF YOUR ROOM HAS SUCH), IN THE 3RD FLOOR OPEN AIR TERAZZA (CAFÉ),"),
                           &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80,
                           tr("IN THE HOOKAH CAFÉ (ON THE GROUND FLOOR, NEXT TO THE LOBBY) AND ON THE ENTRANCE AREA OF THE HOTEL."),
                           &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80,
                           tr("7- SMOKING IN A NON-SMOKING GUEST ROOM, CORRIDORS AND ANY OTHER RESTRICTED AREAS WILL RESULT IN CHARGES"),
                           &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += ps->addTextRect(20, top, 2100, 80, tr("AT THE SUM OF 50 000 AMD TO THE OCCUPYING GUEST."),
                           &trData)->textHeight();
    ps->addLine(20, top - 20, 2100, top - 20, QPen(Qt::SolidPattern, 5));
    top += 200;
    trData.setTextAlignment(Qt::AlignCenter);
    ps->addTextRect(20, top, 2100, 80, tr("WE WISH YOU A NICE AND PLEASANT STAY!"), &trData);
    top += 200;
*/
