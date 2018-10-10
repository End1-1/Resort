#include "qsockettextthread.h"
#include <QDebug>
#include <QTcpSocket>
#include <QNetworkProxy>

QSocketTextThread::QSocketTextThread(QObject *parent) :
    QThread(parent)
{
    connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
}

QSocketTextThread::~QSocketTextThread()
{
    qDebug() << "~QSocketTextThread";
}

void QSocketTextThread::run()
{
    QString ip = "10.1.0.2";
    QTcpSocket fSocket;
    fSocket.connectToHost(ip, 1250);
    if (fSocket.waitForConnected()) {
        QString data = QString("{\"db\" : {\"database\" : \"%1\", \"user\" : \"%2\", \"password\" : \"password\"}, "
                               "\"command\" : {\"command\": \"identify\"}}")
                .arg("resort")
                .arg("Test main");
        int size = data.toUtf8().length();
        QByteArray dataToSend;
        dataToSend.append(reinterpret_cast<const char*>(&size), sizeof(size));
        dataToSend.append(data.toUtf8(), data.toUtf8().length());
        fSocket.write(dataToSend, dataToSend.length());
        fSocket.flush();
    } else {
        return;
    }
    QTcpSocket fSocketDraft;
    fSocketDraft.setProxy(QNetworkProxy::NoProxy);
    fSocketDraft.connectToHost(ip, 1250);
    if (fSocketDraft.waitForConnected()) {
        QString data = QString("{\"db\" : {\"database\" : \"%1\", \"user\" : \"%2\", \"password\" : \"password\"}, "
                               "\"command\" : {\"command\": \"draft\"}}")
                .arg("resort")
                .arg("Test draft");
        int size = data.toUtf8().length();
        QByteArray dataToSend;
        dataToSend.append(reinterpret_cast<const char*>(&size), sizeof(size));
        dataToSend.append(data.toUtf8(), data.toUtf8().length());
        fSocketDraft.write(dataToSend, dataToSend.length());
        fSocketDraft.flush();
        fSocket.waitForReadyRead(20000);
        qDebug() << fSocket.readAll();
        qDebug() << fSocketDraft.readAll();
        for (int i = 0; i < 10; i++) {
            if (fSocket.waitForReadyRead(20000)) {
                qDebug() << fSocket.readAll();
                msleep(1000);
            } else {
                break;
            }
        }
        fSocket.disconnectFromHost();
        fSocketDraft.disconnectFromHost();
    }
}
