#ifndef WGUESTINVOICE_H
#define WGUESTINVOICE_H

#include "basewidget.h"

namespace Ui {
class WGuestInvoice;
}

class DBMRegister;

class WGuestInvoice : public BaseWidget
{
    Q_OBJECT

public:
    explicit WGuestInvoice(QWidget *parent = nullptr);
    ~WGuestInvoice();
    virtual void callback(int sel, const QString &code);
    void setReservationMode(const QString reserveId);
    void initRoom(int room);
    void setBalance();
    void setRoom(int room);
    void setRoomCategory(const QString &category);
    void setGuest(const QString &guest);
    void clear();
    void clearSelector();
    void initSelector();
    int room();
    QString guest() const;
    QString invoice() const;
    QString reserve() const;
    void setDBMRegister(DBMRegister *r);

private slots:
    void on_btnOpenInvoice_clicked();

private:
    Ui::WGuestInvoice *ui;
};

#endif // WGUESTINVOICE_H
