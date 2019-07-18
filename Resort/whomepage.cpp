#include "whomepage.h"
#include "ui_whomepage.h"

WHomePage::WHomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WHomePage)
{
    ui->setupUi(this);
}

WHomePage::~WHomePage()
{
    delete ui;
}
