#ifndef RESERVEWIDGET_H
#define RESERVEWIDGET_H

#include "cacheroom.h"
#include "chardefaults.h"
#include "basewidget.h"
#include "cachereservation.h"
#include <QDate>

class ReserveRect;
class WMainDesk;

namespace Ui {
class ReserveWidget;
}

class ReserveWidget : public QWidget
{
    Q_OBJECT
public:
    friend class WMainDesk;
    explicit ReserveWidget(ReserveRect *rr, QWidget *parent = nullptr);
    explicit ReserveWidget(const QString &code, QWidget *parent = nullptr);
    ~ReserveWidget();
    void createService();
    void removeService();
    CacheReservation fReservation;

protected:
    void resizeEvent(QResizeEvent *e);

private slots:
    void on_btnCancel_clicked();

private:
    Ui::ReserveWidget *ui;
    CacheRoom fRoom;
    QDate fDateStart;
    QDate fDateEnd;
    QString fId;
    void setSize();
signals:
    void editReserv(const QString &code);
};

#endif // RESERVEWIDGET_H
