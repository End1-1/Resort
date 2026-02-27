#ifndef WROOMCHARTCLASSES_H
#define WROOMCHARTCLASSES_H

#include <QThread>
#include <QGraphicsItem>
#include <QDate>
#include <QFont>
#include <QTimer>
#include <QGraphicsScene>

static const qint32 RECT_SIDE = 22;
static const qreal Z_VALUE_RESERVE = 5;
static const qreal Z_VALUE_CHECKIN = 6;
static const qreal Z_VALUE_GRID_LINE = 4;
static const qreal Z_VALUE_TEMP_RECT = 6;
static const qreal Z_MAX = 10;

extern QFont FONT;
extern QDate fFirstDate;
extern QDate fLastDate;
extern QMap<int, QString> DAYS_OF_WEEK;

extern QMap<int, int> fRoomRows;
extern QMap<int, QString> fRoomShort;
extern QMap<int, int> fRoomState;

extern QMap<QString, QString> fReserveRoomName;
extern QMap<QString, QDate> fReserveDateStart;
extern QMap<QString, QDate> fReserveDateEnd;
extern QMap<QString, QString> fReserveCardex;
extern QMap<QString, QString> fReserveGuest;
extern QMap<QString, int> fReserveState;
extern QMap<QString, QString> fReserveStateName;
extern QMap<QString, int> fReserveStatus;
extern QMap<QString, QString> fReserveStatusName;
extern QMap<QString, QString> fReserveInvoice;
extern QMap<QString, int> fReserveGroup;
extern QMap<QString, QString> fReserveGroupName;

class WRoomChartTime;
class WRoomChart;

class ClearScene : public QThread {

public:
    ClearScene();
    void addObject(QObject *o);

protected:
    virtual void run();

private:
    QList<QObject*> fObjects;
};

class MonthRect : public QGraphicsItem {
public:
    MonthRect(const QDate &date, qint32 width);

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QDate fDate;

    qint32 fWidth;
};

class DateRect : public QGraphicsItem {
public:
    DateRect(const QDate &date);

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QDate fDate;
};

class RoomRect : public QGraphicsItem {
public:
    RoomRect(int index);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private:
    int fIndex;
};

class Reserve : public QGraphicsItem {
public:
    Reserve(const QString &id, WRoomChart *rc);
    void setWidth(int w);
    int width();
    void singleClick();
    void doubleClick();
    void removeTimer();
    void resetPos();
    int fOffcet;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

private:
    QString fReserve;
    int fWidth;
    QColor fColor;
    QPointF fTempPoint;
    WRoomChartTime *fTimer;
    WRoomChart *fRoomChart;
    qreal fMouseOffcetX;
    qreal fMouseOffcetY;
    bool fMouseMove;
};

class TempRectItem : public QGraphicsRectItem {    
public:
    TempRectItem(QGraphicsItem *parent = nullptr);
    void reset();

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool fFreeMove;
    qreal fWidth;
    qreal fMouseOffcetX;
    qreal fMouseOffcetY;
};


class ChartScene : public QGraphicsScene {
    Q_OBJECT

public:
    ChartScene();

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    bool fHandleTempRect;
    QPointF fStartPoint;
    TempRectItem fTempRect;
    QPointF nearestPointLeft(const QPointF &p);
    QPointF nearestPointRight(const QPointF &p);

signals:
    void createReserve(int, int, TempRectItem *);
};

#endif // WROOMCHARTCLASSES_H
