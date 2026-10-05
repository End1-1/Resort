#include "dlgexitbyversion.h"
#include "ui_dlgexitbyversion.h"
#include "utils.h"
#include <QApplication>
#include <QDir>

bool DO_NOT_CHECK_VERSION = false;

DlgExitByVersion::DlgExitByVersion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgExitByVersion)
{
    ui->setupUi(this);
    ui->lbMessage->setTextFormat(Qt::RichText);
    ui->lbMessage->setOpenExternalLinks(true);
    fCounter = 60;
    connect(&fTimer, SIGNAL(timeout()), this, SLOT(timeout()));
    fTimer.start(1000);
}

DlgExitByVersion::~DlgExitByVersion()
{
    delete ui;
}

void DlgExitByVersion::exit(const QString &appVersion, const QString &dbVersion)
{
    DlgExitByVersion *d = new DlgExitByVersion();
    d->setVersions(appVersion, dbVersion);
    d->exec();
    qApp->quit();
}

void DlgExitByVersion::exit(const QString &msg)
{
    DlgExitByVersion *d = new DlgExitByVersion();
    d->ui->btnUpdate->setVisible(false);
    d->ui->lbMessage->setText(msg);
    d->exec();
    qApp->quit();
}

void DlgExitByVersion::timeout()
{
    ui->lbTime->setText(QString("%1...").arg(fCounter));
    fCounter--;
    if(fCounter < 1) {
        QDir d;
        d.remove(d.homePath() + "/" + _APPLICATION_ + "/log.txt");
        qApp->exit(0);
    }
}

void DlgExitByVersion::on_btnClose_clicked()
{
    qApp->exit(0);
}

void DlgExitByVersion::on_btnUpdate_clicked()
{
    fTimer.stop();
    if(Utils::startProgramUpdater(fDbVersion, this, false)) {
        qApp->exit(0);
    } else {
        fTimer.start(1000);
    }
}

void DlgExitByVersion::setVersions(const QString &appVersion, const QString &dbVersion)
{
    fDbVersion = dbVersion.trimmed();
    const QString downloadUrl = Utils::setupDownloadUrl(fDbVersion);
    ui->lbMessage->setText(
        QString("Application version %1 <br>"
                "is not compatible with database version %2 <br>"
                "<h1>Update your application</h1>"
                "<br>"
                "Click <b>Update now</b> — SmartHotel will close and the updater will run.<br>"
                "<br>"
                "<a href=\"%3\">Or download manually</a>")
            .arg(appVersion)
            .arg(dbVersion)
            .arg(downloadUrl));
}
