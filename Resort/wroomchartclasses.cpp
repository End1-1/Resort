#include "wroomchartclasses.h"
#include "defines.h"
#include "wroomcharttime.h"
#include "wroomchart.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>

QFont FONT;
QMap<int, QString> DAYS_OF_WEEK;
QDate fFirstDate = QDate::fromString("01/03/2018", "dd/MM/yyyy");
QDate fLastDate = QDate::fromString("01/01/2021", "dd/MM/yyyy");

QMap<int, int> fRoomRows;
QMap<int, QString> fRoomShort;
QMap<int, int> fRoomState;

QMap<QString, QString> fReserveRoomName;
QMap<QString, QDate> fReserveDateStart;
QMap<QString, QDate> fReserveDateEnd;
QMap<QString, QString> fReserveCardex;
QMap<QString, QString> fReserveGuest;
QMap<QString, int> fReserveState;
QMap<QString, QString> fReserveStateName;
QMap<QString, int> fReserveStatus;
QMap<QString, QString> fReserveStatusName;
QMap<QString, QString> fReserveInvoice;
QMap<QString, int> fReserveGroup;
QMap<QString, QString> fReserveGroupName;

ClearScene::ClearScene() :
    QThread() {
        connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
    }

void ClearScene::addObject(QObject *o) {
    fObjects << o;
}

void ClearScene::run() {
    foreach (QObject *o, fObjects) {
        o->deleteLater();
    }
}

MonthRect::MonthRect(const QDate &date, quint32 width) {
    fDate = date;
    fWidth = width;
}

QRectF MonthRect::boundingRect() const {
    return QRectF(0, 0, fWidth * RECT_SIDE, RECT_SIDE);
}

void MonthRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);
    painter->fillRect(option->rect, Qt::white);
    painter->drawRect(option->rect);
    QString dateStr = fDate.toString("MMMM, yyyy");
    QFont f(FONT.family(), 11);
    painter->setFont(f);
    QTextOption to;
    to.setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    painter->drawText(option->rect, dateStr, to);
}



DateRect::DateRect(const QDate &date) {
    fDate = date;
    setPos(fFirstDate.daysTo(fDate) * RECT_SIDE, RECT_SIDE);
    setFlags(ItemIsSelectable);
    setAcceptHoverEvents(true);
}

QRectF DateRect::boundingRect() const {
    return QRectF(0, 0, RECT_SIDE, RECT_SIDE);
}

void DateRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);
    if (option->state & QStyle::State_Selected) {
        QRect selRect = option->rect;
        painter->fillRect(selRect, VSELECTION_COLOR);
    } else {
        painter->fillRect(option->rect, Qt::white);
    }
    painter->setPen(LIGHT_GRAY);
    painter->drawRect(option->rect);
    if (fDate.dayOfWeek() == 6 || fDate.dayOfWeek() == 7) {
        painter->setPen(Qt::red);
    } else {
        painter->setPen(LIGHT_GRAY);
    }
    QTextOption to;
    to.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QFont f(FONT.family(), 8);
    f.setBold(true);
    painter->setFont(f);
    QRect dayRect = option->rect;
    dayRect.adjust(0, 0, 0, (option->rect.height() / 2) * -1);
    QString day = QString::number(fDate.day());
    painter->drawText(dayRect, day, to);

    QRect dayOfWeekRect = option->rect;
    dayOfWeekRect.adjust(0, option->rect.height() / 2, 0, 0);
    QString dayOfWeek = DAYS_OF_WEEK[fDate.dayOfWeek()];
    painter->drawText(dayOfWeekRect, dayOfWeek, to);
}

RoomRect::RoomRect(int index) {
    fIndex = index;
}

void RoomRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);
    QColor color;
    switch (fRoomState[fIndex]) {
    case ROOM_STATE_NONE:
        color = Qt::white;
        break;
    case ROOM_STATE_CHECKIN:
        color = QColor::fromRgb(70, 170, 255);
        break;
    case ROOM_STATE_DIRTY:
        color = Qt::yellow;
        break;
    default:
        color = Qt::gray;
        break;
    }
    painter->fillRect(option->rect, color);
    QTextOption o;
    o.setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    painter->drawRect(option->rect);
    painter->drawText(option->rect, fRoomShort[fIndex], o);
}

QRectF RoomRect::boundingRect() const {
    return QRectF(0, 0, 79, RECT_SIDE);
}

Reserve::Reserve(const QString &id, WRoomChart *rc) {
    fReserve = id;
    fRoomChart = rc;
    fTimer = nullptr;
    setToolTip(QString("%1 %2\n%3-%4\n%5")
               .arg(fReserveCardex[id])
               .arg(fReserveGuest[id])
               .arg(fReserveDateStart[id].toString(def_date_format))
               .arg(fReserveDateEnd[id].toString(def_date_format))
               .arg(fReserveRoomName[id]));
    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptHoverEvents(true);
    setZValue(Z_VALUE_RESERVE);
}

void Reserve::setWidth(int w) {
    fWidth = w;
    qDebug() << w;
    update();
}

void Reserve::singleClick()
{
    qDebug() << "SINGLE CLICK";
    fRoomChart->singleClick(fReserve);
}

void Reserve::doubleClick()
{
    fRoomChart->doubleClick(fReserve);
}

void Reserve::removeTimer()
{
    fTimer->deleteLater();
    fTimer = nullptr;
}

void Reserve::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);
    int state = fReserveState[fReserve];
    QColor fillColor;
    switch (state) {
    case RESERVE_CHECKIN:
        fillColor = QColor::fromRgb(70, 170, 255);
        break;
    case RESERVE_RESERVE:
        fillColor = QColor::fromRgb(255, 80, 80);
        break;
    case RESERVE_SERVICE:
        fillColor = Qt::magenta;
        break;
    case RESERVE_OUTOFINVENTORY:
    case RESERVE_OUTOFROOM:
        fillColor = QColor::fromRgb(88, 88, 88);
        break;
    default:
        fillColor = Qt::yellow;
        break;
    }
    fillColor = option->state & QStyle::State_MouseOver ? fillColor.light() : fillColor;
    fillColor = option->state & QStyle::State_Sunken ? Qt::green : fillColor;
    QLinearGradient bgFill(0, 0, 0, option->rect.height());
    bgFill.setColorAt(0, fillColor);
    bgFill.setColorAt(0.5, fillColor.light(120));
    bgFill.setColorAt(1, fillColor);
    QBrush brush(bgFill);
    painter->fillRect(option->rect, brush);

    if (fReserveState[fReserve] == RESERVE_RESERVE) {
        switch (fReserveStatus[fReserve]) {
        case CONFIRM_CONFIRM:
            fillColor = Qt::green;
            break;
        case CONFIRM_GUARANTEED:
            fillColor = Qt::yellow;
            break;
        case CONFIRM_TENTATIVE:
            fillColor = Qt::gray;
            break;
        case CONFIRM_WAITING:
            fillColor = Qt::white;
            break;
        default:
            fillColor = Qt::blue;
            break;
        }
        QRect statusRect(3, (option->rect.height() / 2) - 3, 7, 7);
        painter->setBrush(fillColor);
        painter->drawEllipse(statusRect);
    }

    painter->setBrush(Qt::NoBrush);
    painter->drawRect(option->rect);

    QFont f(FONT.family(), 10);
    painter->setFont(f);
    QRectF textRect = option->rect;
    textRect.adjust(13, 2, -2, -2);
    painter->drawText(textRect, fReserveGuest[fReserve]);
}

QRectF Reserve::boundingRect() const {
    if (RECT_SIDE * fWidth > 1000) {
        qDebug() << QRectF(0, 0, (RECT_SIDE * fWidth) - 4, RECT_SIDE - 4);
    }
    return QRectF(0, 0, (RECT_SIDE * fWidth) - 4, RECT_SIDE - 4);
}

void Reserve::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    fTempPoint = pos();
    fColor = Qt::green;
    setZValue(Z_MAX);
    update();
    QGraphicsItem::mousePressEvent(event);
    if (!fTimer) {
        fTimer = new WRoomChartTime(this);
        fTimer->start();
    } else {
        fTimer->incDoubleClick();
    }
}

void Reserve::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseMoveEvent(event);
}

void Reserve::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    setPos(fTempPoint);
    setZValue(Z_VALUE_RESERVE);
    update();
    QGraphicsItem::mouseReleaseEvent(event);
    if (fTimer) {
        fTimer->incDoubleClick();
    }
}

