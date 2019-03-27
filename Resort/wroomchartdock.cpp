#include "wroomchartdock.h"
#include "ui_wroomchartdock.h"
#include "wreservation.h"
#include "dlggroupreservationfuck.h"
#include "winvoice.h"

WRoomChartDock::WRoomChartDock(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::WRoomChartDock)
{
    ui->setupUi(this);
}

WRoomChartDock::~WRoomChartDock()
{
    delete ui;
}

void WRoomChartDock::setData(const QMap<QString, QString> &data)
{
    fReserveState = data["statuscode"].toInt();
    ui->lbStatus->setText(data["status"]);
    switch (fReserveState) {
    case RESERVE_RESERVE:
        ui->btnInvoice->setEnabled(false);
        ui->btnReserve->setEnabled(true);
        break;
    case RESERVE_CHECKIN:
        ui->btnInvoice->setEnabled(true);
        ui->btnReserve->setEnabled(true);
        break;
    default:
        ui->btnInvoice->setEnabled(false);
        ui->btnReserve->setEnabled(false);
        break;

    }
    ui->lbType->setText(data["type"]);
    ui->lbCode->setText(data["code"]);
    ui->lbInvoice->setText(data["invoice"]);
    ui->lbGuest->setText(data["guest"]);
    ui->lbEntryDate->setText(data["entrydate"]);
    ui->lbDepartureDate->setText(data["departuredate"]);
    fGroup = data["groupid"].toInt();
    ui->lbGroup->setText(fGroup == 0 ? tr("Individual") : QString("%1 (%2)").arg(fGroup).arg(data["groupname"]));
    ui->btnGroup->setEnabled(fGroup > 0);
}

void WRoomChartDock::on_btnReserve_clicked()
{
    WReservation::openReserveWindows(ui->lbCode->text());
}

void WRoomChartDock::on_btnInvoice_clicked()
{
    WInvoice::openInvoiceWindow(ui->lbInvoice->text());
}

void WRoomChartDock::on_btnGroup_clicked()
{
    DlgGroupReservationFuck::openGroup(fGroup);
}
