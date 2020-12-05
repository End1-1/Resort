/********************************************************************************
** Form generated from reading UI file 'dlgonebreakfasat.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGONEBREAKFASAT_H
#define UI_DLGONEBREAKFASAT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
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

class Ui_DlgOneBreakfasat
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *lbGuest;
    QPushButton *btnPayment;
    QLabel *label_5;
    QLabel *lbRoom;
    QPushButton *btnRoom;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *lbCardType;
    QLabel *label;
    EQLineEdit *lePayment;
    EQLineEdit *lePax;
    EQLineEdit *leInvoice;
    QSpacerItem *verticalSpacer;
    EQLineEdit *leTotal;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *btnOpenDraft;
    QToolButton *btnPrePrint;
    QToolButton *btnPrint;
    QToolButton *btnPrintTax;
    QToolButton *btnExit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnPax;
    QPushButton *btnPrice;
    EQLineEdit *lePrice;
    QLabel *label_3;
    QLineEdit *leGuest;
    EQLineEdit *leRoom;
    QLabel *lbInvoice;
    QLabel *lbCityLedger;
    EQLineEdit *leCityLedger;
    EQLineEdit *leCardType;

    void setupUi(QDialog *DlgOneBreakfasat)
    {
        if (DlgOneBreakfasat->objectName().isEmpty())
            DlgOneBreakfasat->setObjectName(QString::fromUtf8("DlgOneBreakfasat"));
        DlgOneBreakfasat->resize(549, 508);
        verticalLayout = new QVBoxLayout(DlgOneBreakfasat);
        verticalLayout->setSpacing(24);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(DlgOneBreakfasat);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(24);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lbGuest = new QLabel(frame);
        lbGuest->setObjectName(QString::fromUtf8("lbGuest"));

        gridLayout->addWidget(lbGuest, 9, 0, 1, 1);

        btnPayment = new QPushButton(frame);
        btnPayment->setObjectName(QString::fromUtf8("btnPayment"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/wallet-with-money.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPayment->setIcon(icon);

        gridLayout->addWidget(btnPayment, 4, 6, 1, 2);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lbRoom = new QLabel(frame);
        lbRoom->setObjectName(QString::fromUtf8("lbRoom"));

        gridLayout->addWidget(lbRoom, 8, 0, 1, 1);

        btnRoom = new QPushButton(frame);
        btnRoom->setObjectName(QString::fromUtf8("btnRoom"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/dinner.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRoom->setIcon(icon1);

        gridLayout->addWidget(btnRoom, 8, 6, 1, 2);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lbCardType = new QLabel(frame);
        lbCardType->setObjectName(QString::fromUtf8("lbCardType"));

        gridLayout->addWidget(lbCardType, 5, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 8);

        lePayment = new EQLineEdit(frame);
        lePayment->setObjectName(QString::fromUtf8("lePayment"));

        gridLayout->addWidget(lePayment, 4, 1, 1, 5);

        lePax = new EQLineEdit(frame);
        lePax->setObjectName(QString::fromUtf8("lePax"));

        gridLayout->addWidget(lePax, 1, 1, 1, 1);

        leInvoice = new EQLineEdit(frame);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));

        gridLayout->addWidget(leInvoice, 8, 5, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 10, 4, 1, 1);

        leTotal = new EQLineEdit(frame);
        leTotal->setObjectName(QString::fromUtf8("leTotal"));

        gridLayout->addWidget(leTotal, 3, 1, 1, 6);

        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOpenDraft = new QToolButton(widget);
        btnOpenDraft->setObjectName(QString::fromUtf8("btnOpenDraft"));
        btnOpenDraft->setMinimumSize(QSize(60, 60));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOpenDraft->setIcon(icon2);
        btnOpenDraft->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btnOpenDraft);

        btnPrePrint = new QToolButton(widget);
        btnPrePrint->setObjectName(QString::fromUtf8("btnPrePrint"));
        btnPrePrint->setMinimumSize(QSize(60, 60));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrePrint->setIcon(icon3);
        btnPrePrint->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btnPrePrint);

        btnPrint = new QToolButton(widget);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        btnPrint->setEnabled(false);
        btnPrint->setMinimumSize(QSize(60, 60));
        btnPrint->setIcon(icon3);
        btnPrint->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btnPrint);

        btnPrintTax = new QToolButton(widget);
        btnPrintTax->setObjectName(QString::fromUtf8("btnPrintTax"));
        btnPrintTax->setEnabled(false);
        btnPrintTax->setMinimumSize(QSize(60, 60));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/tax.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrintTax->setIcon(icon4);
        btnPrintTax->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btnPrintTax);

        btnExit = new QToolButton(widget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setMinimumSize(QSize(60, 60));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExit->setIcon(icon5);
        btnExit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btnExit);

        horizontalSpacer_2 = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 11, 0, 1, 8);

        btnPax = new QPushButton(frame);
        btnPax->setObjectName(QString::fromUtf8("btnPax"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/guests.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPax->setIcon(icon6);

        gridLayout->addWidget(btnPax, 1, 2, 1, 1);

        btnPrice = new QPushButton(frame);
        btnPrice->setObjectName(QString::fromUtf8("btnPrice"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/cash.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrice->setIcon(icon7);

        gridLayout->addWidget(btnPrice, 1, 6, 1, 1);

        lePrice = new EQLineEdit(frame);
        lePrice->setObjectName(QString::fromUtf8("lePrice"));

        gridLayout->addWidget(lePrice, 1, 5, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 4, 1, 1);

        leGuest = new QLineEdit(frame);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));

        gridLayout->addWidget(leGuest, 9, 1, 1, 5);

        leRoom = new EQLineEdit(frame);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));

        gridLayout->addWidget(leRoom, 8, 1, 1, 2);

        lbInvoice = new QLabel(frame);
        lbInvoice->setObjectName(QString::fromUtf8("lbInvoice"));

        gridLayout->addWidget(lbInvoice, 8, 3, 1, 2);

        lbCityLedger = new QLabel(frame);
        lbCityLedger->setObjectName(QString::fromUtf8("lbCityLedger"));

        gridLayout->addWidget(lbCityLedger, 6, 0, 1, 1);

        leCityLedger = new EQLineEdit(frame);
        leCityLedger->setObjectName(QString::fromUtf8("leCityLedger"));

        gridLayout->addWidget(leCityLedger, 6, 1, 1, 7);

        leCardType = new EQLineEdit(frame);
        leCardType->setObjectName(QString::fromUtf8("leCardType"));

        gridLayout->addWidget(leCardType, 5, 1, 1, 6);


        verticalLayout->addWidget(frame);


        retranslateUi(DlgOneBreakfasat);

        QMetaObject::connectSlotsByName(DlgOneBreakfasat);
    } // setupUi

    void retranslateUi(QDialog *DlgOneBreakfasat)
    {
        DlgOneBreakfasat->setWindowTitle(QCoreApplication::translate("DlgOneBreakfasat", "Dialog", nullptr));
        lbGuest->setText(QCoreApplication::translate("DlgOneBreakfasat", "GUEST", nullptr));
        btnPayment->setText(QString());
        label_5->setText(QCoreApplication::translate("DlgOneBreakfasat", "PAYMENT MODE", nullptr));
        lbRoom->setText(QCoreApplication::translate("DlgOneBreakfasat", "ROOM", nullptr));
        btnRoom->setText(QString());
        label_4->setText(QCoreApplication::translate("DlgOneBreakfasat", "TOTAL", nullptr));
        label_2->setText(QCoreApplication::translate("DlgOneBreakfasat", "PAX", nullptr));
        lbCardType->setText(QCoreApplication::translate("DlgOneBreakfasat", "CARD TYPE", nullptr));
        label->setText(QCoreApplication::translate("DlgOneBreakfasat", "BREAKFAST", nullptr));
        btnOpenDraft->setText(QCoreApplication::translate("DlgOneBreakfasat", "Open\n"
"Draft", nullptr));
        btnPrePrint->setText(QCoreApplication::translate("DlgOneBreakfasat", "Print\n"
"And Draft", nullptr));
        btnPrint->setText(QCoreApplication::translate("DlgOneBreakfasat", "Print\n"
"And Save", nullptr));
        btnPrintTax->setText(QCoreApplication::translate("DlgOneBreakfasat", "Print Tax", nullptr));
        btnExit->setText(QCoreApplication::translate("DlgOneBreakfasat", "Exit", nullptr));
        btnPax->setText(QString());
        btnPrice->setText(QString());
        lePrice->setText(QCoreApplication::translate("DlgOneBreakfasat", "6500", nullptr));
        label_3->setText(QCoreApplication::translate("DlgOneBreakfasat", "PRICE", nullptr));
        lbInvoice->setText(QCoreApplication::translate("DlgOneBreakfasat", "INVOICE", nullptr));
        lbCityLedger->setText(QCoreApplication::translate("DlgOneBreakfasat", "CITY LEDGER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgOneBreakfasat: public Ui_DlgOneBreakfasat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGONEBREAKFASAT_H
