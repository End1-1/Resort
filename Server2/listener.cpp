#include "listener.h"
#include "socketconnection.h"
#include <QTcpServer>
#include <QTcpSocket>

static quint16 server_port = 2134;

Listener::Listener(QObject *parent) : QObject(parent)
{
    fTcpServer = new QTcpServer(this);
    if (!fTcpServer->listen(QHostAddress::Any, serverPort())) {
        return;
    }
    connect(fTcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

Listener::~Listener()
{
    delete fTcpServer;
}

quint16 Listener::serverPort()
{
    return server_port;
}

void Listener::newConnection()
{
    if (fTcpServer->hasPendingConnections()) {
        QTcpSocket *s = fTcpServer->nextPendingConnection();
        SocketConnection *sc = new SocketConnection(s, this);
        sc->start();
    }
}
