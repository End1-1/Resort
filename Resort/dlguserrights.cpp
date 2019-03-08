#include "dlguserrights.h"
#include "ui_dlguserrights.h"
#include <QProxyStyle>

class CustomTabStyle : public QProxyStyle {
public:
  QSize sizeFromContents(ContentsType type, const QStyleOption* option,
                         const QSize& size, const QWidget* widget) const {
    QSize s = QProxyStyle::sizeFromContents(type, option, size, widget);
    if (type == QStyle::CT_TabBarTab) {
      s.transpose();
    }
    return s;
  }

  void drawControl(ControlElement element, const QStyleOption* option, QPainter* painter, const QWidget* widget) const {
    if (element == CE_TabBarTabLabel) {
      if (const QStyleOptionTab* tab = qstyleoption_cast<const QStyleOptionTab*>(option)) {
        QStyleOptionTab opt(*tab);
        opt.shape = QTabBar::RoundedNorth;
        QProxyStyle::drawControl(element, &opt, painter, widget);
        return;
      }
    }
    QProxyStyle::drawControl(element, option, painter, widget);
  }


};

DlgUserRights::DlgUserRights(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgUserRights)
{
    ui->setupUi(this);
    ui->tw->tabBar()->setStyle(new CustomTabStyle());
}

DlgUserRights::~DlgUserRights()
{
    delete ui;
}

void DlgUserRights::setup(QList<QVariant> &values)
{
    fGroupId = values.at(0).toInt();
    setWindowTitle(tr("Rights for") + " " + values.at(1).toString());
    fTrackControl = new TrackControl(TRACK_USER_RIGHTS);
    fTrackControl->addWidget(ui->chRoomChart, "Room char")
            .addWidget(ui->chEditReservation, "Edit reservation")
            .addWidget(ui->chCmnRepREservation, "Reservation report")
            .addWidget(ui->chAllREservation, "All reservation items")
            .addWidget(ui->chMenuApplication, "All application items")
            .addWidget(ui->chUsersGroups, "Users groups")
            .addWidget(ui->chUsers, "Users")
            .addWidget(ui->chEndOfDay, "End of day")
            .addWidget(ui->chTrackChanges, "Track changes")
            .addWidget(ui->chMenuBookeeping, "All bookkeeping items")
            .addWidget(ui->chMenuRestaurant, "All restaurant items")
            .addWidget(ui->chMenuDirectory, "All directory items")
            .addWidget(ui->chPartners, "Partners")
            .addWidget(ui->chGuests, "Guests")
            .addWidget(ui->chGlobalConfig, "Global config")
            .addWidget(ui->chCreditCard, "Credit cards")
            .addWidget(ui->chServices, "Services")
            .addWidget(ui->chUnlockReserve, "Unlock locked reservation")
            .addWidget(ui->choMovement, "Move table / dishes")
            .addWidget(ui->choCancelation, "Cancelation")
            .addWidget(ui->choPrintUnlimitedReceipt, "Print unlimited receipt")
            .addWidget(ui->choPrintReports, "Print reports")
            .addWidget(ui->chMenuCityLedger, "All city ledger items")
            .addWidget(ui->chCityLedgerBalance, "City ledger balance")
            .addWidget(ui->chUpdateProgram, "Update program")
            .addWidget(ui->chSuperCorrection, "Super correction")
            .addWidget(ui->chReceptionMenu, "All reception items")
            .addWidget(ui->chVaucherHistory, "Vouchers history")
            .addWidget(ui->chDailyMovement, "Daily movement")
            .addWidget(ui->chMonthlyTotal, "Monthly report")
            .addWidget(ui->chReportRestaurant, "Restaurant report")
            .addWidget(ui->chCheckoutInvoices, "CheckoutInvoices")
            .addWidget(ui->chRoomEditor, "Room editor")
            .addWidget(ui->chInvoiceItems, "Invoice items")
            .addWidget(ui->chSetupTax, "Setup tax printer")
            .addWidget(ui->chMenuCashier, "Menu cashier")
            .addWidget(ui->chCurrencies, "Currencies")
            .addWidget(ui->chAdvanceReceipt, "Advance voucher")
            .addWidget(ui->chPostCharge, "Post charge")
            .addWidget(ui->chTransferAmount, "Transfer amount")
            .addWidget(ui->chReceiptVaucher, "Recept voucher")
            .addWidget(ui->chDiscountVaucher, "Discount voucher")
            .addWidget(ui->chCheckout, "Checkout")
            .addWidget(ui->chReservationCancel, "Cancel reservation")
            .addWidget(ui->chCashReports, "CashReports")
            .addWidget(ui->chRecheckin, "Recheckin")
            .addWidget(ui->chCallHistory, "Calls history")
            .addWidget(ui->chNotes, "Notes")
            .addWidget(ui->chContacts, "Contacts")
            .addWidget(ui->chExpectedArrivalsPax, "Expected arrivals / pax")
            .addWidget(ui->chExpectedArrivalsPax_2, "Expected arrivals / departures")
            .addWidget(ui->chBanket, "Banket")
            .addWidget(ui->chBreakfast, "Breakfast")
            .addWidget(ui->chRecover, "Recover order")
            .addWidget(ui->chAnalyticsMenu, "Analytics menu")
            .addWidget(ui->chCallIn, "Incoming call")
            .addWidget(ui->chCallOut, "Outgoing call")
            .addWidget(ui->chCallInt, "Internal call")
            .addWidget(ui->chCallTransferIn, "Transfer in call")
            .addWidget(ui->chCallTrasferOut, "Transfer out call")
            .addWidget(ui->chCardexAnalysis, "Cardex analysis")
            .addWidget(ui->chRestReportanyDay, "Restuarant report, any day")
            .addWidget(ui->chArrivalBirthDayPanel, "Arrival and birthday panel")
            .addWidget(ui->chComplimentary, "Complimentary")
            .addWidget(ui->chExportInvoice, "Export invocie")
            .addWidget(ui->chActiveReserve, "Export active reserve")
            .addWidget(ui->chSingleVaucher, "Export signle vouchers")
            .addWidget(ui->chRemarks, "Reservation Remarks")
            .addWidget(ui->chPrintReceiptByNumber, "Print receipt by number")
            .addWidget(ui->chHotelStatus, "Hotel status")
            .addWidget(ui->chReportSet, "Reports set")
            .addWidget(ui->chRemoveOrderPermanent, "Remove restaurant order permanently")
            .addWidget(ui->chExportSingleVauchers, "Export single vouchers")
            .addWidget(ui->chPrintTaxByNumber, "Print tax by order number")
            .addWidget(ui->chOnlineRest, "Online restaurant")
            .addWidget(ui->chMoveInvoiceItem, "Move entry in checkout invoice")
            .addWidget(ui->chRestaurantReports, "Restaurant reports")
            .addWidget(ui->chRoomStateChange, "Changes of room state")
            .addWidget(ui->chCancelationNOShow, "Cancelation, no show")
            .addWidget(ui->chRecetpionRoomInventory, "Reception, room inventory")
            .addWidget(ui->chHotelRoomInventory, "Directory of hotel, room inventory")
            .addWidget(ui->chRoomInventoryState, "Directory of hotel, room inventory state")
            .addWidget(ui->chInvoiceExportToExcel, "Invoice, export to excel")
            .addWidget(ui->chEditViewGroupReservation, "Group reservation")
            .addWidget(ui->chAdvanceReport, "Cashier, advance report")
            .addWidget(ui->chChangeRVDateBank, "Change date for receipt voucher, bank")
            .addWidget(ui->chChangeRVDateCash, "Change date for receipt voucher, cash")
            .addWidget(ui->chChangeRVDateCL, "Change date for receipt voucher, CL")
            .addWidget(ui->chChangeDateRVCard, "Change date for receipt voucher, card")
            .addWidget(ui->chTrakingIndividual, "Changes tracking, individual")
            .addWidget(ui->chListOfCheckingGuest, "List of checking guests")
            .addWidget(ui->chReservLengthOfStay, "Length of stay")
            .addWidget(ui->chEmailConfirmation, "Email confirmation")
            .addWidget(ui->chTransferAnyDirection, "Transfer amount, any direction")
            .addWidget(ui->chRefundVoucher, "Refund voucher")
            .addWidget(ui->chCategoryToSell, "Category to sell")
            .addWidget(ui->chForecastOccupancy, "Forecast occupancy")
            .addWidget(ui->chListOfSourceReservation, "List of source reservation")
            .addWidget(ui->chAvailableRooms, "Available rooms")
            .addWidget(ui->chBookHGuestTrayLegder, "Guest tray ledger")
            .addWidget(ui->chInhouseDetailedBalance, "Inhouse guests detailed balance")
            .addWidget(ui->chYeralyFinancial, "Yearly financial report")
            .addWidget(ui->chMonthlyOccupancyPercentages, "Monthly occupancy percentages")
            .addWidget(ui->chGuestByNationality, "Guests by nationality")
            .addWidget(ui->chDoNotUseSecondDB, "Dont use second database")
            .addWidget(ui->chNationalityFile, "Nationality file")
            .addWidget(ui->chInhouseGuestAnyTime, "Inhouse guest any period")
            .addWidget(ui->chRoomArrangement, "Room arrangement report")
            .addWidget(ui->chRoomAssignmen, "Room assignment")
            .addWidget(ui->chInhouseGuest, "Inhouse guest")
            .addWidget(ui->chAvailableCLAmounts, "Available CL amounts")
            .addWidget(ui->chRoomStatusChange, "Room status changes")
            .addWidget(ui->chHotelHierarchy, "Hotel hierarchy")
            .addWidget(ui->chWakeupCalls, "Wakeup calls")
            .addWidget(ui->chDailyTransactions, "Daily transactions")
            .addWidget(ui->chCityledgerList, "Cityledgers")
            .addWidget(ui->chCancelPreviousDate, "Voucher cancelation on previous date")
            .addWidget(ui->chCancelCurrentDate, "Voucher cancelation on current date")
            ;
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_group"] = fGroupId;
    fDD.exec("select f_right, f_flag from users_rights where f_group=:f_group");
    QMap<int, QString> fTags;
    while (fDD.nextRow()) {
        QListIterator<TrackWidget*> ti = fTrackControl->widgetIterator();
        while (ti.hasNext()) {
            EQCheckBox *check = static_cast<EQCheckBox*>(ti.next()->fWidget);            
            if (check->getTag() == fDD.getInt(0)) {
                if (fTags.contains(check->getTag())) {
                    message_error("Duplicate tag: " + fTags[check->getTag()] + "/" + check->text());
                }
                fTags.insert(check->getTag(), check->text());
                check->setChecked(fDD.getInt(1) == 1);
                break;
            }
        }
    }
    fTrackControl->resetChanges();
}

void DlgUserRights::on_btnCancel_clicked()
{
    reject();
}

void DlgUserRights::on_btnOk_clicked()
{
    DoubleDatabase fDD(true, doubleDatabase);
    fDD.startTransaction();
    fDD[":f_group"] = fGroupId;
    fDD.exec("delete from users_rights where f_group=:f_group");
    QListIterator<TrackWidget*> ti = fTrackControl->widgetIterator();
    QString query = "insert into users_rights (f_group, f_right, f_flag) values ";
    bool first = true;
    while (ti.hasNext()) {
        TrackWidget *t = ti.next();
        if (first) {
            first = false;
        } else {
            query += ",";
        }
        EQCheckBox *check = static_cast<EQCheckBox*>(t->fWidget);
        if (check->getTag() == 0) {
            message_error("Axtung, Tag==0, " + t->fKey);
        }
        query += QString("(%1, %2, %3)")
                .arg(fGroupId)
                .arg(check->getTag())
                .arg(check->isChecked());
    }
    fDD.exec(query);
    if (fTrackControl->hasChanges()) {
        fTrackControl->saveChanges();
    }
    fDD.commit();
    accept();
}

void DlgUserRights::on_chCheckUncheck_clicked(bool checked)
{
    QListIterator<TrackWidget*> ti = fTrackControl->widgetIterator();
    while (ti.hasNext()) {
        TrackWidget *t = ti.next();
        EQCheckBox *check = static_cast<EQCheckBox*>(t->fWidget);
        check->setChecked(checked);
    }
}
