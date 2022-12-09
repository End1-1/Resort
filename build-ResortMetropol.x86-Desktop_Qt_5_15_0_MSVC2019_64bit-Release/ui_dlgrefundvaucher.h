/********************************************************************************
** Form generated from reading UI file 'dlgrefundvaucher.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGREFUNDVAUCHER_H
#define UI_DLGREFUNDVAUCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqdateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgRefundVaucher
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label;
    EQLineEdit *lePaymentName;
    QLabel *label_8;
    EQLineEdit *leCLName;
    EQLineEdit *leInvoice;
    EQLineEdit *leRoom;
    QRadioButton *rgCL;
    QLabel *label_6;
    QLineEdit *leBalance;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnPrint;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_7;
    EQLineEdit *leAmount;
    QLabel *label_2;
    EQLineEdit *leVaucher;
    QRadioButton *rgGuest;
    EQLineEdit *leGuest;
    EQLineEdit *leCLCode;
    QLabel *label_9;
    EQLineEdit *lePaymentMode;
    EQDateEdit *deDate;
    QLabel *label_4;
    QLabel *label_5;
    EQLineEdit *leReserve;
    QLabel *label_10;
    QCheckBox *chDecreaseAdvance;
    QLabel *label_11;

    void setupUi(QDialog *DlgRefundVaucher)
    {
        if (DlgRefundVaucher->objectName().isEmpty())
            DlgRefundVaucher->setObjectName(QString::fromUtf8("DlgRefundVaucher"));
        DlgRefundVaucher->resize(459, 361);
        gridLayout = new QGridLayout(DlgRefundVaucher);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(DlgRefundVaucher);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        label = new QLabel(DlgRefundVaucher);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        lePaymentName = new EQLineEdit(DlgRefundVaucher);
        lePaymentName->setObjectName(QString::fromUtf8("lePaymentName"));
        lePaymentName->setEnabled(false);

        gridLayout->addWidget(lePaymentName, 8, 2, 1, 1);

        label_8 = new QLabel(DlgRefundVaucher);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 8, 0, 1, 1);

        leCLName = new EQLineEdit(DlgRefundVaucher);
        leCLName->setObjectName(QString::fromUtf8("leCLName"));
        leCLName->setEnabled(false);

        gridLayout->addWidget(leCLName, 9, 2, 1, 1);

        leInvoice = new EQLineEdit(DlgRefundVaucher);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setEnabled(false);

        gridLayout->addWidget(leInvoice, 4, 1, 1, 2);

        leRoom = new EQLineEdit(DlgRefundVaucher);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setEnabled(false);

        gridLayout->addWidget(leRoom, 6, 1, 1, 2);

        rgCL = new QRadioButton(DlgRefundVaucher);
        rgCL->setObjectName(QString::fromUtf8("rgCL"));

        gridLayout->addWidget(rgCL, 1, 2, 1, 1);

        label_6 = new QLabel(DlgRefundVaucher);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 10, 0, 1, 1);

        leBalance = new QLineEdit(DlgRefundVaucher);
        leBalance->setObjectName(QString::fromUtf8("leBalance"));
        leBalance->setEnabled(false);
        leBalance->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leBalance, 7, 1, 1, 1);

        widget = new QWidget(DlgRefundVaucher);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(84, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnPrint = new QPushButton(widget);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));

        horizontalLayout->addWidget(btnPrint);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(84, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 12, 0, 1, 3);

        label_7 = new QLabel(DlgRefundVaucher);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        leAmount = new EQLineEdit(DlgRefundVaucher);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));

        gridLayout->addWidget(leAmount, 10, 1, 1, 2);

        label_2 = new QLabel(DlgRefundVaucher);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        leVaucher = new EQLineEdit(DlgRefundVaucher);
        leVaucher->setObjectName(QString::fromUtf8("leVaucher"));
        leVaucher->setEnabled(false);

        gridLayout->addWidget(leVaucher, 2, 1, 1, 2);

        rgGuest = new QRadioButton(DlgRefundVaucher);
        rgGuest->setObjectName(QString::fromUtf8("rgGuest"));
        rgGuest->setChecked(true);

        gridLayout->addWidget(rgGuest, 1, 1, 1, 1);

        leGuest = new EQLineEdit(DlgRefundVaucher);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setEnabled(false);

        gridLayout->addWidget(leGuest, 5, 1, 1, 2);

        leCLCode = new EQLineEdit(DlgRefundVaucher);
        leCLCode->setObjectName(QString::fromUtf8("leCLCode"));
        leCLCode->setEnabled(false);
        leCLCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCLCode, 9, 1, 1, 1);

        label_9 = new QLabel(DlgRefundVaucher);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 9, 0, 1, 1);

        lePaymentMode = new EQLineEdit(DlgRefundVaucher);
        lePaymentMode->setObjectName(QString::fromUtf8("lePaymentMode"));
        lePaymentMode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lePaymentMode, 8, 1, 1, 1);

        deDate = new EQDateEdit(DlgRefundVaucher);
        deDate->setObjectName(QString::fromUtf8("deDate"));

        gridLayout->addWidget(deDate, 0, 1, 1, 2);

        label_4 = new QLabel(DlgRefundVaucher);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        label_5 = new QLabel(DlgRefundVaucher);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        leReserve = new EQLineEdit(DlgRefundVaucher);
        leReserve->setObjectName(QString::fromUtf8("leReserve"));
        leReserve->setEnabled(false);

        gridLayout->addWidget(leReserve, 3, 1, 1, 2);

        label_10 = new QLabel(DlgRefundVaucher);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 7, 0, 1, 1);

        chDecreaseAdvance = new QCheckBox(DlgRefundVaucher);
        chDecreaseAdvance->setObjectName(QString::fromUtf8("chDecreaseAdvance"));

        gridLayout->addWidget(chDecreaseAdvance, 11, 1, 1, 1);

        label_11 = new QLabel(DlgRefundVaucher);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 11, 0, 1, 1);


        retranslateUi(DlgRefundVaucher);

        QMetaObject::connectSlotsByName(DlgRefundVaucher);
    } // setupUi

    void retranslateUi(QDialog *DlgRefundVaucher)
    {
        DlgRefundVaucher->setWindowTitle(QCoreApplication::translate("DlgRefundVaucher", "Refund voucher", nullptr));
        label_3->setText(QCoreApplication::translate("DlgRefundVaucher", "Guest", nullptr));
        label->setText(QCoreApplication::translate("DlgRefundVaucher", "Reservation", nullptr));
        label_8->setText(QCoreApplication::translate("DlgRefundVaucher", "Payment mode", nullptr));
        rgCL->setText(QCoreApplication::translate("DlgRefundVaucher", "City ledger", nullptr));
        label_6->setText(QCoreApplication::translate("DlgRefundVaucher", "Amount", nullptr));
        btnSave->setText(QCoreApplication::translate("DlgRefundVaucher", "Save", nullptr));
        btnPrint->setText(QCoreApplication::translate("DlgRefundVaucher", "Print", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgRefundVaucher", "Cancel", nullptr));
        label_7->setText(QCoreApplication::translate("DlgRefundVaucher", "Voucher", nullptr));
        label_2->setText(QCoreApplication::translate("DlgRefundVaucher", "Invoice", nullptr));
        rgGuest->setText(QCoreApplication::translate("DlgRefundVaucher", "Guest", nullptr));
        label_9->setText(QCoreApplication::translate("DlgRefundVaucher", "City ledger", nullptr));
        label_4->setText(QCoreApplication::translate("DlgRefundVaucher", "Room", nullptr));
        label_5->setText(QCoreApplication::translate("DlgRefundVaucher", "Date", nullptr));
        label_10->setText(QCoreApplication::translate("DlgRefundVaucher", "Balance", nullptr));
        chDecreaseAdvance->setText(QString());
        label_11->setText(QCoreApplication::translate("DlgRefundVaucher", "Decrease advance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgRefundVaucher: public Ui_DlgRefundVaucher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGREFUNDVAUCHER_H
