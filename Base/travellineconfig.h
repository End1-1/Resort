#ifndef TRAVELLINECONFIG_H
#define TRAVELLINECONFIG_H

#include "doubledatabase.h"
#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

class QNetworkReply;

class TravelLineConfig : public QObject
{
    Q_OBJECT
public:
    explicit TravelLineConfig(QObject *parent = nullptr);
    explicit TravelLineConfig(DoubleDatabase &db);

    QString url;
    QString hotelID;
    QString username;
    QString password;
    QString queryAvailability;
    QJsonArray jaRoomTypes;
    QJsonArray jaRatePlans;

    void updateAvailability(const QDate &startdate, const QDate &enddate, const QString &roomtypecode, const QString &rateplancode, int bookinglimit);

public slots:
    void finished(QNetworkReply *reply);

};

#endif // TRAVELLINECONFIG_H
