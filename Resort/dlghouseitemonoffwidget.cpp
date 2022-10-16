#include "dlghouseitemonoffwidget.h"
#include "ui_dlghouseitemonoffwidget.h"

DlgHouseItemOnOffWidget::DlgHouseItemOnOffWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DlgHouseItemOnOffWidget)
{
    ui->setupUi(this);
}

DlgHouseItemOnOffWidget::~DlgHouseItemOnOffWidget()
{
    delete ui;
}

void DlgHouseItemOnOffWidget::setChecked(bool v)
{
    ui->btnOk->setChecked(v);
    ui->btnReady->setChecked(!v);
}

bool DlgHouseItemOnOffWidget::isChecked()
{
    return ui->btnOk->isChecked();
}

void DlgHouseItemOnOffWidget::on_btnReady_clicked()
{
    ui->btnOk->setChecked(!ui->btnReady->isChecked());
    emit clicked();
}

void DlgHouseItemOnOffWidget::on_btnOk_clicked()
{
    ui->btnReady->setChecked(!ui->btnOk->isChecked());
    emit clicked();
}
