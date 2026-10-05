#ifndef APPWEBSOCKET_H
#define APPWEBSOCKET_H

#include <QObject>
#include <QWebSocket>
#include <QJsonObject>
#include <QStringList>

class AppWebSocket : public QObject
{
    Q_OBJECT
public:

    explicit AppWebSocket(QObject *parent = nullptr);

    QAbstractSocket::SocketState connectionState() const;

    QString lastError() const;

    static AppWebSocket *instance;

    static void initInstance();

    void setServerAddress(const QString &proto, const QString &serverAddress);

    void sendMessage(const QString &message);

    void sendMessage(const QJsonObject &json);

    int pendingCount() const;

public slots:
    void connectToServer();

    void disconnectFromServer();

private:
    QWebSocket *mSocket;

    QString mServerAddress;

    QString mLastError;

    bool mReconnect;

    bool mUserDisconnect;

    bool mOpenAfterDisconnect;

    QStringList mPendingMessages;

    void flushPendingMessages();

    void scheduleReconnect();

private slots:

    void pingServer();

    void connectedToServer();

    void disconnectedFromServer();

    void socketError(QAbstractSocket::SocketError error);

    void textMessageReceived(const QString &message);

signals:
    void socketConnecting();

    void socketConnected();

    void socketDisconnected();

    void socketErrorOccurred(const QString &error);

    void messageReceived(const QString &message);
};

#endif // APPWEBSOCKET_H
