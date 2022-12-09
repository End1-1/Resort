/********************************************************************************
** Form generated from reading UI file 'dlgtransferanyamount.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGTRANSFERANYAMOUNT_H
#define UI_DLGTRANSFERANYAMOUNT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>
#include <radiogroupwidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgTransferAnyAmount
{
public:
    QGridLayout *gridLayout_4;
    QPlainTextEdit *teRemarks;
    QGroupBox *grTo;
    QVBoxLayout *verticalLayout_2;
    RadioGroupWidget *wtoAction;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *rbtoReserve;
    QRadioButton *rbtoRoom;
    QRadioButton *rbtoCL;
    QSpacerItem *horizontalSpacer_3;
    QWidget *wtoCL;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_10;
    EQLineEdit *letoCL;
    EQLineEdit *letoCLName;
    QWidget *wtoRoom;
    QGridLayout *gridLayout_2;
    QLabel *label_13;
    QLabel *label_17;
    QLabel *label_12;
    EDateEdit *detoEntry;
    QLabel *label_16;
    QLabel *label_14;
    EQLineEdit *letoRoomCode;
    EQLineEdit *letoReserve;
    QLabel *label_11;
    QLabel *label_15;
    EQLineEdit *letoGuest;
    EQLineEdit *letoRoomName;
    EDateEdit *detoDeparture;
    EQLineEdit *letoInvoice;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_23;
    EQLineEdit *letoBalance;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_2;
    RadioGroupWidget *wDC;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbfromDebit;
    QRadioButton *rbfromCredit;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *grFrom;
    QVBoxLayout *verticalLayout;
    RadioGroupWidget *wfromAction;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbfromReserve;
    QRadioButton *rbfromRoom;
    QRadioButton *rbfromCL;
    QSpacerItem *horizontalSpacer;
    QWidget *wfromCL;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    EQLineEdit *lefromCL;
    EQLineEdit *lefromCLName;
    QWidget *wfromRoom;
    QGridLayout *gridLayout;
    EQLineEdit *lefromRoomName;
    QLabel *label_7;
    EDateEdit *defromDeparture;
    EQLineEdit *lefromInvoice;
    EQLineEdit *lefromGuest;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_8;
    EQLineEdit *lefromRoomCode;
    QLabel *label_3;
    QLabel *label_2;
    EQLineEdit *lefromReserve;
    EDateEdit *defromEntry;
    QLabel *label_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_19;
    EQLineEdit *lefromBalance;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_18;
    EDateEdit *dewDate;
    QLabel *label_9;
    EQLineEdit *leDebitVoucher;
    QLabel *label_21;
    EQLineEdit *leCreditVoucher;
    QSpacerItem *horizontalSpacer_9;
    QToolButton *btnLog;
    QWidget *widget_5;
    QGridLayout *gridLayout_3;
    QPushButton *btnCancel;
    QPushButton *btnSave;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_20;
    EQLineEdit *letoAmount;
    QLabel *label_22;
    EQLineEdit *leAmountUSD;

    void setupUi(QDialog *DlgTransferAnyAmount)
    {
        if (DlgTransferAnyAmount->objectName().isEmpty())
            DlgTransferAnyAmount->setObjectName(QString::fromUtf8("DlgTransferAnyAmount"));
        DlgTransferAnyAmount->resize(942, 579);
        gridLayout_4 = new QGridLayout(DlgTransferAnyAmount);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        teRemarks = new QPlainTextEdit(DlgTransferAnyAmount);
        teRemarks->setObjectName(QString::fromUtf8("teRemarks"));

        gridLayout_4->addWidget(teRemarks, 4, 0, 1, 2);

        grTo = new QGroupBox(DlgTransferAnyAmount);
        grTo->setObjectName(QString::fromUtf8("grTo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(grTo->sizePolicy().hasHeightForWidth());
        grTo->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(grTo);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        wtoAction = new RadioGroupWidget(grTo);
        wtoAction->setObjectName(QString::fromUtf8("wtoAction"));
        horizontalLayout_4 = new QHBoxLayout(wtoAction);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        rbtoReserve = new QRadioButton(wtoAction);
        rbtoReserve->setObjectName(QString::fromUtf8("rbtoReserve"));
        rbtoReserve->setFocusPolicy(Qt::NoFocus);
        rbtoReserve->setChecked(true);
        rbtoReserve->setProperty("Tag", QVariant(5));

        horizontalLayout_4->addWidget(rbtoReserve);

        rbtoRoom = new QRadioButton(wtoAction);
        rbtoRoom->setObjectName(QString::fromUtf8("rbtoRoom"));
        rbtoRoom->setFocusPolicy(Qt::NoFocus);
        rbtoRoom->setProperty("Tag", QVariant(4));

        horizontalLayout_4->addWidget(rbtoRoom);

        rbtoCL = new QRadioButton(wtoAction);
        rbtoCL->setObjectName(QString::fromUtf8("rbtoCL"));
        rbtoCL->setFocusPolicy(Qt::NoFocus);
        rbtoCL->setProperty("Tag", QVariant(6));

        horizontalLayout_4->addWidget(rbtoCL);

        horizontalSpacer_3 = new QSpacerItem(44, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(wtoAction);

        wtoCL = new QWidget(grTo);
        wtoCL->setObjectName(QString::fromUtf8("wtoCL"));
        horizontalLayout_6 = new QHBoxLayout(wtoCL);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_10 = new QLabel(wtoCL);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_6->addWidget(label_10);

        letoCL = new EQLineEdit(wtoCL);
        letoCL->setObjectName(QString::fromUtf8("letoCL"));
        letoCL->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(letoCL);

        letoCLName = new EQLineEdit(wtoCL);
        letoCLName->setObjectName(QString::fromUtf8("letoCLName"));
        letoCLName->setFocusPolicy(Qt::NoFocus);
        letoCLName->setReadOnly(true);

        horizontalLayout_6->addWidget(letoCLName);


        verticalLayout_2->addWidget(wtoCL);

        wtoRoom = new QWidget(grTo);
        wtoRoom->setObjectName(QString::fromUtf8("wtoRoom"));
        gridLayout_2 = new QGridLayout(wtoRoom);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_13 = new QLabel(wtoRoom);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 1, 0, 1, 1);

        label_17 = new QLabel(wtoRoom);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_2->addWidget(label_17, 3, 0, 1, 1);

        label_12 = new QLabel(wtoRoom);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 0, 2, 1, 1);

        detoEntry = new EDateEdit(wtoRoom);
        detoEntry->setObjectName(QString::fromUtf8("detoEntry"));
        detoEntry->setMaximumSize(QSize(100, 16777215));
        detoEntry->setFocusPolicy(Qt::NoFocus);
        detoEntry->setReadOnly(true);

        gridLayout_2->addWidget(detoEntry, 2, 1, 1, 1);

        label_16 = new QLabel(wtoRoom);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_2->addWidget(label_16, 2, 2, 1, 1);

        label_14 = new QLabel(wtoRoom);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 1, 2, 1, 1);

        letoRoomCode = new EQLineEdit(wtoRoom);
        letoRoomCode->setObjectName(QString::fromUtf8("letoRoomCode"));
        letoRoomCode->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(letoRoomCode, 0, 1, 1, 1);

        letoReserve = new EQLineEdit(wtoRoom);
        letoReserve->setObjectName(QString::fromUtf8("letoReserve"));
        letoReserve->setMaximumSize(QSize(100, 16777215));
        letoReserve->setFocusPolicy(Qt::StrongFocus);
        letoReserve->setReadOnly(true);

        gridLayout_2->addWidget(letoReserve, 1, 1, 1, 1);

        label_11 = new QLabel(wtoRoom);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        label_15 = new QLabel(wtoRoom);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_2->addWidget(label_15, 2, 0, 1, 1);

        letoGuest = new EQLineEdit(wtoRoom);
        letoGuest->setObjectName(QString::fromUtf8("letoGuest"));
        letoGuest->setReadOnly(true);

        gridLayout_2->addWidget(letoGuest, 3, 1, 1, 3);

        letoRoomName = new EQLineEdit(wtoRoom);
        letoRoomName->setObjectName(QString::fromUtf8("letoRoomName"));
        letoRoomName->setMaximumSize(QSize(100, 16777215));
        letoRoomName->setFocusPolicy(Qt::NoFocus);
        letoRoomName->setReadOnly(true);

        gridLayout_2->addWidget(letoRoomName, 0, 3, 1, 1);

        detoDeparture = new EDateEdit(wtoRoom);
        detoDeparture->setObjectName(QString::fromUtf8("detoDeparture"));
        detoDeparture->setMaximumSize(QSize(100, 16777215));
        detoDeparture->setFocusPolicy(Qt::NoFocus);
        detoDeparture->setReadOnly(true);

        gridLayout_2->addWidget(detoDeparture, 2, 3, 1, 1);

        letoInvoice = new EQLineEdit(wtoRoom);
        letoInvoice->setObjectName(QString::fromUtf8("letoInvoice"));
        letoInvoice->setMaximumSize(QSize(100, 16777215));
        letoInvoice->setFocusPolicy(Qt::NoFocus);
        letoInvoice->setReadOnly(true);

        gridLayout_2->addWidget(letoInvoice, 1, 3, 1, 1);


        verticalLayout_2->addWidget(wtoRoom);

        widget_2 = new QWidget(grTo);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 0));
        horizontalLayout_10 = new QHBoxLayout(widget_2);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_23 = new QLabel(widget_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_10->addWidget(label_23);

        letoBalance = new EQLineEdit(widget_2);
        letoBalance->setObjectName(QString::fromUtf8("letoBalance"));
        letoBalance->setMaximumSize(QSize(100, 16777215));
        letoBalance->setFocusPolicy(Qt::NoFocus);
        letoBalance->setReadOnly(true);

        horizontalLayout_10->addWidget(letoBalance);

        horizontalSpacer_10 = new QSpacerItem(269, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);


        verticalLayout_2->addWidget(widget_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout_4->addWidget(grTo, 2, 1, 1, 1);

        wDC = new RadioGroupWidget(DlgTransferAnyAmount);
        wDC->setObjectName(QString::fromUtf8("wDC"));
        wDC->setEnabled(false);
        horizontalLayout_2 = new QHBoxLayout(wDC);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rbfromDebit = new QRadioButton(wDC);
        rbfromDebit->setObjectName(QString::fromUtf8("rbfromDebit"));
        rbfromDebit->setFocusPolicy(Qt::NoFocus);
        rbfromDebit->setCheckable(true);
        rbfromDebit->setChecked(false);
        rbfromDebit->setProperty("Tag", QVariant(1));

        horizontalLayout_2->addWidget(rbfromDebit);

        rbfromCredit = new QRadioButton(wDC);
        rbfromCredit->setObjectName(QString::fromUtf8("rbfromCredit"));
        rbfromCredit->setFocusPolicy(Qt::NoFocus);
        rbfromCredit->setCheckable(true);
        rbfromCredit->setProperty("Tag", QVariant(2));

        horizontalLayout_2->addWidget(rbfromCredit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_4->addWidget(wDC, 1, 0, 1, 2);

        grFrom = new QGroupBox(DlgTransferAnyAmount);
        grFrom->setObjectName(QString::fromUtf8("grFrom"));
        sizePolicy.setHeightForWidth(grFrom->sizePolicy().hasHeightForWidth());
        grFrom->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(grFrom);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        wfromAction = new RadioGroupWidget(grFrom);
        wfromAction->setObjectName(QString::fromUtf8("wfromAction"));
        horizontalLayout = new QHBoxLayout(wfromAction);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rbfromReserve = new QRadioButton(wfromAction);
        rbfromReserve->setObjectName(QString::fromUtf8("rbfromReserve"));
        rbfromReserve->setFocusPolicy(Qt::NoFocus);
        rbfromReserve->setChecked(true);
        rbfromReserve->setProperty("Tag", QVariant(2));

        horizontalLayout->addWidget(rbfromReserve);

        rbfromRoom = new QRadioButton(wfromAction);
        rbfromRoom->setObjectName(QString::fromUtf8("rbfromRoom"));
        rbfromRoom->setFocusPolicy(Qt::NoFocus);
        rbfromRoom->setProperty("Tag", QVariant(1));

        horizontalLayout->addWidget(rbfromRoom);

        rbfromCL = new QRadioButton(wfromAction);
        rbfromCL->setObjectName(QString::fromUtf8("rbfromCL"));
        rbfromCL->setFocusPolicy(Qt::NoFocus);
        rbfromCL->setProperty("Tag", QVariant(3));

        horizontalLayout->addWidget(rbfromCL);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(wfromAction);

        wfromCL = new QWidget(grFrom);
        wfromCL->setObjectName(QString::fromUtf8("wfromCL"));
        horizontalLayout_3 = new QHBoxLayout(wfromCL);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(wfromCL);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        lefromCL = new EQLineEdit(wfromCL);
        lefromCL->setObjectName(QString::fromUtf8("lefromCL"));
        lefromCL->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(lefromCL);

        lefromCLName = new EQLineEdit(wfromCL);
        lefromCLName->setObjectName(QString::fromUtf8("lefromCLName"));
        lefromCLName->setFocusPolicy(Qt::NoFocus);
        lefromCLName->setReadOnly(true);

        horizontalLayout_3->addWidget(lefromCLName);


        verticalLayout->addWidget(wfromCL);

        wfromRoom = new QWidget(grFrom);
        wfromRoom->setObjectName(QString::fromUtf8("wfromRoom"));
        gridLayout = new QGridLayout(wfromRoom);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lefromRoomName = new EQLineEdit(wfromRoom);
        lefromRoomName->setObjectName(QString::fromUtf8("lefromRoomName"));
        lefromRoomName->setMaximumSize(QSize(100, 16777215));
        lefromRoomName->setFocusPolicy(Qt::NoFocus);
        lefromRoomName->setStyleSheet(QString::fromUtf8(""));
        lefromRoomName->setReadOnly(true);

        gridLayout->addWidget(lefromRoomName, 0, 3, 1, 1);

        label_7 = new QLabel(wfromRoom);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 2, 1, 1);

        defromDeparture = new EDateEdit(wfromRoom);
        defromDeparture->setObjectName(QString::fromUtf8("defromDeparture"));
        defromDeparture->setMaximumSize(QSize(100, 16777215));
        defromDeparture->setFocusPolicy(Qt::NoFocus);
        defromDeparture->setReadOnly(true);

        gridLayout->addWidget(defromDeparture, 2, 3, 1, 1);

        lefromInvoice = new EQLineEdit(wfromRoom);
        lefromInvoice->setObjectName(QString::fromUtf8("lefromInvoice"));
        lefromInvoice->setMaximumSize(QSize(100, 16777215));
        lefromInvoice->setFocusPolicy(Qt::NoFocus);
        lefromInvoice->setReadOnly(true);

        gridLayout->addWidget(lefromInvoice, 1, 3, 1, 1);

        lefromGuest = new EQLineEdit(wfromRoom);
        lefromGuest->setObjectName(QString::fromUtf8("lefromGuest"));
        lefromGuest->setFocusPolicy(Qt::NoFocus);
        lefromGuest->setReadOnly(true);

        gridLayout->addWidget(lefromGuest, 3, 1, 1, 3);

        label_6 = new QLabel(wfromRoom);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        label_4 = new QLabel(wfromRoom);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_8 = new QLabel(wfromRoom);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        lefromRoomCode = new EQLineEdit(wfromRoom);
        lefromRoomCode->setObjectName(QString::fromUtf8("lefromRoomCode"));
        lefromRoomCode->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lefromRoomCode, 0, 1, 1, 1);

        label_3 = new QLabel(wfromRoom);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_2 = new QLabel(wfromRoom);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lefromReserve = new EQLineEdit(wfromRoom);
        lefromReserve->setObjectName(QString::fromUtf8("lefromReserve"));
        lefromReserve->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lefromReserve, 1, 1, 1, 1);

        defromEntry = new EDateEdit(wfromRoom);
        defromEntry->setObjectName(QString::fromUtf8("defromEntry"));
        defromEntry->setMaximumSize(QSize(100, 16777215));
        defromEntry->setFocusPolicy(Qt::NoFocus);
        defromEntry->setReadOnly(true);

        gridLayout->addWidget(defromEntry, 2, 1, 1, 1);

        label_5 = new QLabel(wfromRoom);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);


        verticalLayout->addWidget(wfromRoom);

        widget = new QWidget(grFrom);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 0));
        horizontalLayout_8 = new QHBoxLayout(widget);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_19 = new QLabel(widget);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_8->addWidget(label_19);

        lefromBalance = new EQLineEdit(widget);
        lefromBalance->setObjectName(QString::fromUtf8("lefromBalance"));
        lefromBalance->setMaximumSize(QSize(100, 16777215));
        lefromBalance->setFocusPolicy(Qt::NoFocus);
        lefromBalance->setReadOnly(true);

        horizontalLayout_8->addWidget(lefromBalance);

        horizontalSpacer_7 = new QSpacerItem(269, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_4->addWidget(grFrom, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(DlgTransferAnyAmount);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_7->addWidget(label_18);

        dewDate = new EDateEdit(groupBox_2);
        dewDate->setObjectName(QString::fromUtf8("dewDate"));
        dewDate->setMaximumSize(QSize(100, 16777215));
        dewDate->setFocusPolicy(Qt::NoFocus);
        dewDate->setReadOnly(true);

        horizontalLayout_7->addWidget(dewDate);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        leDebitVoucher = new EQLineEdit(groupBox_2);
        leDebitVoucher->setObjectName(QString::fromUtf8("leDebitVoucher"));
        leDebitVoucher->setMaximumSize(QSize(100, 16777215));
        leDebitVoucher->setFocusPolicy(Qt::NoFocus);
        leDebitVoucher->setReadOnly(true);

        horizontalLayout_7->addWidget(leDebitVoucher);

        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_7->addWidget(label_21);

        leCreditVoucher = new EQLineEdit(groupBox_2);
        leCreditVoucher->setObjectName(QString::fromUtf8("leCreditVoucher"));
        leCreditVoucher->setMaximumSize(QSize(100, 16777215));
        leCreditVoucher->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_7->addWidget(leCreditVoucher);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);

        btnLog = new QToolButton(groupBox_2);
        btnLog->setObjectName(QString::fromUtf8("btnLog"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/tracking.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLog->setIcon(icon);

        horizontalLayout_7->addWidget(btnLog);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 2);

        widget_5 = new QWidget(DlgTransferAnyAmount);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        gridLayout_3 = new QGridLayout(widget_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        btnCancel = new QPushButton(widget_5);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        gridLayout_3->addWidget(btnCancel, 1, 2, 1, 1);

        btnSave = new QPushButton(widget_5);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        gridLayout_3->addWidget(btnSave, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(299, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 1, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(300, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 0, 1, 1);


        gridLayout_4->addWidget(widget_5, 5, 0, 1, 2);

        widget_3 = new QWidget(DlgTransferAnyAmount);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMinimumSize(QSize(0, 0));
        horizontalLayout_9 = new QHBoxLayout(widget_3);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_20 = new QLabel(widget_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_9->addWidget(label_20);

        letoAmount = new EQLineEdit(widget_3);
        letoAmount->setObjectName(QString::fromUtf8("letoAmount"));
        letoAmount->setMinimumSize(QSize(100, 0));
        letoAmount->setMaximumSize(QSize(100, 16777215));
        letoAmount->setReadOnly(false);

        horizontalLayout_9->addWidget(letoAmount);

        label_22 = new QLabel(widget_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_9->addWidget(label_22);

        leAmountUSD = new EQLineEdit(widget_3);
        leAmountUSD->setObjectName(QString::fromUtf8("leAmountUSD"));
        leAmountUSD->setMinimumSize(QSize(100, 0));
        leAmountUSD->setMaximumSize(QSize(100, 16777215));
        leAmountUSD->setFocusPolicy(Qt::NoFocus);
        leAmountUSD->setReadOnly(true);

        horizontalLayout_9->addWidget(leAmountUSD);


        gridLayout_4->addWidget(widget_3, 3, 1, 1, 1);

        QWidget::setTabOrder(lefromCL, letoCL);
        QWidget::setTabOrder(letoCL, lefromRoomCode);
        QWidget::setTabOrder(lefromRoomCode, lefromReserve);
        QWidget::setTabOrder(lefromReserve, letoRoomCode);
        QWidget::setTabOrder(letoRoomCode, letoReserve);
        QWidget::setTabOrder(letoReserve, letoGuest);
        QWidget::setTabOrder(letoGuest, letoAmount);
        QWidget::setTabOrder(letoAmount, teRemarks);
        QWidget::setTabOrder(teRemarks, btnCancel);
        QWidget::setTabOrder(btnCancel, btnSave);

        retranslateUi(DlgTransferAnyAmount);

        QMetaObject::connectSlotsByName(DlgTransferAnyAmount);
    } // setupUi

    void retranslateUi(QDialog *DlgTransferAnyAmount)
    {
        DlgTransferAnyAmount->setWindowTitle(QCoreApplication::translate("DlgTransferAnyAmount", "Transfer amount", nullptr));
        teRemarks->setPlaceholderText(QCoreApplication::translate("DlgTransferAnyAmount", "Remarks", nullptr));
        grTo->setTitle(QCoreApplication::translate("DlgTransferAnyAmount", "Transfer to", nullptr));
        rbtoReserve->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Reseravation advance", nullptr));
        rbtoRoom->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Checkin room", nullptr));
        rbtoCL->setText(QCoreApplication::translate("DlgTransferAnyAmount", "City ledger", nullptr));
        label_10->setText(QCoreApplication::translate("DlgTransferAnyAmount", "CityLedger", nullptr));
        label_13->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Reservation code", nullptr));
        label_17->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Guest", nullptr));
        label_12->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Room name", nullptr));
        label_16->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Dearture", nullptr));
        label_14->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Invoice", nullptr));
        label_11->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Room code", nullptr));
        label_15->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Entry", nullptr));
        label_23->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Balance", nullptr));
        rbfromDebit->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Debit", nullptr));
        rbfromCredit->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Credit", nullptr));
        grFrom->setTitle(QCoreApplication::translate("DlgTransferAnyAmount", "Transfer from", nullptr));
        rbfromReserve->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Reseravation advance", nullptr));
        rbfromRoom->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Checkin room", nullptr));
        rbfromCL->setText(QCoreApplication::translate("DlgTransferAnyAmount", "City ledger", nullptr));
        label->setText(QCoreApplication::translate("DlgTransferAnyAmount", "CityLedger", nullptr));
        label_7->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Dearture", nullptr));
        label_6->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Invoice", nullptr));
        label_4->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Entry", nullptr));
        label_8->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Guest", nullptr));
        lefromRoomCode->setPlaceholderText(QString());
        label_3->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Room name", nullptr));
        label_2->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Room code", nullptr));
        label_5->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Reservation code", nullptr));
        label_19->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Balance", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DlgTransferAnyAmount", "Voucher", nullptr));
        label_18->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Voucher date", nullptr));
        label_9->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Debit voucher code", nullptr));
        label_21->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Credit voucher code", nullptr));
        btnLog->setText(QString());
        btnCancel->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Cancel", nullptr));
        btnSave->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Save", nullptr));
        label_20->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Amount for transfer", nullptr));
        label_22->setText(QCoreApplication::translate("DlgTransferAnyAmount", "Amount USD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgTransferAnyAmount: public Ui_DlgTransferAnyAmount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGTRANSFERANYAMOUNT_H
