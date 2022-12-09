/********************************************************************************
** Form generated from reading UI file 'fhotelhierarchy.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FHOTELHIERARCHY_H
#define UI_FHOTELHIERARCHY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FHotelHierarchy
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *FHotelHierarchy)
    {
        if (FHotelHierarchy->objectName().isEmpty())
            FHotelHierarchy->setObjectName(QString::fromUtf8("FHotelHierarchy"));
        FHotelHierarchy->resize(840, 16);
        horizontalLayout = new QHBoxLayout(FHotelHierarchy);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);

        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(FHotelHierarchy);

        QMetaObject::connectSlotsByName(FHotelHierarchy);
    } // setupUi

    void retranslateUi(QWidget *FHotelHierarchy)
    {
        FHotelHierarchy->setWindowTitle(QCoreApplication::translate("FHotelHierarchy", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FHotelHierarchy: public Ui_FHotelHierarchy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FHOTELHIERARCHY_H
