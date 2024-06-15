#include "broadcastthread.h"
#include "doubledatabase.h"
#include "broadcast1.h"
#include "appconfig.h"
#include <QTcpSocket>
#include <QNetworkProxy>

#ifndef RESORT_SERVER
#include "mainwindow.h"
#endif

MainWindow *BroadcastThread::mMainWindow = 0;

BroadcastThread::BroadcastThread(const QString &data) :
    ObjectThread()
{
    int size = data.toUtf8().length();
    fData.append(reinterpret_cast<const char*>(&size), sizeof(size));
    fData.append(data.toUtf8(), data.toUtf8().length());
}

void BroadcastThread::cmdRefreshCache(int cache, const QString &item) {
    QString data = QString("{\"db\": {\"database\" : \"%1\", \"user\" : \"%2\", \"password\" : \"%3\"}, "
                           "\"command\" : {\"command\": \"update_cache\", \"cache\":%4, \"item\":\"%5\"}}")
                       .arg(__dd1Database)
                       .arg("userjan")
                       .arg("passwordjan")
                       .arg(cache)
                       .arg(item);
#ifndef RESORT_SERVER
    if (Broadcast1::SOCKET_CONNECTED == 0) {
        QString data = QString("{\"command\": \"update_cache\", \"cache\":%4, \"item\":\"%5\"}")
                           .arg(cache)
                           .arg(item);
        mMainWindow->parseSocketCommand(data);
        return;
    }
#endif

    sendData(data);
}

void BroadcastThread::cmdCommand(int command, const QMap<QString, QString> &params) {
    QString buildData;
    QMapIterator<QString, QString> it(params);
    while (it.hasNext()) {
        it.next();
        buildData += QString(",\"%1\":\"%2\"")
                .arg(it.key())
                .arg(it.value());
    }
    QString data = QString("{\"db\": {\"database\" : \"%1\", \"user\" : \"%2\", \"password\" : \"%3\"}, "
                           "\"command\":{\"command\":\"%4\" %5}} ")
            .arg(__dd1Database)
            .arg("userjan")
            .arg("passwordjan")
            .arg(command)
            .arg(buildData);
    sendData(data);
}

void BroadcastThread::sendData(const QString &data) {

    BroadcastThread *b = new BroadcastThread(data);
    b->start();
}

void BroadcastThread::process()
{
    fSocket = new QTcpSocket();
    fSocket->setProxy(QNetworkProxy::NoProxy);
    fSocket->connectToHost(AppConfig::fServerAddress, 1250);
    if (fSocket->waitForConnected()) {
        fSocket->write(fData, fData.length());
        fSocket->flush();
        fSocket->disconnectFromHost();
    }
    fSocket->deleteLater();
    emit finished();
}
