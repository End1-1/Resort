#include "preferences.h"
#include "doubledatabase.h"
#include <QDir>
#include <QFile>
#include <QHostInfo>
#include <QDebug>
#include <QApplication>

#ifdef WIN32
    #include <windows.h>
#endif

QString __TAX_HOST;
QString __TAX_PORT;
QString __TAX_PASS;

Preferences __preferences;

typedef struct {
    quint32 version;
    quint32 last_db_combo_index;
    char last_username[32];
    char password[32];
    char reserved[4096];
} PreferencesDefault;

QMap<QString, QVariant> Preferences::fConfigPreferences;
QMap<QString, QVariant> Preferences::fDbPreferences;
QMap<QString, QVariant> Preferences::fLocalPreferences;
QMap<QString, Db> Preferences::fDatabases;
QMap<QString, QString> Preferences::fUserPreferences;
QWidget *fParentForMessage = 0;

Preferences::Preferences()
{
}

void Preferences::saveConfig()
{
    QFile file(getString(def_preferences_file));
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }
    PreferencesDefault pd;
    memset( &pd, 0, sizeof(pd));
    pd.last_db_combo_index = fConfigPreferences[def_last_db_combo_index].toInt();
    qstringToChar( &pd.last_username[0], fConfigPreferences[def_last_username].toString());
    qstringToChar( &pd.password[0], fConfigPreferences[def_preferences_password].toString());
    file.write(reinterpret_cast<const char *>( &pd), sizeof(pd));
    for (QMap<QString, Db>::const_iterator it = fDatabases.begin(); it != fDatabases.end(); it++) {
        Db db = getDatabase(it.key());
        file.write(reinterpret_cast<const char *>( &db), sizeof(Db));
    }
    file.close();
}

QString Preferences::getString(const QString &name)
{
    return fConfigPreferences[name].toString();
}

QString Preferences::getLocalString(const QString &name)
{
    return fDbPreferences[name].toString();
}

QDate Preferences::getLocalDate(const QString &name)
{
    QString dateStr = fDbPreferences[name].toString();
    return QDate::fromString(dateStr, def_date_format);
}

void Preferences::setLocalDate(const QString &name, const QDate &date)
{
    QString dateStr = date.toString(def_date_format);
    fDbPreferences[name] = dateStr;
}

int Preferences::getLocalInt(const QString &name)
{
    return fDbPreferences[name].toInt();
}

quint32 Preferences::getInt(const QString &name)
{
    return fConfigPreferences[name].toInt();
}

void Preferences::setDb(const QString &name, const QVariant &value)
{
    fDbPreferences[name] = value;
}

QVariant Preferences::getDb(const QString &name)
{
    if (fDbPreferences.contains(name)) {
        return fDbPreferences[name];
    }
    return QVariant();
}

void Preferences::set(const QString &name, const QVariant &value)
{
    fConfigPreferences[name] = value;
}

void Preferences::setLocal(const QString &name, const QVariant &value)
{
    fLocalPreferences[name] = value;
}

QVariant Preferences::getLocal(const QString &name)
{
    return fLocalPreferences[name];
}

QWidget *Preferences::getDefaultParentForMessage()
{
    return fParentForMessage;
}

void Preferences::setDefaultParentForMessage(QWidget *parent)
{
    fParentForMessage = parent;
}

void Preferences::clearDatabase()
{
    fDatabases.clear();
}

void Preferences::appendDatabase(const QString &name, const QString &mainHost, const QString &mainDb,
                                 const QString &mainUser, const QString &mainPassword,
                                 const QString &logHost, const QString &logDb, const QString &logUser, const QString &logPassword,
                                 const QString &broadcast)
{
    Db db;
    memset( &db, 0, sizeof(db));
    qstringToChar( &db.dc_name[0], name);
    qstringToChar( &db.dc_main_host[0], mainHost);
    qstringToChar( &db.dc_main_path[0], mainDb);
    qstringToChar( &db.dc_main_user[0], mainUser);
    qstringToChar( &db.dc_main_pass[0], mainPassword);
    qstringToChar( &db.dc_log_host[0], logHost);
    qstringToChar( &db.dc_log_path[0], logDb);
    qstringToChar( &db.dc_log_user[0], logUser);
    qstringToChar( &db.dc_log_pass[0], logPassword);
    qstringToChar( &db.dc_broadcast[0], broadcast);
    fDatabases[name] = db;
}

void Preferences::setDatabasesNames(QStringList &names)
{
    names = fDatabases.keys();
}

Db Preferences::getDatabase(const QString &name)
{
    if (!fDatabases.contains(name)) {
        return Db();
    }
    return fDatabases[name];
}

Db Preferences::getFirstDatabase()
{
    if (fDatabases.count() == 0) {
        return Db();
    }
    foreach (Db db, fDatabases) {
        return db;
    }
    return Db();
}

void Preferences::removeDatabase(const QString &name)
{
    fDatabases.remove(name);
}

void Preferences::initFromDb(const QString &dbName, const QString &additionalSettings, int userId)
{
    Db &dbConf = fDatabases[dbName];
    DoubleDatabase db(dbConf.dc_main_host, dbConf.dc_main_path, dbConf.dc_main_user, dbConf.dc_main_pass);
    db.open();
    db.exec("select f_key, f_value from f_global_settings where f_settings = 1 order by f_key");
    fDbPreferences.clear();
    while (db.nextRow()) {
        fDbPreferences[db.getString(0)] = db.getValue(1);
    }
    if (additionalSettings.length() > 0) {
        db.exec("select gs.f_key,  gs.f_value from f_global_settings gs "
                "inner join f_global_settings_names gn on gn.f_id=gs.f_settings "
                "where gn.f_name='" + additionalSettings + "'");
        while (db.nextRow()) {
            fDbPreferences[db.getString(0)] = db.getValue(1);
        }
    }
    db[":f_user"] = userId;
    db.exec("select f_key, f_value from f_users_settings where f_user=:f_user");
    while (db.nextRow()) {
        fUserPreferences[db.getString(0)] = db.getString(1);
    }
    db[":f_comp"] = QHostInfo::localHostName();
    db.exec("select f_comp from s_tax_print where upper(f_comp)=upper(:f_comp)");
    if (!db.nextRow()) {
        db[":f_comp"] = QHostInfo::localHostName().toUpper();
        db.insert("s_tax_print", false);
    }
    db.exec("select max(f_date) from f_eod");
    if (db.nextRow()) {
        fDbPreferences["eod"] = db.getDateTime(0).toString(def_date_time_format);
    } else {
        fDbPreferences["eod"] = "--";
    }
    db.close();
    def_date = getLocalDate(def_working_day);
}

void Preferences::initFromConfig()
{
    if (fConfigPreferences.count() == 0) {
        QDir dir;
        QString s = QString("%1/%2").arg(dir.homePath()).arg("HotelResort");
        fConfigPreferences[def_home_path] = s;
        if (!dir.exists(s))
            dir.mkpath(s);
        s = QString("%1/%2").arg(s).arg("preferences.dat");
        fConfigPreferences[def_preferences_file] = s;
        QFile file(s);
        PreferencesDefault pd;
        memset( &pd, 0, sizeof(pd));
        if (!file.exists() || file.size() == 0) {
            file.open(QIODevice::WriteOnly);
            file.write(reinterpret_cast<const char *>( &pd), sizeof(pd));
        } else {
            file.open(QIODevice::ReadOnly);
            file.read(reinterpret_cast<char *>( &pd), sizeof(pd));
            fConfigPreferences[def_last_db_combo_index] = pd.last_db_combo_index;
            fConfigPreferences[def_last_username] = QString(pd.last_username);
            fConfigPreferences[def_preferences_password] = QString(pd.password);
            while (file.pos() < file.size()) {
                Db db;
                file.read(reinterpret_cast<char *>( &db), sizeof(db));
                fDatabases[db.dc_name] = db;
            }
        }
        file.close();
    }
}

void Preferences::qstringToChar(char *dst, const QString &src)
{
    memcpy(dst, src.toUtf8().data(), src.toUtf8().length());
}

QString Preferences::getUser(const QString &key)
{
    return fUserPreferences[key];
}

void Preferences::setUser(const QString &connName, const QString &key, const QString &value)
{
    fUserPreferences[key] = value;
    Db &dbConf = fDatabases[connName];
    DoubleDatabase db(dbConf.dc_main_host, dbConf.dc_main_path, dbConf.dc_main_user, dbConf.dc_main_pass);
    db.open();
    db[":f_user"] = getLocal(def_working_user_id);
    db[":f_key"] = key;
    db.exec("delete from f_users_settings where f_user=:f_user and f_key=:f_key");
    db[":f_user"] = getLocal(def_working_user_id);
    db[":f_key"] = key;
    db[":f_value"] = value;
    db.insert("f_users_settings", false);
    db.close();
}

QString Preferences::hostUsername()
{
    QString name = qgetenv("USER");
    if (name.isEmpty())
        name = qgetenv("USERNAME");
    return name;
}
