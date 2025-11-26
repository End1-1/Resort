#include "broadcastthread.h"
#include "doubledatabase.h"
#include "appwebsocket.h"
#include "mainwindow.h"

MainWindow *BroadcastThread::mMainWindow = 0;

BroadcastThread::BroadcastThread(QObject *parent):
    QObject(parent)
{
}

void BroadcastThread::cmdRefreshCache(int cache, const QString &item, const QString &additional)
{
    QString data =
        QString( "{\"command\" : \"hotel_cache_update\", \"database\":\"%1\", \"cache\":%2, \"item\":\"%3\" %4}")
        .arg(__dd1Database, QString::number(cache), item, additional);
    AppWebSocket::instance->sendMessage(data);
}

void BroadcastThread::cmdCommand(int command, const QMap<QString, QString> &params)
{
    QString buildData;
    QMapIterator<QString, QString> it(params);
    while (it.hasNext()) {
        it.next();
        buildData += QString(",\"%1\":\"%2\"")
                     .arg(it.key())
                     .arg(it.value());
    }
    QString data = QString("{\"command\":\"hotel_cache_update\", \"subcommand\":%1, \"database\":\"%2\" %3} ")
                   .arg(QString::number(command), __dd1Database, buildData);
    AppWebSocket::instance->sendMessage(data);
}
