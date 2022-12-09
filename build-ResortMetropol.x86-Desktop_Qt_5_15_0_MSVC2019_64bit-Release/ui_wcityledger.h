/********************************************************************************
** Form generated from reading UI file 'wcityledger.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WCITYLEDGER_H
#define UI_WCITYLEDGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_WCityLedger
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    EQLineEdit *leCLName;
    EQLineEdit *leCL;
    QLabel *label_3;
    EQLineEdit *leBalance;
    QLabel *label;

    void setupUi(QWidget *WCityLedger)
    {
        if (WCityLedger->objectName().isEmpty())
            WCityLedger->setObjectName(QString::fromUtf8("WCityLedger"));
        WCityLedger->resize(450, 64);
        gridLayout = new QGridLayout(WCityLedger);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setContentsMargins(9, 9, 9, 9);
        label_2 = new QLabel(WCityLedger);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        leCLName = new EQLineEdit(WCityLedger);
        leCLName->setObjectName(QString::fromUtf8("leCLName"));
        leCLName->setMinimumSize(QSize(250, 0));
        leCLName->setReadOnly(true);

        gridLayout->addWidget(leCLName, 0, 3, 1, 1);

        leCL = new EQLineEdit(WCityLedger);
        leCL->setObjectName(QString::fromUtf8("leCL"));
        leCL->setMinimumSize(QSize(100, 0));
        leCL->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leCL, 0, 1, 1, 1);

        label_3 = new QLabel(WCityLedger);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        leBalance = new EQLineEdit(WCityLedger);
        leBalance->setObjectName(QString::fromUtf8("leBalance"));
        leBalance->setMinimumSize(QSize(100, 0));
        leBalance->setMaximumSize(QSize(100, 16777215));
        leBalance->setReadOnly(true);

        gridLayout->addWidget(leBalance, 1, 1, 1, 1);

        label = new QLabel(WCityLedger);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(WCityLedger);

        QMetaObject::connectSlotsByName(WCityLedger);
    } // setupUi

    void retranslateUi(QWidget *WCityLedger)
    {
        WCityLedger->setWindowTitle(QCoreApplication::translate("WCityLedger", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("WCityLedger", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("WCityLedger", "Balance", nullptr));
        label->setText(QCoreApplication::translate("WCityLedger", "Code", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WCityLedger: public Ui_WCityLedger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WCITYLEDGER_H
