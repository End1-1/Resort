/********************************************************************************
** Form generated from reading UI file 'dlgcouponsales.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCOUPONSALES_H
#define UI_DLGCOUPONSALES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqcombobox.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgCouponSales
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    EQLineEdit *leCode;
    QLabel *label_6;
    EDateEdit *deDate;
    QLabel *label_4;
    EQLineEdit *lePartnerCode;
    EQLineEdit *leSeraiName;
    QLabel *label_5;
    QLabel *label_2;
    EQComboBox *cbPayment;
    EQLineEdit *leSeriaNum;
    QLabel *label_3;
    EQLineEdit *leQty;
    EQLineEdit *lePartnerName;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_7;
    EQLineEdit *leAmount;

    void setupUi(QDialog *DlgCouponSales)
    {
        if (DlgCouponSales->objectName().isEmpty())
            DlgCouponSales->setObjectName(QString::fromUtf8("DlgCouponSales"));
        DlgCouponSales->resize(412, 254);
        gridLayout = new QGridLayout(DlgCouponSales);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgCouponSales);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leCode = new EQLineEdit(DlgCouponSales);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setEnabled(false);
        leCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        label_6 = new QLabel(DlgCouponSales);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        deDate = new EDateEdit(DlgCouponSales);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(deDate, 1, 1, 1, 1);

        label_4 = new QLabel(DlgCouponSales);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lePartnerCode = new EQLineEdit(DlgCouponSales);
        lePartnerCode->setObjectName(QString::fromUtf8("lePartnerCode"));
        lePartnerCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lePartnerCode, 2, 1, 1, 1);

        leSeraiName = new EQLineEdit(DlgCouponSales);
        leSeraiName->setObjectName(QString::fromUtf8("leSeraiName"));
        leSeraiName->setEnabled(false);

        gridLayout->addWidget(leSeraiName, 4, 2, 1, 1);

        label_5 = new QLabel(DlgCouponSales);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        label_2 = new QLabel(DlgCouponSales);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        cbPayment = new EQComboBox(DlgCouponSales);
        cbPayment->setObjectName(QString::fromUtf8("cbPayment"));
        cbPayment->setProperty("Cache", QVariant(108));

        gridLayout->addWidget(cbPayment, 3, 1, 1, 2);

        leSeriaNum = new EQLineEdit(DlgCouponSales);
        leSeriaNum->setObjectName(QString::fromUtf8("leSeriaNum"));
        leSeriaNum->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leSeriaNum, 4, 1, 1, 1);

        label_3 = new QLabel(DlgCouponSales);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        leQty = new EQLineEdit(DlgCouponSales);
        leQty->setObjectName(QString::fromUtf8("leQty"));
        leQty->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leQty, 5, 1, 1, 1);

        lePartnerName = new EQLineEdit(DlgCouponSales);
        lePartnerName->setObjectName(QString::fromUtf8("lePartnerName"));
        lePartnerName->setEnabled(false);

        gridLayout->addWidget(lePartnerName, 2, 2, 1, 1);

        widget = new QWidget(DlgCouponSales);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(101, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(101, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 7, 0, 1, 3);

        label_7 = new QLabel(DlgCouponSales);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        leAmount = new EQLineEdit(DlgCouponSales);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setEnabled(false);
        leAmount->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leAmount, 6, 1, 1, 1);


        retranslateUi(DlgCouponSales);

        QMetaObject::connectSlotsByName(DlgCouponSales);
    } // setupUi

    void retranslateUi(QDialog *DlgCouponSales)
    {
        DlgCouponSales->setWindowTitle(QCoreApplication::translate("DlgCouponSales", "Coupon sale", nullptr));
        label->setText(QCoreApplication::translate("DlgCouponSales", "Code", nullptr));
        label_6->setText(QCoreApplication::translate("DlgCouponSales", "Date", nullptr));
        label_4->setText(QCoreApplication::translate("DlgCouponSales", "Partner", nullptr));
        label_5->setText(QCoreApplication::translate("DlgCouponSales", "Count", nullptr));
        label_2->setText(QCoreApplication::translate("DlgCouponSales", "Seria", nullptr));
        label_3->setText(QCoreApplication::translate("DlgCouponSales", "Payment", nullptr));
        btnSave->setText(QCoreApplication::translate("DlgCouponSales", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgCouponSales", "Cancel", nullptr));
        label_7->setText(QCoreApplication::translate("DlgCouponSales", "Amount", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgCouponSales: public Ui_DlgCouponSales {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCOUPONSALES_H
