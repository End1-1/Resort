/********************************************************************************
** Form generated from reading UI file 'wwelcome.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WWELCOME_H
#define UI_WWELCOME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <etoolbarbutton.h>

QT_BEGIN_NAMESPACE

class Ui_WWelcome
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabInfo;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tblArrival;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tblBirthDay;
    QWidget *wLogo;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lbLogo;
    QSpacerItem *horizontalSpacer;
    QWidget *wv1;
    QHBoxLayout *wl1;
    QHBoxLayout *wl1_2;
    QWidget *wslogan;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbSlogan;
    QWidget *w1;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    EToolbarButton *btnRoomChart;
    EToolbarButton *btnNewReservation;
    EToolbarButton *btnNewGroupResevation;
    EToolbarButton *btnHotelStatus;
    EToolbarButton *btnReservations;
    EToolbarButton *btnInhouseGuest;
    EToolbarButton *btnArrivalDeparture;
    EToolbarButton *btnArrivalDeparture_2;
    EToolbarButton *btnCheckoutInvoices;
    EToolbarButton *btnVauchers;
    EToolbarButton *btnCallHistory;
    QSpacerItem *horizontalSpacer_2;
    QWidget *w2;
    QHBoxLayout *horizontalLayout_3;
    EToolbarButton *btnAdvance;
    EToolbarButton *btnAdvance_2;
    EToolbarButton *btnPostCharge;
    EToolbarButton *btnDiscount;
    EToolbarButton *btnTransferAmount;
    EToolbarButton *btnOnlineInvoice;
    EToolbarButton *btnExportInvoices;
    EToolbarButton *btnExportRestaurant;
    EToolbarButton *btnExportActiveReservation;
    EToolbarButton *btnNotes;
    EToolbarButton *btnButtonsConfig;
    QWidget *w3;
    QHBoxLayout *horizontalLayout_5;
    EToolbarButton *btnCityLedgerDetailedBalance;
    EToolbarButton *btnDailyMovement;
    EToolbarButton *btnMonthlyMovement;
    EToolbarButton *btnCashReportSummary;
    EToolbarButton *btnCashReportDetailed;
    EToolbarButton *btnCardexAnalysis;
    EToolbarButton *btnRestaurant;
    EToolbarButton *btnReportsSet;
    EToolbarButton *btnStatistic;
    QWidget *wv2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *wl2;
    QWidget *w4;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_10;
    EToolbarButton *btnArrivalsSimple;
    EToolbarButton *btnDeparutersSimple;
    EToolbarButton *btnNewRoomChart;
    EToolbarButton *btnWakupCalls;
    EToolbarButton *btnDailyTransactions;
    EToolbarButton *btnRemarks;
    EToolbarButton *btnContacts;
    EToolbarButton *btnHotelHierarchy;
    EToolbarButton *btnRoomStateTouch;
    QSpacerItem *horizontalSpacer_9;

    void setupUi(QWidget *WWelcome)
    {
        if (WWelcome->objectName().isEmpty())
            WWelcome->setObjectName(QString::fromUtf8("WWelcome"));
        WWelcome->resize(1243, 610);
        horizontalLayout = new QHBoxLayout(WWelcome);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(WWelcome);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabInfo = new QTabWidget(widget);
        tabInfo->setObjectName(QString::fromUtf8("tabInfo"));
        tabInfo->setMinimumSize(QSize(360, 0));
        tabInfo->setMaximumSize(QSize(360, 16777215));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tblArrival = new QTableWidget(tab_2);
        if (tblArrival->columnCount() < 4)
            tblArrival->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblArrival->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblArrival->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblArrival->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblArrival->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tblArrival->setObjectName(QString::fromUtf8("tblArrival"));
        tblArrival->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblArrival->setSelectionMode(QAbstractItemView::NoSelection);
        tblArrival->verticalHeader()->setVisible(false);

        verticalLayout_4->addWidget(tblArrival);

        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/arrival.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabInfo->addTab(tab_2, icon, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tblBirthDay = new QTableWidget(tab_3);
        if (tblBirthDay->columnCount() < 3)
            tblBirthDay->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblBirthDay->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblBirthDay->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblBirthDay->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        tblBirthDay->setObjectName(QString::fromUtf8("tblBirthDay"));
        tblBirthDay->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblBirthDay->setSelectionMode(QAbstractItemView::NoSelection);
        tblBirthDay->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(tblBirthDay);

        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/balloons.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabInfo->addTab(tab_3, icon1, QString());

        gridLayout_2->addWidget(tabInfo, 0, 2, 8, 1);

        wLogo = new QWidget(widget);
        wLogo->setObjectName(QString::fromUtf8("wLogo"));
        gridLayout = new QGridLayout(wLogo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        lbLogo = new QLabel(wLogo);
        lbLogo->setObjectName(QString::fromUtf8("lbLogo"));
        lbLogo->setMinimumSize(QSize(0, 0));
        lbLogo->setMaximumSize(QSize(400, 300));
        lbLogo->setScaledContents(true);
        lbLogo->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbLogo, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);


        gridLayout_2->addWidget(wLogo, 2, 1, 1, 1);

        wv1 = new QWidget(widget);
        wv1->setObjectName(QString::fromUtf8("wv1"));
        wl1 = new QHBoxLayout(wv1);
        wl1->setObjectName(QString::fromUtf8("wl1"));
        wl1->setContentsMargins(0, 0, 0, 0);
        wl1_2 = new QHBoxLayout();
        wl1_2->setObjectName(QString::fromUtf8("wl1_2"));

        wl1->addLayout(wl1_2);


        gridLayout_2->addWidget(wv1, 3, 1, 1, 1);

        wslogan = new QWidget(widget);
        wslogan->setObjectName(QString::fromUtf8("wslogan"));
        wslogan->setMinimumSize(QSize(0, 0));
        wslogan->setMaximumSize(QSize(16777215, 55555));
        horizontalLayout_2 = new QHBoxLayout(wslogan);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lbSlogan = new QLabel(wslogan);
        lbSlogan->setObjectName(QString::fromUtf8("lbSlogan"));
        QFont font;
        font.setPointSize(12);
        lbSlogan->setFont(font);
        lbSlogan->setFrameShape(QFrame::Box);
        lbSlogan->setFrameShadow(QFrame::Plain);
        lbSlogan->setLineWidth(1);
        lbSlogan->setMidLineWidth(0);
        lbSlogan->setAlignment(Qt::AlignCenter);
        lbSlogan->setIndent(-1);

        horizontalLayout_2->addWidget(lbSlogan);


        gridLayout_2->addWidget(wslogan, 7, 0, 1, 2);

        w1 = new QWidget(widget);
        w1->setObjectName(QString::fromUtf8("w1"));
        w1->setMinimumSize(QSize(0, 0));
        w1->setMaximumSize(QSize(16777215, 5555));
        horizontalLayout_4 = new QHBoxLayout(w1);
        horizontalLayout_4->setSpacing(1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        btnRoomChart = new EToolbarButton(w1);
        btnRoomChart->setObjectName(QString::fromUtf8("btnRoomChart"));
        btnRoomChart->setMinimumSize(QSize(70, 70));
        btnRoomChart->setMaximumSize(QSize(70, 70));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/analytics.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRoomChart->setIcon(icon2);
        btnRoomChart->setIconSize(QSize(32, 32));
        btnRoomChart->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnRoomChart->setArrowType(Qt::NoArrow);

        horizontalLayout_4->addWidget(btnRoomChart);

        btnNewReservation = new EToolbarButton(w1);
        btnNewReservation->setObjectName(QString::fromUtf8("btnNewReservation"));
        btnNewReservation->setMinimumSize(QSize(70, 70));
        btnNewReservation->setMaximumSize(QSize(70, 70));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/checkin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNewReservation->setIcon(icon3);
        btnNewReservation->setIconSize(QSize(32, 32));
        btnNewReservation->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnNewReservation);

        btnNewGroupResevation = new EToolbarButton(w1);
        btnNewGroupResevation->setObjectName(QString::fromUtf8("btnNewGroupResevation"));
        btnNewGroupResevation->setMinimumSize(QSize(70, 70));
        btnNewGroupResevation->setMaximumSize(QSize(70, 70));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/groupreservation.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNewGroupResevation->setIcon(icon4);
        btnNewGroupResevation->setIconSize(QSize(32, 32));
        btnNewGroupResevation->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnNewGroupResevation);

        btnHotelStatus = new EToolbarButton(w1);
        btnHotelStatus->setObjectName(QString::fromUtf8("btnHotelStatus"));
        btnHotelStatus->setMinimumSize(QSize(70, 70));
        btnHotelStatus->setMaximumSize(QSize(70, 70));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHotelStatus->setIcon(icon5);
        btnHotelStatus->setIconSize(QSize(32, 32));
        btnHotelStatus->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnHotelStatus->setArrowType(Qt::NoArrow);

        horizontalLayout_4->addWidget(btnHotelStatus);

        btnReservations = new EToolbarButton(w1);
        btnReservations->setObjectName(QString::fromUtf8("btnReservations"));
        btnReservations->setMinimumSize(QSize(70, 70));
        btnReservations->setMaximumSize(QSize(70, 70));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/bed.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnReservations->setIcon(icon6);
        btnReservations->setIconSize(QSize(32, 32));
        btnReservations->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnReservations);

        btnInhouseGuest = new EToolbarButton(w1);
        btnInhouseGuest->setObjectName(QString::fromUtf8("btnInhouseGuest"));
        btnInhouseGuest->setMinimumSize(QSize(70, 70));
        btnInhouseGuest->setMaximumSize(QSize(70, 70));
        btnInhouseGuest->setIcon(icon6);
        btnInhouseGuest->setIconSize(QSize(32, 32));
        btnInhouseGuest->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnInhouseGuest);

        btnArrivalDeparture = new EToolbarButton(w1);
        btnArrivalDeparture->setObjectName(QString::fromUtf8("btnArrivalDeparture"));
        btnArrivalDeparture->setMinimumSize(QSize(70, 70));
        btnArrivalDeparture->setMaximumSize(QSize(70, 70));
        btnArrivalDeparture->setIcon(icon);
        btnArrivalDeparture->setIconSize(QSize(32, 32));
        btnArrivalDeparture->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnArrivalDeparture);

        btnArrivalDeparture_2 = new EToolbarButton(w1);
        btnArrivalDeparture_2->setObjectName(QString::fromUtf8("btnArrivalDeparture_2"));
        btnArrivalDeparture_2->setMinimumSize(QSize(70, 70));
        btnArrivalDeparture_2->setMaximumSize(QSize(70, 70));
        btnArrivalDeparture_2->setIcon(icon);
        btnArrivalDeparture_2->setIconSize(QSize(32, 32));
        btnArrivalDeparture_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnArrivalDeparture_2);

        btnCheckoutInvoices = new EToolbarButton(w1);
        btnCheckoutInvoices->setObjectName(QString::fromUtf8("btnCheckoutInvoices"));
        btnCheckoutInvoices->setMinimumSize(QSize(70, 70));
        btnCheckoutInvoices->setMaximumSize(QSize(70, 70));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/invoice.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCheckoutInvoices->setIcon(icon7);
        btnCheckoutInvoices->setIconSize(QSize(32, 32));
        btnCheckoutInvoices->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnCheckoutInvoices->setArrowType(Qt::NoArrow);

        horizontalLayout_4->addWidget(btnCheckoutInvoices);

        btnVauchers = new EToolbarButton(w1);
        btnVauchers->setObjectName(QString::fromUtf8("btnVauchers"));
        btnVauchers->setMinimumSize(QSize(70, 70));
        btnVauchers->setMaximumSize(QSize(70, 70));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnVauchers->setIcon(icon8);
        btnVauchers->setIconSize(QSize(32, 32));
        btnVauchers->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnVauchers->setArrowType(Qt::NoArrow);

        horizontalLayout_4->addWidget(btnVauchers);

        btnCallHistory = new EToolbarButton(w1);
        btnCallHistory->setObjectName(QString::fromUtf8("btnCallHistory"));
        btnCallHistory->setMinimumSize(QSize(70, 70));
        btnCallHistory->setMaximumSize(QSize(70, 70));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/phone-call.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCallHistory->setIcon(icon9);
        btnCallHistory->setIconSize(QSize(32, 32));
        btnCallHistory->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnCallHistory);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        gridLayout_2->addWidget(w1, 0, 1, 1, 1);

        w2 = new QWidget(widget);
        w2->setObjectName(QString::fromUtf8("w2"));
        w2->setMinimumSize(QSize(0, 0));
        w2->setMaximumSize(QSize(5555, 55555));
        horizontalLayout_3 = new QHBoxLayout(w2);
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnAdvance = new EToolbarButton(w2);
        btnAdvance->setObjectName(QString::fromUtf8("btnAdvance"));
        btnAdvance->setMinimumSize(QSize(70, 70));
        btnAdvance->setMaximumSize(QSize(70, 70));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/advance.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdvance->setIcon(icon10);
        btnAdvance->setIconSize(QSize(32, 32));
        btnAdvance->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnAdvance);

        btnAdvance_2 = new EToolbarButton(w2);
        btnAdvance_2->setObjectName(QString::fromUtf8("btnAdvance_2"));
        btnAdvance_2->setMinimumSize(QSize(70, 70));
        btnAdvance_2->setMaximumSize(QSize(70, 70));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/credit-card.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdvance_2->setIcon(icon11);
        btnAdvance_2->setIconSize(QSize(32, 32));
        btnAdvance_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnAdvance_2);

        btnPostCharge = new EToolbarButton(w2);
        btnPostCharge->setObjectName(QString::fromUtf8("btnPostCharge"));
        btnPostCharge->setMinimumSize(QSize(70, 70));
        btnPostCharge->setMaximumSize(QSize(70, 70));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/charge.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPostCharge->setIcon(icon12);
        btnPostCharge->setIconSize(QSize(32, 32));
        btnPostCharge->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnPostCharge->setArrowType(Qt::NoArrow);

        horizontalLayout_3->addWidget(btnPostCharge);

        btnDiscount = new EToolbarButton(w2);
        btnDiscount->setObjectName(QString::fromUtf8("btnDiscount"));
        btnDiscount->setMinimumSize(QSize(70, 70));
        btnDiscount->setMaximumSize(QSize(70, 70));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/discount.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDiscount->setIcon(icon13);
        btnDiscount->setIconSize(QSize(32, 32));
        btnDiscount->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnDiscount);

        btnTransferAmount = new EToolbarButton(w2);
        btnTransferAmount->setObjectName(QString::fromUtf8("btnTransferAmount"));
        btnTransferAmount->setMinimumSize(QSize(70, 70));
        btnTransferAmount->setMaximumSize(QSize(70, 70));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/goto.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTransferAmount->setIcon(icon14);
        btnTransferAmount->setIconSize(QSize(32, 32));
        btnTransferAmount->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnTransferAmount);

        btnOnlineInvoice = new EToolbarButton(w2);
        btnOnlineInvoice->setObjectName(QString::fromUtf8("btnOnlineInvoice"));
        btnOnlineInvoice->setMinimumSize(QSize(70, 70));
        btnOnlineInvoice->setMaximumSize(QSize(70, 70));
        btnOnlineInvoice->setIcon(icon7);
        btnOnlineInvoice->setIconSize(QSize(32, 32));
        btnOnlineInvoice->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnOnlineInvoice);

        btnExportInvoices = new EToolbarButton(w2);
        btnExportInvoices->setObjectName(QString::fromUtf8("btnExportInvoices"));
        btnExportInvoices->setMinimumSize(QSize(70, 70));
        btnExportInvoices->setMaximumSize(QSize(70, 70));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/database.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExportInvoices->setIcon(icon15);
        btnExportInvoices->setIconSize(QSize(32, 32));
        btnExportInvoices->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnExportInvoices);

        btnExportRestaurant = new EToolbarButton(w2);
        btnExportRestaurant->setObjectName(QString::fromUtf8("btnExportRestaurant"));
        btnExportRestaurant->setMinimumSize(QSize(70, 70));
        btnExportRestaurant->setMaximumSize(QSize(70, 70));
        btnExportRestaurant->setIcon(icon15);
        btnExportRestaurant->setIconSize(QSize(32, 32));
        btnExportRestaurant->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnExportRestaurant);

        btnExportActiveReservation = new EToolbarButton(w2);
        btnExportActiveReservation->setObjectName(QString::fromUtf8("btnExportActiveReservation"));
        btnExportActiveReservation->setMinimumSize(QSize(70, 70));
        btnExportActiveReservation->setMaximumSize(QSize(70, 70));
        btnExportActiveReservation->setIcon(icon15);
        btnExportActiveReservation->setIconSize(QSize(32, 32));
        btnExportActiveReservation->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnExportActiveReservation);

        btnNotes = new EToolbarButton(w2);
        btnNotes->setObjectName(QString::fromUtf8("btnNotes"));
        btnNotes->setMinimumSize(QSize(70, 70));
        btnNotes->setMaximumSize(QSize(70, 70));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/notepad.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNotes->setIcon(icon16);
        btnNotes->setIconSize(QSize(32, 32));
        btnNotes->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnNotes);

        btnButtonsConfig = new EToolbarButton(w2);
        btnButtonsConfig->setObjectName(QString::fromUtf8("btnButtonsConfig"));
        btnButtonsConfig->setMinimumSize(QSize(70, 70));
        btnButtonsConfig->setMaximumSize(QSize(70, 70));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnButtonsConfig->setIcon(icon17);
        btnButtonsConfig->setIconSize(QSize(32, 32));
        btnButtonsConfig->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnButtonsConfig->setProperty("config", QVariant(true));

        horizontalLayout_3->addWidget(btnButtonsConfig);


        gridLayout_2->addWidget(w2, 6, 1, 1, 1);

        w3 = new QWidget(widget);
        w3->setObjectName(QString::fromUtf8("w3"));
        horizontalLayout_5 = new QHBoxLayout(w3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        btnCityLedgerDetailedBalance = new EToolbarButton(w3);
        btnCityLedgerDetailedBalance->setObjectName(QString::fromUtf8("btnCityLedgerDetailedBalance"));
        btnCityLedgerDetailedBalance->setMinimumSize(QSize(70, 70));
        btnCityLedgerDetailedBalance->setMaximumSize(QSize(70, 70));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/images/balance.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCityLedgerDetailedBalance->setIcon(icon18);
        btnCityLedgerDetailedBalance->setIconSize(QSize(32, 32));
        btnCityLedgerDetailedBalance->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnCityLedgerDetailedBalance->setArrowType(Qt::NoArrow);

        horizontalLayout_5->addWidget(btnCityLedgerDetailedBalance);

        btnDailyMovement = new EToolbarButton(w3);
        btnDailyMovement->setObjectName(QString::fromUtf8("btnDailyMovement"));
        btnDailyMovement->setMinimumSize(QSize(70, 70));
        btnDailyMovement->setMaximumSize(QSize(70, 70));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/images/graph.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDailyMovement->setIcon(icon19);
        btnDailyMovement->setIconSize(QSize(32, 32));
        btnDailyMovement->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnDailyMovement->setArrowType(Qt::NoArrow);

        horizontalLayout_5->addWidget(btnDailyMovement);

        btnMonthlyMovement = new EToolbarButton(w3);
        btnMonthlyMovement->setObjectName(QString::fromUtf8("btnMonthlyMovement"));
        btnMonthlyMovement->setMinimumSize(QSize(70, 70));
        btnMonthlyMovement->setMaximumSize(QSize(70, 70));
        btnMonthlyMovement->setIcon(icon19);
        btnMonthlyMovement->setIconSize(QSize(32, 32));
        btnMonthlyMovement->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnMonthlyMovement->setArrowType(Qt::NoArrow);

        horizontalLayout_5->addWidget(btnMonthlyMovement);

        btnCashReportSummary = new EToolbarButton(w3);
        btnCashReportSummary->setObjectName(QString::fromUtf8("btnCashReportSummary"));
        btnCashReportSummary->setMinimumSize(QSize(70, 70));
        btnCashReportSummary->setMaximumSize(QSize(70, 70));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/images/money.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCashReportSummary->setIcon(icon20);
        btnCashReportSummary->setIconSize(QSize(32, 32));
        btnCashReportSummary->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnCashReportSummary->setArrowType(Qt::NoArrow);

        horizontalLayout_5->addWidget(btnCashReportSummary);

        btnCashReportDetailed = new EToolbarButton(w3);
        btnCashReportDetailed->setObjectName(QString::fromUtf8("btnCashReportDetailed"));
        btnCashReportDetailed->setMinimumSize(QSize(70, 70));
        btnCashReportDetailed->setMaximumSize(QSize(70, 70));
        btnCashReportDetailed->setIcon(icon20);
        btnCashReportDetailed->setIconSize(QSize(32, 32));
        btnCashReportDetailed->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnCashReportDetailed->setArrowType(Qt::NoArrow);

        horizontalLayout_5->addWidget(btnCashReportDetailed);

        btnCardexAnalysis = new EToolbarButton(w3);
        btnCardexAnalysis->setObjectName(QString::fromUtf8("btnCardexAnalysis"));
        btnCardexAnalysis->setMinimumSize(QSize(70, 70));
        btnCardexAnalysis->setMaximumSize(QSize(70, 70));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/images/partner.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCardexAnalysis->setIcon(icon21);
        btnCardexAnalysis->setIconSize(QSize(32, 32));
        btnCardexAnalysis->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnCardexAnalysis->setArrowType(Qt::NoArrow);

        horizontalLayout_5->addWidget(btnCardexAnalysis);

        btnRestaurant = new EToolbarButton(w3);
        btnRestaurant->setObjectName(QString::fromUtf8("btnRestaurant"));
        btnRestaurant->setMinimumSize(QSize(70, 70));
        btnRestaurant->setMaximumSize(QSize(70, 70));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/images/cutlery.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRestaurant->setIcon(icon22);
        btnRestaurant->setIconSize(QSize(32, 32));
        btnRestaurant->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnRestaurant->setArrowType(Qt::NoArrow);

        horizontalLayout_5->addWidget(btnRestaurant);

        btnReportsSet = new EToolbarButton(w3);
        btnReportsSet->setObjectName(QString::fromUtf8("btnReportsSet"));
        btnReportsSet->setMinimumSize(QSize(70, 70));
        btnReportsSet->setMaximumSize(QSize(70, 70));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/images/reports.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnReportsSet->setIcon(icon23);
        btnReportsSet->setIconSize(QSize(32, 32));
        btnReportsSet->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnReportsSet->setArrowType(Qt::NoArrow);

        horizontalLayout_5->addWidget(btnReportsSet);

        btnStatistic = new EToolbarButton(w3);
        btnStatistic->setObjectName(QString::fromUtf8("btnStatistic"));
        btnStatistic->setMinimumSize(QSize(70, 70));
        btnStatistic->setMaximumSize(QSize(70, 70));
        btnStatistic->setIcon(icon23);
        btnStatistic->setIconSize(QSize(32, 32));
        btnStatistic->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnStatistic->setArrowType(Qt::NoArrow);

        horizontalLayout_5->addWidget(btnStatistic);


        gridLayout_2->addWidget(w3, 5, 1, 1, 1);

        wv2 = new QWidget(widget);
        wv2->setObjectName(QString::fromUtf8("wv2"));
        wv2->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(wv2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wl2 = new QHBoxLayout();
        wl2->setObjectName(QString::fromUtf8("wl2"));

        verticalLayout->addLayout(wl2);


        gridLayout_2->addWidget(wv2, 4, 1, 1, 1);

        w4 = new QWidget(widget);
        w4->setObjectName(QString::fromUtf8("w4"));
        horizontalLayout_8 = new QHBoxLayout(w4);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);

        btnArrivalsSimple = new EToolbarButton(w4);
        btnArrivalsSimple->setObjectName(QString::fromUtf8("btnArrivalsSimple"));
        btnArrivalsSimple->setMinimumSize(QSize(70, 70));
        btnArrivalsSimple->setMaximumSize(QSize(70, 70));
        btnArrivalsSimple->setIcon(icon);
        btnArrivalsSimple->setIconSize(QSize(32, 32));
        btnArrivalsSimple->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_8->addWidget(btnArrivalsSimple);

        btnDeparutersSimple = new EToolbarButton(w4);
        btnDeparutersSimple->setObjectName(QString::fromUtf8("btnDeparutersSimple"));
        btnDeparutersSimple->setMinimumSize(QSize(70, 70));
        btnDeparutersSimple->setMaximumSize(QSize(70, 70));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/images/departure.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDeparutersSimple->setIcon(icon24);
        btnDeparutersSimple->setIconSize(QSize(32, 32));
        btnDeparutersSimple->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_8->addWidget(btnDeparutersSimple);

        btnNewRoomChart = new EToolbarButton(w4);
        btnNewRoomChart->setObjectName(QString::fromUtf8("btnNewRoomChart"));
        btnNewRoomChart->setMinimumSize(QSize(70, 70));
        btnNewRoomChart->setMaximumSize(QSize(70, 70));
        btnNewRoomChart->setIcon(icon2);
        btnNewRoomChart->setIconSize(QSize(32, 32));
        btnNewRoomChart->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnNewRoomChart->setArrowType(Qt::NoArrow);

        horizontalLayout_8->addWidget(btnNewRoomChart);

        btnWakupCalls = new EToolbarButton(w4);
        btnWakupCalls->setObjectName(QString::fromUtf8("btnWakupCalls"));
        btnWakupCalls->setMinimumSize(QSize(70, 70));
        btnWakupCalls->setMaximumSize(QSize(70, 70));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/images/alarm.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWakupCalls->setIcon(icon25);
        btnWakupCalls->setIconSize(QSize(32, 32));
        btnWakupCalls->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnWakupCalls->setArrowType(Qt::NoArrow);

        horizontalLayout_8->addWidget(btnWakupCalls);

        btnDailyTransactions = new EToolbarButton(w4);
        btnDailyTransactions->setObjectName(QString::fromUtf8("btnDailyTransactions"));
        btnDailyTransactions->setMinimumSize(QSize(70, 70));
        btnDailyTransactions->setMaximumSize(QSize(70, 70));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/images/category.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDailyTransactions->setIcon(icon26);
        btnDailyTransactions->setIconSize(QSize(32, 32));
        btnDailyTransactions->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnDailyTransactions->setArrowType(Qt::NoArrow);

        horizontalLayout_8->addWidget(btnDailyTransactions);

        btnRemarks = new EToolbarButton(w4);
        btnRemarks->setObjectName(QString::fromUtf8("btnRemarks"));
        btnRemarks->setMinimumSize(QSize(70, 70));
        btnRemarks->setMaximumSize(QSize(70, 70));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/images/remarks.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemarks->setIcon(icon27);
        btnRemarks->setIconSize(QSize(32, 32));
        btnRemarks->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_8->addWidget(btnRemarks);

        btnContacts = new EToolbarButton(w4);
        btnContacts->setObjectName(QString::fromUtf8("btnContacts"));
        btnContacts->setMinimumSize(QSize(70, 70));
        btnContacts->setMaximumSize(QSize(70, 70));
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/images/phone-book.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnContacts->setIcon(icon28);
        btnContacts->setIconSize(QSize(32, 32));
        btnContacts->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_8->addWidget(btnContacts);

        btnHotelHierarchy = new EToolbarButton(w4);
        btnHotelHierarchy->setObjectName(QString::fromUtf8("btnHotelHierarchy"));
        btnHotelHierarchy->setMinimumSize(QSize(70, 70));
        btnHotelHierarchy->setMaximumSize(QSize(70, 70));
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/images/hierarchy.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHotelHierarchy->setIcon(icon29);
        btnHotelHierarchy->setIconSize(QSize(32, 32));
        btnHotelHierarchy->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnHotelHierarchy->setArrowType(Qt::NoArrow);

        horizontalLayout_8->addWidget(btnHotelHierarchy);

        btnRoomStateTouch = new EToolbarButton(w4);
        btnRoomStateTouch->setObjectName(QString::fromUtf8("btnRoomStateTouch"));
        btnRoomStateTouch->setMinimumSize(QSize(70, 70));
        btnRoomStateTouch->setMaximumSize(QSize(70, 70));
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/images/window.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRoomStateTouch->setIcon(icon30);
        btnRoomStateTouch->setIconSize(QSize(32, 32));
        btnRoomStateTouch->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btnRoomStateTouch->setArrowType(Qt::NoArrow);

        horizontalLayout_8->addWidget(btnRoomStateTouch);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);


        gridLayout_2->addWidget(w4, 1, 1, 1, 1);


        horizontalLayout->addWidget(widget);


        retranslateUi(WWelcome);

        tabInfo->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WWelcome);
    } // setupUi

    void retranslateUi(QWidget *WWelcome)
    {
        WWelcome->setWindowTitle(QCoreApplication::translate("WWelcome", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblArrival->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WWelcome", "Room", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblArrival->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WWelcome", "Guest", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblArrival->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WWelcome", "Pax", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblArrival->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WWelcome", "Time", nullptr));
        tabInfo->setTabText(tabInfo->indexOf(tab_2), QCoreApplication::translate("WWelcome", "Airport pickups", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblBirthDay->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WWelcome", "Room", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblBirthDay->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WWelcome", "Guest", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblBirthDay->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WWelcome", "Date", nullptr));
        tabInfo->setTabText(tabInfo->indexOf(tab_3), QCoreApplication::translate("WWelcome", "Birthdays", nullptr));
        lbLogo->setText(QCoreApplication::translate("WWelcome", "Your logo here", nullptr));
        lbSlogan->setText(QCoreApplication::translate("WWelcome", "SLOGAN", nullptr));
        btnRoomChart->setText(QCoreApplication::translate("WWelcome", "Room chart", nullptr));
        btnRoomChart->setProperty("Tag", QVariant(QString()));
        btnNewReservation->setText(QCoreApplication::translate("WWelcome", "New\n"
"reservation", nullptr));
        btnNewReservation->setProperty("Tag", QVariant(QString()));
        btnNewGroupResevation->setText(QCoreApplication::translate("WWelcome", "New group\n"
"reservation", nullptr));
        btnNewGroupResevation->setProperty("Tag", QVariant(QString()));
        btnHotelStatus->setText(QCoreApplication::translate("WWelcome", "Hotel\n"
"Status", nullptr));
        btnHotelStatus->setProperty("Tag", QVariant(QString()));
        btnReservations->setText(QCoreApplication::translate("WWelcome", "Reservations", nullptr));
        btnReservations->setProperty("Tag", QVariant(QString()));
        btnInhouseGuest->setText(QCoreApplication::translate("WWelcome", "Guests \n"
"in house", nullptr));
        btnInhouseGuest->setProperty("Tag", QVariant(QString()));
        btnArrivalDeparture->setText(QCoreApplication::translate("WWelcome", "Arrivals\n"
"departures", nullptr));
        btnArrivalDeparture->setProperty("Tag", QVariant(QString()));
        btnArrivalDeparture_2->setText(QCoreApplication::translate("WWelcome", "Arrivals\n"
"departures 2", nullptr));
        btnArrivalDeparture_2->setProperty("Tag", QVariant(QString()));
        btnCheckoutInvoices->setText(QCoreApplication::translate("WWelcome", "Checkout\n"
"Invoices", nullptr));
        btnCheckoutInvoices->setProperty("Tag", QVariant(QString()));
        btnVauchers->setText(QCoreApplication::translate("WWelcome", "Vouchers", nullptr));
        btnVauchers->setProperty("Tag", QVariant(QString()));
        btnCallHistory->setText(QCoreApplication::translate("WWelcome", "Daily calls", nullptr));
        btnCallHistory->setProperty("Tag", QVariant(QString()));
        btnAdvance->setText(QCoreApplication::translate("WWelcome", "Advance\n"
"voucher", nullptr));
        btnAdvance->setProperty("Tag", QVariant(QString()));
        btnAdvance_2->setText(QCoreApplication::translate("WWelcome", "Receipt\n"
"voucher", nullptr));
        btnAdvance_2->setProperty("Tag", QVariant(QString()));
        btnPostCharge->setText(QCoreApplication::translate("WWelcome", "Posting\n"
"charge", nullptr));
        btnPostCharge->setProperty("Tag", QVariant(QString()));
        btnDiscount->setText(QCoreApplication::translate("WWelcome", "Discount\n"
"voucher", nullptr));
        btnDiscount->setProperty("Tag", QVariant(QString()));
        btnTransferAmount->setText(QCoreApplication::translate("WWelcome", "Transfer\n"
"voucher", nullptr));
        btnTransferAmount->setProperty("Tag", QVariant(QString()));
        btnOnlineInvoice->setText(QCoreApplication::translate("WWelcome", "Check in\n"
"Invoices", nullptr));
        btnOnlineInvoice->setProperty("Tag", QVariant(QString()));
        btnExportInvoices->setText(QCoreApplication::translate("WWelcome", "Export\n"
"invoices", nullptr));
        btnExportInvoices->setProperty("Tag", QVariant(QString()));
        btnExportRestaurant->setText(QCoreApplication::translate("WWelcome", "Export\n"
"restaurant", nullptr));
        btnExportRestaurant->setProperty("Tag", QVariant(QString()));
        btnExportActiveReservation->setText(QCoreApplication::translate("WWelcome", "Export active\n"
"reservations", nullptr));
        btnExportActiveReservation->setProperty("Tag", QVariant(QString()));
        btnNotes->setText(QCoreApplication::translate("WWelcome", "Reminder", nullptr));
        btnNotes->setProperty("Tag", QVariant(QString()));
        btnButtonsConfig->setText(QCoreApplication::translate("WWelcome", "Configure\n"
"buttons", nullptr));
        btnCityLedgerDetailedBalance->setText(QCoreApplication::translate("WWelcome", "City Ledger\n"
"detailed ", nullptr));
        btnCityLedgerDetailedBalance->setProperty("Tag", QVariant(QString()));
        btnDailyMovement->setText(QCoreApplication::translate("WWelcome", "Daily\n"
"Movement", nullptr));
        btnDailyMovement->setProperty("Tag", QVariant(QString()));
        btnMonthlyMovement->setText(QCoreApplication::translate("WWelcome", "Monthly\n"
"Movement", nullptr));
        btnMonthlyMovement->setProperty("Tag", QVariant(QString()));
        btnCashReportSummary->setText(QCoreApplication::translate("WWelcome", "Cash report\n"
"Summary", nullptr));
        btnCashReportSummary->setProperty("Tag", QVariant(QString()));
        btnCashReportDetailed->setText(QCoreApplication::translate("WWelcome", "Cash report\n"
"Detailed", nullptr));
        btnCashReportDetailed->setProperty("Tag", QVariant(QString()));
        btnCardexAnalysis->setText(QCoreApplication::translate("WWelcome", "Cardex\n"
"Analysis", nullptr));
        btnCardexAnalysis->setProperty("Tag", QVariant(QString()));
        btnRestaurant->setText(QCoreApplication::translate("WWelcome", "Restaurant", nullptr));
        btnRestaurant->setProperty("Tag", QVariant(QString()));
        btnReportsSet->setText(QCoreApplication::translate("WWelcome", "Reports\n"
"Set", nullptr));
        btnReportsSet->setProperty("Tag", QVariant(QString()));
        btnStatistic->setText(QCoreApplication::translate("WWelcome", "Statistics", nullptr));
        btnStatistic->setProperty("Tag", QVariant(QString()));
        btnArrivalsSimple->setText(QCoreApplication::translate("WWelcome", "Arrivals\n"
"simple", nullptr));
        btnArrivalsSimple->setProperty("Tag", QVariant(QString()));
        btnDeparutersSimple->setText(QCoreApplication::translate("WWelcome", "Departures\n"
"simple", nullptr));
        btnDeparutersSimple->setProperty("Tag", QVariant(QString()));
        btnNewRoomChart->setText(QCoreApplication::translate("WWelcome", "Room chart\n"
"Experemental", nullptr));
        btnNewRoomChart->setProperty("Tag", QVariant(QString()));
        btnWakupCalls->setText(QCoreApplication::translate("WWelcome", "Wakeup\n"
"calls", nullptr));
        btnWakupCalls->setProperty("Tag", QVariant(QString()));
        btnDailyTransactions->setText(QCoreApplication::translate("WWelcome", "Daily\n"
"Transactions", nullptr));
        btnDailyTransactions->setProperty("Tag", QVariant(QString()));
        btnRemarks->setText(QCoreApplication::translate("WWelcome", "Remarks", nullptr));
        btnRemarks->setProperty("Tag", QVariant(QString()));
        btnContacts->setText(QCoreApplication::translate("WWelcome", "Contacts", nullptr));
        btnContacts->setProperty("Tag", QVariant(QString()));
        btnHotelHierarchy->setText(QCoreApplication::translate("WWelcome", "Hotel\n"
"hierarchy", nullptr));
        btnHotelHierarchy->setProperty("Tag", QVariant(QString()));
        btnRoomStateTouch->setText(QCoreApplication::translate("WWelcome", "Room\n"
"states", nullptr));
        btnRoomStateTouch->setProperty("Tag", QVariant(QString()));
    } // retranslateUi

};

namespace Ui {
    class WWelcome: public Ui_WWelcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WWELCOME_H
