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
    QVariant getVariant(const QString &field) const;
    QString getString(const QString &field) const;
    QString getString(int column) const;
    int getInt(const QString &field) const;
    QDate getDate(const QString &field) const;
    QDate getDate(int column) const;
    double getDouble(const QString &field) const;
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

protected:
    int columnIndex(const QString &field) const;
};

#endif // CACHEBASESTRUCT_H
