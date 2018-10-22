#include "wglobaldbconfig.h"
#include "ui_wglobaldbconfig.h"
#include "message.h"
#include "defrest.h"
#include "cacheresthall.h"
#include "dlgeditservtax.h"

void WGlobalDbConfig::getCompSettings()
{
    ui->lwHost->clear();
    DoubleDatabase fDD(true, doubleDatabase);
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
    db.setDatabase(__dd1Host, "airwick", __dd1Username, __dd1Password, 1);
    if (!db.open(true, false)) {
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
    db.setDatabase(__dd1Host, "airwick", __dd1Username, __dd1Password, 1);
    if (!db.open(true, false)) {
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
    DoubleDatabase fDD(true, doubleDatabase);
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
    ui->rbDailySubtotalDown->setChecked(fPreferences.getDb(def_daily_movement_total_side).toInt());
}

void WGlobalDbConfig::getTax()
{
    DoubleDatabase fDD(true, doubleDatabase);
    Utils::tableSetColumnWidths(ui->tblTax, ui->tblTax->columnCount(),
                                     0, 150, 40, 150, 150, 150);
    ui->tblTax->clearContents();
    
    fDD.exec("select f_id, f_comp, f_active, f_host, f_port, f_password from serv_tax order by f_comp");
    ui->tblTax->setRowCount(fDD.rowCount());
    for (int i = 0; i < fDD.rowCount(); i++) {
        ui->tblTax->setItem(i, 0, new QTableWidgetItem(fDD.getValue(i, "f_id").toString()));
        ui->tblTax->setItem(i, 1, new QTableWidgetItem(fDD.getValue(i, "f_comp").toString()));
        ui->tblTax->setItem(i, 2, new QTableWidgetItem(fDD.getValue(i, "f_active").toString()));
        ui->tblTax->setItem(i, 3, new QTableWidgetItem(fDD.getValue(i, "f_host").toString()));
        ui->tblTax->setItem(i, 4, new QTableWidgetItem(fDD.getValue(i, "f_port").toString()));
        ui->tblTax->setItem(i, 5, new QTableWidgetItem(fDD.getValue(i, "f_password").toString()));
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
    ui->leBreakfastHallId->setText(fPreferences.getDb(def_breakfast_default_hall).toString());
    ui->leBreakfastTableId->setText(fPreferences.getDb(def_breakfast_default_table).toString());
    ui->leBreakfastDishId->setText(fPreferences.getDb(def_breakfast_default_dish).toString());
    ui->leMinibarHallId->setText(fPreferences.getDb(def_minibar_default_hall).toString());
    ui->leMinibarTableId->setText(fPreferences.getDb(def_minibar_default_table).toString());
    ui->leMinibarDishId->setText(fPreferences.getDb(def_minibar_default_dish).toString());
    ui->chPasswordRequired->setChecked(fPreferences.getDb(def_passport_required).toInt());
    ui->chShowLogs->setChecked(fPreferences.getDb(def_show_logs).toBool());

    fTrackControl =  new TrackControl(TRACK_GLOBAL_CONFIG);
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
            ;

    getCompSettings();
    getAccess();
    getDatabases();
    getMonthly();
    getTax();

    ui->leHallCode->setSelector(this, cache(cid_rest_hall), ui->leHallName);
}

WGlobalDbConfig::~WGlobalDbConfig()
{
    delete ui;
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
    values.insert(def_no_tracking_changes, QString::number((int)ui->chNoTrackControl->isChecked()));
    values.insert(def_filter_manual_tax, ui->leManualTax->text());
    values.insert(def_cancelfee_code, ui->leCancelCode->text());
    values.insert(def_noshowfee_code, ui->leNoshowCode->text());
    values.insert(def_rooming_list, ui->leRoomingList->text());
    values.insert(def_welcome_rest_mode, QString("%1").arg((int)ui->chRestMode->isChecked()));
    values.insert(def_rest_hall_for_reception, ui->leRestHallForReception->text());
    values.insert(def_room_arrangement, ui->leRoomArrangement->text());
    values.insert(def_receip_vaucher_id, ui->leReceiptVaucherId->text());
    values.insert(def_reservation_voucher_id, ui->leReservationVoucherId->text());
    values.insert(def_room_rate_change_id, ui->leRoomRateChangeId->text());
    values.insert(def_advance_voucher_id, ui->leAdvanceVoucherId->text());
    values.insert(def_breakfast_default_hall, ui->leBreakfastHallId->text());
    values.insert(def_breakfast_default_table, ui->leBreakfastTableId->text());
    values.insert(def_breakfast_default_dish, ui->leBreakfastDishId->text());
    values.insert(def_minibar_default_hall, ui->leMinibarHallId->text());
    values.insert(def_minibar_default_table, ui->leMinibarTableId->text());
    values.insert(def_minibar_default_dish, ui->leMinibarDishId->text());
    values.insert(def_passport_required, QString::number((int)ui->chPasswordRequired->isChecked()));
    values.insert(def_show_logs, QString::number(ui->chShowLogs->isChecked()));
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
                .arg(it.key())
                .arg(it.value());
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.startTransaction();
    fDD.exec("delete from f_global_settings where f_settings=1 and f_key not in ('HC', 'AHC', 'dd')");
    bool result = fDD.exec(query);
    fTrackControl->saveChanges();
    if (result) {
        fDD.commit();
        on_btnSaveReports_clicked();
        BroadcastThread::cmdCommand(cmd_global_settings, QMap<QString, QString>());
    } else {
        fDD.rollback();
        message_error(tr("New values not saved"));
    }
}

void WGlobalDbConfig::on_lwHost_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    ui->leHost->setText(index.data(Qt::DisplayRole).toString());
    ui->leHallCode->setInitialValue(index.data(Qt::UserRole).toString());
    DoubleDatabase fDD(true, doubleDatabase);
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
}

void WGlobalDbConfig::on_btnSaveRestaurant_clicked()
{
    if (ui->leHost->text().isEmpty()) {
        message_error(tr("Host not selected"));
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_hall"] = ui->leHallCode->text();
    fDD.update("s_tax_print", where_field("f_comp", "'" + ui->leHost->text() + "'"));
    fDD[":f_comp"] = ui->leHost->text();
    fDD.exec("delete from r_config where f_comp=:f_comp");
    fDD[":f_comp"] = ui->leHost->text();
    fDD[":f_key"] = dr_open_table_after_run;
    fDD[":f_value"] = QString("%1").arg((int)ui->chOpenTableAfterRun->isChecked());
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

    getCompSettings();
    message_info(tr("Saved"));
}

void WGlobalDbConfig::on_btnRefresh_clicked()
{
    getAccess();
}

void WGlobalDbConfig::on_btnSaveAccess_clicked()
{
    DoubleDatabase db(BaseUID::fAirHost, BaseUID::fAirDbName, BaseUID::fAirUser, BaseUID::fAirPass);
    if (!db.open(true, false)) {
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
    DoubleDatabase db(BaseUID::fAirHost, BaseUID::fAirDbName, BaseUID::fAirUser, BaseUID::fAirPass);
    if (!db.open(true, false)) {
        return;
    }

    DoubleDatabase fDD(true, doubleDatabase);
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

void WGlobalDbConfig::on_btnSaveReports_clicked()
{
    DoubleDatabase fDD(true, doubleDatabase);
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
    fDD[":f_key"] = def_daily_movement_items;
    fDD.exec("delete from f_global_settings where f_key=:f_key and f_settings=1");

    fDD[":f_key"] = def_daily_movement_total_side;
    fDD.exec("delete from f_global_settings where f_key=:f_key and f_settings=1");

    fDD[":f_key"] = def_daily_movement_order;
    fDD.exec("delete from f_global_settings where f_key=:f_key and f_settings=1");

    fDD[":f_settings"] = 1;
    fDD[":f_key"] = def_daily_movement_items;
    fDD[":f_value"] = ui->teDailyMovement->toPlainText();
    fDD.insert("f_global_settings");

    fDD[":f_settings"] = 1;
    fDD[":f_key"] = def_daily_movement_total_side;
    fDD[":f_value"] = (int) ui->rbDailySubtotalDown->isChecked();
    fDD.insert("f_global_settings");

    fPreferences.setDb(def_daily_movement_items, ui->teDailyMovement->toPlainText());
    fPreferences.setDb(def_daily_movement_total_side, (int) ui->rbDailySubtotalDown->isChecked());
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
    db.setDatabase(__dd1Host, "airwick", __dd1Username, __dd1Password, 1);
    if (!db.open(true, false)) {
        return;
    }
    DoubleDatabase fDD(true, doubleDatabase);
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
    DoubleDatabase fDD(true, doubleDatabase);
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

void WGlobalDbConfig::on_btnSaveApplication_clicked()
{

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
    DoubleDatabase db(BaseUID::fAirHost, BaseUID::fAirDbName, BaseUID::fAirUser, BaseUID::fAirPass);
    db.open(true, false);
    db[":f_id"] = ui->tblDatabases->lineEdit(rows.at(0).row(), 0)->asInt();
    db.exec("delete from airwick.f_db where f_id=:f_id");
    db[":f_id"] = ui->tblDatabases->lineEdit(rows.at(0).row(), 0)->asInt();
    db.exec("delete from airwick.f_access where f_db=:f_id");
    ui->tblDatabases->removeRow(rows.at(0).row());
    message_info(tr("Database removed"));
}
