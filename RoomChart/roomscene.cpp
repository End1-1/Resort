#include "roomscene.h"
#include "logging.h"
#include "cacheredreservation.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsProxyWidget>

RoomScene::RoomScene(QObject *parent) :
    QGraphicsScene(parent)
{
    fStartReserveSelect = false;
    fReserveRect = nullptr;
    addItem(&fGridGroup);
    addItem(&fHSelGroup);
    addItem(&fVSelGroup);
    addItem(&fReserveGroup);    
    fGridGroup.setZValue(1);
    fHSelGroup.setZValue(2);
    fVSelGroup.setZValue(3);
    fReserveGroup.setZValue(6);
    fReserveGroup.setHandlesChildEvents(false);
    fReserveInfoGroup = nullptr;
}

RoomScene::~RoomScene()
{
    qDeleteAll(fGridGroup.childItems());
    qDeleteAll(fHSelGroup.childItems());
    qDeleteAll(fVSelGroup.childItems());
    qDeleteAll(fReserveGroup.childItems());
    if (fReserveInfoGroup) {
        removeItem(fReserveInfoGroup);
        ClearRoomThread *cs = new ClearRoomThread(fReserveInfoGroup);
        cs->start();
    }
}

void RoomScene::initBackgroung(int columnCount, const QStringList &rooms)
{
    QElapsedTimer et;
    et.start();
    qDebug() << "Start init";
    fSelectedRooms.clear();    
    qDeleteAll(fVSelGroup.childItems());
    fVSelGroup.childItems().clear();

    qDebug() << et.elapsed() << "VSel clear";
    et.restart();

    qDeleteAll(fGridGroup.childItems());
    fGridGroup.childItems().clear();

    qDebug() << et.elapsed() << "Grid clear";
    et.restart();

    if (fReserveInfoGroup) {
        removeItem(fReserveInfoGroup);
        ClearRoomThread *cs = new ClearRoomThread(fReserveInfoGroup);
        cs->start();
    }
    fReserveInfoGroup = new QGraphicsItemGroup();
    addItem(fReserveInfoGroup);
    fReserveInfoGroup->setZValue(5);
    fReserveInfoGroup->setHandlesChildEvents(false);

    qDebug() << et.elapsed() << "Reserve info group clear";
    et.restart();

    foreach (QGraphicsItem *i, fReserveGroup.childItems()) {
        removeItem(i);
        delete i;
    }

    qDebug() << et.elapsed() << "Reserve group clear";
    et.restart();

    fRooms = rooms;
    int width = columnCount * COLUMN_WIDTH;
    int height = rooms.count() * ROW_HEIGHT;
    QPen p(LIGHT_GRAY);
    p.setWidthF(1);
    p.setStyle(Qt::SolidLine);
    QBrush bh(HSELECTION_COLOR, Qt::SolidPattern);
    QBrush bv(VSELECTION_COLOR, Qt::SolidPattern);
    for (int i = 0; i < columnCount + 1; i++) {
        QGraphicsLineItem *l = new QGraphicsLineItem(i * COLUMN_WIDTH, 0, i * COLUMN_WIDTH, height);
        l->setPen(p);
        fGridGroup.addToGroup(l);;
    }

    qDebug() << et.elapsed() << "HGroup create";
    et.restart();

    QPen ph(LIGHT_GRAY);
    ph.setWidthF(1);
    ph.setColor(LIGHT_GRAY);
    ph.setStyle(Qt::SolidLine);
    if (fHSelGroup.childItems().count() == 0) {
        for (int i = 0; i < columnCount + 1; i++) {
            QGraphicsRectItem *r = new QGraphicsRectItem(i * COLUMN_WIDTH, 0, COLUMN_WIDTH, height);
            r->setPen(ph);
            r->setBrush(bh);
            r->setVisible(false);
            fHSelGroup.addToGroup(r);
        }
    }

    qDebug() << et.elapsed() << "VGroup create";
    et.restart();

    for (int i = 0; i < rooms.count(); i++) {
        QGraphicsLineItem *l = new QGraphicsLineItem(0, i * ROW_HEIGHT, width, i * ROW_HEIGHT);
        l->setPen(p);
        fGridGroup.addToGroup(l);
        QGraphicsRectItem *r = new QGraphicsRectItem(0, i * ROW_HEIGHT, width, ROW_HEIGHT);
        r->setPen(p);
        r->setBrush(bv);
        r->setVisible(false);
        fVSelGroup.addToGroup(r);
    }
    QGraphicsLineItem *l = new QGraphicsLineItem(0, rooms.count() * ROW_HEIGHT, width, rooms.count() * ROW_HEIGHT);
    l->setPen(p);
    fGridGroup.addToGroup(l);

    qDebug() << et.elapsed() << "Room scene initialized";
    et.restart();
}

void RoomScene::rowsSelect(const QSet<int> &rows)
{
    changeSelection(fVSelGroup, fSelectedRooms, rows);
}

void RoomScene::columnsSelect(const QSet<int> &columns)
{
    changeSelection(fHSelGroup, fSelectedColumns, columns);
}

void RoomScene::clearReserveWidgets()
{
    QList<QGraphicsItem*> l(fReserveGroup.childItems());
    foreach (QGraphicsItem *item, l) {
        QGraphicsProxyWidget *pw = static_cast<QGraphicsProxyWidget*>(item);
        ReserveWidget *rw = static_cast<ReserveWidget*>(pw->widget());
        if (rw->fReservation.fState() == RESERVE_SERVICE) {
            rw->removeService();
        }
    }
}

void RoomScene::getReserveWidgets(QList<ReserveWidget*> &w)
{
    QListIterator<QGraphicsItem*> it(fReserveGroup.childItems());
    while (it.hasNext()) {
        QGraphicsProxyWidget *p = static_cast<QGraphicsProxyWidget*>(it.next());
        ReserveWidget *rw = static_cast<ReserveWidget*>(p->widget());
        w.append(rw);
    }
}

void RoomScene::removeInvalidReserveWidget(const QString &code)
{
    QList<ReserveWidget*> l;
    getReserveWidgets(l);
    for (int i = 0; i < l.count(); i++) {
        if (code == l.at(i)->fReservation.fId()) {
            l.at(i)->deleteLater();
            return;
        }
    }

    QListIterator<QGraphicsItem*> it(fReserveInfoGroup->childItems());
    while (it.hasNext()) {
        ReservationInfo *rw = static_cast<ReservationInfo*>(it.next());
        if (rw->fReservation.fId() == code) {
            fReserveInfoGroup->removeFromGroup(rw);
            delete rw;
            return;
        }
    }
}

ReservationInfo *RoomScene::addReserveInfo(const QString &code)
{
    ReservationInfo *rc = new ReservationInfo(code);
    rc->p.setY(yFromRoomCode(rc->fReservation.fRoom()));
    rc->setPos(rc->p);
    if (rc->fReservation.fState() == RESERVE_CHECKIN) {
        rc->setZValue(3);
    }
    fReserveInfoGroup->addToGroup(rc);
    return rc;
}

ReserveWidget *RoomScene::addReserveWidget(const QString &code)
{
    CacheReservation r;
    if (!r.get(code)) {
        return nullptr;
    }
    ReserveWidget *rw = new ReserveWidget(code);
    connect(rw, SIGNAL(editReserv(QString)), this, SLOT(editReserveRoom(QString)));
    QGraphicsWidget *pw = addWidget(rw);
    QPointF p;
    p.setX(xFromDate(r.fDateStart()));
    p.setY(yFromRoomCode(r.fRoom()) );
    pw->setPos(p);
    fReserveGroup.addToGroup(pw);
    return rw;
}

void RoomScene::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsScene::mousePressEvent(e);
    fStartReserveSelect = true;
    ReserveRect *r = dynamic_cast<ReserveRect*>(itemAt(e->scenePos(), QTransform()));
    if (r) {
        fStartReserveSelect = false;
    }
    ReservationInfo *ri = dynamic_cast<ReservationInfo*>(itemAt(e->scenePos(), QTransform()));
    if (ri) {
        fStartReserveSelect = false;
    }
}

void RoomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsScene::mouseMoveEvent(e);
    if (fStartReserveSelect) {
        QPointF p = nearestPoint(e->scenePos());
        QPointF pcheck(e->scenePos());
        if (fReserveRect) {
            pcheck.setY(fReserveRect->pos().y() + 2);
        }
        QGraphicsProxyWidget *pw = dynamic_cast<QGraphicsProxyWidget*>(itemAt(pcheck, QTransform()));
        if (pw) {
            return;
        }
        if (fReserveRect) {
            fReserveRect->changeRect(p);
            update();
        } else {
            int row = rowFromY(e->scenePos().y());
            if (row > fRooms.count() - 1) {
                return;
            }
            fReserveRect = new ReserveRect(p);
            fReserveRect->setRoom(fRooms[row]);
            fReserveRect->setZValue(4);
            addItem(fReserveRect);
        }
    }
}

void RoomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsScene::mouseReleaseEvent(e);
    fStartReserveSelect = false;
    if (fReserveRect) {
        ReserveWidget *rw = new ReserveWidget(fReserveRect);
        rw->createService();
        delete rw;
        delete fReserveRect;
        fReserveRect = nullptr;
    }
}

int RoomScene::yFromRoomCode(const QString &room)
{
    int y = 0;
    for (QStringList::iterator it = fRooms.begin(); it != fRooms.end(); it++) {
        if ((*it) == room) {
            return y * ROW_HEIGHT;
        }
        y++;
    }
    return -1;
}

QPointF RoomScene::nearestPoint(const QPointF &p)
{
    int x = p.x();
    int y = p.y();
    x -= (x % COLUMN_WIDTH);
    y -= (y % ROW_HEIGHT);
    return QPointF(x, y);
}

void RoomScene::changeSelection(QGraphicsItemGroup &gr, QMap<int, QGraphicsRectItem *> &sel, const QSet<int> &values)
{
    QList<int> removed;
    for (QMap<int, QGraphicsRectItem*>::const_iterator it = sel.begin(); it != sel.end(); it++) {
        if (!values.contains(it.key())) {
            removed.append(it.key());
            it.value()->setVisible(false);
        }
    }
    for (QList<int>::const_iterator it = removed.begin(); it != removed.end(); it++) {
        sel.remove(*it);
    }
    for (QSet<int>::const_iterator it = values.begin(); it != values.end(); it++) {
        if (sel.contains(*it)) {
            continue;
        }
        QGraphicsRectItem *r = static_cast<QGraphicsRectItem*>(gr.childItems().at(*it));
        r->setVisible(true);
        sel[*it] = r;
    }
    update();
}

void RoomScene::editReserveRoom(const QString &r)
{
    emit editReserve(r);
}

ClearRoomThread::ClearRoomThread(QGraphicsItemGroup *group) :
    QThread()
{
    connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
    fGroup = group;
}

void ClearRoomThread::run()
{
    QList<QGraphicsItem *> ilist = fGroup->childItems();
    for (int i = 0; i < ilist.count(); i++) {
        delete ilist[i];
    }
    delete fGroup;
}
