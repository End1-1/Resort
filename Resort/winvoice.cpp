#include "winvoice.h"
#include <QDir>
#include <QProcess>
#include "cacheactiveroom.h"
#include "cacheinvoiceitem.h"
#include "cacheredreservation.h"
#include "cachereservation.h"
#include "cacheroom.h"
#include "cachetaxmap.h"
#include "dlgadvanceentry.h"
#include "dlgdiscount.h"
#include "dlggposorderinfo.h"
#include "dlginvoicecancelation.h"
#include "dlginvoicepaymentoptions.h"
#include "dlginvoiceprintoption.h"
#include "dlgofferinvoiceextra.h"
#include "dlgpaymentsdetails.h"
#include "dlgpostbreakfast.h"
#include "dlgpostcharge.h"
#include "dlgpretax.h"
#include "dlgprintrandomtax.h"
#include "dlgprinttaxsideoption.h"
#include "dlgreceiptvaucher.h"
#include "dlgreserveshortinfo.h"
#include "dlgselectfiscalmachin.h"
#include "dlgtaxback.h"
#include "dlgtaxback2.h"
#include "dlgtaxreference.h"
#include "dlgtracking.h"
#include "dlgtransfer.h"
#include "dlgtransferanyamount.h"
#include "dlgwakepcalls.h"
#include "epushbutton.h"
#include "pprintinvoice.h"
#include "printtaxd.h"
#include "ui_winvoice.h"
#include "vauchers.h"
#include "wreservation.h"

static const int HINT_ACTIVE_ROOM = 1;

WInvoice::WInvoice(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WInvoice)
{
    ui->setupUi(this);
    ui->btnTaxPrint->setEnabled(false);
    QListIterator<QObject*> it(ui->wBtn->children());

    while(it.hasNext()) {
        QWidget *w = dynamic_cast<QWidget*>(it.next());

        if(w) {
            w->setEnabled(false);
        }
    }

    ui->teRemark->setReadOnly(true);
    QList<int> tblInvWidths;
    tblInvWidths << 0 << 0 << 100 << 200 << 80 << 80 << 70 << 200 << 0 << 0 << 27 << 0 << 0 << 0;

    for(int i = 0; i < tblInvWidths.count(); i++) {
        ui->tblInvLeft->setColumnWidth(i, tblInvWidths.at(i));
        ui->tblInvRight->setColumnWidth(i, tblInvWidths.at(i));
    }

    ui->leRoomCode->setSelector(this, cache(cid_active_room), ui->leRoom, HINT_ACTIVE_ROOM);
    ui->btnManualTax->setVisible(r__(cr__manualtax));
    ui->btnPostingCharges->setVisible(r__(cr__postchage_vaucher));
    ui->btnPaymentsDetails->setVisible(r__(cr__receipt_vaucher));
    ui->btnDiscount->setVisible(r__(cr__discount_vaucher));
    ui->btnTransfer->setVisible(r__(cr__transfer_vaucher));
    ui->btnTransferAmount->setVisible(r__(cr__transfer_vaucher));
    ui->btnWakeup->setVisible(r__(cr__wakeupcall));
    ui->btnAdvance->setVisible(r__(cr__advance_voucher_invoice));
    connect(cache(cid_active_room), SIGNAL(updated(int, QString)), this, SLOT(cacheUpdated(int, QString)));
    connect(ui->leCheckInTime, &EQLineEdit::customButtonClicked, [this](bool v) {
        Q_UNUSED(v);

        if(!r__(cr__super_correction)) {
            return;
        }

        DlgReserveShortInfo::loadShortInfo(ui->leReserveID->text());
        loadInvoice(ui->leInvoice->text());
    });
    QFont font(qApp->font());
    font.setPointSize(font.pointSize() + 2);
    font.setBold(true);
    ui->leTotalLeft->setFont(font);
    ui->leTotalRight->setFont(font);
    font.setPointSize(font.pointSize() + 1);
    ui->leGranTotal->setFont(font);
    ui->btnTrack->setVisible(fPreferences.getDb(def_show_logs).toBool());
}

WInvoice::~WInvoice()
{
    delete ui;
}

void WInvoice::callback(int sel, const QString &code)
{
    switch(sel) {
    case HINT_ACTIVE_ROOM: {
        CacheActiveRoom c;
        c.get(code);

        if(ui->leInvoice->notEmpty()) {
            if(fTrackControl) {
                if(fTrackControl->hasChanges()) {
                    fTrackControl->saveChanges();
                    save();
                }
            }
        }

        if(c.fValid) {
            if(ui->leInvoice->notEmpty()) {
                if(ui->leInvoice->text() != c.fInvoice()) {
                    loadInvoice(c.fInvoice());
                }
            } else {
                loadInvoice(c.fInvoice());
            }
        } else {
            clearInvoice();

            if(ui->leRoomCode->asInt() > 0) {
                message_error(tr("No active invoice on this room or wrong room number"));
            }
        }

        break;
    }
    }
}

void WInvoice::loadInvoice(const QString &id)
{
    DoubleDatabase fDD;
    ui->btnTaxPrint->setEnabled(false);

    if(fTrackControl) {
        if(fTrackControl->hasChanges()) {
            fTrackControl->saveChanges();

            if(ui->leInvoice->notEmpty()) {
                fDD[":f_remarks"] = ui->teRemark->toPlainText();
                fDD.update("f_reservation", where_id(ap(ui->leReserveID->text())));
            }
        }
    }

    QString oldInvoice = ui->leInvoice->text();
    ui->leInvoice->setText(id);
    QString query = "select rs.f_invoice, rs.f_id, 'invoice date', rs.f_room, "
                    "r.f_short as f_room_short, concat(g.f_firstName, ' ', g.f_lastName) as f_guest_name, "
                    "g.f_passport, rs.f_cardex, c.f_name, rs.f_pricePerNight, rs.f_remarks, rs.f_startDate, rs.f_endDate,"
                    "rs.f_man+rs.f_woman+rs.f_child, gs.total, rs.f_vatMode, v.f_" + def_lang + ", "
                    "rs.f_checkInTime, 0 as i_f_prepaid, ucheckin.f_username, rs.f_cityLedger, cl.f_name, "
                    "ra.f_" + def_lang + ", nights.ntotal, rs.f_booking, r.f_donotdisturbe "
                    "from  f_reservation rs "
                    "left join f_room r on rs.f_room=r.f_id "
                    "left join f_guests g on rs.f_guest=g.f_id "
                    "left join f_cardex c on c.f_cardex=rs.f_cardex "
                    "left join f_vat_mode v on v.f_id=rs.f_vatMode "
                    "left join users ucheckin on ucheckin.f_id=rs.f_checkInUser "
                    "left join (select rg.f_reservation, count(f_id) as total from f_reservation_guests rg group by 1) gs on gs.f_reservation=rs.f_id "
                    "left join f_city_ledger cl on cl.f_id=rs.f_cityLedger "
                    "left join f_room_arrangement ra on ra.f_id=rs.f_arrangement "
                    "left join (select f_inv, count(f_id) as ntotal from m_register where f_canceled=0 and f_source='RM' and f_inv=" + ap(
                        ui->leInvoice->text()) + ") nights on nights.f_inv=rs.f_invoice "
                             "where rs.f_invoice=" + ap(id);
    fDD.exec(query);

    if(fDD.rowCount() == 0) {
        enableButtons(false);
        message_error(tr("Invoice number wrong"));
        return;
    }

    enableButtons(true);
    QList<QVariant>& row = fDD.fDbRows[0];
    int c = 0;
    c++; //Skip invoice id
    ui->leReserveID->setText(row.at(c++).toString());
    c++; //Skip invoice date
    ui->leRoomCode->setText(row.at(c++).toString());
    ui->leRoom->setText(row.at(c++).toString());
    ui->leGuest->setText(row.at(c++).toString());
    ui->lePassport->setText(row.at(c++).toString());
    ui->leCardex->setText(row.at(c++).toString());
    ui->leCardexName->setText(row.at(c++).toString());
    ui->leRoomRate->setText(row.at(c++).toString());
    ui->teRemark->setPlainText(row.at(c++).toString());
    ui->deCheckin->setDate(row.at(c++).toDate());
    ui->deDeparture->setDate(row.at(c++).toDate());
    //    ui->leNights->setText(QString::number(ui->deCheckin->date().daysTo(ui->deDeparture->date())));
    ui->leGuestCount->setText(row.at(c++).toString());
    ui->leRegisteredGuest->setText(row.at(c++).toString());
    ui->leVatMode->fHiddenText = row.at(c++).toString();
    ui->leVatMode->setText(row.at(c++).toString());
    ui->leCheckInTime->setText(row.at(c++).toString());
    ui->lePrepaid->setDouble(row.at(c++).toDouble());
    ui->leCheckInOperator->setText(row.at(c++).toString());
    ui->leCityLedgerCode->setText(row.at(c++).toString());
    ui->leCityLedgerName->setText(row.at(c++).toString());
    ui->leArrangement->setText(row.at(c++).toString());
    ui->leNights->setText(QString("%1 / %2").arg(row.at(c++).toString()).arg(ui->deCheckin->date().daysTo(
                              ui->deDeparture->date())));
    ui->leBookingNo->setText(row.at(c++).toString());
    ui->btnDoNotDisturbe->setChecked(row.at(c++).toInt() > 0);
    /* -------------------------- BEGIN CONTENT --------------------------*/
    ui->tblInvLeft->clearContents();
    ui->tblInvRight->clearContents();
    //////////////////////////////////////////////////////////////////////////////  content
    query = "select m.f_id, m.f_sign, m.f_wdate, m.f_finalName, "
            "m.f_amountAmd, m.f_amountVat, m.f_fiscal, m.f_remarks, m.f_source, m.f_doc, "
            "m.f_side, m.f_itemCode, m.f_source, m.f_paymentMode, m.f_fiscalmachine "
            "from m_register m "
            "where m.f_inv=" + ap(ui->leInvoice->text()) + " " +
            "and m.f_canceled=0 and m.f_finance=1 "
            "order by m.f_wdate, m.f_time ";
    fDD.exec(query);
    ui->tblInvLeft->clearContents();
    ui->tblInvRight->clearContents();
    ui->tblInvLeft->setRowCount(0);
    ui->tblInvRight->setRowCount(0);
    QFont f(qApp->font());
    f.setBold(true);
    QList<QVariant> row1;

    while(fDD.nextRow(row1)) {
        EQTableWidget *side = nullptr;

        if(row1.at(10).toInt() == 0) {
            side = ui->tblInvLeft;
        } else {
            side = ui->tblInvRight;
        }

        side->setRowCount(side->rowCount() + 1);
        int r = side->rowCount() - 1;
        side->setItem(r, 0, new C5TableWidgetItem(row1.at(0).toString())); // rec id
        side->setItem(r, 1, new C5TableWidgetItem(row1.at(1).toString())); // sign
        side->setItem(r, 2, new C5TableWidgetItem(row1.at(2).toString())); // date
        side->setItem(r, 3, new C5TableWidgetItem(row1.at(3).toString())); // item name
        side->setItemWithValue(r, 4, row1.at(4).toDouble()); // amount
        side->setItemWithValue(r, 5, row1.at(5).toDouble()); // vat
        side->setItem(r, 6, new C5TableWidgetItem(row1.at(6).toString())); // tax
        side->setItem(r, 7, new C5TableWidgetItem(row1.at(7).toString())); // remarks
        side->setItem(r, 8, new C5TableWidgetItem(row1.at(8).toString())); // source
        side->setItem(r, 9, new C5TableWidgetItem(row1.at(9).toString())); //source id
        side->setItem(r, 10, new C5TableWidgetItem()); // btn
        side->setItem(r, 11, new C5TableWidgetItem(row1.at(11).toString())); // item id
        side->setItem(r, 12, new C5TableWidgetItem(row1.at(12).toString())); // item group
        side->setItem(r, 13, new C5TableWidgetItem(row1.at(13).toString())); // Payment mode
        side->setItem(r, 14, new C5TableWidgetItem(row1.at(14).toString())); //Fiscal machine
        /// tax chebox
        side->item(r, 6)->setCheckState(row1.at(6).toInt() > 0 ? Qt::Checked : Qt::Unchecked);
        side->item(r, 6)->setFlags(side->item(r, 6)->flags() ^Qt::ItemIsUserCheckable);
        side->setItem(r, 7, new C5TableWidgetItem(row1.at(7).toString()));

        /// button for view of restaurant invoice details
        if(side->item(r, 8)->text().toInt() == 2) {
            EPushButton *b = new EPushButton(this);
            b->setIcon(QIcon(":/images/search.png"));
            QSize size(25, 25);
            b->setMaximumSize(size);
            b->setMinimumSize(size);
            b->setTag(row1.at(9).toInt());
            connect(b, SIGNAL(clickedWithTag(int)), this, SLOT(viewGPOSOrder(int)));
            side->setCellWidget(r, 10, b);
        }

        if(row1.at(1).toInt() < 0) {
            for(int i = 0; i < side->columnCount(); i++) {
                side->item(r, i)->setFont(f);
            }
        }
    }

    /* -------------------------- END CONTENT --------------------------*/
    /* advance */
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD.exec("select sum(f_amountAmd) as f_advance from m_register where f_Canceled=0 and f_inv=:f_inv and f_source='AV' and f_fiscal>0");

    if(fDD.nextRow()) {
        ui->lePrepaid->setDouble(fDD.getDouble(0));
    }

    fDD[":f_invoice"] = ui->leInvoice->text();
    fDD.exec("select sum(f_amount) from f_used_advance where f_invoice=:f_invoice");
    fDD.nextRow();
    ui->lePrepaid->setDouble(ui->lePrepaid->asDouble() - fDD.getDouble(0));
    /* end advance */
    countTotals();

    if(fTrackControl) {
        fTrackControl->resetChanges();
    }

    startTracking();

    if(oldInvoice != ui->leInvoice->text()) {
    }

    fTrackControl->saveChanges();
    ui->teRemark->setReadOnly(false);
    setupTabTextAndIcon(tr("Invoice for room") + " #" + ui->leRoomCode->text(), ":/images/invoice.png");
}

void WInvoice::loadReservation(const QString &id)
{
    DoubleDatabase fDD;
    fDD[":f_id"] = id;
    fDD.exec("select f_invoice from f_reservation where f_id=:f_id");

    if(fDD.nextRow()) {
        loadInvoice(fDD.getString(0));
    }
}

void WInvoice::startTracking()
{
    if(fTrackControl == nullptr) {
        fTrackControl = new TrackControl(TRACK_RESERVATION);
        fTrackControl->addWidget(ui->leTotalLeft, "Guest total")
        .addWidget(ui->leTotalRight, "Company total")
        .addWidget(ui->leGranTotal, "Grand total")
        .addWidget(ui->teRemark, "Remarks");
    }

    fTrackControl->fRecord = "-";
    fTrackControl->fInvoice = ui->leInvoice->text();
    fTrackControl->fReservation = ui->leReserveID->text();
}

bool WInvoice::activeDoc(const QString &invoice)
{
    if(invoice == ui->leInvoice->text()) {
        return true;
    }

    return false;
}

void WInvoice::openInvoiceWindow(const QString &invoice)
{
    WInvoice *w = nullptr;

    for(int i = 0; i < fMainWindow->fTab->count(); i++) {
        w = dynamic_cast<WInvoice*>(fMainWindow->fTab->widget(i));

        if(w) {
            if(w->activeDoc(invoice)) {
                fMainWindow->fTab->setCurrentIndex(i);
                return;
            }
        }
    }

    w = addTab<WInvoice>();
    w->loadInvoice(invoice);
}

void WInvoice::openInvoiceFromReservation(const QString &reserve)
{
    DoubleDatabase dd;
    dd[":f_id"] = reserve;
    dd.exec("select f_invoice from f_reservation where f_id=:f_id");

    if(dd.nextRow()) {
        openInvoiceWindow(dd.getString(0));
    }
}

void WInvoice::setupTab()
{
    setupTabTextAndIcon(tr("Invoice"), ":/images/invoice.png");
}

bool WInvoice::canClose()
{
    bool canClose = true;

    if(fTrackControl) {
        canClose = canClose && (ui->leInvoice->notEmpty() && !fTrackControl->hasChanges());
    }

    if(!canClose) {
        int result = message_yesnocancel("Invoice was modifed, save changes?");

        switch(result) {
        case RESULT_YES:
            save();
            canClose = true;
            break;

        case RESULT_NO:
            canClose = true;
            break;

        case RESULT_CANCEL:
            canClose = false;
            break;
        }
    }

    return canClose;
}

void WInvoice::cacheUpdated(int cache, const QString &id)
{
    switch(cache) {
    case cid_active_room: {
        if(id == ui->leRoomCode->text()) {
            if(!cache(cid_active_room)->fStruct->get(id)) {
                clearInvoice();
                return;
            }
        }

        break;
    }

    default:
        break;
    }
}

void WInvoice::viewGPOSOrder(const QString &id)
{
    DlgGPOSOrderInfo *d = new DlgGPOSOrderInfo(this);
    d->setOrder(id);
    d->exec();
    delete d;
}

void WInvoice::on_btnShowLeft_clicked()
{
    ui->wdtLeft->setVisible(!ui->wdtLeft->isVisible());
}

void WInvoice::on_btnShowRight_clicked()
{
    ui->wdtRight->setVisible(!ui->wdtRight->isVisible());
}

void WInvoice::on_leRoomCode_returnPressed()
{
    callback(HINT_ACTIVE_ROOM, ui->leRoomCode->text());
}

void WInvoice::on_btnLeft_clicked()
{
    moveTableRow(ui->tblInvRight, ui->tblInvLeft);
    countTotals();
}

void WInvoice::moveTableRow(EQTableWidget *from, EQTableWidget *to)
{
    DoubleDatabase fDD;
    QModelIndexList sel = from->selectionModel()->selectedRows();
    QString fromTo = QString("%1->%2")
                     .arg((from == ui->tblInvLeft ? tr("Guest") : tr("Company")))
                     .arg((from == ui->tblInvLeft ? tr("Company") : tr("Guest")));

    for(int i = sel.count() - 1; i > -1; i--) {
        int rowTo = to->rowCount();
        to->setRowCount(rowTo + 1);

        for(int j = 0; j < from->columnCount(); j++) {
            to->setItem(rowTo, j, new C5TableWidgetItem(*(from->item(sel.at(i).row(), j))));
        }

        fTrackControl->insert("Entry moved", fromTo,
                              from->item(sel.at(i).row(), 3)->text() + " / " +
                              from->item(sel.at(i).row(), 2)->text() + " / " +
                              from->item(sel.at(i).row(), 4)->text() + " / " +
                              from->item(sel.at(i).row(), 5)->text());
        from->removeRow(sel.at(i).row());
    }

    for(int i = 0; i < ui->tblInvLeft->rowCount(); i++) {
        fDD[":f_side"] = 0;
        fDD.update("m_register", where_id(ap(ui->tblInvLeft->item(i, 0)->text())));
    }

    for(int i = 0; i < ui->tblInvRight->rowCount(); i++) {
        fDD[":f_side"] = 1;
        fDD.update("m_register", where_id(ap(ui->tblInvRight->item(i, 0)->text())));
    }
}

void WInvoice::on_btnDoubleLeft_clicked()
{
    ui->tblInvRight->selectAll();
    moveTableRow(ui->tblInvRight, ui->tblInvLeft);
    countTotals();
}

void WInvoice::on_btnRight_clicked()
{
    moveTableRow(ui->tblInvLeft, ui->tblInvRight);
    countTotals();
}

void WInvoice::countTotals()
{
    double left = countTotal(ui->tblInvLeft);
    double right = countTotal(ui->tblInvRight);
    ui->leTotalLeft->setDouble(left);
    ui->leTotalRight->setDouble(right);
    ui->leGranTotal->setDouble(left + right);
}

double WInvoice::countTotal(QTableWidget *t)
{
    double result = 0.00;

    for(int i = 0; i < t->rowCount(); i++) {
        double amount = t->item(i, 4)->data(Qt::EditRole).toDouble();
        int sign = t->item(i, 1)->data(Qt::EditRole).toInt();
        result += amount * sign;
    }

    return result;
}

void WInvoice::enableButtons(bool v)
{
    QObjectList ol = ui->wBtn->children();

    for(QObject *o : ol) {
        QWidget *w = dynamic_cast<QWidget*>(o);

        if(w) {
            w->setEnabled(v);
        }
    }
}

void WInvoice::on_btnDoubleRight_clicked()
{
    ui->tblInvLeft->selectAll();
    moveTableRow(ui->tblInvLeft, ui->tblInvRight);
    countTotals();
}

void WInvoice::on_btnRefresh_clicked()
{
    QString fileName = "tax_" + ui->leInvoice->text() + ".json" ;
    QDir d;
    QStringList args;
    args << fPreferences.getDb(def_tax_address).toString()
         << fPreferences.getDb(def_tax_port).toString()
         << fPreferences.getDb(def_tax_password).toString()
         << fileName;
    QProcess *pr = new QProcess();
    pr->start(d.currentPath() + "/printtax.exe", args);

    if(ui->leInvoice->notEmpty()) {
        loadInvoice(ui->leInvoice->text());
    }
}

void WInvoice::on_tblInvRight_clicked(const QModelIndex &index)
{
    Q_UNUSED(index)
    ui->tblInvLeft->selectionModel()->clear();
}

void WInvoice::on_tblInvLeft_clicked(const QModelIndex &index)
{
    Q_UNUSED(index)
    ui->tblInvRight->selectionModel()->clear();
}

void WInvoice::on_btnPostingCharges_clicked()
{
    auto *p = new DlgPostCharge(this);
    p->setRoom(ui->leRoomCode->asInt());
    p->exec();
    delete p;
    loadInvoice(ui->leInvoice->text());
}

void WInvoice::on_btnCheckout_clicked()
{
    DoubleDatabase fDD;
    save();
    DlgOfferInvoiceExtra *o = new DlgOfferInvoiceExtra(this);
    o->setRoom(ui->leRoomCode->asInt());
    o->fDayUseRate = ui->leRoomRate->asDouble();

    if(fPreferences.getDb(def_offer_dayuse).toInt() > 0) {
        o->setExtra(DlgOfferInvoiceExtra::exDayUse);
    }

    if(fPreferences.getDb(def_offer_extrarooming).toInt() > 0) {
        o->setExtra(DlgOfferInvoiceExtra::exExtraRooming);
    }

    if(QTime::currentTime() > fPreferences.getDb(def_late_checkout).toTime()) {
        /// check, if not already exists late checkout item
        bool lateOutExists = false;
        for_row_count(ui->tblInvLeft) {
            if(ui->tblInvLeft->toInt(i, 3) == fPreferences.getDb(def_late_checkout_id).toInt()
                    && ui->tblInvLeft->toInt(i, 1) == 1) {
                lateOutExists = true;
                break;
            }
        }

        if(!lateOutExists) {
            for_row_count(ui->tblInvRight) {
                if(ui->tblInvRight->toInt(i, 3) == fPreferences.getDb(def_late_checkout_id).toInt()
                        && ui->tblInvRight->toInt(i, 1) == 1) {
                    lateOutExists = true;
                    break;
                }
            }
        }

        if(!lateOutExists) {
            o->setExtra(DlgOfferInvoiceExtra::exLateCheckout);
        }
    }

    o->exec();
    o->deleteLater();
    loadInvoice(ui->leInvoice->text());

    ////////////////////////////////////// check balance
    if(ui->lePrepaid->asDouble() > 0.001) {
        message_error(tr("Advance balance exists "));
        return;
    }

    if(ui->leGranTotal->asDouble() > 0.1 || ui->leGranTotal->asDouble() < -0.1) {
        DlgPaymentsDetails *d = new DlgPaymentsDetails(this);
        d->setInvoice(ui->leInvoice->text());
        d->setCheckoutFlag();
        d->exec();
        delete d;
        loadInvoice(ui->leInvoice->text());

        if(ui->leGranTotal->asDouble() > 0.1 || ui->leGranTotal->asDouble() < -0.1) {
            message_error(tr("Balance not equal to zero"));
            return;
        }
    }

    if(message_confirm(tr("Confirm to checkout")) != QDialog::Accepted) {
        return;
    }

    bool result = true;
    fDD.startTransaction();

    if(result) {
        // RESERVATION
        fDD[":f_state"] = RESERVE_CHECKOUT;
        fDD[":f_checkOutTime"] = QTime::currentTime();
        fDD[":f_checkOutUser"] = WORKING_USERID;
        result = result && fDD.update("f_reservation", where_id(ap(ui->leReserveID->text())));
        fTrackControl->insert("Checkout", "", "");
    }

    if(result) {
        //ROOM
        fDD[":f_state"] = ROOM_STATE_DIRTY;
        result = result && fDD.update("f_room", where_id(ui->leRoomCode->asInt()));
        fDD[":f_date"] = QDate::currentDate();
        fDD[":f_wdate"] = WORKING_DATE;
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_oldState"] = ROOM_STATE_CHECKIN;
        fDD[":f_newState"] = ROOM_STATE_DIRTY;
        fDD[":f_user"] = WORKING_USERID;
        fDD[":f_comment"] = "CHECKOUT";
        fDD[":f_reservation"] = ui->leReserveID->text();
        fDD.insert("f_room_state_change", false);
    }

    //SET ROOM INVENTORY NOT READY
    if(result) {
        fDD[":f_room"] = ui->leRoomCode->asInt();
        fDD.exec("update f_room_inventory_journal set f_state=2 where f_room=:f_room");
    }

    fDD[":f_inv"] = ui->leInvoice->text();
    fDD[":f_source"] = VAUCHER_RECEIPT_N;
    fDD.exec("select f_cityLedger, sum(f_amountAmd*f_sign) from m_register where f_cityLedger>0 and f_inv=:f_inv and f_source=:f_source and f_canceled=0");
    double cityAmount = 0;
    int cityCode = 0;

    if(fDD.nextRow()) {
        cityCode = fDD.getInt(0);
        cityAmount = fDD.getDouble(1);
    }

    QString cid = uuidx(VAUCHER_CHECKOUT_N);
    fDD.insertId("m_register", cid);
    fDD[":f_source"] = VAUCHER_CHECKOUT_N;
    fDD[":f_wdate"] = WORKING_DATE;
    fDD[":f_rdate"] = QDate::currentDate();
    fDD[":f_time"] = QTime::currentTime();
    fDD[":f_user"] = WORKING_USERID;
    fDD[":f_room"] = ui->leRoomCode->text();
    fDD[":f_guest"] = ui->leGuest->text();
    fDD[":f_itemCode"] = 38;
    fDD[":f_finalName"] = tr("CHECKOUT ") + cid;
    fDD[":f_amountAmd"] = 0;
    fDD[":f_amountVat"] = 0;
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = 0;
    fDD[":f_paymentMode"] = 0;
    fDD[":f_creditCard"] = 0;
    fDD[":f_cityLedger"] = 0;
    fDD[":f_paymentComment"] = "";
    fDD[":f_dc"] = "DEBIT";
    fDD[":f_sign"] = 1;
    fDD[":f_doc"] = "";
    fDD[":f_rec"] = "";
    fDD[":f_res"] = ui->leReserveID->text();
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD[":f_finance"] = 0;
    fDD[":f_remarks"] = "";
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    fDD[":f_side"] = 0;
    fDD.update("m_register", where_id(ap(cid)));

    if(cityAmount > 0.1 || cityAmount < -0.1) {
        cid = uuidx(VAUCHER_CHECKOUT_N);
        fDD.insertId("m_register", cid);
        fDD[":f_source"] = VAUCHER_CHECKOUT_N;
        fDD[":f_wdate"] = WORKING_DATE;
        fDD[":f_rdate"] = QDate::currentDate();
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_user"] = WORKING_USERID;
        fDD[":f_room"] = ui->leRoomCode->text();
        fDD[":f_guest"] = ui->leGuest->text();
        fDD[":f_itemCode"] = 38;
        fDD[":f_finalName"] = tr("CHECKOUT C/L ") + cid;
        fDD[":f_amountAmd"] = cityAmount;
        fDD[":f_amountVat"] = 0;
        fDD[":f_amountUsd"] = def_usd;
        fDD[":f_fiscal"] = 0;
        fDD[":f_paymentMode"] = 0;
        fDD[":f_creditCard"] = 0;
        fDD[":f_cityLedger"] = cityCode;
        CacheCityLedger cc;
        cc.get(cityCode);
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

    // CHECK FOR DAY USE AND REGISTER GUEST COUNT FOR HISTORY
    if(ui->deCheckin->date() == ui->deDeparture->date()) {
        fDD[":f_date"] = WORKING_DATE;
        fDD[":f_reservation"] = ui->leReserveID->text();
        fDD.exec("insert into f_reservation_guests_history (f_date, f_reservation, f_guest) "
                 "select :f_date, :f_reservation, f_guest from f_reservation_guests "
                 "where f_reservation=:f_reservation");
    }

    if(result) {
        //TRACK
        /////////////////////////////// check checkout date == departure date
        if(ui->deDeparture->date() > WORKING_DATE) {
            fTrackControl->insert("Departure date changed", ui->deDeparture->date().toString(def_date_format),
                                  WORKING_DATE.toString(def_date_format));
            fTrackControl->insert("Checkout", "", "");
            fDD[":f_endDate"] = WORKING_DATE;
            result = result && fDD.update("f_reservation", where_id(ap(ui->leReserveID->text())));
        }
    }

    // FINAL AMOUNT
    if(result) {
        fDD[":f_inv"] = ui->leInvoice->text();
        fDD.exec("select sum(f_amountAmd) from m_register where f_inv=:f_inv and f_finance=1 and f_canceled=0 and f_sign=1");
        fDD.nextRow();
        QVariant finalAmount = fDD.getDouble(0);
        fDD[":f_grandTotal"] = finalAmount;
        fDD[":f_id"] = ui->leReserveID->text();
        fDD.update("f_reservation", where_id(ap(ui->leReserveID->text())));
        fDD[":f_amountAmd"] = finalAmount;
        fDD[":f_id"] = ui->leReserveID->text();
        fDD.update("m_register", where_id(ap(ui->leReserveID->text())));
    }

    if(result) {
        fDD[":f_id"] = ui->leReserveID->text();
        fDD.exec("delete from f_reservation_chart where f_id=:f_id");
        fDD[":f_reservation"] = ui->leReserveID->text();
        fDD.exec("delete from f_reservation_map where f_reservation=:f_reservation");
        fTrackControl->insert("Checkout", "", "");
        fTrackControl->saveChanges();
        fDD.commit();

        if(ui->tblInvLeft->rowCount() > 0) {
            PPrintInvoice(ui->leInvoice->text(), 0, QStringList(), DlgInvoicePaymentOptions::printInvoiceImmediately(), "USD",
                          def_usd, true, this);
        }

        if(ui->tblInvRight->rowCount() > 0) {
            PPrintInvoice(ui->leInvoice->text(), 1, QStringList(), DlgInvoicePaymentOptions::printInvoiceImmediately(), "USD",
                          def_usd, true, this);
        }

        CacheReservation r;

        if(r.get(ui->leReserveID->text())) {
            CacheReservation n;

            if(r.hasNext(n)) {
                BroadcastThread::cmdRefreshCache(cid_reservation, n.fId());
                BroadcastThread::cmdRefreshCache(cid_red_reservation, n.fId());
            }
        }

        BroadcastThread::cmdRefreshCache(cid_reservation, ui->leReserveID->text());
        BroadcastThread::cmdRefreshCache(cid_room, ui->leRoomCode->text());
        BroadcastThread::cmdRefreshCache(cid_active_room, ui->leRoomCode->text());
        clearInvoice();
        removeFromTabWidget();
    } else {
        fDD.rollback();
    }
}

void WInvoice::on_btnPaymentsDetails_clicked()
{
    QString amount = ui->leGranTotal->text();
    DlgPaymentsDetails *d = new DlgPaymentsDetails(this);
    d->setInvoice(ui->leInvoice->text());
    d->exec();
    loadInvoice(ui->leInvoice->text());
    delete d;

    if(ui->leGranTotal->text() != amount) {
        if(fPreferences.getDb(def_print_tax_after_receipt).toBool()) {
            on_btnTaxPrint_clicked();
        }
    }
}

void WInvoice::on_btnTaxPrint_clicked()
{
    DoubleDatabase fDD;
    EQTableWidget *t = nullptr;
    int result = DlgPrintTaxSideOption::printTaxSide();

    switch(result) {
    case pts_none:
        return;

    case pts_guest:
        t = ui->tblInvLeft;
        break;

    case pts_company:
        t = ui->tblInvRight;
        break;
    }

    if(fPreferences.getDb(def_tax_port).toInt() == 0) {
        message_error(tr("Setup tax printer first"));
    }

    QSet<int> taxs;

    for(int i = 0; i < t->rowCount(); i++) {
        if(!isTaxPay(t->toString(i, 12))) {
            continue;
        }

        if(t->itemChecked(i, 6)) {
            continue;
        }

        CacheInvoiceItem c;

        if(!c.get(t->toString(i, 11))) {
            message_error(tr("Error in tax print. c == 0, case 1."));
            continue;
        }

        CacheTaxMap ci;

        if(!ci.get(c.fCode())) {
            message_error(tr("Tax department undefined for ") + c.fName());
            return;
        }

        taxs.insert(ci.fTax());
    }

    int taxnumber = 0;

    if(taxs.count() == 1) {
        taxnumber = taxs.values().at(0);
    } else if(taxs.count() > 1) {
        DlgSelectFiscalMachin ds(taxs, this);
        ds.exec();
        taxnumber = ds.fSelectedMachine;
    }

    if(taxnumber == 0) {
        return;
    }

    PrintTaxD *pt = new PrintTaxD(taxnumber, this);
    pt->fInvoice = ui->leInvoice->text();

    for(int i = 0; i < t->rowCount(); i++) {
        if(!isTaxPay(t->toString(i, 12))) {
            continue;
        }

        if(t->itemChecked(i, 6)) {
            continue;
        }

        //HOTEL SOURCE
        if(t->toString(i, 12) != VAUCHER_POINT_SALE_N) {
            CacheInvoiceItem c;

            if(!c.get(t->toString(i, 11))) {
                message_error(tr("Error in tax print. c == 0, case 1."));
                return;
            }

            CacheTaxMap ci;

            if(!ci.get(c.fCode())) {
                message_error(tr("Tax department undefined for ") + c.fName());
                return;
            }

            if(ci.fTax() != taxnumber) {
                continue;
            }

            QString qty = "1";
            QString price = QString::number(t->toDouble(i, 4));

            if(c.fCode() == fPreferences.getDb(def_auto_breakfast_id).toString()) {
                fDD[":f_id"] = t->toString(i, 0);
                fDD.exec("select * from o_breakfast where f_id=:f_id");

                if(!fDD.nextRow()) {
                    message_error(tr("Cannot find breakfast record. Contact to application developer."));
                    continue;
                }

                qty = fDD.getString("f_pax");
                price = fDD.getString("f_price");
            }

            pt->fDept.append((ui->leVatMode->fHiddenText.toInt() == VAT_INCLUDED ? ci.fName() : c.fNoVatDept()));
            pt->fRecList.append(t->toString(i, 0));
            pt->fCodeList.append(c.fCode());
            pt->fNameList.append(c.fTaxName());
            pt->fPriceList.append(price);
            pt->fQtyList.append(qty);
            pt->fAdgCode.append(c.fAdgt());
            pt->fTaxNameList.append(c.fTaxName());
        } else if(t->toString(i, 12) == VAUCHER_POINT_SALE_N) {
            //RESTAURANT SOURCE
            QString orderId = t->toString(i, 0);
            CacheInvoiceItem c;

            if(!c.get(t->toString(i, 11))) {
                message_error(tr("Error in tax print. c == 0, case 2."));
                continue;
            }

            CacheTaxMap ci;

            if(!ci.get(c.fCode())) {
                message_error(tr("Tax department undefined for ") + c.fName());
                return;
            }

            if(ci.fTax() != taxnumber) {
                continue;
            }

            fDD[":f_header"] = orderId;
            fDD[":f_state"] = DISH_STATE_READY;
            fDD.exec("select d.f_id, d.f_am, d.f_adgt, od.f_qty, od.f_price "
                     "from o_dish od "
                     "inner join r_dish d on d.f_id=od.f_dish "
                     "where od.f_header=:f_header and od.f_state=:f_state "
                     "and (od.f_complex=0 or (od.f_complex>0 and od.f_complexId>0))");

            if(!fDD.rowCount()) {
                CacheInvoiceItem c;

                if(!c.get(t->toString(i, 11))) {
                    message_error(tr("Error in tax print. c == 0, case 1."));
                    continue;
                }

                pt->fDept.append((ui->leVatMode->fHiddenText.toInt() == VAT_INCLUDED ? ci.fName() : c.fNoVatDept()));
                pt->fRecList.append(t->toString(i, 0));
                pt->fCodeList.append(c.fCode());
                pt->fNameList.append(c.fTaxName());
                pt->fPriceList.append(t->toString(i, 4));
                pt->fQtyList.append("1");
                pt->fAdgCode.append(c.fAdgt());
                pt->fTaxNameList.append(c.fTaxName());
            } else {
                QList<QVariant> it;

                while(fDD.nextRow(it)) {
                    pt->fDept.append((ui->leVatMode->fHiddenText.toInt() == VAT_INCLUDED ? c.fVatDept() : c.fNoVatDept()));
                    pt->fRecList.append(t->toString(i, 0));
                    pt->fCodeList.append(it.at(0).toString());
                    pt->fNameList.append(it.at(1).toString());
                    pt->fPriceList.append(it.at(4).toString());
                    pt->fQtyList.append(it.at(3).toString());
                    pt->fAdgCode.append(it.at(2).toString());
                    pt->fTaxNameList.append(it.at(1).toString());
                }
            }
        }
    }

    pt->setPrepaid(ui->lePrepaid->text());
    pt->build();

    if(pt->fRecList.count() > 0) {
        pt->exec();
    } else {
        message_info(tr("Nothing to print"));
    }

    delete pt;
    loadInvoice(ui->leInvoice->text());
}

void WInvoice::on_btnCancel_clicked()
{
    QModelIndexList t1 = ui->tblInvLeft->selectionModel()->selectedRows();
    QModelIndexList t2 = ui->tblInvRight->selectionModel()->selectedRows();

    if(t1.count() + t2.count() == 0) {
        message_info(tr("Nothing was selected"));
        return;
    }

    DlgInvoiceCancelation *d = new DlgInvoiceCancelation(this);
    d->setTrackWindowId(ui->leInvoice->text());
    bool noall = false;
    bool haveEntries = false;

    for(int i = 0; i < t1.count(); i++) {
        QList<QVariant> row;

        if(!r__(cr__ps_correction_in_invoice)) {
            noall = true;
            continue;
        }

        row << ui->tblInvLeft->item(t1.at(i).row(), 0)->data(Qt::DisplayRole);
        row << ui->tblInvLeft->item(t1.at(i).row(), 8)->data(Qt::DisplayRole);
        row << ui->tblInvLeft->item(t1.at(i).row(), 2)->data(Qt::DisplayRole);
        row << ui->tblInvLeft->item(t1.at(i).row(), 3)->data(Qt::DisplayRole);
        row << ui->tblInvLeft->item(t1.at(i).row(), 4)->data(Qt::DisplayRole);
        row << ui->tblInvLeft->item(t1.at(i).row(), 5)->data(Qt::DisplayRole);

        if(ui->tblInvLeft->item(t1.at(i).row(), 2)->data(Qt::EditRole).toDate() < WORKING_DATE) {
            if(!r__(cr__invoice_cancelation_previouse_date)) {
                noall = true;
                continue;
            }
        }

        haveEntries = true;
        d->addRow(row);
    }

    for(int i = 0; i < t2.count(); i++) {
        QList<QVariant> row;

        if(!r__(cr__ps_correction_in_invoice)) {
            noall = true;
            continue;
        }

        row << ui->tblInvRight->item(t2.at(i).row(), 0)->data(Qt::DisplayRole);
        row << ui->tblInvRight->item(t2.at(i).row(), 8)->data(Qt::DisplayRole);
        row << ui->tblInvRight->item(t2.at(i).row(), 2)->data(Qt::DisplayRole);
        row << ui->tblInvRight->item(t2.at(i).row(), 3)->data(Qt::DisplayRole);
        row << ui->tblInvRight->item(t2.at(i).row(), 4)->data(Qt::DisplayRole);
        row << ui->tblInvRight->item(t2.at(i).row(), 5)->data(Qt::DisplayRole);

        if(ui->tblInvRight->item(t2.at(i).row(),
                                 11)->data(Qt::DisplayRole).toInt() == fPreferences.getDb(def_room_charge_id).toInt()) {
            if(ui->tblInvRight->item(t2.at(i).row(), 2)->data(Qt::EditRole).toDate() < WORKING_DATE) {
                if(!r__(cr__invoice_cancelation_previouse_date)) {
                    noall = true;
                    continue;
                }
            }
        }

        haveEntries = true;
        d->addRow(row);
    }

    if(noall) {
        message_info(tr("Some entries was excluded from selection, because insufficiently of privileges"));
    }

    if(haveEntries) {
        if(d->exec() == QDialog::Accepted) {
            loadInvoice(ui->leInvoice->text());
        }
    }

    delete d;
}

void WInvoice::clearInvoice()
{
    enableButtons(false);
    ui->leArrangement->clear();
    ui->leRoomCode->clear();
    ui->leRoom->clear();
    ui->teRemark->clear();
    ui->leInvoice->clear();
    ui->leReserveID->clear();
    ui->leGuest->clear();
    ui->lePassport->clear();
    ui->deCheckin->setDate(QDate::currentDate());
    ui->deDeparture->setDate(QDate::currentDate());
    ui->leCardex->clear();
    ui->leCardexName->clear();
    ui->leNights->setText("0");
    ui->leRoomRate->setText("0");
    ui->tblInvLeft->clearContents();
    ui->tblInvRight->clearContents();
    ui->tblInvLeft->setRowCount(0);
    ui->tblInvRight->setRowCount(0);
    ui->leCityLedgerCode->clear();
    ui->leCityLedgerName->clear();
    ui->leCheckInTime->clear();
    ui->leCheckInOperator->clear();
    ui->leVatMode->clear();
    ui->leGuestCount->clear();
    ui->leRegisteredGuest->clear();
    countTotal(ui->tblInvLeft);
    countTotal(ui->tblInvRight);
    setupTabTextAndIcon(tr("Invoice"), ":/images/invoice.png");
}

void WInvoice::on_btnTransfer_clicked()
{
    QModelIndexList t1 = ui->tblInvLeft->selectionModel()->selectedRows();
    QModelIndexList t2 = ui->tblInvRight->selectionModel()->selectedRows();

    if(t1.count() + t2.count() == 0) {
        message_info(tr("Nothing was selected"));
        return;
    }

    DlgTransfer *d = new DlgTransfer(this);

    for(int i = 0; i < t1.count(); i++) {
        if(ui->tblInvLeft->item(t1.at(i).row(), 1)->data(Qt::DisplayRole).toInt() < 0) {
            continue;
        }

        QList<QVariant> row;
        row << ui->tblInvLeft->item(t1.at(i).row(), 0)->data(Qt::DisplayRole);
        row << ui->tblInvLeft->item(t1.at(i).row(), 2)->data(Qt::DisplayRole);
        row << ui->tblInvLeft->item(t1.at(i).row(), 3)->data(Qt::DisplayRole);
        row << ui->tblInvLeft->item(t1.at(i).row(), 4)->data(Qt::DisplayRole);
        d->addRow(row);
    }

    for(int i = 0; i < t2.count(); i++) {
        if(ui->tblInvRight->item(t2.at(i).row(), 1)->data(Qt::DisplayRole).toInt() < 0) {
            continue;
        }

        QList<QVariant> row;
        row << ui->tblInvRight->item(t2.at(i).row(), 0)->data(Qt::DisplayRole);
        row << ui->tblInvRight->item(t2.at(i).row(), 2)->data(Qt::DisplayRole);
        row << ui->tblInvRight->item(t2.at(i).row(), 3)->data(Qt::DisplayRole);
        row << ui->tblInvRight->item(t2.at(i).row(), 4)->data(Qt::DisplayRole);
        d->addRow(row);
    }

    d->setRoomByCode(ui->leRoomCode->text());

    if(d->exec() == QDialog::Accepted) {
        loadInvoice(ui->leInvoice->text());
    }

    delete d;
}

void WInvoice::on_btnTrack_clicked()
{
    DlgTracking::showTracking(TRACK_RESERVATION, ui->leInvoice->text());
}

void WInvoice::save()
{
    DoubleDatabase fDD;
    fDD[":f_remarks"] = ui->teRemark->toPlainText();
    fDD.update("f_reservation", where_id(ap(ui->leReserveID->text())));
    fTrackControl->saveChanges();
    ui->teRemark->setReadOnly(true);
}

void WInvoice::on_btnDiscount_clicked()
{
    DlgDiscount *d = new DlgDiscount(this);
    double guestAmount = countTotal(ui->tblInvLeft);
    double companyAmount = countTotal(ui->tblInvRight);
    d->setParams(ui->leRoomCode->text(), guestAmount, companyAmount);

    if(d->exec() == QDialog::Accepted) {
    }

    loadInvoice(ui->leInvoice->text());
    delete d;
}

void WInvoice::on_btnTransferAmount_clicked()
{
    DlgTransferAnyAmount *d = new DlgTransferAnyAmount(this);
    d->setHint(hint_from_room);
    d->setRoom(ui->leRoomCode->asInt());
    d->exec();
    d->deleteLater();

    if(!ui->leInvoice->isEmpty()) {
        loadInvoice(ui->leInvoice->text());
    }

    /*
    DlgTransferInvoiceAmount *d = new DlgTransferInvoiceAmount(this);
    d->setRoomFrom(ui->leRoomCode->text());
    d->exec();
    delete d;
    loadInvoice(ui->leInvoice->text());
    */
}

void WInvoice::on_btnPrintInvoice_clicked()
{
    QString curr;
    double rate;
    bool printMeal;

    switch(DlgInvoicePrintOption::getOption(curr, rate, printMeal)) {
    case pio_none:
        break;

    case pio_guest:
        PPrintInvoice(ui->leInvoice->text(), 0, QStringList(), false, curr, rate, printMeal, this);
        break;

    case pio_comp:
        PPrintInvoice(ui->leInvoice->text(), 1, QStringList(), false, curr, rate, printMeal, this);
        break;

    case pio_guestcomp_ser:
        PPrintInvoice(ui->leInvoice->text(), 0, QStringList(), false, curr, rate, printMeal, this);
        PPrintInvoice(ui->leInvoice->text(), 1, QStringList(), false, curr, rate, printMeal, this);
        break;

    case pio_guestcomp_tog:
        PPrintInvoice(ui->leInvoice->text(), -1, QStringList(), false, curr, rate, printMeal, this);
        break;
    }
}

void WInvoice::on_btnModifyRoom_clicked()
{
    WReservation::openReserveWindows(ui->leReserveID->text());
}

void WInvoice::on_tblInvLeft_doubleClicked(const QModelIndex &index)
{
    if(!index.isValid()) {
        return;
    }

    openVaucher(ui->tblInvLeft->toString(index.row(), 8), ui->tblInvLeft->toString(index.row(), 0));
    loadInvoice(ui->leInvoice->text());
}

void WInvoice::on_tblInvRight_doubleClicked(const QModelIndex &index)
{
    if(!index.isValid()) {
        return;
    }

    openVaucher(ui->tblInvRight->toString(index.row(), 8), ui->tblInvRight->toString(index.row(), 0));
    loadInvoice(ui->leInvoice->text());
}

void WInvoice::on_btnPrintAdvance_clicked()
{
    if(fPreferences.getDb(def_tax_port).toInt() == 0) {
        message_error(tr("Setup tax printer first"));
    }

    QList<QList<QVariant> > data;

    for(int i = 0; i < ui->tblInvLeft->rowCount(); i++) {
        if(ui->tblInvLeft->toInt(i, 1) != -1) {
            continue;
        }

        if(ui->tblInvLeft->itemChecked(i, 6)) {
            continue;
        }

        if(ui->tblInvLeft->item(i, 8)->text() != VAUCHER_ADVANCE_N) {
            continue;
        }

        QList<QVariant> row;
        row << ui->tblInvLeft->toInt(i, 0)
            << ui->tblInvLeft->toString(i, 3)
            << ui->tblInvLeft->toString(i, 4)
            << ""
            << ui->tblInvLeft->toString(i, 13);
        data << row;
    }

    for(int i = 0; i < ui->tblInvRight->rowCount(); i++) {
        if(ui->tblInvRight->toInt(i, 1) != -1) {
            continue;
        }

        if(ui->tblInvRight->itemChecked(i, 6)) {
            continue;
        }

        if(ui->tblInvRight->item(i, 8)->text() != VAUCHER_ADVANCE_N) {
            continue;
        }

        QList<QVariant> row;
        row << ui->tblInvRight->toInt(i, 0)
            << ui->tblInvRight->toString(i, 3)
            << ui->tblInvRight->toString(i, 4)
            << ""
            << ui->tblInvRight->toString(i, 13);
        data << row;
    }

    if(data.count() == 0) {
        message_info(tr("Nothing to print"));
        return;
    }

    DlgPreTax *d = new DlgPreTax(this);
    d->setInvoice(ui->leInvoice->text());

    foreach(QList<QVariant> v, data) {
        d->addRow(v);
    }

    d->exec();
    delete d;
    loadInvoice(ui->leInvoice->text());
}

void WInvoice::on_btnPrevInvoice_clicked()
{
    int i = ui->leRoomCode->asInt();

    if(i == 0) {
        i = 1000;
    }

    CacheActiveRoom ar;

    if(i > 0) {
        while(i > 1) {
            i--;

            if(ar.get(i)) {
                ui->leRoomCode->setInt(i);
                loadInvoice(ar.fInvoice());
                return;
            }
        }

        message_info(tr("The start is reached"));
    }
}

void WInvoice::on_btnNextInvoice_clicked()
{
    int i = ui->leRoomCode->asInt();

    if(i == 0) {
        i = 1;
    }

    if(i > 0) {
        CacheActiveRoom ar;

        while(i < 700) {
            i++;

            if(ar.get(i)) {
                ui->leRoomCode->setInt(i);
                loadInvoice(ar.fInvoice());
                return;
            }
        }

        message_info(tr("The end is reached"));
    }
}

void WInvoice::on_btnTaxBack_clicked()
{
    QList<QList<QVariant> > rows;

    for(int i = 0; i < ui->tblInvLeft->rowCount(); i++) {
        if(ui->tblInvLeft->item(i, 6)->checkState() == Qt::Checked && ui->tblInvLeft->toInt(i, 6) > 0) {
            QList<QVariant> row;
            row << ui->tblInvLeft->toString(i, 0)
                << ui->tblInvLeft->toString(i, 3)
                << ui->tblInvLeft->toString(i, 4)
                << ui->tblInvLeft->toString(i, 8)
                << ui->tblInvLeft->toString(i, 8)
                << ui->tblInvLeft->toInt(i, 6);
            rows << row;
        }
    }

    for(int i = 0; i < ui->tblInvRight->rowCount(); i++) {
        if(ui->tblInvRight->item(i, 6)->checkState() == Qt::Checked && ui->tblInvRight->toInt(i, 6) > 0) {
            QList<QVariant> row;
            row << ui->tblInvRight->toString(i, 0)
                << ui->tblInvRight->toString(i, 3)
                << ui->tblInvRight->toString(i, 4)
                << ui->tblInvRight->toString(i, 8)
                << ui->tblInvRight->toInt(i, 6)
                << ui->tblInvRight->toInt(i, 6);
            rows << row;
        }
    }

    DlgTaxBack::taxBack(ui->leInvoice->text(), rows);
    loadInvoice(ui->leInvoice->text());
}

void WInvoice::on_btnAdvance_clicked()
{
    /*
    EQTableWidget *t = nullptr;
    int result = DlgPrintTaxSideOption::printTaxSide();
    switch (result) {
    case pts_none:
        return;
    case pts_guest:
        t = ui->tblInvLeft;
        break;
    case pts_company:
        t = ui->tblInvRight;
        break;
    }

    QSet<int> taxs;
    for (int i = 0; i < t->rowCount(); i++) {
        if (!isTaxPay(t->toString(i, 12))) {
            continue;
        }
        if (t->itemChecked(i, 6)) {
            continue;
        }

        CacheInvoiceItem c;
        if (!c.get(t->toString(i, 11))) {
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
        taxnumber = taxs.toList().at(0);
    } else if (taxs.count() > 1){
        DlgSelectFiscalMachin ds(taxs, this);
        ds.exec();
        taxnumber = ds.fSelectedMachine;
    }

    double suggestAmount = 0;
    for (int i = 0; i < t->rowCount(); i++) {
        CacheInvoiceItem c;
        if (!c.get(t->toString(i, 11))) {
            message_error(tr("Error in payment. c == 0, case 1."));
            return;
        }
        CacheTaxMap ci;
        if (!ci.get(c.fCode())) {
            message_error(tr("Tax department undefined for ") + c.fName());
            return;
        }
        if (ci.fTax() != taxnumber && t->toInt(i, 14) != taxnumber) {
            continue;
        }
        suggestAmount += (t->toInt(i, 1) * t->toDouble(i, 4));
    }
    */
    CacheInvoiceItem c;

    if(!c.get(fPreferences.getDb(def_advance_voucher_id).toInt())) {
        message_error(tr("Error in tax print. c == 0, case 1."));
        return;
    }

    CacheTaxMap ci;

    if(!ci.get(c.fCode())) {
        message_error(tr("Tax department undefined for ") + c.fName());
        return;
    }

    //DlgAdvanceEntry *d = new DlgAdvanceEntry(ui->leReserveID->text(), suggestAmount, this);
    //d->setFiscal(taxnumber);
    DlgAdvanceEntry *d = new DlgAdvanceEntry(ui->leReserveID->text(), 0, this);
    d->setFiscal(ci.fTax());
    d->setInvoice(ui->leInvoice->text());
    d->exec();
    delete d;
    loadInvoice(ui->leInvoice->text());
}

void WInvoice::on_btnManualTax_clicked()
{
    DoubleDatabase fDD;
    DlgPrintRandomTax *d = new DlgPrintRandomTax(this);
    d->setHeader(ui->leRoomCode->text(), ui->leGuest->text(), ui->leInvoice->text());
    d->exec();
    delete d;
    QList<QList<QVariant> > dbrows;
    fDD[":f_invoice"] = ui->leInvoice->text();
    fDD.exec("select f_id, f_source, f_item, f_amount, f_taxCode from m_free_tax where f_invoice=:f_invoice and f_used=0",
             dbrows);

    for(int i = 0; i < ui->tblInvLeft->rowCount(); i++) {
        if(ui->tblInvLeft->item(i, 6)->checkState() == Qt::Checked) {
            continue;
        }

        if(ui->tblInvLeft->toString(i, 8) == "RM" || ui->tblInvLeft->toString(i, 8) == "CH") {
            QMutableListIterator<QList<QVariant> >it(dbrows);

            while(it.hasNext()) {
                it.next();

                if(ui->tblInvLeft->toString(i, 8) == it.value().at(1).toString()) {
                    if(ui->tblInvLeft->toString(i, 8) == "RM") {
                        if(ui->tblInvLeft->toDouble(i, 4) == it.value().at(3).toDouble()) {
                            fDD[":f_used"] = 1;
                            fDD.update("m_free_tax", where_id(it.value().at(0).toInt()));
                            fDD[":f_fiscal"] = it.value().at(4);
                            fDD[":f_usedTaxId"] = it.value().at(0);
                            fDD.update("m_register", where_id(ap(ui->tblInvLeft->toString(i, 0))));
                            it.remove();
                        }
                    } else {
                        if(ui->tblInvLeft->toInt(i, 11) == it.value().at(2).toInt()
                                && ui->tblInvLeft->toDouble(i, 4) == it.value().at(3).toDouble()) {
                            fDD[":f_used"] = 1;
                            fDD.update("m_free_tax", where_id(it.value().at(0).toInt()));
                            fDD[":f_fiscal"] = it.value().at(4);
                            fDD[":f_usedTaxId"] = it.value().at(0);
                            fDD.update("m_register", where_id(ap(ui->tblInvLeft->toString(i, 0))));
                            it.remove();
                        }
                    }

                    goto next;
                }
            }
        }

next:
        continue;
    }

    fDD[":f_invoice"] = ui->leInvoice->text();
    fDD.exec("select f_id, f_source, f_item, f_amount, f_taxCode from m_free_tax where f_invoice=:f_invoice and f_used=0",
             dbrows);

    for(int i = 0; i < ui->tblInvRight->rowCount(); i++) {
        if(ui->tblInvRight->item(i, 6)->checkState() == Qt::Checked) {
            continue;
        }

        if(ui->tblInvRight->toString(i, 8) == "RM" || ui->tblInvRight->toString(i, 8) == "CH") {
            QMutableListIterator<QList<QVariant> >it(dbrows);

            while(it.hasNext()) {
                it.next();

                if(ui->tblInvRight->toString(i, 8) == it.value().at(1).toString()) {
                    if(ui->tblInvRight->toString(i, 8) == "RM") {
                        if(ui->tblInvRight->toDouble(i, 4) == it.value().at(3).toDouble()) {
                            fDD[":f_used"] = 1;
                            fDD.update("m_free_tax", where_id(it.value().at(0).toInt()));
                            fDD[":f_fiscal"] = it.value().at(4);
                            fDD[":f_usedTaxId"] = it.value().at(0);
                            fDD.update("m_register", where_id(ap(ui->tblInvRight->toString(i, 0))));
                            it.remove();
                        }
                    } else {
                        if(ui->tblInvRight->toInt(i, 11) == it.value().at(2).toInt()
                                && ui->tblInvRight->toDouble(i, 4) == it.value().at(3).toDouble()) {
                            fDD[":f_used"] = 1;
                            fDD.update("m_free_tax", where_id(it.value().at(0).toInt()));
                            fDD[":f_fiscal"] = it.value().at(4);
                            fDD[":f_usedTaxId"] = it.value().at(0);
                            fDD.update("m_register", where_id(ap(ui->tblInvRight->toString(i, 0))));
                            it.remove();
                        }
                    }

                    goto next2;
                }
            }
        }

next2:
        continue;
    }

    loadInvoice(ui->leInvoice->text());
}

void WInvoice::on_btnRefTax_clicked()
{
    /*
    EQTableWidget *t = ui->tblInvLeft;
    QModelIndexList l = ui->tblInvLeft->selectionModel()->selectedIndexes();
    if (l.count() == 0) {
        t = ui->tblInvRight;
        l = ui->tblInvRight->selectionModel()->selectedIndexes();
    }
    if (l.count() == 0) {
        message_info_tr("Nothing is selected");
        return;
    }
    */
    DlgTaxReference *d = new DlgTaxReference(0, this);
    d->setHeader(ui->leRoomCode->text(), ui->leGuest->text(), ui->leInvoice->text());
    //d->setItem(t->toString(l.at(0).row(), 3), t->toString(l.at(0).row(), 4), t->toInt(l.at(0).row(), 0));
    d->exec();
    delete d;
    loadInvoice(ui->leInvoice->text());
}

void WInvoice::on_btnTaxBack_2_clicked()
{
    QList<QVariant> rows;

    for(int i = 0; i < ui->tblInvLeft->rowCount(); i++) {
        if(ui->tblInvLeft->item(i, 6)->checkState() == Qt::Checked && ui->tblInvLeft->toInt(i, 6) > 1) {
            QList<QVariant> row;
            row << ui->tblInvLeft->toInt(i, 6);
            rows << row;
        }
    }

    for(int i = 0; i < ui->tblInvRight->rowCount(); i++) {
        if(ui->tblInvRight->item(i, 6)->checkState() == Qt::Checked && ui->tblInvRight->toInt(i, 6) > 1) {
            QList<QVariant> row;
            row << ui->tblInvLeft->toInt(i, 6);
            rows << row;
        }
    }

    DlgTaxBack2::taxBack(ui->leInvoice->text(), rows);
    loadInvoice(ui->leInvoice->text());
}

void WInvoice::on_btnPostBreakfast_clicked()
{
    DlgPostBreakfast::postBreakfast(ui->leInvoice->text(), DlgPostBreakfast::ptBreakfast);
    loadInvoice(ui->leInvoice->text());
}

void WInvoice::on_btnPostMinibar_clicked()
{
    DlgPostBreakfast::postBreakfast(ui->leInvoice->text(), DlgPostBreakfast::ptMinibar);
    loadInvoice(ui->leInvoice->text());
}

void WInvoice::on_btnWakeup_clicked()
{
    DlgWakepCalls::openWakeupCalls(ui->leRoomCode->text());
}

void WInvoice::on_btnDoNotDisturbe_clicked(bool checked)
{
    if(message_confirm(tr("Change the room state?")) != RESULT_YES) {
        ui->btnDoNotDisturbe->setChecked(!checked);
        return;
    }

    DoubleDatabase dd;
    dd[":f_donotdisturbe"] = (int) checked;
    dd[":f_id"] = ui->leRoomCode->asInt();
    dd.exec("update f_room set f_donotdisturbe=:f_donotdisturbe where f_id=:f_id");
    BroadcastThread::cmdRefreshCache(cid_room, ui->leRoomCode->text());
    BroadcastThread::cmdRefreshCache(cid_reservation, ui->leReserveID->text());
}

void WInvoice::on_btnResetAdvanceAmount_clicked()
{
    if(ui->lePrepaid->asDouble() < 0.01) {
        return;
    }

    if(message_confirm(tr("Reset available amount of advance?")) != QDialog::Accepted) {
        return;
    }

    DoubleDatabase dd;
    dd[":f_invoice"] = ui->leInvoice->text();
    dd[":f_amount"] = ui->lePrepaid->asDouble();
    dd.insert("f_used_advance", false);
    TrackControl::insert(1, "Reset available amount of advance", ui->lePrepaid->text(), "", "", ui->leInvoice->text(),
                         ui->leReserveID->text());

    if(ui->leInvoice->notEmpty()) {
        loadInvoice(ui->leInvoice->text());
    }
}

void WInvoice::on_btnPayment_clicked()
{
    EQTableWidget *t = nullptr;
    int result = DlgPrintTaxSideOption::printTaxSide();

    switch(result) {
    case pts_none:
        return;

    case pts_guest:
        t = ui->tblInvLeft;
        break;

    case pts_company:
        t = ui->tblInvRight;
        break;
    }

    if(fPreferences.getDb(def_tax_port).toInt() == 0) {
        message_error(tr("Setup tax printer first"));
    }

    QSet<int> taxs;

    for(int i = 0; i < t->rowCount(); i++) {
        if(!isTaxPay(t->toString(i, 12))) {
            continue;
        }

        if(t->itemChecked(i, 6)) {
            continue;
        }

        CacheInvoiceItem c;

        if(!c.get(t->toString(i, 11))) {
            message_error(tr("Error in tax print. c == 0, case 1."));
            continue;
        }

        CacheTaxMap ci;

        if(!ci.get(c.fCode())) {
            message_error(tr("Tax department undefined for ") + c.fName());
            return;
        }

        taxs.insert(ci.fTax());
    }

    int taxnumber = 0;

    if(taxs.count() == 1) {
        taxnumber = taxs.values().at(0);
    } else if(taxs.count() > 1) {
        DlgSelectFiscalMachin ds(taxs, this);
        ds.exec();
        taxnumber = ds.fSelectedMachine;
    } else {
        taxnumber = 1;
    }

    double suggestAmount = 0;

    for(int i = 0; i < t->rowCount(); i++) {
        CacheInvoiceItem c;

        if(!c.get(t->toString(i, 11))) {
            message_error(tr("Error in payment. c == 0, case 1."));
            return;
        }

        CacheTaxMap ci;

        if(!ci.get(c.fCode())) {
            message_error(tr("Tax department undefined for ") + c.fName());
            return;
        }

        if(ci.fTax() != taxnumber && t->toInt(i, 14) != taxnumber && taxnumber != 0) {
            continue;
        }

        suggestAmount += (t->toInt(i, 1) * t->toDouble(i, 4));
    }

    DlgReceiptVaucher d(taxnumber, suggestAmount, result - 1, this);
    d.setRoom(ui->leRoomCode->asInt());

    if(result == 2) {
        d.setCL(ui->leCityLedgerCode->asInt());
    }

    d.exec();
    loadInvoice(ui->leInvoice->text());
}
