#include "dlgmain.h"
#include "paymentmode.h"
#include "ui_dlgmain.h"
#include "utils.h"
#include "doubledatabase.h"
#include "baseuid.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QSettings>
#include <QMessageBox>
#include <QFile>
#include <QProcess>
#include <QInputDialog>

const static QString locCall = "2";
const static QString intCall = "3";

#define def_user_id "user_id"
#define def_host "host"
#define def_db "db"
#define def_user "username"
#define def_pass "password"
#define def_filelog "filelog"
#define def_com_port "com port"
#define def_com_data "com data bits"
#define def_com_parity "com parity"
#define def_ats_model "ats model"
#define def_smarthotel "SmartHotel"
#define def_smarthotel_ats "SmartHotel\\ATS"
#define def_r_line "r_line"
#define def_r_incoming_number "r_incoming_number"
#define def_r_executable "r_executable"
#define def_r_min_time "r_min_time"
#define def_air_host "air_host"
#define def_air_db "air_db"
#define def_air_user "air_user"
#define def_air_pass "air_pass"

DlgMain::DlgMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgMain)
{
    ui->setupUi(this);

    fCanClose = false;
    fTrayMenu.addAction(tr("Quit ATS"), this, SLOT(appTerminate()));
    fCanClose = false;
    fTrayIcon.setIcon(QIcon(":/app.png"));
    fTrayIcon.show();
    fTrayIcon.setContextMenu(&fTrayMenu);
    connect(&fTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconClicked(QSystemTrayIcon::ActivationReason)));

    fCallMap["E"] = 1;
    fCallMap["G"] = 2;
    fCallMap["O"] = 3;
    fCallMap["T"] = 4;
    fCallMap["t"] = 5;

    fPref.initFromConfig();
    QSettings s(def_smarthotel, def_smarthotel_ats);
    ui->leHost->setText(s.value(def_host).toString());
    ui->leDb->setText(s.value(def_db).toString());
    ui->leUsername->setText(s.value(def_user).toString());
    ui->leUserId->setText(s.value(def_user_id).toString());
    ui->lePassword->setText(s.value(def_pass).toString());
    ui->chFileLog->setChecked(s.value(def_filelog).toBool());
    ui->leATSPort->setText(s.value(def_com_port).toString());
    ui->cbATS->setCurrentIndex(s.value(def_ats_model).toInt());
    ui->cbComData->setCurrentIndex(s.value(def_com_data).toInt());
    ui->cbComParity->setCurrentIndex(s.value(def_com_parity).toInt());
    ui->leLine->setText(s.value(def_r_line).toString());
    ui->leIncomingNumber->setText(s.value(def_r_incoming_number).toString());
    ui->lePathToExecutable->setText(s.value(def_r_executable).toString());
    ui->leTime->setText(s.value(def_r_min_time).toString());
    ui->leAirHost->setText(s.value(def_air_host).toString());
    ui->leAirDb->setText(s.value(def_air_db).toString());
    ui->leAirUser->setText(s.value(def_air_user).toString());
    ui->leAirPass->setText(s.value(def_air_pass).toString());

    fPref.appendDatabase("MainDb", ui->leHost->text(), ui->leDb->text(), ui->leUsername->text(), ui->lePassword->text(), "", "", "", "");
    fPref.initFromDb("MainDb", "", 0);
    //Db db = fPref.getDatabase("MainDb");


    _IDGENMODE_ = 1;
    __dd1Host = ui->leHost->text();
    __dd1Database = ui->leDb->text();
    __dd1Username = ui->leUsername->text();
    __dd1Password = ui->lePassword->text();
    DoubleDatabase fDb;
    fDb.setDatabase(ui->leHost->text(), ui->leDb->text(), ui->leUsername->text(), ui->lePassword->text(), 1);
    BaseUID::fAirHost = ui->leHost->text();
    BaseUID::fAirDbName = "airwick";
    BaseUID::fAirUser = ui->leUsername->text();
    BaseUID::fAirPass = ui->lePassword->text();
    fDb.open(true, false);
    fDb.exec("select f_code, f_rate, f_local from f_call_rate");
    while (fDb.nextRow()) {
        rates[fDb.getString(0)] = fDb.getDouble(1);
        fCallType[fDb.getString(0)] = fDb.getInt(2);
    }
    fDb.close();

    fPort.setPortName(ui->leATSPort->text());
    switch (ui->cbComData->currentIndex()) {
    case 0:
        fPort.setDataBits(QSerialPort::Data5);
        break;
    case 1:
        fPort.setDataBits(QSerialPort::Data6);
        break;
    case 2:
        fPort.setDataBits(QSerialPort::Data7);
        break;
    case 3:
        fPort.setDataBits(QSerialPort::Data8);
        break;
    }
    fPort.setBaudRate(QSerialPort::Baud9600);
    fPort.setFlowControl(QSerialPort::NoFlowControl);
    fPort.setStopBits(QSerialPort::OneStop);
    switch (ui->cbComParity->currentIndex()) {
    case 0:
        fPort.setParity(QSerialPort::NoParity);
        break;
    case 1:
        fPort.setParity(QSerialPort::EvenParity);
        break;
    case 2:
        fPort.setParity(QSerialPort::OddParity);
        break;
    }
    connect(&fPort, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(&fPort, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(portError(QSerialPort::SerialPortError)));
    fPort.open(QSerialPort::ReadOnly);
    writeToFile(fPort.readAll());

    connect(ui->tabWidget, &QTabWidget::currentChanged, [this](int index) {
        if (index == 1) {
            ui->tabSettings->setVisible(false);
            QString pwd = QInputDialog::getText(this, tr("Password"), tr("Password"), QLineEdit::PasswordEchoOnEdit);
            if (pwd == ui->lePassword->text()) {
                ui->tabSettings->setVisible(true);
            } else {
                QMessageBox::critical(this, tr("Error"), tr("Invalid password"));
                ui->tabWidget->setCurrentIndex(0);
                ui->tabSettings->setVisible(true);
            }
        }
    });
}

DlgMain::~DlgMain()
{
    delete ui;
}

void DlgMain::closeEvent(QCloseEvent *e)
{
    if (fCanClose) {
        QDialog::closeEvent(e);
    } else {
        e->ignore();
        hide();
    }
}

void DlgMain::processLine(const QString &line)
{
    writeToFile(line);
    if (QDate::fromString(fPref.getDb(def_working_day).toString(), def_date_format) < QDate::currentDate()) {
        fPref.initFromDb("MainDb", "", 0);
    }
    DoubleDatabase fDb;
    fDb.setDatabase(ui->leHost->text(), ui->leDb->text(), ui->leUsername->text(), ui->lePassword->text(), 1);
    bool secondDb = true;
    QStringList dbParams = fPref.getDb("dd").toString().split(";", QString::SkipEmptyParts);
    if (dbParams.count() == 4) {
        __dd2Host = dbParams[0];
        __dd2Database = dbParams[1];
        __dd2Username = dbParams[2];
        __dd2Password = dbParams[3];

        fDb.logEvent("ATS, Set second db");
        fDb.setDatabase(__dd2Host, __dd2Database, __dd2Username, __dd2Password, 2);
    } else {
        secondDb = false;
    }
    if (!fDb.open(true, secondDb)) {
        callLog("DB connection error");
        return;
    }
    QString l = line;
    if (l.contains("Site")) {
        return;
    }
    if (l.contains("---")) {
        return;
    }
    if (l.contains("DIALED")) {
        return;
    }
    if (l.length() < 5) {
        return;
    }
    int row = ui->tblData->rowCount();
    ui->tblData->setRowCount(row + 1);
    for (int i = l.length() - 1; i > 0; i--) {
        if (l.at(i) == 0x20 && l.at(i - 1) == 0x20) {
            l.remove(i, 1);
        }
    }
    QStringList lines = l.split(0x20, QString::SkipEmptyParts);
    if (lines.count() < 9) {
        lines.insert(2, "-");
    }
    int isLocal = 1;
    QString o = lines[6];
    lines.insert(6, o.mid(0, 1));
    lines[7] = o.remove(0, 1);
    QString area = "***";
    double price =  rates["***"];
    if (lines[7].length() > 6) {
        area = lines[7].mid(0, 7);
        bool found = false;
        while (!found) {
            area = area.remove(area.length() - 1, 1);
            if (area.isEmpty()) {
                break;
            }
            for (QMap<QString, double>::const_iterator it = rates.begin(); it != rates.end(); it++) {
                if (it.key() == area) {
                    found = true;
                    price = rates[area];
                    isLocal = fCallType[area];
                    goto mark;
                }
            }
        }
    }

    mark:
    callLog(area);
    int duration = QTime(0, 0, 0).secsTo(QTime::fromString(lines[3], "HH:mm:ss"));
    callLog(QString::number(duration));
    callLog(float_str(price, 2));
    if (duration < 16) {
        price = 0;
    }
    int mins = duration / 60;
    if (duration % 60 > 0) {
        mins++;
    }
    price = price * mins;
    lines[8] = float_str(price, 2);
    if (lines[6] != "O" && lines[6] != "T") {
        price = 0;
        lines[8] = "0";
    }
    // try to get guest

    if (price > 0.1) {
        fDb[":f_room"] = lines[1];
        fDb[":f_state"] = RESERVE_CHECKIN;
        fDb.exec("select r.f_invoice, concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName), "
                   "r.f_room "
                   "from f_reservation r "
                   "inner join f_guests g on g.f_id=r.f_guest "
                   "where r.f_room=:f_room and r.f_state=:f_state");
    }
    int recId = 0;
    int fDoc = 0;
    if (fDb.nextRow()) {
        callLog("Have invoice");
        lines[9] = fDb.getString(1);
        QString invoice= fDb.getString(0);
        QString room = fDb.getString(2);

        QString rid = uuid("CM");
        fDb.insertId("m_register", rid);
        fDb[":f_source"] = "CM";
        fDb[":f_wdate"] = QDate::fromString(fPref.getDb(def_working_day).toString(), def_date_format);
        fDb[":f_rdate"] = QDate::currentDate();
        fDb[":f_time"] = QTime::currentTime();
        fDb[":f_user"] = ui->leUserId->text().toInt();
        fDb[":f_room"] = room;
        fDb[":f_guest"] = lines[9];
        fDb[":f_itemCode"] = (isLocal == 1 ? locCall : intCall);
        fDb[":f_finalName"] = (isLocal == 1 ? "LOC. CALL" : "INT. CALL");
        fDb[":f_amountAmd"] = trunc(price);
        fDb[":f_amountVat"] = Utils::countVATAmount(trunc(price), VAT_INCLUDED);
        fDb[":f_amountUsd"] = def_usd;
        fDb[":f_fiscal"] = 0;
        fDb[":f_paymentMode"] = PAYMENT_CREDIT;
        fDb[":f_creditCard"] = 0;
        fDb[":f_cityLedger"] = 0;
        fDb[":f_paymentComment"] = "";
        fDb[":f_dc"] = "CREDIT";
        fDb[":f_sign"] = 1;
        fDb[":f_doc"] = "";
        fDb[":f_rec"] = "";
        fDb[":f_inv"] = invoice;
        fDb[":f_finance"] = 1;
        fDb[":f_remarks"] = "";
        fDb[":f_canceled"] = 0;
        fDb[":f_cancelReason"] = "";
        fDb[":f_side"] = 0;
        fDb.update("m_register", where_id(ap(rid)));

    } else {
        //No price for another case
        callLog("No invoice");
        lines[8] = "0";
    }
    for (int i = 0; i < lines.count(); i++) {
        ui->tblData->setItem(row, i, new QTableWidgetItem(lines.at(i)));
    }

    fDb[":f_ats_id"] = lines[0];
    fDb[":f_local"] = lines[1];
    fDb[":f_u1"] = lines[2];
    fDb[":f_duration"] = QTime::fromString(lines[3], "HH:mm:ss");
    QDate d = QDate::fromString(lines[4], "MM/dd/yy");
    if (d.year() < 1981) {
        d = d.addYears(100);
    }
    fDb[":f_date"] = d;
    fDb[":f_time"] = QTime::fromString(lines[5], "HH:mm:ss");
    fDb[":f_ident"] = fCallMap[lines[6]];
    fDb[":f_remote"] = lines[7];
    fDb[":f_cost"] = lines[8];
    fDb[":f_acc"] = lines[9];
    fDb[":f_doc"] = fDoc;
    int id = fDb.insert("f_call_log", true);
    if (id < 0) {
        callLog(fDb.fLastError);
    }
    if (recId > 0) {
        fDb[":f_sourceId"] = id;
        fDb.update("f_invoice_content", where_id(recId));
    }

    fDb.close();

    bool exe = ui->lePathToExecutable->text().length() > 0;
    if (!ui->leLine->text().isEmpty()) {
        exe = exe && lines.at(2) == ui->leLine->text();
    }
    if (!ui->leIncomingNumber->text().isEmpty()) {
        exe = exe && lines.at(7) == ui->leIncomingNumber->text();
    }
    if (!ui->leTime->text().isEmpty()) {
        QTime t1 = QTime::fromString(ui->leTime->text(), "HH:mm:ss");
        QTime t2 = QTime::fromString(lines.at(3), "HH:mm:ss");
        exe = exe && t2 > t1;
    }
    if (exe) {
        QProcess *p = new QProcess(0);
        p->start(ui->lePathToExecutable->text());
    }
}

void DlgMain::processLine1(const QString &line)
{
    writeToFile(line);
}

void DlgMain::callLog(const QString &txt)
{
    ui->te->setPlainText(ui->te->toPlainText() + "\r\n" + txt);
}

void DlgMain::writeToFile(const QString &line)
{
    if (ui->chFileLog->isChecked()) {
        QFile f("./call.txt");
        f.open(QIODevice::Append);
        f.write(line.toUtf8());
        f.write("\r\n");
        f.close();
    }

}

void DlgMain::readyRead()
{
    QString temp;
    temp.append(0x0d).append(0x0a);
    fBuffer.append(fPort.readAll());
    ui->te->setPlainText(fBuffer);
    int pos = fBuffer.indexOf(temp, 0);
    ui->te->setPlainText(ui->te->toPlainText() + "|||" + QString::number(pos));
    if (pos > -1) {
        switch (ui->cbATS->currentIndex()) {
        case 0:
            processLine(fBuffer.mid(0, pos));
            break;
        case 1:
            processLine1(fBuffer.mid(0, pos));
            break;
        }
        fBuffer.remove(0, pos + 2);
    }
}

void DlgMain::portError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError != 0) {
        QMessageBox::critical(this, tr("Error"), tr("COM port error") + "\r\n" + QString::number(serialPortError));
    }
}

void DlgMain::iconClicked(QSystemTrayIcon::ActivationReason r)
{
    switch (r) {
    case QSystemTrayIcon::DoubleClick:
        setVisible(true);
        break;
    default:
        break;
    }
}

void DlgMain::appTerminate()
{
    fCanClose = true;
    close();
}

void DlgMain::on_leUserId_textChanged(const QString &arg1)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_user_id, arg1.toInt());
}

void DlgMain::on_leHost_textChanged(const QString &arg1)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_host, arg1);
}

void DlgMain::on_leDb_textChanged(const QString &arg1)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_db, arg1);
}

void DlgMain::on_leUsername_textChanged(const QString &arg1)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_user, arg1);
}

void DlgMain::on_lePassword_textChanged(const QString &arg1)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_pass, arg1);
}

void DlgMain::on_btnReconnect_clicked()
{
    DoubleDatabase fDb;
    fDb.setDatabase(ui->leHost->text(), ui->leDb->text(), ui->leUsername->text(), ui->lePassword->text(), 1);
    if (!fDb.open(true, false)) {
        QMessageBox::critical(this, tr("Database error"), fDb.fLastError);
    }
    fPref.appendDatabase("MainDb", ui->leHost->text(), ui->leDb->text(), ui->leUsername->text(), ui->lePassword->text(), "", "", "", "");
}

void DlgMain::on_chFileLog_clicked(bool checked)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_filelog, checked);
}

void DlgMain::on_leATSPort_textChanged(const QString &arg1)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_com_port, arg1);
}

void DlgMain::on_cbATS_currentIndexChanged(int index)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_ats_model, index);
}


void DlgMain::on_cbComData_currentIndexChanged(int index)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_com_data, index);
}

void DlgMain::on_cbComParity_currentIndexChanged(int index)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_com_parity, index);
}

void DlgMain::on_leLine_textChanged(const QString &arg1)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_r_line, arg1);
}

void DlgMain::on_leIncomingNumber_textChanged(const QString &arg1)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_r_incoming_number, arg1);
}

void DlgMain::on_lePathToExecutable_textChanged(const QString &arg1)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_r_executable, arg1);
}

void DlgMain::on_leTime_textChanged(const QString &arg1)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_r_min_time, arg1);
}

void DlgMain::on_leAirHost_textChanged(const QString &arg1)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_air_host, arg1);
}

void DlgMain::on_leAirDb_textChanged(const QString &arg1)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_air_db, arg1);
}

void DlgMain::on_leAirUser_textChanged(const QString &arg1)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_air_user, arg1);
}

void DlgMain::on_leAirPass_textChanged(const QString &arg1)
{
    QSettings s(def_smarthotel, def_smarthotel_ats);
    s.setValue(def_air_pass, arg1);
}
