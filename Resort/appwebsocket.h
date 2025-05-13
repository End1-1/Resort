#ifndef APPWEBSOCKET_H
#define APPWEBSOCKET_H

#include <QObject>
#include <QWebSocket>
#include <QJsonObject>

class AppWebSocket : public QObject
{
    Q_OBJECT
public:

    explicit AppWebSocket(QObject *parent = nullptr);

    QAbstractSocket::SocketState connectionState() const;

    static AppWebSocket *instance;

    static void initInstance();

    void setServerAddress(const QString &proto, const QString &serverAddress);

    void sendMessage(const QString &message);

    void sendMessage(const QJsonObject &json);

public slots:
    void connectToServer();

    void disconnectFromServer();

private:
    QWebSocket *mSocket;

    QString mServerAddress;

    bool mReconnect;

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

    void messageReceived(const QString &message);
};

#endif // APPWEBSOCKET_H
