/********************************************************************************
** Form generated from reading UI file 'dlgreserveshortinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGRESERVESHORTINFO_H
#define UI_DLGRESERVESHORTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgReserveShortInfo
{
public:
    QGridLayout *gridLayout_2;
    EQLineEdit *leCode;
    QLabel *label_3;
    QLabel *label_2;
    EDateEdit *deCheckin;
    QLabel *label;
    QLabel *label_5;
    QTimeEdit *teCheckin;
    EDateEdit *deDeparture;
    QLabel *label_4;
    EQLineEdit *leRoom;
    QTimeEdit *teCheckout;
    QLabel *label_6;
    EQLineEdit *leCheckoutUserName;
    EQLineEdit *leCheckoutUsercode;
    EQLineEdit *leGuest;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_7;
    QLineEdit *leInvoice;

    void setupUi(QDialog *DlgReserveShortInfo)
    {
        if (DlgReserveShortInfo->objectName().isEmpty())
            DlgReserveShortInfo->setObjectName(QString::fromUtf8("DlgReserveShortInfo"));
        DlgReserveShortInfo->resize(427, 215);
        gridLayout_2 = new QGridLayout(DlgReserveShortInfo);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        leCode = new EQLineEdit(DlgReserveShortInfo);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setEnabled(false);
        leCode->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(leCode, 0, 1, 1, 1);

        label_3 = new QLabel(DlgReserveShortInfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(DlgReserveShortInfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        deCheckin = new EDateEdit(DlgReserveShortInfo);
        deCheckin->setObjectName(QString::fromUtf8("deCheckin"));
        deCheckin->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(deCheckin, 3, 1, 1, 1);

        label = new QLabel(DlgReserveShortInfo);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(DlgReserveShortInfo);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        teCheckin = new QTimeEdit(DlgReserveShortInfo);
        teCheckin->setObjectName(QString::fromUtf8("teCheckin"));

        gridLayout_2->addWidget(teCheckin, 3, 3, 1, 1);

        deDeparture = new EDateEdit(DlgReserveShortInfo);
        deDeparture->setObjectName(QString::fromUtf8("deDeparture"));
        deDeparture->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(deDeparture, 4, 1, 1, 1);

        label_4 = new QLabel(DlgReserveShortInfo);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        leRoom = new EQLineEdit(DlgReserveShortInfo);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setEnabled(false);
        leRoom->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(leRoom, 1, 1, 1, 1);

        teCheckout = new QTimeEdit(DlgReserveShortInfo);
        teCheckout->setObjectName(QString::fromUtf8("teCheckout"));

        gridLayout_2->addWidget(teCheckout, 4, 3, 1, 1);

        label_6 = new QLabel(DlgReserveShortInfo);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 5, 0, 1, 1);

        leCheckoutUserName = new EQLineEdit(DlgReserveShortInfo);
        leCheckoutUserName->setObjectName(QString::fromUtf8("leCheckoutUserName"));
        leCheckoutUserName->setEnabled(false);

        gridLayout_2->addWidget(leCheckoutUserName, 5, 3, 1, 1);

        leCheckoutUsercode = new EQLineEdit(DlgReserveShortInfo);
        leCheckoutUsercode->setObjectName(QString::fromUtf8("leCheckoutUsercode"));
        leCheckoutUsercode->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(leCheckoutUsercode, 5, 1, 1, 1);

        leGuest = new EQLineEdit(DlgReserveShortInfo);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setEnabled(false);
        leGuest->setMaximumSize(QSize(2222, 16777215));

        gridLayout_2->addWidget(leGuest, 2, 1, 1, 3);

        widget = new QWidget(DlgReserveShortInfo);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(109, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        btnOK = new QPushButton(widget);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        gridLayout->addWidget(btnOK, 1, 1, 1, 1);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        gridLayout->addWidget(btnCancel, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);


        gridLayout_2->addWidget(widget, 6, 0, 1, 4);

        label_7 = new QLabel(DlgReserveShortInfo);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 0, 2, 1, 1);

        leInvoice = new QLineEdit(DlgReserveShortInfo);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setEnabled(false);

        gridLayout_2->addWidget(leInvoice, 0, 3, 1, 1);


        retranslateUi(DlgReserveShortInfo);

        QMetaObject::connectSlotsByName(DlgReserveShortInfo);
    } // setupUi

    void retranslateUi(QDialog *DlgReserveShortInfo)
    {
        DlgReserveShortInfo->setWindowTitle(QCoreApplication::translate("DlgReserveShortInfo", "Reservation info", nullptr));
        label_3->setText(QCoreApplication::translate("DlgReserveShortInfo", "Guest", nullptr));
        label_2->setText(QCoreApplication::translate("DlgReserveShortInfo", "Room", nullptr));
        label->setText(QCoreApplication::translate("DlgReserveShortInfo", "Reservation id", nullptr));
        label_5->setText(QCoreApplication::translate("DlgReserveShortInfo", "Checkout", nullptr));
        teCheckin->setDisplayFormat(QCoreApplication::translate("DlgReserveShortInfo", "HH:mm:ss", nullptr));
        label_4->setText(QCoreApplication::translate("DlgReserveShortInfo", "Checkin", nullptr));
        teCheckout->setDisplayFormat(QCoreApplication::translate("DlgReserveShortInfo", "HH:mm:ss", nullptr));
        label_6->setText(QCoreApplication::translate("DlgReserveShortInfo", "Checkout user", nullptr));
        btnOK->setText(QCoreApplication::translate("DlgReserveShortInfo", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgReserveShortInfo", "Cancel", nullptr));
        label_7->setText(QCoreApplication::translate("DlgReserveShortInfo", "Invoice", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgReserveShortInfo: public Ui_DlgReserveShortInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGRESERVESHORTINFO_H
