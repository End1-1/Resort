#include "wroomchartclasses.h"
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include "chardefaults.h"
#include "defines.h"
#include "wroomchart.h"
#include "wroomcharttime.h"

QFont FONT;
QMap<int, QString> DAYS_OF_WEEK;
QDate fFirstDate = QDate::fromString("01/01/2021", "dd/MM/yyyy");
QDate fLastDate = QDate::fromString("01/01/2022", "dd/MM/yyyy");

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

MonthRect::MonthRect(const QDate &date, qint32 width) {
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
        color = QColor::fromRgb(__ss.value("checkincolor", -16733441).toInt());
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
    fOffcet = 0;
    fTimer = nullptr;
    fMouseMove = false;
    setToolTip(QString("%1 %2\n%3-%4\n%5")
               .arg(fReserveCardex[id])
               .arg(fReserveGuest[id])
               .arg(fReserveDateStart[id].toString(def_date_format))
               .arg(fReserveDateEnd[id].toString(def_date_format))
               .arg(fReserveRoomName[id]));
    setFlags(ItemIsSelectable);
    setAcceptHoverEvents(true);
    qreal zvalue = fReserveState[id] == RESERVE_RESERVE ? Z_VALUE_RESERVE : Z_VALUE_CHECKIN;
    setZValue(zvalue);
    if (fReserveState[fReserve] == RESERVE_CHECKIN) {
        fOffcet = (fReserveDateStart[id].daysTo(__preferences.getLocalDate(def_working_day))) * RECT_SIDE;
        fOffcet -= 13;
    }
}

void Reserve::setWidth(int w) {
    fWidth = w;
    update();
}

int Reserve::width()
{
    return boundingRect().width();
}

void Reserve::singleClick()
{
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
        fillColor = QColor::fromRgb(__ss.value("checkincolor", -16733441).toInt());
        break;
    case RESERVE_RESERVE:
        fillColor = QColor::fromRgb(__ss.value("reservecolor", -42403).toInt());
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
    fillColor = option->state & QStyle::State_MouseOver ? fillColor.lighter(150) : fillColor;
    fillColor = option->state & QStyle::State_Sunken ? Qt::green : fillColor;
    QLinearGradient bgFill(0, 0, 0, option->rect.height());
    bgFill.setColorAt(0, fillColor);
    bgFill.setColorAt(0.5, fillColor.lighter(120));
    bgFill.setColorAt(1, fillColor);
    QBrush brush(bgFill);
    painter->fillRect(option->rect, brush);

    if (fReserveState[fReserve] == RESERVE_RESERVE && fWidth > 1) {
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
        QRect statusRect(3 + fOffcet, (option->rect.height() / 2) - 3, 7, 7);
        painter->setBrush(fillColor);
        painter->drawEllipse(statusRect);
    }

    painter->setBrush(Qt::NoBrush);
    painter->setPen(QColor::fromRgb(100, 100, 100));
    painter->drawRect(option->rect);

    if (fOffcet > 0 && !fMouseMove) {
        painter->setPen(QPen(Qt::white, 2));
        painter->drawLine(option->rect.x() + fOffcet - 1, option->rect.y(), option->rect.x() + fOffcet - 1, option->rect.y() + option->rect.height());
    }

    QFont f(FONT.family(), 9);
    f.setBold(true);
    painter->setFont(f);
    painter->setPen(QColor::fromRgb(20, 20, 20));
    QRectF textRect = option->rect;
    textRect.adjust(13 + fOffcet, 2, -2, -2);
    painter->drawText(textRect, fReserveGuest[fReserve]);
}

QRectF Reserve::boundingRect() const {
    return QRectF(0, 0, (RECT_SIDE * fWidth) - 2 - (RECT_SIDE / 2), RECT_SIDE - 4);
}

void Reserve::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    fTempPoint = pos();
    fMouseOffcetX = event->scenePos().x() - fTempPoint.x();
    fMouseOffcetY = event->scenePos().y() - fTempPoint.y();
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
    fMouseMove = true;
}

void Reserve::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseMoveEvent(event);
    if (fMouseMove) {
        QPointF p = event->scenePos();
        p.setX(p.x() - fMouseOffcetX);
        p.setY(p.y() - fMouseOffcetY);
        setPos(p);
    }
}

void Reserve::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseReleaseEvent(event);
    if (fTimer) {
        if (fTempPoint == event->scenePos()) {
            fTimer->incDoubleClick();
        }
    }
    resetPos();
}

void Reserve::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QGraphicsItem::hoverLeaveEvent(event);
    if (fMouseMove) {
        resetPos();
    }
}

void Reserve::resetPos()
{
    setPos(fTempPoint.x(), fTempPoint.y());
    setZValue(Z_VALUE_RESERVE);
    update();
    fMouseMove = false;
}

ChartScene::ChartScene() :
    QGraphicsScene()
{
    addItem(&fTempRect);
    fHandleTempRect = false;
}

void ChartScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
    Reserve *r = dynamic_cast<Reserve*>(itemAt(event->scenePos(), QTransform()));
    if (r) {
        if (event->modifiers() & Qt::ControlModifier) {
            r->resetPos();
            fTempRect.fMouseOffcetX = event->scenePos().x() - r->scenePos().x();
            fTempRect.fMouseOffcetY = event->scenePos().y() - r->scenePos().y();
            fTempRect.fWidth = r->width();
            fTempRect.setRect(r->pos().x() + 2, r->pos().y() + 2, r->width(), RECT_SIDE - 4);
            fTempRect.fFreeMove = true;
            fHandleTempRect = true;
        }
        return;
    }
    fStartPoint = nearestPointLeft(event->scenePos());
    fHandleTempRect = true;
}

void ChartScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
    if (!fHandleTempRect) {
        return;
    }
    if (fTempRect.fFreeMove) {
        QPointF p = event->scenePos();
        p.setX(p.x() - fTempRect.fMouseOffcetX);
        p.setY(p.y() - fTempRect.fMouseOffcetY);
        p = nearestPointLeft(p);
        fTempRect.setRect(p.x(), p.y() + 1, fTempRect.fWidth, RECT_SIDE - 2);
    } else {
        fTempRect.setRect(fStartPoint.x(), fStartPoint.y() + 2, event->scenePos().x() - fStartPoint.x(), RECT_SIDE - 4);
    }
}

void ChartScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
    if (fHandleTempRect) {
        fHandleTempRect = false;
        double posX = fTempRect.rect().x();
        posX /= RECT_SIDE;
        if (fTempRect.rect().width() > 10) {
            emit createReserve(0, posX, &fTempRect);
        } else {
            fTempRect.reset();
        }
    }
    update();
}

QPointF ChartScene::nearestPointLeft(const QPointF &p)
{
    int x = p.x();
    int y = p.y();
    x -= (x % RECT_SIDE);
    y -= (y % RECT_SIDE);
    return QPointF(x + 2, y);
}

QPointF ChartScene::nearestPointRight(const QPointF &p)
{
    int x = p.x();
    int y = p.y();
    x += x - (x % RECT_SIDE);
    y += y + (y % RECT_SIDE);
    return QPointF(x + 2, y);
}


TempRectItem::TempRectItem(QGraphicsItem *parent) :
    QGraphicsRectItem (parent)
{
    setZValue(Z_VALUE_TEMP_RECT);
    fFreeMove = false;
    fMouseOffcetX = 0;
    fMouseOffcetY = 0;
}

void TempRectItem::reset()
{
    setPos(0, 0);
    setRect(0, 0, 0, 0);
    fFreeMove = false;
}

void TempRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    painter->fillRect(option->rect, Qt::magenta);
    QRectF rText = option->rect;
    rText.adjust(2, 2, -2, -2);
    double posX = rect().x();
    posX /= RECT_SIDE;
    QDate d1 = fFirstDate.addDays(posX);
    QDate d2 = fFirstDate.addDays(rect().right() / RECT_SIDE);
    painter->drawText(rText, d1.toString(def_date_format) + "-" + d2.toString(def_date_format));
}
