#ifndef BROADCASTTHREAD_H
#define BROADCASTTHREAD_H

#include "objectthread.h"

#define cmd_end_of_day 1
#define cmd_update_cache 2
#define cmd_global_settings 3
#define cmd_update_program 4

class QTcpSocket;

class BroadcastThread : public ObjectThread
{
public:
    BroadcastThread(const QString &data);
    static void cmdRefreshCache(int cache, const QString &item);
    static void cmdCommand(int command, const QMap<QString, QString> &params);
    static void sendData(const QString &data);

public slots:
    virtual void process() override;

private:
    QByteArray fData;
    QTcpSocket *fSocket;
};

#endif // BROADCASTTHREAD_H
