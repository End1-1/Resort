#include "dlggposorderinfo.h"
#include "ui_dlggposorderinfo.h"
#include "cacherights.h"
#include "pprintreceipt.h"
#include "printtaxd.h"
#include "dlgdishhistory.h"
#include "cachepaymentmode.h"
#include "cacheinvoiceitem.h"
#include "dlgpaymentmode.h"
#include "paymentmode.h"
#include "cachetaxmap.h"
#include "dlgtracking.h"
#include <QPrintDialog>
#include <QPrinter>

DlgGPOSOrderInfo::DlgGPOSOrderInfo(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgGPOSOrderInfo)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                300, 80, 80, 0, 0, 0, 0, 30);
    ui->btnSave->setVisible(r__(cr__super_correction));
    ui->deDate->setReadOnly(!r__(cr__super_correction));
    ui->lePayment->setEnabled(r__(cr__super_correction));
    connect(ui->lePayment, SIGNAL(customButtonClicked(bool)), this, SLOT(selectPaymentMode(bool)));
    fTrackControl = new TrackControl(TRACK_REST_ORDER);
}

DlgGPOSOrderInfo::~DlgGPOSOrderInfo()
{
    delete ui;
}

void DlgGPOSOrderInfo::setOrder(const QString &id)
{
    ui->leOrder->setText(id);
    setWindowTitle(QString("%1 %2")
                   .arg(tr("Order"))
                   .arg(id));
    DoubleDatabase fDD;
    fDD[":f_header"] = id;
    fDD[":f_state"] = DISH_STATE_READY;
    fDD.exec("select d.f_" + def_lang + ", o.f_qty, o.f_total, o.f_id, "
               "o.f_adgt, d.f_id, o.f_price, '', if((o.f_complex=0 or (o.f_complex>0 and o.f_complexId>0)),0,1) "
               "from o_dish o "
               "inner join r_dish d on d.f_id=o.f_dish "
               "where o.f_header=:f_header and o.f_state=:f_state");
    Utils::fillTableWithData(ui->tblData, fDD.fDbRows);
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        ui->tblData->addButton(i, 7, SLOT(showDishHistory(int)), this, QIcon(":/images/update.png"));
    }
    fDD[":f_header"] = id;
    fDD.exec("select oh.f_dateCash, u.f_username, oh.f_paymentMode, oh.f_paymentModeComment, "
             "oh.f_comment from o_header oh "
               "inner join users u on u.f_id=oh.f_staff "
               "where oh.f_id=:f_header");
    if (fDD.rowCount() == 0) {
        message_info(tr("No order for this voucher"));
        return;
    }
    ui->deDate->setDate(fDD.fDbRows.at(0).at(0).toDate());
    ui->leStaff->setText(fDD.fDbRows.at(0).at(1).toString());
    ui->lePaymentComment->setText(fDD.fDbRows.at(0).at(3).toString());
    ui->lePayment->setText(fDD.fDbRows.at(0).at(2).toString());
    ui->leComment->setText(fDD.fDbRows.at(0).at(4).toString());
    CachePaymentMode pm;
    if (pm.get(ui->lePayment->text())) {
        ui->lePaymentName->setText(pm.fName());
    }
    countTotal();
}

void DlgGPOSOrderInfo::setVaucher(const QString &id)
{
    ui->leOrder->setText(id);
    DoubleDatabase fDD;
    fDD[":f_id"] = id;
    fDD.exec("select f_id from m_register where f_id=:f_id");
    if (fDD.nextRow()) {
        setOrder(fDD.getString(0));
    } else {
        setOrder(id);
    }
}

void DlgGPOSOrderInfo::selectPaymentMode(bool v)
{
    Q_UNUSED(v);
    int pm;
    int cl;
    QString oldPm = ui->lePayment->text();
    QString comment;
    if (DlgPaymentMode::getPayment(pm, comment, cl)) {
        CachePaymentMode ci;
        ci.get(pm);
        DoubleDatabase fDD;
        fDD[":f_paymentMode"] = pm;
        fDD[":f_paymentModeComment"] = comment;
        fDD[":f_cityLedger"] = cl;
        fDD.update("o_header", where_id(ap(ui->leOrder->text())));
        fTrackControl->insert("Payment mode changed ", oldPm, ci.fName());
        ui->lePayment->setText(ci.fCode());
        ui->lePaymentName->setText(ci.fName());
    }
}

void DlgGPOSOrderInfo::showDishHistory(int tag)
{
    QString dishId = ui->tblData->toString(tag, 3);
    DlgDishHistory *d = new DlgDishHistory(dishId, this);
    d->exec();
    delete d;
}

void DlgGPOSOrderInfo::on_btnOk_clicked()
{
    accept();
}

void DlgGPOSOrderInfo::on_btnSave_clicked()
{
    DoubleDatabase fDD;
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        fDD[":f_qty"] = ui->tblData->item(i, 1)->data(Qt::EditRole).toDouble();
        fDD[":f_total"] = ui->tblData->item(i, 2)->data(Qt::EditRole).toDouble();
        fDD.update("o_dish", where_id(ap(ui->tblData->item(i, 3)->data(Qt::EditRole).toString())));
        fDD[":f_id"] = ui->tblData->item(i, 3)->data(Qt::EditRole).toString();
        fDD.exec("update o_dish set f_price=:f_total/:f_qty where f_id=:f_id");
    }
    fDD[":f_dateCash"] = ui->deDate->date();
    fDD[":f_total"] = ui->leTotal->asDouble();
    fDD.update("o_header", where_id(ap(ui->leOrder->text())));
    fDD[":f_amountAmd"] = ui->leTotal->asDouble();
    fDD[":f_wdate"] = ui->deDate->date();
    fDD.update("m_register", where_id(ap(ui->leOrder->text())));
    message_info(tr("Saved"));
}

void DlgGPOSOrderInfo::countTotal()
{
    double total = 0;
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        total += ui->tblData->item(i, 2)->data(Qt::EditRole).toDouble();
    }
    ui->leTotal->setDouble(total);
}

void DlgGPOSOrderInfo::on_tblData_currentItemChanged(C5TableWidgetItem *current, C5TableWidgetItem *previous)
{
    Q_UNUSED(current)
    Q_UNUSED(previous)
    countTotal();
}

void DlgGPOSOrderInfo::on_btnPrint_clicked()
{
    QPrinter p;
    QPrintDialog pd(&p, this);
    if (pd.exec() != QDialog::Accepted) {
        return;
    }
    PPrintReceipt::printOrder(p.printerName(), ui->leOrder->text(), WORKING_USERID);
}

void DlgGPOSOrderInfo::on_btnPrintTax_clicked()
{
    DoubleDatabase fDD;
    fDD[":f_id"] = ui->leOrder->text();
    fDD.exec("select f_paymentMode from o_header where f_id=:f_id");
    fDD.nextRow();
    CachePaymentMode cpm;
    cpm.get(fDD.getString(0));

    QString taxDept;
    fDD[":f_id"] = ui->leOrder->text();
    fDD.exec("select f_itemCode from m_register where f_id=:f_id");
    if (!fDD.nextRow()) {
        return;
    }

    CacheInvoiceItem ci;
    ci.get(fDD.getString(0));
    taxDept = ci.fVatDept();
    if (fPreferences.getDb(def_tax_port).toInt() == 0) {
        message_error(tr("Setup tax printer first"));
        return;
    }
    CacheTaxMap cm;
    if (!cm.get(ci.fCode())) {
            return;
    }
    PrintTaxD *pt = new PrintTaxD(cm.fTax(), this);
    double total = 0;
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        if (ui->tblData->toInt(i, 8) == 1) {
            continue;
        }
        total += ui->tblData->toDouble(i, 2);
        pt->fRecList.append(ui->tblData->toString(i, 3));
        pt->fDept.append(taxDept);
        pt->fAdgCode.append(ui->tblData->toString(i, 4));
        pt->fCodeList.append(ui->tblData->toString(i, 5));
        pt->fNameList.append(ui->tblData->toString(i, 0));
        pt->fQtyList.append(QString::number(ui->tblData->toDouble(i, 1), 'f', 2));
        pt->fPriceList.append(QString::number(ui->tblData->toDouble(i, 6), 'f', 2));
        pt->fTaxNameList.append(ui->tblData->toString(i, 0));
    }
    fDD[":f_tax"] = 1;
    fDD.update("o_header", where_id(ap(ui->leOrder->text())));
    fDD[":f_fiscal"] = 1;
    fDD[":f_id"] = ui->leOrder->text();
    fDD.exec("update m_register set f_fiscal=1 where f_id=:f_id");
    pt->fInvoice = ui->leOrder->text();
    pt->build();
    pt->fAmountCash = QString::number(ui->leTotal->asDouble() - ui->leCardAmount->asDouble(), 'f', 2);
    pt->fAmountCard = QString::number(ui->leCardAmount->asDouble(), 'f',  2);
    pt->print();
    delete pt;
}

void DlgGPOSOrderInfo::on_btnTracking_clicked()
{
    DlgTracking::showTracking(TRACK_REST_ORDER, ui->leOrder->text());
}
