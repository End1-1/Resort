#include "waccinvoice.h"
#include "ui_waccinvoice.h"
#include "dlgtracking.h"
#include "wreportgrid.h"
#include "pprintinvoice.h"
#include "dlginvoiceprintoption.h"
#include "cacheinvoiceitem.h"
#include "vauchers.h"
#include "cachecardex.h"
#include "cachevatmode.h"
#include "dlgprinttaxsideoption.h"
#include "dlgsearchinvoice.h"
#include "printtaxd.h"
#include "cachetaxmap.h"
#include "dlgtaxback.h"
#include "dlgviewinvoicecorrections.h"
#include "cachecheckoutinvoice.h"
#include "pexportinvoicetoexcel.h"
#include "frestauranttotal.h"
#include "dlgchartdaterange.h"
#include "dlghdmviewer.h"
#include "dlgreservationguests.h"
#include "dlgpostcharge.h"
#include "dlgcl.h"
#include "wreservation.h"
#include "dlgremotinvoices.h"
#include "dlgreserveshortinfo.h"
#include "dlgselectfiscalmachin.h"
#include "dlgmovetocl.h"
#include "wvauchereditor.h"
#include "dlgexportas.h"
#include <QSqlRecord>
#include <QInputDialog>

#define sel_invoice 1
#define sel_cardex 2
#define sel_vat_mode 3

WAccInvoice::WAccInvoice(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WAccInvoice)
{
    ui->setupUi(this);
    ui->tblTotal->addRow();
    ui->tblTotal->addRow();
    for (int i = 0 ; i < ui->tblTotal->columnCount(); i++) {
        for (int j = 0; j < 2; j++)
            ui->tblTotal->setItemWithValue(j, i, QVariant());
    }
    fDb.open();
    ui->leReservationId->setVisible(false);
    ui->deCheckIn->setReadOnly(!r__(cr__super_correction));
    ui->deDeparture->setReadOnly(!r__(cr__super_correction));
    ui->btnEliminate->setVisible(r__(cr__super_correction));
    ui->btnPostingCharges->setVisible(r__(cr__super_correction) && false);
    ui->btnMoveItem->setVisible(r__(cr__super_correction));
    ui->btnNewVaucher->setVisible(r__(cr__super_correction));
    ui->btnEditReserv->setVisible(r__(cr__super_correction));
    ui->btnEditRowVaucher->setVisible(r__(cr__super_correction));
    ui->btnMoveToCL->setVisible(r__(cr__super_correction));
    ui->btnExcel->setVisible(r__(cr__invoice_export_to_excel));
    fCurrentInvoicePosition = -1;
    fReport = dynamic_cast<WReportGrid *>(parent);
    if (fReport) {
        connect(fReport, SIGNAL(doubleClickOnRow(QList<QVariant>)), this, SLOT(handleValues(QList<QVariant>)));
    }
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                0, 30, 90, 0, 250, 80, 80, 80, 80, 30, 0, 0);
    Utils::tableSetColumnWidths(ui->tblTotal, ui->tblTotal->columnCount(),
                                0, 30, 90, 0, 250, 80, 80, 80, 80, 30, 0, 0);
    ui->leInvoice->setSelector(this, cache(cid_checkout_invoice), ui->leInvoice, sel_invoice);
    fTrackControl = new TrackControl(TRACK_RESERVATION);
    fTrackControl->addWidget(ui->deCheckIn, "Check in date");
    fTrackControl->addWidget(ui->deDeparture, "Departure date");
    ui->leCardexCode->setSelector(this, cache(cid_cardex), ui->leCardex, sel_cardex);
    ui->leVatCode->setSelector(this, cache(cid_vat_mode), ui->leVATMode, sel_vat_mode);
    ui->leCardexCode->setEnabled(r__(cr__super_correction));
    ui->leVatCode->setEnabled(r__(cr__super_correction));
    ui->btnTracking->setVisible(fPreferences.getDb(def_show_logs).toBool());
    ui->btnExportAS->setVisible(r__(cr__export_data_to_as));
    ui->btnExportASRetail->setVisible(r__(cr__export_data_to_as));
}

WAccInvoice::~WAccInvoice()
{
    delete ui;
    fDb.close();
}

void WAccInvoice::openInvoice(const QString &invoice)
{
    WAccInvoice *w = nullptr;
    for (int i = 0; i < fMainWindow->fTab->count(); i++) {
        w = dynamic_cast<WAccInvoice *>(fMainWindow->fTab->widget(i));
        if (w) {
            if (w->invoice() == invoice) {
                fMainWindow->fTab->setCurrentIndex(i);
                return;
            }
        }
    }
    w = addTab<WAccInvoice>();
    w->load(invoice);
}

void WAccInvoice::setupTab()
{
    setupTabTextAndIcon(tr("Invoice"), ":/images/invoice.png");
}

void WAccInvoice::callback(int sel, const QString &code)
{
    DoubleDatabase fDD;
    switch (sel) {
        case sel_invoice: {
            CacheCheckoutInvoice c;
            if (c.get(code)) {
                ui->leInvoice->setText(c.fCode());
                on_leInvoice_returnPressed();
            }
            break;
        }
        case sel_cardex: {
            CacheCardex c;
            if (c.get(code) && code != fOldCardexCode) {
                if (message_confirm(tr("Change the cardex?")) == QDialog::Accepted) {
                    fOldCardex = c.fName();
                    fOldCardexCode = code;
                    fDD[":f_cardex"] = c.fCode();
                    fDD.update("f_reservation", where_id(ap(ui->leReservationId->text())));
                    fTrackControl->insert(TRACK_RESERVATION, "Cardex changed", fOldCardex, ui->leCardex->text());
                    //fTrackControl->saveChanges(ui->leReservationId->text());
                }
            }
            break;
        }
        case sel_vat_mode: {
            CacheVatMode c;
            if (c.get(code) && code != fOldVATCode) {
                if (message_confirm(tr("Change the VAT mode?")) == QDialog::Accepted) {
                    fOldVAT = ui->leVATMode->text();
                    fOldVATCode = code;
                    fDD[":f_vatMode"] = c.fCode().toInt();
                    fDD.update("f_reservation", where_id(ap(ui->leReservationId->text())));
                    fTrackControl->insert("VAT mode",  fOldVAT, ui->leVATMode->text());
                }
            }
            break;
        }
    }
}

bool WAccInvoice::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        if (ui->leInvoice->hasFocus()) {
            load(ui->leInvoice->text());
            return QWidget::event(event);
        }
    }
    return BaseWidget::event(event);
}

QString WAccInvoice::invoiceId()
{
    return ui->leInvoice->text();
}

void WAccInvoice::load(const QString &id)
{
    disconnect(ui->deEntry, SIGNAL(userDateChanged(QDate)), this, SLOT(on_deEntry_userDateChanged(QDate)));
    disconnect(ui->deDeparture, SIGNAL(userDateChanged(QDate)), this, SLOT(on_deDeparture_userDateChanged(QDate)));
    setupTabTextAndIcon(tr("Invoice") + " #?", ":/images/invoice.png");
    ui->tblData->setRowCount(0);
    ui->leInvoice->setText(id);
    ui->leInvoice->fHiddenText = id;
    fDb[":f_id"] = id;
    QString query = "select r.f_startDate, r.f_endDate, r.f_checkInDate, r.f_checkInTime, "
                    "r.f_checkOutTime, rc.f_short, r.f_room, ra.f_" + def_lang + ", "
                    "concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName), n.f_name, "
                    "concat(u1.f_firstName, ' ', u1.f_lastName), concat(u2.f_firstName, ' ', u2.f_lastName), "
                    "r.f_cardex,  "
                    "r.f_man + r.f_woman + r.f_child, r.f_id, r.f_vatMode, r.f_remarks, r.f_state "
                    "from f_reservation r "
                    "left join f_room rm on rm.f_id=r.f_room "
                    "left join f_room_classes rc on rc.f_id=rm.f_class "
                    "left join f_room_arrangement ra on ra.f_id=r.f_arrangement "
                    "left join f_guests g on g.f_id=r.f_guest "
                    "left join f_nationality n on n.f_short=g.f_nation "
                    "left join users u1 on u1.f_id=r.f_checkInUser "
                    "left join users u2 on u2.f_id=r.f_checkOutUser "
                    "left join f_cardex c on r.f_cardex=c.f_cardex "
                    "where r.f_invoice=:f_id";
    fDb.exec(query);
    if (!fDb.nextRow()) {
        message_error(tr("Incorrect invoice number, or end reached"));
        return;
    }
    /* NEXT PREV
    if (fDbRows.at(0).at(17).toInt() != RESERVE_CHECKOUT) {
        if (next == 0) {
            message_error_tr("This invoice available only from room chart");
            return;
        }
        id += next;
        load(id);
        return;
    }
    */
    int c = 0;
    QList<QList<QVariant> > &fDbRows = fDb.fDbRows;
    ui->deEntry->setDate(fDbRows.at(0).at(c++).toDate());
    ui->deDeparture->setDate(fDbRows.at(0).at(c++).toDate());
    ui->deCheckIn->setDate(fDbRows.at(0).at(c++).toDate());
    ui->teCheckInTime->setTime(fDbRows.at(0).at(c++).toTime());
    ui->teCheckOutTime->setTime(fDbRows.at(0).at(c++).toTime());
    ui->leCategory->setText(fDbRows.at(0).at(c++).toString());
    ui->leRoom->setText(fDbRows.at(0).at(c++).toString());
    ui->leArrangment->setText(fDbRows.at(0).at(c++).toString());
    ui->leGuest->setText(fDbRows.at(0).at(c++).toString());
    ui->leNationality->setText(fDbRows.at(0).at(c++).toString());
    ui->leOperatorIn->setText(fDbRows.at(0).at(c++).toString());
    ui->leOperatorOut->setText(fDbRows.at(0).at(c++).toString());
    fOldCardexCode = fDbRows.at(0).at(c++).toString();
    ui->leCardexCode->setInitialValue(fOldCardexCode);
    ui->leGuestCount->setText(fDbRows.at(0).at(c++).toString());
    ui->leReservationId->setText(fDbRows.at(0).at(c++).toString());
    fOldVATCode = fDbRows.at(0).at(c++).toString();
    ui->leVatCode->setInitialValue(fOldVATCode);
    ui->teRemarks->setPlainText(fDbRows.at(0).at(c++).toString());
    CacheVatMode v;
    if (v.get(ui->leVATMode->fHiddenText)) {
        ui->leVATMode->setText(v.fName());
    }
    query = "select m.f_id, m.f_sign, m.f_wdate, m.f_itemcode, if(m.f_cityledger>0, m.f_paymentcomment, m.f_finalName), "
            "m.f_amountAmd, m.f_amountVat, m.f_fiscal, if(m.f_side=0,'G', 'C'), m.f_source, m.f_id "
            "from m_register m "
            "where m.f_inv=" + ap(ui->leInvoice->text()) + " " +
            "and m.f_canceled=0 and m.f_finance in (:fin) "
            "order by m.f_wdate, m.f_time ";
    if (ui->chViewAllVauchers->isChecked()) {
        query.replace(":fin", "0,1");
    } else {
        query.replace(":fin", "1");
    }
    fDb.exec(query);
    viewEntries();
    setupTabTextAndIcon(tr("Invoice") + " S/N " + id, ":/images/invoice.png");
    fTrackControl->fInvoice = ui->leInvoice->text();
    fTrackControl->fReservation = ui->leReservationId->text();
    fTrackControl->resetChanges();
    connect(ui->deEntry, SIGNAL(userDateChanged(QDate)), this, SLOT(on_deEntry_userDateChanged(QDate)));
    connect(ui->deDeparture, SIGNAL(userDateChanged(QDate)), this, SLOT(on_deDeparture_userDateChanged(QDate)));
    fOldCardex = ui->leCardex->text();
    fOldVAT = ui->leVATMode->text();
}

QString WAccInvoice::invoice()
{
    return ui->leInvoice->text();
}

void WAccInvoice::viewEntries()
{
    QFont f(qApp->font());
    f.setBold(true);
    QList<QList<QVariant> > proxyData;
    while (fDb.nextRow()) {
        if (!ui->chPaymentByGuest->isChecked()) {
            if (fDb.getString(8) == "G") {
                continue;
            }
        }
        if (!ui->chPaymentByCompany->isChecked()) {
            if (fDb.getString(8) == "C") {
                continue;
            }
        }
        if (ui->rbEntryName->isChecked()) {
            bool found = false;
            for (QList<QList<QVariant> >::iterator row = proxyData.begin(); row != proxyData.end(); row++) {
                if (row->at(3).toInt() == fDb.getInt(3) && row->at(1).toInt() == fDb.getInt(1)) {
                    if (row->at(1).toInt() == 1) {
                        ( *row)[5] = row->at(5).toDouble() + fDb.getDouble(5);
                    } else if (row->at(1).toInt() == -1) {
                        ( *row)[5] = row->at(5).toDouble() + fDb.getDouble(5);
                    }
                    ( *row)[6] = row->at(6).toDouble() + fDb.getDouble(6);
                    found = true;
                }
            }
            if (!found) {
                proxyData.append(fDb.row());
                proxyData[proxyData.count() - 1][2] = ui->deDeparture->date();
            }
        } else {
            proxyData.append(fDb.row());
        }
    }
    ui->tblData->setRowCount(proxyData.count());
    int row = 0;
    foreach (QList<QVariant> rowData, proxyData) {
        //rec id - 0
        ui->tblData->setItem(row, 0, Utils::tableItem(rowData.at(0)));
        //selection - 1
        C5TableWidgetItem *item = new C5TableWidgetItem();
        item->setData(Qt::UserRole, rowData.at(1));
        item->setCheckState(Qt::Checked);
        ui->tblData->setItem(row, 1, item);
        //date - 2
        ui->tblData->setItem(row, 2, Utils::tableItem(rowData.at(2), rowData.at(2)));
        //item code - 3
        ui->tblData->setItem(row, 3, Utils::tableItem(rowData.at(3)));
        //item - 4
        ui->tblData->setItem(row, 4, Utils::tableItem(rowData.at(4)));
        //debit, depended on second field - 5
        if (rowData.at(1).toInt() == 1) {
            ui->tblData->setItem(row, 5, Utils::tableItem(rowData.at(5)));
        } else {
            ui->tblData->setItem(row, 5, Utils::tableItem(0));
        }
        //credit, depended on second field - 6
        if (rowData.at(1).toInt() == -1) {
            ui->tblData->setItem(row, 6, Utils::tableItem(rowData.at(5)));
        } else {
            ui->tblData->setItem(row, 6, Utils::tableItem(0));
        }
        //vat - 7
        ui->tblData->setItem(row, 7, Utils::tableItem(rowData.at(6)));
        //tax - 8
        C5TableWidgetItem *itemTax = new C5TableWidgetItem(rowData.at(7).toString());
        itemTax->setFlags(itemTax->flags() ^Qt::ItemIsUserCheckable);
        itemTax->setCheckState(rowData.at(7).toInt() == 0  ? Qt::Unchecked : Qt::Checked);
        ui->tblData->setItem(row, 8, itemTax);
        //side - 9
        ui->tblData->setItem(row, 9, Utils::tableItem(rowData.at(8).toString()));
        // source - 10
        ui->tblData->setItem(row, 10, Utils::tableItem(rowData.at(9).toString()));
        // source id - 11
        ui->tblData->setItem(row, 11, Utils::tableItem(rowData.at(10).toString()));
        if (rowData.at(1).toInt() < 0) {
            for (int i = 0; i < ui->tblData->columnCount(); i++) {
                ui->tblData->item(row, i)->setFont(f);
            }
        }
        row++;
    }
    countAmounts();
}

void WAccInvoice::countAmounts()
{
    double debet = 0, credit = 0, vat = 0;
    for (int i = 0, count = ui->tblData->rowCount(); i < count; i++) {
        debet += ui->tblData->toDouble(i, 5);
        credit += ui->tblData->toDouble(i, 6);
        vat += ui->tblData->toDouble(i, 7);
    }
    ui->tblTotal->setItem(0, 5, Utils::tableItem(debet));
    ui->tblTotal->setItem(0, 6, Utils::tableItem(credit));
    ui->tblTotal->setItem(0, 7, Utils::tableItem(vat));
    ui->tblTotal->setItem(1, 4, Utils::tableItem(tr("Balance")));
    ui->tblTotal->setItem(1, 5, Utils::tableItem(credit - debet));
}

void WAccInvoice::correctCOCL()
{
    DoubleDatabase fDD;
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD[":f_source"] = VAUCHER_RECEIPT_N;
    fDD.exec("select f_cityLedger, sum(f_amountAmd*f_sign) from m_register where f_cityLedger>0 and f_inv=:f_inv and f_source=:f_source and f_canceled=0");
    int cl = 0;
    double amount = 0;
    if (fDD.nextRow()) {
        cl = fDD.getInt(0);
        amount = fDD.getDouble(1);
    }
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD.exec("select f_id from m_register where f_inv=:f_inv and lower(f_finalName) like 'checkout c/l%' and f_source='CO'");
    QString f_id;
    if (fDD.nextRow()) {
        f_id = fDD.getString(0);
    }
    if (f_id.isEmpty()) {
        if (cl > 0) {
            QString cid = uuidx(VAUCHER_CHECKOUT_N);
            fDD.insertId("m_register", cid);
            fDD[":f_source"] = VAUCHER_CHECKOUT_N;
            fDD[":f_wdate"] = WORKING_DATE;
            fDD[":f_rdate"] = QDate::currentDate();
            fDD[":f_time"] = QTime::currentTime();
            fDD[":f_user"] = WORKING_USERID;
            fDD[":f_room"] = ui->leRoom->text();
            fDD[":f_guest"] = ui->leGuest->text();
            fDD[":f_itemCode"] = 38;
            fDD[":f_finalName"] = tr("CHECKOUT C/L ") + cid;
            fDD[":f_amountAmd"] = amount;
            fDD[":f_amountVat"] = 0;
            fDD[":f_amountUsd"] = def_usd;
            fDD[":f_fiscal"] = 0;
            fDD[":f_paymentMode"] = 0;
            fDD[":f_creditCard"] = 0;
            fDD[":f_cityLedger"] = cl;
            CacheCityLedger cc;
            cc.get(cl);
            fDD[":f_paymentComment"] = cc.fName();
            fDD[":f_dc"] = "DEBIT";
            fDD[":f_sign"] = 1;
            fDD[":f_doc"] = "";
            fDD[":f_rec"] = "";
            fDD[":f_inv"] = ui->leInvoice->text();
            fDD[":f_finance"] = 0;
            fDD[":f_remarks"] = "";
            fDD[":f_canceled"] = 0;
            fDD[":f_cancelReason"] = "";
            fDD[":f_side"] = 0;
            fDD.update("m_register", where_id(ap(cid)));
        }
    } else {
        fDD[":f_finalName"] = tr("CHECKOUT C/L ") + f_id;
        fDD[":f_amountAmd"] = amount;
        fDD[":f_id"] = f_id;
        fDD.exec("update m_register set f_finalName=:f_finalName, f_amountAmd=:f_amountAmd where f_id=:f_id");
    }
}

void WAccInvoice::handleValues(const QList<QVariant> &values)
{
    if (values.count() == 0) {
        return;
    }
    WAccInvoice *ai = nullptr;
    for (int i = 0, count = fMainWindow->fTab->count(); i < count; i++) {
        ai = dynamic_cast<WAccInvoice *>(fMainWindow->fTab->widget(i));
        if (ai) {
            if (ai->invoiceId() == values.at(0).toString()) {
                fMainWindow->fTab->setCurrentWidget(ai);
                return;
            }
        }
    }
    ai = addTab<WAccInvoice>();
    ai->load(values.at(0).toString());
}

void WAccInvoice::on_btnTracking_clicked()
{
    DlgTracking::showTracking(TRACK_RESERVATION, ui->leInvoice->text());
}

void WAccInvoice::on_rbEntryName_clicked()
{
    viewEntries();
}

void WAccInvoice::on_rbNoGroup_clicked()
{
    viewEntries();
}

void WAccInvoice::on_chPaymentByGuest_clicked()
{
    viewEntries();
}

void WAccInvoice::on_chPaymentByCompany_clicked()
{
    viewEntries();
}

void WAccInvoice::on_btnPrint_clicked()
{
    QStringList ids;
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        if (ui->tblData->item(i, 1)->checkState() == Qt::Checked) {
            ids << ui->tblData->toString(i, 0);
        }
    }
    if (!r__(cr__print_partial_invoice)) {
        ids.clear();
    }
    QString curr;
    double rate;
    bool printMeal;
    switch (DlgInvoicePrintOption::getOption(curr, rate, printMeal)) {
        case pio_none:
            break;
        case pio_guest:
            PPrintInvoice(ui->leInvoice->text(), 0, ids, false, curr, rate, printMeal, this);
            break;
        case pio_comp:
            PPrintInvoice(ui->leInvoice->text(), 1, ids, false, curr, rate, printMeal, this);
            break;
        case pio_guestcomp_ser:
            PPrintInvoice(ui->leInvoice->text(), 0, ids, false, curr, rate, printMeal, this);
            PPrintInvoice(ui->leInvoice->text(), 1, ids, false, curr, rate, printMeal, this);
            break;
        case pio_guestcomp_tog:
            PPrintInvoice(ui->leInvoice->text(), -1, ids, false, curr, rate, printMeal, this);
            break;
    }
}

void WAccInvoice::on_btnTaxPrint_clicked()
{
    QString side;
    int result = DlgPrintTaxSideOption::printTaxSide();
    switch (result) {
        case pts_none:
            return;
        case pts_guest:
            side = "G";
            break;
        case pts_company:
            side = "C";
            break;
    }
    //SET TAX MACHINES
    QSet<int> taxs;
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        if (!isTaxPay(ui->tblData->toString(i, 10))) {
            continue;
        }
        if (ui->tblData->itemChecked(i, 8)) {
            continue;
        }
        if (ui->tblData->toString(i, 9) != side) {
            continue;
        }
        CacheInvoiceItem c;
        if (!c.get(ui->tblData->toString(i, 3))) {
            message_error(tr("Error in tax print. c == 0, case 1."));
            continue;
        }
        CacheTaxMap ci;
        if (!ci.get(c.fCode())) {
            message_error(tr("Tax department undefined for ") + c.fName());
            return;
        }
        taxs.insert(ci.fTax());
    }
    int taxnumber = 0;
    if (taxs.count() == 1) {
        taxnumber = taxs.values().at(0);
    } else {
        DlgSelectFiscalMachin ds(taxs, this);
        ds.exec();
        taxnumber = ds.fSelectedMachine;
    }
    if (taxnumber == 0) {
        return;
    }
    PrintTaxD *pt =  new PrintTaxD(taxnumber, this);
    pt->fInvoice = ui->leInvoice->text();
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        if (!isTaxPay(ui->tblData->toString(i, 10))) {
            continue;
        }
        if (ui->tblData->itemChecked(i, 8)) {
            continue;
        }
        if (ui->tblData->toString(i, 9) != side) {
            continue;
        }
        //HOTEL SOURCE
        if (ui->tblData->toString(i, 10) != VAUCHER_POINT_SALE_N ) {
            CacheInvoiceItem c;
            if (!c.get(ui->tblData->toString(i, 3))) {
                message_error(tr("Error in tax print. c == 0, case 1."));
                continue;
            }
            CacheTaxMap ci;
            if (!ci.get(c.fCode())) {
                message_error(tr("Tax department undefined for ") + c.fName());
                return;
            }
            if (ci.fTax() != taxnumber) {
                continue;
            }
            QString qty = "1";
            QString price = QString::number(ui->tblData->toDouble(i, 5), 'f', 2);
            if (c.fCode() == fPreferences.getDb(def_auto_breakfast_id).toString()) {
                DoubleDatabase drb;
                drb[":f_id"] = ui->tblData->toString(i, 0);
                drb.exec("select * from o_breakfast where f_id=:f_id");
                if (!drb.nextRow()) {
                    message_error(tr("Cannot find breakfast record. Contact to application developer."));
                    continue;
                }
                qty = drb.getValue("f_pax").toString();
                price = drb.getValue("f_price").toString();
            }
            pt->fDept.append(ui->leVatCode->asInt() == VAT_INCLUDED ? c.fVatDept() : c.fNoVatDept());
            pt->fRecList.append(ui->tblData->toString(i, 0));
            pt->fCodeList.append(c.fCode());
            pt->fNameList.append(c.fTaxName());
            pt->fPriceList.append(price);
            pt->fQtyList.append(qty);
            pt->fAdgCode.append(c.fAdgt());
            pt->fTaxNameList.append(c.fTaxName());
        } else if (ui->tblData->toString(i, 10) == VAUCHER_POINT_SALE_N ) {
            //RESTAURANT SOURCE
            QString orderId = ui->tblData->toString(i, 11);
            CacheInvoiceItem c;
            if (!c.get(ui->tblData->toString(i, 3))) {
                message_error(tr("Error in tax print. c == 0, case 2."));
                continue;
            }
            CacheTaxMap ci;
            if (!ci.get(c.fCode())) {
                message_error(tr("Tax department undefined for ") + c.fName());
                return;
            }
            if (ci.fTax() != taxnumber) {
                continue;
            }
            DoubleDatabase fDD;
            fDD[":f_header"] = orderId;
            fDD[":f_state"] = DISH_STATE_READY;
            fDD.exec("select d.f_id, d.f_am, d.f_adgt, od.f_qty, od.f_price "
                     "from o_dish od "
                     "inner join r_dish d on d.f_id=od.f_dish "
                     "where od.f_header=:f_header and od.f_state=:f_state "
                     "and (od.f_complex=0 or (od.f_complex>0 and od.f_complexId>0)) ");
            while (fDD.nextRow()) {
                QString vatReception = c.fVatDept();
                if (!c.fVatReception().isEmpty()) {
                    vatReception = c.fVatReception();
                }
                pt->fDept.append(ui->leVatCode->asInt() == VAT_INCLUDED ? c.fVatDept() : c.fNoVatDept());
                pt->fRecList.append(ui->tblData->toString(i, 0));
                pt->fCodeList.append(fDD.getString(0));
                pt->fNameList.append(fDD.getString(1));
                pt->fPriceList.append(fDD.getString(4));
                pt->fQtyList.append(fDD.getString(3));
                pt->fAdgCode.append(fDD.getString(2));
                pt->fTaxNameList.append(fDD.getString(1));
            }
        }
    }
    pt->build();
    if (pt->fRecList.count() > 0) {
        pt->exec();
    } else {
        message_info(tr("Nothing to print"));
    }
    delete pt;
    load(ui->leInvoice->text());
}

void WAccInvoice::on_leInvoice_returnPressed()
{
    load(ui->leInvoice->text());
}

void WAccInvoice::on_btnTaxBack_clicked()
{
    QList<QList<QVariant> > rows;
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        if (ui->tblData->item(i, 8)->checkState() == Qt::Checked) {
            QList<QVariant> row;
            row << ui->tblData->toString(i, 0)
                << ui->tblData->toString(i, 4)
                << (ui->tblData->toInt(i, 9) == 0 ? ui->tblData->toDouble(i, 5) : ui->tblData->toDouble(i, 6))
                << ui->tblData->toString(i, 10)
                << "";
            rows << row;
        }
    }
    DlgTaxBack::taxBack(ui->leInvoice->text(), rows);
    load(ui->leInvoice->text());
}

void WAccInvoice::on_btnViewCorrections_clicked()
{
    DlgViewInvoiceCorrections *d = new DlgViewInvoiceCorrections(ui->leInvoice->text(), this);
    d->exec();
    delete d;
}

void WAccInvoice::on_btnEliminate_clicked()
{
    DoubleDatabase fDD;
    QModelIndexList rows = ui->tblData->selectionModel()->selectedRows();
    if (rows.count() == 0 && ui->tblData->rowCount() == 0) {
        if (message_confirm(tr("<b>This operation cannot be undon, continue?<b>")) != QDialog::Accepted) {
            return;
        }
        QStringList guestToDelete;
        DoubleDatabase dbGuest;
        dbGuest.open();
        dbGuest[":f_id"] = ui->leReservationId->text();
        dbGuest.exec("select f_guest from f_reservation where f_id=:f_id union select f_guest from f_reservation_guests where f_reservation=:f_id");
        for (int i = 0; i < dbGuest.rowCount(); i++) {
            bool found = false;
            fDD[":f_guest"] = dbGuest.getValue(i, 0);
            fDD[":f_reservation"] = ui->leReservationId->text();
            fDD.exec("select * from f_reservation where f_guest=:f_guest and f_id<>:f_reservation");
            found = fDD.nextRow();
            if (!found) {
                fDD[":f_guest"] = dbGuest.getValue(i, 0);
                fDD[":f_reservation"] = ui->leReservationId->text();
                fDD.exec("select * from f_reservation_guests where f_guest=:f_guest and f_reservation<>:f_reservation");
                found = fDD.nextRow();
            }
            if (!found) {
                guestToDelete << dbGuest.getString(i, 0);
            }
        }
        foreach (QString s, guestToDelete) {
            fDD[":f_id"] = s;
            fDD.exec("delete from f_guests where f_id=:f_id");
        }
        fDD[":f_inv"] = ui->leInvoice->text();
        fDD.exec("delete from m_register where f_inv=:f_inv");
        fDD[":f_reservation"] = ui->leReservationId->text();
        fDD.exec("delete from m_register where f_res=:f_reservation");
        fDD[":f_doc"] = ui->leReservationId->text();
        fDD.exec("delete from m_register where f_doc=:f_doc");
        fDD[":f_invoice"] = ui->leInvoice->text();
        fDD.exec("delete from f_reservation where f_invoice=:f_invoice");
        fDD[":f_reservation"] = ui->leReservationId->text();
        fDD.exec("delete from f_reservation_guests where f_reservation=:f_reservation");
        fTrackControl->insert("Invoice eliminated", "", "");
        fTrackControl->saveChanges();
        message_info(tr("The invoice was eliminated"));
        close();
        fTabWidget->removeTab(fTabIndex);
        return;
    }
    if (rows.count() == 0) {
        message_error(tr("Nothing was selected"));
        return;
    }
    if (message_confirm("<b>" + tr("This operation cannot be undon, continue?") + "<b>") != QDialog::Accepted) {
        return;
    }
    fDD[":f_id"] = ui->tblData->item(rows.at(0).row(), 0)->data(Qt::EditRole);
    fDD.exec("delete from m_register where f_id=:f_id");
    if (ui->tblData->toString(rows.at(0).row(), 10) == VAUCHER_POINT_SALE_N) {
        FRestaurantTotal::removeVoucher(ui->tblData->item(rows.at(0).row(), 0)->data(Qt::EditRole).toString());
    } else if (ui->tblData->toString(rows.at(0).row(), 10) == VAUCHER_EVENT_N) {
        fDD[":f_id"] = ui->tblData->item(rows.at(0).row(), 0)->data(Qt::EditRole);
        fDD.exec("delete from o_event where f_id=:f_id");
    }
    QString oldValue = QString("%1 %2(%3) %4 %5")
                       .arg(ui->tblData->item(rows.at(0).row(), 0)->data(Qt::EditRole).toString(),
                            ui->tblData->item(rows.at(0).row(), 5)->data(Qt::EditRole).toString(),
                            ui->tblData->item(rows.at(0).row(), 6)->data(Qt::EditRole).toString(),
                            ui->tblData->item(rows.at(0).row(), 2)->data(Qt::EditRole).toDate().toString(def_date_format),
                            ui->tblData->item(rows.at(0).row(), 4)->data(Qt::EditRole).toString());
    fTrackControl->insert("Entry eliminated", oldValue, "");
    fTrackControl->saveChanges();
    correctCOCL();
    load(ui->leInvoice->text());
    message_info(tr("The entry was eliminated"));
}

void WAccInvoice::on_tblData_doubleClicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    DoubleDatabase fDD;
    if (index.column() == 2) {
        if (!r__(cr__super_correction)) {
            return;
        }
        QString oldDate = ui->tblData->item(index.row(), 2)->data(Qt::EditRole).toDate().toString(def_date_format);
        QDate date = WORKING_DATE;
        if (DlgChartDateRange::getDate(date)) {
            fDD[":f_wdate"] = date;
            fDD[":f_rdate"] = date;
            fDD.update("m_register", where_id(ap(ui->tblData->item(index.row(), 0)->data(Qt::EditRole).toString())));
            fTrackControl->insert("Manual change date for " + ui->tblData->item(index.row(), 0)->data(Qt::EditRole).toString(),
                                  oldDate, date.toString(def_date_format));
            if (ui->tblData->toString(index.row(), 10) == VAUCHER_POINT_SALE_N) {
                fDD[":f_dateCash"] = date;
                fDD[":f_id"] = ui->tblData->item(index.row(), 0)->data(Qt::EditRole).toString();
                fDD.exec("update o_header set f_dateCash=:f_dateCash where f_id=:f_id");
            }
            correctCOCL();
            fTrackControl->saveChanges();
            load(ui->leInvoice->text());
        }
    } else if (index.column() == 4) {
        openVaucher(ui->tblData->toString(index.row(), 10), ui->tblData->toString(index.row(), 0));
    } else if (index.column() == 5 || index.column() == 6) {
        if (!r__(cr__super_correction)) {
            return;
        }
        double oldAmount = ui->tblData->toDouble(index.row(), index.column());
        bool ok = false;
        double newAmount = QInputDialog::getDouble(this, tr("New amount"), tr("New amount"), oldAmount, 0, 999999999, 2, &ok);
        if (!ok || newAmount < 1) {
            return;
        }
        fDD[":f_amountAmd"] = newAmount;
        fDD[":f_amountVat"] = (index.column() == 5 ? Utils::countVATAmount(newAmount, ui->leVatCode->asInt()) : 0);
        fDD.update("m_register", where_id(ap(ui->tblData->item(index.row(), 0)->data(Qt::EditRole).toString())));
        fTrackControl->insert("Manual change amount for " + ui->tblData->item(index.row(), 0)->data(Qt::EditRole).toString(),
                              float_str(oldAmount, 1), float_str(newAmount, 1));
        correctCOCL();
        fTrackControl->saveChanges();
        load(ui->leInvoice->text());
    } else if (index.column() == 8) {
        DoubleDatabase dd;
        dd[":f_replyTaxCode"] = ui->tblData->toInt(index.row(), 8);
        dd.exec("select * from airwick.tax_print where f_replyTaxCode=:f_replyTaxCode");
        if (dd.nextRow()) {
            DlgHDMViewer(ui->tblData->toString(index.row(), 8), dd.getString("f_queryjson"), this).exec();
        } else {
            message_error(tr("Invalid fiscal code"));
            return;
        }
    }
}

void WAccInvoice::on_deDeparture_userDateChanged(const QDate &date)
{
    if (message_confirm(tr("Are you sure to change the date of entry?")) != QDialog::Accepted) {
        load(ui->leInvoice->text());
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_startDate"] = date;
    fDD.update("m_register", where_id(ap(ui->leReservationId->text())));
    fTrackControl->saveChanges();
}

void WAccInvoice::on_deEntry_userDateChanged(const QDate &date)
{
    if (message_confirm(tr("Are you sure to change the date of entry?")) != QDialog::Accepted) {
        load(ui->leInvoice->text());
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_startDate"] = date;
    fDD.update("m_register", where_id(ap(ui->leReservationId->text())));
    fTrackControl->saveChanges();
}

void WAccInvoice::on_btnPostingCharges_clicked()
{
    auto *p = new DlgPostCharge(this);
    p->setInvoice(ui->leInvoice->text());
    p->exec();
    delete p;
    correctCOCL();
    load(ui->leInvoice->text());
}

void WAccInvoice::on_btnMoveItem_clicked()
{
    QModelIndexList rows = ui->tblData->selectionModel()->selectedRows();
    if (rows.count() == 0) {
        message_error(tr("Nothing was selected"));
        return;
    }
    DoubleDatabase fDD;
    int row = rows.at(0).row();
    DlgRemotInvoices *d = new DlgRemotInvoices(true, this);
    if (d->exec() == QDialog::Accepted) {
        fDD[":f_invoice"] = d->fResult;
        fDD.exec("select r.f_id, r.f_room, g.guest "
                 "from f_reservation r "
                 "inner join guests g on g.f_id=r.f_guest "
                 "where r.f_invoice=:f_invoice");
        fDD.nextRow();
        fDD[":f_inv"] = d->fResult;
        fDD[":f_room"] = fDD.getValue("f_room");
        fDD[":f_guest"] = fDD.getValue("guest");
        fDD[":f_res"] = fDD.getValue("f_id");
        fDD.update("m_register", where_id(ap(ui->tblData->toString(row, 0))));
        fDD[":f_id"] = ui->tblData->toString(row, 0);
        fDD.exec("select * from m_register where f_id=:f_id");
        fDD.nextRow();
        if (fDD.getValue("f_source").toString() == VAUCHER_POINT_SALE_N) {
            fDD[":f_paymentModeComment"] = fDD.getValue("f_room").toString() + ", " + fDD.getValue("f_guest").toString();
            fDD[":f_roomComment"] = fDD.getValue("f_room").toString() + ", " + fDD.getValue("f_guest").toString();
            fDD[":f_reservation"] = ui->leReservationId->text();
            fDD.update("o_header", where_id(ap(ui->tblData->toString(row, 0))));
        }
        fTrackControl->insert("Entry moved to other invoice " + ui->tblData->item(row, 0)->data(Qt::EditRole).toString(),
                              ui->tblData->toString(row, 4) + ": " + ui->tblData->toString(row, 5) + "/" + ui->tblData->toString(row, 6),
                              d->fResult);
        fTrackControl->saveChanges();
        fTrackControl->insert("Entry moved from other invoice " + ui->tblData->item(row, 0)->data(Qt::EditRole).toString(),
                              ui->tblData->toString(row, 4) + ": " + ui->tblData->toString(row, 5) + "/" + ui->tblData->toString(row, 6),
                              ui->leInvoice->text());
        fTrackControl->saveChanges();
        correctCOCL();
        load(ui->leInvoice->text());
    }
    delete d;
}

void WAccInvoice::on_btnChangeCL_clicked()
{
    QModelIndexList rows = ui->tblData->selectionModel()->selectedRows();
    if (rows.count() == 0) {
        message_error(tr("Nothing was selected"));
        return;
    }
    int row = rows.at(0).row();
    DoubleDatabase fDD;
    fDD[":f_id"] = ui->tblData->toString(row, 0);
    fDD.exec("select f_source, f_itemCode, f_cityLedger from m_register  where f_id=:f_id");
    fDD.nextRow();
    if (fDD.getValue("f_source").toString() != "RV") {
        message_error(tr("The voucher must be receipt voucher"));
        return;
    }
    if (fDD.getValue("f_itemCode").toInt() != fPreferences.getDb(def_receip_vaucher_id).toInt()) {
        return;
    }
    QString oldCL = fDD.getValue("f_cityLedger").toString();
    CacheCityLedger cl;
    if (!cl.get(oldCL)) {
        message_error(tr("Wrong cityledger code. Contact with application developer."));
        return;
    }
    QString code, name;
    if (DlgCL::getCL(code, name)) {
        fDD[":f_finalName"] = "C/L " + name;
        fDD[":f_cityLedger"] = code.toInt();
        fDD.update("m_register", where_id(ap(ui->tblData->toString(row, 0))));
        fTrackControl->insert("CL Changed for  " + ui->tblData->toString(row, 0),
                              oldCL + "/" + cl.fName(), code + "/" + name);
        load(ui->leInvoice->text());
    }
}

void WAccInvoice::on_btnNewVaucher_clicked()
{
    WVaucherEditor::newVaucher(ui->leInvoice->text());
    correctCOCL();
    load(ui->leInvoice->text());
}

void WAccInvoice::on_deEntry_dateChanged(const QDate &date)
{
    Q_UNUSED(date)
}

void WAccInvoice::on_deCheckIn_dateChanged(const QDate &date)
{
    Q_UNUSED(date)
}

void WAccInvoice::on_btnEditReserv_clicked()
{
    DlgReserveShortInfo::loadShortInfo(ui->leReservationId->text());
    load(ui->leInvoice->text());
}

void WAccInvoice::on_btnExcel_clicked()
{
    QString curr;
    double rate;
    bool printMeal;
    switch (DlgInvoicePrintOption::getOption(curr, rate, printMeal)) {
        case pio_none:
            break;
        case pio_guest:
            PExportInvoiceToExcel::exportInvoice(ui->leInvoice->text(), 0);
            break;
        case pio_comp:
            PExportInvoiceToExcel::exportInvoice(ui->leInvoice->text(), 1);
            break;
        case pio_guestcomp_ser:
            PExportInvoiceToExcel::exportInvoice(ui->leInvoice->text(), 0);
            PExportInvoiceToExcel::exportInvoice(ui->leInvoice->text(), 1);
            break;
        case pio_guestcomp_tog:
            PExportInvoiceToExcel::exportInvoice(ui->leInvoice->text(), -1);
            break;
    }
}

void WAccInvoice::on_btnEditRowVaucher_clicked()
{
    QModelIndexList rows = ui->tblData->selectionModel()->selectedRows();
    if (rows.count() == 0) {
        message_error(tr("Nothing was selected"));
        return;
    }
    int row = rows.at(0).row();
    WVaucherEditor::load(ui->tblData->toString(row, 0));
    correctCOCL();
    load(ui->leInvoice->text());
}

void WAccInvoice::on_chViewAllVauchers_clicked()
{
    load(ui->leInvoice->text());
}

void WAccInvoice::on_btnViewReserv_clicked()
{
    WReservation::openReserveWindows(ui->leReservationId->text());
}

void WAccInvoice::on_btnGuestInfo_clicked()
{
    DlgReservationGuests::viewGuests(ui->leReservationId->text());
}

void WAccInvoice::on_btnNext_clicked()
{
}

void WAccInvoice::on_btnExportAS_clicked()
{
    QMap<int, QMap<QString, QVariant> > partnersMap;
    QMap<QString, QMap<QString, QVariant> > servicesMap;
    QMap<QString, QMap<QString, QVariant> > goodsMap;
    QMap<QString, QMap<QString, QVariant> > unitsMap;
    DlgExportAS::getAsDataMap(partnersMap, servicesMap, goodsMap, unitsMap);
    DlgExportAS::exportInvoiceToAs(ui->leInvoice->text(), partnersMap, servicesMap, unitsMap, true);
    message_info(tr("Done."));
}

void WAccInvoice::on_btnExportASRetail_clicked()
{
    DlgExportAS::exportInvoiceToAsAsRetailSaleOnlyTax(ui->leInvoice->text());
    //    QString curr;
    //    double rate;
    //    bool printMeal;
    //    switch (DlgInvoicePrintOption::getOption(curr, rate, printMeal)) {
    //    case pio_none:
    //        break;
    //    case pio_guest:
    //        DlgExportAS::exportInvoiceToAsAsRetailSale(ui->leInvoice->text(), 0);
    //        break;
    //    case pio_comp:
    //        DlgExportAS::exportInvoiceToAsAsRetailSale(ui->leInvoice->text(), 1);
    //        break;
    //    case pio_guestcomp_ser:
    //        DlgExportAS::exportInvoiceToAsAsRetailSale(ui->leInvoice->text(), 0);
    //        DlgExportAS::exportInvoiceToAsAsRetailSale(ui->leInvoice->text(), 1);
    //        break;
    //    case pio_guestcomp_tog:
    //        DlgExportAS::exportInvoiceToAsAsRetailSale(ui->leInvoice->text(), -1);
    //        break;
    //    }
    message_info("Finish");
}

void WAccInvoice::on_btnMoveToCL_clicked()
{
    QModelIndexList rows = ui->tblData->selectionModel()->selectedRows();
    if (rows.count() == 0) {
        message_error(tr("Nothing was selected"));
        return;
    }
    int row = rows.at(0).row();
    DoubleDatabase fDD;
    fDD[":f_id"] = ui->tblData->toString(row, 0);
    fDD.exec("select f_source, f_itemCode, f_cityLedger from m_register  where f_id=:f_id");
    if (fDD.nextRow() == false) {
        message_error(tr("Invalid voucher code"));
        return;
    }
    //    if (fDD.getValue("f_source").toString() != "PS") {
    //        message_error(tr("The voucher must be the PS voucher"));
    //        return;
    //    }
    if (DlgMoveToCL(ui->tblData->toString(row, 0), this).exec() == QDialog::Accepted) {
        load(ui->leInvoice->text());
    }
}
