/********************************************************************************
** Form generated from reading UI file 'finhouseguestfuture.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINHOUSEGUESTFUTURE_H
#define UI_FINHOUSEGUESTFUTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_FInhouseGuestFuture
{
public:
    QHBoxLayout *horizontalLayout;
    WDate2 *wDate;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FInhouseGuestFuture)
    {
        if (FInhouseGuestFuture->objectName().isEmpty())
            FInhouseGuestFuture->setObjectName(QString::fromUtf8("FInhouseGuestFuture"));
        FInhouseGuestFuture->resize(79, 23);
        horizontalLayout = new QHBoxLayout(FInhouseGuestFuture);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wDate = new WDate2(FInhouseGuestFuture);
        wDate->setObjectName(QString::fromUtf8("wDate"));
        horizontalLayout_2 = new QHBoxLayout(wDate);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        horizontalLayout->addWidget(wDate);

        horizontalSpacer = new QSpacerItem(52, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FInhouseGuestFuture);

        QMetaObject::connectSlotsByName(FInhouseGuestFuture);
    } // setupUi

    void retranslateUi(QWidget *FInhouseGuestFuture)
    {
        FInhouseGuestFuture->setWindowTitle(QCoreApplication::translate("FInhouseGuestFuture", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FInhouseGuestFuture: public Ui_FInhouseGuestFuture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINHOUSEGUESTFUTURE_H
