#ifndef WRESERVATION_H
#define WRESERVATION_H

#include "basewidget.h"
#include "cacheroom.h"
#include "cachereservation.h"

class WReservationRoomTab;

namespace Ui
{
class WReservation;
}

class WReservation : public BaseWidget
{
    Q_OBJECT

public:
    explicit WReservation(QWidget *parent = nullptr);
    ~WReservation();
    void loadReservation(const QString &id);
    void loadGroup(int id, int initFromRoom = 0);
    void setInitialParams(const QDate &date1, const QDate &date2, QList<CacheRoom *> rooms);
    bool activateDoc(const QString &id);
    int groupId();
    QString groupName();
    void setGroup(int group);
    static void openReserveWindows(const QString &code);
    static void openReserveGroup(int group);
    static void openVaucher(const QString &id);
    void handleBroadcast(const QMap<QString, QVariant> &data) override;

public slots:
    WReservationRoomTab *newRoomTab(bool autocreate = false);

protected:
    virtual void setupTab();
    virtual bool canClose();

private slots:
    void loadFromData(const QList<QVariant> &data);
    void commonChanges();
    void tabCloseRequest(int index);
    void tabIndexChanged(int index);
    void roomNameChanged(const QString &name, int index);
    void on_btnSave_clicked();
    void on_btnCheckIn_clicked();
    void on_btnCancelation_clicked();
    void on_btnCopyLast_clicked();
    void on_btnPrint_clicked();
    void on_btnTracking_clicked();
    void on_btnRecheckin_clicked();
    void on_btnRevive_clicked();
    void on_btnCancelGroup_clicked();
    void on_btnSetGroupParams_clicked();
    void on_btnHelp_clicked();
    void on_btnAddRemoveGroup_clicked();
    WReservationRoomTab *r();
    void on_btnSendConfirmation_clicked();
    void on_btnInvoice_clicked();

private:
    Ui::WReservation *ui;
    QDate fDate1;
    QDate fDate2;
    WReservationRoomTab *activeRoom();
};

#endif // WRESERVATION_H
