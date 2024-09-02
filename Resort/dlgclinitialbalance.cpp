#include "dlgclinitialbalance.h"
#include "ui_dlgclinitialbalance.h"
#include "vauchers.h"
#include "pprintvaucher.h"
#include "paymentmode.h"

DlgCLInitialBalance::DlgCLInitialBalance(const QString &code, QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgCLInitialBalance)
{
    ui->setupUi(this);
    ui->leText->setText(tr("C/L INITIAL BALANCE"));
    fCLCode = code;
    fTrackControl = new TrackControl(TRACK_VAUCHER);
    fTrackControl->addWidget(ui->deDate, "Date")
            .addWidget(ui->leAmount, "Amount")
            .addWidget(ui->leText, "Text")
            .addWidget(ui->rbCredit, "Credit/Debit");
}

DlgCLInitialBalance::~DlgCLInitialBalance()
{
    delete ui;
}

void DlgCLInitialBalance::openVaucher(const QString &id)
{
    DlgCLInitialBalance *d = new DlgCLInitialBalance(0, fPreferences.getDefaultParentForMessage());
    DoubleDatabase fDD;
    fDD[":f_id"] = id;
    fDD.exec("select * from m_register where f_id=:f_id");
    if (!fDD.nextRow()) {
        delete d;
        message_error(tr("Cannot open voucher"));
        return;
    }
    d->fCLCode = fDD.getValue("f_cityLedger").toString();
    d->ui->leVaucher->setText(id);
    d->ui->leAmount->setDouble(fDD.getValue("f_amountAmd").toDouble());
    d->ui->leText->setText(fDD.getValue("f_finalName").toString());
    d->ui->deDate->setDate(fDD.getValue("f_wdate").toDate());
    d->ui->rbCredit->setChecked(fDD.getValue("f_sign").toInt() == -1);
    d->fTrackControl->resetChanges();
    d->exec();
    delete d;
}

void DlgCLInitialBalance::on_btnCancel_clicked()
{
    reject();
}

void DlgCLInitialBalance::on_btnOk_clicked()
{
    QString source = VAUCHER_CL_INIT_N;
    if (ui->rbTC->isChecked()) {
        source = VAUCHER_TRANSFER_CL_N;
    }
    QString dc = "DEBIT";
    int sign = 1;
    if (ui->rbCredit->isChecked()) {
        dc = "CREDIT";
        sign = -1;
    }
    int item = 0;
    if (ui->rbTC->isChecked()) {
        item = 0;
    } else if (ui->rbCredit->isChecked()) {
        item = fPreferences.getDb(def_invoice_default_positive_transfer_id).toInt();
    } else {
        item = fPreferences.getDb(def_invoice_default_negative_transfer_id).toInt();
    }
    DoubleDatabase fDD;
    fDD.startTransaction();
    CacheCityLedger ccl;
    ccl.get(fCLCode);
    if (ui->leVaucher->isEmpty()) {
        QString rid = uuidx("CR");
        fDD.insertId("m_register", rid);
        ui->leVaucher->setText(rid);
        fDD[":f_source"] = source;
        fDD[":f_wdate"] = ui->deDate->date();
        fDD[":f_rdate"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_user"] = WORKING_USERID;
        fDD[":f_room"] = fCLCode;
        fDD[":f_guest"] = ccl.fName();
        fDD[":f_itemCode"] = item;
        fDD[":f_finalName"] = ui->leText->text();
        fDD[":f_amountAmd"] = ui->leAmount->asDouble();
        fDD[":f_amountVat"] = 0;
        fDD[":f_amountUsd"] = def_usd;
        fDD[":f_fiscal"] = 0;
        fDD[":f_paymentMode"] = PAYMENT_CREDIT;
        fDD[":f_creditCard"] = 0;
        fDD[":f_cityLedger"] = fCLCode;
        fDD[":f_paymentComment"] = ccl.fName();
        fDD[":f_dc"] = dc;
        fDD[":f_sign"] = sign;
        fDD[":f_doc"] = "";
        fDD[":f_rec"] = "";
        fDD[":f_inv"] = "";
        fDD[":f_finance"] = 1;
        fDD[":f_remarks"] = "";
        fDD[":f_canceled"] = 0;
        fDD[":f_cancelReason"] = "";
        fDD[":f_side"] = 0;
        fDD[":f_rb"] = 1;
    }
    fDD[":f_itemCode"] = ui->rbCredit->isChecked() ? fPreferences.getDb(def_invoice_default_positive_transfer_id) : fPreferences.getDb(def_invoice_default_negative_transfer_id);
    fDD[":f_amountAmd"] = ui->leAmount->asDouble();
    fDD[":f_wdate"] = ui->deDate->date();
    fDD[":f_finalName"] = ui->leText->text();
    fDD[":f_dc"] = ui->rbCredit->isChecked() ? "CREDIT" : "DEBIT";
    fDD[":f_sign"] = ui->rbCredit->isChecked() ? -1 : 1;
    fDD.update("m_register", where_id(ap(ui->leVaucher->text())));
    fTrackControl->saveChanges();
    fDD.commit();

    PPrintVaucher::printVaucher(ui->leVaucher->text());
    accept();
}
