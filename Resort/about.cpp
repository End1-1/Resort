#include "about.h"
#include "ui_about.h"
#include "utils.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    ui->lbVersion->setText("v " + Utils::getVersionString(qApp->applicationFilePath()));
    ui->lbDebug->setVisible(false);
#ifdef QT_DEBUG
    ui->lbDebug->setVisible(true);
#endif
    QString license;
}

About::~About()
{
    delete ui;
}

void About::on_buttonBox_accepted()
{
}
