#ifndef DATABASEROW_H
#define DATABASEROW_H

#include "doubledatabase.h"

#define row_of_id(a, b, c) DatabaseRow::rowOfId(a, b, c)

class DatabaseRow
{
public:
    DatabaseRow();

    static bool rowOfId(DoubleDatabase &db, const QString &table, const QVariant &id);
};

#endif // DATABASEROW_H
