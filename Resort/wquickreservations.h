#ifndef WQUICKRESERVATIONS_H
#define WQUICKRESERVATIONS_H

#include "basewidget.h"
#include <QItemDelegate>

namespace Ui {
class WQuickReservations;
}

class WQuickReservations;

class WQuickReservationsDelegate : public QItemDelegate {
    Q_OBJECT

public:
    WQuickReservationsDelegate(WQuickReservations *w);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    WQuickReservations *fSrc;
};

class WQuickReservations : public BaseWidget
{
    Q_OBJECT

public:
    explicit WQuickReservations(QWidget *parent = nullptr);
    ~WQuickReservations();
    virtual void setup();
    QString reservationCode(int row);
    QString  invoiceCode(int row);
    int room(int row);
    int roomState(int row);
    int guestCode(int row);
    QString guestFullName(int row);
    QDate dateEntry(int row);
    QDate dateDeparture(int row);
    QString cardex(int row);
    QAbstractItemModel *model();
    void updateTable();
    void broadcast(int row);
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void totalScrollValue(int value);
    void roomUpdated(int cacheId, const QString &code);
    void on_btnRefresh_clicked();
    void on_btnTrackControl_clicked();
    void on_btnOpenReservation_clicked();
    void on_btnGuests_clicked();
    void on_btnCheckinSelected_clicked();
    void on_btnClearSelectedRooms_clicked();
    void on_btnDateLeft_clicked();
    void on_btnDateRight_clicked();
    void on_btnMassNation_clicked();
    void on_btnRoomRate_clicked();

private:
    Ui::WQuickReservations *ui;
    void refresh();
    void setRowSelected(int flag);
};

#endif // WQUICKRESERVATIONS_H
