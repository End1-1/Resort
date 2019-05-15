#ifndef WQUICKRESERVATIONSPAX_H
#define WQUICKRESERVATIONSPAX_H

#include "basedialog.h"
#include "trackcontrol.h"

namespace Ui {
class WQuickReservationsPax;
}

class WQuickReservationsPax : public BaseDialog
{
    Q_OBJECT

public:
    explicit WQuickReservationsPax(QWidget *parent = nullptr);
    ~WQuickReservationsPax();
    void setReservationCode(const QString &code);
    void getValues(int &man, int &woman, int &child, int &baby);
    int pax();

private:
    Ui::WQuickReservationsPax *ui;
    TrackControl *fTrack;
    QString fCode;
};

#endif // WQUICKRESERVATIONSPAX_H
