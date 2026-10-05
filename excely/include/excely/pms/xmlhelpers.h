#ifndef EXCELY_PMS_XMLHELPERS_H
#define EXCELY_PMS_XMLHELPERS_H

#include <QString>
#include <QXmlStreamReader>

namespace Excely {
namespace Pms {
namespace Xml {

QString escape(const QString &s);
void skipElement(QXmlStreamReader &r);
QString attr(const QXmlStreamReader &r, const char *name);
bool isStart(const QXmlStreamReader &r, const char *localName);
bool isEnd(const QXmlStreamReader &r, const char *localName);

} // namespace Xml
} // namespace Pms
} // namespace Excely

#endif
