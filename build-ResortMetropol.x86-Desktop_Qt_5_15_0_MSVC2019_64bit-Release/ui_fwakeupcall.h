/********************************************************************************
** Form generated from reading UI file 'fwakeupcall.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FWAKEUPCALL_H
#define UI_FWAKEUPCALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_FWakeupCall
{
public:
    QHBoxLayout *horizontalLayout;
    WDate2 *wd;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FWakeupCall)
    {
        if (FWakeupCall->objectName().isEmpty())
            FWakeupCall->setObjectName(QString::fromUtf8("FWakeupCall"));
        FWakeupCall->resize(1009, 41);
        horizontalLayout = new QHBoxLayout(FWakeupCall);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        wd = new WDate2(FWakeupCall);
        wd->setObjectName(QString::fromUtf8("wd"));

        horizontalLayout->addWidget(wd);

        horizontalSpacer = new QSpacerItem(972, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FWakeupCall);

        QMetaObject::connectSlotsByName(FWakeupCall);
    } // setupUi

    void retranslateUi(QWidget *FWakeupCall)
    {
        FWakeupCall->setWindowTitle(QCoreApplication::translate("FWakeupCall", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FWakeupCall: public Ui_FWakeupCall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FWAKEUPCALL_H
