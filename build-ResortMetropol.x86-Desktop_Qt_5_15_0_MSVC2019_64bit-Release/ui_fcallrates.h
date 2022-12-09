/********************************************************************************
** Form generated from reading UI file 'fcallrates.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCALLRATES_H
#define UI_FCALLRATES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FCallRates
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *FCallRates)
    {
        if (FCallRates->objectName().isEmpty())
            FCallRates->setObjectName(QString::fromUtf8("FCallRates"));
        FCallRates->resize(748, 16);
        horizontalLayout = new QHBoxLayout(FCallRates);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(FCallRates);

        QMetaObject::connectSlotsByName(FCallRates);
    } // setupUi

    void retranslateUi(QWidget *FCallRates)
    {
        FCallRates->setWindowTitle(QCoreApplication::translate("FCallRates", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCallRates: public Ui_FCallRates {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCALLRATES_H
