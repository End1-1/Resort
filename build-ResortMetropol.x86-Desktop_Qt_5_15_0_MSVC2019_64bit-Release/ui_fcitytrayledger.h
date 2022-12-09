/********************************************************************************
** Form generated from reading UI file 'fcitytrayledger.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCITYTRAYLEDGER_H
#define UI_FCITYTRAYLEDGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FCityTrayLedger
{
public:
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *FCityTrayLedger)
    {
        if (FCityTrayLedger->objectName().isEmpty())
            FCityTrayLedger->setObjectName(QString::fromUtf8("FCityTrayLedger"));
        FCityTrayLedger->resize(934, 18);
        horizontalLayout = new QHBoxLayout(FCityTrayLedger);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        retranslateUi(FCityTrayLedger);

        QMetaObject::connectSlotsByName(FCityTrayLedger);
    } // setupUi

    void retranslateUi(QWidget *FCityTrayLedger)
    {
        FCityTrayLedger->setWindowTitle(QCoreApplication::translate("FCityTrayLedger", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCityTrayLedger: public Ui_FCityTrayLedger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCITYTRAYLEDGER_H
