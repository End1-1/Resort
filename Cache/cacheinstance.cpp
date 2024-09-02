#include "cacheinstance.h"
#include "cachebasestruct.h"
#include "doubledatabase.h"
#include "dlgselector.h"
#include <QMutex>
#include <QElapsedTimer>

static QMutex __mutex;

CacheInstance::CacheInstance(CacheBaseStruct *b) :
    QObject()
{
    QMutexLocker m( &__mutex);
    fStruct = b;
    load();
    fStruct->fInstance = this;
    fStruct->initSelector();
}

bool CacheInstance::selector(QStringList &codes, QStringList &values, bool multicheck)
{
    return fStruct->selector(codes, values, multicheck);
}

int CacheInstance::count()
{
    return fRows.count();
}

void CacheInstance::load()
{
    DoubleDatabase fDD;
    fRows.clear();
    fColumnNameMap.clear();
    QString sql;
    if (fStruct->fReplaceUpdateQuery.isEmpty()) {
        sql = fStruct->fLoadQuery;
    } else {
        sql = fStruct->fLoadQuery;
        sql = sql.replace(fStruct->fReplaceUpdateQuery, "");
    }
    fDD.exec(sql, fRows, fColumnNameMap);
    fStruct->postProcess(this);
}

void CacheInstance::clear()
{
    fRows.clear();
    fColumnNameMap.clear();
}

void CacheInstance::update(const QString &code)
{
    if (code == "0" || code.isEmpty()) {
        return;
    }
    QMutexLocker m( &__mutex);
    DoubleDatabase fDD;
    fDD[":f_id"] = code;
    if (fStruct->fReplaceUpdateQuery.isEmpty()) {
        if (fStruct->fUpdateQuery.isEmpty()) {
            fDD.exec(fStruct->fLoadQuery + " where f_id=:f_id");
        } else {
            fDD.exec(fStruct->fLoadQuery + " where " + fStruct->fUpdateQuery);
        }
    } else {
        QString sql = fStruct->fLoadQuery;
        sql.replace(fStruct->fReplaceUpdateQuery, fStruct->fUpdateQuery);
        fDD.exec(sql);
    }
    if (fRows.contains(code)) {
        if (fDD.nextRow()) {
            fRows[code] = fDD.fDbRows.at(0);
        } else {
            fRows.remove(code);
        }
    } else {
        if (fDD.nextRow()) {
            fRows[code] = fDD.fDbRows.at(0);
        }
    }
    m.unlock();
    fStruct->postUpdate(this, code);
    emit updated(fStruct->fCacheId, code);
}

QString CacheInstance::get(const QString &commonFilter)
{
    if (commonFilter.length() > 0) {
        fStruct->fSelector->fCommonFilter << commonFilter;
    }
    QStringList codes, names;
    selector(codes, names, false);
    fStruct->fSelector->fCommonFilter.clear();
    return codes.count() > 0 ? codes.at(0) : "";
}

void CacheInstance::initDB()
{
    return;
}
