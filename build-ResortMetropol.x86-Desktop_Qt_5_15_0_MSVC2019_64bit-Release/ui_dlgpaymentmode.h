/********************************************************************************
** Form generated from reading UI file 'dlgpaymentmode.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPAYMENTMODE_H
#define UI_DLGPAYMENTMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgPaymentMode
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    EQLineEdit *lePaymentMode;
    QLabel *label_2;
    EQLineEdit *leCardType;
    QLabel *label_3;
    EQLineEdit *leCL;
    QLabel *label_4;
    EQLineEdit *leRoom;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgPaymentMode)
    {
        if (DlgPaymentMode->objectName().isEmpty())
            DlgPaymentMode->setObjectName(QString::fromUtf8("DlgPaymentMode"));
        DlgPaymentMode->resize(385, 163);
        gridLayout = new QGridLayout(DlgPaymentMode);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgPaymentMode);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lePaymentMode = new EQLineEdit(DlgPaymentMode);
        lePaymentMode->setObjectName(QString::fromUtf8("lePaymentMode"));

        gridLayout->addWidget(lePaymentMode, 0, 1, 1, 1);

        label_2 = new QLabel(DlgPaymentMode);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leCardType = new EQLineEdit(DlgPaymentMode);
        leCardType->setObjectName(QString::fromUtf8("leCardType"));
        leCardType->setEnabled(false);

        gridLayout->addWidget(leCardType, 1, 1, 1, 1);

        label_3 = new QLabel(DlgPaymentMode);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leCL = new EQLineEdit(DlgPaymentMode);
        leCL->setObjectName(QString::fromUtf8("leCL"));
        leCL->setEnabled(false);

        gridLayout->addWidget(leCL, 2, 1, 1, 1);

        label_4 = new QLabel(DlgPaymentMode);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        leRoom = new EQLineEdit(DlgPaymentMode);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setEnabled(false);

        gridLayout->addWidget(leRoom, 3, 1, 1, 1);

        widget = new QWidget(DlgPaymentMode);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(87, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 4, 0, 1, 2);


        retranslateUi(DlgPaymentMode);

        QMetaObject::connectSlotsByName(DlgPaymentMode);
    } // setupUi

    void retranslateUi(QDialog *DlgPaymentMode)
    {
        DlgPaymentMode->setWindowTitle(QCoreApplication::translate("DlgPaymentMode", "Mode of payment", nullptr));
        label->setText(QCoreApplication::translate("DlgPaymentMode", "Mode of payment", nullptr));
        label_2->setText(QCoreApplication::translate("DlgPaymentMode", "Card type", nullptr));
        label_3->setText(QCoreApplication::translate("DlgPaymentMode", "City ledger", nullptr));
        label_4->setText(QCoreApplication::translate("DlgPaymentMode", "Transfer to room", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgPaymentMode", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgPaymentMode", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgPaymentMode: public Ui_DlgPaymentMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPAYMENTMODE_H
