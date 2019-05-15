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

private:
    Ui::WQuickReservationsGuests *ui;
    QString fReserve;
    QString fInvoice;
    QMap<int, TrackControl *> fTrackWidgets;
    void addRowTrack(int row);

};

#endif // WQUICKRESERVATIONSGUESTS_H
