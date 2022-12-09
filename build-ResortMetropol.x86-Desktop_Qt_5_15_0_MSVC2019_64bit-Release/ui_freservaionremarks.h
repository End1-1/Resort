/********************************************************************************
** Form generated from reading UI file 'freservaionremarks.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRESERVAIONREMARKS_H
#define UI_FRESERVAIONREMARKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_FReservaionRemarks
{
public:
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbCheckin;
    QRadioButton *rbReserve;
    QRadioButton *rbCheckout;
    QLabel *label;
    WDate2 *wd;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FReservaionRemarks)
    {
        if (FReservaionRemarks->objectName().isEmpty())
            FReservaionRemarks->setObjectName(QString::fromUtf8("FReservaionRemarks"));
        FReservaionRemarks->resize(615, 38);
        horizontalLayout = new QHBoxLayout(FReservaionRemarks);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rbCheckin = new QRadioButton(FReservaionRemarks);
        rbCheckin->setObjectName(QString::fromUtf8("rbCheckin"));
        rbCheckin->setChecked(true);

        horizontalLayout->addWidget(rbCheckin);

        rbReserve = new QRadioButton(FReservaionRemarks);
        rbReserve->setObjectName(QString::fromUtf8("rbReserve"));

        horizontalLayout->addWidget(rbReserve);

        rbCheckout = new QRadioButton(FReservaionRemarks);
        rbCheckout->setObjectName(QString::fromUtf8("rbCheckout"));

        horizontalLayout->addWidget(rbCheckout);

        label = new QLabel(FReservaionRemarks);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        wd = new WDate2(FReservaionRemarks);
        wd->setObjectName(QString::fromUtf8("wd"));

        horizontalLayout->addWidget(wd);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FReservaionRemarks);

        QMetaObject::connectSlotsByName(FReservaionRemarks);
    } // setupUi

    void retranslateUi(QWidget *FReservaionRemarks)
    {
        FReservaionRemarks->setWindowTitle(QCoreApplication::translate("FReservaionRemarks", "Form", nullptr));
        rbCheckin->setText(QCoreApplication::translate("FReservaionRemarks", "Check in", nullptr));
        rbReserve->setText(QCoreApplication::translate("FReservaionRemarks", "Reserved", nullptr));
        rbCheckout->setText(QCoreApplication::translate("FReservaionRemarks", "Checkout", nullptr));
        label->setText(QCoreApplication::translate("FReservaionRemarks", "Checkout date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FReservaionRemarks: public Ui_FReservaionRemarks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRESERVAIONREMARKS_H
