#ifndef TRAVELINE_H
#define TRAVELINE_H

#include <QObject>
#include <QJsonObject>
#include <QNetworkAccessManager>

class QNetworkReply;

class Traveline : public QObject
{
    Q_OBJECT
public:
    explicit Traveline(const QString &username, const QString &password, const QString &hotel, QObject *parent = nullptr);

    void queryReservations(QJsonObject jo);
    void reservationCreated(QJsonObject jo);
    ~Traveline();

private:
    QString fUsername;
    QString fPassword;
    QString fHotel;
    QNetworkAccessManager *manager;
    QString q;

private slots:
    void readyRead();
    void queryFinished(QNetworkReply *reply);
    void confirmFinished(QNetworkReply *reply);

signals:
    void end(QString);
    void confirmEnd(QString);

};

#endif // TRAVELINE_H
