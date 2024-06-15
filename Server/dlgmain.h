#ifndef DLGMAIN_H
#define DLGMAIN_H

#include "command.h"
#include <QDialog>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QTcpServer>
#include <QUdpSocket>

namespace Ui {
class DlgMain;
}

struct Lock {
    QString lock;
    QString user;
};

Q_DECLARE_METATYPE(QTcpSocket*)

class DlgMain : public QDialog
{
    Q_OBJECT
public:
    explicit DlgMain(QWidget *parent = 0);
    ~DlgMain();
protected:
    virtual void closeEvent(QCloseEvent *e);
private:
    Ui::DlgMain *ui;
    bool fCanClose;
    QSystemTrayIcon fTrayIcon;
    QMenu fTrayMenu;
    QTcpServer fTcpServer;
    QUdpSocket fUdpSocket;
    QMap<QTcpSocket*, Command*> fAllSockets;
    QMap<QTcpSocket*, Command*> fTcpSockets;
    QMap<QTcpSocket*, Command*> fTcpSocketsDraft;
    void logActivity(const QString &action);
    void processTravelLine();
private slots:
    void timeout();
    void appTerminate();
    void iconClicked(QSystemTrayIcon::ActivationReason reason);
    void newConnection();
    void clientDisconnected();
    void clientReadyRead();
    void datagramRead();
    void parseCommand(const QString &command);
    void on_btnSave_clicked();
    void on_btnClear_clicked();
    void on_btnClearDisconnected_clicked();
    void on_tabWidget_currentChanged(int index);
    void travellineFinished(QString ar);
    void travellineConfirm();
    void on_leTravelineDB_textChanged(const QString &arg1);
    void on_pushButton_clicked();
};

#endif // DLGMAIN_H
