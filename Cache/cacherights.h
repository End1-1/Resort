#ifndef CACHERIGHTS_H
#define CACHERIGHTS_H

#include "cachebasestruct.h"

#define cid_user_rights 42
#define r__(x) CacheRights::check(x)
#define g__(x, y) CacheRights::checkGroup(x, y)

#define cr__room_chart 1
#define cr__edit_reservation 2
#define cr__reservations 3
#define cr__menu_reservation 4
#define cr__menu_application 5
#define cr__users_groups 6
#define cr__users 7
#define cr_trackin_changes 8
#define cr__menu_bookkeeping 9
#define cr__menu_restaurant 10
#define cr__menu_direcotory 11
#define cr__contacts 12
#define cr__cardex_list 13
#define cr__guests 14
#define cr__credit_cards 15
#define cr__menu_cityledger 16
#define cr__none
#define cr__cityledger_balance 18
#define cr__invoice_cancelation_previouse_date 19
#define cr__invoice_cancelation_current_date 20
#define cr__global_config 21
#define cr__unlock_locked_reservation 23
#define cr__re_checkin 24
#define cr__services 25
#define cr__update_program 26
#define cr__super_correction 27
#define cr__reception 28
#define cr__menu_cashier 29
#define cr__report_daily_movement 30
#define cr__report_monthly 31
#define cr__report_restaurant 32
#define cr__report_checkout_invoices 33
#define cr__room_editor 34
#define cr__setup_tax 35
#define cr__invoice_items 36
#define cr__report_vauchers 37
#define cr__currencies 38
#define cr__advance_vaucher 39
#define cr__receipt_vaucher 40
#define cr__postchage_vaucher 41
#define cr__transfer_vaucher 42
#define cr__discount_vaucher 43
#define cr__report_cash 44
#define cr__reserve_cancelation 45
#define cr__checkout 46
#define cr__calls_history 47
#define cr__notes 48
#define cr__report_guest_notused 49
#define cr__o_movement 50
#define cr__o_cancelation 51
#define cr__o_print_unlimited_receipt 52
#define cr__o_print_reports 53
#define cr__o_complimentary 54
#define cr__o_breakfast 55
#define cr__o_recover_order 56
#define cr__o_banquet 57
#define cr__o_58
#define cr__o_59
#define cr__eod 60
#define cr__analytics_menu 61
#define cr__call_in 62
#define cr__call_out 63
#define cr__call_int 64
#define cr__call_tout 65
#define cr__call_tin 66
#define cr__cardex_analysis 67
#define cr__print_reports_any_day 68
#define cr__airpickup_birthday 69
#define cr__export_event_etc 70
#define cr__export_active_reservations 71
#define cr__remarks 72
#define cr__print_receipt_by_umber 73
#define cr__hotel_status 74
#define cr__reports_set 75
#define cr__remove_restaurant 76
#define cr__export_single_vauchers 77
#define cr__print_any_tax 78
#define cr__online_restaurant 79
#define cr__move_entry_checkout_invoice 80
#define cr__menu_restaurant_reports 81
#define cr__reservation_cancelation_no_show 82
#define cr__reservation_changes_state_room 83
#define cr__reception_room_inventory 84
#define cr__cityledger_avaiable_amounts 85
#define cr__storehouse_all_items 86
#define cr__directory_hotel_room_inventory 87
#define cr__directory_hotel_room_inventory_state 88
#define cr__invoice_export_to_excel 89
#define cr__reservation_group_reservation 90
#define cr__cashier_advance_report 91
#define cr__reseption_password_need 92
#define cr__rv_change_date_bank 93
#define cr__rv_change_date_cash 94
#define cr__rv_change_date_cl 95
#define cr__rv_change_date_card 96
#define cr__tracking_chnages_individual 97
#define cr__list_of_checking_guests 98
#define cr__reserv_lenght_of_stay 99
#define cr__email_confirmation 100
#define cr__cashier_refund 101
#define cr__cashier_transfer_any_direction 102
#define cr__reservation_category_to_sell 103
#define cr__reservation_forecast_occupation 104
#define cr__reservatoin_list_of_source 105
#define cr__reservation_avaiable_room 106
#define cr__bookeeping_guest_tray_ledger 107
#define cr__bookeeping_inhouse_detailed 108
#define cr__bookeeping_yearly_financial_report 109
#define cr__analytics_monthly_occupancy_perc 110
#define cr__analytics_guest_by_nationality 111
#define cr__do_no_write_second_db 112
#define cr__exec_failed_sql_queries 113
#define cr__nationality 114
#define cr__inhouse_anytime 115
#define cr__room_arrangement 116
#define cr__room_assignment 117
#define cr__expected_arrivals_pax 118
#define cr__expected_arrivals_deparutures 119
#define cr__inhouse_guest 120
#define cr__room_status_change 121
#define cr__wakeupcall 122
#define cr__hotel_hierarcgy 123
#define cr__daily_transactions 124
#define cr__cityledger_list 125
#define cr__call_rate 126
#define cr__advance_voucher_invoice 127
#define cr__temporary_receipts 128
#define cr__remove_cardex 129
#define cr__print_partial_invoice 130
#define cr__change_postcharge_wdate 131
#define cr__quick_reservations 132
#define cr__quick_checkout 133
#define cr__cash_report_by_items 134
#define cr__tax_attack 135
#define cr__inhouse_guest_future 136
#define cr__ps_correction_in_invoice 137
#define cr__close_long_open_order 138
#define cr__state_of_room 139
#define cr__expeced_departures_simple 140
#define cr__expected_arrivals_simple 141
#define cr__edit_room_inventory_list 142
#define cr__checkin_with_not_ready_room_inventory 143
#define cr__view_room_inventory_state 144
#define cr__manualtax 145
#define cr__change_rv_other_types 146
#define cr__edit_as_connection_string 147
#define cr__export_data_to_as 148
#define cr__fiscal_report 149
#define cr__update_menu_from_frontdesk 150
#define cr__travelline 151
#define cr__rest_view_guests 152
#define cr__1
#define cr__1
#define cr__1
#define cr__1
#define cr__1
#define cr__1
#define cr__1
#define cr__1
#define cr__1
#define cr__1
#define cr__1

class CacheRights : public CacheBaseStruct
{
public:
    CacheRights();
    static int fGroup;
    static bool check(int right);
    static bool checkGroup(int right, int user);
};

#endif // CACHERIGHTS_H
