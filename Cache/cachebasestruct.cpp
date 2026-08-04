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
    fSelector = nullptr;
}

CacheBaseStruct::~CacheBaseStruct()
{
    if (fSelector) {
        fSelector->setParent(nullptr);
        delete fSelector;
        fSelector = nullptr;
    }
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
    fInstance = cache(fCacheId);
    if (!fInstance) {
        fValid = false;
        fData.clear();
        return false;
    }
    if (!fInstance->fRows.contains(code)) {
        fValid = false;
        fData.clear();
        return false;
    }
    fData = fInstance->fRows[code];
    fValid = fData.count() > 0;
    return fValid;
}

int CacheBaseStruct::columnIndex(const QString &field) const
{
    if (!fValid || !fInstance) {
        return -1;
    }
    const auto it = fInstance->fColumnNameMap.constFind(field.toLower());
    if (it == fInstance->fColumnNameMap.constEnd()) {
        return -1;
    }
    return it.value();
}

QVariant CacheBaseStruct::getVariant(const QString &field) const
{
    int col = columnIndex(field);
    if (col < 0 || col >= fData.size()) {
        return QVariant();
    }
    return fData.at(col);
}

QString CacheBaseStruct::getString(const QString &field) const
{
    return getVariant(field).toString();
}

QString CacheBaseStruct::getString(int column) const
{
    if (column < 0 || column >= fData.size()) {
        return QString();
    }
    return fData.at(column).toString();
}

int CacheBaseStruct::getInt(const QString &field) const
{
    return getVariant(field).toInt();
}

QDate CacheBaseStruct::getDate(const QString &field) const
{
    return getVariant(field).toDate();
}

QDate CacheBaseStruct::getDate(int column) const
{
    if (column < 0 || column >= fData.size()) {
        return QDate();
    }
    return fData.at(column).toDate();
}

double CacheBaseStruct::getDouble(const QString &field) const
{
    return getVariant(field).toDouble();
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
    fSelector->fCacheId = fCacheId;
    fSelector->fCacheInstance = fInstance;
    fSelector->setData(fInstance->fRows);
}

bool CacheBaseStruct::selector(QStringList &codes, QStringList &names, bool multicheck)
{
    fSelector->fMultiCheck = multicheck;
    fSelector->setData(fInstance->fRows);
    fFlagUpdated = false;
    return fSelector->exec(codes, names) == QDialog::Accepted;
}

void CacheBaseStruct::setValue(const QString &field, const QVariant &value)
{
    if (!fValid || !fInstance || fData.isEmpty()) {
        return;
    }
    int col = columnIndex(field);
    if (col < 0) {
        return;
    }
    fData[col] = value;
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
