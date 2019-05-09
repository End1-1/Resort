#include "wroomcharttemprectdlg.h"
#include "ui_wroomcharttemprectdlg.h"

WRoomChartTempRectDlg::WRoomChartTempRectDlg(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::WRoomChartTempRectDlg)
{
    ui->setupUi(this);
}

WRoomChartTempRectDlg::~WRoomChartTempRectDlg()
{
    delete ui;
}

void WRoomChartTempRectDlg::setDates(const QDate &d1, const QDate &d2)
{
    ui->deEntry->setDate(d1);
    ui->deDeparture->setDate(d2);
}

void WRoomChartTempRectDlg::on_btnCancel_clicked()
{
    reject();
}
