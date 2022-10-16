#include "databaserow.h"

DatabaseRow::DatabaseRow()
{

}

bool DatabaseRow::rowOfId(DoubleDatabase &db, const QString &table, const QVariant &id)
{
    db[":f_id"] = id;
    db.exec(QString("select * from %1 where f_id=:f_id").arg(table));
    if (db.nextRow()) {
        return true;
    }
    return false;
}
