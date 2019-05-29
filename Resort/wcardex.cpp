#include "wcardex.h"
#include "ui_wcardex.h"
#include "cachecardex.h"

WCardex::WCardex(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WCardex)
{
    ui->setupUi(this);
    ui->leCardex->setSelector(this, cache(cid_cardex), ui->leCardexName);
}

WCardex::~WCardex()
{
    delete ui;
}

bool WCardex::empty()
{
    return ui->leCardex->isEmpty();
}

QString WCardex::cardex()
{
    return ui->leCardex->text();
}
