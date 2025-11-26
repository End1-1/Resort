#include "dlguserrights.h"
#include "ui_dlguserrights.h"
#include <QProxyStyle>

class CustomTabStyle : public QProxyStyle
{
public:
    QSize sizeFromContents(ContentsType type, const QStyleOption* option,
                           const QSize& size, const QWidget* widget) const
    {
        QSize s = QProxyStyle::sizeFromContents(type, option, size, widget);

        if(type == QStyle::CT_TabBarTab) {
            s.transpose();
        }

        return s;
    }

    void drawControl(ControlElement element, const QStyleOption* option, QPainter* painter, const QWidget* widget) const
    {
        if(element == CE_TabBarTabLabel) {
            if(const QStyleOptionTab* tab = qstyleoption_cast<const QStyleOptionTab*>(option)) {
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

void DlgUserRights::setup(QList<QVariant>& values)
{
    fGroupId = values.at(0).toInt();
    setWindowTitle(tr("Rights for") + " " + values.at(1).toString());
    fTrackControl = new TrackControl(TRACK_USER_RIGHTS);
    fTrackControl->addWidget(ui->chRoomChart, QString::number(fGroupId) + ": " + "Room char")
    .addWidget(ui->chEditReservation, QString::number(fGroupId) + ": " + "Edit reservation")
    .addWidget(ui->chCmnRepREservation, QString::number(fGroupId) + ": " + "Reservation report")
    .addWidget(ui->chAllREservation, QString::number(fGroupId) + ": " + "All reservation items")
    .addWidget(ui->chMenuApplication, QString::number(fGroupId) + ": " + "All application items")
    .addWidget(ui->chUsersGroups, QString::number(fGroupId) + ": " + "Users groups")
    .addWidget(ui->chUsers, QString::number(fGroupId) + ": " + "Users")
    .addWidget(ui->chEndOfDay, QString::number(fGroupId) + ": " + "End of day")
    .addWidget(ui->chTrackChanges, QString::number(fGroupId) + ": " + "Track changes")
    .addWidget(ui->chMenuBookeeping, QString::number(fGroupId) + ": " + "All bookkeeping items")
    .addWidget(ui->chMenuRestaurant, QString::number(fGroupId) + ": " + "All restaurant items")
    .addWidget(ui->chMenuDirectory, QString::number(fGroupId) + ": " + "All directory items")
    .addWidget(ui->chPartners, QString::number(fGroupId) + ": " + "Partners")
    .addWidget(ui->chGuests, QString::number(fGroupId) + ": " + "Guests")
    .addWidget(ui->chGlobalConfig, QString::number(fGroupId) + ": " + "Global config")
    .addWidget(ui->chCreditCard, QString::number(fGroupId) + ": " + "Credit cards")
    .addWidget(ui->chServices, QString::number(fGroupId) + ": " + "Services")
    .addWidget(ui->chUnlockReserve, QString::number(fGroupId) + ": " + "Unlock locked reservation")
    .addWidget(ui->choMovement, QString::number(fGroupId) + ": " + "Move table / dishes")
    .addWidget(ui->choCancelation, QString::number(fGroupId) + ": " + "Cancelation")
    .addWidget(ui->choPrintUnlimitedReceipt, QString::number(fGroupId) + ": " + "Print unlimited receipt")
    .addWidget(ui->choPrintReports, QString::number(fGroupId) + ": " + "Print reports")
    .addWidget(ui->chMenuCityLedger, QString::number(fGroupId) + ": " + "All city ledger items")
    .addWidget(ui->chCityLedgerBalance, QString::number(fGroupId) + ": " + "City ledger balance")
    .addWidget(ui->chUpdateProgram, QString::number(fGroupId) + ": " + "Update program")
    .addWidget(ui->chSuperCorrection, QString::number(fGroupId) + ": " + "Super correction")
    .addWidget(ui->chReceptionMenu, QString::number(fGroupId) + ": " + "All reception items")
    .addWidget(ui->chVaucherHistory, QString::number(fGroupId) + ": " + "Vouchers history")
    .addWidget(ui->chDailyMovement, QString::number(fGroupId) + ": " + "Daily movement")
    .addWidget(ui->chMonthlyTotal, QString::number(fGroupId) + ": " + "Monthly report")
    .addWidget(ui->chReportRestaurant, QString::number(fGroupId) + ": " + "Restaurant report")
    .addWidget(ui->chCheckoutInvoices, QString::number(fGroupId) + ": " + "CheckoutInvoices")
    .addWidget(ui->chRoomEditor, QString::number(fGroupId) + ": " + "Room editor")
    .addWidget(ui->chInvoiceItems, QString::number(fGroupId) + ": " + "Invoice items")
    .addWidget(ui->chSetupTax, QString::number(fGroupId) + ": " + "Setup tax printer")
    .addWidget(ui->chMenuCashier, QString::number(fGroupId) + ": " + "Menu cashier")
    .addWidget(ui->chCurrencies, QString::number(fGroupId) + ": " + "Currencies")
    .addWidget(ui->chAdvanceReceipt, QString::number(fGroupId) + ": " + "Advance voucher")
    .addWidget(ui->chPostCharge, QString::number(fGroupId) + ": " + "Post charge")
    .addWidget(ui->chTransferAmount, QString::number(fGroupId) + ": " +  "Transfer amount")
    .addWidget(ui->chReceiptVaucher, QString::number(fGroupId) + ": " +  "Recept voucher")
    .addWidget(ui->chDiscountVaucher, QString::number(fGroupId) + ": " +  "Discount voucher")
    .addWidget(ui->chCheckout, QString::number(fGroupId) + ": " +  "Checkout")
    .addWidget(ui->chReservationCancel, QString::number(fGroupId) + ": " +  "Cancel reservation")
    .addWidget(ui->chCashReports, QString::number(fGroupId) + ": " +  "CashReports")
    .addWidget(ui->chRecheckin, QString::number(fGroupId) + ": " +  "Recheckin")
    .addWidget(ui->chCallHistory, QString::number(fGroupId) + ": " +  "Calls history")
    .addWidget(ui->chNotes, QString::number(fGroupId) + ": " +  "Notes")
    .addWidget(ui->chContacts, QString::number(fGroupId) + ": " +  "Contacts")
    .addWidget(ui->chExpectedArrivalsPax, QString::number(fGroupId) + ": " +  "Expected arrivals / pax")
    .addWidget(ui->chExpectedArrivalsPax_2, QString::number(fGroupId) + ": " +  "Expected arrivals / departures")
    .addWidget(ui->chBanket, QString::number(fGroupId) + ": " +  "Banket")
    .addWidget(ui->chBreakfast, QString::number(fGroupId) + ": " +  "Breakfast")
    .addWidget(ui->chRecover, QString::number(fGroupId) + ": " +  "Recover order")
    .addWidget(ui->chAnalyticsMenu, QString::number(fGroupId) + ": " +  "Analytics menu")
    .addWidget(ui->chCallIn, QString::number(fGroupId) + ": " +  "Incoming call")
    .addWidget(ui->chCallOut, QString::number(fGroupId) + ": " +  "Outgoing call")
    .addWidget(ui->chCallInt, QString::number(fGroupId) + ": " +  "Internal call")
    .addWidget(ui->chCallTransferIn, QString::number(fGroupId) + ": " +  "Transfer in call")
    .addWidget(ui->chCallTrasferOut, QString::number(fGroupId) + ": " +  "Transfer out call")
    .addWidget(ui->chCardexAnalysis, QString::number(fGroupId) + ": " +  "Cardex analysis")
    .addWidget(ui->chRestReportanyDay, QString::number(fGroupId) + ": " +  "Restuarant report, any day")
    .addWidget(ui->chArrivalBirthDayPanel, QString::number(fGroupId) + ": " +  "Arrival and birthday panel")
    .addWidget(ui->chComplimentary, QString::number(fGroupId) + ": " +  "Complimentary")
    .addWidget(ui->chExportInvoice, QString::number(fGroupId) + ": " +  "Export invocie")
    .addWidget(ui->chActiveReserve, QString::number(fGroupId) + ": " +  "Export active reserve")
    .addWidget(ui->chSingleVaucher, QString::number(fGroupId) + ": " +  "Export signle vouchers")
    .addWidget(ui->chRemarks, QString::number(fGroupId) + ": " +  "Reservation Remarks")
    .addWidget(ui->chPrintReceiptByNumber, QString::number(fGroupId) + ": " +  "Print receipt by number")
    .addWidget(ui->chHotelStatus, QString::number(fGroupId) + ": " +  "Hotel status")
    .addWidget(ui->chReportSet, QString::number(fGroupId) + ": " +  "Reports set")
    .addWidget(ui->chRemoveOrderPermanent, QString::number(fGroupId) + ": " +  "Remove restaurant order permanently")
    .addWidget(ui->chExportSingleVauchers, QString::number(fGroupId) + ": " +  "Export single vouchers")
    .addWidget(ui->chPrintTaxByNumber, QString::number(fGroupId) + ": " +  "Print tax by order number")
    .addWidget(ui->chOnlineRest, QString::number(fGroupId) + ": " +  "Online restaurant")
    .addWidget(ui->chMoveInvoiceItem, QString::number(fGroupId) + ": " +  "Move entry in checkout invoice")
    .addWidget(ui->chRestaurantReports, QString::number(fGroupId) + ": " +  "Restaurant reports")
    .addWidget(ui->chRoomStateChange, QString::number(fGroupId) + ": " +  "Changes of room state")
    .addWidget(ui->chCancelationNOShow, QString::number(fGroupId) + ": " +  "Cancelation, no show")
    .addWidget(ui->chRecetpionRoomInventory, QString::number(fGroupId) + ": " +  "Reception, room inventory")
    .addWidget(ui->chHotelRoomInventory, QString::number(fGroupId) + ": " +  "Directory of hotel, room inventory")
    .addWidget(ui->chRoomInventoryState, QString::number(fGroupId) + ": " +  "Directory of hotel, room inventory state")
    .addWidget(ui->chInvoiceExportToExcel, QString::number(fGroupId) + ": " +  "Invoice, export to excel")
    .addWidget(ui->chEditViewGroupReservation, QString::number(fGroupId) + ": " +  "Group reservation")
    .addWidget(ui->chAdvanceReport, QString::number(fGroupId) + ": " +  "Cashier, advance report")
    .addWidget(ui->chChangeRVDateBank, QString::number(fGroupId) + ": " +  "Change date for receipt voucher, bank")
    .addWidget(ui->chChangeRVDateCash, QString::number(fGroupId) + ": " +  "Change date for receipt voucher, cash")
    .addWidget(ui->chChangeRVDateCL, QString::number(fGroupId) + ": " +  "Change date for receipt voucher, CL")
    .addWidget(ui->chChangeDateRVCard, QString::number(fGroupId) + ": " +  "Change date for receipt voucher, card")
    .addWidget(ui->chTrakingIndividual, QString::number(fGroupId) + ": " +  "Changes tracking, individual")
    .addWidget(ui->chListOfCheckingGuest, QString::number(fGroupId) + ": " +  "List of checking guests")
    .addWidget(ui->chReservLengthOfStay, QString::number(fGroupId) + ": " +  "Length of stay")
    .addWidget(ui->chEmailConfirmation, QString::number(fGroupId) + ": " +  "Email confirmation")
    .addWidget(ui->chTransferAnyDirection, QString::number(fGroupId) + ": " +  "Transfer amount, any direction")
    .addWidget(ui->chRefundVoucher, QString::number(fGroupId) + ": " +  "Refund voucher")
    .addWidget(ui->chCategoryToSell, QString::number(fGroupId) + ": " +  "Category to sell")
    .addWidget(ui->chForecastOccupancy, QString::number(fGroupId) + ": " +  "Forecast occupancy")
    .addWidget(ui->chListOfSourceReservation, QString::number(fGroupId) + ": " +  "List of source reservation")
    .addWidget(ui->chAvailableRooms, QString::number(fGroupId) + ": " +  "Available rooms")
    .addWidget(ui->chBookHGuestTrayLegder, QString::number(fGroupId) + ": " +  "Guest tray ledger")
    .addWidget(ui->chInhouseDetailedBalance, QString::number(fGroupId) + ": " +  "Inhouse guests detailed balance")
    .addWidget(ui->chYeralyFinancial, QString::number(fGroupId) + ": " +  "Yearly financial report")
    .addWidget(ui->chMonthlyOccupancyPercentages, QString::number(fGroupId) + ": " +  "Monthly occupancy percentages")
    .addWidget(ui->chGuestByNationality, QString::number(fGroupId) + ": " +  "Guests by nationality")
    .addWidget(ui->chDoNotUseSecondDB, QString::number(fGroupId) + ": " +  "Dont use second database")
    .addWidget(ui->chNationalityFile, QString::number(fGroupId) + ": " +  "Nationality file")
    .addWidget(ui->chInhouseGuestAnyTime, QString::number(fGroupId) + ": " +  "Inhouse guest any period")
    .addWidget(ui->chRoomArrangement, QString::number(fGroupId) + ": " +  "Room arrangement report")
    .addWidget(ui->chRoomAssignmen, QString::number(fGroupId) + ": " +  "Room assignment")
    .addWidget(ui->chInhouseGuest, QString::number(fGroupId) + ": " +  "Inhouse guest")
    .addWidget(ui->chAvailableCLAmounts, QString::number(fGroupId) + ": " +  "Available CL amounts")
    .addWidget(ui->chRoomStatusChange, QString::number(fGroupId) + ": " +  "Room status changes")
    .addWidget(ui->chHotelHierarchy, QString::number(fGroupId) + ": " +  "Hotel hierarchy")
    .addWidget(ui->chWakeupCalls, QString::number(fGroupId) + ": " +  "Wakeup calls")
    .addWidget(ui->chDailyTransactions, QString::number(fGroupId) + ": " +  "Daily transactions")
    .addWidget(ui->chCityledgerList, QString::number(fGroupId) + ": " +  "Cityledgers")
    .addWidget(ui->chCancelPreviousDate, QString::number(fGroupId) + ": " +  "Voucher cancelation on previous date")
    .addWidget(ui->chCancelCurrentDate, QString::number(fGroupId) + ": " +  "Voucher cancelation on current date")
    .addWidget(ui->chAdvanceReceiptInvoice, QString::number(fGroupId) + ": " +  "Advance voucher in invoice")
    .addWidget(ui->chTempReceipt, QString::number(fGroupId) + ": " +  "Temporary receipts")
    .addWidget(ui->chPartnersRemove, QString::number(fGroupId) + ": " +  "Remove cardex")
    .addWidget(ui->chPrintInvoicePartialy, QString::number(fGroupId) + ": " +  "Print invoice partialy")
    .addWidget(ui->chChangePostChargeWorkingDate, QString::number(fGroupId) + ": " +  "Change post charge working date")
    .addWidget(ui->chQuickReservations, QString::number(fGroupId) + ": " +  "Quick checkin")
    .addWidget(ui->chQuickCheckout, QString::number(fGroupId) + ": " +  "Quick checkout")
    .addWidget(ui->chTaxOfInvoices, QString::number(fGroupId) + ": " + "Tax attack")
    .addWidget(ui->chPSVoucherCancelFromInvoice, QString::number(fGroupId) + ": " + "PS voucher cancelation from invoice")
    .addWidget(ui->chCloseOldOpenOrder, QString::number(fGroupId) + ": " + ui->chCloseOldOpenOrder->text())
    .addWidget(ui->chStateOfTheRoom, QString::number(fGroupId) + ": " + ui->chStateOfTheRoom->text())
    .addWidget(ui->chExpectedDeparturesSimple, QString::number(fGroupId) + ": " + ui->chExpectedDeparturesSimple->text())
    .addWidget(ui->chExpectedArrivalsSimple, QString::number(fGroupId) + ": " + ui->chExpectedArrivalsSimple->text())
    .addWidget(ui->chReceptionEditRoomInventory, QString::number(fGroupId) + ": " + ui->chReceptionEditRoomInventory->text())
    .addWidget(ui->chCheckinWithNotReadyRoomInventory, QString::number(fGroupId) + ": " + ui->chCheckinWithNotReadyRoomInventory->text())
    .addWidget(ui->chRoomInventoryViewer, QString::number(fGroupId) + ": " + ui->chRoomInventoryViewer->text())
    .addWidget(ui->chManualTax, QString::number(fGroupId) + ": " + ui->chManualTax->text())
    .addWidget(ui->chChangeRVDateCL_2, QString::number(fGroupId) + ": " + ui->chChangeRVDateCL_2->text())
    .addWidget(ui->chEditASConString, QString::number(fGroupId) + ": " + "AS connection string")
    .addWidget(ui->chExportDataToAS, QString::number(fGroupId) + ": " + "Export data to AS")
    .addWidget(ui->chTaxReport, QString::number(fGroupId) + ": " + "Fiscal report")
    .addWidget(ui->chTravelLine, QString::number(fGroupId) + ": " + "TravelLine")
    .addWidget(ui->chInitRestaurantFromOffice, QString::number(fGroupId) + ": " + "Init restaurant dishes from external db")
    .addWidget(ui->chGuestArrivalDeparture, QString::number(fGroupId) + ": " + "Arrival departure very simple")
    ;
    DoubleDatabase fDD;
    fDD[":f_group"] = fGroupId;
    fDD.exec("select f_right, f_flag from users_rights where f_group=:f_group");
    QMap<int, QString> fTags;

    while(fDD.nextRow()) {
        QListIterator<TrackWidget*> ti = fTrackControl->widgetIterator();

        while(ti.hasNext()) {
            EQCheckBox *check = static_cast<EQCheckBox*>(ti.next()->fWidget);

            if(check->getTag() == fDD.getInt(0)) {
                if(fTags.contains(check->getTag())) {
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
    DoubleDatabase fDD;
    fDD.startTransaction();
    fDD[":f_group"] = fGroupId;
    fDD.exec("delete from users_rights where f_group=:f_group");
    QListIterator<TrackWidget*> ti = fTrackControl->widgetIterator();
    QString query = "insert into users_rights (f_group, f_right, f_flag) values ";
    bool first = true;

    while(ti.hasNext()) {
        TrackWidget *t = ti.next();

        if(first) {
            first = false;
        } else {
            query += ",";
        }

        EQCheckBox *check = static_cast<EQCheckBox*>(t->fWidget);

        if(check->getTag() == 0) {
            message_error("Axtung, Tag==0 " + t->fKey);
        }

        query += QString("(%1, %2, %3)")
                 .arg(fGroupId)
                 .arg(check->getTag())
                 .arg(check->isChecked());
    }

    fDD.exec(query);

    if(fTrackControl->hasChanges()) {
        fTrackControl->saveChanges();
    }

    fDD.commit();
    accept();
}

void DlgUserRights::on_chCheckUncheck_clicked(bool checked)
{
    QListIterator<TrackWidget*> ti = fTrackControl->widgetIterator();

    while(ti.hasNext()) {
        TrackWidget *t = ti.next();
        EQCheckBox *check = static_cast<EQCheckBox*>(t->fWidget);
        check->setChecked(checked);
    }
}
