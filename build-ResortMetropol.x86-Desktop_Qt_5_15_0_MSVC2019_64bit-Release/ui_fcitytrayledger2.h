/********************************************************************************
** Form generated from reading UI file 'fcitytrayledger2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCITYTRAYLEDGER2_H
#define UI_FCITYTRAYLEDGER2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FCityTrayLedger2
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EDateEdit *deDate;
    QLabel *label_2;
    QTimeEdit *teTime;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FCityTrayLedger2)
    {
        if (FCityTrayLedger2->objectName().isEmpty())
            FCityTrayLedger2->setObjectName(QString::fromUtf8("FCityTrayLedger2"));
        FCityTrayLedger2->resize(934, 38);
        horizontalLayout = new QHBoxLayout(FCityTrayLedger2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FCityTrayLedger2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deDate = new EDateEdit(FCityTrayLedger2);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(deDate);

        label_2 = new QLabel(FCityTrayLedger2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        teTime = new QTimeEdit(FCityTrayLedger2);
        teTime->setObjectName(QString::fromUtf8("teTime"));
        teTime->setTime(QTime(3, 0, 0));

        horizontalLayout->addWidget(teTime);

        horizontalSpacer = new QSpacerItem(798, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FCityTrayLedger2);

        QMetaObject::connectSlotsByName(FCityTrayLedger2);
    } // setupUi

    void retranslateUi(QWidget *FCityTrayLedger2)
    {
        FCityTrayLedger2->setWindowTitle(QCoreApplication::translate("FCityTrayLedger2", "Form", nullptr));
        label->setText(QCoreApplication::translate("FCityTrayLedger2", "Date", nullptr));
        label_2->setText(QCoreApplication::translate("FCityTrayLedger2", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCityTrayLedger2: public Ui_FCityTrayLedger2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCITYTRAYLEDGER2_H
