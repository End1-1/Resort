#include "wweb.h"
#include "ui_wweb.h"

WWeb::WWeb(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WWeb)
{
    ui->setupUi(this);
    setupTabTextAndIcon(tr("Internet"), ":/images/internet.png");

}

WWeb::~WWeb()
{
    delete ui;
}

void WWeb::navigate(const QUrl &url)
{

}

void WWeb::openWeb(const QString &strUrl)
{
    QUrl url = QUrl(strUrl);
    WWeb *w = new WWeb();
    w->navigate(url);
    w->show();
}

void WWeb::on_leAddress_returnPressed()
{
    //ui->teWeb->setSource(ui->leAddress->text());
}

void WWeb::on_btnGo_clicked()
{
    on_leAddress_returnPressed();
}
