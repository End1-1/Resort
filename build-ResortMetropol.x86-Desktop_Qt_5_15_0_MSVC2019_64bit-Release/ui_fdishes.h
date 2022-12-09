/********************************************************************************
** Form generated from reading UI file 'fdishes.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FDISHES_H
#define UI_FDISHES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_FDishes
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EQLineEdit *leTypeCode;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnUpdateMenuNumber;

    void setupUi(QWidget *FDishes)
    {
        if (FDishes->objectName().isEmpty())
            FDishes->setObjectName(QString::fromUtf8("FDishes"));
        FDishes->resize(994, 41);
        horizontalLayout = new QHBoxLayout(FDishes);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FDishes);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        leTypeCode = new EQLineEdit(FDishes);
        leTypeCode->setObjectName(QString::fromUtf8("leTypeCode"));
        leTypeCode->setMinimumSize(QSize(0, 0));
        leTypeCode->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(leTypeCode);

        horizontalSpacer = new QSpacerItem(467, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnUpdateMenuNumber = new QPushButton(FDishes);
        btnUpdateMenuNumber->setObjectName(QString::fromUtf8("btnUpdateMenuNumber"));

        horizontalLayout->addWidget(btnUpdateMenuNumber);


        retranslateUi(FDishes);

        QMetaObject::connectSlotsByName(FDishes);
    } // setupUi

    void retranslateUi(QWidget *FDishes)
    {
        FDishes->setWindowTitle(QCoreApplication::translate("FDishes", "Form", nullptr));
        label->setText(QCoreApplication::translate("FDishes", "Type", nullptr));
        btnUpdateMenuNumber->setText(QCoreApplication::translate("FDishes", "Update menu number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FDishes: public Ui_FDishes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FDISHES_H
