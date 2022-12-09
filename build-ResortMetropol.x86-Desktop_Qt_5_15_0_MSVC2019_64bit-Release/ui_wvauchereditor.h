/********************************************************************************
** Form generated from reading UI file 'wvauchereditor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WVAUCHEREDITOR_H
#define UI_WVAUCHEREDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>
#include <eqtimeedit.h>

QT_BEGIN_NAMESPACE

class Ui_WVaucherEditor
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnNewVaucher;
    QToolButton *btnSave;
    QToolButton *btnPrint;
    QToolButton *btnTrack;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label_30;
    EQLineEdit *leFinalName;
    QLabel *label_6;
    EQLineEdit *leSourceCode;
    QLabel *label_5;
    EQLineEdit *leUserName;
    EQLineEdit *leUserCode;
    QLabel *label_7;
    EQLineEdit *leVATName;
    EQLineEdit *lePayName;
    QLabel *label_18;
    QLabel *label_9;
    QLabel *label_8;
    EQLineEdit *leItemCode;
    EQLineEdit *lePayComment;
    QLabel *label_19;
    EQLineEdit *leItemName;
    QLabel *label_24;
    EQLineEdit *leAmount;
    QLineEdit *leReservation;
    EQTimeEdit *teTime;
    QLabel *label_17;
    QLabel *label_16;
    EQLineEdit *leVAT;
    EQLineEdit *leGuestName;
    QLabel *label_3;
    EQLineEdit *leSourceName;
    EQLineEdit *leCLName;
    QLabel *label_10;
    EQLineEdit *leInvoice;
    EDateEdit *deWorking;
    EQLineEdit *leCLCode;
    QLabel *label_15;
    EDateEdit *deReal;
    QLabel *label_4;
    QLabel *label_2;
    EQLineEdit *leCardCode;
    EQLineEdit *leVATCode;
    EQLineEdit *leRoom;
    QLabel *label;
    EQLineEdit *leCardName;
    EQLineEdit *leCode;
    EQLineEdit *lePayCode;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    EQLineEdit *leCancelUserName;
    EQLineEdit *leCancelFlag;
    EQLineEdit *leFiscal;
    QLabel *label_29;
    QLabel *label_31;
    QLabel *label_26;
    QLabel *label_20;
    QLabel *label_22;
    QLabel *label_25;
    QLabel *label_14;
    QLabel *label_13;
    QLabel *label_12;
    EQLineEdit *leDoc;
    EQLineEdit *leCancelReason;
    QLabel *label_21;
    EQLineEdit *leRb;
    QLabel *label_23;
    EQLineEdit *lePrepaid;
    EQLineEdit *leUSD;
    QPlainTextEdit *teRemarks;
    QLabel *label_27;
    EQLineEdit *leGuestCompany;
    EQLineEdit *leSign;
    QLabel *label_28;
    EQLineEdit *leDC;
    QLabel *label_11;
    EQLineEdit *leFinFlag;
    QDateTimeEdit *deCancelDate;
    EQLineEdit *leCancelUserCode;
    QLabel *label_32;
    EQLineEdit *leRec;

    void setupUi(QDialog *WVaucherEditor)
    {
        if (WVaucherEditor->objectName().isEmpty())
            WVaucherEditor->setObjectName(QString::fromUtf8("WVaucherEditor"));
        WVaucherEditor->resize(548, 557);
        gridLayout_3 = new QGridLayout(WVaucherEditor);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget_4 = new QWidget(WVaucherEditor);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnNewVaucher = new QToolButton(widget_4);
        btnNewVaucher->setObjectName(QString::fromUtf8("btnNewVaucher"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNewVaucher->setIcon(icon);

        horizontalLayout->addWidget(btnNewVaucher);

        btnSave = new QToolButton(widget_4);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon1);

        horizontalLayout->addWidget(btnSave);

        btnPrint = new QToolButton(widget_4);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrint->setIcon(icon2);

        horizontalLayout->addWidget(btnPrint);

        btnTrack = new QToolButton(widget_4);
        btnTrack->setObjectName(QString::fromUtf8("btnTrack"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/tracking.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTrack->setIcon(icon3);

        horizontalLayout->addWidget(btnTrack);

        horizontalSpacer = new QSpacerItem(1129, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_3->addWidget(widget_4, 0, 0, 1, 2);

        tabWidget = new QTabWidget(WVaucherEditor);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_30 = new QLabel(widget_2);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout->addWidget(label_30, 14, 0, 1, 1);

        leFinalName = new EQLineEdit(widget_2);
        leFinalName->setObjectName(QString::fromUtf8("leFinalName"));
        leFinalName->setMinimumSize(QSize(80, 0));
        leFinalName->setMaximumSize(QSize(80000, 16777215));

        gridLayout->addWidget(leFinalName, 18, 2, 1, 4);

        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        leSourceCode = new EQLineEdit(widget_2);
        leSourceCode->setObjectName(QString::fromUtf8("leSourceCode"));
        leSourceCode->setMinimumSize(QSize(80, 0));
        leSourceCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leSourceCode, 2, 2, 1, 1);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        leUserName = new EQLineEdit(widget_2);
        leUserName->setObjectName(QString::fromUtf8("leUserName"));
        leUserName->setEnabled(false);
        leUserName->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(leUserName, 5, 3, 1, 1);

        leUserCode = new EQLineEdit(widget_2);
        leUserCode->setObjectName(QString::fromUtf8("leUserCode"));
        leUserCode->setMinimumSize(QSize(80, 0));
        leUserCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leUserCode, 5, 2, 1, 1);

        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        leVATName = new EQLineEdit(widget_2);
        leVATName->setObjectName(QString::fromUtf8("leVATName"));
        leVATName->setEnabled(false);

        gridLayout->addWidget(leVATName, 14, 3, 1, 1);

        lePayName = new EQLineEdit(widget_2);
        lePayName->setObjectName(QString::fromUtf8("lePayName"));
        lePayName->setEnabled(false);
        lePayName->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(lePayName, 10, 3, 1, 1);

        label_18 = new QLabel(widget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout->addWidget(label_18, 12, 0, 1, 1);

        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 18, 0, 1, 1);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 8, 0, 1, 1);

        leItemCode = new EQLineEdit(widget_2);
        leItemCode->setObjectName(QString::fromUtf8("leItemCode"));
        leItemCode->setMinimumSize(QSize(80, 0));
        leItemCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leItemCode, 8, 2, 1, 1);

        lePayComment = new EQLineEdit(widget_2);
        lePayComment->setObjectName(QString::fromUtf8("lePayComment"));

        gridLayout->addWidget(lePayComment, 13, 2, 1, 2);

        label_19 = new QLabel(widget_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout->addWidget(label_19, 13, 0, 1, 1);

        leItemName = new EQLineEdit(widget_2);
        leItemName->setObjectName(QString::fromUtf8("leItemName"));
        leItemName->setEnabled(false);
        leItemName->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(leItemName, 8, 3, 1, 1);

        label_24 = new QLabel(widget_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout->addWidget(label_24, 1, 0, 1, 1);

        leAmount = new EQLineEdit(widget_2);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setMinimumSize(QSize(80, 0));
        leAmount->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leAmount, 16, 2, 1, 1);

        leReservation = new QLineEdit(widget_2);
        leReservation->setObjectName(QString::fromUtf8("leReservation"));

        gridLayout->addWidget(leReservation, 1, 3, 1, 1);

        teTime = new EQTimeEdit(widget_2);
        teTime->setObjectName(QString::fromUtf8("teTime"));

        gridLayout->addWidget(teTime, 4, 3, 1, 1);

        label_17 = new QLabel(widget_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 11, 0, 1, 1);

        label_16 = new QLabel(widget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 10, 0, 1, 1);

        leVAT = new EQLineEdit(widget_2);
        leVAT->setObjectName(QString::fromUtf8("leVAT"));
        leVAT->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leVAT, 17, 2, 1, 1);

        leGuestName = new EQLineEdit(widget_2);
        leGuestName->setObjectName(QString::fromUtf8("leGuestName"));
        leGuestName->setEnabled(true);
        leGuestName->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(leGuestName, 7, 2, 1, 3);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        leSourceName = new EQLineEdit(widget_2);
        leSourceName->setObjectName(QString::fromUtf8("leSourceName"));
        leSourceName->setEnabled(false);

        gridLayout->addWidget(leSourceName, 2, 3, 1, 1);

        leCLName = new EQLineEdit(widget_2);
        leCLName->setObjectName(QString::fromUtf8("leCLName"));
        leCLName->setEnabled(false);
        leCLName->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(leCLName, 12, 3, 1, 1);

        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 16, 0, 1, 1);

        leInvoice = new EQLineEdit(widget_2);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));

        gridLayout->addWidget(leInvoice, 1, 2, 1, 1);

        deWorking = new EDateEdit(widget_2);
        deWorking->setObjectName(QString::fromUtf8("deWorking"));

        gridLayout->addWidget(deWorking, 3, 2, 1, 1);

        leCLCode = new EQLineEdit(widget_2);
        leCLCode->setObjectName(QString::fromUtf8("leCLCode"));
        leCLCode->setMinimumSize(QSize(80, 0));
        leCLCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCLCode, 12, 2, 1, 1);

        label_15 = new QLabel(widget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 17, 0, 1, 1);

        deReal = new EDateEdit(widget_2);
        deReal->setObjectName(QString::fromUtf8("deReal"));

        gridLayout->addWidget(deReal, 4, 2, 1, 1);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        leCardCode = new EQLineEdit(widget_2);
        leCardCode->setObjectName(QString::fromUtf8("leCardCode"));
        leCardCode->setMinimumSize(QSize(80, 0));
        leCardCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCardCode, 11, 2, 1, 1);

        leVATCode = new EQLineEdit(widget_2);
        leVATCode->setObjectName(QString::fromUtf8("leVATCode"));
        leVATCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leVATCode, 14, 2, 1, 1);

        leRoom = new EQLineEdit(widget_2);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setMinimumSize(QSize(80, 0));
        leRoom->setMaximumSize(QSize(8000, 16777215));

        gridLayout->addWidget(leRoom, 6, 2, 1, 3);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leCardName = new EQLineEdit(widget_2);
        leCardName->setObjectName(QString::fromUtf8("leCardName"));
        leCardName->setEnabled(false);
        leCardName->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(leCardName, 11, 3, 1, 1);

        leCode = new EQLineEdit(widget_2);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setEnabled(false);
        leCode->setMinimumSize(QSize(80, 0));
        leCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCode, 0, 2, 1, 2);

        lePayCode = new EQLineEdit(widget_2);
        lePayCode->setObjectName(QString::fromUtf8("lePayCode"));
        lePayCode->setMinimumSize(QSize(80, 0));
        lePayCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lePayCode, 10, 2, 1, 1);


        verticalLayout->addWidget(widget_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new QWidget(tab_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(500, 0));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        leCancelUserName = new EQLineEdit(widget);
        leCancelUserName->setObjectName(QString::fromUtf8("leCancelUserName"));
        leCancelUserName->setEnabled(false);

        gridLayout_4->addWidget(leCancelUserName, 10, 3, 1, 1);

        leCancelFlag = new EQLineEdit(widget);
        leCancelFlag->setObjectName(QString::fromUtf8("leCancelFlag"));

        gridLayout_4->addWidget(leCancelFlag, 9, 2, 1, 2);

        leFiscal = new EQLineEdit(widget);
        leFiscal->setObjectName(QString::fromUtf8("leFiscal"));
        leFiscal->setMinimumSize(QSize(80, 0));
        leFiscal->setMaximumSize(QSize(80, 16777215));

        gridLayout_4->addWidget(leFiscal, 5, 2, 1, 1);

        label_29 = new QLabel(widget);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_4->addWidget(label_29, 13, 0, 1, 1);

        label_31 = new QLabel(widget);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_4->addWidget(label_31, 0, 0, 1, 1);

        label_26 = new QLabel(widget);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_4->addWidget(label_26, 14, 0, 1, 2);

        label_20 = new QLabel(widget);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_4->addWidget(label_20, 2, 0, 1, 1);

        label_22 = new QLabel(widget);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_4->addWidget(label_22, 9, 0, 1, 1);

        label_25 = new QLabel(widget);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_4->addWidget(label_25, 8, 0, 1, 1);

        label_14 = new QLabel(widget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_4->addWidget(label_14, 5, 0, 1, 1);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 4, 0, 1, 1);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 15, 0, 1, 1);

        leDoc = new EQLineEdit(widget);
        leDoc->setObjectName(QString::fromUtf8("leDoc"));
        leDoc->setMinimumSize(QSize(80, 0));
        leDoc->setMaximumSize(QSize(80, 16777215));

        gridLayout_4->addWidget(leDoc, 0, 2, 1, 1);

        leCancelReason = new EQLineEdit(widget);
        leCancelReason->setObjectName(QString::fromUtf8("leCancelReason"));

        gridLayout_4->addWidget(leCancelReason, 12, 2, 1, 2);

        label_21 = new QLabel(widget);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_4->addWidget(label_21, 6, 0, 1, 2);

        leRb = new EQLineEdit(widget);
        leRb->setObjectName(QString::fromUtf8("leRb"));

        gridLayout_4->addWidget(leRb, 15, 2, 1, 1);

        label_23 = new QLabel(widget);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_4->addWidget(label_23, 10, 0, 1, 1);

        lePrepaid = new EQLineEdit(widget);
        lePrepaid->setObjectName(QString::fromUtf8("lePrepaid"));
        lePrepaid->setMinimumSize(QSize(80, 0));
        lePrepaid->setMaximumSize(QSize(80, 16777215));

        gridLayout_4->addWidget(lePrepaid, 3, 2, 1, 1);

        leUSD = new EQLineEdit(widget);
        leUSD->setObjectName(QString::fromUtf8("leUSD"));
        leUSD->setMinimumSize(QSize(80, 0));
        leUSD->setMaximumSize(QSize(80, 16777215));

        gridLayout_4->addWidget(leUSD, 4, 2, 1, 1);

        teRemarks = new QPlainTextEdit(widget);
        teRemarks->setObjectName(QString::fromUtf8("teRemarks"));

        gridLayout_4->addWidget(teRemarks, 14, 2, 1, 2);

        label_27 = new QLabel(widget);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_4->addWidget(label_27, 11, 0, 1, 1);

        leGuestCompany = new EQLineEdit(widget);
        leGuestCompany->setObjectName(QString::fromUtf8("leGuestCompany"));

        gridLayout_4->addWidget(leGuestCompany, 13, 2, 1, 2);

        leSign = new EQLineEdit(widget);
        leSign->setObjectName(QString::fromUtf8("leSign"));

        gridLayout_4->addWidget(leSign, 6, 2, 1, 2);

        label_28 = new QLabel(widget);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_4->addWidget(label_28, 12, 0, 1, 1);

        leDC = new EQLineEdit(widget);
        leDC->setObjectName(QString::fromUtf8("leDC"));

        gridLayout_4->addWidget(leDC, 2, 2, 1, 2);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 3, 0, 1, 1);

        leFinFlag = new EQLineEdit(widget);
        leFinFlag->setObjectName(QString::fromUtf8("leFinFlag"));

        gridLayout_4->addWidget(leFinFlag, 8, 2, 1, 2);

        deCancelDate = new QDateTimeEdit(widget);
        deCancelDate->setObjectName(QString::fromUtf8("deCancelDate"));

        gridLayout_4->addWidget(deCancelDate, 11, 2, 1, 2);

        leCancelUserCode = new EQLineEdit(widget);
        leCancelUserCode->setObjectName(QString::fromUtf8("leCancelUserCode"));
        leCancelUserCode->setMinimumSize(QSize(80, 0));
        leCancelUserCode->setMaximumSize(QSize(80, 16777215));

        gridLayout_4->addWidget(leCancelUserCode, 10, 2, 1, 1);

        label_32 = new QLabel(widget);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_4->addWidget(label_32, 1, 0, 1, 1);

        leRec = new EQLineEdit(widget);
        leRec->setObjectName(QString::fromUtf8("leRec"));
        leRec->setMinimumSize(QSize(80, 0));
        leRec->setMaximumSize(QSize(80, 16777215));

        gridLayout_4->addWidget(leRec, 1, 2, 1, 1);


        horizontalLayout_2->addWidget(widget);

        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 1, 1, 1, 1);


        retranslateUi(WVaucherEditor);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WVaucherEditor);
    } // setupUi

    void retranslateUi(QDialog *WVaucherEditor)
    {
        WVaucherEditor->setWindowTitle(QCoreApplication::translate("WVaucherEditor", "Edit raw data of voucher", nullptr));
        btnNewVaucher->setText(QCoreApplication::translate("WVaucherEditor", "New voucher", nullptr));
        btnSave->setText(QCoreApplication::translate("WVaucherEditor", "Save", nullptr));
        btnPrint->setText(QCoreApplication::translate("WVaucherEditor", "Print voucher", nullptr));
        btnTrack->setText(QCoreApplication::translate("WVaucherEditor", "Show history", nullptr));
        label_30->setText(QCoreApplication::translate("WVaucherEditor", "VAT mode", nullptr));
        label_6->setText(QCoreApplication::translate("WVaucherEditor", "Room", nullptr));
        label_5->setText(QCoreApplication::translate("WVaucherEditor", "User", nullptr));
        label_7->setText(QCoreApplication::translate("WVaucherEditor", "Guest", nullptr));
        label_18->setText(QCoreApplication::translate("WVaucherEditor", "City ledger", nullptr));
        label_9->setText(QCoreApplication::translate("WVaucherEditor", "Final name", nullptr));
        label_8->setText(QCoreApplication::translate("WVaucherEditor", "Item", nullptr));
        label_19->setText(QCoreApplication::translate("WVaucherEditor", "Payment comment", nullptr));
        label_24->setText(QCoreApplication::translate("WVaucherEditor", "Invoice / Reservation", nullptr));
        label_17->setText(QCoreApplication::translate("WVaucherEditor", "Credit card", nullptr));
        label_16->setText(QCoreApplication::translate("WVaucherEditor", "Payment mode", nullptr));
        label_3->setText(QCoreApplication::translate("WVaucherEditor", "Working date", nullptr));
        label_10->setText(QCoreApplication::translate("WVaucherEditor", "Amount", nullptr));
        label_15->setText(QCoreApplication::translate("WVaucherEditor", "VAT", nullptr));
        label_4->setText(QCoreApplication::translate("WVaucherEditor", "Real date / time", nullptr));
        label_2->setText(QCoreApplication::translate("WVaucherEditor", "Source", nullptr));
        label->setText(QCoreApplication::translate("WVaucherEditor", "Code", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("WVaucherEditor", "Main", nullptr));
        label_29->setText(QCoreApplication::translate("WVaucherEditor", "Guest/Company (0/1)", nullptr));
        label_31->setText(QCoreApplication::translate("WVaucherEditor", "Doc", nullptr));
        label_26->setText(QCoreApplication::translate("WVaucherEditor", "Remarks", nullptr));
        label_20->setText(QCoreApplication::translate("WVaucherEditor", "Debit/Credit", nullptr));
        label_22->setText(QCoreApplication::translate("WVaucherEditor", "Cancel flag", nullptr));
        label_25->setText(QCoreApplication::translate("WVaucherEditor", "Finance flag", nullptr));
        label_14->setText(QCoreApplication::translate("WVaucherEditor", "Fiscal", nullptr));
        label_13->setText(QCoreApplication::translate("WVaucherEditor", "USD Rate", nullptr));
        label_12->setText(QCoreApplication::translate("WVaucherEditor", "RB", nullptr));
        label_21->setText(QCoreApplication::translate("WVaucherEditor", "Sign", nullptr));
        label_23->setText(QCoreApplication::translate("WVaucherEditor", "Cancel user", nullptr));
        label_27->setText(QCoreApplication::translate("WVaucherEditor", "Cancel date", nullptr));
        label_28->setText(QCoreApplication::translate("WVaucherEditor", "Cancel reason", nullptr));
        label_11->setText(QCoreApplication::translate("WVaucherEditor", "Used prepaid", nullptr));
        deCancelDate->setDisplayFormat(QCoreApplication::translate("WVaucherEditor", "dd.MM.yyyy HH:mm:ss", nullptr));
        label_32->setText(QCoreApplication::translate("WVaucherEditor", "Rec", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("WVaucherEditor", "Additional", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WVaucherEditor: public Ui_WVaucherEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WVAUCHEREDITOR_H
