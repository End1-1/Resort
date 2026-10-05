#ifndef EXCELY_PMS_SOAPENVELOPE_H
#define EXCELY_PMS_SOAPENVELOPE_H

#include <QString>

namespace Excely {
namespace Pms {

class SoapEnvelope
{
public:
    static constexpr const char *kSoapNs = "http://schemas.xmlsoap.org/soap/envelope/";
    static constexpr const char *kPmsNs = "https://www.hopenapi.com/Api/PMSConnect";
    static constexpr const char *kOtaNs = "http://www.opentravel.org/OTA/2003/05";

    static QByteArray wrap(const QString &username,
                           const QString &password,
                           const QString &otaBodyXml);

    /** Extract first child element of soap:Body as UTF-8 XML fragment. */
    static QByteArray extractBodyInnerXml(const QByteArray &soapResponse);
};

} // namespace Pms
} // namespace Excely

#endif
