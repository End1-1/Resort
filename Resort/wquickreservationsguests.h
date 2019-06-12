#ifndef WQUICKRESERVATIONSGUESTS_H
#define WQUICKRESERVATIONSGUESTS_H

#include "basedialog.h"
#include "trackcontrol.h"

namespace Ui {
class WQuickReservationsGuests;
}

class WQuickReservationsGuests : public BaseDialog
{
    Q_OBJECT

public:
    explicit WQuickReservationsGuests(QWidget *parent = nullptr);
    ~WQuickReservationsGuests();
    void setRoom(const QString &reserve);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_btnAddGuest_clicked();
    void on_btnRemoveGuest_clicked();
    void on_btnFullInfo_clicked();
    void on_btnChangeGuest_clicked();

private:
    Ui::WQuickReservationsGuests *ui;
    QString fReserve;
    QString fInvoice;
    QList<TrackControl*> fTrackControls;
    void addRowTrack(int row);

};

#endif // WQUICKRESERVATIONSGUESTS_H
