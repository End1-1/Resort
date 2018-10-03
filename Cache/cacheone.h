#ifndef CACHEONE_H
#define CACHEONE_H

#include "preferences.h"
#include "cacheinstance.h"
#include <QMap>

#define cache(x) CacheOne::getCache(x)

class CacheOne : public QObject
{
    Q_OBJECT
public:
    CacheOne();
    static void clearAll();
    static CacheInstance *getCache(int id);

protected:
    static QMap<int, CacheInstance*> fCacheOne;

public slots:
    void updateCache(int cacheId, const QString &id);
};

#endif // CACHEONE_H
