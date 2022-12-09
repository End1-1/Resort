/********************************************************************************
** Form generated from reading UI file 'waccinvoice.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WACCINVOICE_H
#define UI_WACCINVOICE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqcheckbox.h>
#include <eqdateedit.h>
#include <eqlineedit.h>
#include <eqtablewidget.h>
#include <eqtimeedit.h>

QT_BEGIN_NAMESPACE

class Ui_WAccInvoice
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *btnPostingCharges;
    QToolButton *btnNewVaucher;
    QToolButton *btnEditRowVaucher;
    QToolButton *btnViewReserv;
    QToolButton *btnEditReserv;
    QPushButton *btnPrint;
    QPushButton *btnTaxPrint;
    QPushButton *btnExcel;
    QPushButton *btnTaxBack;
    QPushButton *btnViewCorrections;
    QPushButton *btnMoveItem;
    QPushButton *btnEliminate;
    QPushButton *btnChangeCL;
    QPushButton *btnMoveToCL;
    QPushButton *btnExportAS;
    QPushButton *btnExportASRetail;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnTracking;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *btnPreviouse;
    EQLineEdit *leInvoice;
    QPushButton *btnNext;
    EQLineEdit *leReservationId;
    QLabel *label_19;
    QComboBox *cbCurrency;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    EQLineEdit *leVatCode;
    QLabel *label_17;
    QLabel *label_16;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_18;
    EQTimeEdit *teCheckOutTime;
    EQTimeEdit *teCheckInTime;
    QPushButton *btnGuestInfo;
    EQLineEdit *leGuest;
    QLabel *label_10;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    EQCheckBox *chPaymentByCompany;
    QRadioButton *rbNoGroup;
    QRadioButton *rbEntryName;
    QLabel *label_12;
    EQCheckBox *chPaymentByGuest;
    QLabel *label_13;
    QCheckBox *chViewAllVauchers;
    EQLineEdit *leCategory;
    QLabel *label_8;
    EQDateEdit *deEntry;
    QLabel *label_7;
    EQLineEdit *leVATMode;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    EQDateEdit *deDeparture;
    EQLineEdit *leNationality;
    EQLineEdit *leArrangment;
    EQLineEdit *leRoom;
    EQLineEdit *leGuestCount;
    EQDateEdit *deCheckIn;
    QLabel *label_11;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_9;
    EQLineEdit *leCardex;
    EQLineEdit *leCardexCode;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout;
    EQTableWidget *tblData;
    EQTableWidget *tblTotal;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *teRemarks;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_14;
    EQLineEdit *leOperatorIn;
    QLabel *label_15;
    EQLineEdit *leOperatorOut;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *WAccInvoice)
    {
        if (WAccInvoice->objectName().isEmpty())
            WAccInvoice->setObjectName(QString::fromUtf8("WAccInvoice"));
        WAccInvoice->resize(1453, 555);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WAccInvoice->sizePolicy().hasHeightForWidth());
        WAccInvoice->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(WAccInvoice);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_5 = new QWidget(WAccInvoice);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(0, 0));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        btnPostingCharges = new QToolButton(widget_5);
        btnPostingCharges->setObjectName(QString::fromUtf8("btnPostingCharges"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnPostingCharges->sizePolicy().hasHeightForWidth());
        btnPostingCharges->setSizePolicy(sizePolicy1);
        btnPostingCharges->setMinimumSize(QSize(0, 0));
        btnPostingCharges->setMaximumSize(QSize(16777215, 21212));
        btnPostingCharges->setFocusPolicy(Qt::ClickFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/charge.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPostingCharges->setIcon(icon);
        btnPostingCharges->setIconSize(QSize(20, 20));
        btnPostingCharges->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_4->addWidget(btnPostingCharges);

        btnNewVaucher = new QToolButton(widget_5);
        btnNewVaucher->setObjectName(QString::fromUtf8("btnNewVaucher"));
        sizePolicy1.setHeightForWidth(btnNewVaucher->sizePolicy().hasHeightForWidth());
        btnNewVaucher->setSizePolicy(sizePolicy1);
        btnNewVaucher->setMinimumSize(QSize(0, 0));
        btnNewVaucher->setMaximumSize(QSize(16777215, 21212));
        btnNewVaucher->setFocusPolicy(Qt::ClickFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/invoice.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNewVaucher->setIcon(icon1);
        btnNewVaucher->setIconSize(QSize(20, 20));
        btnNewVaucher->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_4->addWidget(btnNewVaucher);

        btnEditRowVaucher = new QToolButton(widget_5);
        btnEditRowVaucher->setObjectName(QString::fromUtf8("btnEditRowVaucher"));
        sizePolicy1.setHeightForWidth(btnEditRowVaucher->sizePolicy().hasHeightForWidth());
        btnEditRowVaucher->setSizePolicy(sizePolicy1);
        btnEditRowVaucher->setMinimumSize(QSize(0, 0));
        btnEditRowVaucher->setMaximumSize(QSize(16777215, 21212));
        btnEditRowVaucher->setFocusPolicy(Qt::ClickFocus);
        btnEditRowVaucher->setIcon(icon1);
        btnEditRowVaucher->setIconSize(QSize(20, 20));
        btnEditRowVaucher->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_4->addWidget(btnEditRowVaucher);

        btnViewReserv = new QToolButton(widget_5);
        btnViewReserv->setObjectName(QString::fromUtf8("btnViewReserv"));
        sizePolicy1.setHeightForWidth(btnViewReserv->sizePolicy().hasHeightForWidth());
        btnViewReserv->setSizePolicy(sizePolicy1);
        btnViewReserv->setMinimumSize(QSize(0, 0));
        btnViewReserv->setMaximumSize(QSize(16777215, 21212));
        btnViewReserv->setFocusPolicy(Qt::ClickFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/bed.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnViewReserv->setIcon(icon2);
        btnViewReserv->setIconSize(QSize(20, 20));
        btnViewReserv->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_4->addWidget(btnViewReserv);

        btnEditReserv = new QToolButton(widget_5);
        btnEditReserv->setObjectName(QString::fromUtf8("btnEditReserv"));
        sizePolicy1.setHeightForWidth(btnEditReserv->sizePolicy().hasHeightForWidth());
        btnEditReserv->setSizePolicy(sizePolicy1);
        btnEditReserv->setMinimumSize(QSize(0, 0));
        btnEditReserv->setMaximumSize(QSize(16777215, 21212));
        btnEditReserv->setFocusPolicy(Qt::ClickFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEditReserv->setIcon(icon3);
        btnEditReserv->setIconSize(QSize(20, 20));
        btnEditReserv->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_4->addWidget(btnEditReserv);

        btnPrint = new QPushButton(widget_5);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        btnPrint->setMaximumSize(QSize(1212, 21212));
        btnPrint->setFocusPolicy(Qt::ClickFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrint->setIcon(icon4);

        horizontalLayout_4->addWidget(btnPrint);

        btnTaxPrint = new QPushButton(widget_5);
        btnTaxPrint->setObjectName(QString::fromUtf8("btnTaxPrint"));
        btnTaxPrint->setMaximumSize(QSize(21545, 21212));
        btnTaxPrint->setFocusPolicy(Qt::ClickFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/tax.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTaxPrint->setIcon(icon5);

        horizontalLayout_4->addWidget(btnTaxPrint);

        btnExcel = new QPushButton(widget_5);
        btnExcel->setObjectName(QString::fromUtf8("btnExcel"));
        btnExcel->setMaximumSize(QSize(21545, 21212));
        btnExcel->setFocusPolicy(Qt::ClickFocus);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/excel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExcel->setIcon(icon6);

        horizontalLayout_4->addWidget(btnExcel);

        btnTaxBack = new QPushButton(widget_5);
        btnTaxBack->setObjectName(QString::fromUtf8("btnTaxBack"));
        btnTaxBack->setMaximumSize(QSize(21545, 21212));
        btnTaxBack->setFocusPolicy(Qt::ClickFocus);
        btnTaxBack->setIcon(icon5);

        horizontalLayout_4->addWidget(btnTaxBack);

        btnViewCorrections = new QPushButton(widget_5);
        btnViewCorrections->setObjectName(QString::fromUtf8("btnViewCorrections"));
        btnViewCorrections->setMaximumSize(QSize(21545, 21212));
        btnViewCorrections->setFocusPolicy(Qt::ClickFocus);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/garbage.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnViewCorrections->setIcon(icon7);

        horizontalLayout_4->addWidget(btnViewCorrections);

        btnMoveItem = new QPushButton(widget_5);
        btnMoveItem->setObjectName(QString::fromUtf8("btnMoveItem"));
        btnMoveItem->setMaximumSize(QSize(222, 222));
        btnMoveItem->setFocusPolicy(Qt::ClickFocus);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/goto.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMoveItem->setIcon(icon8);

        horizontalLayout_4->addWidget(btnMoveItem);

        btnEliminate = new QPushButton(widget_5);
        btnEliminate->setObjectName(QString::fromUtf8("btnEliminate"));
        btnEliminate->setMaximumSize(QSize(21545, 21212));
        btnEliminate->setFocusPolicy(Qt::ClickFocus);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/biohazard.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEliminate->setIcon(icon9);

        horizontalLayout_4->addWidget(btnEliminate);

        btnChangeCL = new QPushButton(widget_5);
        btnChangeCL->setObjectName(QString::fromUtf8("btnChangeCL"));
        btnChangeCL->setMaximumSize(QSize(21545, 21212));
        btnChangeCL->setFocusPolicy(Qt::ClickFocus);
        btnChangeCL->setIcon(icon9);

        horizontalLayout_4->addWidget(btnChangeCL);

        btnMoveToCL = new QPushButton(widget_5);
        btnMoveToCL->setObjectName(QString::fromUtf8("btnMoveToCL"));
        btnMoveToCL->setMaximumSize(QSize(21545, 21212));
        btnMoveToCL->setFocusPolicy(Qt::ClickFocus);
        btnMoveToCL->setIcon(icon9);

        horizontalLayout_4->addWidget(btnMoveToCL);

        btnExportAS = new QPushButton(widget_5);
        btnExportAS->setObjectName(QString::fromUtf8("btnExportAS"));
        btnExportAS->setMaximumSize(QSize(21545, 21212));
        btnExportAS->setFocusPolicy(Qt::ClickFocus);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/AS.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExportAS->setIcon(icon10);

        horizontalLayout_4->addWidget(btnExportAS);

        btnExportASRetail = new QPushButton(widget_5);
        btnExportASRetail->setObjectName(QString::fromUtf8("btnExportASRetail"));
        btnExportASRetail->setMaximumSize(QSize(21545, 21212));
        btnExportASRetail->setFocusPolicy(Qt::ClickFocus);
        btnExportASRetail->setIcon(icon10);

        horizontalLayout_4->addWidget(btnExportASRetail);

        horizontalSpacer_3 = new QSpacerItem(200, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        btnTracking = new QPushButton(widget_5);
        btnTracking->setObjectName(QString::fromUtf8("btnTracking"));
        btnTracking->setFocusPolicy(Qt::ClickFocus);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/tracking.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTracking->setIcon(icon11);

        horizontalLayout_4->addWidget(btnTracking);


        verticalLayout_4->addWidget(widget_5);

        widget = new QWidget(WAccInvoice);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setFocusPolicy(Qt::ClickFocus);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(label);

        btnPreviouse = new QPushButton(widget);
        btnPreviouse->setObjectName(QString::fromUtf8("btnPreviouse"));
        sizePolicy1.setHeightForWidth(btnPreviouse->sizePolicy().hasHeightForWidth());
        btnPreviouse->setSizePolicy(sizePolicy1);
        btnPreviouse->setMaximumSize(QSize(25, 25));
        btnPreviouse->setFocusPolicy(Qt::ClickFocus);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPreviouse->setIcon(icon12);

        horizontalLayout->addWidget(btnPreviouse);

        leInvoice = new EQLineEdit(widget);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setMinimumSize(QSize(100, 0));
        leInvoice->setMaximumSize(QSize(100, 16777215));
        leInvoice->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(leInvoice);

        btnNext = new QPushButton(widget);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        sizePolicy1.setHeightForWidth(btnNext->sizePolicy().hasHeightForWidth());
        btnNext->setSizePolicy(sizePolicy1);
        btnNext->setMaximumSize(QSize(25, 25));
        btnNext->setFocusPolicy(Qt::ClickFocus);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon13);

        horizontalLayout->addWidget(btnNext);

        leReservationId = new EQLineEdit(widget);
        leReservationId->setObjectName(QString::fromUtf8("leReservationId"));
        leReservationId->setFocusPolicy(Qt::ClickFocus);
        leReservationId->setReadOnly(true);

        horizontalLayout->addWidget(leReservationId);

        label_19 = new QLabel(widget);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout->addWidget(label_19);

        cbCurrency = new QComboBox(widget);
        cbCurrency->setObjectName(QString::fromUtf8("cbCurrency"));

        horizontalLayout->addWidget(cbCurrency);

        horizontalSpacer = new QSpacerItem(562, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_4->addWidget(widget);

        widget_3 = new QWidget(WAccInvoice);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setFocusPolicy(Qt::ClickFocus);
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        leVatCode = new EQLineEdit(widget_3);
        leVatCode->setObjectName(QString::fromUtf8("leVatCode"));
        leVatCode->setMaximumSize(QSize(30, 16777215));
        leVatCode->setFocusPolicy(Qt::ClickFocus);
        leVatCode->setReadOnly(true);

        gridLayout->addWidget(leVatCode, 1, 12, 1, 1);

        label_17 = new QLabel(widget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_17, 1, 8, 1, 1);

        label_16 = new QLabel(widget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_16, 2, 8, 1, 1);

        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_5, 0, 13, 1, 1);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_18 = new QLabel(widget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_18, 1, 11, 1, 1);

        teCheckOutTime = new EQTimeEdit(widget_3);
        teCheckOutTime->setObjectName(QString::fromUtf8("teCheckOutTime"));
        teCheckOutTime->setEnabled(false);
        teCheckOutTime->setFocusPolicy(Qt::ClickFocus);
        teCheckOutTime->setReadOnly(true);

        gridLayout->addWidget(teCheckOutTime, 2, 7, 1, 1);

        teCheckInTime = new EQTimeEdit(widget_3);
        teCheckInTime->setObjectName(QString::fromUtf8("teCheckInTime"));
        teCheckInTime->setEnabled(false);
        teCheckInTime->setFocusPolicy(Qt::ClickFocus);
        teCheckInTime->setReadOnly(true);

        gridLayout->addWidget(teCheckInTime, 1, 7, 1, 1);

        btnGuestInfo = new QPushButton(widget_3);
        btnGuestInfo->setObjectName(QString::fromUtf8("btnGuestInfo"));
        btnGuestInfo->setMinimumSize(QSize(25, 25));
        btnGuestInfo->setMaximumSize(QSize(25, 25));
        btnGuestInfo->setFocusPolicy(Qt::ClickFocus);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/question.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGuestInfo->setIcon(icon14);

        gridLayout->addWidget(btnGuestInfo, 0, 5, 1, 1);

        leGuest = new EQLineEdit(widget_3);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setMinimumSize(QSize(250, 0));
        leGuest->setFocusPolicy(Qt::ClickFocus);
        leGuest->setReadOnly(true);

        gridLayout->addWidget(leGuest, 0, 6, 1, 7);

        label_10 = new QLabel(widget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_10, 2, 6, 1, 1);

        groupBox = new QGroupBox(widget_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(16777215, 5555));
        groupBox->setFocusPolicy(Qt::ClickFocus);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        chPaymentByCompany = new EQCheckBox(groupBox);
        chPaymentByCompany->setObjectName(QString::fromUtf8("chPaymentByCompany"));
        chPaymentByCompany->setFocusPolicy(Qt::ClickFocus);
        chPaymentByCompany->setCheckable(true);
        chPaymentByCompany->setChecked(true);

        gridLayout_2->addWidget(chPaymentByCompany, 2, 0, 1, 1);

        rbNoGroup = new QRadioButton(groupBox);
        rbNoGroup->setObjectName(QString::fromUtf8("rbNoGroup"));
        rbNoGroup->setFocusPolicy(Qt::ClickFocus);
        rbNoGroup->setChecked(true);

        gridLayout_2->addWidget(rbNoGroup, 1, 1, 1, 1);

        rbEntryName = new QRadioButton(groupBox);
        rbEntryName->setObjectName(QString::fromUtf8("rbEntryName"));
        rbEntryName->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(rbEntryName, 2, 1, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(label_12, 0, 0, 1, 1);

        chPaymentByGuest = new EQCheckBox(groupBox);
        chPaymentByGuest->setObjectName(QString::fromUtf8("chPaymentByGuest"));
        chPaymentByGuest->setFocusPolicy(Qt::ClickFocus);
        chPaymentByGuest->setCheckable(true);
        chPaymentByGuest->setChecked(true);

        gridLayout_2->addWidget(chPaymentByGuest, 1, 0, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(label_13, 0, 1, 1, 1);

        chViewAllVauchers = new QCheckBox(groupBox);
        chViewAllVauchers->setObjectName(QString::fromUtf8("chViewAllVauchers"));
        chViewAllVauchers->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(chViewAllVauchers, 1, 2, 1, 1);


        gridLayout->addWidget(groupBox, 0, 15, 3, 1);

        leCategory = new EQLineEdit(widget_3);
        leCategory->setObjectName(QString::fromUtf8("leCategory"));
        leCategory->setMaximumSize(QSize(40, 16777215));
        leCategory->setFocusPolicy(Qt::ClickFocus);
        leCategory->setReadOnly(true);

        gridLayout->addWidget(leCategory, 0, 1, 1, 1);

        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_8, 1, 3, 1, 1);

        deEntry = new EQDateEdit(widget_3);
        deEntry->setObjectName(QString::fromUtf8("deEntry"));
        deEntry->setEnabled(false);
        deEntry->setFocusPolicy(Qt::ClickFocus);
        deEntry->setReadOnly(true);

        gridLayout->addWidget(deEntry, 1, 1, 1, 2);

        label_7 = new QLabel(widget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        leVATMode = new EQLineEdit(widget_3);
        leVATMode->setObjectName(QString::fromUtf8("leVATMode"));
        leVATMode->setFocusPolicy(Qt::ClickFocus);
        leVATMode->setReadOnly(true);

        gridLayout->addWidget(leVATMode, 1, 13, 1, 2);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_4, 0, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 16, 1, 1);

        deDeparture = new EQDateEdit(widget_3);
        deDeparture->setObjectName(QString::fromUtf8("deDeparture"));
        deDeparture->setEnabled(false);
        deDeparture->setFocusPolicy(Qt::ClickFocus);
        deDeparture->setReadOnly(true);

        gridLayout->addWidget(deDeparture, 2, 1, 1, 2);

        leNationality = new EQLineEdit(widget_3);
        leNationality->setObjectName(QString::fromUtf8("leNationality"));
        leNationality->setMaximumSize(QSize(100, 16777215));
        leNationality->setFocusPolicy(Qt::ClickFocus);
        leNationality->setReadOnly(true);

        gridLayout->addWidget(leNationality, 0, 14, 1, 1);

        leArrangment = new EQLineEdit(widget_3);
        leArrangment->setObjectName(QString::fromUtf8("leArrangment"));
        leArrangment->setMaximumSize(QSize(80, 16777215));
        leArrangment->setFocusPolicy(Qt::ClickFocus);
        leArrangment->setReadOnly(true);

        gridLayout->addWidget(leArrangment, 2, 4, 1, 1);

        leRoom = new EQLineEdit(widget_3);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setMaximumSize(QSize(50, 16777215));
        leRoom->setFocusPolicy(Qt::ClickFocus);
        leRoom->setReadOnly(true);

        gridLayout->addWidget(leRoom, 0, 3, 1, 1);

        leGuestCount = new EQLineEdit(widget_3);
        leGuestCount->setObjectName(QString::fromUtf8("leGuestCount"));
        leGuestCount->setMaximumSize(QSize(40, 16777215));
        leGuestCount->setFocusPolicy(Qt::ClickFocus);
        leGuestCount->setReadOnly(true);

        gridLayout->addWidget(leGuestCount, 1, 10, 1, 1);

        deCheckIn = new EQDateEdit(widget_3);
        deCheckIn->setObjectName(QString::fromUtf8("deCheckIn"));
        deCheckIn->setEnabled(false);
        deCheckIn->setFocusPolicy(Qt::ClickFocus);
        deCheckIn->setReadOnly(true);

        gridLayout->addWidget(deCheckIn, 1, 4, 1, 1);

        label_11 = new QLabel(widget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_11, 2, 3, 1, 1);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_6 = new QLabel(widget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        label_9 = new QLabel(widget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_9, 1, 6, 1, 1);

        leCardex = new EQLineEdit(widget_3);
        leCardex->setObjectName(QString::fromUtf8("leCardex"));
        leCardex->setFocusPolicy(Qt::ClickFocus);
        leCardex->setReadOnly(true);

        gridLayout->addWidget(leCardex, 2, 10, 1, 5);

        leCardexCode = new EQLineEdit(widget_3);
        leCardexCode->setObjectName(QString::fromUtf8("leCardexCode"));
        leCardexCode->setMaximumSize(QSize(50, 16777215));
        leCardexCode->setFocusPolicy(Qt::ClickFocus);
        leCardexCode->setReadOnly(true);

        gridLayout->addWidget(leCardexCode, 2, 9, 1, 1);


        verticalLayout_4->addWidget(widget_3);

        widget_2 = new QWidget(WAccInvoice);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy2);
        widget_2->setFocusPolicy(Qt::ClickFocus);
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setFocusPolicy(Qt::ClickFocus);
        verticalLayout = new QVBoxLayout(widget_4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tblData = new EQTableWidget(widget_4);
        if (tblData->columnCount() < 12)
            tblData->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        tblData->setFocusPolicy(Qt::ClickFocus);
        tblData->setFrameShape(QFrame::Box);
        tblData->setFrameShadow(QFrame::Sunken);
        tblData->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblData->setTabKeyNavigation(true);
        tblData->setSelectionMode(QAbstractItemView::SingleSelection);
        tblData->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblData->verticalHeader()->setVisible(false);
        tblData->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout->addWidget(tblData);

        tblTotal = new EQTableWidget(widget_4);
        if (tblTotal->columnCount() < 10)
            tblTotal->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(5, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(6, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(7, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(8, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(9, __qtablewidgetitem21);
        tblTotal->setObjectName(QString::fromUtf8("tblTotal"));
        tblTotal->setMinimumSize(QSize(0, 55));
        tblTotal->setMaximumSize(QSize(16777215, 55));
        tblTotal->setFocusPolicy(Qt::ClickFocus);
        tblTotal->setFrameShape(QFrame::Box);
        tblTotal->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblTotal->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblTotal->setSelectionMode(QAbstractItemView::NoSelection);
        tblTotal->horizontalHeader()->setVisible(false);
        tblTotal->verticalHeader()->setVisible(false);
        tblTotal->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout->addWidget(tblTotal);


        horizontalLayout_3->addWidget(widget_4);


        verticalLayout_4->addWidget(widget_2);

        groupBox_2 = new QGroupBox(WAccInvoice);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy3);
        groupBox_2->setFocusPolicy(Qt::ClickFocus);
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        teRemarks = new QTextEdit(groupBox_2);
        teRemarks->setObjectName(QString::fromUtf8("teRemarks"));
        teRemarks->setMaximumSize(QSize(16777215, 50));
        teRemarks->setFocusPolicy(Qt::ClickFocus);
        teRemarks->setFrameShape(QFrame::Box);
        teRemarks->setFrameShadow(QFrame::Sunken);
        teRemarks->setReadOnly(true);

        verticalLayout_3->addWidget(teRemarks);


        verticalLayout_4->addWidget(groupBox_2);

        frame = new QFrame(WAccInvoice);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFocusPolicy(Qt::ClickFocus);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(frame);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_2->addWidget(label_14);

        leOperatorIn = new EQLineEdit(frame);
        leOperatorIn->setObjectName(QString::fromUtf8("leOperatorIn"));
        leOperatorIn->setMinimumSize(QSize(300, 0));
        leOperatorIn->setFocusPolicy(Qt::ClickFocus);
        leOperatorIn->setReadOnly(true);

        horizontalLayout_2->addWidget(leOperatorIn);

        label_15 = new QLabel(frame);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_2->addWidget(label_15);

        leOperatorOut = new EQLineEdit(frame);
        leOperatorOut->setObjectName(QString::fromUtf8("leOperatorOut"));
        leOperatorOut->setMinimumSize(QSize(300, 0));
        leOperatorOut->setFocusPolicy(Qt::ClickFocus);
        leOperatorOut->setReadOnly(true);

        horizontalLayout_2->addWidget(leOperatorOut);

        horizontalSpacer_4 = new QSpacerItem(42, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_4->addWidget(frame);


        retranslateUi(WAccInvoice);

        QMetaObject::connectSlotsByName(WAccInvoice);
    } // setupUi

    void retranslateUi(QWidget *WAccInvoice)
    {
        WAccInvoice->setWindowTitle(QCoreApplication::translate("WAccInvoice", "Invoice", nullptr));
        btnPostingCharges->setText(QCoreApplication::translate("WAccInvoice", "Posting\n"
"Charges", nullptr));
        btnNewVaucher->setText(QCoreApplication::translate("WAccInvoice", "New\n"
"voucher", nullptr));
        btnEditRowVaucher->setText(QCoreApplication::translate("WAccInvoice", "Edit raw\n"
"voucher", nullptr));
        btnViewReserv->setText(QCoreApplication::translate("WAccInvoice", "View\n"
"Reserve", nullptr));
        btnEditReserv->setText(QCoreApplication::translate("WAccInvoice", "Edit\n"
"Reserve", nullptr));
#if QT_CONFIG(tooltip)
        btnPrint->setToolTip(QCoreApplication::translate("WAccInvoice", "Print invoice", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPrint->setText(QCoreApplication::translate("WAccInvoice", "Print invoice", nullptr));
#if QT_CONFIG(tooltip)
        btnTaxPrint->setToolTip(QCoreApplication::translate("WAccInvoice", "Print fiscal", nullptr));
#endif // QT_CONFIG(tooltip)
        btnTaxPrint->setText(QCoreApplication::translate("WAccInvoice", "Print tax", nullptr));
#if QT_CONFIG(tooltip)
        btnExcel->setToolTip(QCoreApplication::translate("WAccInvoice", "Print fiscal", nullptr));
#endif // QT_CONFIG(tooltip)
        btnExcel->setText(QCoreApplication::translate("WAccInvoice", "Excel", nullptr));
#if QT_CONFIG(tooltip)
        btnTaxBack->setToolTip(QCoreApplication::translate("WAccInvoice", "Print fiscal", nullptr));
#endif // QT_CONFIG(tooltip)
        btnTaxBack->setText(QCoreApplication::translate("WAccInvoice", "Tax back", nullptr));
        btnViewCorrections->setText(QCoreApplication::translate("WAccInvoice", "Corrections", nullptr));
        btnMoveItem->setText(QCoreApplication::translate("WAccInvoice", "Move entry", nullptr));
        btnEliminate->setText(QCoreApplication::translate("WAccInvoice", "Eliminate Entry", nullptr));
        btnChangeCL->setText(QCoreApplication::translate("WAccInvoice", "Change CL", nullptr));
        btnMoveToCL->setText(QCoreApplication::translate("WAccInvoice", "MOVE TO CL", nullptr));
        btnExportAS->setText(QCoreApplication::translate("WAccInvoice", "To AS invoice", nullptr));
        btnExportASRetail->setText(QCoreApplication::translate("WAccInvoice", "To AS retail", nullptr));
#if QT_CONFIG(tooltip)
        btnTracking->setToolTip(QCoreApplication::translate("WAccInvoice", "Show history", nullptr));
#endif // QT_CONFIG(tooltip)
        btnTracking->setText(QString());
        label->setText(QCoreApplication::translate("WAccInvoice", "Invoice #", nullptr));
#if QT_CONFIG(tooltip)
        btnPreviouse->setToolTip(QCoreApplication::translate("WAccInvoice", "Previouse invoice", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPreviouse->setText(QString());
#if QT_CONFIG(tooltip)
        btnNext->setToolTip(QCoreApplication::translate("WAccInvoice", "Next invoice", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNext->setText(QString());
        leReservationId->setPlaceholderText(QCoreApplication::translate("WAccInvoice", "reservation id", nullptr));
        label_19->setText(QCoreApplication::translate("WAccInvoice", "Currency", nullptr));
        label_17->setText(QCoreApplication::translate("WAccInvoice", "Guest qty", nullptr));
        label_16->setText(QCoreApplication::translate("WAccInvoice", "Cardex", nullptr));
        label_5->setText(QCoreApplication::translate("WAccInvoice", "Nationality", nullptr));
        label_3->setText(QCoreApplication::translate("WAccInvoice", "Entry", nullptr));
        label_18->setText(QCoreApplication::translate("WAccInvoice", "VAT", nullptr));
        btnGuestInfo->setText(QString());
        label_10->setText(QCoreApplication::translate("WAccInvoice", "CheckOut\n"
"time", nullptr));
        groupBox->setTitle(QCoreApplication::translate("WAccInvoice", "Options", nullptr));
        chPaymentByCompany->setText(QCoreApplication::translate("WAccInvoice", "Company", nullptr));
        rbNoGroup->setText(QCoreApplication::translate("WAccInvoice", "No group", nullptr));
        rbEntryName->setText(QCoreApplication::translate("WAccInvoice", "Entry name", nullptr));
        label_12->setText(QCoreApplication::translate("WAccInvoice", "Payment by", nullptr));
        chPaymentByGuest->setText(QCoreApplication::translate("WAccInvoice", "Guest", nullptr));
        label_13->setText(QCoreApplication::translate("WAccInvoice", "Group by", nullptr));
        chViewAllVauchers->setText(QCoreApplication::translate("WAccInvoice", "Show hidden vauchers", nullptr));
        label_8->setText(QCoreApplication::translate("WAccInvoice", "CheckIn\n"
"date", nullptr));
        label_7->setText(QCoreApplication::translate("WAccInvoice", "Departure", nullptr));
        label_4->setText(QCoreApplication::translate("WAccInvoice", "Guest", nullptr));
        label_11->setText(QCoreApplication::translate("WAccInvoice", "Arrangment", nullptr));
        label_2->setText(QCoreApplication::translate("WAccInvoice", "Room", nullptr));
        label_6->setText(QCoreApplication::translate("WAccInvoice", "Category", nullptr));
        label_9->setText(QCoreApplication::translate("WAccInvoice", "CheckIn\n"
"time", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WAccInvoice", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WAccInvoice", "Sel", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WAccInvoice", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WAccInvoice", "Sale", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WAccInvoice", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblData->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WAccInvoice", "Debit", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblData->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WAccInvoice", "Credit", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblData->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("WAccInvoice", "VAT", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblData->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("WAccInvoice", "Tax", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblData->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("WAccInvoice", "Side", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblData->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("WAccInvoice", "Source", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblData->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("WAccInvoice", "Source id", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblTotal->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("WAccInvoice", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblTotal->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("WAccInvoice", "Sel", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tblTotal->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("WAccInvoice", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tblTotal->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("WAccInvoice", "ItemCode", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tblTotal->horizontalHeaderItem(4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("WAccInvoice", "Item", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tblTotal->horizontalHeaderItem(5);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("WAccInvoice", "Debit", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tblTotal->horizontalHeaderItem(6);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("WAccInvoice", "Credit", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tblTotal->horizontalHeaderItem(7);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("WAccInvoice", "VAT", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tblTotal->horizontalHeaderItem(8);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("WAccInvoice", "Tax", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tblTotal->horizontalHeaderItem(9);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("WAccInvoice", "Side", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("WAccInvoice", "Remarks", nullptr));
        label_14->setText(QCoreApplication::translate("WAccInvoice", "Operator in", nullptr));
        label_15->setText(QCoreApplication::translate("WAccInvoice", "Operator out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WAccInvoice: public Ui_WAccInvoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WACCINVOICE_H
