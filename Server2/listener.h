#ifndef LISTENER_H
#define LISTENER_H

#include <QObject>

class QTcpServer;

class Listener : public QObject
{
    Q_OBJECT

public:
    explicit Listener(QObject *parent = nullptr);
    ~Listener();
    static quint16 serverPort();

private:
    QTcpServer *fTcpServer;

private slots:
    void newConnection();
};

#endif // LISTENER_H
