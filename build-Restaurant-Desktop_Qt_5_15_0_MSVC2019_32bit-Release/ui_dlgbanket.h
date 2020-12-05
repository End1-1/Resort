/********************************************************************************
** Form generated from reading UI file 'dlgbanket.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGBANKET_H
#define UI_DLGBANKET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgBanket
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbState;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *btnNew;
    QToolButton *btnDraft;
    QToolButton *btnOpen;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *btnSave;
    QToolButton *btnTaxPrint;
    QToolButton *btnDuplicateFiscal;
    QToolButton *btnPrintReceipt;
    QToolButton *btnPrintDuplicate;
    QToolButton *btnExit;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_9;
    QDateEdit *deDate;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label;
    QLineEdit *leComment;
    QPushButton *btnSelectService;
    QLabel *label_7;
    QPushButton *btnHall;
    EQLineEdit *leService;
    EQLineEdit *leHall;
    QPushButton *btnComment;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    EQLineEdit *leGuests;
    QPushButton *btnGuestQty;
    QLabel *label_3;
    EQLineEdit *lePrice;
    QPushButton *btnPrice;
    QLabel *label_13;
    EQLineEdit *leTotal;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    EQLineEdit *leModeOfPayment;
    QPushButton *btnPayment;
    QLabel *label_5;
    EQLineEdit *lePaymentComment;
    QLabel *label_14;
    EQLineEdit *leNeedToPay;
    QWidget *widget_10;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QPushButton *btnPrepayment;
    QPushButton *pushButton;
    QLabel *label_12;
    QLabel *label_11;
    EQLineEdit *leModePrepaymentComment;
    QLabel *label_10;
    EQLineEdit *leModePrepayment;
    EQLineEdit *lePrepayment;
    EQLineEdit *lePrepaymentTax;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *DlgBanket)
    {
        if (DlgBanket->objectName().isEmpty())
            DlgBanket->setObjectName(QString::fromUtf8("DlgBanket"));
        DlgBanket->resize(1042, 593);
        DlgBanket->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(DlgBanket);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(DlgBanket);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_8 = new QWidget(frame);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        verticalLayout_2 = new QVBoxLayout(widget_8);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lbState = new QLabel(widget_8);
        lbState->setObjectName(QString::fromUtf8("lbState"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lbState->setFont(font);
        lbState->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lbState);


        gridLayout->addWidget(widget_8, 0, 0, 1, 1);

        widget_3 = new QWidget(frame);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btnNew = new QToolButton(widget_3);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));
        btnNew->setMinimumSize(QSize(60, 0));
        btnNew->setMaximumSize(QSize(5555, 5555));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/revive.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNew->setIcon(icon);
        btnNew->setIconSize(QSize(32, 32));
        btnNew->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnNew);

        btnDraft = new QToolButton(widget_3);
        btnDraft->setObjectName(QString::fromUtf8("btnDraft"));
        btnDraft->setMinimumSize(QSize(60, 0));
        btnDraft->setMaximumSize(QSize(5555, 5555));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/draft.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDraft->setIcon(icon1);
        btnDraft->setIconSize(QSize(32, 32));
        btnDraft->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnDraft);

        btnOpen = new QToolButton(widget_3);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));
        btnOpen->setMinimumSize(QSize(60, 0));
        btnOpen->setMaximumSize(QSize(5555, 5555));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOpen->setIcon(icon2);
        btnOpen->setIconSize(QSize(32, 32));
        btnOpen->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnOpen);

        horizontalSpacer_3 = new QSpacerItem(681, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        btnSave = new QToolButton(widget_3);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(60, 0));
        btnSave->setMaximumSize(QSize(5555, 5555));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon3);
        btnSave->setIconSize(QSize(32, 32));
        btnSave->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnSave);

        btnTaxPrint = new QToolButton(widget_3);
        btnTaxPrint->setObjectName(QString::fromUtf8("btnTaxPrint"));
        btnTaxPrint->setMinimumSize(QSize(60, 0));
        btnTaxPrint->setMaximumSize(QSize(5555, 5555));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/tax.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTaxPrint->setIcon(icon4);
        btnTaxPrint->setIconSize(QSize(32, 32));
        btnTaxPrint->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnTaxPrint);

        btnDuplicateFiscal = new QToolButton(widget_3);
        btnDuplicateFiscal->setObjectName(QString::fromUtf8("btnDuplicateFiscal"));
        btnDuplicateFiscal->setMinimumSize(QSize(60, 0));
        btnDuplicateFiscal->setMaximumSize(QSize(5555, 5555));
        btnDuplicateFiscal->setIcon(icon4);
        btnDuplicateFiscal->setIconSize(QSize(32, 32));
        btnDuplicateFiscal->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnDuplicateFiscal);

        btnPrintReceipt = new QToolButton(widget_3);
        btnPrintReceipt->setObjectName(QString::fromUtf8("btnPrintReceipt"));
        btnPrintReceipt->setMinimumSize(QSize(60, 0));
        btnPrintReceipt->setMaximumSize(QSize(5555, 5555));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/invoice.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrintReceipt->setIcon(icon5);
        btnPrintReceipt->setIconSize(QSize(32, 32));
        btnPrintReceipt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnPrintReceipt);

        btnPrintDuplicate = new QToolButton(widget_3);
        btnPrintDuplicate->setObjectName(QString::fromUtf8("btnPrintDuplicate"));
        btnPrintDuplicate->setMinimumSize(QSize(60, 0));
        btnPrintDuplicate->setMaximumSize(QSize(5555, 5555));
        btnPrintDuplicate->setIcon(icon5);
        btnPrintDuplicate->setIconSize(QSize(32, 32));
        btnPrintDuplicate->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnPrintDuplicate);

        btnExit = new QToolButton(widget_3);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setMinimumSize(QSize(60, 0));
        btnExit->setMaximumSize(QSize(5555, 5555));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExit->setIcon(icon6);
        btnExit->setIconSize(QSize(32, 32));
        btnExit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_4->addWidget(btnExit);


        gridLayout->addWidget(widget_3, 6, 0, 1, 2);

        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget_9 = new QWidget(widget);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_9 = new QHBoxLayout(widget_9);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        deDate = new QDateEdit(widget_9);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setCalendarPopup(true);

        horizontalLayout_9->addWidget(deDate);


        gridLayout_3->addWidget(widget_9, 0, 4, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(180, 0));
        label_6->setMaximumSize(QSize(180, 16777215));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 0, 3, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(180, 0));
        label->setMaximumSize(QSize(180, 16777215));
        label->setFont(font);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        leComment = new QLineEdit(widget);
        leComment->setObjectName(QString::fromUtf8("leComment"));
        leComment->setMaximumSize(QSize(16777215, 16777215));
        leComment->setReadOnly(true);

        gridLayout_3->addWidget(leComment, 1, 4, 1, 1);

        btnSelectService = new QPushButton(widget);
        btnSelectService->setObjectName(QString::fromUtf8("btnSelectService"));
        btnSelectService->setMaximumSize(QSize(100, 16777215));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/banket.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSelectService->setIcon(icon7);

        gridLayout_3->addWidget(btnSelectService, 0, 2, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(180, 0));
        label_7->setMaximumSize(QSize(180, 16777215));

        gridLayout_3->addWidget(label_7, 1, 3, 1, 1);

        btnHall = new QPushButton(widget);
        btnHall->setObjectName(QString::fromUtf8("btnHall"));
        btnHall->setMaximumSize(QSize(100, 16777215));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/hall.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHall->setIcon(icon8);

        gridLayout_3->addWidget(btnHall, 1, 2, 1, 1);

        leService = new EQLineEdit(widget);
        leService->setObjectName(QString::fromUtf8("leService"));
        leService->setMaximumSize(QSize(16777215, 16777215));
        leService->setReadOnly(true);

        gridLayout_3->addWidget(leService, 0, 1, 1, 1);

        leHall = new EQLineEdit(widget);
        leHall->setObjectName(QString::fromUtf8("leHall"));
        leHall->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(leHall, 1, 1, 1, 1);

        btnComment = new QPushButton(widget);
        btnComment->setObjectName(QString::fromUtf8("btnComment"));
        btnComment->setMaximumSize(QSize(100, 16777215));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnComment->setIcon(icon9);

        gridLayout_3->addWidget(btnComment, 1, 5, 1, 1);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        widget_2 = new QWidget(frame);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(150, 0));
        label_2->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_3->addWidget(label_2);

        leGuests = new EQLineEdit(widget_2);
        leGuests->setObjectName(QString::fromUtf8("leGuests"));
        leGuests->setMinimumSize(QSize(100, 0));
        leGuests->setMaximumSize(QSize(100, 16777215));
        leGuests->setReadOnly(true);

        horizontalLayout_3->addWidget(leGuests);

        btnGuestQty = new QPushButton(widget_2);
        btnGuestQty->setObjectName(QString::fromUtf8("btnGuestQty"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/guests.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGuestQty->setIcon(icon10);

        horizontalLayout_3->addWidget(btnGuestQty);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(150, 0));
        label_3->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_3->addWidget(label_3);

        lePrice = new EQLineEdit(widget_2);
        lePrice->setObjectName(QString::fromUtf8("lePrice"));
        lePrice->setMinimumSize(QSize(150, 0));
        lePrice->setMaximumSize(QSize(150, 16777215));
        lePrice->setReadOnly(true);

        horizontalLayout_3->addWidget(lePrice);

        btnPrice = new QPushButton(widget_2);
        btnPrice->setObjectName(QString::fromUtf8("btnPrice"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/cash.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrice->setIcon(icon11);

        horizontalLayout_3->addWidget(btnPrice);

        label_13 = new QLabel(widget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(150, 0));
        label_13->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_3->addWidget(label_13);

        leTotal = new EQLineEdit(widget_2);
        leTotal->setObjectName(QString::fromUtf8("leTotal"));
        leTotal->setEnabled(true);
        leTotal->setReadOnly(true);

        horizontalLayout_3->addWidget(leTotal);


        gridLayout->addWidget(widget_2, 3, 0, 1, 2);

        widget_4 = new QWidget(frame);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_6 = new QHBoxLayout(widget_4);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(150, 0));
        label_4->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_6->addWidget(label_4);

        leModeOfPayment = new EQLineEdit(widget_4);
        leModeOfPayment->setObjectName(QString::fromUtf8("leModeOfPayment"));
        leModeOfPayment->setMinimumSize(QSize(100, 0));
        leModeOfPayment->setMaximumSize(QSize(100, 16777215));
        leModeOfPayment->setReadOnly(true);

        horizontalLayout_6->addWidget(leModeOfPayment);

        btnPayment = new QPushButton(widget_4);
        btnPayment->setObjectName(QString::fromUtf8("btnPayment"));
        btnPayment->setMinimumSize(QSize(0, 0));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/wallet-with-money.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPayment->setIcon(icon12);

        horizontalLayout_6->addWidget(btnPayment);

        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(150, 0));
        label_5->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_6->addWidget(label_5);

        lePaymentComment = new EQLineEdit(widget_4);
        lePaymentComment->setObjectName(QString::fromUtf8("lePaymentComment"));
        lePaymentComment->setMinimumSize(QSize(150, 0));
        lePaymentComment->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_6->addWidget(lePaymentComment);

        label_14 = new QLabel(widget_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(150, 0));
        label_14->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_6->addWidget(label_14);

        leNeedToPay = new EQLineEdit(widget_4);
        leNeedToPay->setObjectName(QString::fromUtf8("leNeedToPay"));
        leNeedToPay->setReadOnly(true);

        horizontalLayout_6->addWidget(leNeedToPay);


        gridLayout->addWidget(widget_4, 4, 0, 1, 2);

        widget_10 = new QWidget(frame);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setMinimumSize(QSize(0, 0));
        widget_10->setStyleSheet(QString::fromUtf8("background:#b2c3cc;"));
        gridLayout_2 = new QGridLayout(widget_10);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_8 = new QLabel(widget_10);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(180, 0));
        label_8->setMaximumSize(QSize(180, 16777215));
        label_8->setFont(font);

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        btnPrepayment = new QPushButton(widget_10);
        btnPrepayment->setObjectName(QString::fromUtf8("btnPrepayment"));
        btnPrepayment->setMinimumSize(QSize(25, 25));
        btnPrepayment->setMaximumSize(QSize(25, 25));
        btnPrepayment->setIcon(icon11);

        gridLayout_2->addWidget(btnPrepayment, 0, 2, 1, 1);

        pushButton = new QPushButton(widget_10);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(25, 25));
        pushButton->setMaximumSize(QSize(25, 25));
        pushButton->setIcon(icon12);

        gridLayout_2->addWidget(pushButton, 1, 2, 1, 1);

        label_12 = new QLabel(widget_10);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(180, 0));
        label_12->setMaximumSize(QSize(180, 16777215));

        gridLayout_2->addWidget(label_12, 0, 3, 1, 1);

        label_11 = new QLabel(widget_10);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(180, 0));
        label_11->setMaximumSize(QSize(180, 16777215));

        gridLayout_2->addWidget(label_11, 1, 3, 1, 1);

        leModePrepaymentComment = new EQLineEdit(widget_10);
        leModePrepaymentComment->setObjectName(QString::fromUtf8("leModePrepaymentComment"));
        leModePrepaymentComment->setMaximumSize(QSize(200, 16777215));
        leModePrepaymentComment->setReadOnly(true);

        gridLayout_2->addWidget(leModePrepaymentComment, 1, 4, 1, 2);

        label_10 = new QLabel(widget_10);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(180, 0));
        label_10->setMaximumSize(QSize(180, 16777215));

        gridLayout_2->addWidget(label_10, 1, 0, 1, 1);

        leModePrepayment = new EQLineEdit(widget_10);
        leModePrepayment->setObjectName(QString::fromUtf8("leModePrepayment"));
        leModePrepayment->setMinimumSize(QSize(150, 0));
        leModePrepayment->setMaximumSize(QSize(200, 16777215));
        leModePrepayment->setReadOnly(true);

        gridLayout_2->addWidget(leModePrepayment, 1, 1, 1, 1);

        lePrepayment = new EQLineEdit(widget_10);
        lePrepayment->setObjectName(QString::fromUtf8("lePrepayment"));
        lePrepayment->setMinimumSize(QSize(100, 0));
        lePrepayment->setMaximumSize(QSize(200, 16777215));
        lePrepayment->setReadOnly(true);

        gridLayout_2->addWidget(lePrepayment, 0, 1, 1, 1);

        lePrepaymentTax = new EQLineEdit(widget_10);
        lePrepaymentTax->setObjectName(QString::fromUtf8("lePrepaymentTax"));
        lePrepaymentTax->setMaximumSize(QSize(200, 16777215));
        lePrepaymentTax->setReadOnly(true);

        gridLayout_2->addWidget(lePrepaymentTax, 0, 4, 1, 1);

        pushButton_2 = new QPushButton(widget_10);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 0, 5, 1, 1);


        gridLayout->addWidget(widget_10, 2, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 316, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);


        horizontalLayout->addWidget(frame);


        retranslateUi(DlgBanket);

        QMetaObject::connectSlotsByName(DlgBanket);
    } // setupUi

    void retranslateUi(QDialog *DlgBanket)
    {
        DlgBanket->setWindowTitle(QCoreApplication::translate("DlgBanket", "Dialog", nullptr));
        lbState->setText(QCoreApplication::translate("DlgBanket", "DRAFT", nullptr));
        btnNew->setText(QCoreApplication::translate("DlgBanket", "CREATE NEW", nullptr));
        btnDraft->setText(QCoreApplication::translate("DlgBanket", "SAVE AS DRAFT", nullptr));
        btnOpen->setText(QCoreApplication::translate("DlgBanket", "OPEN DRAFT", nullptr));
        btnSave->setText(QCoreApplication::translate("DlgBanket", "SAVE", nullptr));
        btnTaxPrint->setText(QCoreApplication::translate("DlgBanket", "PRINT FISCAL", nullptr));
        btnDuplicateFiscal->setText(QCoreApplication::translate("DlgBanket", "DUPLICATE\n"
"FISCAL", nullptr));
        btnPrintReceipt->setText(QCoreApplication::translate("DlgBanket", "RECEIPT", nullptr));
        btnPrintDuplicate->setText(QCoreApplication::translate("DlgBanket", "DUPLICATE\n"
"RECEIPT", nullptr));
        btnExit->setText(QCoreApplication::translate("DlgBanket", "EXIT", nullptr));
        label_6->setText(QCoreApplication::translate("DlgBanket", "PLACE OF EVENT", nullptr));
        label_9->setText(QCoreApplication::translate("DlgBanket", "DATE OF EVENT", nullptr));
        label->setText(QCoreApplication::translate("DlgBanket", "THE NAME OF SERVICE", nullptr));
        btnSelectService->setText(QString());
        label_7->setText(QCoreApplication::translate("DlgBanket", "COMMENT", nullptr));
        btnHall->setText(QString());
        btnComment->setText(QString());
        label_2->setText(QCoreApplication::translate("DlgBanket", "GUEST COUNT", nullptr));
        btnGuestQty->setText(QString());
        label_3->setText(QCoreApplication::translate("DlgBanket", "AMOUNT PER \n"
"GUEST", nullptr));
        btnPrice->setText(QString());
        label_13->setText(QCoreApplication::translate("DlgBanket", "GRAND TOTAL", nullptr));
        label_4->setText(QCoreApplication::translate("DlgBanket", "MODE OF PAYMENT", nullptr));
        btnPayment->setText(QString());
        label_5->setText(QCoreApplication::translate("DlgBanket", "PAYMENT COMMENT", nullptr));
        label_14->setText(QCoreApplication::translate("DlgBanket", "NEED TO PAY", nullptr));
        label_8->setText(QCoreApplication::translate("DlgBanket", "PREPAYMENT", nullptr));
        btnPrepayment->setText(QString());
        pushButton->setText(QString());
        label_12->setText(QCoreApplication::translate("DlgBanket", "TAX NUMBER", nullptr));
        label_11->setText(QCoreApplication::translate("DlgBanket", "COMMENT", nullptr));
        label_10->setText(QCoreApplication::translate("DlgBanket", "MODE OF PREPAYMENT", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DlgBanket", "PRINT TAX", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgBanket: public Ui_DlgBanket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGBANKET_H
