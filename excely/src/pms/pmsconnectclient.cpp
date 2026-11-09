#include "excely/pms/pmsconnectclient.h"

#include "excely/pms/soapenvelope.h"

#include <QDateTime>
#include <QDir>
#include <QEventLoop>
#include <QFile>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QStandardPaths>
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

QString PmsConnectClient::soapActionHotelAvailNotif()
{
    return QStringLiteral("https://www.hopenapi.com/Api/PMSConnect/HotelAvailNotifRQ");
}

QString PmsConnectClient::soapActionHotelRateAmountNotif()
{
    return QStringLiteral("https://www.hopenapi.com/Api/PMSConnect/HotelRateAmountNotifRQ");
}

QString PmsConnectClient::soapActionCancel()
{
    return QStringLiteral("https://www.hopenapi.com/Api/PMSConnect/CancelRQ");
}

namespace {

QString soapActionShortName(const QString &soapAction)
{
    const int slash = soapAction.lastIndexOf(QLatin1Char('/'));
    QString name = slash >= 0 ? soapAction.mid(slash + 1) : soapAction;
    name.remove(QStringLiteral("Request"));
    name.remove(QLatin1Char(' '));
    if (name.isEmpty()) {
        name = QStringLiteral("soap");
    }
    return name;
}

/** %TEMP%/resort/excely/e_dd_MM_yyyy_HH_mm_ss[_n]_{Action}_{rq|rs}.xml — no credentials. */
void dumpSoapExchange(const QString &soapAction,
                      const QString &otaBodyXml,
                      const QByteArray &rawResponse)
{
    const QString tempRoot = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    if (tempRoot.isEmpty()) {
        return;
    }
    QDir dir(tempRoot);
    if (!dir.mkpath(QStringLiteral("resort/excely"))) {
        return;
    }
    const QString folder = dir.filePath(QStringLiteral("resort/excely"));

    const QString stamp = QDateTime::currentDateTime().toString(QStringLiteral("dd_MM_yyyy_HH_mm_ss"));
    const QString action = soapActionShortName(soapAction);
    QString base = QStringLiteral("e_%1_%2").arg(stamp, action);
    QString pathRq = QDir(folder).filePath(base + QStringLiteral("_rq.xml"));
    int n = 1;
    while (QFile::exists(pathRq) || QFile::exists(QDir(folder).filePath(base + QStringLiteral("_rs.xml")))) {
        base = QStringLiteral("e_%1_%2_%3").arg(stamp).arg(action).arg(n++);
        pathRq = QDir(folder).filePath(base + QStringLiteral("_rq.xml"));
    }
    const QString pathRs = QDir(folder).filePath(base + QStringLiteral("_rs.xml"));

    {
        QFile f(pathRq);
        if (f.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            // OTA body only — SoapEnvelope credentials are never written
            f.write(otaBodyXml.toUtf8());
        }
    }
    {
        QFile f(pathRs);
        if (f.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            f.write(rawResponse);
        }
    }
}

} // namespace

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

    dumpSoapExchange(soapAction, otaBodyXml, raw);

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

bool PmsConnectClient::hotelAvailNotif(const QVector<AvailStatusMessage> &messages,
                                       QVector<Channel::PmsError> *errors)
{
    if (messages.isEmpty()) {
        if (errors) {
            Channel::PmsError e;
            e.text = QStringLiteral("No availability messages to send");
            errors->append(e);
        }
        return false;
    }

    QByteArray body;
    QString err;
    if (!postSoap(soapActionHotelAvailNotif(),
                  buildOtaHotelAvailNotifRqXml(m_config.hotelCode, m_config.protocolVersion, messages),
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
    bool ok = false;
    parseSuccessOrErrors(body, QStringLiteral("OTA_HotelAvailNotifRS"), errPtr, &ok);
    if (!ok && !errPtr->isEmpty()) {
        return false;
    }
    // Accept Success or empty errors with non-empty body
    return ok || errPtr->isEmpty();
}

bool PmsConnectClient::hotelRateAmountNotif(const QVector<RateAmountMessage> &messages,
                                            QVector<Channel::PmsError> *errors)
{
    if (messages.isEmpty()) {
        if (errors) {
            Channel::PmsError e;
            e.text = QStringLiteral("No rate amount messages to send");
            errors->append(e);
        }
        return false;
    }

    QByteArray body;
    QString err;
    if (!postSoap(soapActionHotelRateAmountNotif(),
                  buildOtaHotelRateAmountNotifRqXml(m_config.hotelCode, m_config.protocolVersion, messages),
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
    bool ok = false;
    parseSuccessOrErrors(body, QStringLiteral("OTA_HotelRateAmountNotifRS"), errPtr, &ok);
    if (!ok && !errPtr->isEmpty()) {
        return false;
    }
    return ok || errPtr->isEmpty();
}

bool PmsConnectClient::cancelReservation(const QString &channelReservationId,
                                         const QString &reason,
                                         QString *errorText)
{
    if (channelReservationId.trimmed().isEmpty()) {
        if (errorText) {
            *errorText = QStringLiteral("Empty channel reservation id for cancel");
        }
        return false;
    }

    QByteArray body;
    if (!postSoap(soapActionCancel(),
                  buildOtaCancelRqXml(m_config.protocolVersion, channelReservationId.trimmed(), reason),
                  &body, errorText)) {
        return false;
    }

    QVector<Channel::PmsError> errs;
    bool ok = false;
    parseSuccessOrErrors(body, QStringLiteral("OTA_CancelRS"), &errs, &ok);
    if (!ok && !errs.isEmpty()) {
        if (errorText) {
            *errorText = errs.first().text;
        }
        return false;
    }
    return ok || errs.isEmpty();
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

// Exely matches NotifReport LastModifyDateTime against ResRetrieveRS byte-for-byte
static QString dtAttr(const QString &raw, const QDateTime &dt)
{
    if (!raw.trimmed().isEmpty()) {
        return raw;
    }
    const QDateTime v = dt.isValid() ? dt : QDateTime::currentDateTime();
    return v.toString(Qt::ISODateWithMs);
}

bool PmsConnectClient::confirmReservedRooms(const Channel::Booking &booking,
                                            const QVector<Channel::RoomConfirmation> &rooms,
                                            QString *errorText)
{
    if (rooms.isEmpty()) {
        if (errorText) *errorText = QStringLiteral("No PMS reservation ids to confirm");
        return false;
    }
    const QString xml = buildOtaNotifReportReservedRoomsXml(
        m_config.hotelCode,
        m_config.protocolVersion,
        booking.channelReservationId,
        dtAttr(booking.createDateTimeRaw, booking.createDateTime),
        dtAttr(booking.lastModifyDateTimeRaw, booking.lastModifyDateTime),
        rooms);

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
        dtAttr(booking.createDateTimeRaw, booking.createDateTime),
        dtAttr(booking.lastModifyDateTimeRaw, booking.lastModifyDateTime),
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
        dtAttr(booking.createDateTimeRaw, booking.createDateTime),
        dtAttr(booking.lastModifyDateTimeRaw, booking.lastModifyDateTime),
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
