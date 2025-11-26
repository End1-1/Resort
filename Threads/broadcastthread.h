#ifndef BROADCASTTHREAD_H
#define BROADCASTTHREAD_H

#include <QObject>

#define cmd_end_of_day 1
#define cmd_update_cache 2
#define cmd_global_settings 3

class MainWindow;

class BroadcastThread : public QObject
{
public:
    explicit BroadcastThread(QObject *parent = nullptr);
    static void cmdRefreshCache(int cache, const QString &item, const QString &additional = "");
    static void cmdCommand(int command, const QMap<QString, QString> &params);
    static MainWindow *mMainWindow;

private:
    QString fData;
};

#endif // BROADCASTTHREAD_H
