#include "basevoucher.h"
#include "pprintvaucher.h"
#include <QMessageBox>

QStringList BaseVoucher::fFields;

BaseVoucher::BaseVoucher() :
    Base()
{
    setFields();
    foreach (QString s, fFields) {
        fSet[s] = false;
    }
    fNeedInsert = false;
    /* TO BE REMOVED AFTER AUDIT */
    set("f_doc", "");
    set("f_rec", "");
    /* END TO BE REMOVED */
}

BaseVoucher &BaseVoucher::set(const QString &field, const QVariant &value)
{
    if (!fFields.contains(field)) {
        QMessageBox::critical(fPreferences.getDefaultParentForMessage(), "Error", QString("Field not exists") + QString("\r\n") + field);
        return *this;
    }
    fValues[field] = value;
    fSet[field] = true;
    return *this;
}

void BaseVoucher::setA(const QString &field, const QVariant &value)
{
    fAddValues[field] = value;
}

QVariant BaseVoucher::get(const QString &field)
{
    return fValues[field];
}

QVariant BaseVoucher::getA(const QString &field)
{
    return fAddValues[field];
}

QString BaseVoucher::genId(const QString &source)
{
    QString id = uuidx(source);
    set("f_id", id);
    set("f_source", source);
    fNeedInsert = true;
    return id;
}

bool BaseVoucher::load(const QString &id)
{
    DoubleDatabase fDD;
    fDD[":f_id"] = id;    
    fDD.exec("select * from m_register where f_id=:f_id");
    if (!fDD.nextRow()) {
        return false;
    }
    foreach (QString s, fFields) {
        fValues[s] = fDD.getValue(s);
    }
    return loadAdditionalData();
}

void BaseVoucher::print()
{
    PPrintVaucher::printVaucher(fValues["f_id"].toString());
}

void BaseVoucher::print(const QString &id)
{
    PPrintVaucher::printVaucher(id);
}

void BaseVoucher::setFields()
{
    if (fFields.count() > 0) {
        return;
    }
    DoubleDatabase fDD;
    fDD.exec("describe m_register");
    for (int i = 0; i < fDD.rowCount(); i++) {
        fFields.append(fDD.getValue(i, "Field").toString());
    }
}

void BaseVoucher::save()
{
    DoubleDatabase fDD;
    if (fNeedInsert) {
        fDD[":f_id"] = fValues["f_id"];
        fDD.insert("m_register");
    }
    for (QMap<QString, QVariant>::const_iterator it = fValues.begin(); it != fValues.end(); it++) {
        if (it.key() == "f_id") {
            continue;
        }
        fDD[":" + it.key()] = it.value();
    }
    fDD.update("m_register", where_id(ap(fValues["f_id"].toString())));
}
