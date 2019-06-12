#include "tableview.h"
#include <QMouseEvent>

TableView::TableView(QWidget *parent) :
    QTableView(parent)
{
    setMouseTracking(true);
}


void TableView::mouseMoveEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    QModelIndex index = indexAt(pos);
    setCursor(Qt::ArrowCursor);
    if (index.isValid()) {
        if (fLinkColumns.contains(index.column())) {
            setCursor(Qt::PointingHandCursor);
        }
    }
    QTableView::mouseMoveEvent(event);
}
