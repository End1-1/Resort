#include "wreservationroomtab.h"
#include "ui_wreservationroomtab.h"
#include "wguest.h"
#include "cachereservation.h"
#include "cachereservestate.h"
#include "epushbutton.h"
#include "cacherights.h"
#include "dlgadvanceentry.h"
#include "dlgcheckadvancebeforecancel.h"
#include "cacheusers.h"
#include "paymentmode.h"
#include "dlgemail.h"
#include "cacheactiveroom.h"
#include "cacheredreservation.h"
#include "wreservation.h"
#include "cachecardex.h"
#include "dlggroupreserveoption.h"
#include "dlgcreategroupreservation.h"
#include "dlgadvanceentry.h"
#include "dlgnoshow.h"
#include "cachereservationcardex.h"
#include "cachereservestatus.h"
#include "dlgprintreservation.h"
#include "cacheinvoiceitem.h"
#include "vauchers.h"
#include "dlgreservationremarks.h"
#include "pprintcheckin.h"
#include <QKeyEvent>

#define HINT_SEARCH_GUEST 1
#define HINT_CARDEX 2
#define HINT_CITYLEDGER 3

WReservationRoomTab::WReservationRoomTab(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WReservationRoomTab)
{
    ui->setupUi(this);
    fReservation = static_cast<WReservation*>(parent);
    fDockItemSide = new DWReservationItemSize(fItemSide, this);
    fDockItemSide->hide();
    ui->leCardexCode->setSelector(this, cache(cid_cardex), ui->leCardexname, HINT_CARDEX);
    ui->leCardexCode->setInitialValue(fPreferences.getDb(def_default_cardex).toString());
    ui->leCityLedgerCode->setSelector(this, cache(cid_city_ledger), ui->leCityLedgerName, HINT_CITYLEDGER);
    ui->leStatusCode->setSelector(this, cache(cid_reserve_status), ui->leStatusName);
    ui->leStatusCode->setInitialValue(CONFIRM_CONFIRM);
    ui->leSearchGuest->setSelector(this, cache(cid_guest), ui->leSearchGuest, HINT_SEARCH_GUEST);    
    connect(ui->leRoomCode, SIGNAL(customButtonClicked(bool)), this, SLOT(roomSearch(bool)));
    connect(cache(cid_room), SIGNAL(updated(int,QString)), this, SLOT(roomCacheUpdated(int, QString)));
    QList<int> fWidths;
    fWidths << 0 << 50 << 220 << 30 << 30 << 30;
    for (int i = 0; i < ui->tblGuest->columnCount(); i++) {
        ui->tblGuest->setColumnWidth(i, fWidths.at(i));
    }
    fReservRoomId = 0;

    ui->deEntry->setDate(QDate::currentDate());
    ui->deDeparture->setDate(QDate::currentDate());
    ui->lbVAT->setText(QString("%1 %2%")
            .arg(tr("VAT"))
            .arg(QString::number(def_vat, 'f', 2)));
    ui->leReserveCode->setSelector(this, cache(cid_reserve_state), ui->leReserveName);
    ui->leReserveCode->setInitialValue(RESERVE_RESERVE);

    ui->cbPaymentType->setIndexForData(PAYMENT_CASH);
    ui->cbVAT->setIndexForData(VAT_INCLUDED);
    ui->leNoVATReason->setEnabled(ui->cbVAT->asInt() == VAT_NOVAT);

    setEarlyCheckIn(false);
    on_chLateCheckout_clicked(false);
    on_chExtraBed_stateChanged(0);
    ui->leArrivalFee->setValidator(new QDoubleValidator(0, 999999, 1));
    fStartDateOk = true;
    fEndDateOk = true;
    fCardexOk = true;
    fCityLedgerOk = true;
    fAuthor = WORKING_USERNAME;
    fLastModify = WORKING_USERNAME;

    ui->chMealIncluded->setChecked(true);
    on_chMealIncluded_clicked(true);
    ui->btnAppendAdvance->setVisible(r__(cr__advance_vaucher));

    connect(ui->teRoomRemarks, &EQTextEdit::doubleClicked, [this](){
        QString remark = ui->teRoomRemarks->toPlainText();
        if (DlgReservationRemarks::Remarks(remark)) {
            ui->teRoomRemarks->setPlainText(remark);
        }
    });

    connect(ui->leRoomCode, &EQLineEdit::focusOut, [this]() {
        checkDatesCross();
    });
}

WReservationRoomTab::~WReservationRoomTab()
{
    delete ui;
}

bool WReservationRoomTab::check(int room, const QDate &start, const QDate &end, const QString &rid, QString &errorMsg)
{
    DoubleDatabase fDD(true, doubleDatabase);
    if (room == 0) {
        return true;
    }
    fDD[":f_room"] = room;
    fDD[":f_s1"] = 1;
    fDD[":f_s2"] = 2;
    fDD[":f_s3"] = 9;
    fDD[":f_s4"] = 4;
    fDD.exec("select * from f_reservation where (f_state=:f_s1 or f_state=:f_s2 or f_state=:f_s3 or f_state=:f_s4) and f_room=:f_room order by f_id ");
    if (fDD.rowCount() == 0) {
        return true;
    }
    for (int i = 0; i < fDD.rowCount(); i++) {
        if (!rid.isEmpty()) {
            if (rid == fDD.getString(i, "f_id")) {
                continue;
            }
        }
        if (fDD.getInt(i, "f_state") == RESERVE_OUTOFINVENTORY || fDD.getInt(i, "f_state") == RESERVE_OUTOFROOM) {
            if (start == fDD.getDate(i, "f_endDate") || end == fDD.getDate(i, "f_startDate")) {
                errorMsg = tr("Conflict reservation id") + ": " + fDD.getString(i, "f_id");
                return false;
            }
        }
        if (start == end) {
            if (fDD.getValue(i, "f_startDate").toDate() == fDD.getValue(i, "f_endDate").toDate()) {
                if (fDD.getValue(i, "f_startDate").toDate() == start) {
                    errorMsg = tr("Conflict reservation id") + ": " + fDD.getValue(i, "f_id").toString();
                    return false;
                }
            }
            if (start == fDD.getValue(i, "f_endDate").toDate()) {

            }
        }
        if ((start <= fDD.getValue(i, "f_startDate").toDate())
                && (end >= fDD.getValue(i, "f_endDate").toDate())
                && (fDD.getValue(i, "f_startDate").toDate() != fDD.getValue(i, "f_endDate").toDate())) {
            errorMsg = tr("Conflict reservation id") + ": " + fDD.getValue(i, "f_id").toString();
            return false;
        }
        if (start > fDD.getValue(i, "f_startDate").toDate() && end < fDD.getValue(i, "f_endDate").toDate()) {
            errorMsg = tr("Conflict reservation id") + ": " + fDD.getValue(i, "f_id").toString();
            return false;
        }
        if (start <= fDD.getValue(i, "f_startDate").toDate()) {
            if (end > fDD.getValue(i, "f_startDate").toDate()) {
                if (fDD.getValue(i, "f_startDate").toDate() != fDD.getValue(i, "f_endDate").toDate()) {
                    errorMsg = tr("Conflict reservation id") + ": " + fDD.getValue(i, "f_id").toString();
                    return false;
                }
            }
        }
        if (end > fDD.getValue(i, "f_endDate").toDate()) {
            if (start < fDD.getValue(i, "f_endDate").toDate()) {
                errorMsg = tr("Conflict reservation id") + ": " + fDD.getValue(i, "f_id").toString();
                return false;
            }
        }
    }
    return true;
}

void WReservationRoomTab::setBaseData(const QDate &date1, const QDate &date2, const QString &rcode)
{
    disconnectSignals();
    ui->deEntry->setDate(date1);
    ui->deDeparture->setDate(date2);
    ui->sbNights->setValue(date1.daysTo(date2));
    CacheRoom room;
    if (room.get(rcode)) {
        ui->leRoomCode->setText(rcode);
        on_leRoomCode_returnPressed();
    }
    countTotal();
    connectSignals();
    checkDatesCross();
    emit roomChanged(ui->leRoomName->text(), fTabIndex);
}

void WReservationRoomTab::setTimes(const QTime &arrival, const QTime &departure)
{
    ui->teArrivalTime->setTime(arrival);
    ui->teDepartureTime->setTime(departure);
}

void WReservationRoomTab::setCardex(const QString &code)
{
    CacheCardex r;
    if (r.get(code)) {
        ui->leCardexCode->setText(r.fCode());
        ui->leCardexname->setText(r.fName());
        ui->leCommission->setText(r.fCommission());
        ui->cbVAT->setIndexForData(r.fVatMode().toInt());
    } else {
        ui->leCardexCode->clear();
        ui->leCardexname->clear();
    }
}

void WReservationRoomTab::setArrangement(int id)
{
    ui->cbArrangment->setIndexForData(id);
}

void WReservationRoomTab::setRoomPrice(const QString &text)
{
    ui->leRooming->setText(text);
    countTotal();
}

void WReservationRoomTab::setRemarks(const QString &remarks)
{
    ui->teRoomRemarks->setPlainText(remarks);
}

bool WReservationRoomTab::save()
{
    DoubleDatabase fDD(true, doubleDatabase);
    if (ui->leRoomCode->asInt() == 0) {
        if (ui->leReserveCode->asInt() == ROOM_STATE_CHECKIN) {
            message_error(tr("Cannot save reservation. Room code for checkin reservation must be specified"));
            return false;
        }
    }
    QString errorStr;
    if (!check(ui->leRoomCode->asInt(), ui->deEntry->date(), ui->deDeparture->date(), ui->leReservId->text(), errorStr)) {
        message_error(tr("Cannot save reservation") + "<br>" + errorStr);
        return false;
    }
    if (ui->leStatusCode->asInt() == 0) {
        message_error(tr("Cannot save reservation, status code is empty"));
        return false;
    }
    bool result = true;
    int createUser = 0;
    bool changeRoom = (ui->leReserveCode->asInt() == RESERVE_CHECKIN || ui->leReserveCode->asInt() == RESERVE_RESERVE);
    fDD.startTransaction();
    if (ui->leReservId->isEmpty() || ui->leReserveCode->fHiddenText == "1") {
        ui->leReserveCode->setInitialValue(RESERVE_RESERVE);
        ui->deCreated->setDate(WORKING_DATE);
        createUser = WORKING_USERID;
    }
    QString oldRoom = fTrackControl->oldValue(ui->leRoomCode);;
    if (ui->leReservId->notEmpty() && changeRoom) {
        if (fTrackControl->isValueChanged(ui->leRoomCode)) {
            /*------------- BEGIN CHANGE ROOM ------------------*/
            fDD[":f_upgradeFrom"] = fTrackControl->oldValue(ui->leRoomCode).toInt();
            result = result && fDD.update("f_reservation", where_id(ap(ui->leReservId->text())));
            if (result) {
                if (ui->leReserveCode->asInt() == RESERVE_CHECKIN) {
                    fDD[":f_state"] = ROOM_STATE_DIRTY;
                    result = result && fDD.update("f_room", where_id(fTrackControl->oldValue(ui->leRoomCode).toInt()));
                    fDD[":f_state"] = ROOM_STATE_CHECKIN;
                    result = result && fDD.update("f_room", where_id(ui->leReserveCode->asInt()));
                }
            }
            if (ui->leReserveCode->asInt() == RESERVE_CHECKIN) {
                fDD[":f_state"] = ROOM_STATE_DIRTY;
                result = result && fDD.update("f_room", where_id(fTrackControl->oldValue(ui->leRoomCode).toInt()));
                fDD[":f_state"] = ROOM_STATE_CHECKIN;
                result = result && fDD.update("f_room", where_id(ui->leRoomCode->asInt()));
            }
            if (fTrackControl->oldValue(ui->leRoomCode).toInt() > 0) {
                CacheRoom cr;
                if (cr.get(fTrackControl->oldValue(ui->leRoomCode).toInt())) {
                    ui->leUpgradeFrom->setText(cr.fName());
                }
            }
            /*-------------- END CHANGE ROOM ------------------*/
        }
        if (fTrackControl->isValueChanged(ui->leRooming) && result) {
            /* ------------------- BEGIN CHANGE ROOM RATE -----------------*/

            QString vid = ui->leReservId->text();
            QString rid = uuid(VAUCHER_ROOM_RATE_N);
            fDD.insertId("m_register", rid);
            fDD[":f_source"] = VAUCHER_ROOM_RATE_N;
            fDD[":f_res"] = vid;
            fDD[":f_wdate"] = WORKING_DATE;
            fDD[":f_rdate"] = QDate::currentDate();
            fDD[":f_time"] = QTime::currentTime();
            fDD[":f_user"] = WORKING_USERID;
            fDD[":f_room"] = ui->leRoomCode->text();
            fDD[":f_guest"] = ui->tblGuest->item(0, 2)->text();
            fDD[":f_itemCode"] = fPreferences.getDb(def_room_rate_change_id);
            fDD[":f_finalName"] = tr("ROOM RATE CHANGE FOR #") + ui->leReservId->text();
            fDD[":f_amountAmd"] = ui->leRooming->asDouble() - fTrackControl->oldValue(ui->leRooming).toDouble();
            fDD[":f_amountVat"] = 0;
            fDD[":f_amountUsd"] = def_usd;
            fDD[":f_fiscal"] = 0;
            fDD[":f_paymentMode"] = ui->cbPaymentType->currentData();
            fDD[":f_creditCard"] = 0;
            fDD[":f_cityLedger"] = ui->leCityLedgerCode->asInt();
            fDD[":f_paymentComment"] = vaucherPaymentName(ui->cbPaymentType->currentData().toInt(), 0, ui->leCityLedgerCode->text());
            fDD[":f_dc"] = "";
            fDD[":f_sign"] = 0;
            fDD[":f_doc"] = vid;
            fDD[":f_rec"] = 0;
            fDD[":f_finance"] = 0;
            fDD[":f_remarks"] = ui->teRoomRemarks->toPlainText();
            fDD[":f_canceled"] = 0;
            fDD[":f_cancelReason"] = "";
            fDD[":f_side"] = 0;
            fDD.update("m_register", where_id(ap(rid)));
            /* ------------------- END CHANGE ROOM RATE -----------------*/
        }
    }
    if (createUser > 0) {
        fDD[":f_author"] = createUser;
        fDD[":f_createTime"] = QDateTime::currentDateTime();
        fDD[":f_created"] = ui->deCreated->date();
    }
    fDD[":f_state"] = ui->leReserveCode->asInt();
    fDD[":f_reserveState"] = ui->leStatusCode->asInt();
    fDD[":f_invoice"] = ui->leInvoice->text();
    fDD[":f_room"] = ui->leRoomCode->asInt();
    fDD[":f_arrangement"] = ui->cbArrangment->currentData();
    fDD[":f_mealIncluded"] = (int) ui->chMealIncluded->isChecked();
    fDD[":f_guest"] = firstGuestId();
    fDD[":f_man"] = ui->sbMan->value();
    fDD[":f_woman"] = ui->sbWoman->value();
    fDD[":f_child"] = ui->sbChild->value();
    fDD[":f_baby"] = ui->sbBaby->value();
    fDD[":f_cardex"] = ui->leCardexCode->text();
    fDD[":f_cityLedger"] = ui->leCityLedgerCode->asInt();
    fDD[":f_startDate"] = ui->deEntry->date();
    fDD[":f_endDate"] = ui->deDeparture->date();
    fDD[":f_arrivalTime"] = ui->teArrivalTime->time();
    fDD[":f_arrivalFee"] = ui->leArrivalFee->asDouble();
    fDD[":f_departureTime"] = ui->teDepartureTime->time();
    fDD[":f_earlyCheckIn"] = (int) ui->chEarlyCheckIn->isChecked();
    fDD[":f_earlyCheckInTime"] = ui->teEarlyCheckIn->time();
    fDD[":f_earlyCheckInFee"] = ui->leEarlyCheckInFee->asDouble();
    fDD[":f_lateCheckOut"] = (int) ui->chLateCheckout->isChecked();
    fDD[":f_lateCheckOutTime"] = ui->teLateChecout->time();
    fDD[":f_lateCheckOutFee"] = ui->leLateCheckoutFee->asDouble();
    fDD[":f_paymentType"] = ui->cbPaymentType->asInt();
    fDD[":f_roomFee"] = ui->leRooming->asDouble();
    fDD[":f_mealQty"] = ui->sbMealQty->value();
    fDD[":f_mealPrice"] = ui->leMealPrice->asDouble();
    fDD[":f_extraBed"] = ui->chExtraBed->isChecked();
    fDD[":f_extraBedFee"] = ui->leExtraBedAmount->asDouble();
    fDD[":f_pricePerNight"] = ui->lePricePerNight->asDouble();
    fDD[":f_vat"] = def_vat;
    fDD[":f_vatAmount"] = ui->leVAT->asDouble();
    fDD[":f_vatMode"] = ui->cbVAT->asInt();
    fDD[":f_total"] = ui->leTotal->asDouble();
    fDD[":f_grandTotal"] = ui->leGrandTotal->asDouble();
    fDD[":f_totalUSD"] = ui->leTotalUSD->asDouble();
    fDD[":f_novatReason"] = ui->leNoVATReason->text();
    fDD[":f_remarks"] = ui->teRoomRemarks->toPlainText();
    fDD[":f_commission"] = ui->leCommission->asDouble();
    fDD[":f_group"] = fReservation->groupId();
    fDD[":f_booking"] = ui->leBooking->text();
    fDD[":f_pickup"] = (int) ui->chPickup->isChecked();
    fDD[":f_lastEdit"] = WORKING_USERID;
    if (result) {
        if (ui->leReservId->isEmpty()) {
            DoubleDatabase did;
            did.open(true, true);
            QString rsId = uuid(VAUCHER_RESERVATION_N);
            result = did.insertId("f_reservation", rsId);
            fDD[":f_author"] = WORKING_USERID;
            ui->leReservId->setText(rsId);
            QString invId = uuid("IN");
            ui->leInvoice->setText(invId);
            fDD[":f_invoice"] = invId;
            fTrackControl->fReservation = rsId;
            fTrackControl->fInvoice = invId;
        }
    }
    if (fTrackControl->hasChanges()) {
        fDD[":f_lastEdit"] = WORKING_USERID;
    }
    if (result) {
        result = fDD.update("f_reservation", where_id(ap(ui->leReservId->text())));
    }
    if (createUser > 0) {
        fDD[":f_id"] = ui->leReservId->text();
        fDD.exec("update f_reservation_last set f_id=:f_id");
    }
    if (result) {
        result = result && fDD.exec(QString("delete from f_reservation_guests where f_reservation='%1'").arg(ui->leReservId->text()));
        if (result) {
            for (int i = 0; i < ui->tblGuest->rowCount(); i++) {
                fDD[":f_reservation"] = ui->leReservId->text();
                fDD[":f_guest"] = ui->tblGuest->item(i, 0)->data(Qt::DisplayRole).toInt();
                if (i == 0) {
                    fDD[":f_first"] = 1;
                } else {
                    fDD[":f_first"] = 0;
                }
                result = result && fDD.insert("f_reservation_guests", false);
                if (!result) {
                    break;
                }
            }
        }
    }
    bool first = true;
    QString query = "";
    for (QList<int>::const_iterator it =  fItemSide.begin(); it != fItemSide.end(); it++) {
        if (first) {
            first = false;
        } else {
            query += ",";
        }
        query += QString("('%1', %2)").arg(ui->leReservId->text()).arg(*it);
    }
    if (query.length() > 0) {
        query = "insert into f_reservation_item_side (f_reservation, f_itemId) values " + query;
        if (result) {
            result = fDD.exec(query);
        }
    }
    if (result && !oldRoom.isEmpty()) {
        fDD[":f_room"] = ui->leRoomCode->text();
        result = result && fDD.exec("update m_register set f_room=:f_room where f_inv=" + ap(ui->leInvoice->text()));
    }
    if (result) {
        ui->btnAppendAdvance->setEnabled(true);
        fDD.commit();
        emit commonChanges();
        fTrackControl->saveChanges();
        saveVaucher();
        BroadcastThread::cmdRefreshCache(cid_reservation, ui->leReservId->text());
        BroadcastThread::cmdRefreshCache(cid_room, ui->leRoomCode->text());
        BroadcastThread::cmdRefreshCache(cid_red_reservation, ui->leReservId->text());
        BroadcastThread::cmdRefreshCache(cid_reservation_cardex, ui->leReservId->text());
        if (!oldRoom.isEmpty()) {
            BroadcastThread::cmdRefreshCache(cid_room, oldRoom);
            BroadcastThread::cmdRefreshCache(cid_active_room, oldRoom);
            BroadcastThread::cmdRefreshCache(cid_active_room, ui->leRoomCode->text());

        }
    } else {
        fDD.rollback();
    }
    fDD.close();
    fDD.open(true, true);
    return result;
}

void WReservationRoomTab::print()
{
    DlgPrintReservation *d = new DlgPrintReservation(this);
    d->exec();
    delete d;
}

QString WReservationRoomTab::roomName()
{
    return ui->leRoomCode->text();
}

QString WReservationRoomTab::roomCode()
{
    return ui->leRoomCode->text();
}

QDate WReservationRoomTab::date1()
{
    return ui->deEntry->date();
}

QDate WReservationRoomTab::date2()
{
    return ui->deDeparture->date();
}

QString WReservationRoomTab::docId()
{
    return ui->leReservId->text();
}

void WReservationRoomTab::loadReservation(const QString &id)
{
    disconnectSignals();
    ui->leReservId->setText(id);
    QString query = "select "
            "f_state,"
            "f_reserveState,"
            "f_invoice,"
            "f_room,"
            "f_arrangement,"
            "f_mealIncluded,"
            "f_invoice,"
            "f_guest,"
            "f_man,"
            "f_woman,"
            "f_child,"
            "f_baby,"
            "f_cardex,"
            "f_cityLedger,"
            "f_startDate,"
            "f_endDate,"
            "f_arrivalTime,"
            "f_arrivalFee,"
            "f_departureTime,"
            "f_earlyCheckIn,"
            "f_earlyCheckInTime,"
            "f_earlyCheckInFee,"
            "f_lateCheckOut,"
            "f_lateCheckOutTime,"
            "f_lateCheckOutFee,"
            "f_paymentType,"
            "f_roomFee,"
            "f_mealQty,"
            "f_mealPrice,"
            "f_extraBed,"
            "f_extraBedFee,"
            "f_pricePerNight,"
            "f_vat,"
            "f_vatAmount,"
            "f_vatMode,"
            "f_total,"
            "f_grandTotal,"
            "f_totalUSD,"
            "f_novatReason,"
            "f_remarks, "
            "f_commission,"
            "f_upgradeFrom, "
            "f_created, "
            "f_author,"
            "f_lastEdit, "
            "f_group, "
            "f_booking, "
            "f_pickup "
            "from f_reservation "
            "where f_id=" + ap(ui->leReservId->text());
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.exec(query);
    if (!fDD.nextRow()) {
        message_error(tr("Invalid reservation code"));
        return;
    }
    if (fDD.getInt(1) == RESERVE_SERVICE) {
        startTrackControl();
        fDD[":f_table"] = TRACK_RESERVATION;
        fDD[":f_windowId"] = ui->leReservId->text();
        //fDD.exec("delete from f_changes_tracking where f_table=:f_table and f_windowId=:f_windowsId");
        fTrackControl->resetChanges();
    }
    int c = 0;
        QList<QVariant> &row = fDD.fDbRows[0];
        ui->leReserveCode->setInt(row.at(c++).toInt());
        if (ui->leReserveCode->asInt() == RESERVE_SERVICE) {
            ui->leReserveCode->setInitialValue(RESERVE_RESERVE);
            ui->leReserveCode->fHiddenText = "1";
        }

        ui->leStatusCode->setInitialValue(row.at(c++).toInt());
        if (ui->leStatusCode->asInt() == CONFIRM_BLOCK) {
            ui->leStatusCode->setInitialValue(CONFIRM_TENTATIVE);
        }

        ui->leInvoice->setText(row.at(c++).toString());
        ui->leRoomCode->setText(row.at(c++).toString());
        ui->cbArrangment->setIndexForData(row.at(c++));
        ui->chMealIncluded->setChecked((bool) row.at(c++).toInt());
        c++; //Skip invoice
        c++; //Skip main guest
        ui->sbMan->setValue(row.at(c++).toInt());
        ui->sbWoman->setValue(row.at(c++).toInt());
        ui->sbChild->setValue(row.at(c++).toInt());
        ui->sbBaby->setValue(row.at(c++).toInt());
        ui->leCardexCode->setInitialValue(row.at(c++).toString());
        ui->leCityLedgerCode->setInitialValue(row.at(c++).toString());
        ui->deEntry->setDate(row.at(c++).toDate());
        ui->deDeparture->setDate(row.at(c++).toDate());
        ui->sbNights->setValue(ui->deEntry->date().daysTo(ui->deDeparture->date()));
        ui->teArrivalTime->setTime(row.at(c++).toTime());
        ui->leArrivalFee->setText(row.at(c++).toString());
        ui->teDepartureTime->setTime(row.at(c++).toTime());
        ui->chEarlyCheckIn->setChecked(row.at(c++).toInt());
        ui->teEarlyCheckIn->setTime(row.at(c++).toTime());
        ui->leEarlyCheckInFee->setText(row.at(c++).toString());
        ui->chLateCheckout->setChecked(row.at(c++).toInt());
        ui->teLateChecout->setTime(row.at(c++).toTime());
        ui->leLateCheckoutFee->setDouble(row.at(c++).toDouble());
        ui->cbPaymentType->setIndexForData(row.at(c++).toInt());
        ui->leRooming->setText(row.at(c++).toString());
        ui->sbMealQty->setValue(row.at(c++).toInt());
        ui->leMealPrice->setText(row.at(c++).toString());
        ui->chExtraBed->setChecked(row.at(c++).toInt());
        ui->leExtraBedAmount->setText(row.at(c++).toString());
        ui->lePricePerNight->setText(row.at(c++).toString());
        c++; //Skip VAT value
        ui->leVAT->setText(row.at(c++).toString());
        ui->cbVAT->setIndexForData(row.at(c++).toInt());
        ui->leTotal->setText(row.at(c++).toString());
        ui->leGrandTotal->setText(row.at(c++).toString());
        ui->leTotalUSD->setText(row.at(c++).toString());
        ui->leNoVATReason->setText(row.at(c++).toString());
        ui->teRoomRemarks->setPlainText(row.at(c++).toString());
        ui->leCommission->setText(row.at(c++).toString());
        QString roomUpgradeFrom = row.at(c++).toString();
        if (roomUpgradeFrom.toInt() > 0) {
            CacheRoom cr;
            if (cr.get(roomUpgradeFrom)) {
                ui->leUpgradeFrom->setText(cr.fName());
            }
        }
        ui->deCreated->setDate(row.at(c++).toDate());
        CacheUsers cu;
        if (cu.get(row.at(c++).toString())) {
            fAuthor = cu.fName();
        }
        if (cu.get(row.at(c++).toString())) {
            fLastModify = cu.fName();
        }
        c++; // skip group id
        ui->leBooking->setText(row.at(c++).toString());
        ui->chPickup->setChecked(row.at(c++).toInt());
        /// END OF ROW


        ui->leRoomName->clear();
        if (ui->leRoomCode->asInt() == 0) {
            ui->leRoomCode->clear();
            ui->lbRoom->setPixmap(QPixmap(":/images/question.png"));
        }
        CacheRoom r;
        if (!r.get(ui->leRoomCode->text())) {
            ui->lbRoom->setPixmap(QPixmap(":/images/warning.png"));
        } else {
            ui->lbRoom->setPixmap(QPixmap(":/images/ok.png"));
            ui->leRoomName->setText(r.fName());
            emit roomChanged(r.fName(), fTabIndex);
        }

        checkDatesCross();
        int vatIndex = ui->cbVAT->currentIndex();

        ui->cbVAT->setCurrentIndex(vatIndex);
        if (ui->leReserveCode->asInt() == RESERVE_SERVICE) {
            ui->cbVAT->setCurrentIndex(0);
        }


    query = "select r.f_guest, g.f_title, concat(g.f_firstName, ' ' , g.f_lastName), "
            "g.f_tel1, g.f_remarks "
            "from f_reservation_guests r "
            "left join f_guests g on g.f_id=r.f_guest "
            "where r.f_reservation=:f_reservation "
            "order by r.f_first desc ";
    fDD[":f_reservation"] = ui->leReservId->text();
    fDD.exec(query);
    ui->tblGuest->clearContents();
    ui->tblGuest->setRowCount(0);
    for (QList<QList<QVariant> >::const_iterator it = fDD.fDbRows.begin(); it != fDD.fDbRows.end(); it++) {
        CacheGuest g;
        g.get(it->at(0).toString());
        addGuest(g, false);
    }
    getAdvance();
    ui->btnAppendAdvance->setEnabled(ui->leReserveCode->asInt() == RESERVE_RESERVE);
    ui->leNoVATReason->setEnabled(ui->cbVAT->asInt() == VAT_NOVAT);
    on_cbPaymentType_currentIndexChanged(0);
    fItemSide.clear();
    query = "select f_itemId from f_reservation_item_side where f_reservation=:f_reservation";
    fDD[":f_reservation"] = ui->leReservId->text();
    fDD.exec(query);
    while (fDD.nextRow()) {
        fItemSide.append(fDD.getInt(0));
    }
    //Meal
    ui->sbMealQty->setEnabled(!ui->chMealIncluded->isChecked());
    ui->leMealPrice->setEnabled(!ui->chMealIncluded->isChecked());
    connectSignals();
    if (ui->leReserveCode->asInt() == RESERVE_CHECKIN)  {
        ui->deEntry->setEnabled(false);
    }
    bool editable = ui->leReserveCode->asInt() == RESERVE_RESERVE
            || ui->leReserveCode->asInt() == RESERVE_CHECKIN
            || ui->leReserveCode->asInt() == RESERVE_SERVICE;
    setGroupBoxesEnabled(editable);
    emit commonChanges();

    fTrackControl->fInvoice = ui->leInvoice->text();
    fTrackControl->fReservation = ui->leReservId->text();
    if (ui->leReserveCode->asInt() == RESERVE_SERVICE) {
        fTrackControl->saveChanges();
    }
    fTrackControl->resetChanges();
    fInitCardex = ui->leCardexCode->text();
}

void WReservationRoomTab::setGuest(int id, bool removeFirst)
{
    CacheGuest g;
    if (!g.get(id)) {
        return;
    }
    if (removeFirst) {
        for (int i = 0; i < ui->tblGuest->rowCount(); i++) {
            fTrackControl->insert("Guest removed", ui->tblGuest->item(0, 1)->text() + " " + ui->tblGuest->item(0, 2)->text(), "");
            ui->tblGuest->removeRow(0);
        }
    }
    addGuest(g, true);
}

bool WReservationRoomTab::canRecheckin()
{
    bool result = ui->leReserveCode->asInt() == RESERVE_CHECKOUT;
    CacheRoom c;
    if (!c.get(ui->leRoomCode->text())) {
        return false;
    }
    result = result && c.fState() == ROOM_STATE_NONE;
    result = result && ui->deDeparture->date() == WORKING_DATE;
    return result;
}

void WReservationRoomTab::reCheckin()
{
    QString errors;
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_room"] = ui->leRoomCode->asInt();
    fDD[":f_state"] = RESERVE_CHECKIN;
    fDD.exec("select f_id from f_reservation where f_room=:f_room and f_state=:f_state");
    if (fDD.rowCount() > 0) {
        errors += tr("Cannot checkin this room, becouse another reservation active") + "<br>";
    }
    if (ui->deDeparture->date() < WORKING_DATE) {
        errors += tr("Cannot re-checkin, date was expired") + "<br>";
    }
    CacheRoom c;
    if (!c.get(ui->leRoomCode->text())) {
        errors += tr("Program error. Contact to developer. Message: ReCheckIn: CacheRoom==0") + "<br>";
    }
    if (c.fState() != ROOM_STATE_NONE) {
        errors += tr("Change room state to 'Vacant ready' first") + "<br>";
    }
    bool passport = false;
    for (int i = 0; i < ui->tblGuest->rowCount(); i++) {
        CacheGuest g;
        if (!g.get(ui->tblGuest->toString(i, 0))) {
            continue;
        }
        if (g.fNatShort().isEmpty() || g.fNatShort() == "-") {
            errors += tr("Nationality for ") + g.fName() + tr(" must be defined") + "<br>";
        }
        if (!g.fPassport().isEmpty()) {
            passport = true;
        }
    }
    if (!passport && fPreferences.getDb(def_passport_required).toBool()) {
        errors += tr("Guest(s) dont have a passport?");
    }
    if (!errors.isEmpty()) {
        message_error(errors);
        return;
    }
    ui->leReserveCode->setInitialValue(RESERVE_CHECKIN);
    fDD[":f_state"] = RESERVE_CHECKIN;
    fDD.update("f_reservation", where_id(ap(ui->leReservId->text())));
    fDD[":f_state"] = ROOM_STATE_CHECKIN;
    fDD.update("f_room", where_id(ui->leRoomCode->asInt()));
    fTrackControl->insert("Recheckin", "", "");
    setGroupBoxesEnabled(true);
    save();
    BroadcastThread::cmdRefreshCache(cid_reservation, ui->leReservId->text());
    BroadcastThread::cmdRefreshCache(cid_room, ui->leRoomCode->text());
    BroadcastThread::cmdRefreshCache(cid_active_room, ui->leRoomCode->text());
    message_info(tr("Re-checkin completed"));
}

bool WReservationRoomTab::canCheckIn(QString &why)
{
    bool result = ui->leReservId->notEmpty();
    if (ui->leReservId->isEmpty()) {
        why += tr("Reservation not saved\r\n");
    }
    result = result && ui->leRoomName->text().length() > 0;
    if (ui->leRoomCode->asInt() == 0) {
        why += tr("Room is not selected\r\n");
    }
    result = result && ui->deEntry->date() == WORKING_DATE;
    if (ui->deEntry->date() != WORKING_DATE) {
        why += tr("Date of entry is not equal to working date\r\n");
    }
    result = result && ui->leReserveCode->asInt() == RESERVE_RESERVE;
    if (ui->leReserveCode->asInt() != RESERVE_RESERVE) {
        why += tr("Reservatin state should be 'Reserved'\r\n");
    }
    CacheRoom r;
    result = result && r.fValid;
    if (r.get(ui->leRoomCode->text())) {
        result = result && r.fState() == ROOM_STATE_NONE;
        if (r.fState() != ROOM_STATE_NONE) {
            why += tr("Room state is not vacant ready\r\n");
        }
    }
    return result;
}

bool WReservationRoomTab::checkIn(QString &errorString)
{
    bool error = false;
    if (QTime::currentTime() < fPreferences.getDb(def_earyly_checkin).toTime()) {
        if (!ui->chEarlyCheckIn->isChecked() || ui->leEarlyCheckInFee->asDouble() < 0.01) {
            if (fPreferences.getDb(def_earyly_checkin_id).toInt() == 0) {
                message_error(tr("Early checkin code not define in the settings. Contact to administrator."));
                return false;
            }
            switch (message_yesnocancel("Charge early checkin fee? Yes - return to editor")) {
            case RESULT_YES:
                return false;
            case RESULT_NO:
                break;
            case RESULT_CANCEL:
                return false;
            }
        }
    }
    ui->lbRoom->setStyleSheet("color:black");
    if (ui->leRoomName->text().length() == 0) {
        errorString += tr("No room selected for this reservation") + "<br>";
        ui->lbRoom->setStyleSheet("color:red");
        error = true;
    }
    if (ui->sbMan->value() + ui->sbWoman->value() < 1) {
        errorString += tr("Guests count cannot be equal to zero") + "<br>";
        error = true;
    }
    ui->lbStatusCode->setStyleSheet("color:black");
    if (ui->leStatusCode->asInt() == 0) {
        error = true;
        errorString += tr("Status code is not defined") + "<br>";
        ui->lbStatusCode->setStyleSheet("color:red");
    }
    ui->lbRoomPrice->setStyleSheet("color:black");
    if (ui->leRooming->text().toFloat() < 0.1 && ui->cbPaymentType->currentData().toInt() != PAYMENT_COMPLIMENTARY) {
        //message_error_tr("Price is not defined");
        //ui->lbRoomPrice->setStyleSheet("color:red");
        //return false;
    }
    bool passportFound = false;
    for (int i = 0; i < ui->tblGuest->rowCount(); i++) {
        CacheGuest g;
        if (g.get(ui->tblGuest->item(i, 0)->text())) {
            if (g.fPassport().isEmpty()) {
                continue;
            } else {
                passportFound = true;
                break;
            }
        }
    }
    if (!passportFound && fPreferences.getDb(def_passport_required).toBool()) {
        errorString += tr("No passport record found for registered guest") + "<br>";
        error = true;
    }
    bool nationsOk = true;
    for (int i = 0; i < ui->tblGuest->rowCount(); i++) {
        CacheGuest g;
        if (g.get(ui->tblGuest->item(i, 0)->text())) {
            if (g.fNatShort().trimmed().isEmpty() || g.fNatShort() == "-") {
                nationsOk = false;
                break;
            }
        } else {
            nationsOk = false;
            break;
        }
    }
    if (!nationsOk) {
        errorString += tr("Check nations for all guests") + "<br>";
        error = true;
    }

    bool result = save();
    if (!result) {
        return false;
    }
    QDate date = WORKING_DATE;
    if (ui->deEntry->date() != date) {
        errorString += "<br>" + tr("The entry date is not equal to working date");
        error = true;
    }
    if (ui->leArrivalFee->asDouble() > 0.1) {
        if (fPreferences.getDb(def_airport_pickup_id).toInt() == 0) {
            errorString += tr("Airport pickup id not defined in the config. Contact to administrator");
            error = true;
        }
    }
    if (fPreferences.getDb(def_earyly_checkin_id).toInt() == 0) {
        errorString += tr("Early checkin id is not defined. Contact to administrator");
        error = true;
    }
    CacheRoom cri;
    cri.get(ui->leRoomCode->text());
    if (cri.fState() != ROOM_STATE_NONE) {
        errorString += tr("Room is not vacant ready");
        error = true;
    }
    if (error) {
        return false;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.startTransaction();
    if (result) {
        fDD[":f_state"] = RESERVE_CHECKIN;
        fDD[":f_checkInDate"] = WORKING_DATE;
        fDD[":f_checkInTime"] = QTime::currentTime();
        fDD[":f_checkInUser"] = WORKING_USERID;
        result = result && fDD.update("f_reservation", where_id(ap(ui->leReservId->text())));
    }
    if (result) {
        fDD[":f_state"] = ROOM_STATE_CHECKIN;
        result = result && fDD.update("f_room", where_id(ui->leRoomCode->asInt()));

        fDD[":f_date"] = QDate::currentDate();
        fDD[":f_wdate"] = WORKING_DATE;
        fDD[":f_time"] = QTime::currentTime();
        fDD[":f_oldState"] = ROOM_STATE_NONE;
        fDD[":f_newState"] = ROOM_STATE_CHECKIN;
        fDD[":f_user"] = WORKING_USERID;
        fDD[":f_comment"] = "CHECKIN";
        fDD[":f_reservation"] = ui->leReservId->text();
        fDD.insert("f_room_state_change", false);
    }

    /*------------------------ BEGIN ADVANCE -------------------*/
    if (result) {
            fDD[":f_source"] = VAUCHER_ADVANCE_N;
            fDD[":f_res"] = ui->leReservId->text();
            fDD.exec("select f_id, f_fiscal, f_amountAmd "
                       "from m_register where f_canceled=0 and f_source=:f_source "
                       "and f_rec=:f_rec");
            while (fDD.nextRow()) {
                int fiscal = fDD.getInt(1);
                fDD[":f_inv"] = ui->leInvoice->text();
                fDD[":f_room"] = ui->leRoomCode->text();
                result = result && fDD.update("m_register", where_id(ap(fDD.getString(0))));
                if (fiscal > 0) {
                    DoubleDatabase db;
                    db[":f_prepaid"] = fDD.getDouble(2);
                    db[":f_id"] = ui->leInvoice->text();
                    db.exec("update m_v_invoice set f_prepaid=f_prepaid+:f_prepaid where f_id=:f_id");
                }
            }
    }
    /*------------------------ END ADVANCE ----------------------*/
    /*------------------------ BEGIN EARLY CHECKIN FEE ----------------*/
    if (result) {
        if (ui->leEarlyCheckInFee->asDouble() > 0.1) {
            CacheInvoiceItem ii;
            ii.get(fPreferences.getDb(def_earyly_checkin_id).toString());
            fDD[":f_id"] = 0;
            int vid = fDD.insert("m_v_postcharge");
            fDD[":f_id"] = 0;
            int rid = fDD.insert("m_register");
            fDD[":f_source"] = ii.fVaucher();
            fDD[":f_wdate"] = WORKING_DATE;
            fDD[":f_rdate"] = QDate::currentDate();
            fDD[":f_time"] = QTime::currentTime();
            fDD[":f_user"] = WORKING_USERID;
            fDD[":f_room"] = ui->leRoomCode->text();
            fDD[":f_guest"] = ui->tblGuest->item(0, 2)->text();
            fDD[":f_itemCode"] = fPreferences.getDb(def_earyly_checkin_id).toInt();
            fDD[":f_finalName"] = ii.fName();
            fDD[":f_amountAmd"] = ui->leEarlyCheckInFee->asDouble();
            fDD[":f_amountVat"] = Utils::countVATAmount(ui->leEarlyCheckInFee->asDouble(), ui->cbVAT->currentData().toInt());
            fDD[":f_amountUsd"] = def_usd;
            fDD[":f_fiscal"] = 0;
            fDD[":f_paymentMode"] = PAYMENT_CREDIT;
            fDD[":f_creditCard"] = 0;
            fDD[":f_cityLedger"] = 0;
            fDD[":f_paymentComment"] = "";
            fDD[":f_dc"] = "CREDIT";
            fDD[":f_sign"] = 1;
            fDD[":f_doc"] = vid;
            fDD[":f_rec"] = 0;
            fDD[":f_inv"] = ui->leInvoice->text();
            fDD[":f_finance"] = 1;
            fDD[":f_remarks"] = "";
            fDD[":f_canceled"] = 0;
            fDD[":f_cancelReason"] = "";
            fDD[":f_side"] = fItemSide.contains(fPreferences.getDb(def_earyly_checkin_id).toInt());
            result = result && fDD.update("m_register", where_id(ap(rid)));

            if (result) {
                fTrackControl->insert("Auto early checkin fee", QString("%1 / %2 / %3")
                             .arg(WORKING_DATE.toString(def_date_format))
                             .arg(ui->teEarlyCheckIn->time().toString(def_time_format))
                             .arg(ui->leEarlyCheckInFee->text()), "");
            }
        }
    }
    /*------------------------ END EARLY CHECKIN FEE ----------------*/
    /*------------------------ AIRPORT PICKUP -------------------------*/
    if (result) {
        if (ui->leArrivalFee->asDouble() > 0.1) {
            CacheInvoiceItem ia;
            ia.get(fPreferences.getDb(def_airport_pickup_id).toString());
            fDD[":f_id"] = 0;
            int vid = fDD.insert("m_v_receipt");
            fDD[":f_id"] = 0;
            int rid = fDD.insert("m_register");
            fDD[":f_source"] = ia.fVaucher();
            fDD[":f_wdate"] = WORKING_DATE;
            fDD[":f_rdate"] = QDate::currentDate();
            fDD[":f_time"] = QTime::currentTime();
            fDD[":f_user"] = WORKING_USERID;
            fDD[":f_room"] = ui->leRoomCode->text();
            fDD[":f_guest"] = ui->tblGuest->item(0, 2)->text();
            fDD[":f_itemCode"] = ia.fCode();
            fDD[":f_finalName"] = ia.fName();
            fDD[":f_amountAmd"] = ui->leArrivalFee->asDouble();
            fDD[":f_amountVat"] = Utils::countVATAmount(ui->leArrivalFee->asDouble(), ui->cbVAT->currentData().toInt());
            fDD[":f_amountUsd"] = def_usd;
            fDD[":f_fiscal"] = 0;
            fDD[":f_paymentMode"] = PAYMENT_CREDIT;
            fDD[":f_creditCard"] = 0;
            fDD[":f_cityLedger"] = 0;
            fDD[":f_paymentComment"] = "";
            fDD[":f_dc"] = "CREDIT";
            fDD[":f_sign"] = 1;
            fDD[":f_doc"] = vid;
            fDD[":f_rec"] = 0;
            fDD[":f_inv"] = ui->leInvoice->text();
            fDD[":f_finance"] = 1;
            fDD[":f_remarks"] = "";
            fDD[":f_canceled"] = 0;
            fDD[":f_cancelReason"] = "";
            fDD[":f_side"] = fItemSide.contains(fPreferences.getDb(def_earyly_checkin_id).toInt());
            result = result && fDD.update("m_register", where_id(ap(rid)));
            if (result) {
                fTrackControl->insert("Auto airport pickup fee", QString("%1 / %2 ")
                             .arg(WORKING_DATE.toString(def_date_format))
                             .arg(ui->leArrivalFee->text()), "");
            }
        }
    }
    /*------------------------ END AIRPORT PICKUP -------------------------*/
    if (result) {
        fDD.commit();
        ui->leReserveCode->setInitialValue(RESERVE_CHECKIN);
        ui->leStatusCode->setInitialValue(CONFIRM_GUARANTEED);
        ui->deEntry->setEnabled(false);
        fTrackControl->saveChanges();
        BroadcastThread::cmdRefreshCache(cid_red_reservation, ui->leReservId->text());
        BroadcastThread::cmdRefreshCache(cid_reservation, ui->leReservId->text());
        BroadcastThread::cmdRefreshCache(cid_room, ui->leRoomCode->text());
        BroadcastThread::cmdRefreshCache(cid_active_room, ui->leRoomCode->text());
        PPrintCheckin::print(ui->leReservId->text());
    } else {
        fDD.rollback();
    }
    return result;
}

bool WReservationRoomTab::canCancel()
{
    bool result = true;
    result = result && ui->leReservId->notEmpty();
    result = result && ui->leReserveCode->asInt() == RESERVE_RESERVE;
    return result;
}

bool WReservationRoomTab::cancelReservation(bool confirm)
{
    if (ui->leReserveCode->asInt() == RESERVE_REMOVED) {
        return true;
    }
    int cr = DlgCheckAdvanceBeforeCancel::checkAdvance(ui->leInvoice->text());
    getAdvance();
    switch (cr) {
    case CR_NOCANCEL:
    case 0:
        getAdvance();
        return false;
    case CR_CANCEL:
        break;
    }

    int prevreserve = ui->leReserveCode->asInt();
    bool result = true;
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.startTransaction();
    fDD[":f_state"] = RESERVE_REMOVED;
    fDD[":f_cancelUser"] = WORKING_USERID;
    fDD[":f_cancelDate"] = QDateTime::currentDateTime();
    ui->leReserveCode->setInitialValue(RESERVE_REMOVED);
    result = result && fDD.update("f_reservation", where_id(ap(ui->leReservId->text())));

    if (result) {
        fTrackControl->insert("Reservation was canceled", "", "");
        fTrackControl->saveChanges();
        fDD.commit();
        BroadcastThread::cmdRefreshCache(cid_red_reservation, ui->leReservId->text());
        BroadcastThread::cmdRefreshCache(cid_reservation, ui->leReservId->text());
        if (confirm) {
             message_info(tr("Reservation was canceled"));
        }

    } else {
        fDD.rollback();
        ui->leReserveCode->setInitialValue(prevreserve);
        if (confirm) {
            message_info(tr("Reservation was not canceled"));
        }
    }
    emit commonChanges();
    BroadcastThread::cmdRefreshCache(cid_reservation, ui->leReservId->text());
    return result;
}

bool WReservationRoomTab::canCopyLast()
{
    return ui->leReservId->isEmpty();
}

bool WReservationRoomTab::canRevive()
{
    QString errors;
    if (ui->deEntry->date() < WORKING_DATE) {
        errors += tr("This reservation cannot revive. Make another one") + "<br>";
    }
    if (!errors.isEmpty()) {
        message_error(errors);
    }
    return errors.isEmpty();
}

bool WReservationRoomTab::revive()
{
    DoubleDatabase fDD(true, doubleDatabase);
    ui->leReserveCode->setInitialValue(RESERVE_RESERVE);
    fDD[":f_state"] = RESERVE_RESERVE;
    fDD.update("f_reservation", where_id(ap(ui->leReservId->text())));
    fTrackControl->insert("Revive", "", "");
    loadReservation(ui->leReservId->text());
    BroadcastThread::cmdRefreshCache(cid_reservation, ui->leReservId->text());
    fDD[":f_id"] = ui->leReservId->text();
    fDD.exec("select f_group from f_reservation where f_id=:f_id");
    if (fDD.nextRow()) {
        fReservation->setGroup(fDD.getInt("f_group"));
    }
    emit commonChanges();
    return true;
}

void WReservationRoomTab::copyLast(const QString &lastId)
{
    DoubleDatabase fDD(true, doubleDatabase);
    if (ui->leReservId->notEmpty()) {
        return;
    }
    QString last;
    if (!lastId.isEmpty()) {
        last = lastId;
    } else {
        fDD.exec("select f_id from f_reservation_last");
        if (fDD.nextRow()) {
            last = fDD.getString(0);
        } else {
            message_info(tr("There are no last reservation"));
            return;
        }
    }
    loadReservation(last);
    ui->leReservId->clear();
    ui->leInvoice->clear();
    fTrackControl->resetChanges();
    checkDatesCross();
}

QString WReservationRoomTab::author()
{
    return fAuthor;
}

QString WReservationRoomTab::lastModify()
{
    return fLastModify;
}

int WReservationRoomTab::reserveState()
{
    return ui->leReserveCode->asInt();
}

QString WReservationRoomTab::reserveId()
{
    return ui->leReservId->text();
}

void WReservationRoomTab::startTrackControl()
{
    if (fTrackControl) {
        return;
    }
    fTrackControl = new TrackControl(TRACK_RESERVATION);
    fTrackControl->fInvoice = ui->leInvoice->text();
    fTrackControl->fReservation = ui->leReservId->text();
    fTrackControl->addWidget(ui->leReservId, "Doc number")
            .addWidget(ui->deCreated, "Created")
            .addWidget(ui->leReserveName, "Reserve state")
            .addWidget(ui->leStatusName, "Status")
            .addWidget(ui->deEntry, "Entry date")
            .addWidget(ui->deDeparture, "Departure date")
            .addWidget(ui->sbNights, "Nights")
            .addWidget(ui->leInvoice, "Invoice")
            .addWidget(ui->leRoomCode, "Room")
            .addWidget(ui->cbArrangment, "Arrangement")
            .addWidget(ui->chMealIncluded, "Meal included")
            .addWidget(ui->sbMan, "Male")
            .addWidget(ui->sbWoman, "Female")
            .addWidget(ui->sbChild, "Childs")
            .addWidget(ui->sbBaby, "Babies")
            .addWidget(ui->chEarlyCheckIn, "Early checkin")
            .addWidget(ui->teEarlyCheckIn, "Early checkin time")
            .addWidget(ui->chLateCheckout, "Late checkout")
            .addWidget(ui->teLateChecout, "Late checkout time")
            .addWidget(ui->leLateCheckoutFee, "Late checkout fee")
            .addWidget(ui->teArrivalTime, "Arrival time")
            .addWidget(ui->teDepartureTime, "Departure time")
            .addWidget(ui->leArrivalFee, "Pickup fee")
            .addWidget(ui->leCardexCode, "Cardex")
            .addWidget(ui->leCardexname, "Cardex name")
            .addWidget(ui->leBooking, "Booking")
            .addWidget(ui->leCityLedgerName, "City ledger")
            .addWidget(ui->leRooming, "Rate")
            .addWidget(ui->chExtraBed, "Extra bed")
            .addWidget(ui->leExtraBedAmount, "Extra bed fee")
            .addWidget(ui->sbMealQty, "Meal")
            .addWidget(ui->leMealPrice, "Meal price")
            .addWidget(ui->lePricePerNight, "Price per night")
            .addWidget(ui->cbVAT, "VAT")
            .addWidget(ui->leNoVATReason, "No VAR reason")
            .addWidget(ui->leTotal, "Total")
            .addWidget(ui->leVAT, "VAT amount")
            .addWidget(ui->leGrandTotal, "Grand total")
            .addWidget(ui->cbPaymentType, "Payment mode")
            .addWidget(ui->teRoomRemarks, "Remarks")
            .addWidget(ui->chPickup, "Need pickup");
    ui->leStatusCode->setFocus();
}

TrackControl *WReservationRoomTab::trackControl()
{
    return fTrackControl;
}

EQComboBox *WReservationRoomTab::cbRoomArrangement()
{
    return ui->cbArrangment;
}

void WReservationRoomTab::addRemoveFromGroup()
{
    DoubleDatabase fDD(true, doubleDatabase);
    DlgGroupReserveOption::addRemove(ui->leReservId->text());
    fDD[":f_id"] = ui->leReservId->text();
    fDD.exec("select f_group from f_reservation where f_id=:f_id");
    if (fDD.nextRow()) {
        fReservation->setGroup(fDD.getInt("f_group"));
    }
    BroadcastThread::cmdRefreshCache(cid_reservation, ui->leReservId->text());
    BroadcastThread::cmdRefreshCache(cid_red_reservation, ui->leReservId->text());
}

void WReservationRoomTab::sendConfirmation()
{
    DlgEmail::sendDialog();
}

void WReservationRoomTab::callback(int sel, const QString &code)
{
    switch (sel) {
    case HINT_SEARCH_GUEST: {
        ui->leSearchGuest->clear();
        CacheGuest g;
        if (g.get(code)) {
            addGuest(g, true);
        }
        break;
    }
    case HINT_CARDEX: {
        CacheCardex c;
        if (!c.get(code)) {
            if (ui->leCardexCode->text().length() == 0) {
                ui->leCardexname->clear();
                ui->lbCardexError->setPixmap(QPixmap(":/images/warning.png"));
                fCardexOk = false;
                return;
            } else {
                if (!c.get(ui->leCardexCode->text())) {
                    ui->leCardexname->clear();
                    ui->lbCardexError->setPixmap(QPixmap(":/images/warning.png"));
                    ui->leCommission->setText("0.00");
                    fCardexOk = false;
                    return;
                }
            }
        }
        ui->leCardexCode->setText(c.fCode());
        ui->leCardexname->setText(c.fName());
        fCardexOk = true;
        if (fInitCardex != c.fCode()) {
            ui->lbCardexError->setPixmap(QPixmap(":/images/ok.png"));
            ui->leCommission->setText(c.fCommission());
            ui->cbVAT->setIndexForData(c.fVatMode().toInt());
            fInitCardex = c.fCode();
        }
        break;
    }
    case HINT_CITYLEDGER: {
        CacheCityLedger c;
        if (!c.get(code)) {
            if (ui->leCityLedgerCode->asInt() == 0) {
                fCityLedgerOk = true;
                ui->lbCLedgerError->setPixmap(QPixmap(":/images/question.png"));
                ui->leCityLedgerName->clear();
                return;
            } else {
                if (!c.get(ui->leCityLedgerCode->text())) {
                    ui->leCityLedgerName->clear();
                    fCityLedgerOk = false;
                    ui->lbCLedgerError->setPixmap(QPixmap(":/images/warning.png"));
                    return;
                }
            }
        }
        ui->leCityLedgerCode->setText(c.fCode());
        ui->leCityLedgerName->setText(c.fName());
        ui->lbCLedgerError->setPixmap(QPixmap(":/images/ok.png"));
        fCityLedgerOk = true;
        break;
    }
    }
}

void WReservationRoomTab::countTotal()
{
    double total = ui->leRooming->asDouble();
    total += ui->leExtraBedAmount->asDouble();
    total += (ui->sbMealQty->value() * ui->leMealPrice->asDouble());

    ui->lePricePerNight->setDouble(total);
    total *= ui->sbNights->value();
    ui->leTotal->setText(QString::number(total, 'f', 2));
    switch (ui->cbVAT->asInt()) {
    case VAT_INCLUDED: {
        double vat = total - (total / ((def_vat / 100) + 1));
        ui->leVAT->setDouble(vat);
        ui->leGrandTotal->setText(ui->leTotal->text());
        break;
    }
    case VAT_WITHOUT: {
        double vat = total * (def_vat / 100);
        ui->leVAT->setDouble(vat);
        ui->leGrandTotal->setDouble(ui->leTotal->asDouble() + vat);
        break;
    }
    case VAT_NOVAT:
        ui->leVAT->setText("0.00");
        ui->leGrandTotal->setText(ui->leTotal->text());
        break;
    }
    ui->leGrandTotal->addDouble(ui->leEarlyCheckInFee->asDouble());
    ui->leGrandTotal->addDouble(ui->leArrivalFee->asDouble());
    ui->leTotalUSD->setText(QString::number(total / def_usd, 'f', 2));
}

void WReservationRoomTab::setEarlyCheckIn(bool v)
{
    ui->teEarlyCheckIn->setEnabled(v);
    ui->leEarlyCheckInFee->setEnabled(v);
}

void WReservationRoomTab::checkDatesCross()
{
    if (ui->deCreated->date() == ui->deEntry->date()) {
        ui->lbWolking->setEnabled(true);
    } else {
        ui->lbWolking->setEnabled(false);
    }
    if (ui->deEntry->date() == ui->deDeparture->date()) {
        ui->lbDayUse->setEnabled(true);
    } else {
        ui->lbDayUse->setEnabled(false);
    }
    ui->lbEarlyCheckinWarning->setPixmap(QPixmap(":/images/ok.png"));
    ui->lbEndDateWarning->setPixmap(QPixmap(":/images/ok.png"));
    ui->lbStartDateWarning->setPixmap(QPixmap(":/images/ok.png"));
    ui->lbStartDateWarning->setToolTip("");
    ui->lbEndDateWarning->setToolTip("");
    fStartDateOk = true;
    fEndDateOk = true;
    QString tt1, tt2;
    if (ui->leRoomCode->asInt() > 0) {
        QMap<QString, CacheReservation> r;
        CacheReservation().check(ui->deEntry->date(), ui->deDeparture->date(), ui->leRoomCode->asInt(), r, fStartDateOk, fEndDateOk, ui->leReservId->text());
        if (r.count() == 0) {

        } else {
            for (QMap<QString, CacheReservation>::iterator it = r.begin(); it != r.end(); it++) {
                CacheReservation &rm = it.value();
                if (rm.fDateEnd() > ui->deEntry->date()) {
                    tt1 += QString("%1 #%2/%3. %4 - %5\n")
                            .arg(tr("Room"))
                            .arg(rm.fId())
                            .arg(ui->leRoomCode->asInt())
                            .arg(rm.fDateStart().toString(def_date_format))
                            .arg(rm.fDateEnd().toString(def_date_format));
                }
                if (rm.fDateStart() < ui->deDeparture->date()) {
                    tt2 += QString("%1 #%2/%3. %4 - %5\n")
                            .arg(tr("Room"))
                            .arg(rm.fId())
                            .arg(ui->leRoomCode->asInt())
                            .arg(rm.fDateStart().toString(def_date_format))
                            .arg(rm.fDateEnd().toString(def_date_format));
                }
            }
        }
    }
    if (ui->deEntry->date() > ui->deDeparture->date()) {
        fStartDateOk = false;
        fEndDateOk = false;
    }
    if (ui->deEntry->date() < WORKING_DATE && ui->leReserveCode->asInt() == RESERVE_RESERVE) {
        fStartDateOk = false;
    }
    if (ui->leReserveCode->asInt() == RESERVE_CHECKIN) {
        if (ui->deDeparture->date() < WORKING_DATE) {
            fEndDateOk = false;
        }
    }
    if (!fStartDateOk) {
        ui->lbStartDateWarning->setPixmap(QPixmap(":/images/warning.png"));
    }
    if (!fEndDateOk) {
        ui->lbEndDateWarning->setPixmap(QPixmap(":/images/warning.png"));
    }
    ui->lbStartDateWarning->setToolTip(tt1);
    ui->lbEndDateWarning->setToolTip(tt2);
}

void WReservationRoomTab::setGroupBoxesEnabled(bool v)
{
    ui->grCommon->setEnabled(v);
    ui->grRoom->setEnabled(v);
    ui->grAdd->setEnabled(v);
    ui->grPricing->setEnabled(v);
    ui->grPayment->setEnabled(v);
    ui->grRemarks->setEnabled(v);
}

void WReservationRoomTab::saveVaucher()
{
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.startTransaction();
    QString rid = ui->leReservId->text();
    fDD[":f_source"] = VAUCHER_RESERVATION_N;
    fDD[":f_wdate"] = WORKING_DATE;
    fDD[":f_rdate"] = QDate::currentDate();
    fDD[":f_time"] = QTime::currentTime();
    fDD[":f_user"] = WORKING_USERID;
    fDD[":f_room"] = ui->leRoomCode->text();
    fDD[":f_guest"] = ui->tblGuest->item(0, 2)->text();
    fDD[":f_itemCode"] = fPreferences.getDb(def_reservation_voucher_id);
    fDD[":f_finalName"] = tr("RESERVATION ") + ui->leReservId->text();
    fDD[":f_amountAmd"] = ui->leGrandTotal->asDouble();
    fDD[":f_amountVat"] = ui->leVAT->asDouble();
    fDD[":f_amountUsd"] = def_usd;
    fDD[":f_fiscal"] = 0;
    fDD[":f_paymentMode"] = ui->cbPaymentType->currentData();
    fDD[":f_creditCard"] = 0;
    fDD[":f_cityLedger"] = ui->leCityLedgerCode->asInt();
    fDD[":f_paymentComment"] = vaucherPaymentName(ui->cbPaymentType->currentData().toInt(), 0, ui->leCityLedgerCode->text());
    fDD[":f_dc"] = "";
    fDD[":f_sign"] = 1;
    fDD[":f_doc"] = "";
    fDD[":f_rec"] = "";
    fDD[":f_inv"] = ui->leInvoice->text();
    fDD[":f_finance"] = 0;
    fDD[":f_remarks"] = ui->teRoomRemarks->toPlainText();
    fDD[":f_canceled"] = 0;
    fDD[":f_cancelReason"] = "";
    fDD[":f_side"] = 0;
    fDD.update("m_register", where_id(ap(rid)));
    fDD.commit();
}

void WReservationRoomTab::getAdvance()
{
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_invoice"] = ui->leInvoice->text();
    fDD.exec("select sum(f_amountAmd*f_sign*-1) from m_register where f_inv=:f_invoice and f_finance=1 and f_canceled=0");
    if (fDD.nextRow()) {
        ui->leAdvance->setText(fDD.getString(0));
        if (ui->leAdvance->asDouble() < 0.01) {
            ui->leAdvance->setInt(0);
        }
    }
}

int WReservationRoomTab::firstGuestId()
{
    if (ui->tblGuest->rowCount() == 0)
        return 0;
    return ui->tblGuest->item(0, 0)->data(Qt::EditRole).toInt();
}

QString WReservationRoomTab::mainGuest()
{
    CacheGuest g;
    if (g.get(firstGuestId())) {
        return g.fName();
    } else {
        return "No guest";
    }
}

bool WReservationRoomTab::checkDoc(QStringList &errors)
{
    QStringList temp;
    if (temp.count() > 0) {
        temp.insert(0, tr("Room page") + " #" + QString::number(fTabIndex + 1));
        temp.insert(0, "");
    }
    if (ui->tblGuest->rowCount() == 0) {
        temp.append(tr("Guest count must be greater than 0"));
    }
    ui->lbEntryDate->setStyleSheet("color:black");
    if (!fStartDateOk) {
        temp.append(tr("Incorrect entry date"));
        ui->lbEntryDate->setStyleSheet("color:red");
    }
    ui->lbDepartureDate->setStyleSheet("color:black");
    if (!fEndDateOk) {
        temp.append(tr("Incorrect departure date"));
        ui->lbDepartureDate->setStyleSheet("color:red");
    }
    ui->lbCardex->setStyleSheet("color:black");
    if (!fCardexOk) {
        temp.append(tr("Incorrect cardex code"));
        ui->lbCardex->setStyleSheet("color:red");
    }
    if (fCardexOk && !ui->leCardexCode->text().isEmpty()) {
        CacheCardex cardex;
        cardex.get(ui->leCardexCode->text());
        if (cardex.fBookingRequired() && ui->leBooking->text().isEmpty()) {
            temp.append(tr("Booking field is required"));
        }
    }
    if (!fCityLedgerOk) {
        temp.append(tr("Incorrect city ledger code"));
    }
    if (ui->leStatusCode->asInt() == CONFIRM_BLOCK) {
        temp.append(tr("Reservation status cannot be 'Block'"));
    }
    ui->lbArrangement->setStyleSheet("color:black");
    if (ui->cbArrangment->currentIndex() < 0) {
        temp.append(tr("Arrangement not correct"));
        ui->lbArrangement->setStyleSheet("color:red");
    }
    ui->lbVATMode->setStyleSheet("color:black");
    if (ui->cbVAT->currentIndex() < 0) {
        temp.append(tr("VAT mode is not selected"));
        ui->lbVATMode->setStyleSheet("color:red");
    }
    ui->lbPaymentMode->setStyleSheet("color:black");
    if (ui->cbPaymentType->currentIndex() < 0) {
        temp.append("Payment mode is not selected");
        ui->lbPaymentMode->setStyleSheet("color:red");
    }
    ui->lbCityLedger->setStyleSheet("color:black");
    if (ui->cbPaymentType->asInt() == PAYMENT_CL && ui->leCityLedgerCode->asInt() == 0) {
        temp.append(tr("City ledger is not selected"));
        ui->lbCityLedger->setStyleSheet("color:red");
    }

    errors.append(temp);
    return temp.count() == 0;
}

void WReservationRoomTab::setRoom(const QString &code)
{
    CacheRoom r;
    if (!r.get(code)) {
        return;
    }
    ui->leRoomCode->setText(r.fCode());
    ui->leRoomName->setText(r.fName());
    if (ui->leReserveCode->asInt() == RESERVE_SERVICE) {
        ui->leRooming->setText(r.fPrice());
    }
    ui->lbRoom->setPixmap(QPixmap(":/images/ok.png"));
    checkDatesCross();
    emit roomChanged(r.fName(), fTabIndex);
}

void WReservationRoomTab::disconnectSignals()
{
    disconnect(ui->sbMan, SIGNAL(valueChanged(int)), this, SLOT(on_sbMan_valueChanged(int)));
    disconnect(ui->sbWoman, SIGNAL(valueChanged(int)), this, SLOT(on_sbWoman_valueChanged(int)));
    disconnect(ui->sbChild, SIGNAL(valueChanged(int)), this, SLOT(on_sbChild_valueChanged(int)));
    disconnect(ui->leMealPrice, SIGNAL(textChanged(QString)), this, SLOT(on_leMealPrice_textChanged(QString)));
    disconnect(ui->leRooming, SIGNAL(textChanged(QString)), this, SLOT(on_leRooming_textChanged(QString)));
    disconnect(ui->sbNights, SIGNAL(valueChanged(int)), this, SLOT(on_sbNights_valueChanged(int)));
    disconnect(ui->deEntry, SIGNAL(dateChanged(QDate)), this, SLOT(on_deEntry_dateChanged(QDate)));
    disconnect(ui->deDeparture, SIGNAL(dateChanged(QDate)), this, SLOT(on_deDeparture_dateChanged(QDate)));
}

void WReservationRoomTab::connectSignals()
{
    connect(ui->sbMan, SIGNAL(valueChanged(int)), this, SLOT(on_sbMan_valueChanged(int)));
    connect(ui->sbWoman, SIGNAL(valueChanged(int)), this, SLOT(on_sbWoman_valueChanged(int)));
    connect(ui->sbChild, SIGNAL(valueChanged(int)), this, SLOT(on_sbChild_valueChanged(int)));
    connect(ui->leMealPrice, SIGNAL(textChanged(QString)), this, SLOT(on_leMealPrice_textChanged(QString)));
    connect(ui->leRooming, SIGNAL(textChanged(QString)), this, SLOT(on_leRooming_textChanged(QString)));
    connect(ui->sbNights, SIGNAL(valueChanged(int)), this, SLOT(on_sbNights_valueChanged(int)));
    connect(ui->deEntry, SIGNAL(dateChanged(QDate)), this, SLOT(on_deEntry_dateChanged(QDate)));
    connect(ui->deDeparture, SIGNAL(dateChanged(QDate)), this, SLOT(on_deDeparture_dateChanged(QDate)));
}

void WReservationRoomTab::setupTab()
{
    setupTabTextAndIcon(tr("Room"), ":/images/room-key.png");
}

bool WReservationRoomTab::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *ke = static_cast<QKeyEvent*>(event);
        switch (ke->key()) {
        case Qt::Key_Enter:
        case Qt::Key_Return:
            focusNextChild();
            return true;
        }
    }
    return QWidget::event(event);
}

void WReservationRoomTab::roomCacheUpdated(int cacheId, const QString &id)
{
    if (cacheId == cid_room) {
        if (fTabWidget->currentWidget() == this) {
            if (id == ui->leRoomCode->text()) {
                emit commonChanges();
            }
        }
    }
}

void WReservationRoomTab::roomSearch(bool v)
{

    Q_UNUSED(v);

    DlgCreateGroupReservation *d = new DlgCreateGroupReservation(this);
    d->setSingleMode(true);
    d->setReservationTab(this);
    d->exec();
    delete d;

}

void WReservationRoomTab::tblGuestChange(int tag)
{
    tag = -1;
    EPushButton *btn = static_cast<EPushButton*>(sender());
    for (int i = 0; i < ui->tblGuest->rowCount(); i++) {
        if (ui->tblGuest->cellWidget(i, btn->fColumn) == btn) {
            tag = i;
        }
    }
    if (tag < 0) {
        return;
    }
    QList<QVariant> v;
    WGuest *g = WGuest::guest(v);
    g->setValues();
    if (g->exec() == QDialog::Accepted) {
        fTrackControl->insertMessage("Guest changed", ui->tblGuest->toString(tag, 2), v.at(2).toString() + " " + v.at(3).toString());
        ui->tblGuest->item(tag, 1)->setText(v.at(1).toString());
        ui->tblGuest->item(tag, 2)->setText(v.at(2).toString() + " " + v.at(3).toString());
    }
    delete g;
}

void WReservationRoomTab::tblGuestRemove(int row)
{
    if (message_confirm(tr("Are you sure to delete this guest")) != QDialog::Accepted) {
        return;
    }
    row = -1;
    EPushButton *btn = static_cast<EPushButton*>(sender());
    for (int i = 0; i < ui->tblGuest->rowCount(); i++) {
        if (ui->tblGuest->cellWidget(i, btn->fColumn) == btn) {
            row = i;
            break;
        }
    }
    if (row < 0) {
        return;
    }
    EPushButton *btn1 = static_cast<EPushButton*>(ui->tblGuest->cellWidget(row, 4));
    EPushButton *btn2 = static_cast<EPushButton*>(ui->tblGuest->cellWidget(row, 3));
    fTrackControl->insertMessage("Guest removed", ui->tblGuest->item(row, 1)->text() + " " + ui->tblGuest->item(row, 2)->text(), "");
    ui->tblGuest->removeCellWidget(row, 3);
    ui->tblGuest->removeCellWidget(row, 4);
    ui->tblGuest->removeRow(row);
    btn1->deleteLater();
    btn2->deleteLater();
}

void WReservationRoomTab::tblGuestChangeInfo(int tag)
{
    tag = -1;
    EPushButton *btn = static_cast<EPushButton*>(sender());
    for (int i = 0; i < ui->tblGuest->rowCount(); i++) {
        if (ui->tblGuest->cellWidget(i, btn->fColumn) == btn) {
            tag = i;
        }
    }
    if (tag < 0) {
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_id"] = ui->tblGuest->toInt(tag, 0);
    fDD.exec("select g.f_id, g.f_title, g.f_firstName, g.f_lastName, g.f_sex, s.f_" + def_lang + ", g.f_dateBirth, "
               "g.f_placeBirth, "
               "n.f_short, n.f_name as nationality, g.f_passport, g.f_address, g.f_tel1, g.f_tel2, "
               "g.f_email, g.f_postBox, g.f_remarks "
               "from f_guests g "
               "left join f_nationality n on g.f_nation=n.f_short "
               "left join f_guests_sex s on s.f_id=g.f_sex "
               "where g.f_id=:f_id ");
    if (fDD.rowCount() == 0) {
        message_error(tr("Cannot get guest info"));
        return;
    }
    QList<QVariant> v = fDD.fDbRows[0];
    WGuest *g = WGuest::guest(v);
    g->setValues();
    if (g->exec() == QDialog::Accepted) {
        fTrackControl->insert("Guest info edited", ui->tblGuest->toString(tag, 2), v.at(2).toString() + " " + v.at(3).toString());
        ui->tblGuest->item(tag, 1)->setText(v.at(1).toString());
        ui->tblGuest->item(tag, 2)->setText(v.at(2).toString() + " " + v.at(3).toString());
    }
    delete g;
}

void WReservationRoomTab::room(const QString &code)
{
    CacheRoom c;
    if (!c.get(code)) {
        ui->lbRoom->setPixmap(QPixmap(":/images/question.png"));
        ui->leRoomName->clear();
        if (ui->leRoomCode->asInt() > 0) {           
            if (!c.get(ui->leRoomCode->text())) {
                ui->leRoomCode->clear();
                ui->lbRoom->setPixmap(QPixmap(":/images/warning.png"));
            }
        }
    }
    if (c.get(code)) {
        ui->leRoomCode->setText(c.fCode());
        ui->leRoomName->setText(c.fName());
        if (ui->leReserveCode->asInt() == RESERVE_SERVICE) {
            ui->leRooming->setText(c.fPrice());
        }
        ui->lbRoom->setPixmap(QPixmap(":/images/ok.png"));
        checkDatesCross();
    }
}

void WReservationRoomTab::on_leRoomCode_returnPressed()
{
    ui->leRoomName->clear();
    if (ui->leRoomCode->asInt() == 0) {
        ui->leRoomCode->clear();
        ui->lbRoom->setPixmap(QPixmap(":/images/question.png"));
        return;
    }
    CacheRoom r;
    if (!r.get(ui->leRoomCode->text())) {
        ui->lbRoom->setPixmap(QPixmap(":/images/warning.png"));
        return;
    }
    ui->lbRoom->setPixmap(QPixmap(":/images/ok.png"));
    ui->leRoomName->setText(r.fName());
    if (ui->leReserveCode->asInt() == RESERVE_SERVICE) {
        ui->leRooming->setText(r.fPrice());
    }
    emit roomChanged(r.fName(), fTabIndex);
    checkDatesCross();
}

void WReservationRoomTab::addGuest(CacheGuest &g, bool log)
{
    int row = ui->tblGuest->rowCount();
    ui->tblGuest->setRowCount(ui->tblGuest->rowCount() + 1);
    QTableWidgetItem *iCode = new QTableWidgetItem();
    iCode->setData(Qt::DisplayRole, g.fId());
    QTableWidgetItem *iTitle = new QTableWidgetItem();
    iTitle->setData(Qt::DisplayRole, g.fTitle());
    QTableWidgetItem *iName = new QTableWidgetItem();
    iName->setData(Qt::DisplayRole, g.fFullName());
    QTableWidgetItem *iInfo = new QTableWidgetItem();
    QTableWidgetItem *iRemove = new QTableWidgetItem();
    ui->tblGuest->setItem(row, 0, iCode);
    ui->tblGuest->setItem(row, 1, iTitle);
    ui->tblGuest->setItem(row, 2, iName);
    ui->tblGuest->setItem(row, 3, iInfo);
    ui->tblGuest->setItem(row, 4, iRemove);
    on_leMealPrice_textChanged("");
    EPushButton *btnInfo = new EPushButton(this);
    btnInfo->setText("");
    btnInfo->setToolTip(tr("Change guest"));
    btnInfo->setTag(row);
    btnInfo->fColumn = 3;
    btnInfo->setIcon(QIcon(":/images/change.png"));
    EPushButton *btnRemove = new EPushButton(this);
    btnRemove->setText("");
    btnRemove->setToolTip(tr("Remove guest"));
    btnRemove->setIcon(QIcon(":/images/garbage.png"));
    btnRemove->setTag(row);
    btnRemove->fColumn = 4;
    EPushButton *btnChangeInfo = new EPushButton(this);
    btnChangeInfo->setText("");
    btnChangeInfo->setToolTip(tr("Modify guest info"));
    btnChangeInfo->setIcon(QIcon(":/images/info.png"));
    btnChangeInfo->setTag(row);
    btnChangeInfo->fColumn = 5;
    ui->tblGuest->setCellWidget(row, 3, btnInfo);
    ui->tblGuest->setCellWidget(row, 4, btnRemove);
    ui->tblGuest->setCellWidget(row, 5, btnChangeInfo);
    connect(btnInfo, SIGNAL(clickedWithTag(int)), this, SLOT(tblGuestChange(int)));
    connect(btnRemove, SIGNAL(clickedWithTag(int)), this, SLOT(tblGuestRemove(int)));
    connect(btnChangeInfo, SIGNAL(clickedWithTag(int)), this, SLOT(tblGuestChangeInfo(int)));
    countTotal();
    ui->leSearchGuest->clear();
    ui->leSearchGuest->fHiddenText.clear();
    if (log) {
        fTrackControl->fTable = TRACK_GUEST;
        fTrackControl->fRecord = iCode->text();
        fTrackControl->insert("New guest", "", iTitle->text() + " " + iName->text());
        fTrackControl->fTable = TRACK_RESERVATION;
        fTrackControl->insertMessage("New guest", "", iTitle->text() + " " + iName->text());
        fTrackControl->fRecord = "-";
    }
}

void WReservationRoomTab::on_leMealPrice_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    countTotal();
}

void WReservationRoomTab::on_leRooming_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    countTotal();
}

void WReservationRoomTab::on_sbNights_valueChanged(int arg1)
{
    disconnectSignals();
    ui->deDeparture->setDate(ui->deEntry->date().addDays(arg1));
    connectSignals();
    countTotal();
    checkDatesCross();
}

void WReservationRoomTab::on_deDeparture_dateChanged(const QDate &date)
{
    disconnectSignals();
    ui->sbNights->setValue(ui->deEntry->date().daysTo(date));
    connectSignals();
    countTotal();
    checkDatesCross();
    if (date == ui->deEntry->date()) {
        ui->lbDayUse->setEnabled(true);
    } else {
        ui->lbDayUse->setEnabled(false);
    }
}

void WReservationRoomTab::on_deEntry_dateChanged(const QDate &date)
{
    disconnectSignals();
    ui->sbNights->setValue(date.daysTo(ui->deDeparture->date()));
    connectSignals();
    countTotal();
    checkDatesCross();
}

void WReservationRoomTab::on_cbVAT_currentIndexChanged(int index)
{
    Q_UNUSED(index)
    countTotal();
    ui->leNoVATReason->setEnabled(ui->cbVAT->asInt() == VAT_NOVAT);
}

void WReservationRoomTab::on_leExtraBedAmount_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    countTotal();
}

void WReservationRoomTab::on_leEarlyCheckInFee_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1)
    countTotal();
}

void WReservationRoomTab::on_chEarlyCheckIn_stateChanged(int arg1)
{
    setEarlyCheckIn(arg1);
}

void WReservationRoomTab::on_chExtraBed_stateChanged(int arg1)
{
    ui->leExtraBedAmount->setEnabled(arg1);
}

void WReservationRoomTab::on_sbWoman_valueChanged(int arg1)
{
    Q_UNUSED(arg1)
    countTotal();
    on_cbArrangment_currentIndexChanged(ui->cbArrangment->currentIndex());
}

void WReservationRoomTab::on_sbChild_valueChanged(int arg1)
{
    Q_UNUSED(arg1)
    countTotal();
    on_cbArrangment_currentIndexChanged(ui->cbArrangment->currentIndex());
}

void WReservationRoomTab::on_sbMan_valueChanged(int arg1)
{
    Q_UNUSED(arg1)
    countTotal();
    on_cbArrangment_currentIndexChanged(ui->cbArrangment->currentIndex());
}

void WReservationRoomTab::on_chEarlyCheckIn_clicked(bool checked)
{
    if (checked) {
        ui->lbEarlyCheckinWarning->setEnabled(true);
        checkDatesCross();
    } else {
        ui->lbEarlyCheckinWarning->setPixmap(QPixmap(":/images/ok.png"));
        ui->lbEarlyCheckinWarning->setEnabled(false);
        ui->leEarlyCheckInFee->setText("");
        countTotal();
    }
}

void WReservationRoomTab::on_chExtraBed_clicked(bool checked)
{
    if (checked) {
        ui->leExtraBedAmount->setText(fPreferences.getLocalString(def_default_extra_bed));
    } else {
        ui->leExtraBedAmount->setText("");
    }
    countTotal();
}

void WReservationRoomTab::on_btnNewGuest_clicked()
{
    QList<QVariant> values;
    WGuest *g = WGuest::guest(values, true);
    if (g->exec() == QDialog::Accepted) {
        cache(cid_guest)->update(values.at(0).toString());
        CacheGuest guest;
        guest.get(values.at(0).toString());
        if (!guest.fValid) {
            message_error(tr("Cannot register new guest, contact to application developer"));
            return;
        }
        addGuest(guest, true);
    }
    delete g;
}

void WReservationRoomTab::on_cbPaymentType_currentIndexChanged(int index)
{
    Q_UNUSED(index)
    int pm = ui->cbPaymentType->asInt();
    ui->leCityLedgerCode->setEnabled(pm == PAYMENT_CL);
    ui->leCityLedgerName->setEnabled(pm == PAYMENT_CL);
}

void WReservationRoomTab::on_btnItemSide_clicked()
{
    fDockItemSide->show();
    fDockItemSide->raise();
}

void WReservationRoomTab::on_leSearchGuest_returnPressed()
{
    if (ui->leSearchGuest->text().trimmed().isEmpty()) {
        return;
    }
    QStringList fn = ui->leSearchGuest->text().split(" ");
    QString ln;
    if (fn.count() > 0) {
        QString searchName = fn.at(0).toLower();
        if (fn.count() > 1) {
            searchName += " " + fn.at(1).toLower();
        }
        DoubleDatabase fDD(true, doubleDatabase);
        fDD.exec("select f_id from f_guests where concat(lower(f_firstName), ' ', lower(f_lastName)) like '" + searchName + "%'");
        if (fDD.rowCount()  > 0) {
            ui->leSearchGuest->fCommonFilter.clear();
            ui->leSearchGuest->fCommonFilter << ui->leSearchGuest->text();
            QString guestCode = cache(cid_guest)->get(ui->leSearchGuest->text());
            CacheGuest cg;
            if (cg.get(guestCode)) {
                addGuest(cg, true);
            }
        } else {
            fDD[":f_title"] = "";
            fDD[":f_firstName"] = fn.at(0);
            if (fn.count() > 1) {
                QString lastName;
                bool first = true;
                for (int i = 1; i < fn.count(); i++) {
                    if (first) {
                        first = false;
                    } else {
                        lastName += " ";
                    }
                    lastName += fn.at(i);
                }
                fDD[":f_lastName"] = lastName;
                ln = lastName;
            } else {
                fDD[":f_lastName"] = "";
            }
            DoubleDatabase did;
            did.open(true, true);
            did[":f_id"] = 0;
            int gid = did.insert("f_guests");
            fDD.update("f_guests", where_id(gid));
            cache(cid_guest)->update(QString::number(gid));
            BroadcastThread::cmdRefreshCache(cid_guest, QString::number(gid));
            CacheGuest g;
            int t = 500000000;
            while (t > 0 && !g.get(gid)) {
                t--;
            }
            addGuest(g, true);
        }
    }
}

void WReservationRoomTab::on_chMealIncluded_clicked(bool checked)
{
    ui->leMealPrice->setEnabled(!checked);
    if (checked) {
        ui->leMealPrice->setText(0);
    }
    countTotal();
}

void WReservationRoomTab::on_btnAppendAdvance_clicked()
{
    if (ui->leReservId->isEmpty()) {
        message_error(tr("Save reservation first"));
        return;
    }
    DlgAdvanceEntry::advance(ui->leReservId->text());
    getAdvance();
}

void WReservationRoomTab::on_chLateCheckout_clicked(bool checked)
{
    ui->leLateCheckoutFee->setEnabled(checked);
    ui->teLateChecout->setEnabled(checked);
    if (!checked) {
        ui->leLateCheckoutFee->clear();
    }
}

void WReservationRoomTab::on_sbMealQty_valueChanged(int arg1)
{
    Q_UNUSED(arg1)
}

void WReservationRoomTab::on_leMealPrice_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    countTotal();
}

void WReservationRoomTab::on_deEntry_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    checkDatesCross();
}

void WReservationRoomTab::on_deDeparture_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1)
    checkDatesCross();
}


void WReservationRoomTab::on_cbArrangment_currentIndexChanged(int index)
{
    if (index < 0) {
        ui->sbMealQty->setEnabled(false);
        ui->sbMealQty->setValue(0);
    }
    switch (ui->cbArrangment->currentData().toInt()) {
    case ARRANGEMENT_BO:
        ui->sbMealQty->setEnabled(false);
        ui->sbMealQty->setValue(0);
        break;
    default:
        ui->sbMealQty->setEnabled(true);
        ui->sbMealQty->setValue(ui->sbMan->value() + ui->sbWoman->value() + ui->sbChild->value());
    }
}

void WReservationRoomTab::on_btnAllNation_clicked()
{
    DoubleDatabase fDD(true, doubleDatabase);
    QString nation;
    for (int i = 0; i < ui->tblGuest->rowCount(); i++) {
        if (i == 0) {
            CacheGuest g;
            g.get(ui->tblGuest->toString(i, 0));
            nation = g.fNatShort();
            continue;
        }
        fDD[":f_nation"] = nation;
        fDD.update("f_guests", where_id(ui->tblGuest->toString(i, 0)));
    }
}