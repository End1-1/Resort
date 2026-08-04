#include "cacheinstance.h"
#include "cachebasestruct.h"
#include "doubledatabase.h"
#include "dlgselector.h"
#include <QMutex>
#include <QElapsedTimer>

static QMutex __mutex;

static void loadInstanceRows(CacheInstance *ci)
{
    DoubleDatabase fDD;
    ci->fRows.clear();
    ci->fColumnNameMap.clear();
    QString sql;
    if (ci->fStruct->fReplaceUpdateQuery.isEmpty()) {
        sql = ci->fStruct->fLoadQuery;
    } else {
        sql = ci->fStruct->fLoadQuery;
        sql = sql.replace(ci->fStruct->fReplaceUpdateQuery, "");
    }
    fDD.exec(sql, ci->fRows, ci->fColumnNameMap);
    ci->fStruct->postProcess(ci);
}

CacheInstance::CacheInstance(CacheBaseStruct *b) :
    QObject()
{
    QMutexLocker m( &__mutex);
    fStruct = b;
    loadInstanceRows(this);
    fStruct->fInstance = this;
    fStruct->initSelector();
}

CacheInstance::~CacheInstance()
{
    if (fStruct) {
        if (fStruct->fInstance == this) {
            fStruct->fInstance = nullptr;
        }
        delete fStruct;
        fStruct = nullptr;
    }
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
    QMutexLocker m( &__mutex);
    loadInstanceRows(this);
    if (fStruct) {
        fStruct->fFlagUpdated = true;
    }
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
    {
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
    }
    fStruct->postUpdate(this, code);
    emit updated(fStruct->fCacheId, code);
}

QString CacheInstance::get(const QString &commonFilter)
{
    if (!fStruct || !fStruct->fSelector) {
        return "";
    }
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
