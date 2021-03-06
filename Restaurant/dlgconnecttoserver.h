#ifndef DLGCONNECTTOSERVER_H
#define DLGCONNECTTOSERVER_H

#include "baseextendeddialogr.h"
#include <QUdpSocket>
#include <QTimer>

namespace Ui {
class DlgConnectToServer;
}

class DlgConnectToServer : public BaseExtendedDialogR
{
    Q_OBJECT

public:
    explicit DlgConnectToServer(QWidget *parent = 0);
    ~DlgConnectToServer();

private:
    Ui::DlgConnectToServer *ui;
    QTimer fTimer;
    QUdpSocket fUdpSocket;

private slots:
    void timeout();
    void readDatagram();
};

#endif // DLGCONNECTTOSERVER_H
