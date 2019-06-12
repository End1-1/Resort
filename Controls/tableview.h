#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>

class TableView : public QTableView
{
public:
    TableView(QWidget *parent = nullptr);
    QList<int> fLinkColumns;

protected:
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // TABLEVIEW_H
