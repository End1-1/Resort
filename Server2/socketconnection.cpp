#include "socketconnection.h"
#include "datahandler.h"
#include <QHostAddress>

SocketConnection::SocketConnection(QTcpSocket *s, QObject *parent) : QObject(parent)
{
    fTcpSocket = s;
    fDataSize = 0;
}

SocketConnection::SocketConnection(const QString &addr, quint16 port)
{
    fDataSize = 0;
    fTcpSocket = new QTcpSocket();
    fTcpSocket->connectToHost(QHostAddress(addr), port);
    if (!fTcpSocket->waitForConnected(10000)) {

    }
}

SocketConnection::~SocketConnection()
{
    delete fTcpSocket;
}

void SocketConnection::start()
{
    connect(fTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error(QAbstractSocket::SocketError)));
    connect(fTcpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(fTcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

bool SocketConnection::start(const QByteArray &data)
{
    if (!fTcpSocket->isOpen()) {
        return false;
    }
    start();
    fTcpSocket->write(data.data(), data.length());
    fTcpSocket->flush();
    return true;
}

void SocketConnection::readyRead()
{
    QTcpSocket *s = static_cast<QTcpSocket*>(sender());
    if (fDataSize == 0) {
        s->read(reinterpret_cast<char *>(&fDataSize), sizeof(qint64));
    }
    fData.append(s->readAll());
    if (fDataSize == fData.length()) {
        emit callHandler(fData);
    }
    if (fDataSize < fData.length()) {
        deleteLater();
    }
}

void SocketConnection::disconnected()
{
    deleteLater();
}

void SocketConnection::error(QAbstractSocket::SocketError err)
{
    Q_UNUSED(err);
    deleteLater();
}
