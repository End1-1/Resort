#include "wactivegroup.h"
#include "ui_wactivegroup.h"
#include "cacheactivegroup.h"

WActiveGroup::WActiveGroup(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WActiveGroup)
{
    ui->setupUi(this);
    ui->leGroup->setSelector(this, cache(cid_active_group), ui->leGroupName);
}

WActiveGroup::~WActiveGroup()
{
    delete ui;
}

int WActiveGroup::group()
{
    return ui->leGroup->asInt();
}
