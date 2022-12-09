/********************************************************************************
** Form generated from reading UI file 'fhouseitems.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FHOUSEITEMS_H
#define UI_FHOUSEITEMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FHouseItems
{
public:

    void setupUi(QWidget *FHouseItems)
    {
        if (FHouseItems->objectName().isEmpty())
            FHouseItems->setObjectName(QString::fromUtf8("FHouseItems"));
        FHouseItems->resize(400, 16);

        retranslateUi(FHouseItems);

        QMetaObject::connectSlotsByName(FHouseItems);
    } // setupUi

    void retranslateUi(QWidget *FHouseItems)
    {
        FHouseItems->setWindowTitle(QCoreApplication::translate("FHouseItems", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FHouseItems: public Ui_FHouseItems {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FHOUSEITEMS_H
