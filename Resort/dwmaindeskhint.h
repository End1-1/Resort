#ifndef DWMAINDESKHINT_H
#define DWMAINDESKHINT_H

#include "base.h"
#include <QDockWidget>
#include <QItemDelegate>

class TableModel;

namespace Ui {
class DWMainDeskHint;
}

class DeskHintItemDelegate : public QItemDelegate {

public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

class DWMainDeskHint : public QDockWidget, public Base
{
    Q_OBJECT
public:
    explicit DWMainDeskHint(QWidget *parent = nullptr);
    ~DWMainDeskHint();
    void commonFilter(const QString &filter, int col = -1);
    void filterEqual(const QStringList &values, int col = -1);
    void checkInFilter();
    void checkOutFilter();
    void airFilter();
    void hide();
    void show();
    void reset();

private:
    bool fLoaded;
    Ui::DWMainDeskHint *ui;
    bool fCheckInFilter;
    TableModel *fTableModel;
    void load();

private slots:
    void tblHeaderSectionClicked(int logicalIndex);
    void thisVisibilityChanged(bool v);
    void on_btnCheckIn_clicked();
    void on_tbl_clicked(const QModelIndex &index);
};

#endif // DWMAINDESKHINT_H
