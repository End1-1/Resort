#include "dlgexportsinglevaucher.h"
#include "ui_dlgexportsinglevaucher.h"
#include "dlgremotinvoices.h"
#include "vauchers.h"

DlgExportSingleVaucher::DlgExportSingleVaucher(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgExportSingleVaucher)
{
    ui->setupUi(this);
    QStringList dbParams = fPreferences.getDb("AHC").toString().split(";", Qt::SkipEmptyParts);
    if (dbParams.count() < 4) {
        message_error(tr("Setup second database parameters"));
        return;
    }
    fSDb.setDatabase(dbParams[0], dbParams[1], dbParams[2], dbParams[3]);
    if (!fSDb.open()) {
        message_error(tr("Cannot connect to second database"));
        return;
    }
    connect(ui->leInvoice, SIGNAL(customButtonClicked(bool)), this, SLOT(showInvoices(bool)));
    fVoucher.open();
}

DlgExportSingleVaucher::~DlgExportSingleVaucher()
{
    delete ui;
}

void DlgExportSingleVaucher::setupVaucher(const QString &id)
{
    fVaucherId = id;
    fVoucher[":f_id"] = id;
    fVoucher.exec( "select * from m_register where f_id=:f_id");
    ui->leFinalName->setText(fVoucher.getValue(0, "f_finalName").toString());
    ui->leAmount->setText(float_str(fVoucher.getValue(0, "f_amountAmd").toDouble(), 2));
    ui->deDate->setDate(fVoucher.getValue(0, "f_wdate").toDate());
    ui->teTime->setTime(fVoucher.getValue(0, "f_time").toTime());
}

int DlgExportSingleVaucher::exportSingleVaucher(const QString &id)
{
    DlgExportSingleVaucher *d = new DlgExportSingleVaucher(fPreferences.getDefaultParentForMessage());
    d->setupVaucher(id);
    int result = d->exec();
    delete d;
    return result;
}

void DlgExportSingleVaucher::showInvoices(bool v)
{
    Q_UNUSED(v)
    DlgRemotInvoices *d = new DlgRemotInvoices(true, this);
    if (d->exec() == QDialog::Accepted) {
        ui->leInvoice->setText(d->fResult);
        on_leInvoice_returnPressed();
    }
    delete d;
}

void DlgExportSingleVaucher::on_btnCancel_clicked()
{
    reject();
}

void DlgExportSingleVaucher::on_btnOk_clicked()
{
    DoubleDatabase fDD;
    fSDb.startTransaction();
    fVoucher.getBindValues(0, fSDb.fBindValues);
    bool ps = fSDb[":f_source"].toString() == VAUCHER_POINT_SALE_N;
    bool pe = fSDb[":f_source"].toString() == VAUCHER_EVENT_N;
    QString id = fSDb[":f_id"].toString();
    fSDb[":f_inv"] = ui->leInvoice->text();
    fSDb[":f_room"] = ui->leRoom->text();
    fSDb[":f_guest"] = ui->leGuest->text();
    fSDb[":f_wdate"] = ui->deDate->date();
    fSDb[":f_rdate"] = ui->deDate->date();
    fSDb[":f_time"] = ui->teTime->time();
    fSDb[":f_finalName"] = ui->leFinalName->text();
    fSDb[":f_amountAmd"] = ui->leAmount->asDouble();
    if (!fSDb.insert("m_register", false)) {
        message_error(fSDb.fLastError);
        fSDb.rollback();
        return;
    }
    if (ps) {
        fDD.exec("select * from o_header where f_id=" + ap(id));
        fDD.getBindValues(0, fSDb.fBindValues);
        fSDb[":f_dateCash"] = ui->deDate->date();
        fSDb[":f_dateOpen"] = ui->deDate->date();
        fSDb[":f_dateClose"] = ui->deDate->date();
        fSDb[":f_roomComment"] = QString("%1, %2").arg(ui->leRoom->text())
                                 .arg(ui->leGuest->text());
        fSDb[":f_paymentModeComment"] = fDD[":f_roomComment"];
        if (!fSDb.insert("o_header", false)) {
            message_error(fSDb.fLastError);
            fSDb.rollback();
            return;
        }
        fDD.exec("select * from o_dish where f_header=" + ap(id));
        for (int i = 0; i < fDD.rowCount(); i++) {
            fDD.getBindValues(i, fSDb.fBindValues);
            if (!fSDb.insert("o_dish", false)) {
                message_error(fSDb.fLastError);
                fSDb.rollback();
                return;
            }
        }
    }
    if (pe) {
        fDD.exec("select * from o_event where f_id=" + ap(id));
        for (int i = 0; i < fDD.rowCount(); i++) {
            fDD.getBindValues(i, fSDb.fBindValues);
            fDD[":f_wdate"] = ui->deDate->date();
            fDD[":f_rdate"] = ui->deDate->date();
            fDD[":f_time"] = ui->teTime->time();
            if (!fSDb.insert("o_event", false)) {
                message_error(fSDb.fLastError);
                fSDb.rollback();
                return;
            }
        }
    }
    fDD[":p"] = 1;
    fDD.update("m_register", where_id(ap(fVaucherId)));
    fSDb.commit();
    message_info(tr("Exported successfully"));
    accept();
}

void DlgExportSingleVaucher::on_leInvoice_returnPressed()
{
    fSDb[":f_invoice"] = ui->leInvoice->text();
    fSDb.exec("select r.f_room, concat(g.f_firstName, ' ', g.f_lastName) "
              "from f_reservation r "
              "left join f_guests g on g.f_id=r.f_guest "
              "where r.f_invoice=:f_invoice");
    if (!fSDb.nextRow()) {
        message_error(tr("Invalid invoice number"));
        return;
    }
    ui->leRoom->setText(fSDb.getString(0));
    ui->leGuest->setText(fSDb.getString(1));
}
