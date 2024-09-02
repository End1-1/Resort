#include "defrest.h"

QMap<QString, QString> DefRest::fData;

DefRest::DefRest(const QString &comp) :
    Base()
{
    DoubleDatabase fDD;
    fDD[":f_comp"] = comp;
    fDD.exec("select f_key, f_value from r_config where upper(f_comp)=upper(:f_comp)");
    while (fDD.nextRow()) {
        fData[fDD.getString(0)] = fDD.getString(1);
    }
}

QString DefRest::v(const QString &key)
{
    return fData[key];
}
