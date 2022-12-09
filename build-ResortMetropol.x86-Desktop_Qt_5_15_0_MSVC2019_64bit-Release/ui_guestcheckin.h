/********************************************************************************
** Form generated from reading UI file 'guestcheckin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUESTCHECKIN_H
#define UI_GUESTCHECKIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuestCheckin
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *GuestCheckin)
    {
        if (GuestCheckin->objectName().isEmpty())
            GuestCheckin->setObjectName(QString::fromUtf8("GuestCheckin"));
        GuestCheckin->resize(641, 16);
        verticalLayout_2 = new QVBoxLayout(GuestCheckin);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(GuestCheckin);

        QMetaObject::connectSlotsByName(GuestCheckin);
    } // setupUi

    void retranslateUi(QWidget *GuestCheckin)
    {
        GuestCheckin->setWindowTitle(QCoreApplication::translate("GuestCheckin", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuestCheckin: public Ui_GuestCheckin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUESTCHECKIN_H
