#include "databaseconnection.h"
#include "ui_databaseconnection.h"

DatabaseConnection::DatabaseConnection(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DatabaseConnection)
{
    ui->setupUi(this);
    fAppendMode = true;
}

void DatabaseConnection::setConnection(const QString &name)
{
    fOldDbName = name;
    Db db = fPreferences.getDatabase(name);
    ui->leName->setText(db.dc_name);
    ui->leMainHost->setText(db.dc_main_host);
    ui->leMainDb->setText(db.dc_main_path);
    ui->leMainUser->setText(db.dc_main_user);
    ui->leMainPassword->setText(db.dc_main_pass);
    ui->cbProto->setCurrentText(db.dc_broadcast);
    fAppendMode = false;
}

DatabaseConnection::~DatabaseConnection()
{
    delete ui;
}

void DatabaseConnection::on_btnCancel_clicked()
{
    reject();
}

void DatabaseConnection::on_btnOk_clicked()
{
    if (!fAppendMode) {
        fPreferences.removeDatabase(fOldDbName);
    }
    fPreferences.appendDatabase(ui->leName->text(), ui->leMainHost->text(), ui->leMainDb->text(), ui->leMainUser->text(),
                                ui->leMainPassword->text(),
                                "", "", "", "", ui->cbProto->currentText());
    fPreferences.saveConfig();
    accept();
}

void DatabaseConnection::on_btnTest_clicked()
{
    DoubleDatabase db;
    db.setDatabase(ui->leMainHost->text(), ui->leMainDb->text(), ui->leMainUser->text(), ui->leMainPassword->text());
    if (db.open()) {
        message_info(tr("Connected!"));
    } else {
        message_info(QString("%1<br>%2")
                     .arg(tr("Connection failed!"))
                     .arg(db.fLastError));
    }
    db.close();
}
