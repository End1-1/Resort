#ifndef RFACE_H
#define RFACE_H

#include "baseextendeddialog.h"
#include "hall.h"
#include "dishestable.h"
#include "user.h"
#include "cacheone.h"
#include "command.h"
#include <QTimer>
#include <QTcpSocket>

namespace Ui {
class RFace;
}

class RFace : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit RFace(QWidget *parent = 0);
    ~RFace();
    bool setup();
    bool fIsConfigured;
    void secondDbError();
private slots:
    void timeout();
    void socketReadyRead();
    void socketDisconnected();
    void parseCommand(const QString &command);
    void on_tableWidget_clicked(const QModelIndex &index);
    void on_btnExit_clicked();
    void on_tblTables_clicked(const QModelIndex &index);
    void on_btnUp_clicked();
    void on_btnDown_clicked();
    void on_btnChangeHall_clicked();
    void on_btnBreakFast_clicked();

    void on_btnBanket_clicked();

    void on_btnTools_clicked();

protected:
    virtual void closeEvent(QCloseEvent *e);

private:
    bool fCanClose;
    CacheOne fCacheOne;
    Ui::RFace *ui;
    Hall fHall;
    int fCurrentHall;
    int fCurrenTableState;
    QTimer fTimer;
    int fTimerCounter;
    Command fCommand;
    QTcpSocket fSocket;
    User *login();
    void setupTables(int hallId, int busy);
    void scrollTables(int direction);

signals:
    void updateCache(int cache, const QString &code);
};

#endif // RFACE_H
