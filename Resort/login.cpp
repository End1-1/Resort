#include "login.h"
#include <QFile>
#include <QInputDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QProcess>
#include <QRandomGenerator>
#include <QShortcut>
#include "appconfig.h"
#include "appwebsocket.h"
#include "cachecheckoutinvoice.h"
#include "cacherights.h"
#include "cacheusersgroups.h"
#include "databasesconnections.h"
#include "ecomboboxcompleter.h"
#include "loginsettings.h"
#include "ui_login.h"
#include <windows.h>

Login::Login(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->cbDatabase, static_cast<void (QComboBox::*)(int)>( &QComboBox::currentIndexChanged), [](int index) {
        fPreferences.set(def_last_db_combo_index, index);
    });
    ui->leUsername->setText(__s.value("_last_login_user_name").toString());
    if (ui->leUsername->text().length() > 0) {
        ui->lePassword->setFocus();
    }
    fLockUser = 0;
    QFile f("./logo_login.png");
    if (f.exists()) {
        QPixmap p("./logo_login.png");
        ui->lbLogo->setPixmap(p);
    }
    getDatabases();
    ui->wPin->setVisible(fPreferences.getDb(def_touchscreen).toBool());
    ui->wUsernamePassword->setVisible(!fPreferences.getDb(def_touchscreen).toBool());
    adjustSize();
    connect(AppWebSocket::instance, &AppWebSocket::socketConnected, this, &Login::socketConnected);
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
    QStringList dbNames;
    fPreferences.setDatabasesNames(dbNames);
    for (QStringList::const_iterator it = dbNames.constBegin(); it != dbNames.constEnd(); it++) {
        Db db = fPreferences.getDatabase( *it);
        fPreferences.appendDatabase(db.dc_name,
                                    db.dc_main_host,
                                    db.dc_main_path,
                                    db.dc_main_user,
                                    db.dc_main_pass,
                                    "", "", "", "", db.dc_broadcast);
        ui->cbDatabase->addItem(db.dc_name);
        AppConfig::fServerAddress = __s.value("db_broadcast_server").toString();
        AppConfig::fServerPort = SERVER_DEFAULT_PORT;
    }
    ui->cbDatabase->setCurrentIndex(ui->cbDatabase->findText(__s.value("_last_login_db_name").toString()));
    on_leUsername_textChanged(ui->leUsername->text());
}

void Login::on_btnLogin_clicked()
{
    QString connName = ui->cbDatabase->currentText();
    Db conn = fPreferences.getDatabase(connName);
    DoubleDatabase fDD(conn.dc_main_host, conn.dc_main_path, conn.dc_main_user, conn.dc_main_pass);
    if (!fDD.open()) {
        message_error(fDD.fLastError);
        return;
    }
    fDD.exec("SELECT UTC_TIMESTAMP()");
    fDD.nextRow();

    // Получаем QDateTime и явно говорим, что это UTC
    QDateTime serverTimeUtc = fDD.getValue(0).toDateTime();
    serverTimeUtc.setTimeSpec(Qt::UTC);

    // Сравниваем с текущим временем системы в формате UTC
    int diff = std::abs(QDateTime::currentDateTimeUtc().secsTo(serverTimeUtc));

    if (diff > 300) {
        message_error(
            tr("Server time and workstation time not the same, aborting. Diff: %1").arg(diff));
        return;
    }
    fDD[":username"] = ui->leUsername->text();
    fDD[":password"] = ui->lePassword->text();
    fDD.exec("select f_id, f_firstName, f_lastName, f_group, "
             "concat(f_firstName, ' ', f_lastName) as f_fullName "
             "from users "
             "where length(f_username)>0 and f_username=:username and f_password=md5(:password) "
             "and f_state=1 ");
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
    QStringList log = fPreferences.getDb(def_log_main_db).toString().split(";", Qt::SkipEmptyParts);
    if (log.count() == 4) {
        TrackControl::fDbHost = log.at(0);
        TrackControl::fDbDb = log.at(1);
        TrackControl::fDbUser = log.at(2);
        TrackControl::fDbPass = log.at(3);
    }
    log = fPreferences.getDb(def_log_reserve_db).toString().split(";", Qt::SkipEmptyParts);
    if (log.count() == 4) {
        TrackControl::fDbHostReserve = log.at(0);
        TrackControl::fDbDbReserve = log.at(1);
        TrackControl::fDbUserReserve = log.at(2);
        TrackControl::fDbPassReserve = log.at(3);
    }
    TrackControl::setFirstConnection();
    fDD.close();
    fDD.open();
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
    CacheBaseStruct::fWorkingDate = WORKING_DATE;
    BaseUIDX::fUserId = WORKING_USERID;
    EDateEditFirstDate = WORKING_DATE;
    auto *gen = QRandomGenerator::global();
    WORKING_SESSION_ID = gen->bounded(1, 999999999);
    CacheRights::fGroup = WORKING_USERGROUP;
    CacheUsersGroups ug;
    if (ug.get(WORKING_USERGROUP)) {
        EDateEditMinDate = ug.fMinDate();
        CheckoutMinDate = ug.fMinDate();
    }
    fDD[":f_user"] = WORKING_USERID;
    fDD.exec("select f_id, f_start from s_user_session where f_user=:f_user and f_end<'2000-01-01'");
    QString message;
    if (fDD.nextRow()) {
        message = QString("%1, %2<br>%3 %4<br>%5 %6")
                  .arg(tr("Welcome"))
                  .arg(WORKING_USERNAME)
                  .arg(tr("Your session number is"))
                  .arg(fDD.getInt(0))
                  .arg(tr("started at"))
                  .arg(fDD.getDateTime(1).toString(def_date_time_format));
    } else {
        fDD[":f_user"] = WORKING_USERID;
        fDD[":f_start"] = QDateTime::currentDateTime();
        message = QString("%1, %2<br>%3 %4 %5")
                  .arg(tr("Welcome"))
                  .arg(WORKING_USERNAME)
                  .arg(tr("Your session number is"))
                  .arg(WORKING_SESSION_ID)
                  .arg(tr("started at right now"));
    }
    if (!fPreferences.getDb(def_user_auto_session).toBool()) {
        message_info(message);
    }
    fDD.exec("select max(f_id) from serv_years");
    int max_year = 0;
    if (fDD.nextRow()) {
        max_year = fDD.getInt(0);
    }
    int curr_year = QDate::currentDate().year();
    if (curr_year > max_year) {
        while (max_year < curr_year) {
            if (max_year == 0) {
                max_year = curr_year;
            } else {
                max_year++;
            }
            fDD[":f_id"] = max_year;
            fDD[":f_name"] = QString::number(max_year);
            fDD.insert("serv_years");
        }
    }
    AppWebSocket::instance->setServerAddress(conn.dc_broadcast, conn.dc_main_host);
}

void Login::on_leUsername_textChanged(const QString &arg1)
{
    QString connName = ui->cbDatabase->currentText();
    if (connName.isEmpty()) {
        return;
    }
    Db conn = fPreferences.getDatabase(connName);
    DoubleDatabase db(conn.dc_main_host, conn.dc_main_path, conn.dc_main_user, conn.dc_main_pass);
    if (!db.open()) {
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

void Login::on_btnCancel2_clicked()
{
    reject();
}

void Login::on_btnLoginPin_clicked()
{
    QString connName = ui->cbDatabase->currentText();
    Db conn = fPreferences.getDatabase(connName);
    DoubleDatabase fDD;
    fDD.setDatabase(conn.dc_main_host, conn.dc_main_path, conn.dc_main_user, conn.dc_main_pass);
    if (!fDD.open()) {
        message_error(fDD.fLastError);
        return;
    }
    fDD.exec("select current_timestamp");
    fDD.nextRow();
    if (QDateTime::currentDateTime() < fDD.getValue(0).toDateTime().addSecs(-300)) {
        message_error(tr("Server time and workstation time note same, aborting."));
        return;
    }
    fDD[":password"] = ui->lePin->text();
    fDD.exec("select f_id, f_firstName, f_lastName, f_group, concat(f_firstName, ' ', f_lastName) as f_fullName from users where f_altpassword=md5(:password)");
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
    QStringList log = fPreferences.getDb(def_log_main_db).toString().split(";", Qt::SkipEmptyParts);
    if (log.count() == 4) {
        TrackControl::fDbHost = log.at(0);
        TrackControl::fDbDb = log.at(1);
        TrackControl::fDbUser = log.at(2);
        TrackControl::fDbPass = log.at(3);
    }
    log = fPreferences.getDb(def_log_reserve_db).toString().split(";", Qt::SkipEmptyParts);
    if (log.count() == 4) {
        TrackControl::fDbHostReserve = log.at(0);
        TrackControl::fDbDbReserve = log.at(1);
        TrackControl::fDbUserReserve = log.at(2);
        TrackControl::fDbPassReserve = log.at(3);
    }
    TrackControl::setFirstConnection();
    fDD.close();
    fDD.open();
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
    CacheBaseStruct::fWorkingDate = WORKING_DATE;
    BaseUIDX::fUserId = WORKING_USERID;
    EDateEditFirstDate = WORKING_DATE;
    CacheRights::fGroup = WORKING_USERGROUP;
    CacheUsersGroups ug;
    if (ug.get(WORKING_USERGROUP)) {
        EDateEditMinDate = ug.fMinDate();
        CheckoutMinDate = ug.fMinDate();
    }
    fDD[":f_user"] = WORKING_USERID;
    fDD.exec("select f_id, f_start from s_user_session where f_user=:f_user and f_end<'2000-01-01'");
    QString message;
    auto *gen = QRandomGenerator::global();
    WORKING_SESSION_ID = gen->bounded(1, 999999999);
    if (fDD.nextRow()) {
        message = QString("%1, %2<br>%3 %4<br>%5 %6")
                  .arg(tr("Welcome"))
                  .arg(WORKING_USERNAME)
                  .arg(tr("Your session number is"))
                  .arg(WORKING_SESSION_ID)
                  .arg(tr("started at"))
                  .arg(fDD.getDateTime(1).toString(def_date_time_format));
    } else {
        fDD[":f_user"] = WORKING_USERID;
        fDD[":f_start"] = QDateTime::currentDateTime();
        message = QString("%1, %2<br>%3 %4 %5")
                  .arg(tr("Welcome"))
                  .arg(WORKING_USERNAME)
                  .arg(tr("Your session number is"))
                  .arg(WORKING_SESSION_ID)
                  .arg(tr("started at right now"));
    }
    if (!fPreferences.getDb(def_user_auto_session).toBool()) {
        message_info(message);
    }
    fDD.exec("select max(f_id) from serv_years");
    int max_year = 0;
    if (fDD.nextRow()) {
        max_year = fDD.getInt(0);
    }
    int curr_year = QDate::currentDate().year();
    if (curr_year > max_year) {
        while (max_year < curr_year) {
            if (max_year == 0) {
                max_year = curr_year;
            } else {
                max_year++;
            }
            fDD[":f_id"] = max_year;
            fDD[":f_name"] = QString::number(max_year);
            fDD.insert("serv_years");
        }
    }
    accept();
}

void Login::on_btn1_clicked()
{
    ui->lePin->setText(ui->lePin->text() + static_cast<QPushButton *>(sender())->text());
}

void Login::on_btn2_clicked()
{
    ui->lePin->setText(ui->lePin->text() + static_cast<QPushButton *>(sender())->text());
}

void Login::on_btn3_clicked()
{
    ui->lePin->setText(ui->lePin->text() + static_cast<QPushButton *>(sender())->text());
}

void Login::on_btn4_clicked()
{
    ui->lePin->setText(ui->lePin->text() + static_cast<QPushButton *>(sender())->text());
}

void Login::on_btn5_clicked()
{
    ui->lePin->setText(ui->lePin->text() + static_cast<QPushButton *>(sender())->text());
}

void Login::on_btn6_clicked()
{
    ui->lePin->setText(ui->lePin->text() + static_cast<QPushButton *>(sender())->text());
}

void Login::on_btn7_clicked()
{
    ui->lePin->setText(ui->lePin->text() + static_cast<QPushButton *>(sender())->text());
}

void Login::on_btn8_clicked()
{
    ui->lePin->setText(ui->lePin->text() + static_cast<QPushButton *>(sender())->text());
}

void Login::on_btn9_clicked()
{
    ui->lePin->setText(ui->lePin->text() + static_cast<QPushButton *>(sender())->text());
}

void Login::on_btn0_clicked()
{
    ui->lePin->setText(ui->lePin->text() + static_cast<QPushButton *>(sender())->text());
}

void Login::on_btnClearPin_clicked()
{
    ui->lePin->clear();
}

void Login::socketConnected()
{
    QJsonObject jo;
    jo["command"] = "register_socket";
    jo["socket_type"] = 1;
    jo["database"] = __dd1Database;
    jo["userid"] = WORKING_USERID;
    AppWebSocket::instance->sendMessage(QJsonDocument(jo).toJson(QJsonDocument::Compact));
    accept();
}
