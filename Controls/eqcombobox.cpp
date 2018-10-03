#include "eqcombobox.h"
#include "cacheone.h"
#include <QWheelEvent>

EQComboBox::EQComboBox(QWidget *parent) :
    QComboBox(parent)
{

}

void EQComboBox::setIndexForData(const QVariant &data)
{
    int index = findData(data);
    setCurrentIndex(index);
}
int EQComboBox::getCache()
{
    return fCache;
}

int EQComboBox::asInt()
{
    return currentData().toInt();
}

void EQComboBox::setCache(int cacheID)
{
    fCache  = cacheID;
    CacheInstance *ci = cache(cacheID);
    QMap<QString, QList<QVariant> >::iterator it = ci->fRows.begin();
    while (it != ci->fRows.end()) {
        addItem(it.value().at(1).toString(), it.value().at(0));
        it++;
    }
}

QString EQComboBox::getField()
{
    return fField;
}

void EQComboBox::setField(const QString &name)
{
    fField = name;
}

void EQComboBox::wheelEvent(QWheelEvent *e)
{
    e->ignore();
}
