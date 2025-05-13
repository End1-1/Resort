#include "wglobaldbconfig.h"
#include "ui_wglobaldbconfig.h"
#include "message.h"
#include "logging.h"
#include "defrest.h"
#include "cacheresthall.h"
#include "dlgeditservtax.h"
#include "cacheusersgroups.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

void WGlobalDbConfig::getCompSettings()
{
    ui->lwHost->clear();
    DoubleDatabase fDD;
    fDD.exec("select f_comp, f_hall from s_tax_print");
    while (fDD.nextRow()) {
        QListWidgetItem *item = new QListWidgetItem(ui->lwHost);
        item->setText(fDD.getString(0));
        item->setData(Qt::UserRole, fDD.getValue(1));
        ui->lwHost->addItem(item);
    }
    ui->leHost->clear();
    ui->leHallCode->clear();
    ui->leHallCode->setSelector(this, cache(cid_rest_hall), ui->leHallName);
}

void WGlobalDbConfig::getAccess()
{
    DoubleDatabase db;
    db.setDatabase(__dd1Host, "airwick", __dd1Username, __dd1Password);
    if (!db.open()) {
        return;
    }
    db.exec("select * from f_db");
    ui->tblAccess->clearContents();
    ui->tblAccess->setRowCount(0);
    ui->tblAccess->setColumnCount(1 + db.rowCount());
    QStringList colCaption;
    colCaption << tr("Station/Username");
    QMap<QString, int> dbAddr;
    QMap<int, int> dbColAddr;
    for (int i = 0; i < db.rowCount(); i++) {
        colCaption << db.getValue(i, "f_name").toString();
        dbAddr[db.getValue(i, "f_id").toString()] = i + 1;
        dbColAddr[i + 1] = db.getValue(i, "f_id").toInt();
    }
    ui->tblAccess->setHorizontalHeaderLabels(colCaption);
    db.exec("select * from f_users");
    ui->tblAccess->setRowCount(db.rowCount());
    QMap<QString, int> userAddr;
    for (int i = 0; i < db.rowCount(); i++) {
        userAddr[db.getValue(i, "f_name").toString()] = i;
        ui->tblAccess->setItemWithValue(i, 0, db.getValue(i, "f_name"));
        for (int j = 1; j < ui->tblAccess->columnCount(); j++) {
            ui->tblAccess->addCheckBox(i, j);
            ui->tblAccess->setItemWithValue(i, j, "", dbColAddr[j]);
        }
    }
    db.exec("select * from f_access");
    for (int i = 0; i < db.rowCount(); i++) {
        int row = userAddr[db.getValue(i, "f_user").toString()];
        int col = dbAddr[db.getValue(i, "f_db").toString()];
        ui->tblAccess->checkBox(row, col)->setChecked(db.getValue(i, "f_right").toString() == "1");
    }
    ui->tblAccess->horizontalHeader()->resizeContentsPrecision();
}

void WGlobalDbConfig::getDatabases()
{
    DoubleDatabase db;
    db.setDatabase(__dd1Host, "airwick", __dd1Username, __dd1Password);
    if (!db.open()) {
        return;
    }
    db.exec("select * from f_db");
    Utils::tableSetColumnWidths(ui->tblDatabases, ui->tblDatabases->columnCount(),
                                0, 120, 120, 200, 120, 120);
    for (int i = 0; i < db.rowCount(); i++) {
        int row = ui->tblDatabases->addRow();
        ui->tblDatabases->addLineEdit(row, 0, false)->setText(db.getValue(i, "f_id").toString());
        ui->tblDatabases->addLineEdit(row, 1, false)->setText(db.getValue(i, "f_name").toString());
        ui->tblDatabases->addLineEdit(row, 2, false)->setText(db.getValue(i, "f_host").toString());
        ui->tblDatabases->addLineEdit(row, 3, false)->setText(db.getValue(i, "f_database").toString());
        ui->tblDatabases->addLineEdit(row, 4, false)->setText(db.getValue(i, "f_username").toString());
        ui->tblDatabases->addLineEdit(row, 5, false)->setText(db.getValue(i, "f_password").toString());
    }
}

void WGlobalDbConfig::getMonthly()
{
    DoubleDatabase fDD;
    Utils::tableSetColumnWidths(ui->tblMonthly, ui->tblMonthly->columnCount(),
                                50, 120, 100, 300);
    fDD.exec("select * from serv_monthly order by f_id");
    ui->tblMonthly->setRowCount(fDD.rowCount());
    for (int i = 0; i < fDD.rowCount(); i++) {
        ui->tblMonthly->setItemWithValue(i, 0, fDD.getValue(i, "f_id"));
        ui->tblMonthly->addLineEdit(i, 1, false)->setText(fDD.getValue(i, "f_title").toString());
        ui->tblMonthly->addLineEdit(i, 2, false)->setText(fDD.getValue(i, "f_width").toString());
        ui->tblMonthly->addLineEdit(i, 3, false)->setText(fDD.getValue(i, "f_items").toString());
    }
    Utils::tableSetColumnWidths(ui->tblCardexAnalysis, ui->tblCardexAnalysis->columnCount(),
                                50, 120, 100, 300);
    fDD.exec("select * from serv_cardex_analysis order by f_id");
    ui->tblCardexAnalysis->setRowCount(fDD.rowCount());
    for (int i = 0; i < fDD.rowCount(); i++) {
        ui->tblCardexAnalysis->setItemWithValue(i, 0, fDD.getValue(i, "f_id"));
        ui->tblCardexAnalysis->addLineEdit(i, 1, false)->setText(fDD.getValue(i, "f_title").toString());
        ui->tblCardexAnalysis->addLineEdit(i, 2, false)->setText(fDD.getValue(i, "f_width").toString());
        ui->tblCardexAnalysis->addLineEdit(i, 3, false)->setText(fDD.getValue(i, "f_items").toString());
    }
    ui->teDailyMovement->setPlainText(fPreferences.getDb(def_daily_movement_items).toString());
    ui->rbDailySubtotalDown->setChecked(fPreferences.getDb(def_daily_movement_total_side).toInt() == 0);
    ui->rbDailySubtotalUp->setChecked(fPreferences.getDb(def_daily_movement_total_side).toInt() == 1);
}

void WGlobalDbConfig::getTax()
{
    DoubleDatabase fDD;
    Utils::tableSetColumnWidths(ui->tblTax, ui->tblTax->columnCount(),
                                0, 150, 40, 150, 150, 150);
    ui->tblTax->clearContents();
    fDD.exec("select f_id, f_comp, f_active, f_host, f_port, f_password from serv_tax order by f_comp");
    ui->tblTax->setRowCount(fDD.rowCount());
    for (int i = 0; i < fDD.rowCount(); i++) {
        ui->tblTax->setItem(i, 0, new C5TableWidgetItem(fDD.getValue(i, "f_id").toString()));
        ui->tblTax->setItem(i, 1, new C5TableWidgetItem(fDD.getValue(i, "f_comp").toString()));
        ui->tblTax->setItem(i, 2, new C5TableWidgetItem(fDD.getValue(i, "f_active").toString()));
        ui->tblTax->setItem(i, 3, new C5TableWidgetItem(fDD.getValue(i, "f_host").toString()));
        ui->tblTax->setItem(i, 4, new C5TableWidgetItem(fDD.getValue(i, "f_port").toString()));
        ui->tblTax->setItem(i, 5, new C5TableWidgetItem(fDD.getValue(i, "f_password").toString()));
    }
}

void WGlobalDbConfig::getApp()
{
    DoubleDatabase fDD;
    fDD[":f_key"] = def_external_rest_db;
    fDD.exec("select f_value from f_global_settings where f_settings=1 and f_key=:f_key");
    if (fDD.nextRow()) {
        ui->leExternalRestaurantDb->setText(fDD.getString(0));
    }
}

void WGlobalDbConfig::getReportOptions()
{
    DoubleDatabase dd;
    dd.exec("select distinct(rp.f_group), g.f_en from rp_main rp "
            "left join users_groups g on g.f_id=rp.f_group");
    while (dd.nextRow()) {
        QListWidgetItem *item = new QListWidgetItem(ui->lwrpGroups);
        item->setText(dd.getString(1));
        item->setData(Qt::UserRole, dd.getInt(0));
        ui->lwrpGroups->addItem(item);
    }
}

WGlobalDbConfig::WGlobalDbConfig(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WGlobalDbConfig)
{
    ui->setupUi(this);
    ui->deWorkingDate->setDate(WORKING_DATE);
    ui->teSlogan->setPlainText(fPreferences.getDb(def_slogan).toString());
    ui->leExtraBed->setText(fPreferences.getDb(def_default_extra_bed).toString());
    ui->leDefaultCardex->setText(fPreferences.getDb(def_default_cardex).toString());
    ui->leRoomChargeId->setText(fPreferences.getDb(def_room_charge_id).toString());
    ui->teEarlyCheckin->setTime(QTime::fromString(fPreferences.getDb(def_earyly_checkin).toString(), "HH:mm"));
    ui->teLateCheckout->setTime(QTime::fromString(fPreferences.getDb(def_late_checkout).toString(), "HH:mm"));
    ui->leEarlyCheckinID->setText(fPreferences.getDb(def_earyly_checkin_id).toString());
    ui->leLateCheckoutID->setText(fPreferences.getDb(def_late_checkout_id).toString());
    ui->leAirportPickupId->setText(fPreferences.getDb(def_airport_pickup_id).toString());
    ui->leDayUse->setText(fPreferences.getDb(def_day_use_id).toString());
    ui->leVaucherDigits->setText(fPreferences.getDb(def_vouchers_digits).toString());
    ui->teVoucherRightText->setPlainText(fPreferences.getDb(def_vouchers_right_header).toString());
    ui->teVoucherInvoiceFooter->setPlainText(fPreferences.getDb(def_vouchers_invoice_footer).toString());
    ui->leBrekfastChargeId->setText(fPreferences.getDb(def_auto_breakfast_id).toString());
    ui->leDiscountId->setText(fPreferences.getDb(def_invoice_default_discount_id).toString());
    ui->lePosTransferId->setText(fPreferences.getDb(def_invoice_default_positive_transfer_id).toString());
    ui->leNegTransferId->setText(fPreferences.getDb(def_invoice_default_negative_transfer_id).toString());
    ui->leRefundId->setText(fPreferences.getDb(def_invoice_default_refund_id).toString());
    ui->chNoTrackControl->setChecked(fPreferences.getDb(def_no_tracking_changes).toBool());
    ui->leManualTax->setText(fPreferences.getDb(def_filter_manual_tax).toString());
    ui->leRoomingList->setText(fPreferences.getDb(def_rooming_list).toString());
    ui->chRestMode->setChecked(fPreferences.getDb(def_welcome_rest_mode).toInt());
    ui->leCancelCode->setText(fPreferences.getDb(def_cancelfee_code).toString());
    ui->leNoshowCode->setText(fPreferences.getDb(def_noshowfee_code).toString());
    ui->leRestHallForReception->setText(fPreferences.getDb(def_rest_hall_for_reception).toString());
    ui->leRoomArrangement->setText(fPreferences.getDb(def_room_arrangement).toString());
    ui->leReceiptVaucherId->setText(fPreferences.getDb(def_receip_vaucher_id).toString());
    ui->leReservationVoucherId->setText(fPreferences.getDb(def_reservation_voucher_id).toString());
    ui->leRoomRateChangeId->setText(fPreferences.getDb(def_room_rate_change_id).toString());
    ui->leAdvanceVoucherId->setText(fPreferences.getDb(def_advance_voucher_id).toString());
    ui->leAdvanceVoucherIdTransfer->setText(fPreferences.getDb(def_advance_transfer_voucher_id).toString());
    ui->leBreakfastHallId->setText(fPreferences.getDb(def_breakfast_default_hall).toString());
    ui->leBreakfastTableId->setText(fPreferences.getDb(def_breakfast_default_table).toString());
    ui->leBreakfastDishId->setText(fPreferences.getDb(def_breakfast_default_dish).toString());
    ui->leMinibarHallId->setText(fPreferences.getDb(def_minibar_default_hall).toString());
    ui->leMinibarTableId->setText(fPreferences.getDb(def_minibar_default_table).toString());
    ui->leMinibarDishId->setText(fPreferences.getDb(def_minibar_default_dish).toString());
    ui->chPasswordRequired->setChecked(fPreferences.getDb(def_passport_required).toInt());
    ui->chShowLogs->setChecked(fPreferences.getDb(def_show_logs).toBool());
    ui->leCheckinVoucherId->setText(fPreferences.getDb(def_checkin_voucher_id).toString());
    ui->cbInvoiceHeader->setCurrentIndex(fPreferences.getDb(def_invoice_header_mode).toInt());
    ui->leTransferAmountVoucherId->setInt(fPreferences.getDb(def_transfer_amount_id).toInt());
    ui->leRoomingEODSide->setInt(fPreferences.getDb(def_rooming_eod_default_side).toInt());
    ui->leExtraRooming->setText(fPreferences.getDb(def_extrarooming_id).toString());
    ui->chOfferDayUse->setChecked(fPreferences.getDb(def_offer_dayuse).toInt() == 1);
    ui->chOfferExtraRooming->setChecked(fPreferences.getDb(def_offer_extrarooming).toInt() == 1);
    ui->chDailyPrintCanceled->setChecked(fPreferences.getDb(def_daily_report_print_canceled) == 1);
    ui->leLog1->setText(fPreferences.getDb(def_log_main_db).toString());
    ui->leLog2->setText(fPreferences.getDb(def_log_reserve_db).toString());
    ui->chPrintVoucherAfterSave->setChecked(fPreferences.getDb(def_print_voucher_after_save).toInt() == 1);
    ui->lePenaltyList->setText(fPreferences.getDb(def_penalty_list).toString());
    ui->leRoomMoveVoucher->setText(fPreferences.getDb(def_room_move_voucher).toString());
    ui->leCheckoutVoucherId->setText(fPreferences.getDb(def_checkout_voucher_id).toString());
    ui->chothTaxGuestDetailed->setChecked(fPreferences.getDb(def_append_tax_inhouse_detailed).toBool());
    ui->chAutoSession->setChecked(fPreferences.getDb(def_user_auto_session).toBool());
    ui->leRemovalVoucherId->setText(fPreferences.getDb(def_removal_vaucher_id).toString());
    ui->chPrintTaxAfterReceipt->setChecked(fPreferences.getDb(def_print_tax_after_receipt).toBool());
    ui->chDebug->setChecked(fPreferences.getDb(def_debug_mode).toInt() > 0);
    fTrackControl = new TrackControl(TRACK_GLOBAL_CONFIG);
    fTrackControl->addWidget(ui->deWorkingDate, "Working date")
    .addWidget(ui->teSlogan, "Slogan")
    .addWidget(ui->leExtraBed, "Extra bed rate")
    .addWidget(ui->leDefaultCardex, "Default cardex code")
    .addWidget(ui->leRoomChargeId, "Room charge id")
    .addWidget(ui->leEarlyCheckinID, "Early checkin id")
    .addWidget(ui->leLateCheckoutID, "Late checkout id")
    .addWidget(ui->teEarlyCheckin, "Early checkin time")
    .addWidget(ui->teLateCheckout, "Late checkout time")
    .addWidget(ui->leAirportPickupId, "Airport pickup id")
    .addWidget(ui->leDayUse, "Day use id")
    .addWidget(ui->leVaucherDigits, "Voucher number format, digits count")
    .addWidget(ui->leBrekfastChargeId, "Breakfast charge id")
    .addWidget(ui->leDiscountId, "Default discount id")
    .addWidget(ui->lePosTransferId, "Positive balance default id")
    .addWidget(ui->leNegTransferId, "Negative balance default id")
    .addWidget(ui->chNoTrackControl, "No tracking changes")
    .addWidget(ui->leRefundId, "Refund default id")
    .addWidget(ui->leManualTax, "Manual tax filter")
    .addWidget(ui->leCancelCode, "Cancelation fee code")
    .addWidget(ui->leNoshowCode, "No show fee code")
    .addWidget(ui->leRestHallForReception, "Restaurant hall for reception")
    .addWidget(ui->leRoomArrangement, "Default room arrangement")
    .addWidget(ui->leReceiptVaucherId, "Receipt vaucher id")
    .addWidget(ui->leReservationVoucherId, "Reservation voucher id")
    .addWidget(ui->leCheckinVoucherId, "Checkin voucher id")
    .addWidget(ui->leAdvanceVoucherId, "Advance voucher id")
    .addWidget(ui->leRoomRateChangeId, "Room rate change voucher id")
    .addWidget(ui->leBreakfastHallId, "Breakfast hall id")
    .addWidget(ui->leBreakfastTableId, "Breakfast table id")
    .addWidget(ui->leBreakfastDishId, "Breakfast dish id")
    .addWidget(ui->leMinibarHallId, "Minibar hall id")
    .addWidget(ui->leMinibarTableId, "MInibar table id")
    .addWidget(ui->leMinibarDishId, "Minibar dish id")
    .addWidget(ui->chPasswordRequired, "Passport required")
    .addWidget(ui->chShowLogs, "Show logs")
    .addWidget(ui->cbInvoiceHeader, "Invoice header mode")
    .addWidget(ui->leExternalRestaurantDb, "External restaurant db")
    .addWidget(ui->leTransferAmountVoucherId, "Transfer amount voucher id")
    .addWidget(ui->leRoomingEODSide, "Rooming EOD default side")
    .addWidget(ui->leExtraRooming, "Extran rooming id")
    .addWidget(ui->chOfferDayUse, "Offer day use")
    .addWidget(ui->chOfferExtraRooming, "Offer extra rooming")
    .addWidget(ui->chDailyPrintCanceled, "Daily: always print canceled")
    .addWidget(ui->leLog1, "Log 1")
    .addWidget(ui->leLog2, "Log 2")
    .addWidget(ui->chPrintVoucherAfterSave, "Print voucher after save")
    .addWidget(ui->lePenaltyList, "Penalty list")
    .addWidget(ui->leRoomMoveVoucher, "Room move voucher")
    .addWidget(ui->leCheckoutVoucherId, "Checkout voucher id")
    .addWidget(ui->chothTaxGuestDetailed, ui->chothTaxGuestDetailed->text())
    .addWidget(ui->chAutoSession, ui->lbAutoSession->text())
    .addWidget(ui->leRemovalVoucherId, "Removal voucher id")
    .addWidget(ui->chPrintTaxAfterReceipt, "Print tax after receipt")
    .addWidget(ui->chDebug, "Debug mode");
    getCompSettings();
    getAccess();
    getDatabases();
    getMonthly();
    getTax();
    getApp();
    getReportOptions();
    fTrackControl->resetChanges();
    ui->leHallCode->setSelector(this, cache(cid_rest_hall), ui->leHallName);
    ui->lerpGroup->setSelector(this, cache(cid_users_group), ui->lerpGroupName);
}

WGlobalDbConfig::~WGlobalDbConfig()
{
    delete ui;
}

bool WGlobalDbConfig::canClose()
{
    if (!BaseWidget::canClose()) {
        if (message_confirm(tr("Save changes?")) == QDialog::Accepted) {
            on_btnSave_clicked();
        }
    }
    return true;
}

void WGlobalDbConfig::setupTab()
{
    setupTabTextAndIcon(tr("Global config"), ":/images/settings.png");
}

void WGlobalDbConfig::on_btnSave_clicked()
{
    QMap<QString, QString> values;
    values.insert(def_working_day, ui->deWorkingDate->date().toString(def_date_format));
    values.insert(def_slogan, ui->teSlogan->toPlainText());
    values.insert(def_default_extra_bed, ui->leExtraBed->text());
    values.insert(def_default_cardex, ui->leDefaultCardex->text());
    values.insert(def_room_charge_id, ui->leRoomChargeId->text());
    values.insert(def_earyly_checkin, ui->teEarlyCheckin->time().toString("HH:mm"));
    values.insert(def_late_checkout, ui->teLateCheckout->time().toString("HH:mm"));
    values.insert(def_earyly_checkin_id, ui->leEarlyCheckinID->text());
    values.insert(def_airport_pickup_id, ui->leAirportPickupId->text());
    values.insert(def_day_use_id, ui->leDayUse->text());
    values.insert(def_vouchers_digits, ui->leVaucherDigits->text());
    values.insert(def_vouchers_invoice_footer, ui->teVoucherInvoiceFooter->toPlainText());
    values.insert(def_vouchers_right_header, ui->teVoucherRightText->toPlainText());
    values.insert(def_late_checkout_id, ui->leLateCheckoutID->text());
    values.insert(def_auto_breakfast_id, ui->leBrekfastChargeId->text());
    values.insert(def_invoice_default_discount_id, ui->leDiscountId->text());
    values.insert(def_invoice_default_positive_transfer_id, ui->lePosTransferId->text());
    values.insert(def_invoice_default_negative_transfer_id, ui->leNegTransferId->text());
    values.insert(def_invoice_default_refund_id, ui->leRefundId->text());
    values.insert(def_no_tracking_changes, ui->chNoTrackControl->isChecked() ? "1" : "0");
    values.insert(def_filter_manual_tax, ui->leManualTax->text());
    values.insert(def_cancelfee_code, ui->leCancelCode->text());
    values.insert(def_noshowfee_code, ui->leNoshowCode->text());
    values.insert(def_rooming_list, ui->leRoomingList->text());
    values.insert(def_welcome_rest_mode, ui->chRestMode->isChecked() ? "1" : "0");
    values.insert(def_rest_hall_for_reception, ui->leRestHallForReception->text());
    values.insert(def_room_arrangement, ui->leRoomArrangement->text());
    values.insert(def_receip_vaucher_id, ui->leReceiptVaucherId->text());
    values.insert(def_reservation_voucher_id, ui->leReservationVoucherId->text());
    values.insert(def_checkin_voucher_id, ui->leCheckinVoucherId->text());
    values.insert(def_room_rate_change_id, ui->leRoomRateChangeId->text());
    values.insert(def_advance_voucher_id, ui->leAdvanceVoucherId->text());
    values.insert(def_advance_transfer_voucher_id, ui->leAdvanceVoucherIdTransfer->text());
    values.insert(def_breakfast_default_hall, ui->leBreakfastHallId->text());
    values.insert(def_breakfast_default_table, ui->leBreakfastTableId->text());
    values.insert(def_breakfast_default_dish, ui->leBreakfastDishId->text());
    values.insert(def_minibar_default_hall, ui->leMinibarHallId->text());
    values.insert(def_minibar_default_table, ui->leMinibarTableId->text());
    values.insert(def_minibar_default_dish, ui->leMinibarDishId->text());
    values.insert(def_passport_required, ui->chPasswordRequired->isChecked() ? "1" : "0");
    values.insert(def_show_logs, QString::number(ui->chShowLogs->isChecked()));
    values.insert(def_invoice_header_mode, QString::number(ui->cbInvoiceHeader->currentIndex()));
    values.insert(def_external_rest_db, ui->leExternalRestaurantDb->text());
    values.insert(def_daily_movement_items, ui->teDailyMovement->toPlainText());
    values.insert(def_daily_movement_total_side, ui->rbDailySubtotalDown->isChecked() ? "0" : "1");
    values.insert(def_transfer_amount_id, ui->leTransferAmountVoucherId->text());
    values.insert(def_rooming_eod_default_side, QString::number(ui->leRoomingEODSide->text().toInt()));
    values.insert(def_extrarooming_id, ui->leExtraRooming->text());
    values.insert(def_offer_dayuse, ui->chOfferDayUse->isChecked() ? "1" : "0");
    values.insert(def_offer_extrarooming, ui->chOfferExtraRooming->isChecked() ? "1" : "0");
    values.insert(def_daily_report_print_canceled, ui->chDailyPrintCanceled->isChecked() ? "1" : "0");
    values.insert(def_log_main_db, ui->leLog1->text());
    values.insert(def_log_reserve_db, ui->leLog2->text());
    values.insert(def_print_voucher_after_save, ui->chPrintVoucherAfterSave->isChecked() ? "1" : "0");
    values.insert(def_penalty_list, ui->lePenaltyList->text());
    values.insert(def_room_move_voucher, ui->leRoomMoveVoucher->text());
    values.insert(def_checkout_voucher_id, ui->leCheckoutVoucherId->text());
    values.insert(def_append_tax_inhouse_detailed, ui->chothTaxGuestDetailed->isChecked() ? "1" : "0");
    values.insert(def_user_auto_session, ui->chAutoSession->isChecked() ? "1" : "0");
    values.insert(def_removal_vaucher_id, ui->leRemovalVoucherId->text());
    values.insert(def_print_tax_after_receipt, ui->chPrintTaxAfterReceipt->isChecked() ? "1" : "0");
    values.insert(def_debug_mode, ui->chDebug->isChecked() ? "1" : "0");
    QString query = "insert into f_global_settings (f_settings, f_key, f_value) values ";
    bool first = true;
    QMapIterator<QString, QString> it(values);
    while (it.hasNext()) {
        it.next();
        if (first) {
            first = false;
        } else {
            query += ",";
        }
        query += QString("(1, '%1', '%2')")
                 .arg(it.key(), it.value());
    }
    QMap<QString, int> fNameColumnMap;
    DoubleDatabase fDD;
    fDD.exec("delete from f_global_settings where f_settings=1 and f_key not in ('HC', 'AHC', 'dd')");
    fDD.exec(query, fDD.fDbRows, fNameColumnMap);
    //Reports
    for (int i = 0; i < ui->tblMonthly->rowCount(); i++) {
        fDD[":f_title"] = ui->tblMonthly->lineEdit(i, 1)->text();
        fDD[":f_width"] = ui->tblMonthly->lineEdit(i, 2)->text();
        fDD[":f_items"] = ui->tblMonthly->lineEdit(i, 3)->text();
        fDD.update("serv_monthly", where_id(ui->tblMonthly->toString(i, 0)));
    }
    for (int i = 0; i < ui->tblCardexAnalysis->rowCount(); i++) {
        fDD[":f_title"] = ui->tblCardexAnalysis->lineEdit(i, 1)->text();
        fDD[":f_width"] = ui->tblCardexAnalysis->lineEdit(i, 2)->text();
        fDD[":f_items"] = ui->tblCardexAnalysis->lineEdit(i, 3)->text();
        fDD.update("serv_cardex_analysis", where_id(ui->tblCardexAnalysis->toString(i, 0)));
    }
    fPreferences.setDb(def_daily_movement_items, ui->teDailyMovement->toPlainText());
    fPreferences.setDb(def_daily_movement_total_side, ui->rbDailySubtotalDown->isChecked() ? 0 : 1);
    QListWidgetItem *item = ui->lwrpGroups->currentItem();
    if (item) {
        int rpgroup = item->data(Qt::UserRole).toInt();
        item = ui->lwrpReports->currentItem();
        if (item) {
            fDD[":f_group"] = rpgroup;
            fDD[":f_report"] = item->text();
            fDD[":f_fontname"] = ui->fbrpFontName->currentText();
            fDD[":f_fontsize"] = ui->sbrpFontSize->value();
            fDD[":f_printonly"] = ui->chrpReadyOnly->isChecked();
            fDD[":f_fontbold"] = ui->chrpFontBold->isChecked();
            fDD[":f_rowheight"] = ui->chrpRowHeight->value();
            fDD.exec("update rp_main set f_fontname=:f_fontname, f_fontsize=:f_fontsize, f_fontbold=:f_fontbold, "
                     "f_printonly=:f_printonly, f_rowheight=:f_rowheight where f_group=:f_group and f_report=:f_report");
        }
    }
    fTrackControl->saveChanges();
    message_info(tr("Saved"));
}

void WGlobalDbConfig::on_lwHost_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    ui->leHost->setText(index.data(Qt::DisplayRole).toString());
    ui->leHallCode->setInitialValue(index.data(Qt::UserRole).toString());
    DoubleDatabase fDD;
    fDD[":f_comp"] = index.data(Qt::DisplayRole).toString();
    fDD.exec("select f_key, f_value from r_config where upper(f_comp)=upper(:f_comp)");
    QMap<QString, QString> v;
    for (int i = 0; i < fDD.rowCount(); i++) {
        v[fDD.getValue(i, "f_key").toString()] = fDD.getValue(i, "f_value").toString();
    }
    ui->chOpenTableAfterRun->setChecked(v[dr_open_table_after_run].toInt());
    ui->leFirstReceiptPrinter->setText(v[dr_first_receipt_printer]);
    ui->leSecondReceiptPrinter->setText(v[dr_second_receipt_printer]);
    ui->leDisc20->setText(v[dr_discount_20]);
    ui->leDisc50->setText(v[dr_discount_50]);
    ui->leLongOrderTime->setText(v[dr_long_order_time]);
    ui->cbNewDishState->setCurrentIndex(v[dr_new_dish_state_after_close].toInt());
}

void WGlobalDbConfig::on_btnSaveRestaurant_clicked()
{
    if (ui->leHost->text().isEmpty()) {
        message_error(tr("Host not selected"));
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_hall"] = ui->leHallCode->text();
    fDD.update("s_tax_print", where_field("f_comp", "'" + ui->leHost->text() + "'"));
    fDD[":f_comp"] = ui->leHost->text();
    fDD.exec("delete from r_config where f_comp=:f_comp");
    fDD[":f_comp"] = ui->leHost->text();
    fDD[":f_key"] = dr_open_table_after_run;
    fDD[":f_value"] = ui->chOpenTableAfterRun->isChecked() ? "1" : "0";
    fDD.insert("r_config");
    fDD[":f_comp"] = ui->leHost->text();
    fDD[":f_key"] = dr_first_receipt_printer;
    fDD[":f_value"] = ui->leFirstReceiptPrinter->text();
    fDD.insert("r_config");
    fDD[":f_comp"] = ui->leHost->text();
    fDD[":f_key"] = dr_second_receipt_printer;
    fDD[":f_value"] = ui->leSecondReceiptPrinter->text();
    fDD.insert("r_config");
    fDD[":f_comp"] = ui->leHost->text();
    fDD[":f_key"] = dr_discount_20;
    fDD[":f_value"] = ui->leDisc20->text();
    fDD.insert("r_config");
    fDD[":f_comp"] = ui->leHost->text();
    fDD[":f_key"] = dr_discount_50;
    fDD[":f_value"] = ui->leDisc50->text();
    fDD.insert("r_config");
    fDD[":f_comp"] = ui->leHost->text();
    fDD[":f_key"] = dr_long_order_time;
    fDD[":f_value"] = ui->leLongOrderTime->text();
    fDD.insert("r_config");
    fDD[":f_comp"] = ui->leHost->text();
    fDD[":f_key"] = dr_new_dish_state_after_close;
    fDD[":f_value"] = ui->cbNewDishState->currentIndex();
    fDD.insert("r_config");
    getCompSettings();
    message_info(tr("Saved"));
}

void WGlobalDbConfig::on_btnRefresh_clicked()
{
    getAccess();
}

void WGlobalDbConfig::on_btnSaveAccess_clicked()
{
    DoubleDatabase db(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass);
    if (!db.open()) {
        return;
    }
    db.exec("delete from f_access");
    for (int i = 0; i < ui->tblAccess->rowCount(); i++) {
        for (int j = 1; j < ui->tblAccess->columnCount(); j++) {
            db[":f_user"] = ui->tblAccess->toString(i, 0);
            db[":f_db"] = ui->tblAccess->item(i, j)->data(Qt::UserRole);
            db[":f_right"] = (ui->tblAccess->checkBox(i, j)->isChecked() ? 1 : 0);
            db.insert("f_access", false);
        }
    }
    // BroadcastThread::cmdCommand(cmd_global_settings, QMap<QString, QString>());
    message_info(tr("Saved"));
}

void WGlobalDbConfig::on_btnSaveDatabases_clicked()
{
    DoubleDatabase db(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass);
    if (!db.open()) {
        return;
    }
    DoubleDatabase fDD;
    for (int i = 0; i < ui->tblDatabases->rowCount(); i++) {
        fDD[":f_name"] = ui->tblDatabases->lineEdit(i, 1)->text();
        fDD[":f_host"] = ui->tblDatabases->lineEdit(i, 2)->text();
        fDD[":f_database"] = ui->tblDatabases->lineEdit(i, 3)->text();
        fDD[":f_username"] = ui->tblDatabases->lineEdit(i, 4)->text();
        fDD[":f_password"] = ui->tblDatabases->lineEdit(i, 5)->text();
        if (ui->tblDatabases->lineEdit(i, 0)->asInt() == 0) {
            ui->tblDatabases->lineEdit(i, 0)->setInt(db.insert("f_db"));
        } else {
            db.update("f_db", where_id(ap(ui->tblDatabases->lineEdit(i, 0)->text())));
        }
    }
    BroadcastThread::cmdCommand(cmd_global_settings, QMap<QString, QString>());
    message_info(tr("Saved"));
}

void WGlobalDbConfig::on_btnRemoveStation_clicked()
{
    QModelIndexList sel = ui->tblAccess->selectionModel()->selectedRows();
    if (sel.count() == 0) {
        message_error(tr("Nothing was selected"));
        return;
    }
    if (message_confirm(tr("Confirm to remove station")) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase db;
    db.setDatabase(__dd1Host, "airwick", __dd1Username, __dd1Password);
    if (!db.open()) {
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_name"] = ui->tblAccess->toString(sel.at(0).row(), 0);
    db.exec("delete from f_users where lower(f_name)=lower(:f_name)");
    fDD[":f_user"] = ui->tblAccess->toString(sel.at(0).row(), 0);
    db.exec("delete from f_access where lower(f_user)=lower(:f_user)");
    db.close();
    getAccess();
}

void WGlobalDbConfig::on_btnRefreshReset_clicked()
{
    getCompSettings();
}

void WGlobalDbConfig::on_btnRemoveRest_clicked()
{
    QModelIndex index = ui->lwHost->currentIndex();
    if (!index.isValid()) {
        message_error(tr("Nothing was selected"));
    }
    if (message_confirm(tr("Confirm to delete")) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_comp"] = index.data(Qt::DisplayRole).toString();
    fDD.exec("delete from s_tax_print where f_comp=:f_comp");
    getCompSettings();
}

void WGlobalDbConfig::on_btnRefreshTax_clicked()
{
    getTax();
}

void WGlobalDbConfig::on_tblTax_cellDoubleClicked(int row, int column)
{
    if (row < 0 || column < 0) {
        return;
    }
    DlgEditServTax *d = new DlgEditServTax(this);
    d->setParams(ui->tblTax->toInt(row, 0),
                 ui->tblTax->toString(row, 1),
                 ui->tblTax->toInt(row, 2),
                 ui->tblTax->toString(row, 3),
                 ui->tblTax->toString(row, 4),
                 ui->tblTax->toString(row, 5));
    if (d->exec() == QDialog::Accepted) {
        getTax();
    }
    delete d;
}

void WGlobalDbConfig::on_chShowLogs_clicked(bool checked)
{
    fPreferences.setDb(def_show_logs, checked);
}

void WGlobalDbConfig::on_btnRemoveDatabase_clicked()
{
    QModelIndexList rows = ui->tblDatabases->selectionModel()->selectedIndexes();
    if (rows.count() == 0) {
        return;
    }
    if (message_confirm(tr("Confirm to remove database")) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase db(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass);
    db.open();
    db[":f_id"] = ui->tblDatabases->lineEdit(rows.at(0).row(), 0)->asInt();
    db.exec("delete from airwick.f_db where f_id=:f_id");
    db[":f_id"] = ui->tblDatabases->lineEdit(rows.at(0).row(), 0)->asInt();
    db.exec("delete from airwick.f_access where f_db=:f_id");
    ui->tblDatabases->removeRow(rows.at(0).row());
    message_info(tr("Database removed"));
}

void WGlobalDbConfig::on_btnInitExtRestData_clicked()
{
    DoubleDatabase dd;
    //    dd.exec("delete from r_dish");
    //    dd.exec("delete from r_dish_type");
    DoubleDatabase dr(__dd1Host, ui->leExternalRestaurantDb->text(), __dd1Username, __dd1Password);
    if (!dr.open()) {
        message_error(dr.fLastError);
        return;
    }
    QMap<int, QString> adg;
    dr.exec("select f_id, f_name, f_adgcode from d_part2");
    while (dr.nextRow()) {
        continue;
        dd[":f_id"] = dr.getInt(0);
        dd[":f_part"] = 1;
        dd[":f_en"] = dr.getString(1);
        dd[":f_am"] = dr.getString(1);
        dd[":f_ru"] = dr.getString(1);
        adg[dr.getInt(0)] = dr.getString(2);
        dd[":f_bgcolor"] = -1;
        dd[":f_textcolor"] = -16777216;
        dd[":f_queue"] = dr.getInt(0);
        dd[":f_active"] = 1;
        dd.insert("r_dish_type", false);
        dd[":f_id"] = dr.getInt(0);
        dd[":f_part"] = 1;
        dd[":f_en"] = dr.getString(1);
        dd[":f_am"] = dr.getString(1);
        dd[":f_ru"] = dr.getString(1);
        adg[dr.getInt(0)] = dr.getString(2);
        dd[":f_bgcolor"] = -1;
        dd[":f_textcolor"] = -16777216;
        dd[":f_queue"] = dr.getInt(0);
        dd[":f_active"] = 1;
        dd.update("r_dish_type", where_id(dr.getInt(0)));
    }
    dr.exec("select d.f_id, d.f_part, d.f_name, p.f_adgcode "
            "from d_dish d "
            "inner join d_part2 p on p.f_id=d.f_part ");
    while (dr.nextRow()) {
        dd[":f_id"] = dr.getInt(0);
        dd[":f_type"] = dr.getInt(1);
        dd[":f_en"] = dr.getString(2);
        dd[":f_am"] = dr.getString(2);
        dd[":f_ru"] = dr.getString(2);
        dd[":f_bgcolor"] = -1;
        dd[":f_textcolor"] = -16777216;
        dd[":f_queue"] = dr.getInt(0);
        dd[":f_unit"] = 1;
        dd[":f_adgt"] = dr.getString("f_adgcode");
        dd.insert("r_dish", false);
        dd[":f_id"] = dr.getInt(0);
        dd[":f_type"] = dr.getInt(1);
        dd[":f_en"] = dr.getString(2);
        dd[":f_am"] = dr.getString(2);
        dd[":f_ru"] = dr.getString(2);
        dd[":f_bgcolor"] = -1;
        dd[":f_textcolor"] = -16777216;
        dd[":f_queue"] = dr.getInt(0);
        dd[":f_unit"] = 1;
        dd[":f_adgt"] = dr.getString("f_adgcode");
        dd.update("r_dish", where_id(dr.getInt(0)));
    }
    message_info(tr("Done"));
}

void WGlobalDbConfig::on_leExternalRestaurantDb_textChanged(const QString &arg1)
{
    ui->btnInitExtRestData->setEnabled(!arg1.isEmpty());
}

void WGlobalDbConfig::on_btnCorrectRoomChart_clicked()
{
    DoubleDatabase dd1;
    dd1.exec("delete from f_reservation_chart");
    dd1.exec("delete from f_reservation_map");
    dd1.exec("select r.f_id, r.f_invoice, r.f_state, r.f_reservestate, r.f_room, r.f_startdate, r.f_enddate, "
             "g.guest as f_guest, r.f_cardex, c.f_name as f_cardexname, rm.f_short as f_roomshort, rm.f_state as f_roomstate, sn.f_en as f_statename, rsn.f_en as f_reservestatename,  "
             "r.f_invoice, r.f_group, rg.f_name as f_groupname, rm.f_building, rm.f_floor, group_concat(g1.gname separator ', ') as f_allguest, rm.f_class "
             "from f_reservation r "
             "left join guests g on g.f_id=r.f_guest "
             "left join f_cardex c on c.f_cardex=r.f_cardex "
             "left join f_room rm on rm.f_id=r.f_room "
             "left join f_reservation_state sn on sn.f_id=r.f_state "
             "left join f_reservation_status rsn on rsn.f_id=r.f_reservestate "
             "left join f_reservation_group rg on rg.f_id=r.f_group "
             "left join (select f_reservation, concat(g.f_title, ' ', g.f_firstName, ' ' , g.f_lastName) as gname "
             "from f_reservation_guests gr left join f_guests g on g.f_id=gr.f_guest) g1 on g1.f_reservation=r.f_id "
             "where r.f_state in (1,2,4,7,9) and r.f_room>0 and r.f_startdate is not null "
             "group by 1 ");
    while (dd1.nextRow()) {
        DoubleDatabase dd2;
        dd2[":f_id"] = dd1.getString("f_id");
        dd2[":f_invoice"] = dd1.getString("f_invoice");
        dd2[":f_state"] = dd1.getInt("f_state");
        dd2[":f_statename"] = dd1.getString("f_statename");
        dd2[":f_reservestate"] = dd1.getInt("f_reservestate");
        dd2[":f_reservestatename"] = dd1.getString("f_reservestatename");
        dd2[":f_room"] = dd1.getInt("f_room");
        dd2[":f_roomcategory"] = dd1.getInt("f_class");
        dd2[":f_roomshort"] = dd1.getString("f_roomshort");
        dd2[":f_roomstate"] = dd1.getString("f_roomstate");
        dd2[":f_roomfloor"] = dd1.getInt("f_floor");
        dd2[":f_roombuilding"] = dd1.getInt("f_building");
        dd2[":f_startdate"] = dd1.getDate("f_startdate");
        dd2[":f_enddate"] = dd1.getDate("f_enddate");
        dd2[":f_days"] = dd1.getDate("f_startdate").daysTo(dd1.getDate("f_enddate"));
        dd2[":f_guest"] = dd1.getString("f_guest");
        dd2[":f_allguest"] = dd1.getString("f_allguest");
        dd2[":f_cardex"] = dd1.getString("f_cardex");
        dd2[":f_cardexname"] = dd1.getString("f_cardexname");
        dd2[":f_groupcode"] = dd1.getInt("f_group");
        dd2[":f_groupname"] = dd1.getString("f_groupname");
        dd2.insert("f_reservation_chart", false);
        if (dd1.getDate("f_startdate").daysTo(dd1.getDate("f_enddate")) == 0) {
            dd2[":f_reservation"] = dd1.getString("f_id");
            dd2[":f_room"] = dd1.getInt("f_room");
            dd2[":f_date"] = dd1.getDate("f_startdate");
            dd2[":f_entry"] = 1;
            dd2[":f_departure"] = 1;
            dd2.insert("f_reservation_map", false);
        } else {
            for (qint64 i = 0, count = dd1.getDate("f_startdate").daysTo(dd1.getDate("f_enddate")); i < count; i++) {
                dd2[":f_reservation"] = dd1.getString("f_id");
                dd2[":f_room"] = dd1.getInt("f_room");
                dd2[":f_date"] = dd1.getDate("f_startdate").addDays(i);
                dd2[":f_entry"] = (i == 0 ? 1 : 0);
                dd2[":f_departure"] = (i == count - 1 ? 1 : 0);
                dd2.insert("f_reservation_map", false);
            }
        }
    }
    message_info(tr("Done"));
}

void WGlobalDbConfig::on_btnAddrpGroup_clicked()
{
    if (ui->lerpGroup->asInt() == 0) {
        return;
    }
    for (int i = 0; i < ui->lwrpGroups->count(); i++) {
        QListWidgetItem *item = ui->lwrpGroups->item(i);
        if (item->data(Qt::UserRole).toInt() == ui->lerpGroup->asInt()) {
            ui->lwrpGroups->setCurrentRow(i);
            return;
        }
    }
    QListWidgetItem *item = new QListWidgetItem(ui->lwrpGroups);
    item->setText(ui->lerpGroupName->text());
    item->setData(Qt::UserRole, ui->lerpGroup->asInt());
    ui->lwrpGroups->addItem(item);
    ui->lwrpGroups->setCurrentItem(item);
    ui->lerpGroup->setInt(0);
}
void WGlobalDbConfig::on_lwrpGroups_currentRowChanged(int currentRow)
{
    QListWidgetItem *item = ui->lwrpGroups->item(currentRow);
    int group = item->data(Qt::UserRole).toInt();
    ui->lwrpReports->clear();
    DoubleDatabase dd;
    dd[":f_group"] = item->data(Qt::UserRole).toInt();
    dd.exec("select f_report from rp_main where f_group=:f_group");
    while (dd.nextRow()) {
        QListWidgetItem *item = new QListWidgetItem(ui->lwrpReports);
        item->setText(dd.getString(0));
        item->setData(Qt::UserRole, group);
        ui->lwrpReports->addItem(item);
    }
}

void WGlobalDbConfig::on_lwrpReports_currentRowChanged(int currentRow)
{
    if (currentRow < 0) {
        return;
    }
    QListWidgetItem *item = ui->lwrpReports->item(currentRow);
    DoubleDatabase dd;
    dd[":f_group"] = item->data(Qt::UserRole);
    dd[":f_report"] = item->text();
    dd.exec("select * from rp_main where f_group=:f_group and f_report=:f_report");
    if (dd.nextRow()) {
        ui->chrpReadyOnly->setChecked(dd.getInt("f_printonly"));
        ui->fbrpFontName->setCurrentText(dd.getString("f_fontname"));
        ui->sbrpFontSize->setValue(dd.getInt("f_fontsize"));
        ui->chrpFontBold->setChecked(dd.getInt("f_fontbold"));
        ui->chrpRowHeight->setValue(dd.getInt("f_rowheight"));
    }
}

void WGlobalDbConfig::on_chDebug_clicked(bool checked)
{
    fPreferences.setDb(def_debug_mode, checked);
}

void WGlobalDbConfig::on_btnAddRoomType_clicked()
{
}

void WGlobalDbConfig::on_btnRemoveRoomType_clicked()
{
}

void WGlobalDbConfig::on_btnAddRatePlan_clicked()
{
}

void WGlobalDbConfig::on_btnRemoveRatePlan_clicked()
{
}
