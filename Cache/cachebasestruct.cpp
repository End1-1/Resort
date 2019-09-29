#include "cachebasestruct.h"
#include "cacheone.h"
#include "dlgselector.h"

QDate CacheBaseStruct::fWorkingDate;

CacheBaseStruct::CacheBaseStruct()
{
    fCacheId = 0;
    fLoadQuery = "";
    fUpdateQuery = "f_id";
    fValid = true;
    fInstance = nullptr;
    fFlagUpdated = false;
}

CacheBaseStruct::~CacheBaseStruct()
{
}

void CacheBaseStruct::reInit()
{
    if (fInstance) {
        fInstance->deleteLater();
        fInstance = nullptr;
    }
}

bool CacheBaseStruct::get(const QString &code)
{
    if (!fInstance) {
        fInstance = cache(fCacheId);
    }
    if (!fInstance->fRows.contains(code)) {
        fValid = false;
        return false;
    }
    fData = fInstance->fRows[code];
    return fData.count() > 0;
}

bool CacheBaseStruct::get(int code)
{
    return get(QString::number(code));
}

void CacheBaseStruct::getSelectorWidths(int count, ...)
{
    va_list vl;
    va_start(vl, count);
    for (int i = 0; i < count; i++) {
        fSelectorColumnsWidths << va_arg(vl, int);
    }
    va_end(vl);
}

void CacheBaseStruct::getSelectorTitles(const QStringList &titles)
{
    fSelectorColumnNames = titles;
}

void CacheBaseStruct::getSelectorTwoField()
{
    fSelectorColumnsWidths << 80 << 300;
    fSelectorColumnNames << QObject::tr("Code") << QObject::tr("Name");
}

void CacheBaseStruct::initSelector()
{
    fSelector = new DlgSelector(__preferences.getDefaultParentForMessage());
    fSelector->configure(fSelectorTitle, fSelectorColumnsWidths, fSelectorColumnNames);
    if (!fInstance) {
        
    }
    fSelector->fCacheInstance = fInstance;
    fSelector->setData(fInstance->fRows);
}

bool CacheBaseStruct::selector(QStringList &codes, QStringList &names, bool multicheck)
{
    fSelector->fMultiCheck = multicheck;
    if (fFlagUpdated) {
        fFlagUpdated = false;
        fSelector->setData(fInstance->fRows);
    }
    return fSelector->exec(codes, names) == QDialog::Accepted;
}

void CacheBaseStruct::setValue(const QString &field, const QVariant &value)
{
    if (fData.count() == 0) {
        return;
    }
    fData[fInstance->fColumnNameMap[field]] = value;
}

void CacheBaseStruct::postProcess(CacheInstance *ci)
{
    Q_UNUSED(ci)
}

void CacheBaseStruct::postUpdate(CacheInstance *ci, const QString &id)
{
    fFlagUpdated = true;
    Q_UNUSED(ci)
    Q_UNUSED(id)
}
