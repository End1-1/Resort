#include "excely/pms/soapenvelope.h"

#include "excely/pms/xmlhelpers.h"

#include <QXmlStreamReader>
#include <QXmlStreamWriter>

namespace Excely {
namespace Pms {

QByteArray SoapEnvelope::wrap(const QString &username,
                              const QString &password,
                              const QString &otaBodyXml)
{
    QString xml;
    xml.reserve(otaBodyXml.size() + 512);
    xml += QStringLiteral(
        "<?xml version=\"1.0\" encoding=\"utf-8\"?>"
        "<soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\">"
        "<soap:Header xmlns=\"https://www.hopenapi.com/Api/PMSConnect\">"
        "<Security Username=\"%1\" Password=\"%2\"/>"
        "</soap:Header>"
        "<soap:Body>"
        "%3"
        "</soap:Body>"
        "</soap:Envelope>");
    return xml
        .arg(Xml::escape(username), Xml::escape(password), otaBodyXml)
        .toUtf8();
}

QByteArray SoapEnvelope::extractBodyInnerXml(const QByteArray &soapResponse)
{
    QXmlStreamReader r(soapResponse);
    while (!r.atEnd()) {
        r.readNext();
        if (r.isStartElement() && (r.name() == QLatin1String("Body")
                                  || r.qualifiedName() == QLatin1String("soap:Body")
                                  || r.qualifiedName() == QLatin1String("s:Body"))) {
            // Capture inner XML of first child element
            while (!r.atEnd()) {
                r.readNext();
                if (r.isStartElement()) {
                    const QString name = r.qualifiedName().toString();
                    QString frag;
                    QXmlStreamWriter w(&frag);
                    w.setAutoFormatting(false);
                    w.writeCurrentToken(r);
                    int depth = 1;
                    while (depth > 0 && !r.atEnd()) {
                        r.readNext();
                        if (r.isStartElement()) {
                            ++depth;
                            w.writeCurrentToken(r);
                        } else if (r.isEndElement()) {
                            w.writeCurrentToken(r);
                            --depth;
                        } else if (r.isCharacters() || r.isCDATA() || r.isComment()) {
                            w.writeCurrentToken(r);
                        }
                    }
                    Q_UNUSED(name);
                    return frag.toUtf8();
                }
                if (r.isEndElement()) {
                    break;
                }
            }
        }
    }
    // Not wrapped — return as-is
    return soapResponse;
}

} // namespace Pms
} // namespace Excely
