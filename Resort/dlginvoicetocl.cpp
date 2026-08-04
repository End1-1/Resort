#include "dlginvoicetocl.h"
#include "ui_dlginvoicetocl.h"
#include "cachecityledger.h"
#include "message.h"
#include "paymentmode.h"
#include "trackcontrol.h"
#include "vauchers.h"

DlgInvoiceToCL::DlgInvoiceToCL(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgInvoiceToCL)
{
    ui->setupUi(this);
    ui->leCL->setSelector(this, cache(cid_city_ledger), ui->leCLName);
    fTrackControl = new TrackControl(TRACK_RESERVATION);
}

DlgInvoiceToCL::~DlgInvoiceToCL()
{
    delete ui;
}

bool DlgInvoiceToCL::transferDebt(const QString &invoice, QWidget *parent)
{
    if (invoice.isEmpty()) {
        message_error(tr("Invoice is not selected"));
        return false;
    }
    CacheInstance *ci = cache(cid_city_ledger);
    if (ci) {
        ci->load();
    }
    DlgInvoiceToCL d(parent ? parent : fPreferences.getDefaultParentForMessage());
    d.setInvoice(invoice);
    return d.exec() == QDialog::Accepted;
}

void DlgInvoiceToCL::setInvoice(const QString &invoice)
{
    ui->leInvoice->setText(invoice);
    DoubleDatabase dd;
    dd[":invoice"] = invoice;
    dd.exec("select r.f_room, concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName), "
            "r.f_cityLedger, cl.f_name, r.f_id "
            "from f_reservation r "
            "inner join f_guests g on g.f_id=r.f_guest "
            "left join f_city_ledger cl on cl.f_id=r.f_cityLedger "
            "where r.f_invoice=:invoice");
    if (!dd.nextRow()) {
        message_error(tr("Incorrect invoice number"));
        return;
    }
    ui->leRoom->setText(dd.getString(0));
    ui->leGuest->setText(dd.getString(1));
    ui->leFinalName->setText(QString("CHECKOUT %1, %2").arg(ui->leRoom->text(), ui->leGuest->text()));
    ui->leCL->setInitialValue(dd.getInt(2));
    ui->leReservation->setText(dd.getString(4));
    fTrackControl->fInvoice = invoice;
    fTrackControl->fReservation = ui->leReservation->text();

    // sum(amount*sign): charges (+1) - payments (-1). Positive = guest owes hotel.
    dd[":f_inv"] = invoice;
    dd.exec("select coalesce(sum(m.f_amountAmd * m.f_sign), 0) "
            "from m_register m "
            "where m.f_inv=:f_inv and m.f_canceled=0 and m.f_finance=1");
    double balance = 0;
    if (dd.nextRow()) {
        balance = dd.getDouble(0);
    }
    if (balance < 0.01) {
        balance = 0;
    }
    ui->leBalance->setDouble(balance);
    ui->leAmount->setDouble(balance);
}

void DlgInvoiceToCL::on_btnCancel_clicked()
{
    reject();
}

void DlgInvoiceToCL::on_btnSave_clicked()
{
    if (ui->leCL->asInt() == 0) {
        message_error(tr("City ledger is not selected"));
        return;
    }
    if (ui->leAmount->asDouble() < 0.01) {
        message_error(tr("Amount cannot be zero"));
        return;
    }
    if (ui->leFinalName->text().trimmed().isEmpty()) {
        message_error(tr("Final name cannot be empty"));
        return;
    }

    CacheCityLedger cl;
    if (!cl.get(ui->leCL->asInt())) {
        message_error(tr("Wrong cityledger code"));
        return;
    }

    int side = ui->rbCompany->isChecked() ? 1 : 0;
    QString finalName = ui->leFinalName->text().trimmed();
    QString modeName = QString("CHECKOUT %1").arg(cl.fName());
    QString rid = uuidx(VAUCHER_RECEIPT_N);

    DoubleDatabase fDD;
    fDD.insertId("m_register", rid);
    fDD[":f_source"] = VAUCHER_RECEIPT_N;
    fDD[":f_res"] = ui->leReservation->text();
    fDD[":f_wdate"] = WORKING_DATE;
    fDD[":f_rdate"] = QDate::currentDate();
    fDD[":f_time"] = QTime::currentTime();
    fDD[":f_user"] = WORKING_USERID;
    fDD[":f_room"] = ui->leRoom->text();
    fDD[":f_guest"] = ui->leGuest->text();
    fDD[":f_itemCode"] = fPreferences.getDb(def_receip_vaucher_id);
    fDD[":f_finalName"] = finalName;
    fDD[":f_amountAmd"] = ui->leAmount->asDouble();
    fDD[":f_amountVat"] = 0;
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = 0;
    fDD[":f_paymentMode"] = PAYMENT_CL;
    fDD[":f_creditCard"] = 0;
    fDD[":f_cityLedger"] = ui->leCL->asInt();
    fDD[":f_paymentComment"] = modeName;
    fDD[":f_dc"] = "CREDIT";
    fDD[":f_sign"] = -1;
    fDD[":f_doc"] = "";
    fDD[":f_rec"] = "";
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD[":f_finance"] = 1;
    fDD[":f_remarks"] = "";
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    fDD[":f_side"] = side;
    fDD[":f_cash"] = 0;
    fDD[":f_session"] = 0;
    fDD.update("m_register", where_id(ap(rid)));

    fTrackControl->fRecord = rid;
    fTrackControl->insert("Transfer debt to C/L", rid, finalName + " " + ui->leAmount->text() + " / " + cl.fName());
    fTrackControl->saveChanges();
    accept();
}
