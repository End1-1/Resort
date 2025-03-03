#include "wwelcome.h"
#include "ui_wwelcome.h"
#include "wmaindesk.h"
#include "wcontacts.h"
#include "wnotes.h"
#include "cachecardex.h"
#include "cachecityledger.h"
#include "dlgadvanceentry.h"
#include "dlgpostcharge.h"
#include "dlgdiscount.h"
#include "wreservation.h"
#include "dlgreceiptvaucher.h"
#include "dlgtransferanyamount.h"
#include "dlgwelcomebuttonconfig.h"
#include "dlggroupreservationfuck.h"
#include "dlgexitbyversion.h"
#include "winvoice.h"
#include <QFile>
#include <QProcess>

void WWelcome::configureLabels()
{
    fMainWindow->configureLabels();
}

void WWelcome::loadInfo()
{
    DoubleDatabase fDD;
    Utils::tableSetColumnWidths(ui->tblBirthDay, ui->tblBirthDay->columnCount(), 50, 200, 100);
    fDD[":f_state"] = RESERVE_CHECKIN;
    fDD[":f_day1"] = QDate::currentDate().day();
    fDD[":f_day2"] = QDate::currentDate().addDays(1).day();
    fDD[":f_month1"] = QDate::currentDate().month();
    fDD[":f_month2"] = QDate::currentDate().addDays(1).month();
    fDD.exec("select r.f_room, concat(g.f_firstName, ' ', g.f_lastName), g.f_dateBirth "
             "from f_reservation_guests rg "
             "left join f_reservation r on r.f_id=rg.f_reservation "
             "left join f_guests g on g.f_id=rg.f_guest "
             "where r.f_state=:f_state "
             "and ((extract(day from g.f_dateBirth) = :f_day1 and extract(month from g.f_dateBirth)=:f_month1) "
             "or  (extract(day from g.f_dateBirth) = :f_day2 and extract(month from g.f_dateBirth)=:f_month2)) ");
    Utils::fillTableWithData(ui->tblBirthDay, fDD.fDbRows);
    Utils::tableSetColumnWidths(ui->tblArrival, ui->tblArrival->columnCount(), 50, 150, 50, 100);
    fDD[":f_startDate"] = QDate::currentDate();
    fDD[":f_state"] = RESERVE_RESERVE;
    fDD.exec("select r.f_room, concat(g.f_firstName, ' ', g.f_lastName), r.f_man+r.f_woman+r.f_child, r.f_arrivalTime "
             "from f_reservation r "
             "left join f_guests g on g.f_id=r.f_guest "
             "where r.f_startDate=:f_startDate and r.f_state=:f_state and f_pickup=1 ");
    Utils::fillTableWithData(ui->tblArrival, fDD.fDbRows);
}

WWelcome::WWelcome(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WWelcome)
{
    ui->setupUi(this);
    QFile f("logo.png");
    if (f.exists()) {
        ui->lbLogo->setPixmap(QPixmap("logo.png"));
    }
    configureLabels();
    ui->btnRoomChart->setVisible(r__(cr__room_chart));
    //ui->btnNewRoomChart->setVisible(r__(cr__room_chart));
    ui->btnNewRoomChart->setVisible(false);
    ui->btnNewReservation->setVisible(r__(cr__edit_reservation));
    ui->btnNewGroupResevation->setVisible(r__(cr__reservation_group_reservation));
    ui->btnReservations->setVisible(r__(cr__reservations));
    ui->btnInhouseGuest->setVisible(r__(cr__inhouse_guest));
    ui->btnArrivalDeparture->setVisible(r__(cr__expected_arrivals_deparutures));
    ui->btnArrivalDeparture_2->setVisible(r__(cr__expected_arrivals_deparutures));
    ui->btnCallHistory->setVisible(r__(cr__calls_history));
    ui->btnNotes->setVisible(r__(cr__notes));
    ui->btnContacts->setVisible(r__(cr__contacts));
    ui->btnAdvance->setVisible(r__(cr__advance_vaucher));
    ui->btnPostCharge->setVisible(r__(cr__postchage_vaucher));
    ui->btnTransferAmount->setVisible(r__(cr__transfer_vaucher));
    ui->btnDiscount->setVisible(r__(cr__discount_vaucher));
    ui->btnCityLedgerDetailedBalance->setVisible(r__(cr__cityledger_balance));
    ui->btnCheckoutInvoices->setVisible(r__(cr__report_checkout_invoices));
    ui->btnDailyMovement->setVisible(r__(cr__report_daily_movement));
    ui->btnMonthlyMovement->setVisible(r__(cr__report_monthly));
    ui->btnCashReportDetailed->setVisible(r__(cr__report_cash));
    ui->btnCashReportSummary->setVisible(r__(cr__report_cash));
    ui->btnCardexAnalysis->setVisible(r__(cr__cardex_analysis));
    ui->btnVauchers->setVisible(r__(cr__report_vauchers));
    ui->btnExportActiveReservation->setVisible(r__(cr__export_active_reservations));
    ui->btnExportRestaurant->setVisible(r__(cr__export_event_etc));
    ui->btnCallHistory->setVisible(r__(cr__call_in) || r__(cr__call_out) || r__(cr__call_int) || r__(cr__call_tin)
                                   || r__(cr__call_tout));
    ui->btnRestaurant->setVisible(r__(cr__report_restaurant));
    ui->btnRemarks->setVisible(r__(cr__remarks));
    ui->tabInfo->setVisible(r__(cr__airpickup_birthday));
    ui->btnHotelStatus->setVisible(r__(cr__hotel_status));
    ui->btnReportsSet->setVisible(r__(cr__reports_set));
    ui->btnOnlineInvoice->setVisible(r__(cr__edit_reservation));
    ui->btnStatistic->setVisible(r__(cr__reports_set));
    ui->btnWakupCalls->setVisible(r__(cr__wakeupcall));
    ui->btnDailyTransactions->setVisible(r__(cr__daily_transactions));
    ui->btnHotelHierarchy->setVisible(r__(cr__hotel_hierarcgy));
    ui->btnRoomStateTouch->setVisible(r__(cr__state_of_room));
    ui->btnArrivalsSimple->setVisible(r__(cr__expected_arrivals_simple));
    ui->btnDeparutersSimple->setVisible(r__(cr__expeced_departures_simple));
    loadInfo();
    connect( &fTimer, SIGNAL(timeout()), SLOT(loadInfo()));
    fTimer.start(30000);
}

WWelcome::~WWelcome()
{
    delete ui;
}

void WWelcome::setSlogan(const QString &slogan)
{
    ui->lbSlogan->setText(slogan);
}

void WWelcome::handleBroadcast(const QMap<QString, QVariant> &data)
{
    int cmd = data["subcommand"].toInt();
    switch (cmd) {
        case cmd_global_settings:
        case cmd_end_of_day:
            DlgExitByVersion::exit(
                tr("The global configuration of program was modified, <br>"
                   "you need to close program, <br>"
                   "then login again to load new configuration"));
            break;
    }
}

void WWelcome::setupTab()
{
    setupTabTextAndIcon(tr("Home"), ":/images/home.png");
}

void WWelcome::showEvent(QShowEvent *event)
{
    BaseWidget::showEvent(event);
    QObjectList ol = ui->w1->children();
    foreach (QObject *o, ol) {
        EToolbarButton *t = dynamic_cast<EToolbarButton *>(o);
        if (t) {
            t->setVisible(t->isVisible() && (fPreferences.getUser("welbtn_" + t->text()).toInt() == 1));
            if (t->property("config").toBool()) {
                t->setVisible(true);
            }
        }
    }
    ui->wl1->addStretch();
    ol = ui->w2->children();
    int cnt = ui->wv1->width() / ui->btnCheckoutInvoices->width();
    int cntt = 0;
    foreach (QObject *o, ol) {
        EToolbarButton *t = dynamic_cast<EToolbarButton *>(o);
        if (t) {
            t->setVisible(t->isVisible() && (fPreferences.getUser("welbtn_" + t->text()).toInt() == 1));
            if (t->isVisible()) {
                cntt++;
                if (cntt > cnt) {
                    ui->wl2->addWidget(t);
                } else {
                    ui->wl1->addWidget(t);
                }
            }
            if (t->property("config").toBool()) {
                t->setVisible(true);
            }
        }
    }
    ui->wl2->addStretch();
    ol = ui->w3->children();
    foreach (QObject *o, ol) {
        EToolbarButton *t = dynamic_cast<EToolbarButton *>(o);
        if (t) {
            t->setVisible(t->isVisible() && (fPreferences.getUser("welbtn_" + t->text()).toInt() == 1));
            if (t->isVisible()) {
                cntt++;
                if (cntt > cnt) {
                    ui->wl2->addWidget(t);
                } else {
                    ui->wl1->addWidget(t);
                }
            }
            if (t->property("config").toBool()) {
                t->setVisible(true);
            }
        }
    }
    ol = ui->w4->children();
    foreach (QObject *o, ol) {
        EToolbarButton *t = dynamic_cast<EToolbarButton *>(o);
        if (t) {
            t->setVisible(t->isVisible() && (fPreferences.getUser("welbtn_" + t->text()).toInt() == 1));
            if (t->property("config").toBool()) {
                t->setVisible(true);
            }
        }
    }
    if (cntt > cnt) {
        ui->wl2->addWidget(ui->btnButtonsConfig);
    } else {
        ui->wl1->addWidget(ui->btnButtonsConfig);
    }
    ui->wl1->addStretch();
    ui->wl2->addStretch();
    ui->w2->setVisible(false);
    ui->w3->setVisible(false);
}

void WWelcome::on_btnRoomChart_clicked()
{
    addTab<WMainDesk>();
}

void WWelcome::on_btnAdvance_clicked()
{
    fMainWindow->on_actionNew_advance_entry_triggered();
}

void WWelcome::on_btnPostCharge_clicked()
{
    auto *p = new DlgPostCharge(this);
    p->exec();
    delete p;
}

void WWelcome::on_btnDiscount_clicked()
{
    DlgDiscount *d = new DlgDiscount(this);
    d->exec();
    delete d;
}

void WWelcome::on_btnNewReservation_clicked()
{
    WReservation *w = nullptr;
    QList<CacheRoom *> rooms;
    rooms.append(nullptr);
    w = addTab<WReservation>();
    w->setInitialParams(WORKING_DATE, WORKING_DATE, rooms);
}

void WWelcome::on_btnArrivalDeparture_clicked()
{
    fMainWindow->on_actionExpected_arrivals_triggered();
}

void WWelcome::on_btnNewGroupResevation_clicked()
{
    addTab<DlgGroupReservationFuck>();
}

void WWelcome::on_btnReservations_clicked()
{
    fMainWindow->on_actionReservatios_triggered();
}

void WWelcome::on_btnInhouseGuest_clicked()
{
    fMainWindow->on_actionIn_house_guest_triggered();
}

void WWelcome::on_btnNotes_clicked()
{
    addTab<WNotes>();
}

void WWelcome::on_btnContacts_clicked()
{
    addTab<WContacts>();
}

void WWelcome::on_btnCallHistory_clicked()
{
    fMainWindow->on_actionHistory_of_calls_triggered();
}

void WWelcome::on_btnCityLedgerDetailedBalance_clicked()
{
    fMainWindow->on_actionCity_Ledger_detailed_balance_triggered();
}

void WWelcome::on_btnCheckoutInvoices_clicked()
{
    fMainWindow->on_actionInvoices_triggered();
}

void WWelcome::on_btnDailyMovement_clicked()
{
    fMainWindow->on_actionDaily_movement_triggered();
}

void WWelcome::on_btnMonthlyMovement_clicked()
{
    fMainWindow->on_actionMonthly_Report_triggered();
}

void WWelcome::on_btnCashReportSummary_clicked()
{
    fMainWindow->on_actionCash_report_total_triggered();
}

void WWelcome::on_btnCashReportDetailed_clicked()
{
    fMainWindow->on_actionCash_repoort_detailed_triggered();
}

void WWelcome::on_btnCardexAnalysis_clicked()
{
    fMainWindow->on_actionCardex_analysis_triggered();
}

void WWelcome::on_btnVauchers_clicked()
{
    fMainWindow->on_actionVauchers_triggered();
}

void WWelcome::on_btnExportRestaurant_clicked()
{
    fMainWindow->on_actionSynchronization_triggered();
}

void WWelcome::on_btnExportActiveReservation_clicked()
{
    fMainWindow->on_actionExport_active_reservations_triggered();
}

void WWelcome::on_btnButtonsConfig_clicked()
{
    DlgWelcomeButtonConfig *d = new DlgWelcomeButtonConfig(this);
    d->exec();
    delete d;
}

void WWelcome::on_btnRestaurant_clicked()
{
    fMainWindow->on_actionRestaurant_triggered();
}

void WWelcome::on_btnRemarks_clicked()
{
    fMainWindow->on_actionRemarks_triggered();
}

void WWelcome::on_btnHotelStatus_clicked()
{
    fMainWindow->on_actionHotel_status_triggered();
}

void WWelcome::on_btnReportsSet_clicked()
{
    fMainWindow->on_actionReports_set_triggered();
}

void WWelcome::on_btnOnlineInvoice_clicked()
{
    addTab<WInvoice>();
}

void WWelcome::on_btnStatistic_clicked()
{
    fMainWindow->on_actionStatistics_triggered();
}

void WWelcome::on_btnWakupCalls_clicked()
{
    fMainWindow->on_actionWakeup_calls_triggered();
}

void WWelcome::on_btnDailyTransactions_clicked()
{
    fMainWindow->on_actionDaily_transactions_triggered();
}

void WWelcome::on_btnHotelHierarchy_clicked()
{
    fMainWindow->on_actionHotel_hierarchy_triggered();
}

void WWelcome::on_btnNewRoomChart_clicked()
{
    fMainWindow->on_actionNew_room_chart_triggered();
}

void WWelcome::on_btnTransferAmount_clicked()
{
    fMainWindow->on_actionTransfer_amount_triggered();
}

void WWelcome::on_btnArrivalDeparture_2_clicked()
{
    fMainWindow->on_actionExpected_arrivals_departures_2_triggered();
}

void WWelcome::on_btnRoomStateTouch_clicked()
{
    fMainWindow->on_actionState_of_the_room_triggered();
}

void WWelcome::on_btnArrivalsSimple_clicked()
{
    fMainWindow->on_actionExpected_arrivals_simple_triggered();
}

void WWelcome::on_btnDeparutersSimple_clicked()
{
    fMainWindow->on_actionExpected_departures_simple_triggered();
}

void WWelcome::on_btnAdvance_2_clicked()
{
    fMainWindow->on_actionReceipt_voucher_triggered();
}
