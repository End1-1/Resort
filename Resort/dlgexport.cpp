#include "dlgexport.h"
#include "ui_dlgexport.h"
#include "vauchers.h"
#include "fvauchers.h"
#include <QTextBlock>

DlgExport::DlgExport(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgExport)
{
    ui->setupUi(this);
    QStringList dbParams = fPreferences.getDb("AHC").toString().split(";", Qt::SkipEmptyParts);
    if (dbParams.count() < 4) {
        message_error(tr("Setup second database parameters"));
        return;
    }
    ui->leHost->setText(dbParams[0]);
    ui->leDatabase->setText(dbParams[1]);
    ui->leUsername->setText(dbParams[2]);
    ui->lePassword->setText(dbParams[3]);
}

DlgExport::~DlgExport()
{
    delete ui;
}

void DlgExport::start()
{
    DlgExport *d = new DlgExport(fPreferences.getDefaultParentForMessage());
    d->exec();
    delete d;
}

void DlgExport::on_btnStart_clicked()
{
    if (message_confirm(tr("Confirm to start")) != QDialog::Accepted) {
        return;
    }
    QStringList ids;
    DoubleDatabase fDD;
    DoubleDatabase sDb;
    sDb.setDatabase(ui->leHost->text(), ui->leDatabase->text(), ui->leUsername->text(), ui->lePassword->text());
    if (!sDb.open()) {
        ui->ptLog->appendPlainText("Connection error, " + sDb.fLastError);
        return;
    }
    sDb.startTransaction();
    ui->ptLog->appendPlainText("Started...");
    DoubleDatabase dd;
    dd.open();
    bool err = false;
    // WORKING DATE
    ui->ptLog->appendPlainText("Working date");
    sDb[":f_key"] = def_working_day;
    err = sDb.exec("delete from f_global_settings where f_key=:f_key");
    if (err) {
        goto ERR;
    }
    sDb[":f_key"] = def_working_day;
    sDb[":f_settings"] = 1;
    sDb[":f_value"] = WORKING_DATE.toString("dd/MM/yyyy");
    err = sDb.insert("f_global_settings");
    if (err) {
        goto ERR;
    }
    ui->chWorkingDate->setChecked(true);
    // END OF WORKING DATE
    //CHECKIN RESERVATION
    {
        ui->ptLog->appendPlainText("Checkin and reservations");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        fDD[":f_state1"] = RESERVE_CHECKIN;
        fDD[":f_state2"] = RESERVE_RESERVE;
        fDD.exec("select * from f_reservation where f_state=:f_state1 or f_state=:f_state2");
        for (int i = 0; i < fDD.rowCount(); i++) {
            fDD.getBindValues(i, sDb.fBindValues);
            DoubleDatabase dd;
            dd.open();
            dd[":f_id"] = sDb.fBindValues[":f_id"];
            ids << sDb[":f_id"].toString();
            dd.exec("delete from f_reservation where f_id=:f_id");
            err = sDb.insert("f_reservation", false);
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(fDD.rowCount()));
        }
        ui->chCheckinReserve->setChecked(true);
        // END CHECKIN RESERVATION
        ui->ptLog->appendPlainText("Reservation groups");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        int resCount = 0;
        for (int i = 0; i < fDD.rowCount(); i++) {
            if (fDD.getValue(i, "f_group").toInt() > 0) {
                resCount++;
                DoubleDatabase dt;
                dt.open();
                dt[":f_id"] = fDD.getValue(i, "f_group").toInt();
                err = dt.exec("select * from f_reservation_group where f_id=:f_id");
                if (err) {
                    goto ERR;
                }
                if (dt.rowCount() == 0) {
                    ui->ptLog->appendPlainText("Missing group with id " + fDD.getValue(i, "f_group").toString());
                    ui->ptLog->appendPlainText("Continue...");
                    continue;
                }
                dd[":f_id"] = fDD.getValue(i, "f_group").toInt();
                err = dd.exec("delete from f_reservation_group where f_id=:f_id");
                if (err) {
                    goto ERR;
                }
                dt.getBindValues(0, sDb.fBindValues);
                err = sDb.insert("f_reservation_group", false);
                if (err) {
                    goto ERR;
                }
            }
            replacePtLastLine(QString("%1 of %2 entries, found %3").arg(i + 1).arg(fDD.rowCount()).arg(resCount));
        }
        ui->ptLog->appendPlainText("Reservation groups extra names");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        {
            DoubleDatabase drge;
            drge.open();
            if (!drge.exec("select * from f_reservation_group where length(f_extra1)>0")) {
                goto ERR;
            }
            for (int i = 0; i < drge.rowCount(); i++) {
                drge.getBindValues(i, sDb.fBindValues);
                sDb[":f_name"] = sDb[":f_extra1"];
                sDb.update("f_reservation_group", where_id(sDb[":f_id"].toInt()));
                replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(drge.rowCount()));
            }
        }
        ui->chReserveGroups->setChecked(true);
        //VOUCHERS FOR CHECKIN AND RESERVATIONS
        ui->ptLog->appendPlainText("Vouchers for checkin reservation");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        DoubleDatabase dr2;
        dr2.open();
        dr2[":f_state1"] = RESERVE_CHECKIN;
        dr2[":f_state2"] = RESERVE_RESERVE;
        dr2.exec("select * from m_register where f_inv in (select f_invoice from f_reservation where f_state=:f_state1 or f_state=:f_state2)");
        for (int i = 0; i < dr2.rowCount(); i++) {
            dr2.getBindValues(i, sDb.fBindValues);
            ids << sDb[":f_id"].toString();
            dd[":f_id"] = sDb[":f_id"];
            dd.exec("delete from m_register where f_id=:f_id");
            err = sDb.insert("m_register", false);
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr2.rowCount()));
        }
        ui->chVouchers->setChecked(true);
        //END VOUCHERS FOR CHECKIN AND RESERVATIONS
        //RESTAURANT VOUCHERS OF ONLINE RESERVATIONS
        ui->ptLog->appendPlainText("Restaurant vouchers for checkin reservation");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        int restCount = 0;
        for (int i = 0; i < dr2.rowCount(); i++) {
            if (dr2.getValue(i, "f_source").toString() == VAUCHER_POINT_SALE_N) {
                restCount++;
                DoubleDatabase dt1;
                dt1.open();
                dt1[":f_id"] = dr2.getValue(i, "f_id");
                dt1.exec("select * from o_header where f_id=:f_id");
                if (dt1.rowCount() == 0) {
                    ui->ptLog->appendPlainText(QString("Missing o_header for %1").arg(dr2.getValue(i, "f_id").toString()));
                    ui->ptLog->appendPlainText("Continue...");
                    continue;
                }
                dt1.getBindValues(0, sDb.fBindValues);
                dd[":f_id"] = dr2.getValue(i, "f_id");
                dd.exec("delete from o_header where f_id=:f_id");
                err = sDb.insert("o_header", false);
                if (err) {
                    goto ERR;
                }
                DoubleDatabase dt2;
                dt2.open();
                dt2[":f_header"] = dr2.getValue(i, "f_id");
                dt2.exec("select * from o_dish where f_header=:f_header");
                for (int j = 0; j < dt2.rowCount(); j++) {
                    dt2.getBindValues(j, sDb.fBindValues);
                    ids << sDb[":f_id"].toString();
                    dd[":f_id"] = sDb[":f_id"];
                    dd.exec("delete from o_dish where f_id=:f_id");
                    err = sDb.insert("o_dish", false);
                    if (err) {
                        goto ERR;
                    }
                }
            }
            replacePtLastLine(QString("%1 of %2 entries checked, %3 found").arg(i + 1).arg(dr2.rowCount()).arg(restCount));
        }
        ui->chRoomRestaurant->setChecked(true);
        //END RESTAURANT VOUCHERS
        //GUESTS
        ui->ptLog->appendPlainText("Guests");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        DoubleDatabase dr3;
        dr3.open();
        dr3[":f_state1"] = RESERVE_CHECKIN;
        dr3[":f_state2"] = RESERVE_RESERVE;
        dr3.exec("select * from f_guests where f_id in (select f_guest from f_reservation where f_state=:f_state1 or f_state=:f_state2) "
                 "or f_id in (select f_guest from f_reservation_guests where f_reservation in (select f_id from f_reservation where f_state=:f_state1 or f_state=:f_state2))");
        if (dr3.rowCount() == 0) {
            goto ERR;
        }
        for (int i = 0; i < dr3.rowCount(); i++) {
            dr3.getBindValues(i, sDb.fBindValues);
            dd[":f_id"] = sDb[":f_id"];
            dd.exec("delete from f_guests where f_id=:f_id");
            err = sDb.insert("f_guests", false);
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr3.rowCount()));
        }
        ui->chGuests->setChecked(true);
        //END GUESTS
        //F_RESERVATION_GUESTS
        ui->ptLog->appendPlainText("Reservation guests");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        DoubleDatabase dr4;
        dr4.open();
        dr4[":f_state1"] = RESERVE_CHECKIN;
        dr4[":f_state2"] = RESERVE_RESERVE;
        dr4.exec("select * from f_reservation_guests where f_reservation in (select f_id from f_reservation where f_state=:f_state1 or f_state=:f_state2)");
        if (dr4.rowCount() == 0) {
            goto ERR;
        }
        ui->ptLog->appendPlainText("Deleting old Reservation guests");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        for (int i = 0; i < dr4.rowCount(); i++) {
            dr4.getBindValues(i, sDb.fBindValues);
            dd[":f_reservation"] = sDb[":f_reservation"];
            err = dd.exec("delete from f_reservation_guests where f_reservation=:f_reservation");
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr4.rowCount()));
        }
        ui->ptLog->appendPlainText("Inserting new Reservation guests");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        for (int i = 0; i < dr4.rowCount(); i++) {
            dr4.getBindValues(i, sDb.fBindValues);
            sDb.fBindValues.remove(":f_id");
            err = sDb.insert("f_reservation_guests", false);
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr4.rowCount()));
        }
        ui->ptLog->appendPlainText("Inserting new Reservation guests");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        ui->chReservationGuest->setChecked(true);
        ui->ptLog->appendPlainText("Room states");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        DoubleDatabase dr8;
        dr8.open();
        dr8.exec("select * from f_room");
        for (int i = 0; i < dr8.rowCount(); i++) {
            dr8.getBindValues(i, sDb.fBindValues);
            dd[":f_state"] = sDb[":f_state"];
            dd[":f_id"] = sDb[":f_id"];
            err = dd.exec("update f_room set f_state=:f_state where f_id=:f_id");
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr8.rowCount()));
        }
        ui->chRoomstates->setChecked(true);
        //END F_RESERVATION_GUESTS
    }
    if (!processTable(sDb, "r_hall", ui->chHall)) {
        return;
    }
    if (!processTable(sDb, "r_table", ui->chTable)) {
        return;
    }
    if (!processTable(sDb, "users_groups", ui->chUsersGroups)) {
        return;
    }
    if (!processTable(sDb, "users", ui->chUsers)) {
        return;
    }
    {
        //ONLINE RESTAURANT
        ui->ptLog->appendPlainText("Online restaurant");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        DoubleDatabase dr5;
        dr5.open();
        ui->ptLog->appendPlainText("Clear current table states");
        qApp->processEvents();
        sDb.exec("update r_table set f_order=''");
        dr5[":f_state1"] = ORDER_STATE_OPENED;
        dr5[":f_state2"] = ORDER_STATE_CLOSED;
        dr5[":f_dateCash"] = WORKING_DATE;
        err = dr5.exec("select * from o_header where f_state=:f_state1 or (f_state=:f_state2 and f_dateCash=:f_dateCash and f_tax>0)");
        if (err) {
            goto ERR;
        }
        ui->ptLog->appendPlainText("Proceed o_header");
        ui->ptLog->appendPlainText("Go..");
        qApp->processEvents();
        for (int i = 0; i < dr5.rowCount(); i++) {
            dr5.getBindValues(i, sDb.fBindValues);
            dd[":f_id"] = sDb[":f_id"];
            ids << sDb[":f_id"].toString();
            err = dd.exec("delete from o_header where f_id=:f_id");
            if (err) {
                goto ERR;
            }
            err = sDb.insert("o_header", false);
            if (err) {
                goto ERR;
            }
            if (dr5.getValue(i, "f_state").toInt() == ORDER_STATE_OPENED) {
                sDb[":f_order"] = dr5.getValue(i, "f_id");
                sDb[":f_id"] = dr5.getValue(i, "f_table");
                err = sDb.exec("update r_table set f_order=:f_order where f_id=:f_id");
                if (err) {
                    goto ERR;
                }
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr5.rowCount()));
        }
        ui->ptLog->appendPlainText("Proceed o_dish");
        ui->ptLog->appendPlainText("Go..");
        qApp->processEvents();
        DoubleDatabase dr6;
        dr6.open();
        dr6[":f_state1"] = ORDER_STATE_OPENED;
        dr6[":f_state2"] = ORDER_STATE_CLOSED;
        dr6[":f_dateCash"] = WORKING_DATE;
        err = dr6.exec("select * from o_dish where f_header in (select f_id from o_header where f_state=:f_state1 or (f_state=:f_state2 and f_dateCash=:f_dateCash and f_tax>0))");
        if (err) {
            goto ERR;
        }
        for (int i = 0; i < dr6.rowCount(); i++) {
            dr6.getBindValues(i, sDb.fBindValues);
            dd[":f_id"] = sDb[":f_id"];
            ids << sDb[":f_id"].toString();
            err = dd.exec("delete from o_dish where f_id=:f_id");
            if (err) {
                goto ERR;
            }
            err = sDb.insert("o_dish", false);
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr6.rowCount()));
        }
        ui->ptLog->appendPlainText("Proceed m_register for closed orders");
        ui->ptLog->appendPlainText("Go..");
        int restCount = 0;
        for (int i = 0; i < dr5.rowCount(); i++) {
            if (dr5.getValue(i, "f_state").toInt() == ORDER_STATE_CLOSED) {
                restCount++;
                DoubleDatabase dt1;
                dt1.open();
                dt1[":f_id"] = dr5.getValue(i, "f_id");
                err = dt1.exec("select * from m_register where f_id=:f_id");
                if (dt1.rowCount() == 0) {
                    ui->ptLog->appendPlainText(QString("No vaucher for header %1").arg(dr5.getValue(i, "f_id").toString()));
                    ui->ptLog->appendPlainText("Continue...");
                    continue;
                }
                dt1.getBindValues(0, sDb.fBindValues);
                dd[":f_id"] = sDb[":f_id"];
                err = dd.exec("delete from m_register where f_id=:f_id");
                if (err) {
                    goto ERR;
                }
                err = sDb.insert("m_register", false);
                if (err) {
                    goto ERR;
                }
            }
            replacePtLastLine(QString("%1 of %2 entries, found %3").arg(i + 1).arg(dr5.rowCount()).arg(restCount));
        }
        ui->ptLog->appendPlainText("Proceed events");
        ui->ptLog->appendPlainText("Go..");
        qApp->processEvents();
        DoubleDatabase dr7;
        dr7.open();
        dr7[":f_wdate"] = WORKING_DATE;
        if(!dr7.exec("select * from o_event where f_state=0 or (f_state=1 and f_tax>0 and f_wdate=:f_wdate)")) {
            goto ERR;
        }
        for (int i = 0; i < dr7.rowCount(); i++) {
            dr7.getBindValues(i, sDb.fBindValues);
            dd[":f_id"] = sDb[":f_id"];
            ids << sDb[":f_id"].toString();
            err = sDb.exec("delete from o_event where f_id=:f_id");
            if (err) {
                goto ERR;
            }
            err = sDb.insert("o_event", false);
            if (err) {
                goto ERR;
            }
            DoubleDatabase dt;
            dt.open();
            dt[":f_id"] = dr7.getValue(i, "f_id");
            err = dt.exec("select * from m_register where f_id=:f_id");
            if (err) {
                goto ERR;
            }
            if (dt.rowCount() == 0) {
                ui->ptLog->appendPlainText(QString("No voucher for %1").arg(dr7.getValue(i, "f_id").toString()));
                ui->ptLog->appendPlainText("Continue..");
                continue;
            }
            dt.getBindValues(0, sDb.fBindValues);
            dd[":f_id"] = sDb[":f_id"];
            err = sDb.exec("delete from m_register where f_id=:f_id");
            if (err) {
                goto ERR;
            }
            err = sDb.insert("m_register", false);
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr5.rowCount()));
        }
        ui->chOnlineRestaurant->setChecked(true);
        //END ONLINE RESTAURANT
    }
    // MENU
    {
        DoubleDatabase dr9;
        dr9.open();
        ui->ptLog->appendPlainText("Menu names");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        err = sDb.exec("delete from r_menu_names");
        if (err) {
            goto ERR;
        }
        err = dr9.exec("select * from r_menu_names");
        if (err) {
            goto ERR;
        }
        for (int i = 0; i < dr9.rowCount(); i++) {
            dr9.getBindValues(i, sDb.fBindValues);
            err = sDb.insert("r_menu_names", false);
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr9.rowCount()));
        }
        ui->ptLog->appendPlainText("Dish part");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        err = sDb.exec("delete from r_dish_part");
        if (err) {
            goto ERR;
        }
        err = dr9.exec("select * from r_dish_part");
        if (err) {
            goto ERR;
        }
        for (int i = 0; i < dr9.rowCount(); i++) {
            dr9.getBindValues(i, sDb.fBindValues);
            err = sDb.insert("r_dish_part", false);
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr9.rowCount()));
        }
        ui->ptLog->appendPlainText("Dish types");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        err = sDb.exec("delete from r_dish_type");
        if (err) {
            goto ERR;
        }
        err = dr9.exec("select * from r_dish_type");
        if (err) {
            goto ERR;
        }
        for (int i = 0; i < dr9.rowCount(); i++) {
            dr9.getBindValues(i, sDb.fBindValues);
            err = sDb.insert("r_dish_type", false);
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr9.rowCount()));
        }
        ui->ptLog->appendPlainText("Dishes");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        err = sDb.exec("delete from r_dish");
        if (err) {
            goto ERR;
        }
        err = dr9.exec("select * from r_dish");
        if (err) {
            goto ERR;
        }
        for (int i = 0; i < dr9.rowCount(); i++) {
            dr9.getBindValues(i, sDb.fBindValues);
            err = sDb.insert("r_dish", false);
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr9.rowCount()));
        }
        ui->ptLog->appendPlainText("And menu");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        err = sDb.exec("delete from r_menu");
        if (err) {
            goto ERR;
        }
        err = dr9.exec("select * from r_menu");
        if (err) {
            goto ERR;
        }
        for (int i = 0; i < dr9.rowCount(); i++) {
            dr9.getBindValues(i, sDb.fBindValues);
            err = sDb.insert("r_menu", false);
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr9.rowCount()));
        }
        if (!processTable(sDb, "r_dish_complex", 0)) {
            return;
        }
        if (!processTable(sDb, "r_dish_complex_list", 0)) {
            return;
        }
        if (!processTable(sDb, "r_dish_mod", 0)) {
            return;
        }
        if (!processTable(sDb, "r_dish_mod_required", 0)) {
            return;
        }
        ui->chMenu->setChecked(true);
    }
    {
        DoubleDatabase dr10;
        dr10.open();
        ui->ptLog->appendPlainText("Proceed cardex");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        err = sDb.exec("delete from f_cardex");
        if (err) {
            goto ERR;
        }
        err = dr10.exec("select * from f_cardex");
        if (err) {
            goto ERR;
        }
        for (int i = 0; i < dr10.rowCount(); i++) {
            dr10.getBindValues(i, sDb.fBindValues);
            err = sDb.insert("f_cardex", false);
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr10.rowCount()));
        }
        err = dr10.exec("select * from f_cardex where length(f_extra1) > 0");
        if (err) {
            goto ERR;
        }
        ui->ptLog->appendPlainText("Proceed cardex extra names");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        for (int i = 0; i < dr10.rowCount(); i++) {
            dr10.getBindValues(i, sDb.fBindValues);
            dd[":f_name"] = sDb[":f_extra1"];
            dd[":f_addr1"] = sDb[":f_fextra2"];
            dd[":f_addr2"] = "";
            dd[":f_tel"] = "";
            dd[":f_fax"] = "";
            dd[":f_contact"] = "";
            dd[":f_contactPos"] = "";
            dd[":f_email"] = "";
            err = dd.update("f_cardex", where_id(sDb[":f_id"].toInt()));
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr10.rowCount()));
        }
        ui->chCardex->setChecked(true);
        ui->ptLog->appendPlainText("Proceed city ledger");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        err = sDb.exec("delete from f_city_ledger");
        if (err) {
            goto ERR;
        }
        err = dr10.exec("select * from f_city_ledger");
        if (err) {
            goto ERR;
        }
        for (int i = 0; i < dr10.rowCount(); i++) {
            dr10.getBindValues(i, sDb.fBindValues);
            err = sDb.insert("f_city_ledger", false);
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr10.rowCount()));
        }
        ui->ptLog->appendPlainText("Proceed city ledger extra names");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        dr10.exec("select * from f_city_ledger where length(f_extra1)>0");
        for (int i = 0; i < dr10.rowCount(); i++) {
            dr10.getBindValues(i, sDb.fBindValues);
            dd[":f_name"] = sDb[":f_extra1"];
            dd[":f_address"] = sDb[":f_extra2"];
            dd[":f_phone"] = "";
            dd[":f_email"] = "";
            err = sDb.update("f_city_ledger", where_id(sDb[":f_id"].toInt()));
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr10.rowCount()));
        }
        ui->chCL->setChecked(true);
        ui->ptLog->appendPlainText("Proceed cardex counters");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        err = dd.exec("delete from f_cardex_group");
        if (err) {
            goto ERR;
        }
        err = dr10.exec("select * from f_cardex_group");
        if (err) {
            goto ERR;
        }
        for (int i = 0; i < dr10.rowCount(); i++) {
            dr10.getBindValues(i, sDb.fBindValues);
            err = sDb.insert("f_cardex_group", false);
            if (err) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(dr10.rowCount()));
        }
        ui->chCardexCounter->setChecked(true);
    }
    if (!processTable(sDb, "f_nationality", ui->chNationality)) {
        return;
    }
    {
        ui->ptLog->appendPlainText("Proceed settings");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        DoubleDatabase drr;
        drr.open();
        drr.exec("select * from f_global_settings");
        if (!dd.exec("delete from f_global_settings")) {
            goto ERR;
        }
        for (int i = 0; i < drr.rowCount(); i++) {
            drr.getBindValues(i, sDb.fBindValues);
            if (sDb[":f_key"].toString() == "AHC" || sDb[":f_key"].toString() == "HC") {
                continue;
            }
            sDb.fBindValues.remove(":f_id");
            if (!sDb.insert("f_global_settings", false)) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(drr.rowCount()));
        }
        ui->chSettings->setChecked(true);
    }
    {
        ui->ptLog->appendPlainText("Proceed out of order and drafts");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        DoubleDatabase drr;
        drr.open();
        drr[":f_state1"] = RESERVE_OUTOFINVENTORY;
        drr[":f_state2"] = RESERVE_OUTOFROOM;
        drr[":f_state3"] = RESERVE_SERVICE;
        drr[":f_endDate"] = WORKING_DATE;
        if (!drr.exec("select * from f_reservation where (f_state=:f_state1 or f_state=:f_state2 or f_state=:f_state3) and f_endDate>=:f_endDate")) {
            goto ERR;
        }
        for (int i = 0; i < drr.rowCount(); i++) {
            drr.getBindValues(i, sDb.fBindValues);
            dd[":f_id"] = sDb[":f_id"];
            ids << sDb[":f_id"].toString();
            if (!dd.exec("delete from f_reservation where f_id=:f_id")) {
                goto ERR;
            }
            if (!sDb.insert("f_reservation", false)) {
                goto ERR;
            }
            replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(drr.rowCount()));
        }
        ui->chOutOfOrder->setChecked(true);
    }
    {
        ui->ptLog->appendPlainText("Proceed final");
        ui->ptLog->appendPlainText("Go...");
        qApp->processEvents();
        int scount = 1;
        foreach (QString s, ids) {
            fDD[":f_id"] = s;
            fDD.insert("id_back");
            replacePtLastLine(QString("%1 of %2 entries").arg(scount++).arg(ids.count()));
        }
        DoubleDatabase dair;
        dair.setDatabase(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass);
        dair.open();
        dair.exec("update f_id set f_id=f_id*-1, f_comp=null,f_date=null, f_time=null where f_id>0");
        ui->chFinal->setChecked(true);
    }
ERR:
    if (err) {
        sDb.rollback();
        ui->ptLog->appendPlainText(sDb.fLastError);
        ui->ptLog->appendPlainText("Cannot continue, check for errors");
        return;
    }
    sDb.commit();
    ui->ptLog->appendPlainText("Done.");
}

void DlgExport::replacePtLastLine(const QString &str)
{
    QTextBlock tb = ui->ptLog->document()->findBlockByLineNumber(ui->ptLog->document()->lineCount() - 1);
    if (tb.isValid()) {
        QTextCursor cursor(tb);
        cursor.select(QTextCursor::BlockUnderCursor);
        cursor.removeSelectedText();
    }
    ui->ptLog->appendPlainText(str);
    qApp->processEvents();
}

bool DlgExport::processTable(DoubleDatabase &db, const QString &table, QCheckBox *ch)
{
    DoubleDatabase fDD;
    ui->ptLog->appendPlainText(QString("Proceed %1").arg(table));
    ui->ptLog->appendPlainText("Go...");
    qApp->processEvents();
    bool err = db.exec(QString("delete from %1").arg(table));
    if (err) {
        goto ERR;
    }
    err = fDD.exec(QString("select * from %1").arg(table));
    if (err) {
        goto ERR;
    }
    for (int i = 0; i < fDD.rowCount(); i++) {
        fDD.getBindValues(i, db.fBindValues);
        err = db.insert(table, false);
        if (err) {
            goto ERR;
        }
        replacePtLastLine(QString("%1 of %2 entries").arg(i + 1).arg(fDD.rowCount()));
    }
    if (ch) {
        ch->setChecked(true);
    }
ERR:
    if (err) {
        db.rollback();
        ui->ptLog->appendPlainText(db.fLastError);
        ui->ptLog->appendPlainText("Cannot continue, check for errors");
        return false;
    }
    return true;
}
