#ifndef SOCKETCONNECTION_H
#define SOCKETCONNECTION_H

#include <QObject>
#include <QTcpSocket>

class SocketConnection : public QObject
{
    Q_OBJECT

public:
    explicit SocketConnection(QTcpSocket *s, QObject *parent = nullptr);
    explicit SocketConnection(const QString &addr, quint16 port);
    ~SocketConnection();
    void start();
    bool start(const QByteArray &data);

private:
    QTcpSocket *fTcpSocket;
    qint64 fDataSize;
    QByteArray fData;

signals:
    void callHandler(const QByteArray &);

private slots:
    void readyRead();
    void disconnected();
    void error(QAbstractSocket::SocketError err);

};

#endif // SOCKETCONNECTION_H
