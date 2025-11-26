#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "base.h"
#include "cacheone.h"
#include "listener.h"
#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QUdpSocket>

namespace Ui
{
class MainWindow;
}

class BaseWidget;
class QListWidgetItem;

class MainWindow : public QMainWindow, public Base
{
    Q_OBJECT

public:
    explicit MainWindow(bool touchscreen, QWidget *parent = nullptr);
    ~MainWindow();
    void login();
    void logout();
    void addTabWidget(BaseWidget *widget);
    void setCurrentWidget(QWidget *w);
    void configureLabels();
    QTabWidget* fTab;
    void hideMenu();

public slots:
    void parseSocketCommand(const QString &command);
    void on_actionExpected_arrivals_triggered();
    void on_actionReservatios_triggered();
    void on_actionIn_house_guest_triggered();
    void on_actionHistory_of_calls_triggered();
    void on_actionCity_Ledger_detailed_balance_triggered();
    void on_actionInvoices_triggered();
    void on_actionDaily_movement_triggered();
    void on_actionMonthly_Report_triggered();
    void on_actionCash_repoort_detailed_triggered();
    void on_actionCash_report_total_triggered();
    void on_actionCardex_analysis_triggered();
    void on_actionVauchers_triggered();
    void on_actionExport_active_reservations_triggered();
    void on_actionSynchronization_triggered();
    void on_actionRestaurant_triggered();
    void on_actionHotel_status_triggered();
    void on_actionRemarks_triggered();
    void on_actionReports_set_triggered();
    void on_actionStatistics_triggered();
    void on_actionHakk_triggered();
    void on_actionTables_triggered();
    void on_actionNames_of_menu_triggered();
    void on_actionMain_partitions_of_menu_triggered();
    void on_actionType_of_dishes_triggered();
    void on_actionDishes_triggered();
    void on_actionModifiers_triggered();
    void on_actionStorages_triggered();
    void on_actionMenu_review_triggered();
    void on_actionPrinters_triggered();
    void on_actionTrack_changes_triggered();
    void on_actionRoomChart_triggered();
    void on_actionNew_reservation_triggered();
    void on_actionCanceled_reservations_triggered();
    void on_actionWeb_triggered();
    void on_actionReservations_by_date_created_triggered();
    void on_actionNew_store_document_triggered();
    void on_actionPartners_2_triggered();
    void on_actionCalculate_output_of_restaurant_triggered();
    void on_actionLogout_triggered();
    void on_actionLock_triggered();
    void on_actionDatabases_triggered();
    void on_actionRoom_list_triggered();
    void on_actionAbout_triggered();
    void on_actionGuest_file_triggered();
    void on_actionContacts_triggered();
    void on_actionUsers_triggered();
    void on_actionUsers_groups_triggered();
    void on_actionRoom_view_triggered();
    void on_actionPartners_triggered();
    void on_actionCredit_card_triggered();
    void on_actionCity_Ledger_balance_triggered();
    void on_actionChange_password_triggered();
    void on_actionNew_advance_entry_triggered();
    void on_actionGlobal_config_triggered();
    void on_actionComplex_dish_triggered();
    void on_actionCategories_triggered();
    void on_actionType_of_bed_triggered();
    void on_actionCategory_to_sell_triggered();
    void on_actionCity_Ledger_triggered();
    void on_actionCurrencies_triggered();
    void on_actionForecast_Occupancy_Category_triggered();
    void on_actionSetup_Tax_Printer_triggered();
    void on_actionInvoice_items_triggered();
    void on_actionPosting_charge_triggered();
    void on_actionDiscount_triggered();
    void on_actionRe_checkin_triggered();
    void on_actionTransfer_amount_triggered();
    void on_actionExpected_arrivals_simple_triggered();
    void on_actionNotes_triggered();
    void on_actionEvent_triggered();
    void on_actionDaily_financial_report_triggered();
    void on_actionBanquet_comment_triggered();
    void on_actionCity_ledger_balance_2_triggered();
    void on_actionComplimentary_comment_triggered();
    void on_actionReport_buillder_triggered();
    void on_actionList_of_source_reservation_triggered();
    void on_actionYearly_financial_report_triggered();
    void on_actionUtils_triggered();
    void on_actionAdvance_report_triggered();
    void on_actionRestaurant_online_triggered();
    void on_actionPartners_group_triggered();
    void on_actionGuest_titles_triggered();
    void on_actionNationality_file_triggered();
    void on_actionCheckout_invoices_free_rooming_triggered();
    void on_actionNew_group_reservation_triggered();
    void on_actionChanges_of_states_of_room_triggered();
    void on_actionOpen_breakfast_triggered();
    void on_actionMonthly_occupancy_percentages_triggered();
    void on_actionNaitonality_report_by_period_triggered();
    void on_actionCancelation_No_show_fees_triggered();
    void on_actionCancelation_No_show_fee_triggered();
    void on_actionSales_by_storages_triggered();
    void on_actionReservation_groups_triggered();
    void on_actionConfigure_Welcome_Page_triggered();
    void on_actionGuest_by_nationality_triggered();
    void on_actionModels_of_cars_triggered();
    void on_actionCostumers_cars_triggered();
    void on_actionReport_by_payment_triggered();
    void on_actionPartners_debts_triggered();
    void on_actionExit_triggered();
    void on_actionLogin_triggered();
    void on_actionWakeup_calls_triggered();
    void on_actionDaily_transactions_triggered();
    void on_actionHotel_hierarchy_triggered();
    void on_actionNew_room_chart_triggered();
    void on_actionExpected_arrivals_departures_2_triggered();
    void on_actionState_of_the_room_triggered();
    void on_actionExpected_departures_simple_triggered();
    void on_actionReceipt_voucher_triggered();

protected:
    void closeEvent(QCloseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void websocketDisconnected();
    void shortcutFullScreen();
    void shortcutSlot();
    void customReport();
    void tabCloseRequested(int index);
    void timeout();
    void timeout2();
    void on_actionBreakfast_report_triggered();
    void on_actionRefund_voucher_triggered();
    void on_actionRoom_inventory_triggered();
    void on_actionAvailable_amounts_triggered();
    void on_actionGuest_Tray_Ledger_triggered();
    void on_actionIn_house_detailed_balance_triggered();
    void on_actionAvaiable_rooms_triggered();
    void on_actionRoom_inventory_2_triggered();
    void on_actionRoom_inventory_states_triggered();
    void on_actionList_of_checkin_guests_triggered();
    void on_actionLenght_of_stay_triggered();
    void on_actionExport_reservations_triggered();
    void on_actionExecute_failed_sql_triggered();
    void on_actionDisable_second_database_triggered();
    void on_actionRoom_arrangement_triggered();
    void on_actionCall_rates_triggered();
    void on_actionRoom_assignment_triggered();
    void on_actionTemporary_receipts_triggered();
    void on_actionGuest_Tray_Ledger_By_Date_triggered();
    void on_actionQuick_reservations_triggered();
    void on_actionTax_server_triggered();
    void on_actionQuick_checkout_triggered();
    void on_actionCash_report_items_triggered();
    void on_actionPrint_tax_of_checkout_invoices_triggered();
    void on_actionHelp_triggered();
    void on_actionOptions_triggered();
    void on_actionInhouse_guest_future_triggered();
    void on_actionForecast_occupancy_by_category_triggered();
    void on_actionExpected_arivals_simple_triggered();
    void on_actionArmSoft_triggered();
    void on_actionFiscal_report_triggered();
    void on_actionUpload_menu_from_FrontDesk_triggered();
    void on_actionCategory_statistics_triggered();

    void on_actionTravelline_triggered();

    void on_lstTravelLine_itemClicked(QListWidgetItem *item);

    void on_actionIncomplete_guests_names_triggered();

    void on_actionArrival_Departures_for_restaurant_triggered();

private:
    Listener fServer2Listener;
    Ui::MainWindow* ui;
    QTimer fTimer;
    QTimer fTimeErrLabel;
    bool fTimeErrLableValue;
    bool fTouchscreen;
    QString actionTitle(QObject *a);
    QLabel* fStatusLabelLeft;
    QLabel* fStatusLabelRight;
    QLabel* fStateOfSecondDb;
    CacheOne fCacheOne;
    void lock();
    void enableMainMenu(bool value);
    void disableMainMenu();
    QMap<QAction*, int> fCustomReports;

signals:
    void updateCache(int cache, const QString &code);
};

#endif // MAINWINDOW_H
