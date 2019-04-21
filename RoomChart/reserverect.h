#ifndef RESERVERECT_H
#define RESERVERECT_H

#include "chardefaults.h"
#include "cacheroom.h"
#include <QGraphicsItem>

class ReserveWidget;

class ReserveRect : public QGraphicsItem
{
public:
    friend class ReserveWidget;
    ReserveRect(QGraphicsItem *parent = nullptr);
    ReserveRect(const QPointF &p, QGraphicsItem *parent = nullptr);
    ~ReserveRect();
    void changeRect(const QPointF &p);
    void setRoom(const QString &code);
    int width();
    QPointF pos() const;
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QDate fDateStart;
    QDate fDateEnd;
    QRectF fRect;
    QPointF fInitialPoint;
    CacheRoom fRoom;
};

#endif // RESERVERECT_H
