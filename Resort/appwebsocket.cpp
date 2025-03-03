#include "appwebsocket.h"
#include <QDebug>
#include <QTimer>
#include <QJsonDocument>

AppWebSocket *AppWebSocket::instance = nullptr;

AppWebSocket::AppWebSocket(QObject *parent)
    : QObject{parent},
      mConnectionState(disconnected)
{
    mSocket = new QWebSocket();
    connect(mSocket, &QWebSocket::connected, this, &AppWebSocket::connectedToServer);
    connect(mSocket, &QWebSocket::disconnected, this, &AppWebSocket::disconnectedFromServer);
    connect(mSocket, QOverload<QAbstractSocket::SocketError>::of( &QWebSocket::error), this, &AppWebSocket::socketError);
    connect(mSocket, &QWebSocket::textMessageReceived, this, &AppWebSocket::textMessageReceived);
    connectToServer();
    auto *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AppWebSocket::pingServer);
    timer->start(10000);
    mReconnect = true;
}

void AppWebSocket::initInstance()
{
    instance = new AppWebSocket();
}

void AppWebSocket::setServerAddress(const QString &proto, const QString &serverAddress)
{
    mServerAddress = QString("%1://%2/ws").arg(proto == "http" ? "ws" : "wss", serverAddress);
    if (mConnectionState != disconnected) {
        mSocket->close();
        mConnectionState = disconnected;
    }
    connectToServer();
}

void AppWebSocket::sendMessage(const QString &message)
{
    if (mConnectionState != connected) {
        qDebug() << "sending message in disconnected state inpossible";
        return;
    }
    qDebug() << "sending message" << message;
    qDebug() << mSocket->sendTextMessage(message);
}

void AppWebSocket::sendMessage(const QJsonObject &json)
{
    sendMessage(QJsonDocument(json).toJson(QJsonDocument::Compact));
}

void AppWebSocket::connectToServer()
{
    if (mServerAddress.isEmpty()) {
        qDebug() << "websocket server address empty. quiting.";
        return;
    }
    mReconnect = true;
    if (mConnectionState == connecting) {
        return;
    }
    mConnectionState = connecting;
    emit socketConnecting();
    QUrl url(mServerAddress);
    mSocket->open(url);
    qDebug() << "connecting to server";
}

void AppWebSocket::disconnectFromServer()
{
    mReconnect = false;
    mConnectionState = disconnected;
    mSocket->close();
}

void AppWebSocket::pingServer()
{
    if (mConnectionState == connected) {
        sendMessage("ping");
    }
}

void AppWebSocket::connectedToServer()
{
    qDebug() << "connected to server";
    mConnectionState = connected;
    emit socketConnected();
}

void AppWebSocket::disconnectedFromServer()
{
    qDebug() << "disconnected from server";
    mConnectionState = disconnected;
    emit socketDisconnected();
    if (mReconnect) {
        QTimer::singleShot(5000, this, SLOT(connectToServer()));
    }
}

void AppWebSocket::socketError(QAbstractSocket::SocketError error)
{
    qDebug() << "websocket error" << mSocket->errorString();
    mSocket->close();
    if (mReconnect) {
        QTimer::singleShot(5000, this, SLOT(connectToServer()));
    }
}

void AppWebSocket::textMessageReceived(const QString &message)
{
    qDebug() << "websocket message" << message;
    if (message.toLower() == "pong") {
        return;
    }
    emit messageReceived(message);
}
