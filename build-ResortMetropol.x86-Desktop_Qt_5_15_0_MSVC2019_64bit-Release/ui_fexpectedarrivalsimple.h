/********************************************************************************
** Form generated from reading UI file 'fexpectedarrivalsimple.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEXPECTEDARRIVALSIMPLE_H
#define UI_FEXPECTEDARRIVALSIMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_FExpectedArrivalSimple
{
public:
    QHBoxLayout *horizontalLayout;
    WDate2 *wd;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FExpectedArrivalSimple)
    {
        if (FExpectedArrivalSimple->objectName().isEmpty())
            FExpectedArrivalSimple->setObjectName(QString::fromUtf8("FExpectedArrivalSimple"));
        FExpectedArrivalSimple->resize(470, 16);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FExpectedArrivalSimple->sizePolicy().hasHeightForWidth());
        FExpectedArrivalSimple->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(FExpectedArrivalSimple);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wd = new WDate2(FExpectedArrivalSimple);
        wd->setObjectName(QString::fromUtf8("wd"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wd->sizePolicy().hasHeightForWidth());
        wd->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(wd);

        horizontalSpacer = new QSpacerItem(451, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FExpectedArrivalSimple);

        QMetaObject::connectSlotsByName(FExpectedArrivalSimple);
    } // setupUi

    void retranslateUi(QWidget *FExpectedArrivalSimple)
    {
        FExpectedArrivalSimple->setWindowTitle(QCoreApplication::translate("FExpectedArrivalSimple", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FExpectedArrivalSimple: public Ui_FExpectedArrivalSimple {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEXPECTEDARRIVALSIMPLE_H
