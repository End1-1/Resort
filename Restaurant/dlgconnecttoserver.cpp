#include "dlgconnecttoserver.h"
#include "ui_dlgconnecttoserver.h"
#include "appconfig.h"
#include "trackcontrol.h"
#include "rmessage.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkInterface>

DlgConnectToServer::DlgConnectToServer(QWidget *parent) :
    BaseExtendedDialogR(parent),
    ui(new Ui::DlgConnectToServer)
{
    ui->setupUi(this);
    connect(&fUdpSocket, SIGNAL(readyRead()), this, SLOT(readDatagram()));
    timeout();
    connect(&fTimer, SIGNAL(timeout()), this, SLOT(timeout()));
    fTimer.start(2000);
}

DlgConnectToServer::~DlgConnectToServer()
{
    delete ui;
}

void DlgConnectToServer::timeout()
{
    QJsonObject jObj;
    jObj["server"] = "who";
    jObj["client"] = HOSTNAME + "." + fPreferences.hostUsername() + ".restaurant";
    QJsonDocument jDoc(jObj);
    QByteArray datagram = jDoc.toJson();
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface i, nets) {
        QList<QNetworkAddressEntry> addrs = i.addressEntries();
        foreach (QNetworkAddressEntry a, addrs) {
            if (a.ip().protocol() != QAbstractSocket::IPv4Protocol) {
                continue;
            }
            if (a.broadcast().toString().isEmpty()) {
                continue;
            }
            fUdpSocket.writeDatagram(datagram, a.broadcast(), DATAGRAM_PORT);
        }
    }
}

void DlgConnectToServer::readDatagram()
{
    DoubleDatabase fDD(true, doubleDatabase);
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
                fDD.setDatabase(jObj.value("host").toString(),
                                       jObj.value("database").toString(),
                                       jObj.value("username").toString(),
                                       jObj.value("password").toString(), 1);
                if (!fDD.open(true, false)) {
                    message_error(QString("Read datagram: Cannot connect to main database") + QString("<br>") + fDD.fLastError);
                    reject();
                    return;
                }

                BaseUIDX::fAirHost = jObj.value("host").toString();
                BaseUIDX::fAirDbName = jObj.value("database").toString();
                BaseUIDX::fAirUser = jObj.value("username").toString();
                BaseUIDX::fAirPass = jObj.value("password").toString();

                AppConfig::fServerAddress = jObj["host"].toString();
                AppConfig::fServerAddress = jObj["host"].toString();
                _IDGENMODE_ = jObj["idgen"].toInt();
                TrackControl::fDbHost = jObj["loghost"].toString();
                TrackControl::fDbDb = jObj["logdb"].toString();
                TrackControl::fDbUser = jObj["loguser"].toString();
                TrackControl::fDbPass = jObj["logpass"].toString();
                
                fDD[":f_user"] = HOSTNAME + "." + fPreferences.hostUsername() + ".restaurant";
                fDD.exec("select * from f_db where f_id in "
                          "(select f_db from f_access where lower(f_user)=lower(:f_user) and f_right=1)");
                for (int i = 0; i < fDD.rowCount(); i++) {
                    QMap<QString, QString> conn;
                    conn["f_host"] = fDD.getValue(i, "f_host").toString();
                    conn["f_database"] = fDD.getValue(i, "f_database").toString();
                    conn["f_username"] = fDD.getValue(i, "f_username").toString();
                    conn["f_password"] = fDD.getValue(i, "f_password").toString();
                    fPreferences.appendDatabase("Main", fDD.getValue(i, "f_host").toString(),
                                                fDD.getValue(i, "f_database").toString(),
                                                fDD.getValue(i, "f_username").toString(),
                                                fDD.getValue(i, "f_password").toString(),
                                                "", "", "", "");


                    accept();
                    return;
                }
            }
        }
    }
    fTimer.start(2000);
}
