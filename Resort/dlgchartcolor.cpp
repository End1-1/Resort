#include "dlgchartcolor.h"
#include "ui_dlgchartcolor.h"
#include "utils.h"
#include "message.h"
#include <QColorDialog>

DlgChartColor::DlgChartColor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgChartColor)
{
    ui->setupUi(this);
    ui->leReserveColor->setText(__s.value("reservecolor").toString());
    ui->leCheckinColor->setText(__s.value("checkincolor").toString());
    ui->leDoNotDisturbeColor->setText(__s.value("donotdisturbecolor").toString());
    ui->chShowRoomDescription->setChecked(__s.value("showroomdescription", false).toBool());
    connect(ui->leReserveColor, SIGNAL(doubleClicked()), this, SLOT(selectColor()));
    connect(ui->leCheckinColor, SIGNAL(doubleClicked()), this, SLOT(selectColor()));
    connect(ui->leDoNotDisturbeColor, SIGNAL(doubleClicked()), this, SLOT(selectColor()));
}

DlgChartColor::~DlgChartColor()
{
    delete ui;
}

void DlgChartColor::selectColor()
{
    EColorLineEdit *l = static_cast<EColorLineEdit*>(sender());
    QColor initColor = l->color();
    int color = QColorDialog::getColor(initColor, this, tr("Background color")).rgb();
    l->setColor(color);
    l->setText(QString::number(color));
}

void DlgChartColor::on_btnSave_clicked()
{
    __s.setValue("reservecolor", ui->leReserveColor->text());
    __s.setValue("checkincolor", ui->leCheckinColor->text());
    __s.setValue("donotdisturbecolor", ui->leDoNotDisturbeColor->text());
    message_info(tr("The changes will applied in next time you logon"));
    accept();
}

void DlgChartColor::on_btnCancel_clicked()
{
    reject();
}

void DlgChartColor::on_chShowRoomDescription_clicked(bool checked)
{
    __s.setValue("showroomdescription", checked);
}
