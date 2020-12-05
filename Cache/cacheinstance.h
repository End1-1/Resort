#ifndef CACHEINSTANCE_H
#define CACHEINSTANCE_H

#include <QObject>
#include <QMap>
#include <QList>

class CacheBaseStruct;

class CacheInstance : public QObject
{
    Q_OBJECT
public:
    CacheInstance(CacheBaseStruct *b);
    QMap<QString, QList<QVariant> > fRows;
    QMap<QString, int> fColumnNameMap;
    bool selector(QStringList &codes, QStringList &values, bool multicheck);
    int count();
    void load();
    void clear();
    void update(const QString &code);
    QString get(const QString &commonFilter);
    QMap<QString, QStringList> fFieldFilter;
    CacheBaseStruct *fStruct;
private:
    void initDB();
signals:
    void updated(int cacheId, const QString &code);
};

#endif // CACHEINSTANCE_H
