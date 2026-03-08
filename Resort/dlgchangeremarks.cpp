#include "dlgchangeremarks.h"
#include "ui_dlgchangeremarks.h"

DlgChangeRemarks::DlgChangeRemarks(const QString &remarks, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DlgChangeRemarks)
{
    ui->setupUi(this);
    ui->ptRemarks->setPlainText(remarks);
}

DlgChangeRemarks::~DlgChangeRemarks()
{
    delete ui;
}

void DlgChangeRemarks::on_buttonBox_rejected()
{
    reject();
}

void DlgChangeRemarks::on_buttonBox_accepted()
{
    result = ui->ptRemarks->toPlainText();
}
