#include "traveline.h"
#include "logging.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QXmlStreamReader>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

Traveline::Traveline(const QString &username, const QString &password,
                     const QString &hotel, QObject *parent) : QObject(parent),
    fUsername(username),
    fPassword(password),
    fHotel(hotel)
{
    manager = new QNetworkAccessManager();
}

void Traveline::queryReservations(QJsonObject jo)
{
    connect(manager, &QNetworkAccessManager::finished, this, &Traveline::queryFinished);
    q = QString(jo["f_reservations"].toString());
    logging::writeTravelLineLog(q, "HotelReadReservationRQ");
    QNetworkRequest request;
    request.setRawHeader("Content-Type", "text/xml;charset=UTF-8");
    request.setRawHeader("Content-Length", QString::number(q.toUtf8().length()).toLatin1());
    request.setRawHeader("SOAPAction", "https://www.travelline.ru/Api/TLConnect/HotelReadReservationRQ");
    request.setUrl(QUrl("https://www.qatl.ru/Api/TLConnect.svc"));
    manager->post(request, q.toUtf8());

}

void Traveline::reservationCreated(QJsonObject jo)
{
    connect(manager, &QNetworkAccessManager::finished, this, &Traveline::confirmFinished);
    q = QString(jo["f_query"].toString()).replace("%username", fUsername).replace("%password", fPassword);
    logging::writeTravelLineLog(q, "NotifReportRQRequest");
    QNetworkRequest request;
    request.setRawHeader("Content-Type", "text/xml;charset=UTF-8");
    request.setRawHeader("Content-Length", QString::number(q.toUtf8().length()).toLatin1());
    request.setRawHeader("SOAPAction", "https://www.travelline.ru/Api/TLConnect/NotifReportRQRequest");
    request.setUrl(QUrl("https://www.qatl.ru/Api/TLConnect.svc"));
    manager->post(request, q.toUtf8());
}

Traveline::~Traveline()
{
    delete manager;
}

void Traveline::readyRead()
{
    QNetworkReply *reply  = static_cast<QNetworkReply*>(sender());
    if (reply->error() != QNetworkReply::NoError)
        qDebug() << "Network error: " << reply->error() << reply->errorString() << reply->readAll();
    else
        qDebug() << reply->readAll();
}

void Traveline::queryFinished(QNetworkReply *reply)
{
    QByteArray d;
    if (reply->error() != QNetworkReply::NoError)
        logging::writeTravelLineLog("Network error: " + reply->error() + reply->errorString() + reply->readAll(), "HotelReadReservationRQ");
    else {
        d = reply->readAll();
        logging::writeTravelLineLog(d, "HotelReadReservationRQ");
    }

    QXmlStreamReader r(d);
    QJsonArray reservations;
    QJsonObject res;
    QJsonObject room;
    bool guestOfRes = false;
    QJsonObject guest;
    bool guestOfGlobal = false;
    QJsonObject guestGlobal;
    while (!r.atEnd() && !r.hasError()) {
        r.readNext();

        if (r.isStartElement()) {
            if (r.name() == "OTA_ResRetrieveRS") {

            } else if (r.name() == "ReservationsList") {

            } else if (r.name() == "HotelReservation") {
                res = QJsonObject();
            } else if (r.name() == "RequestorID") {
                res["cardex"] = r.attributes().value("ID").toString();
            } else if (r.name() == "Guarantee") {
                res["guarantee"] = r.attributes().value("GuaranteeCode").toString();
                do {
                    r.readNext();
                    if (r.isEndElement()) {
                        if (r.name() == "Guarantee") {
                            break;
                        }
                    }
                    if (r.isStartElement()) {
                        if (r.attributes().hasAttribute("PaymentMethodName")) {
                            r.readNext();
                            res["paymenttype"] = r.readElementText();
                        }
                        if (r.attributes().hasAttribute("PaymentSystemName")) {
                            r.readNext();
                            res["paymentname"] = r.readElementText();
                        }
                        if (r.name() == "GuaranteePayment") {
                            res["guaranteepayment"] = r.attributes().value("Type").toString();
                        }
                    }
                } while (!r.hasError());
            } else if (r.name() == "Comments") {
                r.readNext();
                r.readNext();
                QString txt = r.readElementText();
                if (txt.contains("Reservation number in sales channel")) {
                    res["comment"] = txt;
                }
            } else if (r.name() == "UniqueID") {
                if (!res.contains("res_id")) {
                    res["res_id"] = r.attributes().value("ID").toString();
                }
            } else if (r.name() == "RoomStay") {
                room = QJsonObject();
            } else if (r.name() == "RoomType") {
                room["room_type"] = r.attributes().value("RoomTypeCode").toString();
            } else if (r.name() == "TimeSpan") {
                room["arrival"] = r.attributes().value("Start").toString();
                room["departure"] = r.attributes().value("End").toString();
                room["days"] = r.attributes().value("Duration").toString();
            } else if (r.name() == "RatePlan") {
                room["rateplan"] = r.attributes().value("RatePlanID").toString();
            } else if (r.name() == "GuestsCount") {
                room["guest_count"] = room["guest_count"].toInt() + r.attributes().value("Count").toString().toInt();
            } else if (r.name() == "ResGuests") {
                guestOfRes = true;
            } else if (r.name() == "ResGuest") {
                guest = QJsonObject();
            } else if (r.name() == "GivenName") {
                if (guestOfRes) {
                    guest["first_name"] = r.readElementText();
                } else {
                    guestGlobal["first_name"] = r.readElementText();
                }
            } else if (r.name() == "Surname") {
                if (guestOfRes) {
                    guest["last_name"] = r.readElementText();
                } else {
                    guestGlobal["last_name"] = r.readElementText();
                }
            } else if (r.name() == "MiddleName") {
                if (guestOfRes) {
                    guest["middle_name"] = r.readElementText();
                } else {
                    guestGlobal["middle_name"] = r.readElementText();
                }
            } else if (r.name() == "CitizenCountryName") {
                if (guestOfRes) {
                    guest["country"] = r.attributes().value("Code").toString();
                } else {
                    guestGlobal["country"] = r.attributes().value("Code").toString();
                }
            } else if (r.name() == "Telephone") {
                if (guestOfRes) {
                    guest["phone"] = r.attributes().value("PhoneNumber").toString();
                } else {
                    guestGlobal["phone"] = r.attributes().value("PhoneNumber").toString();
                }
            } else if (r.name() == "Email") {
                if (guestOfRes) {
                    guest["email"] = r.readElementText();
                } else {
                    guestGlobal["email"] = r.readElementText();
                }
            } else if (r.name() == "ResGlobalInfo") {
                guestOfGlobal = true;
            }
        }
        if (r.isEndElement()) {
            if (r.name() == "HotelReservation") {
                reservations.append(res);
            } else if (r.name() == "RoomStay") {
                QJsonArray jatemp = res["rooms"].toArray();
                jatemp.append(room);
                res["rooms"] = jatemp;
            } else if (r.name() == "ResGuest") {
                QJsonArray jatemp = res["guests"].toArray();
                jatemp.append(guest);
                res["guests"] = jatemp;
            } else if (r.name() == "ResGuests") {
                guestOfRes = false;
            } else if (r.name() == "ResGlobalInfo"){
                guestOfGlobal = false;
                res["main_guest"] = guestGlobal;
            }
        }
    }
    if (r.hasError()) {
        qDebug() << "xmlFile.xml Parse Error" << r.errorString() << r.lineNumber() << r.columnNumber();
    }
    reply->deleteLater();
    emit end(QJsonDocument(reservations).toJson(QJsonDocument::Compact));
}

void Traveline::confirmFinished(QNetworkReply *reply)
{
    QByteArray d;
    if (reply->error() != QNetworkReply::NoError) {
        logging::writeTravelLineLog("Network error: " + reply->error() + reply->errorString() + reply->readAll(), "NotifReportRQRequest");
    }
    else {
        d = reply->readAll();
        logging::writeTravelLineLog(d, "NotifReportRQRequest");
    }
    emit end(d);
}
