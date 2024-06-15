#include "dlgmain.h"
#include "ui_dlgmain.h"
#include "defines.h"
#include "qtcppushbutton.h"
#include "traveline.h"
#include "logging.h"
#include "travellineconfig.h"
#include "doubledatabase.h"
#include "broadcastthread.h"
#include "appconfig.h"
#include "baseuid.h"
#include "cachereservation.h"
#include <QCloseEvent>
#include <QHostAddress>
#include <QTcpSocket>
#include <QDateTime>
#include <QInputDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonValue>
#include <QMessageBox>
#include <QSettings>
#include <QUuid>
#include <QNetworkProxy>
#include <QTimer>
#include <QMutex>

static QMutex mutex;

DlgMain::DlgMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgMain)
{
    ui->setupUi(this);

    QSettings s("SmartHotel", "SmartHotel");
    ui->leServerPort->setText(s.value("server_port").toString());
    ui->leHost->setText(s.value("host").toString());
    ui->leDatabase->setText(s.value("database").toString());
    ui->leUsername->setText(s.value("username").toString());
    ui->lePassword->setText(s.value("password").toString());

    BaseUIDX::fAirHost = s.value("host").toString();
    BaseUIDX::fAirDbName = s.value("database").toString();
    BaseUIDX::fAirUser = s.value("username").toString();
    BaseUIDX::fAirPass = s.value("password").toString();

    AppConfig::fServerAddress = s.value("host").toString();

    ui->leLogHost->setText(s.value("loghost").toString());
    ui->leLogDb->setText(s.value("logdb").toString());
    ui->leLogUsername->setText(s.value("logusername").toString());
    ui->leLogPassword->setText(s.value("logpassword").toString());

    ui->rgGenRangom->setChecked(s.value("idgen").toBool());

    fTrayMenu.addAction(tr("Quit"), this, SLOT(appTerminate()));
    fCanClose = false;
    fTrayIcon.setIcon(QIcon(":/app.png"));
    fTrayIcon.show();
    fTrayIcon.setContextMenu(&fTrayMenu);
    connect(&fTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconClicked(QSystemTrayIcon::ActivationReason)));
    fTcpServer.setProxy(QNetworkProxy::NoProxy);
    if (!fTcpServer.listen(QHostAddress::Any, ui->leServerPort->text().toInt())) {
        logActivity("Cannot listen.");
    }
    connect(&fTcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if (!fUdpSocket.bind(DATAGRAM_PORT, QUdpSocket::ShareAddress)) {
        logActivity("Cannot bind udp server.");
    }
    fTcpServer.connect(&fUdpSocket, SIGNAL(readyRead()), this, SLOT(datagramRead()));

    ui->tblConn->setColumnWidth(0, 50);
    ui->tblConn->setColumnWidth(1, 150);
    ui->tblConn->setColumnWidth(2, 120);
    ui->tblConn->setColumnWidth(3, 120);
    ui->tblConn->setColumnWidth(7, 40);
    ui->tblConn->setColumnWidth(10, 0);

    auto *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DlgMain::timeout);

#ifdef QT_DEBUG
    timer->start(30000);
#else
    timer->start(5 * 60000);
#endif

    ui->wSettings->setVisible(false);
    ui->leTravelineDB->setText(s.value("travellinedb").toString());
}

DlgMain::~DlgMain()
{
    qDeleteAll(fTcpSockets);
    fTcpSockets.clear();
    delete ui;
}

void DlgMain::closeEvent(QCloseEvent *e)
{
    if (fCanClose) {
        QDialog::closeEvent(e);
        return;
    } else {
        hide();
        e->ignore();
        return;
    }
}

void DlgMain::logActivity(const QString &action)
{
    if (ui->chDoNotLog->isChecked()) {
        return;
    }
    QDateTime d = QDateTime::currentDateTime();
    QString log = QString("%1: %2")
            .arg(d.toString(def_date_time_format))
            .arg(action);
    QListWidgetItem *item = new QListWidgetItem(ui->lwActivity);
    item->setText(log);
    ui->lwActivity->addItem(item);
    if (ui->lwActivity->count() > 100) {
        for (int i = 0; i < 50; i++) {
            delete ui->lwActivity->item(i);
        }
    }
}

void DlgMain::processTravelLine()
{
    if (ui->leTravelineDB->text().isEmpty()) {
        return;
    }
    QString dbid = ui->leTravelineDB->text();
#ifdef QT_DEBUG
    dbid = 1;
#endif
    DoubleDatabase dd(ui->leHost->text(), ui->leDatabase->text(), ui->leUsername->text(), ui->lePassword->text());
    dd.open(true, false);
    dd.exec(QString("select * from airwick.f_db where f_id in (%1) order by field(f_id, %1) limit 1").arg(dbid));
    int r = dd.rowCount();
    if (r == 0) {
        return;
    }
        __dd1Host = dd.getString(0, "f_host");
        __dd1Database = dd.getString(0, "f_database");
        __dd1Username = dd.getString(0, "f_username");
        __dd1Password = dd.getString(0, "f_password");

    DoubleDatabase dr(true, false);
    dr.exec("select * from travelline where f_id=1");
    if (dr.nextRow() == false) {
        return;
    }
    QJsonObject jo = QJsonDocument::fromJson(dr.getString("f_connection").toUtf8()).object();
    Traveline *t = new Traveline(jo["username"].toString(), jo["password"].toString(), jo["hotelid"].toString(), jo["url"].toString(), this);
    connect(t, &Traveline::end, this, &DlgMain::travellineFinished);
    for (int i = 0; i < dr.columnCount(); i++) {
        jo[dr.fColumnNameMap[i]] = dr.getString(i);
    }
    t->queryReservations(jo);
}

void DlgMain::timeout()
{
    processTravelLine();
}

void DlgMain::appTerminate()
{
    fCanClose = true;
    qApp->quit();
}

void DlgMain::iconClicked(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::DoubleClick:
        setVisible(true);
        break;
    default:
        break;
    }
}

void DlgMain::newConnection()
{
    QMutexLocker ml(&mutex);
    QTcpSocket *s = fTcpServer.nextPendingConnection();
    logActivity(QString("New connection. Client: %1:%2")
                .arg(QHostAddress(s->peerAddress().toIPv4Address()).toString())
                .arg(s->peerPort()));
    connect(s, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    connect(s, SIGNAL(readyRead()), this, SLOT(clientReadyRead()));
    Command *cmd = new Command(s);
    fAllSockets.insert(s, cmd);
    connect(cmd, SIGNAL(parseCommand(QString)), this, SLOT(parseCommand(QString)));
}

void DlgMain::clientDisconnected()
{
    QMutexLocker ml(&mutex);
    QTcpSocket *s = static_cast<QTcpSocket*>(sender());
    for (int i = 0; i < ui->tblConn->rowCount(); i++) {
        if (ui->tblConn->item(i, 0)->data(Qt::UserRole + 1).toInt() == 1) {
            continue;
        }
        if (ui->tblConn->item(i, 0)->data(Qt::UserRole).value<QTcpSocket*>() == s) {
            QImage img(":/ball-red.png");
            ui->tblConn->item(i, 0)->setData(Qt::UserRole + 1, 1);
            ui->tblConn->item(i, 0)->setData(Qt::DecorationRole, img);
            ui->tblConn->item(i, 3)->setData(Qt::DisplayRole, QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss"));
            ui->tblConn->removeCellWidget(i, 7);
            break;
        }
    }
    Command *c = nullptr;
    if (fTcpSockets.contains(s)) {
        c = fTcpSockets[s];
        fTcpSockets.remove(s);
    } else if (fTcpSocketsDraft.contains(s)){
        c = fTcpSocketsDraft[s];
        fTcpSocketsDraft.remove(s);;
    } else {
        c = fAllSockets[s];
    }
    fAllSockets.remove(s);
    s->deleteLater();
    if (c) {
        logActivity(QString("Connection closed. Client: %1:%2, %3")
                    .arg(QHostAddress(s->peerAddress().toIPv4Address()).toString())
                    .arg(s->peerPort())
                    .arg(c->fDatabase));
        c->deleteLater();
    }
}

void DlgMain::clientReadyRead()
{
    QTcpSocket *s = static_cast<QTcpSocket*>(sender());
    Command *cmd = fAllSockets[s];
    cmd->readBytes(s->readAll());
}

void DlgMain::datagramRead()
{
    DoubleDatabase db;
    db.setDatabase(ui->leHost->text(), ui->leDatabase->text(), ui->leUsername->text(), ui->lePassword->text(), 1);
    if (!db.open(true, false)) {
        logActivity("Cannot open db in DlgMain::datagramRead," + db.fLastError + QString("%1,%2,%3,%4")
                    .arg(ui->leHost->text())
                    .arg(ui->leDatabase->text())
                    .arg(ui->leUsername->text())
                    .arg(ui->lePassword->text()));
        return;
    }
    while (fUdpSocket.hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(fUdpSocket.pendingDatagramSize());
        QHostAddress remoteAddress;
        quint16 remotePort;
        fUdpSocket.readDatagram(datagram.data(), datagram.size(), &remoteAddress, &remotePort);
        logActivity(datagram);
        QJsonDocument jDoc = QJsonDocument::fromJson(datagram);
        QJsonObject jObj = jDoc.object();
        if (jObj.contains("server")) {
            QString req = jObj.value("server").toString();
            QString client = jObj.value("client").toString();
            db[":f_name"] = client;
            db.exec("select f_id from f_users where lower(f_name)=lower(:f_name)");
            if (!db.nextRow()) {
                logActivity("Client not found, append new " + client);
                logActivity(db.fLastError);
                db[":f_name"] = client;
                db.insert("f_users", false);
                db.exec("select f_id from f_db");
                for (int i = 0; i < db.rowCount(); i++) {
                    DoubleDatabase d2(db);
                    d2.open(true, false);
                    d2[":f_user"] = client;
                    d2[":f_db"] = db.getValue(i, "f_id");
                    d2[":f_right"] = 0;
                    d2.insert("f_access", false);
                }
            }
            if (req == "who") {
                QJsonObject jObjReply;
                jObjReply["server"] = "me";
                jObjReply["server_port"] = ui->leServerPort->text();
                jObjReply["host"] = ui->leHost->text();
                jObjReply["database"] = ui->leDatabase->text();
                jObjReply["username"] = ui->leUsername->text();
                jObjReply["password"] = ui->lePassword->text();
                jObjReply["loghost"] = ui->leLogHost->text();
                jObjReply["logdb"] = ui->leLogDb->text();
                jObjReply["loguser"] = ui->leLogUsername->text();
                jObjReply["logpass"] = ui->leLogPassword->text();
                jObjReply["idgen"] = (int) ui->rgGenRangom->isChecked();
                QJsonDocument jDocReply(jObjReply);
                datagram = jDocReply.toJson();
                fUdpSocket.writeDatagram(datagram, remoteAddress, remotePort);
                logActivity(datagram);
            }
        } else if (jObj.contains("first_setup")) {
            QString password = jObj["first_setup"].toString();
            DoubleDatabase dbTest;
            dbTest.setDatabase(ui->leHost->text(), ui->leDatabase->text(), ui->leUsername->text(), password, 1);
            QJsonObject jObjReply;
            jObjReply["first_setup"] = dbTest.open(true, false) ? "ok" : "false";
            dbTest.close();
            if (jObjReply["first_setup"].toString() == "ok") {
                db[":f_user"] = jObj["client"].toString();
                db.exec("delete from f_access where f_user=:f_user");
                db.exec("select f_id from f_db");
                for (int i = 0; i < db.rowCount(); i++) {
                    DoubleDatabase db2(db);
                    db2.open(true, false);
                    db2[":f_user"] = jObj["client"].toString();
                    db2[":f_db"] = db.getValue(i, "f_id");
                    db2[":f_right"] = 1;
                    db2.insert("f_access", false);
                }
            }
            QJsonDocument jDocReply(jObjReply);
            datagram = jDocReply.toJson();
            fUdpSocket.writeDatagram(datagram, remoteAddress, remotePort);
        }
    }
}

void DlgMain::parseCommand(const QString &command)
{
    QMutexLocker ml(&mutex);
    Command *cmd = static_cast<Command*>(sender());
    logActivity("Command: " + command);
    QJsonDocument jDoc = QJsonDocument::fromJson(command.toUtf8());
    QJsonObject jObj = jDoc.object();
    QJsonObject jObjDb = jObj.value("db").toObject();
    QJsonObject jObjCmd = jObj.value("command").toObject();
    QString db = jObjDb.value("database").toString();
    cmd->fDatabase = db;
    QJsonValue jValCmd = jObjCmd.value("command");
    if (jValCmd.toString() == "identify") {
        if (cmd->identify(db)) {
            cmd->fUsername = jObjDb.value("user").toString();
            fTcpSockets.insert(cmd->fSocket, cmd);

                int row = ui->tblConn->rowCount();
                ui->tblConn->setRowCount(row + 1);
                QTableWidgetItem *item = new QTableWidgetItem(QHostAddress(cmd->fSocket->peerAddress().toIPv4Address()).toString());
                ui->tblConn->setItem(row, 0, new QTableWidgetItem());
                QImage img(":/ball-green.png");
                ui->tblConn->item(row, 0)->setData(Qt::DecorationRole, img);
                ui->tblConn->item(row, 0)->setData(Qt::UserRole, QVariant::fromValue(cmd->fSocket));
                ui->tblConn->setItem(row, 1, item);
                ui->tblConn->setItem(row, 2, new QTableWidgetItem(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss")));
                ui->tblConn->setItem(row, 3, new QTableWidgetItem());
                ui->tblConn->setItem(row, 4, new QTableWidgetItem(db));
                ui->tblConn->setItem(row, 5, new QTableWidgetItem());
                ui->tblConn->setItem(row, 6, new QTableWidgetItem());
                QTcpPushButton *btn = new QTcpPushButton(cmd->fSocket);
                ui->tblConn->setCellWidget(row, 7, btn);
                ui->tblConn->setItem(row, 8, new QTableWidgetItem(cmd->fUsername));
                QString session = QUuid::createUuid().toByteArray().replace("{", "").replace("}", "");
                ui->tblConn->setItem(row, 9, new QTableWidgetItem());
                ui->tblConn->setItem(row, 10, new QTableWidgetItem(session));
                session = QString("{\"command\":\"session\",\"session\":\"%1\"}").arg(session);
                QByteArray ds;
                int s = session.toUtf8().length();
                ds.append(reinterpret_cast<const char*>(&s), sizeof(s));
                ds.append(session.toUtf8());
                cmd->fSocket->write(ds.data(), ds.length());
                cmd->fSocket->flush();
                cmd->fSocket->waitForBytesWritten();

        }
        return;
    } else if (jValCmd.toString() == "draft") {
        fTcpSocketsDraft.insert(cmd->fSocket, cmd);
        return;
    } else if (jValCmd.toString() == "logout") {
        QString session = jObjCmd["session"].toString();
        for (int i = 0; i < ui->tblConn->rowCount(); i++) {
            if (ui->tblConn->item(i, 10)->text() == session) {
                ui->tblConn->item(i, 9)->setText(tr("Logout"));
            }
        }
        return;
    }

    QJsonDocument jDocBroadcast(jObjCmd);
    QString newCmd = jDocBroadcast.toJson(QJsonDocument::Compact);
    int size = newCmd.toUtf8().length();
    QByteArray dataToSend;
    dataToSend.append(reinterpret_cast<const char*>(&size), sizeof(size));
    dataToSend.append(newCmd.toUtf8());
    for (QMap<QTcpSocket*, Command*>::const_iterator it = fTcpSockets.constBegin(); it != fTcpSockets.constEnd(); it++) {
        if (it.value()->fDatabase != cmd->fDatabase) {
            continue;
        }
        if (!it.value()->isIdentified()) {
            continue;
        }
        it.key()->write(dataToSend, dataToSend.length());
        if (!ui->chDoNotLog->isChecked()) {
            for (int i = 0; i < ui->tblConn->rowCount(); i++) {
                if (ui->tblConn->item(i, 0)->data(Qt::UserRole + 1).toInt() == 1) {
                    continue;
                }
                if (it.key() == static_cast<QTcpPushButton*>(ui->tblConn->cellWidget(i, 7))->fSocket) {
                    ui->tblConn->item(i, 6)->setData(Qt::DisplayRole, QString::number(ui->tblConn->item(i, 6)->data(Qt::DisplayRole).toInt() + dataToSend.length()));
                    goto QUIT;
                }
            }
        }
        QUIT:
        continue;
    }
}

void DlgMain::on_btnSave_clicked()
{
    QSettings s("SmartHotel", "SmartHotel");
    s.setValue("server_port", ui->leServerPort->text());
    s.setValue("host", ui->leHost->text());
    s.setValue("database", ui->leDatabase->text());
    s.setValue("username", ui->leUsername->text());
    s.setValue("password", ui->lePassword->text());
    s.setValue("loghost", ui->leLogHost->text());
    s.setValue("logdb", ui->leLogDb->text());
    s.setValue("logusername", ui->leLogUsername->text());
    s.setValue("logpassword", ui->leLogPassword->text());
    s.setValue("idgen", ui->rgGenRangom->isChecked());
    DoubleDatabase db;
    db.setDatabase(ui->leHost->text(), ui->leDatabase->text(), ui->leUsername->text(), ui->lePassword->text(), 1);
    if (!db.open(true, false)) {
        logActivity(db.fLastError);
        return;
    }
    db.close();
}

void DlgMain::on_btnClear_clicked()
{
    ui->lwActivity->clear();
}


void DlgMain::on_btnClearDisconnected_clicked()
{
    for (int i = ui->tblConn->rowCount() - 1; i > -1; i--) {
        if (ui->tblConn->item(i, 0)->data(Qt::UserRole + 1).toInt() == 1) {
            ui->tblConn->removeRow(i);
        }
    }
}

void DlgMain::on_tabWidget_currentChanged(int index)
{
    if (index == 2) {
        bool ok;
        QString pwd = QInputDialog::getText(this, tr("Settings password"), tr("Password"), QLineEdit::Password, "", &ok);
        if (!ok || ui->lePassword->text() != pwd) {
            ui->tabWidget->setCurrentIndex(0);
            if (ok) {
                QMessageBox::critical(this, tr("Error"), tr("Access denied"));
            }
        } else {
            ui->wSettings->setVisible(true);
        }
    } else {
        ui->wSettings->setVisible(false);
    }
}

void DlgMain::travellineFinished(QString ar)
{
    QJsonArray ja = QJsonDocument::fromJson(ar.toUtf8()).array();
    sender()->deleteLater();
    DoubleDatabase dd(ui->leHost->text(), ui->leDatabase->text(),
                      ui->leUsername->text(), ui->lePassword->text());
    dd.open(true, false);
    QString dbid = ui->leTravelineDB->text();
#ifdef QT_DEBUG
    dbid = "1";
#endif
    dd.exec(QString("select * from airwick.f_db where f_id in (%1) order by field(f_id, %1)").arg(dbid));
    int r = dd.rowCount();
    if (r == 0) {
        return;
    }
    if (r ==  1) {
        __dd1Host = dd.getString(0, "f_host");
        __dd1Database = dd.getString(0, "f_database");
        __dd1Username = dd.getString(0, "f_username");
        __dd1Password = dd.getString(0, "f_password");
    } else {
        __dd2Host = dd.getString(1, "f_host");
        __dd2Database = dd.getString(1, "f_database");
        __dd2Username = dd.getString(1, "f_username");
        __dd2Password = dd.getString(1, "f_password");
    }

    DoubleDatabase dr(true, r > 1);
    dr.exec("select f_rate from f_acc_currencies where f_id=2");
    dr.nextRow();
    double dollarRate = dr.getDouble("f_rate");

    dr.exec("select * from travelline where f_id=1");
    if (dr.nextRow() == false) {
        return;
    }

    QString responseStr = dr.getString("f_confirmrs");
    QString responseStrBody = dr.getString("f_confirmrsbody");
    QString travellineConfig = dr.getString("f_connection");
    QJsonObject companyCodes = QJsonDocument::fromJson(dr.getString("f_bookingmap").toUtf8()).object();
    QJsonArray jRoomTypes = QJsonDocument::fromJson(dr.getString("f_room_types").toUtf8()).array();
    QMap<QString, QString> roomClass;
    QMap<QString, int> roomQty;
    for (int i = 0; i < jRoomTypes.size(); i++) {
        const QJsonObject &jo = jRoomTypes.at(i).toObject();
        roomClass[jo["api"].toString()] = jo["category"].toString();
        roomQty[jo["api"].toString()] = jo["qty"].toString().toInt();
    }
    QJsonDocument jdoc = QJsonDocument::fromJson(dr.getString("f_rate_plans").toUtf8());
    QJsonArray jRatePlans = jdoc.array();
    QMap<QString, double> ratePlan;
    for (int i = 0; i < jRatePlans.size(); i++) {
        const QJsonObject &jo = jRatePlans.at(i).toObject();
        ratePlan[jo["api"].toString()] = jo["price"].toString().toDouble();
    }

    QMap<QString, QString> newTravelResID;
    QStringList newResID;
    QSet<int> guestsCache;

    for (int i = 0; i < ja.count(); i++) {
        const QJsonObject &jr = ja.at(i).toObject();
        const QJsonArray &jrooms = ja.at(i)["rooms"].toArray();

        bool update = false;
        QString existsRes, existsIn;
        dr[":f_chm"] = jr["res_id"].toString();
        dr.exec("select f_id, f_invoice from f_reservation where f_chm=:f_chm");
        if (dr.nextRow()) {
            existsRes = dr.getString("f_id");
            existsIn = dr.getString("f_invoice");
        }
        update = !existsRes.isEmpty();

        dr[":f_name"] = jr["cardex"].toString();
        dr.exec("select f_cardex, f_cityledger from f_cardex where f_name=:f_name");

        QString cardex;
        int cityLedger = 0;
        if (dr.nextRow()) {
            cardex = dr.getString("f_cardex");
            //cityLedger = dr.getInt("f_cityledger");
        }
        if (!jr["companyname"].toString().isEmpty()) {
            if (companyCodes.contains(jr["companyname"].toString())) {
                cardex = companyCodes[jr["companyname"].toString()].toString();
            }
        }
        QString comment = jr["comment"].toString() + "\r\n ";
        int commentStart = comment.indexOf("Guest's comment:");
        if (commentStart > -1) {
            int commentEnd = comment.indexOf("\r\n", commentStart + 1);
            comment = comment.mid(commentStart + 17, commentEnd - commentStart - 17);
        } else {
            comment = "";
        }
        comment += "\r\n" + jr["full_comment"].toString();

        QJsonObject mainGuest = jr["main_guest"].toObject();
        dr[":f_email"] = mainGuest["email"].toString();
        dr.exec("select * from f_guests where f_email=:f_email");
        int mainGuestId = 0;
//        if (dr.nextRow()) {
//            mainGuestId = dr.getInt("f_id");
//            dr[":f_firstname"] = mainGuest["first_name"].toString();
//            dr[":f_lastname"] = mainGuest["last_name"].toString();
//            dr[":f_tel1"] = mainGuest["phone"].toString();
//            dr.update("f_guests", QString("where f_id=%1").arg(mainGuestId));
//        }
        if (mainGuestId == 0) {
            dr[":f_title"] = "";// "MR.";
            dr[":f_firstname"] = mainGuest["first_name"].toString().toUpper();
            dr[":f_lastname"] = mainGuest["last_name"].toString().toUpper();
            dr[":f_sex"] = 1;
            //dr[":f_datebirth"] =
            dr[":f_nation"] = "";
            dr[":f_passport"] ="";
            dr[":f_email"] = mainGuest["email"].toString();
            dr[":f_tel1"] = mainGuest["phone"].toString();
            mainGuestId = dr.insert("f_guests");
        }
        guestsCache.insert(mainGuestId);

        int paymenttype = 1;
        QString paymentName = jr["paymenttype"].toString();
        if (paymentName == "PaymentMethodName") {
            paymentName = "CASH";
        } else if (paymentName == "BankCard") {
            paymentName = jr["paymentname"].toString();
            paymenttype = 2;
        }

        for (int r = 0; r < jrooms.size(); r++) {
            QJsonObject jroom = jrooms.at(r).toObject();

            dr[":f_short"] = roomClass[jroom["room_type"].toString()];
            dr.exec("select f_id from f_room where f_class in (select f_id from f_room_classes where f_short=:f_short)");
            QList<int> checkRooms;
            while (dr.nextRow()) {
                checkRooms.append(dr.getInt("f_id"));
            }

            double pricePerNight = ratePlan[jroom["rateplan"].toString()];
            double totalAmount = pricePerNight * jroom["days"].toString().toInt();
            totalAmount = jroom["total"].toDouble();
            pricePerNight = totalAmount / jroom["days"].toString().toInt();
            QDateTime startDate = QDateTime::fromString(jroom["arrival"].toString(), "yyyy-MM-ddTHH:mm:ss");
            QDateTime endDate = QDateTime::fromString(jroom["departure"].toString(), "yyyy-MM-ddTHH:mm:ss");

            int room = 0;
            QMap<QString, CacheReservation> reserveOut;
            for (const int &tempRoom: checkRooms) {
                bool fStartDateOk = true;
                bool fEndDateOk = true;
                CacheReservation cr;
                cr.fInstance = cache(cid_reservation);
                cr.fInstance->load();
                cr.check(startDate.date(), endDate.date(), tempRoom, reserveOut, fStartDateOk, fEndDateOk, "");
                if (fStartDateOk && fEndDateOk) {
                    room = tempRoom;
                    break;
                }
            }

            QString rsId;
            QString inId;
            if (update) {
                rsId = existsRes;
                inId = existsIn;

                if (jr["resstatus"].toString() == "Cancelled") {
                    dr[":f_id"] = rsId;
                    dr[":f_state"] = 6;
                    dr[":f_canceluser"] = 1;
                    dr[":f_canceldate"] = QDate::currentDate();
                    dr.update("f_reservation", where_id(ap(rsId)));
                    dr[":f_id"] = rsId;
                    dr[":f_reason"] = "Cancelled by Exely.com";
                    dr.insert("f_reservation_cancel_reason");
                    dr[":f_comp"] = "SERVER";
                    dr[":f_date"] = QDate::currentDate();
                    dr[":f_time"] = QTime::currentTime();
                    dr[":f_user"] = 1;
                    dr[":f_type"] = 1;
                    dr[":f_rec"] = rsId;
                    dr[":f_invoice"] = inId;
                    dr[":f_reservation"] = rsId;
                    dr[":f_action"] =  "TRAVELLINE CANCELED";
                    dr[":f_value1"] = comment;
                    dr.insert("airlog.log", false);
                    newTravelResID[jr["res_id"].toString()] = rsId;
                    newResID.append(rsId);
                    continue;
                }
            } else {
                rsId = uuidx("RS");
                inId = uuidx("IN");
            }
            newTravelResID[jr["res_id"].toString()] = rsId;
            newResID.append(rsId);
            dr[":f_id"] = rsId;
            dr[":f_invoice"] = inId;
            dr[":f_created"] = QDate::currentDate();
            dr[":f_author"] = 1;
            dr[":f_state"] = 2;
            dr[":f_reservestate"] = 4;
            dr[":f_arrangement"] = 1;
            dr[":f_mealincluded"] = 0;
            dr[":f_chm"] = jr["res_id"].toString();
            dr[":f_chmstatus"] = 1;
            dr[":f_room"] = room;
            dr[":f_group"] = 0;
            dr[":f_guest"] = mainGuestId;
            dr[":f_man"] = jroom["guest_count_men"].toInt();
            dr[":f_woman"] = 0;
            dr[":f_child"] = jroom["guest_count_oth"].toInt();;
            dr[":f_baby"] = 0;
            dr[":f_cardex"] = cardex;
            dr[":f_cityledger"] = cityLedger;
            dr[":f_booking"] = jr["res_external_id"].toString().isEmpty() ? jr["res_id"].toString() : jr["res_external_id"].toString();
            dr[":f_startdate"] = startDate;
            dr[":f_enddate"] = endDate;
            dr[":f_roomfee"] = pricePerNight;
            dr[":f_paymenttype"] = paymenttype;
            dr[":f_mealqty"] = 1;
            dr[":f_mealprice"] = 0;
            dr[":f_extrabed"] = 0;
            dr[":f_extrabedfee"] = 0;
            dr[":f_pricepernight"] = pricePerNight;
            dr[":f_vat"] = 20;
            dr[":f_vatamount"] = totalAmount - (totalAmount / ((20 / 100) + 1));
            dr[":f_vatmode"]  = 1;
            dr[":f_total"] = totalAmount;
            dr[":f_grandTotal"] = totalAmount;
            dr[":f_totalusd"] = (pricePerNight * jroom["days"].toInt()) / dollarRate;
            dr[":f_remarks"] = comment;
            dr[":f_createtime"] = QTime::currentTime();
            if (update) {
                dr.update("f_reservation", where_id(ap(existsRes)));
            } else {
                dr.insert("f_reservation", false);
            }


            if (update) {
                dr[":f_reservation"] = existsRes;
                dr.exec("delete from f_reservation_guests where f_reservation=:f_reservation");
            }
            dr[":f_reservation"] = rsId;
            dr[":f_guest"] = mainGuestId;
            dr[":f_first"] = 1;
            dr.insert("f_reservation_guests", false);

            dr[":f_id"] = rsId;
            dr[":f_source"] = "RS";
            dr[":f_res"] = rsId;
            dr[":f_wdate"] = QDate::currentDate();
            dr[":f_rdate"] = QDate::currentDate();
            dr[":f_time"] = QTime::currentTime();
            dr[":f_user"] = 1;
            dr[":f_room"] = 0;
            dr[":f_guest"] = mainGuest["first_name"].toString() + " " + mainGuest["last_name"].toString();
            dr[":f_itemcode"] = 32; // NEED TO UPDATE, FETCH FROM CONFIG
            dr[":f_amountamd"] = totalAmount;
            dr[":f_amountvat"] = totalAmount - (totalAmount / ((20 / 100) + 1));
            dr[":f_amountusd"] = dollarRate;
            dr[":f_paymentmode"] = 1;
            dr[":f_paymentcomment"] = "CASH";
            dr[":f_cityledger"] = cityLedger;
            dr[":f_sign"] = 1;
            dr[":f_inv"] = inId;
            dr[":f_finance"] = 0;
            dr[":f_remarks"] = comment;
            dr[":f_canceled"] = 0;
            dr[":f_side"] = 0;
            dr[":f_p"] = 0;
            dr[":f_rb"] = 0;
            dr[":f_cash"] = 0;
            if (update) {
                dr.update("m_register", where_id(ap(rsId)));
            } else {
                dr.insert("m_register", false);
            }

            qDebug() << "Reservation" << jr;

            dr[":f_comp"] = "SERVER";
            dr[":f_date"] = QDate::currentDate();
            dr[":f_time"] = QTime::currentTime();
            dr[":f_user"] = 1;
            dr[":f_type"] = 1;
            dr[":f_rec"] = rsId;
            dr[":f_invoice"] = inId;
            dr[":f_reservation"] = rsId;
            dr[":f_action"] = update ? "TRAVELLINE UPDATE" : "TRAVELLINE INSERT";
            dr[":f_value1"] = comment;
            dr.insert("airlog.log", false);
        }
    }

    if (!ui->leTravelineDB->text().isEmpty()) {
    for (QMap<QString, QString>::const_iterator it = newTravelResID.constBegin(); it != newTravelResID.constEnd(); it++) {
        QJsonObject jo = QJsonDocument::fromJson(travellineConfig.toUtf8()).object();
        Traveline *t = new Traveline(jo["username"].toString(), jo["password"].toString(), jo["hotelid"].toString(), jo["url"].toString(), this);
        connect(t, &Traveline::end, this, &DlgMain::travellineConfirm);
        QString body;
            body += responseStrBody.replace("%1", QDateTime::currentDateTime().toString("yyyy-MM-ddTHH:mm:ss"))
                    .replace("%2", it.key())
                    .replace("%3", it.value());

        body = responseStr.replace("%1", jo["hotelid"].toString()).replace("%2", body);
        qDebug() << body;
        jo["f_query"] = body;
        t->reservationCreated(jo);
    }
    }

    for (const QString &s: newResID) {
        BroadcastThread::cmdRefreshCache(34, s);
        BroadcastThread::cmdRefreshCache(33, 0);
        BroadcastThread::cmdRefreshCache(45, s);
        BroadcastThread::cmdRefreshCache(118, s);
        BroadcastThread::cmdRefreshCache(210, s);
    }
    for (int g: guestsCache) {
        BroadcastThread::cmdRefreshCache(43, QString::number(g));
    }
}

void DlgMain::travellineConfirm()
{
    sender()->deleteLater();
}

void DlgMain::on_leTravelineDB_textChanged(const QString &arg1)
{
    QSettings s("SmartHotel", "SmartHotel");
    s.setValue("travellinedb", arg1);
}

void DlgMain::on_pushButton_clicked()
{
    Traveline t;
    connect(&t, &Traveline::end, this, &DlgMain::travellineFinished);
    t.processResponse(ui->ttCustom->toPlainText().toUtf8());
}

