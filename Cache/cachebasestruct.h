#ifndef CACHEBASESTRUCT_H
#define CACHEBASESTRUCT_H

#include <QString>
#include <QList>
#include "utils.h"
#include "cacheinstance.h"
#include "cacheone.h"


class DlgSelector;

class CacheBaseStruct
{
public:
    CacheBaseStruct();
    virtual ~CacheBaseStruct();
    bool fValid;
    bool fFlagUpdated;
    int fCacheId;
    QString fLoadQuery;
    QString fUpdateQuery;
    QString fReplaceUpdateQuery;
    QList<int> fSelectorColumnsWidths;
    QStringList fSelectorColumnNames;
    QList<QVariant> fData;
    QString fSelectorTitle;
    CacheInstance *fInstance;
    static QDate fWorkingDate;
    void reInit();
    inline QVariant getVariant(const QString &field) { return fData[fInstance->fColumnNameMap[field.toLower()]]; }
    inline QString getString(const QString &field) { return fData[fInstance->fColumnNameMap[field.toLower()]].toString(); }
    inline QString getString(int column) { return fData[column].toString(); }
    inline int getInt(const QString &field) { return fData[fInstance->fColumnNameMap[field.toLower()]].toInt(); }
    inline QDate getDate(const QString &field) { return fData[fInstance->fColumnNameMap[field.toLower()]].toDate(); }
    inline QDate getDate(int column) { return fData[column].toDate(); }
    inline double getDouble(const QString &field) { return fData[fInstance->fColumnNameMap[field.toLower()]].toDouble(); }
    virtual bool get(const QString &code);
    bool get(int code);
    void getSelectorWidths(int count, ...);
    void getSelectorTitles(const QStringList &titles);
    void getSelectorTwoField();
    DlgSelector *fSelector;
    void initSelector();
    bool selector(QStringList &codes, QStringList &names, bool multicheck);
    void setValue(const QString &field, const QVariant &value);
    virtual void postProcess(CacheInstance *ci);
    virtual void postUpdate(CacheInstance *ci, const QString &id);
};

#endif // CACHEBASESTRUCT_H
