#include "dlgreservequickinfo.h"
#include "ui_dlgreservequickinfo.h"
#include "basewidget.h"
#include "winvoice.h"
#include "wreservation.h"
#include "dlggroupreservationfuck.h"

DlgReserveQuickInfo::DlgReserveQuickInfo(const QString &code, QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgReserveQuickInfo)
{
    fReservation.get(code);
    ui->setupUi(this);
    ui->btnOpenInvoice->setEnabled(fReservation.fState() == RESERVE_CHECKIN);
    ui->btnGroup->setEnabled(fReservation.fGroup() > 0);
    ui->tblData->setColumnWidth(0, 200);
    ui->tblData->setColumnWidth(1, 400);
    QList<QVariant> d;
    d << tr("Room") <<  "#" + fReservation.fRoom() + " [" + fReservation.fRoomShort() + "]";
    Utils::tableAppendRowData(ui->tblData, d);
    d.clear();
    d << tr("Guest") << fReservation.fGuest();
    Utils::tableAppendRowData(ui->tblData, d);
    d.clear();
    d << tr("Create date") << fReservation.fDateCreate();
    Utils::tableAppendRowData(ui->tblData, d);
    d.clear();
    d << tr("Entry date") << fReservation.fDateStart().toString(def_date_format);
    Utils::tableAppendRowData(ui->tblData, d);
    d.clear();
    d << tr("Departure date") << fReservation.fDateEnd().toString(def_date_format);
    Utils::tableAppendRowData(ui->tblData, d);
    d.clear();
    d <<  tr("Total nights") << QString::number(fReservation.fDateStart().daysTo(fReservation.fDateEnd()));
    Utils::tableAppendRowData(ui->tblData, d);
    d.clear();
    d << tr("Nights left") << QString::number(WORKING_DATE.daysTo(fReservation.fDateEnd()));
    Utils::tableAppendRowData(ui->tblData, d);
    d.clear();
    d << tr("Cardex") << "[" + fReservation.fCardex() + "] " + fReservation.fCardexName();
    Utils::tableAppendRowData(ui->tblData, d);
    d.clear();
    d << tr("Credit") << fReservation.fCredit();
    Utils::tableAppendRowData(ui->tblData, d);
    d.clear();
    d << tr("Debet") << fReservation.fDebet();
    Utils::tableAppendRowData(ui->tblData, d);
    d.clear();
    d << tr("Balance") << fReservation.fBalance();
    Utils::tableAppendRowData(ui->tblData, d);
}

DlgReserveQuickInfo::~DlgReserveQuickInfo()
{
    delete ui;
}

void DlgReserveQuickInfo::escapePressed()
{
    accept();
}

void DlgReserveQuickInfo::on_btnOpenInvoice_clicked()
{
    accept();
    WInvoice::openInvoiceWindow(fReservation.fInvoice());
}

void DlgReserveQuickInfo::on_btnOpenReserve_clicked()
{
    accept();
    WReservation::openReserveWindows(fReservation.fId());
}

void DlgReserveQuickInfo::on_btnGroup_clicked()
{
    accept();
    //WReservation::openReserveGroup(fReservation.fGroup());
    DlgGroupReservationFuck *d = addTab<DlgGroupReservationFuck>();
    d->loadGroup(fReservation.fGroup());
}
