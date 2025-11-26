#include "pprintheader.h"
#include "pprintscene.h"
#include "ptextrect.h"
#include "pimage.h"

PPrintHeader::PPrintHeader(PPrintScene *ps, const QString &headerText, const QString &number) :
    Base()
{
    PTextRect *trHeader = new PTextRect(20, 20, 2000, 200, headerText, nullptr, QFont("Arial", 40));
    trHeader->setBorders(false, false, false, false);
    trHeader->setTextAlignment(Qt::AlignHCenter);
    QString inv = QString("#%1").arg(number);
    PTextRect *trInvoice = new PTextRect(20, trHeader->textHeight(), 2000, 80, inv, nullptr, QFont("Arial", 25));
    trInvoice->setTextAlignment(Qt::AlignHCenter);
    trInvoice->setBorders(false, false, false, false);
    PTextRect *trInfo = new PTextRect(1500, 20, 650, 400, fPreferences.getDb(def_vouchers_right_header).toString(),
                                      nullptr, QFont("Arial", 25));
    trInfo->setTextAlignment(Qt::AlignTop | Qt::AlignRight);
    trInfo->setBorders(false, false, false, false);
    ps->addItem(trInvoice);
    ps->addItem(trHeader);
    ps->addItem(trInfo);
    PImage *logo = new PImage("logo_print.png");
    ps->addItem(logo);
    logo->setRect(QRectF(20, 10, 500, 300));
}

PPrintHeader::PPrintHeader(PPrintScene *ps, const QString &headerText, int number) :
    PPrintHeader(ps, headerText, QString("%1").arg(number, fPreferences.getDb(def_vouchers_digits).toString().length(), 10,
                 QChar('0')))
{
}
