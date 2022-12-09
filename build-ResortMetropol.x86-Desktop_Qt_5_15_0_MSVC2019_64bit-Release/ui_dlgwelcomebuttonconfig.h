/********************************************************************************
** Form generated from reading UI file 'dlgwelcomebuttonconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGWELCOMEBUTTONCONFIG_H
#define UI_DLGWELCOMEBUTTONCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <etoolbarbutton.h>

QT_BEGIN_NAMESPACE

class Ui_DlgWelcomeButtonConfig
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *w1;
    QHBoxLayout *horizontalLayout_2;
    EToolbarButton *btnRoomChart;
    EToolbarButton *btnNewReservation;
    EToolbarButton *btnNewGroupResevation;
    EToolbarButton *btnHotelStatus;
    EToolbarButton *btnInhouseGuest;
    EToolbarButton *btnReservations;
    EToolbarButton *btnArrivalDeparture;
    EToolbarButton *btnArrivalDeparture_2;
    EToolbarButton *btnCheckoutInvoices;
    EToolbarButton *btnVauchers;
    EToolbarButton *btnCallHistory;
    QSpacerItem *horizontalSpacer_4;
    QWidget *w4;
    QHBoxLayout *horizontalLayout_5;
    EToolbarButton *btnArrivalsSimple;
    EToolbarButton *btnDeparutersSimple;
    EToolbarButton *btnWakeupCalls;
    EToolbarButton *btnDailyTransactions;
    EToolbarButton *btnRemarks;
    EToolbarButton *btnContacts;
    EToolbarButton *btnHotelHierarchy;
    EToolbarButton *btnRoomStateTouch;
    QSpacerItem *horizontalSpacer_6;
    QWidget *w2;
    QHBoxLayout *horizontalLayout_3;
    EToolbarButton *btnDailyMovement;
    EToolbarButton *btnMonthlyMovement;
    EToolbarButton *btnCityLedgerDetailedBalance;
    EToolbarButton *btnCashReportSummary;
    EToolbarButton *btnCashReportDetailed;
    EToolbarButton *btnRestaurant;
    EToolbarButton *btnCardexAnalysis;
    EToolbarButton *btnReportSet;
    EToolbarButton *btnStatistics;
    QSpacerItem *horizontalSpacer_5;
    QWidget *w3;
    QHBoxLayout *horizontalLayout_4;
    EToolbarButton *btnPostCharge;
    EToolbarButton *btnReceipt;
    EToolbarButton *btnAdvance;
    EToolbarButton *btnTransfer;
    EToolbarButton *btnDiscount;
    EToolbarButton *btnOnlineInvoice;
    EToolbarButton *btnExportInvoices;
    EToolbarButton *btnExportRestaurant;
    EToolbarButton *btnExportActiveReservation;
    EToolbarButton *btnNotes;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *DlgWelcomeButtonConfig)
    {
        if (DlgWelcomeButtonConfig->objectName().isEmpty())
            DlgWelcomeButtonConfig->setObjectName(QString::fromUtf8("DlgWelcomeButtonConfig"));
        DlgWelcomeButtonConfig->resize(914, 427);
        verticalLayout = new QVBoxLayout(DlgWelcomeButtonConfig);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        w1 = new QWidget(DlgWelcomeButtonConfig);
        w1->setObjectName(QString::fromUtf8("w1"));
        horizontalLayout_2 = new QHBoxLayout(w1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnRoomChart = new EToolbarButton(w1);
        btnRoomChart->setObjectName(QString::fromUtf8("btnRoomChart"));
        btnRoomChart->setMinimumSize(QSize(0, 0));
        btnRoomChart->setMaximumSize(QSize(555, 555));
        btnRoomChart->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/analytics.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRoomChart->setIcon(icon);
        btnRoomChart->setIconSize(QSize(32, 32));
        btnRoomChart->setCheckable(true);
        btnRoomChart->setChecked(true);
        btnRoomChart->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnRoomChart->setAutoRaise(true);
        btnRoomChart->setArrowType(Qt::NoArrow);

        horizontalLayout_2->addWidget(btnRoomChart);

        btnNewReservation = new EToolbarButton(w1);
        btnNewReservation->setObjectName(QString::fromUtf8("btnNewReservation"));
        btnNewReservation->setMinimumSize(QSize(0, 0));
        btnNewReservation->setMaximumSize(QSize(555, 555));
        btnNewReservation->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/checkin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNewReservation->setIcon(icon1);
        btnNewReservation->setIconSize(QSize(32, 32));
        btnNewReservation->setCheckable(true);
        btnNewReservation->setChecked(true);
        btnNewReservation->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnNewReservation->setAutoRaise(true);

        horizontalLayout_2->addWidget(btnNewReservation);

        btnNewGroupResevation = new EToolbarButton(w1);
        btnNewGroupResevation->setObjectName(QString::fromUtf8("btnNewGroupResevation"));
        btnNewGroupResevation->setMinimumSize(QSize(0, 0));
        btnNewGroupResevation->setMaximumSize(QSize(555, 555));
        btnNewGroupResevation->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/groupreservation.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNewGroupResevation->setIcon(icon2);
        btnNewGroupResevation->setIconSize(QSize(32, 32));
        btnNewGroupResevation->setCheckable(true);
        btnNewGroupResevation->setChecked(true);
        btnNewGroupResevation->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnNewGroupResevation->setAutoRaise(true);

        horizontalLayout_2->addWidget(btnNewGroupResevation);

        btnHotelStatus = new EToolbarButton(w1);
        btnHotelStatus->setObjectName(QString::fromUtf8("btnHotelStatus"));
        btnHotelStatus->setMinimumSize(QSize(0, 0));
        btnHotelStatus->setMaximumSize(QSize(555, 555));
        btnHotelStatus->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHotelStatus->setIcon(icon3);
        btnHotelStatus->setIconSize(QSize(32, 32));
        btnHotelStatus->setCheckable(true);
        btnHotelStatus->setChecked(true);
        btnHotelStatus->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnHotelStatus->setAutoRaise(true);
        btnHotelStatus->setArrowType(Qt::NoArrow);

        horizontalLayout_2->addWidget(btnHotelStatus);

        btnInhouseGuest = new EToolbarButton(w1);
        btnInhouseGuest->setObjectName(QString::fromUtf8("btnInhouseGuest"));
        btnInhouseGuest->setMinimumSize(QSize(0, 0));
        btnInhouseGuest->setMaximumSize(QSize(555, 555));
        btnInhouseGuest->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/bed.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnInhouseGuest->setIcon(icon4);
        btnInhouseGuest->setIconSize(QSize(32, 32));
        btnInhouseGuest->setCheckable(true);
        btnInhouseGuest->setChecked(true);
        btnInhouseGuest->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnInhouseGuest->setAutoRaise(true);

        horizontalLayout_2->addWidget(btnInhouseGuest);

        btnReservations = new EToolbarButton(w1);
        btnReservations->setObjectName(QString::fromUtf8("btnReservations"));
        btnReservations->setMinimumSize(QSize(0, 0));
        btnReservations->setMaximumSize(QSize(555, 555));
        btnReservations->setFocusPolicy(Qt::NoFocus);
        btnReservations->setIcon(icon4);
        btnReservations->setIconSize(QSize(32, 32));
        btnReservations->setCheckable(true);
        btnReservations->setChecked(true);
        btnReservations->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnReservations->setAutoRaise(true);

        horizontalLayout_2->addWidget(btnReservations);

        btnArrivalDeparture = new EToolbarButton(w1);
        btnArrivalDeparture->setObjectName(QString::fromUtf8("btnArrivalDeparture"));
        btnArrivalDeparture->setMinimumSize(QSize(0, 0));
        btnArrivalDeparture->setMaximumSize(QSize(555, 555));
        btnArrivalDeparture->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/arrival.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnArrivalDeparture->setIcon(icon5);
        btnArrivalDeparture->setIconSize(QSize(32, 32));
        btnArrivalDeparture->setCheckable(true);
        btnArrivalDeparture->setChecked(true);
        btnArrivalDeparture->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnArrivalDeparture->setAutoRaise(true);

        horizontalLayout_2->addWidget(btnArrivalDeparture);

        btnArrivalDeparture_2 = new EToolbarButton(w1);
        btnArrivalDeparture_2->setObjectName(QString::fromUtf8("btnArrivalDeparture_2"));
        btnArrivalDeparture_2->setMinimumSize(QSize(0, 0));
        btnArrivalDeparture_2->setMaximumSize(QSize(555, 555));
        btnArrivalDeparture_2->setFocusPolicy(Qt::NoFocus);
        btnArrivalDeparture_2->setIcon(icon5);
        btnArrivalDeparture_2->setIconSize(QSize(32, 32));
        btnArrivalDeparture_2->setCheckable(true);
        btnArrivalDeparture_2->setChecked(true);
        btnArrivalDeparture_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnArrivalDeparture_2->setAutoRaise(true);

        horizontalLayout_2->addWidget(btnArrivalDeparture_2);

        btnCheckoutInvoices = new EToolbarButton(w1);
        btnCheckoutInvoices->setObjectName(QString::fromUtf8("btnCheckoutInvoices"));
        btnCheckoutInvoices->setMinimumSize(QSize(0, 0));
        btnCheckoutInvoices->setMaximumSize(QSize(555, 555));
        btnCheckoutInvoices->setFocusPolicy(Qt::NoFocus);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/invoice.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCheckoutInvoices->setIcon(icon6);
        btnCheckoutInvoices->setIconSize(QSize(32, 32));
        btnCheckoutInvoices->setCheckable(true);
        btnCheckoutInvoices->setChecked(true);
        btnCheckoutInvoices->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnCheckoutInvoices->setAutoRaise(true);
        btnCheckoutInvoices->setArrowType(Qt::NoArrow);

        horizontalLayout_2->addWidget(btnCheckoutInvoices);

        btnVauchers = new EToolbarButton(w1);
        btnVauchers->setObjectName(QString::fromUtf8("btnVauchers"));
        btnVauchers->setMinimumSize(QSize(0, 0));
        btnVauchers->setMaximumSize(QSize(555, 555));
        btnVauchers->setFocusPolicy(Qt::NoFocus);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnVauchers->setIcon(icon7);
        btnVauchers->setIconSize(QSize(32, 32));
        btnVauchers->setCheckable(true);
        btnVauchers->setChecked(true);
        btnVauchers->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnVauchers->setAutoRaise(true);
        btnVauchers->setArrowType(Qt::NoArrow);

        horizontalLayout_2->addWidget(btnVauchers);

        btnCallHistory = new EToolbarButton(w1);
        btnCallHistory->setObjectName(QString::fromUtf8("btnCallHistory"));
        btnCallHistory->setMinimumSize(QSize(0, 0));
        btnCallHistory->setMaximumSize(QSize(555, 555));
        btnCallHistory->setFocusPolicy(Qt::NoFocus);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/phone-call.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCallHistory->setIcon(icon8);
        btnCallHistory->setIconSize(QSize(32, 32));
        btnCallHistory->setCheckable(true);
        btnCallHistory->setChecked(true);
        btnCallHistory->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnCallHistory->setAutoRaise(true);

        horizontalLayout_2->addWidget(btnCallHistory);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(w1);

        w4 = new QWidget(DlgWelcomeButtonConfig);
        w4->setObjectName(QString::fromUtf8("w4"));
        horizontalLayout_5 = new QHBoxLayout(w4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btnArrivalsSimple = new EToolbarButton(w4);
        btnArrivalsSimple->setObjectName(QString::fromUtf8("btnArrivalsSimple"));
        btnArrivalsSimple->setMinimumSize(QSize(0, 0));
        btnArrivalsSimple->setMaximumSize(QSize(555, 555));
        btnArrivalsSimple->setFocusPolicy(Qt::NoFocus);
        btnArrivalsSimple->setIcon(icon5);
        btnArrivalsSimple->setIconSize(QSize(32, 32));
        btnArrivalsSimple->setCheckable(true);
        btnArrivalsSimple->setChecked(true);
        btnArrivalsSimple->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnArrivalsSimple->setAutoRaise(true);

        horizontalLayout_5->addWidget(btnArrivalsSimple);

        btnDeparutersSimple = new EToolbarButton(w4);
        btnDeparutersSimple->setObjectName(QString::fromUtf8("btnDeparutersSimple"));
        btnDeparutersSimple->setMinimumSize(QSize(0, 0));
        btnDeparutersSimple->setMaximumSize(QSize(555, 555));
        btnDeparutersSimple->setFocusPolicy(Qt::NoFocus);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/departure.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDeparutersSimple->setIcon(icon9);
        btnDeparutersSimple->setIconSize(QSize(32, 32));
        btnDeparutersSimple->setCheckable(true);
        btnDeparutersSimple->setChecked(true);
        btnDeparutersSimple->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnDeparutersSimple->setAutoRaise(true);

        horizontalLayout_5->addWidget(btnDeparutersSimple);

        btnWakeupCalls = new EToolbarButton(w4);
        btnWakeupCalls->setObjectName(QString::fromUtf8("btnWakeupCalls"));
        btnWakeupCalls->setMinimumSize(QSize(0, 0));
        btnWakeupCalls->setMaximumSize(QSize(555, 555));
        btnWakeupCalls->setFocusPolicy(Qt::NoFocus);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/alarm.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWakeupCalls->setIcon(icon10);
        btnWakeupCalls->setIconSize(QSize(32, 32));
        btnWakeupCalls->setCheckable(true);
        btnWakeupCalls->setChecked(true);
        btnWakeupCalls->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnWakeupCalls->setAutoRaise(true);
        btnWakeupCalls->setArrowType(Qt::NoArrow);

        horizontalLayout_5->addWidget(btnWakeupCalls);

        btnDailyTransactions = new EToolbarButton(w4);
        btnDailyTransactions->setObjectName(QString::fromUtf8("btnDailyTransactions"));
        btnDailyTransactions->setMinimumSize(QSize(0, 0));
        btnDailyTransactions->setMaximumSize(QSize(555, 555));
        btnDailyTransactions->setFocusPolicy(Qt::NoFocus);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/category.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDailyTransactions->setIcon(icon11);
        btnDailyTransactions->setIconSize(QSize(32, 32));
        btnDailyTransactions->setCheckable(true);
        btnDailyTransactions->setChecked(true);
        btnDailyTransactions->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnDailyTransactions->setAutoRaise(true);
        btnDailyTransactions->setArrowType(Qt::NoArrow);

        horizontalLayout_5->addWidget(btnDailyTransactions);

        btnRemarks = new EToolbarButton(w4);
        btnRemarks->setObjectName(QString::fromUtf8("btnRemarks"));
        btnRemarks->setMinimumSize(QSize(0, 0));
        btnRemarks->setMaximumSize(QSize(555, 555));
        btnRemarks->setFocusPolicy(Qt::NoFocus);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/remarks.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemarks->setIcon(icon12);
        btnRemarks->setIconSize(QSize(32, 32));
        btnRemarks->setCheckable(true);
        btnRemarks->setChecked(true);
        btnRemarks->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnRemarks->setAutoRaise(true);
        btnRemarks->setArrowType(Qt::NoArrow);

        horizontalLayout_5->addWidget(btnRemarks);

        btnContacts = new EToolbarButton(w4);
        btnContacts->setObjectName(QString::fromUtf8("btnContacts"));
        btnContacts->setMinimumSize(QSize(0, 0));
        btnContacts->setMaximumSize(QSize(555, 555));
        btnContacts->setFocusPolicy(Qt::NoFocus);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/phone-book.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnContacts->setIcon(icon13);
        btnContacts->setIconSize(QSize(32, 32));
        btnContacts->setCheckable(true);
        btnContacts->setChecked(true);
        btnContacts->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnContacts->setAutoRaise(true);

        horizontalLayout_5->addWidget(btnContacts);

        btnHotelHierarchy = new EToolbarButton(w4);
        btnHotelHierarchy->setObjectName(QString::fromUtf8("btnHotelHierarchy"));
        btnHotelHierarchy->setMinimumSize(QSize(0, 0));
        btnHotelHierarchy->setMaximumSize(QSize(555, 555));
        btnHotelHierarchy->setFocusPolicy(Qt::NoFocus);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/hierarchy.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHotelHierarchy->setIcon(icon14);
        btnHotelHierarchy->setIconSize(QSize(32, 32));
        btnHotelHierarchy->setCheckable(true);
        btnHotelHierarchy->setChecked(true);
        btnHotelHierarchy->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnHotelHierarchy->setAutoRaise(true);
        btnHotelHierarchy->setArrowType(Qt::NoArrow);

        horizontalLayout_5->addWidget(btnHotelHierarchy);

        btnRoomStateTouch = new EToolbarButton(w4);
        btnRoomStateTouch->setObjectName(QString::fromUtf8("btnRoomStateTouch"));
        btnRoomStateTouch->setMinimumSize(QSize(0, 0));
        btnRoomStateTouch->setMaximumSize(QSize(555, 555));
        btnRoomStateTouch->setFocusPolicy(Qt::NoFocus);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/window.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRoomStateTouch->setIcon(icon15);
        btnRoomStateTouch->setIconSize(QSize(32, 32));
        btnRoomStateTouch->setCheckable(true);
        btnRoomStateTouch->setChecked(true);
        btnRoomStateTouch->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnRoomStateTouch->setAutoRaise(true);
        btnRoomStateTouch->setArrowType(Qt::NoArrow);

        horizontalLayout_5->addWidget(btnRoomStateTouch);

        horizontalSpacer_6 = new QSpacerItem(438, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout->addWidget(w4);

        w2 = new QWidget(DlgWelcomeButtonConfig);
        w2->setObjectName(QString::fromUtf8("w2"));
        horizontalLayout_3 = new QHBoxLayout(w2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnDailyMovement = new EToolbarButton(w2);
        btnDailyMovement->setObjectName(QString::fromUtf8("btnDailyMovement"));
        btnDailyMovement->setMinimumSize(QSize(0, 0));
        btnDailyMovement->setMaximumSize(QSize(555, 555));
        btnDailyMovement->setFocusPolicy(Qt::NoFocus);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/graph.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDailyMovement->setIcon(icon16);
        btnDailyMovement->setIconSize(QSize(32, 32));
        btnDailyMovement->setCheckable(true);
        btnDailyMovement->setChecked(true);
        btnDailyMovement->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnDailyMovement->setAutoRaise(true);
        btnDailyMovement->setArrowType(Qt::NoArrow);

        horizontalLayout_3->addWidget(btnDailyMovement);

        btnMonthlyMovement = new EToolbarButton(w2);
        btnMonthlyMovement->setObjectName(QString::fromUtf8("btnMonthlyMovement"));
        btnMonthlyMovement->setMinimumSize(QSize(0, 0));
        btnMonthlyMovement->setMaximumSize(QSize(555, 555));
        btnMonthlyMovement->setFocusPolicy(Qt::NoFocus);
        btnMonthlyMovement->setIcon(icon16);
        btnMonthlyMovement->setIconSize(QSize(32, 32));
        btnMonthlyMovement->setCheckable(true);
        btnMonthlyMovement->setChecked(true);
        btnMonthlyMovement->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnMonthlyMovement->setAutoRaise(true);
        btnMonthlyMovement->setArrowType(Qt::NoArrow);

        horizontalLayout_3->addWidget(btnMonthlyMovement);

        btnCityLedgerDetailedBalance = new EToolbarButton(w2);
        btnCityLedgerDetailedBalance->setObjectName(QString::fromUtf8("btnCityLedgerDetailedBalance"));
        btnCityLedgerDetailedBalance->setMinimumSize(QSize(0, 0));
        btnCityLedgerDetailedBalance->setMaximumSize(QSize(555, 555));
        btnCityLedgerDetailedBalance->setFocusPolicy(Qt::NoFocus);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/balance.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCityLedgerDetailedBalance->setIcon(icon17);
        btnCityLedgerDetailedBalance->setIconSize(QSize(32, 32));
        btnCityLedgerDetailedBalance->setCheckable(true);
        btnCityLedgerDetailedBalance->setChecked(true);
        btnCityLedgerDetailedBalance->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnCityLedgerDetailedBalance->setAutoRaise(true);
        btnCityLedgerDetailedBalance->setArrowType(Qt::NoArrow);

        horizontalLayout_3->addWidget(btnCityLedgerDetailedBalance);

        btnCashReportSummary = new EToolbarButton(w2);
        btnCashReportSummary->setObjectName(QString::fromUtf8("btnCashReportSummary"));
        btnCashReportSummary->setMinimumSize(QSize(0, 0));
        btnCashReportSummary->setMaximumSize(QSize(555, 555));
        btnCashReportSummary->setFocusPolicy(Qt::NoFocus);
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/images/money.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCashReportSummary->setIcon(icon18);
        btnCashReportSummary->setIconSize(QSize(32, 32));
        btnCashReportSummary->setCheckable(true);
        btnCashReportSummary->setChecked(true);
        btnCashReportSummary->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnCashReportSummary->setAutoRaise(true);
        btnCashReportSummary->setArrowType(Qt::NoArrow);

        horizontalLayout_3->addWidget(btnCashReportSummary);

        btnCashReportDetailed = new EToolbarButton(w2);
        btnCashReportDetailed->setObjectName(QString::fromUtf8("btnCashReportDetailed"));
        btnCashReportDetailed->setMinimumSize(QSize(0, 0));
        btnCashReportDetailed->setMaximumSize(QSize(555, 555));
        btnCashReportDetailed->setFocusPolicy(Qt::NoFocus);
        btnCashReportDetailed->setIcon(icon18);
        btnCashReportDetailed->setIconSize(QSize(32, 32));
        btnCashReportDetailed->setCheckable(true);
        btnCashReportDetailed->setChecked(true);
        btnCashReportDetailed->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnCashReportDetailed->setAutoRaise(true);
        btnCashReportDetailed->setArrowType(Qt::NoArrow);

        horizontalLayout_3->addWidget(btnCashReportDetailed);

        btnRestaurant = new EToolbarButton(w2);
        btnRestaurant->setObjectName(QString::fromUtf8("btnRestaurant"));
        btnRestaurant->setMinimumSize(QSize(0, 0));
        btnRestaurant->setMaximumSize(QSize(555, 555));
        btnRestaurant->setFocusPolicy(Qt::NoFocus);
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/images/cutlery.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRestaurant->setIcon(icon19);
        btnRestaurant->setIconSize(QSize(32, 32));
        btnRestaurant->setCheckable(true);
        btnRestaurant->setChecked(true);
        btnRestaurant->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnRestaurant->setAutoRaise(true);
        btnRestaurant->setArrowType(Qt::NoArrow);

        horizontalLayout_3->addWidget(btnRestaurant);

        btnCardexAnalysis = new EToolbarButton(w2);
        btnCardexAnalysis->setObjectName(QString::fromUtf8("btnCardexAnalysis"));
        btnCardexAnalysis->setMinimumSize(QSize(0, 0));
        btnCardexAnalysis->setMaximumSize(QSize(555, 555));
        btnCardexAnalysis->setFocusPolicy(Qt::NoFocus);
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/images/partner.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCardexAnalysis->setIcon(icon20);
        btnCardexAnalysis->setIconSize(QSize(32, 32));
        btnCardexAnalysis->setCheckable(true);
        btnCardexAnalysis->setChecked(true);
        btnCardexAnalysis->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnCardexAnalysis->setAutoRaise(true);
        btnCardexAnalysis->setArrowType(Qt::NoArrow);

        horizontalLayout_3->addWidget(btnCardexAnalysis);

        btnReportSet = new EToolbarButton(w2);
        btnReportSet->setObjectName(QString::fromUtf8("btnReportSet"));
        btnReportSet->setMinimumSize(QSize(0, 0));
        btnReportSet->setMaximumSize(QSize(555, 555));
        btnReportSet->setFocusPolicy(Qt::NoFocus);
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/images/reports.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnReportSet->setIcon(icon21);
        btnReportSet->setIconSize(QSize(32, 32));
        btnReportSet->setCheckable(true);
        btnReportSet->setChecked(true);
        btnReportSet->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnReportSet->setAutoRaise(true);
        btnReportSet->setArrowType(Qt::NoArrow);

        horizontalLayout_3->addWidget(btnReportSet);

        btnStatistics = new EToolbarButton(w2);
        btnStatistics->setObjectName(QString::fromUtf8("btnStatistics"));
        btnStatistics->setMinimumSize(QSize(0, 0));
        btnStatistics->setMaximumSize(QSize(555, 555));
        btnStatistics->setFocusPolicy(Qt::NoFocus);
        btnStatistics->setIcon(icon21);
        btnStatistics->setIconSize(QSize(32, 32));
        btnStatistics->setCheckable(true);
        btnStatistics->setChecked(true);
        btnStatistics->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnStatistics->setAutoRaise(true);
        btnStatistics->setArrowType(Qt::NoArrow);

        horizontalLayout_3->addWidget(btnStatistics);

        horizontalSpacer_5 = new QSpacerItem(438, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addWidget(w2);

        w3 = new QWidget(DlgWelcomeButtonConfig);
        w3->setObjectName(QString::fromUtf8("w3"));
        horizontalLayout_4 = new QHBoxLayout(w3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btnPostCharge = new EToolbarButton(w3);
        btnPostCharge->setObjectName(QString::fromUtf8("btnPostCharge"));
        btnPostCharge->setMinimumSize(QSize(0, 0));
        btnPostCharge->setMaximumSize(QSize(5555, 5555));
        btnPostCharge->setFocusPolicy(Qt::NoFocus);
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/images/charge.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPostCharge->setIcon(icon22);
        btnPostCharge->setIconSize(QSize(32, 32));
        btnPostCharge->setCheckable(true);
        btnPostCharge->setChecked(true);
        btnPostCharge->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnPostCharge->setAutoRaise(true);
        btnPostCharge->setArrowType(Qt::NoArrow);

        horizontalLayout_4->addWidget(btnPostCharge);

        btnReceipt = new EToolbarButton(w3);
        btnReceipt->setObjectName(QString::fromUtf8("btnReceipt"));
        btnReceipt->setMinimumSize(QSize(0, 0));
        btnReceipt->setMaximumSize(QSize(5555, 5555));
        btnReceipt->setFocusPolicy(Qt::NoFocus);
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/images/credit-card.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnReceipt->setIcon(icon23);
        btnReceipt->setIconSize(QSize(32, 32));
        btnReceipt->setCheckable(true);
        btnReceipt->setChecked(true);
        btnReceipt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnReceipt->setAutoRaise(true);

        horizontalLayout_4->addWidget(btnReceipt);

        btnAdvance = new EToolbarButton(w3);
        btnAdvance->setObjectName(QString::fromUtf8("btnAdvance"));
        btnAdvance->setMinimumSize(QSize(0, 0));
        btnAdvance->setMaximumSize(QSize(5555, 5555));
        btnAdvance->setFocusPolicy(Qt::NoFocus);
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/images/advance.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdvance->setIcon(icon24);
        btnAdvance->setIconSize(QSize(32, 32));
        btnAdvance->setCheckable(true);
        btnAdvance->setChecked(true);
        btnAdvance->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnAdvance->setAutoRaise(true);

        horizontalLayout_4->addWidget(btnAdvance);

        btnTransfer = new EToolbarButton(w3);
        btnTransfer->setObjectName(QString::fromUtf8("btnTransfer"));
        btnTransfer->setMinimumSize(QSize(0, 0));
        btnTransfer->setMaximumSize(QSize(5555, 5555));
        btnTransfer->setFocusPolicy(Qt::NoFocus);
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/images/goto.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTransfer->setIcon(icon25);
        btnTransfer->setIconSize(QSize(32, 32));
        btnTransfer->setCheckable(true);
        btnTransfer->setChecked(true);
        btnTransfer->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnTransfer->setAutoRaise(true);

        horizontalLayout_4->addWidget(btnTransfer);

        btnDiscount = new EToolbarButton(w3);
        btnDiscount->setObjectName(QString::fromUtf8("btnDiscount"));
        btnDiscount->setMinimumSize(QSize(0, 0));
        btnDiscount->setMaximumSize(QSize(5555, 5555));
        btnDiscount->setFocusPolicy(Qt::NoFocus);
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/images/discount.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDiscount->setIcon(icon26);
        btnDiscount->setIconSize(QSize(32, 32));
        btnDiscount->setCheckable(true);
        btnDiscount->setChecked(true);
        btnDiscount->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnDiscount->setAutoRaise(true);

        horizontalLayout_4->addWidget(btnDiscount);

        btnOnlineInvoice = new EToolbarButton(w3);
        btnOnlineInvoice->setObjectName(QString::fromUtf8("btnOnlineInvoice"));
        btnOnlineInvoice->setMinimumSize(QSize(0, 0));
        btnOnlineInvoice->setMaximumSize(QSize(5555, 5555));
        btnOnlineInvoice->setFocusPolicy(Qt::NoFocus);
        btnOnlineInvoice->setIcon(icon6);
        btnOnlineInvoice->setIconSize(QSize(32, 32));
        btnOnlineInvoice->setCheckable(true);
        btnOnlineInvoice->setChecked(true);
        btnOnlineInvoice->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnOnlineInvoice->setAutoRaise(true);

        horizontalLayout_4->addWidget(btnOnlineInvoice);

        btnExportInvoices = new EToolbarButton(w3);
        btnExportInvoices->setObjectName(QString::fromUtf8("btnExportInvoices"));
        btnExportInvoices->setMinimumSize(QSize(0, 0));
        btnExportInvoices->setMaximumSize(QSize(5555, 5555));
        btnExportInvoices->setFocusPolicy(Qt::NoFocus);
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/images/database.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExportInvoices->setIcon(icon27);
        btnExportInvoices->setIconSize(QSize(32, 32));
        btnExportInvoices->setCheckable(true);
        btnExportInvoices->setChecked(true);
        btnExportInvoices->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnExportInvoices->setAutoRaise(true);

        horizontalLayout_4->addWidget(btnExportInvoices);

        btnExportRestaurant = new EToolbarButton(w3);
        btnExportRestaurant->setObjectName(QString::fromUtf8("btnExportRestaurant"));
        btnExportRestaurant->setMinimumSize(QSize(0, 0));
        btnExportRestaurant->setMaximumSize(QSize(5555, 5555));
        btnExportRestaurant->setFocusPolicy(Qt::NoFocus);
        btnExportRestaurant->setIcon(icon27);
        btnExportRestaurant->setIconSize(QSize(32, 32));
        btnExportRestaurant->setCheckable(true);
        btnExportRestaurant->setChecked(true);
        btnExportRestaurant->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnExportRestaurant->setAutoRaise(true);

        horizontalLayout_4->addWidget(btnExportRestaurant);

        btnExportActiveReservation = new EToolbarButton(w3);
        btnExportActiveReservation->setObjectName(QString::fromUtf8("btnExportActiveReservation"));
        btnExportActiveReservation->setMinimumSize(QSize(0, 0));
        btnExportActiveReservation->setMaximumSize(QSize(5555, 5555));
        btnExportActiveReservation->setFocusPolicy(Qt::NoFocus);
        btnExportActiveReservation->setIcon(icon27);
        btnExportActiveReservation->setIconSize(QSize(32, 32));
        btnExportActiveReservation->setCheckable(true);
        btnExportActiveReservation->setChecked(true);
        btnExportActiveReservation->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnExportActiveReservation->setAutoRaise(true);

        horizontalLayout_4->addWidget(btnExportActiveReservation);

        btnNotes = new EToolbarButton(w3);
        btnNotes->setObjectName(QString::fromUtf8("btnNotes"));
        btnNotes->setMinimumSize(QSize(0, 0));
        btnNotes->setMaximumSize(QSize(555, 555));
        btnNotes->setFocusPolicy(Qt::NoFocus);
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/images/notepad.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNotes->setIcon(icon28);
        btnNotes->setIconSize(QSize(32, 32));
        btnNotes->setCheckable(true);
        btnNotes->setChecked(true);
        btnNotes->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnNotes->setAutoRaise(true);

        horizontalLayout_4->addWidget(btnNotes);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(w3);

        widget = new QWidget(DlgWelcomeButtonConfig);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(btnOk, btnCancel);
        QWidget::setTabOrder(btnCancel, btnRoomChart);
        QWidget::setTabOrder(btnRoomChart, btnDiscount);
        QWidget::setTabOrder(btnDiscount, btnCallHistory);
        QWidget::setTabOrder(btnCallHistory, btnTransfer);
        QWidget::setTabOrder(btnTransfer, btnExportInvoices);
        QWidget::setTabOrder(btnExportInvoices, btnCashReportSummary);
        QWidget::setTabOrder(btnCashReportSummary, btnCityLedgerDetailedBalance);
        QWidget::setTabOrder(btnCityLedgerDetailedBalance, btnCashReportDetailed);
        QWidget::setTabOrder(btnCashReportDetailed, btnAdvance);
        QWidget::setTabOrder(btnAdvance, btnReceipt);
        QWidget::setTabOrder(btnReceipt, btnMonthlyMovement);
        QWidget::setTabOrder(btnMonthlyMovement, btnNewGroupResevation);
        QWidget::setTabOrder(btnNewGroupResevation, btnCheckoutInvoices);
        QWidget::setTabOrder(btnCheckoutInvoices, btnDailyMovement);
        QWidget::setTabOrder(btnDailyMovement, btnVauchers);
        QWidget::setTabOrder(btnVauchers, btnNewReservation);
        QWidget::setTabOrder(btnNewReservation, btnPostCharge);

        retranslateUi(DlgWelcomeButtonConfig);

        QMetaObject::connectSlotsByName(DlgWelcomeButtonConfig);
    } // setupUi

    void retranslateUi(QDialog *DlgWelcomeButtonConfig)
    {
        DlgWelcomeButtonConfig->setWindowTitle(QCoreApplication::translate("DlgWelcomeButtonConfig", "Configure buttons", nullptr));
        btnRoomChart->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Room chart", nullptr));
        btnRoomChart->setProperty("Tag", QVariant(QString()));
        btnNewReservation->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "New\n"
"reservation", nullptr));
        btnNewReservation->setProperty("Tag", QVariant(QString()));
        btnNewGroupResevation->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "New group\n"
"reservation", nullptr));
        btnNewGroupResevation->setProperty("Tag", QVariant(QString()));
        btnHotelStatus->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Hotel\n"
"Status", nullptr));
        btnHotelStatus->setProperty("Tag", QVariant(QString()));
        btnInhouseGuest->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Guests \n"
"in house", nullptr));
        btnInhouseGuest->setProperty("Tag", QVariant(QString()));
        btnReservations->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Reservations", nullptr));
        btnReservations->setProperty("Tag", QVariant(QString()));
        btnArrivalDeparture->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Arrivals\n"
"departures", nullptr));
        btnArrivalDeparture->setProperty("Tag", QVariant(QString()));
        btnArrivalDeparture_2->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Arrivals\n"
"departures 2", nullptr));
        btnArrivalDeparture_2->setProperty("Tag", QVariant(QString()));
        btnCheckoutInvoices->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Checkout\n"
"Invoices", nullptr));
        btnCheckoutInvoices->setProperty("Tag", QVariant(QString()));
        btnVauchers->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Vouchers", nullptr));
        btnVauchers->setProperty("Tag", QVariant(QString()));
        btnCallHistory->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Daily calls", nullptr));
        btnCallHistory->setProperty("Tag", QVariant(QString()));
        btnArrivalsSimple->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Arrivals\n"
"simple", nullptr));
        btnArrivalsSimple->setProperty("Tag", QVariant(QString()));
        btnDeparutersSimple->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Departures\n"
"simple", nullptr));
        btnDeparutersSimple->setProperty("Tag", QVariant(QString()));
        btnWakeupCalls->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Wakeup\n"
"calls", nullptr));
        btnWakeupCalls->setProperty("Tag", QVariant(QString()));
        btnDailyTransactions->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Daily\n"
"Transactions", nullptr));
        btnDailyTransactions->setProperty("Tag", QVariant(QString()));
        btnRemarks->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Remarks", nullptr));
        btnRemarks->setProperty("Tag", QVariant(QString()));
        btnContacts->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Contacts", nullptr));
        btnContacts->setProperty("Tag", QVariant(QString()));
        btnHotelHierarchy->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Hotel\n"
"hierarchy", nullptr));
        btnHotelHierarchy->setProperty("Tag", QVariant(QString()));
        btnRoomStateTouch->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Room\n"
"states", nullptr));
        btnRoomStateTouch->setProperty("Tag", QVariant(QString()));
        btnDailyMovement->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Daily\n"
"Movement", nullptr));
        btnDailyMovement->setProperty("Tag", QVariant(QString()));
        btnMonthlyMovement->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Monthly\n"
"Movement", nullptr));
        btnMonthlyMovement->setProperty("Tag", QVariant(QString()));
        btnCityLedgerDetailedBalance->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "City Ledger\n"
"detailed ", nullptr));
        btnCityLedgerDetailedBalance->setProperty("Tag", QVariant(QString()));
        btnCashReportSummary->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Cash report\n"
"Summary", nullptr));
        btnCashReportSummary->setProperty("Tag", QVariant(QString()));
        btnCashReportDetailed->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Cash report\n"
"Detailed", nullptr));
        btnCashReportDetailed->setProperty("Tag", QVariant(QString()));
        btnRestaurant->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Restaurant", nullptr));
        btnRestaurant->setProperty("Tag", QVariant(QString()));
        btnCardexAnalysis->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Cardex\n"
"Analysis", nullptr));
        btnCardexAnalysis->setProperty("Tag", QVariant(QString()));
        btnReportSet->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Reports\n"
"Set", nullptr));
        btnReportSet->setProperty("Tag", QVariant(QString()));
        btnStatistics->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Statistics", nullptr));
        btnStatistics->setProperty("Tag", QVariant(QString()));
        btnPostCharge->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Posting\n"
"charge", nullptr));
        btnPostCharge->setProperty("Tag", QVariant(QString()));
        btnReceipt->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Receipt\n"
"voucher", nullptr));
        btnReceipt->setProperty("Tag", QVariant(QString()));
        btnAdvance->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Advance\n"
"voucher", nullptr));
        btnAdvance->setProperty("Tag", QVariant(QString()));
        btnTransfer->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Transfer\n"
"voucher", nullptr));
        btnTransfer->setProperty("Tag", QVariant(QString()));
        btnDiscount->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Discount\n"
"voucher", nullptr));
        btnDiscount->setProperty("Tag", QVariant(QString()));
        btnOnlineInvoice->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Check in\n"
"Invoices", nullptr));
        btnOnlineInvoice->setProperty("Tag", QVariant(QString()));
        btnExportInvoices->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Export\n"
"invoices", nullptr));
        btnExportInvoices->setProperty("Tag", QVariant(QString()));
        btnExportRestaurant->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Export\n"
"restaurant", nullptr));
        btnExportRestaurant->setProperty("Tag", QVariant(QString()));
        btnExportActiveReservation->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Export active\n"
"reservations", nullptr));
        btnExportActiveReservation->setProperty("Tag", QVariant(QString()));
        btnNotes->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Reminder", nullptr));
        btnNotes->setProperty("Tag", QVariant(QString()));
        btnOk->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgWelcomeButtonConfig", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgWelcomeButtonConfig: public Ui_DlgWelcomeButtonConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGWELCOMEBUTTONCONFIG_H
