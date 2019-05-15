#ifndef DLGCREATEGROUPRESERVATION_H
#define DLGCREATEGROUPRESERVATION_H

#include "baseextendeddialog.h"

namespace Ui {
class DlgCreateGroupReservation;
}

class WReservationRoomTab;

class DlgCreateGroupReservation : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DlgCreateGroupReservation(QWidget *parent = nullptr);
    ~DlgCreateGroupReservation();
    QString fCode;
    void loadRooms();
    void setDates(const QDate &d1, const QDate &d2);
    void setSingleMode(bool mode);
    void setReservationTab(WReservationRoomTab *t);

private slots:
    void singleHandle(bool v);
    void on_btnCreate_clicked();
    void on_btnClearRoomFilter_clicked();
    void on_tblCategory_clicked(const QModelIndex &index);
    void on_tblBed_clicked(const QModelIndex &index);
    void on_tblFloor_clicked(const QModelIndex &index);
    void on_tblSmoke_clicked(const QModelIndex &index);
    void on_deArrival_textEdited(const QString &arg1);
    void on_deDeparture_textEdited(const QString &arg1);


private:
    Ui::DlgCreateGroupReservation *ui;
    bool fSingleMode;
    WReservationRoomTab *fTab;
    void makeRooms();
    QMap<QString, QString> fPrice;
};

#endif // DLGCREATEGROUPRESERVATION_H
