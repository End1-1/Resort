#include "ecomboboxcompleter.h"
#include "doubledatabase.h"
#include "preferences.h"
#include <QCompleter>
#include <QCryptographicHash>

QString EComboBoxCompleter::fDefaultDatabaseName;
QMap<QString, QMap<QString, QString> > EComboBoxCompleter::fCache;

EComboBoxCompleter::EComboBoxCompleter(QWidget *parent) :
    QComboBox(parent)
{
    if (!fDefaultDatabaseName.isEmpty()) {
        fDatabaseName = fDefaultDatabaseName;
    }
    setMaxVisibleItems(50);
    QCompleter *c = completer();
    if (!c) {
        c = new QCompleter();
        setCompleter(c);
    }
    c->setCompletionMode(QCompleter::PopupCompletion);
    setEditable(true);
    connect(this, SIGNAL(currentTextChanged(QString)), this, SLOT(textChanged(QString)));
}

QVariant EComboBoxCompleter::currentData() const
{
    int i = currentIndex();
    return itemData(i);
}

QString EComboBoxCompleter::getSQL()
{
    return fSql;
}

void EComboBoxCompleter::setSQL(const QString &sql)
{
    fSql = sql;
    QString hash = QCryptographicHash::hash(QString(fSql + fDatabaseName).toLatin1(), QCryptographicHash::Md5).toHex();
    if (!fDatabaseName.isEmpty()) {
        if (fCache.contains(hash) && fCache[hash].count() > 0) {
            setData();
        } else {
            refreshData();
        }
    }
}

void EComboBoxCompleter::setDefaultDatabaseName(const QString &dbName)
{
    clearCache();
    fDefaultDatabaseName = dbName;
}

void EComboBoxCompleter::clearCache()
{
    fDefaultDatabaseName.clear();
    fCache.clear();
}

void EComboBoxCompleter::refreshData()
{
    QString hash = QCryptographicHash::hash(QString(fSql + fDatabaseName).toLatin1(), QCryptographicHash::Md5).toHex();
    if (!fCache.contains(hash)) {
        fCache[hash] = QMap<QString, QString>();
    }
    QMap<QString, QString> &map = fCache[hash];
    map.clear();
    Preferences p;
    Db d = p.getDatabase(fDatabaseName);
    DoubleDatabase db;
    db.setDatabase(d.dc_main_host, d.dc_main_path, d.dc_main_user, d.dc_main_pass);
    db.open();
    db.exec(fSql);
    while (db.nextRow()) {
        map[db.getString(1)] = db.getString(0);
    }
    db.close();
    setData();
}

void EComboBoxCompleter::setData()
{
    clear();
    QMap<QString, QString> &map = fCache[QCryptographicHash::hash(QString(fSql + fDatabaseName).toLatin1(),
                                         QCryptographicHash::Md5).toHex()];
    foreach (QString k, map.keys()) {
        addItem(k, map[k]);
    }
    setCurrentIndex(-1);
}

void EComboBoxCompleter::textChanged(const QString &text)
{
    setCurrentIndex(findText(text));
}
