/********************************************************************************
** Form generated from reading UI file 'froomstates.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FROOMSTATES_H
#define UI_FROOMSTATES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FRoomStates
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *FRoomStates)
    {
        if (FRoomStates->objectName().isEmpty())
            FRoomStates->setObjectName(QString::fromUtf8("FRoomStates"));
        FRoomStates->resize(906, 16);
        horizontalLayout = new QHBoxLayout(FRoomStates);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(FRoomStates);

        QMetaObject::connectSlotsByName(FRoomStates);
    } // setupUi

    void retranslateUi(QWidget *FRoomStates)
    {
        FRoomStates->setWindowTitle(QCoreApplication::translate("FRoomStates", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FRoomStates: public Ui_FRoomStates {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FROOMSTATES_H
