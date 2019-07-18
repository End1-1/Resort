#ifndef RESERVATIONINFO_H
#define RESERVATIONINFO_H

#include "cachereservation.h"
#include "chardefaults.h"
#include "preferences.h"
#include <QGraphicsItem>
#include <QTimer>
#include <QElapsedTimer>

class TimerBlya;

class ReservationInfo : public QGraphicsItem
{
public:
    friend class TimerBlya;
    ReservationInfo(const QString &reserveCode, QGraphicsItem *parent = nullptr);
    ~ReservationInfo();
    QRectF boundingRect() const;
    CacheReservation fReservation;
    QPointF p;

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
    QRectF fRect;
    QRect fBtnRect;
    QPixmap fPixmap;
    TimerBlya *fTimer;
    void singleClick();
    void doubleClick();
    static Preferences fPref;
};

#endif // RESERVATIONINFO_H
