/********************************************************************************
** Form generated from reading UI file 'dlgnoshow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGNOSHOW_H
#define UI_DLGNOSHOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <eqdateedit.h>
#include <eqlineedit.h>
#include <wguestinvoice.h>

QT_BEGIN_NAMESPACE

class Ui_DlgNoShow
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_13;
    EQLineEdit *leInvoice;
    EQLineEdit *leCLCode;
    EQLineEdit *leBalance;
    QLabel *label_11;
    QLabel *label_5;
    EQLineEdit *leRoom;
    QLabel *label_9;
    QLabel *label;
    QLabel *label_4;
    EQLineEdit *leTaxCode;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *btnLog;
    QPushButton *btnSave;
    QPushButton *btnPrint;
    QPushButton *btnPrintTax;
    QPushButton *btnClose;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbCancelation;
    QRadioButton *rbNoShow;
    EQLineEdit *lePaymentName;
    EQLineEdit *leAmount;
    EQLineEdit *leVATName;
    QLabel *label_8;
    EQLineEdit *lePaymentMode;
    QLabel *label_14;
    EQLineEdit *leReserve;
    EQLineEdit *leCLName;
    EQLineEdit *leCardCode;
    EQLineEdit *leCardName;
    QLabel *label_12;
    QLabel *Taxcode;
    QLabel *label_7;
    QLabel *label_6;
    EQLineEdit *leVATCode;
    EQLineEdit *leGuest;
    EQLineEdit *leCode;
    EQDateEdit *deEntry;
    QLabel *label_10;
    EQDateEdit *deDate;
    EQDateEdit *deDeparture;
    WGuestInvoice *wGuest;

    void setupUi(QDialog *DlgNoShow)
    {
        if (DlgNoShow->objectName().isEmpty())
            DlgNoShow->setObjectName(QString::fromUtf8("DlgNoShow"));
        DlgNoShow->resize(395, 394);
        gridLayout = new QGridLayout(DlgNoShow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(DlgNoShow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_13 = new QLabel(DlgNoShow);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 12, 0, 1, 1);

        leInvoice = new EQLineEdit(DlgNoShow);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setEnabled(false);
        leInvoice->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leInvoice, 2, 3, 1, 1);

        leCLCode = new EQLineEdit(DlgNoShow);
        leCLCode->setObjectName(QString::fromUtf8("leCLCode"));
        leCLCode->setEnabled(false);
        leCLCode->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leCLCode, 8, 1, 1, 1);

        leBalance = new EQLineEdit(DlgNoShow);
        leBalance->setObjectName(QString::fromUtf8("leBalance"));
        leBalance->setEnabled(false);
        leBalance->setMaximumSize(QSize(100, 16777215));
        leBalance->setReadOnly(true);

        gridLayout->addWidget(leBalance, 4, 3, 1, 1);

        label_11 = new QLabel(DlgNoShow);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 8, 0, 1, 1);

        label_5 = new QLabel(DlgNoShow);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        leRoom = new EQLineEdit(DlgNoShow);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setEnabled(false);
        leRoom->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leRoom, 4, 1, 1, 1);

        label_9 = new QLabel(DlgNoShow);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        label = new QLabel(DlgNoShow);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 2, 1, 1);

        label_4 = new QLabel(DlgNoShow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        leTaxCode = new EQLineEdit(DlgNoShow);
        leTaxCode->setObjectName(QString::fromUtf8("leTaxCode"));
        leTaxCode->setMaximumSize(QSize(100, 16777215));
        leTaxCode->setReadOnly(true);

        gridLayout->addWidget(leTaxCode, 13, 1, 1, 1);

        widget = new QWidget(DlgNoShow);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(105, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnLog = new QToolButton(widget);
        btnLog->setObjectName(QString::fromUtf8("btnLog"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/tracking.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLog->setIcon(icon);

        horizontalLayout->addWidget(btnLog);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnPrint = new QPushButton(widget);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));

        horizontalLayout->addWidget(btnPrint);

        btnPrintTax = new QPushButton(widget);
        btnPrintTax->setObjectName(QString::fromUtf8("btnPrintTax"));
        btnPrintTax->setEnabled(true);

        horizontalLayout->addWidget(btnPrintTax);

        btnClose = new QPushButton(widget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        horizontalLayout->addWidget(btnClose);

        horizontalSpacer_2 = new QSpacerItem(104, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 14, 0, 1, 4);

        label_3 = new QLabel(DlgNoShow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 2, 1, 1);

        frame = new QFrame(DlgNoShow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rbCancelation = new QRadioButton(frame);
        rbCancelation->setObjectName(QString::fromUtf8("rbCancelation"));
        rbCancelation->setChecked(true);

        horizontalLayout_2->addWidget(rbCancelation);

        rbNoShow = new QRadioButton(frame);
        rbNoShow->setObjectName(QString::fromUtf8("rbNoShow"));

        horizontalLayout_2->addWidget(rbNoShow);


        gridLayout->addWidget(frame, 0, 0, 1, 4);

        lePaymentName = new EQLineEdit(DlgNoShow);
        lePaymentName->setObjectName(QString::fromUtf8("lePaymentName"));
        lePaymentName->setEnabled(false);

        gridLayout->addWidget(lePaymentName, 7, 2, 1, 2);

        leAmount = new EQLineEdit(DlgNoShow);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leAmount, 11, 1, 1, 1);

        leVATName = new EQLineEdit(DlgNoShow);
        leVATName->setObjectName(QString::fromUtf8("leVATName"));
        leVATName->setEnabled(false);

        gridLayout->addWidget(leVATName, 12, 2, 1, 2);

        label_8 = new QLabel(DlgNoShow);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 11, 0, 1, 1);

        lePaymentMode = new EQLineEdit(DlgNoShow);
        lePaymentMode->setObjectName(QString::fromUtf8("lePaymentMode"));
        lePaymentMode->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lePaymentMode, 7, 1, 1, 1);

        label_14 = new QLabel(DlgNoShow);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 4, 2, 1, 1);

        leReserve = new EQLineEdit(DlgNoShow);
        leReserve->setObjectName(QString::fromUtf8("leReserve"));
        leReserve->setEnabled(true);
        leReserve->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leReserve, 2, 1, 1, 1);

        leCLName = new EQLineEdit(DlgNoShow);
        leCLName->setObjectName(QString::fromUtf8("leCLName"));
        leCLName->setEnabled(false);

        gridLayout->addWidget(leCLName, 8, 2, 1, 2);

        leCardCode = new EQLineEdit(DlgNoShow);
        leCardCode->setObjectName(QString::fromUtf8("leCardCode"));
        leCardCode->setEnabled(false);
        leCardCode->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leCardCode, 9, 1, 1, 1);

        leCardName = new EQLineEdit(DlgNoShow);
        leCardName->setObjectName(QString::fromUtf8("leCardName"));
        leCardName->setEnabled(false);

        gridLayout->addWidget(leCardName, 9, 2, 1, 2);

        label_12 = new QLabel(DlgNoShow);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 9, 0, 1, 1);

        Taxcode = new QLabel(DlgNoShow);
        Taxcode->setObjectName(QString::fromUtf8("Taxcode"));

        gridLayout->addWidget(Taxcode, 13, 0, 1, 1);

        label_7 = new QLabel(DlgNoShow);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 2, 1, 1);

        label_6 = new QLabel(DlgNoShow);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        leVATCode = new EQLineEdit(DlgNoShow);
        leVATCode->setObjectName(QString::fromUtf8("leVATCode"));
        leVATCode->setEnabled(false);
        leVATCode->setMinimumSize(QSize(100, 0));
        leVATCode->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leVATCode, 12, 1, 1, 1);

        leGuest = new EQLineEdit(DlgNoShow);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setEnabled(false);
        leGuest->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(leGuest, 3, 1, 1, 3);

        leCode = new EQLineEdit(DlgNoShow);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setEnabled(false);
        leCode->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leCode, 1, 1, 1, 1);

        deEntry = new EQDateEdit(DlgNoShow);
        deEntry->setObjectName(QString::fromUtf8("deEntry"));
        deEntry->setEnabled(false);
        deEntry->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(deEntry, 6, 1, 1, 1);

        label_10 = new QLabel(DlgNoShow);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 7, 0, 1, 1);

        deDate = new EQDateEdit(DlgNoShow);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(deDate, 1, 3, 1, 1);

        deDeparture = new EQDateEdit(DlgNoShow);
        deDeparture->setObjectName(QString::fromUtf8("deDeparture"));
        deDeparture->setEnabled(false);
        deDeparture->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(deDeparture, 6, 3, 1, 1);

        wGuest = new WGuestInvoice(DlgNoShow);
        wGuest->setObjectName(QString::fromUtf8("wGuest"));

        gridLayout->addWidget(wGuest, 10, 0, 1, 4);


        retranslateUi(DlgNoShow);

        QMetaObject::connectSlotsByName(DlgNoShow);
    } // setupUi

    void retranslateUi(QDialog *DlgNoShow)
    {
        DlgNoShow->setWindowTitle(QCoreApplication::translate("DlgNoShow", "Cancelation/No show fee", nullptr));
        label_2->setText(QCoreApplication::translate("DlgNoShow", "Reservation", nullptr));
        label_13->setText(QCoreApplication::translate("DlgNoShow", "VAT mode", nullptr));
        label_11->setText(QCoreApplication::translate("DlgNoShow", "City ledger", nullptr));
        label_5->setText(QCoreApplication::translate("DlgNoShow", "Room", nullptr));
        label_9->setText(QCoreApplication::translate("DlgNoShow", "Code", nullptr));
        label->setText(QCoreApplication::translate("DlgNoShow", "Date", nullptr));
        label_4->setText(QCoreApplication::translate("DlgNoShow", "Guest", nullptr));
        btnLog->setText(QString());
        btnSave->setText(QCoreApplication::translate("DlgNoShow", "Save", nullptr));
        btnPrint->setText(QCoreApplication::translate("DlgNoShow", "Print", nullptr));
        btnPrintTax->setText(QCoreApplication::translate("DlgNoShow", "Print tax", nullptr));
        btnClose->setText(QCoreApplication::translate("DlgNoShow", "Close", nullptr));
        label_3->setText(QCoreApplication::translate("DlgNoShow", "Invoice", nullptr));
        rbCancelation->setText(QCoreApplication::translate("DlgNoShow", "Cancelation", nullptr));
        rbNoShow->setText(QCoreApplication::translate("DlgNoShow", "No show", nullptr));
        label_8->setText(QCoreApplication::translate("DlgNoShow", "Amount", nullptr));
        label_14->setText(QCoreApplication::translate("DlgNoShow", "Balance", nullptr));
        label_12->setText(QCoreApplication::translate("DlgNoShow", "Credit card", nullptr));
        Taxcode->setText(QCoreApplication::translate("DlgNoShow", "Tax code", nullptr));
        label_7->setText(QCoreApplication::translate("DlgNoShow", "Departure date", nullptr));
        label_6->setText(QCoreApplication::translate("DlgNoShow", "Entry date", nullptr));
        label_10->setText(QCoreApplication::translate("DlgNoShow", "Mode of payment", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgNoShow: public Ui_DlgNoShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGNOSHOW_H
