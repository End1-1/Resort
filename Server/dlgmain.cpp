#include "dlgmain.h"
#include "ui_dlgmain.h"
#include "defines.h"
#include "qtcppushbutton.h"
#include "logging.h"
#include "doubledatabase.h"
#include <QCloseEvent>
#include <QHostAddress>
#include <QTcpSocket>
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QSettings>
#include <QUuid>
#include <QNetworkProxy>
#include <QMutex>

QMutex mutex;

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
    fTcpServer.
    connect(&fUdpSocket, SIGNAL(readyRead()), this, SLOT(datagramRead()));

    ui->tblConn->setColumnWidth(0, 50);
    ui->tblConn->setColumnWidth(1, 150);
    ui->tblConn->setColumnWidth(2, 120);
    ui->tblConn->setColumnWidth(3, 120);
    ui->tblConn->setColumnWidth(7, 40);
    ui->tblConn->setColumnWidth(10, 0);
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
    Command *c = 0;
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
    for (QMap<QTcpSocket*, Command*>::const_iterator it = fTcpSockets.begin(); it != fTcpSockets.end(); it++) {
        if (it.value()->fDatabase != cmd->fDatabase) {
            continue;
        }
        if (!it.value()->isIdentified()) {
            continue;
        }
        it.key()->write(dataToSend, dataToSend.length());
 //       it.key()->flush();
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
