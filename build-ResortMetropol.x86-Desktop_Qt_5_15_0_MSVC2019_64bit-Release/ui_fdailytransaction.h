/********************************************************************************
** Form generated from reading UI file 'fdailytransaction.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FDAILYTRANSACTION_H
#define UI_FDAILYTRANSACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_FDailyTransaction
{
public:
    QHBoxLayout *horizontalLayout;
    WDate2 *wd;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FDailyTransaction)
    {
        if (FDailyTransaction->objectName().isEmpty())
            FDailyTransaction->setObjectName(QString::fromUtf8("FDailyTransaction"));
        FDailyTransaction->resize(893, 41);
        horizontalLayout = new QHBoxLayout(FDailyTransaction);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        wd = new WDate2(FDailyTransaction);
        wd->setObjectName(QString::fromUtf8("wd"));

        horizontalLayout->addWidget(wd);

        horizontalSpacer = new QSpacerItem(856, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FDailyTransaction);

        QMetaObject::connectSlotsByName(FDailyTransaction);
    } // setupUi

    void retranslateUi(QWidget *FDailyTransaction)
    {
        FDailyTransaction->setWindowTitle(QCoreApplication::translate("FDailyTransaction", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FDailyTransaction: public Ui_FDailyTransaction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FDAILYTRANSACTION_H
