#include "appwebsocket.h"
#include <QDebug>
#include <QTimer>
#include <QJsonDocument>

AppWebSocket *AppWebSocket::instance = nullptr;

AppWebSocket::AppWebSocket(QObject *parent)
    : QObject{parent}
{
    mSocket = new QWebSocket();
    connect(mSocket, &QWebSocket::connected, this, &AppWebSocket::connectedToServer);
    connect(mSocket, &QWebSocket::disconnected, this, &AppWebSocket::disconnectedFromServer);
    connect(mSocket, QOverload<QAbstractSocket::SocketError>::of( &QWebSocket::error), this, &AppWebSocket::socketError);
    connect(mSocket, &QWebSocket::textMessageReceived, this, &AppWebSocket::textMessageReceived);
    auto *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AppWebSocket::pingServer);
    timer->start(10000);
    mReconnect = true;
}

QAbstractSocket::SocketState AppWebSocket::connectionState() const
{
    return mSocket->state();
}

void AppWebSocket::initInstance()
{
    instance = new AppWebSocket();
}

void AppWebSocket::setServerAddress(const QString &proto, const QString &serverAddress)
{
    mServerAddress = QString("%1://%2/ws").arg(proto == "http" ? "ws" : "wss", serverAddress);
    if (connectionState() != QAbstractSocket::UnconnectedState) {
        mSocket->abort();
    }
    connectToServer();
}

void AppWebSocket::sendMessage(const QString &message)
{
    if (connectionState() != QAbstractSocket::ConnectedState) {
        qDebug() << "sending message in disconnected state impossible";
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
    if (mSocket->state() == QAbstractSocket::ConnectingState ||
            mSocket->state() == QAbstractSocket::ConnectedState) {
        qDebug() << "Already connecting or connected. Skipping.";
        return;
    }
    emit socketConnecting();
    QUrl url(mServerAddress);
    mSocket->open(url);
    qDebug() << "connecting to server";
}

void AppWebSocket::disconnectFromServer()
{
    mReconnect = false;
    mSocket->abort();
}

void AppWebSocket::pingServer()
{
    if (connectionState() == QAbstractSocket::ConnectedState) {
        sendMessage("ping");
    }
}

void AppWebSocket::connectedToServer()
{
    qDebug() << "connected to server";
    emit socketConnected();
}

void AppWebSocket::disconnectedFromServer()
{
    qDebug() << "disconnected from server";
    emit socketDisconnected();
    if (mReconnect) {
        QTimer::singleShot(5000, this, SLOT(connectToServer()));
    }
}

void AppWebSocket::socketError(QAbstractSocket::SocketError error)
{
    qDebug() << "websocket error" << mSocket->errorString();
    mSocket->abort();
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
