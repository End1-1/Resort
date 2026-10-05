#include "appwebsocket.h"
#include <QDebug>
#include <QTimer>
#include <QJsonDocument>
#include <QUrl>

AppWebSocket *AppWebSocket::instance = nullptr;

AppWebSocket::AppWebSocket(QObject *parent)
    : QObject{parent},
      mReconnect{true},
      mUserDisconnect{false},
      mOpenAfterDisconnect{false}
{
    mSocket = new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this);
    connect(mSocket, &QWebSocket::connected, this, &AppWebSocket::connectedToServer);
    connect(mSocket, &QWebSocket::disconnected, this, &AppWebSocket::disconnectedFromServer);
    connect(mSocket, &QWebSocket::errorOccurred, this, &AppWebSocket::socketError);
    connect(mSocket, &QWebSocket::textMessageReceived, this, &AppWebSocket::textMessageReceived);
    auto *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AppWebSocket::pingServer);
    timer->start(10000);
}

QAbstractSocket::SocketState AppWebSocket::connectionState() const
{
    return mSocket->state();
}

QString AppWebSocket::lastError() const
{
    return mLastError;
}

void AppWebSocket::initInstance()
{
    if(instance == nullptr) {
        instance = new AppWebSocket();
    }
}

void AppWebSocket::setServerAddress(const QString &proto, const QString &serverAddress)
{
    const QString scheme = (proto.compare("https", Qt::CaseInsensitive) == 0) ? "wss" : "ws";
    mServerAddress = QString("%1://%2/ws").arg(scheme, serverAddress);
    mReconnect = true;
    mUserDisconnect = false;
    mLastError.clear();

    if(mSocket->state() == QAbstractSocket::UnconnectedState) {
        connectToServer();
        return;
    }

    // Close first, open only after disconnected — avoids stale disconnect after connected
    mOpenAfterDisconnect = true;
    mSocket->abort();
}

void AppWebSocket::sendMessage(const QString &message)
{
    if(connectionState() == QAbstractSocket::ConnectedState) {
        qDebug() << "sending message" << message;
        mSocket->sendTextMessage(message);
        return;
    }

    mPendingMessages.append(message);
    qDebug() << "AppWebSocket queued message, pending:" << mPendingMessages.size();
}

void AppWebSocket::sendMessage(const QJsonObject &json)
{
    sendMessage(QJsonDocument(json).toJson(QJsonDocument::Compact));
}

int AppWebSocket::pendingCount() const
{
    return mPendingMessages.size();
}

void AppWebSocket::connectToServer()
{
    if(mServerAddress.isEmpty()) {
        qDebug() << "websocket server address empty. quiting.";
        return;
    }

    mReconnect = true;
    mUserDisconnect = false;

    if(mSocket->state() == QAbstractSocket::ConnectingState
            || mSocket->state() == QAbstractSocket::ConnectedState) {
        qDebug() << "Already connecting or connected. Skipping.";
        return;
    }

    emit socketConnecting();
    mSocket->open(QUrl(mServerAddress));
    qDebug() << "connecting to server" << mServerAddress;
}

void AppWebSocket::disconnectFromServer()
{
    mReconnect = false;
    mUserDisconnect = true;
    mOpenAfterDisconnect = false;
    mPendingMessages.clear();
    mSocket->abort();
}

void AppWebSocket::flushPendingMessages()
{
    while(!mPendingMessages.isEmpty()) {
        const QString msg = mPendingMessages.takeFirst();
        qDebug() << "flushing queued message" << msg;
        mSocket->sendTextMessage(msg);
    }
}

void AppWebSocket::scheduleReconnect()
{
    if(!mReconnect || mUserDisconnect) {
        return;
    }

    QTimer::singleShot(5000, this, [this]() {
        if(!mReconnect || mUserDisconnect) {
            return;
        }

        if(mSocket->state() == QAbstractSocket::ConnectingState
                || mSocket->state() == QAbstractSocket::ConnectedState) {
            return;
        }

        connectToServer();
    });
}

void AppWebSocket::pingServer()
{
    if(connectionState() == QAbstractSocket::ConnectedState) {
        sendMessage("ping");
    }
}

void AppWebSocket::connectedToServer()
{
    qDebug() << "connected to server";
    mLastError.clear();
    mOpenAfterDisconnect = false;
    flushPendingMessages();
    emit socketConnected();
}

void AppWebSocket::disconnectedFromServer()
{
    qDebug() << "disconnected from server, openAfterDisconnect:" << mOpenAfterDisconnect
             << "userDisconnect:" << mUserDisconnect;

    if(mOpenAfterDisconnect) {
        mOpenAfterDisconnect = false;
        QTimer::singleShot(0, this, &AppWebSocket::connectToServer);
        return;
    }

    if(mUserDisconnect) {
        mUserDisconnect = false;
        emit socketDisconnected();
        return;
    }

    emit socketDisconnected();
    scheduleReconnect();
}

void AppWebSocket::socketError(QAbstractSocket::SocketError error)
{
    Q_UNUSED(error);
    mLastError = mSocket->errorString();
    qDebug() << "websocket error" << mLastError << "state" << mSocket->state();

    if(mOpenAfterDisconnect || mUserDisconnect) {
        return;
    }

    if(mSocket->state() == QAbstractSocket::ConnectedState
            || mSocket->state() == QAbstractSocket::ConnectingState) {
        return;
    }

    emit socketErrorOccurred(mLastError);
    scheduleReconnect();
}

void AppWebSocket::textMessageReceived(const QString &message)
{
    qDebug() << "websocket message" << message;

    if(message.toLower() == "pong") {
        return;
    }

    emit messageReceived(message);
}
