#include "travellineconfig.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

TravelLineConfig::TravelLineConfig(QObject *parent) : QObject(parent)
{
    DoubleDatabase dd;
    dd.exec("select * from travelline");
    if (dd.nextRow()) {
        QJsonObject jo = QJsonDocument::fromJson(dd.getString(1).toUtf8()).object();
        url = jo["url"].toString();
        hotelID = jo["hotelid"].toString();
        username = jo["username"].toString();
        password = jo["password"].toString();
        queryAvailability = dd.getString("f_availability");
        jaRoomTypes = QJsonDocument::fromJson(dd.getString("f_room_types").toUtf8()).array();
        jaRatePlans = QJsonDocument::fromJson(dd.getString("f_rate_plans").toUtf8()).array();
    }
}

void TravelLineConfig::updateAvailability(const QDate &startdate, const QDate &enddate,
        const QString &roomtypecode,
        const QString &rateplancode, int bookinglimit)
{
    QString q = queryAvailability;
    q.replace("%username", username);
    q.replace("%password", password);
    q.replace("%hotelid", hotelID);
    q.replace("%bookinglimit", QString::number(bookinglimit));
    q.replace("%startdate", startdate.toString("yyyy-MM-dd"));
    q.replace("%enddate", enddate.toString("yyyy-MM-dd"));
    q.replace("%inputtypecode", roomtypecode);
    q.replace("%rateplancode", rateplancode);
    qDebug() << q;
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    //request.setRawHeader("POST", "/Api/TLConnect.svc HTTP/1.1");
    request.setRawHeader("Content-Type", "text/xml;charset=UTF-8");
    request.setRawHeader("Content-Length", QString::number(q.toUtf8().length()).toLatin1());
    request.setRawHeader("SOAPAction", "https://www.travelline.ru/Api/TLConnect/HotelAvailNotifRQ");
    request.setUrl(QUrl(url));
    connect(manager, &QNetworkAccessManager::finished, this, &TravelLineConfig::finished);
    manager->post(request, q.toUtf8());
}

void TravelLineConfig::finished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
        qDebug() << "Network error: " << reply->error() << reply->errorString() << reply->readAll();
    else
        qDebug() << reply->readAll();
    reply->deleteLater();
}
