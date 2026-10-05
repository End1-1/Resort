#include "excely/pms/xmlhelpers.h"

namespace Excely {
namespace Pms {
namespace Xml {

QString escape(const QString &s)
{
    QString out;
    out.reserve(s.size());
    for (QChar c : s) {
        switch (c.unicode()) {
        case '&': out += QStringLiteral("&amp;"); break;
        case '<': out += QStringLiteral("&lt;"); break;
        case '>': out += QStringLiteral("&gt;"); break;
        case '"': out += QStringLiteral("&quot;"); break;
        case '\'': out += QStringLiteral("&apos;"); break;
        default: out += c; break;
        }
    }
    return out;
}

void skipElement(QXmlStreamReader &r)
{
    if (!r.isStartElement()) {
        return;
    }
    int depth = 1;
    while (depth > 0 && !r.atEnd()) {
        r.readNext();
        if (r.isStartElement()) {
            ++depth;
        } else if (r.isEndElement()) {
            --depth;
        }
    }
}

QString attr(const QXmlStreamReader &r, const char *name)
{
    return r.attributes().value(QLatin1String(name)).toString();
}

bool isStart(const QXmlStreamReader &r, const char *localName)
{
    return r.isStartElement() && r.name() == QLatin1String(localName);
}

bool isEnd(const QXmlStreamReader &r, const char *localName)
{
    return r.isEndElement() && r.name() == QLatin1String(localName);
}

} // namespace Xml
} // namespace Pms
} // namespace Excely
