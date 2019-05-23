#include "login.h"
#include "ui_login.h"
#include "loginsettings.h"
#include "databasesconnections.h"
#include "cacherights.h"
#include "cacheusersgroups.h"
#include "appconfig.h"
#include "cachecheckoutinvoice.h"
#include "ecomboboxcompleter.h"
#include <QProcess>
#include <windows.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QShortcut>
#include <QInputDialog>

Login::Login(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);    
    connect(ui->cbDatabase, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [](int index) {fPreferences.set(def_last_db_combo_index, index);});
    ui->leUsername->setText(__s.value("_last_login_user_name").toString());
    if (ui->leUsername->text().length() > 0) {
        ui->lePassword->setFocus();
    }
    fLockUser = 0;
    QShortcut *shortcut = new QShortcut(QKeySequence("F1"), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(shortcutSlot()));
    QFile f("./logo_login.png");
    if (f.exists()) {
        QPixmap p("./logo_login.png");
        ui->lbLogo->setPixmap(p);
    }
    if (__s.value("db_direct_connection").toBool()) {
        getDatabases();
    } else {
        connect(&fUdpSocket, SIGNAL(readyRead()), this, SLOT(readDatagram()));
        timeout();
        connect(&fTimer, SIGNAL(timeout()), this, SLOT(timeout()));
        fTimer.start(2000);
    }
}

Login::~Login()
{
    delete ui;
}

void Login::setLockUser(int id)
{
    fLockUser = id;
    ui->cbDatabase->setEnabled(false);
}

void Login::shortcutSlot()
{
    if (ui->cbDatabase->count() > 0) {
        return;
    }
    QString password = QInputDialog::getText(this, tr("First setup"), tr("MySQL server password"), QLineEdit::Password);
    if (password.isEmpty()) {
        return;
    }
    QJsonObject jObj;
    jObj["first_setup"] = password;
    jObj["client"] = HOSTNAME + "." + fPreferences.hostUsername();
    QJsonDocument jDoc(jObj);
    QByteArray datagram = jDoc.toJson();
    fUdpSocket.writeDatagram(datagram, QHostAddress::Broadcast, DATAGRAM_PORT);
}

void Login::readDatagram()
{
    fTimer.stop();
    while (fUdpSocket.hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(fUdpSocket.pendingDatagramSize());
        fUdpSocket.readDatagram(datagram.data(), datagram.size());
        QJsonDocument jDoc = QJsonDocument::fromJson(datagram);
        QJsonObject jObj = jDoc.object();
        if (jObj.contains("server")) {
            QString rep = jObj.value("server").toString();
            if (rep == "me") {
                DoubleDatabase db(jObj.value("host").toString(),
                                       jObj.value("database").toString(),
                                       jObj.value("username").toString(),
                                       jObj.value("password").toString());
                if (!db.open(true, false)) {
                    message_error(tr("Cannot connect to main database")
                                  + "<br>"
                                  + db.fLastError
                                  + "<br>Server: "
                                  + jObj.value("host").toString()
                                  + ":" + jObj.value("database").toString());
                    return;
                }

                DoubleDatabase::logEvent(QString("use direct: ") + (__s.value("db_direct_connection").toBool() ? "true" : "false"));
                if (!__s.value("db_direct_connection").toBool()) {
                    AppConfig::fServerAddress =  jObj.value("host").toString();
                    AppConfig::fServerPort = jObj.value("port").toInt();
                    BaseUIDX::fAirHost = jObj.value("host").toString();
                    BaseUIDX::fAirDbName = jObj.value("database").toString();
                    BaseUIDX::fAirUser = jObj.value("username").toString();
                    BaseUIDX::fAirPass = jObj.value("password").toString();
                    DoubleDatabase::logEvent("Base::fAirHost" + BaseUIDX::fAirHost);

                }
//                TrackControl::fDbHost = jObj["loghost"].toString();
//                TrackControl::fDbDb = jObj["logdb"].toString();
//                TrackControl::fDbUser = jObj["loguser"].toString();
//                TrackControl::fDbPass = jObj["logpass"].toString();
//                TrackControl::setFirstConnection();
                _IDGENMODE_ = jObj["idgen"].toInt();
                db[":f_user"] = HOSTNAME + "." + fPreferences.hostUsername();
                db.exec("select * from f_db where f_id in (select f_db from f_access where lower(f_user)=lower(:f_user) and f_right=1)");
                for (int i = 0; i < db.rowCount(); i++) {
                    QMap<QString, QString> conn;
                    conn["f_host"] = db.getString(i, "f_host");
                    conn["f_database"] = db.getString(i, "f_database");
                    conn["f_username"] = db.getString(i, "f_username");
                    conn["f_password"] = db.getString(i, "f_password");
                    fDatabaseList[db.getString(i, "f_name")] = conn;
                }
                getDatabases();
                return;
            }
        } else if (jObj.contains("first_setup")) {
            QString reply = jObj["first_setup"].toString();
            if (reply != "ok") {
                message_error(tr("First setup failed"));
                return;
            }
            timeout();
        }
    }
    fTimer.start(2000);
}

void Login::on_btnCancel_clicked()
{
    reject();
}

void Login::on_btnAddDatabase_clicked()
{
    if (fPreferences.getString(def_preferences_password).length() > 0) {
        LoginSettings ls(this);
        if (ls.exec() != QDialog::Accepted) {
            return;
        }
    }
    DatabasesConnections dc(this);
    dc.exec();
}

void Login::getDatabases()
{
    ui->cbDatabase->clear();
    if (!__s.value("db_direct_connection").toBool()) {
        QStringList dbNames = fDatabaseList.keys();
        fPreferences.clearDatabase();
        foreach (QString s, dbNames) {
            fPreferences.appendDatabase(s,
                    fDatabaseList[s]["f_host"],
                    fDatabaseList[s]["f_database"],
                    fDatabaseList[s]["f_username"],
                    fDatabaseList[s]["f_password"],
                    "", "", "", "");
            }
            ui->cbDatabase->addItems(dbNames);
    } else {
        QStringList dbNames;
        fPreferences.setDatabasesNames(dbNames);
        for (QStringList::const_iterator it = dbNames.begin(); it != dbNames.end(); it++) {
            Db db = fPreferences.getDatabase(*it);
            fPreferences.appendDatabase(db.dc_name,
                    db.dc_main_host,
                    db.dc_main_path,
                    db.dc_main_user,
                    db.dc_main_pass,
                    "", "", "", "");
            ui->cbDatabase->addItem(db.dc_name);
            AppConfig::fServerAddress = db.dc_main_host;
            AppConfig::fServerPort = SERVER_DEFAULT_PORT;
            DoubleDatabase::logEvent("O, shit!");
        }
    }
    ui->cbDatabase->setCurrentIndex(ui->cbDatabase->findText(__s.value("_last_login_db_name").toString()));
    on_leUsername_textChanged(ui->leUsername->text());
    ui->lbF1->setVisible(ui->cbDatabase->count() == 0);
}

void Login::on_btnLogin_clicked()
{
    QString connName = ui->cbDatabase->currentText();
    Db conn = fPreferences.getDatabase(connName);
    DoubleDatabase fDD;
    fDD.setDatabase(conn.dc_main_host, conn.dc_main_path, conn.dc_main_user, conn.dc_main_pass, 1);
    if (!fDD.open(true, false)) {
        message_error(fDD.fLastError);
        return;
    }

    fDD.exec("select current_timestamp");
    fDD.nextRow();
    if (QDateTime::currentDateTime() < fDD.getValue(0).toDateTime().addSecs(-300)) {
        message_error(tr("Server time and workstation time note same, aborting."));
        return;
    }

    fDD[":username"] = ui->leUsername->text();
    fDD[":password"] = ui->lePassword->text();
    fDD.exec("select f_id, f_firstName, f_lastName, f_group, concat(f_firstName, ' ', f_lastName) as f_fullName from users where length(f_username)>0 and f_username=:username and f_password=md5(:password)");
    if (!fDD.nextRow()) {
        message_error(tr("Access denied"));
        return;
    }
    if (fLockUser > 0) {
        if (fDD.getInt(0) != fLockUser) {
            message_error(tr("You cannot unlock this station"));
            return;
        }
    }
    __s.setValue("_last_login_user_name", ui->leUsername->text());
    __s.setValue("_last_login_db_name", ui->cbDatabase->currentText());
    fDbName = connName;

    EComboBoxCompleter::setDefaultDatabaseName(connName);
    fPreferences.initFromDb(connName, "", fDD.getInt(0));
    fPreferences.setLocal(def_working_conn_name, connName);
    fPreferences.setLocal(def_working_user_id, fDD.getInt(0));
    fPreferences.setLocal(def_working_username, fDD.getString("f_fullName"));
    fPreferences.setLocal(def_working_user_group, fDD.getInt(3));
    //setup new double database connection
    Db d = fPreferences.getDatabase(connName);
    __dd1Host = d.dc_main_host;
    __dd1Database = d.dc_main_path;
    __dd1Username = d.dc_main_user;
    __dd1Password = d.dc_main_pass;
    if (__s.value("db_direct_connection").toBool()) {
        TrackControl::fDbHost = __dd1Host;
        TrackControl::fDbDb = __dd1Database;
        TrackControl::fDbUser = __dd1Username;
        TrackControl::fDbPass = __dd1Password;
        TrackControl::setFirstConnection();
        BaseUIDX::fAirHost = __dd1Host;
        BaseUIDX::fAirDbName = "airwick";
        BaseUIDX::fAirUser = __dd1Username;
        BaseUIDX::fAirPass = __dd1Password;
    }

    bool secondDb = true;
    //!r__(cr__do_no_write_second_db);
    QStringList dbParams = fPreferences.getDb("dd").toString().split(";", QString::SkipEmptyParts);
    if (dbParams.count() == 4) {
        __dd2Host = dbParams[0];
        __dd2Database = dbParams[1];
        __dd2Username = dbParams[2];
        __dd2Password = dbParams[3];
        fDD.setDatabase(__dd2Host, __dd2Database, __dd2Username, __dd2Password, 2);
        doubleDatabase = secondDb && true;
    }  else {
        doubleDatabase = false;
    }
    QStringList log = fPreferences.getDb(def_log_main_db).toString().split(";", QString::SkipEmptyParts);
    if (log.count() == 4) {
        TrackControl::fDbHost = log.at(0);
        TrackControl::fDbDb = log.at(1);
        TrackControl::fDbUser = log.at(2);
        TrackControl::fDbPass = log.at(3);
    }
    log = fPreferences.getDb(def_log_reserve_db).toString().split(";", QString::SkipEmptyParts);
    if (log.count() == 4) {
        TrackControl::fDbHostReserve = log.at(0);
        TrackControl::fDbDbReserve = log.at(1);
        TrackControl::fDbUserReserve = log.at(2);
        TrackControl::fDbPassReserve = log.at(3);
    }
    TrackControl::setFirstConnection();

    fDD.close();
    fDD.resetDoNotUse();
    fDD.open(true, doubleDatabase);

    // setup tax parameters
    fDD[":f_comp"] = QHostInfo::localHostName();
    fDD.exec("select f_address, f_port, f_password, f_adg from s_tax_print where f_comp=:f_comp");
    if (fDD.nextRow()) {
        fPreferences.setDb(def_tax_address, fDD.getString(0));
        fPreferences.setDb(def_tax_port, fDD.getString(1));
        fPreferences.setDb(def_tax_password, fDD.getString(2));
        fPreferences.setDb(def_tax_adg, fDD.getString(3));
    }

    /* rate for usd */
    fDD[":f_id"] = 2;
    fDD.exec("select f_rate from f_acc_currencies where f_id=:f_id");
    if (fDD.nextRow()) {
        def_usd = fDD.getDouble(0);
    }

    fDD[":f_comp"] = def_station + QHostInfo::localHostName();
    fDD.exec("select f_active, f_host, f_port, f_password from serv_tax where upper(f_comp)=upper(:f_comp)");
    if (fDD.nextRow()) {
        if (fDD.getInt("f_active") > 0) {
            __TAX_HOST = fDD.getString("f_host");
            __TAX_PORT = fDD.getString("f_port");
            __TAX_PASS = fDD.getString("f_pass");
        }
    } else {
        fDD[":f_active"] = 0;
        fDD[":f_comp"] = def_station + QHostInfo::localHostName();
        fDD.insert("serv_tax", false);
    }   

    BaseUIDX::fUserId = WORKING_USERID;
    EDateEditFirstDate = WORKING_DATE;
    CacheRights::fGroup = WORKING_USERGROUP;
    CacheUsersGroups ug;
    if (ug.get(WORKING_USERGROUP)) {
        EDateEditMinDate = ug.fMinDate();
        CheckoutMinDate = ug.fMinDate();
    }

    accept();
}

void Login::on_leUsername_textChanged(const QString &arg1)
{
    QString connName = ui->cbDatabase->currentText();
    Db conn = fPreferences.getDatabase(connName);
    DoubleDatabase db(conn.dc_main_host, conn.dc_main_path, conn.dc_main_user, conn.dc_main_pass);
    if (!db.open(true, false)) {
        return;
    }
    db[":username"] = arg1;
    db.exec("select f_id, f_firstName, f_lastName, f_group from users where length(f_username)>0 and f_username=:username ");
    if (db.rowCount() > 0) {
        ui->lbFullName->setText(QString("%1 %2")
                                .arg(db.getString(0, "f_firstName"))
                                .arg(db.getString(0, "f_lastName")));
    } else {
        ui->lbFullName->clear();
    }
    db.close();
}

void Login::timeout()
{
    if (__s.value("db_direct_connection").toBool()) {
        getDatabases();
    } else {
        QJsonObject jObj;
        jObj["server"] = "who";
        jObj["client"] = HOSTNAME + "." + fPreferences.hostUsername();
        QJsonDocument jDoc(jObj);
        QByteArray datagram = jDoc.toJson();
        fUdpSocket.writeDatagram(datagram, QHostAddress::Broadcast, DATAGRAM_PORT);
    }
}
