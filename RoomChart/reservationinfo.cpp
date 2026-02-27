#include "reservationinfo.h"
#include "wreservation.h"
#include "dlgreservequickinfo.h"
#include "winvoice.h"
#include "timerblya.h"
#include "logging.h"
#include "chardefaults.h"
#include <QPainter>
#include <QApplication>

Preferences ReservationInfo::fPref;

static QColor chmStatus[][2] = {
    {QColor(255, 100,255), QColor::fromRgb(255,50,255)},
    {QColor(255, 100,255), QColor(255, 50,255)}
};

static QColor rc[][2] = {
    {Qt::white, Qt::white},
    {QColor::fromRgb(__ss.value("checkincolor", -16733441).toInt()), QColor::fromRgb(70, 170, 255)},
    { QColor::fromRgb(__ss.value("reservecolor", -42403).toInt()), QColor::fromRgb(255, 80, 80)},
    {QColor::fromRgb(88, 88, 88), QColor::fromRgb(170, 170, 170)},
    {QColor::fromRgb(88, 88, 88), QColor::fromRgb(170, 170, 170)},
    {QColor::fromRgb(88, 88, 88), QColor::fromRgb(170, 170, 170)},
    {QColor::fromRgb(88, 88, 88), QColor::fromRgb(170, 170, 170)}
};

static const QColor rs[] = {
    Qt::green,
    Qt::yellow,
    Qt::gray,
    Qt::white
};

ReservationInfo::ReservationInfo(const QString &reserveCode, QGraphicsItem *parent) :
    QGraphicsItem(parent)
{


    if (!fReservation.get(reserveCode)) {
        writelog("Cannooooooooooot get reservation reservationinfo.cpp line ~33");
    }

    fRect.setHeight(ROW_HEIGHT );
    int div = 1;
    if (fReservation.hasNext()) {
        div = 2;
    }

    //RESERVATION ON ROOM CHART
    div = 2;
    int offcetX = fReservation.hasPrev() ? COLUMN_WIDTH / 2 : 0;
    if (fReservation.fDateEnd() > fReservation.fDateStart()) {
        fRect.setWidth(COLUMN_WIDTH * fReservation.fDateStart().daysTo(fReservation.fDateEnd()) + (COLUMN_WIDTH / div) - offcetX);
    } else {
        fRect.setWidth(COLUMN_WIDTH / 2);
    }

    p.setX(xFromDate(fReservation.fDateStart()) + offcetX);

    fBtnRect = QRect(0, 0, 25, 25);
    //fPixmap.load(":/images/info.png");
    fTimer =  new TimerBlya(this);
    QString tp = QString("%1 %2\r\n%3-%4\r\n%5")
            .arg(fReservation.fCardexName())
            .arg(fReservation.fGuest())
            .arg(fReservation.fDateStart().toString(def_date_format))
            .arg(fReservation.fDateEnd().toString(def_date_format))
            .arg(fReservation.fRoomShort());
    setToolTip(tp);

}

ReservationInfo::~ReservationInfo()
{
    fTimer->deleteLater();
}

QRectF ReservationInfo::boundingRect() const
{
    return fRect;
}

void ReservationInfo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget)
    if (fReservation.fData.count() == 0) {
        setVisible(false);
        delete this;
        return;
    }
    QColor mainColor = rc[fReservation.fState()][0];
    switch (fReservation.fState()) {
    case RESERVE_CHECKIN:
        if (fReservation.fDoNotDisturbe()) {
            mainColor = QColor::fromRgb(__s.value("donotdisturbecolor", -5570689).toInt());
        }
    break;
    case RESERVE_RESERVE:
        break;
    default:
        setVisible(false);
        delete this;
        return;
    }
    if (!fReservation.fValid) {
        setVisible(false);
        delete this;
        return;
    }
    if (fReservation.fChmStatus() > 0 && fReservation.fState() != RESERVE_CHECKIN) {
        mainColor = chmStatus[fReservation.fChmStatus() - 1][1];
    }

    QRect rect = option->rect;
    QColor alpha = mainColor;
    alpha = alpha.lighter(110);
    QLinearGradient bgFill(0, 0, 0, rect.height());
    bgFill.setColorAt(0, mainColor);
    bgFill.setColorAt(0.5, alpha);
    bgFill.setColorAt(1, mainColor);
    QBrush brush(bgFill);
    painter->fillRect(rect, brush);
    painter->setPen(Qt::gray);
    painter->drawRect(0, 0, rect.width(), rect.height());
    QRect intRect = rect;
    intRect.adjust(1, 1, -1, -1);
    painter->setPen(Qt::white);
    painter->drawRect(intRect);
    QFont f(qApp->font().family(), 8);
    f.setBold(true);
    painter->setFont(f);
    int leftOffcet = 15;
    if (fReservation.fState() == RESERVE_RESERVE) {
        int a = leftOffcet;
        if (fReservation.fDateStart() == fReservation.fDateEnd()) {
            a -= 12;
        }
        QRect statusRect(a, (option->rect.height() / 2) - 3, 7, 7);
        leftOffcet += 10;

        painter->setBrush(rs[fReservation.fStatus() - 1]);
        painter->drawEllipse(statusRect);
    }
    QTextOption to;
    if (fReservation.fState() == RESERVE_CHECKIN) {
        to.setAlignment(Qt::AlignRight);
    }
    if (ROW_HEIGHT >=30 ) {
        QRect textRect = rect;
        painter->setPen(rc[fReservation.fState()][1]);
        textRect.adjust(leftOffcet, 2, -3, (-1 * (textRect.height() / 2)) + 3);
        painter->drawText(textRect, fReservation.fGuest(), to);
        painter->setPen(Qt::black);
        textRect.adjust(-1, -1, 0, 0);
        painter->drawText(textRect, fReservation.fGuest(), to);
        QRect dateRect = rect;
        dateRect.adjust(2, (dateRect.height() / 2), -3, -2);
        QString strDate = QString("%1 - %2")
                .arg(fReservation.fDateStart().toString("dd/MM"))
                .arg(fReservation.fDateEnd().toString("dd/MM"));
        if (fReservation.fState() == RESERVE_RESERVE) {
            if (fReservation.fAdvance().toDouble() > 0.01) {
                strDate += " (" + fReservation.fAdvance() + "AMD)";
            }
        }
        painter->drawText(dateRect, strDate, to);
    } else {
        QRect textRect = rect;
        to.setWrapMode(QTextOption::NoWrap);
        to.setAlignment(Qt::AlignVCenter);
        if (fReservation.fState() == RESERVE_CHECKIN) {
            int ofr = (fReservation.fDateStart()
                       .daysTo(QDate::fromString(fPref.getDb(def_working_day).toString(), def_date_format)) * COLUMN_WIDTH);
            textRect.adjust(ofr, 0, 0, 0);
        }
//        painter->setPen(Qt::black);
        textRect.adjust(leftOffcet, 2, -2, -2);
//        painter->drawText(textRect, fReservation.fGuest(), to);
        painter->setPen(Qt::black);
        textRect.adjust(-1, -1, 0, 0);
        painter->drawText(textRect, fReservation.fGuest(), to);
    }
//    QRect pixRect(rect.left() + rect.width() - 27, rect.top() + 2, 23, 23);
//    painter->fillRect(pixRect, Qt::white);
//    painter->drawPixmap(pixRect, fPixmap);
}

void ReservationInfo::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    fTimer->start();
}

void ReservationInfo::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    fTimer->incDoubleClick();
}

void ReservationInfo::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    fTimer->incDoubleClick();
}

void ReservationInfo::singleClick()
{
    DlgReserveQuickInfo *d = new DlgReserveQuickInfo(fReservation.fId(), fMainWindow);
    d->exec();
    delete d;
}

void ReservationInfo::doubleClick()
{
    switch (fReservation.fState()) {
    case RESERVE_CHECKIN:
       WInvoice::openInvoiceWindow(fReservation.fInvoice());
       break;
    case RESERVE_RESERVE:
        WReservation::openReserveWindows(fReservation.fId());
        break;
    }
}
