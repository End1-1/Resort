#include "dlgconfigtaxserver.h"
#include "ui_dlgconfigtaxserver.h"
#include "trackcontrol.h"
#include "message.h"
#include <QSettings>

static QSettings config("SmartHotel", "SmartHotel\\taxserver");

DlgConfigTaxServer::DlgConfigTaxServer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgConfigTaxServer)
{
    ui->setupUi(this);
    ui->leAddress->setText(address());
    ui->lePort->setText(QString::number(port()));
    ui->lePassword->setText(password());
    ui->chRemote->setChecked(remote());
    fTrack = new TrackControl(TRACK_COMMON);
    fTrack->addWidget(ui->leAddress, "")
            .addWidget(ui->lePort, "")
            .addWidget(ui->lePassword, "")
            .addWidget(ui->chRemote, "");
}

DlgConfigTaxServer::~DlgConfigTaxServer()
{
    delete ui;
    delete fTrack;
}

QString DlgConfigTaxServer::address()
{
    return config.value("address").toString();
}

quint16 DlgConfigTaxServer::port()
{
    return static_cast<quint16>(config.value("port").toUInt());
}

QString DlgConfigTaxServer::password()
{
    return config.value("password").toString();
}

bool DlgConfigTaxServer::remote()
{
    return config.value("remote").toBool();
}

void DlgConfigTaxServer::closeEvent(QCloseEvent *event)
{
    if (fTrack->hasChanges()) {
        if (message_confirm(tr("Save changes?"))) {
            config.setValue("address", ui->leAddress->text());
            config.setValue("port", ui->lePort->text().toUInt());
            config.setValue("password", ui->lePassword->text());
            config.setValue("remote", ui->chRemote->isChecked());
        }
    }
    QDialog::closeEvent(event);
}
