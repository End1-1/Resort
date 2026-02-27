#include "doubledatabase.h"
#include "baseuid.h"
#include "logging.h"
#include "qjsonvalue.h"
#include <QMutexLocker>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDir>
#include <QHostInfo>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QSqlDriver>
#include <QSqlField>

int DoubleDatabase::fCounter = 0;

#ifdef _RESTAURANT_
#include "rface.h"
RFace* __rface;
#endif

static QMutex fMutex;
QString __dd1Host;
QString __dd1Database;
QString __dd1Username;
QString __dd1Password;

DoubleDatabase::DoubleDatabase() :
    QObject()
{
    init();

    if(__dd1Host.isEmpty()) {
        return;
    }

    configureDatabase(fDb1, __dd1Host, __dd1Database, __dd1Username, __dd1Password);
    open();
}

DoubleDatabase::DoubleDatabase(const QString &host, const QString &db, const QString &user, const QString &password) :
    QObject()
{
    init();
    configureDatabase(fDb1, host, db, user, password);
    open();
}

DoubleDatabase::~DoubleDatabase()
{
    fDb1 = QSqlDatabase::addDatabase(_DBDRIVER_);
    QSqlDatabase::removeDatabase(fDbName1);
}

QString DoubleDatabase::getDbNumber(const QString &prefix)
{
    return QString("%1-%2").arg(prefix).arg(fCounter);
}

QVariant& DoubleDatabase::operator[](const QString &name)
{
    return fBindValues[name];
}

void DoubleDatabase::setDatabase(const QString &host, const QString &db, const QString &user, const QString &password)
{
    configureDatabase(fDb1, host, db, user, password);
}

bool DoubleDatabase::open()
{
    fLastError = "";
    bool isOpened = true;

    if(fDb1.open()) {
        //fDb1.transaction();
    } else {
        isOpened = false;
        fLastError += "#1: " + fDb1.lastError().databaseText() + " database: " + fDb1.databaseName() + " drivers: " +
                      fDb1.drivers().join(',');
        logEvent(fLastError);
    }

    return isOpened;
}

bool DoubleDatabase::startTransaction()
{
    //    qDebug() << "Opened" << fDb1.isOpen();
    //    qDebug() << "Futures" << fDb1.driver()->hasFeature(QSqlDriver::Transactions);
    //    qDebug() << "TRansaction" << fDb1.transaction();
    //    if (fExecFlagSlave) {
    //        fDb2.transaction();
    //    }
    QSqlQuery *q = new QSqlQuery(fDb1);
    bool result = q->exec("start transaction");
    delete q;
    return result;
}

bool DoubleDatabase::commit()
{
    //    fDb1.commit();
    //    if (fExecFlagSlave) {
    //        fDb2.commit();
    //    }
    //    return true;
    QSqlQuery *q1 = new QSqlQuery(fDb1);
    bool result = q1->exec("commit");
    delete q1;
    return result;
}

void DoubleDatabase::rollback()
{
    QSqlQuery *q1 = new QSqlQuery(fDb1);
    bool result = q1->exec("rollback");
    delete q1;
}

void DoubleDatabase::close(bool commit)
{
    if(commit) {
        fDb1.commit();
    } else {
        fDb1.rollback();
    }

    fDb1.close();
}

bool DoubleDatabase::exec(const QString &sqlQuery)
{
    QStringList l = sqlQuery.split(";", Qt::SkipEmptyParts);
    bool a = false;

    for(const QString &s : l) {
        a = exec(s, fDbRows, fNameColumnMap);

        if(!a) {
            return false;
        }
    }

    if(a) {
        for(QMap<QString, int>::const_iterator it = fNameColumnMap.constBegin(); it != fNameColumnMap.constEnd(); it++) {
            fColumnNameMap[it.value()]  = it.key();
        }
    }

    return a;
}

bool DoubleDatabase::exec(const QString &sqlQuery, QList<QList<QVariant> >& dbrows)
{
    QMap<QString, int> cols;
    return exec(sqlQuery, dbrows, cols);
}

bool DoubleDatabase::exec(const QString &sqlQuery, QList<QList<QVariant> >& dbrows, QMap<QString, int>& columns)
{
    QElapsedTimer e;
    e.start();
    QSqlQuery *q1 = new QSqlQuery(fDb1);
    bool isSelect = true;
    bool result = true;

    if(!exec(q1, sqlQuery, isSelect)) {
        delete q1;
        fBindValues.clear();
        return false;
    }

    if(logEnabled) {
        logEvent("#1 [" + QString::number(e.elapsed()) + "] " + fDb1.databaseName() + " "  + lastQuery(q1));
        e.restart();
    }

    fBindValues.clear();

    if(isSelect) {
        fCursorPos = -1;
        columns.clear();
        QSqlRecord r = q1->record();

        for(int i = 0; i < r.count(); i++) {
            columns[r.field(i).name().toLower()] = i;
        }

        int colCount = r.count();
        dbrows.clear();

        while(q1->next()) {
            QList<QVariant> row;

            for(int i = 0; i < colCount; i++) {
                row << q1->value(i);
            }

            dbrows << row;
        }
    }

    delete q1;
    return result;
}

bool DoubleDatabase::exec(const QString &sqlQuery, QMap<QString, QList<QVariant> >& dbrows, QMap<QString, int>& columns)
{
    QElapsedTimer e;
    e.start();
    QSqlQuery *q1 = new QSqlQuery(fDb1);
    bool isSelect = true;
    bool result = true;

    if(!exec(q1, sqlQuery, isSelect)) {
        delete q1;
        fBindValues.clear();
        return false;
    }

    if(logEnabled) {
        logEvent("#1 [" + QString::number(e.elapsed()) + "] " + lastQuery(q1));
        e.restart();
    }

    fBindValues.clear();

    if(isSelect) {
        fCursorPos = -1;
        columns.clear();
        QSqlRecord r = q1->record();

        for(int i = 0; i < r.count(); i++) {
            columns[r.field(i).name().toLower()] = i;
        }

        int colCount = r.count();
        dbrows.clear();

        while(q1->next()) {
            QList<QVariant> row;

            for(int i = 0; i < colCount; i++) {
                row << q1->value(i);
            }

            dbrows[q1->value(0).toString()] << row;
        }
    }

    return result;
}

int DoubleDatabase::rowCount()
{
    return fDbRows.count();
}

int DoubleDatabase::columnCount()
{
    return fNameColumnMap.count();
}

bool DoubleDatabase::nextRow(QList<QVariant>& row)
{
    bool result = nextRow();

    if(result) {
        row = fDbRows.at(fCursorPos);
    }

    return result;
}

bool DoubleDatabase::nextRow()
{
    if(fCursorPos < rowCount() - 1 && rowCount() > 0) {
        fCursorPos++;
        return true;
    }

    return false;
}

bool DoubleDatabase::valuesToJsonObject(QJsonObject &jo)
{
    const QList<QVariant>& row = fDbRows.at(fCursorPos);

    for(auto it = fColumnNameMap.cbegin(); it != fColumnNameMap.cend(); ++it) {
        int colIndex = it.key();
        const QString &fieldName = it.value();

        if(colIndex < 0 || colIndex >= row.size())
            continue;

        QVariant v = row.at(colIndex);

        if(fieldName.contains("time", Qt::CaseInsensitive)) {
            v = QTime::fromString(v.toString());
        }

        // if(v.type() == QVariant::String) {
        //     if(v.toString().isEmpty()) {
        //         v = QVariant::Invalid;
        //     }
        // }b
        jo[fieldName] = QJsonValue::fromVariant(v);
    }

    return true;
}

bool DoubleDatabase::update(const QString &tableName, const QString &whereClause)
{
    QString sql = "update " + tableName + " set ";
    bool first = true;

    for(QMap<QString, QVariant>::const_iterator it = fBindValues.begin(); it != fBindValues.end(); it++) {
        if(first) {
            first = false;
        } else {
            sql += ",";
        }

        QString f = it.key();
        sql += f.remove(0, 1) + "=" + it.key();
    }

    if(!whereClause.isEmpty()) {
        sql += " " + whereClause;
    }

    return exec(sql);
}

int DoubleDatabase::insert(const QString &tableName, bool returnId)
{
    QString sql = "insert into " + tableName;
    QString k, v;
    bool first = true;

    for(QMap<QString, QVariant>::const_iterator it = fBindValues.begin(); it != fBindValues.end(); it++) {
        if(first) {
            first = false;
        } else {
            k += ",";
            v += ",";
        }

        k += QString(it.key()).remove(0, 1);
        v += it.key();
    }

    sql += QString("(%1) values (%2)").arg(k).arg(v);

    if(!exec(sql)) {
        return 0;
    }

    if(returnId) {
        exec("select last_insert_id()");
        return getValue(0, 0).toInt();
    } else {
        return 1;
    }
}

int DoubleDatabase::insert(const QString &tableName, const QJsonObject &rec, bool returnId)
{
    for(auto it = rec.constBegin(); it != rec.constEnd(); ++it) {
        const QString &key = it.key();          // ключ
        const QJsonValue &val = it.value();     // значение как QJsonValue
        QString str = val.toString();
        QVariant var = val.toVariant();
        fBindValues[":" + key ] = var;
    }

    return insert(tableName, returnId);
}

bool DoubleDatabase::insertId(const QString &tableName, const QVariant &id)
{
    fBindValues[":f_id"] = id;
    return insert(tableName, false) != 0;
}

QVariant DoubleDatabase::singleResult(const QString &sql)
{
    exec(sql);

    if(nextRow()) {
        return getValue(0);
    }

    return QVariant();
}

bool DoubleDatabase::deleteTableEntry(const QString &table, const QVariant &id)
{
    QString query = "delete from " + table + " where f_id=:f_id";
    fBindValues[":f_id"] = id;
    return exec(query);
}

void DoubleDatabase::getBindValues(QMap<QString, QVariant>& b)
{
    getBindValues(fCursorPos, b);
}

void DoubleDatabase::getBindValues(int row, QMap<QString, QVariant>& b)
{
    b.clear();

    for(QMap<QString, int>::const_iterator it = fNameColumnMap.begin(); it != fNameColumnMap.end(); it++) {
        b[":" + it.key()] = getValue(row, it.key());
    }
}

void DoubleDatabase::setValue(int row, int column, const QVariant &value)
{
    fDbRows[row][column] = value;
}

void DoubleDatabase::setValue(int row, const QString &columnName, const QVariant &value)
{
    setValue(row, fNameColumnMap[columnName], value);
}

void DoubleDatabase::setNoSqlErrorLogMode(bool v)
{
    fNoSqlErrorLog = v;
}

void DoubleDatabase::init()
{
    fNoSqlErrorLog = false;

    if(QSqlDatabase::drivers().count() == 0) {
        return;
    }

    QMutexLocker ml(&fMutex);
    ++fCounter;
    fDbName1 = getDbNumber("DB1");
    fDb1 = QSqlDatabase::addDatabase(_DBDRIVER_, fDbName1);
}

void DoubleDatabase::configureDatabase(QSqlDatabase &cn, const QString &host, const QString &db, const QString &user,
                                       const QString &password)
{
    cn.setHostName(host);
    cn.setDatabaseName(db);
    cn.setUserName(user);
    cn.setPassword(password);
    open();
}

void DoubleDatabase::logEvent(const QString &event)
{
#ifdef QT_DEBUG
    qDebug() << event;
#endif
    QDir d;

    if(!d.exists(d.homePath() + "/" + _APPLICATION_)) {
        d.mkpath(d.homePath() + "/" + _APPLICATION_);
    }

    QFile  f(d.homePath() + "/" + _APPLICATION_ + "/log.txt");
    QString dt = QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss") + " ";

    if(f.open(QIODevice::Append)) {
        f.write(dt.toUtf8());
        f.write(event.toUtf8());
        f.write("\r\n");
        f.close();
    }
}

QString DoubleDatabase::lastQuery(QSqlQuery *q)
{
    QString sql = q->lastQuery();
    const auto values = q->boundValues();
    const auto keys = q->boundValueNames();

    for (int i = 0; i < values.size(); ++i) {
        QVariant value = values[i];
        QString key = keys[i];
        QString replacement;

        switch (value.metaType().id()) {
        case QMetaType::QString:
            replacement = QString("'%1'").arg(value.toString().replace("'", "''"));
            break;

        case QMetaType::QDate:
            replacement = value.toDate().isValid()
                              ? QString("'%1'").arg(value.toDate().toString("yyyy-MM-dd"))
                              : "null";
            break;

        case QMetaType::QDateTime:
            replacement = value.toDateTime().isValid()
                              ? QString("'%1'").arg(
                                    value.toDateTime().toString("yyyy-MM-dd HH:mm:ss"))
                              : "null";
            break;

        case QMetaType::Double:
            replacement = QString::number(value.toDouble());
            break;

        case QMetaType::Int:
            replacement = QString::number(value.toInt());
            break;

        case QMetaType::QTime:
            replacement = value.toTime().isValid()
                              ? QString("'%1'").arg(value.toTime().toString("HH:mm:ss"))
                              : "null";
            break;

        default:
            replacement = value.toString();
            break;
        }

        sql.replace(QRegularExpression(key + "\\b"), replacement);
    }

    return sql;
}

bool DoubleDatabase::exec(QSqlQuery *q, const QString &sqlQuery, bool &isSelect)
{
    QElapsedTimer e;
    e.start();

    if(!q->prepare(sqlQuery)) {
        fLastError = q->lastError().databaseText();

        if(!fNoSqlErrorLog) {
            logEvent(fLastError);
            logEvent(sqlQuery);
        }

        return false;
    }

    for(QMap<QString, QVariant>::const_iterator it = fBindValues.constBegin(); it != fBindValues.constEnd(); it++) {
        q->bindValue(it.key(), it.value());
    }

    if(!q->exec()) {
        fLastError = q->lastError().databaseText();

        if(!fNoSqlErrorLog) {
            logEvent(fLastError);
            logEvent(lastQuery(q));
        }

        return false;
    }

    if(logEnabled) {
        logEvent("? [" + QString::number(e.elapsed()) + "] " + lastQuery(q));
    }

    isSelect = q->isSelect();

    if(!isSelect) {
        isSelect = sqlQuery.mid(0, 4).compare("call", Qt::CaseInsensitive) == 0;
    }

    if(!isSelect) {
        isSelect = sqlQuery.mid(0, 4).compare("drop", Qt::CaseInsensitive) == 0;
    }

    return true;
}
