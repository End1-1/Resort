#ifndef WMAINDESK_H
#define WMAINDESK_H

#include "basewidget.h"
#include "roomscene.h"
#include "dwmaindeskhint.h"
#include "cacheroom.h"
#include "cachereservation.h"
#include <QItemDelegate>
#include <QPainter>
#include <QResizeEvent>
#include <QKeyEvent>
#include <QTimer>

namespace Ui {
class WMainDesk;
}

class WMainDesk : public BaseWidget
{
    Q_OBJECT

public:
    explicit WMainDesk(QWidget *parent = nullptr);
    ~WMainDesk();
    void filterRoom();
    virtual void setup();
    virtual void setupTab();
    virtual void handleBroadcast(const QMap<QString, QVariant> &data);

protected:
    virtual bool event(QEvent *e);

private slots:
    void timeout();
    void scDateHScroll(int value);
    void scMainHScroll(int value);
    void scRoomVScroll(int value);
    void scMainVScroll(int value);
    void catButtonClick();
    void roomSelectionChanged(const QModelIndex &m1, const QModelIndex &m2);
    void editReserveRoom(const QString &code);
    void daySelectionChanged(const QModelIndex &m1, const QModelIndex &m2);
    void reservationCacheUpdated(int cacheId, const QString &id);
    void roomCacheUpdated(int cacheId, const QString &id);
    void dockHintVisibilityChanged(bool v);
    void changeDate();
    void on_btnClearFilter_clicked();
    void on_btnScrollRight_clicked();
    void on_btnScrollLeft_clicked();
    void on_btnCheckIn_clicked();
    void on_btnClearSelection_clicked();
    void on_btnGroupReservation_clicked();
    void on_btnScrollDown_clicked();
    void on_btnScrollUp_clicked();
    void on_btnEndOfDay_clicked();
    void on_btnCheckin_clicked();
    void on_btnShowDockHint_clicked();
    void on_btnJumpToDate_clicked();
    void on_tblRoom_clicked(const QModelIndex &index);
    void on_tblDay_clicked(const QModelIndex &index);
    void on_btnCheckoutFilter_clicked();
    void on_leJumpToRoom_editingFinished();
    void on_tblRoom_doubleClicked(const QModelIndex &index);
    void on_btnInvoice_clicked();
    void on_btnPostCharge_clicked();
    void on_btnTransferRoom_clicked();
    void on_btnAirReserve_clicked();
    void on_leFilterGuest_textEdited(const QString &arg1);
    void on_btnStatus_clicked();
    void on_btnFilterCardex_clicked();
    void on_btnColors_clicked();
    void on_btnRefreshChart_clicked();
    void on_btnFilterCategory_clicked();
    void on_btnBedFilter_clicked();
    void on_btnSmokeFilter_clicked();
    void on_btnRoomStateFilter_clicked();
    void on_btnBuilding_clicked();

private:
    Ui::WMainDesk *ui;
    QTimer fTimer;
    QDate fDateStart;
    QDate fDateEnd;
    DWMainDeskHint *fDockHint;
    RoomScene *fScene;
    int fReserveStatus;
    QString fFilterCardex;
    QStringList fRoomList;
    QStringList fCatList;
    QString fCatFilter;
    QStringList fBedList;
    QStringList fBedListNames;
    QString fBedFilter;
    QStringList fSmokeList;
    QStringList fSmokeListNames;
    QString fSmokeFilter;
    QString fBuildingFilter;
    QStringList fBuildingList;
    QStringList fBuildingListNames;
    QString fStateFilter;
    QStringList fStateList;
    QStringList fStateListNames;
    QList<QList<QVariant> > fReservationHint;
    void uncheckCatButtons();
    void dockHint(const QString &filter);
    int xFromDate(const QDate &date);
    void roomsRowSelectionChanged();
    void daysColumnSelectionChanged();
};

#endif // WMAINDESK_H
