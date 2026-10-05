#include "excely/pms/pmsconnectclient.h"

#include "excely/pms/soapenvelope.h"

#include <QEventLoop>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTimer>
#include <QUrl>

namespace Excely {
namespace Pms {

PmsConnectClient::PmsConnectClient(const Config &config, QObject *parent)
    : QObject(parent)
    , m_config(config)
{
}

void PmsConnectClient::setConfig(const Config &config)
{
    m_config = config;
}

QString PmsConnectClient::soapActionRead()
{
    return QStringLiteral("https://www.hopenapi.com/Api/PMSConnect/HotelReadReservationRQ");
}

QString PmsConnectClient::soapActionNotifReport()
{
    return QStringLiteral("https://www.hopenapi.com/Api/PMSConnect/NotifReportRQRequest");
}

QString PmsConnectClient::soapActionPing()
{
    return QStringLiteral("https://www.hopenapi.com/Api/PMSConnect/PingRQRequest");
}

QString PmsConnectClient::soapActionHotelAvail()
{
    return QStringLiteral("https://www.hopenapi.com/Api/PMSConnect/HotelAvailRQ");
}

bool PmsConnectClient::postSoap(const QString &soapAction,
                                const QString &otaBodyXml,
                                QByteArray *responseBody,
                                QString *errorText)
{
    if (responseBody) responseBody->clear();

    QString cfgErr;
    if (!m_config.isValid(&cfgErr)) {
        if (errorText) *errorText = cfgErr;
        return false;
    }

    const QByteArray payload = SoapEnvelope::wrap(m_config.username, m_config.password, otaBodyXml);

    QNetworkRequest req{QUrl(m_config.endpoint)};
    req.setHeader(QNetworkRequest::ContentTypeHeader, QStringLiteral("text/xml; charset=utf-8"));
    req.setRawHeader("SOAPAction", soapAction.toUtf8());
    req.setTransferTimeout(m_config.requestTimeoutMs);

    QNetworkReply *reply = m_nam.post(req, payload);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QTimer killer;
    killer.setSingleShot(true);
    QObject::connect(&killer, &QTimer::timeout, &loop, &QEventLoop::quit);
    killer.start(m_config.requestTimeoutMs + 5000);
    loop.exec();

    if (!reply->isFinished()) {
        reply->abort();
        if (errorText) *errorText = QStringLiteral("Request timed out");
        reply->deleteLater();
        return false;
    }

    const QByteArray raw = reply->readAll();
    const auto netErr = reply->error();
    const QString netStr = reply->errorString();
    reply->deleteLater();

    if (netErr != QNetworkReply::NoError) {
        if (errorText) {
            *errorText = QStringLiteral("Network error: %1 (%2)").arg(netStr, QString::fromUtf8(raw.left(500)));
        }
        return false;
    }

    if (responseBody) {
        *responseBody = SoapEnvelope::extractBodyInnerXml(raw);
        if (responseBody->isEmpty()) {
            *responseBody = raw;
        }
    }
    return true;
}

bool PmsConnectClient::ping(QString *errorText)
{
    QByteArray body;
    if (!postSoap(soapActionPing(),
                  buildOtaPingRqXml(m_config.hotelCode, m_config.protocolVersion),
                  &body, errorText)) {
        return false;
    }
    QVector<Channel::PmsError> errs;
    bool ok = false;
    parseSuccessOrErrors(body, QStringLiteral("OTA_PingRS"), &errs, &ok);
    if (!errs.isEmpty()) {
        if (errorText) *errorText = errs.first().text;
        return false;
    }
    // Some endpoints echo without Success — accept non-empty body
    return ok || !body.isEmpty();
}

bool PmsConnectClient::hotelAvail(HotelCatalog *out, QVector<Channel::PmsError> *errors)
{
    QByteArray body;
    QString err;
    if (!postSoap(soapActionHotelAvail(),
                  buildOtaHotelAvailRqXml(m_config.hotelCode, m_config.protocolVersion),
                  &body, &err)) {
        if (errors) {
            Channel::PmsError e;
            e.text = err;
            errors->append(e);
        }
        return false;
    }
    return parseHotelAvailRs(body, out, errors);
}

bool PmsConnectClient::readUndelivered(QVector<Channel::Booking> *out, QVector<Channel::PmsError> *errors)
{
    QByteArray body;
    QString err;
    if (!postSoap(soapActionRead(),
                  buildOtaReadRqXml(m_config.hotelCode, m_config.protocolVersion),
                  &body, &err)) {
        if (errors) {
            Channel::PmsError e;
            e.text = err;
            errors->append(e);
        }
        return false;
    }
    QVector<Channel::PmsError> local;
    QVector<Channel::PmsError> *errPtr = errors ? errors : &local;
    if (!parseResRetrieveRs(body, out, errPtr)) {
        if (errors && errors->isEmpty()) {
            Channel::PmsError e;
            e.text = QStringLiteral("Failed to parse OTA_ResRetrieveRS");
            errors->append(e);
        }
        return false;
    }
    for (Channel::Booking &b : *out) {
        if (b.hotelCode.isEmpty()) b.hotelCode = m_config.hotelCode;
    }
    // Hard errors (auth) → fail; warnings alone → ok
    for (const Channel::PmsError &e : *errPtr) {
        if (e.isAuthError() || e.isLimitError()) {
            return false;
        }
    }
    return true;
}

static QString dtAttr(const QDateTime &dt)
{
    if (!dt.isValid()) {
        return QDateTime::currentDateTime().toString(QStringLiteral("yyyy-MM-ddTHH:mm:ss"));
    }
    return dt.toString(QStringLiteral("yyyy-MM-ddTHH:mm:ss"));
}

bool PmsConnectClient::confirmReserved(const Channel::Booking &booking,
                                       const QString &pmsReservationId,
                                       QString *errorText)
{
    QStringList indexes;
    for (const Channel::RoomStay &rs : booking.rooms) {
        if (!rs.indexNumber.isEmpty()) indexes.append(rs.indexNumber);
    }
    const QString xml = buildOtaNotifReportReservedXml(
        m_config.hotelCode,
        m_config.protocolVersion,
        booking.channelReservationId,
        dtAttr(booking.createDateTime),
        dtAttr(booking.lastModifyDateTime),
        pmsReservationId,
        indexes);

    QByteArray body;
    if (!postSoap(soapActionNotifReport(), xml, &body, errorText)) {
        return false;
    }
    QVector<Channel::PmsError> errs;
    bool ok = false;
    parseSuccessOrErrors(body, QStringLiteral("OTA_NotifReportRS"), &errs, &ok);
    if (!errs.isEmpty() && !ok) {
        if (errorText) *errorText = errs.first().text;
        return false;
    }
    return true;
}

bool PmsConnectClient::requestDenied(const Channel::Booking &booking,
                                     const QString &reason,
                                     QString *errorText)
{
    const QString xml = buildOtaNotifReportDeniedXml(
        m_config.hotelCode,
        m_config.protocolVersion,
        booking.channelReservationId,
        dtAttr(booking.createDateTime),
        dtAttr(booking.lastModifyDateTime),
        reason);

    QByteArray body;
    if (!postSoap(soapActionNotifReport(), xml, &body, errorText)) {
        return false;
    }
    QVector<Channel::PmsError> errs;
    bool ok = false;
    parseSuccessOrErrors(body, QStringLiteral("OTA_NotifReportRS"), &errs, &ok);
    if (!errs.isEmpty() && !ok) {
        if (errorText) *errorText = errs.first().text;
        return false;
    }
    return true;
}

} // namespace Pms
} // namespace Excely
