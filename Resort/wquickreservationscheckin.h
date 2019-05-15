#ifndef WQUICKRESERVATIONSCHECKIN_H
#define WQUICKRESERVATIONSCHECKIN_H

#include "basedialog.h"
#include <QTimer>

namespace Ui {
class WQuickReservationsCheckin;
}

class WQuickReservationsCheckin : public BaseDialog
{
    Q_OBJECT

public:
    explicit WQuickReservationsCheckin(QWidget *parent = nullptr);
    ~WQuickReservationsCheckin();
    void setReservations(const QStringList &codes);
    virtual int exec();

private:
    Ui::WQuickReservationsCheckin *ui;
    QTimer fTimer;
    void checkIn(int row, DoubleDatabase &dd);

private slots:
    void timeout();
};

#endif // WQUICKRESERVATIONSCHECKIN_H
