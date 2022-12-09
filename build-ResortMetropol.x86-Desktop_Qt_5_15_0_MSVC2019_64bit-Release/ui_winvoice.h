/********************************************************************************
** Form generated from reading UI file 'winvoice.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINVOICE_H
#define UI_WINVOICE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqdateedit.h>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_WInvoice
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wBtn;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *btnResetAdvanceAmount;
    QPushButton *btnTaxBack;
    QToolButton *btnCheckout;
    QToolButton *btnWakeup;
    QToolButton *btnCancel;
    QPushButton *btnTransfer;
    QPushButton *btnTrack;
    QToolButton *btnAdvance;
    QToolButton *btnTaxPrint;
    QToolButton *btnRefresh;
    QPushButton *btnTransferAmount;
    QToolButton *btnPostingCharges;
    QPushButton *btnModifyRoom;
    QPushButton *btnManualTax;
    QPushButton *btnDiscount;
    QToolButton *btnDoNotDisturbe;
    QPushButton *btnPrintInvoice;
    QToolButton *btnPaymentsDetails;
    QToolButton *btnPayment;
    QWidget *wMiddle;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    EQLineEdit *leRoom;
    EQLineEdit *leRoomCode;
    QLabel *label;
    QTextEdit *teRemark;
    QPushButton *btnPrevInvoice;
    QPushButton *btnNextInvoice;
    QLabel *label_2;
    QFrame *line_3;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    EQLineEdit *leInvoice;
    QLabel *label_4;
    QLabel *label_16;
    EQLineEdit *leReserveID;
    QLabel *label_21;
    QLineEdit *leCheckInOperator;
    EQDateEdit *deCheckin;
    EQLineEdit *leCheckInTime;
    QLabel *label_23;
    QSpacerItem *verticalSpacer;
    EQDateEdit *deDeparture;
    QLabel *label_5;
    QFrame *line;
    QWidget *widget_3;
    QGridLayout *gridLayout_4;
    EQLineEdit *leVatMode;
    EQLineEdit *leRegisteredGuest;
    QLabel *label_18;
    QLabel *label_17;
    EQLineEdit *leGuestCount;
    QLabel *label_24;
    EQLineEdit *leArrangement;
    EQLineEdit *leRoomRate;
    QLabel *label_19;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_10;
    QLineEdit *leNights;
    QFrame *line_2;
    QWidget *widget_4;
    QGridLayout *gridLayout_5;
    EQLineEdit *leCityLedgerCode;
    EQLineEdit *leGuest;
    EQLineEdit *leCityLedgerName;
    QLineEdit *leCardexName;
    QLabel *label_3;
    QLabel *label_28;
    QLineEdit *lePassport;
    QLineEdit *leCardex;
    QLabel *label_7;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_22;
    EQLineEdit *leBookingNo;
    QWidget *wdt;
    QGridLayout *gridLayout_3;
    QWidget *wdtLeft;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_11;
    EQTableWidget *tblInvLeft;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_20;
    EQLineEdit *lePrepaid;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_13;
    EQLineEdit *leTotalLeft;
    QWidget *wdtRight;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_12;
    EQTableWidget *tblInvRight;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_14;
    EQLineEdit *leTotalRight;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btnLeft;
    QPushButton *btnDoubleLeft;
    QPushButton *btnRight;
    QPushButton *btnDoubleRight;
    QPushButton *btnRefTax;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnShowLeft;
    QPushButton *btnShowRight;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_15;
    EQLineEdit *leGranTotal;

    void setupUi(QWidget *WInvoice)
    {
        if (WInvoice->objectName().isEmpty())
            WInvoice->setObjectName(QString::fromUtf8("WInvoice"));
        WInvoice->resize(1374, 615);
        verticalLayout = new QVBoxLayout(WInvoice);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        wBtn = new QWidget(WInvoice);
        wBtn->setObjectName(QString::fromUtf8("wBtn"));
        gridLayout_6 = new QGridLayout(wBtn);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(767, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 0, 18, 1, 1);

        btnResetAdvanceAmount = new QToolButton(wBtn);
        btnResetAdvanceAmount->setObjectName(QString::fromUtf8("btnResetAdvanceAmount"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnResetAdvanceAmount->sizePolicy().hasHeightForWidth());
        btnResetAdvanceAmount->setSizePolicy(sizePolicy);
        btnResetAdvanceAmount->setMinimumSize(QSize(0, 0));
        btnResetAdvanceAmount->setMaximumSize(QSize(55555, 222222));
        btnResetAdvanceAmount->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/password.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnResetAdvanceAmount->setIcon(icon);
        btnResetAdvanceAmount->setIconSize(QSize(20, 20));
        btnResetAdvanceAmount->setCheckable(false);
        btnResetAdvanceAmount->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_6->addWidget(btnResetAdvanceAmount, 1, 10, 1, 1);

        btnTaxBack = new QPushButton(wBtn);
        btnTaxBack->setObjectName(QString::fromUtf8("btnTaxBack"));
        btnTaxBack->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/tax.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTaxBack->setIcon(icon1);

        gridLayout_6->addWidget(btnTaxBack, 0, 11, 1, 1);

        btnCheckout = new QToolButton(wBtn);
        btnCheckout->setObjectName(QString::fromUtf8("btnCheckout"));
        sizePolicy.setHeightForWidth(btnCheckout->sizePolicy().hasHeightForWidth());
        btnCheckout->setSizePolicy(sizePolicy);
        btnCheckout->setMinimumSize(QSize(0, 0));
        btnCheckout->setMaximumSize(QSize(55555, 222222));
        btnCheckout->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/departure.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCheckout->setIcon(icon2);
        btnCheckout->setIconSize(QSize(20, 20));
        btnCheckout->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_6->addWidget(btnCheckout, 0, 5, 1, 1);

        btnWakeup = new QToolButton(wBtn);
        btnWakeup->setObjectName(QString::fromUtf8("btnWakeup"));
        sizePolicy.setHeightForWidth(btnWakeup->sizePolicy().hasHeightForWidth());
        btnWakeup->setSizePolicy(sizePolicy);
        btnWakeup->setMinimumSize(QSize(0, 0));
        btnWakeup->setMaximumSize(QSize(55555, 222222));
        btnWakeup->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/alarm.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWakeup->setIcon(icon3);
        btnWakeup->setIconSize(QSize(20, 20));
        btnWakeup->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_6->addWidget(btnWakeup, 1, 7, 1, 1);

        btnCancel = new QToolButton(wBtn);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        sizePolicy.setHeightForWidth(btnCancel->sizePolicy().hasHeightForWidth());
        btnCancel->setSizePolicy(sizePolicy);
        btnCancel->setMinimumSize(QSize(0, 0));
        btnCancel->setMaximumSize(QSize(55555, 222222));
        btnCancel->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/garbage.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCancel->setIcon(icon4);
        btnCancel->setIconSize(QSize(20, 20));
        btnCancel->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_6->addWidget(btnCancel, 1, 5, 1, 1);

        btnTransfer = new QPushButton(wBtn);
        btnTransfer->setObjectName(QString::fromUtf8("btnTransfer"));
        btnTransfer->setMaximumSize(QSize(5555, 22222));
        btnTransfer->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/goto.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTransfer->setIcon(icon5);

        gridLayout_6->addWidget(btnTransfer, 1, 1, 1, 1);

        btnTrack = new QPushButton(wBtn);
        btnTrack->setObjectName(QString::fromUtf8("btnTrack"));
        btnTrack->setMaximumSize(QSize(222, 222));
        btnTrack->setFocusPolicy(Qt::NoFocus);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/tracking.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTrack->setIcon(icon6);

        gridLayout_6->addWidget(btnTrack, 0, 19, 1, 1);

        btnAdvance = new QToolButton(wBtn);
        btnAdvance->setObjectName(QString::fromUtf8("btnAdvance"));
        sizePolicy.setHeightForWidth(btnAdvance->sizePolicy().hasHeightForWidth());
        btnAdvance->setSizePolicy(sizePolicy);
        btnAdvance->setMinimumSize(QSize(0, 0));
        btnAdvance->setMaximumSize(QSize(55555, 222222));
        btnAdvance->setFocusPolicy(Qt::NoFocus);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/credit-card.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdvance->setIcon(icon7);
        btnAdvance->setIconSize(QSize(20, 20));
        btnAdvance->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_6->addWidget(btnAdvance, 0, 2, 1, 1);

        btnTaxPrint = new QToolButton(wBtn);
        btnTaxPrint->setObjectName(QString::fromUtf8("btnTaxPrint"));
        sizePolicy.setHeightForWidth(btnTaxPrint->sizePolicy().hasHeightForWidth());
        btnTaxPrint->setSizePolicy(sizePolicy);
        btnTaxPrint->setMinimumSize(QSize(0, 0));
        btnTaxPrint->setMaximumSize(QSize(55555, 222222));
        btnTaxPrint->setFocusPolicy(Qt::NoFocus);
        btnTaxPrint->setIcon(icon1);
        btnTaxPrint->setIconSize(QSize(20, 20));
        btnTaxPrint->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_6->addWidget(btnTaxPrint, 0, 8, 1, 1);

        btnRefresh = new QToolButton(wBtn);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        sizePolicy.setHeightForWidth(btnRefresh->sizePolicy().hasHeightForWidth());
        btnRefresh->setSizePolicy(sizePolicy);
        btnRefresh->setMinimumSize(QSize(0, 0));
        btnRefresh->setMaximumSize(QSize(55555, 222222));
        btnRefresh->setFocusPolicy(Qt::NoFocus);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon8);
        btnRefresh->setIconSize(QSize(20, 20));
        btnRefresh->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_6->addWidget(btnRefresh, 0, 0, 1, 1);

        btnTransferAmount = new QPushButton(wBtn);
        btnTransferAmount->setObjectName(QString::fromUtf8("btnTransferAmount"));
        btnTransferAmount->setMaximumSize(QSize(2222, 22222));
        btnTransferAmount->setFocusPolicy(Qt::NoFocus);
        btnTransferAmount->setIcon(icon5);

        gridLayout_6->addWidget(btnTransferAmount, 1, 2, 1, 1);

        btnPostingCharges = new QToolButton(wBtn);
        btnPostingCharges->setObjectName(QString::fromUtf8("btnPostingCharges"));
        sizePolicy.setHeightForWidth(btnPostingCharges->sizePolicy().hasHeightForWidth());
        btnPostingCharges->setSizePolicy(sizePolicy);
        btnPostingCharges->setMinimumSize(QSize(0, 0));
        btnPostingCharges->setMaximumSize(QSize(55555, 222222));
        btnPostingCharges->setFocusPolicy(Qt::NoFocus);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/charge.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPostingCharges->setIcon(icon9);
        btnPostingCharges->setIconSize(QSize(20, 20));
        btnPostingCharges->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_6->addWidget(btnPostingCharges, 1, 0, 1, 1);

        btnModifyRoom = new QPushButton(wBtn);
        btnModifyRoom->setObjectName(QString::fromUtf8("btnModifyRoom"));
        btnModifyRoom->setFocusPolicy(Qt::NoFocus);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/room-key.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnModifyRoom->setIcon(icon10);
        btnModifyRoom->setIconSize(QSize(20, 20));

        gridLayout_6->addWidget(btnModifyRoom, 0, 1, 1, 1);

        btnManualTax = new QPushButton(wBtn);
        btnManualTax->setObjectName(QString::fromUtf8("btnManualTax"));
        btnManualTax->setFocusPolicy(Qt::NoFocus);
        btnManualTax->setIcon(icon1);

        gridLayout_6->addWidget(btnManualTax, 0, 10, 1, 1);

        btnDiscount = new QPushButton(wBtn);
        btnDiscount->setObjectName(QString::fromUtf8("btnDiscount"));
        btnDiscount->setMaximumSize(QSize(2222, 2222));
        btnDiscount->setFocusPolicy(Qt::NoFocus);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/discount.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDiscount->setIcon(icon11);
        btnDiscount->setIconSize(QSize(20, 20));

        gridLayout_6->addWidget(btnDiscount, 1, 4, 1, 1);

        btnDoNotDisturbe = new QToolButton(wBtn);
        btnDoNotDisturbe->setObjectName(QString::fromUtf8("btnDoNotDisturbe"));
        sizePolicy.setHeightForWidth(btnDoNotDisturbe->sizePolicy().hasHeightForWidth());
        btnDoNotDisturbe->setSizePolicy(sizePolicy);
        btnDoNotDisturbe->setMinimumSize(QSize(0, 0));
        btnDoNotDisturbe->setMaximumSize(QSize(55555, 222222));
        btnDoNotDisturbe->setFocusPolicy(Qt::NoFocus);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/do-not-disturbe.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDoNotDisturbe->setIcon(icon12);
        btnDoNotDisturbe->setIconSize(QSize(20, 20));
        btnDoNotDisturbe->setCheckable(true);
        btnDoNotDisturbe->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_6->addWidget(btnDoNotDisturbe, 1, 8, 1, 1);

        btnPrintInvoice = new QPushButton(wBtn);
        btnPrintInvoice->setObjectName(QString::fromUtf8("btnPrintInvoice"));
        btnPrintInvoice->setMaximumSize(QSize(2222, 2222));
        btnPrintInvoice->setFocusPolicy(Qt::NoFocus);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrintInvoice->setIcon(icon13);
        btnPrintInvoice->setIconSize(QSize(20, 20));

        gridLayout_6->addWidget(btnPrintInvoice, 0, 7, 1, 1);

        btnPaymentsDetails = new QToolButton(wBtn);
        btnPaymentsDetails->setObjectName(QString::fromUtf8("btnPaymentsDetails"));
        sizePolicy.setHeightForWidth(btnPaymentsDetails->sizePolicy().hasHeightForWidth());
        btnPaymentsDetails->setSizePolicy(sizePolicy);
        btnPaymentsDetails->setMinimumSize(QSize(0, 0));
        btnPaymentsDetails->setMaximumSize(QSize(55555, 222222));
        btnPaymentsDetails->setFocusPolicy(Qt::NoFocus);
        btnPaymentsDetails->setIcon(icon7);
        btnPaymentsDetails->setIconSize(QSize(20, 20));
        btnPaymentsDetails->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_6->addWidget(btnPaymentsDetails, 1, 11, 1, 1);

        btnPayment = new QToolButton(wBtn);
        btnPayment->setObjectName(QString::fromUtf8("btnPayment"));
        sizePolicy.setHeightForWidth(btnPayment->sizePolicy().hasHeightForWidth());
        btnPayment->setSizePolicy(sizePolicy);
        btnPayment->setMinimumSize(QSize(0, 0));
        btnPayment->setMaximumSize(QSize(55555, 222222));
        btnPayment->setFocusPolicy(Qt::NoFocus);
        btnPayment->setIcon(icon7);
        btnPayment->setIconSize(QSize(20, 20));
        btnPayment->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_6->addWidget(btnPayment, 0, 4, 1, 1);


        verticalLayout->addWidget(wBtn);

        wMiddle = new QWidget(WInvoice);
        wMiddle->setObjectName(QString::fromUtf8("wMiddle"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wMiddle->sizePolicy().hasHeightForWidth());
        wMiddle->setSizePolicy(sizePolicy1);
        wMiddle->setMinimumSize(QSize(0, 0));
        wMiddle->setMaximumSize(QSize(16777215, 200));
        horizontalLayout_2 = new QHBoxLayout(wMiddle);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(1, 1, 1, 1);
        widget = new QWidget(wMiddle);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 1);
        leRoom = new EQLineEdit(widget);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setFocusPolicy(Qt::NoFocus);
        leRoom->setReadOnly(true);

        gridLayout->addWidget(leRoom, 0, 4, 2, 1);

        leRoomCode = new EQLineEdit(widget);
        leRoomCode->setObjectName(QString::fromUtf8("leRoomCode"));
        leRoomCode->setMaximumSize(QSize(75, 16777215));
        leRoomCode->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(leRoomCode, 0, 2, 2, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        teRemark = new QTextEdit(widget);
        teRemark->setObjectName(QString::fromUtf8("teRemark"));
        teRemark->setMinimumSize(QSize(0, 0));
        teRemark->setMaximumSize(QSize(16777215, 2000));
        teRemark->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(teRemark, 2, 1, 1, 4);

        btnPrevInvoice = new QPushButton(widget);
        btnPrevInvoice->setObjectName(QString::fromUtf8("btnPrevInvoice"));
        btnPrevInvoice->setMinimumSize(QSize(25, 25));
        btnPrevInvoice->setMaximumSize(QSize(25, 25));
        btnPrevInvoice->setFocusPolicy(Qt::NoFocus);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/double-left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrevInvoice->setIcon(icon14);

        gridLayout->addWidget(btnPrevInvoice, 0, 1, 1, 1);

        btnNextInvoice = new QPushButton(widget);
        btnNextInvoice->setObjectName(QString::fromUtf8("btnNextInvoice"));
        btnNextInvoice->setMinimumSize(QSize(25, 25));
        btnNextInvoice->setMaximumSize(QSize(25, 25));
        btnNextInvoice->setFocusPolicy(Qt::NoFocus);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/double-right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNextInvoice->setIcon(icon15);

        gridLayout->addWidget(btnNextInvoice, 0, 3, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 2, 1);


        horizontalLayout_2->addWidget(widget);

        line_3 = new QFrame(wMiddle);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_3);

        widget_2 = new QWidget(wMiddle);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(200, 0));
        widget_2->setMaximumSize(QSize(200, 16777215));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        leInvoice = new EQLineEdit(widget_2);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setFocusPolicy(Qt::NoFocus);
        leInvoice->setReadOnly(true);

        gridLayout_2->addWidget(leInvoice, 0, 1, 1, 2);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        label_16 = new QLabel(widget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_2->addWidget(label_16, 1, 0, 1, 1);

        leReserveID = new EQLineEdit(widget_2);
        leReserveID->setObjectName(QString::fromUtf8("leReserveID"));
        leReserveID->setFocusPolicy(Qt::NoFocus);
        leReserveID->setReadOnly(true);

        gridLayout_2->addWidget(leReserveID, 1, 1, 1, 2);

        label_21 = new QLabel(widget_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_2->addWidget(label_21, 4, 0, 1, 1);

        leCheckInOperator = new QLineEdit(widget_2);
        leCheckInOperator->setObjectName(QString::fromUtf8("leCheckInOperator"));
        leCheckInOperator->setFocusPolicy(Qt::NoFocus);
        leCheckInOperator->setReadOnly(true);

        gridLayout_2->addWidget(leCheckInOperator, 4, 1, 1, 2);

        deCheckin = new EQDateEdit(widget_2);
        deCheckin->setObjectName(QString::fromUtf8("deCheckin"));
        deCheckin->setEnabled(false);
        deCheckin->setFocusPolicy(Qt::NoFocus);
        deCheckin->setCalendarPopup(true);

        gridLayout_2->addWidget(deCheckin, 2, 1, 1, 2);

        leCheckInTime = new EQLineEdit(widget_2);
        leCheckInTime->setObjectName(QString::fromUtf8("leCheckInTime"));
        leCheckInTime->setMaximumSize(QSize(2000, 16777215));
        leCheckInTime->setFocusPolicy(Qt::NoFocus);
        leCheckInTime->setReadOnly(true);

        gridLayout_2->addWidget(leCheckInTime, 3, 1, 1, 2);

        label_23 = new QLabel(widget_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_2->addWidget(label_23, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 1, 1, 1);

        deDeparture = new EQDateEdit(widget_2);
        deDeparture->setObjectName(QString::fromUtf8("deDeparture"));
        deDeparture->setEnabled(false);
        deDeparture->setFocusPolicy(Qt::NoFocus);
        deDeparture->setCalendarPopup(true);

        gridLayout_2->addWidget(deDeparture, 5, 1, 1, 2);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 5, 0, 1, 1);


        horizontalLayout_2->addWidget(widget_2);

        line = new QFrame(wMiddle);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        widget_3 = new QWidget(wMiddle);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(100, 0));
        widget_3->setMaximumSize(QSize(200, 16777215));
        widget_3->setFocusPolicy(Qt::NoFocus);
        gridLayout_4 = new QGridLayout(widget_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        leVatMode = new EQLineEdit(widget_3);
        leVatMode->setObjectName(QString::fromUtf8("leVatMode"));
        leVatMode->setFocusPolicy(Qt::NoFocus);
        leVatMode->setReadOnly(true);

        gridLayout_4->addWidget(leVatMode, 5, 1, 1, 1);

        leRegisteredGuest = new EQLineEdit(widget_3);
        leRegisteredGuest->setObjectName(QString::fromUtf8("leRegisteredGuest"));
        leRegisteredGuest->setFocusPolicy(Qt::NoFocus);
        leRegisteredGuest->setReadOnly(true);

        gridLayout_4->addWidget(leRegisteredGuest, 13, 1, 1, 1);

        label_18 = new QLabel(widget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_4->addWidget(label_18, 13, 0, 1, 1);

        label_17 = new QLabel(widget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_4->addWidget(label_17, 6, 0, 1, 1);

        leGuestCount = new EQLineEdit(widget_3);
        leGuestCount->setObjectName(QString::fromUtf8("leGuestCount"));
        leGuestCount->setFocusPolicy(Qt::NoFocus);
        leGuestCount->setReadOnly(true);

        gridLayout_4->addWidget(leGuestCount, 6, 1, 1, 1);

        label_24 = new QLabel(widget_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_4->addWidget(label_24, 2, 0, 1, 1);

        leArrangement = new EQLineEdit(widget_3);
        leArrangement->setObjectName(QString::fromUtf8("leArrangement"));
        leArrangement->setFocusPolicy(Qt::NoFocus);
        leArrangement->setReadOnly(true);

        gridLayout_4->addWidget(leArrangement, 2, 1, 1, 1);

        leRoomRate = new EQLineEdit(widget_3);
        leRoomRate->setObjectName(QString::fromUtf8("leRoomRate"));
        leRoomRate->setFocusPolicy(Qt::NoFocus);
        leRoomRate->setReadOnly(true);

        gridLayout_4->addWidget(leRoomRate, 3, 1, 1, 1);

        label_19 = new QLabel(widget_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_4->addWidget(label_19, 5, 0, 1, 1);

        label_9 = new QLabel(widget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 14, 1, 1, 1);

        label_10 = new QLabel(widget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 4, 0, 1, 1);

        leNights = new QLineEdit(widget_3);
        leNights->setObjectName(QString::fromUtf8("leNights"));
        leNights->setFocusPolicy(Qt::NoFocus);
        leNights->setReadOnly(true);

        gridLayout_4->addWidget(leNights, 4, 1, 1, 1);


        horizontalLayout_2->addWidget(widget_3);

        line_2 = new QFrame(wMiddle);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        widget_4 = new QWidget(wMiddle);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 0));
        gridLayout_5 = new QGridLayout(widget_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        leCityLedgerCode = new EQLineEdit(widget_4);
        leCityLedgerCode->setObjectName(QString::fromUtf8("leCityLedgerCode"));
        leCityLedgerCode->setMaximumSize(QSize(80, 16777215));
        leCityLedgerCode->setFocusPolicy(Qt::NoFocus);
        leCityLedgerCode->setReadOnly(true);

        gridLayout_5->addWidget(leCityLedgerCode, 4, 1, 1, 1);

        leGuest = new EQLineEdit(widget_4);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setFocusPolicy(Qt::NoFocus);
        leGuest->setReadOnly(true);

        gridLayout_5->addWidget(leGuest, 0, 1, 1, 2);

        leCityLedgerName = new EQLineEdit(widget_4);
        leCityLedgerName->setObjectName(QString::fromUtf8("leCityLedgerName"));
        leCityLedgerName->setFocusPolicy(Qt::NoFocus);
        leCityLedgerName->setReadOnly(true);

        gridLayout_5->addWidget(leCityLedgerName, 4, 2, 1, 1);

        leCardexName = new QLineEdit(widget_4);
        leCardexName->setObjectName(QString::fromUtf8("leCardexName"));
        leCardexName->setFocusPolicy(Qt::NoFocus);
        leCardexName->setReadOnly(true);

        gridLayout_5->addWidget(leCardexName, 3, 2, 1, 1);

        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        label_28 = new QLabel(widget_4);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_5->addWidget(label_28, 4, 0, 1, 1);

        lePassport = new QLineEdit(widget_4);
        lePassport->setObjectName(QString::fromUtf8("lePassport"));
        lePassport->setMaximumSize(QSize(80, 16777215));
        lePassport->setFocusPolicy(Qt::NoFocus);
        lePassport->setReadOnly(true);

        gridLayout_5->addWidget(lePassport, 1, 1, 1, 1);

        leCardex = new QLineEdit(widget_4);
        leCardex->setObjectName(QString::fromUtf8("leCardex"));
        leCardex->setMaximumSize(QSize(80, 16777215));
        leCardex->setFocusPolicy(Qt::NoFocus);
        leCardex->setReadOnly(true);

        gridLayout_5->addWidget(leCardex, 3, 1, 1, 1);

        label_7 = new QLabel(widget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_5->addWidget(label_7, 3, 0, 1, 1);

        label_6 = new QLabel(widget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_5->addWidget(label_6, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_4, 6, 1, 1, 1);

        label_22 = new QLabel(widget_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_5->addWidget(label_22, 5, 0, 1, 1);

        leBookingNo = new EQLineEdit(widget_4);
        leBookingNo->setObjectName(QString::fromUtf8("leBookingNo"));
        leBookingNo->setFocusPolicy(Qt::NoFocus);
        leBookingNo->setReadOnly(true);

        gridLayout_5->addWidget(leBookingNo, 5, 1, 1, 2);


        horizontalLayout_2->addWidget(widget_4);


        verticalLayout->addWidget(wMiddle);

        wdt = new QWidget(WInvoice);
        wdt->setObjectName(QString::fromUtf8("wdt"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wdt->sizePolicy().hasHeightForWidth());
        wdt->setSizePolicy(sizePolicy2);
        wdt->setMinimumSize(QSize(0, 0));
        gridLayout_3 = new QGridLayout(wdt);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(1, 1, 1, 1);
        wdtLeft = new QWidget(wdt);
        wdtLeft->setObjectName(QString::fromUtf8("wdtLeft"));
        wdtLeft->setMinimumSize(QSize(50, 50));
        verticalLayout_2 = new QVBoxLayout(wdtLeft);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(wdtLeft);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_2->addWidget(label_11);

        tblInvLeft = new EQTableWidget(wdtLeft);
        if (tblInvLeft->columnCount() < 15)
            tblInvLeft->setColumnCount(15);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblInvLeft->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblInvLeft->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblInvLeft->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblInvLeft->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblInvLeft->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblInvLeft->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblInvLeft->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblInvLeft->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblInvLeft->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblInvLeft->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblInvLeft->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblInvLeft->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblInvLeft->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblInvLeft->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblInvLeft->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        tblInvLeft->setObjectName(QString::fromUtf8("tblInvLeft"));
        tblInvLeft->setFocusPolicy(Qt::NoFocus);
        tblInvLeft->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblInvLeft->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tblInvLeft->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblInvLeft->setWordWrap(false);

        verticalLayout_2->addWidget(tblInvLeft);

        widget_8 = new QWidget(wdtLeft);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_5 = new QHBoxLayout(widget_8);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(widget_8);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_5->addWidget(label_20);

        lePrepaid = new EQLineEdit(widget_8);
        lePrepaid->setObjectName(QString::fromUtf8("lePrepaid"));
        lePrepaid->setFocusPolicy(Qt::NoFocus);
        lePrepaid->setStyleSheet(QString::fromUtf8("font-size:12pt;\n"
"font-weight:bold;\n"
"color:red;"));
        lePrepaid->setReadOnly(true);

        horizontalLayout_5->addWidget(lePrepaid);

        horizontalSpacer_5 = new QSpacerItem(203, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        label_13 = new QLabel(widget_8);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_5->addWidget(label_13);

        leTotalLeft = new EQLineEdit(widget_8);
        leTotalLeft->setObjectName(QString::fromUtf8("leTotalLeft"));
        leTotalLeft->setMaximumSize(QSize(150, 16777215));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        leTotalLeft->setFont(font);
        leTotalLeft->setFocusPolicy(Qt::NoFocus);
        leTotalLeft->setReadOnly(true);

        horizontalLayout_5->addWidget(leTotalLeft);


        verticalLayout_2->addWidget(widget_8);


        gridLayout_3->addWidget(wdtLeft, 1, 0, 1, 1);

        wdtRight = new QWidget(wdt);
        wdtRight->setObjectName(QString::fromUtf8("wdtRight"));
        wdtRight->setMinimumSize(QSize(50, 0));
        verticalLayout_3 = new QVBoxLayout(wdtRight);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(wdtRight);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_3->addWidget(label_12);

        tblInvRight = new EQTableWidget(wdtRight);
        if (tblInvRight->columnCount() < 15)
            tblInvRight->setColumnCount(15);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblInvRight->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tblInvRight->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tblInvRight->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tblInvRight->setHorizontalHeaderItem(3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tblInvRight->setHorizontalHeaderItem(4, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tblInvRight->setHorizontalHeaderItem(5, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tblInvRight->setHorizontalHeaderItem(6, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tblInvRight->setHorizontalHeaderItem(7, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tblInvRight->setHorizontalHeaderItem(8, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tblInvRight->setHorizontalHeaderItem(9, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tblInvRight->setHorizontalHeaderItem(10, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tblInvRight->setHorizontalHeaderItem(11, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tblInvRight->setHorizontalHeaderItem(12, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tblInvRight->setHorizontalHeaderItem(13, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tblInvRight->setHorizontalHeaderItem(14, __qtablewidgetitem29);
        tblInvRight->setObjectName(QString::fromUtf8("tblInvRight"));
        tblInvRight->setFocusPolicy(Qt::NoFocus);
        tblInvRight->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblInvRight->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tblInvRight->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblInvRight->setWordWrap(false);

        verticalLayout_3->addWidget(tblInvRight);

        widget_9 = new QWidget(wdtRight);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout = new QHBoxLayout(widget_9);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(202, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_14 = new QLabel(widget_9);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout->addWidget(label_14);

        leTotalRight = new EQLineEdit(widget_9);
        leTotalRight->setObjectName(QString::fromUtf8("leTotalRight"));
        leTotalRight->setMaximumSize(QSize(150, 16777215));
        leTotalRight->setFont(font);
        leTotalRight->setFocusPolicy(Qt::NoFocus);
        leTotalRight->setReadOnly(true);

        horizontalLayout->addWidget(leTotalRight);


        verticalLayout_3->addWidget(widget_9);


        gridLayout_3->addWidget(wdtRight, 1, 2, 1, 1);

        widget_6 = new QWidget(wdt);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_5 = new QVBoxLayout(widget_6);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(1, 1, 1, 1);
        btnLeft = new QPushButton(widget_6);
        btnLeft->setObjectName(QString::fromUtf8("btnLeft"));
        btnLeft->setMinimumSize(QSize(25, 25));
        btnLeft->setMaximumSize(QSize(25, 25));
        btnLeft->setFocusPolicy(Qt::NoFocus);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/left-arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLeft->setIcon(icon16);

        verticalLayout_5->addWidget(btnLeft);

        btnDoubleLeft = new QPushButton(widget_6);
        btnDoubleLeft->setObjectName(QString::fromUtf8("btnDoubleLeft"));
        btnDoubleLeft->setMinimumSize(QSize(25, 25));
        btnDoubleLeft->setMaximumSize(QSize(25, 25));
        btnDoubleLeft->setFocusPolicy(Qt::NoFocus);
        btnDoubleLeft->setIcon(icon14);

        verticalLayout_5->addWidget(btnDoubleLeft);

        btnRight = new QPushButton(widget_6);
        btnRight->setObjectName(QString::fromUtf8("btnRight"));
        btnRight->setMinimumSize(QSize(25, 25));
        btnRight->setMaximumSize(QSize(25, 25));
        btnRight->setFocusPolicy(Qt::NoFocus);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/right-arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRight->setIcon(icon17);

        verticalLayout_5->addWidget(btnRight);

        btnDoubleRight = new QPushButton(widget_6);
        btnDoubleRight->setObjectName(QString::fromUtf8("btnDoubleRight"));
        btnDoubleRight->setMinimumSize(QSize(25, 25));
        btnDoubleRight->setMaximumSize(QSize(25, 25));
        btnDoubleRight->setFocusPolicy(Qt::NoFocus);
        btnDoubleRight->setIcon(icon15);

        verticalLayout_5->addWidget(btnDoubleRight);

        btnRefTax = new QPushButton(widget_6);
        btnRefTax->setObjectName(QString::fromUtf8("btnRefTax"));
        btnRefTax->setMinimumSize(QSize(25, 25));
        btnRefTax->setMaximumSize(QSize(25, 25));
        btnRefTax->setFocusPolicy(Qt::NoFocus);
        btnRefTax->setIcon(icon1);

        verticalLayout_5->addWidget(btnRefTax);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        btnShowLeft = new QPushButton(widget_6);
        btnShowLeft->setObjectName(QString::fromUtf8("btnShowLeft"));
        btnShowLeft->setMinimumSize(QSize(25, 25));
        btnShowLeft->setMaximumSize(QSize(25, 25));
        btnShowLeft->setFocusPolicy(Qt::NoFocus);

        verticalLayout_5->addWidget(btnShowLeft);

        btnShowRight = new QPushButton(widget_6);
        btnShowRight->setObjectName(QString::fromUtf8("btnShowRight"));
        btnShowRight->setMinimumSize(QSize(25, 25));
        btnShowRight->setMaximumSize(QSize(25, 25));
        btnShowRight->setFocusPolicy(Qt::NoFocus);

        verticalLayout_5->addWidget(btnShowRight);


        gridLayout_3->addWidget(widget_6, 1, 1, 1, 1);


        verticalLayout->addWidget(wdt);

        widget_10 = new QWidget(WInvoice);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_6 = new QHBoxLayout(widget_10);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(605, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        label_15 = new QLabel(widget_10);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_6->addWidget(label_15);

        leGranTotal = new EQLineEdit(widget_10);
        leGranTotal->setObjectName(QString::fromUtf8("leGranTotal"));
        leGranTotal->setMaximumSize(QSize(150, 16777215));
        leGranTotal->setFont(font);
        leGranTotal->setFocusPolicy(Qt::NoFocus);
        leGranTotal->setReadOnly(true);

        horizontalLayout_6->addWidget(leGranTotal);


        verticalLayout->addWidget(widget_10);

        QWidget::setTabOrder(leRoomCode, tblInvLeft);
        QWidget::setTabOrder(tblInvLeft, leGranTotal);
        QWidget::setTabOrder(leGranTotal, tblInvRight);
        QWidget::setTabOrder(tblInvRight, btnShowLeft);
        QWidget::setTabOrder(btnShowLeft, btnShowRight);
        QWidget::setTabOrder(btnShowRight, leTotalLeft);
        QWidget::setTabOrder(leTotalLeft, leTotalRight);

        retranslateUi(WInvoice);

        QMetaObject::connectSlotsByName(WInvoice);
    } // setupUi

    void retranslateUi(QWidget *WInvoice)
    {
        WInvoice->setWindowTitle(QCoreApplication::translate("WInvoice", "Form", nullptr));
        btnResetAdvanceAmount->setText(QCoreApplication::translate("WInvoice", "Reset advance\n"
"amount", nullptr));
        btnTaxBack->setText(QCoreApplication::translate("WInvoice", "Tax\n"
"back", nullptr));
        btnCheckout->setText(QCoreApplication::translate("WInvoice", "Checkout", nullptr));
        btnWakeup->setText(QCoreApplication::translate("WInvoice", "Alarm", nullptr));
        btnCancel->setText(QCoreApplication::translate("WInvoice", "Correction", nullptr));
        btnTransfer->setText(QCoreApplication::translate("WInvoice", "Transfer\n"
"entries", nullptr));
        btnTrack->setText(QString());
        btnAdvance->setText(QCoreApplication::translate("WInvoice", "Advance", nullptr));
        btnTaxPrint->setText(QCoreApplication::translate("WInvoice", "Print\n"
"tax", nullptr));
        btnRefresh->setText(QCoreApplication::translate("WInvoice", "Refresh", nullptr));
        btnTransferAmount->setText(QCoreApplication::translate("WInvoice", "Transfer\n"
"amount", nullptr));
        btnPostingCharges->setText(QCoreApplication::translate("WInvoice", "Posting\n"
"Charges", nullptr));
        btnModifyRoom->setText(QCoreApplication::translate("WInvoice", "Modify\n"
"room", nullptr));
        btnManualTax->setText(QCoreApplication::translate("WInvoice", "Manual\n"
"Tax", nullptr));
        btnDiscount->setText(QCoreApplication::translate("WInvoice", "Discount", nullptr));
        btnDoNotDisturbe->setText(QCoreApplication::translate("WInvoice", "Dont disturbe", nullptr));
        btnPrintInvoice->setText(QCoreApplication::translate("WInvoice", "Print\n"
"invoice", nullptr));
        btnPaymentsDetails->setText(QCoreApplication::translate("WInvoice", "Payment\n"
"details", nullptr));
        btnPayment->setText(QCoreApplication::translate("WInvoice", "Payment", nullptr));
        label->setText(QCoreApplication::translate("WInvoice", "Room", nullptr));
        btnPrevInvoice->setText(QString());
        btnNextInvoice->setText(QString());
        label_2->setText(QCoreApplication::translate("WInvoice", "Remarks", nullptr));
        label_8->setText(QCoreApplication::translate("WInvoice", "Invoice #", nullptr));
        label_4->setText(QCoreApplication::translate("WInvoice", "Check in date", nullptr));
        label_16->setText(QCoreApplication::translate("WInvoice", "Reserve #", nullptr));
        label_21->setText(QCoreApplication::translate("WInvoice", "Check in\n"
"operator", nullptr));
        label_23->setText(QCoreApplication::translate("WInvoice", "Check in time", nullptr));
        label_5->setText(QCoreApplication::translate("WInvoice", "Departure", nullptr));
        label_18->setText(QCoreApplication::translate("WInvoice", "Registered guest", nullptr));
        label_17->setText(QCoreApplication::translate("WInvoice", "Guest count", nullptr));
        label_24->setText(QCoreApplication::translate("WInvoice", "Arrangement", nullptr));
        label_19->setText(QCoreApplication::translate("WInvoice", "VAT", nullptr));
        label_9->setText(QCoreApplication::translate("WInvoice", "Room rate", nullptr));
        label_10->setText(QCoreApplication::translate("WInvoice", "Nights", nullptr));
        label_3->setText(QCoreApplication::translate("WInvoice", "Guest", nullptr));
        label_28->setText(QCoreApplication::translate("WInvoice", "City ledger", nullptr));
        label_7->setText(QCoreApplication::translate("WInvoice", "Cardex ", nullptr));
        label_6->setText(QCoreApplication::translate("WInvoice", "Passport", nullptr));
        label_22->setText(QCoreApplication::translate("WInvoice", "Booking No", nullptr));
        label_11->setText(QCoreApplication::translate("WInvoice", "Payment by guest", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblInvLeft->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WInvoice", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblInvLeft->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WInvoice", "Sign", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblInvLeft->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WInvoice", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblInvLeft->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WInvoice", "Item name", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblInvLeft->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WInvoice", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblInvLeft->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WInvoice", "VAT", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblInvLeft->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WInvoice", "Tax", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblInvLeft->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("WInvoice", "Remarks", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblInvLeft->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("WInvoice", "Source", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblInvLeft->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("WInvoice", "SourceId", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblInvLeft->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("WInvoice", "Btn", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblInvLeft->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("WInvoice", "ItemId", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblInvLeft->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("WInvoice", "ItemGroup", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblInvLeft->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("WInvoice", "PaymentMode", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tblInvLeft->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("WInvoice", "FiscalMachine", nullptr));
        label_20->setText(QCoreApplication::translate("WInvoice", "Prepaid", nullptr));
        lePrepaid->setText(QCoreApplication::translate("WInvoice", "0", nullptr));
        label_13->setText(QCoreApplication::translate("WInvoice", "Total", nullptr));
        label_12->setText(QCoreApplication::translate("WInvoice", "Payment by company", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tblInvRight->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("WInvoice", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tblInvRight->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("WInvoice", "Sign", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tblInvRight->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("WInvoice", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tblInvRight->horizontalHeaderItem(3);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("WInvoice", "Item name", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tblInvRight->horizontalHeaderItem(4);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("WInvoice", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tblInvRight->horizontalHeaderItem(5);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("WInvoice", "VAT", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tblInvRight->horizontalHeaderItem(6);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("WInvoice", "Tax", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tblInvRight->horizontalHeaderItem(7);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("WInvoice", "Remarks", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tblInvRight->horizontalHeaderItem(8);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("WInvoice", "Source", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tblInvRight->horizontalHeaderItem(9);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("WInvoice", "SourceId", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tblInvRight->horizontalHeaderItem(10);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("WInvoice", "Btn", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tblInvRight->horizontalHeaderItem(11);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("WInvoice", "ItemId", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tblInvRight->horizontalHeaderItem(12);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("WInvoice", "ItemGroup", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tblInvRight->horizontalHeaderItem(13);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("WInvoice", "PaymentMode", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tblInvRight->horizontalHeaderItem(14);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("WInvoice", "FiscalMachine", nullptr));
        label_14->setText(QCoreApplication::translate("WInvoice", "Total", nullptr));
        btnLeft->setText(QString());
        btnDoubleLeft->setText(QString());
        btnRight->setText(QString());
        btnDoubleRight->setText(QString());
        btnRefTax->setText(QString());
        btnShowLeft->setText(QCoreApplication::translate("WInvoice", "<1", nullptr));
        btnShowRight->setText(QCoreApplication::translate("WInvoice", "2>", nullptr));
        label_15->setText(QCoreApplication::translate("WInvoice", "Grand total", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WInvoice: public Ui_WInvoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINVOICE_H
