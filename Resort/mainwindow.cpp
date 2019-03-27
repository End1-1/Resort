#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logging.h"
#include "dlghouseitem.h"
#include "preferences.h"
#include "login.h"
#include "fdebtholders.h"
#include "appconfig.h"
#include "loginsettings.h"
#include "databasesconnections.h"
#include "message.h"
#include "wmaindesk.h"
#include "wreportgrid.h"
#include "fcallrates.h"
#include "fcanceledreservations.h"
#include "recoupon.h"
#include "freportbypayment.h"
#include "fhotelhierarchy.h"
#include "guestcheckin.h"
#include "wreportroom.h"
#include "fdiscountreport.h"
#include "fexportreservation.h"
#include "recouponseria.h"
#include "wwelcome.h"
#include "fdiscounttotal.h"
#include "fhouseitems.h"
#include "fwakeupcall.h"
#include "favailablerooms.h"
#include "fbreakfast.h"
#include "fmonthlyoccperc.h"
#include "reroominventory.h"
#include "reroominventorystate.h"
#include "wroomchart.h"
#include "fsalesbycar.h"
#include "froomarrangement.h"
#include "fcash.h"
#include "fdailytransaction.h"
#include "dlgexecfailedsqls.h"
#include "ftstorereport.h"
#include "renationalityfile.h"
#include "fdishes.h"
#include "fstoreentry.h"
#include "dlgexport.h"
#include "froomstate.h"
#include "fcladvance.h"
#include "dlgcityadvance.h"
#include "dlgnotes.h"
#include "dlgexitbyversion.h"
#include "wwelcomerest.h"
#include "fpartnersdebt.h"
#include "fcouponsales.h"
#include "flengthofstay.h"
#include "wstoreentry.h"
#include "fdebtofcostumers.h"
#include "finhousedetailbalance.h"
#include "dlgnoshow.h"
#include "dlgrefundvaucher.h"
#include "about.h"
#include "fcitytrayledger.h"
#include "baseuid.h"
#include "remodelofcars.h"
#include "frestsalebystore.h"
#include "recashdesk.h"
#include "wweb.h"
#include "dlgcalculateoutputofrestaurant.h"
#include "wguests.h"
#include "fcouponstatistics.h"
#include "ecomboboxcompleter.h"
#include "fonlinebreakfast.h"
#include "recarclient.h"
#include "fnoshowcancelationfee.h"
#include "fnatbyperiod.h"
#include "wreservations.h"
#include "fstoredocs.h"
#include "dlgutils.h"
#include "freservebycreate.h"
#include "wnotes.h"
#include "reguesttitle.h"
#include "dlggroupreservationfuck.h"
#include "wcustomreports.h"
#include "wcontacts.h"
#include "wusers.h"
#include "fmaterialsinstore.h"
#include "recardexgroup.h"
#include "fstoremovement.h"
#include "wusersgroups.h"
#include "rebanquetcomment.h"
#include "freservegroups.h"
#include "freservaionremarks.h"
#include "whotelstatus.h"
#include "fyearlyfinancialreport.h"
#include "storedoc.h"
#include "wroomview.h"
#include "wremarks.h"
#include "dlgexportother.h"
#include "wreservation.h"
#include "flistsourcereserve.h"
#include "vauchers.h"
#include "wcardex.h"
#include "cachebasestruct.h"
#include "fonlinerest.h"
#include "reresthall.h"
#include "reresttable.h"
#include "dlgwelcomebuttonconfig.h"
#include "rerestmenunames.h"
#include "wreportssetold.h"
#include "rerestmenupart.h"
#include "rerestdishtype.h"
#include "rerestdish.h"
#include "recityledger.h"
#include "rerestdishmod.h"
#include "rereststore.h"
#include "rerestprinter.h"
#include "recreditcard.h"
#include "fcardexsales.h"
#include "fdailymovementcommon.h"
#include "ftrackchanges.h"
#include "restorepartner.h"
#include "cacherights.h"
#include "fcallhistory.h"
#include "fcityledgerbalance.h"
#include "dlgadvanceentry.h"
#include "dlguserpasswords.h"
#include "reroomcategory.h"
#include "wglobaldbconfig.h"
#include "rerestdishcomplex.h"
#include "reroombed.h"
#include "reroomcategoryrate.h"
#include "wsyncinvoices.h"
#include "finvoices.h"
#include "waccinvoice.h"
#include "frestauranttotal.h"
#include "freservationscommon.h"
#include "fcategorytosell.h"
#include "recurrency.h"
#include "fforecastoccupancycategory.h"
#include "faccmonthlyreport.h"
#include "dlgtaxprintsetup.h"
#include "reinvoiceitem.h"
#include "fcityledgerbalanceextended.h"
#include "fevents.h"
#include "fexpectedarrivalsimple.h"
#include "finhouseguest.h"
#include "fexpectedarrivals.h"
#include "dlgpostingcharges.h"
#include "dlgdiscount.h"
#include "wrecheckin.h"
#include "dlgtransferinvoiceamount.h"
#include "fcashreportsummary.h"
#include "dlgreceiptvaucher.h"
#include "fdailymovement.h"
#include "fcityledgerdetailedbalance.h"
#include "fcommonfilterbydate.h"
#include "fcashreport.h"
#include "fnousedadvance.h"
#include "fvauchers.h"
#include "recomplimentarycomment.h"
#include "wreportbuilder.h"
#include "fallguestindaterange.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QShortcut>
#include <QNetworkProxy>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    fCommand(0)
{
    ui->setupUi(this);

    QWidget *statusWidget = new QWidget();
    QHBoxLayout *hl = new QHBoxLayout();
    fStatusLabelLeft = new QLabel();
    fStatusLabelRight = new QLabel();
    QFont f(qApp->font());
    f.setBold(true);
    f.setPointSize(f.pointSize() + 1);
    fStatusLabelLeft->setFont(f);
    fStatusLabelRight->setFont(f);
    hl->addWidget(fStatusLabelLeft);
    hl->addSpacerItem(new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    hl->addWidget(fStatusLabelRight);
    hl->addSpacerItem(new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    fStateOfSecondDb = new QLabel();
    hl->addWidget(fStateOfSecondDb);
    statusWidget->setLayout(hl);
    ui->statusBar->addWidget(statusWidget);
    ui->actionChange_password->setVisible(false);
    connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(tabCloseRequested(int)));
    fMainWindow = this;
    fTab = ui->tabWidget;
    connect(&fTimer, SIGNAL(timeout()), this, SLOT(timeout()));
    logout();
    fSocket.setProxy(QNetworkProxy::NoProxy);
    fCommand.setSocket(&fSocket);
    connect(&fSocket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));
    connect(&fSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError(QAbstractSocket::SocketError)));
    connect(&fSocket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
    connect(&fCommand, SIGNAL(parseCommand(QString)), this, SLOT(parseSocketCommand(QString)));

    QShortcut *shortcut = new QShortcut(QKeySequence("F2"), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(shortcutSlot()));
    QShortcut *shortcut12 = new QShortcut(QKeySequence("F12"), this);
    connect(shortcut12, SIGNAL(activated()), this, SLOT(on_actionLogout_triggered()));
    QShortcut *shortcat11 = new QShortcut(QKeySequence("F11"), this);
    connect(shortcat11, SIGNAL(activated()), this, SLOT(shortcutFullScreen()));
    QShortcut *shortCat4 = new QShortcut(QKeySequence("F4"), this);
    connect(shortCat4, SIGNAL(activated()), this, SLOT(on_actionRoomChart_triggered()));
    QShortcut *shortSecondDb = new QShortcut(QKeySequence("F10"), this);
    connect(shortSecondDb, SIGNAL(activated()), this, SLOT(on_actionDisable_second_database_triggered()));

    ui->menuStorehouse->setVisible(false);
    ui->menuDiscount_system->setVisible(false);

    fTimeErrLableValue = false;
    connect(&fTimeErrLabel, SIGNAL(timeout()), this, SLOT(timeout2()));
    fTimeErrLabel.start(1000);
    connect(this, SIGNAL(updateCache(int,QString)), &fCacheOne, SLOT(updateCache(int,QString)));
    __mainWindow = this;

}

MainWindow::~MainWindow()
{
    disconnect(&fSocket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
    disconnect(&fSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError(QAbstractSocket::SocketError)));
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionLogin_triggered()
{
    login();
}

void MainWindow::on_actionLogout_triggered()
{
    logout();
}

void MainWindow::on_actionLock_triggered()
{
    lock();
}

void MainWindow::on_actionDatabases_triggered()
{
    if (fPreferences.getString(def_preferences_password).length() > 0) {
        LoginSettings ls(this);
        if (ls.exec() != QDialog::Accepted) {
            return;
        }
    }
    DatabasesConnections dc(this);
    dc.exec();
}

void MainWindow::login()
{
    Login l(this);
    if (l.exec() == QDialog::Rejected) {
        return;
    }
    logout();
    Db db = fPreferences.getDatabase(fDbName);
    fSocket.disconnectFromHost();
    fSocket.connectToHost(AppConfig::fServerAddress, 1250);
    if (fSocket.waitForConnected()) {
        QString data = QString("{\"db\" : {\"database\" : \"%1\", \"user\" : \"%2\", \"password\" : \"password\"}, "
                               "\"command\" : {\"command\": \"identify\"}}")
                .arg(db.dc_main_path)
                .arg(WORKING_USERNAME);
        int size = data.toUtf8().length();
        QByteArray dataToSend;
        dataToSend.append(reinterpret_cast<const char*>(&size), sizeof(size));
        dataToSend.append(data.toUtf8(), data.toUtf8().length());
        fSocket.write(dataToSend, dataToSend.length());
        fSocket.flush();
    } else {
        message_error(QString("Cannot connect to broadcast server, force logout")
                      + QString("<br>") + fSocket.errorString() +
                      "<br>Host: " + AppConfig::fServerAddress);
        logout();
        return;
    }
    fSocketDraft.disconnectFromHost();
    fSocketDraft.setProxy(QNetworkProxy::NoProxy);
    fSocketDraft.connectToHost(AppConfig::fServerAddress, 1250);
    if (fSocketDraft.waitForConnected()) {
        QString data = QString("{\"db\" : {\"database\" : \"%1\", \"user\" : \"%2\", \"password\" : \"password\"}, "
                               "\"command\" : {\"command\": \"draft\"}}")
                .arg(db.dc_main_path)
                .arg(WORKING_USERNAME);
        int size = data.toUtf8().length();
        QByteArray dataToSend;
        dataToSend.append(reinterpret_cast<const char*>(&size), sizeof(size));
        dataToSend.append(data.toUtf8(), data.toUtf8().length());
        fSocketDraft.write(dataToSend, dataToSend.length());
        fSocketDraft.flush();
    } else {
        message_error(QString("Cannot connect to broadcast server, force logout")
                      + QString("<br>") + fSocket.errorString()
                      + "<br>Host: " + AppConfig::fServerAddress);
        logout();
        return;
    }

    enableMainMenu(true);
    if (fPreferences.getDb(def_welcome_rest_mode).toInt() == 1) {
        wwelcomerest *ww = addTab<wwelcomerest>();
        Q_UNUSED(ww)
    } else {
        WWelcome *ww = addTab<WWelcome>();
        ww->setSlogan(fPreferences.getLocalString("Slogan"));
        showMaximized();
    }
    ui->tabWidget->tabBar()->tabButton(0, QTabBar::RightSide)->resize(0, 0);
    fTimer.start(60000);
    ui->actionChange_password->setVisible(true);
    if (fPreferences.getDb(def_receip_vaucher_id).toInt() == 0) {
        message_error(tr("Receipt voucher id not defined"));
        return;
    }
}

void MainWindow::addTabWidget(BaseWidget *widget)
{
    int index = ui->tabWidget->addTab(widget, "");
    widget->setTab(ui->tabWidget, index);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}

void MainWindow::refreshReservationList()
{
    bool refreshed = false;
    for (int i = 0, count = ui->tabWidget->count(); i < count; i++) {
        WMainDesk *d = dynamic_cast<WMainDesk*>(ui->tabWidget->widget(i));
        if (d) {
            if (!refreshed) {
                d->loadReservationList();
                refreshed = true;
            }
            d->filterRoom();
        }
    }
}

void MainWindow::setCurrentWidget(QWidget *w)
{
    ui->tabWidget->setCurrentWidget(w);
}

void MainWindow::configureLabels()
{
    QString str;
#ifdef QT_DEBUG
    str = "DEBUG";
#endif
    QString text = QString("[%1] %2, %3 %4")
            .arg(fDbName)
            .arg(tr("Welcome"))
            .arg(WORKING_USERNAME)
            .arg(str);
    QString textRight = QString("%1: %2; %3: %4; %5: %6")
            .arg(tr("Current date"))
            .arg(QDate::currentDate().toString(def_date_format))
            .arg(tr("Working date"))
            .arg(fPreferences.getLocalString(def_working_day))
            .arg(tr("Last charge date"))
            .arg(WORKING_DATE.addDays(-1).toString(def_date_format));
    fStatusLabelLeft->setText(text);
    fStatusLabelRight->setText(textRight);
}

void MainWindow::hideMenu()
{
    ui->menuBar->setVisible(false);
}

void MainWindow::tabCloseRequested(int index)
{
    BaseWidget *w = static_cast<BaseWidget*>(ui->tabWidget->widget(index));
    if (!w->canClose()) {
        return;
    }
    ui->tabWidget->removeTab(index);
    delete w;
}

void MainWindow::timeout()
{
    fTimer.stop();
    DoubleDatabase db;
    if (!db.open(true, false))
        return;
    QString query = "select r.f_id, r.f_state, s.f_" + def_lang + ", r.f_room, rm.f_short as f_room_short, "
            "r.f_group, ug.f_" + def_lang + ", r.f_dateStart, "
            "r.f_interval, r.f_text, r.f_guest, concat(g.f_firstName, ' ', g.f_lastName) as f_guestName, "
            "n.f_name as f_nationality, r.f_dateLastComplete, concat(u.f_firstName, ' ', u.f_lastName) "
            "from f_reminder r "
            "left join f_room rm on r.f_room=rm.f_id "
            "left join f_guests g on r.f_guest=g.f_id "
            "left join f_nationality n on g.f_nation=n.f_short "
            "left join f_reminder_state s on r.f_state=s.f_id "
            "left join users_groups ug on ug.f_id=r.f_group "
            "left join users u on u.f_id=r.f_author "
            "where r.f_state=1 and (r.f_group = 0 or r.f_group=:f_group) "
            "and (r.f_dateLastComplete is null or current_timestamp() > addtime(r.f_dateLastComplete, r.f_interval)) ";
    db[":f_group"] = WORKING_USERGROUP;
    db.exec(query);

    for (QList<QList<QVariant> >::iterator it = db.fDbRows.begin(); it != db.fDbRows.end(); it++) {
        QDateTime l = (*it)[13].toDateTime();
        bool go = false;
        if (l.isValid()) {
            go = true;
        } else {
            if (QDateTime::currentDateTime() > (*it)[7].toDateTime()) {
                go = true;
            }
        }
        if (go) {
            (*it).removeAt(13);
            DlgNotes *d = new DlgNotes(*it, this);
            d->setValues();
            d->setScheduleVisible();
            if (d->exec() == QDialog::Accepted) {

            }
            delete d;
        }
    }
    db[":f_app"] = _APPLICATION_;
    db.exec("select f_version from s_app where lower(f_app)=lower(:f_app)");
    if (db.nextRow()) {
        if (Utils::getVersionString(qApp->applicationFilePath()) != db.getString(0)) {
            DlgExitByVersion::exit(Utils::getVersionString(qApp->applicationFilePath()), db.getString(0));
        }
    }
    db.close();
    fTimer.start(60000);
}

void MainWindow::timeout2()
{
    fTimeErrLableValue = !fTimeErrLableValue;
    fStateOfSecondDb->setVisible(fTimeErrLableValue);
}

void MainWindow::socketReadyRead()
{
    QTcpSocket *s = static_cast<QTcpSocket*>(sender());
    fCommand.readBytes(s->readAll());
}

void MainWindow::parseSocketCommand(const QString &command)
{
    writelog("ManiWindow: start parsesocket command");
    QJsonDocument jDoc = QJsonDocument::fromJson(command.toUtf8());
    QJsonObject jObj = jDoc.object();
    QString cmd = jObj.value("command").toString();
    if (cmd == "refresh_reservations") {
        refreshReservationList();
    } else if (cmd == "update_cache") {
        int cacheId = jObj.value("cache").toInt();
        QString item = jObj.value("item").toString();
        emit updateCache(cacheId, item);
    } else if (cmd == "session") {
        AppConfig::fAppSession = jObj["session"].toString();
    } else {
        QVariantMap m = jObj.toVariantMap();
        for (int i = 0, count = ui->tabWidget->count(); i < count; i++) {
            BaseWidget *b = static_cast<BaseWidget*>(ui->tabWidget->widget(i));
            if (!b) {
                return;
            }
            b->handleBroadcast(m);
        }
    }
    writelog("ManiWindow: end parsesocket command");
}

void MainWindow::socketError(QAbstractSocket::SocketError f_cityLedger)
{
    Q_UNUSED(f_cityLedger)
    if (fTimer.isActive()) {
        DlgExitByVersion::exit(tr("Lost connection to broadcast server, force logout") + "<br>" + fSocket.errorString());
        logout();
    }
}

void MainWindow::socketDisconnected()
{
    if (fTimer.isActive()) {
        message_error(tr("Lost connection to broadcast server, force logout"));
        logout();
    }
}

void MainWindow::logout()
{
    fTimer.stop();
    disableMainMenu();
    while (ui->tabWidget->count() > 0) {
        tabCloseRequested(0);
    }
    CacheOne::clearAll();
    QString session = QString("{\"command\":{\"command\":\"logout\",\"session\":\"%1\"}}").arg(AppConfig::fAppSession);
    int s = session.length();
    QByteArray bs;
    bs.append(reinterpret_cast<const char*>(&s), sizeof(s));
    bs.append(session);
    fSocket.write(bs.data(), bs.length());
    fSocket.flush();
    fSocket.waitForBytesWritten();
    fSocket.close();
    ui->actionChange_password->setVisible(false);
    fStatusLabelLeft->setText(tr("Not connected"));
    fStatusLabelRight->clear();
    foreach (QAction *a, fCustomReports.keys()) {
        ui->menuBar->removeAction(a);
        delete a;
    }
    fCustomReports.clear();
}

void MainWindow::lock()
{
    Login l(this);
    l.setLockUser(WORKING_USERID);
    do {
    } while (l.exec() != QDialog::Accepted);
}

void MainWindow::enableMainMenu(bool value)
{
    if (!value) {
        return;
    }

    for (int i = 1; i < ui->menuBar->actions().count() - 1; i++) {
        ui->menuBar->actions()[i]->setEnabled(true);
    }

    QStringList dbParams = fPreferences.getDb("dd").toString().split(";", QString::SkipEmptyParts);
    ui->actionDisable_second_database->setVisible(r__(cr__do_no_write_second_db) && dbParams.count() == 4);

    ui->menuBar->actions().at(1)->setVisible(r__(cr__menu_reservation)); //Resevation
    ui->actionRoomChart->setVisible(r__(cr__room_chart));
    ui->actionNew_reservation->setVisible(r__(cr__edit_reservation));
    ui->actionNew_group_reservation->setVisible(r__(cr__reservation_group_reservation));
    ui->actionReservatios->setVisible(r__(cr__reservations));
    ui->actionReservation_groups->setVisible(r__(cr__reservation_group_reservation));
    ui->actionReservations_by_date_created->setVisible(r__(cr__reservations));
    ui->actionRe_checkin->setVisible(r__(cr__re_checkin));
    ui->actionChanges_of_states_of_room->setVisible(r__(cr__reservation_changes_state_room));
    ui->actionCanceled_reservations->setVisible(r__(cr__reservations));
    ui->actionCancelation_No_show_fees->setVisible(r__(cr__reservation_cancelation_no_show));
    ui->actionLenght_of_stay->setVisible(r__(cr__reserv_lenght_of_stay));
    ui->actionList_of_source_reservation->setVisible(r__(cr__reservatoin_list_of_source));
    ui->actionCategory_to_sell->setVisible(r__(cr__reservation_category_to_sell));
    ui->actionForecast_Occupancy_Category->setVisible(r__(cr__reservation_forecast_occupation));
    ui->actionAvaiable_rooms->setVisible(r__(cr__reservation_avaiable_room));
    ui->actionNew_room_chart->setVisible(false);
    ui->actionNew_room_chart->setVisible(r__(cr__room_chart));

    ui->menuBar->actions().at(2)->setVisible(r__(cr__reception)); // Reception
    ui->actionIn_house_guest->setVisible(r__(cr__inhouse_guest));
    ui->actionExpected_arrivals->setVisible(r__(cr__expected_arrivals_deparutures));
    ui->actionExpected_arrivals_simple->setVisible(r__(cr__expected_arrivals_pax));
    ui->actionRoom_assignment->setVisible(r__(cr__room_assignment));
    ui->actionRe_checkin->setVisible(r__(cr__re_checkin));
    ui->actionCall_history->setVisible(r__(cr__call_in) || r__(cr__call_out) || r__(cr__call_int) || r__(cr__call_tin) || r__(cr__call_tout));
    ui->actionNotes->setVisible(r__(cr__notes));
    ui->actionContacts->setVisible(r__(cr__contacts));
    ui->actionRemarks->setVisible(r__(cr__remarks));
    ui->actionHotel_status->setVisible(r__(cr__hotel_status));
    ui->actionRoom_inventory_2->setVisible(r__(cr__reception_room_inventory));
    ui->actionList_of_checkin_guests->setVisible(r__(cr__list_of_checking_guests));
    ui->actionWakeup_calls->setVisible(r__(cr__wakeupcall));
    ui->actionHotel_hierarchy->setVisible(r__(cr__hotel_hierarcgy));
    ui->actionDaily_transactions->setVisible(r__(cr__daily_transactions));

    ui->menuBar->actions().at(3)->setVisible(r__(cr__menu_cashier)); // Cashier
    ui->actionCurrencies->setVisible(r__(cr__currencies));
    ui->actionNew_advance_entry->setVisible(r__(cr__advance_vaucher));
    ui->actionPosting_charge->setVisible(r__(cr__postchage_vaucher));
    ui->actionReceipt_vaucher->setVisible(r__(cr__receipt_vaucher));
    ui->actionDiscount->setVisible(r__(cr__discount_vaucher));
    ui->actionTransfer_amount->setVisible(r__(cr__discount_vaucher));
    ui->actionCash_report_total->setVisible(r__(cr__report_cash));
    ui->actionCash_repoort_detailed->setVisible(r__(cr__report_cash));
    ui->actionAdvance_report->setVisible(r__(cr__cashier_advance_report));
    ui->actionCancelation_No_show_fee->setVisible(r__(cr__reservation_cancelation_no_show));
    ui->actionTransfer_CL_amount->setVisible(r__(cr__cashier_transfer_any_direction));
    ui->actionRefund_voucher->setVisible(r__(cr__cashier_refund));
#ifdef _HOTEL_
    ui->actionAccounts->setVisible(false);
#endif

    ui->menuBar->actions().at(4)->setVisible(r__(cr__menu_cityledger)); //Cityledger
    ui->actionCity_Ledger_detailed_balance->setVisible(r__(cr__cityledger_balance));
    ui->actionCity_ledger_balance_2->setVisible(r__(cr__cityledger_balance));
    ui->actionCity_Ledger_balance->setVisible(r__(cr__cityledger_balance));
    ui->actionAvailable_amounts->setVisible(r__(cr__cityledger_avaiable_amounts));


    ui->menuBar->actions().at(5)->setVisible(r__(cr__menu_bookkeeping)); //Bookkeeping
    ui->actionVauchers->setVisible(r__(cr__report_vauchers));
    ui->actionDaily_movement->setVisible(r__(cr__report_daily_movement));
    ui->actionMonthly_Report->setVisible(r__(cr__report_monthly));
    ui->actionDaily_financial_report->setVisible(r__(cr__report_daily_movement));
    ui->actionRestaurant->setVisible(r__(cr__report_restaurant));
    ui->actionInvoices->setVisible(r__(cr__report_checkout_invoices));
    ui->actionGuest_Tray_Ledger->setVisible(r__(cr__bookeeping_guest_tray_ledger));
    ui->actionIn_house_detailed_balance->setVisible(r__(cr__bookeeping_inhouse_detailed));
    ui->actionYearly_financial_report->setVisible(r__(cr__bookeeping_yearly_financial_report));
    ui->actionCheckout_invoices_free_rooming->setVisible(r__(cr__report_checkout_invoices));

    ui->menuBar->actions().at(6)->setVisible(r__(cr__menu_restaurant_reports)); //Restaurant
    ui->actionOpen_breakfast->setVisible(r__(cr__menu_restaurant_reports));
    ui->actionSales_by_storages->setVisible(r__(cr__menu_restaurant_reports));
    ui->actionBreakfast_report->setVisible(r__(cr__menu_restaurant_reports));

    ui->menuBar->actions().at(7)->setVisible(r__(cr__analytics_menu)); // Analytics
    ui->actionCardex_analysis->setVisible(r__(cr__cardex_analysis));
    ui->actionReports_set->setVisible(r__(cr__reports_set));
    ui->actionStatistics->setVisible(r__(cr__reports_set));
    ui->actionMonthly_occupancy_percentages->setVisible(r__(cr__analytics_menu));
    ui->actionNaitonality_report_by_period->setVisible(r__(cr__reports_set));
    ui->actionCall_history->setVisible(r__(cr__call_in) || r__(cr__call_int) || r__(cr__call_out) || r__(cr__call_tin) || r__(cr__call_tout));
    ui->actionMonthly_occupancy_percentages->setVisible(r__(cr__analytics_monthly_occupancy_perc));
    ui->actionGuest_by_nationality->setVisible(r__(cr__analytics_guest_by_nationality));
    ui->actionRoom_arrangement->setVisible(r__(cr__room_arrangement));

    if (fPreferences.getDb(def_external_rest_db).toString().isEmpty()) {
        ui->menuBar->actions().at(9)->setVisible(r__(cr__menu_restaurant)); //directory restaurant
    } else {
        ui->menuBar->actions().at(9)->setVisible(false);
    }

    ui->menuBar->actions().at(10)->setVisible(r__(cr__menu_direcotory)); //Directory hotel
    ui->actionContacts->setVisible(r__(cr__contacts));
    ui->actionPartners->setVisible(r__(cr__cardex_list));
    ui->actionPartners_group->setVisible(r__(cr__cardex_list));
    ui->actionCity_Ledger->setVisible(r__(cr__cityledger_list));
    ui->actionNationality_file->setVisible(r__(cr__guests));
    ui->actionGuest_file->setVisible(r__(cr__guests));
    ui->actionGuest_titles->setVisible(r__(cr__guests));
    ui->actionCredit_card->setVisible(r__(cr__credit_cards));
    ui->actionCategories->setVisible(r__(cr__room_editor));
    ui->actionRoom_view->setVisible(r__(cr__room_editor));
    ui->actionType_of_bed->setVisible(r__(cr__room_editor));
    ui->actionRoom_list->setVisible(r__(cr__room_editor));
    ui->actionInvoice_items->setVisible(r__(cr__invoice_items));
    ui->actionSetup_Tax_Printer->setVisible(r__(cr__setup_tax));
    ui->actionRoom_inventory->setVisible(r__(cr__directory_hotel_room_inventory));
    ui->actionRoom_inventory_states->setVisible(r__(cr__directory_hotel_room_inventory_state));
    ui->actionNationality_file->setVisible(r__(cr__nationality));
    ui->actionCall_rates->setVisible(r__(cr__call_rate));
#ifdef _HOTEL_
    ui->actionCostumers_cars->setVisible(false);
    ui->actionModels_of_cars->setVisible(false);
    ui->actionAccounts_2->setVisible(false);
#endif

    ui->menuBar->actions().at(11)->setVisible(r__(cr__menu_application)); //Application
    ui->actionUsers_groups->setVisible(r__(cr__users_groups));
    ui->actionUsers->setVisible(r__(cr__users));
    ui->actionTrack_changes->setVisible(r__(cr_trackin_changes));
    ui->actionGlobal_config->setVisible(r__(cr__global_config));
    ui->actionUpdate_program->setVisible(r__(cr__update_program));
    ui->actionReport_buillder->setVisible(WORKING_USERGROUP == 1);
    ui->actionExport_invoices->setVisible(r__(cr__bookkeeper_sync) && fPreferences.getDb("HC").toInt() > 0);
    ui->actionSynchronization->setVisible(fPreferences.getDb("HC").toBool() && r__(cr__export_event_etc));
    ui->actionExport_back->setVisible(fPreferences.getDb("HC").toBool() && r__(cr__export_active_reservations));
    ui->actionExport_active_reservations->setVisible(fPreferences.getDb("HC").toBool() && r__(cr__export_active_reservations));
    ui->actionExport_data->setVisible(fPreferences.getDb("HC").toBool() && r__(cr__bookkeeper_sync));
    ui->actionExport_reservations->setVisible(fPreferences.getDb("HC").toBool() && r__(cr__export_active_reservations));
    ui->actionUtils->setVisible(WORKING_USERGROUP == 1);
    ui->actionWeb->setVisible(false);
    ui->actionExecute_failed_sql->setVisible(r__(cr__exec_failed_sql_queries));

    ui->menuBar->actions().at(12)->setVisible(r__(cr__storehouse_all_items)); // Storehouse

    ui->menuBar->actions().at(13)->setVisible(false); // Discount system
#ifdef _HOTEL_
    ui->actionDebts->setVisible(false);
    ui->actionSales_report_by_cars->setVisible(false);
#endif

    DoubleDatabase fDD(true, doubleDatabase);
    fDD.exec("select f_id, f_name, f_groupAccess, f_menu from serv_reports where f_menu>0");
    while (fDD.nextRow()) {
        if (fDD.getString(2) != "*") {
            QStringList groups = fDD.getString(2).split(";", QString::SkipEmptyParts);
            if (!groups.contains(QString::number(WORKING_USERGROUP))) {
                continue;
            }
        }
        QAction *a = ui->menuBar->actions().at(fDD.getInt(3))->menu()->
                addAction(QIcon(":/images/report.png"), fDD.getString(1), this, SLOT(customReport()));
        fCustomReports[a] = fDD.getInt(0);
    }
    ui->menuBar->actions().at(8)->setVisible(ui->menuOther_Reports->actions().count() > 0);

#ifdef _RESORT_BUILD_
    ui->menuDiscount_system->setVisible(false);
    ui->menuStorehouse->setVisible(false);
#endif
}

void MainWindow::disableMainMenu()
{
    for (int i = 1; i < ui->menuBar->actions().count() - 1; i++) {
        ui->menuBar->actions()[i]->setEnabled(false);
        ui->menuBar->actions()[i]->setVisible(true);
    }
    ui->actionDisable_second_database->setVisible(false);
}

void MainWindow::on_actionRoom_list_triggered()
{
    addTab<WReportRoom>();
}

void MainWindow::on_actionAbout_triggered()
{
    About *a = new About(this);
    a->exec();
    delete a;
}

void MainWindow::on_actionGuest_file_triggered()
{
    addTab<WGuests>();
}

void MainWindow::on_actionDaily_movement_triggered()
{
    FDailyMovement::open();
}

void MainWindow::on_actionContacts_triggered()
{
    addTab<WContacts>();
}

void MainWindow::on_actionUsers_triggered()
{
    addTab<WUsers>();
}

void MainWindow::on_actionUsers_groups_triggered()
{
    addTab<WUsersGroups>();
}

void MainWindow::on_actionRoom_view_triggered()
{
    addTab<WRoomView>();
}

void MainWindow::on_actionInvoices_triggered()
{
    FInvoices::openReport(false);
}

void MainWindow::on_actionPartners_triggered()
{
    addTab<WCardex>();
}

void MainWindow::on_actionHakk_triggered()
{
    QList<int> widths;
    widths << 100
           << 200
           << 0
           << 150
           << 80
           << 80
           << 100
           << 80
           << 80
           << 30
           << 30
           << 30
           << 30
              ;
    QStringList fields;
    fields << "f_id"
           << "f_name"
           << "f_defaultMenu"
           << "f_menuName"
           << "f_defaultSvc"
           << "f_itemForInvoice"
           << "f_receiptPrinter"
           << "f_vatDept"
           << "f_noVatDept"
           << "f_showBanket"
           << "f_showHall"
           << "f_serviceItem"
           << "f_prefix"
              ;
    QStringList titles;
    titles << tr("Code")
             << tr("Name")
             << tr("Menu code")
             << tr("Menu")
             << tr("Service")
             << tr("Invoice id")
             << tr("Printer")
             << tr("VAT dept")
             << tr("No VAT dept")
             << tr("Banket")
             << tr("Hall")
             << tr("Service item")
             << tr("Order Prefix")
                ;
    QString title = tr("Hall");
    QString icon = ":/images/hall.png";
    QString query = "select h.f_id, h.f_name, h.f_defaultMenu, m.f_" + def_lang + ", h.f_defaultSvc, "
            "h.f_itemForInvoice, h.f_receiptPrinter, f_vatDept, f_noVatDept, f_showBanket, f_showHall, "
            "h.f_serviceItem, h.f_prefix "
            "from r_hall h "
            "inner join r_menu_names m on m.f_id=h.f_defaultMenu ";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RERestHall>(widths, fields, titles, title, icon, query);
}

void MainWindow::on_actionTables_triggered()
{
    QList<int> widths;
    widths << 100
           << 100
           << 0
           << 100
           << 100;
    QStringList fields;
    fields << "f_id"
           << "f_name"
           << "f_hall"
           << "f_hallName"
           << "f_queue";
    QStringList titles;
    titles << tr("Code")
           << tr("Name")
           << tr("Hall code")
           << tr("Hall")
           << tr("Queue");
    QString title = tr("Tables");
    QString icon = ":/images/table.png";
    QString query = "select t.f_id, t.f_name, t.f_hall, h.f_name, t.f_queue "
            "from r_table t "
            "inner join r_hall h on h.f_id = t.f_hall "
            "order by f_hall, f_queue ";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RERestTable>(widths, fields, titles, title, icon, query);
}

void MainWindow::on_actionNames_of_menu_triggered()
{
    QList<int> widths;
    widths << 100
           << 230
           << 230
           << 230;
    QStringList fields;
    fields << "f_id"
           << "f_am"
           << "f_en"
           << "f_ru";
    QStringList titles;
    titles << tr("Code")
           << tr("Name, am")
           << tr("Name, en")
           << tr("Name, ru");
    QString title = tr("Names of menu");
    QString icon = ":/images/cutlery.png";
    QString query = "select f_id, f_am, f_en, f_ru from r_menu_names ";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RERestMenuNames>(widths, fields, titles, title, icon, query);
}

void MainWindow::on_actionMain_partitions_of_menu_triggered()
{
    QList<int> widths;
    widths << 100
           << 230
           << 230
           << 230;
    QStringList fields;
    fields << "f_id"
           << "f_am"
           << "f_en"
           << "f_ru";
    QStringList titles;
    titles << tr("Code")
           << tr("Name, am")
           << tr("Name, en")
           << tr("Name, ru");
    QString title = tr("Main partitions of menu");
    QString icon = ":/images/cutlery.png";
    QString query = "select f_id, f_am, f_en, f_ru from r_dish_part";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RERestMenuPart>(widths, fields, titles, title, icon, query);
}

void MainWindow::on_actionType_of_dishes_triggered()
{
    QList<int> widths;
    widths << 100
           << 0
           << 120
           << 120
           << 120
           << 120
           << 0
           << 0
           << 80
           << 0;
    QStringList fields;
    fields << "f_id"
           << "f_part"
           << "f_part_name"
           << "f_am"
           << "f_en"
           << "f_ru"
           << "f_bgColor"
           << "f_textColor"
           << "f_queue"
           << "f_active";
    QStringList titles;
    titles << tr("Code")
           << tr("Part code")
           << tr("Part")
           << tr("Name, am")
           << tr("Name, en")
           << tr("Name, ru")
           << tr("Backgroun color")
           << tr("Text color")
           << tr("Queue")
           << tr("Active");
    QString title = tr("Type of dish");
    QString icon = ":/images/cutlery.png";
    QString query = "select t.f_id, t.f_part, p.f_" + def_lang + ", t.f_am, t.f_en, t.f_ru, "
            "f_bgColor, f_textColor, t.f_queue, f_active "
            "from r_dish_type t "
            "inner join r_dish_part p on p.f_id=t.f_part "
            "order by p.f_" + def_lang + ", t.f_" + def_lang;
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RERestDishType>(widths, fields, titles, title, icon, query);
}

void MainWindow::on_actionDishes_triggered()
{
    FDishes::openFilterReport<FDishes, WReportGrid>();
}

void MainWindow::on_actionModifiers_triggered()
{
    QList<int> widths;
    widths << 80
           << 250
           << 250
           << 250;
    QStringList fields;
    fields << "f_id"
           << "f_am"
           << "f_en"
           << "f_ru";
    QStringList titles;
    titles << tr("Code")
           << tr("Name, am")
           << tr("Name, en")
           << tr("Name, ru");
    QString title = tr("Dish modifiers");
    QString icon = ":/images/cutlery.png";
    QString query = "select f_id, f_am, f_en, f_ru from r_dish_mod order by f_" + def_lang;
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RERestDishMod>(widths, fields, titles, title, icon, query);
}

void MainWindow::on_actionStorages_triggered()
{
    QList<int> widths;
    widths << 100
           << 300;
    QStringList fields;
    fields << "f_id"
           << "f_name";
    QStringList titles;
    titles << tr("Code")
           << tr("Name");
    QString title = tr("Storages");
    QString icon = ":/images/cutlery.png";
    QString query = "select f_id, f_name from r_store";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RERestStore>(widths, fields, titles, title, icon, query);
}

void MainWindow::on_actionMenu_review_triggered()
{
    QList<int> widths;
    widths << 0
           << 0
           << 100
           << 0
           << 100
           << 0
           << 100
           << 250
           << 80
           << 0
           << 100
           << 100
           << 100
           << 80
              ;
    QStringList fields;
    fields << "f_id"
           << "f_menu_id"
           << "f_menu_name"
           << "f_part_id"
           << "f_part_name"
           << "f_type_id"
           << "f_type_name"
           << "f_dish_name"
           << "f_price"
           << "f_store_id"
           << "f_store_name"
           << "f_print1"
           << "f_print2"
           << "f_as"
              ;
    QStringList titles;
    titles << tr("Code")
           << tr("Menu code")
           << tr("Menu")
           << tr("Part code")
           << tr("Part")
           << tr("Type code")
           << tr("Type")
           << tr("Dish")
           << tr("Price")
           << tr("Store code")
           << tr("Store")
           << tr("Printer 1")
           << tr("Printer 2")
           << tr("ArmSoft")
              ;
    QString query = "select  d.f_id, m.f_id, mn.f_" + def_lang + ", t.f_part, p.f_" + def_lang + ", "
            "d.f_type, t.f_" + def_lang + ", d.f_" + def_lang + ", m.f_price, "
            "m.f_store, s.f_name, m.f_print1, m.f_print2, d.f_as "
            "from r_menu m "
            "inner join r_menu_names mn on mn.f_id=m.f_menu "
            "inner join r_store s on s.f_id=m.f_store "
            "inner join r_dish d on d.f_id=m.f_dish "
            "inner join r_dish_type t on t.f_id=d.f_type "
            "inner join r_dish_part p on p.f_id=t.f_part "
            "where m.f_state=1 "
            "order by 2, 4, 6, 7";
    QString title = tr("Review of menu");
    QString icon = ":/images/cutlery.png";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RERestDish>(widths, fields, titles, title, icon, query, false);
}

void MainWindow::on_actionPrinters_triggered()
{
    QList<int> widths;
    widths << 100
           << 300;
    QStringList fields;
    fields << "f_id"
           << "f_name";
    QStringList titles;
    titles << tr("Code")
           << tr("Name");
    QString title = tr("Printers");
    QString icon = ":/images/cutlery.png";
    QString query = "select f_id, f_name from r_printers";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RERestPrinter>(widths, fields, titles, title, icon, query);
}

void MainWindow::on_actionTrack_changes_triggered()
{
    QList<int> widths;
    widths << 0
           << 150
           << 80
           << 80
           << 80
           << 100
           << 120
           << 80
           << 150
           << 100
           << 200
           << 200;
    QStringList fields;
    fields << "c.f_type"
           << "t.f_name"
           << "c.f_rec"
           << "c.f_invoice"
           << "c.f_reservation"
           << "c.f_comp"
           << "c.f_date"
           << "c.f_time"
           << "c.f_user"
           << "c.f_action"
           << "c.f_value1"
           << "c.f_value2";
    QStringList titles;
    titles << tr("Table code")
           << tr("Table")
           << tr("Rec")
           << tr("Invoice")
           << tr("Reservation")
           << tr("Host")
           << tr("Date")
           << tr("Time")
           << tr("User")
           << tr("Field")
           << tr("Old")
           << tr("New");
    QMap<QString, bool> includes;
    includes["c.f_table"] = true;
    includes["t.f_name"] = true;
    includes["c.f_rec"] = true;
    includes["c.f_invoice"] = true;
    includes["c.f_reservation"] = true;
    includes["c.f_comp"] = true;
    includes["c.f_date"] = true;
    includes["c.f_time"] = true;
    includes["c.f_user"] = true;
    includes["c.f_action"] = true;
    includes["c.f_value1"] = true;
    includes["c.f_value2"] = true;
    QStringList tables;
    tables << "airlog.log c"
           << "airlog.logt t";
    QStringList joins;
    joins << "from"
          << "inner";
    QStringList joinConds;
    joinConds << ""
              << "t.f_id=c.f_type";
    QString title = tr("Tracking");
    QString icon = ":/images/tracking.png";
    WReportGrid *rg = addTab<WReportGrid>();
    rg->setQueryModel<FTrackChanges>(widths, fields, titles, includes, tables, joins, joinConds, title, icon);
}

void MainWindow::on_actionRoomChart_triggered()
{
    if (!ui->menuReception->isEnabled()) {
        return;
    }
    addTab<WMainDesk>();
}

void MainWindow::on_actionNew_reservation_triggered()
{
    QList<CacheRoom*> rooms;
    rooms.append(0);
    WReservation *w = addTab<WReservation>();
    w->setInitialParams(WORKING_DATE, WORKING_DATE, rooms);
}

void MainWindow::on_actionCredit_card_triggered()
{
    QList<int> widths;
    widths << 100
           << 300;
    QStringList fields;
    fields << "f_id"
           << "f_name";
    QStringList titles;
    titles << tr("Code")
           << tr("Name");
    QString title = tr("Credit cards");
    QString icon = ":/images/credit-card.png";
    QString query = "select f_id, f_name from f_credit_card";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RECreditCard>(widths, fields, titles, title, icon, query);
}

void MainWindow::on_actionCity_Ledger_balance_triggered()
{
    FCityLedgerBalance::open();
}

void MainWindow::on_actionChange_password_triggered()
{
    DlgUserPasswords *d = new DlgUserPasswords(this);
    d->setSelfMode();
    d->exec();
    delete d;
}

void MainWindow::on_actionNew_advance_entry_triggered()
{
    DlgAdvanceEntry::advance();
}

void MainWindow::on_actionGlobal_config_triggered()
{
    addTab<WGlobalDbConfig>();
}

void MainWindow::on_actionComplex_dish_triggered()
{
    QList<int> widths;
    widths << 80
           << (def_lang == "am" ? 300 : 0)
           << (def_lang == "en" ? 300 : 0)
           << (def_lang == "ru" ? 300 : 0)
           << 80
           << 80
           << 80
           << 80
           << 80
           << 30
              ;
    QStringList fields;
    fields << "f_id"
           << "f_am"
           << "f_en"
           << "f_ru"
           << "f_startTime"
           << "f_endTime"
           << "f_price"
           << "f_priceDeviation"
           << "f_adgt"
           << "f_enabled"
              ;
    QStringList titles;
    titles << tr("Code")
           << tr("Name, am")
           << tr("Name, en")
           << tr("Name, ru")
           << tr("Start time")
           << tr("End time")
           << tr("Price")
           << tr("Price deviation")
           << tr("ADGT")
           << tr("Active")
              ;
    QString title = tr("Complex dish");
    QString icon = ":/images/dinner.png";
    QString query = "select f_id, f_am, f_en, f_ru, f_startTime, f_endTime, f_price, "
            "f_priceDeviation, f_adgt, f_enabled from r_dish_complex";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RERestDishComplex>(widths, fields, titles, title, icon, query);
}

void MainWindow::on_actionCategories_triggered()
{
    QList<int> widths;
    widths << 80
           << 200
           << 300;
    QStringList fields;
    fields << "f_id"
           << "f_short"
           << "f_description";
    QStringList titles;
    titles << tr("Code")
           << tr("Short")
           << tr("Description");
    QString title = tr("Room categories");
    QString icon = ":/images/category.png";
    QString query = "select f_id, f_short, f_description from f_room_classes";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RERoomCategory>(widths, fields, titles, title, icon, query);
    RERoomCategoryRate *cr = new RERoomCategoryRate(r);
    Q_UNUSED(cr)
}

void MainWindow::on_actionType_of_bed_triggered()
{
    QList<int> widths;
    widths << 80
           << 200;
    QStringList fields;
    fields << "f_id"
           << "f_name";
    QStringList titles;
    titles << tr("Code")
           << tr("Name");
    QString title = actionTitle(sender());
    QString icon = ":/images/bed.png";
    QString query = "select f_id, f_name from f_room_bed";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RERoomBed>(widths, fields, titles, title, icon, query);
}

QString MainWindow::actionTitle(QObject *a)
{
    return static_cast<QAction*>(a)->text();
}

void MainWindow::on_actionSynchronization_triggered()
{

}

void MainWindow::on_actionRestaurant_triggered()
{
    FRestaurantTotal::open();
}

void MainWindow::on_actionReservatios_triggered()
{
    QList<int> widths;
    widths << 80 //f_id 1
           << 0 //f_author 2
           << 80 //username 3
           << 0 //state_id 4
           << 100 //state name 5
           << 80 // room 6
           << 100 // start date 7
           << 100 // end date 8
           << 0 // arrangement 9
           << 50 // arrangement name 10
           << 200 // guest 11
           << 50 // pax 12
           << 100 // nights 13
           << 100 // price per night 14
           << 100 // cardex code 15
           << 200 // cardex name 16
           << 200 // booking
           << 80 // grand total 17
              ;
    QStringList fields;
    fields << "r.f_id"
           << "r.f_author"
           << "u.f_username"
           << "r.f_state"
           << "rs.f_" + def_lang
           << "r.f_room"
           << "r.f_startDate"
           << "r.f_endDate"
           << "r.f_arrangement"
           << "ra.f_" + def_lang
           << "concat(g.f_title,' ',g.f_firstName,' ',g.f_lastName)"
           << "r.f_man+r.f_woman+r.f_child"
           << "datediff(r.f_endDate, r.f_startDate)"
           << "r.f_pricePerNight"
           << "r.f_cardex"
           << "cx.f_name"
           << "r.f_booking"
           << "r.f_grandTotal";
    QStringList titles;
    titles << tr("Code")
           << tr("Author code")
           << tr("Author")
           << tr("State code")
           << tr("State")
           << tr("Room")
           << tr("Entry")
           << tr("Departure")
           << tr("Arrangement code")
           << tr("Arrangement")
           << tr("Guest")
           << tr("Pax")
           << tr("Nights")
           << tr("Rate")
           << tr("Cardex code")
           << tr("Cardex mame")
           << tr("Booking")
           << tr("Grand total");
    QMap<QString, bool> includes;
    includes["r.f_id"] = true;
    includes["r.f_author"] = true;
    includes["u.f_username"] = true;
    includes["r.f_state"] = true;
    includes["rs.f_" + def_lang] = true;
    includes["r.f_room"] = true;
    includes["r.f_startDate"] = true;
    includes["r.f_endDate"] = true;
    includes["r.f_arrangement"] = true;
    includes["ra.f_" + def_lang] = true;
    includes["concat(g.f_title,' ',g.f_firstName,' ',g.f_lastName)"] = true;
    includes["r.f_man+r.f_woman+r.f_child"] = true;
    includes["datediff(r.f_endDate, r.f_startDate)"] = true;
    includes["r.f_pricePerNight"] = true;
    includes["r.f_cardex"] = true;
    includes["cx.f_name"] = true;
    includes["r.f_booking"] = true;
    includes["r.f_grandTotal"] = true;
    QStringList tables;
    tables << "f_reservation r"
           << "users u"
          << "f_reservation_state rs"
          << "f_room_arrangement ra"
          << "f_guests g"
          << "f_cardex cx";
    QStringList joins;
    joins << ""
          << "inner"
          << "inner"
          << "left"
          << "left"
          << "left";
    QStringList joinConds;
    joinConds << ""
              << "u.f_id=r.f_author"
              << "rs.f_id=r.f_state"
              << "ra.f_id=r.f_arrangement"
              << "g.f_id=r.f_guest"
              << "cx.f_cardex=r.f_cardex";
    QString title = tr("Reservations");
    QString icon = ":/images/bed.png";
    WReportGrid *rg = addTab<WReportGrid>();
    rg->setQueryModel<FReservationsCommon>(widths, fields, titles, includes, tables, joins, joinConds, title, icon);
    WReservation *wr = new WReservation(rg);
    connect(rg, SIGNAL(doubleClickOnRow(QList<QVariant>)), wr, SLOT(loadFromData(QList<QVariant>)));
}

void MainWindow::on_actionCategory_to_sell_triggered()
{
    WReportGrid *wr = addTab<WReportGrid>();
    wr->setQueryModel<FCategoryToSell>();
}

void MainWindow::on_actionCity_Ledger_triggered()
{
    QList<int> widths;
    widths << 80
           << 300
           << 300
           << 200
           << 200
           << 100
           << 100
              ;
    QStringList fields;
    fields << "f_id"
           << "f_name"
           << "f_address"
           << "f_phone"
           << "f_email"
           << "f_extra1"
           << "f_extra2"
              ;
    QStringList titles;
    titles << tr("Code")
           << tr("Name")
           << tr("Address")
           << tr("Phone")
           << tr("Email")
           << tr("Extra1")
           << tr("Extra2")
              ;
    QString title = actionTitle(sender());
    QString icon = ":/images/currency.png";
    QString query = "select f_id, f_name, f_address, f_phone, f_email, f_extra1, f_extra2 from f_city_ledger";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RECityLedger>(widths, fields, titles, title, icon, query);
}

void MainWindow::on_actionCurrencies_triggered()
{
    QList<int> widths;
    widths << 80
           << 100
           << 300
           << 80;
    QStringList fields;
    fields << "f_id"
           << "f_short"
           << "f_name"
           << "f_rate";
    QStringList titles;
    titles << tr("Code")
           << tr("Short")
           << tr("Name")
           << tr("Rate");
    QString title = actionTitle(sender());
    QString icon = ":/images/currency.png";
    QString query = "select f_id, f_short, f_name, f_rate from f_acc_currencies";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RECurrency>(widths, fields, titles, title, icon, query);
}

void MainWindow::on_actionForecast_Occupancy_Category_triggered()
{
    WReportGrid *wr = addTab<WReportGrid>();
    wr->setQueryModel<FForecastOccupancyCategory>();
}

void MainWindow::on_actionMonthly_Report_triggered()
{
    WReportGrid *wr = addTab<WReportGrid>();
    wr->setQueryModel<FAccMonthlyReport>();
}

void MainWindow::on_actionSetup_Tax_Printer_triggered()
{
    DlgTaxPrintSetup *d = new DlgTaxPrintSetup(this);
    d->exec();
    delete d;
}

void MainWindow::on_actionInvoice_items_triggered()
{
    QList<int> widths;
    widths << 80
           << 0
           << 0
           << 150
           << 200
           << 200
           << 200
           << 80
           << 200
           << 80
           << 80
           << 80
           << 30
           << 30
           << 0
              ;
    QStringList fields;
    fields << "i.f_id"
           << "i.f_vaucher"
           << "i.f_group"
           << "g.f_" + def_lang
           << "i.f_am"
           << "i.f_en"
           << "i.f_ru"
           << "i.f_price"
           << "i.f_taxName"
           << "i.f_adgt"
           << "i.f_vatDept"
           << "i.f_noVatDept"
           << "i.f_auto"
           << "i.f_rest"
           << "i.f_vatReception"
              ;
    QStringList titles;
    titles << tr("Code")
           << tr("Voucher")
           << tr("Group code")
           << tr("Group")
           << tr("Name, am")
           << tr("Name, en")
           << tr("Name, ru")
           << tr("Price")
           << tr("Tax name")
           << tr("ADGT")
           << tr("VAT Dept")
           << tr("No VAT Dept")
           << tr("Manual charge")
           << tr("Restaurant")
           << tr("Vat Reception")
              ;
    QString title = tr("Invoice items");
    QString icon = ":/images/list.png";
    QString query = "select i.f_id, i.f_vaucher, i.f_group, g.f_" +def_lang + ", i.f_am, i.f_en, i.f_ru, i.f_price, "
            "i.f_taxName, i.f_adgt, i.f_vatDept, i.f_noVatDept, i.f_auto, i.f_rest, i.f_vatReception "
            "from f_invoice_item i "
            "inner join f_invoice_item_group g on g.f_id=i.f_group ";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<REInvoiceItem>(widths, fields, titles, title, icon, query);
}

void MainWindow::on_actionIn_house_guest_triggered()
{
    QList<int> widths;
    widths << 0 //date
           << 70 //room
           << 100 // cat
           << 60 //adul
           << 60 //child
           << 60 //acc
           << 100 //entry
           << 100 //dep
           << 120 // nat
           << 80 // rooming
           << 60 // extra bed
           << 60 // meal
           << 30 // vat
           << 250 //gues
           << 300 // cardex
           << 250 // operator
              ;
    QStringList fields;
    fields << "current_date"
           << "r.f_room"
           << "c.f_short"
           << "r.f_man+r.f_woman"
           << "r.f_child"
           << "ar.f_" + def_lang
           << "r.f_startDate"
           << "r.f_endDate"
           << "n.f_name"
           << "r.f_pricePerNight"
           << "r.f_extraBedFee"
           << "r.f_mealPrice"
           << "v.f_vat"
           << "concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName)"
           << "cx.f_name"
           << "concat(u.f_firstName, ' ', u.f_lastName)"
              ;
    QStringList titles;
    titles << tr("Date")
           << tr("Room")
           << tr("Cat")
           << tr("Adults")
           << tr("Childs")
           << tr("Acc.")
           << tr("Arrival date")
           << tr("Departure date")
           << tr("Nationality")
           << tr("Room rate")
           << tr("Extra bed")
           << tr("Meal plan")
           << tr("VAT")
           << tr("Guest")
           << tr("Cardex")
           << tr("Operator")
              ;
    QMap<QString, bool> includes;
    includes["current_date"] = true;
    includes["r.f_room"] = true;
    includes["c.f_short"] = true;
    includes["r.f_man+r.f_woman"] = true;
    includes["r.f_child"] = true;
    includes["ar.f_" + def_lang] = true;
    includes["r.f_startDate"] = true;
    includes["r.f_endDate"] = true;
    includes["n.f_name"] = true;
    includes["r.f_pricePerNight"] = false;
    includes["r.f_extraBedFee"] = false;
    includes["r.f_mealPrice"] = false;
    includes["v.f_vat"] = false;
    includes["concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName)"] = false;
    includes["cx.f_name"] = false;
    includes["concat(u.f_firstName, ' ', u.f_lastName)"] = true;
    QStringList tables;
    tables << "f_reservation r"
           << "f_guests"
           << "f_room rm"
           << "f_room_classes c"
          << "f_room_arrangement ar"
          << "f_guests g"
          << "f_nationality n"
          << "f_vat_mode v"
          << "f_cardex cx"
          << "users u"
             ;
    QStringList joins;
    joins << ""
          << "inner"
          << "inner"
          << "inner"
          << "inner"
          << "inner"
          << "left"
          << "left"
          << "left"
          << "left";
    QStringList joinConds;
    joinConds << ""
              << "g.f_id=r.f_guest"
              << "rm.f_id=r.f_room"
              << "c.f_id=rm.f_class"
              << "ar.f_id=r.f_arrangement"
              << "g.f_id=r.f_guest"
              << "n.f_short=g.f_nation"
              << "v.f_id=r.f_vatMode"
              << "cx.f_cardex=r.f_cardex"
              << "u.f_id=r.f_checkInUser";
    QString title = tr("In house guests");
    QString icon = ":/images/bed.png";
    WReportGrid *rg = addTab<WReportGrid>();
    rg->setQueryModel<FInHouseGuest>(widths, fields, titles, includes, tables, joins, joinConds, title, icon);
}

void MainWindow::on_actionExpected_arrivals_triggered()
{
    WReportGrid *wr = addTab<WReportGrid>();
    wr->setQueryModel<FExpectedArrivals>();
}

void MainWindow::on_actionPosting_charge_triggered()
{
    DlgPostingCharges *p = new DlgPostingCharges(this);
    p->exec();
    delete p;
}

void MainWindow::on_actionDiscount_triggered()
{
    DlgDiscount *d = new DlgDiscount(this);
    d->exec();
    delete d;
}

void MainWindow::on_actionRe_checkin_triggered()
{
    addTab<WReCheckIn>();
}

void MainWindow::on_actionTransfer_amount_triggered()
{

    DlgTransferInvoiceAmount *d = new DlgTransferInvoiceAmount(this);
    d->exec();
    delete d;
}

void MainWindow::on_actionExpected_arrivals_simple_triggered()
{
    WReportGrid *rg = addTab<WReportGrid>();
    rg->setQueryModel<FExpectedArrivalSimple>();
}

void MainWindow::on_actionCash_report_total_triggered()
{
    addTab<WReportGrid>()->setQueryModel<FCashReportSummary>();
}

void MainWindow::on_actionReceipt_vaucher_triggered()
{
    DlgReceiptVaucher *d = new DlgReceiptVaucher(this);
    d->exec();
    delete d;
}

void MainWindow::on_actionCity_Ledger_detailed_balance_triggered()
{
    FCityLedgerDetailedBalance::open();
}

void MainWindow::on_actionCash_repoort_detailed_triggered()
{
    FCashReport::open();
}

void MainWindow::on_actionVauchers_triggered()
{
    FVauchers::open();
}

void MainWindow::on_actionNotes_triggered()
{
    addTab<WNotes>();
}

void MainWindow::on_actionEvent_triggered()
{
    FEvents::open();
}

void MainWindow::on_actionDaily_financial_report_triggered()
{
    FDailyMovementCommon::open();
}

void MainWindow::on_actionBanquet_comment_triggered()
{
    REBanquetComment::openBanquet();
}

void MainWindow::on_actionCity_ledger_balance_2_triggered()
{
    FCityLedgerBalanceExtended::open();
}

void MainWindow::on_actionHistory_of_calls_triggered()
{
    FCallHistory::open();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    bool canClose = true;
    for (int i = 1; i < ui->tabWidget->count(); i++) {
        BaseWidget *w = static_cast<BaseWidget*>(ui->tabWidget->widget(i));
        if (!w->canClose()) {
            canClose = false;
            break;
        }
    }
    if (canClose) {
        if (message_confirm(tr("Confirm to close application")) != QDialog::Accepted) {
            canClose = false;
        }
    }
    if (!canClose) {
        event->ignore();
        return;
    }
    logout();
    QMainWindow::closeEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    /*
    if (event->pos().y() < 30) {
        if (isFullScreen()) {
            ui->menuBar->show();
        }
    } else if (isFullScreen()) {
        ui->menuBar->hide();
    }
    */
    QMainWindow::mouseMoveEvent(event);
}

void MainWindow::secondDbError()
{
    QPixmap p(":/images/ball-red.png");
    fStateOfSecondDb->setPixmap(p.scaled(20, 20, Qt::KeepAspectRatio));
    fStateOfSecondDb->setMaximumSize(20, 20);
}

void MainWindow::shortcutFullScreen()
{
    if (isFullScreen()) {
        showMaximized();
        ui->menuBar->show();
    } else {
        showFullScreen();
        ui->menuBar->hide();
    }
}

void MainWindow::shortcutSlot()
{
    if (ui->tabWidget->count() > 0) {
        ui->tabWidget->setCurrentIndex(0);
    }
}

void MainWindow::customReport()
{
    QAction *a = static_cast<QAction*>(sender());
    if (!fCustomReports.contains(a)) {
        message_error(tr("Application error. Contact with developer. Message custom action == 0"));
        return;
    }
    int reportId = fCustomReports[a];
    FCommonFilterByDate::open(reportId);
}

void MainWindow::on_actionCardex_analysis_triggered()
{
    FCardexSales::open();
}

void MainWindow::on_actionExport_invoices_triggered()
{
    WSyncInvoices::open();
}

void MainWindow::on_actionComplimentary_comment_triggered()
{
    REComplimentaryComment::openComplimentaryComment();
}

void MainWindow::on_actionExport_active_reservations_triggered()
{
    DlgExport::start();
}

void MainWindow::on_actionReport_buillder_triggered()
{
    addTab<WReportBuilder>();
}

void MainWindow::on_actionRemarks_triggered()
{
    FReservaionRemarks::openReport();
}

void MainWindow::on_actionHotel_status_triggered()
{
    addTab<WHotelStatus>();
}

void MainWindow::on_actionList_of_source_reservation_triggered()
{
    FListSourceReserve::openReport();
}

void MainWindow::on_actionYearly_financial_report_triggered()
{
    FYearlyFinancialReport::openReport();
}

void MainWindow::on_actionReports_set_triggered()
{
    addTab<WCustomReports>();
}

void MainWindow::on_actionStatistics_triggered()
{
    addTab<WReportsSetOld>();
}

void MainWindow::on_actionUtils_triggered()
{
    DlgUtils *d = new DlgUtils(this);
    d->exec();
    delete d;
}

void MainWindow::on_actionExport_data_triggered()
{
    DlgExportOther *d = new DlgExportOther(this);
    d->exec();
    delete d;
}

void MainWindow::on_actionAdvance_report_triggered()
{
    FNoUsedAdvance::openReport();
}

void MainWindow::on_actionRestaurant_online_triggered()
{
    FOnlineRest::openOnlineRestaurant();
}

void MainWindow::on_actionReservation_groups_triggered()
{
    FReserveGroups::openReport();
}

void MainWindow::on_actionConfigure_Welcome_Page_triggered()
{
    DlgWelcomeButtonConfig *d = new DlgWelcomeButtonConfig(this);
    d->exec();
    delete d;
}

void MainWindow::on_actionPartners_group_triggered()
{
    RECardexGroup::openEditor();
}

void MainWindow::on_actionGuest_titles_triggered()
{
    REGuestTitle::openEditor();
}

void MainWindow::on_actionNationality_file_triggered()
{
    RENationalityFile::openEditor();
}

void MainWindow::on_actionCheckout_invoices_free_rooming_triggered()
{
    FInvoices::openReport(true);
}

void MainWindow::on_actionNew_group_reservation_triggered()
{
    addTab<DlgGroupReservationFuck>();
}

void MainWindow::on_actionChanges_of_states_of_room_triggered()
{
    FRoomState::openReport();
}

void MainWindow::on_actionCanceled_reservations_triggered()
{
    FCanceledReservations::openReport();
}

void MainWindow::on_actionWeb_triggered()
{
    addTab<WWeb>();
}

void MainWindow::on_actionReservations_by_date_created_triggered()
{
    FReserveByCreate::openReport();
}

void MainWindow::on_actionNew_store_document_triggered()
{
    StoreDoc::openStoreDocument("");
}

void MainWindow::on_actionPartners_2_triggered()
{
    REStorePartner::openStorePartners();
}

void MainWindow::on_actionDocuments_list_triggered()
{
    FStoreDocs::openReport();
}

void MainWindow::on_actionMaterials_in_the_store_triggered()
{
    FMaterialsInStore::openFilterReport<FMaterialsInStore, WReportGrid>();
}

void MainWindow::on_actionStore_movement_triggered()
{
    FStoreMovement::openFilterReport<FStoreMovement, WReportGrid>();
}

void MainWindow::on_actionCoupons_triggered()
{
    RECoupon::openReport();
}

void MainWindow::on_actionCalculate_output_of_restaurant_triggered()
{
    DlgCalculateOutputOfRestaurant::openDialog();
}

void MainWindow::on_actionOpen_breakfast_triggered()
{
    FOnlineBreakfast::openFilterReport<FOnlineBreakfast, WReportGrid>();
}

void MainWindow::on_actionMonthly_occupancy_percentages_triggered()
{
    FMonthlyOccPerc::openFilterReport<FMonthlyOccPerc, WReportGrid>();
}

void MainWindow::on_actionNaitonality_report_by_period_triggered()
{
    FNatByPeriod::openFilterReport<FNatByPeriod, WReportGrid>();
}

void MainWindow::on_actionCancelation_No_show_fees_triggered()
{
    FNoShowCancelationFee::openFilterReport<FNoShowCancelationFee, WReportGrid>();
}

void MainWindow::on_actionCancelation_No_show_fee_triggered()
{
    DlgNoShow *d = new DlgNoShow(this);
    d->exec();
    delete d;
}

void MainWindow::on_actionSales_by_storages_triggered()
{
    FRestSaleByStore::openFilterReport<FRestSaleByStore, WReportGrid>();
}

void MainWindow::on_actionGuest_by_nationality_triggered()
{
    FAllGuestInDateRange::openFilterReport<FAllGuestInDateRange, WReportGrid>();
}

void MainWindow::on_actionModels_of_cars_triggered()
{
    REModelOfCars::openReport();
}

void MainWindow::on_actionCostumers_cars_triggered()
{
    RECarClient::openReport();
}

void MainWindow::on_actionReport_by_payment_triggered()
{
    FReportByPayment::openFilterReport<FReportByPayment, WReportGrid>();
}

void MainWindow::on_actionPartners_debts_triggered()
{
    FPartnersDebt::openFilterReport<FPartnersDebt, WReportGrid>();
}

void MainWindow::on_actionCoupons_sales_triggered()
{
    FCouponSales::openFilterReport<FCouponSales, WReportGrid>();
}

void MainWindow::on_actionCoupons_seria_triggered()
{
    RECouponSeria::openReport();
}

void MainWindow::on_actionAccounts_triggered()
{
    FCash::openFilterReport<FCash, WReportGrid>();
}

void MainWindow::on_actionAccounts_2_triggered()
{
    RECashDesk::openReport();
}

void MainWindow::on_actionStore_entries_triggered()
{
    FStoreEntry::openFilterReport<FStoreEntry, WReportGrid>();
}

void MainWindow::on_actionNew_store_checkpoint_triggered()
{
    WStoreEntry::openDoc(0);
}

void MainWindow::on_actionPartner_payments_triggered()
{
    //FPartnerPayments::openFilterReport<FPartnerPayments, WReportGrid>();
}

void MainWindow::on_actionCoupons_statistics_triggered()
{
    FCouponStatistics::openFilterReport<FCouponStatistics, WReportGrid>();
}

void MainWindow::on_actionDebts_triggered()
{
    FDebtOfCostumers::openFilterReport<FDebtOfCostumers, WReportGrid>();
}

void MainWindow::on_actionBreakfast_report_triggered()
{
    FBreakfast::openFilterReport<FBreakfast, WReportGrid>();
}

void MainWindow::on_actionDiscount_report_triggered()
{
    FDiscountReport::openFilterReport<FDiscountReport, WReportGrid>();
}

void MainWindow::on_actionSales_report_by_cars_triggered()
{
    FSalesByCar::openFilterReport<FSalesByCar, WReportGrid>();
}

void MainWindow::on_actionDiscount_total_triggered()
{
    FDiscountTotal::openFilterReport<FDiscountTotal, WReportGrid>();
}

void MainWindow::on_actionCostumers_triggered()
{
    FDebtHolders::openFilterReport<FDebtHolders, WReportGrid>();
}

void MainWindow::on_actionRefund_voucher_triggered()
{
    DlgRefundVaucher::refundVaucher("", "");
}

void MainWindow::on_actionRoom_inventory_triggered()
{
    RERoomInventory::openRoomInventoryReport();
}

void MainWindow::on_actionTransfer_CL_amount_triggered()
{
    DlgCityAdvance::cityAdvance("", "", 0);
}

void MainWindow::on_actionAvailable_amounts_triggered()
{
    FCLAdvance::openFilterReport<FCLAdvance, WReportGrid>();
}

void MainWindow::on_actionGuest_Tray_Ledger_triggered()
{
    FCityTrayLedger::openFilterReport<FCityTrayLedger, WReportGrid>();
}

void MainWindow::on_actionIn_house_detailed_balance_triggered()
{
    FInhouseDetailBalance::openFilterReport<FInhouseDetailBalance, WReportGrid>();
}

void MainWindow::on_actionAvaiable_rooms_triggered()
{
    FAvailableRooms::openFilterReport<FAvailableRooms, WReportGrid>();
}

void MainWindow::on_actionRoom_inventory_2_triggered()
{
    DlgHouseItem::openWindow();
}

void MainWindow::on_actionRoom_inventory_states_triggered()
{
    RERoomInventoryState::openReport();
}

void MainWindow::on_actionList_of_checkin_guests_triggered()
{
    GuestCheckin::openFilterReport<GuestCheckin, WReportGrid>();
}

void MainWindow::on_actionLenght_of_stay_triggered()
{
    FLengthOfStay::openFilterReport<FLengthOfStay, WReportGrid>();
}

void MainWindow::on_actionExport_reservations_triggered()
{
    FExportReservation::openFilterReport<FExportReservation, WReportGrid>();
}

void MainWindow::on_actionExecute_failed_sql_triggered()
{
    DlgExecFailedSqls::openDialog();
}

void MainWindow::on_actionT_report_triggered()
{
    FTStoreReport::openFilterReport<FTStoreReport, WReportGrid>();
}

void MainWindow::on_actionDisable_second_database_triggered()
{
    QStringList dbParams = fPreferences.getDb("dd").toString().split(";", QString::SkipEmptyParts);
    if (dbParams.count() != 4) {
        return;
    }
    if (!r__(cr__do_no_write_second_db)) {
        return;
    }
    doubleDatabase = !doubleDatabase;
    if (doubleDatabase) {
        DoubleDatabase dd;
        dd.resetDoNotUse();
        setStyleSheet("");
        ui->actionDisable_second_database->setText(tr("Disable second database"));
    } else {
        setStyleSheet("background: rgb(255,150,150);");
        ui->actionDisable_second_database->setText(tr("Enable second database"));
    }
}

void MainWindow::on_actionRoom_arrangement_triggered()
{
    FRoomArrangement::openFilterReport<FRoomArrangement, WReportGrid>();
}

void MainWindow::on_actionWakeup_calls_triggered()
{
    FWakeupCall::openFilterReport<FWakeupCall, WReportGrid>();
}

void MainWindow::on_actionDaily_transactions_triggered()
{
    FDailyTransaction::openFilterReport<FDailyTransaction, WReportGrid>();
}

void MainWindow::on_actionHotel_hierarchy_triggered()
{
    FHotelHierarchy::openFilterReport<FHotelHierarchy, WReportGrid>();
}

void MainWindow::on_actionNew_room_chart_triggered()
{
    addTab<WRoomChart>();
}

void MainWindow::on_actionCall_rates_triggered()
{
    FCallRates::openFilterReport<FCallRates, WReportGrid>();
}
