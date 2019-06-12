#ifndef ROOMSCENE_H
#define ROOMSCENE_H

#include "reserverect.h"
#include "chardefaults.h"
#include "reservewidget.h"
#include "cacheroom.h"
#include "reservationinfo.h"
#include "cachereservation.h"
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QSet>
#include <QThread>

class ClearRoomThread : public QThread {
    Q_OBJECT

public:
    ClearRoomThread(QGraphicsItemGroup *group);
protected:
    virtual void run() override;

private:
    QGraphicsItemGroup *fGroup;
};

class RoomScene : public QGraphicsScene
{
    Q_OBJECT
public:
    RoomScene(QObject *parent = nullptr);
    ~RoomScene();
    void initBackgroung(int columnCount, const QStringList &rooms);
    void rowsSelect(const QSet<int> &rows);
    void columnsSelect(const QSet<int> &columns);
    void clearReserveWidgets();
    void getReserveWidgets(QList<ReserveWidget *> &w);
    void removeInvalidReserveWidget(const QString &code);
    ReservationInfo *addReserveInfo(const QString &code);
    ReserveWidget *addReserveWidget(const QString &code);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *e);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);

private:
    bool fStartReserveSelect;
    ReserveRect *fReserveRect;
    QGraphicsItemGroup fGridGroup;
    QGraphicsItemGroup fHSelGroup;
    QGraphicsItemGroup fVSelGroup;
    QGraphicsItemGroup fReserveGroup;
    QGraphicsItemGroup *fReserveInfoGroup;
    QMap<int, QGraphicsRectItem*> fSelectedRooms;
    QMap<int, QGraphicsRectItem*> fSelectedColumns;
    QStringList fRooms;
    int yFromRoomCode(const QString &room);
    QPointF nearestPoint(const QPointF &p);
    void changeSelection(QGraphicsItemGroup &gr, QMap<int, QGraphicsRectItem*> &sel, const QSet<int> &values);

private slots:
    void editReserveRoom(const QString &r);

signals:
    void editReserve(const QString  &r);
};

#endif // ROOMSCENE_H
