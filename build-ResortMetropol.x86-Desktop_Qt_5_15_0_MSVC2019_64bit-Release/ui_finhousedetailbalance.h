/********************************************************************************
** Form generated from reading UI file 'finhousedetailbalance.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINHOUSEDETAILBALANCE_H
#define UI_FINHOUSEDETAILBALANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_FInhouseDetailBalance
{
public:
    QHBoxLayout *horizontalLayout;
    WDate2 *wd;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FInhouseDetailBalance)
    {
        if (FInhouseDetailBalance->objectName().isEmpty())
            FInhouseDetailBalance->setObjectName(QString::fromUtf8("FInhouseDetailBalance"));
        FInhouseDetailBalance->resize(761, 41);
        horizontalLayout = new QHBoxLayout(FInhouseDetailBalance);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        wd = new WDate2(FInhouseDetailBalance);
        wd->setObjectName(QString::fromUtf8("wd"));

        horizontalLayout->addWidget(wd);

        horizontalSpacer = new QSpacerItem(508, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FInhouseDetailBalance);

        QMetaObject::connectSlotsByName(FInhouseDetailBalance);
    } // setupUi

    void retranslateUi(QWidget *FInhouseDetailBalance)
    {
        FInhouseDetailBalance->setWindowTitle(QCoreApplication::translate("FInhouseDetailBalance", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FInhouseDetailBalance: public Ui_FInhouseDetailBalance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINHOUSEDETAILBALANCE_H
